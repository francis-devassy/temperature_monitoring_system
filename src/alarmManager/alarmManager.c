//*********************** TEMPERATURE MONITORING SYSYTEM ***********************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File		: alarmManager.c
// Summary	: Handles alarm on off control based on temperature threshold
//			  comparison status
// Note		: None
// Author	: Francis V D
// Date		: 01-January-2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include "sensor.h"
#include "alarmManager.h"
#include "customTypes.h"
#include "temperatureMonitoring.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Turn off alarm
//Inputs	: None
//Outputs	: None
//Return	: None
//Return	: None
//Notes		: None
//******************************************************************************
static void alarmManagerAlarmOff(void)
{
	printf("\nAlarm off");
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Turn on alarm for a specific duartion
//Inputs	: uint8 ucAlarmOnTime, time in second for which the alarm to be 
//				turned on
//Outputs	: None
//Return	: bool blReturn, true if ulTemperatureValue is greater than
//				ulThresholdValue
//Return	: bool blReturn, false if ulTemperatureValue is less than or
//				equal to ulThresholdValue
//Notes		: None
//******************************************************************************
static bool alarmManagerAlarmOn(uint8 ucAlarmOnTime)
{
	bool blReturn = false;

	if(ucAlarmOnTime > ALARM_MANAGER_ON_DISABLED)
	{
		printf("\nAlarm on");
		blReturn = sleep(ucAlarmOnTime);

		if(blReturn != 0)
		{
			printf("\nError in alarm on wait duration");
		}
		else
		{
			blReturn = true;
		}
		alarmManagerAlarmOff();
	}
	else
	{
		printf("\nUnable to turn on alarm: Invalid alarm on time");
	}

	return blReturn;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Compares the temparature value with threshold
//Inputs	: uint32 ulTemperatureValue, the temperature value which is to be 
//				compared with the threshold
//Inputs	: uint32 ulThresholdValue, the temperature threshold level
//Outputs	: None
//Return	: bool blReturn, true if ulTemperatureValue is greater than
//				ulThresholdValue
//Return	: bool blReturn, false if ulTemperatureValue is less than or
//				equal to ulThresholdValue
//Notes		: None
//******************************************************************************
static bool alarmManagerCompareData(uint32 ulTemperatureValue,
									uint32 ulThresholdValue)
{
	bool blReturn = false;

	if(ulTemperatureValue >=SENSOR_TEMPERATURE_MIN && 
		ulTemperatureValue <= SENSOR_TEMPERATURE_MAX)
	{
		if(ulTemperatureValue > ulThresholdValue)
		{
			blReturn = true;
		}
	}
	else
	{
		printf("\nUnable to compare data in alarm manager compare:"
				"Inavlid temperature");
	}

	return blReturn;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Read updated temperature data from shared memory
//Inputs	: None
//Outputs	: None
//Return	: uint32 ulTemperature, updated temperature data read 
//			  from shared memory
//Notes		: None
//******************************************************************************
static uint32 alarmManagerReadData(void)
{
	uint32 ulTemperature = 0;

	ulTemperature = ulCurrentTemperature;

	return ulTemperature;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Thread to read temperature every p second
//Inputs	: void *pArg, pointer to thread arguments
//Outputs	: None
//Return	: None
//Notes		: None
//******************************************************************************
static void* alarmMangerThread(void  *pArg)
{
	uint32 ulTemperature = 0;
	bool blReturn = false;

	while(1)
	{
		ulTemperature = alarmManagerReadData();

		if(ulTemperature >= SENSOR_TEMPERATURE_MIN && 
			ulTemperature <= SENSOR_TEMPERATURE_MAX)
		{
			blReturn = alarmManagerCompareData(ulTemperature,
									TEMPERATURE_MONITORING_THRESHOLD);

			if(blReturn == true)
			{
				blReturn = alarmManagerAlarmOn(ALARM_MANAGER_ON_TIME);
			}
		}
		else
		{
			printf("\nUnable to run alarm manger: Inavlid temperature");
		}
		
	}

	return NULL;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Create thread to manage the alarm module
//Inputs	: None
//Outputs	: None
//Return	: bool blReturn, true at time of successful execution
//Return	: bool blReturn, false in case of an error
//Notes		: None
//******************************************************************************
bool alarmMangerCreateThread(void)
{
	bool blReturn = false;
	pthread_t ulalarmManager = 0;

	blReturn = pthread_create(&ulalarmManager, NULL,
				alarmMangerThread, NULL);

	if(blReturn == ALARM_MANAGER_SUCCESS)
	{
		blReturn = pthread_detach(ulalarmManager);
	}
	else
	{
		printf("\n Unable to create alarm manager thread");
	}

	if( blReturn == ALARM_MANAGER_SUCCESS)
	{
		blReturn = true;
	}

	return blReturn;
}
// EOF