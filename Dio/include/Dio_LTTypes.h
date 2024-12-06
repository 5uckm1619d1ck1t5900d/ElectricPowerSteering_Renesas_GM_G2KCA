/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_LTTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright (c) 2012-2015 by Renesas Electronics Corporation                 */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision of AUTOSAR DIO Link Time Parameters                              */
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
 * V1.0.0:  23-Aug-2012  : Initial version
 *
 * V1.0.1:  14-Sep-2012  : As per SCR 013, updated the Alignment.
 *
 * V1.0.2:  08-Aug-2013  : As per CR 225, Copyright information, Device name and
 *                         Project name are updated as part of merge activity.
 *
 * V1.0.3:  17-Sep-2013  : As per CR 241, DIO_PPR_OFFSET macros are removed from
 *                         Global symbol section.
 *
 * V1.0.4:  04-Feb-2014  : As per CR 394 and merge activity code is updated.
 *
 * V1.0.5:  06-Mar-2014  : As per CR 428, SchM critical section protection
 *                         macros are added.
 *
 * V1.0.6:  08-Apr-2014  : As per CR 475, definition is updated for macro
 *                         DIO_ZERO.
 *
 * V1.0.7:  24-Apr-2014  : As per CR 488, variable name ucModeMask is updated as
 *                         ulModeMask.
 *
 * V1.0.8:  28-Jul-2014  : As per CR 564 and mantis #21425, DIO_SHIFT_SIXTEEN
 *                         macro is added.
 *
 * V1.0.9:  06-Aug-2014  : Following changes are made:
 *                         1.As per mantis #22811, Order of declaration Of
 *                           structure elements ulModeMask and ucPortType are
 *                           interchanged to avoid structure padding.
 *
 * V1.0.10: 20-Aug-2014  : As per CR 569, following changes are done:
 *                         1.DIO_MSB_MASK macro is deleted.
 *                         2.Extra space present before == is removed.
 *                         3.Precompile option is added for Extern declarations
 *                           for Global Data.
 *                         4.MISRA C rule violation comment is added for
 *                           (4:0750)-1, (4:3453)-2 and (4:3684)-3.
 *
 * V1.0.11: 22-Sep-2014  : As per CR 629, Precompile option is deleted for
 *                         Extern declarations for Global Data.
 *
 * V1.0.12: 30-Aug-2014  : As per mantis #23838, Precompile option is deleted
 *                         from Global Symbols section.
 *
 * V1.0.13: 18-Dec-2014  : As per mantis #24187, Critical section macros
 *                         are updated.
 * V1.0.14: 02-Feb-2015  : As part of merging activity(mantis #26024 )
 *                         following changes are made:
 *                         1. Volatile declaration is added for LpPortAddress
 *                            to consider the compiler optimization.
 *                         2. Copyright information is updated.
 */
/******************************************************************************/

#ifndef DIO_LTTYPES_H
#define DIO_LTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Dio.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define DIO_LTTYPES_AR_MAJOR_VERSION  DIO_AR_MAJOR_VERSION_VALUE
#define DIO_LTTYPES_AR_MINOR_VERSION  DIO_AR_MINOR_VERSION_VALUE
#define DIO_LTTYPES_AR_PATCH_VERSION  DIO_AR_PATCH_VERSION_VALUE

/* File version information */
#define DIO_LTTYPES_SW_MAJOR_VERSION  DIO_SW_MAJOR_VERSION_VALUE
#define DIO_LTTYPES_SW_MINOR_VERSION  DIO_SW_MINOR_VERSION_VALUE

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0750) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : For accessing 32-bit PSR register separately for lower     */
/*                 16-bit data and upper 16-bit mask.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0750)-1 and                           */
/*                 END Msg(4:0750)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/* Rule          : MISRA-C:2004 Rule 19.7                                     */
/* Justification : The macros are used to differentiate the SchM functions    */
/*                 for common Autosar R3.2 and R4.0 implementation.           */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3453)-2 and                           */
/*                 END Msg(4:3453)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-3 and                           */
/*                 END Msg(4:3684)-3 tags in the code.                        */
/******************************************************************************/
/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3412) Array declared with unknown size.                 */
/* Rule          : MISRA-C:2004 Rule 19.4                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3412)-4 and                           */
/*                 END Msg(4:3412)-4 tags in the code.                        */
/******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define DIO_NORMALPORT                  (Dio_PortType)2
#define DIO_JTAGPORT                    (Dio_PortType)1
#define DIO_INPUTPORT                   (Dio_PortType)0
#define DIO_ZERO                        (uint16)0x0000
#define DIO_SHIFT_SIXTEEN               (uint8)0x10

#if (DIO_CRITICAL_SECTION_PROTECTION == STD_ON)
 /* MISRA Violation: START Msg(4:3453)-2 */
 /* MISRA Violation: START Msg(4:3412)-4 */
#define DIO_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                                 SchM_Enter_Dio(Exclusive_Area);
/* END Msg(4:3453)-2 */
/* MISRA Violation: START Msg(4:3453)-2 */
#define DIO_EXIT_CRITICAL_SECTION(Exclusive_Area) SchM_Exit_Dio(Exclusive_Area);
/* END Msg(4:3453)-2 */
/* END Msg(4:3412)-4 */
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Structure for Dio Port Group */
typedef struct STag_Dio_PortGroup
{
  /* Address of the port */
  P2VAR(uint32 volatile, AUTOMATIC, DIO_CONFIG_DATA) pPortAddress;
  uint32 ulModeMask;
  /* Type Of the port group,
     0 = Input port,
     1 = Jtag port,
     2 = Numeric/Alphabetic/ Analog port */
  uint8 ucPortType;
} Dio_PortGroup;

/* Structure for Dio Channel */
typedef struct STag_Dio_PortChannel
{
  uint16 usMask;
  /* PortGroup Index in the array Dio_GstPortChannel[] with respect to the
     pointer Dio_GpPortChannel of the corresponding configuration */
  uint8 ucPortIndex;
} Dio_PortChannel;

/* Union for accessing 32 bit PSR register */
/* MISRA Violation: START Msg(4:0750)-1 */
typedef union UTag_Dio_PortData
{
  uint32 ulLongWord;
  struct
  {
    uint16 usLSWord;
    uint16 usMSWord;
  }Tst_WordValue;
} Dio_PortData;
/* END Msg(4:0750)-1 */

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/

#define DIO_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-3 */
extern CONST(Dio_PortGroup, DIO_CONST) Dio_GstPortGroup[];
/* END Msg(4:3684)-1 */
/* MISRA Violation: START Msg(4:3684)-3 */
extern CONST(Dio_PortChannel, DIO_CONST) Dio_GstPortChannel[];
/* END Msg(4:3684)-1 */
#define DIO_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif
/* DIO_LTTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
