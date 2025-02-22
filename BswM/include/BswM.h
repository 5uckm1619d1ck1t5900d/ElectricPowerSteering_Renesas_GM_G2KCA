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
/**        \file  BswM.h
 *        \brief  Header file of MICROSAR Basic Software Mode Manager
 *
 *      \details  Implements AUTOSAR BswM
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Leticia Garcia                visgle        Vector Informatik GmbH
 *  Philipp Ritter                visrpp        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2012-04-23  visgle  ESCAN00058536 Create SysService_Asr4BswMCfg5 Implementation according to ASR 4.0.3
 *  1.01.00   2012-09-21  visgle  ESCAN00058538 Add Support of Ethernet components
 *  1.01.00   2012-09-26  visgle  ESCAN00061730 Mode notification from BswM to RTE in the main function is missing 
 *  1.01.00   2012-09-26  visgle  ESCAN00061767 Remove do - while(0) loop
 *  1.02.00   2012-10-05  visgle  ESCAN00061966 Define BSWM_DOMAIN_MODE_NOTIFICATION missing
 *  1.02.00   2012-12-07  visgle  ESCAN00062430 AR4-98: Interaction with BswM
 *  1.02.00   2013-01-21  visgle  ESCAN00063827 Compiler error:'BswM_NvM_BlockMode_CurrentStates':undeclared identifier
 *  1.02.00   2013-01-22  visgle  ESCAN00064439 Compiler error: #error "BswM_EcuM.h version is not correct!"
 *  1.02.00   2013-01-31  visgle  ESCAN00064698 Compiler warning or error: "redefinition; different basic types" 
 *                                              for the function BswM_LinSM_CurrentState"
 *  1.03.00   2013-04-04  visgle  ESCAN00065943 Call of BswM_EcuM_CurrentWakeup does not work with multiple
 *                                              sources as parameter
 *  1.03.00   2013-04-16  visgle  ESCAN00064312 Implement Post-Build Loadable
 *  1.03.00   2013-05-15  visgle  ESCAN00062130 Mode Request Ports as sender receiver interface
 *  1.03.01   2013-05-23  visgle  ESCAN00067631 When using generic modes , the modes are not correctly saved in the
 *                                              BswM_GenericRequest array
 *  2.00.00   2013-09-27  visgle  ESCAN00069702 Rule is not invoked immediate when Request Port is configured 
 *                                              multiple times
 *                                ESCAN00069023 AR4-428: Add Support of Timer Handling, equal to ASR3 implementation
 *                                ESCAN00069713 Action list is invoked multiple times inside one BswM_MainFunction Call
 *                                ESCAN00070762 Optimization of code size
 *                                ESCAN00071353 DET check for BswM_EcuM_CurrentWakeup changed for MICROSAR compatibility
 *                                ESCAN00071420 The immediate rules are executed once in the main function
 *  2.00.01   2013-12-03  visgle  ESCAN00071471 Multiple mode requests of same type that occur during the BswM
 *                                              context get lost.
 *  2.01.00   2013-11-29  visgle  ESCAN00071598 AR4-408: Support for J1939Nm, J1939Rm, and J1939Dcm
 *                                ESCAN00071842 AR4-509: New module: Service Discovery according to ASR 4.1.1
 *            2014-02-03  visgle  ESCAN00072377 AR4-329: Support Renault within AUTOSAR
 *            2014-02-11  visgle  ESCAN00073609 Rule is not invoked immediate or forced immediate when Request Port
 *                                              is configured multiple times
 *                                ESCAN00073912 Support of EcuM_BswErrorHook added
 *                                ESCAN00073909 Make inclusion of "BswM_ComM.h" dependent on BSWM_ENABLE_COMM
 *                                ESCAN00073916 Invoke Com_IpduGroupControl only once per MainFunction/Immediate processing
 *  3.00.00   2014-05-12  visrpp  ESCAN00075707 Rule Arbitration of immediate requests ports at end of BswM_Init shall
 *                                              be configurable
 *                                ESCAN00075708 Change arbitration algorithm: First arbitrate all rules, execute afterwards
 *                                ESCAN00075709 Rule Arbitration of a single rule shall be switchable during runtime
 *                                ESCAN00075711 Call of BswM_Deinit has no effect if DET is disabled 
 *  4.00.00   2014-09-12  visrpp  ESCAN00078364 AR4-698: Post-Build Selectable (Identity Manager)
 *                                ESCAN00078361 AR4-823: Add support for WdgM Partition Reset
 *  4.00.01   2014-12-18  visrpp  ESCAN00080359 Rule is arbitrated at end of BswM_Init even if ArbitrateOnInit is not
 *                                              enabled on any request port
 *  4.01.00   2015-01-23  visrpp  ESCAN00080777 Minimize size of LIN Variables by using a mapping table
 *            2015-01-28  visrpp  ESCAN00080895 Action lists can be executed twice if using preemptive tasks
 *  5.00.00   2015-01-30  visrpp  ESCAN00080895 AR4-1001: Support LIN schedule end notification
 *            2015-02-04  visrpp  ESCAN00081026 Mode Request of EcuM Wakeup Sources does not work for multiple sources
 *  6.00.00   2015-02-20  visrpp  ESCAN00080278 FEAT-427: SafeBSW Step I
 *            2015-04-02  visrpp  ESCAN00082221 FEAT-1377: Support Run Request Protocol of EcuM Flex
 *            2015-04-02  visrpp  ESCAN00081766 FEAT-1275: SafeBSW Step II
 *            2015-05-22  visrpp  ESCAN00082452 FEAT-109: Support of PduR Request Ports
 *            2015-06-11  visrpp  ESCAN00083354 Mode Requests which shall be arbitrated at the end of initialization
 *                                              are already arbitrated during an initiating action list
 *            2015-06-25  visrpp  ESCAN00083660 Improve MainFunction Runtime
 *            2015-06-25  visrpp  ESCAN00084363 Arbitrate BswM_WdgM_RequestPartitionReset only immediate
 *  6.00.01   2015-09-15  visrpp  ESCAN00085189 Mode Requests which occur during the execution of an initializing
 *                                              action list were not arbitrated
 *********************************************************************************************************************/
