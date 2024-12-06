/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2014 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_Sci30CfgAndUse.h
 *     SW-C Type:  CDD_Sci30CfgAndUse
 *  Generated at:  Mon Jan 30 18:12:17 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_Sci30CfgAndUse> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_SCI30CFGANDUSE_H
# define _RTE_CDD_SCI30CFGANDUSE_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# define RTE_PTR2ARRAYBASETYPE_PASSING

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_Sci30CfgAndUse_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_CDD_Sci30CfgAndUse
{
  /* PIM Handles section */
  P2VAR(Ary2D_u8_Sci30CfgAndUseC, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Sci100MilliSecBufCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Sci100MilliSecReadCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary2D_u8_Sci30CfgAndUseB, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Sci10MilliSecBufCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Sci10MilliSecReadCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(Ary2D_u8_Sci30CfgAndUseA, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_Sci2MilliSecBufCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciDiagcFrmErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciDiagcOvrrunErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciDiagcParErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint32, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciDiagcRxMaxDataErrCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciNrOfPnd100MilliSecFrmCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciNrOfPnd10MilliSecFrmCnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciRxPrevLoopDataUnread; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SciRxProcIdx; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CDD_Sci30CfgAndUse, RTE_CONST, RTE_CONST) Rte_Inst_CDD_Sci30CfgAndUse; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CDD_Sci30CfgAndUse, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_Sci30CfgAndUse_GetTxRateGroup_Oper(uint8 RateGroup_Arg, P2VAR(uint8, AUTOMATIC, RTE_CDD_SCI30CFGANDUSE_APPL_VAR) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_Sci30CfgAndUse_SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, P2CONST(uint8, AUTOMATIC, RTE_CDD_SCI30CFGANDUSE_APPL_DATA) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CDD_Sci30CfgAndUse_SetRxSigGroup_Oper(uint8 SigGroup_Arg, ImcArbnRxDataSrc1 DataSrc_Arg, P2CONST(Ary1D_u8_8, AUTOMATIC, RTE_CDD_SCI30CFGANDUSE_APPL_DATA) Buf_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif

FUNC(void, RTE_CODE) Rte_Enter_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RTE_CODE) Rte_Exit_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetTxRateGroup_Oper Rte_Call_CDD_Sci30CfgAndUse_GetTxRateGroup_Oper
# define Rte_Call_SetRxSigGroup_Oper Rte_Call_CDD_Sci30CfgAndUse_SetRxSigGroup_Oper


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

# define Rte_Enter_ExclsvAr1SciDrvrTxRxBuf Rte_Enter_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf
# define Rte_Exit_ExclsvAr1SciDrvrTxRxBuf Rte_Exit_CDD_Sci30CfgAndUse_ExclsvAr1SciDrvrTxRxBuf


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_SciDiagcFrmErrCntr() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciDiagcFrmErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciDiagcOvrrunErrCntr() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciDiagcOvrrunErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciDiagcParErrCntr() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciDiagcParErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciDiagcRxMaxDataErrCntr() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciDiagcRxMaxDataErrCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciNrOfPnd100MilliSecFrmCnt() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciNrOfPnd100MilliSecFrmCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciNrOfPnd10MilliSecFrmCnt() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciNrOfPnd10MilliSecFrmCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciRxPrevLoopDataUnread() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciRxPrevLoopDataUnread) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SciRxProcIdx() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_SciRxProcIdx) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Sci100MilliSecReadCmpl() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci100MilliSecReadCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_Sci10MilliSecReadCmpl() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci10MilliSecReadCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_Sci100MilliSecBufCnt() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) *Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci100MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_Sci100MilliSecBufCnt() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci100MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_Sci10MilliSecBufCnt() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) *Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci10MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_Sci10MilliSecBufCnt() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci10MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#  define Rte_Pim_Sci2MilliSecBufCnt() ((P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT)) *Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci2MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define Rte_Pim_Sci2MilliSecBufCnt() (Rte_Inst_CDD_Sci30CfgAndUse->Pim_Sci2MilliSecBufCnt) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif




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


# define CDD_Sci30CfgAndUse_START_SEC_CODE
# include "CDD_Sci30CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Sci30CfgAndUseInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_Sci30CfgAndUseInit1 Sci30CfgAndUseInit1
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUseInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

# define RTE_RUNNABLE_Sci30CfgAndUsePer1 Sci30CfgAndUsePer1
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

# define RTE_RUNNABLE_Sci30CfgAndUsePer2 Sci30CfgAndUsePer2
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer2(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

# define RTE_RUNNABLE_Sci30CfgAndUsePer3 Sci30CfgAndUsePer3
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer3(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

# define RTE_RUNNABLE_Sci30CfgAndUsePer4 Sci30CfgAndUsePer4
FUNC(void, CDD_Sci30CfgAndUse_CODE) Sci30CfgAndUsePer4(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CDD_Sci30CfgAndUse_STOP_SEC_CODE
# include "CDD_Sci30CfgAndUse_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetTxRateGroup_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetRxSigGroup_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1485824686
#    error "The magic number of the generated file <C:/Component/CM745A_Sci30CfgAndUse_Impl/tools/contract/Rte_CDD_Sci30CfgAndUse.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1485824686
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_CDD_SCI30CFGANDUSE_H */
