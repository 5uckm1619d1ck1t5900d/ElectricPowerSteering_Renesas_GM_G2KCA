/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Irq.c                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the WDG Driver A Component                                */
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
 * V1.0.1:  29-Sep-2012    : As per SCR 020, if condition check is modified.
 *
 * V1.0.2:  23-Jan-2013    : As per SCR 068, in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR the pre-compile CAT2
 *                           interrupt condition is updated.
 *
 * V1.0.3:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.4:  27-Aug-2013    : As per CR 232 for mantis issue 12123 and 13035,
 *                           following changes are made:
 *                           1.Backslash removed for ANSI C code.
 *                           2.Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           3. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.5:  05-Mar-2014    : As per CR 422, critical section is added in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR.
 *
 * V1.0.6:  05-Jun-2014    : As per CR 490, source code has been modified in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR API to support the
 *                           functionality of clearing WUF flag in event wake
 *                           occurrence.
 *
 * V1.0.7:  10-Sep-2014    : As per CR 560 for mantis #22423, following changes
 *                           are made:
 *                           1.WdgWakeUp check is removed in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR API.
 *                           2. Renesas C coding guidelines for Equivalence
 *                           Test is taken care in comparing the variable with
 *                           constant, constant should be left hand side in
 *                           WDG_59_DRIVERA_ERROR_ISR API.
 *                           3. Macro WDG_59_DRIVERA_DEM_TYPE added in
 *                           WDG_59_DRIVERA_ERROR_ISR API for the removal of
 *                           MISRA violation with V8.1.1.
 *                           4. MISRA violation comments have been added for
 *                           MISRA Msg "(4:0303)-1".
 *
 * V1.0.8:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.                   
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG079] */
/* TRACE [R3, WDG079] */
/* TRACE [R4, WDG061] */
/* TRACE [R3, WDG061] */
/* Included for ISR functions declaration */
#include "Wdg_59_DriverA_Irq.h"
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for declaration of the function Wdg_59_DriverA_TriggerFunc() */
#include "Wdg_59_DriverA_Private.h"
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* Included for type definitions and macros */
#include "Wdg_59_DriverA_PBTypes.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version information */
#define WDG_59_DRIVERA_IRQ_C_AR_MAJOR_VERSION  \
                                         WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_AR_MINOR_VERSION  \
                                         WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_AR_PATCH_VERSION  \
                                         WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
#define WDG_59_DRIVERA_IRQ_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#if (WDG_59_DRIVERA_IRQ_AR_RELEASE_MAJOR_VERSION != \
                                  WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_IRQ_AR_RELEASE_MINOR_VERSION != \
                                  WDG_59_DRIVERA_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_IRQ_AR_RELEASE_REVISION_VERSION != \
                               WDG_59_DRIVERA_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Release Revision Version"
#endif

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (WDG_59_DRIVERA_IRQ_AR_MAJOR_VERSION != \
                          WDG_59_DRIVERA_IRQ_C_AR_MAJOR_VERSION)
  #error "WDG_59_DriverA_Irq.c : Mismatch in Specification Major Version"
#endif

#if (WDG_59_DRIVERA_IRQ_AR_MINOR_VERSION != \
                          WDG_59_DRIVERA_IRQ_C_AR_MINOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Specification Minor Version"
#endif

#if (WDG_59_DRIVERA_IRQ_AR_PATCH_VERSION != \
                          WDG_59_DRIVERA_IRQ_C_AR_PATCH_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Specification Patch Version"
#endif
#endif

#if (WDG_59_DRIVERA_IRQ_SW_MAJOR_VERSION != \
                                          WDG_59_DRIVERA_IRQ_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_IRQ_SW_MINOR_VERSION != \
                                         WDG_59_DRIVERA_IRQ_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA_Irq.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                         Global Data                                        **
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
** Function Name         : WDG_59_DRIVERA_TRIGGERFUNCTION_ISR
**
** Service ID            : NA
**
** Description           : This is 75 % Interrupt Service routines for the Wdg
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GusTiggerCounter.
**
** Functions Invoked     : Wdg_59_DriverA_TriggerFunc
**
** Registers Used        : None
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

