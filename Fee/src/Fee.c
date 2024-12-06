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
 *         File:  Fee.c
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
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Fee.h"
#include "Fee_Int.h"
#include "Fee_Cbk.h"

#ifdef FEE_TESTING_LOG_TRANSITIONS
#    include "TsxFee_FsmLogger.h"
#endif

/* include for SIP-check */
#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
# include "v_ver.h"
#endif /* V_SUPPRESS_EXTENDED_VERSION_CHECK */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (FEE_SW_MAJOR_VERSION != (8u)) \
    || (FEE_SW_MINOR_VERSION != (0u)) )
# error "Vendor specific version numbers of Fee.c and Fee.h are inconsistent"
#endif

/* versions of all included header files shall be checked */
#if (  (FEE_CFG_MAJOR_VERSION != (8u)) \
    || (FEE_CFG_MINOR_VERSION != (0u)) )
# error "Version numbers of Fee.c and Fee_Cfg.h are inconsistent!"
#endif

#if (  (FEE_PRIVATE_CFG_MAJOR_VERSION != (8u)) \
    || (FEE_PRIVATE_CFG_MINOR_VERSION != (0u)) )
# error "Version numbers of Fee.c and Fee_PrivateCfg.h are inconsistent!"
#endif

#if (  (FEE_INTERNAL_MAJOR_VERSION != (8u)) \
    || (FEE_INTERNAL_MINOR_VERSION != (0u)) )
# error "Version numbers of Fee.c and Fee_Int.h are inconsistent!"
#endif

#if (  (FEE_CBK_MAJOR_VERSION != (8u)) \
    || (FEE_CBK_MINOR_VERSION != (0u)) )
# error "Version numbers of Fee.c and Fee_Cbk.h are inconsistent!"
#endif

/***************** FEE Notification functions ******************************/

#ifndef FEE_NFY_SS_THRESHOLD
#   define FEE_NFY_SS_THRESHOLD(globals)
#endif

#ifndef FEE_NFY_SS_START
#   define FEE_NFY_SS_START(globals)
#endif

#ifndef FEE_NFY_SS_END
#   define FEE_NFY_SS_END(globals)
#endif

#ifndef FEE_NFY_SECTOR_ERASE
#   define FEE_NFY_SECTOR_ERASE(globals)
#endif
#ifndef FEE_NFY_SECTOR_ERASE_END
#   define FEE_NFY_SECTOR_ERASE_END(globals, result)
#endif
#ifndef FEE_NFY_CHUNK_HEADER_WRITE
#   define FEE_NFY_CHUNK_HEADER_WRITE(globals)
#endif 
#ifndef FEE_NFY_CHUNK_HEADER_WRITE_END
#   define FEE_NFY_CHUNK_HEADER_WRITE_END(globals, result)
#endif

#ifndef FEE_NFY_CHUNK_LINK_WRITE
#   define FEE_NFY_CHUNK_LINK_WRITE(globals)
#endif 
/*  FEE_NFY_CHUNK_LINK_WRITE_END(globals, result)
 *  if undefined it must remain undefined, as it affects actions,action table, and FSM
 */

#ifndef FEE_NFY_INSTANCE_WRITE
#   define FEE_NFY_INSTANCE_WRITE(globals)
#endif
/*  FEE_NFY_INSTANCE_WRITE_END(globals, result)
 *  if undefined it must remain undefined, as it affects actions,action table, and FSM
 */

#ifndef FEE_NFY_INSTANCE_COPY
#   define FEE_NFY_INSTANCE_COPY(globals)
#endif
/* FEE_NFY_INSTANCE_COPY_END(globals, result)
 *  if undefined it must remain undefined, as it affects actions,action table, and FSM
 */

#ifndef FEE_NFY_WRITE_SUSPENDED
#   define FEE_NFY_WRITE_SUSPENDED(globals)
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* "Long Lasting Critical Sections" - a deprecated feature
 *  We'd like to maintain compatibility with newer and older Generator versions.          *
 * For newer ones (Generator 3.xx.xx) we still new the macro definitions (though empty);  *
 * For older ones we don't want to re-define them...                                      */
#ifndef Fee_GlobalSuspendLong
#   define Fee_GlobalSuspendLong() 
#endif

#ifndef Fee_GlobalRestoreLong
#    define Fee_GlobalRestoreLong() 
#endif

/******************************************************************************
 *  FLAGS and MASKS
 *****************************************************************************/
#define FEE_FLAG_WAIT                                                 (0x01u)
#define FEE_FLAG_WAIT_MASK                                            (0xFEu)
#define FEE_FLAG_BINARY_INSTANCE_SEARCH                               (0x02u)
#define FEE_FLAG_BINARY_INSTANCE_SEARCH_MASK                          (0xFDu)
#define FEE_FLAG_BROKEN_LINK                                          (0x04u)
#define FEE_FLAG_BROKEN_LINK_MASK                                     (0xFBu)
#define FEE_FLAG_JOB_DEFERRED                                         (0x08u)
#define FEE_FLAG_JOB_DEFERRED_MASK                                    (0xF7u)

#define FEE_FLAG_FORCE_SECTOR_SWITCH                                  (0x10u)

#define FEE_API_FLAG_FORCE_FBL_MODE                                   (0x01u)
#define FEE_API_FLAG_FORCE_SECTOR_SWITCH                              (0x10u)
#define FEE_API_FLAG_CANCEL                                           (0x20u)
#define FEE_API_FLAG_ENABLE_BSS                                       (0x40u)
#define FEE_API_FLAG_ENABLE_FSS                                       (0x80u)

#    define FEE_IS_IN_FBL_MODE(globals) ((globals)->Config_pt->Fee_ConfigurationIncomplete != 0) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/******************************************************************************
 *  FLASH MEMORY MANAGEMENT CONTAINER SIZES
 *****************************************************************************/

/******************************************************************************
 *  STATE MACHINE
 *****************************************************************************/
/* The maximum number of conditional exits a state can have, 
 * the final ("else") exit is implicitly.
 */
#define FEE_MAX_NUM_OF_STATE_CONDITIONS                               (0x03u)

/* The maximum number of Query functions that can be AND'ed together 
 * to form a state exit condition.
 */
#define FEE_MAX_NUM_OF_QRY_AND                                        (0x02u)

/******************************************************************************
 *  RESERVED BLOCK IDS
 *****************************************************************************/
#define FEE_RESERVED_BLOCK_NUMBER_1                                   (0x0000u)
#define FEE_RESERVED_BLOCK_NUMBER_2                                   (0xFFFFu)

/******************************************************************************
 * GENERAL CONFIGURATION PARAMETERS
 *****************************************************************************/
/* Dataset selection bits mask is used to get the real block ID of the block number. */
#define FEE_DATASET_SELECTION_BITS_MASK                               (uint16)(((uint16)1u << Fee_Globals_t.Config_pt->Fee_DatasetSelectionBits_u8) - (uint16)1u)

/* Defines the inverted DataSet selection bit mask, which is needed to increment SectorSwitchBlockNumber */
#define FEE_DATASET_SELECTION_BITS_MASK_INVERTED                      ((uint16)0xFFFFu ^ (uint16)FEE_DATASET_SELECTION_BITS_MASK)

/* Defines the inverted PageSize mask which is needed to calculate a multiple of the PageSize. */
#define FEE_FLS_PAGE_SIZE_MASK_INVERTED                               (~(Fee_LengthType)(FEE_FLS_PAGE_SIZE_WRITE - 1u))

/* Defines the mask of the internal buffer to calculate the remaining bytes to copy in the last write stream. */
#define FEE_INTERNAL_BUFFER_SIZE_MASK                                 ((uint8)FEE_INTERNAL_BUFFER_SIZE - (uint8)1u)

/* Defines to select the array of the SectorConfigType or just to distinguish between both sectors. */
#define FEE_LOWER_SECTOR_NUMBER                                       (0u)
#define FEE_UPPER_SECTOR_NUMBER                                       (1u)

/* Determining the location of the lower and upper sector header within the data buffer of the Fee. 
 * Needed not to overwrite the lower sector header after the startup to evaluate both sector headers content. 
 * The upper sector header location value is shifted, because the array is built up on an uint32 data type.
 */
#define FEE_BUFFER_LOCATION_LOWER_SECTOR_HEADER                       (0u)
#define FEE_BUFFER_LOCATION_UPPER_SECTOR_HEADER                       (FEE_SECTOR_HEADER_SIZE >> 2u)

/* If the WriteCycle could not be read from the chunk header the reason is described by the corresponding defines. */
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
# define FEE_WRITE_CYCLE_EMPTY                                        (0)
# define FEE_WRITE_CYCLE_FAILED                                       (0xFFFFFFFEuL)
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(Fee_StateType, AUTOMATIC, FEE_PRIVATE_DATA) Fee_StateRefType;
typedef P2CONST(struct Fee_StateDescrStruct, AUTOMATIC, FEE_PRIVATE_CONST) Fee_StateDescriptorConstRefType;

typedef P2VAR(struct Fee_FsmStackStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_FsmStackRefType;

/********************************************************************
 *  ACTIONS
 *******************************************************************/
/* PRQA S 0779 action_enumerators *//* MD_FEE_5.1_identifiers */
typedef enum
{
  FEE_ACT_ID_CALCULATE_NEXT_INSTANCE_INDEX,
  FEE_ACT_ID_EVALUATE_CHUNK_HOPPING,
  FEE_ACT_ID_EVALUATE_INSTANCE_TRAILER,
  FEE_ACT_ID_EVALUATE_SECTOR_HEADERS,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  FEE_ACT_ID_EVALUATE_WRITE_CYCLE,
#endif
    FEE_ACT_ID_FINALIZE_CHUNK_SEARCH,
#ifdef FEE_NFY_CHUNK_LINK_WRITE_END
  FEE_ACT_ID_FINALIZE_CHUNK_LINK_WRITE,
#else
#   define FEE_ACT_ID_FINALIZE_CHUNK_LINK_WRITE FEE_ACT_ID_NOP
#endif
  FEE_ACT_ID_FINALIZE_CHUNK_ALLOCATION,
#if (STD_ON == FEE_GET_ERASE_CYCLE_API)
    FEE_ACT_ID_FINALIZE_ERASE_CYCLE_JOB,
#endif
  FEE_ACT_ID_FINALIZE_GET_NEXT_BLOCK_FSM,
#ifdef FEE_NFY_INSTANCE_WRITE_END
  FEE_ACT_ID_FINALIZE_INSTANCE_WRITE,
#else
#   define FEE_ACT_ID_FINALIZE_INSTANCE_WRITE FEE_ACT_ID_NOP
#endif
#ifdef FEE_NFY_INSTANCE_COPY_END
  FEE_ACT_ID_FINALIZE_INSTANCE_COPY,
#else
#   define FEE_ACT_ID_FINALIZE_INSTANCE_COPY FEE_ACT_ID_NOP
#endif
  FEE_ACT_ID_FINALIZE_JOB,
  FEE_ACT_ID_FINALIZE_BLOCK_COPY,
  FEE_ACT_ID_FINALIZE_SS_COPYING,
  FEE_ACT_ID_FINALIZE_SECTOR_SWITCH_FSM,
  FEE_ACT_ID_FINALIZE_SETUP_SECTORS,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
    FEE_ACT_ID_FINALIZE_WRITE_CYCLE_JOB,
#endif
  FEE_ACT_ID_GET_CURRENT_CHUNK_INFO,
  FEE_ACT_ID_INCREMENT_TO_NEXT_INSTANCE_INDEX,
  FEE_ACT_ID_INIT_ALLOCATE_CHUNK_FSM,
  FEE_ACT_ID_INIT_CHUNK_ALLOC_COPY_FSM,
  FEE_ACT_ID_INIT_DATACHUNK_ALLOC_WRITE_FSM,
  FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM,
  FEE_ACT_ID_INIT_CHUNK_SEARCH_FSM,
  FEE_ACT_ID_INIT_CHUNK_HEADER_CHECK_FSM,
  FEE_ACT_ID_INIT_COPY_PROCESS_FSM,
  FEE_ACT_ID_INIT_CREATE_INSTANCE_FSM,
  FEE_ACT_ID_INITIALIZE_BLOCK_COPY,
  FEE_ACT_ID_INIT_INSTANCE_EVALUATION_FSM,
  FEE_ACT_ID_INIT_INSTANCE_EVALUATION_UPWARDS_FSM,
  FEE_ACT_ID_INIT_INSTANCE_SEARCH_BINARY_FSM,
  FEE_ACT_ID_INIT_INSTANCE_SEARCH_LINEARY_FSM,
  FEE_ACT_ID_INIT_INSTANCE_SEARCH_UPWARDS,
  FEE_ACT_ID_INIT_LINKTABLE_ALLOCATION,
  FEE_ACT_ID_INIT_REVERSE_CHUNK_SEARCH,
  FEE_ACT_ID_INIT_SEARCH_WRITTEN_IN_OLD_SECTOR,
  FEE_ACT_ID_INIT_SEARCH_UPWARDS_FSM,
  FEE_ACT_ID_CONTINUE_UPWARDS_CHUNK_SEARCH,
  FEE_ACT_ID_INIT_SETUP_SECTORS_FSM,
  FEE_ACT_ID_SETUP_SECTORS_WRITE_HEADER,
  FEE_ACT_ID_INIT_SEARCH_FOR_NFA_WRITE,
  FEE_ACT_ID_FINALIZE_SEARCH_FOR_NFA_WRITE,
  FEE_ACT_ID_PRE_INIT_WRITE_PROCESSING,
  FEE_ACT_ID_INIT_WRITE_PROCESSING_FSM,
  FEE_ACT_ID_ALLOC_IN_CURRENT_SECTOR,
  FEE_ACT_ID_NOP,
  FEE_ACT_ID_PREPARE_BLOCK_COPY_READ,
  FEE_ACT_ID_PREPARE_BLOCK_COPY_WRITE,
  FEE_ACT_ID_PREPARE_CHUNK_HEADER_WRITE,
  FEE_ACT_ID_PREPARE_CHUNK_LINK_READ_OF_CURRENT_CHUNK,
  FEE_ACT_ID_PREPARE_CHUNK_LINK_WRITE,
  FEE_ACT_ID_PREPARE_INSTANCE_HEADER_READ,
  FEE_ACT_ID_PREPARE_PAYLOAD_DATA_PROCESSING,
  FEE_ACT_ID_CONTINUE_SEARCH_FOR_NFA,
  FEE_ACT_ID_PREPARE_SECTOR_HEADER_UPPER_READ,
#if(FEE_GET_WRITE_CYCLE_API == STD_ON)
  FEE_ACT_ID_PREPARE_WCC_READ,
#endif
  FEE_ACT_ID_PREPARE_WRITE_STREAM_LAST,
  FEE_ACT_ID_PREPARE_WRITE_STREAM_SECOND,
  FEE_ACT_ID_REPORT_SECTOR_OVERFLOW,
  FEE_ACT_ID_ResetChunkSearch,
  FEE_ACT_ID_RETURN_FROM_SUB_FSM,
  FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED,
  FEE_ACT_ID_SET_LOCAL_JOB_RESULT_INVALID,
  FEE_ACT_ID_SET_LOCAL_JOB_RESULT_OK,
  FEE_ACT_ID_SETUP_SECTOR_SWITCH_SOURCE_SEARCH,
  FEE_ACT_ID_SWITCH_OPERATING_SECTOR,
  FEE_ACT_ID_VALIDATE_CHUNK_LINK,
  FEE_ACT_ID_CHECK_CHUNK_CONSISTENCY,
  FEE_ACT_ID_CHECK_WRITE_SUSP,
  FEE_ACT_ID_WAIT /* must be the last action */
} Fee_StateActionIdType;
/* PRQA L:action_enumerators */

/* Force implicit cast for enum Fee_StateActionIdType into uint8 when using Fee_StateActionType as data type.
 * But only for production mode in order to see not only numbers when debugging.
 */
#if (STD_ON == FEE_DEV_ERROR_DETECT)
  typedef Fee_StateActionIdType Fee_StateActionType;
#else
  typedef uint8 Fee_StateActionType;
#endif

/********************************************************************
 *  QUERIES
 *******************************************************************/
typedef enum
{
  FEE_QRY_ID_BLOCK_PAYLOAD_UPDATED,
  FEE_QRY_ID_BLOCK_COPY_NOT_FINISHED,
  FEE_QRY_ID_CHUNK_IS_DATA_CHUNK,
  FEE_QRY_ID_CHUNK_NOT_FULL,
  FEE_QRY_ID_ERASED_VALUE,
  FEE_QRY_ID_FLS_BUSY,
  FEE_QRY_ID_FLS_JOB_RESULT_OK,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  FEE_QRY_ID_GET_WRITE_CYCLE_JOB,
#endif
  FEE_QRY_ID_LOCAL_JOB_RESULT_EMPTY_CHUNKS,
  FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED,
  FEE_QRY_ID_LOCAL_JOB_RESULT_INVALID,
  FEE_QRY_ID_LOCAL_JOB_RESULT_OK,
  FEE_QRY_ID_MAY_FOLLOW_LINKS,
  FEE_QRY_ID_PREVIOUS_INSTANCE_AVAILABLE,
  
  FEE_QRY_ID_RECENT_CHUNK_LINK_CONSISTENT,
  FEE_QRY_ID_SEARCHING_IN_CURRENT_SECTOR,
  FEE_QRY_ID_VALID_INSTANCE_WRITTEN,
  FEE_QRY_ID_TRUE
} Fee_StateQueryIdType;

/* Force implicit cast for enum Fee_StateQueryIdType into uint8 when using Fee_StateQueryType as data type. 
 * But only for production mode in order to see not only numbers when debugging.
 */
#if (STD_ON == FEE_DEV_ERROR_DETECT)
  typedef Fee_StateQueryIdType Fee_StateQueryType;
#else
  typedef uint8 Fee_StateQueryType;
#endif

/********************************************************************
 *  STATE MACHINE
 *******************************************************************/
/* Listing of the pointers to the action functions. */
typedef struct
{
  Fee_StateActionType ActionHandler1_t;
  Fee_StateActionType ActionHandler2_t;
} Fee_StateChangeActionsType;

/* Pointer to a query table (defined later). */
typedef P2CONST(Fee_StateQueryType, AUTOMATIC, FEE_PRIVATE_CONST) Fee_StateQueryPtrType;

/* Pointer to a set of action functions. */
typedef P2CONST(Fee_StateChangeActionsType, AUTOMATIC, FEE_PRIVATE_CONST) Fee_StateChangeActionsPtrType;

/* Describe one state exit with its condition, its actions and its following state. */
typedef struct
{
  Fee_StateQueryType         Queries_at[FEE_MAX_NUM_OF_QRY_AND];
  Fee_StateChangeActionsType Actions_t;
  Fee_StateType              NextState_t;
} Fee_StateChangeIfDescrType;

/* Describe the final state exit ("else") to be taken if no condition matched. */
typedef struct
{
  Fee_StateChangeActionsType Actions_t;
  Fee_StateType              NextState_t;
} Fee_StateChangeElseDescrType;

/* Describe a state with it's possible change conditions. */
struct Fee_StateDescrStruct
{
  Fee_StateChangeIfDescrType ChangeConditions_at[FEE_MAX_NUM_OF_STATE_CONDITIONS];
  Fee_StateChangeElseDescrType FinalCondition_t;
};

/* Type of a query function pointer. */
typedef P2FUNC(boolean, FEE_PRIVATE_CODE, Fee_QryFctPtrType)(void);

/* Type of an action function pointer. */
typedef P2FUNC(void, FEE_PRIVATE_CODE, Fee_ActFctPtrType)(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/******************************************************************************
 *  ACTIONS
 *****************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActCalculateNextInstanceIndex(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActContinueUpwardsChunkSearch(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateChunkHopping(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateInstanceTrailer(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateSectorHeaders(void);
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateWriteCycle(void);
#endif

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeChunkSearch(void);

#ifdef FEE_NFY_CHUNK_LINK_WRITE_END
    static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeChunkLinkWrite(void);
#endif
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeChunkAllocation(void);

#if (STD_ON == FEE_GET_ERASE_CYCLE_API)
  static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeEraseCycleJob(void);
#endif

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeGetNextBlockFsm(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeBlockCopy(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSsCopying(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSectorSwitchFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSetupSectors(void);

#ifdef FEE_NFY_INSTANCE_WRITE_END 
    static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeInstanceWrite(void);
#endif

#ifdef FEE_NFY_INSTANCE_COPY_END 
    static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeInstanceCopy(void);
#endif

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeJob(void);

#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeWriteCycleJob(void);
  static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareWccRead(void);
#endif

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActGetCurrentChunkInfo(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActIncrementToNextInstanceIndex(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitAllocateChunkFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkHoppingFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkSearchFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkHeaderCheckFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitCopyProcessFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitCreateInstanceFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceEvaluationFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceEvaluationUpwardsFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceSearchBinaryFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceSearchLinearyFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceSearchUpwards(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitLinkTableAllocationFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitReverseChunkSearch(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchWrittenInOldSector(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchUpwardsFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchWrittenFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSetupSectorsFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetupSectorsWriteHeader(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchForNfa_WriteFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSearchForNfa_WriteFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPreInitWriteProcessing(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitWriteProcessingFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkAllocCopyFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitDataChunkAllocWriteFsm(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActAllocationInCurrentSector(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitializeBlockCopy(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActNop(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareBlockCopyRead(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareBlockCopyWrite(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareChunkHeaderWrite(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareChunkLinkReadOfCurrentChunk(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareChunkLinkWrite(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareInstanceHeaderRead(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareInstanceTrailerRead(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPreparePayloadDataProcessing(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActContinueSearchForNfA(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareSectorHeaderUpperRead(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareWriteStreamLast(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareWriteStreamSecond(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActReportSectorOverflow(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActResetChunkSearch(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActReturnFromSubFsm(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetLocalJobResultFailed(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetLocalJobResultInvalid(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetLocalJobResultOk(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetupSectorSwitchSourceSearch(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSwitchOperatingSector(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActValidateChunkLink(void);
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActCheckChunkConsistency(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActCheckWriteSuspension(void);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActWait(void);

/******************************************************************************
 *  QUERIES
 *****************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryBlockPayloadUpdated(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryBlockCopyNotFinished(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryChunkIsDataChunk(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryChunkNotFull(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryInstHeaderErasedValue(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryFlsBusy(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryFlsJobResultOk(void);
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryGetWriteCycleJob(void);
#endif
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultEmptyChunks(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultFailed(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultInvalid(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultOk(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryMayFollowLinks(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryPreviousInstanceAvailable(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryRecentChunkLinkConsistent(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QrySearchingInCurrentSector(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryTrue(void);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryValidInstanceWritten(void);

/******************************************************************************
 *  INTERNAL FUNCTIONS
 *****************************************************************************/
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
  static FUNC(Std_ReturnType, FEE_PRIVATE_CODE) Fee_DetChkUninit(const uint8 ApiId_u8loc);
#endif
#if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)
  static FUNC(Std_ReturnType, FEE_PRIVATE_CODE) Fee_DetChkBlockNumber
  (
    const uint8 ApiId_u8, const uint16 BlockNumber_u16
  );
#endif
static FUNC(void, FEE_PRIVATE_CODE) Fee_Fsm(Fee_StateRefType State_pt);

#ifdef FEE_TESTING_LOG_TRANSITIONS
    static FUNC(boolean, FEE_PRIVATE_CODE) Fee_FsmQuery (Fee_StateQueryPtrType Queries_at, TsxFee_LogExecutedQueries* executed);
#else
    /* PRQA S 3453 1 */ /* MD_MSR_19.7 */
    #define Fee_FsmQuery(queries, log) (Fee_FsmQueryImpl(queries))
    static FUNC(boolean, FEE_PRIVATE_CODE) Fee_FsmQueryImpl (Fee_StateQueryPtrType Queries_at);
#endif

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalActInitFsm(
    Fee_FsmStackRefType FsmStack,
    const Fee_StateType InitState_t);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalApiInit
(
  uint16 BlockNumber_u16,
  Fee_RequestFeeJobType RequestedJob_t
);

static FUNC(uint16, FEE_PRIVATE_CODE) Fee_InternalGetBlockId(const uint16 BlockNumber_u16);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalGetNextBlockToCopy(Fee_GlobalsPtrType  globals);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalFillInstanceBuffer(
    const Fee_IntBuffer_u8PtrType instBuf, const Fee_UserDataConstPtrType userBuf, const uint16 length);

static FUNC(Fee_InstanceStatusType, FEE_PRIVATE_CODE) Fee_InternalEvaluateInstanceStatus(
                                                Fee_SectorConfigRefType sector_pt,
                                                Fee_IntBuffer_u8ConstPtrType intBuf_au8, MemIf_JobResultType flsResult);

static FUNC(Fee_InstanceStatusType, FEE_PRIVATE_CODE) Fee_InternalEvalInstHdrStatus(
                                                Fee_SectorConfigRefType sector_pt,
                                                Fee_IntBuffer_u32ConstPtrType intBuf_au32, MemIf_JobResultType flsResult);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalPrepareEmptyInstanceWrite(Fee_SectorConfigRefType sector, Fee_AddressType addr, Fee_InstanceStatusType status);

static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalScheduleProcess(Fee_GlobalsPtrType globals);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalInitPartitionInitializationFsm(Fee_GlobalsPtrType globals,
                                                                                 Fee_PartitionConfigRefType part);
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalInitBusyFsm(Fee_GlobalsPtrType globals, Fee_PartitionConfigRefType jobPartition_pt);

static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalInitSectorSwitchFsm(Fee_GlobalsPtrType globals, Fee_PartitionConfigRefType partition);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalRequestSectorSwitch(Fee_GlobalsPtrType globals, Fee_PartitionConfigRefType partition);
static FUNC(void , FEE_PRIVATE_CODE) Fee_InternalResetSectorSwitch(Fee_SectorSwitchDataRefType self, boolean isFblMode);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalInitSearchForNfaFsm(Fee_GlobalsPtrType globals_pt,
                                                                    Fee_SectorConfigRefType sector_pt);

static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalIsCancelableOperation(Fee_GlobalsConstPtrType globals);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalEvalFlsRetVal(enum Fee_FlsRequestStatus);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalClearApiFlags(const Fee_GlobalsPtrType globals, Fee_FlagType flags);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalWriteSuspendHandling(const Fee_GlobalsPtrType, const Fee_DeferredFuncType);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalInitChunkHoppingFsm(Fee_GlobalsPtrType, Fee_ChunkHoppingContextRefType);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoWriteStreamFirst(const Fee_GlobalsPtrType);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoWriteStreamSecond(const Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoWriteStreamLast(const Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoBlockCopyWrite(const Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoEmptyInstanceWrite(const Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoSectorErase(const Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoSectorHeaderWrite(const Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoChunkHeaderWrite(const Fee_GlobalsPtrType globals);

static FUNC(void , FEE_PRIVATE_CODE) Fee_ChunkSearchContext_Init(Fee_ChunkSearchContextRefType self,
                                                                 Fee_BlockIdConstRefType blockId_pt,
                                                                 Fee_ChunkInfoRefType prevChunk_pt,
                                                                 Fee_ChunkInfoRefType recentChunk_pt,
                                                                 Fee_AddressType upperLimit_t);

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA VARIABLE
 *********************************************************************************************************************/
#define FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Fee_GlobalVariableType, FEE_VAR_NOINIT) Fee_Globals_t;

#define FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
# define FEE_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

    static VAR(MemIf_StatusType, FEE_VAR) Fee_ModuleStatus_t = MEMIF_UNINIT;

# define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* SIP-check */
#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
CONST(uint32, FEE_CONST) IF_ASRIFFEE_LIB_SYMBOL = (uint32)IF_ASRIFFEE_LIB_VERSION;
#endif /* V_SUPPRESS_EXTENDED_VERSION_CHECK */

/******************************************************************************
 *  ACTIONS
 *****************************************************************************/
static CONST(Fee_ActFctPtrType, FEE_PRIVATE_CONST) Fee_ActionTable_ap[FEE_ACT_ID_WAIT + 1] =      /* PRQA S 3218 */ /* MISRA-C:2004 Rule     Due to the usage of MemMap.h, variables and constants cannot be defined "static" within functions, because the necessary encapsulation in MemMap.h includes would not work. Consequently it is necessary to use static here, to avoid the nesting of sections in functions. Furthermore this variable is to large to locate it on the stack. */
{
  Fee_ActCalculateNextInstanceIndex,
  Fee_ActEvaluateChunkHopping,
  Fee_ActEvaluateInstanceTrailer,
  Fee_ActEvaluateSectorHeaders,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  Fee_ActEvaluateWriteCycle,
#endif
  Fee_ActFinalizeChunkSearch,
#ifdef FEE_NFY_CHUNK_LINK_WRITE_END
  Fee_ActFinalizeChunkLinkWrite,
#endif
  Fee_ActFinalizeChunkAllocation,
#if (STD_ON == FEE_GET_ERASE_CYCLE_API)
  Fee_ActFinalizeEraseCycleJob,
#endif
  Fee_ActFinalizeGetNextBlockFsm,
#ifdef FEE_NFY_INSTANCE_WRITE_END
  Fee_ActFinalizeInstanceWrite,
#endif
#ifdef FEE_NFY_INSTANCE_COPY_END
  Fee_ActFinalizeInstanceCopy,
#endif
  Fee_ActFinalizeJob,
  Fee_ActFinalizeBlockCopy,
  Fee_ActFinalizeSsCopying,
  Fee_ActFinalizeSectorSwitchFsm,
  Fee_ActFinalizeSetupSectors,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  Fee_ActFinalizeWriteCycleJob,
#endif
  Fee_ActGetCurrentChunkInfo,
  Fee_ActIncrementToNextInstanceIndex,
  Fee_ActInitAllocateChunkFsm,
  Fee_ActInitChunkAllocCopyFsm,
  Fee_ActInitDataChunkAllocWriteFsm,
  Fee_ActInitChunkHoppingFsm,
  Fee_ActInitChunkSearchFsm,
  Fee_ActInitChunkHeaderCheckFsm,
  Fee_ActInitCopyProcessFsm,
  Fee_ActInitCreateInstanceFsm,
  Fee_ActInitializeBlockCopy,
  Fee_ActInitInstanceEvaluationFsm,
  Fee_ActInitInstanceEvaluationUpwardsFsm,
  Fee_ActInitInstanceSearchBinaryFsm,
  Fee_ActInitInstanceSearchLinearyFsm,
  Fee_ActInitInstanceSearchUpwards,
  Fee_ActInitLinkTableAllocationFsm,
  Fee_ActInitReverseChunkSearch,
  Fee_ActInitSearchWrittenInOldSector,
  Fee_ActInitSearchUpwardsFsm,
  Fee_ActContinueUpwardsChunkSearch,
  Fee_ActInitSetupSectorsFsm,
  Fee_ActSetupSectorsWriteHeader,
  Fee_ActInitSearchForNfa_WriteFsm,
  Fee_ActFinalizeSearchForNfa_WriteFsm,
  Fee_ActPreInitWriteProcessing,
  Fee_ActInitWriteProcessingFsm,
  Fee_ActAllocationInCurrentSector,
  Fee_ActNop,
  Fee_ActPrepareBlockCopyRead,
  Fee_ActPrepareBlockCopyWrite,
  Fee_ActPrepareChunkHeaderWrite,
  Fee_ActPrepareChunkLinkReadOfCurrentChunk,
  Fee_ActPrepareChunkLinkWrite,
  Fee_ActPrepareInstanceHeaderRead,
  Fee_ActPreparePayloadDataProcessing,
  Fee_ActContinueSearchForNfA,
  Fee_ActPrepareSectorHeaderUpperRead,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  Fee_ActPrepareWccRead,
#endif
  Fee_ActPrepareWriteStreamLast,
  Fee_ActPrepareWriteStreamSecond,
  Fee_ActReportSectorOverflow, 
  Fee_ActResetChunkSearch,
  Fee_ActReturnFromSubFsm,
  Fee_ActSetLocalJobResultFailed,
  Fee_ActSetLocalJobResultInvalid,
  Fee_ActSetLocalJobResultOk,
  Fee_ActSetupSectorSwitchSourceSearch,
  Fee_ActSwitchOperatingSector,
  Fee_ActValidateChunkLink,
  Fee_ActCheckChunkConsistency,

  Fee_ActCheckWriteSuspension,
  Fee_ActWait /* must be the last action */
};

/******************************************************************************
 *  QUERIES
 *****************************************************************************/
static CONST(Fee_QryFctPtrType, FEE_PRIVATE_CONST) Fee_QueryTable_ap[FEE_QRY_ID_TRUE + 1] =      /* PRQA S 3218 */ /* MISRA-C:2004 Rule 8.7 Due to the usage of MemMap.h, variables and constants cannot be defined "static" within functions, because the necessary encapsulation in MemMap.h includes would not work. Consequently it is necessary to use static here, to avoid the nesting of sections in functions. Furthermore this variable is to large to locate it on the stack. */
{
  Fee_QryBlockPayloadUpdated,
  Fee_QryBlockCopyNotFinished,
  Fee_QryChunkIsDataChunk,
  Fee_QryChunkNotFull,
  Fee_QryInstHeaderErasedValue,
  Fee_QryFlsBusy,
  Fee_QryFlsJobResultOk,
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  Fee_QryGetWriteCycleJob,
#endif
  Fee_QryLocalJobResultEmptyChunks,
  Fee_QryLocalJobResultFailed,
  Fee_QryLocalJobResultInvalid,
  Fee_QryLocalJobResultOk,
  Fee_QryMayFollowLinks,
  Fee_QryPreviousInstanceAvailable,
  Fee_QryRecentChunkLinkConsistent,
  Fee_QrySearchingInCurrentSector,
  Fee_QryValidInstanceWritten,
  Fee_QryTrue
};

/******************************************************************************
 *  STATE DESCRIPTION TABLE
 *****************************************************************************/
/* These macros shall increase the readability of the State Descriptor Table. */
#define FEE_STATE_IF
#define FEE_STATE_ELSEIF
#define FEE_STATE_THEN
#define FEE_STATE_ELSE
#define FEE_NEXT_STATE(state)                                         (state)      /* PRQA S 3453 */ /* MD_MSR_19.7 */

static CONST(struct Fee_StateDescrStruct, FEE_PRIVATE_CONST) Fee_StateDescrTable_at[FEE_STATE_NEVER_ENTERED] =      /* PRQA S 3218 */ /* MISRA-C:2004 Rule 8.7 Due to the usage of MemMap.h, variables and constants cannot be defined "static" within functions, because the necessary encapsulation in MemMap.h includes would not work. Consequently it is necessary to use static here, to avoid the nesting of sections in functions. Furthermore this variable is to large to locate it on the stack. */
{
  /* FEE_STATE_ALLOCATE_CHUNK_CHUNK_HOPPING_FSM */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_CONTINUE_SEARCH_FOR_NFA, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_CHUNK_HOPPING_FSM)
      },
      /* Exit 2 */
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_PREPARE_WCC_READ, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_GET_WCC)
      },
#else
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_PREPARE_CHUNK_HEADER_WRITE, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_WRITE_CHUNK_HEADER)
      },
#endif
      /* Exit 3 - not used */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  /* FEE_STATE_ALLOCATE_CHUNK_GET_WCC */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_GET_WCC)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_WRITE_CYCLE, FEE_ACT_ID_PREPARE_CHUNK_HEADER_WRITE},
        FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_WRITE_CHUNK_HEADER)
      },
      /* Exit 3 - not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
#endif

  /* FEE_STATE_ALLOCATE_CHUNK_WRITE_CHUNK_HEADER */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_WRITE_CHUNK_HEADER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_PREPARE_CHUNK_LINK_WRITE, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_WRITE_LINK)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_WAIT},
            FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_NOP, FEE_ACT_ID_WAIT},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_ALLOCATE_CHUNK_WRITE_LINK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_ALLOCATE_CHUNK_WRITE_LINK)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_CHUNK_LINK_WRITE, FEE_ACT_ID_FINALIZE_CHUNK_ALLOCATION},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_BUSY_PROCESS_PAYLOAD_DATA */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_BUSY_PROCESS_PAYLOAD_DATA)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  /* FEE_STATE_BUSY_READ_CHUNK_HEADER */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_BUSY_READ_CHUNK_HEADER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_WRITE_CYCLE_JOB, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
