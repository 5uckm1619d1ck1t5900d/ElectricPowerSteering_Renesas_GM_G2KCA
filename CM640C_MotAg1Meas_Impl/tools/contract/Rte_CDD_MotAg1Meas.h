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
 *          File:  Rte_CDD_MotAg1Meas.h
 *     SW-C Type:  CDD_MotAg1Meas
 *  Generated at:  Wed Jan 25 10:07:35 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg1Meas> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG1MEAS_H
# define _RTE_CDD_MOTAG1MEAS_H

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

# include "Rte_CDD_MotAg1Meas_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_MotAg1Meas
{
  /* PIM Handles section */
  P2VAR(Ary1D_f32_26, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1CoeffTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary1D_sm5p12_128, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1CorrnTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1Diagc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1InitOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1PrevOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1PrevRollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_MotAg1PrevSpiErrFltCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1Delta; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawAgReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawErrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary1D_u32_10, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RawTurnCntrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(sint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1RtOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1SpiCntrAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1SpiMecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(float32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotAg1TurnCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(u0p16, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_dMotAg1MeasMotCtrlMotAg4Mecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_MotAg1Meas, RTE_CONST, RTE_CONST) Rte_Inst_CDD_MotAg1Meas; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_MotAg1Meas, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_MotAg1MeclQlfr_Val (0U)
# define Rte_InitValue_MotAg1MeclRollgCntr_Val (0U)
# define Rte_InitValue_MotAg1Offs_Val (0)
# define Rte_InitValue_MotAgMecl1Polarity_Val (1)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotAg1Meas_MotAgMecl1Polarity_Val(P2VAR(sint8, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1MeclQlfr_Val(SigQlfr1 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1MeclRollgCntr_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotAg1Meas_MotAg1Offs_Val(sint32 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_GetMotAg4Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgMecl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) RefTmr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, P2VAR(uint32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) TiSpan_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctPrphlCsihMotAg1_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1CsihCs_Oper(boolean PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_MotAg1Meas_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u0p16, RTE_CODE) Rte_Prm_CDD_MotAg1Meas_MotAg1MeasMotAgOffs_Val(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u0p16, RTE_CODE) Rte_IrvRead_CDD_MotAg1Meas_MotAg1MeasPer2_MotAg1DiagcAg(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(boolean, RTE_CODE) Rte_IrvRead_CDD_MotAg1Meas_MotAg1MeasPer2_MotAg1SpiTrsmEna(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(u0p16, RTE_CODE) Rte_IrvRead_CDD_MotAg1Meas_MotAg1MeasPer2_MotAg4Mecl(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_CDD_MotAg1Meas_MotAg1MeasPer3_MotAg1DiagcAg(u0p16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_CDD_MotAg1Meas_MotAg1MeasPer3_MotAg1SpiTrsmEna(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_IrvWrite_CDD_MotAg1Meas_MotAg1MeasPer3_MotAg4Mecl(u0p16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC_P2CONST(float32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_MotAg1Meas_MotAg1CoeffTblDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC_P2CONST(Ary1D_f32_26, RTE_CONST_DEFAULT_RTE_CDATA_GROUP, RTE_CODE) Rte_CData_CDD_MotAg1Meas_MotAg1CoeffTblDft(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_MotAgMecl1Polarity_Val Rte_Read_CDD_MotAg1Meas_MotAgMecl1Polarity_Val


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_MotAg1MeclQlfr_Val Rte_Write_CDD_MotAg1Meas_MotAg1MeclQlfr_Val
# define Rte_Write_MotAg1MeclRollgCntr_Val Rte_Write_CDD_MotAg1Meas_MotAg1MeclRollgCntr_Val
# define Rte_Write_MotAg1Offs_Val Rte_Write_CDD_MotAg1Meas_MotAg1Offs_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetMotAg4Mecl_Oper Rte_Call_CDD_MotAg1Meas_GetMotAg4Mecl_Oper
# define Rte_Call_GetNtcQlfrSts_Oper Rte_Call_CDD_MotAg1Meas_GetNtcQlfrSts_Oper
# define Rte_Call_GetRefTmr1MicroSec32bit_Oper Rte_Call_CDD_MotAg1Meas_GetRefTmr1MicroSec32bit_Oper
# define Rte_Call_GetTiSpan1MicroSec32bit_Oper Rte_Call_CDD_MotAg1Meas_GetTiSpan1MicroSec32bit_Oper
# define Rte_Call_IoHwAb_SetFctGpioMotAg1_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctGpioMotAg1_Oper
# define Rte_Call_IoHwAb_SetFctPrphlCsihMotAg1_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetFctPrphlCsihMotAg1_Oper
# define Rte_Call_IoHwAb_SetGpioMotAg1CsihCs_Oper Rte_Call_CDD_MotAg1Meas_IoHwAb_SetGpioMotAg1CsihCs_Oper
# define Rte_Call_MotAg1CoeffTbl_GetErrorStatus Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_GetErrorStatus
# define Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus Rte_Call_CDD_MotAg1Meas_MotAg1CoeffTbl_SetRamBlockStatus
# define Rte_Call_SetNtcSts_Oper Rte_Call_CDD_MotAg1Meas_SetNtcSts_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_MotAg1MeasPer2_MotAg1DiagcAg() \
  Rte_IrvRead_CDD_MotAg1Meas_MotAg1MeasPer2_MotAg1DiagcAg()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_MotAg1MeasPer2_MotAg1SpiTrsmEna() \
  Rte_IrvRead_CDD_MotAg1Meas_MotAg1MeasPer2_MotAg1SpiTrsmEna()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvRead_MotAg1MeasPer2_MotAg4Mecl() \
  Rte_IrvRead_CDD_MotAg1Meas_MotAg1MeasPer2_MotAg4Mecl()
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_MotAg1MeasPer3_MotAg1DiagcAg(data) \
  Rte_IrvWrite_CDD_MotAg1Meas_MotAg1MeasPer3_MotAg1DiagcAg(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_MotAg1MeasPer3_MotAg1SpiTrsmEna(data) \
  Rte_IrvWrite_CDD_MotAg1Meas_MotAg1MeasPer3_MotAg1SpiTrsmEna(data)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
# define Rte_IrvWrite_MotAg1MeasPer3_MotAg4Mecl(data) \
  Rte_IrvWrite_CDD_MotAg1Meas_MotAg1MeasPer3_MotAg4Mecl(data)
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

# define Rte_CData_MotAg1CoeffTblDft Rte_CData_CDD_MotAg1Meas_MotAg1CoeffTblDft

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

# define Rte_Prm_MotAg1MeasMotAgOffs_Val Rte_Prm_CDD_MotAg1Meas_MotAg1MeasMotAgOffs_Val

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_dMotAg1MeasMotAg1TurnCntr() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1TurnCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawAgReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawAgReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawErrReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawErrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawTurnCntrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1PrevOffs() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1PrevOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1RtOffs() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RtOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1Diagc() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1Diagc) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1PrevSpiErrFltCntr() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1PrevSpiErrFltCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1Delta() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1Delta) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1SpiCntrAg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1SpiCntrAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotAg1SpiMecl() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1SpiMecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_dMotAg1MeasMotCtrlMotAg4Mecl() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotCtrlMotAg4Mecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1InitOffs() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1InitOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_MotAg1PrevRollgCntr() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1PrevRollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_MotAg1CoeffTbl() (*Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_MotAg1CoeffTbl() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_MotAg1CorrnTbl() (*Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_MotAg1CorrnTbl() (Rte_Inst_CDD_MotAg1Meas->Pim_MotAg1CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_dMotAg1MeasMotAg1RawReg() (*Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_dMotAg1MeasMotAg1RawReg() (Rte_Inst_CDD_MotAg1Meas->Pim_dMotAg1MeasMotAg1RawReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_dMotAg1MeasMotAg1TurnCntr(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawAgReg(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawErrReg(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawTurnCntrReg(void)
 *   sint32 *Rte_Pim_MotAg1PrevOffs(void)
 *   sint32 *Rte_Pim_dMotAg1MeasMotAg1RtOffs(void)
 *   u0p16 *Rte_Pim_MotAg1Diagc(void)
 *   uint16 *Rte_Pim_MotAg1PrevSpiErrFltCntr(void)
 *   u0p16 *Rte_Pim_dMotAg1MeasMotAg1Delta(void)
 *   u0p16 *Rte_Pim_dMotAg1MeasMotAg1SpiCntrAg(void)
 *   u0p16 *Rte_Pim_dMotAg1MeasMotAg1SpiMecl(void)
 *   u0p16 *Rte_Pim_dMotAg1MeasMotCtrlMotAg4Mecl(void)
 *   uint8 *Rte_Pim_MotAg1InitOffs(void)
 *   uint8 *Rte_Pim_MotAg1PrevRollgCntr(void)
 *   float32 *Rte_Pim_MotAg1CoeffTbl(void)
 *   sm5p12 *Rte_Pim_MotAg1CorrnTbl(void)
 *   uint32 *Rte_Pim_dMotAg1MeasMotAg1RawReg(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   float32 *Rte_CData_MotAg1CoeffTblDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   u0p16 Rte_Prm_MotAg1MeasMotAgOffs_Val(void)
 *
 *********************************************************************************************************************/


# define CDD_MotAg1Meas_START_SEC_CODE
# include "CDD_MotAg1Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1CoeffTblRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg1CoeffTblRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg1CoeffTblRead_Oper(float32 *MotAgCoeffTbl_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1CoeffTblRead_Oper MotAg1CoeffTblRead_Oper
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblRead_Oper(P2VAR(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1CoeffTblWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAg1CoeffTblWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg1CoeffTbl_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAg1CoeffTblWr_Oper(const float32 *MotAgCoeffTbl_Arg)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1CoeffTblWr_Oper MotAg1CoeffTblWr_Oper
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1CoeffTblWr_Oper(P2CONST(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG1MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1MeasInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAg1CoeffTbl_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1MeasInit1 MotAg1MeasInit1
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1MeasPer2
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
 *   Std_ReturnType Rte_Read_MotAgMecl1Polarity_Val(sint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAg1MeclQlfr_Val(SigQlfr1 data)
 *   Std_ReturnType Rte_Write_MotAg1MeclRollgCntr_Val(uint8 data)
 *   Std_ReturnType Rte_Write_MotAg1Offs_Val(sint32 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   u0p16 Rte_IrvRead_MotAg1MeasPer2_MotAg1DiagcAg(void)
 *   boolean Rte_IrvRead_MotAg1MeasPer2_MotAg1SpiTrsmEna(void)
 *   u0p16 Rte_IrvRead_MotAg1MeasPer2_MotAg4Mecl(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetNtcQlfrSts_Oper(NtcNr1 NtcNr_Arg, SigQlfr1 *NtcQlfr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1MeasPer2 MotAg1MeasPer2
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasPer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg1MeasPer3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_MotAg1MeasPer3_MotAg1DiagcAg(u0p16 data)
 *   void Rte_IrvWrite_MotAg1MeasPer3_MotAg1SpiTrsmEna(boolean data)
 *   void Rte_IrvWrite_MotAg1MeasPer3_MotAg4Mecl(u0p16 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetMotAg4Mecl_Oper(u0p16 *MotAgMecl_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr_Arg, uint32 *TiSpan_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctGpioMotAg1_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetFctPrphlCsihMotAg1_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetFctPeriph_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_SetGpioMotAg1CsihCs_Oper(boolean PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_MotAg1MeasPer3 MotAg1MeasPer3
FUNC(void, CDD_MotAg1Meas_CODE) MotAg1MeasPer3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_MotAg1Meas_STOP_SEC_CODE
# include "CDD_MotAg1Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

# define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

# define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetFctPeriph_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1485351287
#    error "The magic number of the generated file <C:/Component/CM640C_MotAg1Meas_Impl/tools/contract/Rte_CDD_MotAg1Meas.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1485351287
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CDD_MOTAG1MEAS_H */
