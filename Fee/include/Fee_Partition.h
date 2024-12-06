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
 *         File:  Fee_Partition.h
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
#if !defined (FEE_PARTITION_H)
# define FEE_PARTITION_H

#include "Fee_Sector.h"

/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
# define FEE_PARTITION_MAJOR_VERSION                                   (8u)
# define FEE_PARTITION_MINOR_VERSION                                   (0u)
# define FEE_PARTITION_PATCH_VERSION                                   (8u)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define FEE_PART_MODE_READ_ONLY    0u
#define FEE_PART_MODE_REJECT_ALL    1u
#define FEE_PART_MODE_RW            2u

enum Fee_Partition_FillLevelEnum
{
    FEE_PART_FILL_LEVEL_UNKNOWN       = -1,
    FEE_PART_FILL_LEVEL_SINGLE_SECTOR = 0,
    FEE_PART_FILL_LEVEL_NORMAL        = 1,
    FEE_PART_FILL_LEVEL_BSS           = 2,
    FEE_PART_FILL_LEVEL_FSS           = 3,
    FEE_PART_FILL_LEVEL_OVERFLOW      = 4
};

struct Fee_PartitionInfoStruct 
{
    Fee_SectorConfigRefType currentSector_pt;

    Fee_BitFieldType sectorId_u8 : 8;
    Fee_BitFieldType readOnlyMode_bl : 1;
    Fee_BitFieldType rejectAllMode_bl  : 1;
};

typedef P2VAR(struct Fee_PartitionInfoStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_PartitionInfoRefType;

struct Fee_PartitionConfigStruct
{
    Fee_PartitionInfoRefType ramData_pt;
    struct Fee_PartitionThresholdsStruct
    {
        Fee_AddressType fss_t;
        Fee_AddressType bss_t;
    } thresholds_t;
    struct Fee_SectorConfigStruct associatedSectors_at[2];
    uint16 linkTableEntries_u16;
    uint8 ownIndex_u8;
};

/* Structure allowing RAM reservation for a complete Partition,    *
 * i.e. RAM data for the partition as well as its sectors          *
 * Shall only be used for purpose of RAM allocation                */
struct Fee_PartitionsRamDataStruct
{
    struct Fee_PartitionInfoStruct partition_t;
    struct Fee_SectorInfoStruct sector_at[2];
};

/*********************************************************************************
 * Partition Functions
 *********************************************************************************/
/* PRQA S 3453 15 */ /* MD_MSR_19.7 */
#define Fee_Partition_getId(self) ((self)->ownIndex_u8)

#define Fee_Partition_getSectorByPos(self, pos) (&((self)->associatedSectors_at[pos]))
#define Fee_Partition_getNewestSector(self) ((self)->ramData_pt->currentSector_pt)

#define Fee_Partition_isNewestSector(self, sector) (Fee_Partition_getNewestSector(self) == (sector))

#define Fee_Partition_getConfiguredLinktableSize(self) ((self)->linkTableEntries_u16)

#define Fee_Partition_freeOldestSector(self) (Fee_Sector_free(Fee_Partition_getOldestSector(self)))
#define Fee_Partition_switchSectors(self)    (Fee_Sector_reset((self)->ramData_pt->currentSector_pt = Fee_Partition_getOldestSector(self)))

#define Fee_Partition_isWriteable(self) ((self)->ramData_pt->readOnlyMode_bl == FALSE)
#define Fee_Partition_isReadable(self) ((self)->ramData_pt->rejectAllMode_bl == FALSE)

#define FEE_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* External Function, REQUIRED by Fee_Partition. Declared here, since it use used in implementation only. *
 * However, MISRA requires declaration in a header file (Fee_Partition.c would be a better place)         */
extern FUNC(Fee_ErrorCallbackReturnType, FEE_PRIVATE_CODE) Fee_ErrorCallbackNotification(uint8, Fee_SectorErrorType);


extern FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_init(Fee_PartitionConfigRefType self);

extern FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_initSector(Fee_PartitionConfigRefType self,
                                                                   Fee_SectorConfigRefType sector_pt,
                                                                   uint8 sectorId);

extern FUNC(Fee_SectorConfigRefType, FEE_PRIVATE_CODE) Fee_Partition_getOldestSector(Fee_PartitionConfigRefType self);

extern FUNC(enum Fee_Partition_FillLevelEnum, FEE_PRIVATE_CODE) Fee_Partition_getFillLevel(Fee_PartitionConfigRefType self);

extern FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_handleError(Fee_PartitionConfigRefType self, Fee_SectorErrorType errorCode);

/* just query next SectorId based on current internal data (do not update) */
extern FUNC(uint8, FEE_PRIVATE_CODE) Fee_Partition_getNextSectorId(Fee_PartitionConfigRefType self);

/* "confirm" new SectorId, i.e. update internal data */
extern FUNC(void, FEE_PRIVATE_CODE) Fee_Partition_updateSectorId(Fee_PartitionConfigRefType self);

#define FEE_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */



#endif /* FEE_PARTITION_H */
