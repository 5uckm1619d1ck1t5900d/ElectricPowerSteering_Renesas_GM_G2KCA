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
 *          File:  Rte_ElecPwrCns.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <ElecPwrCns>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_ELECPWRCNS_H
# define _RTE_ELECPWRCNS_H

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

# include "Rte_ElecPwrCns_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_ElecInpPwrEstim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_SplyCurrEstim_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_BattVltg_BrdgVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LoaMgr_CurrMeasLoaMtgtnEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_LoaMgr_IvtrLoaMtgtnEna_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_MotCtrlMotVltgDax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_MotCtrlMotVltgQax_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrDaxCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrQaxCmd_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_BrdgVltg_Val (6.0F)
#  define Rte_InitValue_CurrMeasLoaMtgtnEna_Logl (FALSE)
#  define Rte_InitValue_ElecInpPwrEstim_Val (0.0F)
#  define Rte_InitValue_IvtrLoaMtgtnEna_Logl (FALSE)
#  define Rte_InitValue_MotCtrlMotCurrDax_Val (0.0F)
#  define Rte_InitValue_MotCtrlMotCurrQax_Val (0.0F)
#  define Rte_InitValue_MotCtrlMotVltgDax_Val (0.0F)
#  define Rte_InitValue_MotCtrlMotVltgQax_Val (0.0F)
#  define Rte_InitValue_MotCurrDaxCmd_Val (0.0F)
#  define Rte_InitValue_MotCurrQaxCmd_Val (0.0F)
#  define Rte_InitValue_SplyCurrEstim_Val (0.0F)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BrdgVltg_Val Rte_Read_ElecPwrCns_BrdgVltg_Val
#  define Rte_Read_ElecPwrCns_BrdgVltg_Val(data) (*(data) = Rte_BattVltg_BrdgVltg_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CurrMeasLoaMtgtnEna_Logl Rte_Read_ElecPwrCns_CurrMeasLoaMtgtnEna_Logl
#  define Rte_Read_ElecPwrCns_CurrMeasLoaMtgtnEna_Logl(data) (*(data) = Rte_LoaMgr_CurrMeasLoaMtgtnEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_IvtrLoaMtgtnEna_Logl Rte_Read_ElecPwrCns_IvtrLoaMtgtnEna_Logl
#  define Rte_Read_ElecPwrCns_IvtrLoaMtgtnEna_Logl(data) (*(data) = Rte_LoaMgr_IvtrLoaMtgtnEna_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCtrlMotCurrDax_Val Rte_Read_ElecPwrCns_MotCtrlMotCurrDax_Val
#  define Rte_Read_ElecPwrCns_MotCtrlMotCurrDax_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCtrlMotCurrQax_Val Rte_Read_ElecPwrCns_MotCtrlMotCurrQax_Val
#  define Rte_Read_ElecPwrCns_MotCtrlMotCurrQax_Val(data) (*(data) = Rte_CDD_MotCtrlMgr_MotCurrQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCtrlMotVltgDax_Val Rte_Read_ElecPwrCns_MotCtrlMotVltgDax_Val
#  define Rte_Read_ElecPwrCns_MotCtrlMotVltgDax_Val(data) (*(data) = Rte_ElecPwrCns_MotCtrlMotVltgDax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCtrlMotVltgQax_Val Rte_Read_ElecPwrCns_MotCtrlMotVltgQax_Val
#  define Rte_Read_ElecPwrCns_MotCtrlMotVltgQax_Val(data) (*(data) = Rte_ElecPwrCns_MotCtrlMotVltgQax_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrDaxCmd_Val Rte_Read_ElecPwrCns_MotCurrDaxCmd_Val
#  define Rte_Read_ElecPwrCns_MotCurrDaxCmd_Val(data) (*(data) = Rte_MotRefMdl_MotCurrDaxCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_MotCurrQaxCmd_Val Rte_Read_ElecPwrCns_MotCurrQaxCmd_Val
#  define Rte_Read_ElecPwrCns_MotCurrQaxCmd_Val(data) (*(data) = Rte_MotRefMdl_MotCurrQaxCmd_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ElecInpPwrEstim_Val Rte_Write_ElecPwrCns_ElecInpPwrEstim_Val
#  define Rte_Write_ElecPwrCns_ElecInpPwrEstim_Val(data) (Rte_ElecPwrCns_ElecInpPwrEstim_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_SplyCurrEstim_Val Rte_Write_ElecPwrCns_SplyCurrEstim_Val
#  define Rte_Write_ElecPwrCns_SplyCurrEstim_Val(data) (Rte_ElecPwrCns_SplyCurrEstim_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01Cmn_ElecPwrCnsCtrlrInpR_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(float32, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_CalRegn01CmnGroupA_ElecPwrCnsPrstcPwrLoss_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Prm_ElecPwrCnsCtrlrInpR_Val() (Rte_CalRegn01Cmn_ElecPwrCnsCtrlrInpR_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_ElecPwrCnsPrstcPwrLoss_Val() (Rte_CalRegn01CmnGroupA_ElecPwrCnsPrstcPwrLoss_Val) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsDrpInpPwr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsModInpPwr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsMotCurrDaxEstim; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsMotCurrQaxEstim; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  endif

#  define Rte_Pim_dElecPwrCnsDrpInpPwr() \
  (&Rte_ElecPwrCns_dElecPwrCnsDrpInpPwr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dElecPwrCnsModInpPwr() \
  (&Rte_ElecPwrCns_dElecPwrCnsModInpPwr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dElecPwrCnsMotCurrDaxEstim() \
  (&Rte_ElecPwrCns_dElecPwrCnsMotCurrDaxEstim) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Pim_dElecPwrCnsMotCurrQaxEstim() \
  (&Rte_ElecPwrCns_dElecPwrCnsMotCurrQaxEstim) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define ElecPwrCns_START_SEC_CODE
# include "ElecPwrCns_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ElecPwrCnsPer1 ElecPwrCnsPer1
# endif

FUNC(void, ElecPwrCns_CODE) ElecPwrCnsPer1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define ElecPwrCns_STOP_SEC_CODE
# include "ElecPwrCns_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_ELECPWRCNS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
