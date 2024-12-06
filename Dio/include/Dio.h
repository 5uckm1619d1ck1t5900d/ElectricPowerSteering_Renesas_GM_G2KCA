/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio.h                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, DIO type definitions, structure data types and  */
/* API function prototypes of DIO Driver                                      */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  23-Aug-2012  : Initial Version
 *
 * V1.0.1:  14-Sep-2012  : As per SCR 013, instance id is updated for
 *                         both R3.2 and R4.0
 *
 * V1.0.2:  06-Mar-2013  : As per SCR 095, the following changes are made
 *                         1.Software version macros are derived
 *                           from tool output macros
 *                         2.Copyright information is updated
 *
 * V1.0.3:  15-Apr-2013  : As per SCR 139 and mantis #9729 and #8153, the
 *                         following change is made:
 *                         Precompile option is removed for
 *                         Dio_MaskedWritePort API and same API is added in
 *                         common functions.
 *
 * V1.0.4:  13-Jun-2013  : As per SCR 184, the following change is made:
 *                         Precompile option is removed for Dio_MaskedWritePort
 *                         API from API Service Id Macros section.
 *
 * V1.0.5:  08-Aug-2013  : As per CR 225, Device name and Project name are
 *                         updated as part of merge activity.
 *
 * V1.0.6:  17-Sep-2013  : As per CR 241 and mantis 12996, memory class for
 *                         P2CONST is updated.
 *
 * V1.0.7:  04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.8:  06-Aug-2014  : As per mantis #22811, following changes are done.
 *                         1. Code is updated for Renesas C Coding Guidelines.
 *                         2. DIO_E_PARAM_INVALID_GROUP_ID macro is added.
 *
 * V1.0.9:  25-Aug-2014  : As per CR 569, following changes are done.
 *                         1. MISRA C rule violation comment is added for
 *                            (4:3684)-1 and (4:3458)-2.
 *
 * V1.0.10: 30-Aug-2014  : As per mantis #23838, Extra space present before
 *                         == is removed.
 *
 * V1.0.11: 20-Dec-2014  : As per mantis #24772, DIO_E_PARAM_POINTER
 *                         is added.
 */
/******************************************************************************/
#ifndef DIO_H
#define DIO_H
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#define DIO_AR_FOUR_ZERO_THREE     403
#define DIO_AR_THREE_TWO_TWO       322
#define DIO_AR_HIGHER_VERSION      DIO_AR_FOUR_ZERO_THREE
#define DIO_AR_LOWER_VERSION       DIO_AR_THREE_TWO_TWO
/* Standard AUTOSAR types */
#include "Std_Types.h"
/* DIO Configuration header file */
#include "Dio_Cfg.h"
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#if (DIO_DEV_ERROR_DETECT == STD_ON)
/*
 * Since all the debug variables will be available in Dio_Ram.h it is
 * included.
 */
#include "Dio_Debug.h"
#endif
#endif
/*END of DIO_AR_VERSION */

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/

#define DIO_VENDOR_ID    DIO_VENDOR_ID_VALUE
#define DIO_MODULE_ID    DIO_MODULE_ID_VALUE
#define DIO_INSTANCE_ID  DIO_INSTANCE_ID_VALUE

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define DIO_AR_RELEASE_MAJOR_VERSION    4
#define DIO_AR_RELEASE_MINOR_VERSION    0
#define DIO_AR_RELEASE_REVISION_VERSION 3

#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* DIO_AR_VERSION */
/* AUTOSAR specification version information */
#define DIO_AR_MAJOR_VERSION       2
#define DIO_AR_MINOR_VERSION       4
#define DIO_AR_PATCH_VERSION       0

#endif
/*END of DIO_AR_VERSION */

/* Module Software version information */
#define DIO_SW_MAJOR_VERSION       DIO_SW_MAJOR_VERSION_VALUE
#define DIO_SW_MINOR_VERSION       DIO_SW_MINOR_VERSION_VALUE
#define DIO_SW_PATCH_VERSION       DIO_SW_PATCH_VERSION_VALUE

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.2                                      */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3458) Macro defines a braced code statement block.      */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3458)-2 and                           */
/*                 END Msg(4:3458)-2 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      API Service Id Macros                                 **
*******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

#endif /*END of DIO_AR_VERSION */

/* Service ID for DIO Masked Write Channel */
#define DIO_MASKED_WRITE_PORT_SID      (uint8)0x13

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

/* DET code to report Invalid Channel Group ID */

#define DIO_E_PARAM_INVALID_GROUP_ID   (uint8)0x1F

#endif

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/*
 * API service Dio_Init called without a database or invalid database in
 * specified location is reported using following error code.
 */
#define DIO_E_INVALID_DATABASE         (uint8) 0xF1

/*
 * API service used without module initialization is reported using following
 * error code.
 */
#define DIO_E_UNINIT                   (uint8)0xF0

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
*/
#define DIO_E_PARAM_POINTER             (uint8)0x20

#endif
/*END of DIO_AR_VERSION */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* TRACE [R4, DIO182] */
/* TRACE [R3, DIO131][R4, DIO131] */
/* TRACE [R3, DIO017][R4, DIO017] */
/* TRACE [R3, DIO015][R4, DIO015] */
/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* TRACE [R4, DIO183] */
/* TRACE [R3, DIO103][R4, DIO103] */
/* TRACE [R3, DIO018][R4, DIO018] */
/* TRACE [R3, DIO020][R4, DIO020] */
/* TRACE [R3, DIO131][R4, DIO131] */
/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* TRACE [R3, DIO024][R4, DIO024] */
/* TRACE [R3, DIO023][R4, DIO023] */
/* TRACE [R4, DIO185] */
/* TRACE [R3, DIO131][R4, DIO131] */
/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* TRACE [R4, DIO186] */
/* TRACE [R3, DIO131][R4, DIO131] */
/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint16 Dio_PortLevelType;

