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
 *         File:  Fee_Sector.c
 *    Component:  If_AsrIfFee
 *       Module:  Fee
 *    Generator:  -
 *
 *  Description:  Internal representation of a FEE-Sector. Provides address translation, access to Sector-Header
 *                (including assembly and checks), maintenance of fill level (incl. allocation of space) alignment stuff
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/* PRQA S 3313 partCfg */ /* Checked, ok: Fee_PartitionCfg is not used within this translation unit */
#include "Fee_Types.h"
/* PRQA L:partCfg */

#include "Fee_Cfg.h"

#include "Fee_IntBase.h"
#include "Fee_Sector.h"
#include "Fee_PrivateCfg.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* We don't do a cross-version check here */

/* index of Erase Cycle within sector header (in 32bit words) */
#define FEE_ERASE_CYCLE_OFFSET_ADDRESS                                (1u)

#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Declaration of internal/private functions; just to satisfy MISRA         *
 * They are useless, but better than justifying...                          */
static FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_Init(Fee_SectorInfoRefType);



FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_Sector_calcFirstFreeAddress(Fee_SectorConfigRefType self)
{
    const Fee_LengthType linkTableEntry = Fee_Sector_alignWrite(self, FEE_SECTOR_LINKTABLE_ELEMENT_SIZE);

    return Fee_Sector_alignAddress(self, FEE_SECTOR_HEADER_SIZE)
        + Fee_Sector_alignAddress(self, (Fee_LengthType)(self->SectorInfo_pt->linkTableSize_t) * linkTableEntry);
}

static FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_Init(Fee_SectorInfoRefType sectorInfo)
{
    sectorInfo->linkTableSize_t = 0;
    sectorInfo->NextFreeAddress_t = 0;
    sectorInfo->isFull = TRUE; 
    sectorInfo->isEmpty = TRUE; /* FULL and EMPTY additionally marks the sector as currently unusable */
    sectorInfo->isNfaConfirmed_bl = FALSE; /* unconfirmed NfA marks sector as being defective (=> not just erased) */

}

FUNC(uint8, FEE_PRIVATE_CODE) Fee_Sector_evaluateHeaderData(
    Fee_SectorConfigRefType self,
    Fee_IntBuffer_u32ConstPtrType intBuf,
    boolean ReadOk)
{
    const Fee_SectorInfoRefType sectorInfo = self->SectorInfo_pt;

#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)  /* ECO_DISABLE_GENERATION : only variable definitions */
    const uint32 reservedMask = 0xFFF00000uL;
    const uint8 sectorId = (uint8)(*intBuf & 0xFFu);
#else  /* ECO_DISABLE_GENERATION : only variable definitions */
    const uint32 reservedMask = 0x0000F0FFuL;
    const uint8 sectorId = (uint8)(*intBuf >> 24);
#endif

    Fee_Sector_Init(sectorInfo);

#if(FEE_GET_ERASE_CYCLE_API == STD_ON)
    sectorInfo->EraseCycleCounter_u32 = intBuf[FEE_ERASE_CYCLE_OFFSET_ADDRESS];
#endif

    /* PRQA S 3344 1 */ /* MD_FEE_13.2_boolean */
    if (ReadOk)
    {
        if(Fee_Sector_isErasedU32(self, intBuf[0]))
        {
            sectorInfo->isNfaConfirmed_bl = TRUE; /* => sector is not usable, but not actually defective */
        }
        else if((sectorId != 0xFFu) && (sectorId != 0) && ((*intBuf & reservedMask) == 0)) 
        {
            Fee_AddressType tempNfa;

            const uint16 linkTableSize =
            #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)  /* ECO_DISABLE_GENERATION : only variable definitions */
                (uint16)(((*intBuf >> 4) & 0xFF0u) | ((*intBuf >> 16) & 0x0F));
            #else  /* ECO_DISABLE_GENERATION : only variable definitions */
                (uint16)(((*intBuf >> 12) & 0xFF0u) | ((*intBuf >> 8) & 0x0F));
            #endif
            
            sectorInfo->linkTableSize_t = linkTableSize;

            tempNfa = Fee_Sector_calcFirstFreeAddress(self);

            /* First Free Address calculated from sector header size + link table size (in bytes)
             * must not exceed one fourth of smaller sector's size.  */
            if(tempNfa < (self->logicalRange_t.size_t >> 2))
            {
                sectorInfo->NextFreeAddress_t = tempNfa;
                sectorInfo->isEmpty = TRUE; /* initally mark as empty; later read and/or writes will update status */
                sectorInfo->isNfaConfirmed_bl = FALSE; /* we don't know the actual next free address */
                sectorInfo->isFull = FALSE;
            }
        } 
        else 
        {
            /* sector header is neither erased nor valid;       *
             * nothing to do; it was intialized to be "invalid" */
        }
    } /* End of ReadOk check. */

    return sectorId;
}

