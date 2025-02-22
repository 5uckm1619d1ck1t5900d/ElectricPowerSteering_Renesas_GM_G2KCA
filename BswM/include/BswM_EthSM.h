/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  BswM_EthSM.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for EthSM.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#if !defined BSWM_ETHSM_H
# define BSWM_ETHSM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "EthSM.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT VERSIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 

/**********************************************************************************************************************
 *  BswM_EthSM_CurrentState()
 *********************************************************************************************************************/
/*!
 * \brief       Function called by EthSM to indicate its current state.
 * \details     Passed state is stored and depending rules are arbitrated.
 * \param[in]   Network       The Ethernet channel that the indicated state corresponds to.
 * \param[in]   CurrentState  The current state of the Ethernet channel.
 * \pre         BswM is initialized
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_ETHSM
 */
extern FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState(NetworkHandleType Network, EthSM_NetworkModeStateType CurrentState);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h" 


#endif  /* BSWM_ETHSM_H */

/**********************************************************************************************************************
 *  END OF FILE: BswM_EthSM.h
 *********************************************************************************************************************/
