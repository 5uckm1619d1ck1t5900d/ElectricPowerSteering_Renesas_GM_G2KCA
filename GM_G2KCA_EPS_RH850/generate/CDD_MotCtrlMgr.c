
/**********************************************************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotCtrlMgr.c
* Module Description: Motor Control Manager
* Project           : CBD
* Author            : Lucas Wendling
* Generator         : artt 2.0.2.0
* Generation Time   : 21.12.2016 15:47:04
***********************************************************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/05/15  1        LWW       Initial Template Version                                                        EA4#511
* 10/29/15  2        LWW       Template update for signal mapping changes                                      EA4#3428
* 08/08/16  3        LWW       Template update for compatibility with MotCtrlMgr Configuration Tool            EA4#6787
**********************************************************************************************************************/



/************************************************ Include Statements *************************************************/
#include "Rte_CDD_MotCtrlMgr.h"
#include "CDD_MotCtrlMgr_Data.h"
/******************************************** File Level Rule Deviations *********************************************/

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value.  Applicable to all casts to void for all Rte_Read and Rte_Write and for client calls that don't have return errors. */ 

/********************************************* Embedded Local Constants **********************************************/

/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

#define CDD_MotCtrlMgr_START_SEC_CODE
#include "CDD_MotCtrlMgr_MemMap.h"

/**********************************************************************************************************************
  * Name:        MotCtrlMgrPer1
  * Description: This function copies all non-RTE data transferred by the DMA from the Motor Control loop to the 2ms loop
  *              and provides them as standard sender outputs for use by the RTE.  A DMA function is called to ensure
  *              completion of the transfer and in case of a timeout error, the RTE outputs are not updated from values
  *              last loop.
  * Inputs:      MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec structure
  * Outputs:     Individual RTE outputs for all signals
  * Usage Notes: To be scheduled by the RTE near the start of the 2ms loop.  Note that other runnables not requiring 
  *              Motor control data can be scheduled in-between the runnable triggering the DMA transfer and this function
  *              to try to prevent or minimize stalled execution while waiting for the DMA transfer.
  ********************************************************************************************************************/
FUNC(void, CDD_MotCtrlMgr_CODE) MotCtrlMgrPer1(void)
{
	if (Rte_Call_DmaWaitForMotCtrlTo2MilliSecTrf_Oper() == E_OK)
	{
		(void)Rte_Write_Adc0SelfDiag0_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0SelfDiag0);
		(void)Rte_Write_Adc0SelfDiag2_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0SelfDiag2);
		(void)Rte_Write_Adc0SelfDiag4_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0SelfDiag4);
		(void)Rte_Write_MotCurrAdcVlyA_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrAdcVlyA);
		(void)Rte_Write_MotCurrAdcVlyB_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrAdcVlyB);
		(void)Rte_Write_MotCurrAdcVlyC_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrAdcVlyC);
		(void)Rte_Write_MotCurrDax_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrDax);
		(void)Rte_Write_MotCurrQax_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrQax);
		(void)Rte_Write_MotAg0Mecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg0Mecl);
		(void)Rte_Write_PhaOnTiSumA_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.PhaOnTiSumA);
		(void)Rte_Write_PhaOnTiSumB_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.PhaOnTiSumB);
		(void)Rte_Write_PhaOnTiSumC_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.PhaOnTiSumC);
		(void)Rte_Write_MotAgCumvAlgndMrfRev_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgCumvAlgndMrfRev);
		(void)Rte_Write_MotAgBuf_Ary1D(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgBuf);
		(void)Rte_Write_MotAgBufIdx_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgBufIdx);
		(void)Rte_Write_MotAgTiBuf_Ary1D(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAgTiBuf);
		(void)Rte_Write_MotCurrCorrdA_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdA);
		(void)Rte_Write_MotCurrCorrdB_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdB);
		(void)Rte_Write_MotCurrCorrdC_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdC);
		(void)Rte_Write_MotCurrCorrdD_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdD);
		(void)Rte_Write_MotCurrCorrdE_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdE);
		(void)Rte_Write_MotCurrCorrdF_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrCorrdF);
		(void)Rte_Write_MotCurrRollgCntr1_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrRollgCntr1);
		(void)Rte_Write_MotCurrRollgCntr2_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotCurrRollgCntr2);
		(void)Rte_Write_MotAg1Mecl_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotAg1Mecl);
		(void)Rte_Write_Ntc5DErrCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Ntc5DErrCnt);
		(void)Rte_Write_Ntc6DErrCnt_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Ntc6DErrCnt);
		(void)Rte_Write_FastLoopCntr_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.FastLoopCntr);
		(void)Rte_Write_SlowLoopCntr_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.SlowLoopCntr);
		(void)Rte_Write_Adc0ScanGroup3Ref0_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup3Ref0);
		(void)Rte_Write_Adc0ScanGroup3Ref1_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup3Ref1);
		(void)Rte_Write_Adc0ScanGroup2Ref1_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup2Ref1);
		(void)Rte_Write_Adc0ScanGroup2Ref0_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.Adc0ScanGroup2Ref0);
		(void)Rte_Write_MotVltgDaxFild_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotVltgDaxFild);
		(void)Rte_Write_MotVltgQaxFild_Val(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec.MotVltgQaxFild);
	}
}


