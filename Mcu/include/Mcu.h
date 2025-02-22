/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, MCU type definitions, structure data types and  */
/* API function prototypes of MCU Driver                                      */
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
 *                        1. extern declaration of MCU_RESET_CALLOUT API is
 *                           added.
 *                        2. Mcu_ProtectedWrite and Mcu_ReadBackDiagTest is
 *                           implemented in macros.
 *                        3. MCU_RAM_SECTOR_SETTING_CONFIGURED precompile
 *                           option is added for Mcu_InitRamSection API
 *                           declaration.
 *
 * V1.0.2:  07-Oct-2014 : As per CR008 and mantis #19850,
 *                        Following changes are made,
 *                        1. MCU_E_PARAM_MODE macro definition is added.
 *                        2. Mcu_ProtectedWriteRetNone macro is added.
 *                        3. Trace marking is added in the file.
 *
 * V1.0.3:  28-Apr-2015 : 1. Added code comments as per MO Review in Mantis
 *                          #27515
 *                        2. Added Justification for MISRA Violation:
 *                           START Msg(4:3412)
 */
/******************************************************************************/

#ifndef MCU_H
/*Defining MCU_H to avoid multiple inclusion*/
#define MCU_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* To publish the type Mcu_ConfigType */
/* TRACE [R4, MCU215] */
/* TRACE [R4, MCU211] */
#include "Mcu_Types.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
/* TRACE [R4, MCU201] */
#include "Mcu_Debug.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Version Information                                  **
*******************************************************************************/
#define MCU_VENDOR_ID    MCU_VENDOR_ID_VALUE
#define MCU_MODULE_ID    MCU_MODULE_ID_VALUE
#define MCU_INSTANCE_ID  MCU_INSTANCE_ID_VALUE

/* AUTOSAR release version information */
#define MCU_AR_RELEASE_MAJOR_VERSION    4
#define MCU_AR_RELEASE_MINOR_VERSION    0
#define MCU_AR_RELEASE_REVISION_VERSION 3

/* Module Software version information */
#define MCU_SW_MAJOR_VERSION       MCU_SW_MAJOR_VERSION_VALUE
#define MCU_SW_MINOR_VERSION       MCU_SW_MINOR_VERSION_VALUE
#define MCU_SW_PATCH_VERSION       MCU_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3458) Macro defines a braced code statement block.      */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3458)-1 and END Msg(4:3458)-1         */
/*                 tags in the code.                                          */
/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3684) Array declared with unknown size.                 */
/*Rule           : MISRA-C:2004 Rule 1.2                                      */
/*Justification  : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3684)-2 and END Msg(4:3684)-2         */
/*                 tags in the code.                                          */
/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3412) Macro defines an unrecognized code-fragment.      */
/*Rule           : MISRA-C:2004 Rule 19.4                                     */
/*Justification  : The APIs Mcu_ProtectedWrite, Mcu_ReadBackDiagTest,         */
/*                 Mcu_ProtectedWriteRetNone are implemented as Macros        */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3412)-1 and END Msg(4:3412)-1         */
/*                 tags in the code.                                          */
/******************************************************************************/

/*******************************************************************************
**                      API service ID Macros                                 **
*******************************************************************************/
/* Service IDs */
/* Service Id of Mcu_Init API */
#define MCU_INIT_SID                        (uint8)0x00

/* Service Id of Mcu_InitRamSection API */
#define MCU_INITRAMSECTION_SID              (uint8)0x01

/* Service Id of Mcu_InitClock API */
#define MCU_INITCLOCK_SID                   (uint8)0x02

/* Service Id of Mcu_DistributePllClock API */
#define MCU_DISTRIBUTEPLLCLOCK_SID          (uint8)0x03

/* Service Id of Mcu_GetPllStatus API */
#define MCU_GETPLLSTATUS_SID                (uint8)0x04

/* Service Id of Mcu_GetResetReason API */
#define MCU_GETRESETREASON_SID              (uint8)0x05

/* Service Id of Mcu_GetResetRawValue API */
#define MCU_GETRESETRAWVAULE_SID            (uint8)0x06

/* Service Id of Mcu_PerformReset API */
#define MCU_PERFORMRESET_SID                (uint8)0x07

/* Service Id of Mcu_SetMode API */
#define MCU_SETMODE_SID                     (uint8)0x08

/* Service Id of Mcu_GetRamState API */
#define MCU_GETRAMSTATE_SID                 (uint8)0x0A

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* TRACE [R4, MCU112] */
/* TRACE [R4, MCU012] */
/* DET Code to report NULL pointer passed to Mcu_Init API */
#define MCU_E_PARAM_CONFIG            (uint8)0x0A

