/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Wdg_59_DriverA_Irq.h                                        */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* ISR functions of the WDG Driver Component.                                 */
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
 * V1.0.1:  23-Jan-2013    : As per SCR 068, in
 *                           WDG_59_DRIVERA_TRIGGERFUNCTION_ISR and
 *                           WDG_59_DRIVERA_ERROR_ISR the pre-compile CAT2
 *                           interrupt condition is updated.
 *
 * V1.0.2:  08-Aug-2013    : As per CR 225, Copyright and Device name are
 *                           updated  as part of merge activity.
 *
 * V1.0.3:  27-Aug-2013    : As per CR 232 for mantis issue 12123 and 13035,
 *                           following changes are made:
 *                           1.Backslash removed for ANSI C code.
 *                           2.Macro 'WDG_59_DRIVERA_START_SEC_PUBLIC_CODE' is
 *                            changed to 'WDG_59_DRIVERA_START_SEC_CODE_FAST'
 *                            and 'WDG_59_DRIVERA_STOP_SEC_PRIVATE_CODE' is
 *                            changed to  'WDG_59_DRIVERA_STOP_SEC_CODE_FAST'
 *                           3. Pointer class 'WDG_59_DRIVERA_PRIVATE_CODE' is
 *                             changed to 'WDG_59_DRIVERA_FAST_CODE'.
 *
 * V1.0.4:  14-Oct-2013    : As per CR 263, Spelling mistake is corrected.
 *
 * V1.0.5:  02-Jun-2014    : As per CR 490, Pre-compile check is added in
 *                           function prototypes section.
 */
/******************************************************************************/
#ifndef WDG_59_DRIVERA_IRQ_H
#define WDG_59_DRIVERA_IRQ_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/*
 * Included for module version information from Wdg_59_DriverA.h and macro
 * definitions required for Wdg_59_DriverA_Irq.c
 */
#include "Wdg_59_DriverA_PBTypes.h"
/* Included for global variable visibility for Wdg_59_DriverA_Irq.c */
#include "Wdg_59_DriverA_Ram.h"
/* Included for interrupt category definitions */
#include "Os.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define WDG_59_DRIVERA_IRQ_AR_RELEASE_MAJOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MAJOR_VERSION
#define WDG_59_DRIVERA_IRQ_AR_RELEASE_MINOR_VERSION \
                                        WDG_59_DRIVERA_AR_RELEASE_MINOR_VERSION
#define WDG_59_DRIVERA_IRQ_AR_RELEASE_REVISION_VERSION \
                                     WDG_59_DRIVERA_AR_RELEASE_REVISION_VERSION

#elif (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* Autosar Specification Version */
#define WDG_59_DRIVERA_IRQ_AR_MAJOR_VERSION \
                                           WDG_59_DRIVERA_AR_MAJOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_AR_MINOR_VERSION \
                                           WDG_59_DRIVERA_AR_MINOR_VERSION_VALUE
#define WDG_59_DRIVERA_IRQ_AR_PATCH_VERSION \
                                           WDG_59_DRIVERA_AR_PATCH_VERSION_VALUE
#endif

/* Module Software version information */
#define WDG_59_DRIVERA_IRQ_SW_MAJOR_VERSION    WDG_59_DRIVERA_SW_MAJOR_VERSION
#define WDG_59_DRIVERA_IRQ_SW_MINOR_VERSION    WDG_59_DRIVERA_SW_MINOR_VERSION

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define WDG_59_DRIVERA_START_SEC_CODE_FAST
#include "MemMap.h"

#if (WDG_59_DRIVERA_AR_VERSION == WDG_59_DRIVERA_AR_HIGHER_VERSION)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR) || \
                              defined (WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, WDG_59_DRIVERA_FAST_CODE)
                                 WDG_59_DRIVERA_TRIGGERFUNCTION_ISR(void);
#endif
#endif

#if (WDG_59_DRIVERA_ERR_MODE_SET == WDG_59_DRIVERA_NMI_MODE)
/* Defines the CAT2 interrupt mapping */
#if defined (Os_WDG_59_DRIVERA_ERROR_CAT2_ISR) || \
                                        defined (WDG_59_DRIVERA_ERROR_CAT2_ISR)
/* Use ISR() macro from Os.h */
/* Defines the CAT1 interrupt mapping */
#else
extern _INTERRUPT_ FUNC(void, WDG_59_DRIVERA_FAST_CODE)
                                           WDG_59_DRIVERA_ERROR_ISR(void);
#endif
#endif
#define WDG_59_DRIVERA_STOP_SEC_CODE_FAST
#include "MemMap.h"

#endif /* WDG_59_DRIVERA_IRQ_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
