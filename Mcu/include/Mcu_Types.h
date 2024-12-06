/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_Types.h                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
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
/*              Devices:        P1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  02-Sep-2013 : Initial Version.
 *
 * V1.0.1:  16-Apr-2014 : As per CR83 and mantis #18031 and #19850,
 *                        Following changes are made,
 *                        1. ulCvmIndicationReg is changed to ucCvmIndicationReg
 *                        2. MCU_RAMSTATE_VALID is kept at the first position
 *                           of Mcu_RamStateType
 *                        3. Mcu_RamWriteSizeType and Mcu_ProtectionCmdType are
 *                           removed since they are not used
 *
 * V1.0.2:  07-Oct-2014 : As per CR008 and mantis #19850, Following
 *                        changes are made,
 *                        1. New structure element 'ulCvmResetEnableReg' is
 *                           added in Mcu_ConfigType to support cvm reset
 *                        2. GRAM related reset values are removed and CVM reset
 *                           is added in Mcu_ResetType
 *                        3. Trace marking is added in the file
 *
 * V1.0.3:  09-Dec-2014 : As per CR076 and mantis #17005, Following
 *                        changes are made,
 *                        1. Include section is updated to include
 *                           rh850_Types.h file.
 * V1.0.4:  25-Mar-2015 : 1.As per mantis #26418 ,following change is made:
 *                             MCU_SW_RST is corrected with name MCU_SW_RESET ,
 *                             MCU_WDT_RST is corrected with name
 *                             MCU_WATCHDOG_RESET ,
 *                             MCU_POWER_ON_CLEAR_RST is corrected with name
 *                             MCU_POWER_ON_RESET
 *                        2. Added code comments as per MO Review in Mantis
 *                             #27515
 */
/******************************************************************************/
#ifndef MCU_TYPES_H
/*Defining MCU_TYPES_H to avoid multiple inclusion*/
#define MCU_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Standard AUTOSAR types */
/* TRACE [R4, MCU152] */
#include "Std_Types.h"
#include "rh850_Types.h"
/* Included for pre-compile options */
#include "Mcu_Cfg.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* macros to differentiate the Autosar R3.2 and R4.0 versions */
#define MCU_AR_FOUR_ZERO_THREE    403
#define MCU_AR_THREE_TWO_TWO      322

/* AUTOSAR release version information */
#define MCU_TYPES_AR_RELEASE_MAJOR_VERSION    4
#define MCU_TYPES_AR_RELEASE_MINOR_VERSION    0
#define MCU_TYPES_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define MCU_TYPES_SW_MAJOR_VERSION  MCU_SW_MAJOR_VERSION_VALUE
#define MCU_TYPES_SW_MINOR_VERSION  MCU_SW_MINOR_VERSION_VALUE
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Type definition for Mcu_ClockType used by the API Mcu_InitClock */
/* TRACE [R4, MCU233] */
typedef uint8 Mcu_ClockType;

/* Type definition for Mcu_RawResetType used by the API Mcu_GetResetRawValue */
/* TRACE [R4, MCU236] */
typedef uint32 Mcu_RawResetType;

/* Type definition for Mcu_ModeType used by the API Mcu_SetMode */
/* TRACE [R4, MCU238] */
typedef uint8 Mcu_ModeType;

/* Type definition for Mcu_RamSectionType used by the API Mcu_InitRamSection */
/* TRACE [R4, MCU240] */
typedef uint8 Mcu_RamSectionType;

