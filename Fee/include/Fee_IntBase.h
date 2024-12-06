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
#if !defined (FEE_INTBASE_H)
# define FEE_INTBASE_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/******************************************************************************
 * VERSION IDENTIFICATION
 *****************************************************************************/
# define FEE_INTBASE_MAJOR_VERSION                                   (8u)
# define FEE_INTBASE_MINOR_VERSION                                   (0u)
# define FEE_INTBASE_PATCH_VERSION                                   (0u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(uint8, AUTOMATIC, FEE_VAR_NOINIT) Fee_IntBuffer_u8PtrType;
typedef P2VAR(uint32, AUTOMATIC, FEE_VAR_NOINIT) Fee_IntBuffer_u32PtrType;

typedef P2CONST(uint8, AUTOMATIC, FEE_VAR_NOINIT) Fee_IntBuffer_u8ConstPtrType;
typedef P2CONST(uint32, AUTOMATIC, FEE_VAR_NOINIT) Fee_IntBuffer_u32ConstPtrType;

typedef P2VAR(struct Fee_BlockIdStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_BlockIdRefType;
typedef P2CONST(struct Fee_BlockIdStruct, AUTOMATIC, FEE_VAR_NOINIT) Fee_BlockIdConstRefType;

struct Fee_BlockIdStruct
{
    uint16 Tag;
    uint8  DataIndex;
}; 

enum Fee_FlsRequestStatus
{
    FEE_REQ_ACCEPTED,
    FEE_REQ_SYNC_OK,
    FEE_REQ_REJECTED,
    FEE_REQ_SYNC_FAILED,
    FEE_REQ_SYNC_USELESS /* request cannot be executed, due to insufficient params (e.g. index out of link table) */
};

/* internal enum type, used to identify the status of management information */
enum Fee_MngmtStatus
{
    FEE_MNGMT_DEFECTIVE,
    FEE_MNGMT_ERASED,
    FEE_MNGMT_CONSISTENT
};

#endif /* FEE_INTBASE_H */

/**********************************************************************************************************************
 *  END OF FILE: Fee_IntBase.h
 *********************************************************************************************************************/