#if !defined BSWM_H
# define BSWM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "BswM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define SYSSERVICE_ASR4BSWMCFG5_VERSION          (0x0600u)
# define SYSSERVICE_ASR4BSWMCFG5_RELEASE_VERSION  (0x01u)

/* Vendor and module identification */
# define BSWM_VENDOR_ID                           (0x001Eu)
# define BSWM_MODULE_ID                           (uint16)(0x002Au)

/* AUTOSAR Software specification version information */
# define BSWM_AR_RELEASE_MAJOR_VERSION            (4u)
# define BSWM_AR_RELEASE_MINOR_VERSION            (0u)
# define BSWM_AR_RELEASE_REVISION_VERSION         (3u)

/* Component Version Information */
# define BSWM_SW_MAJOR_VERSION                    (SYSSERVICE_ASR4BSWMCFG5_VERSION >> 8u)
# define BSWM_SW_MINOR_VERSION                    (SYSSERVICE_ASR4BSWMCFG5_VERSION & 0x00FF)
# define BSWM_SW_PATCH_VERSION                    SYSSERVICE_ASR4BSWMCFG5_RELEASE_VERSION

# define BSWM_INSTANCE_ID_DET                     (0x00u)


/**********************************************************************************************************************
 *  Macros
 *********************************************************************************************************************/

/* DET error codes BswM0029 */
# define BSWM_E_NO_ERROR                 ((uint8)0x00u)  /* used to check if no error occurred                       */
# define BSWM_E_NO_INIT                  ((uint8)0x01u)  /*!< (DET): A service was called prior to initialization    */
# define BSWM_E_NULL_POINTER             ((uint8)0x02u)  /*!< (DET): A null pointer was passed as an argument        */
# define BSWM_E_PARAM_INVALID            ((uint8)0x03u)  /*!< (DET): A parameter was invalid (unspecific)            */
# define BSWM_E_REQ_USER_OUT_OF_RANGE    ((uint8)0x04u)  /*!< (DET): A requesting user was out of range              */
# define BSWM_E_REQ_MODE_OUT_OF_RANGE    ((uint8)0x05u)  /*!< (DET): A requested mode was out of range               */
# define BSWM_E_PARAM_CONFIG             ((uint8)0x06u)  /*!< (DET): The provided configuration is inconsistent      */
# define BSWM_E_ALREADY_INITIALIZED      ((uint8)0x80u)  /*!< (DET): The module is already initialized               */
# define BSWM_E_ALREADY_QUEUED           ((uint8)0xA0u)  /*!< (DET): An immediate request was made before the last
                                                                              request of the same port was processed */

