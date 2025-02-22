/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  NvM_Crc.h
 *    Component:  MemService_AsrNvM
 *       Module:  NvM - Submodule Crc (Crc processing)
 *    Generator:  -
 *
 *  Description:  This sub-module implements the CRC recalculation FSM that recalculates the CRC piece-wise.
 *
 *                This file is an internal include; it shall not be included by other modules than NvM!
 *
 *********************************************************************************************************************/

/* Do not modify this file! */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_CRC_H_)
#define NVM_CRC_H_

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_CRC_MAJOR_VERSION    (5u)
#define NVM_CRC_MINOR_VERSION    (2u)
#define NVM_CRC_PATCH_VERSION    (2u)

/**********************************************************************************************************************
 * MACRO DEFINITIONS
 *********************************************************************************************************************/

/* Define optimal pointer class for crc buffer, depending on NVM_CRC_INT_BUFFER setting.                            *
 * CRC buffer will either point to user RAM Block (NVM_APPL_DATA) or to an internal buffer (NVM_PRIVATE_DATE)       *
 * Since it NVM_CRC_INT_BUFFER is is pre-compile, so we can do it...                                                */
#if(STD_ON == NVM_CRC_INT_BUFFER)
# define NVM_CRC_BUFFER_PTR_CLASS NVM_PRIVATE_DATA
#else
# define NVM_CRC_BUFFER_PTR_CLASS NVM_APPL_DATA
#endif

/* PRQA S 3453 15 */ /* MD_MSR_19.7 */
#define NvM_CrcJob_GetCrcLength(selfPtr)                    ((selfPtr)->HandlerInstance_pt->crcLength)
#define NvM_CrcJob_isBusy(selfPtr)                          ((selfPtr)->RemainingLength_u16 != 0)

#define NvM_CrcJob_ReassignBuffer(selfPtr, crcPtr) ((selfPtr)->CrcBuffer = (crcPtr))

/**********************************************************************************************************************
 * API TYPE DEFINITIONS
 *********************************************************************************************************************/
typedef P2VAR(uint8, AUTOMATIC, NVM_CRC_BUFFER_PTR_CLASS) NvM_CrcBufferPtrType;
typedef P2CONST(uint8, AUTOMATIC, NVM_CRC_BUFFER_PTR_CLASS) NvM_CrcBufferConstPtrType;

typedef P2VAR(uint32, AUTOMATIC, NVM_PRIVATE_DATA) NvM_CrcValuePtrType;
typedef P2CONST(uint8, AUTOMATIC, NVM_PRIVATE_DATA) NvM_CrcValueRefType;

typedef P2FUNC(void, NVM_PRIVATE_CODE, NvM_CrcCalculateFPtr) (NvM_ConstRamAddressType, uint16, NvM_CrcValuePtrType);
typedef P2FUNC(boolean, NVM_PRIVATE_CODE, NvM_CrcCompareFPtr) (NvM_CrcBufferConstPtrType, NvM_CrcValueRefType);
typedef P2FUNC(void, NVM_PRIVATE_CODE, NvM_CrcCopyToBufferFPtr) (NvM_CrcBufferPtrType, NvM_CrcValueRefType);

struct NvM_CrcHandlerClass
{
    NvM_CrcCalculateFPtr    calc;
    NvM_CrcCompareFPtr      compare;
    NvM_CrcCopyToBufferFPtr copyToBuffer;
    uint32                  initialCrcValue;
    uint8                   crcLength;
};

typedef struct NvM_CrcJobStruct
{
    uint32                      CurrentCrcValue;
    NvM_ConstRamAddressType     RamData_pt;
    NvM_CrcBufferPtrType        CrcBuffer;
    NvM_CrcHandlerClassConstPtr HandlerInstance_pt;
    uint16                      RemainingLength_u16;
} NvM_CrcJobType;

