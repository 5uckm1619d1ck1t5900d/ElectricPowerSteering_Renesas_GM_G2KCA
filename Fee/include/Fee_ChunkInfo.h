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
 *         File:  Fee_ChunkInfo.h
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
#ifndef FEE_CHUNKINFO_H
#define FEE_CHUNKINFO_H

/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
# define FEE_CHUNKINFO_MAJOR_VERSION                                   (8u)
# define FEE_CHUNKINFO_MINOR_VERSION                                   (0u)
/* BCD coded! */
# define FEE_CHUNKINFO_PATCH_VERSION                                   (0x10u)

#include "Fee_Types.h"
#include "Fee_Sector.h"

#define FEE_INSTANCE_HEADER_SIZE                                      (1u)
#define FEE_INSTANCE_TRAILER_SIZE                                     (1u)

#define FEE_CHUNK_HEADER_SIZE                                         (16u)
#define FEE_CHUNK_HEADER_SIZE_READ                                    (8u)

#if (STD_ON == FEE_GET_WRITE_CYCLE_API)
# define FEE_CHUNK_HEADER_SIZE_WRITE                                  (FEE_CHUNK_HEADER_SIZE)
/* offset of WCC in 32bit buffer array */
# define FEE_CHUNK_HEADER_WCC_WORD_OFFSET                             (2u)
# define FEE_WCC_BYTE_COUNT                                           (4u)
#else
# define FEE_CHUNK_HEADER_SIZE_WRITE                                  (FEE_CHUNK_HEADER_SIZE_READ)
#endif

/* In order keep dependencies simple, the Sector defines its own chunk link size.
 * Chunk already depends on Sector; we just define CHUNK_TRAILER_SIZE to have same value
 */
#define FEE_CHUNK_TRAILER_SIZE (FEE_SECTOR_LINKTABLE_ELEMENT_SIZE)

