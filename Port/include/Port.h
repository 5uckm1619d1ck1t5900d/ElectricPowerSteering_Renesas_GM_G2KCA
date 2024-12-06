/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port.h                                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros, PORT type definitions, structure data types and */
/* API function prototypes of PORT Driver                                     */
/*                                                                            */
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
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, following changes are made:
 *                         1. Software Version is updated.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  12-Mar-2013  : As per SCR 091 for mantis #9240, two APIs
 *                         'Port_SetToDioMode' and 'Port_SetToAlternateMode'
 *                         are added.
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11215 and #11895, following changes
 *                         are made:
 *                         1. Software Minor Version is updated.
 *                         2. Header and Environment sections are updated to
 *                            change the device name.
 *
 * V1.4.0:  04-Sep-2013  : As per CR 236 for mantis #12602, Software Minor
 *                         Version is updated.
 *
 * V1.4.1:  09-Dec-2013  : As per CR 338 for mantis #11214, following changes
 *                         are made:
 *                         1. Software Patch Version is updated.
 *                         2. Alternative modes are added for Port_SetPinMode()
 *                            API.
 *
 * V1.4.2:  04-Jan-2014  : As per CR 378 for mantis #19208, as part of merging
 *                         activity copyright information is updated.
 *
 * V1.5.0:  21-Feb-2014  : As per CR 419 for mantis #19676, Two APIs
 *                         'Port_SetPinDefaultDirection' and
 *                         'Port_SetPinDefaultMode' are added for ID Macros and
 *                         function prototype.
 *                         2. SWS Requirements are mapped.
 *
 * V1.5.1:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, SWS Requirements are mapped.
 *
 * V1.5.2:  22-Aug-2014  : As per CR 570, MISRA C Rule Violations are added as
 *                         QAC 8.1.1.
 * V1.5.3:  28-Jan-2015  : As per mantis #24335,#23568
 *                         1.Alternative modes are added to Port_SetPinMode()API
 *                         2.Port_Cfg.h is included.
 *                         3.Copyright information is updated.
 */
/******************************************************************************/
#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**      To support different AUTOSAR releases in a single package             **
*******************************************************************************/
#define PORT_AR_FOUR_ZERO_THREE    403
#define PORT_AR_THREE_TWO_TWO      322

#define PORT_AR_HIGHER_VERSION     PORT_AR_FOUR_ZERO_THREE
#define PORT_AR_LOWER_VERSION      PORT_AR_THREE_TWO_TWO

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* To publish the standard types */
#include "Std_Types.h"
/* To include pre compile values and switches */
#include "Port_Cfg.h"
/* To publish the type Port_ConfigType */
#include "Port_Types.h"
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* Only in case of DET enabled, Debug variables will be available externally */
#include "Port_Debug.h"
#endif
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* Version identification */
#define PORT_VENDOR_ID              PORT_VENDOR_ID_VALUE
#define PORT_MODULE_ID              PORT_MODULE_ID_VALUE
#define PORT_INSTANCE_ID            PORT_INSTANCE_ID_VALUE

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION) /* START of PORT_AR_VERSION */
/* Functionality related to R4.0 */
/* TRACE [R3, PORT114] */
/* TRACE [R4, PORT114] */
/* AUTOSAR release version information */
#define PORT_AR_RELEASE_MAJOR_VERSION    4
#define PORT_AR_RELEASE_MINOR_VERSION    0
#define PORT_AR_RELEASE_REVISION_VERSION 3

#elif(PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* TRACE [R3, PORT114] */
/* TRACE [R4, PORT114] */
/* Functionality related to R3.2 */
/* AUTOSAR release version information */
#define PORT_AR_MAJOR_VERSION    3
#define PORT_AR_MINOR_VERSION    2
#define PORT_AR_PATCH_VERSION    0

#endif

/* Module Software version information */
#define PORT_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION_VALUE
#define PORT_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION_VALUE
#define PORT_SW_PATCH_VERSION    PORT_SW_PATCH_VERSION_VALUE
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3458) Macro defines a braced code statement block.      */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : Since GetVersionInfo API is implemented as macro braces    */
/*                 cannot be avoided.                                         */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3458)-1 and END Msg(4:3458)-1         */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3684) Array declared with unknown size.      */
/*Rule           : MISRA-C:2004 Rule 1.2                                      */
/*Justification  : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3684)-2 and END Msg(4:3684)-2         */
/*                 tags in the code.                                          */
/******************************************************************************/