#endif
  /* FEE_STATE_BUSY_SEARCH_CONSISTENT */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_PREPARE_PAYLOAD_DATA_PROCESSING, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_BUSY_PROCESS_PAYLOAD_DATA)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_BUSY_SEARCH_WRITTEN */
  {
    {
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_GET_WRITE_CYCLE_JOB, FEE_QRY_ID_LOCAL_JOB_RESULT_OK},
              FEE_STATE_THEN{FEE_ACT_ID_PRE_INIT_WRITE_PROCESSING, FEE_ACT_ID_PREPARE_WCC_READ},
          FEE_NEXT_STATE(FEE_STATE_BUSY_READ_CHUNK_HEADER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_GET_WRITE_CYCLE_JOB, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_INVALID, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
#endif
      /* Exit 3 or 1 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_PRE_INIT_WRITE_PROCESSING, FEE_ACT_ID_INIT_WRITE_PROCESSING_FSM},
          FEE_NEXT_STATE(FEE_STATE_BUSY_WRITE_PROCESSING_1)
      }
#if (STD_OFF == FEE_GET_WRITE_CYCLE_API)
      ,
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
#endif
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
#endif
  },
  /* FEE_STATE_BUSY_WRITE_PROCESSING_1 */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_ALLOC_IN_CURRENT_SECTOR, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_BUSY_WRITE_PROCESSING_2)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE , FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_BUSY_WRITE_PROCESSING_2 */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE , FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CHUNK_CONSISTENCY_CHECK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_CONSISTENCY_CHECK)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_CHECK_CHUNK_CONSISTENCY, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3, not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },

  /* FEE_STATE_CHUNK_LINK_PROCESSING */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_LINK_PROCESSING)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_VALIDATE_CHUNK_LINK, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3, not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_CHUNK_HOPPING, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH)
      },
      /* Exit 3, not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_CHUNK_HOPPING, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_EVALUATE_CHUNK_HOPPING, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH)
    }
  },
  /* FEE_STATE_CHUNK_SEARCH_CHECK_RECENT_CHUNK */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_RECENT_CHUNK_LINK_CONSISTENT},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_CHUNK_SEARCH, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 - current chunk is okay; but chunk link was defective -> chunk hopping from here */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_SEARCH_CHUNK_HOPPING)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_ResetChunkSearch, FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_SEARCH_CHUNK_HOPPING)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CHUNK_SEARCH_CHUNK_HOPPING */
  {
    {
      /* Exit 1 - Chunk found, continue following chunk-links, if allowd*/
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_MAY_FOLLOW_LINKS},
        FEE_STATE_THEN{FEE_ACT_ID_GET_CURRENT_CHUNK_INFO, FEE_ACT_ID_PREPARE_CHUNK_LINK_READ_OF_CURRENT_CHUNK},
        FEE_NEXT_STATE(FEE_STATE_CHUNK_SEARCH_FOLLOW_CHUNK_LINK)
      },
      /* Exit 2 - Chunk Hopping is FORCED */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_GET_CURRENT_CHUNK_INFO, FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM},
        FEE_NEXT_STATE(FEE_STATE_CHUNK_SEARCH_CHUNK_HOPPING)
          
      },
      /* Exit  3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_CHUNK_SEARCH, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CHUNK_SEARCH_FOLLOW_LINK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_INVALID, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_PREPARE_CHUNK_LINK_READ_OF_CURRENT_CHUNK, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CHUNK_SEARCH_FOLLOW_CHUNK_LINK)
      },
      /* Exit 2 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_INIT_CHUNK_HEADER_CHECK_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_CHUNK_SEARCH_CHECK_RECENT_CHUNK)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_COPY_ALLOCATE_CHUNK */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_REPORT_SECTOR_OVERFLOW, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INITIALIZE_BLOCK_COPY, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_COPY_INSTANCE_COPY)
      },
      /* Exit 3 - not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INITIALIZE_BLOCK_COPY, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_COPY_INSTANCE_COPY)
      }
    },
    /* final case - not used */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_COPY_INSTANCE_COPY */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_INSTANCE_COPY, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CREATE_INSTANCE_1_REMAINING_WRITE_STREAM */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_1_REMAINING_WRITE_STREAM)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_OK, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CREATE_INSTANCE_2_REMAINING_WRITE_STREAMS */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_2_REMAINING_WRITE_STREAMS)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_PREPARE_WRITE_STREAM_LAST, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_1_REMAINING_WRITE_STREAM)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CREATE_INSTANCE_3_REMAINING_WRITE_STREAMS */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_3_REMAINING_WRITE_STREAMS)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_PREPARE_WRITE_STREAM_SECOND, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_2_REMAINING_WRITE_STREAMS)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_READ */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_READ)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_PREPARE_BLOCK_COPY_WRITE, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_WRITE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_WRITE */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_WRITE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_BLOCK_COPY_NOT_FINISHED},
          FEE_STATE_THEN{FEE_ACT_ID_PREPARE_BLOCK_COPY_READ, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_READ)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_OK, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_GET_BLOCK_EVAL_HEADER */
    {
      {
        /* Exit 1 */
        {
          FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_GET_BLOCK_EVAL_HEADER)
        },
        /* Exit 2 */
        {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_CHUNK_HOPPING, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_GET_BLOCK_EVAL_HEADER)
        },
        /* Exit 3 */
        {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_CHUNK_HOPPING, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_GET_BLOCK_EVAL_HEADER)
        }
      },
      /* final case */
      {
        FEE_STATE_ELSE{FEE_ACT_ID_EVALUATE_CHUNK_HOPPING, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_GET_BLOCK_EVAL_HEADER)
      }
    },
  /* FEE_STATE_IDLE */
    {
      {
        /* Exit 1 */
        {
          FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_IDLE)
        },
        /* Exit 2 */
        {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_IDLE)
        },
        /* Exit 3 */
        {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_IDLE)
        }
      },
      /* final case */
      {
        FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
  /* FEE_STATE_INSTANCE_EVALUATION_READ_TRAILER */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_INSTANCE_EVALUATION_READ_TRAILER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_INSTANCE_TRAILER, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_INSTANCE_SEARCH_CALC_INSTANCE */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_INSTANCE_SEARCH_CALC_INSTANCE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_CALCULATE_NEXT_INSTANCE_INDEX, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_INSTANCE_SEARCH_CALC_INSTANCE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_MAIN_BUSY */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_JOB, FEE_ACT_ID_WAIT},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_JOB, FEE_ACT_ID_WAIT},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_JOB, FEE_ACT_ID_WAIT},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_FINALIZE_JOB, FEE_ACT_ID_WAIT},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_MAIN_SECTOR_SWITCH */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_MAIN_STARTUP */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_BLOCK_PAYLOAD_UPDATED, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_INVALID, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_CHUNK_IS_DATA_CHUNK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_INSTANCE_SEARCH_BINARY_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_BINARY)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_SEARCHING_IN_CURRENT_SECTOR, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_SEARCH_WRITTEN_IN_OLD_SECTOR, FEE_ACT_ID_INIT_CHUNK_SEARCH_FSM},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_INVALID, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH_RCH */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_CHUNK_IS_DATA_CHUNK, FEE_QRY_ID_BLOCK_PAYLOAD_UPDATED},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_INVALID, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_CHUNK_IS_DATA_CHUNK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_INSTANCE_SEARCH_LINEARY_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_LINEARY)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_SEARCHING_IN_CURRENT_SECTOR, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SWITCH_OPERATING_SECTOR, FEE_ACT_ID_INIT_CHUNK_SEARCH_FSM},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH_RCH)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_INVALID, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_CONSISTENT_INSTANCE_EVALUATION */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_VALID_INSTANCE_WRITTEN, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_PREVIOUS_INSTANCE_AVAILABLE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_INSTANCE_SEARCH_LINEARY_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_LINEARY)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_REVERSE_CHUNK_SEARCH, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH_RCH)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_BINARY */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_INSTANCE_EVALUATION_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_INSTANCE_EVALUATION)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_CONSISTENT_INSTANCE_SEARCH_LINEARY */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_INSTANCE_EVALUATION_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_CONSISTENT_INSTANCE_EVALUATION)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_UPWARDS_CHECK_CHUNK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_CHUNK_IS_DATA_CHUNK},
        FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_CHUNK_SEARCH, FEE_ACT_ID_INIT_INSTANCE_SEARCH_UPWARDS},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_READ_INSTANCE_HEADER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_CHUNK_SEARCH, FEE_ACT_ID_PREPARE_CHUNK_LINK_READ_OF_CURRENT_CHUNK},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_CHUNK_HOPPING)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },

  /* FEE_STATE_SEARCH_UPWARDS_CHUNK_HOPPING */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_GET_CURRENT_CHUNK_INFO, FEE_ACT_ID_INIT_INSTANCE_SEARCH_UPWARDS},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_READ_INSTANCE_HEADER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_CHUNK_SEARCH, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_UPWARDS_INSTANCE_EVALUATION */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_VALID_INSTANCE_WRITTEN, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED, FEE_QRY_ID_CHUNK_NOT_FULL},
          FEE_STATE_THEN{FEE_ACT_ID_INCREMENT_TO_NEXT_INSTANCE_INDEX, FEE_ACT_ID_PREPARE_INSTANCE_HEADER_READ},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_READ_INSTANCE_HEADER)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INCREMENT_TO_NEXT_INSTANCE_INDEX, FEE_ACT_ID_CONTINUE_UPWARDS_CHUNK_SEARCH},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK)
      }
    },
    /* final case - not used */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_INCREMENT_TO_NEXT_INSTANCE_INDEX, FEE_ACT_ID_CONTINUE_UPWARDS_CHUNK_SEARCH},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK)
    }
  },
  /* FEE_STATE_SEARCH_UPWARDS_READ_INSTANCE_HEADER */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_READ_INSTANCE_HEADER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_ERASED_VALUE},
        FEE_STATE_THEN{FEE_ACT_ID_CONTINUE_UPWARDS_CHUNK_SEARCH, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_INSTANCE_EVALUATION_UPWARDS_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_INSTANCE_EVALUATION)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_INVALID, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_CHUNK_HEADER_CHECK_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_CHECK_CHUNK)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_RECENT_CHUNK_LINK_CONSISTENT},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_CHUNK_HOPPING)
      }
    },
    /* final case */
    {
        FEE_STATE_ELSE{FEE_ACT_ID_INIT_CHUNK_HOPPING_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_SEARCH_UPWARDS_CHUNK_HOPPING)
    }
  },
  /* FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_CURRENT */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_CHUNK_IS_DATA_CHUNK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_SEARCH_FOR_NFA_WRITE, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_WRITTEN_FIND_NFA)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_SEARCH_WRITTEN_IN_OLD_SECTOR, FEE_ACT_ID_INIT_CHUNK_SEARCH_FSM},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_OLD)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_SEARCH_WRITTEN_IN_OLD_SECTOR, FEE_ACT_ID_INIT_CHUNK_SEARCH_FSM},
          FEE_NEXT_STATE(FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_OLD)
      }
    },
    /* final case, not used */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_OLD */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_INIT_SEARCH_FOR_NFA_WRITE, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_SEARCH_WRITTEN_FIND_NFA)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3, not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case, not used */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SEARCH_WRITTEN_FIND_NFA */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_SEARCH_FOR_NFA_WRITE, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_SEARCH_WRITTEN_INSTANCE_SEARCH_BINARY)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_CONTINUE_SEARCH_FOR_NFA, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_SEARCH_WRITTEN_FIND_NFA)
      },
      /* Exit 3 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },

  /* FEE_STATE_SEARCH_WRITTEN_INSTANCE_SEARCH_BINARY */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_OK, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_ALLOCATE_LINKTABLE_CHUNK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_REPORT_SECTOR_OVERFLOW, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SETUP_SECTOR_SWITCH_SOURCE_SEARCH, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_SEARCH_CONSISTENT)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_COPY_PROCESSING */
  {
    {
      /* Exit 1 - Result Empty Chunks -> Copy was forbidden; don't advance to next Block, as we'll need to retry!!! */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_EMPTY_CHUNKS, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_BLOCK_COPY, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_FINAL */
  {
    {
      /* Exit 1 - the only one, we need here */
      {
          FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_SECTOR_SWITCH_FSM, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_GET_BLOCK */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_GET_NEXT_BLOCK_FSM, FEE_ACT_ID_INIT_SEARCH_UPWARDS_FSM},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_SEARCH_UPWARDS)
      },
      /* Exit 2 - Block does not belong to partition */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_LOCAL_JOB_RESULT_EMPTY_CHUNKS, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 3  - all blocks processed */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_SS_COPYING, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_SEARCH_CONSISTENT */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_COPY_PROCESS_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_COPY_PROCESSING)
      },
      /* Exit 2 - not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_INIT_COPY_PROCESS_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_COPY_PROCESSING)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_SEARCH_UPWARDS */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_VALID_INSTANCE_WRITTEN, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_BLOCK_COPY, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 2 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_LINKTABLE_ALLOCATION, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_ALLOCATE_LINKTABLE_CHUNK)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SECTOR_SWITCH_SETUP_SECTORS */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 2 - not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_NOP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SECTOR_SWITCH_FINAL)
      },
      /* Exit 3 - not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case - not used */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SETUP_SECTORS_ERASING */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SETUP_SECTORS_ERASING)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
           FEE_STATE_THEN{FEE_ACT_ID_SETUP_SECTORS_WRITE_HEADER, FEE_ACT_ID_WAIT},
           FEE_NEXT_STATE(FEE_STATE_SETUP_SECTORS_HEADER_WRITING)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_SETUP_SECTORS, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_FINALIZE_SETUP_SECTORS, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_SETUP_SECTORS_HEADER_WRITING */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_SETUP_SECTORS_HEADER_WRITING)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_SETUP_SECTORS, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_SETUP_SECTORS, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_FINALIZE_SETUP_SECTORS, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_STARTUP_READ_SECTOR_HEADER_LOWER */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_STARTUP_READ_SECTOR_HEADER_LOWER)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_FLS_JOB_RESULT_OK, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_PREPARE_SECTOR_HEADER_UPPER_READ, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_STARTUP_READ_SECTOR_HEADER_UPPER)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_SET_LOCAL_JOB_RESULT_FAILED, FEE_ACT_ID_PREPARE_SECTOR_HEADER_UPPER_READ},
          FEE_NEXT_STATE(FEE_STATE_STARTUP_READ_SECTOR_HEADER_UPPER)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_STARTUP_READ_SECTOR_HEADER_UPPER */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_FLS_BUSY, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_STARTUP_READ_SECTOR_HEADER_UPPER)
      },
      /* Exit 2 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_EVALUATE_SECTOR_HEADERS, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_WRITE_PROCESSING_ALLOC_DATACHUNK, */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
            FEE_STATE_THEN{FEE_ACT_ID_INIT_CREATE_INSTANCE_FSM, FEE_ACT_ID_NOP},
            FEE_NEXT_STATE(FEE_STATE_WRITE_PROCESSING_CREATE_INSTANCE)
      },
      /* Exit 3 */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_INIT_CREATE_INSTANCE_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_WRITE_PROCESSING_CREATE_INSTANCE)
      }
    },
    /* final case */
    {
        FEE_STATE_ELSE{FEE_ACT_ID_INIT_CREATE_INSTANCE_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_WRITE_PROCESSING_CREATE_INSTANCE)
    }
  },
  /* FEE_STATE_WRITE_PROCESSING_ALLOC_LINKTABLE, */
  {
    {
      /* Exit 1 */
      {
          FEE_STATE_IF{FEE_QRY_ID_LOCAL_JOB_RESULT_FAILED, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_RETURN_FROM_SUB_FSM, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
        FEE_STATE_THEN{FEE_ACT_ID_INIT_DATACHUNK_ALLOC_WRITE_FSM, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_WRITE_PROCESSING_ALLOC_DATACHUNK)
      },
      /* Exit 3 - not used */
      {
          FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
        FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },
  /* FEE_STATE_WRITE_PROCESSING_CREATE_INSTANCE */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_FINALIZE_INSTANCE_WRITE, FEE_ACT_ID_RETURN_FROM_SUB_FSM},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      },
      /* Exit 3 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_IDLE)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_IDLE)
    }
  },

  /*   FEE_STATE_WAIT_FOR_WRITE_RESUME */
  {
    {
      /* Exit 1 */
      {
        FEE_STATE_IF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_CHECK_WRITE_SUSP, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_WAIT_FOR_WRITE_RESUME)
      },
      /* Exit 2 */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_WAIT_FOR_WRITE_RESUME)
      },
      /* Exit 3 - not used */
      {
        FEE_STATE_ELSEIF{FEE_QRY_ID_TRUE, FEE_QRY_ID_TRUE},
          FEE_STATE_THEN{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
          FEE_NEXT_STATE(FEE_STATE_WAIT_FOR_WRITE_RESUME)
      }
    },
    /* final case */
    {
      FEE_STATE_ELSE{FEE_ACT_ID_WAIT, FEE_ACT_ID_NOP},
        FEE_NEXT_STATE(FEE_STATE_WAIT_FOR_WRITE_RESUME)
    }
  }
};

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Fee_Init
 *********************************************************************************************************************/
/*! \brief      Initialization of module Fee and starting up the state machine.
 *
 *  \return     None
 *  \context    System Startup
 *********************************************************************************************************************/
 FUNC(void, FEE_API_CODE) Fee_Init(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
 {
     Fee_InitEx(&Fee_Config);
 }

/**********************************************************************************************************************
 * Fee_Init
 *********************************************************************************************************************/
/*! \brief      Initialization of module Fee and starting up the state machine.
 *
 *  \return     None
 *  \context    System Startup
 *********************************************************************************************************************/
/* PRQA S 1505 1 */ /* Fee_InitEx belongs to API - additional usage from elsewhere is project dependent */
 FUNC(void, FEE_API_CODE) Fee_InitEx(Fee_ConfigRefType ConfigPtr)  
{
    uint8 partIndex;
  /* Check data buffer parameter for being valid address. */
#if (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER)

    /* Is pointer to a data buffer valid? */
    if (NULL_PTR == ConfigPtr)
    {
        /* Report development error. */
        Fee_Errorhook(FEE_SID_INIT, FEE_E_PARAM_DATABUFFERPTR);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */

        /* stay unitialized / explicitly unitialize */
#       if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
            Fee_ModuleStatus_t = MEMIF_UNINIT;
#       endif

        return;
    }
#endif

    /* initialize all partitions (representations in RAM!) */
    for(partIndex = 0; (partIndex < ConfigPtr->Fee_NumberOfPartitions_u8); partIndex++)
    {
        Fee_Partition_init(&ConfigPtr->PartitionConfig_at[partIndex]);
    }

    /* set the config pointer */
    Fee_Globals_t.Config_pt = ConfigPtr;

    /****************************************************************************
    * Initialize global variables
    ***************************************************************************/
    Fee_Globals_t.FeeJobParameter_t.RequestedFeeJob_t = FEE_JOB_NONE;
    Fee_Globals_t.FeeJobParameter_t.blockConfig_pt = &ConfigPtr->BlockConfig_at[0];

    Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_OK;
    Fee_Globals_t.FeeModuleStatus_t = MEMIF_BUSY_INTERNAL;
    Fee_Globals_t.FeeJobResult_t = MEMIF_JOB_OK;
    Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
    Fee_Globals_t.InternalFlags_t = 0u;
    Fee_Globals_t.ApiFlags_t = 0u;

    /* we start without sector swtich, i.e. partition index is out of bounds     *
     * There's no need to initialize remaining SectorSwtichData_t members:       *
     * They will be set if a sector switch actually becomes necessary.           *
     * This, in turn, can only happen when a job completes                       */
    Fee_Globals_t.SectorSwitchData_t.partitionId_s8 = -1;

    Fee_Globals_t.WritesSuspended_bl = FALSE;

    /****************************************************************************
    * Initialize the FSM stack and start the state machine
    *   only the first two levels of the FSM stack must be initialized, because all 
    *   other will be initialized before increasing the stack pointer
    ***************************************************************************/
    Fee_Globals_t.FsmStack_t.TopOfStack_u8 = 0u;
    Fee_Globals_t.FsmStack_t.Stack_at[0] = FEE_STATE_IDLE;

#ifdef FEE_TESTING_LOG_TRANSITIONS
    TsxFee_LogFsmCompleteReinitialization(FEE_STATE_IDLE);
#endif
  /****************************************************************************
   * Initialize the component
   ***************************************************************************/
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    Fee_ModuleStatus_t = MEMIF_IDLE;
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */
} /* End of Fee_Init() */       /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_SetMode
 *********************************************************************************************************************/
/*! \brief      Setting the mode of the Fee as well as the mode of the underlying Fls driver.
 *
 *  \param[in]  MemIf_ModeType   Mode                    Desired mode to set.
 *  \pre        Module must be initialized.
 *  \return     None
 *  \context    Application
 *  \note       The mode of the Fee causes the sector switch to be done in background (SlowMode). In FastMode, no
 *              sector switch is done normally, except a critical situation as occurred, e.g. a lack of available
 *              memory (exceeding the threshold to perform an uninterruptible sector switch) or corrupt 
 *              management information.
 *********************************************************************************************************************/
FUNC(void, FEE_API_CODE) Fee_SetMode(MemIf_ModeType Mode)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
    /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_SETMODE))
    {
        return;
    }
        else
    {
        /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

    /* Check if the Fee is busy. */
#if (STD_ON == FEE_CFG_CHK_BUSY)
    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
        /* Report development error. */
        Fee_Errorhook(FEE_SID_SETMODE, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
    return;
  }
#endif

/* Check if parameter checking for Mode is switched on? */
#if (STD_ON == FEE_CFG_CHK_PARAM_MODE)
    /* Check if parameter Mode is in allowed range. */
    /* PRQA S 3356,3359,3201 4*//* MISRA-C:2004 Rule 13.7, MISRA-C:2004 Rule 14.1:
            Invalid values could have be supplied via cast; this DEV-Mode check is necessary  */
    if ((MEMIF_MODE_SLOW != Mode) &&    
        (MEMIF_MODE_FAST != Mode))     
    {        /* Report development error. */
        Fee_Errorhook(FEE_SID_SETMODE, FEE_E_PARAM_MODE);  /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */

        return;
    }

#endif /* (STD_ON == FEE_CFG_CHK_PARAM_MODE) */

    /* disable global interrupts */
    Fee_GlobalSuspend();

    if(Mode == MEMIF_MODE_SLOW)
    {
        /* we enable Background Sector Switch, only. FEE may start processing, if necessary.  */
        Fee_Globals_t.ApiFlags_t |= FEE_API_FLAG_ENABLE_BSS;
    }
    else
    {
        /* we disable Sector Switch processign in Background.                                     *
         * A Sectorswitch will be done only, if it is necessary in order to process a pending job */
        Fee_Globals_t.ApiFlags_t &= (FEE_API_FLAG_ENABLE_BSS ^ 0xFFu);
    }

    /* Fee_SetMode does not disable sector switches anymore! */

    /* Set global (public) state to BUSY_INTERNAL -> FEE might have something to do in next MainFunction cycle */
    Fee_Globals_t.FeeModuleStatus_t = MEMIF_BUSY_INTERNAL;

    /* enable global interrupts. */
    Fee_GlobalRestore();
} /* End of Fee_SetMode() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_Read
 *********************************************************************************************************************/
