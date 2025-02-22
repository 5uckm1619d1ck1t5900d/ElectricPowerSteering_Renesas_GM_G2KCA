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
 *          File:  Rte_PwrUpSeq.h
 *     SW-C Type:  PwrUpSeq
 *  Generated at:  Fri Jul 15 10:17:39 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <PwrUpSeq> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_PWRUPSEQ_H
# define _RTE_PWRUPSEQ_H

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

# include "Rte_PwrUpSeq_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_PwrUpSeq
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_PwrUpSeq, RTE_CONST, RTE_CONST) Rte_Inst_PwrUpSeq; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_PwrUpSeq, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CodFlsCrcChkCmpl_Logl (FALSE)
# define Rte_InitValue_CurrMeasWrmIninTestCmpl_Logl (FALSE)
# define Rte_InitValue_MotDrvr0IninTestCmpl_Logl (FALSE)
# define Rte_InitValue_MotDrvr1IninTestCmpl_Logl (FALSE)
# define Rte_InitValue_PwrDiscnctATestCmpl_Logl (FALSE)
# define Rte_InitValue_PwrDiscnctBTestCmpl_Logl (FALSE)
# define Rte_InitValue_StrtUpSt_Val (0U)
# define Rte_InitValue_SysSt_Val (3U)
# define Rte_InitValue_SysStWrmIninCmpl_Logl (FALSE)
# define Rte_InitValue_TmplMonIninTestCmpl_Logl (FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_CodFlsCrcChkCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_CurrMeasWrmIninTestCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_MotDrvr0IninTestCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_MotDrvr1IninTestCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_PwrDiscnctATestCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_PwrDiscnctBTestCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_SysSt_Val(P2VAR(SysSt1, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PwrUpSeq_TmplMonIninTestCmpl_Logl(P2VAR(boolean, AUTOMATIC, RTE_PWRUPSEQ_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PwrUpSeq_StrtUpSt_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PwrUpSeq_SysStWrmIninCmpl_Logl(boolean data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_CodFlsCrcChkCmpl_Logl Rte_Read_PwrUpSeq_CodFlsCrcChkCmpl_Logl
# define Rte_Read_CurrMeasWrmIninTestCmpl_Logl Rte_Read_PwrUpSeq_CurrMeasWrmIninTestCmpl_Logl
# define Rte_Read_MotDrvr0IninTestCmpl_Logl Rte_Read_PwrUpSeq_MotDrvr0IninTestCmpl_Logl
# define Rte_Read_MotDrvr1IninTestCmpl_Logl Rte_Read_PwrUpSeq_MotDrvr1IninTestCmpl_Logl
# define Rte_Read_PwrDiscnctATestCmpl_Logl Rte_Read_PwrUpSeq_PwrDiscnctATestCmpl_Logl
# define Rte_Read_PwrDiscnctBTestCmpl_Logl Rte_Read_PwrUpSeq_PwrDiscnctBTestCmpl_Logl
# define Rte_Read_SysSt_Val Rte_Read_PwrUpSeq_SysSt_Val
# define Rte_Read_TmplMonIninTestCmpl_Logl Rte_Read_PwrUpSeq_TmplMonIninTestCmpl_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_StrtUpSt_Val Rte_Write_PwrUpSeq_StrtUpSt_Val
# define Rte_Write_SysStWrmIninCmpl_Logl Rte_Write_PwrUpSeq_SysStWrmIninCmpl_Logl




# define PwrUpSeq_START_SEC_CODE
# include "PwrUpSeq_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrUpSeqInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PwrUpSeqInit1 PwrUpSeqInit1
FUNC(void, PwrUpSeq_CODE) PwrUpSeqInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PwrUpSeqPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CodFlsCrcChkCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_CurrMeasWrmIninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotDrvr0IninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_MotDrvr1IninTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PwrDiscnctATestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_PwrDiscnctBTestCmpl_Logl(boolean *data)
 *   Std_ReturnType Rte_Read_SysSt_Val(SysSt1 *data)
 *   Std_ReturnType Rte_Read_TmplMonIninTestCmpl_Logl(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_StrtUpSt_Val(uint8 data)
 *   Std_ReturnType Rte_Write_SysStWrmIninCmpl_Logl(boolean data)
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_PwrUpSeqPer1 PwrUpSeqPer1
FUNC(void, PwrUpSeq_CODE) PwrUpSeqPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define PwrUpSeq_STOP_SEC_CODE
# include "PwrUpSeq_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1468585910
#    error "The magic number of the generated file <C:/component/ES004A_PwrUpSeq_Impl/tools/contract/Rte_PwrUpSeq.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1468585910
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_PWRUPSEQ_H */
