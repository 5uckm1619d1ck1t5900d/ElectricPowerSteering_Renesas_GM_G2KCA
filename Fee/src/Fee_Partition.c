/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2014 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Fee_Parition.c
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
#include "Fee_PrivateCfg.h"

#include "Fee_IntBase.h"
#include "Fee_Partition.h"
#include "Fee_Sector.h"

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

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_init(Fee_PartitionConfigRefType self)
{
    self->ramData_pt->rejectAllMode_bl =
        self->ramData_pt->readOnlyMode_bl = FALSE;
    
    /* indicates that sector heders where not checked yet */
    self->ramData_pt->currentSector_pt = NULL_PTR;

    self->ramData_pt->sectorId_u8 = 0;
}

extern FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_initSector(Fee_PartitionConfigRefType self,
                                                                Fee_SectorConfigRefType sector_pt,
                                                                uint8 sectorId)
{
    if(self->ramData_pt->currentSector_pt == NULL_PTR)
    {
        self->ramData_pt->currentSector_pt = sector_pt;
        self->ramData_pt->sectorId_u8 = sectorId;
    }
    else if(Fee_Sector_isUsable(sector_pt))
    { /* both sectors are usable => check new SectorId and currentSectorId */
        sint16 idDiff = ((sint16)sectorId) - ((sint16)self->ramData_pt->sectorId_u8);
        if((!Fee_Sector_isUsable(self->ramData_pt->currentSector_pt)) || ((idDiff > 0) && (idDiff <= 127)) || (idDiff <= -127))
        {
            self->ramData_pt->currentSector_pt = sector_pt;
            self->ramData_pt->sectorId_u8 = sectorId;
        }
    }
    else if(!Fee_Sector_isUsable(self->ramData_pt->currentSector_pt))
    { 
        self->ramData_pt->sectorId_u8 = 0; /* subsequent sector format will increment Id to a valid value */
        if(Fee_Sector_isDefective(sector_pt) || Fee_Sector_isDefective(self->ramData_pt->currentSector_pt))
        { 
            Fee_Partition_handleError(self, FEE_SECTORS_CORRUPTED);   
        }
    }
    else
    {
        /* currently set newest sector is usable, while passed sector_pt is not --> do not change anything */
    }
}

extern FUNC(uint8, FEE_PRIVATE_CODE) Fee_Partition_getNextSectorId(Fee_PartitionConfigRefType self)
{
    return (uint8)((self->ramData_pt->sectorId_u8 < 254) ? (self->ramData_pt->sectorId_u8 + 1) : 1);
}

FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_updateSectorId(Fee_PartitionConfigRefType self)
{
    self->ramData_pt->sectorId_u8 = Fee_Partition_getNextSectorId(self);
}


FUNC(Fee_SectorConfigRefType, FEE_PRIVATE_CODE) Fee_Partition_getOldestSector(Fee_PartitionConfigRefType self)
{
    /* if Sectors[0] is newest sector, Sectors[1] is oldest sector, and vice versa */

    /* PRQA S 3756 1 */ /* QAC issue? Type of ternary expression des not depend on type of condition! Implicit cast of 0 or 1 is ok. */
    const sint8 index = (&self->associatedSectors_at[0] == self->ramData_pt->currentSector_pt) ? 1 : 0;
    return (self->ramData_pt->currentSector_pt != NULL_PTR) ? (&self->associatedSectors_at[index]) : NULL_PTR;
}

FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_handleError(Fee_PartitionConfigRefType self, Fee_SectorErrorType errorCode)
{
    switch(Fee_ErrorCallbackNotification(self->ownIndex_u8, errorCode))
    {
        case FEE_ERRCBK_RESOLVE_AUTOMATICALLY:
        /* Sector OverFlow can be reolved by erasing the current (newer sector) */

            /* make old sector the new one; then free old (formerly new) one */
            self->ramData_pt->currentSector_pt = Fee_Partition_getOldestSector(self);

            Fee_Partition_freeOldestSector(self);

            break;
        case  FEE_ERRCBK_REJECT_ALL:
            /* Fee should accept no jobs and shall start no sector switch */
            self->ramData_pt->rejectAllMode_bl = TRUE;
        
        /* fall through, as reject all mode implies read only mode */
        
        /* PRQA S 2003 1 *//* Fall through (omitting "break;") is actually intended - see above */
        default: /* FEE_ERRCBK_REJECT_WRITE: */
                /* Fee allows only read class jobs */
            self->ramData_pt->readOnlyMode_bl = TRUE;
            break;
    }  
}

static FUNC(enum Fee_Partition_FillLevelEnum, FEE_PRIVATE_CODE) Fee_Partition_determineRealFillLevel(Fee_PartitionConfigRefType self);

FUNC(enum Fee_Partition_FillLevelEnum, FEE_PRIVATE_CODE) Fee_Partition_getFillLevel(Fee_PartitionConfigRefType self)
{
    enum Fee_Partition_FillLevelEnum level;
    if(self->ramData_pt->currentSector_pt == NULL_PTR)
    {
        /* of course: we can check sectors only, if partiotion was already initialized */
        level = FEE_PART_FILL_LEVEL_UNKNOWN;
    }    
    else if(self->ramData_pt->readOnlyMode_bl) /* PRQA S 3344 */ /* MD_FEE_13.2_boolean */
    {
        /* in read only mode, we always report "normal" -> no sector switch necessary */
        level = FEE_PART_FILL_LEVEL_NORMAL;
    }
    else
    {
        level = Fee_Partition_determineRealFillLevel(self);
    }

   return level;
}

static FUNC(enum Fee_Partition_FillLevelEnum, FEE_PRIVATE_CODE) Fee_Partition_determineRealFillLevel(Fee_PartitionConfigRefType self)
{
    const Fee_SectorConfigRefType newSector = Fee_Partition_getNewestSector(self);
    const Fee_SectorConfigRefType oldSector = Fee_Partition_getOldestSector(self);

    enum Fee_Partition_FillLevelEnum level;
    if(Fee_Sector_isUsable(oldSector) && Fee_Sector_isUsable(newSector))
    { 
        const Fee_AddressType newFillLevel = Fee_Sector_getFillLevel(newSector);

        if(newFillLevel > self->thresholds_t.fss_t)
        {
            level = FEE_PART_FILL_LEVEL_FSS;
        }
        else if(newFillLevel > self->thresholds_t.bss_t)
        {
            level = FEE_PART_FILL_LEVEL_BSS;
        }
        else
        {
            level = FEE_PART_FILL_LEVEL_NORMAL;
        }
    }
    else if(Fee_Sector_isUsable(newSector))
    {
        /* single sector usable */
        level = FEE_PART_FILL_LEVEL_SINGLE_SECTOR;
    }
    else
    { /* both sectors shall be erased. We define this as the same level as FSS threshold */
        level = FEE_PART_FILL_LEVEL_FSS;
    }

    return level;
}


#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  END OF FILE: Fee_ChunkInfo.c
 *********************************************************************************************************************/
 
