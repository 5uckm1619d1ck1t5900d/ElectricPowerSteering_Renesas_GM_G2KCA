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
 *          File:  Rte_ImcArbn.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ImcArbn>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_IMCARBN_H
# define _RTE_IMCARBN_H

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

# include "Rte_ImcArbn_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_Appl6_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_DualEcuIdn_EcuId_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl6_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_EcuId_Val (0U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_Appl6_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(boolean, RTE_VAR_INIT) Rte_Irv_ImcArbn_IniTiOutChkCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_Appl6_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/



# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_EcuId_Val Rte_Read_ImcArbn_EcuId_Val
#  define Rte_Read_ImcArbn_EcuId_Val(data) (*(data) = Rte_DualEcuIdn_EcuId_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr100MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr100MicroSec32bit_Oper(arg1) (GetRefTmr100MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan100MicroSec32bit_Oper(uint32 RefTmr, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan100MicroSec32bit_Oper(arg1, arg2) (GetTiSpan100MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL6_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL6_APPL_CODE) SetNtcSts6_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL6_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts6_Oper


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Enter_ExclsvAr1DrvrTxRxBuf() \
  { \
    Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_ENTER_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_EnterHook_ImcArbn_ExclsvAr1DrvrTxRxBuf_Start(); \
    SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_EnterHook_ImcArbn_ExclsvAr1DrvrTxRxBuf_Return(); \
  }
/* PRQA L:L1 */

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Exit_ExclsvAr1DrvrTxRxBuf() \
  { \
    Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_EXIT_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_ExitHook_ImcArbn_ExclsvAr1DrvrTxRxBuf_Start(); \
    ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_ExitHook_ImcArbn_ExclsvAr1DrvrTxRxBuf_Return(); \
  }
/* PRQA L:L1 */

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Enter_ExclsvAr2SigDataBuf() \
  { \
    Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_ENTER_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_EnterHook_ImcArbn_ExclsvAr2SigDataBuf_Start(); \
    SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_EnterHook_ImcArbn_ExclsvAr2SigDataBuf_Return(); \
  }
/* PRQA L:L1 */

/* PRQA S 3458 L1 */ /* MD_MSR_19.4 */
#  define Rte_Exit_ExclsvAr2SigDataBuf() \
  { \
    Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_EXIT_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_ExitHook_ImcArbn_ExclsvAr2SigDataBuf_Start(); \
    ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */ \
    Rte_ExitHook_ImcArbn_ExclsvAr2SigDataBuf_Return(); \
  }
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_ImcArbnPer4_IniTiOutChkCmpl() \
  Rte_Irv_ImcArbn_IniTiOutChkCmpl
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_ImcArbnPer5_IniTiOutChkCmpl() \
  Rte_Irv_ImcArbn_IniTiOutChkCmpl
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_ImcArbnPer6_IniTiOutChkCmpl() \
  Rte_Irv_ImcArbn_IniTiOutChkCmpl
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_ImcArbnPer6_IniTiOutChkCmpl(data) \
  (Rte_Irv_ImcArbn_IniTiOutChkCmpl = (data))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_ImcArbnEcuIninTiOutThd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_ImcArbnFrmFltThd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Prm_ImcArbnEcuIninTiOutThd_Val() (Rte_CalRegn01Cmn_ImcArbnEcuIninTiOutThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ImcArbnFrmFltThd_Val() (Rte_CalRegn01Cmn_ImcArbnFrmFltThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl6_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_ImcEcuComStrtTiRef; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_2_2, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_FrmFltCntr100MilliSec; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_2_2, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_FrmFltCntr10MilliSec; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_2_2, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_FrmFltCntr2MilliSec; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_PrevRollgCntrRxd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_PrimSrcResyncCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_PrimSrcRollgCntrResync; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_PrimSrcRxBuf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_logl_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_ResyncOnPrimActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_logl_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_ResyncOnSecdryActv; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_3, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_RollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u32_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_RxdSigData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_ImrArbnRxExtdSts2_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_RxdSigDataExtdSts; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_ImcArbnRxDataSrc2_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_RxdSigDataSrc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SecdrySrcResyncCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SecdrySrcRollgCntrResync; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SecdrySrcRxBuf; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_ImcArbnRxDataSrc2_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SigGroupDataSrc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SigGroupMissCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_logl_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SigGroupNeverRxd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u8_ImcArbnB, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_SigGroupSkipCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary2D_u8_ImcArbnA, RTE_VAR_DEFAULT_RTE_Appl6_PIM_GROUP) Rte_ImcArbn_TxBuf; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl6_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_ImcEcuComStrtTiRef() \
  (&Rte_ImcArbn_ImcEcuComStrtTiRef) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_FrmFltCntr100MilliSec() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_FrmFltCntr100MilliSec())[0][0]))
