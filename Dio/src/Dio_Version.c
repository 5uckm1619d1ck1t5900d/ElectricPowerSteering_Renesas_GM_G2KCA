/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Version.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for the modules included by   */
/* Dio Driver                                                                 */
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
 * V1.0.1:  17-Sep-2012  : As per SCR 013, updated the Alignment.
 *
 * V1.0.2:  08-Aug-2013  : As per CR 225, Copyright information, Device name and
 *                         Project name are updated as part of merge activity.
 *
 * V1.0.3:  04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.4:  06-Mar-2014  : As per CR 428, errors related to critical section
 *                         protection are added in version check section.
 *
 * V1.0.5:  06-Aug-2014  : As per mantis #22811, code is updated for Renesas
 *                         C coding Guidelines.
 *
 * V1.0.6:  25-Aug-2014  : As per CR 569, Extra space present before ==
 *                         is removed.
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Header file inclusion */
#include "Dio_Version.h"

/*  DIO_AR_VERSION  */
#if (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
#if (DIO_DEV_ERROR_DETECT == STD_ON)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
#endif
#endif
/* END of DIO_AR_VERSION */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

/* AUTOSAR release version information */
#define DIO_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  DIO_AR_RELEASE_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  DIO_AR_RELEASE_MINOR_VERSION_VALUE
#define DIO_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               DIO_AR_RELEASE_REVISION_VERSION_VALUE

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/*  DIO_AR_VERSION  */
/* AUTOSAR specification version information */
#define DIO_VERSION_C_AR_MAJOR_VERSION    DIO_AR_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_AR_MINOR_VERSION    DIO_AR_MINOR_VERSION_VALUE
#define DIO_VERSION_C_AR_PATCH_VERSION    DIO_AR_PATCH_VERSION_VALUE

#endif
/*END of DIO_AR_VERSION */

/* File version information */
#define DIO_VERSION_C_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_VERSION_C_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

#if (DIO_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              DIO_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Release Major Version"
#endif

#if (DIO_VERSION_AR_RELEASE_MINOR_VERSION != \
                              DIO_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Release Minor Version"
#endif

#if (DIO_VERSION_AR_RELEASE_REVISION_VERSION != \
                           DIO_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_Version.c : Mismatch in Release Revision Version"
#endif

#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
/*  DIO_AR_VERSION  */
/* TRACE [R3, DIO106][R4, DIO106] */
#if (DIO_VERSION_AR_MAJOR_VERSION != DIO_VERSION_C_AR_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Specification Major Version"
#endif

/* TRACE [R3, DIO106][R4, DIO106] */
#if (DIO_VERSION_AR_MINOR_VERSION != DIO_VERSION_C_AR_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Specification Minor Version"
#endif

/* TRACE [R3, DIO106][R4, DIO106] */
#if (DIO_VERSION_AR_PATCH_VERSION != DIO_VERSION_C_AR_PATCH_VERSION)
  #error "Dio_Version.c : Mismatch in Specification Patch Version"
#endif

#endif
/* END of DIO_AR_VERSION */

/* TRACE [R3, DIO106][R4, DIO106] */
#if (DIO_VERSION_SW_MAJOR_VERSION != DIO_VERSION_C_SW_MAJOR_VERSION)
  #error "Dio_Version.c : Mismatch in Software Major Version"
#endif

/* TRACE [R3, DIO106][R4, DIO106] */
#if (DIO_VERSION_SW_MINOR_VERSION != DIO_VERSION_C_SW_MINOR_VERSION)
  #error "Dio_Version.c : Mismatch in Software Minor Version"
#endif

#if (DIO_VERSION_CHECK_EXT_MODULES == STD_ON)
/* START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) \
              || (RTE_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* End of DIO_CRITICAL_SECTION_PROTECTION */

/* START of DIO_DEV_ERROR_DETECT */
#if (DIO_DEV_ERROR_DETECT == STD_ON)

#if ((DET_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif
/*  DIO_AR_VERSION  */
#elif(DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

/* START of DIO_DEV_ERROR_DETECT */
#if (DIO_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_MAJOR_VERSION != DIO_DET_AR_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_MINOR_VERSION != DIO_DET_AR_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif

#endif
/* END of DIO_DEV_ERROR_DETECT */

#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#if (SCHM_AR_MAJOR_VERSION != DIO_SCHM_AR_MAJOR_VERSION)
  #error "SchM.h : Mismatch in Specification Major Version"
#endif
#endif
/* END of (DIO_CRITICAL_SECTION_PROTECTION == STD_ON) */
#endif
/* END of (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION) */
#endif
/* END of (DIO_VERSION_CHECK_EXT_MODULES == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
