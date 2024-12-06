/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  ElecPwrCns.c
 *     SW-C Type:  ElecPwrCns
 *  Generated at:  Tue May 10 10:43:52 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <ElecPwrCns>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : ElecPwrCns.c
* Module Description: Implementation of Electric Power Consumption SF109A
* Project           : CBD 
* Author            : Krishna Anne
***********************************************************************************************************************
* Version Control 	:
* %version          : 1 %
* %derived_by       : nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author       Change Description                       	                                    SCR #
* -------   -------  --------  -----------------------------------------------------------------------------  ---------
* 05/10/16  1        VM(TATA)     Initial Version                                                      		   EA4#5246    
***********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_ElecPwrCns.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "ArchGlbPrm.h"
#include "NxtrMath.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]:AUTOSAR requires deviation from this rule for Memory Mapping include statements*/

#define ELECINPPWRESTIMLOLIM_WATT_F32   (-2000.0F)
#define ELECINPPWRESTIMHILIM_WATT_F32   (2000.0F)
#define SPLYCURRESTIMLOLIM_AMPR_F32     (-200.0F)
#define SPLYCURRESTIMHILIM_AMPR_F32     (200.0F)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   float32 *Rte_Pim_dElecPwrCnsDrpInpPwr(void)
 *   float32 *Rte_Pim_dElecPwrCnsModInpPwr(void)
 *   float32 *Rte_Pim_dElecPwrCnsMotCurrDaxEstim(void)
 *   float32 *Rte_Pim_dElecPwrCnsMotCurrQaxEstim(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   float32 Rte_Prm_ElecPwrCnsCtrlrInpR_Val(void)
 *   float32 Rte_Prm_ElecPwrCnsPrstcPwrLoss_Val(void)
 *
 *********************************************************************************************************************/


#define ElecPwrCns_START_SEC_CODE
#include "ElecPwrCns_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ElecPwrCnsPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BrdgVltg_Val(float32 *data)
 *   Std_ReturnType Rte_Read_CurrMeasLoaMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_IvtrLoaMtgtnEna_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotCtrlMotCurrDax_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCtrlMotCurrQax_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCtrlMotVltgDax_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCtrlMotVltgQax_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrDaxCmd_Val(float32 *data)
 *   Std_ReturnType Rte_Read_MotCurrQaxCmd_Val(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ElecInpPwrEstim_Val(float32 data)
 *   Std_ReturnType Rte_Write_SplyCurrEstim_Val(float32 data)
 *
 *********************************************************************************************************************/

FUNC(void, ElecPwrCns_CODE) ElecPwrCnsPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ElecPwrCnsPer1
 *********************************************************************************************************************/
    VAR(float32, AUTOMATIC) BrdgVltg_Volt_T_f32;
	VAR(float32, AUTOMATIC) MotCtrlMotCurrDax_Ampr_T_f32;
	VAR(float32, AUTOMATIC) MotCtrlMotCurrQax_Ampr_T_f32;
	VAR(float32, AUTOMATIC) MotCtrlMotVltgDax_Volt_T_f32;
	VAR(float32, AUTOMATIC) MotCtrlMotVltgQax_Volt_T_f32;
	VAR(float32, AUTOMATIC) MotCurrDaxCmd_Ampr_T_f32;
	VAR(float32, AUTOMATIC) MotCurrQaxCmd_Ampr_T_f32;
	VAR(float32, AUTOMATIC) MotCurrQaxEstimd_Ampr_T_f32;
	VAR(float32, AUTOMATIC) ModInpPower_Watt_T_f32;
	VAR(float32, AUTOMATIC) DrpInpPwr_Watt_T_f32;
	VAR(float32, AUTOMATIC) SplyCurrEstim_Ampr_T_f32;
	VAR(float32, AUTOMATIC) ElecInpPwrEstim_Watt_T_f32;
	VAR(float32, AUTOMATIC) MotCurrDaxEstimd_Ampr_T_f32;
	VAR(float32, AUTOMATIC) ModInpBrdgCurr_Ampr_T_f32;
	
    VAR(boolean, AUTOMATIC) CurrMeasLoaMtgtnEna_Cnt_T_logl;
	VAR(boolean, AUTOMATIC) IvtrLoaMtgtnEna_Cnt_T_logl;
 
    /* REQ: SF109A #58 I */ /* REQ: SF109A #73 I */ /* REQ: SF109A #72 I */
    /*** Reading Inputs From RTE ***/
    (void)Rte_Read_BrdgVltg_Val(&BrdgVltg_Volt_T_f32);							/* REQ: SF109A #9 I */   
    (void)Rte_Read_CurrMeasLoaMtgtnEna_Logl(&CurrMeasLoaMtgtnEna_Cnt_T_logl);	/* REQ: SF109A #67 I */
    (void)Rte_Read_IvtrLoaMtgtnEna_Logl(&IvtrLoaMtgtnEna_Cnt_T_logl);			/* REQ: SF109A #66 I */
    (void)Rte_Read_MotCtrlMotCurrDax_Val(&MotCtrlMotCurrDax_Ampr_T_f32);		/* REQ: SF109A #35 I */ 
    (void)Rte_Read_MotCtrlMotCurrQax_Val(&MotCtrlMotCurrQax_Ampr_T_f32);		/* REQ: SF109A #34 I */
    (void)Rte_Read_MotCtrlMotVltgDax_Val(&MotCtrlMotVltgDax_Volt_T_f32);		/* REQ: SF109A #33 I */
    (void)Rte_Read_MotCtrlMotVltgQax_Val(&MotCtrlMotVltgQax_Volt_T_f32);		/* REQ: SF109A #32 I */
    (void)Rte_Read_MotCurrDaxCmd_Val(&MotCurrDaxCmd_Ampr_T_f32);				/* REQ: SF109A #68 I */
    (void)Rte_Read_MotCurrQaxCmd_Val(&MotCurrQaxCmd_Ampr_T_f32);				/* REQ: SF109A #65 I */
	
    /* REQ: SF109A #59 I */
	/*** Start of CalcInpSelnDueToLoaFlt ***/	
	if( (TRUE == CurrMeasLoaMtgtnEna_Cnt_T_logl) || (TRUE == IvtrLoaMtgtnEna_Cnt_T_logl) )
	{
		MotCurrQaxEstimd_Ampr_T_f32       = MotCurrQaxCmd_Ampr_T_f32;
		MotCurrDaxEstimd_Ampr_T_f32       = MotCurrDaxCmd_Ampr_T_f32;
	}
	else
	{
		MotCurrQaxEstimd_Ampr_T_f32       = MotCtrlMotCurrQax_Ampr_T_f32;
		MotCurrDaxEstimd_Ampr_T_f32       = MotCtrlMotCurrDax_Ampr_T_f32;
	}
	*Rte_Pim_dElecPwrCnsMotCurrQaxEstim() = MotCurrQaxEstimd_Ampr_T_f32;
	*Rte_Pim_dElecPwrCnsMotCurrDaxEstim() = MotCurrDaxEstimd_Ampr_T_f32;
	/*** End of CalcInpSelnDueToLoaFlt ***/
    /* ENDREQ: SF109A #59  */
	
	/* REQ: SF109A #60 I */
    /*** Start of CalcModInpPwr ***/
	ModInpPower_Watt_T_f32                = ( (MotCtrlMotVltgDax_Volt_T_f32 * MotCurrDaxEstimd_Ampr_T_f32) + 
											  (MotCtrlMotVltgQax_Volt_T_f32 * MotCurrQaxEstimd_Ampr_T_f32) ) * 
											ARCHGLBPRM_HALFSQRT3_ULS_F32 ;
	*Rte_Pim_dElecPwrCnsModInpPwr()       = ModInpPower_Watt_T_f32 ;
	/*** End  of CalcModInpPwr ***/
    /* ENDREQ: SF109A #60  */
	
    /* REQ: SF109A #44 I */ /* REQ: SF109A #61 I */
    /*** Start of CalcDrpInpPwr ***/
	ModInpBrdgCurr_Ampr_T_f32             = (ModInpPower_Watt_T_f32 / BrdgVltg_Volt_T_f32);
	DrpInpPwr_Watt_T_f32                  = (ModInpBrdgCurr_Ampr_T_f32 * ModInpBrdgCurr_Ampr_T_f32 * Rte_Prm_ElecPwrCnsCtrlrInpR_Val());
	*Rte_Pim_dElecPwrCnsDrpInpPwr()       = DrpInpPwr_Watt_T_f32 ;
    /*** End of CalcDrpInpPwr ***/
    /* ENDREQ: SF109A #44  */
	
	/* REQ: SF109A #49 I *//* REQ: SF109A #62 I *//* REQ: SF109A #63 I */
    /*** Start of CalcElecInpPwrEstim ***/	
	ElecInpPwrEstim_Watt_T_f32            = Lim_f32( (ModInpPower_Watt_T_f32 + Rte_Prm_ElecPwrCnsPrstcPwrLoss_Val() + DrpInpPwr_Watt_T_f32),
                                                     ELECINPPWRESTIMLOLIM_WATT_F32, ELECINPPWRESTIMHILIM_WATT_F32);	
	/*** End of CalcElecInpPwrEstim ***/
    /* ENDREQ: SF109A #49  */
	
	/* REQ: SF109A #70 I */
    /*** Start of CalcSplyCurrEstim ***/	
	SplyCurrEstim_Ampr_T_f32              = Lim_f32( (ElecInpPwrEstim_Watt_T_f32 / BrdgVltg_Volt_T_f32 ),
                                                      SPLYCURRESTIMLOLIM_AMPR_F32, SPLYCURRESTIMHILIM_AMPR_F32);									
	/*** End of CalcSplyCurrEstim ***/
    /* REQ: SF109A #70 I */
	
	/*** Writing outputs to RTE ***/
    (void)Rte_Write_ElecInpPwrEstim_Val(ElecInpPwrEstim_Watt_T_f32);			/* REQ: SF109A #11 I */
    (void)Rte_Write_SplyCurrEstim_Val(SplyCurrEstim_Ampr_T_f32);				/* REQ: SF109A #36 I */
    
    /* ENDREQ: SF109A #58  *//* ENDREQ: SF109A #73  *//* ENDREQ: SF109A #72  */
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define ElecPwrCns_STOP_SEC_CODE
#include "ElecPwrCns_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
