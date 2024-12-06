/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API implementations of Dio Driver Component.            */
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
 * V1.0.0:  23-Aug-2012  : Initial Version.
 *
 * V1.0.1:  17-Sep-2012  : As per SCR 013, following changes are made.
 *                        1. Updated the pointer assignment for INPUT port
 *                           groups for API's Dio_ReadPort,  Dio_ReadChannel
 *                           and Dio_ReadChannelGroup.
 *                        2. Det Error report is updated for the API's
 *                           Dio_WriteChannel, Dio_FlipChannel,
 *                           Dio_WriteChannelGroup, Dio_ReadChannelGroup.
 *                        3. Added the Pre-compile option
 *                           'DIO_MASKED_WRITE_PORT_API' for API
 *                           Dio_MaskedWritePort.
 *                        4. Updated the Alignment
 *
 * V1.0.2:  20-Oct-2012  : As per SCR 025, following change is made.
 *                         1.INPUT Port is checked with PortTypes instead of
 *                           PortId in API Dio_MaskedWritePort and
 *                           Dio_WritePort.
 *                         2.Precompilation option is corrected for port
 *                           pointer variable in API Dio_MaskedWritePort
 *                           and Dio_WritePort.
 *
 * V1.0.3:  06-Mar-2013  : As per SCR 095, the following changes are made.
 *                          1.Software version macros are hardcoded
 *                            and software patch version is updated.
 *                          2.Copyright information is updated.
 *
 * V1.0.4:  15-Apr-2013  : As per SCR 139 and mantis #9729 and #8153, the
 *                         following changes are made.
 *                          1.Removed the Pre-compile option
 *                            for API Dio_MaskedWritePort.
 *                          2.Removed the macro DIO_C_SW_PATCH_VERSION.
 *                          3.Version check information comment is updated
 *                            for lower version.
 *
 * V1.0.5:  13-Jun-2013  : As per SCR 184, the following changes are made.
 *                         1.#endif is corrected for precompile option
 *                           DIO_CHANNEL_CONFIGURED == STD_ON for
 *                           Dio_FlipChannel API.
 *
 * V1.0.6:  31-Jul-2013  : As per CR 224 and Mantis #13447, the following
 *                         changes are made.
 *                         1.MISRA C rule violation comment is added for
 *                           Msg(7:3347)-3.
 *
 * V1.0.7:  08-Aug-2013  : As per CR 225, Device name and Project name are
 *                         updated as part of merge activity.
 *
 * V1.0.8:  17-Sep-2013  : As per CR 241 and mantis 12996, memory class for
 *                         P2CONST is updated.
 *
 * V1.0.9:  28-Oct-2013  : As per CR 286 and mantis #14560, backslash is
 *                         removed from code.
 *
 * V1.0.10: 04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.11: 05-Mar-2014  : As per CR 428, following changes are made.
 *                         1.Critical section protection is added.
 *                         2.Function header is updated.
 *                         3.Dio_FlipChannel, Dio_WriteChannel, Dio_WritePort
 *                           Dio_MaskedWritePort and Dio_WriteChannelGroup API
 *                           are updated to add channel mode check.
 *                         4.MISRA C rule violation comment is added for
 *                           (4:3792)-4.
 *
 * V1.0.12: 14-May-2014 :  As per CR 488, following changes are done.
 *                         1.Variable name ucModeMask is updated as ulModeMask.
 *                         2.Initialization is done for variable LddPortLevel
 *                           in Dio_FlipChannel API to fix polyspace warning.
 *                         3.MISRA C rule violation comment is removed for
 *                           Msg(7:3347)-3 and (4:3792)-4.
 *                         4.Dio_WritePort and Dio_MaskedWritePort API are
 *                           updated for channel mode check.
 *
 * V1.0.13: 19-Jun-2014 : As per CR 519, comments are provided to check channel
 *                        is output channel.
 *
 * V1.0.14: 10-Jul-2014 : As per CR 545 and mantis 21387, Alignment is
 *                        corrected and no operation required is replaced by
 *                        No Action Required.
 *
 * V1.0.15: 28-Jul-2014  : As per CR 564 and mantis #21425, Dio_MaskedWritePort
 *                         and Dio_WritePort API are updated for write operation
 *                         to PSR register.
 *
 * V1.0.16: 06-Aug-2014  : As per mantis #22811, following changes are made.
 *                         1.Dio_ReadChannelGroup and Dio_WriteChannelGroup
 *                           API's are updated for DET error with
 *                           DIO_E_PARAM_INVALID_GROUP_ID Error.
 *                         2.Code is updated for Renesas C coding Guidelines.
 *
 * V1.0.17: 20-Aug-2014  : As per mantis #22624 and CR569 following changes are
 *                         made:
 *                         1.Dio_ReadPort, Dio_ReadChannel, Dio_ReadChannelGroup
 *                           and Dio_FlipChannel API's are updated for
 *                           typecasting.
 *                         2.Dio_FlipChannel API is updated to make PNOT and
 *                           JPNOT registers as read only.
 *                         3.Extra space present before == is removed.
 *                         4.MISRA C rule violation comment is added for
 *                           (4:0491)-3, (4:0317), (4:4397) and (4:2982)-4.
 *
 * V1.0.18: 08-Oct-2014  : As per mantis #23838, following changes are made:
 *                         1. MISRA C rule violation comment is added for
 *                            (4:0492)-6.
 *                         2. MISRA C rule violation comment is deleted for
 *                            (4:2982)-4.
 *                         3. DET Pre compile check is added for
 *                            "LddPortLevel = DIO_ZERO" in Dio_ReadPort and
 *                            Dio_ReadChannelGroup.
 *
 * V1.0.19: 19-Dec-2014  : As per mantis #24331,#24772,#23962,#25154,#25111
 *                         following changes are made:
 *                         1. Dio_WriteChannelGroup(),Dio_WriteChannel() are
 *                            updated by removing local variable 'LusMask'.
 *                         2. Dio_ReadChannelGroup and Dio_WriteChannelGroup
 *                            is updated by adding NULL check.
 *                         3. Functions Dio_WritePort, Dio_WriteChannel,
 *                            Dio_WriteChannelGroup, Dio_MaskedWritePort are
 *                            Updated for JTAG address calculation.
 *                         4. Dio_WriteChannelGroup() is updated for the
 *                            requirement DIO040.
 *                         5. 'REGISTER_PROTECTION' is Changed to
 *                            'DIO_REGISTER_PROTECTION'.
 * V1.0.20: 02-Feb-2015  : As part of merging activity(mantis #26024)
 *                         following changes are made:
 *                         1. Volatile declaration is added for LpPortAddress
 *                            to consider the compiler optimization.
 *                         2. Copyright information is updated.
 * V1.0.21: 25-Feb-2015  :As per the Mantis ticket #26450, the following changes
 *                         are made:
 *                         1.Critical section protection is extended for
 *                         Dio_WritePort(),Dio_WriteChannel(),Dio_FlipChannel(),
 *                         Dio_WriteChannelGroup()and Dio_MaskedWritePort().
 *                         2. MISRA justfications added.
 *                         3. Fixed the MISRA warning.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for macro definitions and API prototypes */
#include "Dio.h"
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Included for macro definitions and structure declarations */
#include "Dio_PBTypes.h"
/* Included for RAM variable declarations */
#include "Dio_Ram.h"
/*DIO_AR_VERSION */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Included for macro definitions and structure declarations */
#include "Dio_LTTypes.h"
#endif
/*END of DIO_AR_VERSION */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Det.h"
#endif
#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
#include "SchM_Dio.h"
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* AUTOSAR release version information */
#define DIO_C_AR_RELEASE_MAJOR_VERSION     DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_C_AR_RELEASE_MINOR_VERSION     DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_C_AR_RELEASE_REVISION_VERSION  DIO_AR_RELEASE_REVISION_VERSION_VALUE
/* DIO_AR_VERSION */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* AUTOSAR specification version information */
#define DIO_C_AR_MAJOR_VERSION    DIO_AR_MAJOR_VERSION_VALUE
#define DIO_C_AR_MINOR_VERSION    DIO_AR_MINOR_VERSION_VALUE
#define DIO_C_AR_PATCH_VERSION    DIO_AR_PATCH_VERSION_VALUE
#endif
/* END of DIO_AR_VERSION */
/* Software version information */
#define DIO_C_SW_MAJOR_VERSION    1
#define DIO_C_SW_MINOR_VERSION    0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* TRACE [R4, DIO106] */
#if (DIO_AR_RELEASE_MAJOR_VERSION != DIO_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Release Major Version"
#endif

/* TRACE [R4, DIO106] */
#if (DIO_AR_RELEASE_MINOR_VERSION != DIO_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio.c : Mismatch in Release Minor Version"
#endif

#if (DIO_AR_RELEASE_REVISION_VERSION != DIO_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio.c : Mismatch in Release Revision Version"
#endif

#if (DIO_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Software Major Version"
#endif

#if (DIO_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION)
  #error "Dio.c : Mismatch in Software Minor Version"
#endif
/*  DIO_AR_VERSION  */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* TRACE [R3, DIO106] */
#if (DIO_AR_MAJOR_VERSION != DIO_C_AR_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Specification Major Version"
#endif

 /* TRACE [R3, DIO106] */
#if (DIO_AR_MINOR_VERSION != DIO_C_AR_MINOR_VERSION)
  #error "Dio.c : Mismatch in Specification Minor Version"
#endif

 /* TRACE [R3, DIO106] */
#if (DIO_AR_PATCH_VERSION != DIO_C_AR_PATCH_VERSION)
  #error "Dio.c : Mismatch in Specification Patch Version"
#endif

 /* TRACE [R3, DIO106] */
#if (DIO_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION)
  #error "Dio.c : Mismatch in Software Major Version"
#endif

 /* TRACE [R3, DIO106] */
#if (DIO_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION)
  #error "Dio.c : Mismatch in Software Minor Version"
#endif

#endif
/* END of DIO_AR_VERSION */
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : For accessing 32-bit PSR register separately for lower     */
/*                 16-bit data and upper 16-bit mask.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0759)-1 and                           */
/*                 END Msg(4:0759)-1 tags in the code.                        */

/******************************************************************************/
/* 2. MISRA C RULE VIOLATION:                                                 */
 /* Message       : (4:0310) Casting to different object pointer type.        */
 /* Rule          : MISRA-C:2004 Rule 11.4                                    */
 /*                 REFERENCE - ISO-6.3.4 Cast Operators                      */
 /* Justification : For accessing 8-bit and 16-bit PNOT, PPR JTAG and JPNOT,  */
 /*                 PPR JTAG register respectively, the 32-bit pointer is     */
 /*                 typecasted.                                               */
 /* Verification  : However, part of the code is verified manually and it is  */
 /*                 not having any impact.                                    */
 /* Reference     : Look for START Msg(4:0310)-2 and                          */
 /*                 END Msg(4:0310)-2 tags in the code.                       */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0491) Array subscripting applied to an object of        */
