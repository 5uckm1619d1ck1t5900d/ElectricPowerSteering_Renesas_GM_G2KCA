/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the global RAM variable of MCU Driver                   */
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
 * V1.0.0:  02-Sep-2013 : Initial Version
 *
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. Mcu_GblRAMInitStatus is updated with values in
 *                           enum 'Mcu_RamStateType'
 *                        2. Mcu_GblResetStatusSaved is added since it is using
 *                           for internal API Mcu_SaveResetReason()
 *
 * V1.0.2:  08-Oct-2014 : As per CR008 and mantis #19850, Following change
 *                        is made,
 *                        1. Trace marking is added in the file
 *
 * V1.0.3:  05-Dec-2014 : As per CR076 and mantis #21577,#25069, following
 *                        changes are made,
 *                        1.Trailing spaces are removed from the file.
 *                        2.Mcu_GblResetStatusSaved moved to
 *                        section MCU_START_SEC_VAR_BOOLEAN from
 *                        MCU_START_SEC_VAR_NOINIT_UNSPECIFIED.
 *
 * V1.0.4:  28-Apr-2015 : Added code comments as per MO Review in Mantis
 *                        #27515
 */
/******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Included for global variable initialization values */
#include "Mcu_PBTypes.h"

/* Header file inclusion */
#include "Mcu_Ram.h"

/* Included for version check macro definitions and type definitions */
#include "Mcu.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_RAM_C_AR_RELEASE_MAJOR_VERSION    \
                                           MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_RAM_C_AR_RELEASE_MINOR_VERSION    \
                                           MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_RAM_C_AR_RELEASE_REVISION_VERSION  \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_RAM_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_RAM_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (MCU_RAM_AR_RELEASE_MAJOR_VERSION != MCU_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Major Version"
#endif /* (MCU_RAM_AR_RELEASE_MAJOR_VERSION !=
        *                              MCU_RAM_C_AR_RELEASE_MAJOR_VERSION)
        */

#if (MCU_RAM_AR_RELEASE_MINOR_VERSION != MCU_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Minor Version"
#endif /* (MCU_RAM_AR_RELEASE_MINOR_VERSION !=
        *                              MCU_RAM_C_AR_RELEASE_MINOR_VERSION)
        */

#if (MCU_RAM_AR_RELEASE_REVISION_VERSION != \
                                   MCU_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Ram.c : Mismatch in Release Revision Version"
#endif /* (MCU_RAM_AR_RELEASE_REVISION_VERSION != \
        *                           MCU_RAM_C_AR_RELEASE_REVISION_VERSION)
        */

#if (MCU_RAM_SW_MAJOR_VERSION != MCU_RAM_C_SW_MAJOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Software Major Version"
#endif /* (MCU_RAM_SW_MAJOR_VERSION != MCU_RAM_C_SW_MAJOR_VERSION) */

#if (MCU_RAM_SW_MINOR_VERSION != MCU_RAM_C_SW_MINOR_VERSION)
  #error "Mcu_Ram.c : Mismatch in Software Minor Version"
#endif /* (MCU_RAM_SW_MINOR_VERSION != MCU_RAM_C_SW_MINOR_VERSION) */

/******************************************************************************
**                         Global Data                                       **
******************************************************************************/
/* TRACE [R4, MCU200] */

/*To use VAR_NOINIT section in the Memory*/
#define MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the config pointer */
P2CONST(Mcu_ConfigType, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpConfigPtr;

/* Global pointer variable for MCU Clock Setting configuration */
P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpClockSetting;

/* Global pointer variable for MCU ECM Setting configuration */
P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpEcmSetting;

/* Global pointer variable for MCU RAM Setting configuration */
P2CONST(Mcu_RamSetting, MCU_VAR, MCU_CONFIG_CONST) Mcu_GpRamSetting;

/*Exit VAR_NOINIT section in the Memory*/
#define MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*To use VAR_BOOLEAN section in the Memory*/
#define MCU_START_SEC_VAR_BOOLEAN
#include "MemMap.h"


/* Global variable to store Initialization status of MCU Driver */
VAR(boolean, MCU_INIT_DATA) Mcu_GblDriverStatus = MCU_UNINITIALIZED;

VAR(boolean, MCU_INIT_DATA)Mcu_GblResetStatusSaved = MCU_FALSE;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/* Global variable to store ram status of MCU Driver */
VAR(boolean, MCU_INIT_DATA) Mcu_GblRAMInitStatus = (boolean) MCU_RAMSTATE_VALID;
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/*Exit VAR_BOOLEAN section in the Memory*/
#define MCU_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*To use VAR_32 section in the Memory*/
#define MCU_START_SEC_VAR_32
#include "MemMap.h"

/* Global variable to store Last Reset reason status of MCU Driver */
VAR(uint32, MCU_INIT_DATA)Mcu_GulLastResetReasonStatus = MCU_ZERO;

/* Global variable to save RESF status of MCU Driver */
VAR(uint32, MCU_INIT_DATA)Mcu_GulMcuSavedResfStatus = MCU_ZERO;

/*To use VAR_32 section in the Memory*/
#define MCU_STOP_SEC_VAR_32
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
