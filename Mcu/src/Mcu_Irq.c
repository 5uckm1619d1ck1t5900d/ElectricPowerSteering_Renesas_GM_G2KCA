/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Irq.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the MCU Driver Component                                  */
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
 *                        1. MCU_ENTER_CRITICAL_SECTION and
 *                           MCU_EXIT_CRITICAL_SECTION are added
 *                        2. __asm("feret") is added in MCU_FEINT_ISR to avoid
 *                           improper exiting from the function
 *                        3. Mcu_GblRAMInitStatus is updating with values in
 *                           enum 'Mcu_RamStateType'
 *                        4. ISR APIs MCU_FEINT_ISR, MCU_ECM_EIC_ISR are
 *                           updated for addition of switch case for clearing
 *                           the ERROROUT pulse generated
 *
 * V1.0.2:  26-Sep-2014 : As per CR008 and mantis #19850, Following changes
 *                        are made,
 *                        1. MCU_FEINT_ISR API is updated for adding
 *                           MCU_FENMI_ENTRY, MCU_FENMI_LEAVE &
 *                           PRAGMA(NO_PROLOGUE) for proper returning from
 *                           FE level interrupts
 *                        2. Mcu_ProtectedWriteRetNone macro is invoked instead
 *                           of 'Mcu_ProtectedWrite' to avoid compilation
 *                           warnings
 *                        3. Trace marking is added throughout the file
 *                        4. Notification index calculation and delay timer
 *                           stop sections are updated in both ISR routine to
 *                           improve the throughput
 *
 * V1.0.5:  11-Feb-2014 : As per mantis #26305 ,following changes are made:
 *                        1. REG_DATA_PROTECTION is renamed to
 *                           MCU_REGISTER_PROTECTION.
 *                        2. Copyright information is updated.
 *
 * V1.0.6:  20-May-2015 : 1. Added code comments as per MO Review in Mantis
 *                           #27515
 *                        2. Added justification for MISRA warning Msg(4:3138)
 *                        3. Added compiler switch, #ifndef Os_MCU_FEINT_CAT2_ISR
 *                           and #ifndef MCU_FEINT_CAT2_ISR for MCU_FENMI_ENTRY
 *                           and MCU_FENMI_LEAVE as per mantis #27723
 *                        4. Removed _INTERRUPT_ keyword from MCU_FEINT_ISR as
 *                           per Mantis #27723
 *                        5. Removed PRAGMA(NO_PROLOGUE) as per Mantis #27723
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/* Included for global variable initialization values */
#include "Mcu_PBTypes.h"

/* Included for module version information definitions required for Mcu_Irq.c */
/* TRACE [R4, MCU213] */
#include "Mcu.h"

/* Included for ISR functions declaration */
#include "Mcu_Irq.h"

/* Included for ram variable declaration */
#include "Mcu_Ram.h"

/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"

/* Included for Register access */
#include "Mcu_Reg.h"

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION    MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_MINOR_VERSION    MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_IRQ_C_AR_RELEASE_REVISION_VERSION \
                                           MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_IRQ_C_SW_MAJOR_VERSION     MCU_SW_MAJOR_VERSION_VALUE
#define MCU_IRQ_C_SW_MINOR_VERSION     MCU_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_IRQ_AR_RELEASE_MAJOR_VERSION != MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Major Version"
#endif /* (MCU_IRQ_AR_RELEASE_MAJOR_VERSION !=  \
        *                                MCU_IRQ_C_AR_RELEASE_MAJOR_VERSION)
        */

#if (MCU_IRQ_AR_RELEASE_MINOR_VERSION != MCU_IRQ_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Minor Version"
#endif  /* (MCU_IRQ_AR_RELEASE_MINOR_VERSION != \
         *                               MCU_IRQ_C_AR_RELEASE_MINOR_VERSION)
         */

#if (MCU_IRQ_AR_RELEASE_REVISION_VERSION != \
                                        MCU_IRQ_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu_Irq.c : Mismatch in Release Revision Version"
#endif  /* (MCU_IRQ_AR_RELEASE_REVISION_VERSION !=  \
         *                            MCU_IRQ_C_AR_RELEASE_REVISION_VERSION)
         */