/*                 pointer type.                                              */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0491)-3 and                           */
/*                 END Msg(4:0491)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0317) [I] Implicit conversion from a pointer to void to */
/*                 a pointer to object type.                                  */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the type*/
/*                 to the upper layer                                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0317)-4 and                           */
/*                 END Msg(4:0317)-4 tags in the code.                        */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool as an      */
/*                 indirect result of integral promotion in complex bitwise   */
/*                 operations.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4397)-5 and                           */
/*                 END Msg(4:4397)-5 tags in the code.                        */

/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0492) Array subscripting applied to a function parameter*/
/*                 declared as a pointer.                                     */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0492)-6 and                           */
/*                 END Msg(4:0492)-6 tags in the code.                        */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3138) Null statement is located close to other code or  */
/*                 comments..                                                 */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-7 and                           */
/*                 END Msg(4:3138)-7 tags in the code.                        */

/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2985) Null statement is located close to other code or  */
/*                 comments..                                                 */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Minimisation of run-time failures shall be ensured by the  */
/*                 use of at least one of (a) static analysis                 */
/*                 tools/techniques; (b) dynamic analysis tools/techniques;   */
/*                 (c) explicit coding of checks to handle run-time faults.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2985)-8 and                           */
/*                 END Msg(4:2985)-8 tags in the code.                        */
/******************************************************************************/
/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'.                                                   */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always false since */
/*                 only one job is configured. However, when two or more jobs */
/*                 are configured this warning ceases to exist.               */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-9 and                           */
/*                 END Msg(4:2996)-9 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name         : Dio_Init
**
** Service ID            : 0x10
**
** Description           : This service initialize the DIO driver.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr Pointer to the configuration
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Dio_GusNoOfChannelGroups, Dio_GpPortGroup,
**                         Dio_GpPortChannel, Dio_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : None
*******************************************************************************/
/* START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R4, DIO166] */
/* TRACE [R4, DIO165] */
/* Implementation Of Dio_Init API */
FUNC(void, DIO_PUBLIC_CODE) Dio_Init
(P2CONST(Dio_ConfigType, DIO_VAR, DIO_APPL_CONST) ConfigPtr)
{
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Report Error to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO176] */
    /* TRACE [R4, DIO167] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
     DIO_E_PARAM_CONFIG);
  }
  else
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether the existing database is correct */
    /* MISRA Violation: START Msg(4:4397)-5 */
    if (DIO_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(4:4397)-5 */
    {
      /* Initialize the Port group configuration global pointer */
      /* MISRA Violation: START Msg(4:0317)-4 */
      Dio_GpPortGroup = ConfigPtr->pPortGroup;
      /* END Msg(4:0317)-4 */
      #if (DIO_CHANNEL_CONFIGURED == STD_ON)
      /* Initialize the Port channel configuration global pointer */
      /* MISRA Violation: START Msg(4:0317)-4 */
      Dio_GpPortChannel = ConfigPtr->pPortChannel;
      /* END Msg(4:0317)-4 */
      #endif
      #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
      /* TRACE [R3, DIO056][R4, DIO056] */
      /* Initialize the config pointer value to global pointer */
      Dio_GusNoOfChannelGroups = ConfigPtr->usNoofChannelGroups;
      #endif
      #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* Set the state of DIO Driver as initialized */
      Dio_GblDriverStatus = DIO_INITIALIZED;
      #endif
    }

    else
    {
      #if (DIO_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
       DIO_E_INVALID_DATABASE);
      #endif
    } /* End of Check to check database */
  }
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif
/*END of DIO_AR_VERSION */

