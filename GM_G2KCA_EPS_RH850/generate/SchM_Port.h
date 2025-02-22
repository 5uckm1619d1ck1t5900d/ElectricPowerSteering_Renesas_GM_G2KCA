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
 *          File:  SchM_Port.h
 *        Config:  EPS.dpa
 *   ECU-Project:  EPS
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400351 for Nexteer Automotive Corporation
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Port>
 *********************************************************************************************************************/
#ifndef SCHM_PORT_H
# define SCHM_PORT_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Port_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Port_INIT_CONFIG_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_INIT_CONFIG_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Port_REFRESH_PORT_INTERNAL_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_REFRESH_PORT_INTERNAL_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Port_SET_PIN_DEFAULT_DIR_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_SET_PIN_DEFAULT_DIR_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Port_SET_PIN_DEFAULT_MODE_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_SET_PIN_DEFAULT_MODE_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Port_SET_PIN_DIR_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_SET_PIN_DIR_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Port_SET_PIN_MODE_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_SET_PIN_MODE_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Enter_Port_SET_TO_DIO_ALT_PROTECTION(void);
FUNC(void, RTE_CODE) SchM_Exit_Port_SET_TO_DIO_ALT_PROTECTION(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_PORT_H */
