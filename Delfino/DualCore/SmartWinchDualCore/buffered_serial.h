/*
 * buffered_serial.h
 *
 *  Created on: 15 Feb 2018
 *      Author: AfdhalAtiffTan
 *      Based on Arduino SoftSerial Library.
 */

#ifndef BUFFERED_SERIAL_H_
#define BUFFERED_SERIAL_H_

#include "includes.h"

void buffered_serial_write(char c);
char buffered_serial_read();
char buffered_serial_available();
void buffered_serial_flush();

//for ISRs
void buffered_serial_receive();
void buffered_serial_transmit();


extern volatile char eusartTxBufferRemaining;

#endif /* BUFFERED_SERIAL_H_ */
