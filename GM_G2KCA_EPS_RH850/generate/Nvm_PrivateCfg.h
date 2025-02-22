/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2016 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: NvM
 *           Program: GM Global A / FR (MSR_Gm_SLP2)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701311
 *    License Scope : The usage is restricted to CBD1400351_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_PrivateCfg.h
 *   Generation Time: 2016-01-22 11:33:54
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1400351_D03
 *      Tool Version: DaVinci Configurator (beta) 5.10.26 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/* Do not modify the following parts. */
/* Modification is only allowed in the described parts */

/* ---- private section of configuration ---------------------------------- */
/* ---- used as interface to all submodules of the NvM -------------------- */

/**********************************************************************************************************************
 * PROTECTION AGAINST MULTIPLE INCLUSION
 *********************************************************************************************************************/
#if (!defined NVM_CFG_H_PRIVATE)
#define NVM_CFG_H_PRIVATE

/**********************************************************************************************************************
 * VERSION IDENTIFICATION
 *********************************************************************************************************************/
#define NVM_PRIV_CFG_MAJOR_VERSION    (5u)
#define NVM_PRIV_CFG_MINOR_VERSION    (2u)
#define NVM_PRIV_CFG_PATCH_VERSION    (0u)

/* production error */
#include "Dem.h"

/* PRQA S 3453 2 */ /* MD_MSR_19.7 */
#define NvM_SetError(ErrorCode) \
(Dem_ReportErrorStatus((ErrorCode), DEM_EVENT_STATUS_FAILED))

/* macro to mask out the DCM_BLOCK info bit (block aliasing) to obtain original BlockId */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define NVM_BLOCK_FROM_DCM_ID(blockId)   ((NvM_BlockIdType)((blockId) & ((NVM_DCM_BLOCK_OFFSET) ^ 0xFFFFu)))

#if (!defined NVM_CONFIGURATION)
/* in NvM_Cfg.c we don't need the following definitions and includes */
/* ---------------------------------------------------------------------------
 *              Configurations for Development mode
 *
 */
#if (NVM_DEV_ERROR_DETECT == STD_ON)
/* ------------------------------------------------------------------------ */

/* "Group Switches"
 * Here is a single configuration possible
 * On/Off: Check the module status
 */
# define NVM_CFG_CHK_STATUS_UNINIT  (STD_ON)

/* Switch to enable/disable Block listed/pending check on API requests */
# define NVM_CFG_CHK_BLOCK_PENDING  (STD_ON)

/* On/Off: Check the configuration of Management Type:
 * NvM_RestoreBlockDefaults() -  BlockId shall address a ROM-Block type
 * NvM_SetDataIndex()         -  BlockId shall address a Walking/Dataset
 * NvM_GetDataIndex()            Block type
 */
# define NVM_CFG_CHK_MNGMT_TYPE   (STD_ON)

/* Main on/off switches for all parameter checks */
# define NVM_CFG_DO_PARAM_CHK         (STD_ON)

/* Is the Check of Parameters enabled above? */
/* Here is a single configuration possible */
# if (NVM_CFG_DO_PARAM_CHK == STD_ON)

/* On/Off:Check parameter BlockId
 * Generally: BlockId must be smaller than NVM_NO_OF_BLOCK_IDS
 * All API-Calls (excepting NvM_GetErrorStatus()):
 * BlockId must not be 0 (MULIT_BLOCK_REQUEST status block)
 */
#  define NVM_CFG_CHK_PARAM_BLOCKID     (STD_ON)

/* On/Off: check parameter DataIndex in NvM_SetDataIndex() */
#  define NVM_CFG_CHK_PARAM_DATAINDEX   (STD_ON)

/* On/Off: check parameter Pointer in NvM_ReadBlock() */
#  define NVM_CFG_CHK_PARAM_POINTER     (STD_ON)

# else
/* Do not modify these settings */
#  define NVM_CFG_CHK_PARAM_BLOCKID    (STD_OFF)
#  define NVM_CFG_CHK_PARAM_DATAINDEX  (STD_OFF)
#  define NVM_CFG_CHK_PARAM_POINTER    (STD_OFF)
# endif

