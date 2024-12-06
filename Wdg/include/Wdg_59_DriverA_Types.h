/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Types.h                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of Database declaration.                                         */
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
 * V1.0.1:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 * V1.0.2:  26-Aug-2013    : As per CR 232 and mantis #13220, Std_Types.h is
 *                            added for  R3.2 in Include section.
 * V1.0.3:  07-Feb-2014    : As per CR 391, part of Merge activity file is
 *                           updated for the removal of Magic number.
 *
 * V1.0.4:  03-Feb-2015    : As part of merging activity(#26024),File is
 *                           adopted from P1X branch.                   
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_TYPES_H
#define WDG_59_DRIVERA_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for declaration of type WdgIf_ModeType */
#include "WdgIf_Types.h"
/* Included for pre-compile options */
#include "Wdg_59_DriverA_Cfg.h"
/* Included for pre-compile options */
#include "Wdg_59_DriverA.h"
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Included for AUTOSAR standard Type definitions */
#include "Std_Types.h"
#endif

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_TYPES_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_TYPES_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_TYPES_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define WDG_59_DRIVERA_TYPES_AR_MAJOR_VERSION \
                                           WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_TYPES_AR_MINOR_VERSION \
                                           WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_TYPES_AR_PATCH_VERSION \
                                           WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* Module Software version information */
#define WDG_59_DRIVERA_TYPES_SW_MAJOR_VERSION   WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_TYPES_SW_MINOR_VERSION   WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Structure declarations                                **
*******************************************************************************/
/* TRACE [R4, WDG171] */
/* TRACE [R3, WDG171] */
typedef struct STag_Wdg_59_DriverA_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;

  #if(WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
  /* Functionality related to R4.0 */
  /* Value of Timer Counter for Default mode */
  uint16 usInitTimerCountValue;
  #endif

  #if (WDG_59_DRIVERA_DISABLE_ALLOWED == STD_ON)
  #if(WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
  /* Functionality related to R4.0 */
  /* Value of 75% interrupt time for SLOW mode in msec */
  uint16 usSlowTimeValue;
  /* Value of 75% interrupt time for FAST mode in msec */
  uint16 usFastTimeValue;
  #endif

  /* Value of WDTAMD register for SLOW mode */
  uint8 ucWdtamdSlowValue;
  /* Value of WDTAMD register for FAST mode */
  uint8 ucWdtamdFastValue;
  #else
  #if(WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
  /* Functionality related to R4.0 */
  /* Value of 75% interrupt time for Default mode in msec */
  uint16 usDefaultTimeValue;
  #endif
  #endif

  /* Value of WDTAMD register for Default mode */
  uint8 ucWdtamdDefaultValue;
  /* Configured Default mode */
  WdgIf_ModeType ddWdtamdDefaultMode;
}Wdg_59_DriverA_ConfigType;


#if (WDG_59_DRIVERA_DEV_ERROR_DETECT == STD_ON)

/* Type definition for the current state of Watchdog Driver */
typedef enum ETag_Wdg_59_DriverA_StatusType
{
  WDG_59_DRIVERA_UNINIT,
  WDG_59_DRIVERA_IDLE,
  WDG_59_DRIVERA_BUSY
}Wdg_59_DriverA_StatusType;

#endif

#endif /* WDG_59_DRIVERA_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
