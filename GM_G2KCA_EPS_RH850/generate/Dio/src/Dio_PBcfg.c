/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
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
 * V1.0.0:  27-Aug-2012  : Initial Version
 * V1.0.1:  05-Mar-2013  : As per SCR 090, SW version is updated.
 * V1.0.2:  08-Aug-2013  : As per CR 225, F1x is renamed to X1x.
 * V1.0.3:  17-Mar-2014  : As per CR 413, copyright information is updated.
 * V1.0.4:  28-Apr-2014  : As per CR 488, Mask ucmodemask is renamed to
 *                         ulmodemask in Dio_GstPortGroup Structure.
 * V1.0.5:  27-Jun-2014  : As per CR 103 and 563, copyright information is
 *                         updated and  order of structural elements in
 *                         Dio_GstPortGroup Structure is updated.
 * V1.0.6:  02-Sep-2014  : As per CR 569, following changes are made:
 *                         1. MISRA C Rule Violation is added.
 *                         2. Changes are made at all relevant places
 *                         accordingly to append U or UL after numeric values.
 * V1.0.7:  02-Feb-2015  : As part of merging activity(mantis #26024)
 *                         following changes are made:
 *                         1. pPortAddress is updated in Dio_GstPortGroup
 *                            Structure
 *                         2. Copyright information is updated.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.0.16
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\_synergy\G2KCAT3_CZ8L9T\Dio\generate\R403_DIO_P1x_BSWMDT.arxml
 *                C:\Users\cz8l9t\AppData\Local\Temp\Cfg_Gen-1484837221603-8\AutosarFiles_ValGen-1484838501299-0\Dio_ECUC_4501856353292358394.arxml
 * GENERATED ON:  19 Jan 2017 - 10:08:45
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dio.h"
#include "Dio_PBTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_PBCFG_C_AR_RELEASE_MINOR_VERSION  0U
#define DIO_PBCFG_C_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define DIO_PBCFG_C_SW_MAJOR_VERSION   1U
#define DIO_PBCFG_C_SW_MINOR_VERSION   0U


/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) Cast between a pointer to object and an integral  */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Void pointer is used inorder to typecast to different      */
/*                 channel structures later.                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-1 and                           */
/*                 END Msg(4:0306)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (DIO_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
         DIO_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Release Major Version"
#endif

#if (DIO_PBTYPES_AR_RELEASE_MINOR_VERSION != \
         DIO_PBCFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Release Minor Version"
#endif

#if (DIO_PBTYPES_AR_RELEASE_REVISION_VERSION != \
         DIO_PBCFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Release Revision Version"
#endif

#if (DIO_PBTYPES_SW_MAJOR_VERSION != DIO_PBCFG_C_SW_MAJOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Software Major Version"
#endif

#if (DIO_PBTYPES_SW_MINOR_VERSION != DIO_PBCFG_C_SW_MINOR_VERSION)
  #error "Dio_PBcfg.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define DIO_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for DIO Driver Init configuration */
CONST(Dio_ConfigType, DIO_CONFIG_CONST) Dio_GstConfiguration[] =
{
  /* Index: 0 - DioConfig */
  {
    /* ulStartOfDbToc */
    0x0EDE0100UL,

    /* pPortGroup */
    &Dio_GstPortGroup[0],

    /* pPortChannel */
    &Dio_GstPortChannel[0]
  }
};


#define DIO_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure of DIO Port Group Configuration */
CONST (Dio_PortGroup, DIO_CONST) Dio_GstPortGroup[] =
{
  /* Index: 0 - Port0 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
    (P2VAR(uint32 volatile, AUTOMATIC, DIO_CONFIG_DATA))0xFFC10004UL,
    /* END Msg(4:0306)-1 */

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 1 - Port5 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
    (P2VAR(uint32 volatile, AUTOMATIC, DIO_CONFIG_DATA))0xFFC10144UL,
    /* END Msg(4:0306)-1 */

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 2 - Port4 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
    (P2VAR(uint32 volatile, AUTOMATIC, DIO_CONFIG_DATA))0xFFC10104UL,
    /* END Msg(4:0306)-1 */

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 3 - Port3 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
    (P2VAR(uint32 volatile, AUTOMATIC, DIO_CONFIG_DATA))0xFFC100C4UL,
    /* END Msg(4:0306)-1 */

    /* ulModeMask */
    0xFFFF8000UL,

    /* ucPortType */
    0x02U
  },

  /* Index: 4 - Port2 */
  {
    /* pPortAddress */
    /* MISRA Violation: START Msg(4:0306)-1 */
    (P2VAR(uint32 volatile, AUTOMATIC, DIO_CONFIG_DATA))0xFFC10084UL,
    /* END Msg(4:0306)-1 */

    /* ulModeMask */
    0xFFFF0000UL,

    /* ucPortType */
    0x02U
  }
};


/* Data Structure of DIO Port Channel Configuration */
CONST(Dio_PortChannel, DIO_CONST) Dio_GstPortChannel[] =
{
  /* Index: 0 - PwrTurnOffCtrl */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 1 - McuEna */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 2 - EcuIdnPin2 */
  {
    /* usMask */
    0x4000U,

    /* ucPortIndex */
    0x00U
  },

  /* Index: 3 - TmplMonrWdg */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x01U
  },

  /* Index: 4 - MotAg0CsihCs */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x02U
  },

  /* Index: 5 - GateDrv0Rst */
  {
    /* usMask */
    0x0020U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 6 - PhaALowrCmd */
  {
    /* usMask */
    0x0100U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 7 - MotDrvr0Diag */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 8 - PhaBLowrCmd */
  {
    /* usMask */
    0x0400U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 9 - PhaBUpprCmd */
  {
    /* usMask */
    0x0200U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 10 - PhaCLowrCmd */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 11 - PhaCUpprCmd */
  {
    /* usMask */
    0x1000U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 12 - PwrOutpEnaFb */
  {
    /* usMask */
    0x0040U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 13 - MotAg1CsihCs */
  {
    /* usMask */
    0x0008U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 14 - PhaAUpprCmd */
  {
    /* usMask */
    0x0080U,

    /* ucPortIndex */
    0x03U
  },

  /* Index: 15 - SysFlt2A */
  {
    /* usMask */
    0x0010U,

    /* ucPortIndex */
    0x04U
  },

  /* Index: 16 - EcuIdnPin1 */
  {
    /* usMask */
    0x2000U,

    /* ucPortIndex */
    0x04U
  }
};


/* Data Structure of DIO Port Channel Group Configuration */
/* CONST(Dio_ChannelGroupType, DIO_CONST) Dio_GstChannelGroupData[]; */

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
