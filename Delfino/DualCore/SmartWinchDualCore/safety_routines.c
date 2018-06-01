/*
 * safety_routines.c
 *
 *  Created on: 4 Apr 2018
 *      Author: AfdhalAtiffTan
 */

#include "safety_routines.h"



/*
underrun
watchdog
overload
underload
*/

void motor_driving_with_safety_check()
{
    if(dip_switch.BIT5) //bypass safety check
    {
        //flag=1 means command will be executed immediately, i.e. previous task will be halted
        //speed and accelerations are in qpps unit
        RoboClaw_SpeedAccelDeccelPositionM1(RoboClaw_Address, 
                                            length_to_encoder_pulses(modbus_holding_regs[Max_Acceleration]), 
                                            length_to_encoder_pulses(modbus_holding_regs[scaled_velocity]) * homing_workaround, 
                                            length_to_encoder_pulses(modbus_holding_regs[Max_Acceleration]),
                                            length_to_encoder_pulses(modbus_holding_regs[Target_Setpoint]), 1);
    }
    else //enable safety checks
    {
        //force stop
        if (modbus_holding_regs[load_cell_error] ||
            modbus_holding_regs[mcp266_error]    )
        {
            RoboClaw_ForwardM1(RoboClaw_Address, 0x00);
        }
        else
        {
            static uint32_t overload_timer = 0;
            //if there is an overload condition, loosen the current cable lengths
            if ((modbus_holding_regs[overload_error] != 0) && (modbus_holding_regs[load_cell_zero] == LOAD_CELL_ZEROED))
            {
                modbus_holding_regs[Target_Setpoint] = modbus_holding_regs[Current_Encoder_Count] + 50;
                if(systick() - overload_timer > 10000) //if overload condition is more than 2 seconds
                {
                    RoboClaw_ForwardM1(RoboClaw_Address, 0x20); //30% forward
                    DEVICE_DELAY_US(2000000); //release tether for 2 sec

                    RoboClaw_ForwardM1(RoboClaw_Address, 0x00);
                    RoboClaw_ForwardM1(RoboClaw_Address, 0x00);

                    //force mcp266 down                    
                    GPIO_setPadConfig(DEVICE_GPIO_PIN_EMERGENCY_STOP, GPIO_PIN_TYPE_OD);                
                    GPIO_setDirectionMode(DEVICE_GPIO_PIN_EMERGENCY_STOP, GPIO_DIR_MODE_OUT);
                    GPIO_writePin(DEVICE_GPIO_PIN_EMERGENCY_STOP, 0);
                    DEVICE_DELAY_US(200000);
                    SysCtl_resetDevice();
                }                
            }
            else
            {
                overload_timer = systick();

                if(modbus_holding_regs[underload_error])
                    RoboClaw_ForwardM1(RoboClaw_Address, 0x00);
                else
                {
                    if(modbus_holding_regs[underrun_error])
                        RoboClaw_ForwardM1(RoboClaw_Address, 0x00);
                    else
                    {
                        //flag=1 means command will be executed immediately, i.e. previous task will be halted
                        //speed and accelerations are in qpps unit
                        RoboClaw_SpeedAccelDeccelPositionM1(RoboClaw_Address, 
                                                            length_to_encoder_pulses(modbus_holding_regs[Max_Acceleration]), 
                                                            length_to_encoder_pulses(modbus_holding_regs[scaled_velocity]) * homing_workaround, 
                                                            length_to_encoder_pulses(modbus_holding_regs[Max_Acceleration]),
                                                            length_to_encoder_pulses(modbus_holding_regs[Target_Setpoint]), 1);
                    }
                }
            }
        } 
    }
}
