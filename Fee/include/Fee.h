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
 *         File:  Fee.h
 *    Component:  If_AsrIfFee
 *       Module:  Fee
 *    Generator:  -
 *
 *  Description:  The module Fee provides an abstraction from the device specific addressing scheme and 
 *                segmentation. It also offers a virtual addressing scheme and segmentation as well as 
 *                a virtually unlimited number of erase cycles to the upper layer.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *               A U T H O R   I D E N T I T Y
 *--------------------------------------------------------------------------------------------------------------------
 * Initials     Name                      Company
 * --------     ---------------------     ----------------------------------------------------------------------------
 * Ck           Christian Kaiser          Vector Informatik GmbH
 * Du           Manfred Duschinger        Vector Informatik GmbH
 *--------------------------------------------------------------------------------------------------------------------
 *              R E V I S I O N   H I S T O R Y
 *--------------------------------------------------------------------------------------------------------------------
 *  Version     Date        Author      Change Id      Description
 * -------------------------------------------------------------------------------------------------------------------
 *                                                       
 * 8.00.00      2012-06-22  Ck                          Removed prvious revision history entries
 *                                      ESCAN00059643   cahnged signature of Fee_Init to be ASR compliant;
 *                                                      added Fee_InitEx.
 *                                      ESCAN00059332   Fee_ForceSectorSwitch is performed only once
 *                                      ESCAN00057779   AR3-2408 - Split Data Flash into Partitions
 * 8.00.01      2012-08-27  Ck          ESCAN00059980   Corrected Fee_Partition_Init (RejectAllMode flag)
 *                                      ESCAN00059751   Removed redundant function declarations from Fee_Partition.h
 *                                      ESCAN00060047   Corrected BlockNumber reset after sector switch.
 *                                      ESCAN00060015   Corrected Instance Header Evaluation (if alingment < 4)
 *                                      ESCAN00060003   Modified WriteProcessing FSM; reinit ChunkAllocContext in
 *                                                      Fee_ActAllocationInCurrentSetor()
 *                                      ESCAN00060054   Write Cycle Counter Handling
 *                                      ESCAN00060084   No implicit pointer type definitions - typedefs used instead
 *                                      ESCAN00060087   Corrected updating a sector's next free address.
 *                                      ESCAN00060887   Sector Switch in FBL mode: Corrected intitialization of Chunk
 *                                                      Hopping; corrected initialization of chunk allocation,
 *                                                      Handling of Link-Table chunks during chunk hopping (Fee_ChunkInfo)
 *                                      ESCAN00060893   Corrected internal function declaration
 *                                      ESCAN00061061   Variable declarations in Fee_ChunkInfo.c (typos)
 *                                      ESCAN00060999   Variable initialization and in Fee_InternalScheduleProcess
 *                                                      Context Initialization in Fee_ActInitInstanceWriteDcFsm
 *                                      ESCAN00061094   Avoid Compiler Warnings
 * 8.00.02      2012-09-14  Ck          ESCAN00061421   MISRA compliance / QAC findings
 *                                      ESCAN00061327   Corrected Fee_ActFinalizeDataConversion,
 *                                                                Fee_InternalInitDataConversionFsm
 * 8.00.03      2012-12-19  Ck          ESCAN00063033   corrected Assembly of ChunkHeader-/Link (ChunkType info)
 *                                                      in Fee_ChunkInfo.c
 *                                      ESCAN00063064   Made sector space check (chunk allocation) robuster.
 *                                                      Changed ChunkHopping limit check (=> check End address)
 *                                      ESCAN00063833   Refactured Chunk-Hopping Initialization.
 *                                      ESCAN00063881   Initialization of local variable in Fee_InternalScheduleProcess
 *                                      ESCAN00064116   Corrected Fee_ChunkInfo_InitFromLinkData(),
 *                                                      Fee_ChunkInfo_EvaluateHeaderData, Fee_ChunkInfo_CreateFromRawData;
 *                                      ESCAN00063791   Fee_InternalIsCancelableOperation changed (avoid "NULL Sector"): 
 *                                                      It allows canceling almost every thing
 *                                      ESCAN00064507   Avoid compiler warning (Fee_ActFinalizeChunkAllocation)
 *                                                  -   Insignificant modifications to increase MISRA compliance
 * 8.00.04     2013-01-05    Ck         ESCAN00064769   Updated Fee_Sector_allocSpace - handle allocation attempts for 
 *                                                      <sector size> (and more).
 *                                                      Mark old sector as "full" when block copy starts.
 *                                                      (by attempting to allocate whole sector at once).
 *                                                      Fixed condition to perform a sector switch
 *                                                      (old sector "unusable", new sector full or no job pending
 *                                                      or sector switch forced)
 * 8.00.05     2013-03-21    Ck         ESCAN00066078   Fixed Fee_ActSwitchOperatingSector to correctly re-initialize
 *                                                      Search in old sector -> use Fee_ChunkSearchContext_Init().
 * 8.00.06     2013-06-24    Ck         ESCAN00065913   Made sure Fee_ChunkInfo.c ends with "newline".
 *                                      ESCAN00066070   Added "base vs. link offset" check to Fee_ChunkInfo_InitFromLinkData
 *                                      ESCAN00066124   Failed chunk-link write (Fee_ActFinalizeChunkAllocation) results
 *                                                      in FEE_LOCAL_JOB_RESULT_FAILED
 *                                      ESCAN00066316   Removed excluded code (#if 0 ... #endif) from Fee_Partition.c
 *                                      ESCAN00066318   Removed Fee_QryLocalJobResultInconsistent (unused)
 *                                      ESCAN00066317   Removed code depending on obsolete definitions of Fee_FlsReadSync/Fee_FlsCopy
 *                                      ESCAN00067914   Surround declaration of Fee_ChunkInfo_NullChunk with memory section. 
 *                                      ESCAN00067913   Added ECO-Labels (comments) to aid coverage analysis using ECO
 * 8.00.07     2013-10-07    Ck         ESCAN00070922   Added conditional definitions of Fee_GlobalSuspendLong/Fee_GlobalRestoreLong
 *                                                      to Fee.c
 *                                      ESCAN00071245   MISRA Justifiction (Rule 19.7, Fee_ChunkInfo.c)
 *                                      ESCAN00071273   AUTOSAR4 compliant version identification (but AUTOSAR3 macros remain.)
 * 8.00.08     2014-02-04    Ck         ESCAN00070359   Improved robustness of SectorId updates -
 *                                                      1. Fee_Partition_getNextSectorId,
 *                                                      2. Fee_Partition_updateSectorId
 *                                      ESCAN00072977   Partitions remain unitialized if no requests on them occur.
 *                                                      Fee_InternalScheduleProcess, Fee_InternalInitBusyFsm,
 *                                                      Fee_InternalInitPartitionInitializationFsm
 *                                      ESCAN00073366   Fee_Globals_t got external linkage (Debugging purposes).
 *                                      ESCAN00071246   Code Metrics - did refactoring on Fee_MainFunction,
 *                                                      Fee_InternalGetNextBlockToCopy, Fee_ActPrepareChunkLinkWrite,
 *                                                      Fee_Partition_getFillLevel
 * 8.00.09     2015-01-08    Ck         ESCAN00078523   fixed declaration of Fee_GetBlockCfgByBlockId 
 *                                      ESCAN00076637   Fee_Globals_t's declaration surrounded by MemMap stuff
 *                                      ESCAN00078905   ChunkHeaderChecks; when and hwo to initialize ChunkHopping
 *                                                      ChunkHopping is fallback - don't switch back to link-based search.
 *                                                      chunkHoppingForced, chunkLinkPresent in Fee_ChunkSearchContextStruct
 *                                                      as well as related handling, in order to allow switching back from
 *                                                      chunk hopping to link-based search (performance), and to distinguish
 *                                                      non-existent from defective chunk links (=> within link-tables)
 *                                      ESCAN00078909   Fee_ActValidateChunkLink - condition to accept Link-Table Chunks.
 *                                      ESCAN00080317   Explicit re-initialization of SectorSwitch progress variables
 *                                                      (Fee_SectorSwitchData) after SectorOverflow.
 *                                                      Factored out that re-init into function Fee_InternalResetSectorSwitch
 *                                                      Added FEE_STATE_SECTOR_SWITCH_IDLE
 *                                                      Fee_FinalizeBlockCopy conditionally advances SectorSwitch progress
 *                                                      Dedicated result codes for chunk allocation, allowing to distinguish
 *                                                      different failure conditions.
 *                                      ESCAN00081069   FEE_STATE_SECTOR_SWITCH_ALLOCATE_LINKTABLE_CHUNK -> detect/report
 *                                                      SectorOverflows
 *                                      ESCAN00081179   Fee_ActFinalizeChunkSearch to retrieve result (chunk info) added 
 *                                                      to FEE_STATE_SEARCH_UPWARDS_CHUNK_HOPPING 
 * 8.00.10     2015-02-28    Ck         ESCAN00081213   Fee_ChunkInfo_EvaluateHeaderData first makes a copy if "self" chunk,
 *                                                      to be able to restore it.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MULTIPLE INCLUSION PROTECTION
 *********************************************************************************************************************/
#if !defined (FEE_H)
# define FEE_H

/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : If_AsrIfFee CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define IF_ASRIFFEE_VERSION                                          0x0800u
# define IF_ASRIFFEE_RELEASE_VERSION                                  0x10u

/* FEE is still compatible with AUTOSAR 3 and AUTOSAR4!
 * This implementation shall remain usable in AUTOSAR3 environments.
 * Therefore define macros according to both major releases in parallel. */
/* ASR3.1.5 - the version of AUTOSAR_SWS_Flash_EEPROM_Emulation */
# define FEE_AR_MAJOR_VERSION                                         (1u)
# define FEE_AR_MINOR_VERSION                                         (2u)
# define FEE_AR_PATCH_VERSION                                         (1u)

/* AUTOSAR4 - the overall AUTOSAR release */
# define FEE_AR_RELEASE_MAJOR_VERSION                                 (4u)
# define FEE_AR_RELEASE_MINOR_VERSION                                 (0u)
# define FEE_AR_RELEASE_REVISION_VERSION                              (3u)

# define FEE_VENDOR_ID                                                (30u)
# define FEE_MODULE_ID                                                (21u)
# define FEE_INSTANCE_ID                                              (0u)

# define FEE_SW_MAJOR_VERSION                                         (IF_ASRIFFEE_VERSION >> 8u)
# define FEE_SW_MINOR_VERSION                                         (IF_ASRIFFEE_VERSION & 0x00FFu)
# define FEE_SW_PATCH_VERSION                                         IF_ASRIFFEE_RELEASE_VERSION

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Fee_Types.h"
#include "Fee_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define FEE_START_SEC_CODE
# include "MemMap.h"

FUNC(void, FEE_API_CODE) Fee_Init(void);

FUNC(void, FEE_API_CODE) Fee_InitEx(Fee_ConfigRefType ConfigPtr);

FUNC(void, FEE_API_CODE) Fee_SetMode(MemIf_ModeType Mode);

FUNC(Std_ReturnType, FEE_API_CODE) Fee_Read
  (
    uint16 BlockNumber,
    uint16 BlockOffset,
    Fee_UserDataPtrType DataBufferPtr,
    uint16 Length
  );

FUNC(Std_ReturnType, FEE_API_CODE) Fee_Write(uint16 BlockNumber, Fee_UserDataPtrType DataBufferPtr);

FUNC(void, FEE_API_CODE) Fee_Cancel(void);

# if (STD_ON == FEE_FORCE_SECTOR_SWITCH_API)
  FUNC(Std_ReturnType, FEE_API_CODE) Fee_ForceSectorSwitch(void);
# endif

FUNC(MemIf_StatusType, FEE_API_CODE) Fee_GetStatus(void);

FUNC(MemIf_JobResultType, FEE_API_CODE) Fee_GetJobResult(void);

FUNC(Std_ReturnType, FEE_API_CODE) Fee_InvalidateBlock(uint16 BlockNumber);

# if (STD_ON == FEE_VERSION_INFO_API)
  FUNC(void, FEE_API_CODE) Fee_GetVersionInfo(Fee_StdVersionInfoRefType versioninfo);
# endif

FUNC(Std_ReturnType, FEE_API_CODE) Fee_EraseImmediateBlock(uint16 BlockNumber);

FUNC(void, FEE_API_CODE) Fee_MainFunction(void);

# if (STD_ON == FEE_GET_ERASE_CYCLE_API)
  FUNC(Std_ReturnType, FEE_API_CODE) Fee_GetEraseCycle(uint8 SectorNumber, Fee_UserData32PtrType DataPtr);
# endif

# if (STD_ON == FEE_GET_WRITE_CYCLE_API)
  FUNC(Std_ReturnType, FEE_API_CODE) Fee_GetWriteCycle(uint16 BlockNumber, Fee_UserData32PtrType DataPtr);
# endif

FUNC(Fee_SectorSwitchStatusType, FEE_API_CODE) Fee_GetSectorSwitchStatus(void);

FUNC(void, FEE_API_CODE) Fee_SuspendWrites(void);
FUNC(void, FEE_API_CODE) Fee_ResumeWrites(void);

#if (FEE_FSS_CONTROL_API == STD_ON)
    FUNC(void, FEE_API_CODE) Fee_DisableFss(void);
    FUNC(void, FEE_API_CODE) Fee_EnableFss(void);
#endif

# define FEE_STOP_SEC_CODE
# include "MemMap.h"

  /**********************************************************************************************************************
   *  GLOBAL DATA PROTOTYPES
   *********************************************************************************************************************/
# define FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
# include "MemMap.h"

  /* Extern declarations of block configuration. */
  extern CONST(struct Fee_ConfigStruct, FEE_APPL_CONFIG) Fee_Config;

# define FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
# include "MemMap.h"

#endif /* FEE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee.h
 *********************************************************************************************************************/
