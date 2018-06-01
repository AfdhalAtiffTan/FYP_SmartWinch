/*
 * interrupt_handlers.c
 *
 *  Created on: 10 Feb 2018
 *      Author: AfdhalAtiffTan
 */

#include "interrupt_handlers.h"



volatile PID pid1 = PID_DEFAULTS;
volatile float uk; // control
volatile float rk = 0.0f; // reference
volatile float yk = 0.0f; // feedback
volatile float lk = 1.0f; // saturation

void old_pid()
{
    //homing switch
    modbus_holding_regs[Homing_switch] = GPIO_readPin(DEVICE_GPIO_PIN_EQEP1I)^1; //active-low switch

    task_scheduler_handler();

    //
    // PID here
    //
    pid1.Kp = (float)modbus_holding_regs[Kp] * 512.0f;
    pid1.Ki = (float)modbus_holding_regs[Ki] / 1024.0f;
    pid1.Kd = (float)modbus_holding_regs[Kd] * 128.0f;

    float cable_length = (float)EQEP_getPosition(EQEP1_BASE) - (float)0x80000000; //should be able to accept negative length

    //roboclaw test
    EINT; //to allow serial isr
    uint16_t stat;
    bool valid;
    cable_length = (float) RoboClaw_ReadEncM1(0x80, &stat, &valid);



    cable_length = cable_length*47.124f/32.0f/120.0f; /*  count*circumference/pulse_per_rotation/gear_ratio  */
    modbus_holding_regs[Current_Encoder_Count] = (int32_t) cable_length;

    //assign length to appropriate id
    modbus_holding_regs[Current_Length_Winch0   + modbus_holding_regs[Winch_ID]] = modbus_holding_regs[Current_Encoder_Count];   
    modbus_holding_regs[Target_Length_Winch0    + modbus_holding_regs[Winch_ID]] = modbus_holding_regs[Target_Setpoint];   


    rk = (float) MotionProfile_update((float)modbus_holding_regs[Target_Setpoint]);
    yk = cable_length;
    uk = DCL_runPID(&pid1, rk, yk, lk);
    bidirectional_motor((signed long) uk);
    modbus_holding_regs[PID_Setpoint] = (signed int) rk;
    modbus_holding_regs[Current_PWM] = (int)(uk/16777215.0f*100.0f); //in % (pwm is 24 bit)
}

//
// epwm3ISR - ePWM 3 ISR
//
__interrupt void epwm3ISR(void)
{
    //GPIO_writePin(DEVICE_GPIO_PIN_LED2, 0); //tic

    //heartbeat on led
    volatile static int cnt=0;                
    if(cnt++>48) //almost once a second 100MHz/2/8/0xffff/48 (2Hz)
    {
        cnt=0;
        GPIO_togglePin(DEVICE_GPIO_PIN_LED1);
    }
    
    //old_pid();


    EPWM_clearEventTriggerInterruptFlag(EPWM3_BASE);    //Clear INT flag for this timer
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);      //Acknowledge interrupt group

    //GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1); //toc
}



//
// sciaTXFIFOISR - SCIA Transmit FIFO ISR
//
__interrupt void sciaTXFIFOISR(void)
{
    buffered_serial_transmit();

    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF);

    //
    // Issue PIE ACK
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

//
// sciaRXFIFOISR - SCIA Receive FIFO ISR
//
__interrupt void sciaRXFIFOISR(void)
{
    buffered_serial_receive();

    SCI_clearOverflowStatus(SCIA_BASE);

    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_RXFF);

    //
    // Issue PIE ack
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}



//
// scibTXFIFOISR - SCIB Transmit FIFO ISR
//
__interrupt void scibTXFIFOISR(void)
{
    buffered_serial_B_transmit();

    SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_TXFF);

    //
    // Issue PIE ACK
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

//
// scibRXFIFOISR - SCIB Receive FIFO ISR
//
__interrupt void scibRXFIFOISR(void)
{
    buffered_serial_B_receive();

    SCI_clearOverflowStatus(SCIB_BASE);

    SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_RXFF);

    //
    // Issue PIE ack
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}


//
// scicTXFIFOISR - SCIC Transmit FIFO ISR
//
__interrupt void scicTXFIFOISR(void)
{
    buffered_serial_C_transmit();

    SCI_clearInterruptStatus(SCIC_BASE, SCI_INT_TXFF);

    //
    // Issue PIE ACK
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP8);
}

//
// scicRXFIFOISR - SCIC Receive FIFO ISR
//
__interrupt void scicRXFIFOISR(void)
{
    buffered_serial_C_receive();

    SCI_clearOverflowStatus(SCIC_BASE);

    SCI_clearInterruptStatus(SCIC_BASE, SCI_INT_RXFF);

    //
    // Issue PIE ack
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP8);
}


//
// scidTXFIFOISR - SCIC Transmit FIFO ISR
//
__interrupt void scidTXFIFOISR(void)
{
    buffered_serial_D_transmit();

    SCI_clearInterruptStatus(SCID_BASE, SCI_INT_TXFF);

    //
    // Issue PIE ACK
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP8);
}

//
// scidRXFIFOISR - SCIC Receive FIFO ISR
//
__interrupt void scidRXFIFOISR(void)
{
    buffered_serial_D_receive();

    SCI_clearOverflowStatus(SCID_BASE);

    SCI_clearInterruptStatus(SCID_BASE, SCI_INT_RXFF);

    //
    // Issue PIE ack
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP8);
}
