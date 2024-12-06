/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Version.c                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains code for version checking for the modules included by   */
/* Watchdog Driver A                                                          */
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
 * V1.0.0:  28-Aug-2012    : Initial Version
 *
 * V1.0.1:  29-Sep-2012    : As per SCR 020, version check added for Os.h file
 *                           in lower version.
 * V1.0.2:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 * V1.0.3:  26-Mar-2014    : As per CR 422, version check section updated.
 *
 * V1.0.4:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.                   
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* TRACE [R4, WDG099] */
/* TRACE [R3, WDG099] */
/* Header file inclusion */
#include "Wdg_59_DriverA_Version.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* TRACE [R4, WDG109] */
/* TRACE [R3, WDG109] */
/* TRACE [R4, WDG174] */
/* TRACE [R4, WDG174] */
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* TRACE [R3, WDG067] */
/* TRACE [R4, WDG068] */
/* TRACE [R3, WDG068] */
/* TRACE [R3, WDG087] */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MAJOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MINOR_VERSION \
                                  WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_RELEASE_REVISION_VERSION \
                               WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION_VALUE

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* AUTOSAR specification version information */
#define WDG_59_DRIVERA_VERSION_C_AR_MAJOR_VERSION  \
                                          WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_MINOR_VERSION  \
                                          WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_AR_PATCH_VERSION  \
                                          WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
#define WDG_59_DRIVERA_VERSION_C_SW_MAJOR_VERSION \
                                          WDG_59_DRIVERA_SW_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_VERSION_C_SW_MINOR_VERSION \
                                          WDG_59_DRIVERA_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION  == WDG_59_DRIVERA_AR_HIGHER_VERSION)
#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_MAJOR_VERSION != \
                              WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MAJOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_MINOR_VERSION != \
                              WDG_59_DRIVERA_VERSION_C_AR_RELEASE_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_RELEASE_REVISION_VERSION != \
                           WDG_59_DRIVERA_VERSION_C_AR_RELEASE_REVISION_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Release Revision Version"
#endif

#elif (WDG_59_DRIVERA_AR_VERSION  == WDG_59_DRIVERA_AR_LOWER_VERSION)
#if (WDG_59_DRIVERA_VERSION_AR_MAJOR_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_AR_MAJOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Specification Major Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_MINOR_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_AR_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Specification Minor Version"
#endif

#if (WDG_59_DRIVERA_VERSION_AR_PATCH_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_AR_PATCH_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Specification Patch Version"
#endif
#if (WDG_59_DRIVERA_VERSION_SW_MAJOR_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_SW_MAJOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Software Major Version"
#endif
#endif

#if (WDG_59_DRIVERA_VERSION_SW_MINOR_VERSION !=  \
                                      WDG_59_DRIVERA_VERSION_C_SW_MINOR_VERSION)
  #error "WDG_59_DriverA_Version.c : Mismatch in Software Minor Version"
#endif


#if (WDG_59_DRIVERA_VER_CHECK_EXT == STD_ON)
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#if ((DET_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (DET_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

#if ((DEM_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (DEM_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Dem.h does not match the expected version"
#endif

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
#if ((RTE_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (RTE_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Rte.h does not match the expected version"
#endif
#endif

#if ((OS_AR_RELEASE_MAJOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION) \
 || (OS_AR_RELEASE_MINOR_VERSION != WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION))
  #error "The AR version of Os.h does not match the expected version"
#endif

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

#if (DET_AR_MAJOR_VERSION != WDG_59_DRIVERA_DET_AR_MAJOR_VERSION)
  #error "Det.h : Mismatch in Specification Major Version"
#endif

#if (DET_AR_MINOR_VERSION != WDG_59_DRIVERA_DET_AR_MINOR_VERSION)
  #error "Det.h : Mismatch in Specification Minor Version"
#endif

#endif

#if (DEM_AR_MAJOR_VERSION != WDG_59_DRIVERA_DEM_AR_MAJOR_VERSION)
  #error "Dem.h : Mismatch in Specification Major Version"
#endif

#if (DEM_AR_MINOR_VERSION != WDG_59_DRIVERA_DEM_AR_MINOR_VERSION)
  #error "Dem.h : Mismatch in Specification Minor Version"
#endif

#if (OS_AR_MAJOR_VERSION != WDG_59_DRIVERA_OS_AR_MAJOR_VERSION)
  #error "Os.h : Mismatch in Specification Major Version"
#endif

#if (OS_AR_MINOR_VERSION != WDG_59_DRIVERA_OS_AR_MINOR_VERSION)
  #error "Os.h : Mismatch in Specification Minor Version"
#endif

#if (WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION == STD_ON)
#if (SCHM_AR_MAJOR_VERSION != WDG_59_DRIVERA_SCHM_AR_MAJOR_VERSION)
  #error "SchM.h : Mismatch in Specification Major Version"
#endif

#if (SCHM_AR_MINOR_VERSION != WDG_59_DRIVERA_SCHM_AR_MINOR_VERSION)
  #error "SchM.h : Mismatch in Specification Minor Version"
#endif
#endif /* End of WDG_59_DRIVERA_CRITICAL_SECTION_PROTECTION */

#endif

#endif /* #if (WDG_59_DRIVERA_VER_CHECK_EXT == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