extern FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_assembleHeader(Fee_SectorConfigRefType self,
                                                              Fee_IntBuffer_u32PtrType headerBuffer_au32,
                                                              uint8 sectorId,
                                                              uint16 linkTableSize)
{
    const Fee_SectorInfoRefType sectorInfo = self->SectorInfo_pt;
    uint32 firstWord;

    /**** Built up buffer with the sector header. ******************************/

    Fee_Sector_ClearBuffer(self, headerBuffer_au32, FEE_SECTOR_HEADER_SIZE);

  /* set the FirstFreeAddress of the this Fee sector */
    sectorInfo->linkTableSize_t = linkTableSize;

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    firstWord = sectorId;
    firstWord |= ((uint32)linkTableSize << 4) & 0xFF00u;
    firstWord |= ((uint32)linkTableSize & 0x0F) << 16;
#else
    firstWord = (uint32)sectorId << 24;
    firstWord |= ((uint32)linkTableSize & 0x0FF0) << 12;
    firstWord |= ((uint32)linkTableSize & 0x0F) << 8;
#endif

    headerBuffer_au32[0] = firstWord;

#if (STD_ON == FEE_GET_ERASE_CYCLE_API)
    /* Erase cycle value was already set at startup. Pre-Increment the Counter value. */
    ++sectorInfo->EraseCycleCounter_u32;
    headerBuffer_au32[1u] = sectorInfo->EraseCycleCounter_u32;
#endif
}

/* Update Next Free Address, if new value is larger. In that case NfA cannot be reliable => unconfirm it!
 * Don't bother with sector switch -> Partition shall query for fill level to determine necessity */
FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_updateFillLevel(Fee_SectorConfigRefType self, Fee_AddressType alignedNfa)
{
    const Fee_SectorInfoRefType sectorInfo = self->SectorInfo_pt;

    /* we need to update nfa, only if it was not confirmed yet */
    if((alignedNfa > sectorInfo->NextFreeAddress_t)) 
    {
        sectorInfo->NextFreeAddress_t = alignedNfa;
        sectorInfo->isEmpty = FALSE;
        sectorInfo->isNfaConfirmed_bl = FALSE;
    }
}

/* set NfA to address and confirm it ==> to be used after successfull allocation */
FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_confirmFillLevel(Fee_SectorConfigRefType self, Fee_AddressType alignedNfa)
{
    const Fee_SectorInfoRefType sectorInfo = self->SectorInfo_pt;

    sectorInfo->NextFreeAddress_t = alignedNfa;
    sectorInfo->isNfaConfirmed_bl = TRUE;
    sectorInfo->isEmpty = FALSE;
}

