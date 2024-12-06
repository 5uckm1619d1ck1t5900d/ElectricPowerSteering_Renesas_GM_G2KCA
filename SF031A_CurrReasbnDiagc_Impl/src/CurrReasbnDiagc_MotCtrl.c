/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CurrReasbnDiagc_MotCtrl.c
 *     SW-C Type:  CurrReasbnDiagc
 *  Generated at:  Tue Nov 29 14:26:38 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CurrReasbnDiagc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CurrReasbnDiagc_MotCtrl.c
* Module Description: Implementation of Current Reasonableness Diagnostic
* Project           : CBD 
* Author            : Krishna Anne
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz4qtt %
*--------------------------------------------------------------------------------------------------------------------
* Date        Rev     Author    Change Description                                                            SCR #
* -------   -------  --------  ---------------------------------------------------------------------------   --------
* 12/19/16     1       KK       Initial Version                                                              EA4#8123
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CurrReasbnDiagc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrMath.h"
#include "NxtrFil.h"
#include "ElecGlbPrm.h"
#include "MotCtrlMgr_Data.h"

/* MISRA-C:2004 Rule 1.1  [NXTRDEV 1.1.2]: Inline functions are used for functions called from Motor Control ISR to allow for throughput optimization */
/* MISRA-C:2004 Rule 8.8  [NXTRDEV 8.8.1]: Deviation allowed for functions CurrReasbnDiagcInit1() and CurrReasbnDiagcPer1, 
										   required to be declared in two headers to be accessible via the RTE as well as outside of the RTE. */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define MOTVLTGFILDDQAXLOLIM_VOLT_F32	(-26.5F)
#define MOTVLTGFILDDQAXHILIM_VOLT_F32	(26.5F)

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define CurrReasbnDiagc_MotCtrl_START_SEC_CODE
#include "CurrReasbnDiagc_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, CurrReasbnDiagc_CODE) CurrReasbnDiagcInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CurrReasbnDiagcInit1
 *********************************************************************************************************************/
 FilLpInit( 0.0F, Rte_Prm_CurrReasbnDiagcMotVltgDaxLpFilFrq_Val(), ELECGLBPRM_PWMPERDNOMX2_SEC_F32, Rte_Pim_MotVltgDaxLpFil() );
 FilLpInit( 0.0F, Rte_Prm_CurrReasbnDiagcMotVltgQaxLpFilFrq_Val(), ELECGLBPRM_PWMPERDNOMX2_SEC_F32, Rte_Pim_MotVltgQaxLpFil() );
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


FUNC(void, CurrReasbnDiagc_CODE) CurrReasbnDiagcPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CurrReasbnDiagcPer1
 *********************************************************************************************************************/
  
 if(Rte_Prm_CurrReasbnDiagcMotVltgQaxDaxFilEna_Logl() == TRUE)
 {
	MOTCTRLMGR_MotCtrlMotVltgDaxFild = Lim_f32((FilLpUpdOutp_f32(MOTCTRLMGR_MotCtrlMotVltgDax, Rte_Pim_MotVltgDaxLpFil())),
											   (MOTVLTGFILDDQAXLOLIM_VOLT_F32), 
											   (MOTVLTGFILDDQAXHILIM_VOLT_F32));
	
	MOTCTRLMGR_MotCtrlMotVltgQaxFild = Lim_f32((FilLpUpdOutp_f32(MOTCTRLMGR_MotCtrlMotVltgQax, Rte_Pim_MotVltgQaxLpFil())),
											   (MOTVLTGFILDDQAXLOLIM_VOLT_F32), 
											   (MOTVLTGFILDDQAXHILIM_VOLT_F32));
 }
 else
 {
	MOTCTRLMGR_MotCtrlMotVltgDaxFild = Lim_f32(MOTCTRLMGR_MotCtrlMotVltgDax, MOTVLTGFILDDQAXLOLIM_VOLT_F32, MOTVLTGFILDDQAXHILIM_VOLT_F32);
	MOTCTRLMGR_MotCtrlMotVltgQaxFild = Lim_f32(MOTCTRLMGR_MotCtrlMotVltgQax, MOTVLTGFILDDQAXLOLIM_VOLT_F32, MOTVLTGFILDDQAXHILIM_VOLT_F32);
 }
 
 
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CurrReasbnDiagc_MotCtrl_STOP_SEC_CODE
#include "CurrReasbnDiagc_MotCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