/* ----- API service IDs ----- */
# define BSWM_INIT_ID                             ((uint8)0x00u)
# define BSWM_GETVERSIONINFO_ID                   ((uint8)0x01u)
# define BSWM_REQUESTMODE_ID                      ((uint8)0x02u)
# define BSWM_MAINFUNCTION_ID                     ((uint8)0x03u)
# define BSWM_DEINIT_ID                           ((uint8)0x04u)
# define BSWM_CANSM_CURRENTSTATE_ID               ((uint8)0x05u)
# define BSWM_DCM_COMMUNICATION_STATE_ID          ((uint8)0x06u)
# define BSWM_LINSM_CURRENTSTATE_ID               ((uint8)0x09u)
# define BSWM_LINSM_CURRENTSCHEDULE_ID            ((uint8)0x0Au)
# define BSWM_LINTP_REQUESTMODE_ID                ((uint8)0x0Bu)
# define BSWM_FRSM_CURRENTSTATE_ID                ((uint8)0x0Cu)
# define BSWM_ETHSM_CURRENTMODE_ID                ((uint8)0x0Du)
# define BSWM_COMM_CURRENTMODE_ID                 ((uint8)0x0Eu)
# define BSWM_ECUM_CURRENTSTATE_ID                ((uint8)0x0Fu)
# define BSWM_ECUM_CURRENTWAKEUP_ID               ((uint8)0x10u)
# define BSWM_WDGM_REQUESTPARTITIONRESET_ID       ((uint8)0x11u)
# define BSWM_DCM_APPLICATION_UPDATED_ID          ((uint8)0x14u)
# define BSWM_COMM_PNC_CURRENTMODE_ID             ((uint8)0x15u)
# define BSWM_NVM_CURRENTBLOCKMODE_ID             ((uint8)0x16u)
# define BSWM_NVM_CURRENTJOBMODE_ID               ((uint8)0x17u)
# define BSWM_J1939NM_STATE_ID                    ((uint8)0x18u)
# define BSWM_J1939DCM_BROADCASTSTATUS_ID         ((uint8)0x1bu)
# define BSWM_SD_CLIENTSERVICE_CURRENT_ID         ((uint8)0x1fu)
# define BSWM_SD_EVENTHANDLER_CURRENT_ID          ((uint8)0x20u)
# define BSWM_SD_CONSUMEDEVENTGROUP_ID            ((uint8)0x21u)
# define BSWM_ECUM_REQUESTEDSTATE_ID              ((uint8)0x23u)

/* Microsar Service IDs */
# define BSWM_INITMEMORY_ID                       ((uint8)0x80u)
# define BSWM_NM_STATE_CHANGE_ID                  ((uint8)0x81u)
# define BSWM_SWCNOTIFICATION_ID                  ((uint8)0x82u)
# define BSWM_SWCREQUESTMODE_ID                   ((uint8)0x83u)
# define BSWM_RULECONTROL_ID                      ((uint8)0x84u)
# define BSWM_LINSM_SCHEDULEENDNOTIFICATION_ID    ((uint8)0x85u)
# define BSWM_PDUR_RXINDICATION_ID                ((uint8)0x86u)
# define BSWM_PDUR_TPRXINDICATION_ID              ((uint8)0x87u)
# define BSWM_PDUR_TPSTARTOFRECEPTION_ID          ((uint8)0x88u)
# define BSWM_PDUR_TPTXCONFIRMATION_ID            ((uint8)0x89u)
# define BSWM_PDUR_TRANSMIT_ID                    ((uint8)0x8Au)
# define BSWM_PDUR_TXCONFIRMATION_ID              ((uint8)0x8Bu)

/* ----- Modes ----- */
# define BSWM_FALSE                               ((uint8)0x00u)
# define BSWM_TRUE                                ((uint8)0x01u)
# define BSWM_UNDEFINED                           ((uint8)0x02u)
# define BSWM_DEACTIVATED                         ((uint8)0x03u)

/* Timer Status */
# define BSWM_TIMER_STOPPED                       ((uint8)0x00u)
# define BSWM_TIMER_STARTED                       ((uint8)0x01u)
# define BSWM_TIMER_EXPIRED                       ((uint8)0x02u)