/*******************************************************************************
** Function Name         : Dio_ReadPort
**
** Service ID            : 0x02
**
** Description           : This service returns the level of all channels of
**                         given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Returns the value of physical level of the channels
**                         that form the Port.
**
** Preconditions         : R3.2 : None
**                         R4.0 : DIO Driver must be initialized.
**
** Global Variables Used :  Dio_GpPortGroup.
**                          R4.0: Dio_GblDriverStatus
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : PPRn, JPPRn, APPRn, IPPRn
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R3, DIO012][R4, DIO012] */
/* TRACE [R3, DIO013] */
/* TRACE [R3, DIO135][R4, DIO135] */
/* Implementation Of Dio_ReadPort API */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadPort(Dio_PortType PortId)
{
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType LenDetErrFlag;
  #endif

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Initialize the return value to 0 */
  LddPortLevel = DIO_ZERO;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  LenDetErrFlag = E_NOT_OK;
  /* START of DIO_AR_VERSION */
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_READ_PORT_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  /* END of DIO_AR_VERSION */
  /* Check whether the Port Id is out of range */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO177] */
    /* TRACE [R3, DIO065][R4, DIO065] */
    /* TRACE [R3, DIO075][R4, DIO075] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* TRACE [R3, DIO118][R4, DIO118] */
  /* MISRA Violation: START Msg(4:2996)-9 */
  /* Check if no DET error was reported */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2996)-9 */
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the required Port */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(4:0491)-3 */

    /* Get the PSRn or JPSRn address for the required port */
    LpPortAddress = LpPortGroup->pPortAddress;

    /* Check if the required port is Numeric/ AlphaNumeric/ Analog port */
    if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO104][R4, DIO104] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /*
      * Read the port value from PPR register by adding offset to
      * PSR register address of Numeric/Alphabetic/ Analog Port
      */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */
    }
  /* Check if the required port is JTAG port */
    else if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO104][R4, DIO104] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /*
      * Read the port value from JPPR register by adding offset to
      * PSR register address of JTAG Port
      */
       /* MISRA Violation: START Msg(4:0310)-2 */
       /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortLevel =
               (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
       /* END Msg(4:0310)-2 */
       /* END Msg(4:0491)-3 */
    }
    else
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO104][R4, DIO104] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /* Read the port value from IPPR register  */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
             (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                                                LpPortAddress));
      /* END Msg(4:0310)-2 */
    }
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  /* TRACE [R3, DIO031][R4, DIO031] */
  /* Return the Port Level */
  return(LddPortLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Dio_WritePort
**
** Service ID            : 0x03
**
** Description           : This service writes the specified level to all the
**                         channels in given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : R3.2 : None
**                         R4.0 : DIO Driver must be initialized.
**
** Global Variables Used :  Dio_GpPortGroup.
**                          R4.0 : Dio_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, APSRn, PMSRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R3, DIO034][R4, DIO034] */
/* TRACE [R3, DIO064][R4, DIO064] */
/* TRACE [R3, DIO007][R4, DIO007] */
/* TRACE [R3, DIO136][R4, DIO136] */
/* Implementation of the Dio_WritePort API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WritePort
(Dio_PortType PortId, Dio_PortLevelType Level)
{
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LddPortModeLevel;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* START of DIO_AR_VERSION */
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_WRITE_PORT_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  /* END of DIO_AR_VERSION */
  /* Check whether the Port Id is out of range */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO177] */
    /* TRACE [R3, DIO075][R4, DIO075] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                             DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LenDetErrFlag = E_OK;
  }
   else
  {
     /* No action required */
  }
  /* TRACE [R3, DIO119][R4, DIO119] */
  /* Check whether the PortType is INPUT port */
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the required Port */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(4:0491)-3 */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* TRACE [R4, DIO177] */
      /* TRACE [R3, DIO075][R4, DIO075] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                             DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
     /* No action required */
  }

  /* TRACE [R3, DIO119][R4, DIO119] */
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Port */
    /* MISRA Violation: START Msg(4:0491)-3 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(4:0491)-3 */
    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    LpPortAddress = LpPortGroup->pPortAddress;
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    if(DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                        &LpPortAddress[DIO_PMSR_OFFSET_JTAG])) |
                                                       (LpPortGroup->ulModeMask);
        /* END Msg(4:0491)-3 */
    }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                     &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG])) |
                                                       (LpPortGroup->ulModeMask);
        /* END Msg(4:0491)-3 */
    }
    else
    {
        LddPortModeLevel = (uint32)DIO_ZERO;
    }
    /* TRACE [R3, DIO035][R4, DIO035] */
    /* TRACE [R3, DIO004][R4, DIO004] */
    /* TRACE [R3, DIO108][R4, DIO108] */
    /* If the requested channel is an output Channel */
    if (DIO_ZERO != (~LddPortModeLevel))
    {
      /* TRACE [R3, DIO105][R4, DIO105] */
      /*
      * Write the Port value using 32-bit PSR register
      * Enable upper 16-bits using mask to effectively write to lower 16-bits
      */

      /* MISRA Violation: START Msg(4:3138)-7 */
      *(LpPortGroup->pPortAddress) =
               (uint32)(Level | (~(LddPortModeLevel) << DIO_SHIFT_SIXTEEN));
     /* END Msg(4:3138)-7 */
    }
    else
    {
      /* No action required */
    }
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Dio_ReadChannel
**
** Service ID            : 0x00
**
** Description           : This service returns the value of the specified
**                         DIO Channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
**                         physical level of the Pin
**
** Preconditions         : R3.2 : None
**                         R4.0 : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GblDriverStatus, Dio_GpPortChannel,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : PPRn, JPPRn, APPRn, IPPRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R3, DIO012][R4, DIO012] */
/* TRACE [R3, DIO011][R4, DIO011] */
/* TRACE [R3, DIO133][R4, DIO133] */
/* Implementation of the Dio_ReadChannel API */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_ReadChannel(Dio_ChannelType ChannelId)
{
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2CONST(Dio_PortChannel, DIO_VAR, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;
  #endif
  Dio_LevelType LddLevel;
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* MISRA Violation: START Msg(4:2982)-4 */
  LenDetErrFlag = E_NOT_OK;
  /* END Msg(4:2982)-4 */
  #endif

  /* TRACE [R3, DIO089][R4, DIO089] */
  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*START of DIO_AR_VERSION */
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  #endif
  /*END of DIO_AR_VERSION */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether the Channel Id is out of range */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  #endif
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO175] */
    /* TRACE [R3, DIO065][R4, DIO065] */
    /* TRACE [R3, DIO074][R4, DIO074] */
    /* Report Error to DET */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LenDetErrFlag = E_OK;
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:2996)-9 */
  /* TRACE [R3, DIO118][R4, DIO118] */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2996)-9 */
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if at least one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the required Channel */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the Port Address from Port to which the Channel belongs */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(4:0491)-3 */

    LpPortAddress = LpPortGroup->pPortAddress;

    /* Check if the required port is JTAG port */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /*
       * Read the port value from JPPR register by adding offset to
       * PSR register address of JTAG Port
       */
       /* MISRA Violation: START Msg(4:0310)-2 */
       /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
       /* END Msg(4:0491)-3 */
       /* END Msg(4:0310)-2 */

    }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address of Numeric/Alphabetic/Analog Port
       */
      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                      &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(4:0491)-3 */
      /* END Msg(4:0310)-2 */
    }
    else
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /* Read the port value from IPPR register */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
             (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                                                LpPortAddress));
      /* END Msg(4:0310)-2 */
    }
    /*
     * Mask the port level value for required Channel bit position and
     * clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* Check whether value is not equal to zero */
    if (DIO_ZERO != LddPortLevel)
    {
      /* TRACE [R3, DIO089][R4, DIO089] */
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
    #endif
    /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  /* TRACE [R3, DIO027][R4, DIO027] */
  /* Return the Channel Level */
  return LddLevel;
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Dio_WriteChannel
**
** Service ID            : 0x01
**
** Description           : This service writes the given value into the
**                         specified DIO Channel.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelId and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : R3.2 : None
**                         R4.0 : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GblDriverStatus, Dio_GpPortChannel,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, APSRn, PMSRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R3, DIO064][R4, DIO064] */
/* TRACE [R3, DIO006][R4, DIO006] */
/* TRACE [R3, DIO134][R4, DIO134] */
/* Implementation of the Dio_WriteChannel API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannel
(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2CONST(Dio_PortChannel, DIO_VAR, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LddPortModeLevel;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Dio_PortData LunPSRContent;
  /* END Msg(4:0759)-1 */

  #endif
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* MISRA Violation: START Msg(4:2982)-4 */
  LenDetErrFlag = E_NOT_OK;
  /* END Msg(4:2982)-4 */
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*START of DIO_AR_VERSION */
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  #endif
  /* END of DIO_AR_VERSION */
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether the Channel Id is out of range */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  #endif
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R3, DIO074][R4, DIO074] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LenDetErrFlag = E_OK;
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* TRACE [R3, DIO119][R4, DIO119] */
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the Port Channel */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to port group to which the channel belongs */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(4:0491)-3 */

    /* Check if the required port is INPUT port */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* TRACE [R4, DIO177] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }
  #endif

  /* TRACE [R3, DIO119][R4, DIO119] */
  /* MISRA Violation: START Msg(4:2996)-9 */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2996)-9 */
  #endif  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if at least one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the Port Channel */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to port group to which the channel belongs */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(4:0491)-3 */

    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    /*
     * Enable appropriate Channel position by writing
     * upper 16bits of PSR register
     */
    LunPSRContent.Tst_WordValue.usMSWord = LpPortChannel->usMask;

    /* Check if the input level value is ZERO */
    if (STD_LOW == Level)
    {
      /*
       * Make the Channel value as ZERO by writing
       * lower 16-bits of PSR register
       */
      LunPSRContent.Tst_WordValue.usLSWord = DIO_ZERO;
    }
    else
    {
      /*
       * Make the Channel value as ONE by writing
       * lower 16-bits of PSR register
       */
      LunPSRContent.Tst_WordValue.usLSWord = LpPortChannel->usMask;
    }
    LpPortAddress = LpPortGroup->pPortAddress;
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    if(DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PMSR_OFFSET_JTAG]))
                                       & LpPortChannel->usMask;
        /* END Msg(4:0491)-3 */
    }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG]))
                                       & LpPortChannel->usMask;
        /* END Msg(4:0491)-3 */
    }
    else
    {
        LddPortModeLevel = (uint32)DIO_ZERO;
    }

    /* TRACE [R3, DIO029][R4, DIO029] */
    /* TRACE [R3, DIO079][R4, DIO079] */
    /* TRACE [R3, DIO070][R4, DIO070] */
    /* TRACE [R3, DIO028][R4, DIO028] */
    /* If the specified channel is configured as an output channel */
    if (DIO_ZERO == LddPortModeLevel)
    {
      /* Load 32 bit value to PSR register */

      /* MISRA Violation: START Msg(4:3138)-7 */
      *(LpPortGroup->pPortAddress) = LunPSRContent.ulLongWord;
      /* END Msg(4:3138)-7 */
    }
    else
    {
      /* No action required */
    }
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    #endif
    /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Dio_FlipChannel
