/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA.c                                            */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Driver code of the Watchdog Driver A Component                             */
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
 * V1.0.1:  29-Sep-2012    : As per SCR 020, all condition checks are modified.
 *
 * V1.0.2:  23-Jan-2013    : As per SCR 068, software version macros are
 *                           hard coded.
 *
 * V1.0.3:  07-Mar-2013    : As per SCR 109 for mantis issue 9625, following
 *                           change is made:
 *                           Mode register 'WDG_59_DRIVERA_WDTAMD_ADDRESS' is
 *                           updated for not disturbing 75% interrupt bit in
 *                           the API's Wdg_59_DriverA_Init and
 *                           Wdg_59_DriverA_SetMode.
 *
 * V1.0.4:  24-Apr-2013    : As per SCR 148 for mantis issue #9729, following
 *                           change is made:
 *                           Mode register 'WDG_59_DRIVERA_WDTAMD_ADDRESS' is
 *                           updated for not disturbing 75% interrupt bit,
 *                           NMI and Reset mode in the API's Wdg_59_DriverA_Init
 *                           and Wdg_59_DriverA_SetMode.
 *
 * V1.0.5:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.6:  27-Aug-2013    : As per CR 232 for mantis issue 12123, backslash
 *                           removed for ANSI C code.
 *
 * V1.0.7:  14-Oct-2013    : As per CR 263, WDG_59_DRIVERA_ENB_INTVECTAB_MODE
 *                           macro added in Wdg_59_DriverA_Init API for 75%
 *                           interrupt.
 *
 * V1.0.8:  05-Mar-2014    : As per CR 422 for mantis issue 18651, following
 *                           change is made:
 *                           1. critical section is added in
 *                           Wdg_59_DriverA_Init, Wdg_59_DriverA_SetMode and
 *                           Wdg_59_DriverA_SetTriggerCondition API's.
 *                           2. WDG_59_DRIVERA_ENB_INTVECTAB_MODE macro removed
 *                           in Wdg_59_DriverA_Init API.
 *
 * V1.0.9:  24-Apr-2014    : As per CR 490 for mantis #21269, #17424 and 20814
 *                           following changes are made:
 *                           1. Updated the write operation of supervisor
 *                           mode(SV)write enabled Register IMR and
 *                           rh850_Types.h is included.
 *                           2. Register read-back is implemented in API's
 *                           "Wdg_59_DriverA_Init" and "Wdg_59_DriverA_SetMode".
 *                           3. Redundant macro WDG_59_DRIVERA_ENB_NMI_INT is
 *                           removed from Wdg_59_DriverA_Init API.
 *                           4. The mode check (Mode > WDGIF_FAST_MODE) is
 *                           replaced with (Mode > WDGIF_FAST_MODE ||
 *                           (Mode < WDGIF_OFF_MODE) in Wdg_59_DriverA_SetMode
 *                            API.
 *                           5. MISRA violation comments have been updated for
 *                              MISRA Msg "(7:0872)-5".
 *
 * V1.0.10:  16-Jun-2014   : As per CR 520, following changes are made:
 *                           1. Wdg_59_DriverA_RegReadBack.h is added in include
 *                              section.
 *                           2. WDG_59_DRIVERA_READBACKTEST_IMR macro is added
 *                              in initialization API.
 *
 * V1.0.11:  10-Sep-2014   : As per CR 560 for mantis #22421, following changes
 *                           are made:
 *                           1. Renesas C coding guidelines for Equivalence
 *                           Test is taken care in comparing the variable with
 *                           constant, constant should be left hand side in all
 *                           API.
 *                           2. In Wdg_59_DriverA_SetMode API critical section
 *                           is added.
 *                           3. Macro WDG_59_DRIVERA_DEM_TYPE added in
 *                           Wdg_59_DriverA_SetMode for the removal of MISRA
 *                           violation with V8.1.1.
 *                           4. Redundant MISRA C rule violations message are
 *                           removed.
 *                           5. MISRA message number "(4:0303)-1" is updated as
 *                           per QAC 8.1.1.
 *                           6. MISRA message number "(4:4397)-2" is updated as
 *                           per QAC 8.1.1.
 *
 * V1.0.12:  03-Feb-2015   : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.                   
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG061] */
/* TRACE [R3, WDG061] */
/* TRACE [R4, WDG169] */
/* TRACE [R4, WDG161] */
/* Included for Wdg_59_DriverA.h inclusion and macro definitions */
#include "Wdg_59_DriverA_PBTypes.h"

