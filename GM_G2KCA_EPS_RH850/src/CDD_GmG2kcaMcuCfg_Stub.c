/**********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name: CDD_GmG2kcaMcuCfg_Stub.c
* Module Description: Stub GM G2kca Mcu Config File until component is created and implemented
* Project           : GM G2kca
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       CZ8L9T %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/28/15  1        LWW       Initial Version                                                                 EA4#517
* 05/07/15  2        LWW       Fixed ADC1 references                                                           EA4#517
* 06/16/15  3        LWW       Removed comments about FDD deviations due to updated FDD                        EA4#784
* 07/14/15  4        LWW       Update per FDD scaling changes                                                  EA4#1108
* 10/22/15  5        JWJ       Updates for micro diagnostics integration                                       EA4#2198
* 02/11/16  6        JWJ       Added periodic 3 for ADC diagnostics support                                    EA4#3772
* 04/25/16  7        JWJ       Added Batt Vltg Faild output in support of new FDD                              EA4#5483
* 07/13/16  8        JWJ       Added support for ADC scan group references                                     EA4#6572
* 09/26/16  9        JWJ       Removed the ADC Dynamic References                                              EA4#7560
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "Rte_CDD_GmG2kcaMcuCfg.h"
#include "CDD_Adc0CfgAndUse.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "pic_regs.h"
#include "adcd_regs.h"
#include "Os.h"
/******************************************** File Level Rule Deviations *********************************************/

/********************************************* Embedded Local Constants **********************************************/

#define ADCCNVWAITTI_CNT_U32				(uint32)25U
#define BATTVLTGSWD1SCAGFAC_ULS_F32			3.3696682464454974F /* (1.0/0.2967651195499297) */
#define BATTVLTGSWD2SCAGFAC_ULS_F32			3.3696682464454974F /* (1.0/0.2967651195499297) */
#define BATTVLTGSCAGFAC_ULS_F32				6.7471264367816104F /* (1.0/0.1482112436115843) */

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

/**********************************************************************************************************************
  * Name:        GmG2kcaMcuCfgInit1
  * Description: Init1 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit1(void)
{
	PIC2BADCD0TSEL0 = 0x00000000U;
	PIC2BADCD0TSEL1 = 0x00000040U;
	PIC2BADCD0TSEL2 = 0x00000040U;
	PIC2BADCD0TSEL3 = 0x04000000U;
	PIC2BADCD0TSEL4 = 0x00000000U;
	PIC2BADCD0EDGSEL = 0x0000U;
	PIC2BADCD1TSEL0 = 0x00000000U;
	PIC2BADCD1TSEL1 = 0x00000080U;
	PIC2BADCD1TSEL2 = 0x00000080U;
	PIC2BADCD1TSEL3 = 0x00000080U;
	PIC2BADCD1TSEL4 = 0x00000000U;
	PIC2BADCD1EDGSEL = 0x0000U;
	PIC2BADTEN400 = 0x0000U;
	PIC2BADTEN401 = 0x0000U;
	PIC2BADTEN402 = 0x0000U;
	PIC2BADTEN403 = 0x0000U;
	PIC2BADTEN404 = 0x0000U;
	PIC2BADTEN410 = 0x0000U;
	PIC2BADTEN411 = 0x0000U;
	PIC2BADTEN412 = 0x0000U;
	PIC2BADTEN413 = 0x0000U;
	PIC2BADTEN414 = 0x0000U;
	PIC2BADSYNCTRG = 0x00U;
	PIC1AREG30 = 0U; /* MotAg3Meas */
	
}

/**********************************************************************************************************************
  * Name:        GmG2kcaMcuCfgInit2
  * Description: Init2 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit2(void)
{
	VAR(uint32, AUTOMATIC) StartTime_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ElapsedTime_Cnt_T_u32;

	Rte_Call_GetRefTmr1MicroSec32bit_Oper(&StartTime_Cnt_T_u32);

	do
	{
		Rte_Call_GetTiSpan1MicroSec32bit_Oper(StartTime_Cnt_T_u32, &ElapsedTime_Cnt_T_u32);
	}while(ElapsedTime_Cnt_T_u32 < ADCCNVWAITTI_CNT_U32);

	Call_Adc0OutpInin();
}

/**********************************************************************************************************************
  * Name:        GmG2kcaMcuCfgInit3
  * Description: Init3 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit3(void)
{
	(void)Rte_Write_Adc1ScanGroup3Ref0_Val((float32)ADCD1.DR00.BIT.DR00 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_EcuT_Val((float32)ADCD1.DR00.BIT.DR01 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_BattVltgSwd1_Val((float32)ADCD1.DR02.BIT.DR02 * BATTVLTGSWD1SCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1ScanGroup3Ref1_Val((float32)ADCD1.DR02.BIT.DR03 * BATTVLTGSWD2SCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1ScanGroup2Ref0_Val((float32)ADCD1.DR04.BIT.DR04 * BATTVLTGSWD2SCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_BattVltg_Val((float32)ADCD1.DR04.BIT.DR05 * BATTVLTGSCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1ScanGroup2Ref1_Val((float32)ADCD1.DR06.BIT.DR06 * BATTVLTGSCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1SelfDiag0_Val((float32)ADCD1.DR20.BIT.DR21 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1SelfDiag2_Val((float32)ADCD1.DR22.BIT.DR22 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1SelfDiag4_Val((float32)ADCD1.DR22.BIT.DR23 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);

}

/**********************************************************************************************************************
  * Name:        GmG2kcaMcuCfgPer1
  * Description: Per1 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgPer1(void)
{
	MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref0 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[0] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyA = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[1] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyB = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[2] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyC = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[3] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	
	/* Copy values from ABC */
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyD = MOTCTRLMGR_MotCtrlMotCurrAdcVlyA;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyE = MOTCTRLMGR_MotCtrlMotCurrAdcVlyB;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyF = MOTCTRLMGR_MotCtrlMotCurrAdcVlyC;
	
	MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref1 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[4] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref0 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[5] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	
	MOTCTRLMGR_MotCtrlMotCurrAdcPeakA = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[6] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcPeakB = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[7] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcPeakC = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[8] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	
	MOTCTRLMGR_MotCtrlMotCurrSnsrOffs1 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[9] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref1 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[10] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0SelfDiag0 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[21] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0SelfDiag2 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[22] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0SelfDiag4 = (float32)MOTCTRLMGR_MotCtrlAdc0RawRes[23] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
}