**
** Service ID            : 0x11
**
** Description           : This service flip the level of a channel and return
**                         the level of the channel after flip.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelId
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Dio_LevelType - STD_HIGH/STD_LOW depending on the
**                         physical level of the Pin.
**
** Preconditions         : R4.0 : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GblDriverStatus, Dio_GpPortChannel,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PNOTn, JPNOTn, APNOTn, PPRn, JPPRn, APPRn, PMSRn,
**                         JPMSR.
*******************************************************************************/

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

#if (DIO_FLIP_CHANNEL_API == STD_ON)

#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, DIO190] */
/* Implementation Of Dio_FlipChannel API */
FUNC(Dio_LevelType, DIO_PUBLIC_CODE) Dio_FlipChannel(Dio_ChannelType ChannelId)
{
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2CONST(Dio_PortChannel, DIO_VAR, DIO_PRIVATE_CONST) LpPortChannel;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  Dio_PortLevelType LddPortLevel;
  uint32 LddPortModeLevel;
  #endif
  Dio_LevelType LddLevel;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif

  /* TRACE [R3, DIO089][R4, DIO089] */
  /* Initialize the return value to STD_LOW */
  LddLevel = STD_LOW;

  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  LddPortLevel = STD_LOW;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  /* Check whether the Channel Id is out of range */
  if (DIO_MAXNOOFCHANNEL <= ChannelId)
  #endif
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R3, DIO074][R4, DIO074] */
    /* Report Error to DET */
    (void) Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    LenDetErrFlag = E_OK;
  }
  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  else
  #endif
  {
    /* No action required */
  }

  #if (DIO_CHANNEL_CONFIGURED == STD_ON)
  if (E_NOT_OK == LenDetErrFlag)
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the Port Channel */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to port group to which the channel belongs */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(4:0491)-3 */

    /* TRACE [R4, DIO192] */
    /* TRACE [R4, DIO193] */
    /* Check if the required port is INPUT port */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* TRACE [R4, DIO177] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

  #endif

  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if at least one Channel is configured */
    #if (DIO_CHANNEL_CONFIGURED == STD_ON)

    /* Check whether DIO_DEV_ERROR_DETECT is enabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to the required Channel */
    LpPortChannel = &Dio_GpPortChannel[ChannelId];
    /* END Msg(4:0491)-3 */

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the Port Address in which the Channel is configured */
    LpPortGroup = &Dio_GpPortGroup[LpPortChannel->ucPortIndex];
    /* END Msg(4:0491)-3 */

    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */
    LpPortAddress = LpPortGroup->pPortAddress;
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif

    /* Check if the required port is JTAG port */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PMSR_OFFSET_JTAG]))
                                   & LpPortChannel->usMask;
      /* END Msg(4:0491)-3 */

      /* TRACE [R4, DIO191] */
      /* Check if the Direction of the Channel is output */
      if (DIO_ZERO == LddPortModeLevel)
      {
        /*
         * Write the PNOT register by adding offset to PSR register address
         * for JTAG Port
         */

        /* MISRA Violation: START Msg(4:0310)-2 */
        /* MISRA Violation: START Msg(4:0491)-3 */
        *((volatile uint8 *)((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
        &LpPortAddress[DIO_PNOT_OFFSET_JTAG])) = (uint8)(LpPortChannel->usMask);
        /* END Msg(4:0491)-3 */
        /* END Msg(4:0310)-2 */
      }
      else
      {
        /* No action required */
      }

      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for JTAG Port
       */

      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortLevel =
      (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */

     }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
       /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =  (uint32)
                        (*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG]))
                & LpPortChannel->usMask;
       /* END Msg(4:0491)-3 */

       /* TRACE [R4, DIO191] */
       /* To check channel is output channel*/
       if (DIO_ZERO == LddPortModeLevel)
       {
          /*
          * Write the PNOT register by adding offset to PSR register address
          * for for Numeric/Alphabetic Port
          */
          /* MISRA Violation: START Msg(4:0491)-3 */
          /* MISRA Violation: START Msg(4:0310)-2 */
          *((volatile uint16 *)
          ((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
              &LpPortAddress[DIO_PNOT_OFFSET_NONJTAG])) = LpPortChannel->usMask;
          /* END Msg(4:0491)-3 */
          /* END Msg(4:0310)-2 */
       }
       else
       {
         /* No action required */
       }
      /*
       * Read the port value from PPR register by adding offset to
       * PSR register address for Numeric/Alphabetic Port
       */

      /* MISRA Violation: START Msg(4:0310)-2 */
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */
    }
    else
    {
      /* No Action Required */
    }
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /*
     * Mask the port value for required Channel bit position and
     * clear other bit positions
     */

    LddPortLevel = LddPortLevel & (LpPortChannel->usMask);

    /* TRACE [R4, DIO191] */
    /* Check whether value is not equal to zero */
    if (DIO_ZERO != LddPortLevel)
    {
      /* TRACE [R4, DIO191] */
      /* TRACE [R3, DIO089][R4, DIO089] */
      /* Set the return value to STD_HIGH */
      LddLevel = STD_HIGH;
    }
    else
    {
      /* No action required */
    }
    #endif
    /* (DIO_CHANNEL_CONFIGURED == STD_ON) */
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  /* Return the Channel Level */
  return(LddLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif
/* #if (DIO_FLIP_CHANNEL_API == STD_ON) */

#endif
/*END of DIO_AR_VERSION */
/*******************************************************************************
** Function Name         : Dio_ReadChannelGroup
**
** Service ID            : 0x04
**
** Description           : This service returns the value of the ChannelGroup
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelGroupIdPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : Returns the value of physical level of the Channels
**                         that form the ChannelGroup
**
** Preconditions         : R3.2 : None
**                         R4.0 : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GusNoOfChannelGroups, Dio_GblDriverStatus,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError
**
** Registers Used        : PPRn, JPPRn, APPRn, IPPRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* TRACE [R3, DIO012][R4, DIO012] */
/* TRACE [R3, DIO037][R4, DIO037] */
/* TRACE [R3, DIO137][R4, DIO137] */
/* Implementation of the Dio_ReadChannelGroup API */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_CONFIG_CONST) ChannelGroupIdPtr)