/*******************************************************************************
**                      API service ID Macros                                 **
*******************************************************************************/
/* Service ID for PORT Initialization */
#define PORT_INIT_SID                            (uint8)0x00
/* Service ID for setting the Direction of PORT Pin */
#define PORT_SET_PIN_DIR_SID                     (uint8)0x01
/* Service ID for refreshing the Direction of PORT Pin */
#define PORT_REFRESH_PORT_DIR_SID                (uint8)0x02
/* Service ID for PORT getting Version Information */
#define PORT_GET_VERSION_INFO_SID                (uint8)0x03
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_PIN_MODE_SID                    (uint8)0x04
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_TO_DIO_MODE_SID                 (uint8)0x05
/* Service ID for setting the Mode of PORT Pin */
#define PORT_SET_TO_ALT_MODE_SID                 (uint8)0x06
/* Service ID for setting the Default Mode of PORT Pin */
#define PORT_SET_PIN_DEFAULT_MODE_SID            (uint8)0x07
/* Service ID for setting the Default Direction of PORT Pin */
#define PORT_SET_PIN_DEFAULT_DIR_SID             (uint8)0x08


/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* Development error values are of type uint8 */
/* TRACE [R3, PORT116] */
/* TRACE [R4, PORT116] */

/* DET error type, values and related error codes */
/* TRACE [R3, PORT051] */
/* TRACE [R4, PORT116] */

/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                         (uint8)0x0A

/* Port Pin Direction not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE            (uint8)0x0B

/* API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                      (uint8)0x0C

/* When valid Mode is not available */
#define PORT_E_PARAM_INVALID_MODE                (uint8)0x0D

/* When valid Mode is not configured as changeable  */
#define PORT_E_MODE_UNCHANGEABLE                 (uint8)0x0E

/* When PORT APIs are invoked before PORT Module Initialization */
#define PORT_E_UNINIT                            (uint8)0x0F

/* When valid Database is not available */
#define PORT_E_INVALID_DATABASE                  (uint8)0xEF

/* Alternative modes for Port_SetPinMode() API */
#define APP_ALT1_OUT                 (Port_PinModeType)0x02
#define APP_ALT1_IN                  (Port_PinModeType)0x03
#define APP_ALT2_OUT                 (Port_PinModeType)0x04
#define APP_ALT2_IN                  (Port_PinModeType)0x05
#define APP_ALT3_OUT                 (Port_PinModeType)0x06
#define APP_ALT3_IN                  (Port_PinModeType)0x07
#define APP_ALT4_OUT                 (Port_PinModeType)0x08
#define APP_ALT4_IN                  (Port_PinModeType)0x09
#define APP_ALT5_OUT                 (Port_PinModeType)0x0A
#define APP_ALT5_IN                  (Port_PinModeType)0x0B
#define APP_ALT6_OUT                 (Port_PinModeType)0x0C
#define APP_ALT6_IN                  (Port_PinModeType)0x0D
#define APP_ALT7_OUT                 (Port_PinModeType)0x0E
#define APP_ALT7_IN                  (Port_PinModeType)0x0F

#define APP_ALT1_OUT_SET_PIPC        (Port_PinModeType)0x82
#define APP_ALT1_IN_SET_PIPC         (Port_PinModeType)0x83
#define APP_ALT2_OUT_SET_PIPC        (Port_PinModeType)0x84
#define APP_ALT2_IN_SET_PIPC         (Port_PinModeType)0x85
#define APP_ALT3_OUT_SET_PIPC        (Port_PinModeType)0x86
#define APP_ALT3_IN_SET_PIPC         (Port_PinModeType)0x87
#define APP_ALT4_OUT_SET_PIPC        (Port_PinModeType)0x88
#define APP_ALT4_IN_SET_PIPC         (Port_PinModeType)0x89
#define APP_ALT5_OUT_SET_PIPC        (Port_PinModeType)0x8A
#define APP_ALT5_IN_SET_PIPC         (Port_PinModeType)0x8B
#define APP_ALT6_OUT_SET_PIPC        (Port_PinModeType)0x8C
#define APP_ALT6_IN_SET_PIPC         (Port_PinModeType)0x8D
#define APP_ALT7_OUT_SET_PIPC        (Port_PinModeType)0x8E
#define APP_ALT7_IN_SET_PIPC         (Port_PinModeType)0x8F
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* TRACE [R4, PORT201] */
/* Type definition for Port_PinType used by the API Port_SetPinDirection() */
/* TRACE [R3, PORT013][R4, PORT013] */
/* TRACE [R4, PORT219] */
typedef uint16 Port_PinType;

