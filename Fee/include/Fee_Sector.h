/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2013 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Fee_Sector.h
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
#if !defined (FEE_SECTOR_H)
# define FEE_SECTOR_H

/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
# define FEE_SECTOR_MAJOR_VERSION                                   (8u)
# define FEE_SECTOR_MINOR_VERSION                                   (0u)
# define FEE_SECTOR_PATCH_VERSION                                   (6u)

#define FEE_SECTOR_HEADER_SIZE                                        (8u)
#define FEE_SECTOR_LINKTABLE_ELEMENT_SIZE 8u

/* PRQA S 3453 5 */ /* MD_MSR_19.7 */
#define FEE_CREATE_ALIGN_MASK(alignBits) (0xFFFFFFFFuL << (alignBits))
#define FEE_ALIGN_LENGTH_VALUE(len, alignBits) ((Fee_LengthType)(((len) + (~FEE_CREATE_ALIGN_MASK(alignBits))) & (FEE_CREATE_ALIGN_MASK(alignBits))))

typedef P2VAR(struct Fee_SectorInfoStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_SectorInfoRefType;
typedef P2CONST(struct Fee_SectorInfoStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_SectorInfoConstRefType;

struct Fee_AddressRangeStruct
{
    Fee_AddressType baseAddress_t;
    Fee_AddressType size_t;
};

struct Fee_SectorInfoStruct {
#if (FEE_GET_ERASE_CYCLE_API == STD_ON)
    uint32 EraseCycleCounter_u32;
#endif
    Fee_AddressType NextFreeAddress_t;
    Fee_BitFieldType linkTableSize_t : 12; /* number of link table entries */
    Fee_BitFieldType isNfaConfirmed_bl:1;
    Fee_BitFieldType isEmpty:1;
    Fee_BitFieldType isFull:1;
};

struct Fee_PartitionAlignmentBitsStruct
{
    uint8 write_u8;
    uint8 address_u8;
};

/* structure to describe the base/start address and size of a logical Fee sector. */
struct Fee_SectorConfigStruct
{
    Fee_SectorInfoRefType SectorInfo_pt;

    uint32 eraseValue_u32;
    struct Fee_AddressRangeStruct physicalRange_t;
    struct Fee_AddressRangeStruct logicalRange_t;

    struct Fee_PartitionAlignmentBitsStruct alignments_t;
};

/*********************************************************************************
 * Sector Functions
 *********************************************************************************/
/* PRQA S 3453 50 */ /* MD_MSR_19.7 */
#define Fee_Sector_alignAddress(sec, value) (FEE_ALIGN_LENGTH_VALUE(value, (sec)->alignments_t.address_u8))
#define Fee_Sector_alignWrite(sec, value) (FEE_ALIGN_LENGTH_VALUE(value, (sec)->alignments_t.write_u8))

#define Fee_Sector_getBaseAddress(self) ((self)->logicalRange_t.baseAddress_t)

#define Fee_Sector_currentLinktableEntryCount(self) ((uint16)((self)->SectorInfo_pt->linkTableSize_t))
#define Fee_Sector_currentLinkTableBytes(self)     (Fee_Sector_currentLinktableEntryCount(self) * \
                                                    Fee_Sector_alignWrite((self), FEE_SECTOR_LINKTABLE_ELEMENT_SIZE))

#define Fee_Sector_isUsable(self) (((self)->SectorInfo_pt->isEmpty != TRUE) || ((self)->SectorInfo_pt->isFull != TRUE))
#define Fee_Sector_isDefective(self) ((!Fee_Sector_isUsable(self)) && ((self)->SectorInfo_pt->isNfaConfirmed_bl == FALSE))

#define Fee_Sector_isErasedU32(sector, value) (((sector)->eraseValue_u32) == (value))
#define Fee_Sector_isErasedU8(sector, value) (((uint8)((sector)->eraseValue_u32)) == ((uint8)(value)))

#define Fee_Sector_getEraseValueU32(self) ((self)->eraseValue_u32)

#define Fee_Sector_getSize(sector)       ((sector)->logicalRange_t.size_t)
#define Fee_Sector_getEndOffset(sector) (Fee_Sector_getSize(sector) - 1u)

#define Fee_Sector_getEraseCycleCounter(sector) ((sector)->SectorInfo_pt->EraseCycleCounter_u32)

/* An unusable Sector's, fill-level is also "known" */
#define Fee_Sector_isFillLevelKnown(self) (((self)->SectorInfo_pt->isNfaConfirmed_bl == TRUE) || (!Fee_Sector_isUsable(self)))

/* Report a fill level of zero whenever sector contains no data (empty or not usable) */
#define Fee_Sector_getFillLevel(self) (((self)->SectorInfo_pt->isEmpty == TRUE) ? 0 : (self)->SectorInfo_pt->NextFreeAddress_t)

/* Only a "usable" sector may be empty (=> it could be written to without any pre-processing (e.g. formatting). */
#define Fee_Sector_isEmpty(self) ((Fee_Sector_isUsable(self)) && ((self)->SectorInfo_pt->isEmpty == TRUE))

#define Fee_Sector_readHeader(self, buf)  Fee_Sector_readMngmtData((self), 0, (buf), FEE_SECTOR_HEADER_SIZE)
#define Fee_Sector_writeHeader(self, buf) Fee_Sector_writeMngmtData((self), 0, (buf), FEE_SECTOR_HEADER_SIZE)


#define Fee_Sector_isWriteable(self) ((Fee_Sector_isUsable(self)) && ((self)->SectorInfo_pt->isFull == FALSE)) 

/* currently we don't implement "clear buffer functionality". References just serve as place holders */
#define Fee_Sector_ClearBuffer(self, buf, length)

#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_Sector_allocSpace(Fee_SectorConfigRefType self, Fee_LengthType byteCount);

extern FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_Sector_calcFirstFreeAddress(Fee_SectorConfigRefType self);

/* make sector unusable -> this is the "state" when it may/shall be erased (later),  *
   From Partition's point of view this sector's destructor call.                     */
extern FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_free(Fee_SectorConfigRefType self);

extern FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_reset(Fee_SectorConfigRefType);

FUNC(uint8, FEE_PRIVATE_CODE) Fee_Sector_evaluateHeaderData(Fee_SectorConfigRefType self, 
                                                            Fee_IntBuffer_u32ConstPtrType intBuf,
                                                            boolean ReadOk);


/* automatically unconfirms level; address shall be rounded up to next address alignment */
extern FUNC(void, FEE_PRIVATE_CODE)Fee_Sector_updateFillLevel(Fee_SectorConfigRefType, Fee_AddressType);
extern FUNC(void, FEE_PRIVATE_CODE)Fee_Sector_confirmFillLevel(Fee_SectorConfigRefType, Fee_AddressType);

extern FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_assembleHeader(Fee_SectorConfigRefType self,
                                                              Fee_IntBuffer_u32PtrType headerBuffer_au32, 
                                                              uint8 sectorId, uint16 linkTableSize);

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_erase(Fee_SectorConfigRefType self);

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_writeData(Fee_SectorConfigRefType self, 
                                                                              Fee_AddressType offset, 
                                                                              Fee_UserDataConstPtrType data,
                                                                              Fee_LengthType byteCount);

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_readData(Fee_SectorConfigRefType self, 
                                                                              Fee_AddressType offset, 
                                                                              Fee_UserDataPtrType data,
                                                                              Fee_LengthType byteCount);

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_writeMngmtData(Fee_SectorConfigRefType self, 
                                                                              Fee_AddressType offset, 
                                                                              Fee_IntBuffer_u32ConstPtrType data,
                                                                              Fee_LengthType byteCount);

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_readMngmtData(Fee_SectorConfigRefType self, 
                                                                              Fee_AddressType offset, 
                                                                              Fee_IntBuffer_u32PtrType data,
                                                                              Fee_LengthType byteCount);

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */



#endif /* FEE_SECTOR_H */