/*! \brief      Caching a request from the upper layer. If internal processing is running and is not interruptible, 
 *              the job is cached. In other case the job will be started.
 *
 *  \param[in]  BlockNumber         Number of block, datasets included.
 *  \param[in]  BlockOffset         Offset in the block/dataset.
 *  \param[out] DataBufferPtr       Pointer to application buffer.
 *  \param[in]  Length              Count of bytes which should be read.
 *  \pre        Module must be initialized.
 *  \return     E_OK                Job accepted.
 *  \return     E_NOT_OK            Job rejected.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_API_CODE) Fee_Read  /* PRQA S 1503 */ /* MD_MSR_14.1 */
  (
    uint16 BlockNumber,
    uint16 BlockOffset,
    Fee_UserDataPtrType DataBufferPtr,
    uint16 Length
  )
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)

    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_READ))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Module has been initialized. */
    }

#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Check if the Fee is busy. */
#if (STD_ON == FEE_CFG_CHK_BUSY)

    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_READ, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check if the block number shall be tested for being valid. */
#if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)

    /* Is the BlockNumber value valid? (FEE_E_INVALID_BLOCK_NO) */
    if (E_OK != Fee_DetChkBlockNumber(FEE_SID_READ, BlockNumber))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check data buffer parameter for being valid address. */
#if (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER)

    /* Is pointer to a data buffer valid? */
    if (NULL_PTR == DataBufferPtr)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_READ, FEE_E_PARAM_DATABUFFERPTR);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check whether parameter length and offset within boundaries of block size and length has a 0-size. */
#if (STD_ON == FEE_CFG_CHK_PARAM_LENGTH_OFFSET)

    /* Check 0-value of parameter length. */
    if ((uint16)0u == Length)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_READ, FEE_E_PARAM_LENGTH_OFFSET);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

    /* Get real block number which is encoded in parameter BlockNumber. */
    if (Fee_Globals_t.Config_pt->BlockConfig_at[Fee_InternalGetBlockId(BlockNumber)].BlockPayloadSize_u16 < (Length + BlockOffset))
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_READ, FEE_E_PARAM_LENGTH_OFFSET);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }
#endif

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

  /* Store block offset value. */
  Fee_Globals_t.FeeJobParameter_t.BlockOffset_u16 = BlockOffset;

  /* Store pointer to RAM address where to read the data to write it on the non-volatile memory. */
  Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8 = DataBufferPtr;

  /* Overwrite requested number of bytes to read from the NVRAM by the configured one in the block configuration. */
  Fee_Globals_t.FeeJobParameter_t.Length_u16 = Length;

  Fee_InternalApiInit(BlockNumber, FEE_JOB_READ);

  /* Enable global interrupts. */
  Fee_GlobalRestore();

  /* API call successful. */
  return (E_OK);
} /* End of Fee_Read() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_Write
 *********************************************************************************************************************/
/*! \brief      Caching a request from the upper layer. If internal processing is running and is not interruptible, 
 *              the job is cached. In other case the job will be started.
 *
 *  \param[in]  BlockNumber         Number of block, datasets included.
 *  \param[in]  DataBufferPtr       Pointer to application buffer.
 *  \pre        Module must be initialized.
 *  \return     E_OK                Job accepted.
 *  \return     E_NOT_OK            Job rejected.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_API_CODE) Fee_Write(uint16 BlockNumber, Fee_UserDataPtrType DataBufferPtr)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_WRITE))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Check if the Fee is busy. */
#if (STD_ON == FEE_CFG_CHK_BUSY)

    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_WRITE, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check if the block number shall be tested for being valid. */
#if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)

    /* Is the BlockNumber value valid? (FEE_E_INVALID_BLOCK_NO) */
    if (E_OK != Fee_DetChkBlockNumber(FEE_SID_WRITE, BlockNumber))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check data buffer parameter for being valid address. */
#if (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER)

    /* Is pointer to a data buffer valid? */
    if (NULL_PTR == DataBufferPtr)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_WRITE, FEE_E_PARAM_DATABUFFERPTR);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

  /* Store pointer to RAM address where data to write are located. */
  Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8 = DataBufferPtr;

  Fee_InternalApiInit(BlockNumber, FEE_JOB_WRITE);

  /* Enable global interrupts. */
  Fee_GlobalRestore();

  /* API call successful. */
  return (E_OK);
} /* End of Fee_Write() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_InvalidateBlock
 *********************************************************************************************************************/
/*! \brief      Caching a request from the upper layer. If internal processing is running and is not interruptible,
 *              the job is cached. In other case the job will be started.
 *
 *  \param[in]  BlockNumber         Number of block, datasets included.
 *  \pre        Module must be initialized.
 *  \return     E_OK                Job accepted.
 *  \return     E_NOT_OK            Job rejected.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_API_CODE) Fee_InvalidateBlock(uint16 BlockNumber)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_INVALIDATEBLOCK))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Check if the Fee is busy. */
#if (STD_ON == FEE_CFG_CHK_BUSY)

    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_INVALIDATEBLOCK, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check if the block number shall be tested for being valid. */
#if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)

    /* Is the BlockNumber value valid? (FEE_E_INVALID_BLOCK_NO) */
    if (E_OK != Fee_DetChkBlockNumber(FEE_SID_INVALIDATEBLOCK, BlockNumber))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

  Fee_InternalApiInit(BlockNumber, FEE_JOB_INVALIDATE_BLOCK);

  /* Enable global interrupts. */
  Fee_GlobalRestore();

  return (E_OK);
} /* End of Fee_InvalidateBlock() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_EraseImmediateBlock
 *********************************************************************************************************************/
/*! \brief      Caching a request from the upper layer. If internal processing is running and is not interruptible,
 *              the job is cached. In other case the job will be started.
 *
 *  \param[in]  BlockNumber         Number of block, datasets included.
 *  \pre        Module must be initialized.
 *  \return     E_OK                Job accepted.
 *  \return     E_NOT_OK            Job rejected.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_API_CODE) Fee_EraseImmediateBlock(uint16 BlockNumber)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_ERASEIMMEDIATEBLOCK))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Check if the Fee is busy. */
#if (STD_ON == FEE_CFG_CHK_BUSY)

    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_ERASEIMMEDIATEBLOCK, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check if the block number shall be tested for being valid. */
#if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)

    /* Is the BlockNumber value valid? (FEE_E_INVALID_BLOCK_NO) */
    if (E_OK != Fee_DetChkBlockNumber(FEE_SID_ERASEIMMEDIATEBLOCK, BlockNumber))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Check if the block number shall be tested of containing immediate data. */
#if (STD_ON == FEE_CFG_CHK_IMMEDIATE_DATA)

    /* Contains the block immediate data? */
    if (!Fee_Globals_t.Config_pt->BlockConfig_at[Fee_InternalGetBlockId(BlockNumber)].ImmediateData_bl)
    {
# if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_ERASEIMMEDIATEBLOCK, FEE_E_INVALID_BLOCK_NO);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

#endif

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

  Fee_InternalApiInit(BlockNumber, FEE_JOB_ERASE_IMMEDIATE_BLOCK);

  /* Enable global interrupts. */
  Fee_GlobalRestore();

  return (E_OK);
} /* End of Fee_EraseImmediateBlock() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_Cancel
 *********************************************************************************************************************/
/*! \brief      Aborts a running job processing or the sector switch in background mode.
 *
 *  \pre        Module must be initialized.
 *  \return     None
 *  \context    Application
 *********************************************************************************************************************/
FUNC(void, FEE_API_CODE) Fee_Cancel(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_CANCEL))
    {
      return;
    }
    else
    {
      /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* disable global interrupts */
  Fee_GlobalSuspend();

  if(Fee_Globals_t.FeeModuleStatus_t == MEMIF_BUSY)
  { /* we may modify the status, if there is a job pending */
      Fee_Globals_t.FeeModuleStatus_t = MEMIF_IDLE;
      Fee_Globals_t.FeeJobResult_t = MEMIF_JOB_CANCELLED;
  }
  /* set the cancel flag */
  Fee_Globals_t.ApiFlags_t |= FEE_API_FLAG_CANCEL;
 
  /* enable global interrupts. */
  Fee_GlobalRestore();
} /* End of Fee_Cancel() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_GetStatus
 *********************************************************************************************************************/
/*! \brief      Get the current status of the module.
 *
 *  \pre        Module must be initialized.
 *  \return     Current module status.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(MemIf_StatusType, FEE_API_CODE) Fee_GetStatus(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  return (Fee_Globals_t.FeeModuleStatus_t);
} /* End of Fee_GetStatus() */

/**********************************************************************************************************************
 * Fee_GetJobResult
 *********************************************************************************************************************/
/*! \brief      Get the result previously or currently running job.
 *
 *  \pre        Module must be initialized.
 *  \return     Previously or currently running job result.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(MemIf_JobResultType, FEE_API_CODE) Fee_GetJobResult(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_GETJOBRESULT))
    {
      return MEMIF_JOB_FAILED;
    }
    else
    {
      /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  return (Fee_Globals_t.FeeJobResult_t);
} /* End of Fee_GetJobResult() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

/**********************************************************************************************************************
 * Fee_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief      Get the module version information.
 *
 *  \param[out] versioninfo         Pointer to where to store the version information of this module.
 *  \return     None
 *  \context    Application
 *********************************************************************************************************************/
#if (STD_ON == FEE_VERSION_INFO_API)
FUNC(void, FEE_API_CODE) Fee_GetVersionInfo(Fee_StdVersionInfoRefType versioninfo)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
# if (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER)

    /* Check if the parameter is a null pointer? */
    if (NULL_PTR == versioninfo)
    {
#  if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_GETVERSIONINFO, FEE_E_PARAM_DATABUFFERPTR);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#  endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return;
    }
    else
    {
      /* Intentionally left free. */
    }

# endif /* (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER) */
  /* Even in case of ASR3, we don't set Instance ID, to maintain compatibility to ASR 4 */

  versioninfo->vendorID         = FEE_VENDOR_ID;
  versioninfo->moduleID         = FEE_MODULE_ID;
  versioninfo->sw_major_version = FEE_SW_MAJOR_VERSION;
  versioninfo->sw_minor_version = FEE_SW_MINOR_VERSION;
  versioninfo->sw_patch_version = FEE_SW_PATCH_VERSION;

} /* End of Fee_GetVersionInfo() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_ON == FEE_VERSION_INFO_API) */

/**********************************************************************************************************************
 * Fee_MainFunction
 *********************************************************************************************************************/
/*! \brief      Triggers the job processing. If Fee must wait for Fls processing, nothing else is done.
 *
 *  \pre        Module must be initialized.
 *  \return     None
 *  \context    Application
 *********************************************************************************************************************/
/** Intended to be used by Fee_MainFunction only **/
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalHandleCancelRequest(Fee_GlobalsPtrType globals);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalSetupToplevelFsm(Fee_GlobalsPtrType globals);

FUNC(void, FEE_API_CODE) Fee_MainFunction(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
    /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_MAINFUNCTION))
    {
      return;
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

    /* get the scheduler, because the MainFunction must not be interrupted -> non-preemptive function */
    Fee_GlobalSuspendLong();

    if((Fee_Globals_t.ApiFlags_t & FEE_API_FLAG_CANCEL) != 0)
    {
        Fee_InternalHandleCancelRequest(&Fee_Globals_t);
    }

    /* Clear wait flag */
    Fee_Globals_t.InternalFlags_t &= (Fee_FlagType)FEE_FLAG_WAIT_MASK;

    /* Only if FEE is not IDLE we have to do anything, at all */
    if(Fee_Globals_t.FeeModuleStatus_t != MEMIF_IDLE)
    {
        if(FEE_STATE_IDLE == Fee_Globals_t.FsmStack_t.Stack_at[0u])
        {
            Fee_InternalSetupToplevelFsm(&Fee_Globals_t);
        }

        /* State machine processing. */
        do
        {
            Fee_Fsm(&Fee_Globals_t.FsmStack_t.Stack_at[Fee_Globals_t.FsmStack_t.TopOfStack_u8]);
        } while ((Fee_Globals_t.InternalFlags_t & FEE_FLAG_WAIT) == 0);

    } /* if(FEE != IDLE) */

        /* release the scheduler */
        Fee_GlobalRestoreLong();
} /* End of Fee_MainFunction() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalHandleCancelRequest(Fee_GlobalsPtrType globals)
{
    if(globals->FsmStack_t.Stack_at[0] == FEE_STATE_MAIN_BUSY)
    { /* a normal job is currently being processed -> cancel it immediatelly.
        * Necessary to avoid problems with job result, FEE state and job end/error notification */
        globals->FsmStack_t.Stack_at[0u] = FEE_STATE_IDLE;
        globals->FsmStack_t.TopOfStack_u8 = 0;

        /* cancel a pending Fls job (which originated from job processing) */
        if(globals->FlsJobResult_t == MEMIF_JOB_PENDING)
        {
            Fee_FlsCancel();
        }

#ifdef FEE_TESTING_LOG_TRANSITIONS
        TsxFee_LogFsmCompleteReinitialization(FEE_STATE_IDLE);
#endif
    }

    /* we finalize the cancellation when a new job arrived */
    if(globals->FeeModuleStatus_t == MEMIF_BUSY)
    {
        /*  actual cancellation will be handled only, if the new job is a write job
            *  Other jobs take precedence over BSS (resuming), but nothing will be destructively cancelled
            *  Note that the Startup phase shall not be cancelled at all! */
        /* PRQA S 3344,3415 2 *//* MD_FEE_13.2_boolean,MD_FEE_12.4_queries */
        if((globals->FeeJobParameter_t.RequestedFeeJob_t == FEE_JOB_WRITE) && 
            (Fee_InternalIsCancelableOperation(&Fee_Globals_t)))  
        {
            if(globals->FlsJobResult_t == MEMIF_JOB_PENDING)
            {
                Fee_FlsCancel();
            }

            /* normal reset of FSM */    
            globals->FsmStack_t.Stack_at[0u] = FEE_STATE_IDLE;
            globals->FsmStack_t.TopOfStack_u8 = 0;

#ifdef FEE_TESTING_LOG_TRANSITIONS
            TsxFee_LogFsmCompleteReinitialization(FEE_STATE_IDLE);
#endif
        }
        /* Finally, clear cancel Flag, enable job processing (for next job request) */
        Fee_InternalClearApiFlags(&Fee_Globals_t, FEE_API_FLAG_CANCEL);

        /* Reset all SectorSwitch requests, in order to prevent from starting Sector Switch processing.  *
            * They will be set again on demand                                                              */
        globals->SectorSwitchData_t.partitionId_s8 = -1;
    }
}
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalSetupToplevelFsm(Fee_GlobalsPtrType globals)
{
#if(FEE_FORCE_SECTOR_SWITCH_API == STD_ON)
    if((globals->ApiFlags_t & FEE_API_FLAG_FORCE_SECTOR_SWITCH) != 0)
    {
        globals->SectorSwitchData_t.partitionId_s8 = (sint8)globals->Config_pt->Fee_NumberOfPartitions_u8 - 1;

        Fee_InternalResetSectorSwitch(&globals->SectorSwitchData_t, FEE_IS_IN_FBL_MODE(globals));

        /* set "processing flag";  clear "request flag" */
        globals->InternalFlags_t |= FEE_FLAG_FORCE_SECTOR_SWITCH;
        Fee_InternalClearApiFlags(&Fee_Globals_t, FEE_API_FLAG_FORCE_SECTOR_SWITCH);
    }
#endif
    if(!Fee_InternalScheduleProcess(&Fee_Globals_t))
    { 
        /* Guarded! Before reseting module status, we have to check whether we became BUSY meanwhile
            We may check for sector switch flag, even if API was disabled.
            */
        Fee_GlobalSuspend();
        if((globals->FeeModuleStatus_t != MEMIF_BUSY) &&
            ((globals->ApiFlags_t & FEE_API_FLAG_FORCE_SECTOR_SWITCH) == 0))
        {
            /* No process was started; we're actually IDLE */
            globals->FeeModuleStatus_t = MEMIF_IDLE;
        }
        Fee_GlobalRestore();
    }
}

/**********************************************************************************************************************
 * Fee_JobEndNotification
 *********************************************************************************************************************/
/*! \brief      This routine shall be called by the underlying EEPROM driver to report the successful end of an  
 *              asynchronous operation.
 *
 *  \pre        Module must be initialized.
 *  \return     None
 *  \context    Application
 *********************************************************************************************************************/
#if (STD_OFF == FEE_POLLING_MODE)
FUNC(void, FEE_API_CODE) Fee_JobEndNotification(void)    /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_JOBENDNOTIFICATION))
    {
      return;
    }
    else
    {
      /* Module has been initialized. */
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* set job result of Fls driver to MEMIF_JOB_OK. */
  Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_OK;
} /* End of Fee_JobErrorNotification() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_OFF == FEE_POLLING_MODE) */

/**********************************************************************************************************************
 * Fee_JobErrorNotification
 *********************************************************************************************************************/
/*! \brief      This function is called by the Fls driver for reporting an error in job processing.
 *
 *  \pre        Module must be initialized.
 *  \return     None
 *  \context    Application
 *********************************************************************************************************************/
#if (STD_OFF == FEE_POLLING_MODE)
FUNC(void, FEE_API_CODE) Fee_JobErrorNotification(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_JOBERRORNOTIFICATION))
    {
      return;
    }
    else
    {
      /* Module has been initialized. */
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Retrieve job result from Fls driver. */
  Fee_Globals_t.FlsJobResult_t = Fee_FlsGetJobResult();
} /* End of Fee_JobErrorNotification() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_OFF == FEE_POLLING_MODE) */

/**********************************************************************************************************************
 * Fee_GetEraseCycle
 *********************************************************************************************************************/
/*! \brief      Get the erase cycle of the specified sector.
 *
 *  \param[in]  SectorNumber        Sector number of which to read the erase cycle.
 *  \param[out] DataPtr             Pointer to where to store the erase cycle.
 *  \pre        Module must be initialized.
 *  \return     E_OK                Job accepted.
 *  \return     E_NOT_OK            Job rejected.
 *  \context    Application
 *********************************************************************************************************************/
#if (STD_ON == FEE_GET_ERASE_CYCLE_API)
FUNC(Std_ReturnType, FEE_API_CODE) Fee_GetEraseCycle  /* PRQA S 1503 */ /* MD_MSR_14.1 */
  (
    uint8 SectorNumber,
    P2VAR(uint32, AUTOMATIC, FEE_APPL_DATA) DataPtr
  )
{
  /* Check if module shall be tested for being initialized. */
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_GET_ERASE_CYCLE))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Module has been initialized. */
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Check if the Fee is busy. */
# if (STD_ON == FEE_CFG_CHK_BUSY)

    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
#  if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_GET_ERASE_CYCLE, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#  endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

# endif

# if (STD_ON == FEE_CFG_CHK_PARAM_SECTOR_NUMBER)

    /* Check if the parameter is out of range? We have 2 sectors per partition, i.e. upper limit is 2*partitions */
    if (SectorNumber >= (2 * Fee_Globals_t.Config_pt->Fee_NumberOfPartitions_u8))
    {
#  if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_GET_ERASE_CYCLE, FEE_E_PARAM_SECTOR_NUMBER);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#  endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

# endif /* (STD_ON == FEE_CFG_CHK_PARAM_SECTOR_NUMBER) */

# if (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER)

    /* Check if the parameter is a null pointer? */
    if (NULL_PTR == DataPtr)
    {
#  if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_GET_ERASE_CYCLE, FEE_E_PARAM_DATABUFFERPTR);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#  endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

# endif /* (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER) */

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

  Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8 = (Fee_UserDataPtrType)DataPtr;      /* PRQA S 0310 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */

  /* Block Number parameter Must be valid ; settings must be corrected after call */
  Fee_InternalApiInit(1u << Fee_Globals_t.Config_pt->Fee_DatasetSelectionBits_u8, FEE_JOB_GET_ERASE_CYCLE);

  Fee_Globals_t.FeeJobParameter_t.DataIndex_u8 = SectorNumber & 1u;
  Fee_Globals_t.FeeJobParameter_t.PartitionIndex_s8 = (sint8)(SectorNumber >> 1);
  Fee_Globals_t.FeeJobParameter_t.blockConfig_pt = NULL_PTR;

  /* Enable global interrupts. */
  Fee_GlobalRestore();

  return (E_OK);
} /* End of Fee_GetEraseCycle() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_ON == FEE_GET_ERASE_CYCLE_API) */

/**********************************************************************************************************************
 * Fee_GetWriteCycle
 *********************************************************************************************************************/
/*! \brief      Get the write cycle of the specified block/dataset.
 *
 *  \param[in]  BlockNumber         Number of block, datasets included.
 *  \param[out] DataPtr             Pointer to where to store the write cycle.
 *  \pre        Module must be initialized.
 *  \return     E_OK                Job accepted.
 *  \return     E_NOT_OK            Job rejected.
 *  \context    Application
 *********************************************************************************************************************/
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
FUNC(Std_ReturnType, FEE_API_CODE) Fee_GetWriteCycle  /* PRQA S 1503 */ /* MD_MSR_14.1 */
  (
    uint16 BlockNumber,
    P2VAR(uint32, AUTOMATIC, FEE_APPL_DATA) DataPtr
  )
{
  /* Check if module shall be tested for being initialized. */
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_GET_WRITE_CYCLE))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Module has been initialized. */
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Check if the Fee is busy. */
# if (STD_ON == FEE_CFG_CHK_BUSY)

    /* Is Fee busy? */
    if (MEMIF_BUSY == Fee_Globals_t.FeeModuleStatus_t)
    {
#  if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_GET_WRITE_CYCLE, FEE_E_BUSY);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#  endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

# endif

  /* Check if the block number shall be tested for being valid. */
# if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)

    /* Is the BlockNumber value valid? (FEE_E_INVALID_BLOCK_NO) */
    if (E_OK != Fee_DetChkBlockNumber(FEE_SID_GET_WRITE_CYCLE, BlockNumber))
    {
      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

# endif

# if (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER)

    /* Check if the parameter is a null pointer? */
    if (NULL_PTR == DataPtr)
    {
#  if (STD_ON == FEE_DEBUG_REPORTING)
        /* Report development error. */
        Fee_Errorhook(FEE_SID_GET_WRITE_CYCLE, FEE_E_PARAM_DATABUFFERPTR);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#  endif /* (STD_ON == FEE_DEBUG_REPORTING) */

      return (E_NOT_OK);
    }
    else
    {
      /* Intentionally left free. */
    }

# endif /* (STD_ON == FEE_CFG_CHK_PARAM_NULL_POINTER) */

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

  Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8 = (Fee_UserDataPtrType)DataPtr;      /* PRQA S 0310 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */

  Fee_InternalApiInit(BlockNumber, FEE_JOB_GET_WRITE_CYCLE);

  /* Enable global interrupts. */
  Fee_GlobalRestore();

  return (E_OK);
} /* End of Fee_GetWriteCycle() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_ON == FEE_GET_WRITE_CYCLE_API) */

/**********************************************************************************************************************
 * Fee_GetSectorSwitchStatus
 *********************************************************************************************************************/
/*! \brief      Get the current status of the module about the status of the sector switch.
 *
 *  \pre        Module must be initialized.
 *  \return     Status about the sector switch.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(Fee_SectorSwitchStatusType, FEE_API_CODE) Fee_GetSectorSwitchStatus(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
    Fee_SectorSwitchStatusType retVal = FEE_SECTOR_SWITCH_IDLE;
    
  /* Check if module shall be tested for being initialized. */
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_GET_SECTOR_SWITCH_STATUS))
    {
        return (FEE_SECTOR_SWITCH_UNINIT);
    }
    else
    {
      /* Module has been initialized. */
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

    Fee_GlobalSuspend();

    if(Fee_Globals_t.FsmStack_t.Stack_at[0] == FEE_STATE_MAIN_SECTOR_SWITCH)
    {
        retVal = (Fee_Partition_getFillLevel(
                            Fee_Globals_t.CurrentProcessData.Partition_pt) == FEE_PART_FILL_LEVEL_SINGLE_SECTOR) ? 
                                                                FEE_SECTOR_SWITCH_ERASE : FEE_SECTOR_SWITCH_BLOCK_COPY;
    }

    Fee_GlobalRestore();

    return retVal;
} /* End of Fee_GetSectorSwitchStatus() */      /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void, FEE_API_CODE) Fee_SuspendWrites(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_SUSPEND_WRITE))
    {
        return;
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

    /* no synchronization necessary: Only  Fee_ResumeWrites also writes this flag */
    Fee_Globals_t.WritesSuspended_bl = TRUE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

FUNC(void, FEE_API_CODE) Fee_ResumeWrites(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
# if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_RESUME_WRITE))
    {
        return;
    }
# endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

   /* no synchronization necessary: Only  Fee_SuspendWrites also writes this flag */
   Fee_Globals_t.WritesSuspended_bl = FALSE;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */

#if (FEE_FSS_CONTROL_API == STD_ON)
    FUNC(void, FEE_API_CODE) Fee_DisableFss(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
    {
    # if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
        /* Has module been initialized? (FEE_E_NO_INIT) */
        if (E_OK != Fee_DetChkUninit(FEE_SID_DISABLE_FSS))
        {
            return;
        }
    # endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

        Fee_GlobalSuspend();
        Fee_Globals_t.ApiFlags_t &= (FEE_API_FLAG_ENABLE_FSS ^ 0xFFu);
        Fee_GlobalRestore();
      
    } /* PRQA S 2006 */ /* MD_MSR_14.7 */

    FUNC(void, FEE_API_CODE) Fee_EnableFss(void)  /* PRQA S 1503 */ /* MD_MSR_14.1 */
    {
    # if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
        /* Has module been initialized? (FEE_E_NO_INIT) */
        if (E_OK != Fee_DetChkUninit(FEE_SID_ENABLE_FSS))
        {
            return;
        }
    # endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

        Fee_GlobalSuspend();
        Fee_Globals_t.ApiFlags_t |= FEE_API_FLAG_ENABLE_FSS;        
        Fee_GlobalRestore();
    } /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
/**********************************************************************************************************************
 *  Fee_DetChkUninit
 *********************************************************************************************************************/
/*! \brief      This function checks if an API function has been called and the module has been initialized by the
 *              function WdgM_Init(). This functions is only performed if development error tracing and the 
 *              UNINIT-check has been switched on.
 *  \param[in]  ApiId_u8loc                                The ServiceID (SID) of the the corresponding function.
 *  \param[out] -
 *  \return     E_OK                                       If module has been initialized while API call.
 *  \return     E_NOT_OK                                   If module has not been initialized while API call.
 *  \pre        -
 *  \context    -
 *  \note       -
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, FEE_PRIVATE_CODE) Fee_DetChkUninit(const uint8 ApiId_u8loc)
{
    /* use ApiId_loc to avoid compiler warnings -> use bitwise operations (is E_OK was not deined to zero, the final 
       OR is necessary to gain the correct value */
    Std_ReturnType retVal = (Std_ReturnType)((ApiId_u8loc & E_OK) | E_OK);
    /* Is the module initialized? */
    if (Fee_ModuleStatus_t == MEMIF_UNINIT)
    {
        /* Report development error. */
        Fee_Errorhook(ApiId_u8loc, FEE_E_NO_INIT);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */

        retVal = E_NOT_OK;
    }

    return retVal;
}      
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

/**********************************************************************************************************************
 * Fee_DetChkBlockNumber
 *********************************************************************************************************************/
/*! \brief      This function performs the block number check if the corresponding precompile switch is switched on.
 *
 *  \param[in]  ApiId_u8            The ServiceID (SID) of the the corresponding function.
 *  \param[in]  BlockNumber_u16     The block number to be checked.
 *  \return     E_OK                The BlockNumber check succeeded.
 *  \return     E_NOT_OK            The BlockNumber check failed.
 *********************************************************************************************************************/
#if (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER)
static FUNC(Std_ReturnType, FEE_PRIVATE_CODE) Fee_DetChkBlockNumber
  (
    const uint8 ApiId_u8, const uint16 BlockNumber_u16
  )
{
  uint16 BlockId_u16loc;

  /* Check reserved block numbers. */
  if (((uint16)FEE_RESERVED_BLOCK_NUMBER_1 == BlockNumber_u16) ||
      ((uint16)FEE_RESERVED_BLOCK_NUMBER_2 == BlockNumber_u16))
  {
      /* Report development error. */
      Fee_Errorhook(ApiId_u8, FEE_E_INVALID_BLOCK_NO);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
      return (E_NOT_OK);
  }

  /* Check block number.
   * Assign block ID which is encoded in parameter BlockNumber. 
   */
  BlockId_u16loc = Fee_InternalGetBlockId(BlockNumber_u16);

  /* Check if the block ID is not out of range.
   * Adapting the block ID to a 0-based index value is not necessary in this case because of the '>' 
   * (Greater Than) operator.
   */
  if (BlockId_u16loc > (Fee_Globals_t.Config_pt->Fee_NumberOfBlocks_u16 - (uint16)1u))
  {
# if (STD_ON == FEE_DEBUG_REPORTING)
      /* Report development error. */
      Fee_Errorhook(ApiId_u8, FEE_E_INVALID_BLOCK_NO);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
#else
  /* intialization is unnecessary, but it helps to avoid compiler warning */
  BlockId_u16loc = ApiId_u8;
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

    return (E_NOT_OK);
  }

  /* Check dataset number. */
  if ((BlockNumber_u16 & (uint16)FEE_DATASET_SELECTION_BITS_MASK) >
        ((uint16)(Fee_Globals_t.Config_pt->BlockConfig_at[BlockId_u16loc].NumberOfDatasets_u8) - (uint16)1u))
  {
# if (STD_ON == FEE_DEBUG_REPORTING)
      /* Report development error. */
      Fee_Errorhook(ApiId_u8, FEE_E_INVALID_BLOCK_NO);      /* PRQA S 3200 */ /* MISRA-C:2004 Rule 16.10 According to a component requirement the return values of that function is right and has to be ignored. */
# endif /* (STD_ON == FEE_DEBUG_REPORTING) */

    return (E_NOT_OK);
  }

  return (E_OK);
}      /* PRQA S 2006 */ /* PRQA S 4700 */ /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif /* (STD_ON == FEE_CFG_CHK_PARAM_BLOCK_NUMBER) */

#if (STD_ON == FEE_FORCE_SECTOR_SWITCH_API)
/**********************************************************************************************************************
 * Fee_ForceSectorSwitch
 *********************************************************************************************************************/
/*! \brief      Set a flag, that the sector switch will be forced twice.
 *
 *  \pre        Module must be initialized.
 *  \return     Current module status.
 *  \context    Application
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FEE_API_CODE) Fee_ForceSectorSwitch(void) /* PRQA S 1503 */ /* MD_MSR_14.1 */
{
  /* Check if module shall be tested for being initialized. */
#if (STD_ON == FEE_CFG_CHK_STATUS_UNINIT)
    /* Has module been initialized? (FEE_E_NO_INIT) */
    if (E_OK != Fee_DetChkUninit(FEE_SID_FORCE_SECTOR_SWITCH))
    {
        return (E_NOT_OK);
    }
    else
    {
        /* Module has been initialized. */
    }
#endif /* (STD_ON == FEE_CFG_CHK_STATUS_UNINIT) */

  /* Disable global interrupts. */
  Fee_GlobalSuspend();

    /* set ForceSectorSwitch flag to note, that two sector switches must be done,
    *  enable all types of SectorSwitch .
    * An eventually already running sector switch cuases Fee_ForceSectorSwtich do perform only one additional Sector Switch */
    Fee_Globals_t.ApiFlags_t |= FEE_API_FLAG_FORCE_SECTOR_SWITCH | FEE_API_FLAG_ENABLE_FSS | FEE_API_FLAG_ENABLE_BSS;
      
    /* set module state to MEMIF_BUSY_INTERNAL, only if Fee is MEMIF_IDLE. */
    if(MEMIF_IDLE == Fee_Globals_t.FeeModuleStatus_t)
    {
        Fee_Globals_t.FeeModuleStatus_t = MEMIF_BUSY_INTERNAL;
    }

    /* Enable global interrupts. */
    Fee_GlobalRestore();

    return (E_OK);
}  /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif

/**********************************************************************************************************************
 * Fee_Fsm
 *********************************************************************************************************************/
/*! \brief      This function executes exactly one State of a state machine. This initial state contains two exits. 
 *              Which exit is taken depends on the queries which in turn lead to the actions. At last the next state 
 *              is stored. The next time the function is called, it executes this next state. 
 *              This function is called from Fee_Mainfunction() which is called cyclically.
 *
 *  \param[in]  State_pt             Denotes the current state.
 *  \param[out] State_pt             Denotes the next state.
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_Fsm(Fee_StateRefType State_pt)
{
    const Fee_StateDescriptorConstRefType CurrentExit_ptloc = &Fee_StateDescrTable_at[*State_pt];

  Fee_StateType NextState_tloc;
  Fee_StateChangeActionsPtrType Actions_ptloc;

/* PRQA S 0842 8 */ /* MISRA Rule 19.5: Macro defined whitin this block is only used here; code is intended for internal Testing purposes only */
#ifdef FEE_TESTING_LOG_TRANSITIONS
# define SetTransId(x) (transId = (x))
  sint16 transId = 0;
  TsxFee_LogExecutedQueries logQueries;
  logQueries.count = 0;
#else
# define SetTransId(x)
#endif

  /* Execute the first query, if it is fulfilled then do the corresponding action and return with the next state
   * to Fee_MainFunction(). If the first query is not true then execute next query as long as the right exit
   * is found.
   */
#if (3u == FEE_MAX_NUM_OF_STATE_CONDITIONS)
    if (Fee_FsmQuery(CurrentExit_ptloc->ChangeConditions_at[0u].Queries_at, &logQueries))       /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
      NextState_tloc = CurrentExit_ptloc->ChangeConditions_at[0u].NextState_t;
      Actions_ptloc = &CurrentExit_ptloc->ChangeConditions_at[0u].Actions_t;
    }
    else if (Fee_FsmQuery(CurrentExit_ptloc->ChangeConditions_at[1u].Queries_at, &logQueries))  /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
      SetTransId(1);
      NextState_tloc = CurrentExit_ptloc->ChangeConditions_at[1u].NextState_t;
      Actions_ptloc = &CurrentExit_ptloc->ChangeConditions_at[1u].Actions_t;
    }
    /* this ELSE IF must NOT be removed, because it is important to increment CurrentExit_ptloc a second time */
    else if (Fee_FsmQuery(CurrentExit_ptloc->ChangeConditions_at[2u].Queries_at, &logQueries))  /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
      SetTransId(2);
      NextState_tloc = CurrentExit_ptloc->ChangeConditions_at[2u].NextState_t;
      Actions_ptloc = &CurrentExit_ptloc->ChangeConditions_at[2u].Actions_t;
    }
    else
    {
      SetTransId(3);
      NextState_tloc = Fee_StateDescrTable_at[*State_pt].FinalCondition_t.NextState_t;
      Actions_ptloc = &(Fee_StateDescrTable_at[*State_pt].FinalCondition_t.Actions_t);
    }
#else /* ECO_DISABLE_GENERATION : FSM condition check. No test necessary. */
# error "Only case '3 conditions (4 state exits)' is implemented"
#endif

#ifdef FEE_TESTING_LOG_TRANSITIONS
  TsxFee_LogStateTransition(*State_pt, transId, NextState_tloc, &logQueries);
#endif

  *State_pt = NextState_tloc;

  Fee_ActionTable_ap[Actions_ptloc->ActionHandler1_t]();
  Fee_ActionTable_ap[Actions_ptloc->ActionHandler2_t]();
}

/**********************************************************************************************************************
 * Fee_FsmQuery
 *********************************************************************************************************************/
/*! \brief      Process a state machine query (logical AND)
 *
 *  \param[in]  Queries_at                 The queries to be AND'ed together
 *  \return     TRUE                       All queries executed are true.
 *  \return     FALSE                      At least one query executed is false.
 *********************************************************************************************************************/
#ifdef FEE_TESTING_LOG_TRANSITIONS
    static FUNC(boolean, FEE_PRIVATE_CODE) Fee_FsmQuery (Fee_StateQueryPtrType Queries_at, TsxFee_LogExecutedQueries* executed)
    {
        boolean retVal = Fee_QueryTable_ap[Queries_at[0u]]();

        executed->query[executed->count].id = Queries_at[0];
        executed->query[executed->count].result = retVal;
        executed->count++;

        if(retVal)
        {
            retVal = Fee_QueryTable_ap[Queries_at[1u]]();

            executed->query[executed->count].id = Queries_at[1u];
            executed->query[executed->count].result = retVal;
            executed->count++;

        }
        return retVal;
    }
#else
    static FUNC(boolean, FEE_PRIVATE_CODE) Fee_FsmQueryImpl(Fee_StateQueryPtrType Queries_at)
    {
        #if (2u == FEE_MAX_NUM_OF_QRY_AND)
          /* Currently there are no queries with side-effects, forcing execution in the defined order. */
          return (boolean)(((Fee_QueryTable_ap[Queries_at[0u]]()) && (Fee_QueryTable_ap[Queries_at[1u]]())));   /* PRQA S 3344,3415 *//* MD_FEE_13.2_boolean, MD_FEE_12.4_queries */
        #else /* ECO_DISABLE_GENERATION : FSM-query check. No test necessary. */
        # error "Currently two AND-associated queries per state exit are supported"
        #endif
    }
#endif

/**********************************************************************************************************************
 * Fee_InternalActInitFsm
 *********************************************************************************************************************/
/*! \brief      This functions initializes a sub-state-machine to the initial state given by the parameter. Therefore
 *              the state machine stack is incremented.
 *
 *  \param[in]  InitState_t            The initial state the sub FSM shall be initialized with.
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalActInitFsm(Fee_FsmStackRefType FsmStack, const Fee_StateType InitState_t)
{
  FsmStack->TopOfStack_u8++;
  FsmStack->Stack_at[FsmStack->TopOfStack_u8] = InitState_t;

#ifdef FEE_TESTING_LOG_TRANSITIONS
  TsxFee_LogFsmInitalization(InitState_t);
#endif
}

/**********************************************************************************************************************
 * Fee_InternalApiInit
 *********************************************************************************************************************/
/*! \brief      Common initialization of a Fee job.
 *
 *  \param[in]  uint16                BlockNumber_u16   The block number of the requested job.
 *  \param[in]  Fee_RequestFeeJobType RequestedJob_t    The type of the requested job.
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalApiInit
(
  uint16 BlockNumber_u16,
  Fee_RequestFeeJobType RequestedJob_t
)
{
  if(RequestedJob_t <= FEE_JOB_WRITE)
  {
    /* If FSS_Control API is enabled, FSS can be controlled via Fee_EnableBss and Fee_DisableFss */
    /* BSS can be controlled via Fee_SetMode */

    #if (FEE_FSS_CONTROL_API == STD_OFF)
      Fee_Globals_t.ApiFlags_t |=  FEE_API_FLAG_ENABLE_FSS;
    #endif
  }
  /* set module state to MEMIF_BUSY. */
  Fee_Globals_t.FeeModuleStatus_t = MEMIF_BUSY;

  /* Store BlockNumber which is needed in the MainFunction for initializing the job data.
   * It is used to:
   * - if it has been interrupted by a SectorSwitch
   * - if a running SectorSwitch in background mode is interrupted by an incoming job
   */
  Fee_Globals_t.FeeJobParameter_t.blockConfig_pt = 
                                    &Fee_Globals_t.Config_pt->BlockConfig_at[Fee_InternalGetBlockId(BlockNumber_u16)];
  Fee_Globals_t.FeeJobParameter_t.DataIndex_u8 = (uint8)(BlockNumber_u16 & FEE_DATASET_SELECTION_BITS_MASK);
  Fee_Globals_t.FeeJobParameter_t.PartitionIndex_s8 = 
                                    (sint8)(Fee_Globals_t.FeeJobParameter_t.blockConfig_pt->PartitionIndex);

  /* set requested read-job for later decision in state machine. */
  Fee_Globals_t.FeeJobParameter_t.RequestedFeeJob_t = RequestedJob_t;

  /* Job has been accepted. Hence, module is pending. */
  Fee_Globals_t.FeeJobResult_t = MEMIF_JOB_PENDING;
}

/**********************************************************************************************************************
 * Fee_InternalGetBlockId
 *********************************************************************************************************************/
/*! \brief      This function retrieves the block ID at a zero-based index which is extracted from the BlockNumber
 *              parameter and the dataset selection bits.
 *
 *  \param[in]  BlockNumber_u16     Contains the block number and the selected dataset.
 *  \return                         The block ID.
 *********************************************************************************************************************/
static FUNC(uint16, FEE_PRIVATE_CODE) Fee_InternalGetBlockId(const uint16 BlockNumber_u16)
{
  return ((BlockNumber_u16 >> (uint16)Fee_Globals_t.Config_pt->Fee_DatasetSelectionBits_u8) - (uint16)1u);
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS STATE MACHINE - ACTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_ActCalculateNextInstanceIndex
 *********************************************************************************************************************/
/*! \brief      calculates the next instance index for the binary and the lineary search.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActCalculateNextInstanceIndex(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;
    const Fee_InstanceDescriptorRefType instDescr_ptloc = context_pt->instDescr_pt;
    uint16 newInstanceIndex = instDescr_ptloc->index_u16;
    boolean searchEnd = FALSE;

    /* evaluate current instance header status */
    Fee_InstanceStatusType currStatus_t = 
        Fee_InternalEvalInstHdrStatus(Fee_ChunkInfo_GetSector(&instDescr_ptloc->chunk_t),
                                                              context_pt->Buffer_au32, Fee_Globals_t.FlsJobResult_t);

    /* binary search */
    if(context_pt->binarySearch_bl) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        const uint16 BinaryStep = ((newInstanceIndex + 1u) & (uint16)(~newInstanceIndex)) >> 1;

        /* check if an instance on the last level of the binary tree has been read (--> next search step == 0) */
        if(0u == BinaryStep)
        {
            /* --> set end flag to finish the binary search */
            searchEnd = TRUE;

            /* backup the instance header status and adapt the InstanceIndex, if necessary*/
            if((FEE_INSTANCE_STATUS_EMPTY == currStatus_t) && (0u != newInstanceIndex))
            {
                newInstanceIndex--;

                /* the instance status of the RightestInstance must be stored as instance header status of the last instance */
                currStatus_t = context_pt->UppermostInstanceStatus_t;
            }
        }
        else
        {
            /* --> calculate the next instance-index */

            /* was this instance already written? */
            if(FEE_INSTANCE_STATUS_EMPTY == currStatus_t)
            {
                /* --> search left: next instance = actual instance - BinaryStep */
                newInstanceIndex -= BinaryStep;
            }
            else
            {
                /* --> search right: next instance = actual instance + BinaryStep */
                newInstanceIndex += BinaryStep;

                /* backup the instance header status */
                context_pt->UppermostInstanceStatus_t = currStatus_t;
            }
        }
    }
    /* lineary search */
    else
    {
        /* check if the first instance is reached */
        if((0u == newInstanceIndex) || (FEE_INSTANCE_STATUS_EMPTY != currStatus_t))
        {
            /* --> set end flag to finish the binary search */
            searchEnd = TRUE;

            /* the instance index points already to the last written instance */
        }
        else
        {
            /* --> calculate the next instance-index */
            newInstanceIndex--;
        }
    }

    instDescr_ptloc->index_u16 = newInstanceIndex;
    instDescr_ptloc->status_t = currStatus_t;

    if(searchEnd == FALSE)
    {
        /* continue search with reading next instance header */
        Fee_InternalEvalFlsRetVal(
            Fee_ChunkInfo_ReadInstanceHeader(&instDescr_ptloc->chunk_t, newInstanceIndex, context_pt->Buffer_au32));
                                                                                            
    }
    else
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
        Fee_ActReturnFromSubFsm();
    }
}

/**********************************************************************************************************************
 * Fee_ActEvaluateChunkHopping
 *********************************************************************************************************************/
/*! \brief      This function evaluates the block information which is located in the chunk header, to decide
 *              about further chunk-hopping processing (or finalization).
 *              Precondition: Chunk-Header Read finished. 
 *                            
 *  \return     None
 *********************************************************************************************************************/

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateChunkHopping(void)
{
    const Fee_ChunkHoppingContextRefType context = Fee_Globals_t.chunkHoppingContext_pt;
    const Fee_ChunkInfoRefType chunk = &context->tempChunk_t;

    boolean continueSearch = FALSE;
    enum Fee_MngmtStatus headerStatus;

    struct Fee_BlockIdStruct blockId;

    headerStatus = Fee_ChunkInfo_EvaluateHeaderData(
        chunk,
        &blockId,
        context->headerBuffer_au32,
        (boolean)(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK));

    switch (headerStatus) 
    {
        case FEE_MNGMT_ERASED:
            Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
            break;

        case FEE_MNGMT_CONSISTENT:
               /* matching bits will be XORes to 0, irrelevant bits are forced to 0 => match if result is 0 */
            if((((context->searchBlockId_t.Tag ^ blockId.Tag) & context->blockIdMask_t.Tag) != 0) ||
               (Fee_ChunkInfo_isDataChunk(chunk) &&
                   (((context->searchBlockId_t.DataIndex ^ blockId.DataIndex) & context->blockIdMask_t.DataIndex) != 0)))
            {
                /* BlockTag doesn't match or DataIndex of DataChunk doesn't match */
                continueSearch = TRUE;

                /* advance to next possible chunk address */
                Fee_ChunkInfo_SwitchToSuccessor(chunk);
            }
            else
            {
                Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
                if(context->resultBlockId_pt != NULL_PTR)
                {   /* deliver blockId, if space was supplied */
                    *(context->resultBlockId_pt) = blockId;
                }
            }
            break;

        default:
            /* Chunk Header was inconsistent; we don't need to adapt the address.
             * It was done by Fee_ChunkHeaderInfo_EvaluateHeaderData, due to inconsistency */
            continueSearch = TRUE;
            break;
    }

    if(continueSearch == FALSE)
    {
        /* "normal" search end -> NfA and Result have already been set */
        Fee_ActReturnFromSubFsm();
    }
    else if(Fee_ChunkInfo_GetEndAddress(chunk) <= context->upperSearchLimit_t)
    { /* read next chunk header */
        Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadChunkHeader(chunk, context->headerBuffer_au32));
    }
    else
    { /* we'd had to continue search, but sector end reached -> "abnormal" termination */
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
        
        Fee_ActReturnFromSubFsm();
    }
}

/**********************************************************************************************************************
 * Fee_ActEvaluateWriteCycle
 *********************************************************************************************************************/
/*! \brief      This function evaluates the Write Cycle Counter which is located in the chunk header.
 *              The Fls Read job only retrieved the WriteCycle Counter!!!
 *              The counter is not critical, thus we don't need the remaining chunk header in order to check it.
 *              (Additionally it must at least exist -> due to links and/or checks during chunk-hopping.
 *
 *  \return     None
 *********************************************************************************************************************/
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
    static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateWriteCycle(void)
    {
        const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;
        const Fee_InstanceDescriptorRefType instDescr = context_pt->wccChunk_pt;
        const Fee_SectorConfigRefType sector = Fee_ChunkInfo_GetSector(&instDescr->chunk_t);

        const boolean wccErased = (boolean)((!Fee_ChunkInfo_isDataChunk(&instDescr->chunk_t)) ||
                                            (sector == NULL_PTR) ||
                                            (Fee_Sector_isErasedU32(sector,
                                             context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET])));

        if (MEMIF_JOB_OK != Fee_Globals_t.FlsJobResult_t)
        {
            context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET] = FEE_WRITE_CYCLE_FAILED;
        }
        else if(wccErased) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
        {
            context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET] = FEE_WRITE_CYCLE_EMPTY;
        }
        else
        {
            context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET] +=
                instDescr->index_u16 + ((instDescr->status_t != FEE_INSTANCE_STATUS_EMPTY) ? 1u : 0);
        }
    }
#endif /* (STD_ON == FEE_GET_WRITE_CYCLE_API) */

/**********************************************************************************************************************
 * Fee_ActEvaluateInstanceTrailer
 *********************************************************************************************************************/
/*! \brief      This function evaluates the InstanceTrailer.
 *              Precondition: Called with Header == OK (CurrentInstanceStatus_t)
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateInstanceTrailer(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;
    
    /* PRQA S 0310 4*/ /* MISRA-C:2004 Rule 11.4 These casts ok: It's just a pointer cast to looser alignment */    
    const Fee_InstanceStatusType instStatus = 
                        Fee_InternalEvaluateInstanceStatus(
                            Fee_ChunkInfo_GetSector(&context_pt->instDescr_pt->chunk_t),
                            (Fee_IntBuffer_u8ConstPtrType)context_pt->Buffer_au32, Fee_Globals_t.FlsJobResult_t);

    Fee_LocalJobResultType result = FEE_LOCAL_JOB_RESULT_OK;

    /* evaluate instance trailer against header (== FEE_INSTANCE_STATUS_OK) */
    if(instStatus != FEE_INSTANCE_STATUS_OK)
    {
        /* later we only evaluate the header's status (here it became the overall instance status) */
        context_pt->instDescr_pt->status_t = FEE_INSTANCE_STATUS_FAILED;

        /* instance inconsistent */
        result = FEE_LOCAL_JOB_RESULT_FAILED;
    }

    Fee_Globals_t.FeeLocalJobResult_t = result;
}

/**********************************************************************************************************************
 * Fee_ActEvaluateSectorHeaders
 *********************************************************************************************************************/
/*! \brief      This function evaluates the sector header, especially the sector ID, to determines the CurrentSector
 *              and the old sector. It also determines if both sectors are erased/empty or one or both sectors are
 *              corrupt.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActEvaluateSectorHeaders(void)
{
    const Fee_PartitionConfigRefType partition = Fee_Globals_t.CurrentProcessData.Partition_pt;

    const Fee_SectorConfigRefType sector2 = Fee_Partition_getSectorByPos(partition, FEE_UPPER_SECTOR_NUMBER);

    const Fee_InternalSharedDataRefType FsmVars = &Fee_Globals_t.FsmLocalVars_t;
    const uint8 sectId =  Fee_Sector_evaluateHeaderData(sector2,
                                                        FsmVars->PartitionInitContext_t.sectorHeaderData,
                                                        (boolean)(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK));

    Fee_Partition_initSector(partition, sector2, sectId);
}

#ifdef FEE_NFY_CHUNK_LINK_WRITE_END
/**********************************************************************************************************************
 * Fee_ActFinalizeChunkLinkWrite
 *********************************************************************************************************************/
/*! \brief      This finalizes the chunk link write process process.
 *              Since it just invokes the debug callback, it is only necessary if callback is provided to the FEE
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeChunkLinkWrite(void)
{
    FEE_NFY_CHUNK_LINK_WRITE_END(&Fee_Globals_t, Fee_Globals_t.FlsJobResult_t);
}
#endif

/**********************************************************************************************************************
 * Fee_ActFinalizeChunkAllocation
 *********************************************************************************************************************/
/*! \brief      This finalizes the chunk allocation process.
 *              => evaluate Flash Result, set LocalJobResult accordingly, confirm the NextFreeAddress.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeChunkAllocation(void)
{
    Fee_LocalJobResultType result = FEE_LOCAL_JOB_RESULT_FAILED;

    if(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK)
    {
        const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

        context_pt->ChunkAllocResult_t = FEE_CHUNK_ALLOC_OK;
        Fee_ChunkInfo_Clone(&context_pt->previousChunk_pt->chunk_t, &context_pt->newChunk_t);
        
        context_pt->previousChunk_pt->index_u16 = 0;
        context_pt->previousChunk_pt->status_t = FEE_INSTANCE_STATUS_EMPTY;

        result = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS;
    }

    Fee_Globals_t.FeeLocalJobResult_t = result;
    
    Fee_ActReturnFromSubFsm();
}

/**********************************************************************************************************************
 * Fee_ActFinalizeEraseCycleJob
 *********************************************************************************************************************/
/*! \brief      This function writes the previously read Erase Cycle back to the pointer given by the API call.
 *
 *  \return     None
 *********************************************************************************************************************/
#if (STD_ON == FEE_GET_ERASE_CYCLE_API)
  static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeEraseCycleJob(void)
  {
      const uint16 SectorNumber_u16loc = Fee_Globals_t.FeeJobParameter_t.DataIndex_u8 & 0x01u;
      const Fee_SectorConfigRefType sector_ptloc = 
                        Fee_Partition_getSectorByPos(Fee_Globals_t.CurrentProcessData.Partition_pt, SectorNumber_u16loc);
      /* PRQA S 0310 1 */ /* PRQA S 3305 1 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. The target buffer originally passed via Fee_GetEraseCycleCounter is of type uint32* and hence is expected to be correctly aligned. Verified as ok. */
      *((Fee_UserData32PtrType)(Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8)) =       
           Fee_Sector_getEraseCycleCounter(sector_ptloc);

    Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
  }
#endif

/**********************************************************************************************************************
 * Fee_ActFinalizeBlockCopy
 *********************************************************************************************************************/
/*! \brief      This function finalizes the Block Copy process during SectorSwitch or Data Conversion. 
 *              It advances internal counter or FblSectorSwtichDataset (depending on mode), so that next call to
 *              Fee_ActGetNextBlockToCopy can proceed with next block.
 *              Adfvancing to next block shall be avoided, if FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS was detected
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeBlockCopy(void)
{ 
    if(Fee_Globals_t.FeeLocalJobResult_t != FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS)
    {
        if(FEE_IS_IN_FBL_MODE(&Fee_Globals_t))
        {
            Fee_ChunkInfo_SwitchToSuccessor(&Fee_Globals_t.SectorSwitchData_t.mode.fbl);
        }
        else
        { /* BlockId/Index into blockConfig will be checked (and adapted) with next Sector Switch cycle.      *
             Note that datasets are processed in descending order!                                            */
            Fee_Globals_t.SectorSwitchData_t.mode.appl.DataIndex_s16--;
        }
    }
}

/**********************************************************************************************************************
 * Fee_ActFinalizeGetNextBlockFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for finalizing "Get Next Block" FSM during Sector Switch.
 *              Basically it saves most recent chunk, used by ChunkHopping FSM (which acutally performed the search)
 *              This function makes sense only, if Sector Switch is being performed in FBL mode
 *              (process all chunks that can be found in old sector).
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeGetNextBlockFsm(void)
{
    const Fee_ChunkHoppingContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.super_t;

    if(FEE_IS_IN_FBL_MODE(&Fee_Globals_t))
    {
        Fee_ChunkInfo_Clone(&Fee_Globals_t.SectorSwitchData_t.mode.fbl, &context_pt->tempChunk_t);
    }

    /* reset CurrentDataset (that is the source info) */
    Fee_ChunkInfo_Clear(&Fee_Globals_t.CurrentDataset_t.chunk_t);
}

/**********************************************************************************************************************
 * Fee_ActFinalizeSsCopying
 *********************************************************************************************************************/
/*! \brief      Called if Block Copying during Sector switch completed -> last Block has been processed
 *              (checked, and copied)
 *              We may reset FSS flag as well as "Critical Fill Level" flag.
 *              Old sector is marked as unusable, to be formatted later.
 *              Sector Format will be done in BSS mode, unless another write request causes exceeding of FSS thresholds
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSsCopying(void)
{
    FEE_NFY_SS_END(&Fee_Globals_t); 

    Fee_Partition_freeOldestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);

    /* any deferred job can be processed afterwards */
    Fee_Globals_t.InternalFlags_t &= FEE_FLAG_JOB_DEFERRED_MASK;

    Fee_InternalResetSectorSwitch(&Fee_Globals_t.SectorSwitchData_t, FEE_IS_IN_FBL_MODE(&Fee_Globals_t));

    /* indicate, that sector switch is not actually complete, becuase sector erase is still necessary */
    Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS;
}

/**********************************************************************************************************************
 * Fee_ActFinalizeSectorSwitchFsm
 *********************************************************************************************************************/
/*! \brief      This function finalizes the SectorSwitch FSM. Decisions how the SectorSwitch shall be finished depends on:
 *              - the SectorSwitch is interrupted by an incoming job (SectorSwitch is currently performed in background mode)
 *              - the SectorSwitch has ended OK or Failed, while this LocalJobResult is just forwarded.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSectorSwitchFsm(void)
{
    Fee_LocalJobResultType lastResult = Fee_Globals_t.FeeLocalJobResult_t;

    if(lastResult == FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS)
    { /* suspend sector switch (either block copy or sector erase) */
        lastResult = FEE_LOCAL_JOB_RESULT_OK;
    }
    else /* finalize sector switch */
    {
        if(lastResult != FEE_LOCAL_JOB_RESULT_OK)
        {
            lastResult = FEE_LOCAL_JOB_RESULT_FAILED;
        }
    }

    Fee_Globals_t.FeeLocalJobResult_t = lastResult;
}

/**********************************************************************************************************************
 * Fee_ActFinalizeSetupSectors
 *********************************************************************************************************************/
/*! \brief      This function finalizes the SetupSectors FSM. If the setup process is not finished, yet, it is rather
 *              a "suspend".
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSetupSectors(void)
{
    FEE_NFY_SECTOR_ERASE_END(&Fee_Globals_t, Fee_Globals_t.FlsJobResult_t);

    /* any deferred job can be processed afterwards */
    Fee_Globals_t.InternalFlags_t &= FEE_FLAG_JOB_DEFERRED_MASK;

    if(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK)
    { /* last job was the sector header write */
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
    
        /* make sector usable again. Note that (in case of sector switch) this sector must become
         *  the CurrentSector ASAP! 
         * ... sector is empty -> NfA must be correct */
        Fee_Partition_switchSectors(Fee_Globals_t.CurrentProcessData.Partition_pt);
        Fee_Partition_updateSectorId(Fee_Globals_t.CurrentProcessData.Partition_pt);
    }
    else
    { 
        Fee_Partition_handleError(Fee_Globals_t.CurrentProcessData.Partition_pt, FEE_SECTOR_FORMAT_FAILED);
    }
}

/**********************************************************************************************************************
 * Fee_ActFinalizeJob
 *********************************************************************************************************************/
/*! \brief      This function finalizes a Fee job. Decisions how the job shall be finished depends on the value of the
 *              LocalJobResult, which is mapped to the real JobResult. Finally, the appropriate callback function
 *              is called and the Fee is set to IDLE.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeJob(void)
{
    /* Job succeeded, and/or it may not be repeated (only write class jobs might have been deferred once) */
    if((Fee_Globals_t.FeeLocalJobResult_t == MEMIF_JOB_OK) ||
        ((Fee_Globals_t.InternalFlags_t & FEE_FLAG_JOB_DEFERRED) == 0))
    {
        /* set the job result and call notification */
        /* Take over the JobResult from LocalJobResult. 
         * Note: Due to the case from Fee_LocalJobResultType to MemIf_JobResultType is it necessary, that
         *       the equivalent values are at the same position within the Fee_LocalJobResultIdType.
         */
        switch(Fee_Globals_t.FeeLocalJobResult_t)
        {
            case (Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_OK:
                Fee_Globals_t.FeeJobResult_t = MEMIF_JOB_OK;
                break;
            case (Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_INVALID:
                Fee_Globals_t.FeeJobResult_t = MEMIF_BLOCK_INVALID;
                break;
            case (Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_INCONSISTENT:
                Fee_Globals_t.FeeJobResult_t = MEMIF_BLOCK_INCONSISTENT;
                break;
            default:
                Fee_Globals_t.FeeJobResult_t = MEMIF_JOB_FAILED;
        }

        /* Call callbacks of upper layer component if configured. */
    #if (STD_OFF == FEE_NVM_POLLING_MODE)
        if ((Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_OK == Fee_Globals_t.FeeLocalJobResult_t)
        {
            Fee_NvMJobEndNotification();
        }
        else
        {
            Fee_NvMJobErrorNotification();
        }
    #endif /* (STD_OFF == FEE_NVM_POLLING_MODE) */

        Fee_Globals_t.FeeJobParameter_t.RequestedFeeJob_t = FEE_JOB_NONE;

        /* Set to BUSY_INTERNAL, FEE becomes Idle, if MainFunction does not find anything to process */
        Fee_Globals_t.FeeModuleStatus_t = MEMIF_BUSY_INTERNAL;
    } 
    /* if ((job ok) || (!deferred job) 
         -> else: job was not OKAY, but it may be repeated after sector switch 
                  (write class job, which failed at chunk allocation), no actions */

    /* In general: Request background sector switch, if necessary. *
     * Note that "critical block handling" is not considered here: *
     * such a sector switch is done in foreground (job is WAITING) */
    if(Fee_Partition_getFillLevel(Fee_Globals_t.CurrentProcessData.Partition_pt) > FEE_PART_FILL_LEVEL_NORMAL)
    {
        Fee_InternalRequestSectorSwitch(&Fee_Globals_t, Fee_Globals_t.CurrentProcessData.Partition_pt);
    }
}

/**********************************************************************************************************************
 * Fee_ActFinalizeWriteCycleJob
 *********************************************************************************************************************/
/*! \brief      This function writes the Write Cycle back to the pointer given by the API call. If the Write Cycle
 *              could not be read before or is empty the corresponding LocalJobResult is set which is mapped later to
 *              the real JobResult.
 *
 *  \return     None
 *********************************************************************************************************************/
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
    static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeWriteCycleJob(void)
    {
        const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

        Fee_LocalJobResultType jobResult = FEE_LOCAL_JOB_RESULT_OK;
    /* Check if the write cycle contains a valid value.
     * The invalid values (FEE_WRITE_CYCLE_EMPTY, FEE_WRITE_CYCLE_FAILED) have an odd number and could be determined
     * if the last bit is set.
     */
        Fee_ActEvaluateWriteCycle();

        switch(context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET])
        {
            case FEE_WRITE_CYCLE_FAILED:
                jobResult = FEE_LOCAL_JOB_RESULT_FAILED;
                break;
            case FEE_WRITE_CYCLE_EMPTY:
                jobResult = FEE_LOCAL_JOB_RESULT_INVALID;
                break;
            default:
                /* PRQA S 0310 2*/ /* PRQA S 3305 2*/ /* MISRA-C:2004 Rule 11.4 These casts are necessary. The target buffer originally passed via Fee_GetEraseCycleCounter is of type uint32* and hence is expected to be correctly aligned. Verified as ok. */
                *((Fee_UserData32PtrType)Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8) = 
                    context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET];
        }

        Fee_Globals_t.FeeLocalJobResult_t = jobResult;
    }     
#endif

/**********************************************************************************************************************
 * Fee_ActIncrementToNextInstanceIndex
 *********************************************************************************************************************/
/*! \brief      This function is responsible to increment the instance index to be able to search upwards.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActIncrementToNextInstanceIndex(void)
{
    Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t.instDescr_pt->index_u16++;
}

/**********************************************************************************************************************
 * Fee_ActInitAllocateChunkFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the AllocateChunk FSM.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitAllocateChunkFsm(void)
{
    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

    /* We are pessimistic... */
    context_pt->ChunkAllocResult_t = FEE_CHUNK_ALLOC_SECTOR_FULL;

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_ALLOCATE_CHUNK_CHUNK_HOPPING_FSM);

    Fee_InternalInitSearchForNfaFsm(&Fee_Globals_t, Fee_ChunkInfo_GetSector(&context_pt->previousChunk_pt->chunk_t));
}

/**********************************************************************************************************************
 * Fee_ActInitChunkHoppingFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the ChunkHopping FSM.
 *              During chunk search ==> Context lies withing Chunk-Search Context
 *
 *              It requests searching for a specific block ID (the Block that is currently being processed).
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkHoppingFsm(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;

    Fee_ChunkInfo_Clone(&context_pt->super_t.tempChunk_t, &context_pt->mostRecentChunk_t);

    Fee_InternalInitChunkHoppingFsm(&Fee_Globals_t, &context_pt->super_t);
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalInitChunkHoppingFsm(Fee_GlobalsPtrType globals, Fee_ChunkHoppingContextRefType context)
{
    globals->chunkHoppingContext_pt = context;
    if(Fee_ChunkInfo_GetEndAddress(&context->tempChunk_t) <= context->upperSearchLimit_t)
    {
        Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH);

        Fee_ChunkInfo_SwitchToSuccessor(&context->tempChunk_t);
        Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadChunkHeader(&context->tempChunk_t, context->headerBuffer_au32));
    }
    else
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
    }
}

/**********************************************************************************************************************
 * Fee_ActInitChunkSearchFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the ChunkSearch FSM.
 *              
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkSearchFsm(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;

    context_pt->chunkHoppingForced = FALSE;

    /* check whether the operating sector is valid (if not it is the old one) */
    if(Fee_Sector_isUsable(Fee_ChunkInfo_GetSector(context_pt->recentChunk_pt)))
    {
        /* --> LinktableIndex of current block fits into the linktable: normal chunk search */
        Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_CHUNK_SEARCH_FOLLOW_CHUNK_LINK);
        Fee_ActPrepareChunkLinkReadOfCurrentChunk();
    }
    else
    {   /* sector is not available -> it makes no sense to search inside */
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
    }
}

/**********************************************************************************************************************
 * Fee_ActInitChunkHeaderCheckFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the ChunkHeaderCheck FSM.
 *              => Read current Chunk's Header, compare it to current info (usually read from previous link)
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkHeaderCheckFsm(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    const enum Fee_FlsRequestStatus status = 
        Fee_ChunkInfo_ReadChunkHeader(&context_pt->mostRecentChunk_t, context_pt->super_t.headerBuffer_au32);

    if(status != FEE_REQ_SYNC_USELESS)
    {
        Fee_InternalEvalFlsRetVal(status);
        Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_CHUNK_CONSISTENCY_CHECK);
    }
    else
    {   /* check does not make sense -> current chunk is a pseudo-chunk -> there is no header to be checked */
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
    }
}
/**********************************************************************************************************************
 * Fee_ActInitCreateInstanceFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the CreateInstance FSM.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitCreateInstanceFsm(void)
{
    const Fee_GlobalsPtrType globals = &Fee_Globals_t;
    const Fee_PartitionConfigRefType partition = globals->CurrentProcessData.Partition_pt;
    const Fee_InstanceDescriptorRefType target_pt = globals->FsmLocalVars_t.ChunkAllocContext_t.previousChunk_pt;
    
    const Fee_SectorConfigRefType targetSector = Fee_ChunkInfo_GetSector(&target_pt->chunk_t);

    /* Create an instance depending on config and on write target:                                 *
     * Critical blocks may only be allocated in old sector                                         *
     * (unless old sector is about to be erased; all most recent data instance are in new sector). *
     * Otherwise (we're in new sector and old one contains data), an FSS must be performed first.  */
    
    /* PRQA S 3415 3 */ /* MD_FEE_12.4_queries */
    if((globals->CurrentProcessData.BlockConfig_pt->CriticalData_bl == FALSE) ||
       (!Fee_Partition_isNewestSector(partition, targetSector)) ||
       (Fee_Partition_getFillLevel(partition) == FEE_PART_FILL_LEVEL_SINGLE_SECTOR))
    {  
        const Fee_InstanceWriteContextRefType context_pt = &globals->FsmLocalVars_t.instanceWriteContext_t;
        const Fee_AddressType targetAddr =
                                Fee_ChunkInfo_GetInstanceStartAddress(&target_pt->chunk_t, target_pt->index_u16);
        /* writing an instance cannot be repeated */
        globals->InternalFlags_t &= FEE_FLAG_JOB_DEFERRED_MASK;

        context_pt->sector_pt = targetSector;

        Fee_Sector_ClearBuffer(
                    context_pt->sector_pt, 
                    context_pt->BufferBytes,
                    FEE_INTERNAL_BUFFER_SIZE);

        /* If a write error occurs, the job may not be deferred to be repeated after sector switch
         * write class job is not deferrable anymore; chunk allocation has been passed */
        globals->InternalFlags_t &= FEE_FLAG_JOB_DEFERRED_MASK;   

        FEE_NFY_INSTANCE_WRITE(globals);

        if(globals->FeeJobParameter_t.RequestedFeeJob_t == FEE_JOB_WRITE) 
        { /* just write */
            context_pt->targetOffset_t = targetAddr;
            context_pt->userData_pt = Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8;

            /* Setup byte counter, necessary to count the bytes which have already been written.
               Since we want to write into current chunk, it must contain correct length info         */
            context_pt->ByteCount_s32 = (sint32)Fee_ChunkInfo_getPayload(&target_pt->chunk_t);

            Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_CREATE_INSTANCE_3_REMAINING_WRITE_STREAMS);

            Fee_InternalWriteSuspendHandling(globals, Fee_InternalDoWriteStreamFirst);

        }
        else
        { /* it's an invalidate job */
            /* we don't need to initialize write context; only target address is important */
            Fee_InternalPrepareEmptyInstanceWrite(targetSector, targetAddr, FEE_INSTANCE_STATUS_INVALID);
        }
    }
    else /* Critical Data that would be written into new sector */
    {
        globals->FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
    }
}

#ifdef FEE_NFY_INSTANCE_WRITE_END
/**********************************************************************************************************************
 * Fee_ActFinalizeInstanceWrite
 *********************************************************************************************************************/
/*! \brief      This function is responsible for finalizing the CreateInstance FSM.
 *              It does not "return" from sub-fsm!
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeInstanceWrite(void)
{
    FEE_NFY_INSTANCE_WRITE_END(&Fee_Globals_t, Fee_Globals_t.FlsJobResult_t);
}
#endif

/**********************************************************************************************************************
 * Fee_InternalGetNextBlockToCopy
 *********************************************************************************************************************/
/*! \brief      This function determines the BlockId that shall be used next during sector switch processing.
 *              Depending on configuration/mode (complete / incomplete (aka FBL mode), it may start a sub-FSM.
 *              If necessary the internal variables (esp. SectoSwitchBlockNumber) is initialized.
 *              Shortened Block Number determination (without sub-FSM) also sets FeeLocalJobResult in order
 *              to affect further processing.
 *
 *  \return     None
 *********************************************************************************************************************/
/* Following two functions are only needed here... */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalInitSsChunkSearchFbl(Fee_ChunkInfoRefType fblChunk, Fee_PartitionConfigRefType partitionRef);
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalGetNextBlockToCopy_Appl(Fee_GlobalsPtrType globals);

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalGetNextBlockToCopy(Fee_GlobalsPtrType globals)
{

    if(FEE_IS_IN_FBL_MODE(globals))
    {
        const Fee_ChunkInfoRefType fblChunk = &globals->SectorSwitchData_t.mode.fbl;
        const Fee_ChunkHoppingContextRefType context_pt = &globals->FsmLocalVars_t.chunkSearchContext_t.super_t;

        if(Fee_ChunkInfo_GetBaseAddress(fblChunk) == 0)
        { /* sector switch did not begin - intitialize variables */
            Fee_InternalInitSsChunkSearchFbl(fblChunk, globals->CurrentProcessData.Partition_pt);
            FEE_NFY_SS_START(globals);
        }

        globals->chunkHoppingContext_pt = context_pt;
        globals->CurrentProcessData.BlockConfig_pt = NULL_PTR;
        context_pt->upperSearchLimit_t = Fee_Sector_getEndOffset(Fee_ChunkInfo_GetSector(fblChunk));
        /* initialize chunk Hopping context */
        context_pt->blockIdMask_t.DataIndex = 0;
        context_pt->blockIdMask_t.Tag = 0;
        context_pt->searchBlockId_t = context_pt->blockIdMask_t;
        context_pt->resultBlockId_pt = &globals->CurrentProcessData.BlockId;
        Fee_ChunkInfo_Clone(&context_pt->tempChunk_t, fblChunk);
        
        Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadChunkHeader(fblChunk, context_pt->headerBuffer_au32));

        Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_GET_BLOCK_EVAL_HEADER);
    }
    else
    {
        Fee_InternalGetNextBlockToCopy_Appl(globals);
    }
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalInitSsChunkSearchFbl(Fee_ChunkInfoRefType fblChunk, Fee_PartitionConfigRefType partitionRef)
{
        const Fee_SectorConfigRefType olderSector = 
                                        Fee_Partition_getOldestSector(partitionRef);
		/* Mark "older" sector as full. We achieve this attempt to "allocate" its whole size *
            * Ignore return value (success info)                                                */
        (void)Fee_Sector_allocSpace(olderSector, Fee_Sector_getSize(olderSector));
		
        Fee_ChunkInfo_Construct(fblChunk, olderSector);

        /* skip pseudo chunk */
        Fee_ChunkInfo_SwitchToSuccessor(fblChunk);
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalGetNextBlockToCopy_Appl(Fee_GlobalsPtrType globals)
{
    Fee_BlockConfigRefType blockConfig = globals->Config_pt->BlockConfig_at;
    uint16 currBlockNumber = globals->SectorSwitchData_t.mode.appl.BlockConfigIndex_u16;
    sint16 DataIndex_s16loc = globals->SectorSwitchData_t.mode.appl.DataIndex_s16;
        
    if(DataIndex_s16loc < 0) /* we counted backwards; every value greater than 255 indicates an underflow */
    {
        currBlockNumber++;
    }

	if(currBlockNumber == 0)
	{
        const Fee_SectorConfigRefType olderSector = 
                                        Fee_Partition_getOldestSector(globals->CurrentProcessData.Partition_pt);
			
		/* Mark "older" sector as full. We achieve this attempt to "allocate" its whole size *
            * Ignore return value (success info)                                                */
        (void)Fee_Sector_allocSpace(olderSector, Fee_Sector_getSize(olderSector));

        FEE_NFY_SS_START(globals);
	}

    if(currBlockNumber < globals->Config_pt->Fee_NumberOfBlocks_u16)
    {
        blockConfig = &blockConfig[currBlockNumber];

        if(&globals->Config_pt->PartitionConfig_at[blockConfig->PartitionIndex] != globals->CurrentProcessData.Partition_pt)
        {
            DataIndex_s16loc = -1;    
            globals->FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS; /* indicate wrong partition */
        }
        else
        {
            if(DataIndex_s16loc < 0)
            {
                DataIndex_s16loc = (sint16)blockConfig->NumberOfDatasets_u8 - 1;
            }
                
            globals->FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK; /* indicate that we "found" a next block */
        }

        /* set partition to block's partition */
        globals->CurrentProcessData.BlockConfig_pt = blockConfig;
        globals->CurrentProcessData.BlockId.DataIndex = (uint8)((DataIndex_s16loc < 0) ? 0 : DataIndex_s16loc);
        globals->CurrentProcessData.BlockId.Tag = blockConfig->LinktableIndex_u16;

    }
    else
    {
        currBlockNumber = 0xFFFFu; /* reset id -> for next SectorSwitch */
        DataIndex_s16loc = -1; /* reset dataindex -> for next SectorSwitch */
        globals->FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
    }

    globals->SectorSwitchData_t.mode.appl.BlockConfigIndex_u16 = currBlockNumber;
    globals->SectorSwitchData_t.mode.appl.DataIndex_s16 = DataIndex_s16loc;
}

/**********************************************************************************************************************
 * Fee_ActInitInstanceEvaluationFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the InstanceEvaluation FSM.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceEvaluationFsm(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;
  /* evaluate instance header
   * FirstInstanceStatus_t contains the status of the last written instance, which was found during instance search
   * CurrentInstanceStatus_t contains the status of the last read instance during instance search */
    
    /* initialize with failed. If we actually enter the evaluation FSM, the LocalJobResult will be overwritten. */
    Fee_LocalJobResultType localResult = FEE_LOCAL_JOB_RESULT_FAILED;

    switch(context_pt->instDescr_pt->status_t)
    {
        case FEE_INSTANCE_STATUS_OK:
            /* start the InstanceEvaluation FSM only in this case */
            Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_INSTANCE_EVALUATION_READ_TRAILER);

            /* read instance trailer for evaluation in InstanceEvaluation FSM */
            Fee_ActPrepareInstanceTrailerRead();
 
            /* we don't need to set localResult to OK here */
            break;
        case FEE_INSTANCE_STATUS_EMPTY:
            localResult = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS;
            break;
        case FEE_INSTANCE_STATUS_INCONSISTENT:
            localResult = FEE_LOCAL_JOB_RESULT_INCONSISTENT;
            break;
        case FEE_INSTANCE_STATUS_INVALID:
            localResult = FEE_LOCAL_JOB_RESULT_INVALID;
            break;
        default:
            /* FAILED was the initial value... */
            break;
    }

    Fee_Globals_t.FeeLocalJobResult_t = localResult;
}

/**********************************************************************************************************************
 * Fee_ActInitInstanceEvaluationUpwardsFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the InstanceEvaluation FSM.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceEvaluationUpwardsFsm(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;

    /* evaluate current instance header status */
    context_pt->instDescr_pt->status_t =
        Fee_InternalEvalInstHdrStatus(
                            Fee_ChunkInfo_GetSector(&context_pt->instDescr_pt->chunk_t),
                            context_pt->Buffer_au32, Fee_Globals_t.FlsJobResult_t);

  /* start InstanceEvaluation FSM */
  Fee_ActInitInstanceEvaluationFsm();
}

/**********************************************************************************************************************
 * Fee_ActInitInstanceSearchBinaryFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the InstanceSearchBinary FSM.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceSearchBinaryFsm(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;
    const Fee_InstanceDescriptorRefType instDescr_ptloc = &Fee_Globals_t.CurrentDataset_t;

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_INSTANCE_SEARCH_CALC_INSTANCE);

    context_pt->binarySearch_bl = TRUE;

    context_pt->instDescr_pt = instDescr_ptloc;

    instDescr_ptloc->index_u16 = Fee_ChunkInfo_GetInstanceCount(&instDescr_ptloc->chunk_t) >> 1;

    Fee_InternalEvalFlsRetVal(
        Fee_ChunkInfo_ReadInstanceHeader(&instDescr_ptloc->chunk_t, instDescr_ptloc->index_u16, context_pt->Buffer_au32));
}

/**********************************************************************************************************************
 * Fee_ActInitInstanceSearchLinearyFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the InstanceSearchLineary FSM.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceSearchLinearyFsm(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;
    const Fee_InstanceDescriptorRefType instDescr_ptloc = &Fee_Globals_t.CurrentDataset_t;

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_INSTANCE_SEARCH_CALC_INSTANCE);

    context_pt->binarySearch_bl = FALSE;
    context_pt->instDescr_pt = instDescr_ptloc;

    /* revert to PreviousDataSetChunkLinkAddress_t if the first instance is reached in the current chunk */
    if(0u == instDescr_ptloc->index_u16)
    {
        instDescr_ptloc->index_u16 = Fee_ChunkInfo_GetInstanceCount(&instDescr_ptloc->chunk_t);
    /* set instance index to the chunk-size, because the mid instance will be calculated in Fee_ActCalculateNextInstanceIndex */
    }

    instDescr_ptloc->index_u16--;

    Fee_InternalEvalFlsRetVal(
        Fee_ChunkInfo_ReadInstanceHeader(&instDescr_ptloc->chunk_t, instDescr_ptloc->index_u16, context_pt->Buffer_au32));
}

/**********************************************************************************************************************
 * Fee_ActInitLinkTableAllocationFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for deteriming the necessity of a link-table chunk
 *              and to intitiate its allocation. It's used during sector Switch.
 *              Use SectorSwitchTarget.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitLinkTableAllocationFsm(void)
{
    const Fee_InstanceDescriptorRefType target = &Fee_Globals_t.SectorSwitchTarget_t;
    
    /* PRQA S 3760 4 *//* MD_FEE_10.1_ternary */
    const uint8 datasets =  (uint8)
        ((Fee_Globals_t.CurrentProcessData.BlockConfig_pt != NULL_PTR) ?
                (Fee_Globals_t.CurrentProcessData.BlockConfig_pt->NumberOfDatasets_u8) :
                (Fee_Globals_t.CurrentProcessData.BlockId.DataIndex + 1u));

    /* is a link-table chunk necessary AND is it allowed? */
    if((datasets > 1) && (Fee_ChunkInfo_isLinkTableAllowed(&target->chunk_t)))
    {
        const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;
        context_pt->blockId_t = Fee_Globals_t.CurrentProcessData.BlockId;
        context_pt->previousChunk_pt = target;

#if(FEE_GET_WRITE_CYCLE_API == STD_ON)
        context_pt->wccChunk_pt = &Fee_Globals_t.CurrentDataset_t;
#endif
        Fee_ChunkInfo_InitLinktableChunk(&context_pt->newChunk_t, datasets);
        Fee_ActInitAllocateChunkFsm();
    }
    else
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
    }
}

/**********************************************************************************************************************
 * Fee_ActInitReverseChunkSearch
 *********************************************************************************************************************/
/*! \brief      This function is initializes Reverse Chunk search.
 *              It checks the sector to be searched and prepares the maximum address to be used
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitReverseChunkSearch(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    const Fee_PartitionConfigRefType partition = Fee_Globals_t.CurrentProcessData.Partition_pt;
    const Fee_ChunkInfoRefType currChunk = &Fee_Globals_t.CurrentDataset_t.chunk_t;
    const Fee_ChunkInfoRefType prevChunk = &Fee_Globals_t.PreviousChunk_t;

    if(Fee_ChunkInfo_isDataChunk(prevChunk))
    {
        if(Fee_ChunkInfo_Equals(prevChunk, currChunk)) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
        { /* currentChunk points to same address as previous chunk ==> we already were here.
           * This means: we need to search for previous chunk's predecessor.
           * Since we currently point to a data chunk, chances are good to find a predecessor
           * (that is a data chunk, too!)                                                        */
            const Fee_AddressType limit = Fee_ChunkInfo_GetBaseAddress(currChunk);

            Fee_ChunkInfo_Construct(currChunk, Fee_ChunkInfo_GetSector(currChunk));

            Fee_ChunkSearchContext_Init(context_pt, 
                &Fee_Globals_t.CurrentProcessData.BlockId, prevChunk, currChunk, limit);
            Fee_ActInitChunkSearchFsm();
        }
        else
        {
            Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
            Fee_ChunkInfo_Clone(currChunk, prevChunk);
            Fee_ChunkInfo_Clone(&context_pt->mostRecentChunk_t, prevChunk);
        }
    }
    else if(Fee_Partition_isNewestSector(partition, Fee_ChunkInfo_GetSector(prevChunk)))
    { /* if we ended up at a link-table chunk (initial link-table, or real one),
         we still have the chance to search in older sector */
        const Fee_SectorConfigRefType oldSector = Fee_Partition_getOldestSector(partition);

        Fee_ChunkInfo_Construct(currChunk, oldSector);

        Fee_ChunkSearchContext_Init(context_pt, 
            &Fee_Globals_t.CurrentProcessData.BlockId, prevChunk, currChunk,
                                                    Fee_Sector_getEndOffset(oldSector));

        Fee_ActInitChunkSearchFsm();
    }
    else
    { /* we have nothing but the link table or a link table chunk -> try to search in older sector
       * to achieve this, we just need to set the result accordingly... */
        Fee_ChunkInfo_Clone(currChunk, prevChunk);
        Fee_ChunkInfo_Clone(&context_pt->mostRecentChunk_t, prevChunk);
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
    }
}

/**********************************************************************************************************************
 * Fee_ActInitSearchWrittenInOldSector
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the Search FSM in old sector.
 *              It is only used when searching for the most recently written chunk.
 *              It also conditionally saves the most recent chunk address (in current chunk)
 *              To save the address were to write the link to.
 *              
 *              ChunkSearchContext is still valid, we don't need to re-initialize it
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchWrittenInOldSector(void)
{
    const Fee_SectorConfigRefType oldSector = Fee_Partition_getOldestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);

    /* reset upper search limit -> we have to search the whole sector 
     * => important, because both logical sectors might differ in sice.*/
    Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.super_t.upperSearchLimit_t = Fee_Sector_getEndOffset(oldSector);

    Fee_ChunkInfo_Clear(&Fee_Globals_t.PreviousChunk_t);

    /* Save the chunk (link table or link table chunk, that will get the link, 
     * If we'll need to allocate a chunk in new sector.
     * We implicitly save the info whether the link is writeable...
     * SectorSwitchTarget can be used, since we are processing a WriteJob, not a SectorSwitch */
    Fee_ChunkInfo_Clone(&Fee_Globals_t.SectorSwitchTarget_t.chunk_t, &Fee_Globals_t.CurrentDataset_t.chunk_t);
    Fee_Globals_t.SectorSwitchTarget_t.index_u16 = 0;
    Fee_Globals_t.SectorSwitchTarget_t.status_t = FEE_INSTANCE_STATUS_EMPTY;

    Fee_ChunkInfo_Construct(&Fee_Globals_t.CurrentDataset_t.chunk_t, oldSector);

    Fee_ChunkInfo_Clone(&Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.mostRecentChunk_t, 
                                Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.recentChunk_pt);
}

/**********************************************************************************************************************
 * Fee_ActInitSearchUpwardsFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the SearchUpwards FSM.
 *              Upwards search FSM is done to Find the _first_ valid instance, and hence the first chunk, of a block.
 *              It is used during Sector Switch only, to determine whether block must be copied.
 *              Therfore it is limited to newest logical sector.
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchUpwardsFsm(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    const Fee_InstanceDescriptorRefType target = &Fee_Globals_t.SectorSwitchTarget_t;
    /* we search in current (newer) sector */
    const Fee_SectorConfigRefType newSector =
                                    Fee_Partition_getNewestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);

    /* start with instance index 0 */
    target->index_u16 = 0;
    target->status_t = FEE_INSTANCE_STATUS_EMPTY;

    /* Create a "pseudo" link-table chunk info (the initial linktable isn't actually a chunk) */
    Fee_ChunkInfo_Construct(&target->chunk_t, newSector);

    Fee_ChunkSearchContext_Init(context_pt, 
                                        &Fee_Globals_t.CurrentProcessData.BlockId, NULL_PTR, &target->chunk_t,
                                                                                    Fee_Sector_getEndOffset(newSector));

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_SEARCH_UPWARDS_FOLLOW_CHUNK_LINK);
    Fee_ActPrepareChunkLinkReadOfCurrentChunk();
}

/* reset context to ChunkSearchContext, in order to follow correct chunk link */
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActContinueUpwardsChunkSearch(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    const Fee_InstanceDescriptorRefType target = &Fee_Globals_t.SectorSwitchTarget_t;
    const Fee_SectorConfigRefType newSector = Fee_ChunkInfo_GetSector(&target->chunk_t);

    Fee_ChunkSearchContext_Init(context_pt, 
                                        &Fee_Globals_t.CurrentProcessData.BlockId, NULL_PTR, &target->chunk_t,
                                                                                    Fee_Sector_getEndOffset(newSector));

    Fee_ActPrepareChunkLinkReadOfCurrentChunk();
}

/**********************************************************************************************************************
 * Fee_ActInitSearchWrittenFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the SearchWritten FSM.
 *              Chunk Search Context IS intialized
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchWrittenFsm(void)
{
    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_SEARCH_WRITTEN_CHUNK_SEARCH_CURRENT);
    Fee_ActInitChunkSearchFsm();
}

/**********************************************************************************************************************
 * Fee_ActInitSetupSectorsFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the SetupSectors FSM.
 *              Initialize the sub-FSM (and related context) and trigger sector erase
 *              We always erase the oldest sector!
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSetupSectorsFsm(void)
{
    const Fee_GlobalsPtrType globals = &Fee_Globals_t;
    const Fee_SectorFormatContextRefType context_pt = &globals->FsmLocalVars_t.SectorFormatContext_t;

    const Fee_SectorConfigRefType newSector = Fee_Partition_getNewestSector(globals->CurrentProcessData.Partition_pt);
    uint16 linkTableSize = Fee_Partition_getConfiguredLinktableSize(globals->CurrentProcessData.Partition_pt);
    
    /* Note that the configuration shall always be used if it is complete, regardless of FORCE_FBL_MODE_FLAG! */
    if(globals->Config_pt->Fee_ConfigurationIncomplete) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        /* --> incomplete block configuration: use the LinktableSize of the newer sector,
         *     if configured value is smaller */
        const uint16 minLinkTableSize = Fee_Sector_currentLinktableEntryCount(newSector);
        if(linkTableSize < minLinkTableSize)
        {
            linkTableSize = minLinkTableSize;
        }
    }

    context_pt->sector_pt = Fee_Partition_getOldestSector(globals->CurrentProcessData.Partition_pt);
    context_pt->linkTableSize_u16 = linkTableSize;
    context_pt->sectorId_u8 = Fee_Partition_getNextSectorId(globals->CurrentProcessData.Partition_pt);

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_SETUP_SECTORS_ERASING);

    FEE_NFY_SECTOR_ERASE(globals);
    Fee_InternalWriteSuspendHandling(globals, Fee_InternalDoSectorErase);
}

