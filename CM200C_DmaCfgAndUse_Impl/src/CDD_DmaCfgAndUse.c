/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_DmaCfgAndUse.c
 *     SW-C Type:  CDD_DmaCfgAndUse
 *  Generated at:  Tue Nov  8 16:08:16 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_DmaCfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name: CDD_DmaCfgAndUse.c
* Module Description: Configuration and use of the DMA 
* Project           : CBD   
* Author            : Avinash James
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/08/16	1   	 AJM			Initial version derived from CM200A baseline version 2.1.0                 EA4#7566
* 12/10/16  2        AJM            Added more micro diag test cases and corrected the define STD_ON           EA4#8877
******************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Rte_CDD_DmaCfgAndUse.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 #include "CDD_DmaCfgAndUse.h"
 #include "NxtrDmaRegs.h"
 #include "csih_regs.h"
 #include "adcd_regs.h"
 #include "tsg3_regs.h"
 #include "CDD_MotCtrlMgr_Data.h"
 #include "CDD_MotAg0Meas.h"
 #include "CDD_MotAg1Meas.h"
 #include "Os.h"
 #include "NxtrMath.h"
 #include "McuErrInj.h"
 
 /* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.1]	Cast of a register address to an integer type required for writing a register address to a register. */

 /* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.2]	Cast of a variable address to an integer type required for writing a variable address to a register. */
 
 /* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
 
 #define CPU1PEID_CNT_U32 					((uint32)0x01U)
 #define PRPHLTOLCLRAMSPID_CNT_U32			((uint32)0x03U)  			/* Peripheral to Local RAM SPID = 3U */
 #define LCLRAMTOPRPHLSPID_CNT_U32			((uint32)0x02U)  			/* Local RAM to Peripheral SPID = 2U */
 #define LCLRAMTOLCLRAMSPID_CNT_U32			((uint32)0x00U)  			/* Local RAM to Local RAM SPID = 0U */
  
 #define USRMODENA_CNT_U32					((uint32)0x1U)  			/* User Mode Bit : 1: User Mode Access Allowed */
 #define USRMODDI_CNT_U32					((uint32)0x0U)  			/* User Mode Bit : 0: Supervisor Mode access only */

 #define MAXWAIT_MICROSEC_U32       		((uint32)400U)
 #define INIZERO_CNT_U32					0U
 #if (MCUDIAGCERRINJ == STD_ON)
 #define ERRID2BBIT0CASE1_CNT_U32			(0x002B0101U)
 #define ERRID2BBIT1CASE1_CNT_U32			(0x002B0201U)
 #define ERRID36BIT0CASE1_CNT_U32			(0x00360101U)
 #define ERRID36BIT1CASE1_CNT_U32			(0x00360201U)
 #define ERRID36BIT1CASE2_CNT_U32			(0x00360202U)
 #endif
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
 *   uint32 *Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi(void)
 *   uint32 *Rte_Pim_d2MilliSecAdcActDmaTrfTi(void)
 *   uint32 *Rte_Pim_d2MilliSecAdcMaxDmaTrfTi(void)
 *
 *********************************************************************************************************************/


#define CDD_DmaCfgAndUse_START_SEC_CODE
#include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmaCfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaCfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaCfgAndUseInit1
 *********************************************************************************************************************/


	*Rte_Pim_d2MilliSecAdcActDmaTrfTi() = INIZERO_CNT_U32;
	*Rte_Pim_d2MilliSecAdcMaxDmaTrfTi() = INIZERO_CNT_U32;

	Call_DmaRegInin();
				
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmaCfgAndUsePer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_GetRefTmr1MicroSec32bit_Oper(uint32 *RefTmr)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaCfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaCfgAndUsePer1
 *********************************************************************************************************************/
	
	DMASSDRQC14 = 1U; /* Clear the Hardware DMA Transfer Request Flag */
	DMASSTCC14 = 1U; /* Clear Transfer Complete Flag */
	DMASSDTE14 = 1U; /* Channel Operation Enable */
	(void) Rte_Call_Adc1CfgAndUseAdc1EnaCnvn_Oper(); /* Enable ADC1 Hardware End of Conversion */
	(void) Rte_Call_GetRefTmr1MicroSec32bit_Oper(Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi()); /* Get Start Time */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmaEna2MilliSecToMotCtrlTrf_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <DmaEna2MilliSecToMotCtrlTrf>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DmaEna2MilliSecToMotCtrlTrf_Oper(void)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_DmaCfgAndUse_CODE) DmaEna2MilliSecToMotCtrlTrf_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaEna2MilliSecToMotCtrlTrf_Oper
 *********************************************************************************************************************/