/* Notify development errors */
# define NVM_DEV_ERROR_REPORT          (STD_ON)

/* Is the reporting of Debug-Errors enabled */
# if (NVM_DEV_ERROR_REPORT == STD_ON)

/* Module Identification for the Errorhook Function as defined by AUTOSAR */

/* Include-File, which contains Errorhook-Function */
#include "Det.h"

/* User definable Errorhook */
/* PRQA S 3453 2 */ /* MD_MSR_19.7 */
#define NvM_Errorhook(ServiceId, ErrorCode) \
((void)Det_ReportError((NVM_MODULE_ID), (0u), (ServiceId), (ErrorCode)))

# else /* (NVM_DEV_ERROR_REPORT == STD_OFF) */

/* the Errorhook does nothing */
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#  define NvM_Errorhook(ServiceId, ErrorCode)

# endif  /* (NVM_DEV_ERROR_REPORT == STD_ON) */
/* ------------------------------------------------------------------------ */
/*                     Configurations for Production mode                   */
#else /* (NVM_DEV_ERROR_DETECT == STD_OFF) */
/* ------------------------------------------------------------------------ */
    /* Development mode is off, all development checks are explicitly disabled */
    /* Do not modify these settings */
# define NVM_CFG_CHK_BLOCK_PENDING    (STD_OFF)
# define NVM_CFG_CHK_STATUS_UNINIT    (STD_OFF)
# define NVM_CFG_CHK_MNGMT_TYPE       (STD_OFF)
# define NVM_CFG_CHK_PARAM_BLOCKID    (STD_OFF)
# define NVM_CFG_CHK_PARAM_DATAINDEX  (STD_OFF)
# define NVM_CFG_CHK_PARAM_POINTER    (STD_OFF)

# define NVM_CFG_DO_PARAM_CHK         (STD_OFF)
# define NVM_DEV_ERROR_REPORT          (STD_OFF)

    /* no Errorhook routine available */
    /* PRQA S 3453 1 */ /* MD_MSR_19.7 */
# define NvM_Errorhook(ServiceId, ErrorCode)

/* ------------------------------------------------------------------------ */
#endif   /*  (NVM_DEV_ERROR_DETECT == STD_ON)   */
/* ------------------------------------------------------------------------ */

/*---- NvM type definitions and defines for the submodules ---------------- */

/* defines for internal flags */
#define NVM_INTFLAG_WAIT_SET           (0x01u)
#define NVM_INTFLAG_WAIT_CL            (0xFEu)
#define NVM_INTFLAG_ERROR_SET          (0x10u)
#define NVM_INTFLAG_ERROR_CL           (0xEFu)
#define NVM_INTFLAG_DYN_MISMATCH_SET   (0x20u)
#define NVM_INTFLAG_DYN_MISMATCH_CL    (0xDFu)

/* defines for internal flags, controlled via API) */
#define NVM_APIFLAG_WRITE_ALL_SET               (0x02u)
#define NVM_APIFLAG_WRITE_ALL_CL                (0xFDu)
#define NVM_APIFLAG_READ_ALL_SET                (0x04u)
#define NVM_APIFLAG_READ_ALL_CL                 (0xFBu)
#define NVM_APIFLAG_CANCEL_WR_ALL_SET           (0x40u)
#define NVM_APIFLAG_CANCEL_WR_ALL_CL            (0xBFu)
#define NVM_APIFLAG_KILL_WR_ALL_SET             (0x80u)
#define NVM_APIFLAG_KILL_WR_ALL_CL              (0x7Fu)
#define NVM_APIFLAG_REPAIR_REDUNDANT_BLOCKS_SET (0x08u)
#define NVM_APIFLAG_REPAIR_REDUNDANT_BLOCKS_CL  (0xF7u)

