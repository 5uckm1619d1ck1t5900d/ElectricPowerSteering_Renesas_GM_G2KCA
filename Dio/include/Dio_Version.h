/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Version.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains macros required for checking versions of modules        */
/* included by DIO Driver.                                                    */
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
 * V1.0.1:  14-Sep-2012  : As per SCR 013, updated the Alignment
 *
 * V1.0.2:  08-Aug-2013  : As per CR 225, Copyright information, Device name and
 *                         Project name are updated as part of merge activity.
 *
 * V1.0.3:  04-Oct-2013  : As per CR 253, Purpose field is updated for DIO
 *                         Driver.
 *
 * V1.0.4:  04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.5:  06-Mar-2014  : As per CR 428, precompile options related to
 *                         critical section protection is added in include
 *                         section.
 *
 * V1.0.6:  08-Apr-2014  : As per CR 475, code is updated for spell check.
 *
 * V1.0.7:  14-Jul-2014  : As per CR 545, code is updated to correct the
 *                         alignment of revision history.
 *
 * V1.0.8:  25-Aug-2014  : As per CR 569, Extra space present before == is
 *                         removed.
 *
 */
/******************************************************************************/
#ifndef DIO_VERSION_H
#define DIO_VERSION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Dio.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/* DET module version information is required only when DET is enabled */
#include "Det.h"
/*  DIO_AR_VERSION  */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
#define DIO_DET_AR_MAJOR_VERSION        2
#define DIO_DET_AR_MINOR_VERSION        2
#endif
/*END of DIO_AR_VERSION */
#endif

#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)
/*
 * RTE module version information is required only when critical section
 * protection is enabled
 */
#include "Rte.h"
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)
#include "SchM.h"
#endif
/*END of DIO_AR_VERSION*/
#endif
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*START of DIO_AR_VERSION */
#if (DIO_AR_VERSION == DIO_AR_HIGHER_VERSION)

/* AUTOSAR release version information */
#define DIO_VERSION_AR_RELEASE_MAJOR_VERSION    DIO_AR_RELEASE_MAJOR_VERSION
#define DIO_VERSION_AR_RELEASE_MINOR_VERSION    DIO_AR_RELEASE_MINOR_VERSION
#define DIO_VERSION_AR_RELEASE_REVISION_VERSION DIO_AR_RELEASE_REVISION_VERSION

/*  DIO_AR_VERSION  */
#elif (DIO_AR_VERSION == DIO_AR_LOWER_VERSION)

/* AUTOSAR specification version information */
#define DIO_VERSION_AR_MAJOR_VERSION    DIO_AR_MAJOR_VERSION_VALUE
#define DIO_VERSION_AR_MINOR_VERSION    DIO_AR_MINOR_VERSION_VALUE
#define DIO_VERSION_AR_PATCH_VERSION    DIO_AR_PATCH_VERSION_VALUE

#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
#define DIO_SCHM_AR_MAJOR_VERSION     1
#define DIO_SCHM_AR_MINOR_VERSION     2
#endif

#endif /*END of DIO_AR_VERSION */

/* Module Software version information */
#define DIO_VERSION_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION
#define DIO_VERSION_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#endif
/* DIO_VERSION_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
