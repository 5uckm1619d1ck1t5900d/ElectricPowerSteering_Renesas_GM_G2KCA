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
 *          File:  Rte_CDD_GmG2kcaMcuCfg.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_GmG2kcaMcuCfg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_GMG2KCAMCUCFG_H
# define _RTE_CDD_GMG2KCAMCUCFG_H

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

# include "Rte_CDD_GmG2kcaMcuCfg_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag0_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag2_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag4_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltg_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1AdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2AdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_EcuT_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_EcuTAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2Cos_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2CosAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2Sin_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2SinAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakAAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakBAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakCAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakDAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakEAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakFAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyAAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyBAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyCAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyDAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyEAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyFAdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs1AdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs2AdcFaild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc0Faild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc1Faild_Logl; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Adc0Faild_Logl (FALSE)
#  define Rte_InitValue_Adc1Faild_Logl (FALSE)
#  define Rte_InitValue_Adc1ScanGroup2Ref0_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup2Ref1_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup3Ref0_Val (0.0F)
#  define Rte_InitValue_Adc1ScanGroup3Ref1_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag0_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag2_Val (0.0F)
#  define Rte_InitValue_Adc1SelfDiag4_Val (0.0F)
#  define Rte_InitValue_BattVltg_Val (0.0F)
#  define Rte_InitValue_BattVltgAdcFaild_Logl (FALSE)
#  define Rte_InitValue_BattVltgSwd1_Val (0.0F)
#  define Rte_InitValue_BattVltgSwd1AdcFaild_Logl (FALSE)
#  define Rte_InitValue_BattVltgSwd2_Val (0.0F)
#  define Rte_InitValue_BattVltgSwd2AdcFaild_Logl (FALSE)
#  define Rte_InitValue_EcuT_Val (0.0F)
#  define Rte_InitValue_EcuTAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotAg2Cos_Val (0.0F)
#  define Rte_InitValue_MotAg2CosAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotAg2Sin_Val (0.0F)
#  define Rte_InitValue_MotAg2SinAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcPeakAAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcPeakBAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcPeakCAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcPeakDAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcPeakEAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcPeakFAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyAAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyBAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyCAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyDAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyEAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrAdcVlyFAdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrSnsrOffs1AdcFaild_Logl (FALSE)
#  define Rte_InitValue_MotCurrSnsrOffs2AdcFaild_Logl (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Adc0Faild_Logl Rte_Read_CDD_GmG2kcaMcuCfg_Adc0Faild_Logl
#  define Rte_Read_CDD_GmG2kcaMcuCfg_Adc0Faild_Logl(data) (*(data) = Rte_CDD_AdcDiagc_Adc0Faild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Adc1Faild_Logl Rte_Read_CDD_GmG2kcaMcuCfg_Adc1Faild_Logl
#  define Rte_Read_CDD_GmG2kcaMcuCfg_Adc1Faild_Logl(data) (*(data) = Rte_CDD_AdcDiagc_Adc1Faild_Logl, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Adc1ScanGroup2Ref0_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref0_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref0_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1ScanGroup2Ref1_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref1_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref1_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1ScanGroup3Ref0_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref0_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref0_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1ScanGroup3Ref1_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref1_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref1_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1SelfDiag0_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1SelfDiag0_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1SelfDiag0_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag0_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1SelfDiag2_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1SelfDiag2_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1SelfDiag2_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag2_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_Adc1SelfDiag4_Val Rte_Write_CDD_GmG2kcaMcuCfg_Adc1SelfDiag4_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_Adc1SelfDiag4_Val(data) (Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag4_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltg_Val Rte_Write_CDD_GmG2kcaMcuCfg_BattVltg_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_BattVltg_Val(data) (Rte_CDD_GmG2kcaMcuCfg_BattVltg_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_BattVltgAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgSwd1_Val Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd1_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd1_Val(data) (Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgSwd1AdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd1AdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd1AdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1AdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgSwd2_Val Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd2_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd2_Val(data) (Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_BattVltgSwd2AdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd2AdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_BattVltgSwd2AdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2AdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_EcuT_Val Rte_Write_CDD_GmG2kcaMcuCfg_EcuT_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_EcuT_Val(data) (Rte_CDD_GmG2kcaMcuCfg_EcuT_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_EcuTAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_EcuTAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_EcuTAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_EcuTAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg2Cos_Val Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2Cos_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2Cos_Val(data) (Rte_CDD_GmG2kcaMcuCfg_MotAg2Cos_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg2CosAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2CosAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2CosAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotAg2CosAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg2Sin_Val Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2Sin_Val
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2Sin_Val(data) (Rte_CDD_GmG2kcaMcuCfg_MotAg2Sin_Val = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotAg2SinAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2SinAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotAg2SinAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotAg2SinAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcPeakAAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakAAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakAAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakAAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcPeakBAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakBAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakBAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakBAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcPeakCAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakCAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakCAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakCAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcPeakDAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakDAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakDAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakDAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcPeakEAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakEAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakEAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakEAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcPeakFAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakFAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakFAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakFAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyAAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyAAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyAAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyAAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyBAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyBAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyBAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyBAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyCAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyCAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyCAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyCAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyDAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyDAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyDAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyDAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyEAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyEAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyEAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyEAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrAdcVlyFAdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyFAdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyFAdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyFAdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrSnsrOffs1AdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs1AdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs1AdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs1AdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_MotCurrSnsrOffs2AdcFaild_Logl Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs2AdcFaild_Logl
#  define Rte_Write_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs2AdcFaild_Logl(data) (Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs2AdcFaild_Logl = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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


# endif /* !defined(RTE_CORE) */


# define CDD_GmG2kcaMcuCfg_START_SEC_CODE
# include "CDD_GmG2kcaMcuCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_GmG2kcaMcuCfgInit1 GmG2kcaMcuCfgInit1
#  define RTE_RUNNABLE_GmG2kcaMcuCfgInit2 GmG2kcaMcuCfgInit2
#  define RTE_RUNNABLE_GmG2kcaMcuCfgInit3 GmG2kcaMcuCfgInit3
#  define RTE_RUNNABLE_GmG2kcaMcuCfgPer2 GmG2kcaMcuCfgPer2
#  define RTE_RUNNABLE_GmG2kcaMcuCfgPer3 GmG2kcaMcuCfgPer3
# endif

FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgPer2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgPer3(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_GmG2kcaMcuCfg_STOP_SEC_CODE
# include "CDD_GmG2kcaMcuCfg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_GMG2KCAMCUCFG_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
