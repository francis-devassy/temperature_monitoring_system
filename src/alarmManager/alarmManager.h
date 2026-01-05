//*********************** TEMPERATURE MONITORING SYSYTEM ***********************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// Summary	: 
// Note		: 
//
//******************************************************************************

#ifndef _ALARM_MANAGER_H_
#define _ALARM_MANAGER_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdbool.h>

//******************************* Global Types *********************************
#define ALARM_MANAGER_SUCCESS	(0)
#define ALARM_MANAGER_ON_TIME	(1)


//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool alarmMangerCreateThread(void);

#endif // _ALARM_MANAGER_H_
// EOF