/* defines for setting and clearing the internal flags */
/* PRQA S 3453 5 */ /* MD_MSR_19.7 */
#define NvM_SetIntFlag(FlagParam)   (NvM_IntFlags_u8 |= (FlagParam))

#define NvM_ClearIntFlag(FlagParam) (NvM_IntFlags_u8 &= (FlagParam))

#define NvM_PollIntFlag(FlagParam)  ((FlagParam) == (NvM_IntFlags_u8 & (FlagParam)))

#endif /* NVM_CONFIGURATION */

/* includes, we only need internally */
/* ---- Include of the interface of the MemIf module ---------------------- */
#include "MemIf.h"

#define NVM_BLOCK_TYPE_ROM          (NVM_BLOCK_NATIVE_ROM)

typedef unsigned int NvM_BitFieldType;

/* Block Management Types */
#define NVM_BLOCK_NATIVE          0u
#define NVM_BLOCK_REDUNDANT     0x01u
#define NVM_BLOCK_DATASET       0x02u

/* The blocks' RAM management area type */
typedef struct
{
    uint8                   NvDataIndex_t;
    NvM_RequestResultType   NvRamErrorStatus_u8;
    uint8                   NvRamAttributes_u8;
} NvM_RamMngmtAreaType;

typedef P2VAR(NvM_RamMngmtAreaType, AUTOMATIC, NVM_CONFIG_DATA) NvM_RamMngmtPtrType;

/* type of a callback function for the asynchron job end callbacks */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_AsyncCbkPtrType)
    (NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult);

/* type of a block init callback function pointer
 * type changed thanks to Bugzilla 11982; we use return type void,
 * because since the original return value is useless to us           */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_InitCbkPtrType)(void);

/* types of the synchronisation mechanism callback function pointer */
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_WriteRamToNvMCbkPtrType)(P2VAR(void, AUTOMATIC, NVM_APPL_DATA));
typedef P2FUNC(Std_ReturnType, NVM_APPL_CODE, NvM_ReadRamFromNvMCbkPtrType)(P2CONST(void, AUTOMATIC, NVM_APPL_DATA));

/* pointer type referencing a block of Application's RAM/ROM/CRC data,
 * the pointer itself doesn't have any memmclass assigned, at this point
 */
typedef P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_RamAddressType;
typedef P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_ConstRamAddressType;

typedef P2CONST(uint8, AUTOMATIC, NVM_APPL_CONST)NvM_RomAddressType;

/* switch the Crc functionality on or off */
#define NVM_CALC_RAM_CRC_USED STD_OFF 


#if(NVM_CRC_INT_BUFFER == STD_ON)
typedef P2VAR(uint8, AUTOMATIC, NVM_PRIVATE_DATA) NvM_RamCrcAddressType;
#endif

/* block's Flag bit mask, used in the block descriptor element "Flags_u8" */
#define NVM_BLOCK_USE_CRC_OFF                (0u)
#define NVM_BLOCK_CRC_8_ON                   (1u)
#define NVM_BLOCK_CRC_16_ON                  (2u)
#define NVM_BLOCK_CRC_32_ON                  (3u)

#define NVM_BLOCK_CRC_MASK                   (0x03)

#define NVM_CALC_RAM_BLOCK_CRC_ON            (1u)
#define NVM_CALC_RAM_BLOCK_CRC_OFF           (0u)
#define NVM_BLOCK_WRITE_PROT_ON              (2u)
#define NVM_BLOCK_WRITE_PROT_OFF             (0u)
#define NVM_BLOCK_WRITE_BLOCK_ONCE_ON        (4u)
#define NVM_BLOCK_WRITE_BLOCK_ONCE_OFF       (0u)
#define NVM_RESISTANT_TO_CHANGED_SW_ON       (8u)
#define NVM_RESISTANT_TO_CHANGED_SW_OFF      (0u)
#define NVM_SELECT_BLOCK_FOR_READALL_ON      (16u)
#define NVM_SELECT_BLOCK_FOR_READALL_OFF     (0u)
#define NVM_SELECT_BLOCK_FOR_WRITEALL_ON     (32)
#define NVM_SELECT_BLOCK_FOR_WRITEALL_OFF    (0u)


