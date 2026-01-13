//*********************** TEMPERATURE MONITORING SYSYTEM ***********************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File		: sensor.c
// Summary	: Options to read sensor output data
// Note		: None
// Author	: Francis V D
// Date		: 02-January-2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sensor.h"
#include "temperatureMonitoring.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: To read the output from temperature sensor
//Inputs	: uint32 *pulCurrentTemperature, pointer to variable where
//			  temperature value is get stored
//Outputs	: None
//Return	: uint8 ucTemperature, measured temperature
//******************************************************************************
bool sensorTemperatureReadValue(uint32 *pulCurrentTemperature)
{
	bool blReturn = false;
	uint32 ulTimeAsRandomSeed = 0;

	ulTimeAsRandomSeed = time(NULL);
	srand(ulTimeAsRandomSeed);
	*pulCurrentTemperature = ((rand() )% (SENSOR_TEMPERATURE_CALIBRATE));

	if((*pulCurrentTemperature >= SENSOR_TEMPERATURE_MIN) && 
		(*pulCurrentTemperature <= SENSOR_TEMPERATURE_MAX))
	{
		blReturn = true;
	}
	else
	{
		printf("Unable to read sensor value\n");
	}

	return blReturn;
}
// EOF