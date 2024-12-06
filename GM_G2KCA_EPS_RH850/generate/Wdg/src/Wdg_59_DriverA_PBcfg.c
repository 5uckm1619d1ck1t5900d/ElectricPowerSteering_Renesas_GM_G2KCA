/*===========================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_PBcfg.c                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains post-build time parameters.                             */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
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
 * V1.0.0:  29-Aug-2012  : Initial Version
 * V1.0.1:  23-Jan-2013  : As per SCR 068,
 *                         1. File version of output generated file is taken 
 *                            from BSWMDT file instead of hardcoding in 
 *                            template file.                                  
 * V1.0.2:  08-Aug-2013  : As per CR 225, F1x is renamed to X1x.
 * V1.0.3:  18-Oct-2013  : As per CR 263, hash BswPbSrcTpl is updated. 
 * V1.0.4:  04-Feb-2014  : As per CR 400 and mantis #19208, for P1x-F1x merge
 *                         activity following changes are made:
 *                         1. Copyright information is updated.
 *                         2. Template_Hash is updated.
 * V1.0.5:  28-Feb-2014  : As per CR 422 and mantis #19537, following changes
 *                         are made:
 *                         1. Hash BswPbSrcTpl::Template_Hash is updated.
 *                         2. COPYRIGHT section is updated.
 * V1.0.6:  02-Sep-2014 :  As per CR 560 and mantis #22252, Changes are made at 
 *                         all relevant places accordingly to append U or UL
 *                         after numeric values.
 */
/******************************************************************************/
 
/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.0.17
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\czgng4\AppData\Local\Temp\Cfg_Gen-1453480162916-8\AutosarFiles_ValGen-1453480494219-0\Wdg_ECUC_1408701641491077325.arxml
 *                C:\Project\Wdg\generate\R403_WDG_P1x_BSWMDT.arxml
 * GENERATED ON:  22 Jan 2016 - 11:35:27
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Wdg_59_DriverA_PBTypes.h" 

/*******************************************************************************
**                     Version Information                                    **
*******************************************************************************/

/* AUTOSAR release version information */
#define WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MINOR_VERSION  0U
#define WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define WDG_59_DRIVERA_PBCFG_C_SW_MAJOR_VERSION  1U
#define WDG_59_DRIVERA_PBCFG_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (WDG_59_DRIVERA_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_AR_RELEASE_MINOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_AR_RELEASE_REVISION_VERSION != \
                       WDG_59_DRIVERA_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Release Revision Version"
#endif
 
#if (WDG_59_DRIVERA_PBTYPES_SW_MAJOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_SW_MAJOR_VERSION)
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (WDG_59_DRIVERA_PBTYPES_SW_MINOR_VERSION != \
                        WDG_59_DRIVERA_PBCFG_C_SW_MINOR_VERSION) 
  #error "Wdg_59_DriverA_PBcfg.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define WDG_59_DRIVERA_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for Watchdog Driver Init configuration */
CONST(Wdg_59_DriverA_ConfigType,WDG_59_DRIVERA_CONFIG_CONST)
Wdg_59_DriverA_GstConfiguration =
{
  /* ulStartOfDbToc */
  0x0ED98100UL,

  /* usInitTimerCountValue */
  0x065CU,

  /* usDefaultTimeValue */
  0x0006U,

  /* ucWdtamdDefaultValue */
  0x78U,

  /* ddWdtamdDefaultMode */
  WDGIF_SLOW_MODE
};

#define WDG_59_DRIVERA_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
