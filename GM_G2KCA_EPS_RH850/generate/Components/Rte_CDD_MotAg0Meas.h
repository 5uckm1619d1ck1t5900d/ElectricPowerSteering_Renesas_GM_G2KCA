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
 *          File:  Rte_CDD_MotAg0Meas.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg0Meas>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG0MEAS_H
# define _RTE_CDD_MOTAG0MEAS_H

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

# include "Rte_CDD_MotAg0Meas_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0MeclRollgCntr_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0Offs_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl0Polarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAg0MeclQlfr_Val (0U)
#  define Rte_InitValue_MotAg0MeclRollgCntr_Val (0U)
#  define Rte_InitValue_MotAg0Offs_Val (0)
#  define Rte_InitValue_MotAgMecl0Polarity_Val (1)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(u0p16, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg0DiagcAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg0SpiTrsmEna; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg3Mecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAgMecl0Polarity_Val Rte_Read_CDD_MotAg0Meas_MotAgMecl0Polarity_Val
#  define Rte_Read_CDD_MotAg0Meas_MotAgMecl0Polarity_Val(data) (*(data) = Rte_PolarityCfg_MotAgMecl0Polarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_MotAg0MeclQlfr_Val Rte_Write_CDD_MotAg0Meas_MotAg0MeclQlfr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0MeclQlfr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0MeclRollgCntr_Val Rte_Write_CDD_MotAg0Meas_MotAg0MeclRollgCntr_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0MeclRollgCntr_Val(data) (Rte_CDD_MotAg0Meas_MotAg0MeclRollgCntr_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg0Offs_Val Rte_Write_CDD_MotAg0Meas_MotAg0Offs_Val
#  define Rte_Write_CDD_MotAg0Meas_MotAg0Offs_Val(data) (Rte_CDD_MotAg0Meas_MotAg0Offs_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_MOTAG3MEAS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_MOTAG3MEAS_APPL_CODE) GetMotAg3Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG3MEAS_APPL_VAR) MotAgMecl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_MOTAG3MEAS_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetMotAg3Mecl_Oper(arg1) (GetMotAg3Mecl_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) GetNtcQlfrSts10_Oper(NtcNr1 NtcNr_Arg, P2VAR(SigQlfr1, AUTOMATIC, RTE_DIAGCMGRPROXYAPPL10_APPL_VAR) NtcQlfr_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetNtcQlfrSts_Oper GetNtcQlfrSts10_Oper
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetRefTmr1MicroSec32bit_Oper(P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) RefTmr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetRefTmr1MicroSec32bit_Oper(arg1) (GetRefTmr1MicroSec32bit_Oper(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CDD_NXTRTI_APPL_CODE) GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr, P2VAR(uint32, AUTOMATIC, RTE_CDD_NXTRTI_APPL_VAR) TiSpan); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CDD_NXTRTI_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_GetTiSpan1MicroSec32bit_Oper(arg1, arg2) (GetTiSpan1MicroSec32bit_Oper(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctGpioMotAg0_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctGpioMotAg0_Oper IoHwAb_SetFctGpioMotAg0_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetFctPeriphMotAg0_Oper(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetFctPrphlCsihMotAg0_Oper IoHwAb_SetFctPeriphMotAg0_Oper
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_SetGpioMotAg0_Oper(IOHWAB_BOOL PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_IoHwAb_SetGpioMotAg0CsihCs_Oper IoHwAb_SetGpioMotAg0_Oper
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg0CoeffTbl_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((NvM_BlockIdType)114, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_MotAg0CoeffTbl_SetRamBlockStatus(arg1) (NvMProxy_SetRamBlockStatus((NvM_BlockIdType)114, arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DIAGCMGRPROXYAPPL10_APPL_CODE) SetNtcSts10_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DIAGCMGRPROXYAPPL10_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_SetNtcSts_Oper SetNtcSts10_Oper


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_MotAg0MeasPer2_MotAg0DiagcAg() \
  Rte_Irv_CDD_MotAg0Meas_MotAg0DiagcAg
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_MotAg0MeasPer2_MotAg0SpiTrsmEna() \
  Rte_Irv_CDD_MotAg0Meas_MotAg0SpiTrsmEna
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvRead_MotAg0MeasPer2_MotAg3Mecl() \
  Rte_Irv_CDD_MotAg0Meas_MotAg3Mecl
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_MotAg0MeasPer3_MotAg0DiagcAg(data) \
  (Rte_Irv_CDD_MotAg0Meas_MotAg0DiagcAg = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_MotAg0MeasPer3_MotAg0SpiTrsmEna(data) \
  (Rte_Irv_CDD_MotAg0Meas_MotAg0SpiTrsmEna = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_19.7 */
#  define Rte_IrvWrite_MotAg0MeasPer3_MotAg3Mecl(data) \
  (Rte_Irv_CDD_MotAg0Meas_MotAg3Mecl = (data))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_CData_MotAg0CoeffTblDft() (&(((P2CONST(Rte_Calprm_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP])->MotAg0CoeffTblDft[0])) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  else
#   define Rte_CData_MotAg0CoeffTblDft() (&((P2CONST(Rte_Calprm_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CDD_MotAg0Meas_DEFAULT_RTE_CDATA_GROUP])->MotAg0CoeffTblDft) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  endif

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0TurnCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawAgReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawErrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawTurnCntrReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RtOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0Diagc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevSpiErrFltCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0Delta; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0SpiCntrAg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0SpiMecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotCtrlMotAg3Mecl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0InitOffs; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevRollgCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_f32_26, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0CoeffTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_sm5p12_128, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0CorrnTbl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Ary1D_u32_10, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawReg; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_dMotAg0MeasMotAg0TurnCntr() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0TurnCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawAgReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawAgReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawErrReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawErrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RawTurnCntrReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawTurnCntrReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0PrevOffs() \
  (&Rte_CDD_MotAg0Meas_MotAg0PrevOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0RtOffs() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RtOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0Diagc() \
  (&Rte_CDD_MotAg0Meas_MotAg0Diagc) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0PrevSpiErrFltCntr() \
  (&Rte_CDD_MotAg0Meas_MotAg0PrevSpiErrFltCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0Delta() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0Delta) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0SpiCntrAg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0SpiCntrAg) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotAg0SpiMecl() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0SpiMecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dMotAg0MeasMotCtrlMotAg3Mecl() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotCtrlMotAg3Mecl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0InitOffs() \
  (&Rte_CDD_MotAg0Meas_MotAg0InitOffs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_MotAg0PrevRollgCntr() \
  (&Rte_CDD_MotAg0Meas_MotAg0PrevRollgCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotAg0CoeffTbl() (&((*RtePim_MotAg0CoeffTbl())[0]))
#  else
#   define Rte_Pim_MotAg0CoeffTbl() RtePim_MotAg0CoeffTbl()
#  endif
#  define RtePim_MotAg0CoeffTbl() \
  (&Rte_CDD_MotAg0Meas_MotAg0CoeffTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_MotAg0CorrnTbl() (&((*RtePim_MotAg0CorrnTbl())[0]))
#  else
#   define Rte_Pim_MotAg0CorrnTbl() RtePim_MotAg0CorrnTbl()
#  endif
#  define RtePim_MotAg0CorrnTbl() \
  (&Rte_CDD_MotAg0Meas_MotAg0CorrnTbl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#   define Rte_Pim_dMotAg0MeasMotAg0RawReg() (&((*RtePim_dMotAg0MeasMotAg0RawReg())[0]))
#  else
#   define Rte_Pim_dMotAg0MeasMotAg0RawReg() RtePim_dMotAg0MeasMotAg0RawReg()
#  endif
#  define RtePim_dMotAg0MeasMotAg0RawReg() \
  (&Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawReg) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_MotAg0Meas_START_SEC_CODE
# include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotAg0CoeffTblRead_Oper MotAg0CoeffTblRead_Oper
#  define RTE_RUNNABLE_MotAg0CoeffTblWr_Oper MotAg0CoeffTblWr_Oper
#  define RTE_RUNNABLE_MotAg0MeasInit1 MotAg0MeasInit1
#  define RTE_RUNNABLE_MotAg0MeasPer2 MotAg0MeasPer2
#  define RTE_RUNNABLE_MotAg0MeasPer3 MotAg0MeasPer3
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblRead_Oper(P2VAR(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_VAR) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(float32, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0CoeffTblWr_Oper(P2CONST(Ary1D_f32_26, AUTOMATIC, RTE_CDD_MOTAG0MEAS_APPL_DATA) MotAgCoeffTbl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_MotAg0Meas_CODE) MotAg0MeasPer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_MotAg0Meas_STOP_SEC_CODE
# include "CDD_MotAg0Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_GetNtcQlfrSts_PortIf1_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_SetFctGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetFctPeriph_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetGpio_PortIf1_E_NOT_OK (1U)

#  define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG0MEAS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