# define BSWM_NO_DEM_REPORT 0u


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 *  BswM_InitMemory()
 *********************************************************************************************************************/
/*!
 * \brief       Power-up memory initialization
 * \details     Initializes component variables in *_INIT_* sections at power up.
 * \pre         Module is uninitialized.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Use this function in case these variables are not initialized by the startup code.
 */
extern FUNC(void, BSWM_CODE) BswM_InitMemory(void);



/**********************************************************************************************************************
 *  BswM_Init()
 *********************************************************************************************************************/
/*!
 * \brief       Initializes component
 * \details     Initializes all component variables and sets the component state to initialized.
 * \param[in]   ConfigPtr          Component configuration structure.
 * \pre         Interrupts are disabled.
 * \pre         BswM is uninitialized.
 * \pre         BswM_InitMemory has been called unless variables in *_INIT_* section are initialized by start-up code.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Normally called by EcuM.
*/
extern FUNC(void, BSWM_CODE) BswM_Init(P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_INIT_DATA) ConfigPtr);

/**********************************************************************************************************************
 *  BswM_Deinit()
 *********************************************************************************************************************/
/*!
 * \brief       Deinitializes component.
 * \details     Sets the component state to uninitialized and removes queued mode requests.
 * \pre         BswM is initialized.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Normally called by EcuM.
*/
extern FUNC(void, BSWM_CODE) BswM_Deinit(void);


# if(BSWM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  BswM_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * \brief       Returns the version information
 * \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 * \param[out]  VersionInfo    Pointer to where to store the version information. Parameter must not be NULL.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \config      BSWM_VERSION_INFO_API
 */
extern FUNC(void, BSWM_CODE) BswM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo);
# endif

/**********************************************************************************************************************
 *  BswM_RequestMode()
 *********************************************************************************************************************/
/*!
 * \brief       Generic function call to request modes.
 * \details     This function shall only be used by other BSW modules that do not have a specific mode request interface.
 * \param[in]   requesting_user  The user that requests the mode.
 * \param[in]   requested_mode   The requested mode.
 * \pre         BswM is initialized.
 * \context     TASK
 * \reentrant   TRUE for different users
 * \synchronous TRUE
 */
extern FUNC(void, BSWM_CODE) BswM_RequestMode(BswM_UserType requesting_user, BswM_ModeType requested_mode);

# if (BSWM_ENABLE_RULE_CONTROL == STD_ON)
/**********************************************************************************************************************
 *  BswM_RuleControl()
 *********************************************************************************************************************/
/*!
 * \brief       Enables or disables arbitration of given rule.
 * \details     This function sets the intern state of a rule to the given one.
 * \param[in]   ruleId   The external ID of a Rule.
 * \param[in]   state    Disable Rule: BSWM_DEACTIVATED.
 *                       Enable Rule:  BSWM_UNDEFINED, BSWM_TRUE or BSWM_FALSE.
 * \pre         BswM is initialized.
 * \context     ANY
 * \reentrant   TRUE for different rules
 * \synchronous TRUE
 * \config      BSWM_ENABLE_RULE_CONTROL
 * \note        Normally called by an action of BswM.
 */
extern FUNC(void, BSWM_CODE) BswM_RuleControl(BswM_HandleType ruleId, uint8 state);
# endif

/**********************************************************************************************************************
 *  BswM_MainFunction()
 *********************************************************************************************************************/
/*! \fn          BswM_MainFunction
 *  \brief       Implements the processes of the BswM which need a fix cyclic scheduling.
 *  \details     Arbitrates and executes deferred rules, updates RTE Ports and decreases timers.
 *  \pre         BswM is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
/* The BswM_MainFunction definition is localized in BswM.c. The declaration is realized by SchM */

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/*!
 * \exclusivearea BSWM_EXCLUSIVE_AREA_0
 * Ensures consistency while arbitrating mode requests.
 * \protects BswM_ModeRequestQueue, BswM_ActionListQueue, BswM_QueueSemaphore, BswM_TimerState, BswM_TimerValue
 * \usedin All functions.
 * \exclude All functions provided by BswM except BswM_GetVersionInfo.
 * \length LONG This exclusive area may have a large call tree (only subroutines of BswM, no other BSW modules).
 * \endexclusivearea
 */

#endif  /* BSWM_H */

/**********************************************************************************************************************
 *  END OF FILE: BswM.h
 *********************************************************************************************************************/
