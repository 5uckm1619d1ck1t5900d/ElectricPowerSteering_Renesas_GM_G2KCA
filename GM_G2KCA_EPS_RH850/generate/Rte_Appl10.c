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
 *          File:  Rte_Appl10.c
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_Rte_0777, MD_Rte_0779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_Assi.h"
#include "Rte_AssiHiFrq.h"
#include "Rte_AssiPahFwl.h"
#include "Rte_AssiSumLim.h"
#include "Rte_BattVltg.h"
#include "Rte_BattVltgCorrln.h"
#include "Rte_BswM.h"
#include "Rte_CDD_Adc0CfgAndUse.h"
#include "Rte_CDD_Adc1CfgAndUse.h"
#include "Rte_CDD_AdcDiagc.h"
#include "Rte_CDD_ChkPtAppl10.h"
#include "Rte_CDD_ChkPtAppl6.h"
#include "Rte_CDD_CurrMeas.h"
#include "Rte_CDD_CurrMeasArbn.h"
#include "Rte_CDD_DataAndAdrPar.h"
#include "Rte_CDD_DmaCfgAndUse.h"
#include "Rte_CDD_EcmOutpAndDiagc.h"
#include "Rte_CDD_ExcpnHndlg.h"
#include "Rte_CDD_FlsMem.h"
#include "Rte_CDD_GMLANSdl.h"
#include "Rte_CDD_GmG2kcaMcuCfg.h"
#include "Rte_CDD_GuardCfgAndDiagc.h"
#include "Rte_CDD_HwTq0Meas.h"
#include "Rte_CDD_HwTq1Meas.h"
#include "Rte_CDD_HwTq2Meas.h"
#include "Rte_CDD_HwTq3Meas.h"
#include "Rte_CDD_McuCoreCfgAndDiagc.h"
#include "Rte_CDD_McuDiagc.h"
#include "Rte_CDD_MotAg0Meas.h"
#include "Rte_CDD_MotAg1Meas.h"
#include "Rte_CDD_MotAg3Meas.h"
#include "Rte_CDD_MotAg4Meas.h"
#include "Rte_CDD_MotAgArbn.h"
#include "Rte_CDD_MotAgCmp.h"
#include "Rte_CDD_MotCtrlMgr.h"
#include "Rte_CDD_MotCurrRegVltgLimr.h"
#include "Rte_CDD_MotRplCoggCmd.h"
#include "Rte_CDD_MotVel.h"
#include "Rte_CDD_NvMProxy.h"
#include "Rte_CDD_NxtrTi.h"
#include "Rte_CDD_RamMem.h"
#include "Rte_CDD_Sci30CfgAndUse.h"
#include "Rte_CDD_SinVltgGenn.h"
#include "Rte_CDD_SnsrMeasStrt.h"
#include "Rte_CDD_SyncCrc.h"
#include "Rte_CDD_TSG31CfgAndUse.h"
#include "Rte_CDD_Tauj0CfgAndUse.h"
#include "Rte_CDD_Tauj1CfgAndUse.h"
#include "Rte_CDD_VrfyCritReg.h"
#include "Rte_CDD_XcpIf.h"
#include "Rte_CalRegn01Rt01_Dummy.h"
#include "Rte_CalRegn02Rt01GroupC_Dummy.h"
#include "Rte_CalRegn03Rt01GroupA_Dummy.h"
#include "Rte_CalRegn03Rt01GroupB_Dummy.h"
#include "Rte_CalRegn03Rt01_Dummy.h"
#include "Rte_CmnMfgSrv.h"
#include "Rte_CmnMfgSrvIf.h"
#include "Rte_CmplncErr.h"
#include "Rte_CurrMeasCorrln.h"
#include "Rte_CurrReasbnDiagc.h"
#include "Rte_CustDiagc.h"
#include "Rte_Dampg.h"
#include "Rte_DampgPahFwl.h"
#include "Rte_Dem.h"
#include "Rte_Det.h"
#include "Rte_DiagcMgr.h"
#include "Rte_DiagcMgrProxyAppl10.h"
#include "Rte_DiagcMgrProxyAppl6.h"
#include "Rte_DiagcMgrStub.h"
#include "Rte_DualEcuIdn.h"
#include "Rte_DutyCycThermProtn.h"
#include "Rte_EcuM.h"
#include "Rte_EcuTMeas.h"
#include "Rte_ElecPwrCns.h"
#include "Rte_EotLrng.h"
#include "Rte_EotProtn.h"
#include "Rte_EotProtnFwl.h"
#include "Rte_FltInj.h"
#include "Rte_GateDrv0Ctrl.h"
#include "Rte_GmFctDiArbn.h"
#include "Rte_GmMsg0C5BusHiSpd.h"
#include "Rte_GmMsg0C9BusHiSpd.h"
#include "Rte_GmMsg148BusHiSpd.h"
#include "Rte_GmMsg17DBusHiSpd.h"
#include "Rte_GmMsg180BusChassisExp.h"
#include "Rte_GmMsg180BusHiSpd.h"
#include "Rte_GmMsg182BusChassisExp.h"
#include "Rte_GmMsg184BusHiSpd.h"
#include "Rte_GmMsg1CABusChassisExp.h"
#include "Rte_GmMsg1E5BusChassisExp.h"
#include "Rte_GmMsg1E5BusHiSpd.h"
#include "Rte_GmMsg1E9BusHiSpd.h"
#include "Rte_GmMsg1F1BusHiSpd.h"
#include "Rte_GmMsg1F5BusHiSpd.h"
#include "Rte_GmMsg214BusHiSpd.h"
#include "Rte_GmMsg232BusHiSpd.h"
#include "Rte_GmMsg335BusChassisExp.h"
#include "Rte_GmMsg337BusChassisExp.h"
#include "Rte_GmMsg348BusChassisExp.h"
#include "Rte_GmMsg348BusHiSpd.h"
#include "Rte_GmMsg34ABusChassisExp.h"
#include "Rte_GmMsg34ABusHiSpd.h"
#include "Rte_GmMsg3F1BusHiSpd.h"
#include "Rte_GmMsg4D1BusHiSpd.h"
#include "Rte_GmMsg500BusHiSpd.h"
#include "Rte_GmMsg778BusHiSpd.h"
#include "Rte_GmOvrlStMgr.h"
#include "Rte_GmRoadWhlInQlfr.h"
#include "Rte_GmStrtStop.h"
#include "Rte_GmTqArbn.h"
#include "Rte_GmVehPwrMod.h"
#include "Rte_GmVehSpdArbn.h"
#include "Rte_HiLoadStallLimr.h"
#include "Rte_HowDetn.h"
#include "Rte_HwAg0Meas.h"
#include "Rte_HwAg1Meas.h"
#include "Rte_HwAgArbn.h"
#include "Rte_HwAgCorrln.h"
#include "Rte_HwAgSnsrls.h"
#include "Rte_HwAgSysArbn.h"
#include "Rte_HwAgTrajGenn.h"
#include "Rte_HwAgTrakgServo.h"
#include "Rte_HwAgVehCentrTrim.h"
#include "Rte_HwTqArbn.h"
#include "Rte_HwTqCorrln.h"
#include "Rte_HysCmp.h"
#include "Rte_ImcArbn.h"
#include "Rte_InertiaCmpVel.h"
#include "Rte_IoHwAb.h"
#include "Rte_LimrCdng.h"
#include "Rte_LoaMgr.h"
#include "Rte_MotAgCorrln.h"
#include "Rte_MotCtrlPrmEstimn.h"
#include "Rte_MotCurrPeakEstimn.h"
#include "Rte_MotCurrRegCfg.h"
#include "Rte_MotDrvDiagc.h"
#include "Rte_MotQuadDetn.h"
#include "Rte_MotRefMdl.h"
#include "Rte_MotRplCoggCfg.h"
#include "Rte_MotTqCmdSca.h"
#include "Rte_MotTqTranlDampg.h"
#include "Rte_MotVelCtrl.h"
#include "Rte_NvM.h"
#include "Rte_NvMProxy.h"
#include "Rte_NxtrCalIds.h"
#include "Rte_NxtrSwIds.h"
#include "Rte_PartNr.h"
#include "Rte_PolarityCfg.h"
#include "Rte_ProgMfgSrv.h"
#include "Rte_PullCmpActv.h"
#include "Rte_PwrDiscnct.h"
#include "Rte_PwrLimr.h"
#include "Rte_PwrSply.h"
#include "Rte_PwrUpSeq.h"
#include "Rte_PwrpkCmpbltyChk.h"
#include "Rte_Rtn.h"
#include "Rte_RtnPahFwl.h"
#include "Rte_SerlComInpProxy.h"
#include "Rte_SerlComOutpProxy.h"
#include "Rte_SnsrOffsCorrn.h"
#include "Rte_SnsrOffsLrng.h"
#include "Rte_StHlthSigNormn.h"
#include "Rte_StHlthSigStc.h"
#include "Rte_StOutpCtrl.h"
#include "Rte_StabyCmp.h"
#include "Rte_Swp.h"
#include "Rte_SysFricLrng.h"
#include "Rte_SysStMod.h"
#include "Rte_TEstimn.h"
#include "Rte_TmplMonr.h"
#include "Rte_TqLoa.h"
#include "Rte_TqOscn.h"
#include "Rte_TunSelnAuthy.h"
#include "Rte_TunSelnMngt.h"
#include "Rte_VehSigCdng.h"
#include "Rte_VehSpdLimr.h"
#include "Rte_WdgM.h"
#include "Rte_WhlImbRejctn.h"
#include "SchM_BswM.h"
#include "SchM_ChkPt.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_Fls.h"
#include "SchM_IoHwAb.h"
#include "SchM_Mcu.h"
#include "SchM_NvM.h"
#include "SchM_NvMProxy.h"
#include "SchM_Port.h"
#include "SchM_Spi.h"
#include "SchM_WdgM.h"
#include "SchM_Wdg_59_DriverA.h"

