/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : MotAgArbn_MotCtrl_MemMap.h
* Module Description: Motor Angle Arbitration Motor Control MemMap
* Project           : CBD
* Author            : Matthew Leser
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz2796 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/16/16	1   	 ML			Initial version							                                    	EA4#7269
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


#ifdef MotAgArbn_MotCtrl_START_SEC_CODE
    # undef MotAgArbn_MotCtrl_START_SEC_CODE
	#define MotCtrl_START_SEC_CODE
	#include "MemMap.h"	
#endif

#ifdef MotAgArbn_MotCtrl_STOP_SEC_CODE
    # undef MotAgArbn_MotCtrl_STOP_SEC_CODE
	#define MotCtrl_STOP_SEC_CODE
	#include "MemMap.h"
#endif