/* Either callback function (providing defaults) or ROM Defaults Block. *
 * uint32 is compatible to all pointer types (we'll need to cast)       */
typedef uint32 NvM_GenericRomDefaultsPtrType;

/* NvRam block descriptor type */
typedef struct
{
    NvM_RamAddressType      RamBlockDataAddr_t;
    NvM_RomAddressType      RomBlockDataAddr_pt;
    NvM_InitCbkPtrType      InitCallback_pt;
    NvM_AsyncCbkPtrType     CallbackFunc_pt;
    NvM_ReadRamFromNvMCbkPtrType CbkGetMirrorFunc_pt;
    NvM_WriteRamToNvMCbkPtrType CbkSetMirrorFunc_pt;
#if (STD_ON == NVM_CRC_INT_BUFFER)
    NvM_RamCrcAddressType   RamBlockCrcAddr_t;
#endif
    uint16                  NvIdentifier_u16;
    uint16                  NvBlockLength_u16;
    NvM_BitFieldType        NvBlockCount_u8 :8;
    NvM_BitFieldType        BlockPrio_u8    :8;
    NvM_BitFieldType        DeviceId_u8     :4;
    NvM_BitFieldType        MngmtType_t     :2;
    NvM_BitFieldType        CrcSettings     :2;
    NvM_BitFieldType        Flags_u8        :6;
    NvM_BitFieldType        NotifyBswM      :1;
} NvM_BlockDescriptorType;


/* pointer type to the BlockDescriptor Table or one of its entries, with the correct distance */
typedef P2CONST(NvM_BlockDescriptorType, AUTOMATIC, NVM_CONFIG_CONST) NvM_BlockDescrPtrType;

/* Internal Service Ids of the different services of the NVM */
typedef enum
{
    NVM_INT_FID_WRITE_BLOCK = 0u,
    NVM_INT_FID_READ_BLOCK,
    NVM_INT_FID_RESTORE_DEFAULTS,
    NVM_INT_FID_INVALIDATE_NV_BLOCK,
    NVM_INT_FID_ERASE_BLOCK,
    NVM_INT_FID_WRITE_ALL,
    NVM_INT_FID_READ_ALL,
    NVM_INT_FID_REPAIR_REDUNDANT_BLOCKS,
    NVM_INT_FID_NO_JOB_PENDING /* additionally denotes idle state oif NVM */
} NvM_InternalServiceIdEnumType;

/* Force implizit cast for enum NvM_InternalServiceIdEnumType into uint8 when using
 * NvM_InternalServiceIdType as data type. But only for production mode in order to
 * see not only numbers when debugging in debug mode
 */
#if (NVM_DEV_ERROR_DETECT == STD_ON)
typedef NvM_InternalServiceIdEnumType NvM_InternalServiceIdType;
#else
typedef uint8 NvM_InternalServiceIdType;
#endif

/* reference (pointer) to a queue element, actually it is just an index */
typedef uint8 NvM_QueueEntryRefType;

/* type of a queue element */
typedef struct
{
    NvM_RamAddressType          RamAddr_t;
    NvM_BlockIdType             BlockId;
    NvM_InternalServiceIdType   ServiceId;
    NvM_QueueEntryRefType       NextEntry;
    NvM_QueueEntryRefType       PrevEntry;
#if (NVM_JOB_PRIORISATION == STD_ON)
    uint8                       JobPrio;
#endif
} NvM_QueueEntryType;

typedef struct
{
    uint8 MaxIndex; /* size of immediate and normal queues - 1 */
    uint8 NpSize;   /* size of Normal Prio Queue */
} NvM_QueueSizesType;

