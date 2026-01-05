//*********************** TEMPERATURE MONITORING SYSYTEM ***********************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// Summary	: Handle options to read sensor readings
// Note		: None
//
//******************************************************************************

#ifndef _SENSOR_H_
#define _SENSOR_H_

//******************************* Include Files ********************************
#include <customTypes.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define SENSOR_TEMPERATURE_MAX		(100)
#define SENSOR_TEMPERATURE_MIN		(0)
#define SENSOR_TEMPERATURE_CALIBRATE	(101)


//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
uint8 sensorTemperatureReadValue(void);

#endif // _SENSOR_H_
// EOF