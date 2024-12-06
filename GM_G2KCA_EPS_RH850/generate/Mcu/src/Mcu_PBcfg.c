/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_PBcfg.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR MCU post build parameters.                            */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  26-Aug-2013 : Initial Version
 * V1.1.0:  21-Apr-2014 : Following changes are made:
 *                        1. Copyright information is updated.
 *                        2. Include section is updated.
 *                        3. Structure Mcu_GstConfiguration is updated.
 * V1.1.1:  15-Sep-2014 : As per CR 008 and mantis #19850, following change is
 *                        made:
 *                        1. Changes are made at all relevant places
 *                           accordingly to append U or UL after numeric values.
 *                        2. Include Section is updated for adding Mcu.h.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.1.1
 */

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/
/*
 * INPUT FILE:    C:\Users\kzdyfh\AppData\Local\Temp\Cfg_Gen-1472502872948-8\AutosarFiles_ValGen-1472503133169-0\Mcu_ECUC_8970060308995407055.arxml
 *                C:\Workspace\_EA4\T1xx\GM_T1XX_EPS_RH850_Working\Mcu\generate\R403_MCU_P1x_BSWMDT.arxml
 * GENERATED ON:  29 Aug 2016 - 16:39:18
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcu.h"
#include "Mcu_PBTypes.h"
#include "Mcu_Cbk.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION  0U
#define MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define MCU_PBCFG_C_SW_MAJOR_VERSION  1U
#define MCU_PBCFG_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
/* Specification Major Version Check */
#if (MCU_PBTYPES_AR_RELEASE_MAJOR_VERSION != \
MCU_PBCFG_C_AR_RELEASE_MAJOR_VERSION)
#error "Mcu_PBcfg.c : Mismatch in Release Major Version"
  #endif

  #if (MCU_PBTYPES_AR_RELEASE_MINOR_VERSION != \
MCU_PBCFG_C_AR_RELEASE_MINOR_VERSION)
#error "Mcu_PBcfg.c : Mismatch in Release Minor Version"
  #endif

  #if (MCU_PBTYPES_AR_RELEASE_REVISION_VERSION != \
MCU_PBCFG_C_AR_RELEASE_REVISION_VERSION)
#error "Mcu_PBcfg.c : Mismatch in Release Revision Version"
  #endif

  #if (MCU_PBTYPES_SW_MAJOR_VERSION != MCU_PBCFG_C_SW_MAJOR_VERSION)
    #error "Mcu_PBcfg.c : Mismatch in Software Major Version"
  #endif

  #if (MCU_PBTYPES_SW_MINOR_VERSION != MCU_PBCFG_C_SW_MINOR_VERSION)
    #error "Mcu_PBcfg.c : Mismatch in Software Minor Version"
  #endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#define MCU_START_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for MCU Init configuration */
CONST(Mcu_ConfigType, MCU_CONST) Mcu_GstConfiguration[1] =
{
  /* Index: 0 - McuModuleConfiguration */
  {
    /* ulStartOfDbToc */
    0x0ED94100UL,

    /* ulLVIindicationReg */
    0x00000000UL,

    /* pClockSetting */
    &Mcu_GstClockSetting[0],

    /* pEcmSetting */
    &Mcu_GstEcmSetting[0],

    /* pRamSetting */
    &Mcu_GstRamSetting[0],

    /* pMINotification */
    &Mcu_GstMINotification[0],

    /* pNMINotification */
    &Mcu_GstNMINotification[0],

    /* usCLMA0CMPL */
    0x0072U,

    /* usCLMA0CMPH */
    0x0091U,

    /* usCLMA1CMPL */
    0x009BU,

    /* usCLMA1CMPH */
    0x00A5U,

    /* usCLMA2CMPL */
    0x0072U,

    /* usCLMA2CMPH */
    0x0091U,

    /* usCLMA3CMPL */
    0x0138U,

    /* usCLMA3CMPH */
    0x0148U,

    /* ucCvmIndicationReg */
    0x00U,

    /* ulCvmResetEnableReg */
    0x00000003UL
  }
};



#define MCU_STOP_SEC_DBTOC_DATA_UNSPECIFIED
#include "MemMap.h"

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/* Structure for MCU clock setting configuration */
CONST(Mcu_ClockSetting, MCU_CONST) Mcu_GstClockSetting[1] =
{
  /* Index: 0 - McuClockSettingConfig */
  {
    /* ucExtClk0SelectedSrcClock */
    0x00U,

    /* ucExtClk1SelectedSrcClock */
    0x00U,

    /* ulExternalClk0Divider */
    0x00000001UL,

    /* ulExternalClk1Divider */
    0x00000001UL
  }
};


/* Structure for MCU ecm setting configuration */
CONST(Mcu_EcmSetting, MCU_CONST) Mcu_GstEcmSetting[1] =
{
  /* Index: 0 - McuEcmErrorSourcesCfg */
  {
    /* ulEcmMaskInterReg0value */
    0x00000000UL,

    /* ulEcmMaskInterReg1value */
    0x00000014UL,

    /* ulEcmNonMaskInterReg0value */
    0x21E00FF1UL,

    /* ulEcmNonMaskInterReg1value */
    0x00000003UL,

    /* ulEcmInternalResetReg0value */
    0x00000002UL,

    /* ulEcmInternalResetReg1value */
    0x00000000UL,

    /* ulEcmErrorMaskReg0Value */
    0xC81D4000UL,

    /* ulEcmErrorMaskReg1Value */
    0x200005F4UL,

    /* ulEcmDelayTimerReg0Value */
    0x00000000UL,

    /* ulEcmDelayTimerReg1Value */
    0x00000000UL,

    /* ulEcmDelayTimerReg2Value */
    0x00000000UL,

    /* ulEcmDelayTimerReg3Value */
    0x00000000UL
  }
};