/* TRACE [R4, DIO184] */
/* TRACE [R3, DIO021][R4, DIO021] */
/* TRACE [R3, DIO022][R4, DIO022] */
/* Structure for Dio_ChannelGroup */
typedef struct STag_Dio_ChannelGroupType
{
  /* Positions of the Channel Group */
  uint16 usMask;
  /* Position from LSB */
  uint8 ucOffset;
  /* PortGroup Index in the array Dio_GstPortGroup[] with respect to the
     pointer Dio_GpPortGroup of the corresponding configuration */
  uint8 ucPortIndex;
} Dio_ChannelGroupType;

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

/* TRACE [R4, DIO187] */
/* TRACE [R4, DIO164] */
/* Data Structure required for initializing the Dio Driver */
typedef struct STag_Dio_ConfigType
{
  /* Database start value - DIO_DBTOC_VALUE */
  uint32 ulStartOfDbToc;
  /* Pointer to DIO Port configuration */
  P2CONST(void, DIO_VAR, DIO_CONFIG_CONST) pPortGroup;
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Pointer to DIO Channel configuration */
  P2CONST(void, DIO_VAR, DIO_CONFIG_CONST) pPortChannel;
  #endif
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  /* Sum of number of channel groups in the previous configuration */
  uint16 usNoofChannelGroups;
  #endif
} Dio_ConfigType;

#endif
/*END of DIO_AR_VERSION */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* Function for DIO read Channel API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort
(Dio_PortType PortId);

/* Function for DIO write Channel API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort
(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
extern FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel
(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel
(Dio_ChannelType ChannelId, Dio_LevelType Level);

#if (DIO_MASKED_WRITE_PORT_API == STD_ON)
/* Function for DIO Masked Write channel API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_MaskedWritePort
(
Dio_PortType  PortId, Dio_PortLevelType  Level, Dio_PortLevelType  Mask
);
#endif

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

/* Function for DIO read Channel Group API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_CONFIG_CONST) ChannelGroupIdPtr);

/* Function for DIO write Channel Group API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_CONFIG_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level);

 /* Function for DIO Initialization API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_Init
(P2CONST(Dio_ConfigType, DIO_VAR, DIO_APPL_CONST) ConfigPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
extern FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_FlipChannel
(Dio_ChannelType ChannelId);
#endif

/* DIO_AR_VERSION */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

/* Function for DIO read Channel Group API */
extern FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr);

/* Function for DIO write Channel Group API */
extern FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level);

#endif
/*END of DIO_AR_VERSION */

/* DIO get Version Information implemented as macro */
#if (DIO_VERSION_INFO_API == STD_ON)
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* TRACE [R3, DIO139][R4, DIO139] */
/* TRACE [R3, DIO126][R4, DIO126] */
/* TRACE [R3, DIO123][R4, DIO123] */
/* Implementation of the Dio_GetVersionInfo */
/* MISRA Violation: START Msg(4:3458)-2 */
  #define Dio_GetVersionInfo(versioninfo) \
  { \
    (versioninfo)->vendorID = (uint16)DIO_VENDOR_ID; \
    (versioninfo)->moduleID = (uint16)DIO_MODULE_ID; \
    (versioninfo)->sw_major_version = DIO_SW_MAJOR_VERSION; \
    (versioninfo)->sw_minor_version = DIO_SW_MINOR_VERSION; \
    (versioninfo)->sw_patch_version = DIO_SW_PATCH_VERSION; \
  }
/* END Msg(4:3458)-2 */

/* DIO_AR_VERSION */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* MISRA Violation: START Msg(4:3458)-2 */
   #define Dio_GetVersionInfo(versioninfo) \
  { \
    (versioninfo)->vendorID = (uint16)DIO_VENDOR_ID; \
    (versioninfo)->moduleID = (uint16)DIO_MODULE_ID; \
    (versioninfo)->instanceID = (uint8)DIO_INSTANCE_ID;\
    (versioninfo)->sw_major_version = DIO_SW_MAJOR_VERSION; \
    (versioninfo)->sw_minor_version = DIO_SW_MINOR_VERSION; \
    (versioninfo)->sw_patch_version = DIO_SW_PATCH_VERSION; \
  }
/* END Msg(4:3458)-2 */

#endif
/*END of DIO_AR_VERSION */
#endif
/* STD_ON == DIO_VERSION_INFO_API */
#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
/* DIO_AR_VERSION */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
#define DIO_START_SEC_CONST_UNSPECIFIED
#endif
/*END of DIO_AR_VERSION */
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Dio_ChannelGroupType, DIO_CONST) Dio_GstChannelGroupData[];
/* END Msg(4:3684)-1 */
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* DIO_AR_VERSION */
#define DIO_STOP_SEC_CONST_UNSPECIFIED
#endif
/*END of DIO_AR_VERSION */
#include "MemMap.h"

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Declaration for DIO Database */
/* MISRA Violation: START Msg(4:3684)-1 */
extern CONST(Dio_ConfigType, DIO_CONFIG_CONST) Dio_GstConfiguration[];
/* END Msg(4:3684)-1 */
#define DIO_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif
/*END of DIO_AR_VERSION */

#endif
/* DIO_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