#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
/* TRACE [R4, WDG063] */
/* TRACE [R3, WDG063] */
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif
#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Wdg_59_DriverA.h"
#endif
/* TRACE [R4, WDG080] */
/* TRACE [R3, WDG080] */
/* TRACE [R4, WDG062] */
/* TRACE [R3, WDG062] */
/* TRACE [R4, WDG110] */
/* TRACE [R3, WDG110] */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for RAM variable declarations */
#include "Wdg_59_DriverA_Ram.h"
/* Included for declaration of the function Wdg_59_DriverA_TriggerFunc() */
#include "Wdg_59_DriverA_Private.h"
/* Included for declaration of the SV enabled registers write operation */
#include "rh850_Types.h"
/* Included for declaration of global variables for register readback */
#include "Wdg_59_DriverA_RegReadBack.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_C_AR_RELEASE_MAJOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_RELEASE_MINOR_VERSION \
                                   WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_RELEASE_REVISION_VERSION \
                                WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* AUTOSAR specification version information */
#define WDG_59_DRIVERA_C_AR_MAJOR_VERSION  WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_MINOR_VERSION  WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_C_AR_PATCH_VERSION  WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
#define WDG_59_DRIVERA_C_SW_MAJOR_VERSION  1
#define WDG_59_DRIVERA_C_SW_MINOR_VERSION  0
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#if (WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION != \
                                      WDG_59_DRIVERA_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION != \
                                      WDG_59_DRIVERA_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION != \
                                   WDG_59_DRIVERA_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Release Revision Version"
