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
 *          File:  Rte_CalRegn03Rt01_Dummy.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Application header file for SW-C <CalRegn03Rt01_Dummy>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CALREGN03RT01_DUMMY_H
# define _RTE_CALREGN03RT01_DUMMY_H

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

# ifndef RTE_CORE
#  define RTE_MULTI_INST_API
# endif

/* include files */

# include "Rte_CalRegn03Rt01_Dummy_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE
typedef P2CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, TYPEDEF, RTE_CONST) Rte_Instance; /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  define Rte_Prm_InertiaCmpVelDampgFilFrq_Ary1D(self) ((self)->InertiaCmpVelDampgFilFrq.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

#  define Rte_Prm_InertiaCmpVelDampgFilFrqWhlImbRejctnOn_Ary1D(self) ((self)->InertiaCmpVelDampgFilFrqWhlImbRejctnOn.Prm_Ary1D()) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# endif /* !defined(RTE_CORE) */


# define CalRegn03Rt01_Dummy_START_SEC_CODE
# include "CalRegn03Rt01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CalRegn03Rt01DummyInit1 CalRegn03Rt01DummyInit1
# endif

FUNC(void, CalRegn03Rt01_Dummy_CODE) CalRegn03Rt01DummyInit1(P2CONST(struct Rte_CDS_CalRegn03Rt01_Dummy, AUTOMATIC, RTE_CONST) self); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CalRegn03Rt01_Dummy_STOP_SEC_CODE
# include "CalRegn03Rt01_Dummy_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CALREGN03RT01_DUMMY_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
