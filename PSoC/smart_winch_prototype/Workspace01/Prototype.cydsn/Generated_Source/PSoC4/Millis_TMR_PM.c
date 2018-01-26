/*******************************************************************************
* File Name: Millis_TMR_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Millis_TMR.h"

static Millis_TMR_BACKUP_STRUCT Millis_TMR_backup;


/*******************************************************************************
* Function Name: Millis_TMR_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Millis_TMR_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Millis_TMR_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Millis_TMR_Sleep(void)
{
    if(0u != (Millis_TMR_BLOCK_CONTROL_REG & Millis_TMR_MASK))
    {
        Millis_TMR_backup.enableState = 1u;
    }
    else
    {
        Millis_TMR_backup.enableState = 0u;
    }

    Millis_TMR_Stop();
    Millis_TMR_SaveConfig();
}


/*******************************************************************************
* Function Name: Millis_TMR_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Millis_TMR_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Millis_TMR_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Millis_TMR_Wakeup(void)
{
    Millis_TMR_RestoreConfig();

    if(0u != Millis_TMR_backup.enableState)
    {
        Millis_TMR_Enable();
    }
}


/* [] END OF FILE */
