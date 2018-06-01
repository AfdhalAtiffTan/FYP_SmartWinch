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
    DIP_Switch_Status, //set via dip_switches
    Soft_Reset, //for emergency stop

    Max_Velocity,       // this is in mm/s used for motion control
    Max_Acceleration,   // this is in mm/s^2 used for motion control

    Encoder_Radius, //for measuring wheel
    Encoder_Pulse, //edge per full rotation

    Target_Setpoint, //for cable length in mm (absolute control)
    Target_Setpoint_Offset, //used for relative control

    //MCP266
    Kp_velocity,
    Ki_velocity,
    Kd_velocity,
    Max_Encoder_Feedrate, //max tether speed at 100% power in mm/s

    //MCP266
    Kp_position,
    Ki_position,
    Kd_position,

    Kp, //legacy
    Ki, //legacy
    Kd, //legacy
    PID_Setpoint, //for motion planner (read only) - legacy

    Target_X,
    Target_Y,
    Target_Z,

    Target_X_Offset,
    Target_Y_Offset,
    Target_Z_Offset,

    Field_Length, //in mm
    Field_Width, //in mm

    Current_Encoder_Count, //in mm
    Current_PWM, //in percent
    

    //legacy
    Current_RPM,
    Homing_Flag,
    Homing_switch,

    Current_X,
    Current_Y,
    Current_Z,

    Current_Length_Winch0, //in mm
    Current_Length_Winch1, 
    Current_Length_Winch2, 
    Current_Length_Winch3, 

    Target_Length_Winch0, //in mm
    Target_Length_Winch1,
    Target_Length_Winch2,
    Target_Length_Winch3,

    Current_Force_Winch0, //in gram
    Current_Force_Winch1,
    Current_Force_Winch2,
    Current_Force_Winch3,

    ADC0, //legacy
    ADC1,
    ADC2,
    ADC3,

    Follow_Waypoints,
    Current_Waypoints_Pointer,
    Number_of_Waypoints,
    Dwell_Time,

    load_cell_neg, //negative force flag
    load_cell_H,
    load_cell_L,
    load_cell_zero, //tare
    load_cell_cal, //scalar
    load_cell_offset_H,
    load_cell_offset_L,
    
    //flags
    load_cell_error, //non responding ads1220 flag
    mcp266_error, //non-responding mcp266    
    underrun_error, //cable is not moving
    underload_error, //not enough tension on cable
    overload_error, //too much tension
    tether_reached_target, //will be set if the tether is within 20mm from target length

    minimum_duty_cycle, //minimum duty cycle for the motor to turn
    minimum_tension, // to avoid bird-nesting
    maximum_tension, //tension limit

    scaled_velocity,
    
    kinematics_test_X, //matt's section
    kinematics_test_Y,
    kinematics_test_Z,
    kinematics_test_U,
    kinematics_test_M,
    kinematics_test_N,

    kinematics_test_A,
    kinematics_test_B,
    kinematics_test_C,
    kinematics_test_D,

    modbus_master_test,

    fram_test_w,
    fram_test_r,

    interwinch_comms,
    sync,
    network_error,

    wifi_polling_time,


    //start of waypoints
    X1,
    Y1,
    Z1,
    X2,
    Y2,
    Z2, //etc..

    MB_HREGS  = 2048 
};

extern signed int modbus_holding_regs[MB_HREGS];

#endif /* MODBUS_REGS_H_ */


/* [] END OF FILE */
