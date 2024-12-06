/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Ram.h                                                  */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2013 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the extern declarations of global RAM variables of PORT */
/* Driver                                                                     */
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
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.0.1:  05-Aug-2013  : As per CR 225, as part of merging activity, Header
 *                         and Environment sections are updated to change the
 *                         device name.
 */
/******************************************************************************/
#ifndef PORT_RAM_H
#define PORT_RAM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define PORT_RAM_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_RAM_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_RAM_AR_RELEASE_REVISION_VERSION \
                                          PORT_AR_RELEASE_REVISION_VERSION

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version */
#define PORT_RAM_AR_MAJOR_VERSION  PORT_AR_MAJOR_VERSION_VALUE
#define PORT_RAM_AR_MINOR_VERSION  PORT_AR_MINOR_VERSION_VALUE
#define PORT_RAM_AR_PATCH_VERSION  PORT_AR_PATCH_VERSION_VALUE
#endif

/* Module Software version information */
#define PORT_RAM_SW_MAJOR_VERSION  PORT_SW_MAJOR_VERSION
#define PORT_RAM_SW_MINOR_VERSION  PORT_SW_MINOR_VERSION
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0828) [L] More than 8 levels of nested conditional      */
/*                 inclusion - program does not conform strictly to ISO:C90.  */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : This is due to the counting of nested condition on the     */
/*                 common files which share other modules                     */
/* Verification  : However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0828)-1 and                           */
/*                 END Msg(4:0828)-1 tags in the code.                        */

/******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define PORT_START_SEC_VAR_BOOLEAN
/* MISRA Violation: START Msg(4:0828)-1 */
#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define PORT_START_SEC_VAR_1BIT
#endif
/* END Msg(4:0828)-1 */

#include "MemMap.h"

/* Global variable to store Initialization status of Port Driver Component */
extern VAR (boolean, PORT_INIT_DATA) Port_GblDriverStatus;

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#define PORT_STOP_SEC_VAR_BOOLEAN
/* MISRA Violation: START Msg(4:0828)-1 */
#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define PORT_STOP_SEC_VAR_1BIT
#endif
/* END Msg(4:0828)-1 */

#include "MemMap.h"

#endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

#define PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Global variable to store pointer to Configuration */
extern P2CONST(Port_ConfigType, PORT_VAR, PORT_CONFIG_CONST)
                                             Port_GpConfigPtr;
#define PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_RAM_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
