/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *                This file provides all public types. 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MULTIPLE INCLUSION PROTECTION
 *********************************************************************************************************************/
#if !defined (FEE_TYPES_H)
# define FEE_TYPES_H

/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
# define FEE_TYPES_MAJOR_VERSION                                   (8u)
# define FEE_TYPES_MINOR_VERSION                                   (0u)
# define FEE_TYPES_PATCH_VERSION                                   (1u)

# include "MemIf_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/******************************************************************************
 *  PUBLISHED INFORMATION
 *****************************************************************************/
# define FEE_BLOCK_OVERHEAD                                           (2u)
# define FEE_PAGE_OVERHEAD                                            (0u)

/******************************************************************************
 *  ERROR CODES IN DEVELOPMENT-MODE
 *****************************************************************************/
# define FEE_E_INVALID_BLOCK_NO                                       (0x02u)

# define FEE_E_PARAM_DATABUFFERPTR                                    (0x10u)
# define FEE_E_PARAM_SECTOR_NUMBER                                    (0x11u)
# define FEE_E_PARAM_LENGTH_OFFSET                                    (0x12u)

# define FEE_E_BUSY                                                   (0x13u)
# define FEE_E_NO_INIT                                                (0x14u)
# define FEE_E_PARAM_MODE                                             (0x15u)

/******************************************************************************
 *  FEE SERVICE IDENTIFICATION
 *****************************************************************************/
# define FEE_SID_INIT                                                 (0x00u)
# define FEE_SID_SETMODE                                              (0x01u)
# define FEE_SID_READ                                                 (0x02u)
# define FEE_SID_WRITE                                                (0x03u)
# define FEE_SID_CANCEL                                               (0x04u)
# define FEE_SID_GETSTATUS                                            (0x05u)
# define FEE_SID_GETJOBRESULT                                         (0x06u)
# define FEE_SID_INVALIDATEBLOCK                                      (0x07u)
# define FEE_SID_GETVERSIONINFO                                       (0x08u)
# define FEE_SID_ERASEIMMEDIATEBLOCK                                  (0x09u)
# define FEE_SID_JOBENDNOTIFICATION                                   (0x10u)
# define FEE_SID_JOBERRORNOTIFICATION                                 (0x11u)
# define FEE_SID_MAINFUNCTION                                         (0x12u)

# define FEE_SID_GET_ERASE_CYCLE                                      (0x20u)
# define FEE_SID_GET_WRITE_CYCLE                                      (0x21u)
# define FEE_SID_GET_SECTOR_SWITCH_STATUS                             (0x22u)
# define FEE_SID_FORCE_SECTOR_SWITCH                                  (0x23u)

#define FEE_SID_CONVERT_BLOCK_CONFIG                                  (0x24u)

#define FEE_SID_SUSPEND_WRITE                                         (0x30u)
#define FEE_SID_RESUME_WRITE                                          (0x31u)
#define FEE_SID_DISABLE_FSS                                           (0x32u)
#define FEE_SID_ENABLE_FSS                                            (0x33u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef P2VAR(uint8, AUTOMATIC, FEE_APPL_DATA) Fee_UserDataPtrType;
typedef P2CONST(uint8, AUTOMATIC, FEE_APPL_DATA) Fee_UserDataConstPtrType;

typedef P2VAR(uint32, AUTOMATIC, FEE_APPL_DATA) Fee_UserData32PtrType;

typedef P2VAR(Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA) Fee_StdVersionInfoRefType;

typedef enum
{
  FEE_SECTOR_SWITCH_IDLE = 0u,
  FEE_SECTOR_SWITCH_BLOCK_COPY,
  FEE_SECTOR_SWITCH_ERASE,
  FEE_SECTOR_SWITCH_UNINIT
} Fee_SectorSwitchStatusType;

typedef enum
{
  FEE_SECTOR_OVERFLOW = 0u,
  FEE_SECTORS_CORRUPTED,
  FEE_SECTOR_FORMAT_FAILED,
  FEE_SECTOR_CRITICAL_FILL_LEVEL
} Fee_SectorErrorType;

typedef uint8 Fee_ErrorCallbackReturnType;
#define FEE_ERRCBK_REJECT_WRITE                                       (0x0u)
#define FEE_ERRCBK_REJECT_ALL                                         (0x1u)
#define FEE_ERRCBK_RESOLVE_AUTOMATICALLY                              (0x80)

typedef P2CONST(struct Fee_PartitionConfigStruct, AUTOMATIC, FEE_APPL_CONFIG) Fee_PartitionConfigRefType;
typedef P2CONST(struct Fee_SectorConfigStruct,    AUTOMATIC, FEE_APPL_CONFIG) Fee_SectorConfigRefType;

typedef P2CONST(struct Fee_ConfigStruct,          AUTOMATIC, FEE_APPL_CONFIG) Fee_ConfigRefType;
typedef P2CONST(struct Fee_BlockConfigStruct,     AUTOMATIC, FEE_APPL_CONFIG) Fee_BlockConfigRefType;

typedef unsigned int Fee_BitFieldType;
typedef signed int Fee_SignedBitfieldType;

typedef uint32 Fee_AddressType;
typedef uint32 Fee_LengthType;

struct Fee_BlockConfigStruct
{
    /* index of the block in the linktable */
    uint16 LinktableIndex_u16;
    /* payload length of block */
    uint16 BlockPayloadSize_u16;
    /* number of datasets per block */
    Fee_BitFieldType NumberOfDatasets_u8 : 8;
    Fee_BitFieldType PartitionIndex : 2;
    /* the exponent of the number of instances per chunk (2^n)-1 */
    Fee_BitFieldType NumberOfInstancesExponent_u8 : 4;
    Fee_BitFieldType ImmediateData_bl : 1;
    Fee_BitFieldType CriticalData_bl : 1;
};

struct Fee_ConfigStruct
{
    Fee_BlockConfigRefType     BlockConfig_at;
    Fee_PartitionConfigRefType PartitionConfig_at;
    uint16          Fee_NumberOfBlocks_u16;
    uint8           Fee_NumberOfPartitions_u8;
    uint8           Fee_DatasetSelectionBits_u8;
    boolean         Fee_ConfigurationIncomplete;
};

#endif 
