/*
 * This library was taken from https://www.cooking-hacks.com/documentation/tutorials/modbus-module-shield-tutorial-for-arduino-raspberry-pi-intel-galileo/
 * Ported from C++ to C by Afdhal Atiff Tan on 8th November 2017.
*/
    
#ifndef MODBUS_SLAVE_232H
#define MODBUS_SLAVE_232H
/****************************************************************************
 * 
 * ModbusSlave library implementing a Modbus RTU Slave for Arduino
 * Modified by S.Marco. mailto:sammarcoarmengol@gmail.com
 * Based on the work published by jpmzometa at 
 * http://sites.google.com/site/jpmzometa/arduino-mbrt
 * 
 * Based also on http://pcscada.com.au by P.Costigan email: phil@pcscada.com.au
 * 
 * These library of functions are designed to enable a program send and
 * receive data from a device that communicates using the Modbus protocol.
 * 
 * Copyright (C) 2000 Philip Costigan  P.C. SCADA LINK PTY. LTD.
 * 
 * This file is part of ModbusSlave.
 * 
 * ModbusSlave is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * 
 * 
 * The functions included here have been derived from the 
 * Modbus Specifications and Implementation Guides
 * 
 * http://www.modbus.org/docs/Modbus_over_serial_line_V1_02.pdf
 * http://www.modbus.org/docs/Modbus_Application_Protocol_V1_1b.pdf
 * http://www.modbus.org/docs/PI_MBUS_300.pdf
 * 
 ****************************************************************************/

/****************************************************************************
 * BEGIN MODBUS RTU SLAVE FUNCTIONS
 ****************************************************************************/

#include "includes.h"

  extern unsigned char modbusRTU_Written;
  extern unsigned char DEBUGGING;

  //to do: change this to struct
  //extern unsigned long modbusRTU_written_register_flags;
  extern bool modbusRTU_written_register_flags[128];

/*
 * update(regs, regs_size)
 * 
 * checks if there is any valid request from the modbus master. If there is,
 * performs the requested action
 * 
 * regs: an array with the holding registers. They start at address 1 (master point of view)
 * regs_size: total number of holding registers, i.e. the size of the array regs.
 * returns: 0 if no request from master,
 * 	NO_REPLY (-1) if no reply is sent to the master
 * 	an exception code (1 to 4) in case of a modbus exceptions
 * 	the number of bytes sent as reply ( > 4) if OK.
 */
  int modbusRTU_Update(unsigned char slave_id, int *regs, unsigned int regs_size); //lora
  int modbusRTU_Update_2(unsigned char slave_id, int *regs, unsigned int regs_size); //wifi

  //used to init all flags to zero
  void modbusRTU_init();

#endif
