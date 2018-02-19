/*
 * includes.h
 *
 *  Created on: 10 Feb 2018
 *      Author: AfdhalAtiffTan
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

//
// Included Files
//
#include <math.h>
#include <stdio.h>
#include "driverlib.h"
#include "device.h"
#include "DCL/include/DCL.h"

#include "device_init.h"
#include "interrupt_handlers.h"
#include "motor_driver.h"

#include "modbusRTU.h"
#include "modbus_regs.h"

#include "buffered_serial.h"


//utilities
#define systick() ((uint32_t)(4294967295 - CPUTimer_getTimerCount(CPUTIMER0_BASE))) //needed because the cpu_timer is cnt_dwn, not up! (200us per tick)

#endif /* INCLUDES_H_ */
