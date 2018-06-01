//#############################################################################
//
// FILE:   device.h
//
// TITLE:  Device setup for examples.
//
//#############################################################################
// $TI Release: F2837xD Support Library v3.03.00.00 $
// $Release Date: Thu Dec  7 18:51:32 CST 2017 $
// $Copyright:
// Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"

#define _LAUNCHXL_F28379D //added by afdhal


#if (!defined(CPU1) && !defined(CPU2))
#error "You must define CPU1 or CPU2 in your project properties.  Otherwise, \
the offsets in your header files will be inaccurate."
#endif

#if (defined(CPU1) && defined(CPU2))
#error "You have defined both CPU1 and CPU2 in your project properties.  Only \
a single CPU should be defined."
#endif

//*****************************************************************************
//
// Defines for pin numbers and other GPIO configuration
//
//*****************************************************************************
//
// LEDs
//
#define DEVICE_GPIO_PIN_LED1        31U  // GPIO number for LD2
#define DEVICE_GPIO_PIN_LED2        34U  // GPIO number for LD3
#define DEVICE_GPIO_CFG_LED1        GPIO_31_GPIO31  // "pinConfig" for LD2
#define DEVICE_GPIO_CFG_LED2        GPIO_34_GPIO34  // "pinConfig" for LD3

//
// SCIA for USB-to-UART adapter on FTDI chip
//
#define DEVICE_GPIO_PIN_SCIRXDA     43U             // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDA     42U             // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDA     GPIO_43_SCIRXDA // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDA     GPIO_42_SCITXDA // "pinConfig" for SCI TX

//
// SCIB on J1
//
#define DEVICE_GPIO_PIN_SCIRXDB     19U             // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDB     18U             // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDB     GPIO_19_SCIRXDB // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDB     GPIO_18_SCITXDB // "pinConfig" for SCI TX

//
// SCIC on J5
//
#define DEVICE_GPIO_PIN_SCIRXDC     139U             // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDC     56U             // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDC     GPIO_139_SCIRXDC // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDC     GPIO_56_SCITXDC // "pinConfig" for SCI TX

//
// SCID for interwinch WiFi
//
#define DEVICE_GPIO_PIN_SCIRXDD     105U             // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDD     104U             // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDD     GPIO_105_SCIRXDD // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDD     GPIO_104_SCITXDD // "pinConfig" for SCI TX

//
// CANA
//
#define DEVICE_GPIO_PIN_CANTXA      31U  // GPIO number for CANTXA
#define DEVICE_GPIO_PIN_CANRXA      30U  // GPIO number for CANRXA

//
// CAN External Loopback
//
#define DEVICE_GPIO_CFG_CANRXA      GPIO_30_CANRXA  // "pinConfig" for CANA RX
#define DEVICE_GPIO_CFG_CANTXA      GPIO_31_CANTXA  // "pinConfig" for CANA TX
#define DEVICE_GPIO_CFG_CANRXB      GPIO_10_CANRXB  // "pinConfig" for CANB RX
#define DEVICE_GPIO_CFG_CANTXB      GPIO_8_CANTXB   // "pinConfig" for CANB TX



//
// eQEP_A
//
#define DEVICE_GPIO_PIN_EQEP1A      20U             // GPIO number for EQEP1A
#define DEVICE_GPIO_PIN_EQEP1B      21U             // GPIO number for EQEP1B
#define DEVICE_GPIO_PIN_EQEP1I      99U             // GPIO number for EQEP1I
#define DEVICE_GPIO_CFG_EQEP1A      GPIO_20_EQEP1A  // "pinConfig" for EQEP1A
#define DEVICE_GPIO_CFG_EQEP1B      GPIO_21_EQEP1B  // "pinConfig" for EQEP1B
#define DEVICE_GPIO_CFG_EQEP1I      GPIO_99_EQEP1I  // "pinConfig" for EQEP1I


//
// PWM2
//
#define DEVICE_GPIO_PIN_EPWM2A        2U  
#define DEVICE_GPIO_PIN_EPWM2B        3U  
#define DEVICE_GPIO_CFG_EPWM2A        GPIO_2_EPWM2A  
#define DEVICE_GPIO_CFG_EPWM2B        GPIO_3_EPWM2B  

