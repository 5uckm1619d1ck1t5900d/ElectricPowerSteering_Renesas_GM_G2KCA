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
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Fee_Int.h
 *    Component:  If_AsrIfFee
 *       Module:  Fee
 *    Generator:  -
 *
 *  Description:  The module Fee provides an abstraction from the device specific addressing scheme and 
 *                segmentation. It also offers a virtual addressing scheme and segmentation as well as 
 *                a virtually unlimited number of erase cycles to the upper layer.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MULTIPLE INCLUSION PROTECTION
 *********************************************************************************************************************/
#if !defined (FEE_INT_H)
# define FEE_INT_H

#include "Fee_IntBase.h"
#include "Fee_PrivateCfg.h"
#include "Fee_Partition.h"
#include "Fee_Sector.h"
#include "Fee_ChunkInfo.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
# define FEE_INTERNAL_MAJOR_VERSION                                   (8u)
# define FEE_INTERNAL_MINOR_VERSION                                   (0u)
# define FEE_INTERNAL_PATCH_VERSION                                   (9u)

/******************************************************************************
 * GENERAL CONFIGURATION PARAMETER
 *****************************************************************************/
# if (STD_ON == FEE_FORCE_SECTOR_SWITCH_API)
/* Define the depth of the FSM stack. 
 * Determined from design: largest depth is reached when the Fee performs ChunkHopping during a read/write job:
 *   1. Main FSM
 *   2. SectorSwitchForced FSM
 *   3. SectorSwitch FSM
 *   4. SearchConsistent FSM
 *   5. ChunkSearch FSM
 *   6. ChunkHopping FSM
 */
#  define FEE_FSM_STACK_SIZE                                           (6u)
# else
/* Define the depth of the FSM stack. 
 * Determined from design: largest depth is reached when the Fee performs ChunkHopping during a read/write job:
 *   1. Main FSM
 *   2. Busy FSM
 *   3. SearchConsistent FSM
 *   4. ChunkSearch FSM
 *   5. ChunkHopping FSM
 */
#  define FEE_FSM_STACK_SIZE                                           (5u)
# endif

/**************************************************************************
 *  GENERAL TYPES
 *************************************************************************/
typedef uint8 Fee_FlagType;

/**************************************************************************
 *  STATES
 *************************************************************************/
