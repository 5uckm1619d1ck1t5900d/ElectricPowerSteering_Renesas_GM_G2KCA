/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Mcu_Cbk.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for MCU callback Notification    */
/* Functions.                                                                 */
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
 * V1.0.0:  26-Aug-2013 : Initial version
 * V1.1.0:  21-Apr-2014 : Following changes are made:
 *                        1. Copyright information is updated.
 * V1.1.1:  15-Sep-2014 : As per CR 008 and mantis #19850, following change is
 *                        made:
 *                        2. Changes are made at all relevant places
 *                           accordingly to append U or UL after numeric values.
 */
/******************************************************************************/

/*******************************************************************************
**                       Generation Tool Version                              **
*******************************************************************************/
/*
 * TOOL VERSION:    1.1.1
 */
/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*
 * INPUT FILE:    C:\Users\kzdyfh\AppData\Local\Temp\Cfg_Gen-1472502872948-8\AutosarFiles_ValGen-1472503133169-0\Mcu_ECUC_8970060308995407055.arxml
 *                C:\Workspace\_EA4\T1xx\GM_T1XX_EPS_RH850_Working\Mcu\generate\R403_MCU_P1x_BSWMDT.arxml
 * GENERATED ON:  29 Aug 2016 - 16:39:18
 */

#ifndef MCU_CBK_H
#define MCU_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define MCU_CBK_AR_RELEASE_MAJOR_VERSION  4U
#define MCU_CBK_AR_RELEASE_MINOR_VERSION  0U
#define MCU_CBK_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define MCU_CBK_C_SW_MAJOR_VERSION  1U
#define MCU_CBK_C_SW_MINOR_VERSION  0U


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/


#define MCU_START_SEC_APPL_CODE
#include "MemMap.h"

extern FUNC(void, MCU_APPL_CODE) FeNmiOperModErrSngChipInactv (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiDmaRegAcsProtnErr (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr0RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr3RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) RamMemLclRamSngBitEcc (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiDmaTrf (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiOperModErrTestModStrtd (void);
extern FUNC(void, MCU_APPL_CODE) CodFlsSngBitEcc (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr1RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr2RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr1RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr3RtUpprLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiEcmMstChkrCmp (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiOperModErrFlsProgmModStrtd (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr2RtLowrLimFlt (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiPeg (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiWdg (void);
extern FUNC(void, MCU_APPL_CODE) FeNmiClkMonr0RtLowrLimFlt (void);


#define MCU_STOP_SEC_APPL_CODE
#include "MemMap.h"

#endif /* MCU_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
