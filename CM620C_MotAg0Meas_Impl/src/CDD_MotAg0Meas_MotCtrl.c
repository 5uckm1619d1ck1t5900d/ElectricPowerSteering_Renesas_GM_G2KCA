/*****************************************************************************
* Copyright 2016, 2017 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotAg0Meas_MotCtrl.c
* Module Description: Motor Control Loop runnable(s) for Measurement function of Motor Angle 0.  
*                     This function includes configuration and use of the CSIH1 peripheral.
* Project           : CBD   
* Author            : Avinash James
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/26/16  1        AJM       Initial Version                                                                 EA4#7471  
* 01/25/17  2        AJM       Updated to design version 1.6.0                                                 EA4#9379
******************************************************************************/

#include "Rte_CDD_MotAg0Meas.h"  
#include "CDD_MotAg0Meas_private.h" 
#include "CDD_MotAg0Meas.h"      
#include "CDD_MotCtrlMgr_Data.h"
#include "CDD_NxtrTi.h"  
#include "CDD_MotAg3Meas.h"
#include "NxtrMath.h"


/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.2]: Per Instance Memory pointers to array base types are cast back to their array type for code readability and to allow use of "sizeof". */


 
#define  MOTAGDELTAPERCORRNPT_CNT_U16		((uint16)512U)  
#define  MOTAGIDXMASK_CNT_U16  				((uint16)65024U) 

#define CDD_MotAg0Meas_MotCtrl_START_SEC_CODE
#include "CDD_MotAg0Meas_MotCtrl_MemMap.h" 

/******************************************************************************
  * Name:        MotAg0MeasPer1
  * Description: MotAg0Meas component periodic processing in the motor control loop
  * Inputs:      see component's DataDict.m file     
  * Outputs:     see component's DataDict.m file 
  * Usage Notes: Called at Motor Control loop rate 
  ****************************************************************************/
FUNC (void, CDD_MotAg0Meas_CODE) MotAg0MeasPer1 (void)
{
	/* Temporary variables */
	VAR(sint32, AUTOMATIC)  MotAg0OffsCorrd_Cnt_T_s32;
	VAR(uint16, AUTOMATIC)  MotAg0OffsCorrd_Cnt_T_u16;
	VAR(u0p16, AUTOMATIC)   MotAg3RawMecl_Cnt_T_u0p16;
	VAR(uint16, AUTOMATIC)  MotAg0Gain_Uls_T_u16;
	VAR(sint32, AUTOMATIC)  MotAg0Cmp_Cnt_T_s32;
	VAR(sint8,  AUTOMATIC)  MotAg0CorrnA_MotRev_T_sm5p12;
	VAR(sint8,  AUTOMATIC)  MotAg0CorrnB_MotRev_T_sm5p12;
	VAR(u0p16, AUTOMATIC)  MotCtrlMotAg0Mecl_MotRev_T_u0p16;
	
	/* Write module o/p */
	GetRefTmr1MicroSec32bit_Oper( &MOTCTRLMGR_MotCtrlMotAgMeasTi ); 
	
	/* Read module i/p */
	GetMotAg3Mecl_Oper(&MotAg3RawMecl_Cnt_T_u0p16);
	*Rte_Pim_dMotAg0MeasMotCtrlMotAg3Mecl() = MotAg3RawMecl_Cnt_T_u0p16;
	
	MotAg0OffsCorrd_Cnt_T_s32 = ((sint32)MotAg3RawMecl_Cnt_T_u0p16 - MOTCTRLMGR_MotCtrlMotAg0Offs);
	/* Roll-over and typecasting from sign to unsigned is intentional here */
	MotAg0OffsCorrd_Cnt_T_u16 = (uint16)(MotAg0OffsCorrd_Cnt_T_s32);
	
	/***** -------------------- START: Compensate MechMtrPos --------------------- *****/
	/* Masking is redundant, but used to match the design */
	
	MotAg0Gain_Uls_T_u16 = (MotAg0OffsCorrd_Cnt_T_u16 - (MotAg0OffsCorrd_Cnt_T_u16 & MOTAGIDXMASK_CNT_U16)) >> 5U;
	MotAg0CorrnA_MotRev_T_sm5p12 = PimMotAg0CorrnTbl[(MotAg0OffsCorrd_Cnt_T_u16 >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
	MotAg0CorrnB_MotRev_T_sm5p12 = PimMotAg0CorrnTbl[((MotAg0OffsCorrd_Cnt_T_u16 + MOTAGDELTAPERCORRNPT_CNT_U16) >> 9U) & CORRNTBLSIZEMASK_CNT_U08];
	
	MotAg0Cmp_Cnt_T_s32 =  (((sint32)MotAg0CorrnB_MotRev_T_sm5p12 - (sint32)MotAg0CorrnA_MotRev_T_sm5p12) * (sint32)MotAg0Gain_Uls_T_u16) + (sint32)(uint32)((uint32)MotAg0CorrnA_MotRev_T_sm5p12 << 4U);

	/* Roll-over and typecasting from sign to unsigned is intentional here */
	MotCtrlMotAg0Mecl_MotRev_T_u0p16 = (u0p16)(MotAg0OffsCorrd_Cnt_T_u16 - (uint16)MotAg0Cmp_Cnt_T_s32);
	
	/***** -------------------- END  : Compensate MechMtrPos --------------------- *****/

	/* Write module o/p */
	MOTCTRLMGR_MotCtrlMotAg0Mecl = MotCtrlMotAg0Mecl_MotRev_T_u0p16;
	*Rte_Pim_MotAg0Diagc() = MotCtrlMotAg0Mecl_MotRev_T_u0p16;

}	
	
#define CDD_MotAg0Meas_MotCtrl_STOP_SEC_CODE
#include "CDD_MotAg0Meas_MotCtrl_MemMap.h"  

