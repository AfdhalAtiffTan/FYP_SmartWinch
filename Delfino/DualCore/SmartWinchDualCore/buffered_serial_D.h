/*
 * buffered_serial_D.h
 *
 *  Created on: 31 May 2018
 *      Author: AfdhalAtiffTan
 *      Based on Arduino SoftSerial Library.
 */

#ifndef BUFFERED_SERIAL_D_H_
#define BUFFERED_SERIAL_D_H_

#include "includes.h"

void buffered_serial_D_write(char c);
char buffered_serial_D_read();
char buffered_serial_D_available();
void buffered_serial_D_flush();

//for ISRs
void buffered_serial_D_receive();
void buffered_serial_D_transmit();


extern volatile char eusartTxBufferRemaining_D;

#endif /* BUFFERED_SERIAL_H_ */