/* Structure for MCU Init Configuration */
/* TRACE [R4, MCU035] */
/* TRACE [R4, MCU131] */
typedef struct STag_Mcu_ConfigType
{
  /* Database start value */
  uint32 ulStartOfDbToc;
  /* Element to handle the LVI detection level of voltage */
  uint32 ulLVIindicationReg;
  /* Pointer to MCU Clock Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pClockSetting;
  /* Pointer to array of MCU ECM Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pEcmSetting;
  /* Pointer to ram Setting configuration */
  P2CONST(void, AUTOMATIC, MCU_CONFIG_CONST) pRamSetting;
  /* Pointer to callback notification function */
  P2CONST (void, AUTOMATIC, MCU_CONFIG_CONST)pMINotification;
  /* Pointer to callback notification function */
  P2CONST (void, AUTOMATIC, MCU_CONFIG_CONST)pNMINotification;
  #if(MCU_CLMA0_OPERATION == STD_ON)
  /* Element containing value of CLMA0CMPL register */
  uint16 usCLMA0CMPL;
  /* Element containing value of CLMA0CMPH register */
  uint16 usCLMA0CMPH;
  #endif  /* #if(MCU_CLMA0_OPERATION == STD_ON) */
  #if(MCU_CLMA1_OPERATION == STD_ON)
  /* Element containing value of CLMA1CMPL register */
  uint16 usCLMA1CMPL;
  /* Element containing value of CLMA1CMPH register */
  uint16 usCLMA1CMPH;
  #endif /* #if(MCU_CLMA1_OPERATION == STD_ON) */
  #if(MCU_CLMA2_OPERATION == STD_ON)
  /* Element containing value of CLMA2CMPL register */
  uint16 usCLMA2CMPL;
  /* Element containing value of CLMA2CMPH register */
  uint16 usCLMA2CMPH;
  #endif /* #if(MCU_CLMA2_OPERATION == STD_ON) */
  #if(MCU_CLMA3_OPERATION == STD_ON)
  /* Element containing value of CLMA3CMPL register */
  uint16 usCLMA3CMPL;
  /* Element containing value of CLMA3CMPH register */
  uint16 usCLMA3CMPH;
  #endif /* #if(MCU_CLMA3_OPERATION == STD_ON) */
  /* Element to handle the CVM detection enabling  */
  uint8 ucCvmIndicationReg;
  /* Element to handle the CVM reset enabling  */
  uint32 ulCvmResetEnableReg;

} Mcu_ConfigType;

/* Status value returned by the API Mcu_GetPllStatus */
/* TRACE [R4, MCU231] */
typedef enum ETag_Mcu_PllStatusType
{
  MCU_PLL_LOCKED = 0,
  MCU_PLL_UNLOCKED,
  MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

/* Type of reset supported by the hardware */
/* TRACE [R4, MCU134] */
/* TRACE [R4, MCU234] */
typedef enum ETag_Mcu_ResetType
{
  MCU_POWER_ON_RESET = 0,
  MCU_PIN_RST,
  MCU_SW_RESET,
  MCU_WATCHDOG_RESET,
  MCU_LOCK_STEP_CORE_RST,
  MCU_CLMA0_UPPER_LIMIT_RST,
  MCU_CLMA0_LOWER_LIMIT_RST,
  MCU_CLMA2_UPPER_LIMIT_RST,
  MCU_CLMA2_LOWER_LIMIT_RST,
  MCU_CLMA1_UPPER_LIMIT_RST,
  MCU_CLMA1_LOWER_LIMIT_RST,
  MCU_CLMA3_UPPER_LIMIT_RST,
  MCU_CLMA3_LOWER_LIMIT_RST,
  MCU_LRAM_ECC2_ADDPTY_RST,
  MCU_CASHE_RAM_ECC2_RST,
  MCU_CFLH_ECC2_ADDPTY_RST,
  MCU_DATA_FLSH_ECC2_RST,
  MCU_DTS_RAM_ECC2_RST,
  MCU_CSIH_RAM_ECC2_RST,
  MCU_CAN_RAM_ECC2_RST,
  MCU_FLXR_RAM_ECC2_RST,
  MCU_MODE0_RST,
  MCU_MODE1_RST,
  MCU_MODE2_RST,
  MCU_PEGUARD_RST,
  MCU_PBUSGUARD_RST,
  MCU_SAR_ADC_PTY_RST,
  MCU_DATA_PRTY_RST,
  MCU_ECM_COMP_RST,
  MCU_LVI_RST,
  MCU_TEMP_SENSE_RST,
  MCU_DMA_TRANSF_RST,
  MCU_DMA_REG_PROTECT_RST,
  MCU_LRAM_ECC1_PTY_RST,
  MCU_CFLH_ECC1_RST,
  MCU_DATA_FLSH_ECC1_RST,
  MCU_DTS_RAM_ECC1_RST,
  MCU_ALL_PERI_RAM_ECC1_RST,
  MCU_BIST_ECC1_RST,
  MCU_BIST_ECC2_RST,
  MCU_FACI_TRANSF_RST,
  MCU_ECM_DELY_OVRFLW_RST,
  MCU_CVM_RST,
  MCU_RESET_UNDEFINED,
  MCU_RESET_UNKNOWN
} Mcu_ResetType;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/* Status value returned by the API Mcu_GetRamState */
typedef enum ETag_Mcu_RamStateType
{
  MCU_RAMSTATE_VALID = 0,
  MCU_RAMSTATE_INVALID
} Mcu_RamStateType;
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/* Ram write size type for ram initialization  */
typedef enum ETag_Mcu_ClmaIndexType
{
  MCU_CLMA0 = (uint8)0x00,
  MCU_CLMA1,
  MCU_CLMA2,
  MCU_CLMA3
} Mcu_ClmaIndexType;

#endif /* MCU_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