#endif

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (WDG_59_DRIVERA_AR_MAJOR_VERSION != WDG_59_DRIVERA_C_AR_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Specification Major Version"
#endif

#if (WDG_59_DRIVERA_AR_MINOR_VERSION != WDG_59_DRIVERA_C_AR_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Specification Minor Version"
#endif

#if (WDG_59_DRIVERA_AR_PATCH_VERSION != WDG_59_DRIVERA_C_AR_PATCH_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Specification Patch Version"
#endif
#endif

#if (WDG_59_DRIVERA_SW_MAJOR_VERSION != WDG_59_DRIVERA_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_SW_MINOR_VERSION != WDG_59_DRIVERA_C_SW_MINOR_VERSION)
  #error "Wdg_59_DriverA.c : Mismatch in Software Minor Version"
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

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex bitwise*/
/*                 operations.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-2 and                           */
/*                 END Msg(4:4397)-2 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_Init
**
** Service ID            : 0x00
**
** Description           : This service initialize the Watchdog driver and
**                         hardware.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr Pointer to the configuration
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Wdg_59_DriverA_GpConfigPtr,
**                         Wdg_59_DriverA_GusTiggerCounter,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GulIMR1Mirror,
**                         Wdg_59_DriverA_GulIMR1Mask.
**
** Functions Invoked     : Det_ReportError,
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION,
**                         Wdg_59_DriverA_TriggerFunc.
**
** Registers Used        : IMRn, WDTAnMD.
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, WDG106] */
/* TRACE [R3, WDG106] */
FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_Init
(P2CONST(Wdg_59_DriverA_ConfigType, AUTOMATIC, WDG_59_DRIVERA_APPL_CONST)
  ConfigPtr)
{
  /* TRACE [R4, WDG065] */
  /* TRACE [R3, WDG065] */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R4, WDG089] */
  /* TRACE [R3, WDG089] */
  /* Report Error to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /* TRACE [R4, WDG111] */
    /* TRACE [R3, WDG111] */
    /* Report Error to DET */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                 WDG_59_DRIVERA_INIT_SID, WDG_59_DRIVERA_E_PARAM_CONFIG);
  }
  else
  #endif /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether the existing database is correct */
    /* MISRA Violation: START Msg(4:4397)-2 */
    if (WDG_59_DRIVERA_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(4:4397)-2 */
    {
      /* Assign the config pointer value to global pointer */
      Wdg_59_DriverA_GpConfigPtr = ConfigPtr;

      #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
      /* Functionality related to R4.0 */
      /* TRACE [R4, WDG040] */
      /* TRACE [R3, WDG040] */
      /* Check if critical section protection is required */
      #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
      WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
      #endif

      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Enable the 75 percent interrupt output */
      RH850_SV_MODE_IMR_AND(32, WDG_59_DRIVERA_INTWDTIMR_ADDR,
                                                 WDG_59_DRIVERA_INTWDTIMR_MASK);

      #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                         WDG_59_DRIVERA_READBACK_INIT_ONLY) || \
      (WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

      /* TRACE [R4, WDG100] */
      /* TRACE [R3, WDG100] */
      /* IMR mirror global variable */
      Wdg_59_DriverA_GulIMR1Mirror = (*((volatile uint32 *)
             WDG_59_DRIVERA_INTWDTIMR_ADDR) & ~(WDG_59_DRIVERA_INTWDTIMR_MASK));

      /* IMR mask value global variable */
      Wdg_59_DriverA_GulIMR1Mask = ~(WDG_59_DRIVERA_INTWDTIMR_MASK);

      WDG_59_DRIVERA_READBACKTEST_IMR(*((volatile uint32 *)
                 WDG_59_DRIVERA_INTWDTIMR_ADDR), WDG_59_DRIVERA_INTWDTIMR_MASK,
                   Wdg_59_DriverA_GulIMR1Mirror)
      #endif

      /* END Msg(4:0303)-1 */
      /* Check if critical section protection is required */
      /* TRACE [R4, WDG040] */
      /* TRACE [R3, WDG040] */
      #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
      WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
      #endif

      #endif
      /* Check whether Watchdog disable is allowed */
      #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON)
      /* To check whether the default mode is not OFF mode */
      if (WDGIF_OFF_MODE != Wdg_59_DriverA_GpConfigPtr->ddWdtamdDefaultMode)
      #endif
      {
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* MISRA Violation: START Msg(4:0303)-1 */
        /* TRACE [R4, WDG001] */
        /* TRACE [R3, WDG001] */
        /* TRACE [R4, WDG101] */
        /* TRACE [R3, WDG101] */
        /* Set Default mode value to Mode register */
        WDG_59_DRIVERA_WDTAMD_ADDRESS =
            (Wdg_59_DriverA_GpConfigPtr->ucWdtamdDefaultValue |
            (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK));

        /* ReadBackTest for configured Register */
        #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                     WDG_59_DRIVERA_READBACK_INIT_ONLY) || \
        (WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

        WDG_59_DRIVERA_READBACKTEST(WDG_59_DRIVERA_WDTAMD_ADDRESS,
                           ((Wdg_59_DriverA_GpConfigPtr->ucWdtamdDefaultValue) |
            (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)))

        #endif

        /* END Msg(4:0303)-1 */
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
        /* Functionality related to R4.0 */
        /* Set the Initial trigger counter value */
        Wdg_59_DriverA_GusTiggerCounter =
                     Wdg_59_DriverA_GpConfigPtr->usInitTimerCountValue;
        #endif

        /* Call the Trigger Function which restarts the Watchdog hardware */
        Wdg_59_DriverA_TriggerFunc();
      }
      /* Check whether Watchdog disable is allowed */
      #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON)
      else
      {
        /* No action required */
      }
      #endif
      /* Set current mode */
      Wdg_59_DriverA_GddCurrentMode =
                              Wdg_59_DriverA_GpConfigPtr->ddWdtamdDefaultMode;

      /* Check if WDG_59_DRIVERA_DEV_ERROR_DETECT is enabled */
      #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R4, WDG019] */
      /* TRACE [R3, WDG019] */
      /* Set the state of Watchdog as idle */
      Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
      #endif
    } /* end of if (WDG_59_DRIVERA_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))*/
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    else
    {
      /* TRACE [R4, WDG090] */
      /* TRACE [R3, WDG090] */
      /* Report Error to DET */
      (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID,
      WDG_59_DRIVERA_INSTANCE_ID, WDG_59_DRIVERA_INIT_SID,
      WDG_59_DRIVERA_E_INVALID_DATABASE);
    } /* End of Check to check database */
    #endif
  }
}

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetMode
**
** Service ID            : 0x01
**
** Description           : This service change the mode of the Watchdog timer
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : WdgIf_ModeType  Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Std_ReturnType E_OK or E_NOT_OK
**
** Preconditions         : Wdg_59_DriverAInit must be called before this
**                         function.
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GusTiggerCounter.
**
** Functions Invoked     : Det_ReportError,
**                         Dem_ReportErrorStatus,
**                         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION,
**                         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION,
**                         Wdg_59_DriverA_TriggerFunc.
**
** Registers Used        : WDTAnMD.
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, WDG107] */
/* TRACE [R3, WDG107] */
/* TRACE [R4, WDG160] */
/* TRACE [R3, WDG102] */
FUNC(Std_ReturnType,  WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetMode
  (WdgIf_ModeType Mode)
{
  /* TRACE [R4, WDG105] */
  /* TRACE [R3, WDG105] */
  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* TRACE [R4, WDG017] */
  /* TRACE [R3, WDG017] */
  /* Report Error to DET, if state of Watchdog is not idle */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  if (WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState)
  {
    /* TRACE [R4, WDG010] */
    /* TRACE [R3, WDG010] */
    /* Report Error to DET */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_SETMODE_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether input parameter 'Mode' is within the range */
  if ((Mode > WDGIF_FAST_MODE) || (Mode < WDGIF_OFF_MODE))

  {
    /* TRACE [R4, WDG091] */
    /* TRACE [R3, WDG091] */
    /* TRACE [R4, WDG092] */
    /* TRACE [R3, WDG092] */
    /* Report Error to DET, if the parameter mode is not within the range */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_SETMODE_SID, WDG_59_DRIVERA_E_PARAM_MODE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;

  }
  else
  {
    /* No action required */
  }
  /* Check if any DET error was reported */
  if (E_OK == LenReturnValue)
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R4, WDG018] */
    /* TRACE [R3, WDG018] */
    /* Set the state of Watchdog as busy */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
    #endif

    if (WDGIF_OFF_MODE == Mode)
    {
      /* TRACE [R3, WDG012] */
      /* TRACE [R4, WDG025] */
      /* TRACE [R3, WDG025] */
      /* TRACE [R4, WDG026] */
      /* TRACE [R3, WDG026] */
      /* Report Error to DEM */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_DISABLE_REJECTED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    /* Check whether Watchdog disable is allowed */
    #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON)
    /* Switching the Watchdog Mode from OFF to SLOW */
    else if (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode)
    {

      /* Switching the Watchdog Mode from OFF to SLOW */
      if (WDGIF_SLOW_MODE == Mode)
      {
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* MISRA Violation: START Msg(4:0303)-1 */
        /* Set configured slow mode value to Mode register */
        WDG_59_DRIVERA_WDTAMD_ADDRESS =
            (Wdg_59_DriverA_GpConfigPtr->ucWdtamdSlowValue |
            (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK));
        /* ReadBackTest for configured Register */
        #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                     WDG_59_DRIVERA_READBACK_RUNTIME_ONLY) || \
        (WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

        WDG_59_DRIVERA_READBACKTEST(WDG_59_DRIVERA_WDTAMD_ADDRESS,
                                (Wdg_59_DriverA_GpConfigPtr->ucWdtamdSlowValue |
             (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)))
        #endif
        /* END Msg(4:0303)-1 */

        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
         #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
         #endif

         #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
         /* Functionality related to R4.0 */
         /* TRACE [R4, WDG145] */
         /* TRACE [R4, WDG040] */
         /* TRACE [R3, WDG040] */
         #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
         WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
         #endif

         /* Set the trigger counter value considering the slow mode */
         Wdg_59_DriverA_GusTiggerCounter = WDG_59_DRIVERA_INITIAL_TIMEOUT /
                               Wdg_59_DriverA_GpConfigPtr->usSlowTimeValue;

         #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
         WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
         #endif
         #endif
      }
      /* Switching the Watchdog Mode from OFF to FAST */
      else
      {
        /* Check if critical section protection is required */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        /* MISRA Violation: START Msg(4:0303)-1 */
        /* Set configured fast mode value to Mode register */
        WDG_59_DRIVERA_WDTAMD_ADDRESS =
            (Wdg_59_DriverA_GpConfigPtr->ucWdtamdFastValue |
            (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK));

        /* ReadBackTest for configured Register */
        #if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                     WDG_59_DRIVERA_READBACK_RUNTIME_ONLY) || \
        (WDG_59_DRIVERA_READBACK_OPTION == \
                                      WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

        WDG_59_DRIVERA_READBACKTEST(WDG_59_DRIVERA_WDTAMD_ADDRESS,
                                (Wdg_59_DriverA_GpConfigPtr->ucWdtamdFastValue |
             (WDG_59_DRIVERA_WDTAMD_ADDRESS & WDG_59_DRIVERA_75INTERRUPT_MASK)))
        #endif
        /* END Msg(4:0303)-1 */
        /* Check if critical section protection is required */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
        #endif

        #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
        /* Functionality related to R4.0 */
        /* TRACE [R4, WDG040] */
        /* TRACE [R3, WDG040] */
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif
        /* Set the trigger counter value considering the fast mode */
        Wdg_59_DriverA_GusTiggerCounter = WDG_59_DRIVERA_INITIAL_TIMEOUT /
                                   Wdg_59_DriverA_GpConfigPtr->usFastTimeValue;
        #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
        WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
        #endif
        #endif
      }
       /* Check if critical section protection is required */
       #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
       WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
       #endif

      /* Set the current mode */
      Wdg_59_DriverA_GddCurrentMode = Mode;

      /* Check if critical section protection is required */
      #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
      WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(MODE_SWITCH_PROTECTION)
      #endif

      /* Call the Trigger Function which restarts the Watchdog hardware */
      Wdg_59_DriverA_TriggerFunc();
    } /* end of else if (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode) */
    #endif /* #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON) */
    else if (Mode != Wdg_59_DriverA_GddCurrentMode)
    {
      #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
      /* Functionality related to R4.0 */
      /* TRACE [R4, WDG013] */
      /* TRACE [R3, WDG013] */
      /* TRACE [R4, WDG173] */
      /* TRACE [R3, WDG016] */
      /* TRACE [R4, WDG016] */
      /* TRACE [R3, WDG012] */
      /* Report Error to DEM */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_FAILED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

      #elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
      /* Functionality related to R3.2 */
      Dem_ReportErrorStatus(WDG_59_DRIVERA_E_MODE_SWITCH_FAILED,
                             (WDG_59_DRIVERA_DEM_TYPE) DEM_EVENT_STATUS_FAILED);
      #endif
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
    /* Set Watchdog Driver State to IDLE after Mode Switch operation */
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as idle */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
    #endif  /* (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  } /* End of if (E_OK == LenReturnValue) */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON) */
  return(LenReturnValue);
}

#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_Trigger
**
** Service ID            : 0x02
**
** Sync/Async            : Synchronous
**
** Description           : This service is used to trigger the Watchdog timer
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
** Preconditions         : Wdg_59_DriverA_Init must be called before this
**                         function
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState
**
** Functions Invoked     : Det_ReportError
**                         Wdg_59_DriverA_TriggerFunc
**
** Registers Used        : None
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R3, WDG108] */
/* TRACE [R3, WDG036] */
/* TRACE [R3, WDG041] */
/* TRACE [R3, WDG104] */
FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_Trigger(void)
{
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, WDG035] */
  /* TRACE [R4, WDG035] */
  /* Check whether Watchdog is in idle state */
  if (WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState)
  {

    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
                  WDG_59_DRIVERA_TRIGGER_SID, WDG_59_DRIVERA_E_DRIVER_STATE);

  }
  else
  #endif
  {
    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as busy */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_BUSY;
    #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */

    /* TRACE [R3, WDG093] */
    /* TRACE [R3, WDG094] */
    /* TRACE [R3, WDG095] */
    /* Call the Trigger Function which restarts the Watchdog hardware */
    Wdg_59_DriverA_TriggerFunc();

    #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
    /* Set the state of Watchdog as idle */
    /* TRACE [R3, WDG052] */
    /* TRACE [R4, WDG052] */
    Wdg_59_DriverA_GddDriverState = WDG_59_DRIVERA_IDLE;
    #endif /* WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON */
  }
}
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name         : Wdg_59_DriverA_SetTriggerCondition
**
** Service ID            : 0x03
**
** Description           : This service is used to initialize the trigger
**                         counter.
**
** Sync/Async            : Synchronous
**
** Re-entrancy           : Non-Reentrant
**
** Input Parameters      : timeout
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Wdg_59_DriverAInit must be called before this
**                         function.
**
** Global Variables Used : Wdg_59_DriverA_GddDriverState,
**                         Wdg_59_DriverA_GddCurrentMode,
**                         Wdg_59_DriverA_GusTiggerCounter.
**
** Functions Invoked     : Det_ReportError.
**
** Registers Used        : None
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define WDG_59_DRIVERA_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, WDG155] */

FUNC(void, WDG_59_DRIVERA_PUBLIC_CODE) Wdg_59_DriverA_SetTriggerCondition
                                                            (uint16 timeout)
{
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value */
  Std_ReturnType LenReturnValue;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /* Check whether Watchdog Driver is initialized */
  if ((WDG_59_DRIVERA_IDLE != Wdg_59_DriverA_GddDriverState) ||
                              (WDGIF_OFF_MODE == Wdg_59_DriverA_GddCurrentMode))
  {
    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
         WDG_59_DRIVERA_SETTRIGGERCONDITION_SID, WDG_59_DRIVERA_E_DRIVER_STATE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
   /*
   * Check whether timeout value requested is more than the maximum timeout
   * value configured
   */
  if (timeout > WDG_59_DRIVERA_MAXIMUM_TIMEOUT)
  {
    /* TRACE [R4, WDG146] */
    /* Report to DET, if Watchdog is not in idle state */
    (void)Det_ReportError(WDG_59_DRIVERA_MODULE_ID, WDG_59_DRIVERA_INSTANCE_ID,
    WDG_59_DRIVERA_SETTRIGGERCONDITION_SID, WDG_59_DRIVERA_E_PARAM_TIMEOUT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* Check if any DET error was reported */
  if (E_OK == LenReturnValue)
  #endif
  {
    /* Check if critical section protection is required */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_ENTER_CRITICAL_SECTION(TRIGG_PROTECTION)
    #endif

    /* TRACE [R4, WDG139] */
    /* Check whether Watchdog disable is allowed */
    #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON)
    /* Check if the current mode is slow */
    if (WDGIF_SLOW_MODE == Wdg_59_DriverA_GddCurrentMode)
    {
      /* Set the trigger counter value considering the slow mode */
      Wdg_59_DriverA_GusTiggerCounter = timeout /
                Wdg_59_DriverA_GpConfigPtr->usSlowTimeValue;
    }
    else if (WDGIF_FAST_MODE == Wdg_59_DriverA_GddCurrentMode)
    {
      /* Set the trigger counter value considering the fast mode */
      Wdg_59_DriverA_GusTiggerCounter = timeout /
                Wdg_59_DriverA_GpConfigPtr->usFastTimeValue;
    }
    else
    {
      /* The trigger counter need not be set for off mode */
    }
    #else /* #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON) */

    /* Set the trigger counter value considering the default mode */
    Wdg_59_DriverA_GusTiggerCounter = timeout /
                     Wdg_59_DriverA_GpConfigPtr->usDefaultTimeValue;
    #endif /* #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_OFF) */

    /* Check if critical section protection is required */
    #if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
    WDG_59_DRIVERA_EXIT_CRITICAL_SECTION(TRIGG_PROTECTION)
    #endif
  }
  /* Check if DET is enabled */
  #if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
}
#define WDG_59_DRIVERA_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
