/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Private.h                                    */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of API and database declaration, Service Id and DET error Macros */
/* and Module version information Macros.                                     */
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
 * V1.0.1:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.2:  12-Sep-2013    : As per CR 232 for mantis issue 13035,
 *                           following changes are made:
 *                           1. Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           2. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.3:  03-Feb-2015     : As part of merging activity(#26024) alignment of
 *                            revision history is updated.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_PRIVATE_H
#define WDG_59_DRIVERA_PRIVATE_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version */
#define WDG_59_DRIVERA_PRIVATE_AR_MAJOR_VERSION \
                                           WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_AR_MINOR_VERSION \
                                           WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_PRIVATE_AR_PATCH_VERSION \
                                           WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* Module Software version information */
#define WDG_59_DRIVERA_PRIVATE_SW_MAJOR_VERSION  WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_PRIVATE_SW_MINOR_VERSION  WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

extern FUNC(void, WDG_59_DRIVERA_FAST_CODE) Wdg_59_DriverA_TriggerFunc(void);

#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* WDG_59_DRIVERA_PRIVATE_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