/* PRQA S 0779 state_enumerators  *//* MD_FEE_5.1_identifiers */
typedef enum
{
  FEE_STATE_ALLOCATE_CHUNK_CHUNK_HOPPING_FSM,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  FEE_STATE_ALLOCATE_CHUNK_GET_WCC,
#endif
  FEE_STATE_ALLOCATE_CHUNK_WRITE_CHUNK_HEADER,
  FEE_STATE_ALLOCATE_CHUNK_WRITE_LINK,
  FEE_STATE_BUSY_PROCESS_PAYLOAD_DATA,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  FEE_STATE_BUSY_READ_CHUNK_HEADER,
#endif
  FEE_STATE_BUSY_SEARCH_CONSISTENT,
  FEE_STATE_BUSY_SEARCH_WRITTEN,
  FEE_STATE_BUSY_WRITE_PROCESSING_1,
  FEE_STATE_BUSY_WRITE_PROCESSING_2,
  FEE_STATE_CHUNK_CONSISTENCY_CHECK,
  FEE_STATE_CHUNK_LINK_PROCESSING,
  FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH,
  FEE_STATE_CHUNK_SEARCH_CHECK_RECENT_CHUNK,
  FEE_STATE_CHUNK_SEARCH_CHUNK_HOPPING,
  FEE_STATE_CHUNK_SEARCH_FOLLOW_CHUNK_LINK,
  FEE_STATE_COPY_ALLOCATE_CHUNK,
  FEE_STATE_COPY_INSTANCE_COPY,
  FEE_STATE_CREATE_INSTANCE_1_REMAINING_WRITE_STREAM,
  FEE_STATE_CREATE_INSTANCE_2_REMAINING_WRITE_STREAMS,
  FEE_STATE_CREATE_INSTANCE_3_REMAINING_WRITE_STREAMS,
  FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_READ,
  FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_WRITE,
  FEE_STATE_GET_BLOCK_EVAL_HEADER,
  FEE_STATE_IDLE,
  FEE_STATE_INSTANCE_EVALUATION_READ_TRAILER,
  FEE_STATE_INSTANCE_SEARCH_CALC_INSTANCE,
  FEE_STATE_MAIN_BUSY,
  FEE_STATE_MAIN_SECTOR_SWITCH,
  FEE_STATE_MAIN_STARTUP,
  FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH,
  FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH_RCH,
  FEE_STATE_SEARCH_CONSISTENT_INSTANCE_EVALUATION,
  FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_BINARY,
  FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_LINEARY,
  FEE_STATE_SEARCH_UPWARDS_CHECK_CHUNK,
  FEE_STATE_SEARCH_UPWARDS_CHUNK_HOPPING,
  FEE_STATE_SEARCH_UPWARDS_INSTANCE_EVALUATION,
  FEE_STATE_SEARCH_UPWARDS_READ_INSTANCE_HEADER,
  FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK,
  FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_CURRENT,
  FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_OLD,
  FEE_STATE_SEARCH_WRITTEN_FIND_NFA,
  FEE_STATE_SEARCH_WRITTEN_INSTANCE_SEARCH_BINARY,
  FEE_STATE_SECTOR_SWITCH_ALLOCATE_LINKTABLE_CHUNK,
  FEE_STATE_SECTOR_SWITCH_COPY_PROCESSING,
  FEE_STATE_SECTOR_SWITCH_FINAL,
  FEE_STATE_SECTOR_SWITCH_GET_BLOCK,
  FEE_STATE_SECTOR_SWITCH_SEARCH_CONSISTENT,
  FEE_STATE_SECTOR_SWITCH_SEARCH_UPWARDS,
  FEE_STATE_SECTOR_SWITCH_SETUP_SECTORS,
  FEE_STATE_SETUP_SECTORS_ERASING,
  FEE_STATE_SETUP_SECTORS_HEADER_WRITING,
  FEE_STATE_STARTUP_READ_SECTOR_HEADER_LOWER,
  FEE_STATE_STARTUP_READ_SECTOR_HEADER_UPPER,
  FEE_STATE_WRITE_PROCESSING_ALLOC_DATACHUNK,
  FEE_STATE_WRITE_PROCESSING_ALLOC_LINKTABLE,
  FEE_STATE_WRITE_PROCESSING_CREATE_INSTANCE,

  FEE_STATE_WAIT_FOR_WRITE_RESUME,

  FEE_STATE_NEVER_ENTERED
} Fee_StateIdType;
/* PRQA L:state_enumerators */

/* Force implizit cast for enum Fee_StateIdType into uint8 when using Fee_StateQueryType as data type. 
 * But only for production mode in order to see not only numbers when debugging.
 */
# if (STD_ON == FEE_DEV_ERROR_DETECT)
  typedef Fee_StateIdType Fee_StateType;
# else
  typedef uint8 Fee_StateType;
# endif

/**************************************************************************
 *  Type to store the job, requested by the upper layer.
 *************************************************************************/
typedef enum
{
  /* Attention:
   * The order of the values must not be changed!!! 
   * It is used in the QryReadClassJob, QryWriteClassJob and also in 
   * the JobCache functionality.
   */
  FEE_JOB_NONE = 0,
  FEE_JOB_ERASE_IMMEDIATE_BLOCK,
  FEE_JOB_INVALIDATE_BLOCK,
  FEE_JOB_WRITE,
# if (STD_ON == FEE_GET_ERASE_CYCLE_API)
    FEE_JOB_GET_ERASE_CYCLE,
# endif
# if (STD_ON == FEE_GET_WRITE_CYCLE_API)
    FEE_JOB_GET_WRITE_CYCLE,
# endif
  FEE_JOB_READ
} Fee_RequestFeeJobIdType;

/* Force implizit cast for enum Fee_RequestFlsJobIdType into uint8. 
 * But only for production mode in order to see not only numbers 
 * when debugging.
 */