/*  DIO_AR_VERSION  */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* TRACE [R3, DIO012][R4, DIO012] */
/* TRACE [R3, DIO037][R4, DIO037] */
/* TRACE [R3, DIO137][R4, DIO137] */
/* Implementation of the Dio_ReadChannelGroup API */
FUNC(Dio_PortLevelType, DIO_PUBLIC_CODE) Dio_ReadChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr)

#endif
/*END of DIO_AR_VERSION */
{
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_PRIVATE_CONST) LpChannelGroupPtr;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  #endif

  Dio_PortLevelType LddPortLevel;

  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  /* MISRA Violation: START Msg(4:2982)-4 */
  LenDetErrFlag = E_NOT_OK;
  /* END Msg(4:2982)-4 */
  #endif
  #endif

  /* Set the return value to 0 */
   /* MISRA Violation: START Msg(4:2982)-4 */
  LddPortLevel = DIO_ZERO;
  /* END Msg(4:2982)-4 */

  /* Check if at least one ChannelGroup is configured */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*START of DIO_AR_VERSION */
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_READ_CHANNEL_GROUP_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  /* TRACE [R4, DIO188] */
  if (ChannelGroupIdPtr == NULL_PTR)
  {
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* TRACE [R4, DIO178] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                     DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
      LenDetErrFlag = E_OK;
  }
  else
  {
      /* Get the pointer to corresponding index in the
          array Dio_GstChannelGroupData */

      /* MISRA Violation: START Msg(4:0492)-6 */
      LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusNoOfChannelGroups];
      /* END Msg(4:0492)-6 */

      if (LpChannelGroupPtr == NULL_PTR)
      {
          /* Report Error to DET */
          (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                        DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
          LenDetErrFlag = E_OK;
      }
      else
      {
          /* No action required */
      }
  }

  /*  DIO_AR_VERSION  */
  #elif (DIO_AR_VERSION  == DIO_AR_LOWER_VERSION)

  /* Check whether LpChannelGroupPtr is NULL_PTR */
  LpChannelGroupPtr = ChannelGroupIdPtr;

  if (LpChannelGroupPtr == NULL_PTR)
  {
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP_ID);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

  #endif
  /*END of DIO_AR_VERSION */

  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

  /* Get the pointer to corresponding index in the
  array Dio_GstChannelGroupData */

