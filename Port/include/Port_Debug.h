/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Debug.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of global variables for debugging purpose.                       */
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
 * V1.0.0:  13-Jun-2013  : Initial Version
 *
 * V1.0.1:  05-Aug-2013  : As per CR 225, as part of merging activity, Header
 *                         and Environment sections are updated to change the
 *                         device name.
 */
/******************************************************************************/
#ifndef PORT_DEBUG_H
#define PORT_DEBUG_H
/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/*
 * Since all the debug variables will be available in Port_Ram.h it
 * is included.
 */
#include "Port_Ram.h"
/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
/* AUTOSAR release version information */
#define PORT_DEBUG_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_DEBUG_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_DEBUG_AR_RELEASE_REVISION_VERSION \
                                     PORT_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define PORT_DEBUG_SW_MAJOR_VERSION   PORT_SW_MAJOR_VERSION
#define PORT_DEBUG_SW_MINOR_VERSION   PORT_SW_MINOR_VERSION
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* PORT_DEBUG_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