#include "Rte_Hook.h"

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (STATIC)
# define STATIC static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelUM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelUM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Assi_AssiCmdBas_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Assi_HwTqHysOvrl_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiHiFrq_AssiHiFrqCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiPahFwl_AssiCmdSum_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiPahFwl_AssiPahLimrActv_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_MotTqCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_AssiSumLim_MotTqCmdLimDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_MotTqCmdLimdPreStall_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_MotTqCmdLimrMin_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_MotTqCmdPreLim_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_PinionCentrLrnCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_AssiSumLim_PinionCentrLrnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_SysProtnRednFac_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_AssiSumLim_TqSteerMtgtnCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_BattVltg_BrdgVltg_Val = 6.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_BattVltgCorrln_BattSwdVltgCorrlnSts_Val = 7U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_BattVltgCorrln_BattVltgCorrlnIdptSig_Val = 3U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_BattVltgCorrln_DftBrdgVltgActv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_BattVltgCorrln_InhbBattVltgDiagc_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_BattVltgCorrln_SwdVltgLimd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc0Faild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_AdcDiagc_Adc1Faild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val = 23U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val = 21U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_CurrMeas_CurrMeasWrmIninTestCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotCurrEolCalSt2, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrEolCalSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrQlfr1_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_CurrMeas_MotCurrQlfr2_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_FlsMem_CodFlsCrcChkCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag2_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag4_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltg_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1AdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2AdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_EcuT_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_EcuTAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2Cos_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2CosAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2Sin_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotAg2SinAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakAAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakBAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakCAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakDAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakEAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakFAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyAAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyBAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyCAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyDAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyEAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyFAdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs1AdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs2AdcFaild_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq0Meas_HwTq0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq0Meas_HwTq0Qlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq0Meas_HwTq0RollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq0Meas_RackLimrCcwEotSig0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq0Meas_RackLimrCwEotSig0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_HwTq0Meas_RackLimrEotSig0Avl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq1Meas_HwTq1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq1Meas_HwTq1Qlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq1Meas_HwTq1RollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq1Meas_RackLimrCcwEotSig1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq1Meas_RackLimrCwEotSig1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_HwTq1Meas_RackLimrEotSig1Avl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq2Meas_GearIdn1_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_HwTq2Meas_GearIdn1Vld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq2Meas_HwTq2_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq2Meas_HwTq2Qlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq2Meas_HwTq2RollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq3Meas_GearIdn2_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_HwTq3Meas_GearIdn2Vld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_HwTq3Meas_HwTq3_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_HwTq3Meas_HwTq3Qlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_HwTq3Meas_HwTq3RollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_CDD_McuDiagc_LoopCntr2MilliSec_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0MeclRollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint32, RTE_VAR_INIT) Rte_CDD_MotAg0Meas_MotAg0Offs_Val = 0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1MeclRollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint32, RTE_VAR_INIT) Rte_CDD_MotAg1Meas_MotAg1Offs_Val = 0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s18p13, RTE_VAR_INIT) Rte_CDD_MotAgCmp_MotAgCumvAlgndCrf_Val = 0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s18p13, RTE_VAR_INIT) Rte_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val = 0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag2_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Adc0SelfDiag4_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_FastLoopCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg0Mecl_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAg1Mecl_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u0p16_8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgBuf_Ary1D = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgBufIdx_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s15p16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgCumvAlgndMrfRev_Val = 0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u32_8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D = {
  0U, 62U, 125U, 187U, 250U, 312U, 375U, 437U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyA_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyB_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyC_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyD_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyE_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrAdcVlyF_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdA_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdB_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdC_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdD_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdE_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrCorrdF_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrDax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrQax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrRollgCntr1_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotCurrRollgCntr2_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotREstimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotVltgDaxFild_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_MotVltgQaxFild_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Ntc5DErrCnt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_Ntc6DErrCnt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_PhaOnTiSumA_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_PhaOnTiSumB_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_PhaOnTiSumC_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_CDD_MotCtrlMgr_SlowLoopCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_HwVel_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelCrf_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CDD_MotVel_MotVelMrf_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CDD_RamMem_LclRamEccSngBitCntrOutp_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj1CfgAndUse_PhaOnTiMeasdD_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj1CfgAndUse_PhaOnTiMeasdE_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_CDD_Tauj1CfgAndUse_PhaOnTiMeasdF_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CmplncErr_CmplncErrMotToPinion_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CmplncErr_CmplncErrPinionToHw_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CurrMeasCorrln_CurrMeasCorrlnSts_Val = 63U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CurrMeasCorrln_CurrMeasIdptSig_Val = 2U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CurrMeasCorrln_CurrMotSumABC_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_CurrMeasCorrln_CurrMotSumDEF_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_CurrReasbnDiagc_MotAgElec_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Dampg_DampgCmdBas_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Dampg_DampgCmdOvrl_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DampgPahFwl_DampgCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_DiagcMgr_ClrDiagcFlgProxy_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsCtrldShtDwnFltPrsnt_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsDftHwAg_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsDftHwAgSerlComExprtVal_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsDftVehSpd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsIvtr1Inactv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsIvtr2Inactv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsLimdTPrfmnc_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_DiagcStsWhlImbRejctnDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_DiagcMgr_RegInBRAMDAT1_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DiagcMgr_SysDiMotTqCmdSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DiagcMgr_SysDiRampRate_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DiagcMgr_SysStFltOutpReqDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DutyCycThermProtn_DualEcuFltMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_DutyCycThermProtn_DutyCycThermProtnMaxOutp_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_DutyCycThermProtn_IgnTiOff_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermDutyCycProtnLoadDptLim_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermDutyCycProtnTDptLim_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermLimSlowFilMax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermMotTqLim_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_DutyCycThermProtn_ThermRednFac_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_DutyCycThermProtn_VehTiVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EcuTMeas_EcuTFild_Val = 25.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_ElecInpPwrEstim_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_MotCtrlMotVltgDax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_MotCtrlMotVltgQax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_ElecPwrCns_SplyCurrEstim_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_EotLrng_HwAgCcwDetd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_EotLrng_HwAgCwDetd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_EotLrng_HwAgDiDiagSts_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotLrng_HwAgEotCcw_Val = -360.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotLrng_HwAgEotCw_Val = 360.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotProtn_EotActvCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotProtn_EotAssiSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotProtn_EotDampgCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotProtn_EotMotTqLim_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotProtnFwl_EotActvCmdLimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_EotProtnFwl_EotDampgCmdLimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GateDrv0Ctrl_MotDrvr0IninTestCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_ApaEnaArbn_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_EscEnaArbn_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(GmFctDiArbnSts1, RTE_VAR_INIT) Rte_GmFctDiArbn_GmFctDiSts_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_InertiaCmpDecelGainDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_LkaEnaArbn_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_PullCmpActvDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_TunSetRtDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmFctDiArbn_WhlImbRejctnDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmOvrlStMgr_ApaDrvrIntvDetd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_GmOvrlStMgr_ApaSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_GmOvrlStMgr_EscSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwAgServoCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwAgServoEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwAgTrajEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwOscnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwOscnFrq_Val = 50.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwOscnMotAmp_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_GmOvrlStMgr_HwTqOscSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_GmOvrlStMgr_LkaSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmRoadWhlInQlfr_WhlFrqVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmRoadWhlInQlfr_WhlLeFrq_Val = 0.01F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmRoadWhlInQlfr_WhlRiFrq_Val = 0.01F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmStrtStop_VehStrtStopMotTqCmdSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmStrtStop_VehStrtStopRampRate_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_GmStrtStop_VehStrtStopSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_AssiCmdBasSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_DampgCmdSca_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_EscCmdArbd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmTqArbn_EscLimdActv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_HwTqOvrl_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_LkaTqCmdCdnd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_MotTqCmdOvrl_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmTqArbn_RtnCmdSca_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehPwrMod_PwrSplyEnaReq_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmVehPwrMod_SysOperMotTqCmdSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmVehPwrMod_SysOperRampRate_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehPwrMod_SysStReqEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehPwrMod_VehPwrModDftVehSpdEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdArbd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdArbdVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdMaxSecur_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdMaxSecurVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdMinSecur_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdMinSecurVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_GmVehSpdArbn_VehSpdSnsrVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HiLoadStallLimr_StallMotTqLim_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HowDetn_HowDetnEstimn_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_HowDetn_HowDetnSt_Val = 0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAg0Meas_HwAg0_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_HwAg0Meas_HwAg0Qlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_HwAg0Meas_HwAg0RollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAg1Meas_HwAg1_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_INIT) Rte_HwAg1Meas_HwAg1Qlfr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_HwAg1Meas_HwAg1RollgCntr_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgArbn_HwAg_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_HwAgCorrln_HwAgCorrlnSt_Val = 1U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_HwAgCorrln_HwAgIdptSig_Val = 2U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSnsrls_HwAgSnsrls_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSnsrls_HwAgSnsrlsConf_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_HwAgSnsrls_MotAgCumvAlgndVld_Logl = TRUE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSysArbn_HwAgFinal_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSysArbn_HwAgNotCorrd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_HwAgSysArbn_HwAgStsToSerlCom_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSysArbn_HwAgToSerlCom_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSysArbn_PinionAg_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgSysArbn_PinionAgConf_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_HwAgTrajGenn_HwAgTrajGennEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgTrajGenn_HwAgTrakgServoCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgTrakgServo_MotTqServoCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_HwAgVehCentrTrim_HwAgTrimPrfmd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwAgVehCentrTrim_HwAgVehTrimOffs_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTq_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTqChA_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwTqArbn_HwTqChB_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwTqCorrln_HwTqChACorrlnTraErr_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HwTqCorrln_HwTqChBCorrlnTraErr_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_HwTqCorrln_HwTqCorrlnSts_Val = 15U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_HwTqCorrln_HwTqIdptSig_Val = 4U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_HysCmp_HysCmpCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_InertiaCmpVel_InertiaCmpVelCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_EotAssiScaCdnd_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_EotMotTqLimCdnd_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_StallMotTqLimCdnd_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_SysMotTqCmdScaCdnd_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_ThermMotTqLimCdnd_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LimrCdng_VehSpdMotTqLimCdnd_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_LoaMgr_CurrMeasLoaMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_LoaMgr_HwTqLoaMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_LoaMgr_IvtrLoaMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LoaMgr_LoaRateLim_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_LoaMgr_LoaSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(LoaSt1, RTE_VAR_INIT) Rte_LoaMgr_LoaSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_LoaMgr_MotAgLoaMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_MotAgCorrln_MotAgMeclCorrlnSt_Val = 7U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_MotAgCorrln_MotAgMeclIdptSig_Val = 3U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_DualEcuFltMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotBackEmfConEstimd_Val = 0.025F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduDaxEstimd_Val = 0.00011889F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduDaxEstimdIvs_Val = 8412.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduQaxEstimd_Val = 0.00011889F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotInduQaxEstimdIvs_Val = 8412.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCtrlPrmEstimn_MotREstimd_Val = 0.0139083F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_MotCurrPeakEstimn_DualEcuMotCtrlMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrPeakEstimn_MotCurrPeakEstimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrPeakEstimn_MotCurrPeakEstimdFild_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_MotCurrRegCfg_DualEcuMotCtrlMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotAgElecDly_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotDampgDax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotDampgQax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotIntglGainDax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotIntglGainQax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotPropGainDax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotCurrRegCfg_MotPropGainQax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotDrvDiagc_MotDrvErrA_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotDrvDiagc_MotDrvErrB_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotDrvDiagc_MotDrvErrC_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotDrvDiagc_MotDrvErrD_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotDrvDiagc_MotDrvErrE_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotDrvDiagc_MotDrvErrF_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_MotQuadDetn_MotDirInsts_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotQuad1, RTE_VAR_INIT) Rte_MotQuadDetn_MotQuad_Val = 1U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_MotRefMdl_DualEcuMotCtrlMtgtnEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotBackEmfVltg_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrAg_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrDaxCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrDaxMax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotCurrQaxCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotReacncDax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotReacncQax_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgDaxFf_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgDaxFfStat_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgQaxFf_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRefMdl_MotVltgQaxFfStat_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotAgElecDlyRpl_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotCurrQaxToMotTqGain_Val = 0.021651F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotTqRplCoggOrder1Mgn_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotTqRplCoggOrder1Pha_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotTqRplCoggOrder2Mgn_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotTqRplCoggOrder2Pha_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotTqRplCoggOrder3Mgn_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotRplCoggCfg_MotTqRplCoggOrder3Pha_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotTqCmdSca_MotTqCmdMrfScad_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotTqTranlDampg_MotTqCmdCrfDampd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_MotTqTranlDampg_MotTqCmdMrfDampd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_MotTqTranlDampg_MotTqTranlDampgCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_AssiMechPolarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg0Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg1Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg2Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg3Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg4Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg5Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg6Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwAg7Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq0Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq1Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq2Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq3Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq4Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq5Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq6Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_HwTq7Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl0Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl1Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl2Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl3Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl4Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl5Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl6Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl7Polarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotElecMeclPolarity_Val = 1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_PullCmpActv_PullCmpCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_PwrDiscnct_PwrDiscnctATestCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_PwrDiscnct_PwrDiscnctBTestCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_PwrLimr_AltFltActv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_DualEcuFltMtgtnSca_Val = 0.5F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_MotTqCmdPwrLimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_PwrLimr_PwrLimrRednFac_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_PwrUpSeq_MotDrvr1IninTestCmpl_Logl = TRUE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_PwrUpSeq_StrtUpSt_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_PwrUpSeq_SysStWrmIninCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Rtn_HwAgRtnOffs_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Rtn_RtnCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Rtn_RtnCmdDiagcDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Rtn_RtnCmdScaServo_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_RtnPahFwl_RtnCmdLimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SnsrOffsCorrn_HwAgCorrd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SnsrOffsCorrn_HwTqCorrd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SnsrOffsCorrn_VehYawRateCorrd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SnsrOffsLrng_HwAgOffs_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SnsrOffsLrng_HwTqOffs_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SnsrOffsLrng_VehYawRateOffs_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_AbsltMotPosABDifStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_AbsltMotPosACDifStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_AbsltMotPosBCDifStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_CtrlrTRng_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_CtrlrTStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_CurrMotSumABCStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_CurrMotSumDEFStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_DigTqIdptSigStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_DigTqSnsrAStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_DigTqSnsrBStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_DutyCycStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_EotImpctStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_FricEstimnStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_StHlthSigNormn_MotAg2VltgSqd_Val = 1.755625F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_StHlthSigNormn_MotAgABErrTerm_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_StHlthSigNormn_MotAgACErrTerm_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_StHlthSigNormn_MotAgBCErrTerm_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_MotPosStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_OutpAssiStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_PhaAStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_PhaBStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_PhaCStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_PhaDStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_PhaEStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_PhaFStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_RamEccSngBitCorrnStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_VltgRng_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_StHlthSigNormn_WhlImbMaxCmpStHlth_Val = 100U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_StOutpCtrl_SysMotTqCmdSca_Val = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_StOutpCtrl_SysStReqDi_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_StabyCmp_AssiCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Swp_HwTqSwp_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Swp_MotTqCmdSwp_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_SysFricLrng_FricLrngCustEna_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SysFricLrng_MaxLrndFric_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SysFricLrng_SysFricEstimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SysFricLrng_SysFricOffs_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_SysFricLrng_SysSatnFricEstimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SysSt1, RTE_VAR_INIT) Rte_SysStMod_SysSt_Val = 3U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_SysStMod_SysStImdtTranReqOff_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_TEstimn_AmbTVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TEstimn_AssiMechT_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_TEstimn_EngOilTVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TEstimn_MotFetT_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TEstimn_MotMagT_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TEstimn_MotWidgT_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_TmplMonr_TmplMonrIninTestCmpl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_TqLoa_TqLoaAvl_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TqLoa_TqLoaCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnActv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TqOscn_HwOscnCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_TqOscn_HwOscnDcThdExcdd_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TqOscn_HwOscnFallRampRate_Val = -4400.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_TqOscn_HwOscnRisngRampRate_Val = 4400.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_TunSelnMngt_ActvGroup_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_TunSelnMngt_ActvIninIdx_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_TunSelnMngt_ActvRtIdx_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(CalCopySts1, RTE_VAR_INIT) Rte_TunSelnMngt_CalCopySts_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_TunSelnMngt_DesIninIdx_Val = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_VehSigCdng_VehLatA_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_VehSigCdng_VehLatAEstimd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_VehSigCdng_VehLatAEstimdVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_VehSigCdng_VehLatAVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_VehSigCdng_VehLgtA_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_VehSigCdng_VehLgtAVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_VehSigCdng_VehLgtAVldSerlCom_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_VehSigCdng_VehSpd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_VehSigCdng_VehSpdVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_VehSigCdng_VehYawRate_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_VehSigCdng_VehYawRateVld_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_VehSpdLimr_VehSpdMotTqLim_Val = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_WhlImbRejctn_WhlImbRejctnActv_Logl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_WhlImbRejctn_WhlImbRejctnAmp_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_WhlImbRejctn_WhlImbRejctnCmd_Val = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_WhlImbRejctn_WhlImbRejctnCustEna_Logl = TRUE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Assi_dAssiThermAssiSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Assi_dAssiWhlImbRejctnBlnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiHiFrq_dAssiHiFrqGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiHiFrq_dAssiHiFrqGainBlnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiHiFrq_dAssiHiFrqGainWhlImbRejtcnZero; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_CombdAssiPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlActvRaw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlBasAssiLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlBasAssiLowrLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlBasAssiUpprLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlHiFrqAssiLowrLimFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlHiFrqAssiUpprLimFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlHiFrqCmdHpPah; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlHiFrqCmdLpPah; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlHiFrqLpLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlSumInp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_BrdgVltgSumPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_EolOffsHiBrdgVltg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolGainA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolGainB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolGainC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolGainD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolGainE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolGainF; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsDeltaA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsDeltaB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsDeltaC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsDeltaD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsDeltaE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsDeltaF; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsHiAvrgA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsHiAvrgB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsHiAvrgC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsHiAvrgD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsHiAvrgE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsHiAvrgF; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsLoAvrgA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsLoAvrgB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsLoAvrgC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsLoAvrgD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsLoAvrgE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsLoAvrgF; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsZeroAvrgA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsZeroAvrgB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsZeroAvrgC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsZeroAvrgD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsZeroAvrgE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrOffsZeroAvrgF; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrSumAPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrSumBPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrSumCPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrSumDPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrSumEPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrSumFPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_TempMotCurrAdcVlySum1Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_TempMotCurrAdcVlySum2Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_HwTq0MeasPrevHwTq0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrCcwEot0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrCwEot0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_HwTq1MeasPrevHwTq1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrCcwEot1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrCwEot1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_HwTq2MeasPrevHwTq2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_HwTq3MeasPrevHwTq3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0TurnCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1TurnCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_AntiWdupCmdScaDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_AntiWdupCmdScaQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_CurrLoaScarPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_DualEcuLoaScarPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_IvtrLoaScarPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_MotCtrlMotVltgDaxPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_MotCtrlMotVltgQaxPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_MotVltgIntglCmdDaxPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_MotVltgIntglCmdQaxPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrAntiWdupCmdScaDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrAntiWdupCmdScaQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotCurrCmdErr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotCurrCmdErrDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotCurrCmdErrQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotCurrCmdScaDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotCurrCmdScaQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgBrdgFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgCmdFinal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgCmdPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDampgDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDampgQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDaxFb; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDaxIntglPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDecouplFbDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDecouplFbQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDircFbDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgDircFbQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgPreLimDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgPreLimQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgPropCmdDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgPropCmdQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgQaxFb; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgQaxFfFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgQaxIntglPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgSatnIvsRat; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrMotVltgSatnRat; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_dMotCurrRegVltgLimrPhaAdvPreDly; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotRplCoggCmd_dMotRplCoggCmdMotCoggCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotRplCoggCmd_dMotRplCoggCmdMotCurrQaxCoggCmdPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotRplCoggCmd_dMotRplCoggCmdMotRplCmdPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_dMotVelAvrgTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_dMotVelTiStampRef; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_Fil1OutpPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_Fil2OutpPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PhaDptOffsA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PhaDptOffsB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PhaDptOffsC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_RndNrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildInp1Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildInp2Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildOutp1Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDiagFildOutp2Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgAFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgBFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDaxDif; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagFildLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgDiagSecdryFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcMotVltgQaxDif; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_dCurrReasbnDiagcVelLpFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_PrevHwTqBacklshOutp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_PrevHydOutpLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_PrevMotVelBacklshOutp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgAssiMechTSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgCoeff1Term; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgCoeff2Term; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgCoeff3Term; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgCoeff4Term; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgHwTqSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgMotVelDampgCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgQuadHwTqBacklsh; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_dDampgQuadMotVelBacklsh; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlActvRaw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlAddDampg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlDampgCmdLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlDampgCmdLowrLimFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlDampgCmdUpprLimFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlInertiaCmpHpPah; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlInertiaCmpLowrLimFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlInertiaCmpLpLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlInertiaCmpLpPah; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlInertiaCmpUpprLimFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_AbsltTLimSlewStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_LstTblValRateLimrStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_ReInitCntrVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnAbsltCtrlrTTqLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnAbsltCuTTqLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnAbsltTTqLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr12T; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr36T; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnThermLoadLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnThermLoadLimTblYVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsDrpInpPwr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsModInpPwr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsMotCurrDaxEstim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_ElecPwrCns_dElecPwrCnsMotCurrQaxEstim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_PrevCcwEot; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_PrevCwEot; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_PrevEotAssiSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_PrevEotDampg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_PrevImpctPosn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnDampg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnEntrGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnEotAssiSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnEotGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnExitGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnLimPosn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotActvCmdActvLowrBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotActvCmdActvUpprBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotDampgActvLowrBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotDampgActvUpprBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotDampgFwX0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevLeWhlFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevRawLeWhlFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevRawRiWhlFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevRiWhlFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrRawLeWhlFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrRawRiWhlFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_ActPosnServoCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_DesLkaTqCmdRateLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_PosnServoSmotngEnaRateLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_dGmTqArbnDesLkaTqCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_dGmTqArbnEscTqCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_dGmTqArbnLkaTqCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_dGmTqArbnPosnServoSmotngLowrLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HiLoadStallLimr_StallMotTqLimPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HiLoadStallLimr_dHiLoadStallLimrStallMotTqCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HiLoadStallLimr_dHiLoadStallLimrStallMotTqCmdFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HiLoadStallLimr_dHiLoadStallLimrStallMotTqLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_PrevCalcdHowEstim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_PrevHowEstim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_dHowDetnAbsHiFrqTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_dHowDetnAbsLoFrqTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0PrevHwAg0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_PrevHwAg0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr0Abs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr0Rel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr1Abs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr1Rel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1PrevHwAg1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_PrevHwAg1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr0Abs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr0Rel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr1Abs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr1Rel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgArbn_HwAgPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_CorrdPinionAgHwAgOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_CorrdPinionAgHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_FCentrHwAgOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_FCentrHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_MotAgOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevFildRelHwAg1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevHwAgOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevMaxHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevSmotngHwAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_VehDynHwAgOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_WhlSpdHwAgOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_WhlSpdHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_dHwAgSnsrlsStordHwAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_dHwAgSnsrlsStordHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_dHwAgSnsrlsVehDynHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_dHwAgSnsrlsWhlSpdHwConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_PrevHwAgNotCorrd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_PrevPinionAgConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_PrevSeldHwAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_SeldHwAgConf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_AMax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_HwPosnIni; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_HwPosnOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_SignHwPosnDelta; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_TiDeltaA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_TiDeltaVel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_TiSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_VelMax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_HwAgTarRateLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_PrevDftlErr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_PrevHwAgTar; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_PrevIntglErr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_PrevSmotng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoDftlTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoHwAgTarFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoIntglTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoPidCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoPropTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoRtnScaFac; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoSmotngEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChACmnModCmpLpFilSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChBCmnModCmpLpFilSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_PrevAssiCmdFildVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_PrevHwTqFildVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_PrevRiseX; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_PrevRiseY; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpAssiCmdFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpEffCmpTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpHwTqFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpNegAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpPosAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpRawVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_dHysCmpRiseYFac; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_DecelGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_PreScagCmpCmdPrev1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_PreScagCmpCmdPrev2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_ScaDrvrVelPrev1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_ScaDrvrVelPrev2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_TqSnsrAgPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelAssiBasdDampgCoeff; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelCalcdInertiaCmp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelFilFrq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelMotVelBasdOutpScag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelNotScadDrvrVel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelNotchBlndVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelNotchInpVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelNotchOutpVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelRawDecelGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelScadDrvrVel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_dInertiaCmpVelTqSnsrVelFildVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LimrCdng_PrevEotAssiScaCdnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LimrCdng_PrevEotMotTqLimCdnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LimrCdng_PrevStallMotTqLimCdnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LimrCdng_PrevSysMotTqCmdScaCdnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LimrCdng_PrevThermMotTqLimCdnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LimrCdng_PrevVehSpdMotTqLimCdnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnCtrlrREstimdPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnFetRFfEstimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotBackEmfConEstimdPreLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotBackEmfConEstimdSatnSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotInduEstimdPreLimDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotInduEstimdPreLimQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotInduEstimdSatnScaDax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotInduEstimdSatnScaQax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_dMotCtrlPrmEstimnMotRFfEstimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrPeakEstimn_dMotCurrPeakEstimnMotCurrDaxFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrPeakEstimn_dMotCurrPeakEstimnMotCurrQaxFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrRegCfg_dMotCurrRegCfgMotVelMrfFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_MotCurrDaxCmdPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_MotCurrQaxCmdPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_VltgDaxFfTermPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_VltgQaxFfTermPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlCurrDaxAtPeakTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlCurrDaxMin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlCurrQaxMin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlCurrSqdMin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlInterCalcnCurrDaxMax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotCurrDaxBoost; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotTqCmdLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVelFildFf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVltgDaxFfDyn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVltgDaxFfDynTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVltgDaxFfStat; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVltgQaxFfDyn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVltgQaxFfDynTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMotVltgQaxFfStat; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlPeakTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlPhaAdvAtPeakTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlReacncDaxOverR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlReacncQaxOverR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlRelncTqCoeff; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotAgElecDlyRpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotCurrQaxToMotTqGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotTqRplOrder1Mgn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotTqRplOrder1Pha; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotTqRplOrder2Mgn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotTqRplOrder2Pha; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotTqRplOrder3Mgn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_dMotRplCoggCfgMotTqRplOrder3Pha; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqCmdSca_MotTqScaFac; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_dMotTqTranlDampgCmdCtrld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_dMotTqTranlDampgSignPhaSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_dMotTqTranlDampgTiElpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_dMotTqTranlDampgVelDampgCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_MotVelTar; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_PrevAntiWdupCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_PrevDerivtvOutp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_PrevIntgtrInp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_PrevIntgtrOutp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_PrevMotVelErr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_PrevMotVelTar; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_VelSlewRate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_CmpLrnTiDecShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_CmpLrnTiIncShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_CmpLrnTiLongTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_IntgtrGainDecShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_IntgtrGainIncShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpCmdRateLimPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpCmdTot; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpLongTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_VehSpdPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_VehSpdRate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvIntgtrGainShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvPullErrLongTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvPullErrShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrDiscnct_PwrDiscnctDeltaVltg1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrDiscnct_PwrDiscnctDeltaVltg2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_BrdgVltgAdjSlewStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_PrevBrdgVltgAltFltAdjLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_PrevSpdAdj; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_SpdAdjSlewStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrFildMotVel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrLimDif; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrMinStdOperLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrMotEnvlpSpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrMotTqCmdIvtrLoaSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrOutpVelOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrSpdAdj; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrTLimMaxCurr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrTqEnvlpLim1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrTqEnvlpLim4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrTqLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrTqLim1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_dPwrLimrTqLim4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_PrevHwAgAuthy; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_PrevHwAgOffsLimd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnAbsltHwAgOffsCalcd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnAssiMechTRtnSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnBascRtn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnHwAgAuthySca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnHwAgRtnCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnHwTqRtnSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Rtn_dRtnHwVelRtnSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_RtnPahFwl_dRtnPahFwlLowrBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_RtnPahFwl_dRtnPahFwlUpprBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgLrngDrvgDstPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnEnaTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnHwTqPreProc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnSinGenrAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg1FilSt1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg1FilSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg2CenFilSt1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg2CenFilSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg2DwnFilSt1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg2DwnFilSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg2UpFilSt1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg2UpFilSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawLrngElpdLrngTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawRatePrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngSysTqLoThd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngSysTqUpThd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngHwAgMeas; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngHwTqMeas; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngHwTqOffsRaw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngSampleCntTot; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngSampleImb; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwVelFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngSysTqFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngTqInpDetnHwTqFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngTqInpDetnStg1Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngYawA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngYawLrngBiasEstimnRaw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngYawRateFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngYawRateFildCorrd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StOutpCtrl_StOutpCtrlPrevCmdSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StOutpCtrl_dStOutpCtrlRateLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StOutpCtrl_dStOutpCtrlTarSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpAssiScaCmpBlnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil02Blnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil04Blnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil12Blnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil12Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil1Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil2Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil34Blnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil34Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil3Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_dStabyCmpNotchFil4Outp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_EstimdFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_PrevFricOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_PrevMaxRawAvrgFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_SatnEstimdFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_AssiMechTEstimnPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_AssiMechTSlewLimPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_CuTEstimnPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_MagTEstimnPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_SiTEstimnPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnAmbPwr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnAssiMechCorrn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnAssiMechDampgSca; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnAssiMechFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnAssiMechLLFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnCuCorrn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnCuLLFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnMagCorrn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnMagLLFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnScadAmbT; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnScadEngT; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnSiCorrn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnSiLLFilv; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_dTEstimnWghtAvrgT; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_MotTqCmdPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_MotVelAndTqBasdScaFacPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_VehLatADifScaFacPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_dTqLoaMotTqCmdPreScag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_dTqLoaMotVelAndTqBasdScaFac; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_dTqLoaScaFacFinal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_dTqLoaVehLatADifScaFac; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_dTqLoaVehLatAEstimn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_dTqLoaVehSpdBasdScaFac; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_AmpRampSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevFallRampRate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevLimdAmp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevPhaAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevPhaAgInc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevRisngRampRate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnPreFinalCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnRateLimdAmp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnSinCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevLatA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevLtgA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevVehSpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevYawRate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSpdLimr_dVehSpdLimrBreakPt1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSpdLimr_dVehSpdLimrBreakPt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_EnaSlewPerLoop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcUgr1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcUgr2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_LeCurrMgnSlewPerLoop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_LePeakPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_MaxCompPerc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PhaAdjFil1Coeff1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PhaAdjFil1Coeff2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PhaAdjFil2Coeff1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PhaAdjFil2Coeff2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PrevFlt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PrevHwTq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_RiCurrMgnSlewPerLoop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_RiPeakPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_ScaLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_ScaRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_UgrLe1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_UgrLe2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_UgrRi1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_UgrRi2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnCnclTqOutp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnCurrMgnLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnCurrMgnRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnFildWhlSpdLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnFildWhlSpdRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnLMSqdOutLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnLMSqdOutRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnScaLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnScaRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_dWhlImbRejctnWhlSpdCorrPerc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_DmaCfgAndUse2MilliSecAdcStrtTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_d2MilliSecAdcActDmaTrfTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_DmaCfgAndUse_d2MilliSecAdcMaxDmaTrfTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_FlsMem_CodFlsCrcChkStrtTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_HwTq0MsgMissRxCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_HwTq1MsgMissRxCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_HwTq2MsgMissRxCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_HwTq3MsgMissRxCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuCoreCfgAndDiagc_CoreCompTestRegRead; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawAgReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawErrReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawTurnCntrReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawAgReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawErrReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawTurnCntrReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_ShtdwnClsChk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_LclRamFailrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_LclRamWordLineRead; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemCanRamDblBitEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemCanRamSngBitEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemDtsRamEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemFrRamDblBitEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemFrRamSngBitEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemFrRamTmpBufADblBitEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemFrRamTmpBufBDblBitEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemSpi0RamEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemSpi1RamEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemSpi2RamEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemSpi3RamEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_dRamMemSpiRamEccErrAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PhaOnTiSumAPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PhaOnTiSumBPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PhaOnTiSumCPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SinVltgGenn_PwmPerdRng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SnsrMeasStrt_TqMsgTrigCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseAdcStrtOfCnvnPeak; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseMotAg0SPIStart; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrAPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrBPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj0CfgAndUse_PhaOnTiCntrCPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj1CfgAndUse_PhaOnTiCntrDPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj1CfgAndUse_PhaOnTiCntrEPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Tauj1CfgAndUse_PhaOnTiCntrFPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_VrfyCritReg_dVrfyCritRegCritRegActVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_VrfyCritReg_dVrfyCritRegCritRegAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_VrfyCritReg_dVrfyCritRegCritRegDesVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_VrfyCritReg_dVrfyCritRegSysCritRegActVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_VrfyCritReg_dVrfyCritRegSysCritRegAdr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_VrfyCritReg_dVrfyCritRegSysCritRegDesVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_CcwEotRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_CwEotRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_InCcwEotRngElpdTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_InCwEotRngElpdTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_OnCentrElpdTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_HaptcStTranActvToWaitRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_HapticActvRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_HapticWaitRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LkaFltRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LkaIntvRefTi1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LkaIntvRefTi2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LoaMtgtnHaptcFbStrtOnRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevApaIntvRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevHaptcReqRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevShiftLvrRvsRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevVehStandStillRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_TqOscCycRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_TranHaptcWaitToApaStActvRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevVldTiLeFrqChg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevVldTiRiFrqChg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmStrtStop_Mod1RefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmStrtStop_Mod2RefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehPwrMod_TqRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehSpdArbn_DiagcRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0RawDataAvlStrtTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr0CS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr0FRXD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr1CS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_dHwAg0MeasSnsr1FRXD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1RawDataAvlStrtTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr0CS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr0FRXD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr1CS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_dHwAg1MeasSnsr1FRXD; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_VehDynRefTmr1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_VehDynRefTmr2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_WhlSpdRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_HwAgToMotAgCorrlnDurnRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_SlewElpdRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaOnTiSumAPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaOnTiSumBPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaOnTiSumCPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_TmrRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_RefTiRampDwn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PolarityCfg_PolarityCfgSaved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_RefTiEnaLrng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_RefTiOpstSign; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_FltRefTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrpkCmpbltyChk_GearIdnRefTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqLrngEnaTmrRef; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqLrngMeasTmrRef; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_RefTmrLrngConstr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_RefTmrNtc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_ActvCmpBand1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_ActvCmpBand2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_ActvCmpBand3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendRefTiEnaLrng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendRefTiEnaLrngTmr1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendRefTiEnaLrngTmr2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcRefTiEnaLrng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcRefTiEnaLrngTiOut; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_MaxMgnRefTiEnaLrng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_SlowSpdDiagcRefTiEnaLrngTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdCorrlnDiagcRefTiEnaLrng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdCorrlnRefTiEnaLrngTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RtOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1PrevOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint32, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RtOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s15p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgCmp_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevSVPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s15p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgCmp_MotAgCmpMotCtrlMotAgMeclPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s18p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotQuadDetn_MotAgCumPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(s18p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotQuadDetn_dMotQuadDetnMotAgCumDelta; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_GainEolAvrgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCtrlNtc5DErrCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCtrlNtc6DErrCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_Ntc5DErrCnt2MilliSecPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_Ntc6DErrCnt2MilliSecPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_OffsEolAvrgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_PhaOnTiErrCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_FlsMem_CrcHwIdxKey; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_FastLoopCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_LoopCntr2MilliSecStore; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_LoopCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_dMcuDiagcFastLoopCntrMax; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_dMcuDiagcFastLoopCntrMin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_dMcuDiagcLoopCntr2MilliSecMotCtrlDif; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0Diagc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevSpiErrFltCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0Delta; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0SpiCntrAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0SpiMecl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotCtrlMotAg3Mecl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1Diagc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1PrevSpiErrFltCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1Delta; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1SpiCntrAg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1SpiMecl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotCtrlMotAg4Mecl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgArbn_MotAgMeclPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgCmp_MotAgCmpMotAgBackEmf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotRplCoggCmd_dMotRplCoggCmdCoggIdx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_dMotVelMotAgRef; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgr_DtcEnaSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u9p7, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnLstTblVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u9p7, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnLstTblValSlew; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u3p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u3p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u3p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u3p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u3p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u3p13, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_dDutyCycThermProtnMplr6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0Diag0Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0Diag1Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0Diag2Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0StsVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0VrfyRes0Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0VrfyRes1Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0Diag0Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0Diag1Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0Diag2Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0StsVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0VrfyRes0Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0VrfyRes1Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_GmLoaIgnCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevVldLeWhlDstPlsCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevVldLeWhlDstTiStamp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevVldRiWhlDstPlsCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevVldRiWhlDstTiStamp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrLeDeltaPls; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrLeDeltaTiStamp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrRiDeltaPls; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrRiDeltaTiStamp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_PrevHwAg0Snsr0Raw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_PrevHwAg0Snsr1Raw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_PrevHwAg1Snsr0Raw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_PrevHwAg1Snsr1Raw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwAgTrajCmdSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_CmdSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnErrThd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnPreProcEnaLoop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_MotAgCorrlnErrThd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysStMod_dSysStModTranVect; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u5p11, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSpdLimr_dVehSpdLimrLimTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u5p11, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSpdLimr_dVehSpdLimrZeroVehSpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnBattVltgOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnBattVltgRngOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnBattVltgSwd1Ok; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnBattVltgSwd1RngOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnBattVltgSwd2Ok; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnBattVltgSwd2RngOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnNtc0x03CQlfrSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnNtc0x03DQlfrSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnNtc0x044QlfrSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_BattVltgCorrln_dBattVltgCorrlnNtc0x04CQlfrSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Adc0CfgAndUse_Adc0DiagcEndPtr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Adc0CfgAndUse_Adc0DiagcStrtPtr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Adc1CfgAndUse_Adc1DiagcEndPtr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_Adc1CfgAndUse_Adc1DiagcStrtPtr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0FltCntSt6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0ScanGroup2RefFltCntSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc0ScanGroup3RefFltCntSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1FltCntSt6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1ScanGroup2RefFltCntSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_Adc1ScanGroup3RefFltCntSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_AdcDiagcEndPtr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_AdcDiagcSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_AdcDiagc_AdcDiagcStrtPtr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_EolGainSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_EolOffsSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_EolTranCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotCurrEolCalSt2, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolCalStPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrRollgCnt1Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrRollgCnt2Prev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeasArbn_CurrMeasArbnSens0RollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeasArbn_CurrMeasArbnSens0StallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeasArbn_CurrMeasArbnSens1RollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeasArbn_CurrMeasArbnSens1StallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_HwTq0ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_HwTq0IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_HwTq0MeasPrevRollgCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Data0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Data1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Data2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_HwTq1ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_HwTq1IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_HwTq1MeasPrevRollgCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Data0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Data1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Data2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_GearIdn1Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_HwTq2ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_HwTq2IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_HwTq2MeasPrevRollgCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_GearIdn2Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_HwTq3ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_HwTq3IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_HwTq3MeasPrevRollgCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_McuDiagc_FastLoopCntrDiagcCfgd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0InitOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0PrevRollgCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1InitOffs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1PrevRollgCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgArbn_MotAgARollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgArbn_MotAgAStallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_MotAgBufIdx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_MotAgBufIdxPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_MotVelIninCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_LclRamEccSngBitCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrMeasCorrln_CurrMeasCorrlnSens0RollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrMeasCorrln_CurrMeasCorrlnSens0StallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrMeasCorrln_CurrMeasCorrlnSens1RollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrMeasCorrln_CurrMeasCorrlnSens1StallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgr_ClrDiagcFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgr_PrevClrDtcFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgrProxyAppl10_PrevClrNtcFlg10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fil3ValPwrUp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fil4ValPwrUp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fil5ValPwrUp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fil6ValPwrUp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_NewSoftEndStopSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_PrevSoftEndStopSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotActvCmdMod; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotDampgMod; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0CfgCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0OffStChkIdx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0OffStCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0St; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_Ivtr0BootstrpSplyFltPrmVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_Ivtr0GenericFltPrmVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_dGateDrv0CtrlGateDrv0OffsStVrfyPrmBitIdx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LkaFltCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevApaSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevEscSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevHaptcSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevLkaSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmStrtStop_PrevActSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmStrtStop_PrevStrtStopSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0PrevRollCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0PrevStepSeqNr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr0ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr0IdErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr0IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr0NoMsgErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr1ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr1IdErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr1IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Snsr1NoMsgErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0SnsrTrigNr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_PrevHwAg0Qlfr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_PrevHwAg0Snsr0TestOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_PrevHwAg0Snsr1TestOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1PrevRollCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1PrevStepSeqNr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr0ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr0IdErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr0IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr0NoMsgErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr1ComStsErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr1IdErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr1IntSnsrErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Snsr1NoMsgErrCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1SnsrTrigNr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SigQlfr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_PrevHwAg1Qlfr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_PrevHwAg1Snsr0TestOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_PrevHwAg1Snsr1TestOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgArbn_HwAgARollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgArbn_HwAgAStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgCorrln_HwAgARollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgCorrln_HwAgAStallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_SelnCaseSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqARollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqAStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqBRollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqBStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqCRollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqCStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqDRollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_HwTqArbnTqDStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqARollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqAStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqBRollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqBStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqCRollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqCStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqDRollgCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqDStallCntrPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevCurrMeasIdptSigResp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevCurrMeasIdptSigVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevHwTqIdptSigResp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevHwTqIdptSigVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevIvtrIdptSigResp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevIvtrIdptSigVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevMotAgMeclIdptSigResp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevMotAgMeclIdptSigVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevVltgModSrc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgARollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgAStallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgBRollgCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_MotAgCorrlnMotAgBStallCntPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlMinCurrNrItrn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_dMotRefMdlPeakTqNrItrn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(LoaSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_LoaStPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg1Idx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_AbsltMotPosABDifStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_AbsltMotPosACDifStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_AbsltMotPosBCDifStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_CurrMotSumABCStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_CurrMotSumDEFStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_DigTqIdptSigStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_DigTqSnsrAStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_DigTqSnsrBStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_EcuTRngIgnCyc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_EotImpctCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_MotPosStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_PhaAStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_PhaBStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_PhaCStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_PhaDStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_PhaEStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_PhaFStHlthSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_VltgRngIgnCyc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StOutpCtrl_StOutpCtrlPrevSrc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SysFricLrngOperMod1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricLrngOperModPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SysSt1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysStMod_SysStModPrevSysSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TmplMonr_TmplMonrIninCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TmplMonr_TmplMonrNtc40PrmByte; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TmplMonr_TmplMonrWdgRstrtCnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TunSelnMngt_PrevActvIninIdx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TunSelnMngt_PrevActvRtIdx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TunSelnMngt_PrevRamPageAcs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TunSelnMngt_RamTblSwt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DlyIdxLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DlyIdxRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_PrevSrcSeln; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotQuadDetn_MotDirInstsPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotQuadDetn_MotTqCmdSignPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(sint8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotQuadDetn_dMotQuadDetnTqCmdSign; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_AssiPrfmncPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlBasAssiCmdOverLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_dAssiPahFwlHiFrqCmdOverLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_MotCurrEolOffsProcFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_WrmIninTestCmplPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_FlsMem_CodFlsSngBitErr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_FlsMem_CrcChkCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_FlsMem_PwrOnRstCrcChkCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Avl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Id2DataReadCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Id3DataReadCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_RackLimrEot0Id4DataReadCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Avl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Id2DataReadCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Id3DataReadCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_RackLimrEot1Id4DataReadCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_GearIdn1Avl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_GearIdn2Avl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAgCmp_MotAgCmpFirstRunCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_NvmStsCollctd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_RamMem_LclRamEccSngBitSoftFailr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_TSG31CfgAndUse_TSG31CfgAndUseSysStEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_DampgDecPrfmncPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlDampgCmdOverLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_dDampgPahFwlInertiaCmpOverLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_ReInitCntrFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_HwAgOverTrvlCntrDi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_RstLimReq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_PrevRackTrvlLimrEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_PrevRackTrvlLimrInin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnDetd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_dEotProtnRackTrvlLimrDi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotActvCmdOverActvLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotActvCmdOverInactvLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotDampgOverActvLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlEotDampgOverInactvLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtnFwl_dEotProtnFwlPinionAgConfSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0CfgSecAtmpt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_GateDrv0OffStChkSecAtmpt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GateDrv0Ctrl_Ivtr0OffStChkCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_CcwEotEnad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_CwEotEnad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_FctDiLtch; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_InCcwEotRng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_InCwEotRng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmFctDiArbn_InOnCentrRng; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_IgnCntrUpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LkaFltPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LkaIntvPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_LoaStChk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevApaIntvEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevHaptcReqEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevLkaFlt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevShiftLvrRvsEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_PrevVehStandStillEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_dGmOvrlStMgrApaShiftLvrRvs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_dGmOvrlStMgrApaStandStill; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevLeWhlFrqVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_PrevRiWhlFrqVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrLeWhlFrqVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmRoadWhlInQlfr_dGmRoadWhlInQlfrRiWhlFrqVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehPwrMod_PrevSysStReqEnaVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehPwrMod_TqRefTiActv; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehPwrMod_dGmVehPwrModHwTqKeepAssi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehPwrMod_dGmVehPwrModVehSpdAssiKeepMin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehPwrMod_dGmVehPwrModVehSpdAssiOnMin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehSpdArbn_dGmVehSpdArbnLeDrvnVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehSpdArbn_dGmVehSpdArbnLeNonDrvnVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehSpdArbn_dGmVehSpdArbnRiDrvnVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmVehSpdArbn_dGmVehSpdArbnRiNonDrvnVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0InitStepSeqNrCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1InitStepSeqNrCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgArbn_dHwAgArbnAgAAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgCorrln_dHwAgCorrlnAgAAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_FCentrHwAgEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_MotAgOffsEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevSmotngSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevVehDynFil1Ena; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PrevVehDynFil2Ena; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_WhlSpdHwAgLrndEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_HwAgKineFlt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_HwAgToMotAgCorrln; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSysArbn_SlewSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrajGenn_CalcFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_dHwAgTrakgServoRampCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_dHwTqArbnChAAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqArbn_dHwTqArbnChBAvl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChAImdtCorrlnChk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChBImdtCorrlnChk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_NotchFilChk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevCurrMeasLoaStSwMtgtnEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevHwTqLoaStSwMtgtnEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevIvtrLoaStSwMtgtnEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevMotAgLoaMtgtnEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_LoaMgr_PrevMotAgLoaStSwMtgtnEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotAgCorrln_dMotAgCorrlnMotAgABOk; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_UnitDly; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_DiagStsPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_StLtch; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotTqTranlDampg_dMotTqTranlDampgTmrEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_EnaCtrl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_EnaCtrlStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_FctActvSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotVelCtrl_RampDwnCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_LrngEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_LrngEnad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_OpstSignPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpLongTermRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_PullCmpShoTermRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_dPullCmpActvShoTermRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrDiscnct_PwrDiscnctSeqATestCmplPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_PrevThd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrSply_PwrSplyReadWrOrderFlg1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrSply_PwrSplyReadWrOrderFlg2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrSply_PwrSplyStrtUpSelfTestCmpl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_RtnPahFwl_dRtnPahFwlOverBnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgLrngStRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqLrngStRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqLrngTqInpDetnEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqLrngTqInpPrsnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_VehYawRateLrngStRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_VehYawRateOffsFrsh; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngCdnVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngRst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngSysTqVldt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwAgLrngTiVldt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngEstimnVldt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngMeasEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngTqInpPrsnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngHwTqLrngTqInpPrsntVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngTqInpPrsntRaw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngYawLrngCdnVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_dSnsrOffsLrngYawLrngEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigNormn_EntrEot; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigStc_VldNvm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricLrngRunOneTi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricOffsOutpDi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_AmbTVldPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_AssiMechTInitEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_EngOilTVldPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TmplMonr_TmplMonrIninTestCmplFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TmplMonr_TmplMonrSpiReadWrOrderFlg1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TmplMonr_TmplMonrSpiReadWrOrderFlg2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevActv; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevDcThdExcdd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PrevEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_dTqOscnNonZeroAmpFlg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevLatAVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevLtgAVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevVehSpdVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_PrevYawRateVld; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendLrngEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendLrngEnaPrevTmr1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendLrngEnaPrevTmr2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DistbnMagEnadPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcLrngEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcLrngEnaPrevTiOut; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_MaxMgnLrngEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_PrevSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_RampNo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_RampYes; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_SlowSpdDiagcLrngEnaPrevTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdCorrlnDiagcLrngEnaPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdCorrlnLrngEnaPrevTmr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_26, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0CoeffTbl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_sm5p12_128, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_MotAg0CorrnTbl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u32_10, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg0Meas_dMotAg0MeasMotAg0RawReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_26, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1CoeffTbl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_sm5p12_128, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_MotAg1CorrnTbl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u32_10, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotAg1Meas_dMotAg1MeasMotAg1RawReg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_s1p14_512, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotRplCoggCmd_MotCoggCmdY; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u0p16_8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_MotAgBufPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u32_8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotVel_MotAgTiBufPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_BlkFltTblRec1_5, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_BlkFltTbl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_CmdRtnBufRec1_NvMProxy1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_CmdRtnBuf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_boolean_NvMProxy1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_NvMProxy_NvmBlkActv; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_CrcHwStsRec1_4, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_SyncCrc_CrcHwSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_NtcFltInfoRec2_20, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgr_DiagcMgrNtcFltAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u08_DiagcMgr1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgr_DtcIdxPrevSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_SnpshtDataRec1_8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgr_SnpshtDataAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_NtcInfoRec4_DiagcMgrProxyAppl10, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgrProxyAppl10_DiagcMgrNtcInfo10Ary; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_s16_DiagcMgrProxyAppl10, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgrProxyAppl10_DiagcMgrNtcInfo10DebCntrAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_CosDelta; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_8, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_SinDelta; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary2D_s1p14_10_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotTqRplOrder1X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary2D_s1p14_10_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotTqRplOrder1Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary2D_s1p14_10_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotTqRplOrder2X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary2D_s1p14_10_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotTqRplOrder2Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary2D_s1p14_10_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotTqRplOrder3X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary2D_s1p14_10_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotTqRplOrder3Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_72, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnStg1Buf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u32_StHlthSigStc1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigStc_IgnCycSampleCntrAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u8_StHlthSigStc1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigStc_RamBuf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u8_225, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StHlthSigStc_SigStcHistDataAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_ColTqAry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_4, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FilAvrgFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_HwAgBuf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_12, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_HwVelBuf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_4, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_RawAvrgFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_4, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_SatnAvrgFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_4, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_VehBasLineFric; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_30, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_LeStDlyUpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_30, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_LeStVariUpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_30, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_RiStDlyUpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_30, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_RiStVariUpd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_30, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_StordValLe; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_f32_30, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_StordValRi; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilHpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiHiFrq_HwTqHpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_FwlActvLpFilStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_HiFrqCmdLpFilStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_LowrLimLpFilStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_AssiPahFwl_UpprLimLpFilStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(CurrMeasEolGainCalRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_CurrMeasEolGainCalSet; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(CurrMeasEolOffsCalRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_CurrMeas_CurrMeasEolOffsCalSet; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwTqOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq0Meas_HwTq0Offs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwTqOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq1Meas_HwTq1Offs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwTqOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq2Meas_HwTq2Offs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwTqOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_HwTq3Meas_HwTq3Offs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_MotVltgBrdgLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CDD_MotCurrRegVltgLimr_MotVltgQaxFfLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_CurrReasbnMotVelLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_DiagVltgLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgDaxLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_CurrReasbnDiagc_MotVltgQaxLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_MotVelDampgLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_QuadDampgHwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_QuadDampgMotVelLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_Dampg_QuadDampgScaLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_DampgCmdLpFilLowrLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_DampgCmdLpFilUpprLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_FwlActvLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_InertiaCmpLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_InertiaCmpLpFilLowrLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DampgPahFwl_InertiaCmpLpFilUpprLim; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(DiagcDataRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgrProxyAppl10_DiagcData10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(DiagcDataRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DiagcMgrProxyAppl10_ProxySetNtcData10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fil1ValStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fil2ValStVari; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(DutyCycThermProtnFilStValRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_FilStVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fild3Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fild4Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fild5Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_DutyCycThermProtn_Fild6Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EcuTMeas_EcuTMeasFilStVarPrev; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EotNvmDataRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_EotNvmData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MaxHwAgCwAndCcwRec2, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotLrng_MaxHwAgCwAndCcw; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_EotAssiScaLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_EotProtn_HwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_HwTqLkaLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_HwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmOvrlStMgr_HwTqOscnLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_GmTqArbn_APASmotngHwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HiLoadStallLimr_StallMotTqCmdFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_EstimLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_FinalLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_IniLpFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_IniLpFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_IniLpFil3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_StLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilHpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HowDetn_TqHpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwAgOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg0Meas_HwAg0Offs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwAgOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAg1Meas_HwAg1Offs; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_PinionTqFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_RelHwAgFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_RelHwAgFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(StordLstPrmRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_StordLstPrm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgSnsrls_YawRateFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_DftlTermLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_HwAgLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgTrakgServo_HwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HwAgSnsrTrimRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwAgVehCentrTrim_HwAgTrimData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChACmnModCmpLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChAStabStLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChATraLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChBCmnModCmpLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChBStabStLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HwTqCorrln_HwTqChBTraLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_AssiCmdLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_FinalOutpLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_HysCmp_HwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_TqSnsrVelFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilNotchStRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_InertiaCmpVel_TqSnsrVelFilNotchSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotPrmNomEolRec3, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCtrlPrmEstimn_MotPrmNom; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrPeakEstimn_MotCurrDaxFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrPeakEstimn_MotCurrPeakEstimdFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrPeakEstimn_MotCurrQaxFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotCurrRegCfg_MotVelMrfFild; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaAFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaBFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaCFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaDFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaEFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotDrvDiagc_MotDrvDiagcPhaFFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRefMdl_MotVelLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotRplCoggPrmRec2, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_MotRplCoggCfg_MotRplCoggPrm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_HwTqLpFilLongTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_HwTqLpFilLrngEna; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_HwTqLpFilShoTerm; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PullCmpActv_VehYawRateLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_MotVelLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_PwrLimr_TqLimAssiRednLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgCdngFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgLrngFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgLrngFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgLrngSysTqFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgLrngSysTqFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgMeasFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwAgMeasFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqMeasFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwTqMeasFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_HwVelCdngFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SnsrLrndOffsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_SnsrOffsLrnd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_SysTqCdngFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_TqInpDetnHwTqFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawACdngFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawCdngFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawCdngFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawLrngFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SnsrOffsLrng_YawLrngFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilNotchStRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_AssiNotch1Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilNotchStRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_AssiNotch2Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilNotchStRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_AssiNotch3Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilNotchStRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_AssiNotch4Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_StabyCmp_HwTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_AssiMechTLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_AvrgFricLpFil1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_AvrgFricLpFil2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_AvrgFricLpFil3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_AvrgFricLpFil4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_ColTqLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricChgLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SysFricDataRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricLrngData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SysFricNonLrngDataRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_FricNonLrngData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_HwAgAuthyLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_HwAgLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_HwVelLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_LatALpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_SysFricLrng_VehSpdLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_AssiMechFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_CuFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_MagFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TEstimn_SiFilLp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqLoa_VehLatAEstimnFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TqOscn_PreFinalCmdLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(OnlineCalStsRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_TunSelnMngt_OnlineCalSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_HwTqFilRec; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_VehSigCdng_LatAFilRec; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_BlndCmdMgnLp1Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_BlndCmdMgnLp2Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_CmdMgnLp1Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_CmdMgnLp2Fil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(PassFailCntrDiagcRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendFltRcvry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DcTrendLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DistbnMgnLeLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_DistbnMgnRiLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(PassFailCntrDiagcRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcFltRcvry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_FrqDiagcLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(PassFailCntrDiagcRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_MaxMgnFltRcvry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(PassFailCntrDiagcRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdCorrlnFltRcvry; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdLeLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(FilLpRec1, RTE_VAR_DEFAULT_RTE_Appl10_PIM_GROUP) Rte_WhlImbRejctn_WhlSpdRiLpFil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_Appl10_PIM_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_AssiSumLim_ProcdManTqCmd = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_AssiSumLim_ProcdManTqCmdEna = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(u0p16, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg0DiagcAg = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg0SpiTrsmEna = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_Irv_CDD_MotAg0Meas_MotAg3Mecl = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(u0p16, RTE_VAR_INIT) Rte_Irv_CDD_MotAg1Meas_MotAg1DiagcAg = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_CDD_MotAg1Meas_MotAg1SpiTrsmEna = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(u0p16, RTE_VAR_INIT) Rte_Irv_CDD_MotAg1Meas_MotAg4Mecl = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(boolean, RTE_VAR_INIT) Rte_Irv_DutyCycThermProtn_FilStVariReInitFlg = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(boolean, RTE_VAR_INIT) Rte_Irv_GateDrv0Ctrl_GateDrv0Ena = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_GateDrv0Ctrl_Ivtr0PhyFltInpActv = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(boolean, RTE_VAR_INIT) Rte_Irv_GmFctDiArbn_FctDiReq = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_Irv_GmFctDiArbn_FctDiStrtTi = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint16, RTE_VAR_INIT) Rte_Irv_GmOvrlStMgr_IgnCntrLcl = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint16, RTE_VAR_INIT) Rte_Irv_HwAg0Meas_HwAg0Snsr0Raw = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_Irv_HwAg0Meas_HwAg0Snsr0TestOk = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_Irv_HwAg0Meas_HwAg0Snsr1Raw = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_Irv_HwAg0Meas_HwAg0Snsr1TestOk = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint16, RTE_VAR_INIT) Rte_Irv_HwAg1Meas_HwAg1Snsr0Raw = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_Irv_HwAg1Meas_HwAg1Snsr0TestOk = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_Irv_HwAg1Meas_HwAg1Snsr1Raw = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_Irv_HwAg1Meas_HwAg1Snsr1TestOk = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_HwAgSnsrls_StordHwAg = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_HwAgSnsrls_StordHwConf = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_HwAgTrajGenn_HwATar = 10.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_HwAgTrajGenn_HwAgTar = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_HwAgTrajGenn_HwVelTar = 10.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(boolean, RTE_VAR_INIT) Rte_Irv_HwTqCorrln_HwTqChAAvl = TRUE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_HwTqCorrln_HwTqChATqSumLim = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_HwTqCorrln_HwTqChBAvl = TRUE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_HwTqCorrln_HwTqChBTqSumLim = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(boolean, RTE_VAR_INIT) Rte_Irv_LoaMgr_SnsrlsMotAgAvl = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_MotCtrlPrmEstimn_MotBackEmfConFf = 0.03993F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_MotCurrPeakEstimn_MotCurrEstimd = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Ary1D_u16p0_2, RTE_VAR_INIT) Rte_Irv_MotTqTranlDampg_CtrldDampgScaX = {
  0U, 100U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Ary1D_u2p14_2, RTE_VAR_INIT) Rte_Irv_MotTqTranlDampg_CtrldDampgScaY = {
  16384U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_AntiWdupGain = 1.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_AntiWdupLim = 5.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_DerivtvGain = 0.004F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_DerivtvLpFilTiCon = 0.008F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_IntgtrGain = 0.15F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_PropGain = 0.2F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_MotVelCtrl_TqCmdLim = 8.8F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_PullCmpActv_RampDwnStepSize = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_PwrLimr_MinStdOperLim = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_PwrLimr_MotEnvlpSpd = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_PwrLimr_TqEnvlpLim1 = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint8, RTE_VAR_INIT) Rte_Irv_SnsrOffsLrng_HwTqLrngSts = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_StHlthSigNormn_EolFric = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(float32, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_CmdAmp = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_CurrMgnSlewRate = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_DcTrendFlt = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(float32, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_EnaSlewRate = 0.0F; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_FrqDiagcFlt = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_IniCmpFlt = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_MaxMgnFlt = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_SlowSpdDiagc = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_INIT) Rte_Irv_WhlImbRejctn_WhlSpdCorrlnFlt = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API Prototypes
 *********************************************************************************************************************/
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(uint32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Component Data Structures
 *********************************************************************************************************************/

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn01Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn01Rt01_Dummy =
{
  /* Port API section */
  {
    Rte_PrmInst1_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn01Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn01Rt01_Dummy_1 =
{
  /* Port API section */
  {
    Rte_PrmInst2_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn01Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn01Rt01_Dummy_2 =
{
  /* Port API section */
  {
    Rte_PrmInst3_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn01Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn01Rt01_Dummy_3 =
{
  /* Port API section */
  {
    Rte_PrmInst4_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn01Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn01Rt01_Dummy_4 =
{
  /* Port API section */
  {
    Rte_PrmInst5_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn02Rt01GroupC_Dummy, RTE_CONST) Rte_Instance_CalRegn02Rt01GroupC_Dummy =
{
  /* Port API section */
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val,
  },
  {
    Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn02Rt01GroupC_Dummy, RTE_CONST) Rte_Instance_CalRegn02Rt01GroupC_Dummy_1 =
{
  /* Port API section */
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val,
  },
  {
    Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn02Rt01GroupC_Dummy, RTE_CONST) Rte_Instance_CalRegn02Rt01GroupC_Dummy_2 =
{
  /* Port API section */
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val,
  },
  {
    Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn02Rt01GroupC_Dummy, RTE_CONST) Rte_Instance_CalRegn02Rt01GroupC_Dummy_3 =
{
  /* Port API section */
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val,
  },
  {
    Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn02Rt01GroupC_Dummy, RTE_CONST) Rte_Instance_CalRegn02Rt01GroupC_Dummy_4 =
{
  /* Port API section */
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val,
  },
  {
    Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupA_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupA_Dummy =
{
  /* Port API section */
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupA_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupA_Dummy_1 =
{
  /* Port API section */
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupA_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupA_Dummy_2 =
{
  /* Port API section */
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupA_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupA_Dummy_3 =
{
  /* Port API section */
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupA_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupA_Dummy_4 =
{
  /* Port API section */
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupB_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupB_Dummy =
{
  /* Port API section */
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupB_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupB_Dummy_1 =
{
  /* Port API section */
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupB_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupB_Dummy_2 =
{
  /* Port API section */
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupB_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupB_Dummy_3 =
{
  /* Port API section */
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01GroupB_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01GroupB_Dummy_4 =
{
  /* Port API section */
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01_Dummy =
{
  /* Port API section */
  {
    Rte_PrmInst1_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D,
  },
  {
    Rte_PrmInst1_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01_Dummy_1 =
{
  /* Port API section */
  {
    Rte_PrmInst2_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D,
  },
  {
    Rte_PrmInst2_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01_Dummy_2 =
{
  /* Port API section */
  {
    Rte_PrmInst3_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D,
  },
  {
    Rte_PrmInst3_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01_Dummy_3 =
{
  /* Port API section */
  {
    Rte_PrmInst4_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D,
  },
  {
    Rte_PrmInst4_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, RTE_CONST) Rte_Instance_CalRegn03Rt01_Dummy_4 =
{
  /* Port API section */
  {
    Rte_PrmInst5_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D,
  },
  {
    Rte_PrmInst5_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint16_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#define RTE_USEC_OsCounter(val) ((TickType)RTE_CONST_USEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */
#define RTE_MSEC_OsCounter(val) ((TickType)RTE_CONST_MSEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */
#define RTE_SEC_OsCounter(val)  ((TickType)RTE_CONST_SEC_OsCounter_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */

#define RTE_CONST_MSEC_OsCounter_0 (0UL)

#define RTE_CONST_MSEC_OsCounter_10 (5UL)

#define RTE_CONST_MSEC_OsCounter_100 (50UL)

#define RTE_CONST_MSEC_OsCounter_2 (1UL)

#define RTE_CONST_MSEC_OsCounter_4 (2UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


FUNC(void, RTE_CODE) Rte_InitMemory_Appl10(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_Assi_AssiCmdBas_Val = 0.0F;
  Rte_AssiHiFrq_AssiHiFrqCmd_Val = 0.0F;
  Rte_AssiPahFwl_AssiCmdSum_Val = 0.0F;
  Rte_AssiPahFwl_AssiPahLimrActv_Val = 0.0F;
  Rte_AssiSumLim_MotTqCmd_Val = 0.0F;
  Rte_AssiSumLim_MotTqCmdLimdPreStall_Val = 0.0F;
  Rte_AssiSumLim_MotTqCmdLimrMin_Val = 8.8F;
  Rte_AssiSumLim_MotTqCmdPreLim_Val = 0.0F;
  Rte_AssiSumLim_SysProtnRednFac_Val = 0.0F;
  Rte_BattVltg_BrdgVltg_Val = 6.0F;
  Rte_BattVltgCorrln_BattSwdVltgCorrlnSts_Val = 7U;
  Rte_BattVltgCorrln_BattVltgCorrlnIdptSig_Val = 3U;
  Rte_BattVltgCorrln_DftBrdgVltgActv_Logl = FALSE;
  Rte_BattVltgCorrln_SwdVltgLimd_Logl = FALSE;
  Rte_CDD_AdcDiagc_Adc0Faild_Logl = FALSE;
  Rte_CDD_AdcDiagc_Adc1Faild_Logl = FALSE;
  Rte_CDD_AdcDiagc_AdcDiagcEndPtrOutp_Val = 23U;
  Rte_CDD_AdcDiagc_AdcDiagcStrtPtrOutp_Val = 21U;
  Rte_CDD_CurrMeas_CurrMeasWrmIninTestCmpl_Logl = FALSE;
  Rte_CDD_CurrMeas_MotCurrEolCalSt_Val = 0U;
  Rte_CDD_CurrMeas_MotCurrQlfr1_Val = 0U;
  Rte_CDD_CurrMeas_MotCurrQlfr2_Val = 0U;
  Rte_CDD_FlsMem_CodFlsCrcChkCmpl_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref0_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup2Ref1_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref0_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_Adc1ScanGroup3Ref1_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag0_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag2_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_Adc1SelfDiag4_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_BattVltg_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_BattVltgAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd1AdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_BattVltgSwd2AdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_EcuT_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_EcuTAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotAg2Cos_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_MotAg2CosAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotAg2Sin_Val = 0.0F;
  Rte_CDD_GmG2kcaMcuCfg_MotAg2SinAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakAAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakBAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakCAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakDAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakEAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcPeakFAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyAAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyBAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyCAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyDAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyEAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrAdcVlyFAdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs1AdcFaild_Logl = FALSE;
  Rte_CDD_GmG2kcaMcuCfg_MotCurrSnsrOffs2AdcFaild_Logl = FALSE;
  Rte_CDD_HwTq0Meas_HwTq0_Val = 0.0F;
  Rte_CDD_HwTq0Meas_HwTq0Qlfr_Val = 0U;
  Rte_CDD_HwTq0Meas_HwTq0RollgCntr_Val = 0U;
  Rte_CDD_HwTq0Meas_RackLimrCcwEotSig0_Val = 0.0F;
  Rte_CDD_HwTq0Meas_RackLimrCwEotSig0_Val = 0.0F;
  Rte_CDD_HwTq0Meas_RackLimrEotSig0Avl_Logl = FALSE;
  Rte_CDD_HwTq1Meas_HwTq1_Val = 0.0F;
  Rte_CDD_HwTq1Meas_HwTq1Qlfr_Val = 0U;
  Rte_CDD_HwTq1Meas_HwTq1RollgCntr_Val = 0U;
  Rte_CDD_HwTq1Meas_RackLimrCcwEotSig1_Val = 0.0F;
  Rte_CDD_HwTq1Meas_RackLimrCwEotSig1_Val = 0.0F;
  Rte_CDD_HwTq1Meas_RackLimrEotSig1Avl_Logl = FALSE;
  Rte_CDD_HwTq2Meas_GearIdn1_Val = 0U;
  Rte_CDD_HwTq2Meas_GearIdn1Vld_Logl = FALSE;
  Rte_CDD_HwTq2Meas_HwTq2_Val = 0.0F;
  Rte_CDD_HwTq2Meas_HwTq2Qlfr_Val = 0U;
  Rte_CDD_HwTq2Meas_HwTq2RollgCntr_Val = 0U;
  Rte_CDD_HwTq3Meas_GearIdn2_Val = 0U;
  Rte_CDD_HwTq3Meas_GearIdn2Vld_Logl = FALSE;
  Rte_CDD_HwTq3Meas_HwTq3_Val = 0.0F;
  Rte_CDD_HwTq3Meas_HwTq3Qlfr_Val = 0U;
  Rte_CDD_HwTq3Meas_HwTq3RollgCntr_Val = 0U;
  Rte_CDD_McuDiagc_LoopCntr2MilliSec_Val = 0U;
  Rte_CDD_MotAg0Meas_MotAg0MeclQlfr_Val = 0U;
  Rte_CDD_MotAg0Meas_MotAg0MeclRollgCntr_Val = 0U;
  Rte_CDD_MotAg0Meas_MotAg0Offs_Val = 0;
  Rte_CDD_MotAg1Meas_MotAg1MeclQlfr_Val = 0U;
  Rte_CDD_MotAg1Meas_MotAg1MeclRollgCntr_Val = 0U;
  Rte_CDD_MotAg1Meas_MotAg1Offs_Val = 0;
  Rte_CDD_MotAgCmp_MotAgCumvAlgndCrf_Val = 0;
  Rte_CDD_MotAgCmp_MotAgCumvAlgndMrf_Val = 0;
  Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref0_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Adc0ScanGroup2Ref1_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref0_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Adc0ScanGroup3Ref1_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Adc0SelfDiag0_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Adc0SelfDiag2_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Adc0SelfDiag4_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_FastLoopCntr_Val = 0U;
  Rte_CDD_MotCtrlMgr_MotAg0Mecl_Val = 0U;
  Rte_CDD_MotCtrlMgr_MotAg1Mecl_Val = 0U;
  Rte_MemCpy32(Rte_CDD_MotCtrlMgr_MotAgBuf_Ary1D, Rte_C_Ary1D_u0p16_8_0, sizeof(Ary1D_u0p16_8));
  Rte_CDD_MotCtrlMgr_MotAgBufIdx_Val = 0U;
  Rte_CDD_MotCtrlMgr_MotAgCumvAlgndMrfRev_Val = 0;
  Rte_MemCpy32(Rte_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D, Rte_C_Ary1D_u32_8_1, sizeof(Ary1D_u32_8));
  Rte_CDD_MotCtrlMgr_MotCurrAdcVlyA_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrAdcVlyB_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrAdcVlyC_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrAdcVlyD_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrAdcVlyE_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrAdcVlyF_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrCorrdA_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrCorrdB_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrCorrdC_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrCorrdD_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrCorrdE_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrCorrdF_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrDax_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrQax_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotCurrRollgCntr1_Val = 0U;
  Rte_CDD_MotCtrlMgr_MotCurrRollgCntr2_Val = 0U;
  Rte_CDD_MotCtrlMgr_MotVltgDaxFild_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_MotVltgQaxFild_Val = 0.0F;
  Rte_CDD_MotCtrlMgr_Ntc5DErrCnt_Val = 0U;
  Rte_CDD_MotCtrlMgr_Ntc6DErrCnt_Val = 0U;
  Rte_CDD_MotCtrlMgr_PhaOnTiSumA_Val = 0U;
  Rte_CDD_MotCtrlMgr_PhaOnTiSumB_Val = 0U;
  Rte_CDD_MotCtrlMgr_PhaOnTiSumC_Val = 0U;
  Rte_CDD_MotCtrlMgr_SlowLoopCntr_Val = 0U;
  Rte_CDD_MotVel_HwVel_Val = 0.0F;
  Rte_CDD_MotVel_MotVelCrf_Val = 0.0F;
  Rte_CDD_MotVel_MotVelMrf_Val = 0.0F;
  Rte_CDD_RamMem_LclRamEccSngBitCntrOutp_Val = 0U;
  Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdA_Val = 0U;
  Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdB_Val = 0U;
  Rte_CDD_Tauj0CfgAndUse_PhaOnTiMeasdC_Val = 0U;
  Rte_CDD_Tauj1CfgAndUse_PhaOnTiMeasdD_Val = 0U;
  Rte_CDD_Tauj1CfgAndUse_PhaOnTiMeasdE_Val = 0U;
  Rte_CDD_Tauj1CfgAndUse_PhaOnTiMeasdF_Val = 0U;
  Rte_CmplncErr_CmplncErrMotToPinion_Val = 0.0F;
  Rte_CmplncErr_CmplncErrPinionToHw_Val = 0.0F;
  Rte_CurrMeasCorrln_CurrMeasCorrlnSts_Val = 63U;
  Rte_CurrMeasCorrln_CurrMeasIdptSig_Val = 2U;
  Rte_CurrMeasCorrln_CurrMotSumABC_Val = 0.0F;
  Rte_CurrMeasCorrln_CurrMotSumDEF_Val = 0.0F;
  Rte_Dampg_DampgCmdBas_Val = 0.0F;
  Rte_DampgPahFwl_DampgCmd_Val = 0.0F;
  Rte_DiagcMgr_ClrDiagcFlgProxy_Val = 0U;
  Rte_DiagcMgr_DiagcStsCtrldShtDwnFltPrsnt_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsDftHwAg_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsDftHwAgSerlComExprtVal_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsDftVehSpd_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsIvtr1Inactv_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsIvtr2Inactv_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsLimdTPrfmnc_Logl = FALSE;
  Rte_DiagcMgr_DiagcStsWhlImbRejctnDi_Logl = FALSE;
  Rte_DiagcMgr_SysDiMotTqCmdSca_Val = 1.0F;
  Rte_DiagcMgr_SysDiRampRate_Val = 1.0F;
  Rte_DiagcMgr_SysStFltOutpReqDi_Logl = FALSE;
  Rte_DutyCycThermProtn_DutyCycThermProtnMaxOutp_Val = 0U;
  Rte_DutyCycThermProtn_ThermDutyCycProtnLoadDptLim_Val = 8.8F;
  Rte_DutyCycThermProtn_ThermDutyCycProtnTDptLim_Val = 8.8F;
  Rte_DutyCycThermProtn_ThermLimSlowFilMax_Val = 0.0F;
  Rte_DutyCycThermProtn_ThermMotTqLim_Val = 8.8F;
  Rte_DutyCycThermProtn_ThermRednFac_Val = 0.0F;
  Rte_EcuTMeas_EcuTFild_Val = 25.0F;
  Rte_ElecPwrCns_ElecInpPwrEstim_Val = 0.0F;
  Rte_ElecPwrCns_SplyCurrEstim_Val = 0.0F;
  Rte_EotLrng_HwAgCcwDetd_Logl = FALSE;
  Rte_EotLrng_HwAgCwDetd_Logl = FALSE;
  Rte_EotLrng_HwAgEotCcw_Val = -360.0F;
  Rte_EotLrng_HwAgEotCw_Val = 360.0F;
  Rte_EotProtn_EotActvCmd_Val = 0.0F;
  Rte_EotProtn_EotAssiSca_Val = 1.0F;
  Rte_EotProtn_EotDampgCmd_Val = 0.0F;
  Rte_EotProtn_EotMotTqLim_Val = 8.8F;
  Rte_EotProtnFwl_EotActvCmdLimd_Val = 0.0F;
  Rte_EotProtnFwl_EotDampgCmdLimd_Val = 0.0F;
  Rte_GateDrv0Ctrl_MotDrvr0IninTestCmpl_Logl = FALSE;
  Rte_GmFctDiArbn_ApaEnaArbn_Logl = FALSE;
  Rte_GmFctDiArbn_EscEnaArbn_Logl = FALSE;
  Rte_GmFctDiArbn_GmFctDiSts_Val = 0U;
  Rte_GmFctDiArbn_InertiaCmpDecelGainDi_Logl = FALSE;
  Rte_GmFctDiArbn_LkaEnaArbn_Logl = FALSE;
  Rte_GmFctDiArbn_PullCmpActvDi_Logl = FALSE;
  Rte_GmFctDiArbn_TunSetRtDi_Logl = FALSE;
  Rte_GmFctDiArbn_WhlImbRejctnDi_Logl = FALSE;
  Rte_GmOvrlStMgr_ApaDrvrIntvDetd_Logl = FALSE;
  Rte_GmOvrlStMgr_ApaSt_Val = 0U;
  Rte_GmOvrlStMgr_EscSt_Val = 0U;
  Rte_GmOvrlStMgr_HwAgServoCmd_Val = 0.0F;
  Rte_GmOvrlStMgr_HwAgServoEna_Logl = FALSE;
  Rte_GmOvrlStMgr_HwOscnEna_Logl = FALSE;
  Rte_GmOvrlStMgr_HwOscnFrq_Val = 50.0F;
  Rte_GmOvrlStMgr_HwOscnMotAmp_Val = 0.0F;
  Rte_GmOvrlStMgr_HwTqOscSt_Val = 0U;
  Rte_GmOvrlStMgr_LkaSt_Val = 0U;
  Rte_GmRoadWhlInQlfr_WhlFrqVld_Logl = FALSE;
  Rte_GmRoadWhlInQlfr_WhlLeFrq_Val = 0.01F;
  Rte_GmRoadWhlInQlfr_WhlRiFrq_Val = 0.01F;
  Rte_GmStrtStop_VehStrtStopMotTqCmdSca_Val = 1.0F;
  Rte_GmStrtStop_VehStrtStopRampRate_Val = 1.0F;
  Rte_GmStrtStop_VehStrtStopSt_Val = 0U;
  Rte_GmTqArbn_AssiCmdBasSca_Val = 1.0F;
  Rte_GmTqArbn_DampgCmdSca_Val = 0.0F;
  Rte_GmTqArbn_EscCmdArbd_Val = 0.0F;
  Rte_GmTqArbn_EscLimdActv_Logl = FALSE;
  Rte_GmTqArbn_HwTqOvrl_Val = 0.0F;
  Rte_GmTqArbn_LkaTqCmdCdnd_Val = 0.0F;
  Rte_GmTqArbn_MotTqCmdOvrl_Val = 0.0F;
  Rte_GmTqArbn_RtnCmdSca_Val = 0.0F;
  Rte_GmVehPwrMod_PwrSplyEnaReq_Logl = FALSE;
  Rte_GmVehPwrMod_SysOperMotTqCmdSca_Val = 1.0F;
  Rte_GmVehPwrMod_SysOperRampRate_Val = 1.0F;
  Rte_GmVehPwrMod_SysStReqEna_Logl = FALSE;
  Rte_GmVehPwrMod_VehPwrModDftVehSpdEna_Logl = FALSE;
  Rte_GmVehSpdArbn_VehSpdArbd_Val = 0.0F;
  Rte_GmVehSpdArbn_VehSpdArbdVld_Logl = FALSE;
  Rte_GmVehSpdArbn_VehSpdMaxSecur_Val = 0.0F;
  Rte_GmVehSpdArbn_VehSpdMaxSecurVld_Logl = FALSE;
  Rte_GmVehSpdArbn_VehSpdMinSecur_Val = 0.0F;
  Rte_GmVehSpdArbn_VehSpdMinSecurVld_Logl = FALSE;
  Rte_GmVehSpdArbn_VehSpdSnsrVld_Logl = FALSE;
  Rte_HiLoadStallLimr_StallMotTqLim_Val = 8.8F;
  Rte_HowDetn_HowDetnEstimn_Val = 0.0F;
  Rte_HowDetn_HowDetnSt_Val = 0;
  Rte_HwAg0Meas_HwAg0_Val = 0.0F;
  Rte_HwAg0Meas_HwAg0Qlfr_Val = 0U;
  Rte_HwAg0Meas_HwAg0RollgCntr_Val = 0U;
  Rte_HwAg1Meas_HwAg1_Val = 0.0F;
  Rte_HwAg1Meas_HwAg1Qlfr_Val = 0U;
  Rte_HwAg1Meas_HwAg1RollgCntr_Val = 0U;
  Rte_HwAgArbn_HwAg_Val = 0.0F;
  Rte_HwAgCorrln_HwAgCorrlnSt_Val = 1U;
  Rte_HwAgCorrln_HwAgIdptSig_Val = 2U;
  Rte_HwAgSnsrls_HwAgSnsrls_Val = 0.0F;
  Rte_HwAgSnsrls_HwAgSnsrlsConf_Val = 0.0F;
  Rte_HwAgSysArbn_HwAgFinal_Val = 0.0F;
  Rte_HwAgSysArbn_HwAgNotCorrd_Val = 0.0F;
  Rte_HwAgSysArbn_HwAgStsToSerlCom_Logl = FALSE;
  Rte_HwAgSysArbn_HwAgToSerlCom_Val = 0.0F;
  Rte_HwAgSysArbn_PinionAg_Val = 0.0F;
  Rte_HwAgSysArbn_PinionAgConf_Val = 0.0F;
  Rte_HwAgTrajGenn_HwAgTrakgServoCmd_Val = 0.0F;
  Rte_HwAgTrakgServo_MotTqServoCmd_Val = 0.0F;
  Rte_HwAgVehCentrTrim_HwAgTrimPrfmd_Logl = FALSE;
  Rte_HwAgVehCentrTrim_HwAgVehTrimOffs_Val = 0.0F;
  Rte_HwTqArbn_HwTq_Val = 0.0F;
  Rte_HwTqArbn_HwTqChA_Val = 0.0F;
  Rte_HwTqArbn_HwTqChB_Val = 0.0F;
  Rte_HwTqCorrln_HwTqChACorrlnTraErr_Val = 0.0F;
  Rte_HwTqCorrln_HwTqChBCorrlnTraErr_Val = 0.0F;
  Rte_HwTqCorrln_HwTqCorrlnSts_Val = 15U;
  Rte_HwTqCorrln_HwTqIdptSig_Val = 4U;
  Rte_HysCmp_HysCmpCmd_Val = 0.0F;
  Rte_InertiaCmpVel_InertiaCmpVelCmd_Val = 0.0F;
  Rte_LimrCdng_EotAssiScaCdnd_Val = 1.0F;
  Rte_LimrCdng_EotMotTqLimCdnd_Val = 8.8F;
  Rte_LimrCdng_StallMotTqLimCdnd_Val = 8.8F;
  Rte_LimrCdng_SysMotTqCmdScaCdnd_Val = 1.0F;
  Rte_LimrCdng_ThermMotTqLimCdnd_Val = 8.8F;
  Rte_LimrCdng_VehSpdMotTqLimCdnd_Val = 8.8F;
  Rte_LoaMgr_CurrMeasLoaMtgtnEna_Logl = FALSE;
  Rte_LoaMgr_HwTqLoaMtgtnEna_Logl = FALSE;
  Rte_LoaMgr_IvtrLoaMtgtnEna_Logl = FALSE;
  Rte_LoaMgr_LoaRateLim_Val = 1.0F;
  Rte_LoaMgr_LoaSca_Val = 1.0F;
  Rte_LoaMgr_LoaSt_Val = 0U;
  Rte_LoaMgr_MotAgLoaMtgtnEna_Logl = FALSE;
  Rte_MotAgCorrln_MotAgMeclCorrlnSt_Val = 7U;
  Rte_MotAgCorrln_MotAgMeclIdptSig_Val = 3U;
  Rte_MotCtrlPrmEstimn_MotBackEmfConEstimd_Val = 0.025F;
  Rte_MotCtrlPrmEstimn_MotInduDaxEstimd_Val = 0.00011889F;
  Rte_MotCtrlPrmEstimn_MotInduDaxEstimdIvs_Val = 8412.0F;
  Rte_MotCtrlPrmEstimn_MotInduQaxEstimd_Val = 0.00011889F;
  Rte_MotCtrlPrmEstimn_MotInduQaxEstimdIvs_Val = 8412.0F;
  Rte_MotCtrlPrmEstimn_MotREstimd_Val = 0.0139083F;
  Rte_MotCurrPeakEstimn_MotCurrPeakEstimd_Val = 0.0F;
  Rte_MotCurrPeakEstimn_MotCurrPeakEstimdFild_Val = 0.0F;
  Rte_MotCurrRegCfg_MotAgElecDly_Val = 0.0F;
  Rte_MotCurrRegCfg_MotDampgDax_Val = 0.0F;
  Rte_MotCurrRegCfg_MotDampgQax_Val = 0.0F;
  Rte_MotCurrRegCfg_MotIntglGainDax_Val = 0.0F;
  Rte_MotCurrRegCfg_MotIntglGainQax_Val = 0.0F;
  Rte_MotCurrRegCfg_MotPropGainDax_Val = 0.0F;
  Rte_MotCurrRegCfg_MotPropGainQax_Val = 0.0F;
  Rte_MotDrvDiagc_MotDrvErrA_Val = 0.0F;
  Rte_MotDrvDiagc_MotDrvErrB_Val = 0.0F;
  Rte_MotDrvDiagc_MotDrvErrC_Val = 0.0F;
  Rte_MotDrvDiagc_MotDrvErrD_Val = 0.0F;
  Rte_MotDrvDiagc_MotDrvErrE_Val = 0.0F;
  Rte_MotDrvDiagc_MotDrvErrF_Val = 0.0F;
  Rte_MotQuadDetn_MotDirInsts_Val = 1;
  Rte_MotQuadDetn_MotQuad_Val = 1U;
  Rte_MotRefMdl_MotBackEmfVltg_Val = 0.0F;
  Rte_MotRefMdl_MotCurrAg_Val = 0.0F;
  Rte_MotRefMdl_MotCurrDaxCmd_Val = 0.0F;
  Rte_MotRefMdl_MotCurrDaxMax_Val = 0.0F;
  Rte_MotRefMdl_MotCurrQaxCmd_Val = 0.0F;
  Rte_MotRefMdl_MotReacncDax_Val = 0.0F;
  Rte_MotRefMdl_MotReacncQax_Val = 0.0F;
  Rte_MotRefMdl_MotVltgDaxFf_Val = 0.0F;
  Rte_MotRefMdl_MotVltgDaxFfStat_Val = 0.0F;
  Rte_MotRefMdl_MotVltgQaxFf_Val = 0.0F;
  Rte_MotRefMdl_MotVltgQaxFfStat_Val = 0.0F;
  Rte_MotRplCoggCfg_MotAgElecDlyRpl_Val = 0.0F;
  Rte_MotRplCoggCfg_MotCurrQaxToMotTqGain_Val = 0.021651F;
  Rte_MotRplCoggCfg_MotTqRplCoggOrder1Mgn_Val = 0.0F;
  Rte_MotRplCoggCfg_MotTqRplCoggOrder1Pha_Val = 0.0F;
  Rte_MotRplCoggCfg_MotTqRplCoggOrder2Mgn_Val = 0.0F;
  Rte_MotRplCoggCfg_MotTqRplCoggOrder2Pha_Val = 0.0F;
  Rte_MotRplCoggCfg_MotTqRplCoggOrder3Mgn_Val = 0.0F;
  Rte_MotRplCoggCfg_MotTqRplCoggOrder3Pha_Val = 0.0F;
  Rte_MotTqCmdSca_MotTqCmdMrfScad_Val = 0.0F;
  Rte_MotTqTranlDampg_MotTqCmdCrfDampd_Val = 0.0F;
  Rte_MotTqTranlDampg_MotTqCmdMrfDampd_Val = 0.0F;
  Rte_MotTqTranlDampg_MotTqTranlDampgCmpl_Logl = FALSE;
  Rte_PolarityCfg_AssiMechPolarity_Val = 1;
  Rte_PolarityCfg_HwAg0Polarity_Val = 1;
  Rte_PolarityCfg_HwAg1Polarity_Val = 1;
  Rte_PolarityCfg_HwAg2Polarity_Val = 1;
  Rte_PolarityCfg_HwAg3Polarity_Val = 1;
  Rte_PolarityCfg_HwAg4Polarity_Val = 1;
  Rte_PolarityCfg_HwAg5Polarity_Val = 1;
  Rte_PolarityCfg_HwAg6Polarity_Val = 1;
  Rte_PolarityCfg_HwAg7Polarity_Val = 1;
  Rte_PolarityCfg_HwTq0Polarity_Val = 1;
  Rte_PolarityCfg_HwTq1Polarity_Val = 1;
  Rte_PolarityCfg_HwTq2Polarity_Val = 1;
  Rte_PolarityCfg_HwTq3Polarity_Val = 1;
  Rte_PolarityCfg_HwTq4Polarity_Val = 1;
  Rte_PolarityCfg_HwTq5Polarity_Val = 1;
  Rte_PolarityCfg_HwTq6Polarity_Val = 1;
  Rte_PolarityCfg_HwTq7Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl0Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl1Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl2Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl3Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl4Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl5Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl6Polarity_Val = 1;
  Rte_PolarityCfg_MotAgMecl7Polarity_Val = 1;
  Rte_PolarityCfg_MotElecMeclPolarity_Val = 1;
  Rte_PullCmpActv_PullCmpCmd_Val = 0.0F;
  Rte_PwrDiscnct_PwrDiscnctATestCmpl_Logl = FALSE;
  Rte_PwrDiscnct_PwrDiscnctBTestCmpl_Logl = FALSE;
  Rte_PwrLimr_MotTqCmdPwrLimd_Val = 0.0F;
  Rte_PwrLimr_PwrLimrRednFac_Val = 0.0F;
  Rte_PwrUpSeq_StrtUpSt_Val = 0U;
  Rte_PwrUpSeq_SysStWrmIninCmpl_Logl = FALSE;
  Rte_Rtn_RtnCmd_Val = 0.0F;
  Rte_RtnPahFwl_RtnCmdLimd_Val = 0.0F;
  Rte_SnsrOffsCorrn_HwAgCorrd_Val = 0.0F;
  Rte_SnsrOffsCorrn_HwTqCorrd_Val = 0.0F;
  Rte_SnsrOffsCorrn_VehYawRateCorrd_Val = 0.0F;
  Rte_SnsrOffsLrng_HwAgOffs_Val = 0.0F;
  Rte_SnsrOffsLrng_HwTqOffs_Val = 0.0F;
  Rte_SnsrOffsLrng_VehYawRateOffs_Val = 0.0F;
  Rte_StHlthSigNormn_AbsltMotPosABDifStHlth_Val = 100U;
  Rte_StHlthSigNormn_AbsltMotPosACDifStHlth_Val = 100U;
  Rte_StHlthSigNormn_AbsltMotPosBCDifStHlth_Val = 100U;
  Rte_StHlthSigNormn_CtrlrTRng_Val = 0U;
  Rte_StHlthSigNormn_CtrlrTStHlth_Val = 100U;
  Rte_StHlthSigNormn_CurrMotSumABCStHlth_Val = 100U;
  Rte_StHlthSigNormn_CurrMotSumDEFStHlth_Val = 100U;
  Rte_StHlthSigNormn_DigTqIdptSigStHlth_Val = 100U;
  Rte_StHlthSigNormn_DigTqSnsrAStHlth_Val = 100U;
  Rte_StHlthSigNormn_DigTqSnsrBStHlth_Val = 100U;
  Rte_StHlthSigNormn_DutyCycStHlth_Val = 100U;
  Rte_StHlthSigNormn_EotImpctStHlth_Val = 100U;
  Rte_StHlthSigNormn_FricEstimnStHlth_Val = 100U;
  Rte_StHlthSigNormn_MotPosStHlth_Val = 100U;
  Rte_StHlthSigNormn_OutpAssiStHlth_Val = 100U;
  Rte_StHlthSigNormn_PhaAStHlth_Val = 100U;
  Rte_StHlthSigNormn_PhaBStHlth_Val = 100U;
  Rte_StHlthSigNormn_PhaCStHlth_Val = 100U;
  Rte_StHlthSigNormn_PhaDStHlth_Val = 100U;
  Rte_StHlthSigNormn_PhaEStHlth_Val = 100U;
  Rte_StHlthSigNormn_PhaFStHlth_Val = 100U;
  Rte_StHlthSigNormn_RamEccSngBitCorrnStHlth_Val = 100U;
  Rte_StHlthSigNormn_VltgRng_Val = 0U;
  Rte_StHlthSigNormn_WhlImbMaxCmpStHlth_Val = 100U;
  Rte_StOutpCtrl_SysMotTqCmdSca_Val = 1.0F;
  Rte_StOutpCtrl_SysStReqDi_Logl = FALSE;
  Rte_StabyCmp_AssiCmd_Val = 0.0F;
  Rte_Swp_HwTqSwp_Val = 0.0F;
  Rte_Swp_MotTqCmdSwp_Val = 0.0F;
  Rte_SysFricLrng_MaxLrndFric_Val = 0.0F;
  Rte_SysFricLrng_SysFricEstimd_Val = 0.0F;
  Rte_SysFricLrng_SysFricOffs_Val = 0.0F;
  Rte_SysFricLrng_SysSatnFricEstimd_Val = 0.0F;
  Rte_SysStMod_SysSt_Val = 3U;
  Rte_TEstimn_AssiMechT_Val = 0.0F;
  Rte_TEstimn_MotFetT_Val = 0.0F;
  Rte_TEstimn_MotMagT_Val = 0.0F;
  Rte_TEstimn_MotWidgT_Val = 0.0F;
  Rte_TmplMonr_TmplMonrIninTestCmpl_Logl = FALSE;
  Rte_TqLoa_TqLoaAvl_Logl = FALSE;
  Rte_TqLoa_TqLoaCmd_Val = 0.0F;
  Rte_TqOscn_HwOscnActv_Logl = FALSE;
  Rte_TqOscn_HwOscnCmd_Val = 0.0F;
  Rte_TqOscn_HwOscnDcThdExcdd_Logl = FALSE;
  Rte_TunSelnMngt_ActvGroup_Val = 0U;
  Rte_TunSelnMngt_ActvIninIdx_Val = 0U;
  Rte_TunSelnMngt_ActvRtIdx_Val = 0U;
  Rte_TunSelnMngt_CalCopySts_Val = 0U;
  Rte_VehSigCdng_VehLatA_Val = 0.0F;
  Rte_VehSigCdng_VehLatAEstimd_Val = 0.0F;
  Rte_VehSigCdng_VehLatAEstimdVld_Logl = FALSE;
  Rte_VehSigCdng_VehLatAVld_Logl = FALSE;
  Rte_VehSigCdng_VehLgtA_Val = 0.0F;
  Rte_VehSigCdng_VehLgtAVld_Logl = FALSE;
  Rte_VehSigCdng_VehSpd_Val = 0.0F;
  Rte_VehSigCdng_VehSpdVld_Logl = FALSE;
  Rte_VehSigCdng_VehYawRate_Val = 0.0F;
  Rte_VehSigCdng_VehYawRateVld_Logl = FALSE;
  Rte_VehSpdLimr_VehSpdMotTqLim_Val = 8.8F;
  Rte_WhlImbRejctn_WhlImbRejctnActv_Logl = FALSE;
  Rte_WhlImbRejctn_WhlImbRejctnAmp_Val = 0.0F;
  Rte_WhlImbRejctn_WhlImbRejctnCmd_Val = 0.0F;
  Rte_Assi_HwTqHysOvrl_Val = 0.0F;
  Rte_AssiSumLim_MotTqCmdLimDi_Logl = FALSE;
  Rte_AssiSumLim_PinionCentrLrnCmd_Val = 0.0F;
  Rte_AssiSumLim_PinionCentrLrnEna_Logl = FALSE;
  Rte_AssiSumLim_TqSteerMtgtnCmd_Val = 0.0F;
  Rte_BattVltgCorrln_InhbBattVltgDiagc_Logl = FALSE;
  Rte_CDD_MotCtrlMgr_MotREstimd_Val = 0.0F;
  Rte_CurrReasbnDiagc_MotAgElec_Val = 0U;
  Rte_Dampg_DampgCmdOvrl_Val = 0.0F;
  Rte_DiagcMgr_RegInBRAMDAT1_Val = 0U;
  Rte_DutyCycThermProtn_DualEcuFltMtgtnEna_Logl = FALSE;
  Rte_DutyCycThermProtn_IgnTiOff_Val = 0U;
  Rte_DutyCycThermProtn_VehTiVld_Logl = FALSE;
  Rte_ElecPwrCns_MotCtrlMotVltgDax_Val = 0.0F;
  Rte_ElecPwrCns_MotCtrlMotVltgQax_Val = 0.0F;
  Rte_EotLrng_HwAgDiDiagSts_Logl = FALSE;
  Rte_GmOvrlStMgr_HwAgTrajEna_Logl = FALSE;
  Rte_HwAgSnsrls_MotAgCumvAlgndVld_Logl = TRUE;
  Rte_HwAgTrajGenn_HwAgTrajGennEna_Logl = FALSE;
  Rte_MotCtrlPrmEstimn_DualEcuFltMtgtnEna_Logl = FALSE;
  Rte_MotCurrPeakEstimn_DualEcuMotCtrlMtgtnEna_Logl = FALSE;
  Rte_MotCurrRegCfg_DualEcuMotCtrlMtgtnEna_Logl = FALSE;
  Rte_MotRefMdl_DualEcuMotCtrlMtgtnEna_Logl = FALSE;
  Rte_PwrLimr_AltFltActv_Logl = FALSE;
  Rte_PwrLimr_DualEcuFltMtgtnSca_Val = 0.5F;
  Rte_PwrUpSeq_MotDrvr1IninTestCmpl_Logl = TRUE;
  Rte_Rtn_HwAgRtnOffs_Val = 0.0F;
  Rte_Rtn_RtnCmdDiagcDi_Logl = FALSE;
  Rte_Rtn_RtnCmdScaServo_Val = 1.0F;
  Rte_StHlthSigNormn_MotAg2VltgSqd_Val = 1.755625F;
  Rte_StHlthSigNormn_MotAgABErrTerm_Val = 0U;
  Rte_StHlthSigNormn_MotAgACErrTerm_Val = 0U;
  Rte_StHlthSigNormn_MotAgBCErrTerm_Val = 0U;
  Rte_SysFricLrng_FricLrngCustEna_Logl = FALSE;
  Rte_SysStMod_SysStImdtTranReqOff_Logl = FALSE;
  Rte_TEstimn_AmbTVld_Logl = FALSE;
  Rte_TEstimn_EngOilTVld_Logl = FALSE;
  Rte_TqOscn_HwOscnFallRampRate_Val = -4400.0F;
  Rte_TqOscn_HwOscnRisngRampRate_Val = 4400.0F;
  Rte_TunSelnMngt_DesIninIdx_Val = 0U;
  Rte_VehSigCdng_VehLgtAVldSerlCom_Logl = FALSE;
  Rte_WhlImbRejctn_WhlImbRejctnCustEna_Logl = TRUE;

  /* initialize inter-runnable variables */
  Rte_Irv_AssiSumLim_ProcdManTqCmd = 0.0F;
  Rte_Irv_AssiSumLim_ProcdManTqCmdEna = FALSE;
  Rte_Irv_CDD_MotAg0Meas_MotAg0DiagcAg = 0U;
  Rte_Irv_CDD_MotAg0Meas_MotAg0SpiTrsmEna = FALSE;
  Rte_Irv_CDD_MotAg0Meas_MotAg3Mecl = 0U;
  Rte_Irv_CDD_MotAg1Meas_MotAg1DiagcAg = 0U;
  Rte_Irv_CDD_MotAg1Meas_MotAg1SpiTrsmEna = FALSE;
  Rte_Irv_CDD_MotAg1Meas_MotAg4Mecl = 0U;
  Rte_Irv_DutyCycThermProtn_FilStVariReInitFlg = FALSE;
  Rte_Irv_GateDrv0Ctrl_GateDrv0Ena = FALSE;
  Rte_Irv_GateDrv0Ctrl_Ivtr0PhyFltInpActv = FALSE;
  Rte_Irv_GmFctDiArbn_FctDiReq = FALSE;
  Rte_Irv_GmFctDiArbn_FctDiStrtTi = 0U;
  Rte_Irv_GmOvrlStMgr_IgnCntrLcl = 0U;
  Rte_Irv_HwAg0Meas_HwAg0Snsr0Raw = 0U;
  Rte_Irv_HwAg0Meas_HwAg0Snsr0TestOk = 0U;
  Rte_Irv_HwAg0Meas_HwAg0Snsr1Raw = 0U;
  Rte_Irv_HwAg0Meas_HwAg0Snsr1TestOk = 0U;
  Rte_Irv_HwAg1Meas_HwAg1Snsr0Raw = 0U;
  Rte_Irv_HwAg1Meas_HwAg1Snsr0TestOk = 0U;
  Rte_Irv_HwAg1Meas_HwAg1Snsr1Raw = 0U;
  Rte_Irv_HwAg1Meas_HwAg1Snsr1TestOk = 0U;
  Rte_Irv_HwAgSnsrls_StordHwAg = 0.0F;
  Rte_Irv_HwAgSnsrls_StordHwConf = 0.0F;
  Rte_Irv_HwAgTrajGenn_HwATar = 10.0F;
  Rte_Irv_HwAgTrajGenn_HwAgTar = 0.0F;
  Rte_Irv_HwAgTrajGenn_HwVelTar = 10.0F;
  Rte_Irv_HwTqCorrln_HwTqChAAvl = TRUE;
  Rte_Irv_HwTqCorrln_HwTqChATqSumLim = 0.0F;
  Rte_Irv_HwTqCorrln_HwTqChBAvl = TRUE;
  Rte_Irv_HwTqCorrln_HwTqChBTqSumLim = 0.0F;
  Rte_Irv_LoaMgr_SnsrlsMotAgAvl = FALSE;
  Rte_Irv_MotCtrlPrmEstimn_MotBackEmfConFf = 0.03993F;
  Rte_Irv_MotCurrPeakEstimn_MotCurrEstimd = 0.0F;
  Rte_MemCpy(Rte_Irv_MotTqTranlDampg_CtrldDampgScaX, Rte_C_Ary1D_u16p0_2_1, sizeof(Ary1D_u16p0_2));
  Rte_MemCpy(Rte_Irv_MotTqTranlDampg_CtrldDampgScaY, Rte_C_Ary1D_u2p14_2_1, sizeof(Ary1D_u2p14_2));
  Rte_Irv_MotVelCtrl_AntiWdupGain = 1.0F;
  Rte_Irv_MotVelCtrl_AntiWdupLim = 5.0F;
  Rte_Irv_MotVelCtrl_DerivtvGain = 0.004F;
  Rte_Irv_MotVelCtrl_DerivtvLpFilTiCon = 0.008F;
  Rte_Irv_MotVelCtrl_IntgtrGain = 0.15F;
  Rte_Irv_MotVelCtrl_PropGain = 0.2F;
  Rte_Irv_MotVelCtrl_TqCmdLim = 8.8F;
  Rte_Irv_PullCmpActv_RampDwnStepSize = 0.0F;
  Rte_Irv_PwrLimr_MinStdOperLim = 0.0F;
  Rte_Irv_PwrLimr_MotEnvlpSpd = 0.0F;
  Rte_Irv_PwrLimr_TqEnvlpLim1 = 0.0F;
  Rte_Irv_SnsrOffsLrng_HwTqLrngSts = 0U;
  Rte_Irv_StHlthSigNormn_EolFric = 0.0F;
  Rte_Irv_WhlImbRejctn_CmdAmp = 0.0F;
  Rte_Irv_WhlImbRejctn_CurrMgnSlewRate = 0.0F;
  Rte_Irv_WhlImbRejctn_DcTrendFlt = FALSE;
  Rte_Irv_WhlImbRejctn_EnaSlewRate = 0.0F;
  Rte_Irv_WhlImbRejctn_FrqDiagcFlt = FALSE;
  Rte_Irv_WhlImbRejctn_IniCmpFlt = FALSE;
  Rte_Irv_WhlImbRejctn_MaxMgnFlt = FALSE;
  Rte_Irv_WhlImbRejctn_SlowSpdDiagc = FALSE;
  Rte_Irv_WhlImbRejctn_WhlSpdCorrlnFlt = FALSE;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_MotAgBuf_Ary1D(P2CONST(Ary1D_u0p16_8, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_WRITE_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_WriteHook_CDD_MotCtrlMgr_MotAgBuf_Ary1D_Start(data); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Rte_MemCpy32(Rte_CDD_MotCtrlMgr_MotAgBuf_Ary1D, *(data), sizeof(Ary1D_u0p16_8));
  Rte_WriteHook_CDD_MotCtrlMgr_MotAgBuf_Ary1D_Return(data); /* PRQA S 3112 */ /* MD_Rte_3112 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D(P2CONST(Ary1D_u32_8, AUTOMATIC, RTE_CDD_MOTCTRLMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_WRITE_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_WriteHook_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D_Start(data); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Rte_MemCpy32(Rte_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D, *(data), sizeof(Ary1D_u32_8));
  Rte_WriteHook_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D_Return(data); /* PRQA S 3112 */ /* MD_Rte_3112 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotVel_MotAgBuf_Ary1D(P2VAR(Ary1D_u0p16_8, AUTOMATIC, RTE_CDD_MOTVEL_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_READ_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_ReadHook_CDD_MotVel_MotAgBuf_Ary1D_Start(data); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Rte_MemCpy32(*(data), Rte_CDD_MotCtrlMgr_MotAgBuf_Ary1D, sizeof(Ary1D_u0p16_8));
  Rte_ReadHook_CDD_MotVel_MotAgBuf_Ary1D_Return(data); /* PRQA S 3112 */ /* MD_Rte_3112 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_MotVel_MotAgTiBuf_Ary1D(P2VAR(Ary1D_u32_8, AUTOMATIC, RTE_CDD_MOTVEL_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_READ_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_ReadHook_CDD_MotVel_MotAgTiBuf_Ary1D_Start(data); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Rte_MemCpy32(*(data), Rte_CDD_MotCtrlMgr_MotAgTiBuf_Ary1D, sizeof(Ary1D_u32_8));
  Rte_ReadHook_CDD_MotVel_MotAgTiBuf_Ary1D_Return(data); /* PRQA S 3112 */ /* MD_Rte_3112 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Inter-runnable variable access
 *********************************************************************************************************************/

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CODE) Rte_IrvRead_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaX(P2VAR(u16p0, AUTOMATIC, RTE_APPL_VAR) data)
#else
FUNC(void, RTE_CODE) Rte_IrvRead_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaX(P2VAR(Ary1D_u16p0_2, AUTOMATIC, RTE_APPL_VAR) data)
#endif
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_IRVREAD_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_IrvReadHook_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaX_Start(data); /* PRQA S 3112 */ /* MD_Rte_3112 */

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(data, Rte_Irv_MotTqTranlDampg_CtrldDampgScaX, sizeof(Ary1D_u16p0_2));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  Rte_IrvReadHook_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaX_Return(data); /* PRQA S 3112 */ /* MD_Rte_3112 */

  return;
}

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_CODE) Rte_IrvRead_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaY(P2VAR(u2p14, AUTOMATIC, RTE_APPL_VAR) data)
#else
FUNC(void, RTE_CODE) Rte_IrvRead_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaY(P2VAR(Ary1D_u2p14_2, AUTOMATIC, RTE_APPL_VAR) data)
#endif
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_IRVREAD_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_IrvReadHook_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaY_Start(data); /* PRQA S 3112 */ /* MD_Rte_3112 */

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(data, Rte_Irv_MotTqTranlDampg_CtrldDampgScaY, sizeof(Ary1D_u2p14_2));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  Rte_IrvReadHook_MotTqTranlDampg_MotTqTranlDampgPer1_CtrldDampgScaY_Return(data); /* PRQA S 3112 */ /* MD_Rte_3112 */

  return;
}


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP])->TEstimnMagAmbMplr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwTqY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt01_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwVelY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn01Rt02_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt02_DEFAULT_RTE_CALPRM_GROUP])->TEstimnMagAmbMplr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt02_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt02_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwTqY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt02_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt02_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwVelY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn01Rt03_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt03_DEFAULT_RTE_CALPRM_GROUP])->TEstimnMagAmbMplr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt03_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt03_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwTqY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt03_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt03_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwVelY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn01Rt04_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt04_DEFAULT_RTE_CALPRM_GROUP])->TEstimnMagAmbMplr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt04_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt04_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwTqY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt04_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt04_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwVelY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn01Rt01_Dummy_TEstimnMagAmbMplr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP])->TEstimnMagAmbMplr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn01Rt01_Dummy_TunSelnAuthyHwTqY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwTqY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u6p10_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn01Rt01_Dummy_TunSelnAuthyHwVelY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn01Rt00_DEFAULT_RTE_CALPRM_GROUP])->TunSelnAuthyHwVelY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrHwAgTarLimr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaEnaRate_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngHwTqLpFilFrq_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrShiftLvrTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaDiRateY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt01GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrHwAgTarLimr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaEnaRate_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngHwTqLpFilFrq_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrShiftLvrTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaDiRateY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt02GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrHwAgTarLimr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaEnaRate_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngHwTqLpFilFrq_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrShiftLvrTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaDiRateY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt03GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrHwAgTarLimr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaEnaRate_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngHwTqLpFilFrq_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrShiftLvrTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaDiRateY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt04GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrHwAgTarLimr_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrHwAgTarLimr_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaEnaRate_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaEnaRate_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(float32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngHwTqLpFilFrq_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngHwTqLpFilFrq_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrShiftLvrTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrShiftLvrTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC(uint32, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmOvrlStMgrStandStillTiThd_Val(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return ((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmOvrlStMgrStandStillTiThd_Val;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaDiRateY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaDiRateY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnApaSmotngY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnApaSmotngY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn02Rt01GroupC_Dummy_GmTqArbnLkaSlewY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn02Rt00GroupC_DEFAULT_RTE_CALPRM_GROUP])->GmTqArbnLkaSlewY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff1ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff2ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff3ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff4ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOffY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgCoeffX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgStatY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgSpdBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelNotchBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelY_Ary2D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff1ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff2ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff3ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff4ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOffY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgCoeffX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgStatY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgSpdBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelNotchBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelY_Ary2D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff1ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff2ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff3ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff4ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOffY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgCoeffX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgStatY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgSpdBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelNotchBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelY_Ary2D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff1ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff2ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff3ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff4ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOffY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgCoeffX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgStatY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgSpdBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelNotchBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelY_Ary2D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiHiFrqGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiHiFrqTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_AssiMotTqWhlImbRejctnMinY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMinY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff1ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff1ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff2ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff2ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff3ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff3ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgHydCoeff4ScaY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgHydCoeff4ScaY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgMotVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_DampgMotVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->DampgMotVelY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u8p8_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u2p14_6, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOffY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOffY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_HysCmpFricWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->HysCmpFricWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u4p12_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgCoeffX_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgCoeffX_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgRollgY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelAssiBasdDampgStatY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgStatY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelDampgSpdBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgSpdBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u1p15_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_InertiaCmpVelNotchBlndY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelNotchBlndY_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_9_16, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnHwAgOffsCalcdY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnHwAgOffsCalcdY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaTqY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaTqY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u7p9_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaVelX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_9_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupA_Dummy_RtnScaVelY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupA_DEFAULT_RTE_CALPRM_GROUP])->RtnScaVelY_Ary2D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqWhlImbRejctnTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejctnGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnDampgVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnExitDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnHwDegDampgX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnNormDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01GroupB_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqWhlImbRejctnTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejctnGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnDampgVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnExitDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnHwDegDampgX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnNormDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02GroupB_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqWhlImbRejctnTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejctnGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnDampgVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnExitDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnHwDegDampgX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnNormDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03GroupB_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqWhlImbRejctnTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejctnGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnDampgVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnExitDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnHwDegDampgX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnNormDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04GroupB_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqTqWhlImbRejctnTqX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqTqWhlImbRejctnTqX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u3p13_12_13, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejctnGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejctnGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u4p12_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiHiFrqWhlImbRejtcnBlndY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiHiFrqWhlImbRejtcnBlndY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u8p8_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_s4p11_12_20, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiMotTqWhlImbRejctnMaxY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiMotTqWhlImbRejctnMaxY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u5p11_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u2p14_12_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_AssiWhlImbRejctnBlndScaY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->AssiWhlImbRejctnBlndScaY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnDampgVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnDampgVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u9p7_5, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainVehSpdTbl_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainVehSpdTbl_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u1p15_5_4, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnEntrGainY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnEntrGainY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnExitDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnExitDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u12p4_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnHwDegDampgX_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnHwDegDampgX_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary2D_u0p16_4_2, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_EotProtnNormDampgY_Ary2D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->EotProtnNormDampgY_Ary2D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u0p16_10, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01GroupB_Dummy_InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00GroupB_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelAssiBasdDampgRollgWhlImbRejctnOnY_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrq_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst1_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt01_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt01_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrq_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst2_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt02_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt02_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrq_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst3_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt03_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt03_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrq_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst4_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt04_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt04_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Calprm API
 *********************************************************************************************************************/

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrq_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrq_Ary1D;
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
FUNC_P2CONST(Ary1D_u7p9_12, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP, RTE_CODE) Rte_PrmInst5_CalRegn03Rt01_Dummy_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(void)
{
   Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_PRM_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   return &((P2CONST(Rte_Calprm_CalRegn03Rt00_DEFAULT_RTE_CALPRM_GROUP_Type, AUTOMATIC, RTE_CONST))RteParameterBase[Rte_CalprmElementGroup_CalRegn03Rt00_DEFAULT_RTE_CALPRM_GROUP])->InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D;
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     Task_100ms_Appl10
 * Priority: 51
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_100ms_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_100ms_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_100msAppl10Strt_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_100msAppl10Strt();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_100msAppl10Strt_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DiagcMgr_DiagcMgrPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DiagcMgrPer2();
  Rte_Runnable_DiagcMgr_DiagcMgrPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DutyCycThermProtn_DutyCycThermProtnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DutyCycThermProtnPer1();
  Rte_Runnable_DutyCycThermProtn_DutyCycThermProtnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq0Meas_HwTq0MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq0MeasPer2();
  Rte_Runnable_CDD_HwTq0Meas_HwTq0MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq1Meas_HwTq1MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq1MeasPer2();
  Rte_Runnable_CDD_HwTq1Meas_HwTq1MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq2Meas_HwTq2MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq2MeasPer2();
  Rte_Runnable_CDD_HwTq2Meas_HwTq2MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq3Meas_HwTq3MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq3MeasPer2();
  Rte_Runnable_CDD_HwTq3Meas_HwTq3MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwTqCorrln_HwTqCorrlnPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTqCorrlnPer3();
  Rte_Runnable_HwTqCorrln_HwTqCorrlnPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer5_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg0MeasPer5();
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer5_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer5_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg1MeasPer5();
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer5_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCtrlPrmEstimn_MotCtrlPrmEstimnPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCtrlPrmEstimnPer2();
  Rte_Runnable_MotCtrlPrmEstimn_MotCtrlPrmEstimnPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCurrPeakEstimn_MotCurrPeakEstimnPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCurrPeakEstimnPer2();
  Rte_Runnable_MotCurrPeakEstimn_MotCurrPeakEstimnPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PullCmpActv_PullCmpActvPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PullCmpActvPer2();
  Rte_Runnable_PullCmpActv_PullCmpActvPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EcuTMeas_EcuTMeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EcuTMeasPer1();
  Rte_Runnable_EcuTMeas_EcuTMeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TEstimn_TEstimnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TEstimnPer1();
  Rte_Runnable_TEstimn_TEstimnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_IoHwAb_IoHwAb_Per1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  IoHwAb_Per1();
  Rte_Runnable_IoHwAb_IoHwAb_Per1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_FlsMem_FlsMemPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  FlsMemPer2();
  Rte_Runnable_CDD_FlsMem_FlsMemPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrpkCmpbltyChk_PwrpkCmpbltyChkPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrpkCmpbltyChkPer1();
  Rte_Runnable_PwrpkCmpbltyChk_PwrpkCmpbltyChkPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_100msAppl10End_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_100msAppl10End();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_100msAppl10End_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_10msBsw_Appl10
 * Priority: 60
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10msBsw_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState != RTE_STATE_UNINIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_10msBsw_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call schedulable entity */
  ChkPt_10msBswAppl10Strt();

  /* call runnable */
  Rte_Runnable_Dem_Dem_MainFunction_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Dem_MainFunction();
  Rte_Runnable_Dem_Dem_MainFunction_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EcuM_EcuM_MainFunction_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EcuM_MainFunction();
  Rte_Runnable_EcuM_EcuM_MainFunction_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_BswM_BswM_MainFunction_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  BswM_MainFunction();
  Rte_Runnable_BswM_BswM_MainFunction_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_NvM_NvM_MainFunction_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  NvM_MainFunction();
  Rte_Runnable_NvM_NvM_MainFunction_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  NvMProxy_MainFunction();
  Rte_Runnable_NvMProxy_NvMProxy_MainFunction_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call schedulable entity */
  Fee_MainFunction();

  /* call schedulable entity */
  Fls_MainFunction();

  /* call schedulable entity */
  ChkPt_10msBswAppl10End();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_10ms_Appl10
 * Priority: 62
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_10ms_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_10ms_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_10msAppl10Strt_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_10msAppl10Strt();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_10msAppl10Strt_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DiagcMgrProxyAppl10_DiagcMgrProxyAppl10Per1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DiagcMgrProxyAppl10Per1();
  Rte_Runnable_DiagcMgrProxyAppl10_DiagcMgrProxyAppl10Per1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmVehSpdArbn_GmVehSpdArbnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmVehSpdArbnPer1();
  Rte_Runnable_GmVehSpdArbn_GmVehSpdArbnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrLimr_PwrLimrPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrLimrPer2();
  Rte_Runnable_PwrLimr_PwrLimrPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmStrtStop_GmStrtStopPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmStrtStopPer1();
  Rte_Runnable_GmStrtStop_GmStrtStopPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmFctDiArbn_GmFctDiArbnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmFctDiArbnPer1();
  Rte_Runnable_GmFctDiArbn_GmFctDiArbnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TunSelnMngt_TunSelnMngtPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TunSelnMngtPer1();
  Rte_Runnable_TunSelnMngt_TunSelnMngtPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EotLrng_EotLrngPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EotLrngPer1();
  Rte_Runnable_EotLrng_EotLrngPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_VrfyCritReg_VrfyCritRegPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  VrfyCritRegPer1();
  Rte_Runnable_CDD_VrfyCritReg_VrfyCritRegPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SnsrOffsLrng_SnsrOffsLrngPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrOffsLrngPer2();
  Rte_Runnable_SnsrOffsLrng_SnsrOffsLrngPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SysFricLrng_SysFricLrngPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SysFricLrngPer1();
  Rte_Runnable_SysFricLrng_SysFricLrngPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_ElecPwrCns_ElecPwrCnsPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ElecPwrCnsPer1();
  Rte_Runnable_ElecPwrCns_ElecPwrCnsPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_10msAppl10End_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_10msAppl10End();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_10msAppl10End_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_2ms_Appl10
 * Priority: 81
 * Schedule: FULL
 * Alarm:    Cycle Time 0.002 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_2ms_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_2ms_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_2msAppl10Strt_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_2msAppl10Strt();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_2msAppl10Strt_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_DmaCfgAndUse_DmaCfgAndUsePer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DmaCfgAndUsePer1();
  Rte_Runnable_CDD_DmaCfgAndUse_DmaCfgAndUsePer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TmplMonr_TmplMonrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TmplMonrPer1();
  Rte_Runnable_TmplMonr_TmplMonrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_McuDiagc_McuDiagcPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  McuDiagcPer2();
  Rte_Runnable_CDD_McuDiagc_McuDiagcPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotCtrlMgr_MotCtrlMgrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCtrlMgrPer1();
  Rte_Runnable_CDD_MotCtrlMgr_MotCtrlMgrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Tauj0CfgAndUse_Tauj0CfgAndUsePer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Tauj0CfgAndUsePer1();
  Rte_Runnable_CDD_Tauj0CfgAndUse_Tauj0CfgAndUsePer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Tauj1CfgAndUse_Tauj1CfgAndUsePer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Tauj1CfgAndUsePer1();
  Rte_Runnable_CDD_Tauj1CfgAndUse_Tauj1CfgAndUsePer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GateDrv0Ctrl_GateDrv0CtrlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GateDrv0CtrlPer1();
  Rte_Runnable_GateDrv0Ctrl_GateDrv0CtrlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrDiscnct_PwrDiscnctPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrDiscnctPer1();
  Rte_Runnable_PwrDiscnct_PwrDiscnctPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_SnsrMeasStrt_SnsrMeasStrtPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrMeasStrtPer1();
  Rte_Runnable_CDD_SnsrMeasStrt_SnsrMeasStrtPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq0Meas_HwTq0MeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq0MeasPer1();
  Rte_Runnable_CDD_HwTq0Meas_HwTq0MeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq1Meas_HwTq1MeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq1MeasPer1();
  Rte_Runnable_CDD_HwTq1Meas_HwTq1MeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq2Meas_HwTq2MeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq2MeasPer1();
  Rte_Runnable_CDD_HwTq2Meas_HwTq2MeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq3Meas_HwTq3MeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq3MeasPer1();
  Rte_Runnable_CDD_HwTq3Meas_HwTq3MeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwTqCorrln_HwTqCorrlnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTqCorrlnPer1();
  Rte_Runnable_HwTqCorrln_HwTqCorrlnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwTqArbn_HwTqArbnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTqArbnPer1();
  Rte_Runnable_HwTqArbn_HwTqArbnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg0MeasPer3();
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg0MeasPer2();
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg1MeasPer3();
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg1MeasPer2();
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer4_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg0MeasPer4();
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer4_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer4_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg1MeasPer4();
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer4_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Adc1CfgAndUse_Adc1CfgAndUsePer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Adc1CfgAndUsePer1();
  Rte_Runnable_CDD_Adc1CfgAndUse_Adc1CfgAndUsePer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotVel_MotVelPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotVelPer2();
  Rte_Runnable_CDD_MotVel_MotVelPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SnsrOffsCorrn_SnsrOffsCorrnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrOffsCorrnPer1();
  Rte_Runnable_SnsrOffsCorrn_SnsrOffsCorrnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Swp_SwpPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SwpPer1();
  Rte_Runnable_Swp_SwpPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmRoadWhlInQlfr_GmRoadWhlInQlfrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmRoadWhlInQlfrPer1();
  Rte_Runnable_GmRoadWhlInQlfr_GmRoadWhlInQlfrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_WhlImbRejctn_WhlImbRejctnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  WhlImbRejctnPer1();
  Rte_Runnable_WhlImbRejctn_WhlImbRejctnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Assi_AssiPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiPer1();
  Rte_Runnable_Assi_AssiPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_AssiHiFrq_AssiHiFrqPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiHiFrqPer1();
  Rte_Runnable_AssiHiFrq_AssiHiFrqPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HysCmp_HysCmpPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HysCmpPer1();
  Rte_Runnable_HysCmp_HysCmpPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_AssiPahFwl_AssiPahFwlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiPahFwlPer1();
  Rte_Runnable_AssiPahFwl_AssiPahFwlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CmplncErr_CmplncErrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CmplncErrPer1();
  Rte_Runnable_CmplncErr_CmplncErrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgVehCentrTrim_HwAgVehCentrTrimPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgVehCentrTrimPer1();
  Rte_Runnable_HwAgVehCentrTrim_HwAgVehCentrTrimPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgSnsrls_HwAgSnsrlsPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgSnsrlsPer1();
  Rte_Runnable_HwAgSnsrls_HwAgSnsrlsPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgSysArbn_HwAgSysArbnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgSysArbnPer1();
  Rte_Runnable_HwAgSysArbn_HwAgSysArbnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Rtn_RtnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  RtnPer1();
  Rte_Runnable_Rtn_RtnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_StabyCmp_StabyCmpPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  StabyCmpPer1();
  Rte_Runnable_StabyCmp_StabyCmpPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Dampg_DampgPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DampgPer1();
  Rte_Runnable_Dampg_DampgPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_InertiaCmpVel_InertiaCmpVelPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  InertiaCmpVelPer1();
  Rte_Runnable_InertiaCmpVel_InertiaCmpVelPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DampgPahFwl_DampgPahFwlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DampgPahFwlPer1();
  Rte_Runnable_DampgPahFwl_DampgPahFwlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_RtnPahFwl_RtnPahFwlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  RtnPahFwlPer1();
  Rte_Runnable_RtnPahFwl_RtnPahFwlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_StOutpCtrl_StOutpCtrlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  StOutpCtrlPer1();
  Rte_Runnable_StOutpCtrl_StOutpCtrlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EotProtn_EotProtnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EotProtnPer1();
  Rte_Runnable_EotProtn_EotProtnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EotProtnFwl_EotProtnFwlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EotProtnFwlPer1();
  Rte_Runnable_EotProtnFwl_EotProtnFwlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PullCmpActv_PullCmpActvPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PullCmpActvPer1();
  Rte_Runnable_PullCmpActv_PullCmpActvPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotVelCtrl_MotVelCtrlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotVelCtrlPer1();
  Rte_Runnable_MotVelCtrl_MotVelCtrlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_AssiSumLim_AssiSumLimPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiSumLimPer1();
  Rte_Runnable_AssiSumLim_AssiSumLimPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Swp_SwpPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SwpPer2();
  Rte_Runnable_Swp_SwpPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotTqTranlDampg_MotTqTranlDampgPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotTqTranlDampgPer1();
  Rte_Runnable_MotTqTranlDampg_MotTqTranlDampgPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmG2kcaMcuCfgPer2();
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SnsrOffsLrng_SnsrOffsLrngPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrOffsLrngPer1();
  Rte_Runnable_SnsrOffsLrng_SnsrOffsLrngPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_AdcDiagc_AdcDiagcPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AdcDiagcPer1();
  Rte_Runnable_CDD_AdcDiagc_AdcDiagcPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Adc1CfgAndUse_Adc1CfgAndUsePer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Adc1CfgAndUsePer2();
  Rte_Runnable_CDD_Adc1CfgAndUse_Adc1CfgAndUsePer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmG2kcaMcuCfgPer3();
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_BattVltgCorrln_BattVltgCorrlnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  BattVltgCorrlnPer1();
  Rte_Runnable_BattVltgCorrln_BattVltgCorrlnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_BattVltg_BattVltgPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  BattVltgPer1();
  Rte_Runnable_BattVltg_BattVltgPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrLimr_PwrLimrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrLimrPer1();
  Rte_Runnable_PwrLimr_PwrLimrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotTqCmdSca_MotTqCmdScaPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotTqCmdScaPer1();
  Rte_Runnable_MotTqCmdSca_MotTqCmdScaPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotQuadDetn_MotQuadDetnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotQuadDetnPer1();
  Rte_Runnable_MotQuadDetn_MotQuadDetnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotRefMdl_MotRefMdlPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotRefMdlPer1();
  Rte_Runnable_MotRefMdl_MotRefMdlPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCurrRegCfg_MotCurrRegCfgPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCurrRegCfgPer1();
  Rte_Runnable_MotCurrRegCfg_MotCurrRegCfgPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotRplCoggCfg_MotRplCoggCfgPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotRplCoggCfgPer1();
  Rte_Runnable_MotRplCoggCfg_MotRplCoggCfgPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCurrPeakEstimn_MotCurrPeakEstimnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCurrPeakEstimnPer1();
  Rte_Runnable_MotCurrPeakEstimn_MotCurrPeakEstimnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCtrlPrmEstimn_MotCtrlPrmEstimnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCtrlPrmEstimnPer1();
  Rte_Runnable_MotCtrlPrmEstimn_MotCtrlPrmEstimnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TmplMonr_TmplMonrPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TmplMonrPer2();
  Rte_Runnable_TmplMonr_TmplMonrPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg0Meas_MotAg0MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg0MeasPer2();
  Rte_Runnable_CDD_MotAg0Meas_MotAg0MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg1Meas_MotAg1MeasPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg1MeasPer2();
  Rte_Runnable_CDD_MotAg1Meas_MotAg1MeasPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotAgCorrln_MotAgCorrlnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAgCorrlnPer1();
  Rte_Runnable_MotAgCorrln_MotAgCorrlnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAgCmp_MotAgCmpPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAgCmpPer2();
  Rte_Runnable_CDD_MotAgCmp_MotAgCmpPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_CurrMeas_CurrMeasPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrMeasPer3();
  Rte_Runnable_CDD_CurrMeas_CurrMeasPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CurrMeasCorrln_CurrMeasCorrlnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrMeasCorrlnPer1();
  Rte_Runnable_CurrMeasCorrln_CurrMeasCorrlnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgTrajGenn_HwAgTrajGennPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgTrajGennPer1();
  Rte_Runnable_HwAgTrajGenn_HwAgTrajGennPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmOvrlStMgr_GmOvrlStMgrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmOvrlStMgrPer1();
  Rte_Runnable_GmOvrlStMgr_GmOvrlStMgrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TqOscn_TqOscnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TqOscnPer1();
  Rte_Runnable_TqOscn_TqOscnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgTrakgServo_HwAgTrakgServoPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgTrakgServoPer1();
  Rte_Runnable_HwAgTrakgServo_HwAgTrakgServoPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmTqArbn_GmTqArbnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmTqArbnPer1();
  Rte_Runnable_GmTqArbn_GmTqArbnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HiLoadStallLimr_HiLoadStallLimrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HiLoadStallLimrPer1();
  Rte_Runnable_HiLoadStallLimr_HiLoadStallLimrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_VehSpdLimr_VehSpdLimrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  VehSpdLimrPer1();
  Rte_Runnable_VehSpdLimr_VehSpdLimrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_LimrCdng_LimrCdngPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  LimrCdngPer1();
  Rte_Runnable_LimrCdng_LimrCdngPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_CurrMeas_CurrMeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrMeasPer1();
  Rte_Runnable_CDD_CurrMeas_CurrMeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotDrvDiagc_MotDrvDiagcPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotDrvDiagcPer1();
  Rte_Runnable_MotDrvDiagc_MotDrvDiagcPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_VehSigCdng_VehSigCdngPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  VehSigCdngPer1();
  Rte_Runnable_VehSigCdng_VehSigCdngPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmVehPwrMod_GmVehPwrModPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmVehPwrModPer1();
  Rte_Runnable_GmVehPwrMod_GmVehPwrModPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TqLoa_TqLoaPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TqLoaPer1();
  Rte_Runnable_TqLoa_TqLoaPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrUpSeq_PwrUpSeqPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrUpSeqPer1();
  Rte_Runnable_PwrUpSeq_PwrUpSeqPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DiagcMgr_DiagcMgrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DiagcMgrPer1();
  Rte_Runnable_DiagcMgr_DiagcMgrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SysStMod_SysStModPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SysStModPer1();
  Rte_Runnable_SysStMod_SysStModPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotCtrlMgr_MotCtrlMgrPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCtrlMgrPer2();
  Rte_Runnable_CDD_MotCtrlMgr_MotCtrlMgrPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_TSG31CfgAndUse_TSG31CfgAndUsePer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TSG31CfgAndUsePer2();
  Rte_Runnable_CDD_TSG31CfgAndUse_TSG31CfgAndUsePer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_NxtrTi_NxtrTiPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  NxtrTiPer1();
  Rte_Runnable_CDD_NxtrTi_NxtrTiPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ExcpnHndlg_ExcpnHndlgPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ExcpnHndlgPer1();
  Rte_Runnable_CDD_ExcpnHndlg_ExcpnHndlgPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_RamMem_RamMemPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  RamMemPer1();
  Rte_Runnable_CDD_RamMem_RamMemPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HowDetn_HowDetnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HowDetnPer1();
  Rte_Runnable_HowDetn_HowDetnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg0MeasPer1();
  Rte_Runnable_HwAg0Meas_HwAg0MeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg1MeasPer1();
  Rte_Runnable_HwAg1Meas_HwAg1MeasPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GateDrv0Ctrl_GateDrv0CtrlPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GateDrv0CtrlPer2();
  Rte_Runnable_GateDrv0Ctrl_GateDrv0CtrlPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg0Meas_MotAg0MeasPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg0MeasPer3();
  Rte_Runnable_CDD_MotAg0Meas_MotAg0MeasPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg1Meas_MotAg1MeasPer3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg1MeasPer3();
  Rte_Runnable_CDD_MotAg1Meas_MotAg1MeasPer3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CurrReasbnDiagc_CurrReasbnDiagcPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrReasbnDiagcPer2();
  Rte_Runnable_CurrReasbnDiagc_CurrReasbnDiagcPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_2msAppl10End_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_2msAppl10End();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_2msAppl10End_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_4msBsw_Appl10
 * Priority: 90
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4msBsw_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState != RTE_STATE_UNINIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_4msBsw_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_WdgM_WdgM_MainFunction_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  WdgM_MainFunction();
  Rte_Runnable_WdgM_WdgM_MainFunction_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_4ms_Appl10
 * Priority: 70
 * Schedule: FULL
 * Alarm:    Cycle Time 0.004 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Task_4ms_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_4ms_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_4msAppl10Strt_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_4msAppl10Strt();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_4msAppl10Strt_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_WhlImbRejctn_WhlImbRejctnPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  WhlImbRejctnPer2();
  Rte_Runnable_WhlImbRejctn_WhlImbRejctnPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwTqCorrln_HwTqCorrlnPer2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTqCorrlnPer2();
  Rte_Runnable_HwTqCorrln_HwTqCorrlnPer2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_LoaMgr_LoaMgrPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  LoaMgrPer1();
  Rte_Runnable_LoaMgr_LoaMgrPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgArbn_HwAgArbnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgArbnPer1();
  Rte_Runnable_HwAgArbn_HwAgArbnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgCorrln_HwAgCorrlnPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgCorrlnPer1();
  Rte_Runnable_HwAgCorrln_HwAgCorrlnPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrSply_PwrSplyPer1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrSplyPer1();
  Rte_Runnable_PwrSply_PwrSplyPer1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_4msAppl10End_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ChkPt_4msAppl10End();
  Rte_Runnable_CDD_ChkPtAppl10_ChkPt_4msAppl10End_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Task_Init_Appl10
 * Priority: 98
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Task_Init_Appl10) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  Rte_CheckDetErrorContinue(Rte_InitState == RTE_STATE_INIT, RTE_TASK_SERVICE_ID, RTE_E_DET_UNINIT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_Task_Dispatch(Task_Init_Appl10); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_NxtrTi_NxtrTiInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  NxtrTiInit1();
  Rte_Runnable_CDD_NxtrTi_NxtrTiInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DiagcMgrProxyAppl10_DiagcMgrProxyAppl10Init1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DiagcMgrProxyAppl10Init1();
  Rte_Runnable_DiagcMgrProxyAppl10_DiagcMgrProxyAppl10Init1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_NvMProxy_NvMProxyInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  NvMProxyInit1();
  Rte_Runnable_CDD_NvMProxy_NvMProxyInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TmplMonr_TmplMonrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TmplMonrInit1();
  Rte_Runnable_TmplMonr_TmplMonrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SysStMod_SysStModInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SysStModInit1();
  Rte_Runnable_SysStMod_SysStModInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_ExcpnHndlg_ExcpnHndlgInit2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  ExcpnHndlgInit2();
  Rte_Runnable_CDD_ExcpnHndlg_ExcpnHndlgInit2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PolarityCfg_PolarityCfgInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PolarityCfgInit1();
  Rte_Runnable_PolarityCfg_PolarityCfgInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_CurrMeas_CurrMeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrMeasInit1();
  Rte_Runnable_CDD_CurrMeas_CurrMeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_CurrMeasArbn_CurrMeasArbnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrMeasArbnInit1();
  Rte_Runnable_CDD_CurrMeasArbn_CurrMeasArbnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwTqCorrln_HwTqCorrlnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTqCorrlnInit1();
  Rte_Runnable_HwTqCorrln_HwTqCorrlnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_SinVltgGenn_SinVltgGennInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SinVltgGennInit1();
  Rte_Runnable_CDD_SinVltgGenn_SinVltgGennInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotDrvDiagc_MotDrvDiagcInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotDrvDiagcInit1();
  Rte_Runnable_MotDrvDiagc_MotDrvDiagcInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EotProtn_EotProtnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EotProtnInit1();
  Rte_Runnable_EotProtn_EotProtnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TunSelnAuthy_TunSelnAuthyInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TunSelnAuthyInit1();
  Rte_Runnable_TunSelnAuthy_TunSelnAuthyInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Adc0CfgAndUse_Adc0CfgAndUseInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Adc0CfgAndUseInit1();
  Rte_Runnable_CDD_Adc0CfgAndUse_Adc0CfgAndUseInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmG2kcaMcuCfgInit1();
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgInit2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmG2kcaMcuCfgInit2();
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgInit2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgInit3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmG2kcaMcuCfgInit3();
  Rte_Runnable_CDD_GmG2kcaMcuCfg_GmG2kcaMcuCfgInit3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Tauj0CfgAndUse_Tauj0CfgAndUseInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Tauj0CfgAndUseInit1();
  Rte_Runnable_CDD_Tauj0CfgAndUse_Tauj0CfgAndUseInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Tauj1CfgAndUse_Tauj1CfgAndUseInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Tauj1CfgAndUseInit1();
  Rte_Runnable_CDD_Tauj1CfgAndUse_Tauj1CfgAndUseInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EcuTMeas_EcuTMeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EcuTMeasInit1();
  Rte_Runnable_EcuTMeas_EcuTMeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TEstimn_TEstimnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TEstimnInit1();
  Rte_Runnable_TEstimn_TEstimnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_DmaCfgAndUse_DmaCfgAndUseInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DmaCfgAndUseInit1();
  Rte_Runnable_CDD_DmaCfgAndUse_DmaCfgAndUseInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_TSG31CfgAndUse_TSG31CfgAndUseInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TSG31CfgAndUseInit1();
  Rte_Runnable_CDD_TSG31CfgAndUse_TSG31CfgAndUseInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq0Meas_HwTq0MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq0MeasInit1();
  Rte_Runnable_CDD_HwTq0Meas_HwTq0MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq1Meas_HwTq1MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq1MeasInit1();
  Rte_Runnable_CDD_HwTq1Meas_HwTq1MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq2Meas_HwTq2MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq2MeasInit1();
  Rte_Runnable_CDD_HwTq2Meas_HwTq2MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg0Meas_HwAg0MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg0MeasInit1();
  Rte_Runnable_HwAg0Meas_HwAg0MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAg1Meas_HwAg1MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAg1MeasInit1();
  Rte_Runnable_HwAg1Meas_HwAg1MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_HwTq3Meas_HwTq3MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwTq3MeasInit1();
  Rte_Runnable_CDD_HwTq3Meas_HwTq3MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmOvrlStMgr_GmOvrlStMgrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmOvrlStMgrInit1();
  Rte_Runnable_GmOvrlStMgr_GmOvrlStMgrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Swp_SwpInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SwpInit1();
  Rte_Runnable_Swp_SwpInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_Dampg_DampgInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DampgInit1();
  Rte_Runnable_Dampg_DampgInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_AssiSumLim_AssiSumLimInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiSumLimInit1();
  Rte_Runnable_AssiSumLim_AssiSumLimInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_StOutpCtrl_StOutpCtrlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  StOutpCtrlInit1();
  Rte_Runnable_StOutpCtrl_StOutpCtrlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrLimr_PwrLimrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrLimrInit1();
  Rte_Runnable_PwrLimr_PwrLimrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_AssiHiFrq_AssiHiFrqInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiHiFrqInit1();
  Rte_Runnable_AssiHiFrq_AssiHiFrqInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_StabyCmp_StabyCmpInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  StabyCmpInit1();
  Rte_Runnable_StabyCmp_StabyCmpInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgSysArbn_HwAgSysArbnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgSysArbnInit1();
  Rte_Runnable_HwAgSysArbn_HwAgSysArbnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TqLoa_TqLoaInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TqLoaInit1();
  Rte_Runnable_TqLoa_TqLoaInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_LoaMgr_LoaMgrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  LoaMgrInit1();
  Rte_Runnable_LoaMgr_LoaMgrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotTqTranlDampg_MotTqTranlDampgInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotTqTranlDampgInit1();
  Rte_Runnable_MotTqTranlDampg_MotTqTranlDampgInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotQuadDetn_MotQuadDetnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotQuadDetnInit1();
  Rte_Runnable_MotQuadDetn_MotQuadDetnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCtrlPrmEstimn_MotCtrlPrmEstimnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCtrlPrmEstimnInit1();
  Rte_Runnable_MotCtrlPrmEstimn_MotCtrlPrmEstimnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotRefMdl_MotRefMdlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotRefMdlInit1();
  Rte_Runnable_MotRefMdl_MotRefMdlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCurrRegCfg_MotCurrRegCfgInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCurrRegCfgInit1();
  Rte_Runnable_MotCurrRegCfg_MotCurrRegCfgInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotCurrRegVltgLimr_MotCurrRegVltgLimrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCurrRegVltgLimrInit1();
  Rte_Runnable_CDD_MotCurrRegVltgLimr_MotCurrRegVltgLimrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotCurrPeakEstimn_MotCurrPeakEstimnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotCurrPeakEstimnInit1();
  Rte_Runnable_MotCurrPeakEstimn_MotCurrPeakEstimnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HiLoadStallLimr_HiLoadStallLimrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HiLoadStallLimrInit1();
  Rte_Runnable_HiLoadStallLimr_HiLoadStallLimrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_Adc1CfgAndUse_Adc1CfgAndUseInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  Adc1CfgAndUseInit1();
  Rte_Runnable_CDD_Adc1CfgAndUse_Adc1CfgAndUseInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HysCmp_HysCmpInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HysCmpInit1();
  Rte_Runnable_HysCmp_HysCmpInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_VehSigCdng_VehSigCdngInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  VehSigCdngInit1();
  Rte_Runnable_VehSigCdng_VehSigCdngInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EotLrng_EotLrngInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EotLrngInit1();
  Rte_Runnable_EotLrng_EotLrngInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PullCmpActv_PullCmpActvInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PullCmpActvInit1();
  Rte_Runnable_PullCmpActv_PullCmpActvInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAgArbn_CDD_MotAgArbn_Init1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CDD_MotAgArbn_Init1();
  Rte_Runnable_CDD_MotAgArbn_CDD_MotAgArbn_Init1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmTqArbn_GmTqArbnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmTqArbnInit1();
  Rte_Runnable_GmTqArbn_GmTqArbnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_SyncCrc_SyncCrcInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SyncCrcInit1();
  Rte_Runnable_CDD_SyncCrc_SyncCrcInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TunSelnMngt_TunSelnMngtInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TunSelnMngtInit1();
  Rte_Runnable_TunSelnMngt_TunSelnMngtInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DutyCycThermProtn_DutyCycThermProtnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DutyCycThermProtnInit1();
  Rte_Runnable_DutyCycThermProtn_DutyCycThermProtnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_SnsrMeasStrt_SnsrMeasStrtInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrMeasStrtInit1();
  Rte_Runnable_CDD_SnsrMeasStrt_SnsrMeasStrtInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_EcmOutpAndDiagc_EcmOutpAndDiagcInit2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EcmOutpAndDiagcInit2();
  Rte_Runnable_CDD_EcmOutpAndDiagc_EcmOutpAndDiagcInit2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_GuardCfgAndDiagc_GuardCfgAndDiagcInit2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GuardCfgAndDiagcInit2();
  Rte_Runnable_CDD_GuardCfgAndDiagc_GuardCfgAndDiagcInit2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_FlsMem_FlsMemInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  FlsMemInit1();
  Rte_Runnable_CDD_FlsMem_FlsMemInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_RamMem_RamMemInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  RamMemInit1();
  Rte_Runnable_CDD_RamMem_RamMemInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_McuCoreCfgAndDiagc_McuCoreCfgAndDiagcInit3_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  McuCoreCfgAndDiagcInit3();
  Rte_Runnable_CDD_McuCoreCfgAndDiagc_McuCoreCfgAndDiagcInit3_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotAgCorrln_MotAgCorrlnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAgCorrlnInit1();
  Rte_Runnable_MotAgCorrln_MotAgCorrlnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrUpSeq_PwrUpSeqInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrUpSeqInit1();
  Rte_Runnable_PwrUpSeq_PwrUpSeqInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_VrfyCritReg_VrfyCritRegInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  VrfyCritRegInit1();
  Rte_Runnable_CDD_VrfyCritReg_VrfyCritRegInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgTrakgServo_HwAgTrakgServoInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgTrakgServoInit1();
  Rte_Runnable_HwAgTrakgServo_HwAgTrakgServoInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CmplncErr_CmplncErrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CmplncErrInit1();
  Rte_Runnable_CmplncErr_CmplncErrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_AdcDiagc_AdcDiagcInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AdcDiagcInit1();
  Rte_Runnable_CDD_AdcDiagc_AdcDiagcInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmStrtStop_GmStrtStopInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmStrtStopInit1();
  Rte_Runnable_GmStrtStop_GmStrtStopInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_AssiPahFwl_AssiPahFwlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  AssiPahFwlInit1();
  Rte_Runnable_AssiPahFwl_AssiPahFwlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DampgPahFwl_DampgPahFwlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DampgPahFwlInit1();
  Rte_Runnable_DampgPahFwl_DampgPahFwlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_EotProtnFwl_EotProtnFwlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  EotProtnFwlInit1();
  Rte_Runnable_EotProtnFwl_EotProtnFwlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_RtnPahFwl_RtnPahFwlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  RtnPahFwlInit1();
  Rte_Runnable_RtnPahFwl_RtnPahFwlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgTrajGenn_HwAgTrajGennInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgTrajGennInit1();
  Rte_Runnable_HwAgTrajGenn_HwAgTrajGennInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SnsrOffsLrng_SnsrOffsLrngInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrOffsLrngInit1();
  Rte_Runnable_SnsrOffsLrng_SnsrOffsLrngInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SnsrOffsCorrn_SnsrOffsCorrnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SnsrOffsCorrnInit1();
  Rte_Runnable_SnsrOffsCorrn_SnsrOffsCorrnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_TqOscn_TqOscnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  TqOscnInit1();
  Rte_Runnable_TqOscn_TqOscnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotRplCoggCfg_MotRplCoggCfgInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotRplCoggCfgInit1();
  Rte_Runnable_MotRplCoggCfg_MotRplCoggCfgInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotRplCoggCmd_MotRplCoggCmdInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotRplCoggCmdInit1();
  Rte_Runnable_CDD_MotRplCoggCmd_MotRplCoggCmdInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_StHlthSigNormn_StHlthSigNormnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  StHlthSigNormnInit1();
  Rte_Runnable_StHlthSigNormn_StHlthSigNormnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_StHlthSigStc_StHlthSigStcInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  StHlthSigStcInit1();
  Rte_Runnable_StHlthSigStc_StHlthSigStcInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HowDetn_HowDetnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HowDetnInit1();
  Rte_Runnable_HowDetn_HowDetnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotVelCtrl_MotVelCtrlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotVelCtrlInit1();
  Rte_Runnable_MotVelCtrl_MotVelCtrlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_DiagcMgrStub_DiagcMgrStubInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  DiagcMgrStubInit1();
  Rte_Runnable_DiagcMgrStub_DiagcMgrStubInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_MotTqCmdSca_MotTqCmdScaInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotTqCmdScaInit1();
  Rte_Runnable_MotTqCmdSca_MotTqCmdScaInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmRoadWhlInQlfr_GmRoadWhlInQlfrInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmRoadWhlInQlfrInit1();
  Rte_Runnable_GmRoadWhlInQlfr_GmRoadWhlInQlfrInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_DataAndAdrPar_CDD_DataAndAdrPar_Init2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CDD_DataAndAdrPar_Init2();
  Rte_Runnable_CDD_DataAndAdrPar_CDD_DataAndAdrPar_Init2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmVehSpdArbn_GmVehSpdArbnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmVehSpdArbnInit1();
  Rte_Runnable_GmVehSpdArbn_GmVehSpdArbnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_WhlImbRejctn_WhlImbRejctnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  WhlImbRejctnInit1();
  Rte_Runnable_WhlImbRejctn_WhlImbRejctnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrSply_PwrSplyInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrSplyInit1();
  Rte_Runnable_PwrSply_PwrSplyInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmVehPwrMod_GmVehPwrModInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmVehPwrModInit1();
  Rte_Runnable_GmVehPwrMod_GmVehPwrModInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_SysFricLrng_SysFricLrngInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  SysFricLrngInit1();
  Rte_Runnable_SysFricLrng_SysFricLrngInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Start(&Rte_Instance_CalRegn01Rt01_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn01Rt01DummyInit1(&Rte_Instance_CalRegn01Rt01_Dummy_2);
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Return(&Rte_Instance_CalRegn01Rt01_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Start(&Rte_Instance_CalRegn01Rt01_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn01Rt01DummyInit1(&Rte_Instance_CalRegn01Rt01_Dummy_3);
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Return(&Rte_Instance_CalRegn01Rt01_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Start(&Rte_Instance_CalRegn01Rt01_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn01Rt01DummyInit1(&Rte_Instance_CalRegn01Rt01_Dummy_1);
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Return(&Rte_Instance_CalRegn01Rt01_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Start(&Rte_Instance_CalRegn01Rt01_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn01Rt01DummyInit1(&Rte_Instance_CalRegn01Rt01_Dummy);
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Return(&Rte_Instance_CalRegn01Rt01_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Start(&Rte_Instance_CalRegn02Rt01GroupC_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn02Rt01GroupCDummyInit1(&Rte_Instance_CalRegn02Rt01GroupC_Dummy);
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Return(&Rte_Instance_CalRegn02Rt01GroupC_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Start(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn02Rt01GroupCDummyInit1(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_3);
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Return(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Start(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn02Rt01GroupCDummyInit1(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_2);
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Return(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Start(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn02Rt01GroupCDummyInit1(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_1);
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Return(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Start(&Rte_Instance_CalRegn03Rt01_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01DummyInit1(&Rte_Instance_CalRegn03Rt01_Dummy_3);
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Return(&Rte_Instance_CalRegn03Rt01_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Start(&Rte_Instance_CalRegn03Rt01_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01DummyInit1(&Rte_Instance_CalRegn03Rt01_Dummy);
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Return(&Rte_Instance_CalRegn03Rt01_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Start(&Rte_Instance_CalRegn03Rt01_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01DummyInit1(&Rte_Instance_CalRegn03Rt01_Dummy_2);
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Return(&Rte_Instance_CalRegn03Rt01_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Start(&Rte_Instance_CalRegn03Rt01_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01DummyInit1(&Rte_Instance_CalRegn03Rt01_Dummy_1);
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Return(&Rte_Instance_CalRegn03Rt01_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupADummyInit1(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_2);
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupADummyInit1(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_1);
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupA_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupADummyInit1(&Rte_Instance_CalRegn03Rt01GroupA_Dummy);
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupA_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupADummyInit1(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_3);
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupBDummyInit1(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_1);
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_1); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupB_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupBDummyInit1(&Rte_Instance_CalRegn03Rt01GroupB_Dummy);
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupB_Dummy); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupBDummyInit1(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_2);
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_2); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupBDummyInit1(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_3);
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_3); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Start(&Rte_Instance_CalRegn01Rt01_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn01Rt01DummyInit1(&Rte_Instance_CalRegn01Rt01_Dummy_4);
  Rte_Runnable_CalRegn01Rt01_Dummy_CalRegn01Rt01DummyInit1_Return(&Rte_Instance_CalRegn01Rt01_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Start(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn02Rt01GroupCDummyInit1(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_4);
  Rte_Runnable_CalRegn02Rt01GroupC_Dummy_CalRegn02Rt01GroupCDummyInit1_Return(&Rte_Instance_CalRegn02Rt01GroupC_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Start(&Rte_Instance_CalRegn03Rt01_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01DummyInit1(&Rte_Instance_CalRegn03Rt01_Dummy_4);
  Rte_Runnable_CalRegn03Rt01_Dummy_CalRegn03Rt01DummyInit1_Return(&Rte_Instance_CalRegn03Rt01_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupADummyInit1(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_4);
  Rte_Runnable_CalRegn03Rt01GroupA_Dummy_CalRegn03Rt01GroupADummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupA_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Start(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CalRegn03Rt01GroupBDummyInit1(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_4);
  Rte_Runnable_CalRegn03Rt01GroupB_Dummy_CalRegn03Rt01GroupBDummyInit1_Return(&Rte_Instance_CalRegn03Rt01GroupB_Dummy_4); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_PwrpkCmpbltyChk_PwrpkCmpbltyChkInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  PwrpkCmpbltyChkInit1();
  Rte_Runnable_PwrpkCmpbltyChk_PwrpkCmpbltyChkInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_McuDiagc_McuDiagcInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  McuDiagcInit1();
  Rte_Runnable_CDD_McuDiagc_McuDiagcInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotVel_MotVelInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotVelInit1();
  Rte_Runnable_CDD_MotVel_MotVelInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_InertiaCmpVel_InertiaCmpVelInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  InertiaCmpVelInit1();
  Rte_Runnable_InertiaCmpVel_InertiaCmpVelInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgSnsrls_HwAgSnsrlsInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgSnsrlsInit1();
  Rte_Runnable_HwAgSnsrls_HwAgSnsrlsInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_HwAgVehCentrTrim_HwAgVehCentrTrimInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  HwAgVehCentrTrimInit1();
  Rte_Runnable_HwAgVehCentrTrim_HwAgVehCentrTrimInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GmFctDiArbn_GmFctDiArbnInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GmFctDiArbnInit1();
  Rte_Runnable_GmFctDiArbn_GmFctDiArbnInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_GateDrv0Ctrl_GateDrv0CtrlInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  GateDrv0CtrlInit1();
  Rte_Runnable_GateDrv0Ctrl_GateDrv0CtrlInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg0Meas_MotAg0MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg0MeasInit1();
  Rte_Runnable_CDD_MotAg0Meas_MotAg0MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg1Meas_MotAg1MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg1MeasInit1();
  Rte_Runnable_CDD_MotAg1Meas_MotAg1MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg3Meas_MotAg3MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg3MeasInit1();
  Rte_Runnable_CDD_MotAg3Meas_MotAg3MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CDD_MotAg4Meas_MotAg4MeasInit1_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  MotAg4MeasInit1();
  Rte_Runnable_CDD_MotAg4Meas_MotAg4MeasInit1_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  /* call runnable */
  Rte_Runnable_CurrReasbnDiagc_CurrReasbnDiagcInit2_Start(); /* PRQA S 3112 */ /* MD_Rte_3112 */
  CurrReasbnDiagcInit2();
  Rte_Runnable_CurrReasbnDiagc_CurrReasbnDiagcInit2_Return(); /* PRQA S 3112 */ /* MD_Rte_3112 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0342:  MISRA rule: 19.13
     Reason:     For efficient code the use of macros and the operator '##' is necessary.
     Risk:       The used compiler is not ANSI/ISO C89 compatible. No functional risk.
     Prevention: AUTOSAR is based on ANSI/ISO C89. Compatible compilers are required.

   MD_Rte_0777:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_0779:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3112:  MISRA rule: 14.2
     Reason:     The structures of macros are specified in the RTE specification [rte_sws_1236].
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
