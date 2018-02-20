/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/


#ifndef MODBUS_REGS_H_
#define MODBUS_REGS_H_




// Slave registers
enum 
{
    Winch_ID, //set via dip_switches
    Soft_Reset, //for emergency stop

    Max_Velocity,       // this is in mm/s
    Max_Acceleration,   // this is in mm/s^2

    Target_Setpoint, //for cable length in mm

    Kp,
    Ki,
    Kd,
    PID_Setpoint, //for motion planner (read only)

    Target_X,
    Target_Y,
    Target_Z,

    Field_Length, //in mm
    Field_Width, //in mm

    Homing_switch, //read only

    Current_Encoder_Count, //in mm
    Current_PWM, //in percent
    Current_RPM,

    Current_X,
    Current_Y,
    Current_Z,

    Current_Length_Winch0,
    Current_Length_Winch1,
    Current_Length_Winch2,
    Current_Length_Winch3,

    Current_Force_Winch0,
    Current_Force_Winch1,
    Current_Force_Winch2,
    Current_Force_Winch3,

    ADC0,
    ADC1,
    ADC2,
    ADC3,

    Global_Dwell_Time,

    Homing_Flag,
    Auto_mode,
    Sync,

    Follow_Waypoints,
    Current_Waypoints_Pointer,
    Number_of_Waypoints,

    //start of waypoints
    X1 = 64,
    Y1,
    Z1,
    X2,
    Y2,
    Z2, //etc..

    MB_HREGS  = 4096 //should give ~1344 3D points
};

extern signed int modbus_holding_regs[MB_HREGS];

#endif /* MODBUS_REGS_H_ */


/* [] END OF FILE */