/* MISRA Violation: START Msg(4:0492)-6 */
  LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusNoOfChannelGroups];
/* END Msg(4:0492)-6 */

 #elif (DIO_AR_VERSION  == DIO_AR_LOWER_VERSION)

  LpChannelGroupPtr = ChannelGroupIdPtr;

 #endif /*END of DIO_AR_VERSION */
 #endif

  #if(DIO_DEV_ERROR_DETECT == STD_ON)

  /* MISRA Violation: START Msg(4:2996)-9 */
  /* TRACE [R3, DIO118][R4, DIO118] */
  if (E_NOT_OK == LenDetErrFlag)
  /* END Msg(4:2996)-9 */
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the Port Address in which the Channel is configured */
    LpPortGroup = &Dio_GpPortGroup[LpChannelGroupPtr->ucPortIndex];
    /* END Msg(4:0491)-3 */
    LpPortAddress = LpPortGroup->pPortAddress;

    /* Check if the required port is JTAG port */
    if (DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /* TRACE [R3, DIO014][R4, DIO014] */
      /* Read the port value from PPR register by adding offset to */
      /* PSR register address for JTAG Port
      */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint8 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PPR_OFFSET_JTAG]));
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */

    }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /* TRACE [R3, DIO014][R4, DIO014] */
      /* Read the port value from PPR register by adding offset to */
      /* PSR register address for Numeric/Alphabetic Port          */
      /* MISRA Violation: START Msg(4:0491)-3 */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PPR_OFFSET_NONJTAG]));
      /* END Msg(4:0310)-2 */
      /* END Msg(4:0491)-3 */
    }
    else
    {
      /* TRACE [R3, DIO083][R4, DIO083] */
      /* TRACE [R3, DIO084][R4, DIO084] */
      /* TRACE [R3, DIO014][R4, DIO014] */
      /* Read the port value from IPPR register  */
      /* MISRA Violation: START Msg(4:0310)-2 */
      LddPortLevel =
              (Dio_PortLevelType)(*((P2VAR(uint16 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                                                LpPortAddress));
      /* END Msg(4:0310)-2 */
    }
    /* TRACE [R3, DIO092][R4, DIO092] */
    /*
     * Mask the port value for required ChannelGroup related bit positions
     * and clear other bit positions
     */
    LddPortLevel = LddPortLevel & (LpChannelGroupPtr->usMask);
    /* TRACE [R3, DIO093][R4, DIO093] */
    /* Rotate right to get the corresponding ChannelGroup value */
    LddPortLevel = LddPortLevel >> (LpChannelGroupPtr->ucOffset);
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)

  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  /* TRACE [R3, DIO140][R4, DIO140] */
  /* TRACE [R4, DIO178] */
  /* Report Error to DET */
  (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                       DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
  #elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
  /* TRACE [R3, DIO114][R4, DIO114] */
  (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP_ID);
  #endif /* #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION) */
  #endif /* #if (DIO_DEV_ERROR_DETECT == STD_ON) */

  #endif/* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */

  /* Return the ChannelGroup Level */
  return(LddPortLevel);
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Dio_WriteChannelGroup
**
** Service ID            : 0x05
**
** Description           : This service writes specified level to the
**                         ChannelGroup
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : ChannelGroupIdPtr and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : R3.2 : None
**                         R4.0 : DIO Driver must be initialized.
**
** Global Variables Used : Dio_GusNoOfChannelGroups, Dio_GblDriverStatus,
**                         Dio_GpPortGroup.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, APSRn, PMSRn.
*******************************************************************************/
#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* TRACE [R3, DIO064][R4, DIO064] */
/* TRACE [R3, DIO064][R4, DIO064] */
/* TRACE [R3, DIO039][R4, DIO039] */
/* TRACE [R3, DIO008][R4, DIO008] */
/* TRACE [R3, DIO138][R4, DIO138] */
/* Implementation of the Dio_WriteChannelGroup API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_CONFIG_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level)

/*  DIO_AR_VERSION  */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* TRACE [R3, DIO138][R4, DIO138] */
/* Implementation of the Dio_WriteChannelGroup API */
FUNC(void, DIO_PUBLIC_CODE) Dio_WriteChannelGroup
(CONSTP2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST) ChannelGroupIdPtr,
 Dio_PortLevelType Level)
#endif
/*END of DIO_AR_VERSION */
{
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2CONST(Dio_ChannelGroupType, DIO_VAR, DIO_PRIVATE_CONST) LpChannelGroupPtr;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LddPortModeLevel;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif
  #endif

  /* Check if at least one ChannelGroup is configured */
  #if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*START of DIO_AR_VERSION */
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
  if (DIO_UNINITIALIZED == Dio_GblDriverStatus)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                                DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_UNINIT);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }

/* TRACE [R3, DIO188][R4, DIO188] */
  if (ChannelGroupIdPtr == NULL_PTR)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO178] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* Get the pointer to corresponding index in the
       array Dio_GstChannelGroupData */
    /* MISRA Violation: START Msg(4:0492)-6 */
     LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusNoOfChannelGroups];
    /* END Msg(4:0492)-6 */
      if (NULL_PTR == LpChannelGroupPtr)
      {
        /* Report Error to DET */
        (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
        LenDetErrFlag = E_OK;
      }
      else
      {
        /* No action required */
      }
  }

  /*  DIO_AR_VERSION  */
  #elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

  LpChannelGroupPtr = ChannelGroupIdPtr;
 /* TRACE [R3, DIO188][R4, DIO188] */
  if (NULL_PTR == LpChannelGroupPtr)
  {
    /* TRACE [R3, DIO114][R4, DIO114] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                 DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP_ID);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* No action required */
  }
  #endif
  /*END of DIO_AR_VERSION */
  #elif(DIO_DEV_ERROR_DETECT == STD_OFF)
  #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

  /* Get the pointer to corresponding index in the
  array Dio_GstChannelGroupData */

  /* MISRA Violation: START Msg(4:0492)-6 */
  LpChannelGroupPtr = &ChannelGroupIdPtr[Dio_GusNoOfChannelGroups];
  /* END Msg(4:0492)-6 */

 #elif (DIO_AR_VERSION  == DIO_AR_LOWER_VERSION)
 LpChannelGroupPtr = ChannelGroupIdPtr;
 #endif /*END of DIO_AR_VERSION */

  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #if(DIO_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, DIO119][R4, DIO119] */
  if (E_NOT_OK == LenDetErrFlag)

  {
    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the Port Address in which the Channel group is configured */
    LpPortGroup = &Dio_GpPortGroup[LpChannelGroupPtr->ucPortIndex];
    /* END Msg(4:0491)-3 */

    /* TRACE [R3, DIO040][R4, DIO040] */
    /* Check if the required port is not INPUT port */
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* TRACE [R4, DIO177] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                    DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

 /* TRACE [R3, DIO119][R4, DIO119] */
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)

    /* MISRA Violation: START Msg(4:0491)-3 */
    /* Get the pointer to port group to which the channel belongs */
    LpPortGroup = &Dio_GpPortGroup[LpChannelGroupPtr->ucPortIndex];
    /* END Msg(4:0491)-3 */

    #endif
    /* (DIO_DEV_ERROR_DETECT == STD_OFF) */

    /* Get the Port Address in which the Channel group is configured */
    LpPortAddress = LpPortGroup->pPortAddress;

    /* TRACE [R3, DIO091][R4, DIO091] */
    /* Rotate left the input level to get the value to be written to port */
    Level = Level << (LpChannelGroupPtr->ucOffset);
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    /* TRACE [R3, DIO040][R4, DIO040] */
    if(DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(~(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
            &LpPortAddress[DIO_PMSR_OFFSET_JTAG])))& (~(LpPortGroup->ulModeMask)
                                                   & LpChannelGroupPtr->usMask);
        /* END Msg(4:0491)-3 */
    }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
        /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(~(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
         &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG])))& (~(LpPortGroup->ulModeMask)
                                                   & LpChannelGroupPtr->usMask);
        /* END Msg(4:0491)-3 */
    }
    else
    {
        LddPortModeLevel = (uint32)DIO_ZERO;
    }

    /* To check channel is output channel*/
    if (DIO_ZERO != LddPortModeLevel)
    {
      /* MISRA Violation: START Msg(4:2985)-8 */
      /* MISRA Violation: START Msg(4:3138)-7 */
      *(LpPortGroup->pPortAddress) =
      (Level | ((uint32)(((LddPortModeLevel)) & LpChannelGroupPtr->usMask) <<
                                                            DIO_SHIFT_SIXTEEN));
      /* END Msg(4:2985)-8 */
      /* END Msg(4:3138)-7 */
    }
    else
    {
      /* No action required */
    }
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  #else
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
    #if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO178] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
    #elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
    /* TRACE [R3, DIO114][R4, DIO114] */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                     DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP_ID);
    #endif
  #endif
  /* (DIO_CHANNELGROUP_CONFIGURED == STD_ON) */
  #endif
}
#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Dio_MaskedWritePort
**
** Service ID            : 0x13
**
** Description           : This service writes the specified level to all the
**                         channels that are Masked in given Port.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : PortId, Mask and Level.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return parameter      : None
**
** Preconditions         : None
**
** Global Variables Used :  Dio_GpPortGroup.
**                          R4.0 : Dio_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, DIO_ENTER_CRITICAL_SECTION,
**                         DIO_EXIT_CRITICAL_SECTION.
**
** Registers Used        : PSRn, JPSRn, APSRn, PMSRn.
*******************************************************************************/
/* TRACE [R3, DIO195] */
/* TRACE [R3, DIO064][R4, DIO064] */
/* Implementation of the Dio_MaskedWritePort interface */
#if (DIO_MASKED_WRITE_PORT_API == STD_ON)