/* PRQA S 3673 1 */ /* MISRA Rule 16.7: It shall be allowed, to modify content of globals; a function prototype does not depend on function's implementation! */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoSectorErase(const Fee_GlobalsPtrType globals)
{
    Fee_InternalEvalFlsRetVal(Fee_Sector_erase(globals->FsmLocalVars_t.SectorFormatContext_t.sector_pt));
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetupSectorsWriteHeader(void)
{
    const Fee_SectorFormatContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.SectorFormatContext_t;
    /* handle wrap around, in order to prevent from writing an invalid sector id */

    Fee_Sector_assembleHeader(context_pt->sector_pt, 
                              context_pt->sectorHeader_au32,
                              context_pt->sectorId_u8,
                              context_pt->linkTableSize_u16);

    Fee_InternalWriteSuspendHandling(&Fee_Globals_t, Fee_InternalDoSectorHeaderWrite);
}

/* PRQA S 3673 1 */ /* MISRA Rule 16.7: It shall be allowed, to modify content of globals; a function prototype does not depend on function's implementation! */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoSectorHeaderWrite(const Fee_GlobalsPtrType globals)
{
    /* PRQA S 0310 3 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    Fee_InternalEvalFlsRetVal(
        Fee_Sector_writeHeader(
            globals->FsmLocalVars_t.SectorFormatContext_t.sector_pt,
                globals->FsmLocalVars_t.SectorFormatContext_t.sectorHeader_au32));
}

/**********************************************************************************************************************
 * Fee_ActPreInitWriteProcessing
 *********************************************************************************************************************/
/*! \brief      This function is responsible to prepare write processing
 *              Specifically it initializes the chunk allocation variable context
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPreInitWriteProcessing(void)
{
    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

#if(FEE_GET_WRITE_CYCLE_API == STD_ON)
    /* Current Dataset describes the most recent data chunk (if any)        *
     * Thus, it also contains current write cycle counter                   */
    context_pt->wccChunk_pt = &Fee_Globals_t.CurrentDataset_t;
#endif

    /* If chunk allocation is necessary, CurrentDataset describes the predecessor, unless we need to
     * allocate in the other sector (then, previousChunk will be updated accordingly */
    context_pt->previousChunk_pt = &Fee_Globals_t.CurrentDataset_t;

    context_pt->blockId_t = Fee_Globals_t.CurrentProcessData.BlockId;
}

/**********************************************************************************************************************
 * Fee_ActInitWriteProcessingFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the WriteProcessing FSM.
 *              We are in a WriteJob -> The Block DOES exist in the BlockConfig, i.e. ConfigTableIndex IS valid. 
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitWriteProcessingFsm(void)
{
    const enum Fee_Partition_FillLevelEnum criticality =
                    Fee_Partition_getFillLevel(Fee_Globals_t.CurrentProcessData.Partition_pt);
    const Fee_FlagType forceNewChunk = (Fee_Globals_t.InternalFlags_t & FEE_FLAG_BROKEN_LINK);

    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

    const Fee_InstanceDescriptorRefType instDescr_ptloc = context_pt->previousChunk_pt;
    const Fee_ChunkInfoRefType currChunk = &instDescr_ptloc->chunk_t;
    const boolean isNewSector = (boolean)
                        (Fee_Partition_isNewestSector(Fee_Globals_t.CurrentProcessData.Partition_pt,
                                                      Fee_ChunkInfo_GetSector(currChunk)));

    if((criticality >= FEE_PART_FILL_LEVEL_FSS) ||
       ((forceNewChunk != 0) && (!isNewSector)))
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;

        if((Fee_Globals_t.ApiFlags_t & FEE_API_FLAG_ENABLE_FSS) != 0)
        {
            Fee_Globals_t.InternalFlags_t |= FEE_FLAG_JOB_DEFERRED;
        }
        else
        {
            Fee_Globals_t.InternalFlags_t &= FEE_FLAG_JOB_DEFERRED_MASK;
        }
    }
    else
    {
        const Fee_BlockConfigRefType blockConfig = Fee_Globals_t.CurrentProcessData.BlockConfig_pt;
        const uint16_least instanceCount = Fee_ChunkInfo_GetInstanceCount(currChunk);

        /* a broken link shall only result in chunk allocation, if we currently are in "older sector" */

        /* okay, writing is possible */
        if(instDescr_ptloc->status_t != FEE_INSTANCE_STATUS_EMPTY)
        { /* the last instance that was found was not empty 
          (binary instance searche may find the first empty or last written instance */
            instDescr_ptloc->index_u16++;
        }
 
        /* Write-Job may be deferred (by sector switch), unless we are writing the instance */
        Fee_Globals_t.InternalFlags_t |= FEE_FLAG_JOB_DEFERRED;

       /* Check whether a new chunk is necessary:
          - Block Config (length) changed
          - CurrentChunk is a Datachunk, but it is full.
          - CurrentChunk is a Link-Table Chunk
          - Current Chunk points to Link-Table (addtional states necessary, if we need to allocat a link-table chunk first
          - BrokenLink and we're in old sector (allocate in new sector!)  */
        if((Fee_ChunkInfo_isDataChunk(currChunk)) &&
            (instDescr_ptloc->index_u16 < instanceCount) &&
           (Fee_ChunkInfo_doesConfigMatch(currChunk, blockConfig)) &&
            (!forceNewChunk))
            { /* chunk is not full, config matches and no broken link -> no allocation necessary */
            Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_WRITE_PROCESSING_CREATE_INSTANCE);
            Fee_ActInitCreateInstanceFsm();
        }
        else
        { /* chunk allocation is necessary */
            if((Fee_ChunkInfo_isLinkTableAllowed(currChunk)) && 
                (blockConfig->NumberOfDatasets_u8 > 1))
            {  /* link table chunk */
                Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_WRITE_PROCESSING_ALLOC_LINKTABLE);
                Fee_ChunkInfo_InitLinktableChunk(&context_pt->newChunk_t, (uint8)blockConfig->NumberOfDatasets_u8);

                Fee_ActInitAllocateChunkFsm();
                
            }
            else /* data chunk */
            {
                Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_WRITE_PROCESSING_ALLOC_DATACHUNK);
                Fee_ActInitDataChunkAllocWriteFsm();
            }
        }
    }
}

/**********************************************************************************************************************
 * Fee_ActInitSearchForNfa_WriteFsm
 *********************************************************************************************************************/
/*! \brief      This function initiates Chunk Hopping FSM for searching Nfa in current sector.
 *              It is used only during write processing; chunk hopping will only be performed if Nfa 
 *              was not confirmed yet.
 *              It decides what type of chunk needs to be allocated, and whether it can do so in operating sector. 
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitSearchForNfa_WriteFsm(void)
{
    const Fee_SectorConfigRefType newSector = Fee_Partition_getNewestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);
    Fee_InternalInitSearchForNfaFsm(&Fee_Globals_t, newSector);
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalInitSearchForNfaFsm(Fee_GlobalsPtrType globals_pt,
                                                                    Fee_SectorConfigRefType sector_pt)
{
    const Fee_ChunkHoppingContextRefType context_pt = &globals_pt->FsmLocalVars_t.ChunkAllocContext_t.super_t;

    globals_pt->FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;

    if(!Fee_Sector_isFillLevelKnown(sector_pt))
    {
        context_pt->upperSearchLimit_t = Fee_Sector_getEndOffset(sector_pt);

        context_pt->blockIdMask_t.Tag       = 0xFFFFu;
        context_pt->blockIdMask_t.DataIndex = 0xFFu;
        /* we search for next free address by searching for a block that most likely will not extist */
        context_pt->searchBlockId_t = context_pt->blockIdMask_t;

        context_pt->resultBlockId_pt = NULL_PTR; /* we are not interested in getting the result block id */

        /* basically the chunk type does not matter, as it will be determined by reading chunk header; *
         * here we create smallest legal data chunk                                                    */
        Fee_ChunkInfo_InitDataChunk(&context_pt->tempChunk_t, 1, 1);

        /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
        if(Fee_ChunkInfo_AssignSector(&context_pt->tempChunk_t, sector_pt))
        {
            globals_pt->chunkHoppingContext_pt = context_pt;

            Fee_InternalActInitFsm(&globals_pt->FsmStack_t, FEE_STATE_CHUNK_HOPPING_CHUNK_HEADER_SEARCH);

            Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadChunkHeader(&context_pt->tempChunk_t, context_pt->headerBuffer_au32));
        }
        else
        {
            Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
        }
    }        
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeSearchForNfa_WriteFsm(void)
{
    const Fee_ChunkInfoRefType currChunk = &Fee_Globals_t.CurrentDataset_t.chunk_t;

    if(Fee_ChunkInfo_isDataChunk(currChunk)) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        Fee_ActInitInstanceSearchBinaryFsm();
    }
    else
    {
        Fee_Globals_t.CurrentDataset_t.index_u16 = 0;
        Fee_Globals_t.CurrentDataset_t.status_t = FEE_INSTANCE_STATUS_EMPTY;
        Fee_ActReturnFromSubFsm();
    }
}

/**********************************************************************************************************************
 * Fee_ActInitDataChunkAllocWriteFsm
 *********************************************************************************************************************/
/*! \brief      This function initiates data chunk allocation during write job processing
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitDataChunkAllocWriteFsm(void)
{
    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;
    const Fee_BlockConfigRefType blockConfig = Fee_Globals_t.CurrentProcessData.BlockConfig_pt;

    Fee_ChunkInfo_InitDataChunk(&context_pt->newChunk_t,
                                    blockConfig->BlockPayloadSize_u16,
                                    (uint8)blockConfig->NumberOfInstancesExponent_u8);

    Fee_ActInitAllocateChunkFsm();
}

/**********************************************************************************************************************
 * Fee_ActInitChunkAllocCopyFsm
 *********************************************************************************************************************/
/*! \brief      This function initiates chunk allocation for copy purposes, i.e. in current (newer) sector
 *              (Thus, we don't have to worry about broken links)
 *              It ALWAYS allocates a data chunk; i.e. a link-table chunk must have been allocated before, if necessary.
 *              Note that we don't need information about the source chunk anymore.
 *              Function may not be called, if source chunk (current chunk) is a link-table chunk!
 *       
 *              Precondition: SectorSwitchTarget Chunk already points into newer sector 
 *                            current Chunk still points into older sector (copy source).
 *                            
 *                            See: Fee_ActInitCopyProcess()
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitChunkAllocCopyFsm(void)
{
    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;
    const Fee_BlockConfigRefType blockConfig = Fee_Globals_t.CurrentProcessData.BlockConfig_pt;
    uint16 payload;
    uint8 instanceExponent;

    /* allocate a data chunk */
    if(blockConfig != NULL_PTR)
    {
        payload = blockConfig->BlockPayloadSize_u16;
        instanceExponent = (uint8)blockConfig->NumberOfInstancesExponent_u8;
    }
    else
    { /* no Block Config known (FBL mode) -> use config from SourceChunk */
        payload = Fee_ChunkInfo_getPayload(&Fee_Globals_t.CurrentDataset_t.chunk_t);
        instanceExponent = 1u; /* in FBL mode, during SectorSwitch we always create chunks with one instance! */
    }

    context_pt->blockId_t = Fee_Globals_t.CurrentProcessData.BlockId;
    context_pt->previousChunk_pt = &Fee_Globals_t.SectorSwitchTarget_t;

#if(FEE_GET_WRITE_CYCLE_API == STD_ON)
    context_pt->wccChunk_pt = &Fee_Globals_t.CurrentDataset_t;
#endif

    /* now we can store our new chunk's parameters */
    Fee_ChunkInfo_InitDataChunk(&context_pt->newChunk_t, payload, instanceExponent);

    Fee_ActInitAllocateChunkFsm();
}

/**********************************************************************************************************************
 * Fee_ActAllocationInCurrentSetor
 *********************************************************************************************************************/
/*! \brief      This function initiates prepares write allocation in current sector, assuming that
 *              on entry the "older" sector was selected (operating)
 *              
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActAllocationInCurrentSector(void)
{
    if((Fee_Globals_t.FeeLocalJobResult_t != FEE_LOCAL_JOB_RESULT_OK) &&
       (!Fee_Partition_isNewestSector(Fee_Globals_t.CurrentProcessData.Partition_pt,
                                      Fee_ChunkInfo_GetSector(&Fee_Globals_t.CurrentDataset_t.chunk_t))))
    {
        const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

#       if(FEE_GET_WRITE_CYCLE_API == STD_ON)
            /* Current Dataset describes the most recent data chunk (if any)        *
             * Thus, it also contains current write cycle counter                   */
            context_pt->wccChunk_pt = &Fee_Globals_t.CurrentDataset_t;
        #endif

        /* If chunk allocation is necessary, CurrentDataset describes the predecessor, unless we need to
         * allocate in the other sector (then, previousChunk will be updated accordingly */
        context_pt->previousChunk_pt = &Fee_Globals_t.SectorSwitchTarget_t;

        context_pt->blockId_t = Fee_Globals_t.CurrentProcessData.BlockId;

        Fee_ActInitWriteProcessingFsm();
    }
}

/**********************************************************************************************************************
 * Fee_ActInitCopyProcessFsm
 *********************************************************************************************************************/
/*! \brief      This function initializes the copy process during secotr switch: It includes decision whether:
 *              - copying is actually necessary
 *              - chunk allocation is necessary
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitCopyProcessFsm(void)
{
    /* This is the last point in processing we check current Enable state.
     * (Foreground) Sector Switch might have been disabled asynchronously (Fee_DisableFss()) */
    if((Fee_Partition_getFillLevel(Fee_Globals_t.CurrentProcessData.Partition_pt) < FEE_PART_FILL_LEVEL_FSS) ||
        ((Fee_Globals_t.ApiFlags_t & FEE_API_FLAG_ENABLE_FSS)  != 0))
    {
        /* check whether old sector contains data, at all */
        if(Fee_ChunkInfo_isDataChunk(&Fee_Globals_t.CurrentDataset_t.chunk_t))
        {
            const Fee_InstanceDescriptorRefType target = &Fee_Globals_t.SectorSwitchTarget_t;
            const Fee_InstanceDescriptorRefType source = &Fee_Globals_t.CurrentDataset_t;

            /* get the block's configured payload, or - in FBL mode - the source's payload.
             * The latter case results in comparing target's and source's payloads twice ... */
            const uint16 configPayload = (uint16)((Fee_Globals_t.CurrentProcessData.BlockConfig_pt != NULL_PTR) ? 
                        Fee_Globals_t.CurrentProcessData.BlockConfig_pt->BlockPayloadSize_u16 :
                                                            Fee_ChunkInfo_getPayload(&source->chunk_t));
            const uint16_least targetInstances = Fee_ChunkInfo_GetInstanceCount(&target->chunk_t);
            boolean chunkNecessary;

            if(configPayload != Fee_ChunkInfo_getPayload(&source->chunk_t))
            { 
                /* configuration change: is always FALSE in FBL because of value of configPayload */
                source->status_t = FEE_INSTANCE_STATUS_INVALID;
            }

            /* chunk is necessary if: a valid instance was found in old sector and *
             * if it cannot be copied into new sector's chunk                      *
             * (link table chunk, chunk is full or it has another payload)         */                                                 
            chunkNecessary = (boolean)((source->status_t == FEE_INSTANCE_STATUS_OK) &&
                                ((!target->chunk_t.isDataChunk_bl) ||
                                (target->index_u16 >= targetInstances) || 
                                (configPayload != Fee_ChunkInfo_getPayload(&target->chunk_t))));

    #if(FEE_GET_WRITE_CYCLE_API == STD_ON)
            /* To maintain the write cycle counter, we need a chunk, if no data chunk was found in new sector,  *
             * regardless of a valid instance in most recent data chunk in old sector                           */
            chunkNecessary = (boolean)((!Fee_ChunkInfo_isDataChunk(&target->chunk_t)) || chunkNecessary);
    #endif

            if(chunkNecessary)   /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
            {
                /* Previous chunk becomes current -> it is the chunk, which gets the link */
                Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_COPY_ALLOCATE_CHUNK);
                Fee_ActInitChunkAllocCopyFsm();
            }
            else
            {
                Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_COPY_INSTANCE_COPY);
                Fee_ActInitializeBlockCopy();
            }
        }
        else
        { /* we don't have a source (data) chunk, i.e. we even cannot save the write cycle counter */
            Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
        }
    }
    else
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS;
    }
}

/**********************************************************************************************************************
 * Fee_ActInitializeBlockCopy
 *********************************************************************************************************************/
/*! \brief      This function initializes the BlockCopy procedure needed for copying the instance while the garbage
 *              collection.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitializeBlockCopy(void)
{
    const Fee_InstanceDescriptorRefType target = &Fee_Globals_t.SectorSwitchTarget_t;
    const Fee_InstanceDescriptorRefType source = &Fee_Globals_t.CurrentDataset_t;
    const Fee_InstanceCopyContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceCopyContext_t;

    Fee_LengthType copySize = Fee_ChunkInfo_GetInstanceSize(&source->chunk_t);
        
    /* Set Source and Target. */

    context_pt->sourceOffset_t =
        Fee_ChunkInfo_GetInstanceStartAddress(&source->chunk_t, source->index_u16);
    context_pt->targetOffset_t =
        Fee_ChunkInfo_GetInstanceStartAddress(&target->chunk_t, target->index_u16);
    context_pt->ByteCount_t = copySize;

    switch(source->status_t)
    {
        case FEE_INSTANCE_STATUS_INCONSISTENT:
            Fee_InternalPrepareEmptyInstanceWrite(
                                                Fee_ChunkInfo_GetSector(&target->chunk_t),
                                                context_pt->targetOffset_t,
                                                FEE_INSTANCE_STATUS_INCONSISTENT);
            break;
        
        case FEE_INSTANCE_STATUS_OK:
            FEE_NFY_INSTANCE_COPY(&Fee_Globals_t);

            /* Setup byte counter, which is needed to count the bytes which has already be copied/written. */
            Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_CREATE_INSTANCE_BLOCK_COPY_READ);
          /* --> BlockCopy means, that a sector switch is currently executed. Hence, a block/instance is copied from its 
           *     source address at the old sector to the CurrentSector.
           */
           Fee_ActPrepareBlockCopyRead();
           break;
           
        default:
           /* we don't want to pollute the data flash with INVALID instances;
            * do nothing but faking successful instance copy */
           Fee_ActSetLocalJobResultOk();
           break;
    }
}

/**********************************************************************************************************************
 * Fee_ActFinalizeInstanceCopy
 *********************************************************************************************************************/
/*! \brief      This function is responsible for finalizing the CreateInstance FSM.
 *              It does not "return" from sub-fsm!
 *
 *  \return     None
 *********************************************************************************************************************/
#ifdef FEE_NFY_INSTANCE_COPY_END
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeInstanceCopy(void)
{
    FEE_NFY_INSTANCE_COPY_END(&Fee_Globals_t, Fee_Globals_t.FlsJobResult_t);
}
#endif

/**********************************************************************************************************************
 * Fee_ActNop
 *********************************************************************************************************************/
/*! \brief      This function is just a dummy function needed by the state machine to pad unused action locations.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActNop(void)
{
  /* Do nothing. */
}

/**********************************************************************************************************************
 * Fee_InternalDoWriteStreamFirst
 *********************************************************************************************************************/
/*! \brief      This function prepares the first write stream to the Fls driver. This function is called if at least
 *              two requests to the Fls driver are necessary. Hence, this function fills the internal buffer with
 *              the instance header and the first payload data, given by the upper layer.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoWriteStreamFirst(const Fee_GlobalsPtrType globals)
{
    const Fee_InstanceWriteContextRefType context = &globals->FsmLocalVars_t.instanceWriteContext_t;
    const Fee_IntBuffer_u8PtrType DataBuffer_pu8loc = context->BufferBytes;        
    const Fee_AddressType writeAddr = context->targetOffset_t;

    Fee_LengthType writeLength;
    /* Calculate the number of payload data bytes which are possible to be copied into the first stream. */
    sint32 PayloadBytesToCopy_s32 = (sint32)(FEE_INTERNAL_BUFFER_SIZE - FEE_INSTANCE_HEADER_SIZE);

    /* Check if the number of payload data bytes must be truncated due to the smaller payload data configured. */
    if (PayloadBytesToCopy_s32 > context->ByteCount_s32)
    {
        PayloadBytesToCopy_s32 = context->ByteCount_s32;
        context->ByteCount_s32 = -1;

        /* we have only one "write stream", thus set the trailer */
        DataBuffer_pu8loc[PayloadBytesToCopy_s32 + (sint32)FEE_INSTANCE_HEADER_SIZE] = FEE_INSTANCE_STATUS_OK;
        
        writeLength = (Fee_LengthType)PayloadBytesToCopy_s32 + FEE_INSTANCE_HEADER_SIZE + FEE_INSTANCE_TRAILER_SIZE;
    }
    else
    {
        writeLength = FEE_INTERNAL_BUFFER_SIZE;
        
        /* Set Remaining Bytes -> includes the INSTANCE_TRAILER (it must also be written!) */
        context->ByteCount_s32 -= PayloadBytesToCopy_s32;
    }

    /* Writing the instance status to the instance header. */
    DataBuffer_pu8loc[0u] = FEE_INSTANCE_STATUS_OK;

    Fee_InternalFillInstanceBuffer(&DataBuffer_pu8loc[1u], context->userData_pt, (uint16)PayloadBytesToCopy_s32);

    /* Adapt the pointer to the payload data, because these bytes has already been processed now. 
     * So we can "forget" it.  */
    context->userData_pt =
      &context->userData_pt[PayloadBytesToCopy_s32];

    context->targetOffset_t += writeLength;
    
    /* PRQA S 0310 3 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    Fee_InternalEvalFlsRetVal(Fee_Sector_writeData(context->sector_pt, writeAddr, DataBuffer_pu8loc, writeLength));
}

/**********************************************************************************************************************
 * Fee_ActPrepareWriteStreamSecond
 *********************************************************************************************************************/
/*! \brief      This function prepares the second write stream to the Fls driver. This function is called if at least
 *              three requests to the Fls driver are necessary. Hence, this function is only responsible for requesting
 *              a write job with just payload data to the Fls driver. Consequently, the internal buffer is not involved
 *              in this procedure.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareWriteStreamSecond(void)
{
    const Fee_InstanceWriteContextRefType context = &Fee_Globals_t.FsmLocalVars_t.instanceWriteContext_t;

    if(context->ByteCount_s32 > (sint32)((FEE_INTERNAL_BUFFER_SIZE - FEE_INSTANCE_TRAILER_SIZE)))
    {
        Fee_InternalWriteSuspendHandling(&Fee_Globals_t, Fee_InternalDoWriteStreamSecond);
    }
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoWriteStreamSecond(const Fee_GlobalsPtrType globals)
{
    const Fee_InstanceWriteContextRefType context = &globals->FsmLocalVars_t.instanceWriteContext_t;
    const Fee_UserDataConstPtrType writeBuffer = context->userData_pt;
    /* Calculate the size of the 2nd stream. -> "remaining PayloadSize" rounded down to next buffer size */
    const uint16 writeLength = (uint16)context->ByteCount_s32 & ((FEE_INTERNAL_BUFFER_SIZE - 1u) ^ 0xFFFFu);
    const Fee_AddressType writeAddr = context->targetOffset_t;

    context->targetOffset_t += writeLength;
    context->ByteCount_s32 -= writeLength;
    /* Adapt the pointer to the payload data, because these bytes will be processed shortly. So we can "forget" it. */
    context->userData_pt = &writeBuffer[writeLength];

    /* Flash request must be issued here, since from FSM it would be triggered unconditionally */
    Fee_InternalEvalFlsRetVal(Fee_Sector_writeData(context->sector_pt, writeAddr, writeBuffer, writeLength));
}

/**********************************************************************************************************************
 * Fee_ActPrepareBlockCopyRead
 *********************************************************************************************************************/
/*! \brief      This function prepares the reading of an instance step by step (i.e. multiple of internal buffers or at
 *              last the page size of the Flash) which must be copied for the sector switch.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareBlockCopyRead(void)
{
    const Fee_InstanceCopyContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceCopyContext_t;
    const Fee_SectorConfigRefType oldSector = 
                                    Fee_Partition_getOldestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);

    const Fee_LengthType readLength = 
            (context_pt->ByteCount_t > FEE_INTERNAL_BUFFER_SIZE) ? FEE_INTERNAL_BUFFER_SIZE : context_pt->ByteCount_t;

    Fee_Sector_ClearBuffer(oldSector, context_pt->BufferBytes, FEE_INTERNAL_BUFFER_SIZE);

    Fee_InternalEvalFlsRetVal(
        Fee_Sector_readData(oldSector, context_pt->sourceOffset_t, context_pt->BufferBytes, readLength));

    /* update source address for next copy cycle; since the request has been sent to the Fls, we may modify FlsAddress */
    context_pt->sourceOffset_t += readLength;
}

/**********************************************************************************************************************
 * Fee_ActPrepareBlockCopyWrite
 *********************************************************************************************************************/
/*! \brief      This function prepares the writing of an instance step by step (i.e. multiple of internal buffers or at
 *              last the page size of the Flash) which must be copied for the sector switch.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareBlockCopyWrite(void)
{
    Fee_InternalWriteSuspendHandling(&Fee_Globals_t, Fee_InternalDoBlockCopyWrite);
}

/* PRQA S 3673 1 */ /* MISRA Rule 16.7: It shall be allowed, to modify content of globals; prototype does not depend on function's implementation! */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoBlockCopyWrite(const Fee_GlobalsPtrType globals)
{
    const Fee_InstanceCopyContextRefType context_pt = &globals->FsmLocalVars_t.instanceCopyContext_t;
    const Fee_SectorConfigRefType newSector_pt = Fee_Partition_getNewestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);

    /* The length must be calculated again, in the same way as at BlockCopyRead */
    const Fee_LengthType writeLength = 
        (context_pt->ByteCount_t > FEE_INTERNAL_BUFFER_SIZE) ? FEE_INTERNAL_BUFFER_SIZE : context_pt->ByteCount_t;

    Fee_InternalEvalFlsRetVal(Fee_Sector_writeData(newSector_pt, context_pt->targetOffset_t, 
                         context_pt->BufferBytes, writeLength));

    /* update destination address for next copy cycle; since the request has been sent to the Fls, we may modify FlsAddress */
    context_pt->targetOffset_t += writeLength;
    /* Update the bytes of the instance (aligned) which are already copied. */
    context_pt->ByteCount_t -= writeLength;
}

#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
/**********************************************************************************************************************
 * Fee_ActPrepareWccRead
 *********************************************************************************************************************/
/*! \brief      Prepares (starts) reading of write cycle counter field of current chunk's header,
 *              if the chunk is a data chunk.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareWccRead(void)
{
    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;
    const Fee_InstanceDescriptorRefType instDescr_ptloc = context_pt->wccChunk_pt;
    const Fee_ChunkInfoConstRefType chunk = &instDescr_ptloc->chunk_t;

    /* we do not want to read a WCC from LinkTable chunks, and we cannot do so if there is no chunk at all */
    if(Fee_ChunkInfo_isDataChunk(chunk) && (Fee_ChunkInfo_GetSector(chunk) != NULL_PTR))
    {
        const Fee_AddressType addr = 
            Fee_ChunkInfo_GetBaseAddress(chunk) + FEE_CHUNK_HEADER_SIZE_READ;
     
        /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
        Fee_InternalEvalFlsRetVal(Fee_Sector_readMngmtData(Fee_ChunkInfo_GetSector(chunk),
                                                           addr,
                                                           &context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET],
                                                           FEE_WCC_BYTE_COUNT));
    }
    else
    {   /* no data chunk available: fake a successful read, but use the "empty" value */
        Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_OK;
        context_pt->buffer_au32[FEE_CHUNK_HEADER_WCC_WORD_OFFSET] = FEE_WRITE_CYCLE_EMPTY;
    }
}
#endif

/**********************************************************************************************************************
 * Fee_ActPrepareChunkHeaderWrite
 *********************************************************************************************************************/
/*! \brief      This function prepares and starts (due to the limited state exits) the writing of the chunk header at
 *              the location the current chunk header address points to. Therefore, the internal buffer must be filled
 *              with the corresponding data.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareChunkHeaderWrite(void)
{
    const Fee_ChunkAllocContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t;

    /* PRQA S 3344 2*/ /* MD_FEE_13.2_boolean */
    if(Fee_ChunkInfo_AssignSector(&context_pt->newChunk_t,
                                  Fee_ChunkInfo_GetSector(&context_pt->previousChunk_pt->chunk_t)))
    {

        context_pt->ChunkAllocResult_t = FEE_CHUNK_ALLOC_HEADER_FAILED;

        Fee_ChunkInfo_AssembleHeader(&context_pt->newChunk_t, 
                                     &context_pt->blockId_t,
                                     context_pt->buffer_au32);

        /* write cycle counter was already stored at apropriate location */

        FEE_NFY_CHUNK_HEADER_WRITE(&Fee_Globals_t);
        
        Fee_InternalWriteSuspendHandling(&Fee_Globals_t, Fee_InternalDoChunkHeaderWrite);
    }
    else
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
        Fee_ActReturnFromSubFsm();
    }
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoChunkHeaderWrite(const Fee_GlobalsPtrType globals)
{
    const Fee_ChunkAllocContextRefType context_pt = &globals->FsmLocalVars_t.ChunkAllocContext_t;

    Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_WriteHeader(&context_pt->newChunk_t, context_pt->buffer_au32));
}

/**********************************************************************************************************************
 * Fee_ActPrepareChunkLinkReadOfCurrentChunk
 *********************************************************************************************************************/