#if (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Software Major Version"
#endif  /* (MCU_IRQ_SW_MAJOR_VERSION != MCU_IRQ_C_SW_MAJOR_VERSION) */

#if (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION)
  #error "Mcu_Irq.c : Mismatch in Software Minor Version"
#endif  /* (MCU_IRQ_SW_MINOR_VERSION != MCU_IRQ_C_SW_MINOR_VERSION) */

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
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
/* Message       : (4:0316) An integer constant expression with negative      */
/*                 value is being converted to an unsigned type               */
/* Rule          : MISRA-C:2004 Rule 10.1                                     */
/*                 REFERENCE - ISO-6.2.1.2                                    */
/* Justification : Typecasting is not done because it is a common macro       */
/*                  function used for hardware registers of all sizes         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-2 and                           */
/*                 END Msg(4:0316)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) This switch default label is unreachable.         */
/* Rule          : MISRA-C:2004 Rule 14.1                                     */
/* Justification : Default case is added to avoid misra violation, also it is */
/*                 required as a safety measure                               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-3 and                           */
/*                 END Msg(4:0491)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3138) Null statement is located close to other code or  */
/*                  comments.                                                 */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : Mcu_ProtectedWriteRetNone is not a regular c function, it  */
/*                  is implemented as a macro.                                */
/*                  required as a safety measure                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-4 and                           */
/*                 END Msg(4:3138)-4 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : MCU_FEINT_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM NMI
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
** Global Variables Used : Mcu_GpConfigPtr, Mcu_GpEcmSetting,
**                         Mcu_GblRAMInitStatus
**
** Functions Invoked     : MCU_ENTER_CRITICAL_SECTION,
**                         MCU_EXIT_CRITICAL_SECTION, Mcu_ProtectedWrite
**
** Registers Used        : ECMMESSTR0, ECMESSTC0, ECMMESSTR1, ECMDTMCTL,
**                         ECMESSTC1, ECMPCMD1, ECMPS
*******************************************************************************/