typedef P2VAR(struct Fee_ChunkInfoStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_ChunkInfoRefType;
typedef P2CONST(struct Fee_ChunkInfoStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_ChunkInfoConstRefType;

struct Fee_ChunkInfoStruct
{
    Fee_SectorConfigRefType Sector_pt;
    Fee_AddressType ChunkBaseOffset_t;
    Fee_BitFieldType PayloadSize_b16:16;
    Fee_BitFieldType InstanceExponent_b8:8;  
    Fee_BitFieldType isDataChunk_bl:1;
    Fee_BitFieldType isPseudoChunk_bl:1;     /* denotes the initial "pseudo chunk" */
    Fee_BitFieldType wasLinkWritten_bl:1;
    Fee_BitFieldType isLinkDefective_bl:1;
};

#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(struct Fee_ChunkInfoStruct, FEE_PRIVATE_CONST) Fee_ChunkInfo_NullChunk;

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*********************************************************************************
 * ChunkInf Functions
 *********************************************************************************/

/* PRQA S 3453 35 */ /* MD_MSR_19.7 */
#define Fee_ChunkInfo_Clone(target_pt, source_pt) (*(target_pt) = *(source_pt))


#define Fee_ChunkInfo_Clear(chunk_pt) (Fee_ChunkInfo_Clone((chunk_pt), &Fee_ChunkInfo_NullChunk))

#define Fee_ChunkInfo_GetSector(chunk_pt) ((chunk_pt)->Sector_pt)
#define Fee_ChunkInfo_GetBaseAddress(chunk_pt) ((chunk_pt)->ChunkBaseOffset_t)
#define Fee_ChunkInfo_GetEndAddress(chunk_pt) (Fee_ChunkInfo_GetBaseAddress(chunk_pt) + (Fee_ChunkInfo_GetChunkSize(chunk_pt) - 1u))

#define Fee_ChunkInfo_doesConfigMatch(self, config_pt) (Fee_ChunkInfo_getPayload(self) == (config_pt)->BlockPayloadSize_u16)

#define Fee_ChunkInfo_isDataChunk(self)           ((self)->isDataChunk_bl == TRUE)
#define Fee_ChunkInfo_isLinkTable(self)           (!Fee_ChunkInfo_isDataChunk(self))
#define Fee_ChunkInfo_isInitialLinkTable(self)    (Fee_ChunkInfo_isLinkTable(self) && ((self)->isPseudoChunk_bl == TRUE))

/* A link table chunk may follow the pseudo-chunk (which is the link table at sector start) */
#define Fee_ChunkInfo_isLinkTableAllowed(self) ((Fee_ChunkInfo_isInitialLinkTable(self)) && (Fee_ChunkInfo_isLinkAllowed(self)))

#define Fee_ChunkInfo_isLinkAllowed(self)   ((self)->wasLinkWritten_bl == FALSE)
#define Fee_ChunkInfo_isLinkConsistent(self) ((self)->isLinkDefective_bl == FALSE)

#define Fee_ChunkInfo_confirmEmptyLink(self)      ((self)->wasLinkWritten_bl = (self)->isLinkDefective_bl = FALSE)

/* an "unconfirmed", i.e. defective, link cannot be writable! */
#define Fee_ChunkInfo_unconfirmLink(self)   ((self)->isLinkDefective_bl = (self)->wasLinkWritten_bl = TRUE)

#define Fee_ChunkInfo_getPayload(self)  ((uint16)((self)->PayloadSize_b16))
/* return instance size, including header and trailer */
#define Fee_ChunkInfo_GetInstanceSize(self) (((Fee_LengthType)Fee_ChunkInfo_getPayload(self)) + \
                                                  (((self)->isDataChunk_bl != FALSE) ? \
                                                        (FEE_INSTANCE_HEADER_SIZE + FEE_INSTANCE_TRAILER_SIZE) : 0))

#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */
extern FUNC(boolean, FEE_PRIVATE_CODE)  Fee_ChunkInfo_Equals(Fee_ChunkInfoConstRefType self, Fee_ChunkInfoConstRefType other);

extern FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_Construct(Fee_ChunkInfoRefType, Fee_SectorConfigRefType);


/* used for allocation; assigns sector as well as next free address -> returns true if chunk would fit */
extern FUNC(boolean, FEE_PRIVATE_CODE) Fee_ChunkInfo_AssignSector(Fee_ChunkInfoRefType, Fee_SectorConfigRefType);

extern FUNC(enum Fee_MngmtStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_EvaluateHeaderData(
    Fee_ChunkInfoRefType self,
    Fee_BlockIdRefType blockId_pt,
    Fee_IntBuffer_u32ConstPtrType intBuf_au32,
    boolean ReadOk);

extern FUNC(enum Fee_MngmtStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_InitFromLinkData(
    Fee_ChunkInfoRefType self,
    Fee_ChunkInfoConstRefType referrer_pt,
    Fee_IntBuffer_u32ConstPtrType intBuf,
    boolean ReadOk);


extern FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_InitDataChunk(Fee_ChunkInfoRefType self,
                                                               uint16 payload,
                                                               uint8 instanceExponent);
extern FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_InitLinktableChunk(Fee_ChunkInfoRefType self, uint8 datasetCount);


/* return instance size, including header and trailer */
extern FUNC(Fee_LengthType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetChunkSize( Fee_ChunkInfoConstRefType chunk);
extern FUNC(uint16, FEE_PRIVATE_CODE)   Fee_ChunkInfo_GetInstanceCount(Fee_ChunkInfoConstRefType self);

/* Moves internal address pointer to point to the "theoretical" chunk beyond current one. */
extern FUNC(void , FEE_PRIVATE_CODE) Fee_ChunkInfo_SwitchToSuccessor(Fee_ChunkInfoRefType);

extern FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetInstanceStartAddress(
                                                     Fee_ChunkInfoConstRefType chunk, uint16 instanceIndex);

FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_AssembleHeader(Fee_ChunkInfoConstRefType self,
                                                          Fee_BlockIdConstRefType blockId_pt, 
                                                          Fee_IntBuffer_u32PtrType buffer_au32);

extern FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_AssembleLink(Fee_ChunkInfoConstRefType self, Fee_IntBuffer_u32PtrType buffer_au32);

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadChunkHeader(Fee_ChunkInfoConstRefType,
                                                                                       Fee_IntBuffer_u32PtrType);
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadChunkLink(Fee_ChunkInfoConstRefType,
                                                                                     Fee_BlockIdConstRefType,
                                                                                     Fee_IntBuffer_u32PtrType);

/* ==> Allocation, i.e. UnconfirmNfa! */
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_WriteHeader(Fee_ChunkInfoConstRefType,
                                                                                   Fee_IntBuffer_u32ConstPtrType);
/* ==> Requires Chunk to have been allocated, i.e. NfA must be confirmed! */
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_WriteChunkLink(Fee_ChunkInfoConstRefType,
                                                                                     Fee_BlockIdConstRefType,
                                                                                     Fee_IntBuffer_u32ConstPtrType);

/*************** Instance specific functions **********************************/
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadInstanceHeader(Fee_ChunkInfoConstRefType, uint16, Fee_IntBuffer_u32PtrType);
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadInstanceTrailer(Fee_ChunkInfoConstRefType, uint16, Fee_IntBuffer_u32PtrType);
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadInstancePayload(Fee_ChunkInfoConstRefType, uint16, Fee_UserDataPtrType, uint16, uint16);

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* FEE_CHUNKINFO_H */
