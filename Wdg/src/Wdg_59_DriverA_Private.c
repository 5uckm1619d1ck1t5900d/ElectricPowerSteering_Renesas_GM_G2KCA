/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Private.c                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Internal Watchdog Driver A Component                    */
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
 * V1.0.2:  12-Sep-2013    : As per CR 232 for mantis issue13035,
 *                           following changes are made:
 *                           1. Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           2. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.3:  20-May-2014    : As per CR 490 for mantis issue 21269, following
 *                           changes are made:
 *                           1. Register read back is implemented in API
 *                           "Wdg_59_DriverA_TriggerFunc" and Dem.h is included.
 *                           2. LucVacReadback variable added for read-back
 *                              value checking when VAC enabled.
 *
 * V1.0.4:  10-Sep-2014    : As per CR 560, MISRA message number "(4:0303)-1" is
 *                           updated as per QAC 8.1.1.
 *
 * V1.0.5:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.                   
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R3, WDG061] */
/* Included for type definitions and macros */
#include "Wdg_59_DriverA_PBTypes.h"
/* Header file inclusion */
#include "Wdg_59_DriverA_Private.h"
/* Included for RAM variable declarations */
#include "Wdg_59_DriverA_Ram.h"
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MAJOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MINOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_REVISION_VERSION \
                                WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version information */
#define WDG_59_DRIVERA_PRIVATE_C_AR_MAJOR_VERSION  \
                                         WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_MINOR_VERSION  \
                                         WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_AR_PATCH_VERSION  \
                                         WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
#define WDG_59_DRIVERA_PRIVATE_C_SW_MAJOR_VERSION \
                                           WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_C_SW_MINOR_VERSION \
                                           WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MAJOR_VERSION != \
                              WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MINOR_VERSION != \
                              WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_RELEASE_REVISION_VERSION != \
                           WDG_59_DRIVERA_PRIVATE_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Release Revision Version"
#endif

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (WDG_59_DRIVERA_PRIVATE_AR_MAJOR_VERSION != \
                          WDG_59_DRIVERA_PRIVATE_C_AR_MAJOR_VERSION)
  #error "WDG_59_DriverA_Private.c : Mismatch in Specification Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_MINOR_VERSION != \
                          WDG_59_DRIVERA_PRIVATE_C_AR_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Specification Minor Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_AR_PATCH_VERSION != \
                          WDG_59_DRIVERA_PRIVATE_C_AR_PATCH_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Specification Patch Version"
#endif
#endif

#if (WDG_59_DRIVERA_PRIVATE_SW_MAJOR_VERSION != \
                                     WDG_59_DRIVERA_PRIVATE_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_PRIVATE_SW_MINOR_VERSION != \
                                      WDG_59_DRIVERA_PRIVATE_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Private.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) [I] Cast between a pointer to volatile object and */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-1 and                           */
/*                 END Msg(4:0303)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_TriggerFunc
**
** Service ID            : Not Applicable
**
** Description           : This service is used to trigger the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState.
**
** Functions Invoked     : WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION
**
** Registers Used        : WDTAnMD, WDTAnEVAC.
*******************************************************************************/

#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

/* TRACE [R4, WDG144] */
FUNC(void, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_TriggerFunc(void)
{
  /* Variable to store VAC write value for read-back */
  #if (((WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_RUNTIME_ONLY) || \
  (WDG_59_DRIVERA_READBACK_OPTION == \
                                 WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME)) && \
                                  (WDG_59_DRIVERA_VAC_ALLOWED == STD_ON))
  uint8 LucVacReadback ;
  #endif

  #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
  /* Functionality related to R4.0 */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as busy */
  Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
  #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */
  #endif

  /* Check if critical section protection is required */
  /* TRACE [R4, WDG040] */
  /* TRACE [R3, WDG040] */
  #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
  WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
  #endif

  /* Check whether Varying Activation Code is enabled */
  #if (WDG_59_DRIVERA_VAC_ALLOWED == STD_OFF)
  /* MISRA Violation: START Msg(4:0303)-1 */
  /* Initialize the register with preconfigured value */
  WDG_59_DRIVERA_WDTAWDTE_ADDRESS = WDG_59_DRIVERA_RESTART;

  /* ReadBackTest for configured Register */
  #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_RUNTIME_ONLY) || \
  (WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

  WDG_59_DRIVERA_READBACKTEST(WDG_59_DRIVERA_WDTAWDTE_ADDRESS,
                                                        WDG_59_DRIVERA_RESTART)
  /* END Msg(4:0303)-1 */
  #endif  /* WDG_59_DRIVERA_READBACK_OPTION  */

  #else

   /* MISRA Violation: START Msg(4:0303)-1 */
  #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                     WDG_59_DRIVERA_READBACK_RUNTIME_ONLY) || \
  (WDG_59_DRIVERA_READBACK_OPTION == WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))
  LucVacReadback = (WDG_59_DRIVERA_RESTART - WDG_59_DRIVERA_WDTAREF_ADDRESS);
  #endif

  /* Initialize VAC register */
  WDG_59_DRIVERA_WDTAEVAC_ADDRESS = WDG_59_DRIVERA_RESTART -
                                              WDG_59_DRIVERA_WDTAREF_ADDRESS;
  /* ReadBackTest for configured Register */
  #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                     WDG_59_DRIVERA_READBACK_RUNTIME_ONLY) || \
   (WDG_59_DRIVERA_READBACK_OPTION == WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

  WDG_59_DRIVERA_READBACKTEST(WDG_59_DRIVERA_WDTAEVAC_ADDRESS, LucVacReadback)
  /* END Msg(4:0303)-1 */
  #endif  /* WDG_59_DRIVERA_READBACK_OPTION  */

  #endif /* WDG_59_DRIVERA_VAC_ALLOWED == STD_OFF */

  /* Check if critical section protection is required */
  /* TRACE [R4, WDG040] */
  /* TRACE [R3, WDG040] */
  #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
  WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
  #endif

  #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
  /* Functionality related to R4.0 */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Set the state of Watchdog as idle */
  Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
  #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */
  #endif
}
#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
