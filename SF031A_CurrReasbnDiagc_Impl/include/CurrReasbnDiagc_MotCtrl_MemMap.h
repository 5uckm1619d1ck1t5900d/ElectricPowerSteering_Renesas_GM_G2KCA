/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CurrReasbnDiagc_MotCtrl_MemMap.h
* Module Description: Current Reasonableness Diagnostic
* Project           : CBD
* Author            : Krishna Anne
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz4qtt %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 12/19/16     1       KK       Initial Version                                                              EA4#8123
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#ifdef CurrReasbnDiagc_MotCtrl_START_SEC_CODE
    # undef CurrReasbnDiagc_MotCtrl_START_SEC_CODE
	#define MotCtrl_START_SEC_CODE
	#include "MemMap.h"	
#endif

#ifdef CurrReasbnDiagc_MotCtrl_STOP_SEC_CODE
    # undef CurrReasbnDiagc_MotCtrl_STOP_SEC_CODE
	#define MotCtrl_STOP_SEC_CODE
	#include "MemMap.h"
#endif


