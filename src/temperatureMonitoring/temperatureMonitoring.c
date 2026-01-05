//**************************** PROJECT X ***************************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File		: temperatureMonitoring.c
// Summary	: 
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
#include "temperatureMonitoring.h"
#include "alarmManager.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Thread to read temperature every p second
//Inputs	: None
//Outputs	: None
//Return	: 
//Notes		: None
//******************************************************************************
static void* temperatureMonitoringThread(void  *pArg)
{
	while(1)
	{
		ulCurrentTemperature = sensorTemperatureReadValue();
		printf("\n Temperature : %lu",ulCurrentTemperature);
		sleep(TEMPERATURE_MONITORING_POLL_FREQ);
	}

	return NULL;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Create thread to monitor temperature
//Inputs	: None
//Outputs	: None
//Return	: bool blReturn, true at time of successful execution
//Return	: bool blReturn, false in case of an error
//Notes		: None
//******************************************************************************
bool temperatureMonitoringCreateThread(void)
{
	bool blReturn = false;
	pthread_t ultemperatureMonitoring = 0;
	blReturn = pthread_create(&ultemperatureMonitoring, NULL,
				temperatureMonitoringThread, NULL);
	
	if(blReturn == TEMPERATURE_MONITORING_SUCCESS)
	{
		blReturn = pthread_detach(ultemperatureMonitoring);
	}
	else
	{
		printf("\n Unable to create temperature monotoring thread");
	}

	if( blReturn == TEMPERATURE_MONITORING_SUCCESS)
	{
		blReturn = true;
	}

	return blReturn;
}
// EOF