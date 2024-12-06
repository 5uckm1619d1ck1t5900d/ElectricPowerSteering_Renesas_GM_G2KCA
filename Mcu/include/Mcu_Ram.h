/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Ram.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of MCU  */
/* Driver                                                                     */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2013 : Initial Version.
 *
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. Mcu_GblResetStatusSaved is added since it is using
 *                           for internal API Mcu_SaveResetReason()
 *
 * V1.0.2:  07-Oct-2014 : As per CR008 and mantis #19850, Following
 *                        changes is made,
 *                        1. Pre-compile checking for variable
 *                           Mcu_GblDriverStatus is removed.
 *
 * V1.0.3:  08-Dec-2014 : As per CR076 and mantis #25069,#21577, following
 *                        changes are made,
 *                        1.Mcu_GblResetStatusSaved moved to
 *                        section MCU_START_SEC_VAR_BOOLEAN from
 *                        MCU_START_SEC_VAR_NOINIT_UNSPECIFIED.
 *
 * V1.0.4:  28-Apr-2015 : Added code comments as per MO Review in Mantis
 *                        #27515
 */
/******************************************************************************/

#ifndef MCU_RAM_H
/*Defining RAM_H to avoid multiple inclusion*/
#define MCU_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
/* AUTOSAR specification version information */

#define MCU_RAM_AR_RELEASE_MAJOR_VERSION      MCU_AR_RELEASE_MAJOR_VERSION
#define MCU_RAM_AR_RELEASE_MINOR_VERSION      MCU_AR_RELEASE_MINOR_VERSION
#define MCU_RAM_AR_RELEASE_REVISION_VERSION   MCU_AR_RELEASE_REVISION_VERSION

/* File version information */
#define MCU_RAM_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION
#define MCU_RAM_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*To use VAR NOINIT UNSPECIFIED section in the Memory*/
#define MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the config pointer */
extern P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
extern P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpClockSetting;

/* Global pointer variable for MCU ECM Setting configuration */
extern P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpEcmSetting;

/* Global pointer variable for MCU RAM Setting configuration */
extern P2CONST(Mcu_RamSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpRamSetting;

/*Exit VAR NOINIT UNSPECIFIED section in the Memory*/
#define MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*To use VAR BOOLEAN section in the Memory*/
#define MCU_START_SEC_VAR_BOOLEAN
#include "MemMap.h"

/* Global variable to store Initialization status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblDriverStatus;

/* Global variable to store Reset status of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblResetStatusSaved;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/* Global variable to store ram state of MCU Driver */
extern VAR(boolean, MCU_INIT_DATA) Mcu_GblRAMInitStatus;
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/*Exit VAR BOOLEAN section in the Memory*/
#define MCU_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*To use VAR32 section in the Memory*/
#define MCU_START_SEC_VAR_32
#include "MemMap.h"

/* Global variable to store Last Reset reason status */
extern VAR(uint32, MCU_INIT_DATA)Mcu_GulLastResetReasonStatus;
/* Global variable to save resf register status. */
extern VAR(uint32, MCU_INIT_DATA)Mcu_GulMcuSavedResfStatus;

/*Exit VAR32 section in the Memory*/
#define MCU_STOP_SEC_VAR_32
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
