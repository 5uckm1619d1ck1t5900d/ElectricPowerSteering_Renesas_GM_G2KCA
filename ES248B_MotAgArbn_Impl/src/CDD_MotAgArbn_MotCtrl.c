
/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotAgArbn_MotCtrl.c
* Module Description: Implementation of Motor Angle Arbitration FDD ES248B 
                       Motor Control Loop runnable(s) for Motor Angle Arbitration
* Project           : CBD
* Author            : Matthew Leser
***********************************************************************************************************************
* Version Control:
* %version:           1 %
* %derived_by:        nz2796 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                             SCR #
* --------  -------  --------  -----------------------------------------------------------------------------  -------
* 11/15/16   1       ML        Initial version                                                                EA4#7269
**********************************************************************************************************************/

#include "Rte_CDD_MotAgArbn.h"
#include "CDD_MotAgArbn.h"
#include "CDD_MotCtrlMgr_Data.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define MAXSTALL_CNT_U08 			   200U
#define MAXSTALLCNTR_CNT_U08		   255U
#define CORRLNSTSMASKSIGA_CNT_U08      0x01u

#define MotAgArbn_MotCtrl_START_SEC_CODE
#include "CDD_MotAgArbn_MotCtrl_MemMap.h" 

static FUNC(boolean, MotAgArbn_CODE) SigAvlChkRev(uint8 SigCorrChk_Cnt_T_u08,
											   uint8 SigRollgCnt_Cnt_T_u08,
											   SigQlfr1 SigQlfr_Cnt_T_enum,
											   P2VAR(uint8, AUTOMATIC, MotAgArbn_APPL_VAR) LstRollgCnt_Cnt_T_u08,
											   P2VAR(uint8, AUTOMATIC, MotAgArbn_APPL_VAR) StallCnt_Cnt_T_u08);
											   

/**********************************************************************************************************************
  * Name        : MotAgArbnPer1
  * Description : MotAgArbn periodic processing in the motor control loop
  * Inputs      : MOTCTRLMGR_MotCtrlMotAgAMeclRollgCntr 
				  MOTCTRLMGR_MotCtrlMotAgAMecl
				  MOTCTRLMGR_MotCtrlMotAgAMeclQlfr
                  MOTCTRLMGR_MotCtrlMotAgMeclCorrlnSts
  * Outputs     : MOTCTRLMGR_MotCtrlMotAgMecl 
  * Usage Notes : Called at Motor Control loop rate 
  **********************************************************************************************************************/
FUNC (void, MotAgArbn_CODE) MotAgArbnPer1 (void)
{
	VAR(uint16, AUTOMATIC) 		MotCtrlMotAgAMecl_MotRev_T_u0p16;
	VAR(uint16, AUTOMATIC)		MotCtrlMotAgMecl_MotRev_T_u16;
	VAR(uint8, AUTOMATIC)		MotCtrlMotAgAMeclRollgCntr_Cnt_T_u08;
	VAR(uint8, AUTOMATIC)		MotCtrlMotAgMeclCorrlnSts_Cnt_T_u08;
	VAR(SigQlfr1, AUTOMATIC)	MotCtrlMotAgAMeclQlfr_Cnt_T_enum;
	VAR(boolean, AUTOMATIC)		MotAgASigAvl_Cnt_T_lgc;
	
	MotCtrlMotAgAMecl_MotRev_T_u0p16 		= MOTCTRLMGR_MotCtrlMotAgAMecl;
	MotCtrlMotAgAMeclRollgCntr_Cnt_T_u08 	= MOTCTRLMGR_MotCtrlMotAgAMeclRollgCntr;
	MotCtrlMotAgMeclCorrlnSts_Cnt_T_u08		= MOTCTRLMGR_MotCtrlMotAgMeclCorrlnSts;
	MotCtrlMotAgAMeclQlfr_Cnt_T_enum		= MOTCTRLMGR_MotCtrlMotAgAMeclQlfr;
	
	MotAgASigAvl_Cnt_T_lgc = SigAvlChkRev(MotCtrlMotAgMeclCorrlnSts_Cnt_T_u08 & CORRLNSTSMASKSIGA_CNT_U08,
										  MotCtrlMotAgAMeclRollgCntr_Cnt_T_u08,
										  MotCtrlMotAgAMeclQlfr_Cnt_T_enum,
										  Rte_Pim_MotAgARollgCntPrev(),
										  Rte_Pim_MotAgAStallCntPrev());
										  
	/*****MotAg0Selection*****/
	if (MotAgASigAvl_Cnt_T_lgc == TRUE)
	{
		MotCtrlMotAgMecl_MotRev_T_u16 = MotCtrlMotAgAMecl_MotRev_T_u0p16;
	}
	else
	{
		MotCtrlMotAgMecl_MotRev_T_u16 = *Rte_Pim_MotAgMeclPrev();
	}
	
	*Rte_Pim_MotAgMeclPrev() = MotCtrlMotAgMecl_MotRev_T_u16;
	MOTCTRLMGR_MotCtrlMotAgMecl = MotCtrlMotAgMecl_MotRev_T_u16;
}

/**********************************************************************************************************************
* Name:             SigAvlChkRev
* Description:      Check availability of the signal based on 'RollingCounter', 'StallCounter' and 'SignalQualifier'.
* Inputs:			SigCorrChk_Cnt_T_u08
					SigRollgCnt_Cnt_T_u08
					SigQlfr_Cnt_T_enum
* Inputs/Outputs:   *LstRollgCnt_Cnt_T_u08
					*StallCnt_Cnt_T_u08
* Outputs:          SigAvl_Cnt_T_lgc
* Usage Notes:      None
**********************************************************************************************************************/
static FUNC(boolean, MotAgArbn_CODE) SigAvlChkRev(uint8 SigCorrChk_Cnt_T_u08,
											   uint8 SigRollgCnt_Cnt_T_u08,
											   SigQlfr1 SigQlfr_Cnt_T_enum,
											   P2VAR(uint8, AUTOMATIC, MotAgArbn_APPL_VAR) LstRollgCnt_Cnt_T_u08,
											   P2VAR(uint8, AUTOMATIC, MotAgArbn_APPL_VAR) StallCnt_Cnt_T_u08)
{																					   
	VAR(boolean, AUTOMATIC) SigAvl_Cnt_T_lgc;
	
	if (SigRollgCnt_Cnt_T_u08 == *LstRollgCnt_Cnt_T_u08)
	{
		if (*StallCnt_Cnt_T_u08 < MAXSTALLCNTR_CNT_U08)
		{
			*StallCnt_Cnt_T_u08 = *StallCnt_Cnt_T_u08 + 1U;
		}
	}
	else
	{
		*StallCnt_Cnt_T_u08 = 0U;
	}
	
	*LstRollgCnt_Cnt_T_u08 = SigRollgCnt_Cnt_T_u08;
	
	if (*StallCnt_Cnt_T_u08 >= MAXSTALL_CNT_U08)
	{
		SigAvl_Cnt_T_lgc = FALSE;
	}
	else
	{
		if ((SigQlfr_Cnt_T_enum < SIGQLFR_FAILD) && (SigCorrChk_Cnt_T_u08 > 0U))
		{
			SigAvl_Cnt_T_lgc = TRUE;
		}
		else
		{
			SigAvl_Cnt_T_lgc = FALSE;
		}
	}
	return SigAvl_Cnt_T_lgc;
}
    
#define MotAgArbn_MotCtrl_STOP_SEC_CODE
#include "CDD_MotAgArbn_MotCtrl_MemMap.h" 