/* defines for the block ram attribute states */
#define NVM_STATE_VALID_SET   (0x01u)
#define NVM_STATE_VALID_CL    (0xFEu)
#define NVM_STATE_CHANGED_SET (0x02u)
#define NVM_STATE_CHANGED_CL  (0xFDu)
#define NVM_WR_PROT_SET       (0x80u)
#define NVM_WR_PROT_CL        (0x7Fu)
#define NVM_LOCK_STAT_SET     (0x40u)
#define NVM_LOCK_STAT_CL      (0xBFu)
#define NVM_PRI_DEFECT_SET    (0x20u)
#define NVM_PRI_DEFECT_CL     (0xDFu)

/* defines the possible states of an NV Block, which can be determined.
 *  They are necessary for write processing of redundant NVRAM Blocks.          */
#define NVM_NVBLOCK_STATE_UPTODATE (0x00u)
#define NVM_NVBLOCK_STATE_OUTDATED (0x01u)
#define NVM_NVBLOCK_STATE_DEFECT   (0x02u)
#define NVM_NVBLOCK_STATE_UNKNOWN  (0x03u)

#define NVM_NVBLOCK_STATE_SEC_ACTIVE   (0x80u)
#define NVM_NVBLOCK_STATE_PRI_ACTIVE   (0x7Fu)

/* our state information shall contain primary, secondary block, and current block's state,
 * this current state is at the least significant position, i.e. shift = 0 */
#define NVM_PRI_NVBLOCK_STATE_SHIFT (0x5u)
#define NVM_SEC_NVBLOCK_STATE_SHIFT (0x3u)

#define NVM_NVBLOCK_STATE_BIT_MASK (0x3u)

#define NVM_USE_BLOCK_ID_CHECK STD_OFF 


/* Crc union Type */
/* PRQA S 0750 2 */ /* MD_MSR_18.4 */
typedef union
{
    uint8 CrcArray_au8[4u];
    uint16 Crc16_u16;
    uint32 Crc32_u32;
} NvM_CrcType;

/* define the base type for the CRC queue bitstring */
# define NVM_CRC_QUEUE_ENTRY_BITS     32u
# define NVM_CRC_QUEUE_BITINDEX_MASK  0x1Fu
# define NVM_CRC_QUEUE_ENTRY_SHIFT    5
# define NVM_CRC_QUEUE_ENTRY_MASK     0xFFFFFFFFu

typedef uint32 NvM_CrcQueueEntryType;

#define NVM_START_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 * NvM_EnterCriticalSection
 *********************************************************************************************************************/
/*! \brief Invoke the SchM API to enter NvM's critical section.
 *  \details Invoke the SchM API to enter NvM's critical section.
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_EnterCriticalSection(void);

/**********************************************************************************************************************
 * NvM_ExitCriticalSection
 *********************************************************************************************************************/
/*! \brief Invoke the SchM API to exit NvM's critical section.
 *  \details Invoke the SchM API to exit NvM's critical section.
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_ExitCriticalSection(void);

/**********************************************************************************************************************
 * NvM_MultiBlockCbk
 *********************************************************************************************************************/
/*! \brief Invokes multi block job end and BSWM notifications, if there are any.
 *  \details Invokes multi block job end and BSWM notifications, if there are any.
 *  \param[in] ServiceId
 *  \param[in] JobResult
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockCbk(NvM_ServiceIdType, NvM_RequestResultType);

/**********************************************************************************************************************
 * NvM_BlockNotification
 *********************************************************************************************************************/
/*! \brief Invokes single block job end and BSWM notifications, if there are any.
 *  \details Invokes single block job end and BSWM notifications, if there are any.
 *  \param[in] BlockId
 *  \param[in] ServiceId
 *  \param[in] JobResult
 *  \context TASK
 *  \reentrant FALSE
 *  \synchronous TRUE
 *  \pre -
 */
extern FUNC(void, NVM_PRIVATE_CODE) NvM_BlockNotification(NvM_BlockIdType, NvM_ServiceIdType, NvM_RequestResultType);

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#define NVM_START_SEC_VAR_NOINIT_8
#include "MemMap.h"

#if ((NVM_CRC_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON))
/* create the internal buffer */
/* PRQA S 3684 1 */ /* MD_NvM_8.12 */
extern VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalBuffer_au8[];
#endif

