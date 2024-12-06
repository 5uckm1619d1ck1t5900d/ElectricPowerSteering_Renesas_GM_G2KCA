/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2016 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: GM Global A / FR (MSR_Gm_SLP2)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701311
 *    License Scope : The usage is restricted to CBD1400351_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2016-01-13 16:51:40
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1400351_D03
 *      Tool Version: DaVinci Configurator (beta) 5.10.26 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
* Module File Name  : BswM_Callout_Stubs.c
* Module Description: BSWM Callout Functions
* Project           : GM T1xx
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          14 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/28/15  4        LWW       Added initial implementation of functions for shutdown processing               EA4#512
* 05/01/15  5        LWW       Added callout for CanStop processing                                            EA4#553
* 05/04/15  6        LWW       Changed NvM_MainFunction to trusted function for readall processing             EA4#569
* 05/08/15  7        LWW       Added trusted function call for WdgM_Init                                       EA4#580
* 05/19/15  8        LWW       Anomaly EA4#591 Correction                                                      EA4#616
* 06/23/15  9        LWW       Fixed NvM ReadAll Trusted Function calls                                        EA4#900
* 10/22/15  10       JWJ       Updates to SelectBootTarget function in support of Micro Diagnostics updates    EA4#2214
* 01/25/16  14       LWW       Updates for new vector BSW delivery                                             EA4#3191
* 01/28/16  15       JWJ       Update to support NvM Proxy CDD name changes                                    EA4#3615
* 02/29/16  16       JWJ       Added shutdown function for SoH to WriteAll function                            EA4#4026
* 03/11/16  17       JWJ       Updated the call to DiagMgr shutdown function to support ES101A version 2.0.0   EA4#4466
* 10/07/16  18       JWJ       Added call to NvM MultiBlkCallBack function before WriteAll                     EA4#7935
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"



/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "WdgIf.h"
#include "ram_regs.h"
#include "Os.h"
#include "osekext.h"
#include "CDD_NvMProxy.h"
#include "CDD_NvMProxy_Cbk.h"
#include "CDD_ExcpnHndlg.h"
#include "DiagcMgr.h"

/* TODO: This extern statement needs to be moved to StHlthSigStc.h */
extern FUNC(void, StHlthSigStc_CODE) StHlthStcPwrDwn_Oper(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

    NvM_RequestResultType MultiBlockStatus;

    NvM_ReadAll();
    
    do
    {
	 Call_NvM_MainFunction();
	 Fee_MainFunction();
	 Call_Fls_MainFunction();

	 NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &MultiBlockStatus);

    }
    while(MultiBlockStatus==NVM_REQ_PENDING);

	NvMProxy_Init0();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */


FUNC(void, BSWM_CODE) BswM_SHUTDOWN_NvMWriteAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_SHUTDOWN_NvMWriteAll>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    NvM_RequestResultType MultiBlockStatus;

	/* Anomaly EA4#591 Short Term Correction: Increase Watchdog reset timing and mask O/S Tick interrupt for shutdown processing.
	 *  This should be removed when a more robust shutdown processes is integrated as part of a longer term solution. */
    WdgIf_SetTriggerCondition(0U, 10000);
    osSetIMRmEI(74U);

	StHlthStcPwrDwn_Oper();
	(void)DiagcMgrPwrDwn();

	if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownStates) != BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_HARDRESET)
	{
		NvMProxy_MultiBlkCallBack(NVM_WRITE_ALL, NVM_REQ_PENDING);
		NvM_WriteAll();
		
		do
		{
		 NvM_MainFunction();
		 Fee_MainFunction();
		 Fls_MainFunction();

		 NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &MultiBlockStatus);

		}
		while(MultiBlockStatus==NVM_REQ_PENDING);
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_SHUTDOWN_NvMWriteAll */


FUNC(void, BSWM_CODE) BswM_WriteCloseCheck(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_WriteCloseCheck>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	NvM_RequestResultType ClsChkStatus;

	if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownStates) != BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_HARDRESET)
	{
		NvMProxy_ClsChkWr_Oper();

		do
		{
			NvM_MainFunction();
			Fee_MainFunction();
			Fls_MainFunction();

			NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_Rte_NvmBlock_NvMProxy_ShtdwnClsChk, &ClsChkStatus);

		} while(ClsChkStatus==NVM_REQ_PENDING);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_WriteCloseCheck */


FUNC(void, BSWM_CODE) BswM_CanStop(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_CanStop>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownStates) != BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_REPROGRAM)
  {
    (void)CallNonTrustedFunction(NtWrapS_CanStop, NULL_PTR);
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_CanStop */


FUNC(void, BSWM_CODE) BswM_SelectBootTarget(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_SelectBootTarget>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

	/* Check the source of request and call the appropriate functions as per the request source */
	if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownStates) == BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_REPROGRAM)
	{
		SetMcuDiagcIdnData(MCUDIAGC_FLSPROGMREQ, BRAMDAT1);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_SelectBootTarget */


FUNC(void, BSWM_CODE) BswM_ShtdwnHndlg_PrepShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ShtdwnHndlg_PrepShutdown>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownStates) == BSWM_GENERICVALUE_BswM_ShutdownStates_PREPSHUTDOWN_SWITCHOFF) 
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_OFF, 0);
        BswM_RequestMode(BSWM_GENERIC_BswM_ShutdownStates, BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_SWITCHOFF);
    }
    else if(BswM_GetGenericState(BSWM_GENERIC_BswM_ShutdownStates) == BSWM_GENERICVALUE_BswM_ShutdownStates_PREPSHUTDOWN_HARDRESET) 
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
        BswM_RequestMode(BSWM_GENERIC_BswM_ShutdownStates, BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_HARDRESET);
    }
    else
    {
        EcuM_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU);
        BswM_RequestMode(BSWM_GENERIC_BswM_ShutdownStates, BSWM_GENERICVALUE_BswM_ShutdownStates_GOOFFONE_REPROGRAM);    
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ShtdwnHndlg_PrepShutdown */


#define BSWM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


