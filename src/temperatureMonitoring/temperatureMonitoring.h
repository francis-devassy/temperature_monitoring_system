//**************************** PROJECT X ***************************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// Summary	: 
// Note		: None
//
//******************************************************************************

#ifndef _TEMPERATURE_MONITORING_H_
#define _TEMPERATURE_MONITORING_H_

//******************************* Include Files ********************************
#include "customTypes.h"

//******************************* Global Types *********************************
// typedef struct _TEMPERATURE_MONITORING_DATA_
// {
// 	uint32 ulDeviceVendor;
// } TEMPERATURE_MONITORING_DATA;

//***************************** Global Constants *******************************
#define TEMPERATURE_MONITORING_SUCCESS		(0)
#define TEMPERATURE_MONITORING_POLL_FREQ	(1)
#define TEMPERATURE_MONITORING_THRESHOLD	(60)

//***************************** Global Variables *******************************
extern uint32 ulCurrentTemperature;

//**************************** Forward Declarations ****************************
bool temperatureMonitoringCreateThread(void);

#endif // _TEMPERATURE_MONITORING_H_
// EOF