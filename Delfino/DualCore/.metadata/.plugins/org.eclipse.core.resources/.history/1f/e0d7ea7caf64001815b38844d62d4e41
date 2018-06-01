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
#include <stdlib.h>  /* malloc, free, rand */
#include <stdbool.h>

#include "driverlib.h"
#include "device.h"
#include "DCL/include/DCL.h"

#include "device_init.h"
#include "interrupt_handlers.h"
#include "motor_driver.h"

#include "modbusRTU.h"
#include "modbus_regs.h"

#include "buffered_serial.h"
#include "buffered_serial_B.h"

#include "MotionProfile.h"
#include "kinematics.h"

#include "motion_buffer.h"

#include "task_scheduler.h"

#include "RoboClaw.h"

#include "safety_routines.h"

#include "autonomous_mode.h"

#include "ModbusMaster.h"

#include "FM25W256.h"

#include "interwinch_comms.h"


//utilities
#define systick() ((uint32_t)(4294967295 - CPUTimer_getTimerCount(CPUTIMER0_BASE))) //needed because the cpu_timer is cnt_dwn, not up! (200us per tick)

#endif /* INCLUDES_H_ */