#  else
#   define Rte_Pim_FrmFltCntr100MilliSec() RtePim_FrmFltCntr100MilliSec()
#  endif
#  define RtePim_FrmFltCntr100MilliSec() \
  (&Rte_ImcArbn_FrmFltCntr100MilliSec) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_FrmFltCntr10MilliSec() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_FrmFltCntr10MilliSec())[0][0]))
#  else
#   define Rte_Pim_FrmFltCntr10MilliSec() RtePim_FrmFltCntr10MilliSec()
#  endif
#  define RtePim_FrmFltCntr10MilliSec() \
  (&Rte_ImcArbn_FrmFltCntr10MilliSec) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_FrmFltCntr2MilliSec() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_FrmFltCntr2MilliSec())[0][0]))
#  else
#   define Rte_Pim_FrmFltCntr2MilliSec() RtePim_FrmFltCntr2MilliSec()
#  endif
#  define RtePim_FrmFltCntr2MilliSec() \
  (&Rte_ImcArbn_FrmFltCntr2MilliSec) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_PrevRollgCntrRxd() (&((*RtePim_PrevRollgCntrRxd())[0]))
#  else
#   define Rte_Pim_PrevRollgCntrRxd() RtePim_PrevRollgCntrRxd()
#  endif
#  define RtePim_PrevRollgCntrRxd() \
  (&Rte_ImcArbn_PrevRollgCntrRxd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_PrimSrcResyncCntr() (&((*RtePim_PrimSrcResyncCntr())[0]))
#  else
#   define Rte_Pim_PrimSrcResyncCntr() RtePim_PrimSrcResyncCntr()
#  endif
#  define RtePim_PrimSrcResyncCntr() \
  (&Rte_ImcArbn_PrimSrcResyncCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_PrimSrcRollgCntrResync() (&((*RtePim_PrimSrcRollgCntrResync())[0]))
#  else
#   define Rte_Pim_PrimSrcRollgCntrResync() RtePim_PrimSrcRollgCntrResync()
#  endif
#  define RtePim_PrimSrcRollgCntrResync() \
  (&Rte_ImcArbn_PrimSrcRollgCntrResync) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_PrimSrcRxBuf() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_PrimSrcRxBuf())[0][0]))
