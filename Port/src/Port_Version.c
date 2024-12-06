/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Version.c                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2013 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for modules included by PORT  */
/* Driver                                                                     */
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
 * V1.0.1:  17-Oct-2012  : As per SCR 027, Version Check section is updated to
 *                         modify stubs for Higher and Lower versions.
 *
 * V1.0.2:  05-Aug-2013  : As per CR 225, as part of merging activity, following
 *                         changes are made:
 *                         1. Header and Environment sections are updated to
 *                            change the device name.
 *                         2. Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Header file inclusion */
#include "Port_Version.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define PORT_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                             PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                             PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_VERSION_C_AR_RELEASE_REVISION_VERSION \
                                          PORT_AR_RELEASE_REVISION_VERSION_VALUE

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* AUTOSAR specification version information */
#define PORT_VERSION_C_AR_MAJOR_VERSION  PORT_AR_MAJOR_VERSION_VALUE
#define PORT_VERSION_C_AR_MINOR_VERSION  PORT_AR_MINOR_VERSION_VALUE
#define PORT_VERSION_C_AR_PATCH_VERSION  PORT_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
#define PORT_VERSION_C_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION_VALUE
#define PORT_VERSION_C_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION_VALUE
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */

#if (PORT_VERSION_AR_RELEASE_MAJOR_VERSION != \
                                        PORT_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Release Major Version"
#endif
#if (PORT_VERSION_AR_RELEASE_MINOR_VERSION != \
                                        PORT_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Release Minor Version"
#endif
#if (PORT_VERSION_AR_RELEASE_REVISION_VERSION != \
                                     PORT_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "Port_Version.c : Mismatch in Release Revision Version"
#endif

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */

#if (PORT_VERSION_AR_MAJOR_VERSION != PORT_VERSION_C_AR_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Specification Major Version"
#endif
#if (PORT_VERSION_AR_MINOR_VERSION != PORT_VERSION_C_AR_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Specification Minor Version"
#endif
#if (PORT_VERSION_AR_PATCH_VERSION != PORT_VERSION_C_AR_PATCH_VERSION)
  #error "Port_Version.c : Mismatch in Specification Patch Version"
#endif

#endif /* (PORT_AR_VERSION == PORT_AR_LOWER_VERSION) */

#if (PORT_VERSION_SW_MAJOR_VERSION != PORT_VERSION_C_SW_MAJOR_VERSION)
  #error "Port_Version.c : Mismatch in Software Major Version"
#endif
#if (PORT_VERSION_SW_MINOR_VERSION != PORT_VERSION_C_SW_MINOR_VERSION)
  #error "Port_Version.c : Mismatch in Software Minor Version"
#endif

#if (PORT_VERSION_CHECK_EXT_MODULES == STD_ON)

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)

/* Rte Module Version Check */
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif /* (PORT_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* Dem Module Version Check */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

/* Det Module Version Check */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#if ((DET_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)

/* SchM Module Version Check */
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
#if (SCHM_AR_MAJOR_VERSION != PORT_SCHM_AR_MAJOR_VERSION)
  #error "SchM.h : Mismatch in Specification Major Version"
#endif
#if (SCHM_AR_MINOR_VERSION != PORT_SCHM_AR_MINOR_VERSION)
  #error "SchM.h : Mismatch in Specification Minor Version"
#endif
#endif /* (PORT_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* Det Module Version Check */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#if (DET_AR_MAJOR_VERSION != PORT_DET_AR_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif
#if (DET_AR_MINOR_VERSION != PORT_DET_AR_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif
#endif/* (PORT_DEV_ERROR_DETECT == STD_ON) */

/* Dem Module Version Check */
#if (DEM_AR_MAJOR_VERSION != PORT_DEM_AR_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif
#if (DEM_AR_MINOR_VERSION != PORT_DEM_AR_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif

#endif /* (PORT_AR_VERSION == PORT_AR_LOWER_VERSION) */
#endif /* #if (PORT_VERSION_CHECK_EXT_MODULES == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