/* create a test buffer of size 1 byte for testing readability of a block */
extern VAR(uint8, NVM_PRIVATE_DATA) NvM_TestBuffer_u8;
    
#define NVM_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h"

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
# define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"

/* Job Queue used for normal and high prio jobs */
/* PRQA S 3684 1 *//* MD_NvM_8.12 */
extern VAR(NvM_QueueEntryType, NVM_PRIVATE_DATA) NvM_JobQueue_at[];

# define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"
#endif

#define NVM_START_SEC_CONST_8
#include "MemMap.h"

/* Variable that holds the number of write attempts (1 + retries) */
extern CONST(uint8, NVM_PRIVATE_CONST) NvM_NoOfWrAttempts_u8;

#define NVM_STOP_SEC_CONST_8
#include "MemMap.h"

#define NVM_START_SEC_CONST_16
#include "MemMap.h"

/* number of crc bytes per call of NvM_MainFunction() */
extern CONST(uint16, NVM_CONFIG_CONST) NvM_NoOfCrcBytes_u16;

/* constant holding Crc quueue size value */
extern CONST(uint16, NVM_PRIVATE_CONST) NvM_CrcQueueSize_u16;
    
#define NVM_STOP_SEC_CONST_16
#include "MemMap.h"

typedef P2CONST(struct NvM_CrcHandlerClass, AUTOMATIC, NVM_PRIVATE_CONST) NvM_CrcHandlerClassConstPtr;

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* constants holding the compiled queue size values */
extern CONST(NvM_QueueSizesType, NVM_PRIVATE_CONST) NvM_QueueSizes_t;

extern CONST(NvM_CrcHandlerClassConstPtr, NVM_PRIVATE_CONST) NvM_CrcHandlerTable_at[4];

/* Constants, holding the DEM error codes */
extern CONST(Dem_EventIdType, NVM_PRIVATE_CONST) NvM_DemErrReqFailed;
extern CONST(Dem_EventIdType, NVM_PRIVATE_CONST) NvM_DemErrIntegrityFailed;
extern CONST(Dem_EventIdType, NVM_PRIVATE_CONST) NvM_DemErrLossOfRedundancy;
extern CONST(Dem_EventIdType, NVM_PRIVATE_CONST) NvM_DemErrQueueOverflow;
extern CONST(Dem_EventIdType, NVM_PRIVATE_CONST) NvM_DemErrWriteProtected;

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 * ALL BLOCK RELATED SETTINGS
 *********************************************************************************************************************/

#define NVM_START_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

/* block descriptor table that holds the static configuration parameters
 * of the RAM, ROM and NVBlocks. This table has to be adjusted according
 * to the configuration of the NVManager
 */
 
/* PRQA S 3684 1 *//* MD_NvM_8.12 */
extern CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[];

#define NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
#include "MemMap.h"

#define NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if((NVM_SET_RAM_BLOCK_STATUS_API == STD_ON) && (NVM_CALC_RAM_CRC_USED == STD_ON))
/* Crc job queue. It's just a bit string, for performance reasons we use uint32 */
/* PRQA S 3684 1 *//* MD_NvM_8.12 */
extern VAR(NvM_CrcQueueEntryType, NVM_CONFIG_DATA) NvM_CrcQueue_at[];
#endif

#define NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h"

/* array of RAM Block Management areas, defined to be usable in block descriptor table */
/* PRQA S 3684 1 *//* MD_NvM_8.12 */
extern VAR(NvM_RamMngmtAreaType, NVM_CONFIG_DATA) NvM_BlockMngmtArea_at[];

 /* management area for DCM blocks */
extern VAR(NvM_RamMngmtAreaType, NVM_CONFIG_DATA) NvM_DcmBlockMngmt_t;

#define NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "MemMap.h"

/* ---- end private configuration section --------------------------------- */
#endif /* NVM_CFG_PRIVATE */

/*---- End of File ---------------------------------------------------------*/
    