/**********************************************************************************************************************
  * Name:        GmG2kcaMcuCfgPer2
  * Description: Per2 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgPer2(void)
{
	(void)Rte_Write_Adc1ScanGroup3Ref0_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[0] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_EcuT_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[1] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_BattVltgSwd1_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[2] * BATTVLTGSWD1SCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1ScanGroup3Ref1_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[3] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1ScanGroup2Ref0_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[4] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_BattVltg_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[5] * BATTVLTGSCAGFAC_ULS_F32 * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1ScanGroup2Ref1_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[6] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1SelfDiag0_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[21] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1SelfDiag2_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[22] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
	(void)Rte_Write_Adc1SelfDiag4_Val((float32)MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc1RawRes[23] * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32);
}

/**********************************************************************************************************************
  * Name:        GmG2kcaMcuCfgPer3
  * Description: Per3 Function
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: NONE
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgPer3(void)
{
	VAR(boolean, AUTOMATIC) Adc0Faild_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) Adc1Faild_Cnt_T_logl;

	(void)Rte_Read_Adc0Faild_Logl(&Adc0Faild_Cnt_T_logl);
	(void)Rte_Read_Adc1Faild_Logl(&Adc1Faild_Cnt_T_logl);

	(void)Rte_Write_MotCurrAdcPeakAAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcPeakBAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcPeakCAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcPeakDAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcPeakEAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcPeakFAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcVlyAAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcVlyBAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcVlyCAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcVlyDAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcVlyEAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrAdcVlyFAdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrSnsrOffs1AdcFaild_Logl(Adc0Faild_Cnt_T_logl);
	(void)Rte_Write_MotCurrSnsrOffs2AdcFaild_Logl(Adc0Faild_Cnt_T_logl);

	(void)Rte_Write_BattVltgSwd1AdcFaild_Logl(Adc1Faild_Cnt_T_logl);
	(void)Rte_Write_BattVltgSwd2AdcFaild_Logl(Adc1Faild_Cnt_T_logl);
	(void)Rte_Write_EcuTAdcFaild_Logl(Adc1Faild_Cnt_T_logl);
	(void)Rte_Write_MotAg2CosAdcFaild_Logl(Adc1Faild_Cnt_T_logl);
	(void)Rte_Write_MotAg2SinAdcFaild_Logl(Adc1Faild_Cnt_T_logl);
	(void)Rte_Write_BattVltgAdcFaild_Logl(Adc1Faild_Cnt_T_logl);
}

/**********************************************************************************************************************
  * Name:        Adc0OutpInin
  * Description: ADC 0 Output Initialization
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: Called from Init1 above via trusted function call.
  ********************************************************************************************************************/
FUNC(void, CDD_GmG2kcaMcuCfg_CODE) Adc0OutpInin(void)
{
	MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref0 = (float32)ADCD0.DR00.BIT.DR00 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyA = (float32)ADCD0.DR00.BIT.DR01 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyB = (float32)ADCD0.DR02.BIT.DR02 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyC = (float32)ADCD0.DR02.BIT.DR03 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	
	/* Copy values from ABC */
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyD = MOTCTRLMGR_MotCtrlMotCurrAdcVlyA;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyE = MOTCTRLMGR_MotCtrlMotCurrAdcVlyB;
	MOTCTRLMGR_MotCtrlMotCurrAdcVlyF = MOTCTRLMGR_MotCtrlMotCurrAdcVlyC;
	
	MOTCTRLMGR_MotCtrlAdc0ScanGroup3Ref1 = (float32)ADCD0.DR04.BIT.DR04 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref0 = (float32)ADCD0.DR04.BIT.DR05 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcPeakA = (float32)ADCD0.DR06.BIT.DR06 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcPeakB = (float32)ADCD0.DR06.BIT.DR07 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrAdcPeakC = (float32)ADCD0.DR08.BIT.DR08 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlMotCurrSnsrOffs1 = (float32)ADCD0.DR08.BIT.DR09 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0ScanGroup2Ref1 = (float32)ADCD0.DR10.BIT.DR10 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0SelfDiag0 = (float32)ADCD0.DR20.BIT.DR21 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0SelfDiag2 = (float32)ADCD0.DR22.BIT.DR22 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
	MOTCTRLMGR_MotCtrlAdc0SelfDiag4 = (float32)ADCD0.DR22.BIT.DR23 * 1.0F * ADC0CFGANDUSE_ADCSCAGFAC_VOLTPERCNT_F32;
}