# if (STD_ON == FEE_DEV_ERROR_DETECT)
  typedef Fee_RequestFeeJobIdType Fee_RequestFeeJobType;
# else
  typedef uint8 Fee_RequestFeeJobType;
# endif

/**************************************************************************
 *  Type to determine the LocalJobResult values, utilized by the Fee
 *************************************************************************/
typedef enum
{
  FEE_LOCAL_JOB_RESULT_OK = 0u,
  FEE_LOCAL_JOB_RESULT_FAILED,
  FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS,
  FEE_LOCAL_JOB_RESULT_INCONSISTENT,
  FEE_LOCAL_JOB_RESULT_INVALID,
  FEE_LOCAL_JOB_RESULT_BLOCK_COPY
} Fee_LocalJobResultIdType;

/* Force implizit cast for enum Fee_LocalJobResultIdType into uint8. 
 * But only for production mode in order to see not only numbers 
 * when debugging.
 */
# if (STD_ON == FEE_DEV_ERROR_DETECT)
  typedef Fee_LocalJobResultIdType Fee_LocalJobResultType;
# else
  typedef uint8 Fee_LocalJobResultType;
# endif

/**************************************************************************
 *  Type to determine the status of the rightest instance within a chunk
 *************************************************************************/
typedef enum
{
  FEE_INSTANCE_STATUS_OK = 0xAu,
  FEE_INSTANCE_STATUS_FAILED = 0x0u,
  FEE_INSTANCE_STATUS_EMPTY = 0x6u,
  FEE_INSTANCE_STATUS_INCONSISTENT = 0x9u,
  FEE_INSTANCE_STATUS_INVALID = 0x5u
} Fee_InstanceStatusIdType;

/* Force implizit cast for enum Fee_InstanceStatusIdType into uint8. 
 * But only for production mode in order to see not only numbers 
 * when debugging.
 */
# if (STD_ON == FEE_DEV_ERROR_DETECT)
  typedef Fee_InstanceStatusIdType Fee_InstanceStatusType;
# else
  typedef uint8 Fee_InstanceStatusType;
# endif

/**************************************************************************
 * Type which holds the Fee job parameter gotten by the API call.
 *************************************************************************/
struct Fee_FeeJobParameterStruct
{
  Fee_UserDataPtrType DataBufferPtr_pu8;
  Fee_BlockConfigRefType blockConfig_pt;
  uint16 Length_u16;
  uint16 BlockOffset_u16;
  Fee_RequestFeeJobType RequestedFeeJob_t;
  uint8 DataIndex_u8;
  sint8 PartitionIndex_s8;
};

/**************************************************************************
 * Type for the FSM stack.
 *************************************************************************/
struct Fee_FsmStackStruct
{
  Fee_StateType Stack_at[FEE_FSM_STACK_SIZE];
  uint8 TopOfStack_u8;
};

/**************************************************************************
 * Global struct which holds all RAM variables.
 *************************************************************************/

typedef P2VAR(struct Fee_GlobalVariableStruct, AUTOMATIC, FEE_VAR_NOINIT)     Fee_GlobalsPtrType;
typedef P2CONST(struct Fee_GlobalVariableStruct, AUTOMATIC, FEE_VAR_NOINIT)   Fee_GlobalsConstPtrType;

typedef P2FUNC(void, FEE_PRIVATE_CODE, Fee_DeferredFuncType) (const Fee_GlobalsPtrType);

typedef P2VAR(union Fee_InternalSharedDataUnion, AUTOMATIC, FEE_VAR_NOINIT) Fee_InternalSharedDataRefType;