typedef P2VAR(NvM_CrcJobType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_CrcJobPtrType;
typedef P2CONST(NvM_CrcJobType, AUTOMATIC, NVM_PRIVATE_DATA) NvM_CrcJobConstPtrType;

/**********************************************************************************************************************
 * API FUNCTIONS
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* "Dummy" Handler for Disabled CRC -> always exists */
extern CONST(struct NvM_CrcHandlerClass, NVM_PRIVATE_CONST) NvM_Crc_NoCrcHandler_t;

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_CODE
#include "MemMap.h"

#if ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && (NVM_CALC_RAM_CRC_USED == STD_ON))
/**********************************************************************************************************************
 * NvM_CrcQueueInit
 *********************************************************************************************************************/
/*! \brief Initialization of NvM's Crc_Queue
 *  \details Initialization of NvM's Crc_Queue
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \config SetRamBlockStatus Api is enabled and at least one block is configured with CalcRamCrc true
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_CrcQueueInit(void);

/**********************************************************************************************************************
 * NvM_CrcQueueJob
 *********************************************************************************************************************/
/*! \brief Function queues a CRC recalculation request for the given Block Id.
 *  \details Function queues a CRC recalculation request for the given Block Id.
 *  \param[in] BlockId
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \config SetRamBlockStatus Api is enabled and at least one block is configured with CalcRamCrc true
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_CrcQueueJob(NvM_BlockIdType);

/**********************************************************************************************************************
 * NvM_CrcGetQueuedBlockId
 *********************************************************************************************************************/
/*! \brief Function checks if there are still Crc jobs queued and returns the next block for Crc calculation.
 *  \details Function checks if there are still Crc jobs queued and returns the next block for Crc calculation.
 *  \return 0 CRC queue was empty
 *  \return next block Id for Crc calculation
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \config SetRamBlockStatus Api is enabled and at least one block is configured with CalcRamCrc true
 *  \pre -
 */
extern FUNC(NvM_BlockIdType, NVM_PRIVATE_CODE) NvM_CrcGetQueuedBlockId(void);
#endif /* ((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && (NVM_CALC_RAM_CRC_USED == STD_ON)) */

/**********************************************************************************************************************
 * NvM_CrcJob_Create
 *********************************************************************************************************************/
/*! \brief Cyclically called function, creates a Crc job.
 *  \details Creates a Crc job and if the Block Id check feature is enabled, it also will process one Crc calculation
 *           step. Within this step the Block Id and corresponding Dataindex will be added to the Crc.
 *  \param[in] descPtr
 *  \param[in] ramDataPtr
 *  \param[in, out] self
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 *  \trace CREQ-752
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_Create(NvM_CrcJobPtrType, NvM_BlockIdType, NvM_RamAddressType);

/**********************************************************************************************************************
 * NvM_CrcJob_Process
 *********************************************************************************************************************/
/*! \brief Cyclically called function for processing the CRC calculation (one step)
 *  \details Cyclically called function for processing the CRC calculation (one step)
 *  \param[in,out] self
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 *  \trace CREQ-749
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_Process(NvM_CrcJobPtrType, uint16);

/**********************************************************************************************************************
 * NvM_CrcJob_CopyToBuffer
 *********************************************************************************************************************/
/*! \brief Copy Crc into data buffer.
 *  \details Copy Crc into data buffer.
 *  \param[in,out] self
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_CopyToBuffer(NvM_CrcJobConstPtrType);

/**********************************************************************************************************************
 * NvM_CrcJob_Compare
 *********************************************************************************************************************/
/*! \brief Compare recalculated Crc against the Crc from NV RAM.
 *  \details Compare recalculated Crc against the Crc from NV RAM.
 *  \param[in] self
 *  \return TRUE Crc match
 *  \return FALSE Crc mismatch
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 */
extern FUNC(boolean, NVM_PRIVATE_CODE) NvM_CrcJob_Compare(NvM_CrcJobConstPtrType);

#if (NVM_CRC_INT_BUFFER == STD_ON)
/**********************************************************************************************************************
 * NvM_CrcJob_ExportBufferedValue
 *********************************************************************************************************************/
/*! \brief Copy Crc into the given buffer.
 *  \details Copy Crc into the given buffer.
 *  \param[in] self
 *  \param[in,out] dest_pt
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \config Crc internal buffer is enabled
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_ExportBufferedValue(NvM_CrcJobConstPtrType, NvM_CrcBufferPtrType);
#endif /* (NVM_CRC_INT_BUFFER == STD_ON) */

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* NVM_CRC_H_ */

/*---- End of File ---------------------------------------------------------*/
