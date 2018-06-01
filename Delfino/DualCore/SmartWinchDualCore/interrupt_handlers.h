/*
 * interrupt_handlers.h
 *
 *  Created on: 10 Feb 2018
 *      Author: AfdhalAtiffTan
 */

#ifndef INTERRUPT_HANDLERS_H_
#define INTERRUPT_HANDLERS_H_

#include "includes.h"

//temporary pid

/*
volatile extern float setpoint;
volatile extern float kp, ki, kd;
volatile extern float error, input_previous, error_integrated, input_differentiated;
volatile extern float out_min, out_max;
volatile extern float input, output;
volatile extern uint16_t adc_temp;*/

volatile extern PID pid1;

__interrupt void epwm3ISR(void);

__interrupt void sciaTXFIFOISR(void);
__interrupt void sciaRXFIFOISR(void);

__interrupt void scibTXFIFOISR(void);
__interrupt void scibRXFIFOISR(void);

__interrupt void scicTXFIFOISR(void);
__interrupt void scicRXFIFOISR(void);

__interrupt void scidTXFIFOISR(void);
__interrupt void scidRXFIFOISR(void);

#endif /* INTERRUPT_HANDLERS_H_ */
