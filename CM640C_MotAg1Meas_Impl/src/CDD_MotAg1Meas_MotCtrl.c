/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotAg1Meas_MotCtrl.c
* Module Description: Motor Control Loop runnable(s) for Measurement function of Motor Angle 1.  
*                     This function includes configuration and use of the CSIH3 peripheral.
* Project           : CBD   
* Author            : Avinash James
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/01/16	1   	 AJM	   Initial version                                                                 EA4#7270
* 01/25/17  2        AJM       Updated to design version 1.5.0                                                 EA4#9381
******************************************************************************/

#include "Rte_CDD_MotAg1Meas.h"  
#include "CDD_MotAg1Meas_private.h" 
#include "CDD_MotAg1Meas.h"      
#include "CDD_MotCtrlMgr_Data.h"
#include "CDD_NxtrTi.h"  
#include "CDD_MotAg4Meas.h"
#include "NxtrMath.h"


/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.2]: Per Instance Memory pointers to array base types are cast back to their array type for code readability and to allow use of "sizeof". */


 
#define  MOTAGDELTAPERCORRNPT_CNT_U16		((uint16)512U)  
#define  MOTAGIDXMASK_CNT_U16  				((uint16)65024U) 

#define CDD_MotAg1Meas_MotCtrl_START_SEC_CODE
#include "CDD_MotAg1Meas_MotCtrl_MemMap.h" 

/******************************************************************************
  * Name:        MotAg1MeasPer1
  * Description: MotAg1Meas component periodic processing in the motor control loop
  * Inputs:      see component's DataDict.m file     
  * Outputs:     see component's DataDict.m file 
  * Usage Notes: Called at Motor Control loop rate 
  ****************************************************************************/
FUNC (void, CDD_MotAg1Meas_CODE) MotAg1MeasPer1 (void)
{
	/* Temporary variables */
	VAR(sint32, AUTOMATIC)  MotAg1OffsCorrd_Cnt_T_s32;
	VAR(uint16, AUTOMATIC)  MotAg1OffsCorrd_Cnt_T_u16;
	VAR(u0p16, AUTOMATIC)   MotAg4RawMecl_Cnt_T_u0p16;
	VAR(uint16, AUTOMATIC)  MotAg1Gain_Uls_T_u16;
	VAR(sint32, AUTOMATIC)  MotAg1Cmp_Cnt_T_s32;
	VAR(sint8,  AUTOMATIC)  MotAg1CorrnA_MotRev_T_sm5p12;
	VAR(sint8,  AUTOMATIC)  MotAg1CorrnB_MotRev_T_sm5p12;
	VAR(u0p16, AUTOMATIC)   MotCtrlMotAg1Mecl_MotRev_T_u0p16;
	
	/* Write module o/p */
	GetRefTmr1MicroSec32bit_Oper( &MOTCTRLMGR_MotCtrlMotAgMeasTi ); 
	
	/* Read module i/p */
	GetMotAg4Mecl_Oper(&MotAg4RawMecl_Cnt_T_u0p16);
	*Rte_Pim_dMotAg1MeasMotCtrlMotAg4Mecl() = MotAg4RawMecl_Cnt_T_u0p16;
	
	MotAg1OffsCorrd_Cnt_T_s32 = ((sint32)MotAg4RawMecl_Cnt_T_u0p16 - MOTCTRLMGR_MotCtrlMotAg1Offs);
	/* Roll-over and typecasting from sign to unsigned is intentional here */
	MotAg1OffsCorrd_Cnt_T_u16 = (uint16)(MotAg1OffsCorrd_Cnt_T_s32);
	
	/***** -------------------- START: Compensate MechMtrPos --------------------- *****/
	/* Masking is redundant, but used to match the design */
	
	MotAg1Gain_Uls_T_u16 = (MotAg1OffsCorrd_Cnt_T_u16 - (MotAg1OffsCorrd_Cnt_T_u16 & MOTAGIDXMASK_CNT_U16)) >> 5U;
	MotAg1CorrnA_MotRev_T_sm5p12 = PimMotAg1CorrnTbl[(MotAg1OffsCorrd_Cnt_T_u16 >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
	MotAg1CorrnB_MotRev_T_sm5p12 = PimMotAg1CorrnTbl[((MotAg1OffsCorrd_Cnt_T_u16 + MOTAGDELTAPERCORRNPT_CNT_U16) >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
	
	MotAg1Cmp_Cnt_T_s32 =  (((sint32)MotAg1CorrnB_MotRev_T_sm5p12 - (sint32)MotAg1CorrnA_MotRev_T_sm5p12) * (sint32)MotAg1Gain_Uls_T_u16) + (sint32)(uint32)((uint32)MotAg1CorrnA_MotRev_T_sm5p12 << 4U);
	
	/* Roll-over and typecasting from sign to unsigned is intentional here */
	MotCtrlMotAg1Mecl_MotRev_T_u0p16 = (u0p16)(MotAg1OffsCorrd_Cnt_T_u16 - (uint16)MotAg1Cmp_Cnt_T_s32 - Rte_Prm_MotAg1MeasMotAgOffs_Val());
	
	/***** -------------------- END  : Compensate MechMtrPos --------------------- *****/

	/* Write module o/p */
	MOTCTRLMGR_MotCtrlMotAg1Mecl = MotCtrlMotAg1Mecl_MotRev_T_u0p16;
	*Rte_Pim_MotAg1Diagc() = MotCtrlMotAg1Mecl_MotRev_T_u0p16;
}	
	
#define CDD_MotAg1Meas_MotCtrl_STOP_SEC_CODE
#include "CDD_MotAg1Meas_MotCtrl_MemMap.h"  