typedef P2VAR(struct Fee_ChunkHoppingContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_ChunkHoppingContextRefType;

typedef P2VAR(struct Fee_InstanceSearchContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_InstanceSearchContextRefType;
typedef P2VAR(struct Fee_InstanceWriteContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_InstanceWriteContextRefType;
typedef P2VAR(struct Fee_InstanceCopyContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_InstanceCopyContextRefType;

typedef P2VAR(struct Fee_ChunkSearchContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_ChunkSearchContextRefType;
typedef P2VAR(struct Fee_ChunkAllocContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_ChunkAllocContextRefType;
typedef P2VAR(struct Fee_PartitionInitContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_PartitionInitContextRefType;
typedef P2VAR(struct Fee_SectorFormatContextStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_SectorFormatContextRefType;

typedef P2VAR(struct Fee_InstanceDescriptorStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_InstanceDescriptorRefType;

typedef P2VAR(struct Fee_SectorSwitchData, AUTOMATIC, FEE_VAR_NOINIT) Fee_SectorSwitchDataRefType;

struct Fee_ChunkHoppingContextStruct
{
    struct Fee_ChunkInfoStruct tempChunk_t;

    Fee_AddressType upperSearchLimit_t;
    Fee_BlockIdRefType resultBlockId_pt; /* OUT parameter: ID of result chunk; may be NULL_PTR */

    struct Fee_BlockIdStruct searchBlockId_t; /* similar to IP network mask: */
    struct Fee_BlockIdStruct blockIdMask_t;   /* mask bits = 1 => bits of interest, mask bits = 0 => ignore */
    uint32 headerBuffer_au32[2]   ;           /* we don't need complete 16-bytes chunk header, only first 8bytes */
};

struct Fee_InstanceWriteContextStruct
{
    Fee_SectorConfigRefType sector_pt;
    Fee_AddressType targetOffset_t;
    Fee_UserDataConstPtrType userData_pt;
    sint32 ByteCount_s32; /* since 0 is a quite valid byte count (i.e. we'd something to do), we have to allow negative values. */
    uint8 BufferBytes[FEE_INTERNAL_BUFFER_SIZE]; 
};

struct Fee_InstanceSearchContextStruct
{
    Fee_InstanceDescriptorRefType instDescr_pt;
    Fee_InstanceStatusType UppermostInstanceStatus_t; /* stores the status of the uppermost non empty instance header
                                                       * during binary instance search */
    boolean binarySearch_bl; 

    uint32 Buffer_au32[1]; /* any additionally required byte (due to Flash Page Size) is available */
};

struct Fee_InstanceCopyContextStruct
{   /* Sector information is implicitly given -> we always copy from old to new sector */
    Fee_AddressType targetOffset_t;
    Fee_AddressType sourceOffset_t;
    Fee_LengthType ByteCount_t; /* Different type than in write context! Here we don't count only payload, thus > 64KB */
    uint8 BufferBytes[FEE_INTERNAL_BUFFER_SIZE]; 
};

struct Fee_ChunkAllocContextStruct
{   
#if(FEE_GET_WRITE_CYCLE_API == STD_ON)
    Fee_InstanceDescriptorRefType wccChunk_pt;      /* pointer to most recent data chunk -> it holds current WriteCyvle counter; may not be NULL_PTR */
#endif    
    Fee_InstanceDescriptorRefType previousChunk_pt; /* pointer to previous instance descriptor structure
                                                       (to be "inherited" to instance handling, which typically follows);
                                                       content(!) will be overwritten, if new chunk was allocated */
    struct Fee_ChunkHoppingContextStruct super_t;   /* don't use its buffer for allocation! */

    struct Fee_ChunkInfoStruct newChunk_t;
    struct Fee_BlockIdStruct   blockId_t;      /* chunk's blockId */

    enum FEE_tagChunkAllocResults
    {
        FEE_CHUNK_ALLOC_OK,
        FEE_CHUNK_ALLOC_HEADER_FAILED,
        FEE_CHUNK_ALLOC_TRAILER_FAILED,
        FEE_CHUNK_ALLOC_SECTOR_FULL
    } ChunkAllocResult_t;
    uint32 buffer_au32[4];             /* We need the complete header buffer only for actual allocation */
};

struct Fee_ChunkSearchContextStruct
{   
    Fee_ChunkInfoRefType recentChunk_pt; /* validated recent chunk, basically the predecessor of mostRecentChunk */
    Fee_ChunkInfoRefType prevChunk_pt; /* may be NULL PTR, if search does not need to deliver previous chunk */
    struct Fee_ChunkInfoStruct mostRecentChunk_t; /* most recent chunk, being currently checked */
    /*we may re-use all fields. Actually, Fee_ChunkHoppingContextStruct is extended here */
    struct Fee_ChunkHoppingContextStruct super_t;
    boolean chunkHoppingForced;
    boolean chunkLinkPresent; /* for Linktables -> cleared if link-table does not contain current block's/dataset's entry */
};

struct Fee_SectorFormatContextStruct
{
    uint32 sectorHeader_au32[2];
    Fee_SectorConfigRefType sector_pt; 
    uint16 linkTableSize_u16;
    uint8 sectorId_u8;
};

struct Fee_PartitionInitContextStruct
{
    uint32 sectorHeaderData[2];
};

/* PRQA S 0750 2 *//* MD_MSR_18.4 */
union Fee_InternalSharedDataUnion
{
    struct Fee_InstanceWriteContextStruct  instanceWriteContext_t;
    struct Fee_InstanceCopyContextStruct   instanceCopyContext_t;
    struct Fee_InstanceSearchContextStruct instanceSearchContext_t;
    struct Fee_ChunkSearchContextStruct chunkSearchContext_t;
    struct Fee_SectorFormatContextStruct SectorFormatContext_t;
    struct Fee_PartitionInitContextStruct PartitionInitContext_t;
    struct Fee_ChunkAllocContextStruct ChunkAllocContext_t;
};

struct Fee_InstanceDescriptorStruct
{
    struct Fee_ChunkInfoStruct chunk_t;
    uint16 index_u16;
    Fee_InstanceStatusType status_t;
};

struct Fee_SectorSwitchData
{
    /* PRQA S 0750 2 *//* MD_MSR_18.4 */
    union
    {
        struct 
        {
            uint16 BlockConfigIndex_u16;
            sint16 DataIndex_s16; /* sint16 to allow values smaller than 0 */
        }   appl;
        struct Fee_ChunkInfoStruct fbl;
    } mode;
    sint8 partitionId_s8;
};

typedef struct Fee_GlobalVariableStruct
{
    Fee_ConfigRefType Config_pt;
    Fee_ChunkHoppingContextRefType chunkHoppingContext_pt; /* shall be used by Chunk-Hopping FSM */
    union Fee_InternalSharedDataUnion FsmLocalVars_t;
    Fee_DeferredFuncType DeferredWriteAction_pt;
    struct Fee_ChunkInfoStruct PreviousChunk_t;

    struct Fee_InstanceDescriptorStruct CurrentDataset_t;
    struct Fee_InstanceDescriptorStruct SectorSwitchTarget_t;

    struct
    {   
        Fee_PartitionConfigRefType Partition_pt;
        Fee_BlockConfigRefType BlockConfig_pt;
        struct Fee_BlockIdStruct BlockId;
    } CurrentProcessData;
    struct Fee_FeeJobParameterStruct FeeJobParameter_t;
    struct Fee_SectorSwitchData SectorSwitchData_t;
    Fee_FlagType InternalFlags_t; /* flags only written by MainFunctuion; no sync necessary */
    Fee_FlagType ApiFlags_t;      /* flags written via API and MainFunction; sync IS necessary */
    Fee_LocalJobResultType FeeLocalJobResult_t;
    MemIf_StatusType FeeModuleStatus_t;
    MemIf_JobResultType FeeJobResult_t;
    MemIf_JobResultType FlsJobResult_t;
    struct Fee_FsmStackStruct FsmStack_t;
    
    /* Flag indicating suspension of Write Accesses.                            *
     *  Separated from other flags to avoid necessity of access synchronization */
    boolean WritesSuspended_bl;
} Fee_GlobalVariableType;

#define FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 1404 1*/ /* MISRA Rule 8.10: external linkage is required to allow debugging according to AUTOSAR */
extern VAR(Fee_GlobalVariableType, FEE_VAR_NOINIT) Fee_Globals_t;

#define FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* FEE_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_Int.h
 *********************************************************************************************************************/