#  else
#   define Rte_Pim_PrimSrcRxBuf() RtePim_PrimSrcRxBuf()
#  endif
#  define RtePim_PrimSrcRxBuf() \
  (&Rte_ImcArbn_PrimSrcRxBuf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_ResyncOnPrimActv() (&((*RtePim_ResyncOnPrimActv())[0]))
#  else
#   define Rte_Pim_ResyncOnPrimActv() RtePim_ResyncOnPrimActv()
#  endif
#  define RtePim_ResyncOnPrimActv() \
  (&Rte_ImcArbn_ResyncOnPrimActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_ResyncOnSecdryActv() (&((*RtePim_ResyncOnSecdryActv())[0]))
#  else
#   define Rte_Pim_ResyncOnSecdryActv() RtePim_ResyncOnSecdryActv()
#  endif
#  define RtePim_ResyncOnSecdryActv() \
  (&Rte_ImcArbn_ResyncOnSecdryActv) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_RollgCntr() (&((*RtePim_RollgCntr())[0]))
#  else
#   define Rte_Pim_RollgCntr() RtePim_RollgCntr()
#  endif
#  define RtePim_RollgCntr() \
  (&Rte_ImcArbn_RollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_RxdSigData() (&((*RtePim_RxdSigData())[0]))
#  else
#   define Rte_Pim_RxdSigData() RtePim_RxdSigData()
#  endif
#  define RtePim_RxdSigData() \
  (&Rte_ImcArbn_RxdSigData) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_RxdSigDataExtdSts() (&((*RtePim_RxdSigDataExtdSts())[0]))
#  else
#   define Rte_Pim_RxdSigDataExtdSts() RtePim_RxdSigDataExtdSts()
#  endif
#  define RtePim_RxdSigDataExtdSts() \
  (&Rte_ImcArbn_RxdSigDataExtdSts) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_RxdSigDataSrc() (&((*RtePim_RxdSigDataSrc())[0]))
#  else
#   define Rte_Pim_RxdSigDataSrc() RtePim_RxdSigDataSrc()
#  endif
#  define RtePim_RxdSigDataSrc() \
  (&Rte_ImcArbn_RxdSigDataSrc) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SecdrySrcResyncCntr() (&((*RtePim_SecdrySrcResyncCntr())[0]))
#  else
#   define Rte_Pim_SecdrySrcResyncCntr() RtePim_SecdrySrcResyncCntr()
#  endif
#  define RtePim_SecdrySrcResyncCntr() \
  (&Rte_ImcArbn_SecdrySrcResyncCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SecdrySrcRollgCntrResync() (&((*RtePim_SecdrySrcRollgCntrResync())[0]))
#  else
#   define Rte_Pim_SecdrySrcRollgCntrResync() RtePim_SecdrySrcRollgCntrResync()
#  endif
#  define RtePim_SecdrySrcRollgCntrResync() \
  (&Rte_ImcArbn_SecdrySrcRollgCntrResync) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SecdrySrcRxBuf() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_SecdrySrcRxBuf())[0][0]))
#  else
#   define Rte_Pim_SecdrySrcRxBuf() RtePim_SecdrySrcRxBuf()
#  endif
#  define RtePim_SecdrySrcRxBuf() \
  (&Rte_ImcArbn_SecdrySrcRxBuf) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SigGroupDataSrc() (&((*RtePim_SigGroupDataSrc())[0]))
#  else
#   define Rte_Pim_SigGroupDataSrc() RtePim_SigGroupDataSrc()
#  endif
#  define RtePim_SigGroupDataSrc() \
  (&Rte_ImcArbn_SigGroupDataSrc) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SigGroupMissCntr() (&((*RtePim_SigGroupMissCntr())[0]))
#  else
#   define Rte_Pim_SigGroupMissCntr() RtePim_SigGroupMissCntr()
#  endif
#  define RtePim_SigGroupMissCntr() \
  (&Rte_ImcArbn_SigGroupMissCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SigGroupNeverRxd() (&((*RtePim_SigGroupNeverRxd())[0]))
#  else
#   define Rte_Pim_SigGroupNeverRxd() RtePim_SigGroupNeverRxd()
#  endif
#  define RtePim_SigGroupNeverRxd() \
  (&Rte_ImcArbn_SigGroupNeverRxd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_SigGroupSkipCntr() (&((*RtePim_SigGroupSkipCntr())[0]))
#  else
#   define Rte_Pim_SigGroupSkipCntr() RtePim_SigGroupSkipCntr()
#  endif
#  define RtePim_SigGroupSkipCntr() \
  (&Rte_ImcArbn_SigGroupSkipCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_TxBuf() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) &((*RtePim_TxBuf())[0][0]))
#  else
#   define Rte_Pim_TxBuf() RtePim_TxBuf()
#  endif
#  define RtePim_TxBuf() \
  (&Rte_ImcArbn_TxBuf) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define ImcArbn_START_SEC_CODE
# include "ImcArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_f32_Oper GetSigImcDataExtdSts_f32_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_logl_Oper GetSigImcDataExtdSts_logl_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_s08_Oper GetSigImcDataExtdSts_s08_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_s16_Oper GetSigImcDataExtdSts_s16_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_s32_Oper GetSigImcDataExtdSts_s32_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_u08_Oper GetSigImcDataExtdSts_u08_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_u16_Oper GetSigImcDataExtdSts_u16_Oper
#  define RTE_RUNNABLE_GetSigImcDataExtdSts_u32_Oper GetSigImcDataExtdSts_u32_Oper
#  define RTE_RUNNABLE_GetSigImcData_f32_Oper GetSigImcData_f32_Oper
#  define RTE_RUNNABLE_GetSigImcData_logl_Oper GetSigImcData_logl_Oper
#  define RTE_RUNNABLE_GetSigImcData_s08_Oper GetSigImcData_s08_Oper
#  define RTE_RUNNABLE_GetSigImcData_s16_Oper GetSigImcData_s16_Oper
#  define RTE_RUNNABLE_GetSigImcData_s32_Oper GetSigImcData_s32_Oper
#  define RTE_RUNNABLE_GetSigImcData_u08_Oper GetSigImcData_u08_Oper
#  define RTE_RUNNABLE_GetSigImcData_u16_Oper GetSigImcData_u16_Oper
#  define RTE_RUNNABLE_GetSigImcData_u32_Oper GetSigImcData_u32_Oper
#  define RTE_RUNNABLE_GetTxRateGroup_Oper GetTxRateGroup_Oper
#  define RTE_RUNNABLE_GetTxSigGroup_Oper GetTxSigGroup_Oper
#  define RTE_RUNNABLE_ImcArbnInit1 ImcArbnInit1
#  define RTE_RUNNABLE_ImcArbnPer1 ImcArbnPer1
#  define RTE_RUNNABLE_ImcArbnPer2 ImcArbnPer2
#  define RTE_RUNNABLE_ImcArbnPer3 ImcArbnPer3
#  define RTE_RUNNABLE_ImcArbnPer4 ImcArbnPer4
#  define RTE_RUNNABLE_ImcArbnPer5 ImcArbnPer5
#  define RTE_RUNNABLE_ImcArbnPer6 ImcArbnPer6
#  define RTE_RUNNABLE_SetRxSigGroup_Oper SetRxSigGroup_Oper
# endif

FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_f32_Oper(uint16 SigId_Arg, P2VAR(float32, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_logl_Oper(uint16 SigId_Arg, P2VAR(boolean, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_s08_Oper(uint16 SigId_Arg, P2VAR(sint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_s16_Oper(uint16 SigId_Arg, P2VAR(sint16, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_s32_Oper(uint16 SigId_Arg, P2VAR(sint32, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_u08_Oper(uint16 SigId_Arg, P2VAR(uint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_u16_Oper(uint16 SigId_Arg, P2VAR(uint16, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcDataExtdSts_u32_Oper(uint16 SigId_Arg, P2VAR(uint32, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxExtdSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg, P2VAR(ImcArbnRxDataSrc1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) DataSrc_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_f32_Oper(uint16 SigId_Arg, P2VAR(float32, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_logl_Oper(uint16 SigId_Arg, P2VAR(boolean, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_s08_Oper(uint16 SigId_Arg, P2VAR(sint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_s16_Oper(uint16 SigId_Arg, P2VAR(sint16, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_s32_Oper(uint16 SigId_Arg, P2VAR(sint32, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_u08_Oper(uint16 SigId_Arg, P2VAR(uint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_u16_Oper(uint16 SigId_Arg, P2VAR(uint16, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetSigImcData_u32_Oper(uint16 SigId_Arg, P2VAR(uint32, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetTxRateGroup_Oper(uint8 RateGroup_Arg, P2VAR(uint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, ImcArbn_CODE) GetTxSigGroup_Oper(uint8 SigGroupId_Arg, P2VAR(uint8, AUTOMATIC, RTE_IMCARBN_APPL_VAR) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, ImcArbn_CODE) ImcArbnInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ImcArbn_CODE) ImcArbnPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ImcArbn_CODE) ImcArbnPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ImcArbn_CODE) ImcArbnPer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ImcArbn_CODE) ImcArbnPer4(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ImcArbn_CODE) ImcArbnPer5(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, ImcArbn_CODE) ImcArbnPer6(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, ImcArbn_CODE) SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, P2CONST(uint8, AUTOMATIC, RTE_IMCARBN_APPL_DATA) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, ImcArbn_CODE) SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, P2CONST(Ary1D_u8_8, AUTOMATIC, RTE_IMCARBN_APPL_DATA) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define ImcArbn_STOP_SEC_CODE
# include "ImcArbn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetSigImcDataExtdSts_f32_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_logl_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_s08_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_s16_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_s32_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_u08_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_u16_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcDataExtdSts_u32_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_f32_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_logl_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_s08_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_s16_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_s32_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_u08_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_u16_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetSigImcData_u32_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetTxRateGroup_PortIf1_E_NOT_OK (1U)

#  define RTE_E_GetTxSigGroup_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetRxSigGroup_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_IMCARBN_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