/* TRACE [R4, WDG134] */
/* TRACE [R4, WDG135] */
/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR) || \
                              defined (WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR)
ISR(WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, WDG_59_DRIVERA_FAST_CODE)
                                  WDG_59_DRIVERA_TRIGGERFUNCTION_ISR(void)
#endif
{
  /* Check if WdgWakeUpFactor enabled  */
  #if (WDG_59_DRIVERA_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* MISRA Violation: START Msg(4:0303)-1 */
  WDG_59_DRIVERA_WUFC0 = WDG_59_DRIVERA_INT_MASKVALUE;
  /* END Msg(4:0303)-1 */
  #endif

  /* Check if the trigger counter has completed the timeout value requested */
  if (Wdg_59_DriverA_GusTiggerCounter > WDG_59_DRIVERA_ZERO)
  {
    /* TRACE [R4, WDG040] */
    /* TRACE [R3, WDG040] */
    /* Check if critical section protection is required */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
    #endif

    /* Decrement the trigger counter */
    Wdg_59_DriverA_GusTiggerCounter--;

    /* Check if critical section protection is required */
    /* TRACE [R4, WDG040] */
    /* TRACE [R3, WDG040] */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
    #endif

    /* Restart the WDG hardware */
    Wdg_59_DriverA_TriggerFunc();
  }
  else
  {
    /* No action required */
  }

}

#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name         : WDG_59_DRIVERA_ERROR_ISR
**
** Service ID            : NA
**
** Description           : This is NMI Interrupt Service routines for the Wdg
**                         hardware unit.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GddCurrentMode.
**
** Functions Invoked     : Dem_ReportErrorStatus.
**
** Registers Used        : None
*******************************************************************************/
#if (WDG_59_DRIVERA_ERR_MODE_SET == WDG_59_DRIVERA_NMI_MODE)
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERA_ERROR_CAT2_ISR) || \
                                        defined (WDG_59_DRIVERA_ERROR_CAT2_ISR)
ISR(WDG_59_DRIVERA_ERROR_CAT2_ISR)
#else
/* Defines the CAT1 interrupt mapping */
_INTERRUPT_ FUNC(void, WDG_59_DRIVERA_FAST_CODE)
                                            WDG_59_DRIVERA_ERROR_ISR(void)
#endif
{
  /* Check if WdgWakeUpFactor enabled  */
  #if (WDG_59_DRIVERA_WAKEUP_FACTOR_CLEAR_ISR == STD_ON)
  /* MISRA Violation: START Msg(4:0303)-1 */
  WDG_59_DRIVERA_WUFC0 = WDG_59_DRIVERA_NMI_MASKVALUE;
  /* END Msg(4:0303)-1 */
  #endif

  if (WDGIF_OFF_MODE != Wdg_59_DriverA_GddCurrentMode)
  {
    /* TRACE [R3, WDG012] */
    /* Report Error to DEM */
    Dem_ReportErrorStatus(WDG_59_DRIVERA_E_TRIGGER_TIMEOUT,
                              (WDG_59_DRIVERA_DEM_TYPE)DEM_EVENT_STATUS_FAILED);
  }
  else
  {
    #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
    /* Functionality related to R4.0 */
    /* TRACE [R3, WDG012] */
    /* Report Error to DEM */
    /* TRACE [R3, WDG016] */
    /* TRACE [R4, WDG016] */
    Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_FAILED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
    #elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
    /* Functionality related to R3.2 */
    Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_SWITCH_FAILED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
    #endif
  }
}
#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"
#endif /* #if (WDG_59_DRIVERA_ERR_MODE_SET == WDG_59_DRIVERA_NMI_MODE) */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