/* Type definition for Port_PinDirectionType used by the API
 * Port_SetPinDirection()
 */
/* TRACE [R3, PORT046][R4, PORT046] */
typedef enum ETag_Port_PinDirectionType
{
  /* The type Port_PinDirectionType shall be of enumeration type */
  /* TRACE [R4, PORT220] */
  PORT_PIN_OUT,
  PORT_PIN_IN
} Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the API
 * Port_SetPinMode()
 */
/* TRACE [R3, PORT124][R4, PORT124] */
/* TRACE [R4, PORT221] */
typedef uint8 Port_PinModeType;


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* External Declaration for Port Initialization API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_Init
           (P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr);

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDirection
                     (Port_PinType Pin, Port_PinDirectionType Direction);
#endif

#if (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDefaultDirection
                                  (Port_PinType Pin);
#endif

#if (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON)
/* External Declaration for Port Set pin direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_SetPinDefaultMode
                                  (Port_PinType Pin);
#endif

/* External Declaration for Port refresh port direction API. */
extern FUNC(void, PORT_PUBLIC_CODE) Port_RefreshPortDirection(void);

#if (PORT_VERSION_INFO_API == STD_ON)

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* Port_GetVersionInfo shall return the version information of the module */
/* TRACE [R4, PORT102] */
/* TRACE [R4, PORT144] */
#define Port_GetVersionInfo(versioninfo) \
 { \
   (versioninfo)->vendorID = (uint16)PORT_VENDOR_ID; \
   (versioninfo)->moduleID = (uint16)PORT_MODULE_ID; \
   (versioninfo)->sw_major_version = PORT_SW_MAJOR_VERSION; \
   (versioninfo)->sw_minor_version = PORT_SW_MINOR_VERSION; \
   (versioninfo)->sw_patch_version = PORT_SW_PATCH_VERSION; \
 }

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Port_GetVersionInfo shall return the version information of the module */
/* MISRA Violation: START Msg(4:3458)-1 */
/* TRACE [R3, PORT102] */
/* TRACE [R4, PORT144] */
#define Port_GetVersionInfo(versioninfo) \
 { \
   (versioninfo)->vendorID = (uint16)PORT_VENDOR_ID; \
   (versioninfo)->moduleID = (uint16)PORT_MODULE_ID; \
   (versioninfo)->instanceID = (uint8)PORT_INSTANCE_ID; \
   (versioninfo)->sw_major_version = PORT_SW_MAJOR_VERSION; \
   (versioninfo)->sw_minor_version = PORT_SW_MINOR_VERSION; \
   (versioninfo)->sw_patch_version = PORT_SW_PATCH_VERSION; \
 }
/* END Msg(4:3458)-1 */
#endif
#endif /*(PORT_VERSION_INFO_API == STD_ON)*/

#if (PORT_SET_PIN_MODE_API == STD_ON)
/* External Declaration for Port set pin mode API. */
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
                                   (Port_PinType Pin, Port_PinModeType Mode);
#endif

#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
extern FUNC (void, PORT_PUBLIC_CODE) Port_SetToDioMode (Port_PinType Pin);

extern FUNC (void, PORT_PUBLIC_CODE) Port_SetToAlternateMode (Port_PinType Pin);
#endif

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define PORT_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"
/* External Declaration for Port database configuration set. */
/* MISRA Violation: START Msg(4:3684)-2 */
/* Structure for PORT Init configuration */
extern CONST(Port_ConfigType, PORT_CONST) Port_GstConfiguration[];
/* END Msg(4:3684)-2 */

#define PORT_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#endif /* PORT_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
