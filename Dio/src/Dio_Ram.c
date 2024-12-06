/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Ram.c                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Global RAM variable definitions for Dio Driver                             */
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
 * V1.0.0:  23-Aug-2012  : Initial Version
 *
 * V1.0.1:  08-Aug-2013  : As per CR 225, Copyright information, Device name and
 *                         Project name are updated as part of merge activity.
 *
 * V1.0.2:  17-Sep-2013  : As per CR 241 and mantis 12996, memory class for
 *                         P2CONST is updated.
 *
 * V1.0.3:  06-Feb-2014  : As per CR 394 the Copyright information is updated.
 *
 * V1.0.4:  23-May-2014  : As per CR 488 and mantis 21315, Global Data Types
 *                         section is updated for memory mapping.
 *
 * V1.0.5:  28-Jul-2014  : As per CR 564, version information section is updated
 *                         for lower version check.
 *
 * V1.0.6:  25-Aug-2014  : As per CR 569, Extra space present before ==
 *                         is removed.
 * V1.0.7:  16-Jan-2015  : Precompile options for global variables
 *                         Dio_GpPortGroup,Dio_GpPortChannel are added to
 *                         avoid MISRA warnings.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for module version information and other types declarations */
#include "Dio.h"
/* Included for macro definitions and structure declarations */
#include "Dio_PBTypes.h"
/* Included for RAM variable declarations */
#include "Dio_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define DIO_RAM_C_AR_RELEASE_MAJOR_VERSION   DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_RAM_C_AR_RELEASE_MINOR_VERSION   DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_RAM_C_AR_RELEASE_REVISION_VERSION \
                                          DIO_AR_RELEASE_REVISION_VERSION_VALUE

#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* AUTOSAR Specification version information */
#define DIO_RAM_C_AR_MAJOR_VERSION    DIO_AR_MAJOR_VERSION_VALUE
#define DIO_RAM_C_AR_MINOR_VERSION    DIO_AR_MINOR_VERSION_VALUE
#define DIO_RAM_C_AR_PATCH_VERSION    DIO_AR_PATCH_VERSION_VALUE
#endif /* End of DIO_AR_VERSION */

/* Module Software version information  */
#define DIO_RAM_C_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_RAM_C_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#if (DIO_RAM_AR_RELEASE_MAJOR_VERSION != DIO_RAM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Release Major Version"
#endif

#if (DIO_RAM_AR_RELEASE_MINOR_VERSION != DIO_RAM_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Release Minor Version"
#endif

#if (DIO_RAM_AR_RELEASE_REVISION_VERSION != \
                                         DIO_RAM_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_Ram.c : Mismatch in Release Revision Version"
#endif

#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (DIO_RAM_AR_MAJOR_VERSION != DIO_RAM_C_AR_MAJOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Specification Major Version"
#endif

#if (DIO_RAM_AR_MINOR_VERSION != DIO_RAM_C_AR_MINOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Specification Minor Version"
#endif

#if (DIO_RAM_AR_PATCH_VERSION != DIO_RAM_C_AR_PATCH_VERSION)
  #error "Dio_Ram.c : Mismatch in Specification Patch Version"
#endif
#endif /* End of DIO_AR_VERSION */

#if (DIO_RAM_SW_MAJOR_VERSION != DIO_RAM_C_SW_MAJOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Software Major Version"
#endif

#if (DIO_RAM_SW_MINOR_VERSION != DIO_RAM_C_SW_MINOR_VERSION)
  #error "Dio_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define DIO_START_SEC_VAR_BOOLEAN
#include "MemMap.h"

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define DIO_START_SEC_VAR_1BIT
#include "MemMap.h"
#endif

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* Global variable to store the Dio driver initialization state */
VAR(boolean, DIO_INIT_DATA) Dio_GblDriverStatus = DIO_UNINITIALIZED;
#endif

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define DIO_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define DIO_STOP_SEC_VAR_1BIT
#include "MemMap.h"
#endif

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
#define DIO_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store pointer to Configuration */
P2CONST(Dio_PortGroup, DIO_VAR, DIO_CONFIG_CONST)Dio_GpPortGroup;

#if (DIO_CHANNEL_CONFIGURED == STD_ON)
/* Global variable to store pointer to Configuration */
P2CONST(Dio_PortChannel, DIO_VAR, DIO_CONFIG_CONST)Dio_GpPortChannel;
#endif

#define DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"
#endif

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define DIO_START_SEC_VAR_NOINIT_16
#include "MemMap.h"

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define DIO_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
#endif

#if (DIO_CHANNELGROUP_CONFIGURED == STD_ON)
/*
 * Global variable to indicate the offset of channel groups starting for the
 * corresponding configuration set in the array Dio_GstChannelGroupData[].
 */
VAR(uint16, DIO_CONFIG_CONST) Dio_GusNoOfChannelGroups;
#endif

#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define DIO_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define DIO_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
#endif
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
