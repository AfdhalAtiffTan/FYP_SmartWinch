/*
 * buffered_serial_D.c
 *
 *  Created on: 31 May 2018
 *      Author: AfdhalAtiffTan
 */


#include "buffered_serial_D.h"

// static data
#define EUSART_TX_BUFFER_SIZE_D 0xFF
static char eusartTxHead = 0;
static char eusartTxTail = 0;
static char eusartTxBuffer[EUSART_TX_BUFFER_SIZE_D];
volatile char eusartTxBufferRemaining_D=EUSART_TX_BUFFER_SIZE_D;
volatile char TXIE_D = 0;

#define MAX_BUFF_D 0xFF
static char _receive_buffer[MAX_BUFF_D];
static volatile char _receive_buffer_tail=0;
static volatile char _receive_buffer_head=0;


//ported from microchip mcc usart driver
void buffered_serial_D_write(char c)
{
    while(0 == eusartTxBufferRemaining_D)
    {
    }


    if(0 == TXIE_D)
    {
        //TX1REG = txData;
        SCI_writeCharBlockingFIFO(SCID_BASE, c);
    }
    else
    {
        TXIE_D = 0;
        Interrupt_disable(INT_SCID_TX);

        eusartTxBuffer[eusartTxHead++] = c;
        if(EUSART_TX_BUFFER_SIZE_D <= eusartTxHead)
        {
            eusartTxHead = 0;
        }
        eusartTxBufferRemaining_D--;
    }

    //only set isr when tx fifo is full
    if(SCI_getTxFIFOStatus(SCID_BASE) < SCI_FIFO_TX16) //this might not work properly
    {
        TXIE_D = 1;
        Interrupt_enable(INT_SCID_TX);
    }
}

//ported from arduino softserial library
char buffered_serial_D_read()
{
    // Empty buffer?
    if (_receive_buffer_head == _receive_buffer_tail)
      return -1;

    // Read from "head"
    char d = _receive_buffer[_receive_buffer_head]; // grab next byte
    _receive_buffer_head = (_receive_buffer_head + 1) % MAX_BUFF_D;
    return d;
}

//ported from arduino softserial library
char buffered_serial_D_available()
{
    return (_receive_buffer_tail + MAX_BUFF_D - _receive_buffer_head) % MAX_BUFF_D;
}

//flush rx buff
void buffered_serial_D_flush()
{
    _receive_buffer_head = 0;
    _receive_buffer_tail = 0;
}

//ported from arduino softserial library
void buffered_serial_D_receive()
{
    // if buffer full, set the overflow flag and return
    char next = (_receive_buffer_tail + 1) % MAX_BUFF_D;
    if (next != _receive_buffer_head)
    {
      // save new data in buffer: tail points to where byte goes
      _receive_buffer[_receive_buffer_tail] = SCI_readCharNonBlocking(SCID_BASE); // save new byte
      _receive_buffer_tail = next;
    }

}

//ported from microchip mcc usart driver
void buffered_serial_D_transmit()
{
    // add your EUSART interrupt custom code
    if(EUSART_TX_BUFFER_SIZE_D > eusartTxBufferRemaining_D)
    {
        //TX1REG = eusartTxBuffer[eusartTxTail++];

        //fillup fifo
        while((EUSART_TX_BUFFER_SIZE_D > eusartTxBufferRemaining_D) && (SCI_getTxFIFOStatus(SCID_BASE) < SCI_FIFO_TX16)) //this might not work properly
        {
            SCI_writeCharBlockingFIFO(SCID_BASE, eusartTxBuffer[eusartTxTail++]);
            if(EUSART_TX_BUFFER_SIZE_D <= eusartTxTail)
            {
                eusartTxTail = 0;
            }
            eusartTxBufferRemaining_D++;
        }
    }
    else
    {
        TXIE_D = 0;
        Interrupt_disable(INT_SCID_TX);
    }

    //GPIO_togglePin(DEVICE_GPIO_PIN_LED2);
}
