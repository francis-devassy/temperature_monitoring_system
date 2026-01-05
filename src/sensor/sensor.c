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
#include "sensor.h"


//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: To read the output from temperature sensor
//Inputs	: None
//Outputs	: None
//Return	: uint8 ucTemperature, measured temperature
//******************************************************************************
uint8 sensorTemperatureReadValue(void)
{
	uint8 ucTemperature = 0;
	uint32 ulTimeAsRandomSeed = 0;

	ulTimeAsRandomSeed = time(NULL);
	//srand(time(NULL));
	srand(ulTimeAsRandomSeed);
	ucTemperature = (rand() % SENSOR_TEMPERATURE_CALIBRATE);

	return ucTemperature;
}
// EOF