/* DET Code for invalid Clock Setting */
#define MCU_E_PARAM_CLOCK             (uint8)0x0B

/* DET Code for invalid mode Setting */
#define MCU_E_PARAM_MODE              (uint8)0x0C

/* DET Code for invalid RAM Section handle */
#define MCU_E_PARAM_RAMSECTION        (uint8)0x0D

/* DET Code to report that PLL Clock is not locked */
#define MCU_E_PLL_NOT_LOCKED          (uint8)0x0E

/* DET code to report uninitialized state */
#define MCU_E_UNINIT                  (uint8)0x0F

/* DET code to report invalid database */
#define MCU_E_INVALID_DATABASE        (uint8)0xED

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

#if (MCU_SW_RESET_CALL_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) MCU_RESET_CALLOUT (void);
#endif /* (MCU_SW_RESET_CALL_API == STD_ON) */

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
               (P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr);

#if (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
                                              (Mcu_RamSectionType RamSection);
#endif /* (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_ON) */

#if (MCU_INIT_CLOCK == STD_ON)
extern FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock
                                                 (Mcu_ClockType ClockSetting);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void);

extern FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void);

extern FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason (void);

extern FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void);

#if (MCU_PERFORM_RESET_API == STD_ON)
extern FUNC(void, MCU_PUBLIC_CODE) Mcu_PerformReset (void);
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

extern FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode);

/* TRACE [R4, MCU104] */
#if (MCU_VERSION_INFO_API == STD_ON)
/* TRACE [R4, MCU103] */
/* TRACE [R4, MCU149] */
/* TRACE [R4, MCU162] */
/* MISRA Violation: START Msg(4:3458)-1 */
#define Mcu_GetVersionInfo(versioninfo) \
{ \
  (versioninfo)->vendorID = (uint16)MCU_VENDOR_ID;  \
  (versioninfo)->moduleID = (uint16)MCU_MODULE_ID;  \
  (versioninfo)->sw_major_version = MCU_SW_MAJOR_VERSION; \
  (versioninfo)->sw_minor_version = MCU_SW_MINOR_VERSION; \
  (versioninfo)->sw_patch_version = MCU_SW_PATCH_VERSION; \
}
/* END Msg(4:3458)-1 */
#endif /* (MCU_VERSION_INFO_API == STD_ON) */

#if (MCU_GET_RAM_STATE_API == STD_ON)
extern FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState (void);
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/* MISRA Violation: START Msg(4:3412)-1 */
#define Mcu_ProtectedWrite(reg, value, preg, sreg, loopcount, retvalue) \
  do  \
  { \
    (preg) = MCU_WRITE_DATA;  \
    (reg) = (value);  \
    (reg) = ~(value); \
    (reg) = (value);  \
    (loopcount) = (loopcount) - MCU_ONE;  \
  }while ((MCU_ONE == (sreg)) && ((loopcount) > MCU_ONE));  \
  if (MCU_ONE == (sreg)) \
  { \
    Dem_ReportErrorStatus \
                      (MCU_E_WRITE_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED); \
    (retvalue) = E_NOT_OK; \
  } \
  else  \
  {\
   \
  }

#define Mcu_ReadBackDiagTest(regaddr, compdata, status) \
  if ((regaddr) != (compdata))  \
  { \
    Dem_ReportErrorStatus \
                       (MCU_E_WRITE_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED); \
    (status) = E_NOT_OK;  \
  } \
  else  \
  { \
  }

#define Mcu_ProtectedWriteRetNone(reg, value, preg, sreg, loopcount) \
  do  \
  { \
    (preg) = MCU_WRITE_DATA;  \
    (reg) = (value);  \
    (reg) = ~(value); \
    (reg) = (value);  \
    (loopcount) = (loopcount) - MCU_ONE;  \
  }while ((MCU_ONE == (sreg)) && ((loopcount) > MCU_ONE));  \
  if (MCU_ONE == (sreg))  \
  { \
    Dem_ReportErrorStatus \
                       (MCU_E_WRITE_TIMEOUT_FAILURE, DEM_EVENT_STATUS_FAILED); \
  } \
  else  \
  { \
  }
/*END Msg(4:3412)-1*/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* To use DBTOC DATA section in the Memory*/
#define MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-2 */
/* Structure for MCU Init configuration */
extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_GstConfiguration[];
/* END Msg(4:3684)-2 */
/*Exit use DBTOC DATA section in the Memory*/
#define MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* MCU_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
