/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_Sci30CfgAndUse.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_Sci30CfgAndUse>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_SCI30CFGANDUSE_H
# define _RTE_CDD_SCI30CFGANDUSE_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_Sci30CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/


# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_IMCARBN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IMCARBN_APPL_CODE) GetTxRateGroup_Oper(uint8 RateGroup_Arg, P2VAR(uint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IMCARBN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTxRateGroup_Oper GetTxRateGroup_Oper
#  define RTE_START_SEC_IMCARBN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_IMCARBN_APPL_CODE) SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, P2CONST(uint8, AUTOMATIC, RTE_IMCARBN_APPL_DATA) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_IMCARBN_APPL_CODE) SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, P2CONST(Ary1D_u8_8, AUTOMATIC, RTE_IMCARBN_APPL_DATA) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_IMCARBN_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetRxSigGroup_Oper SetRxSigGroup_Oper


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Enter_ExclsvAr1SciDrvrTxRxBuf() \
  { \
    Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_ENTER_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_EnterHook_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf_Start(); \
    SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_EnterHook_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf_Return(); \
  }
/* PRQA L:L1 */

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Exit_ExclsvAr1SciDrvrTxRxBuf() \
  { \
    Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_EXIT_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_ExitHook_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf_Start(); \
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_ExitHook_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf_Return(); \
  }
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl6_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciDiagcFrmErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciDiagcOvrrunErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciDiagcParErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciDiagcRxMaxDataErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciNrOfPnd100MilliSecFrmCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciNrOfPnd10MilliSecFrmCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciRxPrevLoopDataUnread; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_SciRxProcIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_Sci100MilliSecReadCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_Sci10MilliSecReadCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_Sci30CfgAndUseC, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_Sci100MilliSecBufCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_Sci30CfgAndUseB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_Sci10MilliSecBufCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_Sci30CfgAndUseA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_CDD_Sci30CfgAndUse_Sci2MilliSecBufCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl6_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_SciDiagcFrmErrCntr() \
  (&Rte_CDD_Sci30CfgAndUse_SciDiagcFrmErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciDiagcOvrrunErrCntr() \
  (&Rte_CDD_Sci30CfgAndUse_SciDiagcOvrrunErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciDiagcParErrCntr() \
  (&Rte_CDD_Sci30CfgAndUse_SciDiagcParErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciDiagcRxMaxDataErrCntr() \
  (&Rte_CDD_Sci30CfgAndUse_SciDiagcRxMaxDataErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciNrOfPnd100MilliSecFrmCnt() \
  (&Rte_CDD_Sci30CfgAndUse_SciNrOfPnd100MilliSecFrmCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciNrOfPnd10MilliSecFrmCnt() \
  (&Rte_CDD_Sci30CfgAndUse_SciNrOfPnd10MilliSecFrmCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciRxPrevLoopDataUnread() \
  (&Rte_CDD_Sci30CfgAndUse_SciRxPrevLoopDataUnread) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_SciRxProcIdx() \
  (&Rte_CDD_Sci30CfgAndUse_SciRxProcIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Sci100MilliSecReadCmpl() \
  (&Rte_CDD_Sci30CfgAndUse_Sci100MilliSecReadCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_Sci10MilliSecReadCmpl() \
  (&Rte_CDD_Sci30CfgAndUse_Sci10MilliSecReadCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_Sci100MilliSecBufCnt() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_Sci100MilliSecBufCnt())[0][0]))
#  else
#   define Rte_Pim_Sci100MilliSecBufCnt() RtePim_Sci100MilliSecBufCnt()
#  endif
#  define RtePim_Sci100MilliSecBufCnt() \
  (&Rte_CDD_Sci30CfgAndUse_Sci100MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_Sci10MilliSecBufCnt() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_Sci10MilliSecBufCnt())[0][0]))
#  else
#   define Rte_Pim_Sci10MilliSecBufCnt() RtePim_Sci10MilliSecBufCnt()
#  endif
#  define RtePim_Sci10MilliSecBufCnt() \
  (&Rte_CDD_Sci30CfgAndUse_Sci10MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_Sci2MilliSecBufCnt() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_Sci2MilliSecBufCnt())[0][0]))
#  else
#   define Rte_Pim_Sci2MilliSecBufCnt() RtePim_Sci2MilliSecBufCnt()
#  endif
#  define RtePim_Sci2MilliSecBufCnt() \
  (&Rte_CDD_Sci30CfgAndUse_Sci2MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_Sci30CfgAndUse_START_SEC_CODE
# include "CDD_Sci30CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Sci30CfgAndUseInit1 Sci30CfgAndUseInit1
#  define RTE_RUNNABLE_Sci30CfgAndUsePer1 Sci30CfgAndUsePer1
#  define RTE_RUNNABLE_Sci30CfgAndUsePer2 Sci30CfgAndUsePer2
#  define RTE_RUNNABLE_Sci30CfgAndUsePer3 Sci30CfgAndUsePer3
#  define RTE_RUNNABLE_Sci30CfgAndUsePer4 Sci30CfgAndUsePer4
# endif

FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUseInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer4(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_Sci30CfgAndUse_STOP_SEC_CODE
# include "CDD_Sci30CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetTxRateGroup_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetRxSigGroup_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_SCI30CFGANDUSE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