//
// PWM3
//
#define DEVICE_GPIO_PIN_EPWM3A        4U  
#define DEVICE_GPIO_PIN_EPWM3B        5U  
#define DEVICE_GPIO_CFG_EPWM3A        GPIO_4_EPWM3A  
#define DEVICE_GPIO_CFG_EPWM3B        GPIO_5_EPWM3B  

//<legacy>
//
// WinchID Pins (used to set 2-bit Winch Address)
//
#define DEVICE_GPIO_PIN_ID0        124U  
#define DEVICE_GPIO_PIN_ID1        125U  
#define DEVICE_GPIO_CFG_ID0        GPIO_124_GPIO124 
#define DEVICE_GPIO_CFG_ID1        GPIO_125_GPIO125  

//
// Debug-mode Pin (used to enter debug mode)
//
#define DEVICE_GPIO_PIN_DBG        19U 
#define DEVICE_GPIO_CFG_DBG        GPIO_19_GPIO19 
//</legacy>

//SPIA for load cell
#define DEVICE_GPIO_PIN_SPISIMOA    58U
#define DEVICE_GPIO_PIN_SPISOMIA    59U
#define DEVICE_GPIO_PIN_SPIIRQA     123U
#define DEVICE_GPIO_PIN_SPICLKA     60U
#define DEVICE_GPIO_PIN_SPISTEA     61U
#define DEVICE_GPIO_CFG_SPISIMOA    GPIO_58_SPISIMOA 
#define DEVICE_GPIO_CFG_SPISOMIA    GPIO_59_SPISOMIA  
#define DEVICE_GPIO_CFG_SPIIRQA     GPIO_123_GPIO123  
#define DEVICE_GPIO_CFG_SPICLKA     GPIO_60_SPICLKA  
#define DEVICE_GPIO_CFG_SPISTEA     GPIO_61_SPISTEA  

//SPIB for fram
#define DEVICE_GPIO_PIN_SPISIMOB    63U
#define DEVICE_GPIO_PIN_SPISOMIB    64U
#define DEVICE_GPIO_PIN_SPICLKB     65U
#define DEVICE_GPIO_PIN_SPISTEB     66U
#define DEVICE_GPIO_CFG_SPISIMOB    GPIO_63_SPISIMOB 
#define DEVICE_GPIO_CFG_SPISOMIB    GPIO_64_SPISOMIB  
#define DEVICE_GPIO_CFG_SPICLKB     GPIO_65_SPICLKB  
#define DEVICE_GPIO_CFG_SPISTEB     GPIO_66_SPISTEB  
//#define DEVICE_GPIO_CFG_SPISTEB     GPIO_66_GPIO66

//
// Emergency Stop Switch
//
#define DEVICE_GPIO_PIN_EMERGENCY_STOP       2U 
#define DEVICE_GPIO_CFG_EMERGENCY_STOP       GPIO_2_GPIO2 

//
// Zero Tether Switch
//
#define DEVICE_GPIO_PIN_ZERO_TETHER       0U 
#define DEVICE_GPIO_CFG_ZERO_TETHER       GPIO_0_GPIO0 

//
// Reel Out Switch
//
#define DEVICE_GPIO_PIN_REEL_OUT       1U 
#define DEVICE_GPIO_CFG_REEL_OUT       GPIO_1_GPIO1 

//
// Reel In Switch
//
#define DEVICE_GPIO_PIN_REEL_IN       6U 
#define DEVICE_GPIO_CFG_REEL_IN       GPIO_6_GPIO6 

//
// Zero Force Switch
//
#define DEVICE_GPIO_PIN_ZERO_FORCE       7U 
#define DEVICE_GPIO_CFG_ZERO_FORCE       GPIO_7_GPIO7 

//
// Right Limit Switch
//
#define DEVICE_GPIO_PIN_RIGHT_LIMIT       8U 
#define DEVICE_GPIO_CFG_RIGHT_LIMIT       GPIO_8_GPIO8 

//
// Left Switch
//
#define DEVICE_GPIO_PIN_LEFT_LIMIT       9U 
#define DEVICE_GPIO_CFG_LEFT_LIMIT       GPIO_9_GPIO9 


// Bit0 Switch
#define DEVICE_GPIO_PIN_B0       122U 
#define DEVICE_GPIO_CFG_B0       GPIO_122_GPIO122 

