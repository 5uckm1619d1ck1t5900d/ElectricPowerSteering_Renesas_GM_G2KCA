/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CDD_MotAg3Meas.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CDD_MotAg3Meas>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CDD_MOTAG3MEAS_H
# define _RTE_CDD_MOTAG3MEAS_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CDD_MotAg3Meas_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(sint8, RTE_VAR_INIT) Rte_PolarityCfg_MotAgMecl3Polarity_Val; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_MotAgMecl3Polarity_Val (1)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_MotAgMecl3Polarity_Val Rte_Read_CDD_MotAg3Meas_MotAgMecl3Polarity_Val
#  define Rte_Read_CDD_MotAg3Meas_MotAgMecl3Polarity_Val(data) (*(data) = Rte_PolarityCfg_MotAgMecl3Polarity_Val, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CDD_MotAg3Meas_START_SEC_CODE
# include "CDD_MotAg3Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_GetMotAg3Mecl_Oper GetMotAg3Mecl_Oper
#  define RTE_RUNNABLE_MotAg3MeasInit1 MotAg3MeasInit1
# endif

FUNC(void, CDD_MotAg3Meas_CODE) GetMotAg3Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG3MEAS_APPL_VAR) MotAgMecl_Arg); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CDD_MotAg3Meas_CODE) MotAg3MeasInit1(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CDD_MotAg3Meas_STOP_SEC_CODE
# include "CDD_MotAg3Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CDD_MOTAG3MEAS_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
