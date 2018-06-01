/*
 * interwinch_comms.c
 *
 *  Created on: 25 May 2018
 *      Author: AfdhalAtiffTan
 */

#include "interwinch_comms.h"

uint32_t polling_time; //5000x200us = 1second 

//future: add independent safety flag
void check_network_health()
{
    static uint16_t active_winch_count;
      
    //count replies from other winches
    active_winch_count = 0;
    active_winch_count += modbusRTU_written_register_flags[Current_Force_Winch0];
    active_winch_count += modbusRTU_written_register_flags[Current_Force_Winch1];
    active_winch_count += modbusRTU_written_register_flags[Current_Force_Winch2];
    active_winch_count += modbusRTU_written_register_flags[Current_Force_Winch3];

    //reset timer on every successful packet exchange
    static uint32_t error_timestamp = 0;
    if(active_winch_count >= 3)
    {
        error_timestamp = systick();

        //clear flag
        modbusRTU_written_register_flags[Current_Force_Winch0] = 0;
        modbusRTU_written_register_flags[Current_Force_Winch1] = 0;
        modbusRTU_written_register_flags[Current_Force_Winch2] = 0;
        modbusRTU_written_register_flags[Current_Force_Winch3] = 0;
    }

    //if no complete response received within specified time, set a flag
    if(systick() - error_timestamp > (polling_time*30))
        modbus_holding_regs[network_error] = 1;    
    else
        modbus_holding_regs[network_error] = 0;
}

//broadcast cable length and cable tension to all winches
//future: add sync flag
void broadcast_status()
{
    // static unsigned char broadcast_turn = 0;

    if(modbus_holding_regs[Winch_ID]==0)
    {
        ModbusMaster_setTransmitBuffer(0, 1);
        ModbusMaster_writeMultipleRegisters(sync, 1);
    }

    ModbusMaster_setTransmitBuffer(0, modbus_holding_regs[Current_Length_Winch0 + modbus_holding_regs[Winch_ID]]);
    ModbusMaster_writeMultipleRegisters((Current_Length_Winch0 + modbus_holding_regs[Winch_ID]), 1);

    ModbusMaster_setTransmitBuffer(0, modbus_holding_regs[Current_Force_Winch0 + modbus_holding_regs[Winch_ID]]);
    ModbusMaster_writeMultipleRegisters((Current_Force_Winch0 + modbus_holding_regs[Winch_ID]), 1);  

    // switch (broadcast_turn)
    // {
    //     case 0:
    //     {
    //         ModbusMaster_setTransmitBuffer(0, modbus_holding_regs[Current_Length_Winch0 + modbus_holding_regs[Winch_ID]]);
    //         ModbusMaster_writeMultipleRegisters((Current_Length_Winch0 + modbus_holding_regs[Winch_ID]), 1);
    //         break;
    //     }
    //     case 1:
    //     {
    //         ModbusMaster_setTransmitBuffer(0, modbus_holding_regs[Current_Force_Winch0 + modbus_holding_regs[Winch_ID]]);
    //         ModbusMaster_writeMultipleRegisters((Current_Force_Winch0 + modbus_holding_regs[Winch_ID]), 1);  
    //         break;
    //     }
    // }
    
    // broadcast_turn += 1; //go to next turn 
    // broadcast_turn %= 2; //only to packets to be shared
}

void master_winch_comms()
{
    //future: add mesh timer
    static uint32_t prev_systick = 0;
    if (systick() - prev_systick > polling_time)
    {
        prev_systick = systick();
        broadcast_status();
    }
}

void slave_winch_comms()
{
    static bool monostable_state = 1;
    static uint32_t monostable_timestamp = 0;
    uint32_t mutiplexing_time = (polling_time/4) * modbus_holding_regs[Winch_ID];

    if (modbusRTU_written_register_flags[sync])
    {
        modbusRTU_written_register_flags[sync] = 0; //clear flag
        monostable_state = 0; //reset state
        monostable_timestamp = systick();
    }

    if(monostable_state == 0)
    {
        //broadcast once soon after multiplex turn comes
        if (systick() - monostable_timestamp > mutiplexing_time) 
        {
            monostable_state = 1;
            broadcast_status();
        }
    }
}

void interwinch_comms_handler()
{
    if(modbus_holding_regs[interwinch_comms])
    {
        polling_time = modbus_holding_regs[wifi_polling_time];
        
        if(modbus_holding_regs[Winch_ID] == 0)
            master_winch_comms();
        else
            slave_winch_comms();

        check_network_health();
    }    
}