/*To use CODE_FAST section in the Memory*/
#define MCU_START_SEC_CODE_FAST
#include "MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined  (Os_MCU_FEINT_CAT2_ISR) || defined (MCU_FEINT_CAT2_ISR)
 ISR(MCU_FEINT_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
FUNC(void, MCU_FAST_CODE) MCU_FEINT_ISR(void)
#endif
{
  /* Pointer to NMI notification function array */
  P2CONST(Mcu_ErrorNotification, MCU_VAR, MCU_CONFIG_CONST) LpNmiNotfyFunc;
  /* Pointer to Ecm configuration */
  P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) LpEcmSetting;
  uint32 LulDataValueReg0;
  uint32 LulReg1DataValue;
  uint8 LucLoopCount;
  uint8 LucRetryCount;

  #ifndef Os_MCU_FEINT_CAT2_ISR
  #ifndef MCU_FEINT_CAT2_ISR
  MCU_FENMI_ENTRY();
  #endif /* MCU_FEINT_CAT2_ISR is not defined */
  #endif /* Os_MCU_FEINT_CAT2_ISR is not defined */

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* MISRA Violation: START Msg(4:0316)-2 */
  /* Load the NMI notification array start address to local pointer */
  LpNmiNotfyFunc =
        (P2CONST(Mcu_ErrorNotification, MCU_VAR, MCU_CONFIG_CONST))
                                          (Mcu_GpConfigPtr->pNMINotification);
  /* END Msg(4:0316)-2 */

  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;

  /* MISRA Violation: START Msg(4:0303)-1 */
  /* Store the error value to be checked in the ISR */
  LulDataValueReg0 =
                 (MCU_ECMMESSTR0 & (LpEcmSetting->ulEcmNonMaskInterReg0value));
  LulReg1DataValue =
                 (MCU_ECMMESSTR1 & (LpEcmSetting->ulEcmNonMaskInterReg1value));
  /* END Msg(4:0303)-1 */

    for (LucLoopCount = MCU_ZERO; LucLoopCount < MCU_THIRTYTWO; LucLoopCount++)
    {
      /*  Check if error is not zero and
       *  Find which ecm source caused this interrupt
       */
      if ((MCU_ZERO != LulDataValueReg0) &&
          (MCU_ONE == ((LulDataValueReg0 >> LucLoopCount) & MCU_ONE)))
      {
        /* Check the delay timer start is configured for this source and
         * running, if yes stop timer to avoid restart and error output mask.
         */
        /* MISRA Violation: START Msg(4:0491)-3 */
        if (MCU_ONE ==
                (LpNmiNotfyFunc[LucLoopCount].ucDelayTimerOnStatus & MCU_ONE))
        /* END Msg(4:0491)-3 */
        {
          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Check  delay timer running status */
          if (MCU_ONE == (MCU_ECMDTMCTL & MCU_ONE))
          /* END Msg(4:0303)-1 */
          {
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Stop the delay timer */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_TWO, MCU_ECMPCMD1,
                                   MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Reconfigure delay control register to start timer
             * on next interrupt
             */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_ONE, MCU_ECMPCMD1,
                                   MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
          }
          else
          {
            /* No action required */
          }
        }
        else
        {
          /* No action required */
        }

        /* MISRA Violation: START Msg(4:0491)-3 */
        /* Check whether notification function  configured or not */
        if ((LpNmiNotfyFunc[LucLoopCount].pNotificationFuncPtr)
                                                                != NULL_PTR)
        {
          /* Invoke the configured notification function */
          LpNmiNotfyFunc[LucLoopCount].pNotificationFuncPtr();
        /* END Msg(4:0491)-3 */
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }
      if ((MCU_ZERO != LulReg1DataValue) && (LucLoopCount < MCU_ELEVEN) &&
              (MCU_ONE == ((LulReg1DataValue >> LucLoopCount) & MCU_ONE)))
      {
        /* Check the delay timer start is configured for this source and
         * running, if yes stop timer to avoid restart and error output mask.
         */
        /* MISRA Violation: START Msg(4:0491)-3 */
        if (MCU_ONE ==
            (LpNmiNotfyFunc[LucLoopCount + MCU_THIRTYTWO].ucDelayTimerOnStatus
                                                                    & MCU_ONE))
        /* END Msg(4:0491)-3 */
        {
          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Check  delay timer running status */
          if (MCU_ONE == (MCU_ECMDTMCTL & MCU_ONE))
          /* END Msg(4:0303)-1 */
          {
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Stop the delay timer */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_TWO, MCU_ECMPCMD1,
                                    MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
                         /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Reconfigure delay control register to start timer
             * on next interrupt
             */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_ONE, MCU_ECMPCMD1,
                                   MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
          }
          else
          {
            /* No action required */
          }
        }
        else
        {
          /* No action required */
        }

        /* MISRA Violation: START Msg(4:0491)-3 */
        if (NULL_PTR !=
           LpNmiNotfyFunc[LucLoopCount + MCU_THIRTYTWO].pNotificationFuncPtr)
        {
          /* Invoke the configured notification function */
          LpNmiNotfyFunc[LucLoopCount + MCU_THIRTYTWO].pNotificationFuncPtr();
        /* END Msg(4:0491)-3 */
        }
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }

    }
    #if (MCU_GET_RAM_STATE_API == STD_ON)
    /* Check local and global ram error */
    if ((MCU_ZERO != (LulDataValueReg0 & MCU_RAM_MASK0_VALUE)) ||
        (MCU_ZERO != (LulReg1DataValue & MCU_RAM_MASK1_VALUE)))
    {
      /* Set the ram state variable  */
      Mcu_GblRAMInitStatus = (boolean) MCU_RAMSTATE_INVALID;
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_GET_RAM_STATE_API == STD_ON) */
    if (MCU_ZERO != LulDataValueReg0)
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;
      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Clear the status register */
      Mcu_ProtectedWriteRetNone(MCU_ECMESSTC0, LulDataValueReg0,
              MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
      /* END Msg(4:0303)-1 */
    }
    else
    {
      /* No action required */
    }
    if (MCU_ZERO != LulReg1DataValue)
    {
       /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Clear the status register */
      Mcu_ProtectedWriteRetNone(MCU_ECMESSTC1, LulReg1DataValue,
                MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
      /* END Msg(4:0303)-1 */
    }
    else
    {
      /* No action required */
    }


  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  #ifndef Os_MCU_FEINT_CAT2_ISR
  #ifndef MCU_FEINT_CAT2_ISR
  MCU_FENMI_LEAVE();
  #endif /* MCU_FEINT_CAT2_ISR is not defined */
  #endif /* Os_MCU_FEINT_CAT2_ISR is not defined */
}

/*Exit CODE_FAST section in the Memory*/
#define MCU_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
** Function Name         : MCU_ECM_EIC_ISR
**
** Service ID            : NA
**
** Description           : Interrupt service routine for ECM MI
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
** Global Variables Used : Mcu_GpConfigPtr, Mcu_GpEcmSetting,
**                         Mcu_GblRAMInitStatus
**
** Functions Invoked     : MCU_ENTER_CRITICAL_SECTION,
**                         MCU_EXIT_CRITICAL_SECTION, Mcu_ProtectedWrite
**
** Registers Used        : ECMMESSTR0, ECMESSTC0, ECMMESSTR1, ECMDTMCTL,
**                         ECMESSTC1, ECMPCMD1, ECMPS
*******************************************************************************/

/*To use CODE_FAST section in the Memory*/
#define MCU_START_SEC_CODE_FAST
#include "MemMap.h"

/* Defines the CAT2 interrupt mapping */
#if defined  (Os_MCU_ECM_EIC_CAT2_ISR) || defined (MCU_ECM_EIC_CAT2_ISR)
ISR(MCU_ECM_EIC_CAT2_ISR)
/* Defines the CAT1 interrupt mapping */
#else
_INTERRUPT_ FUNC(void, MCU_FAST_CODE) MCU_ECM_EIC_ISR(void)
#endif
{
  /* Pointer to NMI notification function array */
  P2CONST(Mcu_ErrorNotification, MCU_VAR, MCU_CONFIG_CONST) LpMiNotfyFunc;
  /* Pointer to Ecm configuration */
  P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) LpEcmSetting;
  uint32 LulDataValueReg0;
  uint32 LulReg1DataValue;
  uint8 LucLoopCount;
  uint8 LucRetryCount;

  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

  /* MISRA Violation: START Msg(4:0316)-2 */
  /* Load the MI notification array start address */
  LpMiNotfyFunc = (P2CONST(Mcu_ErrorNotification, MCU_VAR, MCU_CONFIG_CONST))
                                           (Mcu_GpConfigPtr->pMINotification);
  /* END Msg(4:0316)-2 */

  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;

  /* MISRA Violation: START Msg(4:0303)-1 */
  /* Store the error value to be checked in the ISR */
  LulDataValueReg0 = (MCU_ECMMESSTR0 & (LpEcmSetting->ulEcmMaskInterReg0value));

  LulReg1DataValue = (MCU_ECMMESSTR1 & (LpEcmSetting->ulEcmMaskInterReg1value));
  /* END Msg(4:0303)-1 */

    for (LucLoopCount = MCU_ZERO; LucLoopCount < MCU_THIRTYTWO; LucLoopCount++)
    {
      /* Find which ecm source caused this interrupt */
      if ((MCU_ZERO != LulDataValueReg0) &&
         (MCU_ONE == ((LulDataValueReg0 >> LucLoopCount) & MCU_ONE)))
      {
        /* Check the delay timer start is configured for this source and
         * running, if yes stop timer to avoid restart and error output mask.
         */
        /* MISRA Violation: START Msg(4:0491)-3 */
         if (MCU_ONE ==
            (LpMiNotfyFunc[LucLoopCount].ucDelayTimerOnStatus & MCU_ONE))
        /* END Msg(4:0491)-3 */
        {
          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Check  delay timer running status */
          if (MCU_ONE == (MCU_ECMDTMCTL & MCU_ONE))
          /* END Msg(4:0303)-1 */
          {
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Stop the delay timer */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_TWO, MCU_ECMPCMD1,
                                   MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
             /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Reconfigure delay control register to start timer
             * on next interrupt
             */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_ONE, MCU_ECMPCMD1,
                                   MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
          }
          else
          {
            /* No action required */
          }
        }
        else
        {
          /* No action required */
        }

          /* MISRA Violation: START Msg(4:0491)-3 */
          /* Check whether notification function  configured or not */
          if (NULL_PTR != LpMiNotfyFunc[LucLoopCount].pNotificationFuncPtr)
          {
            /* Invoke the configured notification function */
            LpMiNotfyFunc[LucLoopCount].pNotificationFuncPtr();
          }
          /* END Msg(4:0491)-3 */
          else
          {
            /* No action required */
          }

      }
      else
      {
        /* No action required */
      }

      if ((MCU_ZERO != LulReg1DataValue) && (LucLoopCount < MCU_ELEVEN) &&
         (MCU_ONE == ((LulReg1DataValue >> LucLoopCount) & MCU_ONE)))
      {
        /* Check the delay timer start is configured for this source and
         * running, if yes stop timer to avoid restart and error output mask.
         */
        /* MISRA Violation: START Msg(4:0491)-3 */
        if (MCU_ONE ==
           (LpMiNotfyFunc[LucLoopCount + MCU_THIRTYTWO].ucDelayTimerOnStatus
                                                                  & MCU_ONE))
        /* END Msg(4:0491)-3 */
        {
          /* MISRA Violation: START Msg(4:0303)-1 */
          /* Check  delay timer running status */
          if (MCU_ONE == (MCU_ECMDTMCTL & MCU_ONE))
          /* END Msg(4:0303)-1 */
          {
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* MISRA Violation: START Msg(4:3138)-4 */
            /* Stop the delay timer */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_TWO, MCU_ECMPCMD1,
                                 MCU_ECMPS, LucRetryCount);
            /* END Msg(4:3138)-4 */
            /* END Msg(4:0303)-1 */
                         /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-1 */
            /* Reconfigure delay control register to start timer
             * on next interrupt
             */
            Mcu_ProtectedWriteRetNone(MCU_ECMDTMCTL, MCU_ONE, MCU_ECMPCMD1,
                                   MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-1 */
          }
          else
          {
            /* No action required */
          }
        }
        else
        {
          /* No action required */
        }

        /* MISRA Violation: START Msg(4:0491)-3 */
        /* Check whether notification function configured or not */
        if (NULL_PTR !=
            LpMiNotfyFunc[LucLoopCount + MCU_THIRTYTWO].pNotificationFuncPtr)
        {
          /* Invoke the configured notification function */
          LpMiNotfyFunc[LucLoopCount + MCU_THIRTYTWO].pNotificationFuncPtr();
        }
        /* END Msg(4:0491)-3 */
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }
    }
    #if (MCU_GET_RAM_STATE_API == STD_ON)
    /* Check local and global ram error */
    if ((MCU_ZERO != (LulDataValueReg0 & MCU_RAM_MASK0_VALUE)) ||
        (MCU_ZERO != (LulReg1DataValue & MCU_RAM_MASK1_VALUE)))
    {
      /* Set the ram state variable  */
      Mcu_GblRAMInitStatus = (boolean) MCU_RAMSTATE_INVALID;
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_GET_RAM_STATE_API == STD_ON) */
     if (MCU_ZERO != LulDataValueReg0)
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Clear the status register */
      Mcu_ProtectedWriteRetNone(MCU_ECMESSTC0, LulDataValueReg0,
                MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
      /* END Msg(4:0303)-1 */
    }
    else
    {
      /* No action required */
    }
    if (MCU_ZERO != LulReg1DataValue)
    {
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-1 */
      /* Clear the status register */
      Mcu_ProtectedWriteRetNone(MCU_ECMESSTC1, LulReg1DataValue,
                MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
      /* END Msg(4:0303)-1 */
    }
    else
    {
      /* No action required */
    }


  #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
  MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
  #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
}

/*Exit CODE_FAST section in the Memory*/
#define MCU_STOP_SEC_CODE_FAST
#include "MemMap.h"

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
