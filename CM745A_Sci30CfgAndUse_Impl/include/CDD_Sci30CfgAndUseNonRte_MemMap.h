/**********************************************************************************************************************
* Copyright 2017 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_Sci30CfgAndUseNonRte_MemMap.h
* Module Description: Sci30CfgAndUse component DmaWrite MemMap
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 01/19/17	1   	 AJM			Initial version							                                   EA4#8022
**********************************************************************************************************************/

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 19.6 [NXTRDEV 19.6.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/* MISRA-C:2004 Rule 19.15 [NXTRDEV 19.15.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#ifdef CDD_Sci30CfgAndUse_START_SEC_VAR_INIT_128
	/* Use GreenHills pragma for ensuring proper memory alignment (128bit) on DMA structures  */
	#pragma alignvar (16)
	#undef CDD_Sci30CfgAndUse_START_SEC_VAR_INIT_128
	#define CDD_Sci30CfgAndUse_START_SEC_VAR_INIT_UNSPECIFIED
	#include "CDD_Sci30CfgAndUse_MemMap.h"
#elif defined CDD_Sci30CfgAndUse_STOP_SEC_VAR_INIT_128
	#undef CDD_Sci30CfgAndUse_STOP_SEC_VAR_INIT_128
	#define CDD_Sci30CfgAndUse_STOP_SEC_VAR_INIT_UNSPECIFIED
	#include "CDD_Sci30CfgAndUse_MemMap.h"
	
#elif defined CDD_Sci30CfgAndUse_DmaWrite_START_SEC_VAR_INIT_128
	/* Use GreenHills pragma for ensuring proper memory alignment (128bit) on DMA structures  */
	#pragma alignvar (16)
	/* Use GreenHills pragma for ensuring proper memory section allocation for DMA structures that need DMA write access  */
	#pragma ghs section data=".data_dma_128"
	#undef CDD_Sci30CfgAndUse_DmaWrite_START_SEC_VAR_INIT_128
	#undef MEMMAP_ERROR
#elif defined CDD_Sci30CfgAndUse_DmaWrite_STOP_SEC_VAR_INIT_128
	/* Use GreenHills pragma to restore default memory section allocation  */
	#pragma ghs section data=default
	#undef CDD_Sci30CfgAndUse_DmaWrite_STOP_SEC_VAR_INIT_128
	#undef MEMMAP_ERROR
#endif
