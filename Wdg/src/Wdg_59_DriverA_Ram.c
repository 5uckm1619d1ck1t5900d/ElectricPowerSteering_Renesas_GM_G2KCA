/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Ram.c                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Watchdog Driver A                      */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.2:  02-Jan-2014    : As per CR 334 and mantis #13043, global variable
 *                           Wdg_59_DriverA_GusTiggerCounter placed under memory
 *                           section WDG_59_DRIVERA_START_SEC_VAR_NOINIT_16BIT.
 *
 * V1.0.3:  16-Jan-2014    : As per CR 350 and mantis #13043, pre-compile is
 *                           added for inclusion of global variable
 *                           Wdg_59_DriverA_GusTiggerCounter.
 *
 * V1.0.4:  03-Jun-2014    : As per CR 490 for mantis 21269, following changes
 *                           are made:
 *                           1. Wdg_59_DriverA_GulIMR1Mirror and
 *                           Wdg_59_DriverA_GulIMR1Mask global variables are
 *                           added.
 *                           2. Wdg_59_DriverA_PBTypes.h and
 *                              Wdg_59_DriverA_RegReadBack.h are included.
 *
 * V1.0.5:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.                   
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R3, WDG061] */
/* TRACE [R4, WDG168] */
/* Included for module version information and other types declarations */
#include "Wdg_59_DriverA.h"
/* Header file inclusion */
#include "Wdg_59_DriverA_Ram.h"
/* Header file inclusion for macro definitions */
#include "Wdg_59_DriverA_PBTypes.h"
/* Header file inclusion for read-back global variable */
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
#if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                        WDG_59_DRIVERA_READBACK_INIT_ONLY) || \
   (WDG_59_DRIVERA_READBACK_OPTION == \
                                 WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

#include "Wdg_59_DriverA_RegReadBack.h"
#endif
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version information */
#define WDG_59_DRIVERA_RAM_C_AR_MAJOR_VERSION  \
                                         WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_MINOR_VERSION  \
                                         WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_AR_PATCH_VERSION  \
                                         WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
#define WDG_59_DRIVERA_RAM_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_RAM_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#if (WDG_59_DRIVERA_RAM_AR_RELEASE_MAJOR_VERSION != \
                                  WDG_59_DRIVERA_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_RELEASE_MINOR_VERSION != \
                                  WDG_59_DRIVERA_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_RELEASE_REVISION_VERSION != \
                               WDG_59_DRIVERA_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Release Revision Version"
#endif

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (WDG_59_DRIVERA_RAM_AR_MAJOR_VERSION != \
                          WDG_59_DRIVERA_RAM_C_AR_MAJOR_VERSION)
  #error "WDG_59_DriverA_Ram.c : Mismatch in Specification Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_MINOR_VERSION != \
                          WDG_59_DRIVERA_RAM_C_AR_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Specification Minor Version"
#endif

#if (WDG_59_DRIVERA_RAM_AR_PATCH_VERSION != \
                          WDG_59_DRIVERA_RAM_C_AR_PATCH_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Specification Patch Version"
#endif
#endif

#if (WDG_59_DRIVERA_RAM_SW_MAJOR_VERSION != \
                                          WDG_59_DRIVERA_RAM_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_RAM_SW_MINOR_VERSION != \
                                          WDG_59_DRIVERA_RAM_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#define WDG_59_DRIVERA_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the current watchdog driver state */
VAR(Wdg_59_DriverA_StatusType, WDG_59_DRIVERA_INIT_DATA)
                          Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_UNINIT;

#define WDG_59_DRIVERA_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#endif

#define WDG_59_DRIVERA_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store the current watchdog driver mode */
VAR(WdgIf_ModeType, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GddCurrentMode;

/* Global variable to store pointer to Configuration */
P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC,
                        WDG_59_DRIVERA_CONFIG_CONST)Wdg_59_DriverA_GpConfigPtr;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
#define WDG_59_DRIVERA_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

/* Global variable to store the trigger counter value */
VAR(uint16, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GusTiggerCounter;

#define WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

#endif /*#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)*/

#if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                        WDG_59_DRIVERA_READBACK_INIT_ONLY) || \
   (WDG_59_DRIVERA_READBACK_OPTION == \
                                 WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

 #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define WDG_59_DRIVERA_START_SEC_VAR_NOINIT_32
#include "MemMap.h"

/* External declarations for the variable for IMR1 register */
VAR(uint32, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GulIMR1Mirror;

/* External declarations for the variable for IMR1 mask value */
VAR(uint32, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GulIMR1Mask;
/* Functionality related to R4.0 */
#define WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#endif
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