/*! \brief      This function prepares the reading of the chunk link of the current chunk.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareChunkLinkReadOfCurrentChunk(void)
{
    enum Fee_FlsRequestStatus ret;
    Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_CHUNK_LINK_PROCESSING);

    ret = Fee_ChunkInfo_ReadChunkLink(&context_pt->mostRecentChunk_t,
                                         &context_pt->super_t.searchBlockId_t,
                                         context_pt->super_t.headerBuffer_au32);
    context_pt->chunkLinkPresent = (boolean)(ret != FEE_REQ_SYNC_USELESS);
    Fee_InternalEvalFlsRetVal(ret);
}

/**********************************************************************************************************************
 * Fee_ActPrepareChunkLinkWrite
 *********************************************************************************************************************/
/*! \brief      This function prepares the writing of the chunk link at the location the previous chunk header
 *              address points to. Therefore, the internal buffer must be filled with the corresponding data.
 *
 *  \return     None
 *********************************************************************************************************************/

/* Following function is only used by Fee_ActPrepareChunkLinkWrite */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalsetupChunkLinkWrite(Fee_ChunkAllocContextRefType);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareChunkLinkWrite(void)
{
    FEE_NFY_CHUNK_HEADER_WRITE_END(&Fee_Globals_t, Fee_Globals_t.FlsJobResult_t); 

    if(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK)
    {
        FEE_NFY_CHUNK_LINK_WRITE(&Fee_Globals_t);
        Fee_InternalsetupChunkLinkWrite(&Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t);
    }
    else
    {
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
        Fee_ActReturnFromSubFsm();
    }
}

/* PRQA S 3673 1 */ /* MISRA Rule 16.7: QAC is quite wrong! Making context_pt a pointer to const type is NOT allowd because of Fee_ChunkInfo_AssembleLink */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalsetupChunkLinkWrite(Fee_ChunkAllocContextRefType context_pt)
{
    context_pt->ChunkAllocResult_t = FEE_CHUNK_ALLOC_TRAILER_FAILED;
    Fee_Sector_confirmFillLevel(Fee_ChunkInfo_GetSector(&context_pt->newChunk_t),
                            Fee_ChunkInfo_GetEndAddress(&context_pt->newChunk_t) + 1u);

    Fee_ChunkInfo_AssembleLink(&context_pt->newChunk_t, context_pt->buffer_au32);

    Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_WriteChunkLink(&context_pt->previousChunk_pt->chunk_t,
                                            &context_pt->blockId_t,
                                            context_pt->buffer_au32));
}

/**********************************************************************************************************************
 * Fee_ActPrepareInstanceHeaderRead
 *********************************************************************************************************************/
/*! \brief      This function prepares the reading of the instance header, which is located at the beginning of the 
 *              instance.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareInstanceHeaderRead(void)
{
    Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;

    Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadInstanceHeader(
        &context_pt->instDescr_pt->chunk_t, context_pt->instDescr_pt->index_u16, context_pt->Buffer_au32));
}

/**********************************************************************************************************************
 * Fee_ActPrepareInstanceTrailerRead
 *********************************************************************************************************************/
/*! \brief      This function prepares the reading of the instance trailer, which is located at the end of the 
 *              instance.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareInstanceTrailerRead(void)
{
   const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;

    /* Calculate the address of the instance trailer by go one instance forward and go back about the size of the 
   * trailer. 
   */

    /* PRQA S 0310 1 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadInstanceTrailer(
        &context_pt->instDescr_pt->chunk_t, context_pt->instDescr_pt->index_u16, context_pt->Buffer_au32));
}

/**********************************************************************************************************************
 * Fee_ActPrepareWriteStreamLast
 *********************************************************************************************************************/
/*! \brief      This function prepares the last write stream to the Fls driver. This function is called in any case an
 *              instance must be written to the Flash. 
 *              If the instance is to large to be handled with one request (first stream), the internal buffer is setup
 *              with remaining instance data as well as the instance trailer.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareWriteStreamLast(void)
{
    const Fee_InstanceWriteContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceWriteContext_t;

  /* Do we have to do anything at all?
     Note, that even if byte count IS 0, we have to write the Instance Trailer (ByteCount includes user data only) */
    if(context_pt->ByteCount_s32 >= 0)
    {
        Fee_InternalWriteSuspendHandling(&Fee_Globals_t, Fee_InternalDoWriteStreamLast);
    }
}

/* PRQA S 3673 1 */ /* MISRA Rule 16.7: It shall be allowed, to modify content of globals; prototype does not depend on function's implementation! */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoWriteStreamLast(const Fee_GlobalsPtrType globals)
{
    const Fee_InstanceWriteContextRefType context_pt = &(globals->FsmLocalVars_t.instanceWriteContext_t);
    const Fee_LengthType  writeLength = (Fee_LengthType)context_pt->ByteCount_s32 + FEE_INSTANCE_TRAILER_SIZE;
    const Fee_AddressType writeAddr   = context_pt->targetOffset_t;

    context_pt->BufferBytes[context_pt->ByteCount_s32] = FEE_INSTANCE_STATUS_OK;

    Fee_Sector_ClearBuffer(context_pt->sector_pt, context_pt->BufferBytes, (uint16)context_pt->ByteCount_s32);
    Fee_InternalFillInstanceBuffer(context_pt->BufferBytes, context_pt->userData_pt, (uint16)context_pt->ByteCount_s32);

    Fee_InternalEvalFlsRetVal(
                    Fee_Sector_writeData(context_pt->sector_pt, writeAddr, context_pt->BufferBytes, writeLength));
}

/**********************************************************************************************************************
 * Fee_InternalPrepareEmptyInstanceWrite
 *********************************************************************************************************************/
/*! \brief      This function prepares writing an empty instance, i.e. it just initiates writing an instance header
 *              with status INVALID or INCONSISTENT, depending on parameter "status"
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalPrepareEmptyInstanceWrite(Fee_SectorConfigRefType sector, Fee_AddressType addr, Fee_InstanceStatusType status)
{
    const Fee_IntBuffer_u8PtrType bufPtr = Fee_Globals_t.FsmLocalVars_t.instanceWriteContext_t.BufferBytes;
    
    Fee_Globals_t.FsmLocalVars_t.instanceWriteContext_t.targetOffset_t = addr;
    Fee_Globals_t.FsmLocalVars_t.instanceWriteContext_t.sector_pt = sector;

    bufPtr[0] = bufPtr[1] = bufPtr[2] = bufPtr[3] = (uint8)status;

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_CREATE_INSTANCE_1_REMAINING_WRITE_STREAM);

    Fee_InternalWriteSuspendHandling(&Fee_Globals_t, Fee_InternalDoEmptyInstanceWrite);
}

/* PRQA S 3673 1 */ /* MISRA Rule 16.7: It shall be allowed, to modify content of globals; prototype does not depend on function's implementation! */
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalDoEmptyInstanceWrite(const Fee_GlobalsPtrType globals)
{
    Fee_InternalEvalFlsRetVal(Fee_Sector_writeData(
                         globals->FsmLocalVars_t.instanceWriteContext_t.sector_pt,
                         globals->FsmLocalVars_t.instanceWriteContext_t.targetOffset_t, 
                         globals->FsmLocalVars_t.instanceWriteContext_t.BufferBytes,
                         FEE_INSTANCE_HEADER_SIZE));
}

/**********************************************************************************************************************
 * Fee_ActPreparePayloadDataProcessing
 *********************************************************************************************************************/
/*! \brief      This function prepares the reading/comparing of the payload from/with the Flash.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPreparePayloadDataProcessing(void)
{
    const Fee_InstanceDescriptorRefType instDescr_ptloc = &Fee_Globals_t.CurrentDataset_t;

    if(instDescr_ptloc->status_t == FEE_INSTANCE_STATUS_OK)
    {

        Fee_InternalEvalFlsRetVal(Fee_ChunkInfo_ReadInstancePayload(
                             &instDescr_ptloc->chunk_t,
                             instDescr_ptloc->index_u16,
                             Fee_Globals_t.FeeJobParameter_t.DataBufferPtr_pu8,
                             Fee_Globals_t.FeeJobParameter_t.BlockOffset_u16,
                             Fee_Globals_t.FeeJobParameter_t.Length_u16));

    }
    else
    { /* nothing to read; just translate instance status into local job result */
        /* Make sure that last Fls job result was OK */
        Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_OK;
        
        Fee_Globals_t.FeeLocalJobResult_t = 
            (instDescr_ptloc->status_t == FEE_INSTANCE_STATUS_INVALID) ? 
                FEE_LOCAL_JOB_RESULT_INVALID : FEE_LOCAL_JOB_RESULT_INCONSISTENT;
    }
}

/**********************************************************************************************************************
 * Fee_ActPrepareSearchForNfA
 *********************************************************************************************************************/
/*! \brief      Sets the chunk hopping start address (Current ChunkLinkAddress) to the operating sector's NfA
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActContinueSearchForNfA(void)
{
    const Fee_ChunkHoppingContextRefType context_pt = Fee_Globals_t.chunkHoppingContext_pt;

    Fee_InternalInitChunkHoppingFsm(&Fee_Globals_t, context_pt);
}

/**********************************************************************************************************************
 * Fee_ActPrepareSectorHeaderUpperRead
 *********************************************************************************************************************/
/*! \brief      This function prepares and starts (due to the limited state exits) the reading of the sector header of
 *              the upper sector.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActPrepareSectorHeaderUpperRead(void)
{
    const Fee_PartitionConfigRefType partition = Fee_Globals_t.CurrentProcessData.Partition_pt;
    const Fee_SectorConfigRefType sector1 = Fee_Partition_getSectorByPos(partition, FEE_LOWER_SECTOR_NUMBER);
    const Fee_SectorConfigRefType sector2 = Fee_Partition_getSectorByPos(partition, FEE_UPPER_SECTOR_NUMBER);
    
    const Fee_PartitionInitContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.PartitionInitContext_t;
    const boolean readOk = (boolean)(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK);

    const uint8 sectId = Fee_Sector_evaluateHeaderData(sector1, context_pt->sectorHeaderData, readOk);

    Fee_Partition_initSector(partition, sector1, sectId);

    /* PRQA S 0310 1 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    Fee_InternalEvalFlsRetVal(Fee_Sector_readHeader(sector2, context_pt->sectorHeaderData));
}

/**********************************************************************************************************************
 * Fee_ActReportSectorOverflow
 *********************************************************************************************************************/
/*! \brief      This function reports to the upper layer that a chunk could not be allocated. The sectors are full.
 *              In the callback it could be decided if Fee should stop working or accept only read class jobs.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActReportSectorOverflow(void)
{
    if(Fee_Globals_t.FsmLocalVars_t.ChunkAllocContext_t.ChunkAllocResult_t == FEE_CHUNK_ALLOC_SECTOR_FULL)
    {
        const Fee_PartitionConfigRefType part = Fee_Globals_t.CurrentProcessData.Partition_pt;

        Fee_Partition_handleError(part, FEE_SECTOR_OVERFLOW);

        /* Regardless of handleError's result (how to proceed), reset sector switch data (current block) */
        Fee_InternalResetSectorSwitch(&Fee_Globals_t.SectorSwitchData_t, FEE_IS_IN_FBL_MODE(&Fee_Globals_t));
        
        /* this is quite ugly but important to further processing: It shall prevent from calling Fee_ActFinalizeBlockCopy,
         * which, in turn, attempts to update SectorSwitchData, which just were reset */
        Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS; 
    }
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActResetChunkSearch(void) {
    Fee_ChunkInfo_Construct(&Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.mostRecentChunk_t,
        Fee_ChunkInfo_GetSector(&Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.mostRecentChunk_t));

    Fee_ChunkInfo_unconfirmLink(&Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.mostRecentChunk_t);
    
    Fee_ChunkInfo_Clear(Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.recentChunk_pt);
}

/**********************************************************************************************************************
 * Fee_ActReturnFromSubFsm
 *********************************************************************************************************************/
/*! \brief      This function finalizes the execution of a Sub-State-Machine.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActReturnFromSubFsm(void)
{
#ifdef FEE_TESTING_LOG_TRANSITIONS 
    TsxFee_LogFsmFinalization();
#endif
    Fee_Globals_t.FsmStack_t.TopOfStack_u8--;
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActGetCurrentChunkInfo(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    /* At this place, if Previus chunk's link was defective, current chunk might be an orphan chunk.
     *  This information needs to be inherited in order to go on with search. */

    if(!Fee_ChunkInfo_isLinkConsistent(context_pt->recentChunk_pt))
    {
        Fee_ChunkInfo_unconfirmLink(&context_pt->mostRecentChunk_t);
    }

    Fee_ChunkInfo_Clone(context_pt->recentChunk_pt, &context_pt->mostRecentChunk_t);
    Fee_ChunkInfo_Clone(&context_pt->mostRecentChunk_t, &context_pt->super_t.tempChunk_t);
}

/**********************************************************************************************************************
 * Fee_Act_InitInstanceSearchUpFsm
 *********************************************************************************************************************/
/*! \brief      This function insitializes Upwards instance search (to find chunk's FIRST valid instance).
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActInitInstanceSearchUpwards(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;

    Fee_ChunkInfo_Clone(&Fee_Globals_t.SectorSwitchTarget_t.chunk_t, 
        &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.mostRecentChunk_t);

    context_pt->instDescr_pt = &Fee_Globals_t.SectorSwitchTarget_t;
    context_pt->instDescr_pt->index_u16 = 0u;

    Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS;

    Fee_ActPrepareInstanceHeaderRead();
}

/**********************************************************************************************************************
 * Fee_ActSetLocalJobResultFailed
 *********************************************************************************************************************/
/*! \brief      This function sets the LocalJobResult to Failed.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetLocalJobResultFailed(void)
{
  Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;
}

/**********************************************************************************************************************
 * Fee_ActSetLocalJobResultInvalid
 *********************************************************************************************************************/
/*! \brief      This function sets the LocalJobResult to Invalid.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetLocalJobResultInvalid(void)
{
  Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_INVALID;
}

/**********************************************************************************************************************
 * Fee_ActSetLocalJobResultOk
 *********************************************************************************************************************/
/*! \brief      This function sets the LocalJobResult to Ok.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetLocalJobResultOk(void)
{
  Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
}

/**********************************************************************************************************************
 * Fee_ActSetupSectorSwitchSourceSearch
 *********************************************************************************************************************/
/*! \brief      Stores target information, and prepares the search for copy source in old Sector
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSetupSectorSwitchSourceSearch(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    /* FblSectorSwitch Dataset holds the address of a chunk belonging to the current block */
    Fee_SectorConfigRefType oldSector;

    Fee_ChunkInfo_Clear(&Fee_Globals_t.PreviousChunk_t);

    if(FEE_IS_IN_FBL_MODE(&Fee_Globals_t))
    {
        Fee_ChunkInfo_Clone(&Fee_Globals_t.CurrentDataset_t.chunk_t, &Fee_Globals_t.SectorSwitchData_t.mode.fbl);
    }
    else
    {
        Fee_ChunkInfo_Construct(&Fee_Globals_t.CurrentDataset_t.chunk_t, 
                                 Fee_Partition_getOldestSector(Fee_Globals_t.CurrentProcessData.Partition_pt));
    }
    
    oldSector = Fee_ChunkInfo_GetSector(&Fee_Globals_t.CurrentDataset_t.chunk_t);
    
    Fee_ChunkSearchContext_Init(context_pt, 
                                &Fee_Globals_t.CurrentProcessData.BlockId, 
                                &Fee_Globals_t.PreviousChunk_t,
                                &Fee_Globals_t.CurrentDataset_t.chunk_t,
                                Fee_Sector_getEndOffset(oldSector));

    Fee_InternalActInitFsm(&Fee_Globals_t.FsmStack_t, FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH);
    Fee_ActInitChunkSearchFsm();
}

/**********************************************************************************************************************
 * Fee_InternalEvalFlsRetVal
 *********************************************************************************************************************/
/*! \brief      This function is responsible to check the return value of an Fls API call, and
 *              based on result, to initiate internal wait mechanism
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalEvalFlsRetVal(enum Fee_FlsRequestStatus apiRetVal)
{

    switch(apiRetVal)
    {
        case FEE_REQ_SYNC_OK:
            Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_OK;
            break;

        case FEE_REQ_ACCEPTED:
            Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_PENDING;
            Fee_ActWait();
            break;
        default:
            /* even if Fls rejected the request, set wait flag */
            Fee_Globals_t.FlsJobResult_t = MEMIF_JOB_FAILED;
            Fee_ActWait();
            break;
    }
}

/**********************************************************************************************************************
 * Fee_ActSwitchOperatingSector
 *********************************************************************************************************************/
/*! \brief      This function switches the OperatingSector which is utilized, i.e. searching for a block/dataset
 *              must be continued (restarted) in the older sector.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActSwitchOperatingSector(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    const Fee_SectorConfigRefType oldSector =
                                        Fee_Partition_getOldestSector(Fee_Globals_t.CurrentProcessData.Partition_pt);

	Fee_ChunkInfo_Construct(&Fee_Globals_t.CurrentDataset_t.chunk_t, oldSector);
	Fee_ChunkInfo_Clear(&Fee_Globals_t.PreviousChunk_t);

	Fee_ChunkSearchContext_Init(context_pt, 
			&Fee_Globals_t.CurrentProcessData.BlockId, 
			&Fee_Globals_t.PreviousChunk_t,
			&Fee_Globals_t.CurrentDataset_t.chunk_t,
			Fee_Sector_getEndOffset(oldSector));
}

/**********************************************************************************************************************
 * Fee_ActValidateChunkLink
 *********************************************************************************************************************/
/*! \brief      This function validates the chunk link for a valid value.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActValidateChunkLink(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;

    const Fee_ChunkInfoRefType currentChunk_pt = &context_pt->mostRecentChunk_t;
    const Fee_ChunkInfoRefType newChunk_pt = &context_pt->super_t.tempChunk_t;
    enum Fee_MngmtStatus linkStatus = 
                    Fee_ChunkInfo_InitFromLinkData(newChunk_pt, 
                                                   currentChunk_pt,
                                                   context_pt->super_t.headerBuffer_au32,
                                                   (boolean)(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK));

    switch(linkStatus)
    {
        case FEE_MNGMT_ERASED:
            /* no chunk link stored -> last chunk found */
            Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
            Fee_ChunkInfo_confirmEmptyLink(currentChunk_pt);
            break;

        case FEE_MNGMT_DEFECTIVE: 
            /* perform chunk hopping initialization; set "Broken Link" flag */
            Fee_Globals_t.InternalFlags_t |= (Fee_FlagType)FEE_FLAG_BROKEN_LINK;
            Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_INCONSISTENT;

            Fee_ChunkInfo_unconfirmLink(currentChunk_pt);

            if(context_pt->chunkLinkPresent) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
            {
                /* chunk link is really defective instead of "just absent" */
                context_pt->chunkHoppingForced = TRUE;
            }

            break;

        default:
            if((context_pt->super_t.searchBlockId_t.DataIndex != 0) && 
                      Fee_ChunkInfo_isInitialLinkTable(currentChunk_pt) &&
                            Fee_ChunkInfo_isDataChunk(newChunk_pt))
            { /* we are searching for a Dataset > 0, but initial link-table's entry delivered a data chunk. *
                 The only allowed initial link-table entry pointing to a data chunk is for DataIndex == 0   */
                
                /* Cause chunk hopping, and set broken link flag                                            *
                 * (in order to cause chunk allocation in new chunk if we are  processing a write request)  */
                   
                Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_INCONSISTENT;
                Fee_Globals_t.InternalFlags_t |= (Fee_FlagType)FEE_FLAG_BROKEN_LINK;
                Fee_ChunkInfo_unconfirmLink(currentChunk_pt);
                context_pt->chunkLinkPresent = FALSE;
            }
            else if(Fee_ChunkInfo_GetBaseAddress(newChunk_pt) < context_pt->super_t.upperSearchLimit_t)
            {
                /* store the current chunk link address as previous chunk link address to be able to get one
                 * chunk back (history-process).
                 */
                Fee_ChunkInfo_Clone(context_pt->recentChunk_pt, currentChunk_pt);
                Fee_ChunkInfo_Clone(currentChunk_pt, newChunk_pt);

                Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_INVALID;
            }
            else
            {   /* Finish "Reverse Chunk Hopping" (everything above the current address was already checked)
                 *  New Chunk shall not be considered valid -> it exceeded our search area 
                 */
                Fee_Globals_t.FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_OK;
            }
            break;
    }
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActCheckChunkConsistency(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    struct Fee_BlockIdStruct blockId_tloc;
    Fee_LocalJobResultType localJobResult;
    enum Fee_MngmtStatus headerStatus;
    
    /* initialize address and sector (otherwise the comparison - .Equals - _will_ fail.
       It is oaky to clone the ChunkInfo we will compare to, as long as we check result of .EvaluateHeaderData, which
       also indicates whether ChunkInfo was definitela setup (OK; NOK does not guarantee that it wasn't changed!).
     */
    Fee_ChunkInfo_Clone(&context_pt->super_t.tempChunk_t, &context_pt->mostRecentChunk_t);

    headerStatus = Fee_ChunkInfo_EvaluateHeaderData(
                                                  &context_pt->super_t.tempChunk_t,
                                                  &blockId_tloc,
                                                  context_pt->super_t.headerBuffer_au32,
                                                  (boolean)(Fee_Globals_t.FlsJobResult_t == MEMIF_JOB_OK));
    /* PRQA S 3415 3 */ /* MD_FEE_12.4_queries */
    if((headerStatus == FEE_MNGMT_CONSISTENT) &&
        (context_pt->super_t.searchBlockId_t.Tag == blockId_tloc.Tag) &&
        ((context_pt->super_t.searchBlockId_t.DataIndex == blockId_tloc.DataIndex) || Fee_ChunkInfo_isLinkTable(&context_pt->super_t.tempChunk_t)) &&
        (Fee_ChunkInfo_Equals(&context_pt->super_t.tempChunk_t, &context_pt->mostRecentChunk_t)))
    {
        localJobResult = FEE_LOCAL_JOB_RESULT_OK;
    }
    else
    {
      localJobResult = FEE_LOCAL_JOB_RESULT_INCONSISTENT;
      
      /* important for write write requests: force chunk allocation; if possible in new chunk */
      Fee_Globals_t.InternalFlags_t |= (Fee_FlagType)FEE_FLAG_BROKEN_LINK; 
      context_pt->chunkHoppingForced = TRUE;

      /* since we ended up "somewhere" we assume all Links being defective. Prepare for ChunkHopping */
      Fee_ChunkInfo_unconfirmLink(context_pt->recentChunk_pt);
      Fee_ChunkInfo_Clone(&context_pt->mostRecentChunk_t, context_pt->recentChunk_pt);
    }

    Fee_Globals_t.FeeLocalJobResult_t = localJobResult;
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_ActFinalizeChunkSearch(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;

    /* mostRecentChunk is CONSISTENT => we must not touch predecessor's, i.e. 
       recentChunk's link validity info (because it might be "defective" anyway) */

    if(context_pt->prevChunk_pt != NULL_PTR)
    {
        Fee_ChunkInfo_Clone(context_pt->prevChunk_pt, context_pt->recentChunk_pt);
    }
    
    Fee_ChunkInfo_Clone(context_pt->recentChunk_pt, &context_pt->mostRecentChunk_t);
}

/**********************************************************************************************************************
 * Fee_ActCheckWriteSuspension
 *********************************************************************************************************************/
/*! \brief      This function checks whether FEE is "Write suspended", and depending on related flag:
 *              either waits (FEE is suspended), leaves "Wait SubFsm" exceuting specified "deferred acion" 
 *              
 *              See also Fee_InternalWriteSuspendHandling.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActCheckWriteSuspension(void)
{
    if(Fee_Globals_t.WritesSuspended_bl) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        FEE_NFY_WRITE_SUSPENDED(&Fee_Globals_t);
        Fee_ActWait();
    }
    else
    {
        Fee_ActReturnFromSubFsm();
        Fee_Globals_t.DeferredWriteAction_pt(&Fee_Globals_t);
    }
}

/**********************************************************************************************************************
 * Fee_ActWait
 *********************************************************************************************************************/
/*! \brief      This function sets the wait flag to indicate, that the MainFunction of the Fee can be left, because
 *              the Fee has temporarily nothing to due, e.g. it has to wait for the Fls driver and its JobResult of
 *              the previously requested job.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(void, FEE_PRIVATE_CODE) Fee_ActWait(void)
{
  Fee_Globals_t.InternalFlags_t |= (Fee_FlagType)FEE_FLAG_WAIT;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS STATE MACHINE - QUERIES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Fee_QryBlockCopyNotFinished
 *********************************************************************************************************************/
/*! \brief      This function checks, if the BlockCopy procedure of the sector switch for a specific block/dataset has been
 *              finished.
 *
 *  \return     TRUE                   The BlockCopy procedure has not finished. Continue to copy the remaining parts
 *                                     of the block/dataset or especially the instance.
 *  \return     FALSE                  The BlockCopy procedure has finished. The block/dataset or especially the
 *                                     instance has been copied successfully from the old sector to the CurrentSector.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryBlockCopyNotFinished(void)
{
    const Fee_InstanceCopyContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceCopyContext_t;
    
    return (boolean)(context_pt->ByteCount_t > 0);
}

/**********************************************************************************************************************
 * Fee_QryChunkNotFull
 *********************************************************************************************************************/
/*! \brief      This function checks, if the actual instance is empty or if an successor instance is available.
 *
 *  \return     TRUE                   The chunk is not full.
 *  \return     FALSE                  The chunk is full.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryChunkNotFull(void)
{
    const uint16 instanceCount = 
        Fee_ChunkInfo_GetInstanceCount(&Fee_Globals_t.SectorSwitchTarget_t.chunk_t);
  
    /* calculate the instance index to be used: If it current instance is empty, use it.                 *
     *  otherwise check it's successor (which would be empty, if it's in chunk's instance range)         */
    const uint16 freeInstanceIndex =
                        (uint16)(Fee_Globals_t.SectorSwitchTarget_t.index_u16 + 
                               ((FEE_INSTANCE_STATUS_EMPTY == Fee_Globals_t.SectorSwitchTarget_t.status_t) ? 0 : 1));
  
  return (boolean)(freeInstanceIndex < instanceCount);
}  

/**********************************************************************************************************************
 * Fee_QryChunkIsDataChunk
 *********************************************************************************************************************/
/*! \brief      This function checks, if the current chunk is a data chunk.
 *
 *  \return     TRUE                   The current chunk is a data chunk
 *  \return     FALSE                  The current chunk is a linktable chunk (for the links to chunks of datasets).
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryChunkIsDataChunk(void)
{
    return (boolean)Fee_ChunkInfo_isDataChunk(&Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.mostRecentChunk_t);
}

/**********************************************************************************************************************
 * Fee_QryInstHeaderErasedValue
 *********************************************************************************************************************/
/*! \brief      This function checks, if the first four bytes of the previously read bytes are equal to the ErasedValue
 *              specified by the Flash.
 *              It is only used for instance header / trailer checks. 
 *              Due to ESCAN00053464 we have to check a whole write page.
 *              Precondition: we may do the check 32bit-wise: Either a whole page (multiple of 4 bytes)has been read,
 *                            or, if page size < 4, first bytes have been initialized with erase value  
 *              
 *
 *  \return     TRUE                   First byte is equal to the ErasedValue.
 *  \return     FALSE                  First byte differs from ErasedValue.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryInstHeaderErasedValue(void)
{
    const Fee_InstanceSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t;
    const Fee_InstanceStatusType status = Fee_InternalEvalInstHdrStatus(
                                Fee_ChunkInfo_GetSector(&context_pt->instDescr_pt->chunk_t),
                                context_pt->Buffer_au32,
                                Fee_Globals_t.FlsJobResult_t);
    return (boolean)(FEE_INSTANCE_STATUS_EMPTY == status);
}

/**********************************************************************************************************************
 * Fee_QryFlsBusy
 *********************************************************************************************************************/
/*! \brief      This function checks, if the Fls driver is currently BUSY. If the Fls driver is IDLE, its JobResult is
 *              retrieved, if polling the Fls driver is configured.
 *
 *  \return     TRUE                   The Fls driver is currently BUSY.
 *  \return     FALSE                  The Fls driver is currently IDLE. Its JobResult is retrieved if the polling the
 *                                     Fls driver is configured. In the other case, notification mechanism is 
 *                                     configured, the JobResult is retrieved by the callback functions itself.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryFlsBusy(void)
{
    boolean retVal = TRUE;
    /* Check if Fls driver is still busy. */
    if (MEMIF_JOB_PENDING == Fee_Globals_t.FlsJobResult_t)
    {
        /* --> Fls had accepted the job and FEE is still waiting. */

#if (STD_ON == FEE_POLLING_MODE)
        /* --> Polling mode is switched on -> Fls status must be polled. */

        if (MEMIF_BUSY != Fee_FlsGetStatus())
        {
            /* Fls is idle -> get the job result of the Fls driver */
            Fee_Globals_t.FlsJobResult_t = Fee_FlsGetJobResult();
            retVal = FALSE;
        }
#endif
  }
  else
  {
        retVal = FALSE; /* Fls is idle; in Polling mode: we did not request a job, or FLS did not accept it */

  }

  return retVal;
}

/**********************************************************************************************************************
 * Fee_QryFlsJobResultOk
 *********************************************************************************************************************/
/*! \brief      This function checks, if the FlsJobResult is equal to Ok.
 *
 *  \return     TRUE                   The FlsJobResult is equal to Ok.
 *  \return     FALSE                  The FlsJobResult is different to Ok.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryFlsJobResultOk(void)
{
  return (boolean)(MEMIF_JOB_OK == Fee_Globals_t.FlsJobResult_t);
}

/**********************************************************************************************************************
 * Fee_QryGetWriteCycleJob
 *********************************************************************************************************************/
/*! \brief      This function checks, if the currently requested Fee job is equal to the GetWriteCycleJob.
 *
 *  \return     TRUE                   The requested Fee job is equal to the GetWriteCycleJob.
 *  \return     FALSE                  The requested Fee job is different to the GetWriteCycleJob.
 *********************************************************************************************************************/
