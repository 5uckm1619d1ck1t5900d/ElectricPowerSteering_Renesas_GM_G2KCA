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
 *          File:  Rte_CurrReasbnDiagc.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CurrReasbnDiagc>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CURRREASBNDIAGC_H
# define _RTE_CURRREASBNDIAGC_H

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

# include "Rte_CurrReasbnDiagc_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(u0p16, RTE_VAR_INIT) Rte_CurrReasbnDiagc_MotAgElec_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_MotTqCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelMrf_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgDaxFfStat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotVltgDaxFild_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgQaxFfStat_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotVltgQaxFild_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_StOutpCtrl_SysMotTqCmdSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAgElec_Val (0U)
#  define Rte_InitValue_MotTqCmdLimrMin_Val (0.0F)
#  define Rte_InitValue_MotVelMrf_Val (0.0F)
#  define Rte_InitValue_MotVltgDaxFfStat_Val (0.0F)
#  define Rte_InitValue_MotVltgDaxFild_Val (0.0F)
#  define Rte_InitValue_MotVltgQaxFfStat_Val (0.0F)
#  define Rte_InitValue_MotVltgQaxFild_Val (0.0F)
#  define Rte_InitValue_SysMotTqCmdSca_Val (1.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAgElec_Val Rte_Read_CurrReasbnDiagc_MotAgElec_Val
#  define Rte_Read_CurrReasbnDiagc_MotAgElec_Val(data) (*(data) = Rte_CurrReasbnDiagc_MotAgElec_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotTqCmdLimrMin_Val Rte_Read_CurrReasbnDiagc_MotTqCmdLimrMin_Val
#  define Rte_Read_CurrReasbnDiagc_MotTqCmdLimrMin_Val(data) (*(data) = Rte_AssiSumLim_MotTqCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVelMrf_Val Rte_Read_CurrReasbnDiagc_MotVelMrf_Val
#  define Rte_Read_CurrReasbnDiagc_MotVelMrf_Val(data) (*(data) = Rte_CDD_MotVel_MotVelMrf_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVltgDaxFfStat_Val Rte_Read_CurrReasbnDiagc_MotVltgDaxFfStat_Val
#  define Rte_Read_CurrReasbnDiagc_MotVltgDaxFfStat_Val(data) (*(data) = Rte_MotRefMdl_MotVltgDaxFfStat_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVltgDaxFild_Val Rte_Read_CurrReasbnDiagc_MotVltgDaxFild_Val
#  define Rte_Read_CurrReasbnDiagc_MotVltgDaxFild_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotVltgDaxFild_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVltgQaxFfStat_Val Rte_Read_CurrReasbnDiagc_MotVltgQaxFfStat_Val
#  define Rte_Read_CurrReasbnDiagc_MotVltgQaxFfStat_Val(data) (*(data) = Rte_MotRefMdl_MotVltgQaxFfStat_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotVltgQaxFild_Val Rte_Read_CurrReasbnDiagc_MotVltgQaxFild_Val
#  define Rte_Read_CurrReasbnDiagc_MotVltgQaxFild_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotVltgQaxFild_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_SysMotTqCmdSca_Val Rte_Read_CurrReasbnDiagc_SysMotTqCmdSca_Val
#  define Rte_Read_CurrReasbnDiagc_SysMotTqCmdSca_Val(data) (*(data) = Rte_StOutpCtrl_SysMotTqCmdSca_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcPrimErrThd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcDiagFildLim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcDiagVltgLpFilFrq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcLpFilSca_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcMotVelHiLim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcMotVelLoLim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcVelLpFilFrq_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Inin00_SysGlbPrmMotPoleCnt_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(boolean, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcDiagVltgLpFilEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(boolean, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(boolean, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_CurrReasbnDiagcVelLpFilEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Prm_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcCurrDiagcPrimErrThd_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcPrimErrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcDiagFildLim_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcDiagFildLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcDiagVltgLpFilFrq_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcDiagVltgLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcLpFilSca_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcLpFilSca_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcMotVelHiLim_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcMotVelHiLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcMotVelLoLim_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcMotVelLoLim_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcVelLpFilFrq_Val() (Rte_CalRegn01Cmn_CurrReasbnDiagcVelLpFilFrq_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_SysGlbPrmMotPoleCnt_Val() (Rte_CalRegn01Inin00_SysGlbPrmMotPoleCnt_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcDiagVltgLpFilEna_Logl() (Rte_CalRegn01Cmn_CurrReasbnDiagcDiagVltgLpFilEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl() (Rte_CalRegn01Cmn_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_CurrReasbnDiagcVelLpFilEna_Logl() (Rte_CalRegn01Cmn_CurrReasbnDiagcVelLpFilEna_Logl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildInp1Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildInp2Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildOutp1Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildOutp2Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgAFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgBFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDaxDif; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagFildLimd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagSecdryFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgQaxDif; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcVelLpFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_CurrReasbnMotVelLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_DiagVltgLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDaxLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgQaxLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_MotVltgDiagFildInp1Prev() \
  (&Rte_CurrReasbnDiagc_MotVltgDiagFildInp1Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotVltgDiagFildInp2Prev() \
  (&Rte_CurrReasbnDiagc_MotVltgDiagFildInp2Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotVltgDiagFildOutp1Prev() \
  (&Rte_CurrReasbnDiagc_MotVltgDiagFildOutp1Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotVltgDiagFildOutp2Prev() \
  (&Rte_CurrReasbnDiagc_MotVltgDiagFildOutp2Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgAFild() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgAFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgBFild() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgBFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgDaxDif() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDaxDif) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgDiagFild() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgDiagFildLimd() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagFildLimd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgDiagSecdryFild() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagSecdryFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcMotVltgQaxDif() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgQaxDif) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dCurrReasbnDiagcVelLpFild() \
  (&Rte_CurrReasbnDiagc_dCurrReasbnDiagcVelLpFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_CurrReasbnMotVelLpFil() \
  (&Rte_CurrReasbnDiagc_CurrReasbnMotVelLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_DiagVltgLpFil() \
  (&Rte_CurrReasbnDiagc_DiagVltgLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotVltgDaxLpFil() \
  (&Rte_CurrReasbnDiagc_MotVltgDaxLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotVltgQaxLpFil() \
  (&Rte_CurrReasbnDiagc_MotVltgQaxLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CurrReasbnDiagc_START_SEC_CODE
# include "CurrReasbnDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CurrReasbnDiagcInit2 CurrReasbnDiagcInit2
#  define RTE_RUNNABLE_CurrReasbnDiagcPer2 CurrReasbnDiagcPer2
# endif

FUNC(void, CurrReasbnDiagc_CODE) CurrReasbnDiagcInit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CurrReasbnDiagc_CODE) CurrReasbnDiagcPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CurrReasbnDiagc_STOP_SEC_CODE
# include "CurrReasbnDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CURRREASBNDIAGC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
