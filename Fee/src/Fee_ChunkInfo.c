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
 *         File:  Fee_ChunkInfo.c
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
#include "Fee_Cfg.h"

#include "Fee_IntBase.h"

/* PRQA S 3313 partCfg */ /* Checked, ok: Fee_PartitionCfg is not used within this translation unit */
#include "Fee_ChunkInfo.h"
/* PRQA L:partCfg */


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* We don't do a cross-version check here */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/******************************************************************************
 *  INTERNAL FUNCTIONS
 *****************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA VARIABLE
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(struct Fee_ChunkInfoStruct, FEE_PRIVATE_CONST) Fee_ChunkInfo_NullChunk = {0};

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Declaration of internal/private functions; just to satisfy MISRA         *
 * They are useless, but better than justifying...                          */
static FUNC(Fee_LengthType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetAlignedInstanceSize(Fee_ChunkInfoConstRefType);
static FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetLinkAddress(Fee_ChunkInfoConstRefType, Fee_BlockIdConstRefType);

static FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_NewChunkInfo(
                                Fee_ChunkInfoRefType , const Fee_SectorConfigRefType , Fee_AddressType, uint16, uint8);
static Fee_LengthType Fee_ChunkInfo_GetContentLength(const Fee_ChunkInfoConstRefType);

static FUNC(enum Fee_MngmtStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_CreateFromRawData(const Fee_ChunkInfoRefType,
                                                                                    const Fee_IntBuffer_u32ConstPtrType,
                                                                                    const boolean);



static FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_NewChunkInfo(
        Fee_ChunkInfoRefType info_pt,
        const Fee_SectorConfigRefType sector_pt,
        Fee_AddressType baseAddr,
        uint16 payload,
        uint8 instanceExponent)
{
    info_pt->Sector_pt = sector_pt;
    info_pt->InstanceExponent_b8 = instanceExponent;
    info_pt->PayloadSize_b16 = payload;
    info_pt->wasLinkWritten_bl = 0;
    info_pt->isLinkDefective_bl = 0;
    info_pt->isPseudoChunk_bl = 0;

    info_pt->ChunkBaseOffset_t = baseAddr;
}

static Fee_LengthType Fee_ChunkInfo_GetContentLength(const Fee_ChunkInfoConstRefType chunk_pt)
{
    uint32 retVal = Fee_ChunkInfo_GetAlignedInstanceSize(chunk_pt);

    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if(chunk_pt->isDataChunk_bl)
    {
        retVal = (retVal << chunk_pt->InstanceExponent_b8) - retVal;
    }

    return retVal;
}

static FUNC(Fee_LengthType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetAlignedInstanceSize(Fee_ChunkInfoConstRefType self)
{
    return Fee_Sector_alignAddress(self->Sector_pt, Fee_ChunkInfo_GetInstanceSize(self));
}


/**********************************************************************************************************************
 * Fee_ChunkInfo_GetChunkSize
 *********************************************************************************************************************/
/*! \brief      Calculates the overall size of the chunk described by given ChunkInfo object,
 *              considering alignments
 *              It distinguishes LinkTable and Data Chunks:
 *              Link-Table: "ChunkHeader + Aligned Payload + ChunkTrailer"
 *                    Data: "ChunkHeader + (Aligned Payload * (2^instExp - 1)) + ChunkTrailer"
 *
 *  \return     TRUE                   Always.
 *********************************************************************************************************************/
FUNC(Fee_LengthType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetChunkSize(Fee_ChunkInfoConstRefType chunk)
{
    const Fee_SectorConfigRefType sector = chunk->Sector_pt;
    
    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    return (chunk->isPseudoChunk_bl) ? 
        (Fee_Sector_calcFirstFreeAddress(Fee_ChunkInfo_GetSector(chunk))) :
           (Fee_Sector_alignAddress(sector, FEE_CHUNK_HEADER_SIZE)
           + Fee_ChunkInfo_GetContentLength(chunk)  
           + Fee_Sector_alignAddress(sector, FEE_CHUNK_TRAILER_SIZE));
}

FUNC(uint16, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetInstanceCount(Fee_ChunkInfoConstRefType self)
{
    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    return (uint16)((self->isDataChunk_bl) ? ((1u << self->InstanceExponent_b8) - 1u) : 1u);
}

FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetInstanceStartAddress(
                                                    Fee_ChunkInfoConstRefType chunk, uint16 instanceIndex)
{
    Fee_AddressType retVal;
    const Fee_SectorConfigRefType sector = chunk->Sector_pt;


    if(chunk->isPseudoChunk_bl)  /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        retVal = (instanceIndex == 0) ? 
            Fee_Sector_alignAddress(sector, FEE_SECTOR_HEADER_SIZE) : (Fee_Sector_calcFirstFreeAddress(sector));
    }
    else
    {
        retVal = Fee_ChunkInfo_GetBaseAddress(chunk) 
               + Fee_Sector_alignAddress(sector, FEE_CHUNK_HEADER_SIZE)
               + (Fee_ChunkInfo_GetAlignedInstanceSize(chunk) * instanceIndex);
    }

    return retVal;
}

static FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_ChunkInfo_GetLinkAddress(Fee_ChunkInfoConstRefType chunk,
                                                                     Fee_BlockIdConstRefType blockId)
{
    Fee_AddressType retVal = Fee_ChunkInfo_GetInstanceStartAddress(chunk, 0);

    /* PRQA S 3344 3 */ /* MD_FEE_13.2_boolean */
    if((!chunk->isDataChunk_bl) && (blockId != NULL_PTR))
    { /* "self" is a link-table chunk, and a specific entry (blockId) was requested. */
        const Fee_BitFieldType index = (Fee_BitFieldType)(chunk->isPseudoChunk_bl ? blockId->Tag : blockId->DataIndex);
        const Fee_LengthType offset = Fee_Sector_alignWrite(chunk->Sector_pt, FEE_CHUNK_TRAILER_SIZE) * index;

        /* PRQA S 3762 1 */ /* QAC issue? both types are unsigned! */
        if(offset < chunk->PayloadSize_b16)
        {
            retVal += offset;
        }
        else
        {
            retVal = 0; /* indicate that requested block is outide of link-table (chunk) */
        }
    }
    else
    {
        retVal += Fee_ChunkInfo_GetContentLength(chunk);
    }
    return retVal;
}

static FUNC(enum Fee_MngmtStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_CreateFromRawData(
                                            const Fee_ChunkInfoRefType self,
                                            const Fee_IntBuffer_u32ConstPtrType intBuf,
                                            const boolean readOk)
{
    const Fee_SectorConfigRefType sector = self->Sector_pt;
    enum Fee_MngmtStatus mngmtStatus = FEE_MNGMT_DEFECTIVE;

    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if(readOk)
    {
        if(Fee_Sector_isErasedU32(sector, intBuf[0]) && Fee_Sector_isErasedU32(sector, intBuf[1]))
        {
            mngmtStatus = FEE_MNGMT_ERASED;
        }
        else
        {
            boolean instExpOk;
            const Fee_AddressType sectorEnd = Fee_Sector_getEndOffset(sector);
            Fee_AddressType chunkEndAddress;

#      if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)  /* ECO_DISABLE_GENERATION : only variable definitions */
            const uint32 reservedBits = (intBuf[0] & 0xE0000000uL) | (intBuf[1] & 0x00FF0000uL);
            const boolean isDataChunk = (boolean)((intBuf[0] & 0x10000000uL) == 0);
            const uint8 instExp       = (uint8)((intBuf[0] >> 24) & 0x0Fu);
            const uint16 payload      = (uint16)(intBuf[1] & 0xFFFFu);
#      else
            const uint32 reservedBits = (intBuf[0] & 0x00000E0uL) | (intBuf[1] & 0x0000FF00uL);
            const boolean isDataChunk = (boolean)((intBuf[0] & 0x0000010uL) == 0);
            const uint8 instExp       = (uint8)(intBuf[0] & 0x0Fu);
            const uint16 payload      = (uint16)((intBuf[1] >> 16) & 0xFFFFu);

#       endif
            
            /* we cannot use our "constructors" (NewChunkInfo) as don't want "create" an object,  *
             * but we want to initialize it (complete initialization)                             */
            self->PayloadSize_b16 = payload;
            self->isDataChunk_bl = isDataChunk;
            self->InstanceExponent_b8 = instExp;

            chunkEndAddress = Fee_ChunkInfo_GetEndAddress(self);
            instExpOk = (boolean)(((self->isDataChunk_bl) && (instExp > 0)) ||
                         ((!self->isDataChunk_bl) && (instExp == 0)));

            /* Note: ChunkEndAddress, calculated from Base + Size, cannot overflow (32bit arithmetic)! */
            /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
            if((reservedBits == 0) && (self->PayloadSize_b16 > 0) && (instExpOk) &&
                (self->ChunkBaseOffset_t < sectorEnd ) &&
                (chunkEndAddress <= sectorEnd))
            {
                /* Chunk end address is aligned, as it was calculated from aligned base address and 
                   aligned "components" (header, data area, trailer) */
                mngmtStatus = FEE_MNGMT_CONSISTENT;
            }
        } /* erase value check */
    } /* readError */

    return mngmtStatus;
}

FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_InitLinktableChunk(Fee_ChunkInfoRefType self, uint8 datasetCount)
{
    /* we don't have a sector assigned, yet. We just store number of datasets as instance exponent */
    Fee_ChunkInfo_NewChunkInfo(self, NULL_PTR, 0, 0, datasetCount);
    self->isDataChunk_bl = FALSE;
}

extern FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_InitDataChunk(Fee_ChunkInfoRefType self,
                                                               uint16 payload,
                                                               uint8 instanceExponent)
{
    Fee_ChunkInfo_NewChunkInfo((self), NULL_PTR, 0, payload, instanceExponent);
    self->isDataChunk_bl = TRUE;
}

/* used for allocation; assigns sector as well as next free address -> returns true if chunk would fit */
extern FUNC(boolean, FEE_PRIVATE_CODE) Fee_ChunkInfo_AssignSector(Fee_ChunkInfoRefType self, Fee_SectorConfigRefType sector_pt)
{
    self->Sector_pt = sector_pt;
    
    if(!self->isDataChunk_bl)
    { /* we have to complete payload size calculation based on current chunk.                 *
       *  We must keep original value (Dataset count), if chunk does not fit into sector      */
        /* PRQA S 3762 1 */ /* QAC issue? self->InstanceExponent_b IS unsigned, as well as the other factor and the lvalue! */
        self->PayloadSize_b16 = self->InstanceExponent_b8 * Fee_Sector_alignWrite(sector_pt, FEE_CHUNK_TRAILER_SIZE);
    }

    self->ChunkBaseOffset_t = Fee_Sector_allocSpace(sector_pt, Fee_ChunkInfo_GetChunkSize(self));

    return (boolean)(self->ChunkBaseOffset_t != 0); 
}

FUNC(enum Fee_MngmtStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_InitFromLinkData(
                                                                            Fee_ChunkInfoRefType self,
                                                                            Fee_ChunkInfoConstRefType referrer_pt,
                                                                            Fee_IntBuffer_u32ConstPtrType intBuf,
                                                                            boolean ReadOk)

{
    enum Fee_MngmtStatus linkStatus;
    const Fee_SectorConfigRefType sector_pt = referrer_pt->Sector_pt;  
    const Fee_AddressType linkAddress = 
#   if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)  /* ECO_DISABLE_GENERATION : only variable definitions */
        (Fee_AddressType)((intBuf[0] & 0x00FFFFFFuL) | (intBuf[1] & 0xFF000000uL));
#   else  /* ECO_DISABLE_GENERATION : FSM condition check. No test necessary. */
        (Fee_AddressType)((intBuf[0] >> 8) | (intBuf[1] << 24));
#   endif

    /* Create a chunk pointing immediately behind refChunk. That is the smallest possiible address, *
     * the link may point to. Based on it, the target chunk must still fit into current sector      */
    Fee_ChunkInfo_Clone(self, referrer_pt);
    Fee_ChunkInfo_SwitchToSuccessor(self); 

    linkStatus = Fee_ChunkInfo_CreateFromRawData(self, intBuf, ReadOk);

    if(linkStatus == FEE_MNGMT_CONSISTENT)
    {
        /* Chunk Range checks (Link Address, Base Address, Size) */
        const Fee_AddressType base = self->ChunkBaseOffset_t;
        Fee_AddressType linkOffset = linkAddress - Fee_Sector_getBaseAddress(sector_pt);

        self->ChunkBaseOffset_t = linkOffset 
                                   - Fee_ChunkInfo_GetContentLength(self)
                                   - Fee_Sector_alignAddress(sector_pt, FEE_CHUNK_HEADER_SIZE);
        /* calculate first usable address beyond chunk;
         * if link was erroneously unaligned, it remains unaligned => important for next check */
        linkOffset += Fee_Sector_alignAddress(sector_pt, FEE_CHUNK_TRAILER_SIZE);

        if((linkAddress <= Fee_Sector_getBaseAddress(sector_pt)) ||
            (Fee_Sector_alignAddress(sector_pt, linkAddress) != linkAddress) ||
           (base > self->ChunkBaseOffset_t)  ||           
		   (linkOffset <= self->ChunkBaseOffset_t) ||       
           (linkOffset > Fee_Sector_getSize(sector_pt)))  
        {
            linkStatus = FEE_MNGMT_DEFECTIVE;
        }
        else
        {
            /* link target appears to be valid -> Sector is at least that full,
               updateFillLevel expects aligned address ->  calculations and checks above ensured that it is aligned */
            Fee_Sector_updateFillLevel(sector_pt, linkOffset);
        }
    }

    return linkStatus;
}

/* Reserved Bits in a chunk header. Defining it here is better for ECO (coverage analysis). */
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#    define FEE_CHUNKINFO_HEADER_MASK 0xFFFF0000uL
#else
#    define FEE_CHUNKINFO_HEADER_MASK 0x0000FFFFuL
#endif

FUNC(enum Fee_MngmtStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_EvaluateHeaderData(
                                                                        Fee_ChunkInfoRefType self,
                                                                        Fee_BlockIdRefType blockId_pt,
                                                                        Fee_IntBuffer_u32ConstPtrType intBuf_au32,
                                                                        boolean ReadOk)
{
    enum Fee_MngmtStatus headerStatus = FEE_MNGMT_CONSISTENT;

    /* a pseudo chunk, i.e. sector's link table, is always consistent,
     * as it's information did not result from Dataflash itself */
    if(self->isPseudoChunk_bl == FALSE)
    {
        const Fee_SectorConfigRefType sector_pt = self->Sector_pt;  
        struct Fee_ChunkInfoStruct backupChunk; /* create a "backup" */

        Fee_ChunkInfo_Clone(&backupChunk, self);

        headerStatus =
            Fee_ChunkInfo_CreateFromRawData(self, intBuf_au32, ReadOk);


        if(headerStatus == FEE_MNGMT_CONSISTENT)
        {
            const uint32 headerMask = FEE_CHUNKINFO_HEADER_MASK;

            /* Perform activites regardless of actual validity.
               If header was already detected to be DEFECTIVE, it won't become CONSISTENT here */
    #if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
            blockId_pt->Tag = (uint16)(intBuf_au32[0] & 0xFFFFu);
            blockId_pt->DataIndex = (uint8)((intBuf_au32[0] >> 16) & 0xFFu);
    #else
            blockId_pt->Tag = (uint16)(intBuf_au32[0] >> 16);
            blockId_pt->DataIndex  = (uint8)((intBuf_au32[0] >> 8) & 0xFFu);
    #endif
            
            if((intBuf_au32[1] & headerMask) != 0)
            {
                headerStatus = FEE_MNGMT_DEFECTIVE;
            }
            
            if(Fee_ChunkInfo_isLinkTable(self))
            {
                const uint32 linkTablePayload = blockId_pt->DataIndex * Fee_Sector_alignWrite(sector_pt, FEE_CHUNK_TRAILER_SIZE);

                /* Set DataIndex to max DataIndex, rather than number of Datasets (because a DataIndex "NumDatasets" is invalid) */
                blockId_pt->DataIndex--;

                if(((uint32)self->PayloadSize_b16) != linkTablePayload)
                {
                    headerStatus = FEE_MNGMT_DEFECTIVE;
                }
            }

        }

        switch(headerStatus)
        {
            case FEE_MNGMT_ERASED: 
                /* Header was erased; thus we don't want do do anything.
                   However, it doesn't appear to ba a good default ... */
                break;
            case FEE_MNGMT_CONSISTENT:
                Fee_Sector_updateFillLevel(sector_pt, Fee_ChunkInfo_GetEndAddress(self) + 1u);
                break;
            default: /* that is Defective */
               /* Restore from backup, but increase Offset to point to next possible location */
                Fee_ChunkInfo_Clone(self, &backupChunk);
                self->ChunkBaseOffset_t += Fee_Sector_alignAddress(sector_pt, FEE_CHUNK_HEADER_SIZE);
            
                /* a (possible) header address is always aligned */
                Fee_Sector_updateFillLevel(sector_pt, self->ChunkBaseOffset_t);
                break;
        }
    }
     
    return headerStatus;
}

/* some "local" macros, that shall help to abstract from endianness */
/* PRQA S 3453 10 */ /* MD_MSR_19.7 */
#define Fee_ChunkInfo_TypeInfo(chunk) ((uint32)(((chunk)->isDataChunk_bl) ? ((chunk)->InstanceExponent_b8) : 0x10u))

#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#   define Fee_ChunkInfo_AssembleChunkTypeInfo(chunk) (Fee_ChunkInfo_TypeInfo(chunk) << 24)
#   define Fee_ChunkInfo_AssemblePayloadInfo(chunk) ((uint32)((chunk)->PayloadSize_b16))
#else
#   define Fee_ChunkInfo_AssembleChunkTypeInfo(chunk) Fee_ChunkInfo_TypeInfo(chunk)
#   define Fee_ChunkInfo_AssemblePayloadInfo(chunk) (((uint32)((chunk)->PayloadSize_b16)) << 16)
#endif

FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_AssembleHeader(Fee_ChunkInfoConstRefType self,
                                                          Fee_BlockIdConstRefType blockId_pt, 
                                                          Fee_IntBuffer_u32PtrType buffer_au32)
{
    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    const uint32 dataIndexField = (uint32)((self->isDataChunk_bl) ? blockId_pt->DataIndex : self->InstanceExponent_b8);

    Fee_Sector_ClearBuffer(Fee_ChunkInfo_GetSector(self), buffer_au32, FEE_CHUNK_HEADER_SIZE_WRITE);

    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)  /* ECO_DISABLE_GENERATION : only variable definitions */
        buffer_au32[0] = (uint32)blockId_pt->Tag  | (dataIndexField << 16);
    #else  /* ECO_DISABLE_GENERATION : only variable definitions */
        buffer_au32[0] = ((uint32)blockId_pt->Tag << 16) | (dataIndexField << 8);
    #endif

    /* PRQA S 3344 2 */ /* MD_FEE_13.2_boolean */
    /* PRQA S 3760 1 */ /* QAC issue? all relevant types (see macros above) are unsigned! */
    buffer_au32[0] |= Fee_ChunkInfo_AssembleChunkTypeInfo(self);
    buffer_au32[1] = Fee_ChunkInfo_AssemblePayloadInfo(self);
}

FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_AssembleLink(Fee_ChunkInfoConstRefType self, Fee_IntBuffer_u32PtrType buffer_au32)
{
    /* passing no blockId means "current chunk's link address, rather than some specific link-table index */
    const Fee_AddressType link = Fee_ChunkInfo_GetLinkAddress(self, NULL_PTR) + 
                                        Fee_Sector_getBaseAddress(Fee_ChunkInfo_GetSector(self));
      /**** Fill up data buffer with the corresponding content the chunk link shall be written with. *******************/

    Fee_Sector_ClearBuffer(Fee_ChunkInfo_GetSector(self), buffer, FEE_CHUNK_TRAILER_SIZE);

#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)  /* ECO_DISABLE_GENERATION : only variable definitions */
        buffer_au32[0] = (0x00FFFFFFuL & link);
        
        /* put highest address byte into last byte of chunk link */
        buffer_au32[1] = (0xFF000000uL & link);
    #else  /* ECO_DISABLE_GENERATION : only variable definitions */
        buffer_au32[0] = link << 8;
        /* put highest address byte into last byte of chunk link */
        buffer_au32[1] = (link >> 24);
    #endif

    /* PRQA S 3344 2 */ /* MD_FEE_13.2_boolean */
    /* PRQA S 3760 1 */ /* QAC issue? all relevant types (see macros above) are unsigned! */
    buffer_au32[0] |= Fee_ChunkInfo_AssembleChunkTypeInfo(self);
    buffer_au32[1] |= Fee_ChunkInfo_AssemblePayloadInfo(self);
}

FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadInstanceHeader(
                            Fee_ChunkInfoConstRefType self, uint16 instanceIndex, Fee_IntBuffer_u32PtrType buffer)
{
    enum Fee_FlsRequestStatus result = FEE_REQ_SYNC_OK;

    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if(self->isDataChunk_bl)
    {
        const Fee_SectorConfigRefType sector = Fee_ChunkInfo_GetSector(self);
        const Fee_AddressType addr = Fee_ChunkInfo_GetInstanceStartAddress(self, instanceIndex);
        const Fee_LengthType readLen = Fee_Sector_alignWrite(sector, FEE_INSTANCE_HEADER_SIZE);
        /* We have to prepare data buffer's first 4 bytes.
         * It is important for the case "Fls page size < 4"
         * Otherwise (if page size > 4 Bytes), we expect 2^n bytes to be read
         *  => we will always have multiples of 32bits (it is important during checks) */
        buffer[0] = Fee_Sector_getEraseValueU32(sector); 

        /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
        result = Fee_Sector_readMngmtData(sector, addr, buffer, readLen);
    }

    return result;
}

FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadInstanceTrailer(Fee_ChunkInfoConstRefType self, 
                                                                                    uint16 instanceIndex,
                                                                                    Fee_IntBuffer_u32PtrType buffer_au32)
{
    enum Fee_FlsRequestStatus result = FEE_REQ_SYNC_OK;

    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if(self->isDataChunk_bl)
    {
        const Fee_SectorConfigRefType sector = Fee_ChunkInfo_GetSector(self);
        const Fee_AddressType addr = Fee_ChunkInfo_GetInstanceStartAddress(self, instanceIndex)
            + Fee_ChunkInfo_getPayload(self) + FEE_INSTANCE_HEADER_SIZE;

        /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
        result = Fee_Sector_readMngmtData(sector, addr, buffer_au32, FEE_INSTANCE_TRAILER_SIZE);
    }

    return result;
}


FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadInstancePayload(Fee_ChunkInfoConstRefType self ,
                                                                                    uint16 instanceIndex,
                                                                                    Fee_UserDataPtrType buffer_au8, uint16 offset, uint16 length)
{
    enum Fee_FlsRequestStatus result = FEE_REQ_SYNC_USELESS;

    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if(self->isDataChunk_bl)
    {
        const Fee_SectorConfigRefType sector = Fee_ChunkInfo_GetSector(self);
        const Fee_AddressType addr = Fee_ChunkInfo_GetInstanceStartAddress(self, instanceIndex)
            + FEE_INSTANCE_HEADER_SIZE + offset;

        /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
        result = Fee_Sector_readData(sector, addr, buffer_au8, length);
    }

    return result;
}

FUNC(void, FEE_PRIVATE_CODE) Fee_ChunkInfo_Construct(Fee_ChunkInfoRefType self, Fee_SectorConfigRefType sector_pt)
{
    self->Sector_pt = sector_pt;
    self->PayloadSize_b16 = 
        (uint16)Fee_Sector_currentLinkTableBytes(sector_pt);
    self->isDataChunk_bl = FALSE;
    self->wasLinkWritten_bl = FALSE;
    self->isLinkDefective_bl = FALSE;
    self->isPseudoChunk_bl = TRUE;
    self->InstanceExponent_b8 = 
    self->ChunkBaseOffset_t = 0;
}


FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadChunkHeader(Fee_ChunkInfoConstRefType self,
                                                                                       Fee_IntBuffer_u32PtrType buffer_au32)
{
    enum Fee_FlsRequestStatus retVal;
    
    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if(self->isPseudoChunk_bl)
    {
        /* Pesudo chunks (at sector start) don't have a chunk header.             *
         * Thus reading it makes no sense. However, do not retun an ERROR nor OK) */
        retVal = FEE_REQ_SYNC_USELESS; 
    }
    else
    {
        retVal = Fee_Sector_readMngmtData(Fee_ChunkInfo_GetSector(self),
                                    Fee_ChunkInfo_GetBaseAddress(self),
                                    buffer_au32,
                                    FEE_CHUNK_HEADER_SIZE_READ);
    }
    return retVal;
}

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_ReadChunkLink(Fee_ChunkInfoConstRefType self,
                                                                                     Fee_BlockIdConstRefType blockId,
                                                                                     Fee_IntBuffer_u32PtrType buffer_au32)
{
    enum Fee_FlsRequestStatus retVal;
    const Fee_AddressType linkAddress = Fee_ChunkInfo_GetLinkAddress(self, blockId); 

    if(linkAddress != 0)
    {
        retVal = Fee_Sector_readMngmtData(Fee_ChunkInfo_GetSector(self),
                                    linkAddress,
                                    buffer_au32,
                                    FEE_CHUNK_HEADER_SIZE_READ);
    }
    else
    {
        retVal = FEE_REQ_SYNC_USELESS;
    }

    return retVal;
}

FUNC(void , FEE_PRIVATE_CODE) Fee_ChunkInfo_SwitchToSuccessor(Fee_ChunkInfoRefType self)
{
        self->ChunkBaseOffset_t += Fee_ChunkInfo_GetChunkSize(self);
        self->PayloadSize_b16 = 1u;
        self->InstanceExponent_b8 = 1u;
        self->isPseudoChunk_bl = FALSE;
}

FUNC(boolean, FEE_PRIVATE_CODE)  Fee_ChunkInfo_Equals(Fee_ChunkInfoConstRefType self, Fee_ChunkInfoConstRefType other)
{
    return (boolean)
       ((self->Sector_pt == other->Sector_pt) &&
        (self->ChunkBaseOffset_t == other->ChunkBaseOffset_t) &&
        (self->InstanceExponent_b8 == other->InstanceExponent_b8) &&
        (self->isDataChunk_bl == other->isDataChunk_bl) &&
        (self->PayloadSize_b16 == other->PayloadSize_b16));
}

/* ==> Allocation, i.e. UnconfirmNfa! */

/* PRQA S 3453 6 */ /* MD_MSR_19.7 */
#if(FEE_GET_WRITE_CYCLE_API == STD_ON)
	/* link-table chunks will always be written without WCC */
#    define FEE_CHUNK_HEADER_WRITE_SIZE(isDataChunk) (((isDataChunk) != 0) ? FEE_CHUNK_HEADER_SIZE : FEE_CHUNK_HEADER_SIZE_READ)
#else
#    define FEE_CHUNK_HEADER_WRITE_SIZE(isDataChunk) FEE_CHUNK_HEADER_SIZE
#endif

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_WriteHeader(Fee_ChunkInfoConstRefType self,
                                                                                   Fee_IntBuffer_u32ConstPtrType buffer_au32)
{
    const Fee_AddressType address = Fee_ChunkInfo_GetBaseAddress(self);
    const Fee_SectorConfigRefType sector_pt = Fee_ChunkInfo_GetSector(self);
    
    const Fee_LengthType len = FEE_CHUNK_HEADER_WRITE_SIZE(self->isDataChunk_bl);

    return Fee_Sector_writeMngmtData(sector_pt, address, buffer_au32, len);
}
/* ==> Requires Chunk to have been allocated, i.e. NfA must be confirmed! */
extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_ChunkInfo_WriteChunkLink(Fee_ChunkInfoConstRefType self,
                                                                                     Fee_BlockIdConstRefType blockId_pt,
                                                                                     Fee_IntBuffer_u32ConstPtrType buffer_au32)
{
    enum Fee_FlsRequestStatus retVal;
    const Fee_AddressType address = Fee_ChunkInfo_GetLinkAddress(self, blockId_pt);
    
    if(address > 0)
    {
        const Fee_SectorConfigRefType sector_pt = Fee_ChunkInfo_GetSector(self);
        retVal = Fee_Sector_writeMngmtData(sector_pt, address, buffer_au32, FEE_CHUNK_TRAILER_SIZE);
    }
    else
    {
        retVal = FEE_REQ_SYNC_OK;
    }

    return retVal;
}

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  END OF FILE: Fee_ChunkInfo.c
 *********************************************************************************************************************/