FUNC(Fee_AddressType, FEE_PRIVATE_CODE) Fee_Sector_allocSpace(Fee_SectorConfigRefType self, Fee_LengthType byteCount)
{
	/* set return value to 0 (invalid address)  => for the case the chunk cannot be allocated  */
	Fee_AddressType addr = 0;
    
    if(Fee_Sector_isWriteable(self)) 
	{
		self->SectorInfo_pt->isEmpty = FALSE;


	/* Condition looks quite weird, but it is the check whether the sector has <bytecount> bytes of remaining space.
	 * It is safe as long as we're far away from wrap-arounds. With uint32 there is currently no risk (up to 2GBytes are no problem). */
		if(self->logicalRange_t.size_t >= (byteCount + self->SectorInfo_pt->NextFreeAddress_t))
		{
			/* we are about to allocate something:                        *
			   - NfA is not confirmed (to be re-confirmed upon success)   *
			   - sector will not be empty                                 */
			self->SectorInfo_pt->isNfaConfirmed_bl = FALSE;
			addr = self->SectorInfo_pt->NextFreeAddress_t;
		}
		else
		{   /* chunk cannot be allocated                                                    *
			 *  => mark sector being full.                                                  *
			 *  Sector might also be defect or not usable by other means (to be erased).    *
			 *  In this case isFull is still correct.                                       */
			self->SectorInfo_pt->isFull = TRUE;
		}
	} /* don't modify anything, if sector is not writable */

    return addr;

}

FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_erase(Fee_SectorConfigRefType self)
{
    return (Fee_FlsErase(self->physicalRange_t.baseAddress_t, self->physicalRange_t.size_t) == E_OK) ?
                                                                                FEE_REQ_ACCEPTED : FEE_REQ_REJECTED;
}

FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_writeData(Fee_SectorConfigRefType self, 
                                                                          Fee_AddressType offset, 
                                                                          Fee_IntBuffer_u8ConstPtrType data,
                                                                          Fee_LengthType byteCount)
{
    offset+= self->logicalRange_t.baseAddress_t;
    byteCount = Fee_Sector_alignWrite(self, byteCount);

    return (Fee_FlsWrite(offset, data, byteCount) == E_OK) ? FEE_REQ_ACCEPTED : FEE_REQ_REJECTED;
}

FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_writeMngmtData(Fee_SectorConfigRefType self, 
                                                                              Fee_AddressType offset, 
                                                                              Fee_IntBuffer_u32ConstPtrType data,
                                                                              Fee_LengthType byteCount)
{
    /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    return Fee_Sector_writeData(self, offset, (Fee_UserDataConstPtrType)data, byteCount);
}


FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_readData(Fee_SectorConfigRefType self, 
                                                                      Fee_AddressType offset, 
                                                                      Fee_IntBuffer_u8PtrType data,
                                                                      Fee_LengthType byteCount)
{
    offset+= self->logicalRange_t.baseAddress_t;

    return (Fee_FlsRead(offset, data, byteCount) == E_OK) ? FEE_REQ_ACCEPTED : FEE_REQ_REJECTED;
}

extern FUNC(enum Fee_FlsRequestStatus, FEE_PRIVATE_CODE) Fee_Sector_readMngmtData(Fee_SectorConfigRefType self, 
                                                                              Fee_AddressType offset, 
                                                                              Fee_IntBuffer_u32PtrType data,
                                                                              Fee_LengthType byteCount)
{
    /* PRQA S 0310 2 */ /* MISRA-C:2004 Rule 11.4 These casts are necessary. Verified as ok. */
    return Fee_Sector_readData(self, offset, (Fee_UserDataPtrType)data, byteCount);
}


/* make sector unusable -> this is the "state" when it may/shall be erased (later),  *
   From Partition's point of view this sector's destructor call.                     */

FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_free(Fee_SectorConfigRefType self)
{
    const Fee_SectorInfoRefType info = self->SectorInfo_pt;

    info->isFull = TRUE;
    info->isEmpty = TRUE;
    info->isNfaConfirmed_bl = TRUE;
    info->NextFreeAddress_t = 0;
}


/* reset sector information: It is known to be empty                               *
 * Precondition: Format (erase + sector header write succeeded - not checked here! */
FUNC(void, FEE_PRIVATE_CODE) Fee_Sector_reset(Fee_SectorConfigRefType self)
{
    const Fee_SectorInfoRefType info = self->SectorInfo_pt;

    info->isFull = FALSE;
    info->isEmpty = TRUE;
    info->isNfaConfirmed_bl = TRUE;
    info->NextFreeAddress_t = Fee_Sector_calcFirstFreeAddress(self);
}

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */
