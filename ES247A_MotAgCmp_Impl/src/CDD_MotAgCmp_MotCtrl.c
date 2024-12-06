/*****************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name: CDD_MotAgCmp_MotCtrl.c
* Module Description: Motor Control Loop runnable(s) for Motor Angle Compensation
* Project           : CBD   
* Author            : Spandana Balani
*****************************************************************************
* Version Control:
* %version:          3 %
* %derived_by:       gzkys7 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/04/15  1        SB         Initial version                                                                 EA4#636
* 11/06/15  2        SB       	Updated to ES247A_MotAgCmp_Design_1.4.0 - modified MtrRev calc &                EA4#2415
								implemented overflow protection 
* 11/19/15  3        SB         Fix Anomaly EA4# 2515                                                           EA4#2557
**********************************************************************************************************************/

#include "Rte_CDD_MotAgCmp.h"
#include "CDD_MotAgCmp.h"
#include "CDD_MotCtrlMgr_Data.h"
#include "NxtrMath.h"

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define     MOTAGMAXDELTA_MOTREV_U0P16                  32768UL
#define     MOTAGCUMVALGNDMRFREVMASK_CNT_U32            0x3FFFFFFFUL    /* (1073741823UL) */

#define MotAgCmp_MotCtrl_START_SEC_CODE
#include "CDD_MotAgCmp_MotCtrl_MemMap.h" 

/******************************************************************************
  * Name:        MotAgCmpPer1
  * Description: MotAgCmp periodic processing in the motor control loop
  * Inputs:      see component's DataDict.m file     
  * Outputs:     see component's DataDict.m file 
  * Usage Notes: Called at Motor Control loop rate 
  ****************************************************************************/
FUNC (void, MotAgCmp_CODE) MotAgCmpPer1 (void) /* REQ: ES247A #75 I */
{   
    VAR(sint32, AUTOMATIC)  Delta1_MotRev_T_s15p16;
    VAR(sint32, AUTOMATIC)  Delta2_MotRev_T_s15p16;

    /* Compute corrected angle and limit to within one electrical rev */
    /* REQ: ES247A #83 I */ /* REQ: ES247A #67 I */
    MOTCTRLMGR_MotCtrlMotAgElec =  (uint16)(((uint16)((uint32)Rte_Prm_SysGlbPrmMotPoleCnt_Val() >> 1U) *    
                                    MOTCTRLMGR_MotCtrlMotAgMecl) - *Rte_Pim_MotAgCmpMotAgBackEmf());                /* REQ: ES247A #53 I */ 
                                                                                                                    /* REQ: ES247A #48 I */ 
                                                                                                                    /* REQ: ES247A #51 I */
	/* ENDREQ: ES247A #83 I */ /* ENDREQ: ES247A #67 I */
                                                                            
    /* Calculate MotCtrlMotAgCumvAlgndMrfRev */ 
    /* REQ: ES247A #69 I */ /* REQ: ES247A #80 I */ /* REQ: ES247A #83 I */     
    Delta1_MotRev_T_s15p16 = (sint32)MOTCTRLMGR_MotCtrlMotAgMecl - *Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev();     /* REQ: ES247A #48 I */
    if(*Rte_Pim_MotAgCmpFirstRunCmpl() == FALSE)
    {
        Delta1_MotRev_T_s15p16 = (sint32)MOTCTRLMGR_MotCtrlMotAgMecl;  /* REQ: ES247A #48 I */
    }
    else if(Delta1_MotRev_T_s15p16 > (sint32)MOTAGMAXDELTA_MOTREV_U0P16)     
    {
        Delta1_MotRev_T_s15p16 = Delta1_MotRev_T_s15p16 - (2*(sint32)MOTAGMAXDELTA_MOTREV_U0P16); 
    }
    else if(Delta1_MotRev_T_s15p16 < ((-1) * (sint32)MOTAGMAXDELTA_MOTREV_U0P16))
    {       
        Delta1_MotRev_T_s15p16 = Delta1_MotRev_T_s15p16 + (2*(sint32)MOTAGMAXDELTA_MOTREV_U0P16);     
    }
    else{}          
    Delta2_MotRev_T_s15p16 = Delta1_MotRev_T_s15p16 + *Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevSVPrev();
    
    MOTCTRLMGR_MotCtrlMotAgCumvAlgndMrfRev = (sint32)Sign_s08_s32(Delta2_MotRev_T_s15p16) *                                  
                                             (sint32)(uint32)(Abslt_u32_s32(Delta2_MotRev_T_s15p16) & MOTAGCUMVALGNDMRFREVMASK_CNT_U32); 
                                                                                                                                /* REQ: ES247A #52 I */
    /* ENDREQ: ES247A #69 I */ /* ENDREQ: ES247A #80 I */ /* ENDREQ: ES247A #83 I */                                        
    
    *Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevSVPrev() = MOTCTRLMGR_MotCtrlMotAgCumvAlgndMrfRev;                              /* REQ: ES247A #69 I */
                
    *Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev() = (sint32)MOTCTRLMGR_MotCtrlMotAgMecl;                                              /* REQ: ES247A #48 I */
    *Rte_Pim_MotAgCmpFirstRunCmpl() = TRUE;
     
}/* ENDREQ: ES247A #75 I */ 
    
#define MotAgCmp_MotCtrl_STOP_SEC_CODE
#include "CDD_MotAgCmp_MotCtrl_MemMap.h" 

