/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CurrReasbnDiagc.h
 *     SW-C Type:  CurrReasbnDiagc
 *  Generated at:  Mon Dec 19 11:11:20 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CurrReasbnDiagc> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CURRREASBNDIAGC_H
# define _RTE_CURRREASBNDIAGC_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# define RTE_PTR2ARRAYBASETYPE_PASSING

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CurrReasbnDiagc_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CurrReasbnDiagc
{
  /* PIM Handles section */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_CurrReasbnMotVelLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_DiagVltgLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotVltgDaxLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotVltgDiagFildInp1Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotVltgDiagFildInp2Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotVltgDiagFildOutp1Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotVltgDiagFildOutp2Prev; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(FilLpRec1, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotVltgQaxLpFil; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgAFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgBFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgDaxDif; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgDiagFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgDiagFildLimd; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgDiagSecdryFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcMotVltgQaxDif; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dCurrReasbnDiagcVelLpFild; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CurrReasbnDiagc, RTE_CONST, RTE_CONST) Rte_Inst_CurrReasbnDiagc; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CurrReasbnDiagc, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAgElec_Val (0U)
# define Rte_InitValue_MotTqCmdLimrMin_Val (0.0F)
# define Rte_InitValue_MotVelMrf_Val (0.0F)
# define Rte_InitValue_MotVltgDaxFfStat_Val (0.0F)
# define Rte_InitValue_MotVltgDaxFild_Val (0.0F)
# define Rte_InitValue_MotVltgQaxFfStat_Val (0.0F)
# define Rte_InitValue_MotVltgQaxFild_Val (0.0F)
# define Rte_InitValue_SysMotTqCmdSca_Val (1.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotAgElec_Val(P2VAR(u0p16, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotTqCmdLimrMin_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotVelMrf_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotVltgDaxFfStat_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotVltgDaxFild_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotVltgQaxFfStat_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_MotVltgQaxFild_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CurrReasbnDiagc_SysMotTqCmdSca_Val(P2VAR(float32, AUTOMATIC, RTE_CURRREASBNDIAGC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CurrReasbnDiagc_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcPrimErrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcDiagFildLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcDiagVltgLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcLpFilSca_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVelHiLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVelLoLim_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcVelLpFilFrq_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Prm_CurrReasbnDiagc_SysGlbPrmMotPoleCnt_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcDiagVltgLpFilEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcVelLpFilEna_Logl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAgElec_Val Rte_Read_CurrReasbnDiagc_MotAgElec_Val
# define Rte_Read_MotTqCmdLimrMin_Val Rte_Read_CurrReasbnDiagc_MotTqCmdLimrMin_Val
# define Rte_Read_MotVelMrf_Val Rte_Read_CurrReasbnDiagc_MotVelMrf_Val
# define Rte_Read_MotVltgDaxFfStat_Val Rte_Read_CurrReasbnDiagc_MotVltgDaxFfStat_Val
# define Rte_Read_MotVltgDaxFild_Val Rte_Read_CurrReasbnDiagc_MotVltgDaxFild_Val
# define Rte_Read_MotVltgQaxFfStat_Val Rte_Read_CurrReasbnDiagc_MotVltgQaxFfStat_Val
# define Rte_Read_MotVltgQaxFild_Val Rte_Read_CurrReasbnDiagc_MotVltgQaxFild_Val
# define Rte_Read_SysMotTqCmdSca_Val Rte_Read_CurrReasbnDiagc_SysMotTqCmdSca_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SetNtcSts_Oper Rte_Call_CurrReasbnDiagc_SetNtcSts_Oper


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val

# define Rte_Prm_CurrReasbnDiagcCurrDiagcPrimErrThd_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcPrimErrThd_Val

# define Rte_Prm_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val

# define Rte_Prm_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val

# define Rte_Prm_CurrReasbnDiagcDiagFildLim_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcDiagFildLim_Val

# define Rte_Prm_CurrReasbnDiagcDiagVltgLpFilFrq_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcDiagVltgLpFilFrq_Val

# define Rte_Prm_CurrReasbnDiagcLpFilSca_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcLpFilSca_Val

# define Rte_Prm_CurrReasbnDiagcMotVelHiLim_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVelHiLim_Val

# define Rte_Prm_CurrReasbnDiagcMotVelLoLim_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVelLoLim_Val

# define Rte_Prm_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val

# define Rte_Prm_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val

# define Rte_Prm_CurrReasbnDiagcVelLpFilFrq_Val Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcVelLpFilFrq_Val

# define Rte_Prm_SysGlbPrmMotPoleCnt_Val Rte_Prm_CurrReasbnDiagc_SysGlbPrmMotPoleCnt_Val

# define Rte_Prm_CurrReasbnDiagcDiagVltgLpFilEna_Logl Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcDiagVltgLpFilEna_Logl

# define Rte_Prm_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl

# define Rte_Prm_CurrReasbnDiagcVelLpFilEna_Logl Rte_Prm_CurrReasbnDiagc_CurrReasbnDiagcVelLpFilEna_Logl

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_MotVltgDiagFildInp1Prev() (Rte_Inst_CurrReasbnDiagc->Pim_MotVltgDiagFildInp1Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotVltgDiagFildInp2Prev() (Rte_Inst_CurrReasbnDiagc->Pim_MotVltgDiagFildInp2Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotVltgDiagFildOutp1Prev() (Rte_Inst_CurrReasbnDiagc->Pim_MotVltgDiagFildOutp1Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotVltgDiagFildOutp2Prev() (Rte_Inst_CurrReasbnDiagc->Pim_MotVltgDiagFildOutp2Prev) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgAFild() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgAFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgBFild() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgBFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgDaxDif() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgDaxDif) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgDiagFild() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgDiagFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgDiagFildLimd() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgDiagFildLimd) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgDiagSecdryFild() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgDiagSecdryFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcMotVltgQaxDif() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcMotVltgQaxDif) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dCurrReasbnDiagcVelLpFild() (Rte_Inst_CurrReasbnDiagc->Pim_dCurrReasbnDiagcVelLpFild) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_CurrReasbnMotVelLpFil() (Rte_Inst_CurrReasbnDiagc->Pim_CurrReasbnMotVelLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_DiagVltgLpFil() (Rte_Inst_CurrReasbnDiagc->Pim_DiagVltgLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotVltgDaxLpFil() (Rte_Inst_CurrReasbnDiagc->Pim_MotVltgDaxLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotVltgQaxLpFil() (Rte_Inst_CurrReasbnDiagc->Pim_MotVltgQaxLpFil) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_MotVltgDiagFildInp1Prev(void)
 *   float32 *Rte_Pim_MotVltgDiagFildInp2Prev(void)
 *   float32 *Rte_Pim_MotVltgDiagFildOutp1Prev(void)
 *   float32 *Rte_Pim_MotVltgDiagFildOutp2Prev(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgAFild(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgBFild(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgDaxDif(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgDiagFild(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgDiagFildLimd(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgDiagSecdryFild(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcMotVltgQaxDif(void)
 *   float32 *Rte_Pim_dCurrReasbnDiagcVelLpFild(void)
 *   FilLpRec1 *Rte_Pim_CurrReasbnMotVelLpFil(void)
 *   FilLpRec1 *Rte_Pim_DiagVltgLpFil(void)
 *   FilLpRec1 *Rte_Pim_MotVltgDaxLpFil(void)
 *   FilLpRec1 *Rte_Pim_MotVltgQaxLpFil(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_CurrReasbnDiagcCurrDiagcMotEnvlpTblMax_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcCurrDiagcPrimErrThd_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcCurrDiagcSecdryErrThd_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcCurrDiagcSecdryTqLimThd_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcDiagFildLim_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcDiagVltgLpFilFrq_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcLpFilSca_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcMotVelHiLim_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcMotVelLoLim_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val(void)
 *   float32 Rte_Prm_CurrReasbnDiagcVelLpFilFrq_Val(void)
 *   uint8 Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
 *   boolean Rte_Prm_CurrReasbnDiagcDiagVltgLpFilEna_Logl(void)
 *   boolean Rte_Prm_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl(void)
 *   boolean Rte_Prm_CurrReasbnDiagcVelLpFilEna_Logl(void)
 *
 *********************************************************************************************************************/


# define CurrReasbnDiagc_START_SEC_CODE
# include "CurrReasbnDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrReasbnDiagcInit2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CurrReasbnDiagcInit2 CurrReasbnDiagcInit2
FUNC(void, CurrReasbnDiagc_CODE) CurrReasbnDiagcInit2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CurrReasbnDiagcPer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAgElec_Val(u0p16 *data)
 *   Std_ReturnType Rte_Read_MotTqCmdLimrMin_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVelMrf_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVltgDaxFfStat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVltgDaxFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVltgQaxFfStat_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotVltgQaxFild_Val(float32 *data)
 *   Std_ReturnType Rte_Read_SysMotTqCmdSca_Val(float32 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_CurrReasbnDiagcPer2 CurrReasbnDiagcPer2
FUNC(void, CurrReasbnDiagc_CODE) CurrReasbnDiagcPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CurrReasbnDiagc_STOP_SEC_CODE
# include "CurrReasbnDiagc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1482162429
#    error "The magic number of the generated file <C:/Component/SF031A_CurrReasbnDiagc_Impl/tools/contract/Rte_CurrReasbnDiagc.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1482162429
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CURRREASBNDIAGC_H */