// Bit1 Switch
#define DEVICE_GPIO_PIN_B1       124U 
#define DEVICE_GPIO_CFG_B1       GPIO_124_GPIO124 

// Bit2 Switch
#define DEVICE_GPIO_PIN_B2       125U 
#define DEVICE_GPIO_CFG_B2       GPIO_125_GPIO125

// Bit3 Switch
#define DEVICE_GPIO_PIN_B3       29U 
#define DEVICE_GPIO_CFG_B3       GPIO_29_GPIO29

// Bit4 Switch
#define DEVICE_GPIO_PIN_B4       131U 
#define DEVICE_GPIO_CFG_B4       GPIO_131_GPIO131 

// Bit5 Switch
#define DEVICE_GPIO_PIN_B5       130U 
#define DEVICE_GPIO_CFG_B5       GPIO_130_GPIO130 

// Bit6 Switch
#define DEVICE_GPIO_PIN_B6       26U 
#define DEVICE_GPIO_CFG_B6       GPIO_26_GPIO26 

// Bit7 Switch
#define DEVICE_GPIO_PIN_B7       27U 
#define DEVICE_GPIO_CFG_B7       GPIO_27_GPIO27 


//*****************************************************************************
//
// Defines related to clock configuration
//
//*****************************************************************************
//
// Launchpad Configuration
//
#ifdef _LAUNCHXL_F28379D

//
// 10MHz XTAL on LaunchPad. For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          10000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 10MHz (XTAL_OSC) * 40 (IMULT) * 1 (FMULT) / 2 (PLLCLK_BY_2)
//
#define DEVICE_SETCLOCK_CFG         (SYSCTL_OSCSRC_XTAL | SYSCTL_IMULT(40) |  \
                                     SYSCTL_FMULT_NONE | SYSCTL_SYSDIV(2) |   \
                                     SYSCTL_PLL_ENABLE)

//
// 200MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          ((DEVICE_OSCSRC_FREQ * 40 * 1) / 2)

//
// ControlCARD Configuration
//
#else

//
// 20MHz XTAL on controlCARD. For use with SysCtl_getClock().
//
#define DEVICE_OSCSRC_FREQ          20000000U

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = 20MHz (XTAL_OSC) * 20 (IMULT) * 1 (FMULT) / 2 (PLLCLK_BY_2)
//
#define DEVICE_SETCLOCK_CFG         (SYSCTL_OSCSRC_XTAL | SYSCTL_IMULT(20) |  \
                                     SYSCTL_FMULT_NONE | SYSCTL_SYSDIV(2) |   \
                                     SYSCTL_PLL_ENABLE)

//
// 200MHz SYSCLK frequency based on the above DEVICE_SETCLOCK_CFG. Update the
// code below if a different clock configuration is used!
//
#define DEVICE_SYSCLK_FREQ          ((DEVICE_OSCSRC_FREQ * 20 * 1) / 2)

#endif

//
// 50MHz LSPCLK frequency based on the above DEVICE_SYSCLK_FREQ and a default
// low speed peripheral clock divider of 4. Update the code below if a
// different LSPCLK divider is used!
//
#define DEVICE_LSPCLK_FREQ          (DEVICE_SYSCLK_FREQ / 4)

//*****************************************************************************
//
// Macro to call SysCtl_delay() to achieve a delay in microseconds. The macro
// will convert the desired delay in microseconds to the count value expected
// by the function. \b x is the number of microseconds to delay.
//
//*****************************************************************************
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              (long double)DEVICE_SYSCLK_FREQ)) - 9.0L) / 5.0L)

//*****************************************************************************
//
// Defines, Globals, and Header Includes related to Flash Support
//
//*****************************************************************************
#ifdef _FLASH
#include <stddef.h>

extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;

#define DEVICE_FLASH_WAITSTATES 3

#endif

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
extern void Device_init(void);
extern void Device_enableAllPeripherals(void);
extern void Device_initGPIO(void);
extern void Device_enableUnbondedGPIOPullupsFor176Pin(void);
extern void Device_enableUnbondedGPIOPullupsFor100Pin(void);
extern void Device_enableUnbondedGPIOPullups(void);
extern void __error__(char *filename, uint32_t line);

//
// End of file
//