#if (MCUDIAGCERRINJ == STD_ON)
	VAR (uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
#endif

	DMASSDTFR9 = 0U; /* Disable Hardware Trigger */
	DMASSDRQC9 = 1U; /* Clear the hardware DMA Transfer Request Flag */
	DMASSTCC9 = 1U; /* Clear Transfer Complete Flag */
	
#if (MCUDIAGCERRINJ == STD_ON)
	if(ErrId_Cnt_T_u32 == ERRID2BBIT1CASE1_CNT_U32)
	{
		/* Do nothing */
	}
	else
	{
#endif
		DMASSDTE9 = 1U; /* Channel Operation Enable */
		DMASSDTFR9 = 0xD5U; /* Hardware DMA Transfer */
 #if (MCUDIAGCERRINJ == STD_ON)
	}
 #endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DmaWaitForMotCtrlTo2MilliSecTrf_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <DmaWaitForMotCtrlTo2MilliSecTrf>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetTiSpan1MicroSec32bit_Oper(uint32 RefTmr, uint32 *TiSpan)
 *     Synchronous Server Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DmaWaitForMotCtrlTo2MilliSecTrf1_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) DmaWaitForMotCtrlTo2MilliSecTrf_Oper(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DmaWaitForMotCtrlTo2MilliSecTrf_Oper (returns application error)
 *********************************************************************************************************************/
	VAR (Std_ReturnType, AUTOMATIC) RetVal_T_StdType;
	VAR (uint32, AUTOMATIC) TiSpan_MicroSec_T_u32;
	
	/* In the while loop check Transfer Complete flag (RegInpDMASSTC17 ==1) for 100us  */
	do
	{
		(void) Rte_Call_GetTiSpan1MicroSec32bit_Oper(*Rte_Pim_DmaCfgAndUse2MilliSecAdcStrtTi(), &TiSpan_MicroSec_T_u32);
	}
	while ((TiSpan_MicroSec_T_u32 < MAXWAIT_MICROSEC_U32) && (DMASSTC15 != 1U));
	
	/* If time expired */
	if (TiSpan_MicroSec_T_u32 >= MAXWAIT_MICROSEC_U32)
	{
		/* then return E_NOT_OK */
		RetVal_T_StdType = E_NOT_OK;
	}
	else
	{
		/* otherwise return E_OK & Clear Transfer Complete Flag */
		RetVal_T_StdType = E_OK;
		DMASSTCC15 = 1U;
	}
	
	*Rte_Pim_d2MilliSecAdcActDmaTrfTi() = TiSpan_MicroSec_T_u32;
	*Rte_Pim_d2MilliSecAdcMaxDmaTrfTi() = Max_u32(*Rte_Pim_d2MilliSecAdcMaxDmaTrfTi(),TiSpan_MicroSec_T_u32);

	return (RetVal_T_StdType);
	

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_DmaCfgAndUse_STOP_SEC_CODE
#include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define CDD_DmaCfgAndUse_START_SEC_CODE
#include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/******************************************************************************
  * Name:        DmaRegInin
  * Description: DMA Register Initialization
  * Inputs:      See CM200A_DmaCfgAndUse_Design FDD     
  * Outputs:     See CM200A_DmaCfgAndUse_Design FDD   
  * Usage Notes: To be configured as a trusted function because it needs to run in supervisor mode
  ****************************************************************************/
FUNC(void, CDD_DmaCfgAndUse_CODE) DmaRegInin(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
	
	/* DMASSDMxxCM registers can only be written in supervisor mode. 
	After the DMASSDMxxCM register is written for a given DMA channel, 
	that channel's registers can be written in user mode by the processor 
	element identified in the DMASSDMxxCM PEID field. For simplicity, all 
	DMA register initialization is done in this function.  */
	
	/* DMAC01 configuration */
	DMASSDM01CM = ((uint32)CPU1PEID_CNT_U32 << 4)
				| ((uint32)PRPHLTOLCLRAMSPID_CNT_U32 << 2)
				| ((uint32)USRMODDI_CNT_U32 << 1);
	DMASSDSA1 = (uint32)&(ADCD0DR00);
	DMASSDDA1 = (uint32)(&(MOTCTRLMGR_MotCtrlAdc0RawRes));
	DMASSDTC1 =   ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTCT1 = 	((uint32)0x00U << 27)
				|	((uint32)0x01U << 26)
				|	((uint32)0x00U << 18)
				|	((uint32)0x00U << 16)
				|	((uint32)0x00U << 15)
				|	((uint32)0x01U << 14)
				|	((uint32)0x01U << 13)
				|	((uint32)0x00U << 11)
				|	((uint32)0x03U << 9)
				|	((uint32)0x00U << 7)
				|	((uint32)0x00U << 5)
				|	((uint32)0x04U << 2)
				|	((uint32)0x01U << 0);
	DMASSDRSA1 = (uint32)&(ADCD0DR00);			
	DMASSDRDA1 = (uint32)(&(MOTCTRLMGR_MotCtrlAdc0RawRes));
	DMASSDRTC1 =  ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTFR1 =   ((uint32)58U << 1)
				|  ((uint32)1U << 0);
	DMASSDCEN1 = 	0x00000001U;
				
	/* DMAC03 configuration */
	DMASSDM03CM = ((uint32)CPU1PEID_CNT_U32 << 4)
				| ((uint32)LCLRAMTOPRPHLSPID_CNT_U32 << 2)
				| ((uint32)USRMODDI_CNT_U32 << 1);
	DMASSDSA3 =  (uint32)(&(MOTCTRLMGR_MotCtrlTSG31DCMP0E));
	DMASSDDA3 =  (uint32)&(TSG31DCMP0E);
	DMASSDTC3 =   ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTCT3 = 	((uint32)0x00U << 27)
				|	((uint32)0x01U << 26)
				|	((uint32)0x04U << 18)
				|	((uint32)0x01U << 16)
				|	((uint32)0x00U << 15)
				|	((uint32)0x00U << 14)
				|	((uint32)0x01U << 13)
				|	((uint32)0x00U << 11)
				|	((uint32)0x03U << 9)
				|	((uint32)0x00U << 7)
				|	((uint32)0x00U << 5)
				|	((uint32)0x02U << 2)
				|	((uint32)0x01U << 0);
	DMASSDRSA3 = (uint32)(&(MOTCTRLMGR_MotCtrlTSG31DCMP0E));			
	DMASSDRDA3 = (uint32)&(TSG31DCMP0E);
	DMASSDRTC3 =  ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTFR3 =   ((uint32)103U << 1)
				|  ((uint32)1U << 0);
	DMASSDCEN3 = 	0x00000001U;
				
	/* DMAC04 configuration */ 
	DMASSDM04CM = ((uint32)CPU1PEID_CNT_U32 << 4)
				| ((uint32)LCLRAMTOPRPHLSPID_CNT_U32 << 2)
				| ((uint32)USRMODDI_CNT_U32 << 1);
	DMASSDSA4 = (uint32)(&(MOTCTRLMGR_MotCtrlTSG31CMPWE));
	DMASSDDA4 = (uint32)&(TSG31CMPWE);
	DMASSDTC4 =   ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTCT4 = 	((uint32)0x00U << 27)
				|	((uint32)0x00U << 26)
				|	((uint32)0x00U << 18)
				|	((uint32)0x00U << 16)
				|	((uint32)0x00U << 15)
				|	((uint32)0x00U << 14)
				|	((uint32)0x01U << 13)
				|	((uint32)0x00U << 11)
				|	((uint32)0x03U << 9)
				|	((uint32)0x00U << 7)
				|	((uint32)0x00U << 5)
				|	((uint32)0x02U << 2)
				|	((uint32)0x01U << 0);
	DMASSDRSA4 = (uint32)(&(MOTCTRLMGR_MotCtrlTSG31CMPWE));			
	DMASSDRDA4 = (uint32)&(TSG31CMPWE);
	DMASSDRTC4 =  ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTFR4 =   ((uint32)0U << 1)
				|  ((uint32)0U << 0);
	DMASSDCEN4 = 	0x00000001U;
				
				
	/* DMAC11 aka channel 9 configuration */  
	DMASSDM11CM = ((uint32)CPU1PEID_CNT_U32 << 4)
				| ((uint32)LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
				| ((uint32)USRMODENA_CNT_U32 << 1);
	DMASSDSA9 = (uint32)(&(MotCtrlMgr_TwoMilliSecToMotCtrl_Rec));
	DMASSDDA9 = (uint32)(&(MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec));
	DMASSDTC9 =   ((uint32)0x00U << 16)
				| ((uint32)(sizeof(MotCtrlMgr_TwoMilliSecToMotCtrl_Rec)/16U) << 0); /* bytes in record divided by 16 bytes (= 128 bits) per transfer */
	DMASSDTCT9 = 	((uint32)0x00U << 27)
				|	((uint32)0x01U << 26)
				|	((uint32)0x00U << 18)
				|	((uint32)0x00U << 16)
				|	((uint32)0x00U << 15)
				|	((uint32)0x00U << 14)
				|	((uint32)0x00U << 13)
				|	((uint32)0x00U << 11)
				|	((uint32)0x03U << 9)
				|	((uint32)0x00U << 7)
				|	((uint32)0x00U << 5)
				|	((uint32)0x04U << 2)
				|	((uint32)0x01U << 0);
	DMASSDRSA9 = (uint32)(&(MotCtrlMgr_TwoMilliSecToMotCtrl_Rec));		
	DMASSDRDA9 = (uint32)(&(MotCtrlMgr_MotCtrlFromTwoMilliSec_Rec));
	DMASSDRTC9 =  ((uint32)0x00U << 16)
				| ((uint32)(sizeof(MotCtrlMgr_TwoMilliSecToMotCtrl_Rec)/16U) << 0); /* bytes in record divided by 16 bytes (= 128 bits) per transfer */
	DMASSDTFR9 =   ((uint32)106U << 1)
				|  ((uint32)1U << 0);
	DMASSDCEN9 = 	0x00000001U;
				

	/* DMAC16 aka channel 14 configuration */
	DMASSDM16CM = ((uint32)CPU1PEID_CNT_U32 << 4)
				| ((uint32)PRPHLTOLCLRAMSPID_CNT_U32 << 2)
				| ((uint32)USRMODENA_CNT_U32 << 1);
	DMASSDSA14 = (uint32)&(ADCD1DR00);
	DMASSDDA14 = (uint32)(&(MOTCTRLMGR_MotCtrlAdc1RawRes));
	DMASSDTC14 =  ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTCT14 = 	((uint32)0x00U << 27)
				|	((uint32)0x01U << 26)
				|	((uint32)0x07U << 18)
				|	((uint32)0x01U << 16)
				|	((uint32)0x00U << 15)
				|	((uint32)0x00U << 14)
				|	((uint32)0x00U << 13)
				|	((uint32)0x00U << 11)
				|	((uint32)0x03U << 9)
				|	((uint32)0x00U << 7)
				|	((uint32)0x00U << 5)
				|	((uint32)0x04U << 2)
				|	((uint32)0x01U << 0);
	DMASSDRSA14 = (uint32)&(ADCD1DR00);			
	DMASSDRDA14 = (uint32)(&(MOTCTRLMGR_MotCtrlAdc1RawRes));
	DMASSDRTC14 = ((uint32)0x00U << 16)
				| ((uint32)0x03U << 0);
	DMASSDTFR14 =  ((uint32)61U << 1)
				|  ((uint32)1U << 0);
	DMASSDCEN14 = 	0x00000001U;
				
	/* DMAC17 aka channel 15 configuration */
	DMASSDM17CM = ((uint32)CPU1PEID_CNT_U32 << 4)
				| ((uint32)LCLRAMTOLCLRAMSPID_CNT_U32 << 2)
				| ((uint32)USRMODENA_CNT_U32 << 1);
	DMASSDSA15 = (uint32)(&(MotCtrlMgr_MotCtrlToTwoMilliSec_Rec));
	DMASSDDA15 = (uint32)(&(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec));
	DMASSDTC15 =  ((uint32)0x00U << 16)
				| ((uint32)(sizeof(MotCtrlMgr_MotCtrlToTwoMilliSec_Rec)/16U) << 0); /* bytes in record divided by 16 bytes (= 128 bits) per transfer */
	DMASSDTCT15 = 	((uint32)0x00U << 27)
				|	((uint32)0x00U << 26)
				|	((uint32)0x00U << 18)
				|	((uint32)0x00U << 16)
				|	((uint32)0x00U << 15)
				|	((uint32)0x00U << 14)
				|	((uint32)0x01U << 13)
				|	((uint32)0x00U << 11)
				|	((uint32)0x03U << 9)
				|	((uint32)0x00U << 7)
				|	((uint32)0x00U << 5)
				|	((uint32)0x04U << 2)
				|	((uint32)0x01U << 0);
	DMASSDRSA15 = (uint32)(&(MotCtrlMgr_MotCtrlToTwoMilliSec_Rec));		
	DMASSDRDA15 = (uint32)(&(MotCtrlMgr_TwoMilliSecFromMotCtrl_Rec));
	DMASSDRTC15 = ((uint32)0x00U << 16)
				| ((uint32)(sizeof(MotCtrlMgr_MotCtrlToTwoMilliSec_Rec)/16U) << 0); /* bytes in record divided by 16 bytes (= 128 bits) per transfer */
	DMASSDTFR15 =  ((uint32)0U << 1)
				|  ((uint32)0U << 0);
	DMASSDCEN15 = 	0x00000001U;
				
}

#if (MCUDIAGCERRINJ == STD_ON)
/******************************************************************************
  * Name:        InjDmaErr
  * Description: Function to inject DMA error
  * Inputs:      None     
  * Outputs:     E_OK is returned
  * Usage Notes: 
  ****************************************************************************/
FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) InjDmaErr(void)
{
	VAR (uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == ERRID36BIT0CASE1_CNT_U32)
	{
		ClrErrInjReg_Oper();
		DMASSDM02CM &= (~((uint32)0x0000000CU)); /* clear the SPID bits (bits 3:2) */
		DMASSDM02CM |=((uint32)0x00000004U);     /* use SPID 1 */
	}
	if(ErrId_Cnt_T_u32 == ERRID36BIT1CASE1_CNT_U32)
	{
		ClrErrInjReg_Oper();
		DMASSDM11CM &= (~((uint32)0x00000002U));  /* clear the user mode bit (bit 1) */
	}
	if(ErrId_Cnt_T_u32 == ERRID36BIT1CASE2_CNT_U32)
	{
		ClrErrInjReg_Oper();
		/* Disable the channel */
		DMASSDCEN1 = 0x0U;
		DMASSDDA1  = 0xFEBFFFFCU;  /* Trasfer error from an undefined RAM area */
		DMASSDRDA1 = 0xFEBFFFFCU ; /* Trasfer error from an undefined RAM area */
		/* Enable the channel */
		DMASSDCEN1 = 0x00000001U;
	}	
	return E_OK;
}

/******************************************************************************
  * Name:        InjMcuDiagcErr
  * Description: Function to inject NTC0x2B error by stopping DMA transfer 
  * Inputs:      None     
  * Outputs:     E_OK is returned   
  * Usage Notes: 
  ****************************************************************************/
FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) InjMcuDiagcErr(void)
{
	VAR (uint32, AUTOMATIC) ErrId_Cnt_T_u32;
	ReadErrInjReg_Oper(&ErrId_Cnt_T_u32);
	
	if(ErrId_Cnt_T_u32 == ERRID2BBIT0CASE1_CNT_U32)
	{
		ClrErrInjReg_Oper();
		DMASSDCEN15 = 	0x00000000U; /* Disable DMA channel 15 */
	}
	return E_OK;
}
#endif
#define CDD_DmaCfgAndUse_STOP_SEC_CODE
#include "CDD_DmaCfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
