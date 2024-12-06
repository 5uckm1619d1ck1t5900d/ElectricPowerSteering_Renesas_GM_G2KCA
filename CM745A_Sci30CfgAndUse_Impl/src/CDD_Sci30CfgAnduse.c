/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_Sci30CfgAndUse.c
 *     SW-C Type:  CDD_Sci30CfgAndUse
 *  Generated at:  Mon Jan 30 18:12:18 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_Sci30CfgAndUse>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2017 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_Sci30CfgAndUse.c
* Module Description: Sci30CfgAndUse Driver component
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       jzk9cc %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 01/19/17  1        AJM       Initial version                                                                 EA4#8022
* 02/01/17  2        AJM       Remove void from the exclusive area enter/exit calls                            EA4#8022
**********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  ImcArbnRxDataSrc1
    uint8 represents integers with a minimum value of 0 and a maximum value of 255.
     The order-relation on uint8 is: x < y if y - x is positive.
     uint8 has a lexical representation consisting of a finite-length sequence 
     of decimal digits (#x30-#x39).
     
     For example: 1, 0, 126, +10.

 *********************************************************************************************************************/

#include "Rte_CDD_Sci30CfgAndUse.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "CDD_Sci30CfgAndUseNonRte_MemMap.h"
#include "sci3_regs.h"
#include "dma_regs.h"
#include "Os.h"
#include "ImcArbn.h"
#include "CDD_Sci30CfgAndUse.h"

/******************************************** File Level Rule Deviations *********************************************/
/* MISRA-C:2004 Rule 1.1 [NXTRDEV 1.1.1]: Inline functions are used to allow for throughput optimization */
/* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.1]	Cast of a register address to an integer type required for writing a register address to a register. */
/* MISRA-C:2004 Rule 11.3 [NXTRDEV 11.3.2]	Cast of a variable address to an integer type required for writing a variable address to a register. */
/* MISRA-C:2004 Rule 11.4 [NXTRDEV 11.4.2]: Per Instance Memory pointers to array base types are cast back to their array type for code readability and to allow use of "sizeof" */
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
/*********************************************************************************************************************/
#define CPU1PEID_CNT_U32 					((uint32)0x01U)
#define PRPHLTOLCLRAMSPID_CNT_U32			((uint32)0x03U)  			/* Peripheral to Local RAM SPID = 3U */
#define LCLRAMTOPRPHLSPID_CNT_U32			((uint32)0x02U)  			/* Local RAM to Peripheral SPID = 2U */
#define USRMODENA_CNT_U32					((uint32)0x1U)  			/* User Mode Bit : 1: User Mode Access Allowed */  
#define SCIRXMAXBUFSIZE_CNT_U08				144U
#define MAXSIGGROUPFORTX_CNT_U08			9U
#define UINT8ROLLOVROFFS_CNT_U16			256U
#define DATABYTE0_CNT_U08					(0U)
#define DATABYTE1_CNT_U08					(1U)
#define DATABYTE2_CNT_U08					(2U)
#define DATABYTE3_CNT_U08					(3U)
#define DATABYTE4_CNT_U08					(4U)
#define DATABYTE5_CNT_U08					(5U)
#define DATABYTE6_CNT_U08					(6U)
#define DATABYTE7_CNT_U08					(7U)
#define DATABYTE8_CNT_U08					(8U)
#define IMCARBNRXDATASRCSCI_CNT_U08			1U
#define SCITXMAXBUFSIZE_CNT_U08				80U

#define CDD_Sci30CfgAndUse_START_SEC_VAR_INIT_128
#include "CDD_Sci30CfgAnduseNonRte_MemMap.h"

static VAR(uint8, AUTOMATIC) SciGlbTxBuf_M[SCITXMAXBUFSIZE_CNT_U08] = {0U};
    
#define CDD_Sci30CfgAndUse_STOP_SEC_VAR_INIT_128
#include "CDD_Sci30CfgAnduseNonRte_MemMap.h"

#define  CDD_Sci30CfgAndUse_DmaWrite_START_SEC_VAR_INIT_128 
#include "CDD_Sci30CfgAnduseNonRte_MemMap.h"

static VAR(uint8, AUTOMATIC) SciGlbRxBuf_M[SCIRXMAXBUFSIZE_CNT_U08] = {0U};

#define CDD_Sci30CfgAndUse_DmaWrite_STOP_SEC_VAR_INIT_128
#include "CDD_Sci30CfgAnduseNonRte_MemMap.h"

LOCAL_INLINE FUNC(uint8, CDD_Sci30CfgAnduse_CODE) RollOvrAdd(uint8 Idx_Cnt_T_u08);
static FUNC(void, CDD_Sci30CfgAnduse_CODE)UpdDtsTxReg(uint8 SciGlbTxCnt_Cnt_u08);
static FUNC(void, CDD_Sci30CfgAnduse_CODE)UpdDtsRxReg(void);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ImcArbnRxDataSrc1: Integer in interval [0...255]
 *
 * Array Types:
 * ============
 * Ary1D_u8_8: Array with 8 element(s) of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_SciDiagcFrmErrCntr(void)
 *   uint32 *Rte_Pim_SciDiagcOvrrunErrCntr(void)
 *   uint32 *Rte_Pim_SciDiagcParErrCntr(void)
 *   uint32 *Rte_Pim_SciDiagcRxMaxDataErrCntr(void)
 *   uint8 *Rte_Pim_SciNrOfPnd100MilliSecFrmCnt(void)
 *   uint8 *Rte_Pim_SciNrOfPnd10MilliSecFrmCnt(void)
 *   uint8 *Rte_Pim_SciRxPrevLoopDataUnread(void)
 *   uint8 *Rte_Pim_SciRxProcIdx(void)
 *   boolean *Rte_Pim_Sci100MilliSecReadCmpl(void)
 *   boolean *Rte_Pim_Sci10MilliSecReadCmpl(void)
 *   uint8 *Rte_Pim_Sci100MilliSecBufCnt(void)
 *   uint8 *Rte_Pim_Sci10MilliSecBufCnt(void)
 *   uint8 *Rte_Pim_Sci2MilliSecBufCnt(void)
 *
 *********************************************************************************************************************/


#define CDD_Sci30CfgAndUse_START_SEC_CODE
#include "CDD_Sci30CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Sci30CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUseInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Sci30CfgAndUseInit1
 *********************************************************************************************************************/
	/* Initialize the SCI Registers */
	SCI30SMR  =  (uint8)(((uint32)0<<7)   /* CM - Asynchronous Communication */
			   | ((uint32)0<<6)   /* CHR - Character Length = 8 bits */
			   | ((uint32)1<<5)   /* PE - Parity Enabled */   
			   | ((uint32)1<<4)   /* PM - Odd Parity */
			   | ((uint32)1<<3)   /* STOP - 2 Stop Bits */
			   | ((uint32)0<<1));  /* CKS[1:0] - Alpha = 0 */   
 
	SCI30SCR  = 0U;

	SCI30SCMR =   (uint8)(((uint32)0U<<3)  /* SDIR - LSB First */
	            | ((uint32)0U<<2)); /* SINV - No Data Inversion */

	SCI30SEMR =   (uint8)((uint32)1U<<3); /* ABCS - Double Speed Operation */
	SCI30BRR  =   4U;    /* N= 4 */
	SCI30SEMR =   (uint8)(((uint32)1U<<7)  /* BRME - Bit Rate Modulation Enabled */
	            | ((uint32)1U<<6)); /* MDDRS - SCI30MDDR is accessible */
	SCI30MDDR = 255U;
	SCI30SCR  =  (uint8)(((uint32)1U<<7)   /* TIE - Transmit Interrupt Enable */
			   | ((uint32)1U<<6)   /* RIE - Receive interrupt enable */
			   | ((uint32)1U<<5)   /* TE - Transmiot enable */   
			   | ((uint32)1U<<4));  /* RE - Receive Enable */
	/* Trusted Function call to initialize DTS channel master registers used by SCI */ 
	Call_IninSciDtsChMstReg();
	
	/* DTS Channel 88 SCI30 Transmit Configuration */
	DMASSDTFSL088 = 0U;
	DMASSDTSA088  = (uint32)&(SciGlbTxBuf_M[0]);
	DMASSDTDA088  = (uint32)&(SCI30TDR);
	DMASSDTTC088  = 0U;
	DMASSDTTCT088 = 256U;
	DMASSDTFSC088 = 1U;
	DMASSDTFSL088 = 1U;

	/* DTS Channel 87 SCI30 Receive Configuration */
	DMASSDTFSL087 = 0U;
	DMASSDTSA087  = (uint32)&(SCI30RDR);
	DMASSDTDA087  = (uint32)&(SciGlbRxBuf_M[0]);
	DMASSDTTC087  = 9437328U;
	DMASSDTTCT087 = 6208U;
	DMASSDTRSA087 = (uint32)&(SCI30RDR);
	DMASSDTRDA087 = (uint32)&(SciGlbRxBuf_M[0]);
	DMASSDTRTC087|= 9437184U;
	DMASSDTFSC087 = 1U;
	DMASSDTFSL087 = 1U;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Sci30CfgAndUsePer1
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
 *   Std_ReturnType Rte_Call_SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, const uint8 *Buf_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetRxSigGroup_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Sci30CfgAndUsePer1
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) SciRxDataCntr_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) SciRxIdxMax_Cnt_T_u08;
    VAR(uint8, AUTOMATIC) Idx_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) SetBreakOutOfLoop_Cnt_T_logl = FALSE;
	VAR(boolean, AUTOMATIC)	ImcDataBuf_Cnt_u08[8];
	
	SciRxDataCntr_Cnt_T_u08 = (uint8)((uint32)SCIRXMAXBUFSIZE_CNT_U08 - (DMASSDTTC087 & 0x0000FFFFU));
	
	if(SciRxDataCntr_Cnt_T_u08 > 0U)
	{
		SciRxIdxMax_Cnt_T_u08 = SciRxDataCntr_Cnt_T_u08 + *Rte_Pim_SciRxPrevLoopDataUnread();
		
		*Rte_Pim_SciRxPrevLoopDataUnread() = 0U; /* Clear */
		
		Idx_Cnt_T_u08 = 0U;

		while((Idx_Cnt_T_u08 < SciRxIdxMax_Cnt_T_u08) && (SetBreakOutOfLoop_Cnt_T_logl == FALSE))
		{
			if((SciGlbRxBuf_M[*Rte_Pim_SciRxProcIdx()] & IMCARBN_PATIDMASKVAL_CNT_U08) == IMCARBN_PATIDN_CNT_U08)
			{
				if((SciRxIdxMax_Cnt_T_u08 - Idx_Cnt_T_u08) < 8U)
				{
					SetBreakOutOfLoop_Cnt_T_logl = TRUE;
					*Rte_Pim_SciRxPrevLoopDataUnread() = SciRxIdxMax_Cnt_T_u08 - Idx_Cnt_T_u08;
				}
				else if(((SciGlbRxBuf_M[*Rte_Pim_SciRxProcIdx()]) ^ (SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx()+ DATABYTE7_CNT_U08)])) == 0xFFU)
				{
					ImcDataBuf_Cnt_u08[DATABYTE0_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE0_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE1_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE1_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE2_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE2_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE3_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE3_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE4_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE4_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE5_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE5_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE6_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE6_CNT_U08)];
					ImcDataBuf_Cnt_u08[DATABYTE7_CNT_U08] = SciGlbRxBuf_M[RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE7_CNT_U08)];

					(void)Rte_Call_SetRxSigGroup_Oper(ImcDataBuf_Cnt_u08[DATABYTE1_CNT_U08], IMCARBNRXDATASRCSCI_CNT_U08, &ImcDataBuf_Cnt_u08[0u]);
					*Rte_Pim_SciRxProcIdx() = RollOvrAdd(*Rte_Pim_SciRxProcIdx() + DATABYTE8_CNT_U08);
					Idx_Cnt_T_u08 += (IMCARBN_FRMSIZE_CNT_U08 - 1U);

				}
				else
				{
					*Rte_Pim_SciRxProcIdx() = RollOvrAdd(*Rte_Pim_SciRxProcIdx() + 1U);
				}

			}
			else
			{
				*Rte_Pim_SciRxProcIdx() = RollOvrAdd(*Rte_Pim_SciRxProcIdx() + 1U);
			}

			Idx_Cnt_T_u08++;
		}
	}
	UpdDtsRxReg();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Sci30CfgAndUsePer2
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
 *   Std_ReturnType Rte_Call_GetTxRateGroup_Oper(uint8 RateGroup_Arg, uint8 *Buf_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetTxRateGroup_PortIf1_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclsvAr1SciDrvrTxRxBuf(void)
 *   void Rte_Exit_ExclsvAr1SciDrvrTxRxBuf(void)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Sci30CfgAndUsePer2
 *********************************************************************************************************************/
	VAR(uint8, AUTOMATIC) SigGroup_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) EmptyFrm_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) BytesUsed_Cnt_T_u08 = 0U;
	VAR(uint8, AUTOMATIC) SciGlbTxCnt_T_u08 = 0U;
	VAR(uint8, AUTOMATIC) SigByte_Cnt_T_u08;
	
	#if (IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08 != 0U) 
	VAR(boolean, AUTOMATIC) Sci2MilliSecReadCmpl_Cnt_T_logl;

	Sci2MilliSecReadCmpl_Cnt_T_logl = Rte_Call_GetTxRateGroup_Oper(IMCARBN_RATEGROUPID2MILLISEC_CNT_U08, Rte_Pim_Sci2MilliSecBufCnt());
	if(Sci2MilliSecReadCmpl_Cnt_T_logl == E_OK)
	{
		/* Copy all 2ms signals group data to global buffer */
		for(SigGroup_Cnt_T_u08 = 0U;  SigGroup_Cnt_T_u08 < (IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08 * IMCARBN_FRMSIZE_CNT_U08); SigGroup_Cnt_T_u08++)
		{
			SciGlbTxBuf_M[BytesUsed_Cnt_T_u08] = *((Rte_Pim_Sci2MilliSecBufCnt() + BytesUsed_Cnt_T_u08));  
			BytesUsed_Cnt_T_u08++;
		} 
		SciGlbTxCnt_T_u08 = IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08;
	}
	#endif
	
	#if (IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08 != 0U) 
	if(*Rte_Pim_Sci10MilliSecReadCmpl() == E_OK)
	{
		EmptyFrm_Cnt_T_u08 = MAXSIGGROUPFORTX_CNT_U08 - SciGlbTxCnt_T_u08;
		
		if(*Rte_Pim_SciNrOfPnd10MilliSecFrmCnt() <= EmptyFrm_Cnt_T_u08)
		{
			EmptyFrm_Cnt_T_u08 = *Rte_Pim_SciNrOfPnd10MilliSecFrmCnt();
			*Rte_Pim_Sci10MilliSecReadCmpl() = E_NOT_OK;
		}
		/* Copy possible 10ms signals group data to global buffer */
		for(SigGroup_Cnt_T_u08 = 0U;  SigGroup_Cnt_T_u08 < EmptyFrm_Cnt_T_u08; SigGroup_Cnt_T_u08++)
		{
			/* Enter Exclusive Area */
			Rte_Enter_ExclsvAr1SciDrvrTxRxBuf();
			for(SigByte_Cnt_T_u08 = 0U;  SigByte_Cnt_T_u08 < IMCARBN_FRMSIZE_CNT_U08; SigByte_Cnt_T_u08++)
			{
				SciGlbTxBuf_M[BytesUsed_Cnt_T_u08] = 
					*(Rte_Pim_Sci10MilliSecBufCnt()+((IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08- *Rte_Pim_SciNrOfPnd10MilliSecFrmCnt())*IMCARBN_FRMSIZE_CNT_U08) + SigByte_Cnt_T_u08);   
				BytesUsed_Cnt_T_u08++;
			} 
			/* Exit Exclusive Area */
			Rte_Exit_ExclsvAr1SciDrvrTxRxBuf();
			*Rte_Pim_SciNrOfPnd10MilliSecFrmCnt() -= 1U;
		}
		SciGlbTxCnt_T_u08 += EmptyFrm_Cnt_T_u08;
	}
	#endif
	
	#if (IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08 != 0) 
	if(*Rte_Pim_Sci100MilliSecReadCmpl() == E_OK)
	{
		EmptyFrm_Cnt_T_u08 = MAXSIGGROUPFORTX_CNT_U08 - SciGlbTxCnt_T_u08;
		if(*Rte_Pim_SciNrOfPnd100MilliSecFrmCnt() <= EmptyFrm_Cnt_T_u08)
		{
			EmptyFrm_Cnt_T_u08 = *Rte_Pim_SciNrOfPnd100MilliSecFrmCnt();
			*Rte_Pim_Sci100MilliSecReadCmpl() = E_NOT_OK;
		}
		/* Copy possible 100ms signals group data to global buffer */
		for(SigGroup_Cnt_T_u08 = 0U;  SigGroup_Cnt_T_u08 < EmptyFrm_Cnt_T_u08; SigGroup_Cnt_T_u08++)
		{
			/* Enter Exclusive Area */
			Rte_Enter_ExclsvAr1SciDrvrTxRxBuf();
			for(SigByte_Cnt_T_u08 = 0U;  SigByte_Cnt_T_u08 < IMCARBN_FRMSIZE_CNT_U08; SigByte_Cnt_T_u08++)
			{
				SciGlbTxBuf_M[BytesUsed_Cnt_T_u08] =  
					*(Rte_Pim_Sci100MilliSecBufCnt()+((IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08 - *Rte_Pim_SciNrOfPnd100MilliSecFrmCnt())*IMCARBN_FRMSIZE_CNT_U08) + SigByte_Cnt_T_u08);       
				BytesUsed_Cnt_T_u08++;
			}
			/* Exit Exclusive Area */
			Rte_Exit_ExclsvAr1SciDrvrTxRxBuf();
			*Rte_Pim_SciNrOfPnd100MilliSecFrmCnt() -= 1U;
		}
		SciGlbTxCnt_T_u08 += EmptyFrm_Cnt_T_u08;
	}
	#endif
	if((SciGlbTxCnt_T_u08 > 0U) && (SCI30TDRE == 1U))
	{
		UpdDtsTxReg(SciGlbTxCnt_T_u08);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Sci30CfgAndUsePer3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetTxRateGroup_Oper(uint8 RateGroup_Arg, uint8 *Buf_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetTxRateGroup_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer3(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Sci30CfgAndUsePer3
 *********************************************************************************************************************/
	#if (IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08 != 0U) 
	*Rte_Pim_Sci10MilliSecReadCmpl() = Rte_Call_GetTxRateGroup_Oper(IMCARBN_RATEGROUPID10MILLISEC_CNT_U08, Rte_Pim_Sci10MilliSecBufCnt());
	*Rte_Pim_SciNrOfPnd10MilliSecFrmCnt() = IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08;
	#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Sci30CfgAndUsePer4
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetTxRateGroup_Oper(uint8 RateGroup_Arg, uint8 *Buf_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetTxRateGroup_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer4(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Sci30CfgAndUsePer4
 *********************************************************************************************************************/
	#if (IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08 != 0U) 
	*Rte_Pim_Sci100MilliSecReadCmpl() = Rte_Call_GetTxRateGroup_Oper(IMCARBN_RATEGROUPID100MILLISEC_CNT_U08, Rte_Pim_Sci100MilliSecBufCnt());
	*Rte_Pim_SciNrOfPnd100MilliSecFrmCnt() = IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08;
	#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_Sci30CfgAndUse_STOP_SEC_CODE
#include "CDD_Sci30CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define CDD_Sci30CfgAnduse_START_SEC_CODE
#include "CDD_Sci30CfgAnduse_MemMap.h"
/**********************************************************************************************************************
  * Name:        IninSciDtsChMstReg
  * Description: DTS Channel Master Register initialization
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called from Sci30CfgAndUseInit1
                 Need to run in Supervisor mode
**********************************************************************************************************************/
FUNC(void, CDD_Sci30CfgAnduse_CODE)IninSciDtsChMstReg(void)
{
	DMASSDTS088CM = ((uint32)CPU1PEID_CNT_U32 << 20)
				| ((uint32)LCLRAMTOPRPHLSPID_CNT_U32 << 18)
				| ((uint32)USRMODENA_CNT_U32 << 17);
				
	DMASSDTS087CM = ((uint32)CPU1PEID_CNT_U32 << 20)
				| ((uint32)PRPHLTOLCLRAMSPID_CNT_U32 << 18)
				| ((uint32)USRMODENA_CNT_U32 << 17);
}

/**********************************************************************************************************************
  * Name:        UpdDtsTxReg
  * Description: Update DTS Registers for transmit during run time
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called from Sci30CfgAndUsePer2
**********************************************************************************************************************/
static FUNC(void, CDD_Sci30CfgAnduse_CODE)UpdDtsTxReg(uint8 SciGlbTxCnt_Cnt_u08)
{
	DMASSDTFSL088 = 0U;
	DMASSDTFSC088 = 1U;
	DMASSDTSA088 = (uint32)&(SciGlbTxBuf_M[0]);
	DMASSDTDA088 = (uint32)&(SCI30TDR);
	DMASSDTTC088 = (uint32)(uint8)(SciGlbTxCnt_Cnt_u08 * IMCARBN_FRMSIZE_CNT_U08);
	DMASSDTFSL088 = 1U;
	DMASSDTFSS088 = 1U;
}

/**********************************************************************************************************************
  * Name:        UpdDtsRxReg
  * Description: Update DTS Registers for receive during run time
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called from Sci30CfgAndUsePer1
**********************************************************************************************************************/
static FUNC(void, CDD_Sci30CfgAnduse_CODE)UpdDtsRxReg(void)
{
	if((DMASSDTTC087 & 0xFFFF0000U) >= SCIRXMAXBUFSIZE_CNT_U08)
	{
		*Rte_Pim_SciDiagcRxMaxDataErrCntr() += 1U;
	}
	if(SCI30ORER == 1U)
	{
		SCI30ORER = 0U;
		SCI30RDRF = 0U;
		*Rte_Pim_SciDiagcOvrrunErrCntr() += 1U;
	}
	if(SCI30PER == 1U)
	{
		SCI30PER = 0U;
		*Rte_Pim_SciDiagcParErrCntr() += 1U;
	}
	if(SCI30FER == 1U)
	{
		SCI30FER = 0U;
		*Rte_Pim_SciDiagcFrmErrCntr() += 1U;
	}
	DMASSDTFSL087 = 0U;
	DMASSDTFSC087 = 1U;
	
	DMASSDTTC087 |= 0x0000FFFFU;
	DMASSDTTC087 &= 0xFFFF0090U;
	DMASSDTFSL087 = 1U;
}

/**********************************************************************************************************************
  * Name:        RollOvrAdd
  * Description: Check for roll over and update the index
  * Inputs:      NONE
  * Outputs:     NONE
  * Usage Notes: To be called from Sci30CfgAndUsePer1
**********************************************************************************************************************/
LOCAL_INLINE FUNC(uint8, CDD_Sci30CfgAndUse_CODE) RollOvrAdd(uint8 Idx_Cnt_T_u08)
{
	return (((Idx_Cnt_T_u08)) % ((2U*IMCARBN_FRMSIZE_CNT_U08 * MAXSIGGROUPFORTX_CNT_U08)));
}

#define CDD_Sci30CfgAnduse_STOP_SEC_CODE
#include "CDD_Sci30CfgAnduse_MemMap.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