/**********************************************************************************************************************
  * Name:        MotCtrlMgrPer2
  * Description: This function copies all RTE data transferred by the DMA from the 2ms loop to the Motor Control loop 
  *              to the non-RTE structure the DMA references.  A DMA function is called at the end of processing to
  *              trigger the DMA transfer of the data.
  * Inputs:      Individual RTE inputs for all signals
  * Outputs:     MotCtrlMgr_TwoMilliSecToMotCtrl_Rec structure
  * Usage Notes: To be scheduled by the RTE at the end of the 2ms forward path after all critical forward path motor control
  *              signals have been calculated.
  ********************************************************************************************************************/
FUNC(void, CDD_MotCtrlMgr_CODE) MotCtrlMgrPer2(void)
{
	(void)Rte_Read_MotCurrEolCalSt_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrEolCalSt);
	(void)Rte_Read_BrdgVltg_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.BrdgVltg);
	(void)Rte_Read_DiagcStsIvtr1Inactv_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.DiagcStsIvtr1Inactv);
	(void)Rte_Read_DiagcStsIvtr2Inactv_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.DiagcStsIvtr2Inactv);
	(void)Rte_Read_MotElecMeclPolarity_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotElecMeclPolarity);
	(void)Rte_Read_MotVelMrf_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotVelMrf);
	(void)Rte_Read_SysSt_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.SysSt);
	(void)Rte_Read_MotAg0MeclRollgCntr_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg0MeclRollgCntr);
	(void)Rte_Read_EcuTFild_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.EcuTFild);
	(void)Rte_Read_CurrMeasCorrlnSts_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.CurrMeasCorrlnSts);
	(void)Rte_Read_MotAgMecl0Polarity_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAgMecl0Polarity);
	(void)Rte_Read_MotCurrQlfr1_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrQlfr1);
	(void)Rte_Read_MotCurrQlfr2_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrQlfr2);
	(void)Rte_Read_IvtrLoaMtgtnEna_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.IvtrLoaMtgtnEna);
	(void)Rte_Read_MotAgElecDly_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAgElecDly);
	(void)Rte_Read_MotCurrDaxCmd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrDaxCmd);
	(void)Rte_Read_MotCurrDaxMax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrDaxMax);
	(void)Rte_Read_CurrMeasLoaMtgtnEna_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.CurrMeasLoaMtgtnEna);
	(void)Rte_Read_MotCurrQaxCmd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrQaxCmd);
	(void)Rte_Read_MotDampgDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotDampgDax);
	(void)Rte_Read_MotDampgQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotDampgQax);
	(void)Rte_Read_MotIntglGainDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotIntglGainDax);
	(void)Rte_Read_MotIntglGainQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotIntglGainQax);
	(void)Rte_Read_MotPropGainDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotPropGainDax);
	(void)Rte_Read_MotPropGainQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotPropGainQax);
	(void)Rte_Read_MotReacncDax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotReacncDax);
	(void)Rte_Read_MotReacncQax_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotReacncQax);
	(void)Rte_Read_MotVltgDaxFf_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotVltgDaxFf);
	(void)Rte_Read_MotVltgQaxFf_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotVltgQaxFf);
	(void)Rte_Read_MotAgMecl1Polarity_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAgMecl1Polarity);
	(void)Rte_Read_MotAg1MeclRollgCntr_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg1MeclRollgCntr);
	(void)Rte_Read_MotAgMeclCorrlnSt_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAgMeclCorrlnSt);
	(void)Rte_Read_MotAg0MeclQlfr_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg0MeclQlfr);
	(void)Rte_Read_MotAg1MeclQlfr_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg1MeclQlfr);
	(void)Rte_Read_CurrMeasWrmIninTestCmpl_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.CurrMeasWrmIninTestCmpl);
	(void)Rte_Read_MotAgElecDlyRpl_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAgElecDlyRpl);
	(void)Rte_Read_MotCurrQaxToMotTqGain_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrQaxToMotTqGain);
	(void)Rte_Read_MotTqRplCoggOrder1Mgn_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotTqRplCoggOrder1Mgn);
	(void)Rte_Read_MotTqRplCoggOrder1Pha_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotTqRplCoggOrder1Pha);
	(void)Rte_Read_MotTqRplCoggOrder2Mgn_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotTqRplCoggOrder2Mgn);
	(void)Rte_Read_MotTqRplCoggOrder2Pha_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotTqRplCoggOrder2Pha);
	(void)Rte_Read_MotTqRplCoggOrder3Mgn_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotTqRplCoggOrder3Mgn);
	(void)Rte_Read_MotTqRplCoggOrder3Pha_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotTqRplCoggOrder3Pha);
	(void)Rte_Read_MotCurrAdcVlyAAdcFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrAdcVlyAAdcFaild);
	(void)Rte_Read_MotCurrAdcVlyBAdcFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrAdcVlyBAdcFaild);
	(void)Rte_Read_MotCurrAdcVlyCAdcFaild_Logl(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotCurrAdcVlyCAdcFaild);
	(void)Rte_Read_LoopCntr2MilliSec_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.LoopCntr2MilliSec);
	(void)Rte_Read_AdcDiagcStrtPtrOutp_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.AdcDiagcStrtPtrOutp);
	(void)Rte_Read_AdcDiagcEndPtrOutp_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.AdcDiagcEndPtrOutp);
	(void)Rte_Read_MotREstimd_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotREstimd);
	(void)Rte_Read_MotAg0Offs_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg0Offs);
	(void)Rte_Read_MotAg1Offs_Val(&MotCtrlMgr_TwoMilliSecToMotCtrl_Rec.MotAg1Offs);

	(void)Rte_Call_DmaEna2MilliSecToMotCtrlTrf_Oper();
}

#define CDD_MotCtrlMgr_STOP_SEC_CODE
#include "CDD_MotCtrlMgr_MemMap.h"
