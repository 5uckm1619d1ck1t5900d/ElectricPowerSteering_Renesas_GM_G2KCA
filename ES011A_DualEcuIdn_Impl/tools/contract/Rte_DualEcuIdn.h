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
 *          File:  Rte_DualEcuIdn.h
 *     SW-C Type:  DualEcuIdn
 *  Generated at:  Wed Jan 18 15:30:04 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <DualEcuIdn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DUALECUIDN_H
# define _RTE_DUALECUIDN_H

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

# include "Rte_DualEcuIdn_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_DualEcuIdn
{
  /* PIM Handles section */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_EcuIdInt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(boolean, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_EcuIdnEvlnCmpl; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2VAR(uint8, TYPEDEF, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Pim_SecdryEcuIdnReqTiOutCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_DualEcuIdn, RTE_CONST, RTE_CONST) Rte_Inst_DualEcuIdn; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_DualEcuIdn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_EcuComTiOut_Logl (FALSE)
# define Rte_InitValue_EcuId_Val (0U)


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DualEcuIdn_EcuComTiOut_Logl(P2VAR(boolean, AUTOMATIC, RTE_DUALECUIDN_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DualEcuIdn_EcuId_Val(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DualEcuIdn_GetSigImcData_u08_Oper(uint16 SigId_Arg, P2VAR(uint8, AUTOMATIC, RTE_DUALECUIDN_APPL_VAR) Data_Arg, P2VAR(ImcArbnRxSts1, AUTOMATIC, RTE_DUALECUIDN_APPL_VAR) Sts_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DualEcuIdn_IoHwAb_GetGpioEcuIdnPin1_Oper(P2VAR(boolean, AUTOMATIC, RTE_DUALECUIDN_APPL_VAR) PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DualEcuIdn_IoHwAb_GetGpioEcuIdnPin2_Oper(P2VAR(boolean, AUTOMATIC, RTE_DUALECUIDN_APPL_VAR) PinSt_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DualEcuIdn_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_EcuComTiOut_Logl Rte_Read_DualEcuIdn_EcuComTiOut_Logl


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_EcuId_Val Rte_Write_DualEcuIdn_EcuId_Val


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_GetSigImcData_u08_Oper Rte_Call_DualEcuIdn_GetSigImcData_u08_Oper
# define Rte_Call_IoHwAb_GetGpioEcuIdnPin1_Oper Rte_Call_DualEcuIdn_IoHwAb_GetGpioEcuIdnPin1_Oper
# define Rte_Call_IoHwAb_GetGpioEcuIdnPin2_Oper Rte_Call_DualEcuIdn_IoHwAb_GetGpioEcuIdnPin2_Oper
# define Rte_Call_SetNtcSts_Oper Rte_Call_DualEcuIdn_SetNtcSts_Oper


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_EcuIdInt() (Rte_Inst_DualEcuIdn->Pim_EcuIdInt) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_SecdryEcuIdnReqTiOutCntr() (Rte_Inst_DualEcuIdn->Pim_SecdryEcuIdnReqTiOutCntr) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# define Rte_Pim_EcuIdnEvlnCmpl() (Rte_Inst_DualEcuIdn->Pim_EcuIdnEvlnCmpl) /* PRQA S 3453 */ /* MD_MSR_19.7 */




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_EcuIdInt(void)
 *   uint8 *Rte_Pim_SecdryEcuIdnReqTiOutCntr(void)
 *   boolean *Rte_Pim_EcuIdnEvlnCmpl(void)
 *
 *********************************************************************************************************************/


# define DualEcuIdn_START_SEC_CODE
# include "DualEcuIdn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DualEcuIdnInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_EcuId_Val(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_IoHwAb_GetGpioEcuIdnPin1_Oper(boolean *PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetGpio_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAb_GetGpioEcuIdnPin2_Oper(boolean *PinSt_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetGpio_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DualEcuIdnInit1 DualEcuIdnInit1
FUNC(void, DualEcuIdn_CODE) DualEcuIdnInit1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DualEcuIdnPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_EcuComTiOut_Logl(boolean *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_GetSigImcData_u08_Oper(uint16 SigId_Arg, uint8 *Data_Arg, ImcArbnRxSts1 *Sts_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GetSigImcData_u08_PortIf1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SetNtcSts_Oper(NtcNr1 NtcNr_Arg, uint8 NtcStInfo_Arg, NtcSts1 NtcSts_Arg, uint16 DebStep_Arg)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SetNtcSts_PortIf1_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_DualEcuIdnPer1 DualEcuIdnPer1
FUNC(void, DualEcuIdn_CODE) DualEcuIdnPer1(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DualEcuIdn_STOP_SEC_CODE
# include "DualEcuIdn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_GetGpio_PortIf1_E_NOT_OK (1U)

# define RTE_E_GetSigImcData_u08_PortIf1_E_NOT_OK (1U)

# define RTE_E_SetNtcSts_PortIf1_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1484769524
#    error "The magic number of the generated file <C:/Component/ES011A_DualEcuIdn_Impl/tools/contract/Rte_DualEcuIdn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1484769524
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_DUALECUIDN_H */