/* Data Structure of RAM setting Configuration */
CONST(Mcu_RamSetting, MCU_CONST) Mcu_GstRamSetting[1] =
{
  /* Index: 0 - DummySection */
  {
    /* ucRamDefaultValue */
    0x00U,

    /* ulRamSectionBaseAddress */
    0xFEBFF000UL,

    /* ulRamSectionSize */
    0x00000001UL
  }
};


/* Data Structure of MI Notification Configuration */
CONST(Mcu_ErrorNotification, MCU_CONST) Mcu_GstMINotification[43] =
{
  /* Index: 0 - McuEcmErrorSource0 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 1 - McuEcmErrorSource1 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 2 - McuEcmErrorSource2 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 3 - McuEcmErrorSource3 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 4 - McuEcmErrorSource4 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 5 - McuEcmErrorSource5 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 6 - McuEcmErrorSource6 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 7 - McuEcmErrorSource7 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 8 - McuEcmErrorSource8 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 9 - McuEcmErrorSource9 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 10 - McuEcmErrorSource10 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 11 - McuEcmErrorSource11 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 12 - McuEcmErrorSource12 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 13 - McuEcmErrorSource13 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 14 - McuEcmErrorSource14 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 15 - McuEcmErrorSource15 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 16 - McuEcmErrorSource16 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 17 - McuEcmErrorSource17 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 18 - McuEcmErrorSource18 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 19 - McuEcmErrorSource19 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 20 - McuEcmErrorSource20 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 21 - McuEcmErrorSource21 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 22 - McuEcmErrorSource22 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 23 - McuEcmErrorSource23 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 24 - McuEcmErrorSource24 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 25 - McuEcmErrorSource25 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 26 - McuEcmErrorSource26 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 27 - McuEcmErrorSource27 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 28 - McuEcmErrorSource28 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 29 - McuEcmErrorSource29 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 30 - McuEcmErrorSource30 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 31 - McuEcmErrorSource31 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 32 - McuEcmErrorSource32 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 33 - McuEcmErrorSource33 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 34 - McuEcmErrorSource34 */
  {
    /* pMINotificationFuncPtr */
    &RamMemLclRamSngBitEcc,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 35 - McuEcmErrorSource35 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 36 - McuEcmErrorSource36 */
  {
    /* pMINotificationFuncPtr */
    &CodFlsSngBitEcc,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 37 - McuEcmErrorSource37 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 38 - McuEcmErrorSource38 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 39 - McuEcmErrorSource39 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 40 - McuEcmErrorSource40 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 41 - McuEcmErrorSource41 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 42 - McuEcmErrorSource42 */
  {
    /* pMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  }
};


/* Data Structure of NMI Notification Configuration */
CONST(Mcu_ErrorNotification, MCU_CONST) Mcu_GstNMINotification[43] =
{
  /* Index: 0 - McuEcmErrorSource0 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiWdg,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 1 - McuEcmErrorSource1 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 2 - McuEcmErrorSource2 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 3 - McuEcmErrorSource3 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 4 - McuEcmErrorSource4 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr0RtUpprLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 5 - McuEcmErrorSource5 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr0RtLowrLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 6 - McuEcmErrorSource6 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr2RtUpprLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 7 - McuEcmErrorSource7 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr2RtLowrLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 8 - McuEcmErrorSource8 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr1RtUpprLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 9 - McuEcmErrorSource9 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr1RtLowrLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 10 - McuEcmErrorSource10 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr3RtUpprLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 11 - McuEcmErrorSource11 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiClkMonr3RtLowrLimFlt,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 12 - McuEcmErrorSource12 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 13 - McuEcmErrorSource13 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 14 - McuEcmErrorSource14 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 15 - McuEcmErrorSource15 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 16 - McuEcmErrorSource16 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 17 - McuEcmErrorSource17 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 18 - McuEcmErrorSource18 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 19 - McuEcmErrorSource19 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 20 - McuEcmErrorSource20 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 21 - McuEcmErrorSource21 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiOperModErrFlsProgmModStrtd,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 22 - McuEcmErrorSource22 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiOperModErrTestModStrtd,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 23 - McuEcmErrorSource23 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiOperModErrSngChipInactv,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 24 - McuEcmErrorSource24 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiPeg,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 25 - McuEcmErrorSource25 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 26 - McuEcmErrorSource26 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 27 - McuEcmErrorSource27 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 28 - McuEcmErrorSource28 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 29 - McuEcmErrorSource29 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiEcmMstChkrCmp,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 30 - McuEcmErrorSource30 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 31 - McuEcmErrorSource31 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 32 - McuEcmErrorSource32 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiDmaTrf,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 33 - McuEcmErrorSource33 */
  {
    /* pNMINotificationFuncPtr */
    &FeNmiDmaRegAcsProtnErr,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 34 - McuEcmErrorSource34 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 35 - McuEcmErrorSource35 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 36 - McuEcmErrorSource36 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 37 - McuEcmErrorSource37 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 38 - McuEcmErrorSource38 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 39 - McuEcmErrorSource39 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 40 - McuEcmErrorSource40 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 41 - McuEcmErrorSource41 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  },

  /* Index: 42 - McuEcmErrorSource42 */
  {
    /* pNMINotificationFuncPtr */
    NULL_PTR,

    /* ucDelayTimerOnStatus */
    0x00U
  }
};



#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/

