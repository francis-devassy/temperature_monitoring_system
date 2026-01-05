//*********************** TEMPERATURE MONITORING SYSYTEM ***********************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File		: main.c
// Summary	: 
// Note		: None
// Author	: Francis V D
// Date		: 02-January-2026
// 
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include "customTypes.h"
#include "alarmManager.h"
#include "temperatureMonitoring.h"

//***************************** Global Variables *******************************
uint32 ulCurrentTemperature = 0;

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: 
//Inputs	: None
//Outputs	: None
//Return	: Return 0 at time of successful execution
//Return	: Returns a non-zero integer value in case of an error
//Notes		:  Code execution begins from here
//******************************************************************************
int main()
{
	while(1)
	{
		temperatureMonitoringCreateThread();
		alarmMangerCreateThread();
	}
	
	return 0;
}
// EOF