#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryGetWriteCycleJob(void)
  {
    return (boolean)
      ((Fee_RequestFeeJobType)FEE_JOB_GET_WRITE_CYCLE == Fee_Globals_t.FeeJobParameter_t.RequestedFeeJob_t);
  }
#endif

/**********************************************************************************************************************
 * Fee_QryValidInstanceWritten
 *********************************************************************************************************************/
/*! \brief      This function checks, if a valid (i.e. consistent) Instance was found.
 *              Shall only be called after Instance Evaluation Sub-FSM was executed.
 *
 *  \return     TRUE                   Instance was written with valid status.
 *  \return     FALSE                  Instance was not written with valid status.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryValidInstanceWritten(void)
{
    return (boolean)((Fee_Globals_t.FeeLocalJobResult_t != FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS) &&
                     (Fee_Globals_t.FeeLocalJobResult_t != FEE_LOCAL_JOB_RESULT_FAILED));
}  

/**********************************************************************************************************************
 * Fee_QryBlockPayloadUpdated
 *********************************************************************************************************************/
/*! \brief      This function checks, if the payload has been updated for the current block.
 *
 *  \return     TRUE                   The block config of the current block has been updated.
 *  \return     FALSE                  The block config of the current block has (presumably) NOT been updated
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryBlockPayloadUpdated(void)
{
    const Fee_ChunkInfoConstRefType chunk_pt = Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.recentChunk_pt;
    const Fee_BlockConfigRefType cfg_pt = Fee_Globals_t.CurrentProcessData.BlockConfig_pt;
    boolean retVal = FALSE;

    /* If we are in FBL Sector Swtich, we don't know the block config -> Index is 0xFFFF),
       Additonally, we can only determine a config update, if we found a data chunk
     */
    if(Fee_ChunkInfo_isDataChunk(chunk_pt) && (cfg_pt != NULL_PTR))
    {
        retVal = (boolean)(Fee_ChunkInfo_getPayload(chunk_pt) != cfg_pt->BlockPayloadSize_u16);
    }

    return retVal;
}

/**********************************************************************************************************************
 * Fee_QryLocalJobResultEmptyChunks
 *********************************************************************************************************************/
/*! \brief      This function checks, if the LocalJobResult is equal to the EmptyChunks value.
 *
 *  \return     TRUE                   The LocalJobResult is equal to the EmptyChunks value.
 *  \return     FALSE                  The LocalJobResult is different from the EmptyChunks value.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultEmptyChunks(void)
{
  return (boolean)
    ((Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_EMPTY_CHUNKS == Fee_Globals_t.FeeLocalJobResult_t);
}

/**********************************************************************************************************************
 * Fee_QryLocalJobResultFailed
 *********************************************************************************************************************/
/*! \brief      This function checks, if the LocalJobResult is equal to the Failed value.
 *
 *  \return     TRUE                   The LocalJobResult is equal to the Failed value.
 *  \return     FALSE                  The LocalJobResult is different from the Failed value.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultFailed(void)
{
  return (boolean)
    ((Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_FAILED == Fee_Globals_t.FeeLocalJobResult_t);
}

/**********************************************************************************************************************
 * Fee_QryLocalJobResultInvalid
 *********************************************************************************************************************/
/*! \brief      This function checks, if the LocalJobResult is equal to the Invalid value.
 *
 *  \return     TRUE                   The LocalJobResult is equal to the Invalid value.
 *  \return     FALSE                  The LocalJobResult is different from the Invalid value.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultInvalid(void)
{
  return (boolean)((Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_INVALID == Fee_Globals_t.FeeLocalJobResult_t);
}

/**********************************************************************************************************************
 * Fee_QryLocalJobResultOk
 *********************************************************************************************************************/
/*! \brief      This function checks, if the LocalJobResult is equal to the Ok value.
 *
 *  \return     TRUE                   The LocalJobResult is equal to the Ok value.
 *  \return     FALSE                  The LocalJobResult is different from the Ok value.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryLocalJobResultOk(void)
{
  return (boolean)((Fee_LocalJobResultType)FEE_LOCAL_JOB_RESULT_OK == Fee_Globals_t.FeeLocalJobResult_t);
}

static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryMayFollowLinks(void) {
    return (boolean)(Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t.chunkHoppingForced == FALSE);
}

/**********************************************************************************************************************
 * Fee_QryPreviousInstanceAvailable
 *********************************************************************************************************************/
/*! \brief      This function checks, if a previous instance is available. This includes also, if a previous chunk
 *              is available in the chunk history. 
 *              A previous instance is available, if a previous chunk is available or the instance index does 
 *              not point the first instance within a chunk.
 *
 *  \return     TRUE                   A previous instance is available.
 *  \return     FALSE                  A previous instance is not available. This includes, that no previous chunk
 *                                     is available.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryPreviousInstanceAvailable(void)
{
    return (boolean)(Fee_Globals_t.FsmLocalVars_t.instanceSearchContext_t.instDescr_pt->index_u16 > 0u);
}

static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryRecentChunkLinkConsistent(void)
{
    const Fee_ChunkSearchContextRefType context_pt = &Fee_Globals_t.FsmLocalVars_t.chunkSearchContext_t;
    return (boolean)(Fee_ChunkInfo_isLinkConsistent(&context_pt->mostRecentChunk_t));
}

/**********************************************************************************************************************
 * Fee_QrySearchingInCurrentSector
 *********************************************************************************************************************/
/*! \brief      This function checks, if the Fee is searching in the CurrentSector. This can be determined if the
 *              the OperatingSector is different from the CurrentSector.
 *
 *  \return     TRUE                   The Fee searches in the CurrentSector.
 *  \return     FALSE                  The Fee searches in the old sector (= not CurrentSector).
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QrySearchingInCurrentSector(void)
{
    const Fee_SectorConfigRefType secto_ptloc = Fee_ChunkInfo_GetSector(&Fee_Globals_t.CurrentDataset_t.chunk_t);

    return (boolean)(Fee_Partition_isNewestSector(Fee_Globals_t.CurrentProcessData.Partition_pt, secto_ptloc));
}

/**********************************************************************************************************************
 * Fee_QryTrue
 *********************************************************************************************************************/
/*! \brief      This function is just a dummy function needed by the state machine to pad unused query locations.
 *
 *  \return     TRUE                   Always.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_QryTrue(void)
{
  return (TRUE);
}

/******** Size/Address calculation helper functions ************************/

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalFillInstanceBuffer(
    const Fee_IntBuffer_u8PtrType instBuf, const Fee_UserDataConstPtrType userBuf, const uint16 length)
{
    uint16_least loopCount = length;
    /* Fill up the internal buffer with the first part of the payload data. */

    while(loopCount > 0)
    {
        loopCount--;
        instBuf[loopCount] = userBuf[loopCount];
    }
}

static FUNC(Fee_InstanceStatusType, FEE_PRIVATE_CODE) Fee_InternalEvalInstHdrStatus(Fee_SectorConfigRefType sector_pt,
                                                Fee_IntBuffer_u32ConstPtrType intBuf_au32, MemIf_JobResultType flsResult)
{
    /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    Fee_InstanceStatusType retVal = Fee_InternalEvaluateInstanceStatus(sector_pt, 
                                                                       (Fee_IntBuffer_u8ConstPtrType)intBuf_au32,
                                                                       flsResult);
    if(retVal == FEE_INSTANCE_STATUS_EMPTY)
    { /* header byte is empty; chek remaining flash page */
        sint32 index = (sint32)((Fee_Sector_alignWrite(sector_pt, FEE_INSTANCE_HEADER_SIZE) - 1u) >> 2);
        
        do
        {
            if(!Fee_Sector_isErasedU32(sector_pt, intBuf_au32[index]))
            {
                retVal = FEE_INSTANCE_STATUS_FAILED;
                break;
            }
            index--;
        }
        while(index >= 0);
    }
    return retVal;
}

static FUNC(Fee_InstanceStatusType, FEE_PRIVATE_CODE) Fee_InternalEvaluateInstanceStatus(
                                                Fee_SectorConfigRefType sector_pt,
                                                Fee_IntBuffer_u8ConstPtrType intBuf_au8, MemIf_JobResultType flsResult)
{
    Fee_InstanceStatusType retVal = FEE_INSTANCE_STATUS_FAILED;

    if(MEMIF_JOB_FAILED != flsResult)
    {
        if(Fee_Sector_isErasedU8(sector_pt, intBuf_au8[0]))
        {
            retVal = FEE_INSTANCE_STATUS_EMPTY;
        }
        else
        {
            switch(intBuf_au8[0])
            {
                case FEE_INSTANCE_STATUS_INVALID:
                    retVal = FEE_INSTANCE_STATUS_INVALID;
                    break;
                case FEE_INSTANCE_STATUS_OK:
                    retVal = FEE_INSTANCE_STATUS_OK;
                    break;
                case FEE_INSTANCE_STATUS_INCONSISTENT: /* explicitly marked as INCONSISTENT */
                    retVal = FEE_INSTANCE_STATUS_INCONSISTENT;
                    break;
                default:
                    break; /* any other value means FAILED */
            }
        }
    }

    return retVal;
}

static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalScheduleProcess(Fee_GlobalsPtrType globals)
{
    boolean processStarted;

    /* We expect blockConfig_pt to be always valid (actually points into our block Config) */
    const sint8 ssPartIndex = globals->SectorSwitchData_t.partitionId_s8;
    const Fee_RequestFeeJobType reqJob = globals->FeeJobParameter_t.RequestedFeeJob_t;
    /* If FSS threshold was exceeded we need to check whether FSS is allowed, otherwise we check for BSS.  *
     * If no sector switch is necessary at all, we also check for BSS                                      */

    if((globals->FeeJobParameter_t.RequestedFeeJob_t != FEE_JOB_NONE)
#if(FEE_FORCE_SECTOR_SWITCH_API == STD_ON) /* ECO_IGNORE_BLOCK_BEGIN */
            &&        ((globals->InternalFlags_t & FEE_FLAG_FORCE_SECTOR_SWITCH) == 0)
#endif /* ECO_IGNORE_BLOCK_END */
      )
    {
        const sint8 jobPartIndex = globals->FeeJobParameter_t.PartitionIndex_s8;
        const Fee_PartitionConfigRefType jobPartition_pt = &globals->Config_pt->PartitionConfig_at[jobPartIndex];

        /* remaining field shall be initialized in Fee_InternalInitBusyFsm -> when decission about job type has been made */
        processStarted = Fee_InternalInitPartitionInitializationFsm(globals, jobPartition_pt);
        if(!processStarted)
        {
            /* Don't Start job processing, if:                                                                      *
             *   - it is a write-like job, but the job was marked deferred (within previous processing attempt)     *
             * Otherwise: directly start the job                                                                    *
             * That mean's that every read-like and every NEW (1st try) write-like job has higher precedence than   *
             * any sector switch                                                                                    */
            /* PRQA S 3415 3 */ /* MISRA Rule 12.4: Conditional evaluation of &&'s right-hand side is exactly what was intended. */
            if((reqJob <= FEE_JOB_WRITE) &&
              ((globals->InternalFlags_t & FEE_FLAG_JOB_DEFERRED) != 0) &&
                (Fee_InternalInitSectorSwitchFsm(globals, jobPartition_pt)))
            {
                processStarted = TRUE;
            }
            else  
            { 
                processStarted = Fee_InternalInitBusyFsm(globals, jobPartition_pt);
            }
        }
    }
    /* No user job; check whether a partition needs "internal operation", but only if BSS is allowed */
    else if((ssPartIndex >= 0) && ((globals->ApiFlags_t & FEE_API_FLAG_ENABLE_BSS) != 0))
    {
        const Fee_PartitionConfigRefType ssPart_pt = &globals->Config_pt->PartitionConfig_at[ssPartIndex];
        processStarted = TRUE; /* We have something to do. At least: check next partition */

        /* Check whether a partition _might_ need sector switch (first condition) and whether             *
         * performing it in Background mode is allwoed                                                    *
         * This means: Even a FSS can only be processed in background (while no job is pending),          *
         * if BSS is enabled (or Force Sector Switch was requested),                                      *
         *  and if FSS is allowed (to be checked elsewhere) , of course                                   */

#if((FEE_FORCE_SECTOR_SWITCH_API == STD_ON) || (FEE_DATA_CONVERSION_API == STD_ON)) /* ECO_IGNORE_BLOCK_BEGIN */
        /* PRQA S 3415 2 */ /* MISRA Rule 12.4: Conditional evaluation of &&'s right-hand side is exactly what was intended. */
        if(((globals->InternalFlags_t & FEE_FLAG_FORCE_SECTOR_SWITCH) != 0) &&
            (Fee_InternalInitPartitionInitializationFsm(globals, ssPart_pt)))

        { /* Partion needs to be intitialized in order to perform the requested sector switch.
             But herein, nothing is to do */
        }
        else
#endif /* ECO_IGNORE_BLOCK_END */
        {
            /* PRQA S 3415 2 */ /* MISRA Rule 12.4: Conditional evaluation of &&'s right-hand side is exactly what was intended. */
            if((Fee_Partition_getNewestSector(ssPart_pt) == NULL_PTR) ||
                (Fee_InternalInitSectorSwitchFsm(globals, ssPart_pt) == FALSE))
            {
                /* If no sector switch was necessary (or allowed) on current partition, decrement.
                    *  If index becomes smaller than 0, sector switch was finished for all partitions;
                    *  Next cycle will caus to enter final else path */
                globals->SectorSwitchData_t.partitionId_s8--;
            }
        }
        /* process started must remain TRUE, because FEE is currently NOT known to be IDLE!!! */
    } 
    else /* we checked all partitions -> no sector switch was started */
    {
#if(FEE_FORCE_SECTOR_SWITCH_API == STD_ON)
        /* unconditionally, clear "force sector switch" processing flag */
        globals->InternalFlags_t &= (FEE_FLAG_FORCE_SECTOR_SWITCH ^ 0xFFu);
#endif
        /* indicate "nothing started / nothing to do" to the caller => FEE is actually IDLE */
        processStarted = FALSE;
    }

    return processStarted;
}

/**********************************************************************************************************************
 * Fee_InternalInitPartitionInitializationFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the "Start-Up" FSM, which initializes a partition
 *              (check sector headers in order to determine "new" and "old" sector.
 *
 *  \return     True, if job processing was actually started
 *********************************************************************************************************************/
 static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalInitPartitionInitializationFsm(Fee_GlobalsPtrType globals,
                                                                                  Fee_PartitionConfigRefType part)
 {
     boolean needInit = (boolean)(Fee_Partition_getNewestSector(part) == NULL_PTR);

     if(needInit) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
     {
            /* Force sector switch might be called while a partition is not initialized.  *
             * A "normal" sector switch cannot occur under such conditions                */

            const Fee_PartitionInitContextRefType context_pt = &globals->FsmLocalVars_t.PartitionInitContext_t;
            const Fee_SectorConfigRefType sector1 = Fee_Partition_getSectorByPos(part, FEE_LOWER_SECTOR_NUMBER);

            globals->CurrentProcessData.Partition_pt = part;

            globals->FsmStack_t.Stack_at[0] = FEE_STATE_MAIN_STARTUP;
            Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_STARTUP_READ_SECTOR_HEADER_LOWER); 

            /* PRQA S 0310 1 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
            Fee_InternalEvalFlsRetVal(Fee_Sector_readHeader(sector1, context_pt->sectorHeaderData));
     }

     return needInit;
 }
 
/**********************************************************************************************************************
 * Fee_InternalInitBusyFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the Busy FSM.
 *
 *  \return     True, if job processing was actually started
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalInitBusyFsm(Fee_GlobalsPtrType globals, 
                                                               Fee_PartitionConfigRefType jobPartition_pt)
{
    boolean processingStarted = TRUE;

#ifdef FEE_TESTING_LOG_TRANSITIONS
    TsxFee_LogExecutedQueries queries;
    queries.count = 0;
    TsxFee_LogStateTransition(globals->FsmStack_t.Stack_at[0u], 1, FEE_STATE_MAIN_BUSY, &queries);
#endif
    globals->FsmStack_t.Stack_at[0u] = FEE_STATE_MAIN_BUSY;

    /* job is started, but not deferred (maybe it WAS deferred...) */
    globals->InternalFlags_t &= FEE_FLAG_JOB_DEFERRED_MASK;

    /* initial job result -> will be overwritten, if a job is actually ececuted;
     * remains, if FEE is in  REJECT_ALL mode or in READ_ONLY mode and a write job was requested */
    globals->FeeLocalJobResult_t = FEE_LOCAL_JOB_RESULT_FAILED;

    globals->CurrentProcessData.Partition_pt = jobPartition_pt;

    if(Fee_Partition_isReadable(jobPartition_pt))
    {
        const Fee_SectorConfigRefType newSector = Fee_Partition_getNewestSector(jobPartition_pt);
        
        /* for any job processing, we use CurrentDataSet -> initialize it */
        Fee_ChunkInfo_Construct(&Fee_Globals_t.CurrentDataset_t.chunk_t, newSector);

        Fee_ChunkInfo_Clear(&globals->PreviousChunk_t);

        /* clear BrokenLink flag, because only the block with the broken link should be written in the new sector */
        globals->InternalFlags_t &= (Fee_FlagType)FEE_FLAG_BROKEN_LINK_MASK;

    #if (STD_ON == FEE_GET_ERASE_CYCLE_API)  /* ECO_IGNORE_BLOCK_BEGIN : define needs no test, because it contains an else condition. */
        /* in case of Fee_GetEraseCycle processing, we may not use the "normal" job initialization,
         *  since Fee_Globals_t.FeeJobParameter_t.BlockNumber_u16 is not a block Number!!! */
        if(globals->FeeJobParameter_t.RequestedFeeJob_t == FEE_JOB_GET_ERASE_CYCLE)
        {            
            Fee_ActFinalizeEraseCycleJob();
        }
        else
    #endif /* ECO_IGNORE_BLOCK_END */
        {
            /* We are aboput to start a block specific job ==> BlockConfig MUST be valid */
            const Fee_BlockConfigRefType jobBlockCfg_pt = globals->FeeJobParameter_t.blockConfig_pt;

            const Fee_ChunkSearchContextRefType context_pt = &globals->FsmLocalVars_t.chunkSearchContext_t;

            /* init block specific parameters */
            globals->CurrentProcessData.BlockId.Tag = jobBlockCfg_pt->LinktableIndex_u16;
            globals->CurrentProcessData.BlockId.DataIndex = globals->FeeJobParameter_t.DataIndex_u8;
            globals->CurrentProcessData.BlockConfig_pt = jobBlockCfg_pt;
            
            Fee_ChunkSearchContext_Init(context_pt,
                                        &globals->CurrentProcessData.BlockId, 
                                        &globals->PreviousChunk_t,
                                        &globals->CurrentDataset_t.chunk_t, 
                                        Fee_Sector_getEndOffset(newSector));

            switch(globals->FeeJobParameter_t.RequestedFeeJob_t)
            {
                /* write class jobs */
                case FEE_JOB_WRITE:
                case FEE_JOB_ERASE_IMMEDIATE_BLOCK:
                case FEE_JOB_INVALIDATE_BLOCK:
                    /* Check whether a write class job shall be rejected */
                    if(Fee_Partition_isWriteable(jobPartition_pt))
                    { /* job allowed */
                        Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_BUSY_SEARCH_WRITTEN);
                        Fee_ActInitSearchWrittenFsm();
                    }
                    break;
#if(FEE_GET_WRITE_CYCLE_API == STD_ON) /* ECO_DISABLE_GENERATION */
                case FEE_JOB_GET_WRITE_CYCLE:
                    /* very similar to WriteClass jobs, but it can be executed in "read only" mode.
                     * And it does not enable Foregound Sector Switch */                    
                    Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_BUSY_SEARCH_WRITTEN);
                    Fee_ActInitSearchWrittenFsm();
                    break;
#endif
                case FEE_JOB_READ:
                    Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_BUSY_SEARCH_CONSISTENT);
                    Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_SEARCH_CONSISTENT_CHUNK_SEARCH);
                    Fee_ActInitChunkSearchFsm();
                    break;

                default:
                    processingStarted = FALSE;
                    break;
            }
        }
    } /* if (!rejectAllJobs) */

    return processingStarted;
}

/**********************************************************************************************************************
 * Fee_InternalInitSectorSwitchFsm
 *********************************************************************************************************************/
/*! \brief      This function is responsible for initializing the SectorSwitch FSM.
 *              Because the Sector Switch processing is a state machine on its own,
 *              this function does not only initialze it, but it also resumes processing.
 *   
 *
 *  \return     TRUE, if Sector Switch FSM was actually started.
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalInitSectorSwitchFsm(Fee_GlobalsPtrType globals, Fee_PartitionConfigRefType partition)
{
    const enum Fee_Partition_FillLevelEnum fillLevel = Fee_Partition_getFillLevel(partition);
    const Fee_FlagType fssAllowed = globals->ApiFlags_t & FEE_API_FLAG_ENABLE_FSS;
    boolean processStarted;

#       ifdef FEE_TESTING_LOG_TRANSITIONS
        TsxFee_LogExecutedQueries queries;
        queries.count = 0;
        TsxFee_LogStateTransition(globals->FsmStack_t.Stack_at[0u], 0, FEE_STATE_MAIN_SECTOR_SWITCH, &queries);
#       endif
    globals->FsmStack_t.Stack_at[0u] = FEE_STATE_MAIN_SECTOR_SWITCH;

    /* init used Partition to sector switch's current one */
    globals->CurrentProcessData.Partition_pt = partition;

    /* If FSS is necessary but not allowed, don't start processing */
    if((Fee_Partition_isWriteable(partition)) &&
        ((fillLevel < FEE_PART_FILL_LEVEL_FSS) || (fssAllowed != 0)))
    {
    	const Fee_SectorConfigRefType olderSector = Fee_Partition_getOldestSector(partition);
        const Fee_FlagType forcedSwitch = 
                            (globals->InternalFlags_t & (FEE_FLAG_JOB_DEFERRED | FEE_FLAG_FORCE_SECTOR_SWITCH));

	    const boolean newerSectorWriteable  = (boolean)Fee_Sector_isWriteable(Fee_Partition_getNewestSector(partition));
        const boolean newerSectorEmpty = (boolean)Fee_Sector_isEmpty(Fee_Partition_getNewestSector(partition));

        /* Sector Erase, if the older sector is marked to be erased, and it would not defer a pending job.                       *
		 * If newer sectore is not writeable (e.g. full) we'd even defer a job. We also defer a job if sector switch was forced. */
        if((!Fee_Sector_isUsable(olderSector)) && ((!newerSectorWriteable) || (forcedSwitch != FEE_FLAG_JOB_DEFERRED)))
        {
            processStarted = TRUE;

            /* only the old sector needs to be erased */
            Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_SECTOR_SWITCH_SETUP_SECTORS);
            Fee_ActInitSetupSectorsFsm();
        }
        /* check whether Block Copy is necessary (erase is not necessary):
           - Any threshold exceeded (actual BSS handling is done outside)
           - A job was deferred (actually it forces a sector switch). 
           - Force SectorSwitch                                                */
        else if((fillLevel >= FEE_PART_FILL_LEVEL_BSS) ||
                ((forcedSwitch != 0) &&
                (fillLevel != FEE_PART_FILL_LEVEL_SINGLE_SECTOR) && (!newerSectorEmpty)))
        {
            processStarted = TRUE;

            /* only the old sector needs to be erased */
            Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_SECTOR_SWITCH_GET_BLOCK);
            Fee_InternalGetNextBlockToCopy(globals);
        }
        else
        { /* job can be processed - either newer sector has enough space, or (in case of critical data)        *
           *  one single sector is in use (either newer is not full and lower may be erased, or newer is empty */
            processStarted = FALSE;
        }
    }
    else
    { /* if FSS is necessary, but not allowed, we don't start any processing */
            processStarted = FALSE;
    }

    return processStarted;
}

/**********************************************************************************************************************
 * Fee_InternalIsCancelableOperation
 *********************************************************************************************************************/
/*! \brief      Checks whether current operation (Sector Switch) may be cancelled.
 *              Only start-Up (read sector headers) may never be cancelled.
 *              Even a FSS be cancelled: cancellation is excpected to occur infrequently; infrequent cancellation does
 *              not impose severe damage in flash image.
 *
 *  \return     None
 *********************************************************************************************************************/
static FUNC(boolean, FEE_PRIVATE_CODE) Fee_InternalIsCancelableOperation(Fee_GlobalsConstPtrType globals)
{
    const Fee_PartitionConfigRefType partition_pt = globals->CurrentProcessData.Partition_pt;

    /* Initialize with "unknown" - if currently processed partition is NULL, we may cancel anything ... */ 
    enum Fee_Partition_FillLevelEnum fillLevel = FEE_PART_FILL_LEVEL_UNKNOWN;
    
    if(partition_pt != NULL_PTR)
    {
        fillLevel = Fee_Partition_getFillLevel(partition_pt);
    }
    
    return (boolean)(
        (Fee_Globals_t.FsmStack_t.Stack_at[0] != FEE_STATE_MAIN_STARTUP) &&
                                 (fillLevel <= FEE_PART_FILL_LEVEL_FSS));
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalWriteSuspendHandling(
                                                 const Fee_GlobalsPtrType globals,
                                                 const Fee_DeferredFuncType deferredRequest)
{
    if(globals->WritesSuspended_bl) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        Fee_InternalActInitFsm(&globals->FsmStack_t, FEE_STATE_WAIT_FOR_WRITE_RESUME);
        globals->DeferredWriteAction_pt = deferredRequest;

        FEE_NFY_WRITE_SUSPENDED(&Fee_Globals_t);
        Fee_ActWait();
    }
    else
    {
        deferredRequest(globals);
    }
}

static FUNC(void , FEE_PRIVATE_CODE) Fee_ChunkSearchContext_Init(Fee_ChunkSearchContextRefType self,
                                                                 Fee_BlockIdConstRefType blockId_pt,
                                                                 Fee_ChunkInfoRefType prevChunk_pt,
                                                                 Fee_ChunkInfoRefType recentChunk_pt,
                                                                 Fee_AddressType upperLimit_t)
{
    self->super_t.searchBlockId_t = *blockId_pt;
    
    /* normally we're searching for a particular block */    
    self->super_t.blockIdMask_t.Tag = 0xFFFFu;
    self->super_t.blockIdMask_t.DataIndex = 0xFFu;
    
    /* normally we're not interested in result block id, since we know what we are searching for */
    self->super_t.resultBlockId_pt = NULL_PTR;

    self->super_t.upperSearchLimit_t = upperLimit_t;

    self->recentChunk_pt = recentChunk_pt;
    self->prevChunk_pt = prevChunk_pt;

    Fee_ChunkInfo_Clone(&self->mostRecentChunk_t, recentChunk_pt);
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalRequestSectorSwitch(Fee_GlobalsPtrType globals, Fee_PartitionConfigRefType partition)
{
    const sint8 pId = (sint8)Fee_Partition_getId(partition);

    /* only, if passed partition is not currently being processed by Sector Switch, we have to re-init variables */
    if(pId != globals->SectorSwitchData_t.partitionId_s8)
    { /* re-initialize complete sector switch processing */
        
        /* only if pId is larger than currently processed partion (sector switch), *
         * we make this pId the one to be processed next.                          *
         * Doing so prevents from skipping partitions (handling in background),    *
         * because partitions are scanned backwards, until 0 was reached.          *
         * After that complete SectorSwitch is finished.                           */
        if(pId > globals->SectorSwitchData_t.partitionId_s8)
        {
            globals->SectorSwitchData_t.partitionId_s8 = pId;
        }

        Fee_InternalResetSectorSwitch(&globals->SectorSwitchData_t, FEE_IS_IN_FBL_MODE(globals));
    }
}

static FUNC(void , FEE_PRIVATE_CODE) Fee_InternalResetSectorSwitch(Fee_SectorSwitchDataRefType self, boolean isFblMode)
{
    if(isFblMode) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        Fee_ChunkInfo_Clear(&self->mode.fbl);
    }
    else
    {
        self->mode.appl.DataIndex_s16 = -1;
        self->mode.appl.BlockConfigIndex_u16 = 0xFFFF;
    }
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_InternalClearApiFlags(const Fee_GlobalsPtrType globals, Fee_FlagType flags)
{
    flags ^= 0xFFu; /* invert flags to get the and mask */
    /* Commit clearing API Flags */
    Fee_GlobalSuspend();
        globals->ApiFlags_t &= flags;
    Fee_GlobalRestore();
}

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* module specific MISRA deviations: 
   MD_FEE_5.1_identifiers:
     Reason: Identifiers' name length have been exceeded due to their naming scheme
     Risk: Compiler might issue warnings or errors. Currently no such compiler is known.
     Prevention: n/a

   MD_FEE_10.1_ternary:
     Reason: Rule is NOT violated; QAC message apparently results from evulating condition's type.
             According to standard the type of a ternary expression does not depend on condition's type.
     Risk: no risk
     Prevention: n/a

   MD_FEE_12.4_queries: 
     Reason: Functions at right hand of || or && are defined to have no side-effects.
             It intended and thus ok to omit unnecessary calls. 
     Risk: A function HAS side effects, leading to unexpected behaviour, if call is omitted.
     Prevention: Review; make ensure, that these functions do not change any global value,
                 and that they do not access "volatile" values.

   MD_FEE_13.2_boolean: 
     Reason: type (boolean) represents a Boolean value, as defined by AUTOSAR
     Risk: Type is misused, leading to unexpected behaviour.
     Prevention: Review; boolean values shall only be set by (effectively) boolean expressions. 
*/ 

/**********************************************************************************************************************
 *  END OF FILE: Fee.c
 *********************************************************************************************************************/
 