#define DIO_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC(void, DIO_PUBLIC_CODE) Dio_MaskedWritePort
(Dio_PortType PortId,
 Dio_PortLevelType Level,
 Dio_PortLevelType  Mask)
{
  P2CONST(Dio_PortGroup, DIO_VAR, DIO_PRIVATE_CONST) LpPortGroup;
  P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA) LpPortAddress;
  uint32 LddPortModeLevel;

  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Declare the variable to store the DET return value */
  Std_ReturnType LenDetErrFlag;
  LenDetErrFlag = E_NOT_OK;
  #endif

  /* Check whether DIO_DEV_ERROR_DETECT is enabled */
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check whether the Port Id is out of range */
  if (DIO_MAXNOOFPORT <= PortId)
  {
    /* TRACE [R3, DIO140][R4, DIO140] */
    /* TRACE [R4, DIO177] */
    /* Report Error to DET */
    (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_MASKED_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    LenDetErrFlag = E_OK;
  }
  else
  {
    /* Get the pointer to the required Port */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    if (DIO_INPUTPORT == LpPortGroup->ucPortType)
    {
      /* TRACE [R3, DIO140][R4, DIO140] */
      /* TRACE [R4, DIO177] */
      /* Report Error to DET */
      (void)Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
                      DIO_MASKED_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
      LenDetErrFlag = E_OK;
    }
    else
    {
      /* No action required */
    }
  }

  /* TRACE [R3, DIO119][R4, DIO119] */
  if (E_NOT_OK == LenDetErrFlag)
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check whether DIO_DEV_ERROR_DETECT is disabled */
    #if (DIO_DEV_ERROR_DETECT == STD_OFF)
    /* Get the pointer to the required Port */
    /* MISRA Violation: START Msg(4:0491)-3 */
    LpPortGroup = &Dio_GpPortGroup[PortId];
    /* END Msg(4:0491)-3 */
    #endif

    LpPortAddress = LpPortGroup->pPortAddress;
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_ENTER_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
    if(DIO_JTAGPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                          &LpPortAddress[DIO_PMSR_OFFSET_JTAG]))
                                                    | (LpPortGroup->ulModeMask);
      /* END Msg(4:0491)-3 */
    }
    else if (DIO_NORMALPORT == LpPortGroup->ucPortType)
    {
      /* MISRA Violation: START Msg(4:0491)-3 */
      LddPortModeLevel =
      (uint32)(*((P2VAR(uint32 volatile, AUTOMATIC, DIO_PRIVATE_DATA))
                                       &LpPortAddress[DIO_PMSR_OFFSET_NONJTAG]))
                                                | (LpPortGroup->ulModeMask);
      /* END Msg(4:0491)-3 */
    }
    else
    {
        LddPortModeLevel = (uint32)DIO_ZERO;
    }

    /* TRACE [R3, DIO199] */
    /* TRACE [R3, DIO197] */
    /* Check if the channels which are configured as output */
    /* MISRA Violation: START Msg(4:3138)-7 */
    if (DIO_ZERO != (~LddPortModeLevel))
    {
      /* TRACE [R3, DIO196] */
      /* TRACE [R3, DIO198] */
      /*Load 32 bit value to PSR register*/
      *(LpPortGroup->pPortAddress) =
      (Level | ((uint32)((~(LddPortModeLevel)) & Mask) << DIO_SHIFT_SIXTEEN));
     /* END Msg(4:3138)-7 */
    }
    else
    {
      /* No action required */
    }
    #if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
    DIO_EXIT_CRITICAL_SECTION(DIO_REGISTER_PROTECTION);
    #endif
  }
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif
  /* (DIO_DEV_ERROR_DETECT == STD_ON) */
}

#define DIO_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif
/* STD_ON == DIO_MASKED_WRITE_PORT_API */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
