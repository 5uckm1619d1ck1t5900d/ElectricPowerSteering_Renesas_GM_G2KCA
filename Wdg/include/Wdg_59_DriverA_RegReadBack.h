/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_RegReadBack.h                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2014 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of prototypes for internal functions.                            */
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
 * V1.0.0:  13-May-2014    : Initial Version
 *
 */
/******************************************************************************/

#ifndef WDG_59_DRIVERA_REGREADBACK_H
#define WDG_59_DRIVERA_REGREADBACK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Inclusion for the tool generated macros */
#include "Wdg_59_DriverA_Cfg.h"
/* Inclusion for the macro values defined in PBTypes */
#include "Wdg_59_DriverA_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION  == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR Release version information */
#define WDG_59_DRIVERA_REGREADBACK_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_REGREADBACK_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_REGREADBACK_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

#elif (WDG_59_DRIVERA_AR_VERSION  == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* AUTOSAR specification version information */
#define WDG_59_DRIVERA_REGREADBACK_AR_MAJOR_VERSION \
                                          WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_REGREADBACK_AR_MINOR_VERSION  \
                                          WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_REGREADBACK_AR_PATCH_VERSION \
                                          WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif /* End of Wdg_59_DriverA_AR_VERSION */


/*  File version information */
#define WDG_59_DRIVERA_REGREADBACK_SW_MAJOR_VERSION \
                                                WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_REGREADBACK_SW_MINOR_VERSION \
                                                WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if ((WDG_59_DRIVERA_READBACK_OPTION == \
                                        WDG_59_DRIVERA_READBACK_INIT_ONLY) || \
   (WDG_59_DRIVERA_READBACK_OPTION == \
                                 WDG_59_DRIVERA_READBACK_INIT_AND_RUNTIME))

 #if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define WDG_59_DRIVERA_START_SEC_VAR_NOINIT_32
#include "MemMap.h"

/* External declarations for the variable for IMR1 register */
extern VAR(uint32, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GulIMR1Mirror;

/* External declarations for the variable for IMR1 mask value */
extern VAR(uint32, WDG_59_DRIVERA_NOINIT_DATA) Wdg_59_DriverA_GulIMR1Mask;

/* Functionality related to R4.0 */
#define WDG_59_DRIVERA_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

#endif
#endif

#endif  /* WDG_59_DRIVERA_REGREADBACK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
