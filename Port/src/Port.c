/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port.c                                                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* API function implementations of PORT Driver                                */
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
 * V1.0.1:  27-Sep-2012  : As per SCR 018, following changes are made:
 *                         1. Port_InitConfig API is updated to correct PPCMD
 *                            register size.
 *                         2. Port_SetPinMode API is updated to remove the
 *                            condition check of 'INPUT' PortType for DET Error
 *                            Reporting.
 *                         3. Port_SetPinMode API is updated to remove condition
 *                            check for mode range.
 *                         4. Port_SetPinDirection API is updated to remove the
 *                            condition check of 'INPUT' PortType for DET Error
 *                            Reporting.
 *                         5. Port_InitConfig API is updated to remove condition
 *                            check for LenReturnValue which is not necessary.
 *                         6. Comments are updated.
 *
 * V1.0.2:  17-Oct-2012  : As per SCR 027, following changes are made:
 *                         1. Port_Init API is updated to invoke
 *                            Port_FilterConfig() API for configuration of
 *                            filter registers.
 *                         2. Port_FilterConfig() API is added.
 *                         3. Port_Filter prototype is added under Function
 *                            Prototypes section.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, the following changes are made:
 *                         1.In API Port_Init, PORT_PIN_STATUS_BACKUP
 *                           Pre-compile option and DeepStop mode features are
 *                           updated.
 *                         2.In API Port_InitConfig, Restore registers variable
 *                           are updated with pre-compile option.
 *                         3. Copyright information is updated.
 *
 * V1.2.0:  11-Mar-2013  : As per SCR 091 for mantis #9240, following changes
 *                         are made:
 *                         1. Two APIs 'Port_SetToDioMode' and
 *                            'Port_SetToAlternateMode' are added.
 *                         2. Internal functions Port_SetToDioOrAltMode and
 *                            Port_SearchDioAltModePin are added.
 *
 * V1.2.1:  26-Apr-2013  : As per SCR 155 for mantis #6426,
 *                         PORT_DEM_ERROR_DETECT pre-compile check is added for
 *                         DEM error.
 *
 * V1.2.2:  12-Jun-2013  : As per SCR 177, Pre-compile options updated  while
 *                         merging with R4.0
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11895 and #11215, following changes
 *                         are made:
 *                         1. Port_InitConfig API is updated for the following
 *                            changes:
 *                            a. PUCC register is added.
 *                            b. PPCMD_32BIT_REG_AVAILABLE Pre-compile option is
 *                               added to support PPCMDn register bit size.
 *                         2. Header and Environment sections are updated to
 *                            change the device name.
 *                         3. Port_FilterConfig API is updated for the following
 *                            changes:
 *                            a. Pre-compile option PORT_EDGE_DETECT_CONTROL is
 *                               added to have digital Noise filter edge detect
 *                               control functionality.
 *                            b. Pre-compile option PORT_DNFAEN_REG_AVAILABLE is
 *                               added to have DNFAnEN register for F1x variant.
 *                         4. Port_Init API is updated to add Pre-compile option
 *                            PORT_IOHOLD_FUNC_AVAILABLE for IOHOLD
 *                            functionality.
 *
 * V1.4.0:  06-Sep-2013  : As per CR 236 for mantis #12110 and #12602, following
 *                         changes are made:
 *                         1. PORT_E_WRITE_FAILURE is changed to
 *                            PORT_E_WRITE_TIMEOUT_FAILURE for DEM error
 *                            reporting.
 *                         2. Port_InitConfig API is updated to add PUCC and
 *                            PINV registers.
 *                         3. Port_SetPinDirection API is updated to add
 *                            Pre-compile option 'PORT_PINV_REG_AVAILABLE' to
 *                            have Port pin level inversion functionality.
 *                         4. Endless loop exit is implemented using macro
 *                            PORT_LOOP_TIMEOUT.
 *
 * V1.4.1:  18-Nov-2013  : As per CR 295, Port_SetPinDirection API is updated
 *                         to remove PORT_OS_BASE_ADDRESS_ANALOG from Analog
 *                         port group.
 *
 * V1.4.2:  09-Dec-2013  : As per CR 338, Following changes are made:
 *                         1. Misra C violation is updated for Cast between a
 *                            pointer to volatile object and an integral type.
 *                         2. Endif comments added for PORT_PINV_REG_AVAILABLE
 *                            and PORT_DEV_ERROR_DETECT.
 *
 * V1.4.3:  27-Jan-2014  : As per CR 369, Comment modified for value of Mode
 *                         from adding 6 to 0x0E.
 *
 * V1.4.4:  04-Feb-2014  : As per CR 378 for mantis #19208, as part of merging
 *                         activity following changes are made:
 *                         1. File version information is updated.
 *                         2. Port_Init API is updated to correct conditional
 *                            check for PORT_DBTOC_VALUE.
 *
 * V1.5.0:  21-Feb-2014  : As per CR 419 for mantis #19676, following changes
 *                         are made:
 *                         1. Two APIs 'Port_SetPinDefaultDirection' and
 *                            'Port_SetPinDefaultMode' are added.
 *                         2. PORT_CRITICAL_SECTION_PROTECTION is added for
 *                            Port_SetPinDirection, Port_InitConfig,
 *                            Port_RefreshPortInternal, Port_SetToDioOrAltMode.
 *
 * V1.5.1:  29-Apr-2014  : As per CR 491 for mantis #20657, #21388 and #21668,
 *                         following changes are made:
 *                         1. End comment for Port_SetPinDefaultMode is updated
 *                            from Port_SetPinMode.
 *                         2. Typos with the code comments and alignment are
 *                            updated.
 *                         3. Critical Section Protection for
 *                            Port_SetToDioOrAltMode is updated.
 *
 * V1.5.2:  03-Jul-2014  : As per CR 543 for mantis #22125 and 22038, following
 *                         changes are made:
 *                         1. In Port_SetToDioOrAltMode API, PORT_PUBLIC_CODE is
 *                            updated to PORT_PRIVATE_CODE.
 *                         2. In API Port_InitConfig, pre-compile check
 *                            PORT_PIN_STATUS_BACKUP is added for
 *                            PORT_JTAG_PORT_GROUPS_AVAILABLE and
 *                            PORT_INPUT_PORT_GROUPS_AVAILABLE.
 *                         3. Tab space is removed.
 *
 * V1.5.3:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, following changes are made:
 *                         1. Equivalence Test is carried out throughout the
 *                            file to have a constants on the left hand side of
 *                            the check.
 *                         2. AUTOSAR violations and SWS Requirements are
 *                            mapped.
 *                         3. Port_FilterConfig API is updated to add
 *                            Pre-compile option PORT_DNF_CLK_SRC_AVAILABLE to
 *                            have digital Noise filter clock source
 *                            functionality.
 *                         4. Code is updated for Hardware Register Access
 *                            using volatile pointer.
 *
 * V1.5.4:  22-Aug-2014  : As per CR 570, following changes are made:
 *                         1. Port_SetPinDefaultMode and
 *                            Port_SetPinDefaultDirection API's are modified to
 *                            update the register functionality.
 *                         2. MISRA C Rule Violations are updated as per QAC
 *                            8.1.1.
 *                         3. Global Variable is updated for
 *                            Port_SetToDioOrAltMode.
 *
 * V1.5.5:  10-Oct-2014  : As per CR 638, following changes are made:
 *                         1. Msg(4:2986) has been removed from MISRA C Rule
 *                            Violations and from the file.
 *                         2. PORT_ALPHA_PORT_GROUPS_AVAILABLE for type casting.
 *                         3. Msg(4:1891) has been added in respective places.
 *                         4. Port_SetPinDefaultDirection description has been
 *                            updated.
 *
 * V1.5.6:  28-Jan-2015  : As per Mantis #25131,#24335,#25147,#23322,#25484
 *                         #24138,#23493,#24167 following changes are made:
 *                         1. Port_SetPinMode API is modified to update the
 *                            PIPC and PSR register functionality.
 *                         2. Port_SetToDioOrAltMode API is modified to add
 *                            checks for availability of ANALOG and INPUT Port
 *                            groups and PIPC register functionality.
 *                         3. Port_InitConfig() API is modified to add
 *                            'LenReturnValue' check in while-loop processing.
 *                            Register initialization sequence is updated.
 *                         4. Port_SetPinDirection API is updated to check for
 *                            requested and current direction.
 *                         5. Port_SetPinDirection and Port_Init API are
 *                            updated for  DEM error checks
 *                         6. Copyright information is updated.
 *                         7. Port_FilterConfig API is updated to add delay
 *                            after enabling the digital filter.
 *                         8. Port_InitConfig() API is modified for register
 *                            initialization sequence
 *                         9. Port_SetPinDefaultMode API is updated to check for
 *                            mode and direction before updating PSR register.
 *
 * V1.5.7     12-Feb-2015   As per merge activity(#26024), following changes are
 *                         adapted from R1x and P1x.
 *                         1. Port_SetInitialValue() API is added.
 *                         2. PPROTS_32BIT_REG_AVAILABLE Pre-compile option is
 *                            added to support PPROTSn register size in API's
 *                            Port_InitConfig() and Port_SetPinDirection().
 *                         3. volatile is added for variables which holds
 *                            register addresses.
 *                         4. Port_InitConfig() API is modified to add
 *                            'LenReturnValue' check in while-loop processing.
 *                         5. Port_InitConfig() API is updated to add PIBC, PU,
 *                            PBDC, PIS, PIPC register values.
 *                         6. Port_SetPinDefaultMode() API is updated to change
 *                            the order of register setting.
 *
 * V1.5.8     25-Mar-2015   Following Changes are made:
 *                          1.Static Analysis done and all Misra violations are
 *                            justified.
 *                          2.To justify the misra violation, Ecode is updated
 *                            form "LpPMSRReg = PORT_ZERO" to
 *                            "LpPMSRReg = NULL_PTR".
 * V1.5.9     09-Apr-2015   Following Changes are made:
 *                          1.Datatype of local variables LucNoOfRegs and
 *                            LblJtag changed from "volatile uint" to "uint".
 *                          2."Else" statement is added for following "If"
 *                          statement
 *                          "if (PORT_REG_NOTAVAILABLE !=
 *                                     LpSetPinModeGroupStruct->ucPIPCRegIndex)"
 *                          in "Port_SetPinMode" API.
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Port.h inclusion and macro definitions */
/* TRACE [R3, PORT131][R4, PORT131] */
#include "Port.h"
#include "Port_PBTypes.h"
#if (PORT_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
/* TRACE [R4, PORT131] */
#include "Det.h"
#endif
#if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
/* Included for the declaration of the critical section protection functions */
/* TRACE [R4, PORT131] */
#include "SchM_Port.h"
#endif
/* TRACE [R3, PORT115][R4, PORT115] */
/* Included for declaration of the function Dem_ReportErrorStatus() */
#include "Dem.h"
/* Included for RAM variable declarations */
#include "Port_Ram.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define PORT_C_AR_RELEASE_MAJOR_VERSION     PORT_AR_RELEASE_MAJOR_VERSION_VALUE
#define PORT_C_AR_RELEASE_MINOR_VERSION     PORT_AR_RELEASE_MINOR_VERSION_VALUE
#define PORT_C_AR_RELEASE_REVISION_VERSION \
                                         PORT_AR_RELEASE_REVISION_VERSION_VALUE

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
/* TRACE [R3, PORT114] */
/* AUTOSAR release version information */
#define PORT_C_AR_MAJOR_VERSION     PORT_AR_MAJOR_VERSION_VALUE
#define PORT_C_AR_MINOR_VERSION     PORT_AR_MINOR_VERSION_VALUE
#define PORT_C_AR_PATCH_VERSION     PORT_AR_PATCH_VERSION_VALUE
#endif

/* File version information */
/* TRACE [R3, PORT114] */
#define PORT_C_SW_MAJOR_VERSION    1
#define PORT_C_SW_MINOR_VERSION    5
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
#if (PORT_AR_RELEASE_MAJOR_VERSION != PORT_C_AR_RELEASE_MAJOR_VERSION)
  #error "Port.c : Mismatch in Release Major Version"
#endif
#if (PORT_AR_RELEASE_MINOR_VERSION != PORT_C_AR_RELEASE_MINOR_VERSION)
  #error "Port.c : Mismatch in Release Minor Version"
#endif
#if (PORT_AR_RELEASE_REVISION_VERSION != PORT_C_AR_RELEASE_REVISION_VERSION)
  #error "Port.c : Mismatch in Release Revision Version"
#endif

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#if (PORT_AR_MAJOR_VERSION != PORT_C_AR_MAJOR_VERSION)
  #error "Port.c : Mismatch in Specification Major Version"
#endif

#if (PORT_AR_MINOR_VERSION != PORT_C_AR_MINOR_VERSION)
  #error "Port.c : Mismatch in Specification Minor Version"
#endif

#if (PORT_AR_PATCH_VERSION != PORT_C_AR_PATCH_VERSION)
  #error "Port.c : Mismatch in Specification Patch Version"
#endif
#endif

#if (PORT_SW_MAJOR_VERSION != PORT_C_SW_MAJOR_VERSION)
  #error "Port.c : Mismatch in Software Major Version"
#endif
#if (PORT_SW_MINOR_VERSION != PORT_C_SW_MINOR_VERSION)
  #error "Port.c : Mismatch in Software Minor Version"
#endif
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0759) An object of union type has been defined.         */
/* Rule          : MISRA-C:2004 Rule 18.4                                     */
/* Justification : Data access of larger data types is used to achieve        */
/*                 better throughput.                                         */
/* Verification  : However, part of the code is verified manually and         */
/*                 it is not having any impact.                               */
/* Reference     : Look for START Msg(4:0759)-1 and                           */
/*                 END Msg(4:0759)-1 tags in the code.                        */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0303) Cast between a pointer to volatile object and     */
/*                 an integral type.                                          */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0303)-2 and                           */
/*                 END Msg(4:0303)-2 tags in the code.                        */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0306) [I] Cast between a pointer to object and an       */
/*                 integral type.                                             */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : Typecasting is done as per the register size, to access    */
/*                 hardware registers.                                        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0306)-3 and                           */
/*                 END Msg(4:0306)-3 tags in the code.                        */

/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2985) This operation is redundant. The value of the     */
/*                  result is always that of the left-hand operand.           */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The value of the result will be calculated based on the    */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2985)-4 and                           */
/*                 END Msg(4:2985)-4 tags in the code.                        */

/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2962) Apparent: Using value of uninitialized            */
/*                  automatic object.                                         */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The value of the result will be calculated based on the    */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2962)-5 and                           */
/*                 END Msg(4:2962)-5 tags in the code.                        */

/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:0488) Performing Pointer arithmetic.                    */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : This is to get the ID in the data structure in the code.   */
/*Verification   : However, part of the code is verified manually             */
/*                 and it is not having any impact.                           */
/*Reference      : Look for START Msg(4:0488)-6 and                           */
/*                 END Msg(4:0488)-6  tags in the code.                       */

/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0489) The integer value 1 is being added or             */
/*                  subtracted from a pointer.                                */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : Increment operator is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0489)-7 and                           */
/*                 END Msg(4:0489)-7 tags in the code.                        */

/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2984) This operation is redundant. The value of the     */
/*                  result is always '0'.                                     */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/* Justification : The value of the result will be calculated based on the    */
/*                 configuration                                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2984)-8 and                           */
/*                 END Msg(4:2984)-8 tags in the code.                        */

/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (2:4397) An expression which is the result of a ~ or <<    */
/*                 operation has not been cast to its essential type.         */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : Though the bitwise operation is performed on unsigned      */
/*                 data, this warning is generated by the QAC tool V8.1.1 as  */
/*                 an indirect result of integral promotion in complex bitwise*/
/*                 operations.                                                */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(2:4397)-9 and                           */
/*                 END Msg(2:4397)-9 tags in the code.                        */

/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3393) Extra parentheses recommended. An arithmetic      */
/*                 operation (* / + -) is the operand of a different operator */
/*                 with the same precedence.                                  */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : parentheses is applied to calculte the register address    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3393)-10 and                          */
/*                 END Msg(4:3393)-10 tags in the code.                       */

/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:1891) A composite expression of 'essentially unsigned'  */
/*                 type (unsigned short) is being implicitly converted to a   */
/*                 wider unsigned type, 'unsigned long'.                      */
/* Rule          : MISRA-C:2004 Rule 11.3                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : unsigned type is offset address being added to base address*/
/*                 to calculate register address                              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:1891)-11 and                          */
/*                 END Msg(4:1891)-11 tags in the code.                       */

/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:3138) Null statement is located close to other code or  */
/*                 comments..                                                 */
/* Rule          : MISRA-C:2004 Rule 14.3                                     */
/* Justification : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3138)-12 and                          */
/*                 END Msg(4:3138)-12 tags in the code.                       */

/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (6:0857) Number of macro definitions exceeds 1024 -        */
/*                 program does not conform strictly to ISO:C90.              */
/* Rule          : MISRA-C:2004 Rule                                          */
/* Justification : Number of macro definitions exceeds 1024,                  */
/*                 Since these much macros are are required in program        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(6:0857)-13 and                          */
/*                 END Msg(6:0857)-13 tags in the code.                       */

/******************************************************************************/

/* 14. MISRA C RULE VIOLATION:                                                 */
/* Message       : (5:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified.                */
/* Rule          : NA                                                         */
/* Justification : The variable that is being assigned is of return type .If  */
/*                 any error occurs it will return the default assigned value.*/
/* Verification  : However, part of the code is verified manually and it does */
/*                 not have any impact.                                       */
/* Reference     : Look for START Message(5:2982)-14 and                       */
/*                 END Message(5:2982)-14 tags in the code.                    */

/******************************************************************************/

/*******************************************************************************
**                  Function Prototypes                                       **
*******************************************************************************/
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC (void, PORT_PRIVATE_CODE) Port_InitConfig
                                                 (Port_GroupType LenGroupType);

STATIC FUNC (void, PORT_PRIVATE_CODE) Port_SetInitialValue
                                                 (Port_GroupType LenGroupType);

#if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
STATIC FUNC (void, PORT_PRIVATE_CODE) Port_FilterConfig(void);
#endif

#if (PORT_SET_PIN_DIRECTION_API == STD_ON) || \
                         (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON)
STATIC
FUNC (P2CONST (Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchDirChangeablePin(Port_PinType LddPinNumber,
    P2CONST (Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
    LpStartPtr, uint8 Lucsize);
#endif

STATIC FUNC (void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                                                 (Port_GroupType LenGroupType);

#if ((PORT_SET_PIN_MODE_API == STD_ON) || \
                              (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON))
STATIC
FUNC (P2CONST(Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
     PORT_PRIVATE_CODE)Port_SearchModeChangeablePin(Port_PinType LddPinNumber,
     P2CONST(Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
     LpStartPtr, uint8 Lucsize);
#endif

#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
STATIC
FUNC(P2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
  PORT_PRIVATE_CODE) Port_SearchDioAltModePin(Port_PinType LddPinNumber,
  P2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
  LpStartPtr, uint8 Lucsize);

STATIC
FUNC (void, PORT_PRIVATE_CODE) Port_SetToDioOrAltMode (Port_PinType Pin,
                                              boolean LblDioMode);
#endif

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
**                  Function Definitions                                      **
*******************************************************************************/
/* TRACE [R3, PORT140][R4, PORT140] */
/*******************************************************************************
** Function Name         : Port_Init
**
** Service ID            : 0x00
**
** Description           : This service performs initialization of the PORT
**                         Driver components.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : ConfigPtr
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError, Port_InitConfig, Port_FilterConfig.
**
** Registers Used        : None
*******************************************************************************/
/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R3, PORT001][R4, PORT001] */
/* Initialize the Port Driver module */

/* TRACE [R3, PORT041][R4, PORT041] */
/* TRACE [R3, PORT078][R4, PORT078] */
/* TRACE [R3, PORT042][R4, PORT042] */
/* TRACE [R3, PORT213][R4, PORT213] */
/* TRACE [R3, PORT003][R4, PORT003] */
FUNC (void, PORT_PUBLIC_CODE) Port_Init
(P2CONST (Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr)
{
  #if (PORT_IOHOLD_FUNC_AVAILABLE == STD_ON)
  uint8 LucLoopCount;
  #endif /* End of PORT_IOHOLD_FUNC_AVAILABLE == STD_ON */

  /*
   * If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, PORT077][R4, PORT077] */
  /* TRACE [R3, PORT105][R4, PORT105] */
  /* TRACE [R3, PORT121][R4, PORT121] */
  /* Report to DET, if the config pointer value is NULL */
  if (NULL_PTR == ConfigPtr)
  {
    /* TRACE [R3, PORT087][R4, PORT087] */
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                            PORT_E_PARAM_CONFIG);
  } /* End of ConfigPtr == NULL_PTR */
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(2:4397)-9 */
    if (PORT_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    /* END Msg(2:4397)-9 */
    {
      /* Assign the config pointer value to global pointer */
      Port_GpConfigPtr = ConfigPtr;

      /* Check for available Port Group Type(Numeric Port) */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_SetInitialValue() API with Numeric Port Group data */
      Port_SetInitialValue (PORT_GROUP_NUMERIC);
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Alphabetic Port) */
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_SetInitialValue() API with Alphabetic Port Group data */
      Port_SetInitialValue (PORT_GROUP_ALPHABETIC);
      #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(JTag Port) */
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_SetInitialValue() API with JTag Port Group data */
      Port_SetInitialValue (PORT_GROUP_JTAG);
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Analog Port) */
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_SetInitialValue() API with Analog Port Group data */
      Port_SetInitialValue (PORT_GROUP_ANALOG);
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Input Port) */
      #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_SetInitialValue() API with Input Port Group data */
      Port_SetInitialValue (PORT_GROUP_INPUT);
      #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */

      #if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
      /* Invoking Port_FilterConfig() for configuration of filter registers */
      /* TRACE [R3, PORT043][R4, PORT043] */
      Port_FilterConfig ();
      #endif /*
              * End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
              * (PORT_FCLA_REG_CONFIG == STD_ON)
              */

      /* Check for available Port Group Type(Numeric Port) */
      #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Numeric Port Group data */
      Port_InitConfig (PORT_GROUP_NUMERIC);
      #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Alphabetic Port) */
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Alphabetic Port Group data */
      Port_InitConfig (PORT_GROUP_ALPHABETIC);
      #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(JTag Port) */
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with JTag Port Group data */
      Port_InitConfig (PORT_GROUP_JTAG);
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Analog Port) */
      #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Analog Port Group data */
      Port_InitConfig (PORT_GROUP_ANALOG);
      #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */

      /* Check for available Port Group Type(Input Port) */
      #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
      /* Invoking Port_InitConfig() API with Input Port Group data */
      Port_InitConfig (PORT_GROUP_INPUT);
      #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */

      /*
       * If DET is enabled, the API parameter checking shall be performed
       * according to the respective functions
       */
      /* TRACE [R3, PORT031] */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* Set the Port status to initialized */
      Port_GblDriverStatus = PORT_INITIALIZED;
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

      #if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))
      /* Invoking Port_FilterConfig() for configuration of filter registers */
      /* TRACE [R3, PORT043][R4, PORT043] */
      Port_FilterConfig ();
      #endif /*
              * End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
              * (PORT_FCLA_REG_CONFIG == STD_ON)
              */

      #if (PORT_IOHOLD_FUNC_AVAILABLE == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      if ((PORT_IOHOLD & PORT_IOHOLD_MASK) == PORT_IOHOLD_MASK)

      /* END Msg(4:0303)-2 */
      {
        LucLoopCount = PORT_LOOP_TIMEOUT;
        /* MISRA Violation: START Msg(4:0303)-2 */
        do
        {
          /* Write the write enable register */
          PORT_PROTCMD0 = PORT_WRITE_ERROR_CLEAR_VAL;
          /* Mask the IOHOLD bit */
          PORT_IOHOLD = PORT_IOHOLD_CLEAR;
          PORT_IOHOLD = ~PORT_IOHOLD_CLEAR;
          PORT_IOHOLD = PORT_IOHOLD_CLEAR;
          LucLoopCount--;

        } while ((PORT_ZERO < LucLoopCount) && (PORT_ONE == PORT_PROTS0));

        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        #if (PORT_DEM_ERROR_DETECT == STD_ON)
        if (PORT_PROTS0 == PORT_ONE)

        {
          /*
           * AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per
           * mantis #6426, the configurable pre-compile switch for detection of
           * production code errors is added
           */

          /* TRACE [R3, PORT037][R4, PORT037] */
          /* END Msg(4:0303)-2 */
          /*
           * Writing to write-protected register failed and
           * report production error
           */
          /* TRACE [R3, PORT146][R4, PORT146] */
          Dem_ReportErrorStatus(PORT_E_WRITE_TIMEOUT_FAILURE,
                                     (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

        } /* End of PORT_PROTS0 == PORT_ONE */
        else
        {
          /* No action required */
        }
        #endif
      }
      else
      {
        /* No action required */
      }
        #endif /* End of PORT_IOHOLD_FUNC_AVAILABLE == STD_ON */
    }
    /*If there is no valid database is present */
    else
    {
      /*
       * If DET is enabled, the API parameter checking shall be performed
       * according to the respective functions
       */
      /* TRACE [R3, PORT031] */
      #if (PORT_DEV_ERROR_DETECT == STD_ON)
      /* TRACE [R3, PORT077][R4, PORT077] */
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                                          PORT_E_INVALID_DATABASE);
      #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
    }
  }
} /* End of API Port_Init */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R3, PORT141][R4, PORT141] */
/*******************************************************************************
** Function Name         : Port_SetPinDirection
**
** Service ID            : 0x01
**
** Description           : This service sets the port pin direction during
**                         runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Direction - Port Pin Direction
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_Init().
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_SET_PIN_DIR_PROTECTION,
**                         SchM_Exit_Port_SET_PIN_DIR_PROTECTION,
**                         Port_SearchDirChangeablePin
**
** Registers Used        : PSR, PMSR.
*******************************************************************************/
/* The function Port_SetPinDirection shall be available if the pre-compile
 * parameter PortSetPinDirectionApi is set to TRUE
 */
/* TRACE [R4, PORT086] */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDirection
(Port_PinType Pin, Port_PinDirectionType Direction)
{
  P2CONST(volatile Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                             LpChangeablePinDet;
  #if (PORT_PINV_REG_AVAILABLE == STD_ON)
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  #else
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
  #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) Lp32BitPPROTSRegAdd;
  #else
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) Lp8BitPPROTSRegAdd;
  #endif
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) Lp32BitRegAddress;
  boolean LblNumAlpha = PORT_ZERO;
  boolean LblJtag = PORT_ZERO;
  uint32 LulOsBaseAddress;
  uint8 LucLoopCount;
  uint8 LucPortGroupIndex;
  #endif /* End of (PORT_PINV_REG_AVAILABLE == STD_ON) */

  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;
  /* END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint16 LusCurrentDirection;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

  /* Initialize the pointer to null pointer */
  LpChangeablePinDet = NULL_PTR;

  /*
   * If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, PORT077][R4, PORT077] */
  /* Check whether the PORT module is initialized */
  /* TRACE [R3, PORT087][R4, PORT087] */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                               PORT_SET_PIN_DIR_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }
  /* TRACE [R3, PORT087][R4, PORT087] */
  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_PIN_DIR_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* TRACE [R3, PORT086] */
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);

    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpChangeablePinDet)
    {
      /* TRACE [R3, PORT087][R4, PORT087] */
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                 PORT_SET_PIN_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_OFF)

    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    #endif /* End of PORT_DEV_ERROR_DETECT == STD_OFF */

    /* Get the base address of the corresponding Port Type */

    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_NUMERIC == LpChangeablePinDet->ucPortType)
    {
      /* Get the Base address of Numeric Port */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
      #if (PORT_PINV_REG_AVAILABLE == STD_ON)
      /* Get the pointer to the Numeric Port registers */
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      /* Get the Base address of Numeric Port */
      LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
      LblNumAlpha = PORT_ONE;
      #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((unit8)PORT_GROUP_ALPHABETIC == LpChangeablePinDet->ucPortType)
    {
      /* Get the Base address of Alphabetic Port */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      #if (PORT_PINV_REG_AVAILABLE == STD_ON)
      /* Get the pointer to the Alphabetic Port registers */
      LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
      /* Get the Base address of Alphabetic Port */
      LulOsBaseAddress = PORT_OS_BASE_ADDRESS_ALPHABETIC;
      LblNumAlpha = PORT_ONE;
      #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_JTAG == LpChangeablePinDet->ucPortType)
    {
      /* Get the Base address of JTag Port */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
      #if (PORT_PINV_REG_AVAILABLE == STD_ON)
      /* Get the pointer to the JTag Port registers */
      LpPortReg = Port_GpConfigPtr->pPortJRegs;
      /* Get the Base address of JTag Port */
      LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
      LblJtag = PORT_ONE;
      #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_ANALOG == LpChangeablePinDet->ucPortType)
    {
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
    /*
     * An atomic access to Microcontroller registers by the use of an exclusive
     * area
     */
    /* TRACE [R3, PORT075] */
    /* TRACE [R4, PORT075] */
    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_ENTER_CRITICAL_SECTION(SET_PIN_DIR_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
    /*
     * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
     * variable to 1 of the configured pin whose Direction has to be changed
     */
    LunSRRegContent.Tst_Port_Word.usMSWord = LpChangeablePinDet->usOrMaskVal;
    /* Check if requested direction is OUTPUT and current direction is INPUT. */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* MISRA Violation: START Msg(4:0306)-3 */
    LusCurrentDirection = (uint16)
     (*((uint32 *)(LulBaseAddress + LpChangeablePinDet->usPMSRRegAddrOffset)));
    /* MISRA Violation: END Msg(4:0306)-3 */
    /* MISRA Violation: END Msg(4:2962)-5 */
    /* Check if requested direction is OUTPUT */
    if ((Direction == PORT_PIN_OUT) &&
        ((LusCurrentDirection & LpChangeablePinDet->usOrMaskVal) ==
         LpChangeablePinDet->usOrMaskVal))
    {
      /* AUTOSAR IMPL [R3, PORT082][R4, PORT082] RULE VIOLATION: As per
       * requirement AR_PN0062_FR_0048 Level inversion is implemented to invert
       * the output level of a pin when the pin is in output mode
       */
      #if (PORT_PINV_REG_AVAILABLE == STD_ON)
      LucPortGroupIndex = LpChangeablePinDet->ucPortGroupIndex;

      /* Check if requested direction is OUTPUT */
      if (PORT_INV_NOT_CFG != (LpChangeablePinDet->usPINVRegAddrOffset))
      {
        if (PORT_INV_NOT_CFG != (LpChangeablePinDet->usPortinversionVal))
        {
          /* Initialize the loop count to ten */
          LucLoopCount = PORT_LOOP_TIMEOUT;

          /*
           * Get the register address by adding the offset to the Base address
           */
          Lp32BitRegAddress =
           (uint32 *)(LpChangeablePinDet->usPINVRegAddrOffset + LulBaseAddress);

          /* Get the address of the corresponding PPROTS register */
          #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
          Lp32BitPPROTSRegAdd = (uint32 *)
                (((LpPortReg + LucPortGroupIndex)->usRegAddrOffset -
                (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblNumAlpha) +
                ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblJtag)) +
                 LulOsBaseAddress) +
                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
          #else
          Lp8BitPPROTSRegAdd = (uint8 *)
                (((LpPortReg + LucPortGroupIndex)->usRegAddrOffset -
                (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblNumAlpha) +
                ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblJtag)) +
                 LulOsBaseAddress) +
                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
          #endif

          /* Get the address of the corresponding PPCMD register */
          #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
          LpPPCMDRegAdd = (uint32 *)
                (((LpPortReg + LucPortGroupIndex)->usRegAddrOffset -
                (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblNumAlpha) +
                ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblJtag)) +
                 LulOsBaseAddress) +
                (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));

          #else
          LpPPCMDRegAdd = (uint8 *)
                (((LpPortReg + LucPortGroupIndex)->usRegAddrOffset -
                (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblNumAlpha) +
                ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblJtag)) +
                 LulOsBaseAddress) +
                (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
          #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
          do
          {
            *LpPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
            /*
             * Write the register value to the corresponding register with upper
             * 16 bit set to zero
             */
            *Lp32BitRegAddress = (*Lp32BitRegAddress) |
                  ((LpChangeablePinDet->usPortinversionVal) & (~PORT_MSB_MASK));

            /*
             * Write the bit wise inverse value to the corresponding register
             * with upper 16 bit set to one
             */
            *Lp32BitRegAddress = (*Lp32BitRegAddress) |
            ((uint16)(~LpChangeablePinDet->usPortinversionVal) | PORT_MSB_MASK);
            /*
             * Write the register value to the corresponding register with upper
             * 16 bit set to zero
             */
            *Lp32BitRegAddress = (*Lp32BitRegAddress) |
                  ((LpChangeablePinDet->usPortinversionVal) & (~PORT_MSB_MASK));
            /* Decrement the loop count for each iteration */
            LucLoopCount--;
            /*
             * Check the state of PPROTS register for successful write operation
             * or perform maximum ten tries, if failure occurs report DEM and
             * skip further configuration
             */
          }
          #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
          while (((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd) &&
                                                    (PORT_ZERO < LucLoopCount));
          #else
          while (((uint32)PORT_ONE == *Lp8BitPPROTSRegAdd) &&
                                                    (PORT_ZERO < LucLoopCount));
          #endif

          #if (PORT_DEM_ERROR_DETECT == STD_ON)
          /* Check if the loop has exited because of failure of writing to
           * register
           */
          #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
          if ((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
          #else
          if (PORT_ONE == *Lp8BitPPROTSRegAdd)
          #endif
          {
            /*
             * AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per
             * mantis #6426, the configurable pre-compile switch for detection
             * of production code errors is added
             */
            /* TRACE [R3, PORT037]TRACE [R4, PORT037] */
            /* Report write failure production error */
            /* TRACE [R3, PORT146][R4, PORT146] */
            Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                      (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);


            #if (PORT_DEV_ERROR_DETECT == STD_ON)
            /* Set Return Value as E_NOT_OK */
            LenReturnValue = E_NOT_OK;
            #endif
          } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
          else
          {
            /* No action required */
          }
            #endif
        } /* End of ((LpChangeablePinDet->usPortinversionVal) != PORT_HIGH) */
        else
        {
          /* No action required */
        }
      } /* End of ((LpChangeablePinDet->usPortinversionVal) != PORT_HIGH) */
      else
      {
        /* No action required */
      }
      #endif /* End of (PORT_PINV_REG_AVAILABLE == STD_ON) */



      /* TRACE [R3, PORT138][R4, PORT138] */
      /* Write the Lower word contents with configured Pin Level Value */
      LunSRRegContent.Tst_Port_Word.usLSWord =
                                    LpChangeablePinDet->usChangeableConfigVal;

      /* MISRA Violation: START Msg(4:0306)-3 */
      /* Write the configured value into the register */
      *((uint32 *)(LulBaseAddress + LpChangeablePinDet->usPSRRegAddrOffset)) =
                                           LunSRRegContent.ulRegContent;
      /* END Msg(4:0306)-3 */

      /* Set the requested direction */
      LunSRRegContent.Tst_Port_Word.usLSWord = ~LpChangeablePinDet->usOrMaskVal;
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
       * Bit value of Lower 16 bits (15-0) of PMSR register = Configured value
       * for the corresponding pin position
       */
      *((uint32 *)(LulBaseAddress + LpChangeablePinDet->usPMSRRegAddrOffset)) =
                                                  LunSRRegContent.ulRegContent;
      /* END Msg(4:0306)-3 */

    } /* End of Direction == PORT_PIN_OUT */
    else if (PORT_PIN_IN == Direction)
    {
      /* Requested direction is INPUT */
      LunSRRegContent.Tst_Port_Word.usLSWord = LpChangeablePinDet->usOrMaskVal;
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* Bit value of Upper 16 bits (31-16) of PMSR register is set to 1
       * Bit value of Lower 16 bits (15-0) of PMSR register = Configured value
       * for the corresponding pin position
       */
      *((uint32 *)(LulBaseAddress + LpChangeablePinDet->usPMSRRegAddrOffset)) =
                                                LunSRRegContent.ulRegContent;
      /* END Msg(4:0306)-2 */
    }
    else
    {
        /* No action required */
    }
    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_EXIT_CRITICAL_SECTION(SET_PIN_DIR_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */

    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  } /* End of LenReturnValue == E_OK */

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* End of (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetPinDirection */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

/* TRACE [R3, PORT142][R4, PORT142] */
/*******************************************************************************
** Function Name         : Port_RefreshPortDirection
**
** Service ID            : 0x02
**
** Description           : This service shall refresh the direction of all
**                         configured ports to the configured direction.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus.
**
** Functions Invoked     : Det_ReportError, Port_RefreshPortInternal.
**
** Registers Used        : None
*******************************************************************************/
/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R3, PORT060][R4, PORT060] */
FUNC (void, PORT_PUBLIC_CODE) Port_RefreshPortDirection (void)
{
  /*
   * If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, PORT077][R4, PORT077] */
  /* Check whether the PORT module is initialized */
  /* TRACE [R3, PORT087][R4, PORT087] */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET  */
    (void) Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
               PORT_REFRESH_PORT_DIR_SID, PORT_E_UNINIT);
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with Numeric Group data */
      Port_RefreshPortInternal (PORT_GROUP_NUMERIC);
    }
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with Alphabetic Group data */
      Port_RefreshPortInternal (PORT_GROUP_ALPHABETIC);
    }
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with JTag Group data */
      Port_RefreshPortInternal (PORT_GROUP_JTAG);
    }
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
    {
      /* Invoking Port_RefreshPortInternal API with Analog Group data */
      Port_RefreshPortInternal (PORT_GROUP_ANALOG);
    }
    #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
  }
} /* End of API Port_RefreshPortDirection */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R3, PORT145][R4, PORT145] */
/*******************************************************************************
** Function Name         : Port_SetPinMode
**
** Service ID            : 0x04
**
** Description           : This function used to set the mode of a port pin
**                         during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**                         Mode - New mode to be set on port pin.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_SET_PIN_MODE_PROTECTION,
**                         SchM_Exit_Port_SET_PIN_MODE_PROTECTION,
**                         Port_SearchModeChangeablePin.
**
** Registers Used        : PSR, PMSR, PFCE, PFC, PFCAE, PMCSR.
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, PORT124] */
/* The type Port_PinModeType used with the function call Port_SetPinMode */
FUNC (void, PORT_PUBLIC_CODE) Port_SetPinMode
     (Port_PinType Pin, Port_PinModeType Mode)
{
  /* Pointer to mode changeable pin data structure */
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpModeChangeablePin;

  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;

  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;

  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                                 LpFuncCtrlReg;

  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;

  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST)LpRegAddr;

  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST)Lp16BitRegAddr;

  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;

  /* Variable for revised mode */
  Port_PinModeType LucMode;

  /* END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint16 LusCurrentDirection;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;
  #endif

  /* Initialize the pointer to Null pointer */
  LpModeChangeablePin = NULL_PTR;

  /*
   * If DET is enabled, the API parameter checking shall be performed
   * according to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, PORT077][R4, PORT077] */
  /* Check whether the PORT module is initialized */
  /* TRACE [R3, PORT087][R4, PORT087] */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* TRACE [R3, PORT087][R4, PORT087] */
  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }

  /* TRACE [R3, PORT087][R4, PORT087] */
  /* Check whether the requested mode is invalid
     In case of PortIpControl ON user will pass mode value ORed with 0x80,
     so this is to be masked while checking against the max mode */
  if ((PORT_MAX_MODE < (Mode & PORT_MODE_MASK)) && (Mode < SET_PIPC_MIN_MODE))
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                  PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of (Mode > PORT_MAX_MODE) */
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                              Port_GpConfigPtr->pPinModeChangeableDetails,
                              Port_GpConfigPtr->ucNoOfPinsModeChangeable);

    /* TRACE [R3, PORT087][R4, PORT087] */
    /* TRACE [R4, PORT223] */
    /* Return value LpModeChangeablePin - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpModeChangeablePin)
    {
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of LpModeChangeablePin == NULL_PTR */
    else
    {
      /* No action required */
    }

    if (E_OK == LenReturnValue)
    {
      if ((PORT_DIO_IN < Mode) &&
               ((uint8)PORT_GROUP_ANALOG == (LpModeChangeablePin->ucPortType)))
      {
        /*
         * If the PORT is Analog Port, Mode can be PORT_DIO_OUT or PORT_DIO_IN
         */
        /* TRACE [R3, PORT146][R4, PORT146] */
        /* Report to DET */
        (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                      PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;

      }
      else
      {
        /* No action required */
      } /*
         * End of ((Mode > PORT_DIO_IN) &&
         * ((LpModeChangeablePin->ucPortType) == PORT_GROUP_ANALOG))
         */
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  } /* End of LenReturnValue == E_NOT_OK */

  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_OFF)
    /* Check whether the Pin is mode changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    #endif

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Get the pointer to the Set Mode group list */
    LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                    + (LpModeChangeablePin->ucSetModeIndex));
    /* END Msg(4:0488)-6 */
    /* If the Pin group is of Numeric type */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
    {
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
    else
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_ALPHABETIC == LpModeChangeablePin->ucPortType)
      {
        LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
        LpPortPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
        LpFuncCtrlReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs;
        LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_ALPHABETIC */
      else
      #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        if ((uint8)PORT_GROUP_JTAG == LpModeChangeablePin->ucPortType)
        {
          LpPortReg = Port_GpConfigPtr->pPortJRegs;
          LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
          LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
          LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_JTAG */
        else
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
          if ((uint8)PORT_GROUP_ANALOG == LpModeChangeablePin->ucPortType)
          {
            LpPortReg = Port_GpConfigPtr->pPortAnalogRegs;
            LpPortPMSRReg = Port_GpConfigPtr->pPortAnalogPMSRRegs;
            LulBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
          } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_ANALOG */
          else
          {
            /* No action required */
          }
          #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
        }
      }
    }

    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPIPCRegIndex)
    {
        /* Get the PIPC register Address */
        /* MISRA Violation: START Msg(4:0488)-4 */
        /* MISRA Violation: START Msg(4:1891)-11 */
        /* MISRA Violation: START Msg(4:0306)-3 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        Lp16BitRegAddr = (uint16 *)((LpPortReg +
                LpSetPinModeGroupStruct->ucPIPCRegIndex)->usRegAddrOffset +
                PORT_OS_BASE_ADDRESS_OFFSET + LulBaseAddress);

        if (SET_PIPC_MIN_MODE <= Mode)
        {

        /* If bit needs to be set, OR the register contents with usOrMask */
        *Lp16BitRegAddr =
                (*Lp16BitRegAddr) | (uint16)(LpModeChangeablePin->usOrMask);
        /* MISRA Violation: END Msg(4:0488)-4 */
        /* MISRA Violation: END Msg(4:1891)-11 */
        /* MISRA Violation: END Msg(4:0306)-3 */
        /* END Msg(4:2962)-5 */
        Mode = Mode & PORT_MODE_MASK;
        }
        else
        {
        /* If bit needs to be reset, AND  with inverted usOrMask */
        *Lp16BitRegAddr =
           (uint16)(*Lp16BitRegAddr) & (uint16)(~LpModeChangeablePin->usOrMask);
        }


    }
    else
    {
      /* No action required */
    }

    /* Check if the value of Mode passed is greater than 1 */
    if (PORT_DIO_IN < Mode)
    {
      /* Value of Mode passed is greater than 1. Hence add 14 to the value */
      LucMode = Mode + PORT_MODE_ADJUST;
    }
    else
    {
      /* Keep the same value of Mode */
      LucMode = Mode;
    }

    /*
     * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
     * variable to 1 of the configured pin whose Mode has to be changed
     */
    LunSRRegContent.Tst_Port_Word.usMSWord = LpModeChangeablePin->usOrMask;

    /*
     * An atomic access to Microcontroller registers by the use of an exclusive
     * area
     */
    /* TRACE [R3, PORT075][R4, PORT075] */
    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_ENTER_CRITICAL_SECTION(SET_PIN_MODE_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

      /* MISRA Violation: START Msg(4:0488)-4 */
      /* MISRA Violation: START Msg(4:0306)-3 */
     /* Get the PMSR register Address */
      LpRegAddr = (uint32 *)((LpPortPMSRReg +
                    LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
      /* MISRA Violation: END Msg(4:0306)-3 */
      /* MISRA Violation: END Msg(4:0488)-4 */
      LusCurrentDirection = (((uint16)(*LpRegAddr)) &
                             LpModeChangeablePin->usOrMask);

    if(((Mode == PORT_DIO_IN) ||(Mode == PORT_DIO_OUT)) &&
                  (LusCurrentDirection == PORT_WORD_ZERO))
    {
    /* Write PSR register.Check for PSR register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Write Initial mode register value into Lower word of PSR variable */
      LunSRRegContent.Tst_Port_Word.usLSWord = (LpPortReg +
               LpSetPinModeGroupStruct->ucPSRRegIndex)->usInitModeRegVal;
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0488)-6 */


      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the PSR register Address */
      LpRegAddr = (uint32 *)((LpPortReg +
                  LpSetPinModeGroupStruct->ucPSRRegIndex)->usRegAddrOffset
                  + LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */

      /* TRACE [R3, PORT138][R4, PORT138] */
      /*
       * Bit value of Upper 16 bits (31-16) of PSR register is to set 1
       * Bit value of Lower 16 bits (15-0) of PSR register = Initial value
       * for the corresponding pin position
       */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    } /* LpSetPinModeGroupStruct->ucPSRRegIndex != PORT_REG_NOTAVAILABLE */
    else
    {
      /* No action required */
    }
    }

    /* Write PMSR register.Check for PMSR register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the PMSR register Address */
      LpRegAddr = (uint32 *)((LpPortPMSRReg +
                    LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */
      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT0_MASK))
      {
        /* Write the requested direction into Lower word of PMSR variable
         * by using inverse of OR mask
         */
        LunSRRegContent.Tst_Port_Word.usLSWord = ~LpModeChangeablePin->usOrMask;
      } /* End of (Mode & PORT_BIT0_MASK) == PORT_ZERO */
      else
      {
        /* Write the requested direction into Lower word of PMSR variable
         * by using OR mask
         */
        LunSRRegContent.Tst_Port_Word.usLSWord = LpModeChangeablePin->usOrMask;
      }
      /* Write the contents of Lower word and Upper word of PMSR variable
       * into the PMSR register address
       */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    }
    else
    {
      /* No action required */
    } /*
       * End of LpSetPinModeGroupStruct->ucPMSRRegIndex !=
       * PORT_REG_NOTAVAILABLE
       */

    /* Write PFCE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCERegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCERegIndex)->usRegAddrOffset +
               LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */

      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT2_MASK))
      {
        /*
         * If bit needs to reset, AND the register contents with
         * Inverse of OrMask
         */
        *Lp16BitRegAddr =
              (*Lp16BitRegAddr) & (uint16)(~LpModeChangeablePin->usOrMask);
      }
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr =
               (*Lp16BitRegAddr) | (uint16)(LpModeChangeablePin->usOrMask);
      }
    } /* End of Write PFCE register */
    else
    {
      /* No action required */
    }

    /* Write PFC register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCRegIndex)->usRegAddrOffset +
                 LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */

      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT1_MASK))
      {
        /* If bit needs to be reset, AND the register contents with OrMask */
        *Lp16BitRegAddr =
          (*Lp16BitRegAddr) & (uint16)(~LpModeChangeablePin->usOrMask);
      } /* End of (Mode & PORT_BIT1_MASK) == PORT_ZERO */
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr =
                (*Lp16BitRegAddr) | (uint16)(LpModeChangeablePin->usOrMask);
      }
    } /* End of Write PFC register */
    else
    {
      /* No action required */
    }

    /* Write PFCAE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCAERegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCAERegIndex)->usRegAddrOffset
                 + LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */

      /* Check whether the corresponding bit is to set or reset. */
      if (PORT_ZERO == (LucMode & PORT_BIT3_MASK))
      {
        /* If bit needs to be reset, AND the register contents with OrMask */
        *Lp16BitRegAddr =
          (*Lp16BitRegAddr) & (uint16)(~LpModeChangeablePin->usOrMask);
      } /* End of (Mode & PORT_BIT3_MASK) == PORT_ZERO */
      else
      {
        /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr =
              (*Lp16BitRegAddr) | (uint16)(LpModeChangeablePin->usOrMask);
      }
    } /* End of Write PFCAE register */
    else
    {
      /* No action required */
    }

    /* Write PMCSR register. Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMCSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the address of PMCSR register */
      LpRegAddr = (uint32 *)((LpFuncCtrlReg +
                  LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usRegAddrOffset
                  + LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */
      if (PORT_ZERO == (LucMode & PORT_BIT4_MASK))
      {
        /*
         * Write the requested direction into Lower word of PMCSR variable
         * by using inverse of OR mask
         */
        LunSRRegContent.Tst_Port_Word.usLSWord = ~LpModeChangeablePin->usOrMask;
      } /* End of (Mode & PORT_BIT4_MASK) == PORT_ZERO */
      else
      {
        /*
         * Write the requested direction into Lower word of PMCSR variable
         * by using OR mask
         */
        LunSRRegContent.Tst_Port_Word.usLSWord = LpModeChangeablePin->usOrMask;
      }
      /* Write the corresponding 32 bit value to the PMCSR register */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    } /* End of Write PMCSR register */
    else
    {
      /* No action required */
    }

    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_EXIT_CRITICAL_SECTION(SET_PIN_MODE_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  } /* End of LenReturnValue == E_NOT_OK */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Port_SetPinMode */
  /* MISRA Violation: START Msg(6:0857)-13 */
#define PORT_STOP_SEC_PUBLIC_CODE
  /* END Msg(6:0857)-13 */
#include "MemMap.h"
#endif /* PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Function Name         : Port_SetToDioMode
**
** Service ID            : 0x05
**
** Description           : This function used to set the mode of a port pin
**                         to DIO mode during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus
**
** Functions Invoked     : Det_ReportError, Port_SetToDioOrAltMode.
**
** Registers Used        : None
*******************************************************************************/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, PORT_PUBLIC_CODE) Port_SetToDioMode (Port_PinType Pin)
{

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_TO_DIO_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_TO_DIO_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LenReturnValue)
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Invoke the internal function to set the requested pin to DIO mode */
    Port_SetToDioOrAltMode(Pin, PORT_TRUE);
  }
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetToDioMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*******************************************************************************
** Function Name         : Port_SetToAlternateMode
**
** Service ID            : 0x06
**
** Description           : This function used to set the mode of a port pin
**                         to alternate mode during runtime.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GblDriverStatus
**
** Functions Invoked     : Det_ReportError, Port_SetToDioOrAltMode.
**
** Registers Used        : None
*******************************************************************************/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, PORT_PUBLIC_CODE) Port_SetToAlternateMode (Port_PinType Pin)
{
  /*
   * If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* TRACE [R3, PORT077][R4, PORT077] */
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_TO_ALT_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_TO_ALT_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }
  if (E_OK == LenReturnValue)
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
     * Invoke the internal function to set the requested pin to alternate
     * mode.
     */
    Port_SetToDioOrAltMode(Pin, PORT_FALSE);
  }
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* #if (PORT_DEV_ERROR_DETECT == STD_ON) */
} /* End of API Port_SetToAlternateMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*******************************************************************************
** Function Name         : Port_SetToDioOrAltMode
**
** Service ID            : NA
**
** Description           : This function used to set the mode of a port pin
**                         during runtime to either DIO or Alternate mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number, boolean - Mode
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_SET_TO_DIO_ALT_PROTECTION,
**                         SchM_Exit_Port_SET_TO_DIO_ALT_PROTECTION,
**                         Port_SearchDioAltModePin.
**
** Registers Used        : PMCSR
*******************************************************************************/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC
FUNC (void, PORT_PRIVATE_CODE) Port_SetToDioOrAltMode (Port_PinType Pin,
                                              boolean LblDioMode)
{
  P2CONST (Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinDioAltMode;
  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                              LpFuncCtrlReg;
  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;
  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST)LpRegAddr;
  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST)Lp16BitRegAddr;
  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_DioOrAltMode LunSRRegContent;
  /* END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint8 LucPortGroupIndex;

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;
  #endif

  /*
   * Check whether the Pin is in Dio or Alternate mode changeable at run time
   */
  LpSetPinDioAltMode = Port_SearchDioAltModePin (Pin,
                               Port_GpConfigPtr->pPinDioAltModeDetails,
                             Port_GpConfigPtr->ucNoOfPinsDioAltModeChangeable);
  if (NULL_PTR != LpSetPinDioAltMode)
  {
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_NUMERIC == LpSetPinDioAltMode->ucPortType)
    {
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpSetPinDioAltMode->ucPortType == PORT_GROUP_NUMERIC */
    else
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_ALPHABETIC == LpSetPinDioAltMode->ucPortType)
      {
        LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
        LpFuncCtrlReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs;
        LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      } /* End of LpSetPinDioAltMode->ucPortType == PORT_GROUP_ALPHABETIC */
      else
      #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        if ((uint8)PORT_GROUP_JTAG == LpSetPinDioAltMode->ucPortType)
        {
          LpPortReg = Port_GpConfigPtr->pPortJRegs;
          LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
          LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        } /* End of LpSetPinDioAltMode->ucPortType == PORT_GROUP_JTAG */
        else
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
          if ((uint8)PORT_GROUP_ANALOG == LpSetPinDioAltMode->ucPortType)
          {
            #if (PORT_DEV_ERROR_DETECT == STD_ON)

                  /* TRACE [R3, PORT146][R4, PORT146] */
                  /* Report to DET */
                  (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
                  /* Set Return Value as E_NOT_OK */
                  LenReturnValue = E_NOT_OK;
            #endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
          }
          else
          #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
          {
                #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
                if ((uint8)PORT_GROUP_INPUT == LpSetPinDioAltMode->ucPortType)
                {
                    #if (PORT_DEV_ERROR_DETECT == STD_ON)

                          /* TRACE [R3, PORT146][R4, PORT146] */
                          /* Report to DET */
                        (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
                        /* Set Return Value as E_NOT_OK */
                        LenReturnValue = E_NOT_OK;
                    #endif /* (PORT_DEV_ERROR_DETECT = = STD_ON) */
                }
                else
                #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
                {
                    /* No action required */
                }
          }
        }
      }
    }
 #if (PORT_DEV_ERROR_DETECT == STD_ON)
 if (E_OK == LenReturnValue)
 #endif
  {
    /*
     * Search for the Pin and get the index in the array
     * Port_GstSetDioAltPinDetails[]
     */
    LucPortGroupIndex = LpSetPinDioAltMode->ucPortGroupIndex;
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    LpRegAddr = (uint32 *)
      (((LpFuncCtrlReg + LucPortGroupIndex)->usRegAddrOffset) + LulBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-3 */
    /* END Msg(4:0488)-6 */

        /* MISRA Violation: START Msg(4:0306)-3 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* MISRA Violation: START Msg(4:1891)-11 */
    Lp16BitRegAddr = (uint16 *)((LpPortReg +
         LpSetPinDioAltMode->ucPortPIPCIndex)->usRegAddrOffset +
         PORT_OS_BASE_ADDRESS_OFFSET + LulBaseAddress);
         /* MISRA Violation: END Msg(4:0306)-3 */
         /* MISRA Violation: END Msg(4:2962)-5 */
         /* MISRA Violation: END Msg(4:0488)-6 */
         /* MISRA Violation: END Msg(4:1891)-11 */

    LunSRRegContent.Tst_Port_Word.usMSWord = LpSetPinDioAltMode->usOrMask;

    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(SET_TO_DIO_ALT_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*
     * Write the requested direction into Lower word of PMCSR variable
     * by using OR mask
     */
    if (PORT_TRUE == LblDioMode)
    {
    /* MISRA Violation: START Msg(2:4397)-9 */
     *Lp16BitRegAddr =
                   (*Lp16BitRegAddr) & (~(LpSetPinDioAltMode->usOrMask));
    /* END Msg(2:4397)-9 */
      LunSRRegContent.Tst_Port_Word.usLSWord = ~LpSetPinDioAltMode->usOrMask;
    }
    else
    {
      LunSRRegContent.Tst_Port_Word.usLSWord = LpSetPinDioAltMode->usOrMask;
    }
    /* Write the corresponding 32 bit value to the PMCSR register */
    *LpRegAddr = LunSRRegContent.ulRegContent;
    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(SET_TO_DIO_ALT_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/
   }
  }
  else
  {
    /*
     * If DET is enabled, the API parameter checking shall be performed
     * according to the respective functions
     */
    /* TRACE [R3, PORT031] */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* TRACE [R3, PORT077][R4, PORT077] */
    if (PORT_TRUE == LblDioMode)
    {
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_TO_DIO_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    else
    {
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_TO_ALT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    }
    #endif /* (PORT_DEV_ERROR_DETECT = = STD_ON) */
  }

} /* End of API Port_SetToDioOrAltMode */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*******************************************************************************
** Function Name         : Port_SearchDioAltModePin
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin
**                         is Mode changeable as DIO or ALTERNATE mode.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         LpStartPtr - Start pointer to the Changeable pin
**                         structures.
**                         Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Mode Changeable Pin structure - if given
**                         pin number matches.
**                         NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC
FUNC(P2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
  PORT_PRIVATE_CODE) Port_SearchDioAltModePin(Port_PinType LddPinNumber,
  P2CONST(Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
  LpStartPtr, uint8 Lucsize)
{
  P2CONST (Port_PinDioAltChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
                                                     LpRetPtr = NULL_PTR;
  uint8 LddLow;
  uint8 LddHigh;
  uint8 LddMid;
  uint16 LddListSearchId;
  LddHigh = Lucsize - PORT_ONE;
  LddLow = PORT_ONE;
  /* Get the lower limit of Search ID */
  LddListSearchId = LpStartPtr->ddPinId;
  /* MISRA Violation: START Msg(4:0488)-6 */
  /* Check whether search Search-ID is in range */
  if ((LddPinNumber >= LddListSearchId) &&
     (LddPinNumber <= ((LpStartPtr + LddHigh)->ddPinId)))
  /* END Msg(4:0488)-6 */
  {
    /*
     * Check whether requested Search-ID is same as first Search-ID
     * of the list
     */
    if (LddPinNumber != LddListSearchId)
    {
      do
      {
        /* Get the middle index number */
        LddMid = (LddHigh + LddLow) >> PORT_ONE;
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get the Search-ID of the mid IDs */
        LddListSearchId = ((LpStartPtr + LddMid)->ddPinId);
        /* END Msg(4:0488)-6 */
        /* Compare Search-ID with the requested one */
        if (LddListSearchId == LddPinNumber)
        {
          /* MISRA Violation: START Msg(4:0488)-6 */
          /* Update the return pointer with the pin number structure */
          LpRetPtr = (LpStartPtr + LddMid);
          /* END Msg(4:0488)-6 */
          /* Set LddHigh to zero to break the loop */
          LddHigh = PORT_ZERO;
        } /* End of LddListSearchId == LddPinNumber */
        else
        {
          /* Compare the Search-ID with the requested one */
          if (LddPinNumber < LddListSearchId)
          {
            /* If the priority is lower, update LddHigh */
            LddHigh = LddMid - PORT_ONE;
          }
          else
          {
            /* If the priority is higher, update LddLow */
            LddLow = LddMid + PORT_ONE;
          }
        }
      } while (LddLow <= LddHigh);
    } /* End of LddPinNumber != LddListSearchId */
    else
    {
      /* Update the return pointer with start pointer (Matches with first Id)*/
      LpRetPtr = LpStartPtr;
    }
  } /*
     * End of (LddPinNumber >= LddListSearchId) &&
     * (LddPinNumber <= ((LpStartPtr + LddHigh)->ddPinId))
     */
  else
  {
    /* No action required */
  }
  return (LpRetPtr);
} /* End of Port_SearchDioAltModePin */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* PORT_SET_TO_DIO_ALT_MODE_API == STD_ON */

/*******************************************************************************
** Function Name         : Port_SearchModeChangeablePin
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin
**                         is Mode changeable.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         LpStartPtr - Start pointer to the Changeable pin
**                         structures.
**                         Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Mode Changeable Pin structure - if given
**                         pin number matches.
**                         NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC
FUNC(P2CONST(Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchModeChangeablePin(Port_PinType LddPinNumber,
    P2CONST(Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
    LpStartPtr, uint8 Lucsize)
{
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_DATA)
                                                     LpRetPtr = NULL_PTR;
  uint8 LddLow;
  uint8 LddHigh;
  uint8 LddMid;
  uint16 LddListSearchId;
  LddHigh = Lucsize - PORT_ONE;
  LddLow = PORT_ONE;
  /* Get the lower limit of Search ID */
  LddListSearchId = LpStartPtr->ddPinId;
  /* MISRA Violation: START Msg(4:0488)-6 */
  /* Check whether search Search-ID is in range */
  if ((LddPinNumber >= LddListSearchId) &&
     (LddPinNumber <= ((LpStartPtr + LddHigh)->ddPinId)))
  /* END Msg(4:0488)-6 */
  {
    /*
     * Check whether requested Search-ID is same as first Search-ID
     * of the list
     */
    if (LddPinNumber != LddListSearchId)
    {
      do
      {
        /* Get the middle index number */
        LddMid = (LddHigh + LddLow) >> PORT_ONE;
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get the Search-ID of the mid IDs */
        LddListSearchId = ((LpStartPtr + LddMid)->ddPinId);
        /* END Msg(4:0488)-6 */
        /* Compare Search-ID with the requested one */
        if (LddListSearchId == LddPinNumber)
        {
          /* MISRA Violation: START Msg(4:0488)-6 */
          /* Update the return pointer with the pin number structure */
          LpRetPtr = (LpStartPtr + LddMid);
          /* END Msg(4:0488)-6 */
          /* Set LddHigh to zero to break the loop */
          LddHigh = PORT_ZERO;
        } /* End of LddListSearchId == LddPinNumber */
        else
        {
          /* Compare the Search-ID with the requested one */
          if (LddPinNumber < LddListSearchId)
          {
            /* If the priority is lower, update LddHigh */
            LddHigh = LddMid - PORT_ONE;
          }
          else
          {
            /* If the priority is higher, update LddLow */
            LddLow = LddMid + PORT_ONE;
          }
        }
      } while (LddLow <= LddHigh);
    } /* End of LddPinNumber != LddListSearchId */
    else
    {
      /* Update the return pointer with start pointer (Matches with first Id) */
      LpRetPtr = LpStartPtr;
    }
  } /*
     * End of (LddPinNumber >= LddListSearchId) &&
     * (LddPinNumber <= ((LpStartPtr + LddHigh)->ddPinId))
     */
  else
  {
    /* No action required */
  }

  return (LpRetPtr);
} /* End of Port_SearchModeChangeablePin */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */

/*******************************************************************************
** Function Name         : Port_InitConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         numeric, alphabetic and JTag ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Dem_ReportErrorStatus
**                         SchM_Enter_Port_INIT_CONFIG_PROTECTION
**                         SchM_Exit_Port_INIT_CONFIG_PROTECTION
**
** Registers Used        : PSRn, PISn, PIBCn, PIPCn, PUn, PDn, PBDCn,
**                         PODCn, PDSCn, PFCEn, PFCn, PFCAEn, PMCSRn, PMSRn,
**                         PPROTS, PPCMD, JPSRn, JPISn, JPIBCn, JPIPCn, JPUn,
**                         JPDn, JPBDCn, JPFCEn, JPFCn, JPMCSRn, JPMSRn, JPODCn,
**                         JPDSCn, JPPROTS.
*******************************************************************************/
/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

/* The function Port_Init shall initialize all controller registers */
/* TRACE [R3, PORT113][R4, PORT113] */
/* TRACE [R3, PORT002][R4, PORT002] */
STATIC FUNC(void, PORT_PRIVATE_CODE) Port_InitConfig
                                                 (Port_GroupType LenGroupType)
{
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPIBCReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPBDCReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPSRReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPISReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPIPCReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPUReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPODCReg;
  P2CONST(volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                                LpPortPMCSRReg;
  P2CONST(volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                                 LpFuncCtrlReg;
  P2CONST(volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)LpPMSRReg;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) Lp32BitRegAddress;
  /* Pointer for 16-bit Port Registers */
  P2VAR(volatile uint16, AUTOMATIC, PORT_CONFIG_DATA) Lp16BitRegAddress;
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) Lp8BitRegAddress;
  /* Check PPCMDn register size is 32-bit */
  #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  #else
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) LpPPCMDRegAdd;
  #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
  /* Check PPROTSn register size is 32-bit */
  #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) Lp32BitPPROTSRegAdd;
  #else
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) Lp8BitPPROTSRegAdd;
  #endif /* End of (PPROTS_32BIT_REG_AVAILABLE == STD_ON) */
  uint32 LulUserBaseAddress;
  uint32 LulOsBaseAddress;
  uint8 LucLoopCount;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPSRRegs;
  uint8 LucNoOfPMCSRRegs;
  uint8 LucNoOfOther16BitRegs;
  uint8 LucNoOfPODCRegs;
  uint8 LucNoOfPODCERegs;
  uint8 LucNoOfPDSCRegs;
  uint8 LucNoOfPUCCRegs;
  uint8 LucNoOfPINVRegs;
  uint8 LucNoOfFuncCtrlRegs;
  uint8 LucNoOfPIBCRegs;
  uint8 LucNoOfPBDCRegs;
  uint8 LucNoOfPMSRRegs;
  uint8 LucNoOfPIPCRegs;
  uint8 LucNoOfPISRegs;
  uint8 LucNoOfPURegs;

  #if (PORT_PIN_STATUS_BACKUP == STD_ON)
  uint8 LucNoOfRestoredRegs;
  #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON */
  Std_ReturnType LenReturnValue = E_OK;
  boolean LblNumAlpha = PORT_ZERO;
  boolean LblJtag = PORT_ZERO;
  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* Get the pointer to the Numeric Port registers */
    LpPortReg = Port_GpConfigPtr->pPortNumRegs;
    /* Get the pointer to the Numeric Function Control registers */
    LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
    /* Get the pointer to the Numeric PMSR registers */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* Get the total number of Numeric PSR registers */
    LucNoOfPSRRegs = PORT_NUM_PSR_REGS;
    /* Get the total number of Numeric PMCSR registers */
    LucNoOfPMCSRRegs = PORT_NUM_PMCSR_REGS;
    /* Get the total number of Numeric Other 16 Bit registers */
    LucNoOfOther16BitRegs = PORT_NUM_OTHER_16BIT_REGS;
    /* Get the total number of Numeric PODC registers */
    LucNoOfPODCRegs = PORT_NUM_PODC_REGS;
    /* Get the total number of Numeric PODCE registers */
    LucNoOfPODCERegs = PORT_NUM_PODCE_REGS;
    /* Get the total number of Numeric PDSC registers */
    LucNoOfPDSCRegs = PORT_NUM_PDSC_REGS;
    /* Get the total number of Numeric PUCC registers */
    LucNoOfPUCCRegs = PORT_NUM_PUCC_REGS;
    /* Get the total number of Numeric PINV registers */
    LucNoOfPINVRegs = PORT_NUM_PINV_REGS;
    /* Get the total number of Numeric Function Control registers */
    LucNoOfFuncCtrlRegs = PORT_NUM_FUNC_CTRL_REGS;
    #if (PORT_PIN_STATUS_BACKUP == STD_ON)
    /* Get the total number of Numeric Restored registers */
    LucNoOfRestoredRegs = Port_GpConfigPtr->ucNoOfNumRestoredRegs;
    #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON */
    /* Get the Base address of Numeric Port */
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    /* Get the Base address of Numeric Port */
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
    /* Get the total number of Numeric PIBC registers */
    LucNoOfPIBCRegs = PORT_NUM_PIBC_REGS;
    /* Get the total number of Numeric PBDC registers */
    LucNoOfPBDCRegs = PORT_NUM_PBDC_REGS;
    /* Get the total number of Numeric PMSR registers */
    LucNoOfPMSRRegs = PORT_NUM_PMSR_REGS;
    /* Get the total number of Numeric PIPC registers */
    LucNoOfPIPCRegs = PORT_NUM_PIPC_REGS;
    /* Get the total number of Numeric PIS registers */
    LucNoOfPISRegs = PORT_NUM_PIS_REGS;
    /* Get the total number of Numeric PU and PD and PBDC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    LucNoOfPURegs = PORT_NUM_PU_REGS + PORT_NUM_PD_REGS
                   + PORT_NUM_PBDC_REGS;
    /* Get the pointer to the Numeric PIBC registers */
    LpPortPIBCReg = LpPortReg + (PORT_NUM_PSR_REGS
                    + PORT_NUM_PIS_REGS);
    /* Get the pointer to the Numeric PBDC registers */
    LpPortPBDCReg = LpPortReg + (PORT_NUM_PSR_REGS + PORT_NUM_PIS_REGS
                    + PORT_NUM_PIBC_REGS + PORT_NUM_PIPC_REGS
                    + PORT_NUM_PU_REGS + PORT_NUM_PD_REGS);
    /* Get the pointer to the Numeric PMCSR registers */
    LpPortPMCSRReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs
                    + (PORT_NUM_PFCE_REGS + PORT_NUM_PFC_REGS
                    + PORT_NUM_PFCAE_REGS);
    /* Get the pointer to the Numeric PIPC registers */
    LpPortPIPCReg = LpPortReg + (PORT_NUM_PSR_REGS + PORT_NUM_PIS_REGS
                    + PORT_NUM_PIBC_REGS);
    /* Get the pointer to the Numeric PSR registers */
    LpPortPSRReg = LpPortReg;
    /* Get the pointer to the Numeric PIS registers */
    LpPortPISReg = LpPortReg + PORT_NUM_PSR_REGS;
    /* Get the pointer to the Numeric PU registers */
    LpPortPUReg = LpPortReg + (PORT_NUM_PSR_REGS + PORT_NUM_PIS_REGS
                  + PORT_NUM_PIBC_REGS + PORT_NUM_PIPC_REGS);
    /* Get the pointer to the Numeric PODC registers */
    LpPortPODCReg = LpPortReg + (PORT_NUM_PSR_REGS + PORT_NUM_PIS_REGS
                  + PORT_NUM_PIBC_REGS + PORT_NUM_PIPC_REGS
                  + PORT_NUM_PU_REGS + PORT_NUM_PD_REGS
                  + PORT_NUM_PBDC_REGS);
    /* Update the local variable as one */
    /* END Msg(4:0488)-6 */
    LblNumAlpha = PORT_ONE;
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  {
    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if (PORT_GROUP_ALPHABETIC == LenGroupType)
    {
      /* Get the pointer to the Alphabetic Port registers */
      LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
      /* Get the pointer to the Alphabetic Function Control registers */
      LpFuncCtrlReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs;
      /* Get the pointer to the Alphabetic PMSR registers */
      LpPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
      /* Get the total number of Alphabetic PSR registers */
      LucNoOfPSRRegs = PORT_ALPHA_PSR_REGS;
      /* Get the total number of Alphabetic PMCSR registers */
      LucNoOfPMCSRRegs = PORT_ALPHA_PMCSR_REGS;
      /* Get the total number of Alphabetic Other 16 Bit registers */
      LucNoOfOther16BitRegs = PORT_ALPHA_OTHER_16BIT_REGS;
      /* Get the total number of Alphabetic PODC registers */
      LucNoOfPODCRegs = PORT_ALPHA_PODC_REGS;
      /* Get the total number of Alphabetic PODCE registers */
      LucNoOfPODCERegs = PORT_ALPHA_PODCE_REGS;
      /* Get the total number of Alphabetic PDSC registers */
      LucNoOfPDSCRegs = PORT_ALPHA_PDSC_REGS;
      /* Get the total number of Alphabetic PUCC registers */
      LucNoOfPUCCRegs = PORT_ALPHA_PUCC_REGS;
      /* Get the total number of Alphabetic PINV registers */
      LucNoOfPINVRegs = PORT_ALPHA_PINV_REGS;
      /* Get the total number of Alphabetic Function Control registers */
      LucNoOfFuncCtrlRegs = PORT_ALPHA_FUNC_CTRL_REGS;
      #if (PORT_PIN_STATUS_BACKUP == STD_ON)
      /* Get the total number of Alphabetic Restored registers */
      LucNoOfRestoredRegs = Port_GpConfigPtr->ucNoOfAlphaRestoredRegs;
      #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON */
      /* Get the Base address of Alphabetic Port */
      LulUserBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      /* Get the Base address of Alphabetic Port */
      LulOsBaseAddress = PORT_OS_BASE_ADDRESS_ALPHABETIC;
      /* Get the total number of Alphabetic PIBC registers */
      LucNoOfPIBCRegs = PORT_ALPHA_PIBC_REGS;
      /* Get the total number of Alphabetic PBDC registers */
      LucNoOfPBDCRegs = PORT_ALPHA_PBDC_REGS;
      /* Get the total number of Alphabetic PMSR registers */
      LucNoOfPMSRRegs = PORT_ALPHA_PMSR_REGS;
      /* Get the total number of Alphabetic PIPC registers */
      LucNoOfPIPCRegs = PORT_ALPHA_PIPC_REGS;
      /* Get the total number of Alphabetic PIS registers */
      LucNoOfPISRegs = PORT_ALPHA_PIS_REGS;
      /* Get the total number of ALPHA PU and PD and PBDC registers */
      LucNoOfPURegs = PORT_ALPHA_PU_REGS + PORT_ALPHA_PD_REGS
                      + PORT_ALPHA_PBDC_REGS;
      /* Get the pointer to the Alphabetic PIBC registers */
      LpPortPIBCReg = LpPortReg + (PORT_ALPHA_PSR_REGS
                      + PORT_ALPHA_PIS_REGS);
      /* Get the pointer to the Alphabetic PBDC registers */
      LpPortPBDCReg = LpPortReg + (PORT_ALPHA_PSR_REGS + PORT_ALPHA_PIS_REGS
                      + PORT_ALPHA_PIBC_REGS + PORT_ALPHA_PIPC_REGS
                      + PORT_ALPHA_PU_REGS + PORT_ALPHA_PD_REGS);
      /* Get the pointer to the Alphabetic PMCSR registers */
      LpPortPMCSRReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs
                      + (PORT_ALPHA_PFCE_REGS + PORT_ALPHA_PFC_REGS
                      + PORT_ALPHA_PFCAE_REGS);
      /* Get the pointer to the Alphabetic PIPC registers */
      LpPortPIPCReg = LpPortReg + (PORT_ALPHA_PSR_REGS + PORT_ALPHA_PIS_REGS
                      + PORT_ALPHA_PIBC_REGS);
      /* Get the pointer to the Alpha PIS registers */
      LpPortPISReg = LpPortReg + PORT_ALPHA_PSR_REGS;
      /* Update the local variable as one */
      LblNumAlpha = PORT_ONE;
    } /* End of LenGroupType == PORT_GROUP_ALPHABETIC */
    else
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if (PORT_GROUP_JTAG == LenGroupType)
      {
        /* Get the pointer to the JTag Port registers */
        LpPortReg = Port_GpConfigPtr->pPortJRegs;
        /* Get the pointer to the JTag Function Control registers */
        LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
        /* Get the pointer to the JTag PMSR registers */
        LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
        /* Get the total number of JTAG PSR registers */
        LucNoOfPSRRegs = PORT_JTAG_PSR_REGS;
        /* Get the total number of JTAG PMCSR registers */
        LucNoOfPMCSRRegs = PORT_JTAG_PMCSR_REGS;
        /* Get the total number of JTag Other 16 Bit registers */
        LucNoOfOther16BitRegs = PORT_JTAG_OTHER_8BIT_REGS;
        /* Get the total number of JTag PODC registers */
        LucNoOfPODCRegs = PORT_JTAG_PODC_REGS;
        /* Get the total number of JTag PODCE registers */
        LucNoOfPODCERegs = PORT_JTAG_PODCE_REGS;
        /* Get the total number of JTag PDSC registers */
        LucNoOfPDSCRegs = PORT_JTAG_PDSC_REGS;
        /* Get the total number of JTag PUCC registers */
        LucNoOfPUCCRegs = PORT_JTAG_PUCC_REGS;
        /* Get the total number of JTag PINV registers */
        LucNoOfPINVRegs = PORT_JTAG_PINV_REGS;
        /* Get the total number of JTag Function Control registers */
        LucNoOfFuncCtrlRegs = PORT_JTAG_FUNC_CTRL_REGS;
        #if (PORT_PIN_STATUS_BACKUP == STD_ON)
        /* Get the total number of Numeric Restored registers */
        LucNoOfRestoredRegs = PORT_ZERO;
        #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON */
        /* Get the Base address of JTag Port */
        LulUserBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        /* Get the Base address of JTag Port */
        LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
        /* Get the total number of JTAG PIBC registers */
        LucNoOfPIBCRegs = PORT_JTAG_PIBC_REGS;
        /* Get the total number of JTAG PBDC registers */
        LucNoOfPBDCRegs = PORT_JTAG_PBDC_REGS;
        /* Get the total number of JTAG PMSR registers */
        LucNoOfPMSRRegs = PORT_JTAG_PMSR_REGS;
        /* Get the total number of JTAG PIPC registers */
        LucNoOfPIPCRegs = PORT_JTAG_PIPC_REGS;
        /* Get the total number of JTAG PIS registers */
        LucNoOfPISRegs = PORT_JTAG_PIS_REGS;
        /* Get the total number of JTAG PU and PD and PBDC registers */
        LucNoOfPURegs = PORT_JTAG_PU_REGS + PORT_JTAG_PD_REGS
                        + PORT_JTAG_PBDC_REGS;
        /* Get the pointer to the JTAG PIBC registers */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LpPortPIBCReg = LpPortReg + PORT_JTAG_PSR_REGS
                        + PORT_JTAG_PIS_REGS;
        /* Get the pointer to the JTAG PBDC registers */
        LpPortPBDCReg = LpPortReg + PORT_JTAG_PSR_REGS + PORT_JTAG_PIS_REGS
                        + PORT_JTAG_PIBC_REGS + PORT_JTAG_PIPC_REGS
                        + PORT_JTAG_PU_REGS + PORT_JTAG_PD_REGS;
        /* Get the pointer to the JTAG PMCSR registers */
        LpPortPMCSRReg = Port_GpConfigPtr->pPortJFuncCtrlRegs
                        + (PORT_JTAG_PFCE_REGS + PORT_JTAG_PFC_REGS
                        + PORT_JTAG_PFCAE_REGS);
        /* Get the pointer to the JTAG PIPC registers */
        LpPortPIPCReg = LpPortReg + (PORT_JTAG_PSR_REGS + PORT_JTAG_PIS_REGS
                        + PORT_JTAG_PIBC_REGS);
        /* Get the pointer to the JTAG PSR registers */
        LpPortPSRReg = LpPortReg;
        /* Get the pointer to the JTAG PU registers */
        LpPortPUReg = LpPortReg + (PORT_JTAG_PSR_REGS + PORT_JTAG_PIS_REGS
                      + PORT_JTAG_PIBC_REGS + PORT_JTAG_PIPC_REGS);
        /* Get the pointer to the JTAG PODC registers */
        LpPortPODCReg = LpPortReg + (PORT_JTAG_PSR_REGS + PORT_JTAG_PIS_REGS
                      + PORT_JTAG_PIBC_REGS + PORT_JTAG_PIPC_REGS
                      + PORT_JTAG_PU_REGS + PORT_JTAG_PD_REGS
                      + PORT_JTAG_PBDC_REGS);
        /* Get the pointer to the JTAG PIS registers */
        /* END Msg(4:0488)-6 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LpPortPISReg = LpPortReg + PORT_JTAG_PSR_REGS;
        /* END Msg(4:0488)-6 */
        /* Update the local variable as one */
        LblJtag = PORT_ONE;
      } /* End of LenGroupType == PORT_GROUP_JTAG */
      else
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
        if (PORT_GROUP_ANALOG == LenGroupType)
        {
          /* Get the pointer to the Analog Port registers */
          LpPortReg = Port_GpConfigPtr->pPortAnalogRegs;
          /* Get the pointer to the Analog PMSR registers */
          LpPMSRReg = Port_GpConfigPtr->pPortAnalogPMSRRegs;
          /* Get the total number of Analog PSR registers */
          LucNoOfPSRRegs = PORT_ANALOG_PSR_REGS;
          /* Get the total number of Analog PMCSR registers */
          LucNoOfPMCSRRegs = PORT_ZERO;
          /* Get the total number of Analog Other 16 Bit registers */
          LucNoOfOther16BitRegs = PORT_ANALOG_OTHER_16BIT_REGS;
          /* Get the total number of Analog PODC registers */
          LucNoOfPODCRegs = PORT_ZERO;
          /* Get the total number of Analog PODCE registers */
          LucNoOfPODCERegs = PORT_ZERO;
          /* Get the total number of Analog PDSC registers */
          LucNoOfPDSCRegs = PORT_ZERO;
          /* Get the total number of Analog PUCC registers */
          LucNoOfPUCCRegs = PORT_ZERO;
          /* Get the total number of Analog PINV registers */
          LucNoOfPINVRegs = PORT_ZERO;
          /* Get the total number of Analog Function Control registers */
          LucNoOfFuncCtrlRegs = PORT_ZERO;
          #if (PORT_PIN_STATUS_BACKUP == STD_ON)
          /* Get the total number of Alphabetic Restored registers */
          LucNoOfRestoredRegs = Port_GpConfigPtr->ucNoOfAnalogRestoredRegs;
          #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON */
          /* Get the Base address of Analog Port */
          LulUserBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
          /* Get the Base address of Analog Port */
          LulOsBaseAddress = PORT_OS_BASE_ADDRESS_ANALOG;
          /* Get the total number of Analog PIBC registers */
          LucNoOfPIBCRegs = PORT_ANALOG_PIBC_REGS;
          /* Get the total number of Analog PBDC registers */
          LucNoOfPBDCRegs = PORT_ANALOG_PBDC_REGS;
          /* Get the total number of Analog PMSR registers */
          LucNoOfPMSRRegs = PORT_ANALOG_PMSR_REGS;
          /* Get the total number of Analog PIPC registers */
          LucNoOfPIPCRegs = PORT_ANALOG_PIPC_REGS;
          /* Get the total number of Analog PIS registers */
          LucNoOfPISRegs = PORT_ANALOG_PIS_REGS;
          /* Get the total number of JTAG PU and PD and PBDC registers*/
          /* MISRA Violation: START Msg(4:0488)-6 */
          LucNoOfPURegs = PORT_ANALOG_PU_REGS + PORT_ANALOG_PD_REGS
                          + PORT_ANALOG_PBDC_REGS;
          /* Get the pointer to the Analog PIBC registers */
          LpPortPIBCReg = LpPortReg + (PORT_ANALOG_PSR_REGS
                          + PORT_ANALOG_PIS_REGS);
          /* Get the pointer to the Analog PBDC registers */
          LpPortPBDCReg = LpPortReg + (PORT_ANALOG_PSR_REGS
                          + PORT_ANALOG_PIS_REGS + PORT_ANALOG_PIBC_REGS
                          + PORT_ANALOG_PIPC_REGS + PORT_ANALOG_PU_REGS
                          + PORT_ANALOG_PD_REGS);
          /* Get the pointer to the Analog PSR registers */
          LpPortPUReg = LpPortReg + (PORT_ANALOG_PSR_REGS
                        + PORT_ANALOG_PIS_REGS + PORT_ANALOG_PIBC_REGS
                        + PORT_ANALOG_PIPC_REGS);
          /* Get the pointer to the Analog PIS registers */
          /* END Msg(4:0488)-6 */
           /* MISRA Violation: START Msg(4:0488)-6 */
          LpPortPISReg = LpPortReg + PORT_ANALOG_PSR_REGS;
          /* END Msg(4:0488)-6 */
          /* Get the pointer to the Analog PSR registers */
          LpPortPSRReg = LpPortReg;
        } /* End of LenGroupType == PORT_GROUP_ANALOG */
        else
        #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
          if (PORT_GROUP_INPUT == LenGroupType)
          {
            /* Get the pointer to the Input Port registers */
            LpPortReg = Port_GpConfigPtr->pPortInputRegs;
            /* Get the pointer to the Input PMSR registers */
            LpPMSRReg = NULL_PTR;
            /* Get the total number of Input PSR registers */
            LucNoOfPSRRegs = PORT_ZERO;
            /* Get the total number of Input PMCSR registers */
            LucNoOfPMCSRRegs = PORT_ZERO;
            /* Get the total number of Input Other 16 Bit registers */
            LucNoOfOther16BitRegs = PORT_INPUT_OTHER_16BIT_REGS;
            /* Get the total number of Input PODC registers */
            LucNoOfPODCRegs = PORT_ZERO;
            /* Get the total number of Input PODCE registers */
            LucNoOfPODCERegs = PORT_ZERO;
            /* Get the total number of Input PDSC registers */
            LucNoOfPDSCRegs = PORT_ZERO;
            /* Get the total number of Input PUCC registers */
            LucNoOfPUCCRegs = PORT_ZERO;
            /* Get the total number of Input PINV registers */
            LucNoOfPINVRegs = PORT_ZERO;
            /* Get the total number of Input Function Control registers */
            LucNoOfFuncCtrlRegs = PORT_ZERO;
            #if (PORT_PIN_STATUS_BACKUP == STD_ON)
            /* Get the total number of Numeric Restored registers */
            LucNoOfRestoredRegs = PORT_ZERO;
            #endif /* End of PORT_PIN_STATUS_BACKUP == STD_ON */
            /* Get the Base address of Input Port */
            LulUserBaseAddress = PORT_USER_BASE_ADDRESS_INPUT;
            /* Get the Base address of Input Port */
            LulOsBaseAddress = PORT_OS_BASE_ADDRESS_INPUT;
            /* Get the total number of Input PIBC registers */
            LucNoOfPIBCRegs = PORT_INPUT_PIBC_REGS;
            /* Get the total number of Input PBDC registers */
            LucNoOfPBDCRegs = PORT_ZERO;
            /* Get the total number of Input PMSR registers */
            LucNoOfPMSRRegs = PORT_ZERO;
            /* Get the total number of Input PMCSR registers */
            LucNoOfPMCSRRegs = PORT_ZERO;
            /* Get the total number of Input PIPC registers*/
            LucNoOfPIPCRegs = PORT_ZERO;
            /* Get the total number of Input PU,  registers*/
            LucNoOfPURegs = PORT_ZERO;
            /* Get the pointer to the JTAG PIBC registers */
            LpPortPIBCReg = LpPortReg;
          } /* End of LenGroupType == PORT_GROUP_INPUT */
          else
          {
            /* No action required */
          }
          #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
        }
      }
    }
  }

    /*
     * An atomic access to Microcontroller registers by the use of an exclusive
     * area
     */
    /* TRACE [R3, PORT075][R4, PORT075] */
  /* Enter critical section */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_ENTER_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of PSR registers */
  LucNoOfRegs = LucNoOfPSRRegs;
  /* END Msg(4:2962)-5 */
  #if (PORT_PIN_STATUS_BACKUP == STD_ON)
   /* MISRA Violation: START Msg(4:0303)-2 */
   if (PORT_IOHOLD_MASK == (PORT_IOHOLD & PORT_IOHOLD_MASK))
   /* MISRA Violation: START Msg(4:0303)-2 */
   {
     /* Get the count for number of registers to be restored */
     /* MISRA Violation: START Msg(4:0488)-4 */
     /* MISRA Violation: START Msg(4:2962)-5 */
      LpPortReg = LpPortReg + LucNoOfRestoredRegs;
     /* MISRA Violation: END Msg(4:2962)-5 */
     /* MISRA Violation: END Msg(4:0488)-4 */
      LucNoOfRegs = LucNoOfRegs - LucNoOfRestoredRegs;
   }
   else
   {
     /* No action required */
   }
  #endif /*End of PORT_PIN_STATUS_BACKUP == STD_ON */

  while (PORT_ZERO < LucNoOfRegs)
  {
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset with the Base address */
    Lp32BitRegAddress =
          (uint32 *)(LpPortReg->usRegAddrOffset + LulUserBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-3 */
    /* TRACE [R3, PORT055][R4, PORT055] */
    /* Write the register value to the corresponding register */
    *Lp32BitRegAddress = (LpPortReg->usInitModeRegVal | PORT_MSB_MASK);

    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* Exit critical section */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_EXIT_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of Other 16Bit registers */
  LucNoOfRegs = LucNoOfOther16BitRegs;
  /* END Msg(4:2962)-5 */
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset to the Base address */
    Lp16BitRegAddress =
           (uint16 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-3 */
    /* Write the register value to the corresponding register */
    *Lp16BitRegAddress = LpPortReg->usInitModeRegVal;
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 32Bit PODC registers */
  LucNoOfRegs = LucNoOfPODCRegs;
  /* END Msg(4:2962)-5 */
  /* Get the pointer of PODC register top */
  LpPortReg = LpPortPODCReg;
  while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* Get the register address by adding the offset with the Base address */
    Lp32BitRegAddress =
                    (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPROTS register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    Lp32BitPPROTSRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));

    #else
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    #endif
    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPCMD register */
    #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
    LpPPCMDRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    #else
    LpPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PODC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PODC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:0306)-3 */
    #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
    do
    {
      *LpPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /* Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress =
                       (uint16)(~LpPortReg->usInitModeRegVal) | PORT_MSB_MASK;

      /* Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /*
       * Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occurs report DEM and skip
       * further configuration
       */
    }
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    while (((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
                                                && (PORT_ZERO < LucLoopCount));
    #else
    while ((PORT_ONE == *Lp8BitPPROTSRegAdd) && (PORT_ZERO < LucLoopCount));
    #endif

    #if (PORT_DEM_ERROR_DETECT == STD_ON)
    /* Check if the loop has exited because of failure of writing to register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    if ((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
    #else
    if (PORT_ONE == *Lp8BitPPROTSRegAdd)
    #endif
    {
      /* AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per mantis
       * #6426, the configurable pre-compile switch for detection of production
       * code errors is added
       */
      /* TRACE [R3, PORT037] */
      /* TRACE [R4, PORT037] */
      /* Report write failure production error */
      /* TRACE [R3, PORT146][R4, PORT146] */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                       (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

      /* Set the Dem error flag */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    #endif
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) */


  /* Get the count of total number of 32Bit PODCE registers */
  LucNoOfRegs = LucNoOfPODCERegs;

  while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* Get the register address by adding the offset with the Base address */
    Lp32BitRegAddress =
                    (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPROTS register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    Lp32BitPPROTSRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PODCE_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PODCE_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));

    #else
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PODCE_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PODCE_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    #endif

    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:2984)-8 */
    /* END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPCMD register */
    #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
    LpPPCMDRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PODCE_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PODCE_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    #else
    LpPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PODCE_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PODCE_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:2984)-8 */
    /* END Msg(4:0306)-3 */
    #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
    do
    {
      *LpPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /*
       * Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress =
                       (uint16)(~LpPortReg->usInitModeRegVal) | PORT_MSB_MASK;

      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /*
       * Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occurs report DEM and skip
       * further configuration
       */
    }
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    while (((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
                                                && (PORT_ZERO < LucLoopCount));
    #else
    while ((PORT_ONE == *Lp8BitPPROTSRegAdd) && (PORT_ZERO < LucLoopCount));
    #endif

    #if (PORT_DEM_ERROR_DETECT == STD_ON)
    /* Check if the loop has exited because of failure of writing to register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    if ((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
    #else
    if (PORT_ONE == *Lp8BitPPROTSRegAdd)
    #endif
    {
      /*
       * AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per mantis
       * #6426, the configurable pre-compile switch for detection of production
       * code errors is added
       */
      /* TRACE [R3, PORT037] */
      /* TRACE [R4, PORT037] */
      /* Report write failure production error */
      /* TRACE [R3, PORT146][R4, PORT146] */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                      (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

      /* Set the Dem error flag */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    #endif
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 32Bit PDSC registers */
  LucNoOfRegs = LucNoOfPDSCRegs;
  /* END Msg(4:2962)-5 */
  while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* Get the register address by adding the offset with the Base address */
    Lp32BitRegAddress =
              (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2985)-4 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPROTS register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    Lp32BitPPROTSRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));

    #else
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    #endif

    /* Get the address of the corresponding PPCMD register */
    #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
    LpPPCMDRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    #else
    LpPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PDSC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PDSC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:2985)-4 */
    /* END Msg(4:0306)-3 */
    /* END Msg(4:2984)-8 */
    do
    {
      *LpPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /*
       * Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress =
                        (uint16)(~LpPortReg->usInitModeRegVal) | PORT_MSB_MASK;
      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /*
       * Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occurs report DEM and skip
       * further configuration
       */
    }
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    while (((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
                                                && (PORT_ZERO < LucLoopCount));
    #else
    while ((PORT_ONE == *Lp8BitPPROTSRegAdd) && (PORT_ZERO < LucLoopCount));
    #endif

    #if (PORT_DEM_ERROR_DETECT == STD_ON)
    /* Check if the loop has exited because of failure of writing to register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    if ((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
    #else
    if (PORT_ONE == *Lp8BitPPROTSRegAdd)
    #endif
    {
      /*
       * AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per mantis
       * #6426, the configurable pre-compile switch for detection of production
       * code errors is added
       */
      /* TRACE [R3, PORT037] */
      /* TRACE [R4, PORT037] */
      /* Report write failure production error */
      /* TRACE [R3, PORT146][R4, PORT146] */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                       (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    #endif
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) && (LenReturnValue == E_NOT_OK) */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 32Bit PUCC registers */
  LucNoOfRegs = LucNoOfPUCCRegs;
  /* END Msg(4:2962)-5 */
  while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
  {
    /* Initialize the loop count to ten */
    LucLoopCount = PORT_LOOP_TIMEOUT;

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* Get the register address by adding the offset with the Base address */
    Lp32BitRegAddress =
              (uint32 *)(LpPortReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPROTS register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    Lp32BitPPROTSRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PUCC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PUCC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));

    #else
    Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                                ((PORT_NUM_PUCC_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PUCC_REG_ADD_OFFSET * LblJtag)) +
                                LulOsBaseAddress) +
                                (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
                                (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
    #endif
    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:2984)-8 */
    /* END Msg(4:0306)-3 */

    /* MISRA Violation: START Msg(4:2984)-8 */
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:3393)-10 */
    /* MISRA Violation: START Msg(4:1891)-11 */
    /* Get the address of the corresponding PPCMD register */
    #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
    LpPPCMDRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PUCC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PUCC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));

    #else
    LpPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                               ((PORT_NUM_PUCC_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PUCC_REG_ADD_OFFSET * LblJtag)) +
                               LulOsBaseAddress) +
                               (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                               (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
    #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
    /* END Msg(4:1891)-11 */
    /* END Msg(4:3393)-10 */
    /* END Msg(4:2984)-8 */
    /* END Msg(4:0306)-3 */
    do
    {
      *LpPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

      /*
       * Write the bit wise inverse value to the corresponding register with
       * upper 16 bit set to one
       */
      *Lp32BitRegAddress =
                        (uint16)(~LpPortReg->usInitModeRegVal) | PORT_MSB_MASK;
      /*
       * Write the register value to the corresponding register with upper 16
       * bit set to zero
       */
      *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
      /* Decrement the loop count for each iteration */
      LucLoopCount--;
      /*
       * Check the state of PPROTS register for successful write operation or
       * perform maximum ten tries, if failure occurs report DEM and skip
       * further configuration
       */
    }
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    while (((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
                                             && (PORT_ZERO < LucLoopCount));
    #else
    while ((PORT_ONE == *Lp8BitPPROTSRegAdd) && (PORT_ZERO < LucLoopCount));
    #endif

    #if (PORT_DEM_ERROR_DETECT == STD_ON)
    /* Check if the loop has exited because of failure of writing to register */
    #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
    if ((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
    #else
    if (PORT_ONE == *Lp8BitPPROTSRegAdd)
    #endif
    {
      /*
       * AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per mantis
       * #6426, the configurable pre-compile switch for detection of production
       * code errors is added
       */
      /* TRACE [R3, PORT037] */
      /* TRACE [R4, PORT037] */
      /* Report write failure production error */
      /* TRACE [R3, PORT146][R4, PORT146] */
      Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                       (PORT_DEM_TYPE)DEM_EVENT_STATUS_FAILED);

      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
    else
    {
      /* No action required */
    }
    #endif
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of (LucNoOfRegs > PORT_ZERO) && (LenReturnValue == E_NOT_OK) */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 16Bit PU, PD, PBDC registers */
  LucNoOfRegs = LucNoOfPURegs;
  /* END Msg(4:2962)-5 */
  while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
  {
    /* Check JTAG port */
    if (LblJtag == PORT_ONE)
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp8BitRegAddress =
             (uint8 *)(LpPortPUReg->usRegAddrOffset + LulOsBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register value to the corresponding register */
      *Lp8BitRegAddress = (uint8)LpPortPUReg->usInitModeRegVal;
    }
    else
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp16BitRegAddress =
             (uint16 *)(LpPortPUReg->usRegAddrOffset + LulOsBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register value to the corresponding register */
      *Lp16BitRegAddress = LpPortPUReg->usInitModeRegVal;
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPUReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 16Bit PIS registers */
  LucNoOfRegs = LucNoOfPISRegs;
  /* END Msg(4:2962)-5 */
  while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
  {
    /* MISRA Violation: START Msg(4:0306)-2 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset to the Base address */
    Lp16BitRegAddress =
           (uint16 *)(LpPortPISReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-2 */
    /* Write the register value to the corresponding register */
    *Lp16BitRegAddress = LpPortPISReg->usInitModeRegVal;
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPISReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  if (LenReturnValue == E_OK)
  {
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the count of total number of Function Control registers */
    LucNoOfRegs = LucNoOfFuncCtrlRegs;
    /* END Msg(4:2962)-5 */
    while (LucNoOfRegs > PORT_ZERO)
    {
      /* Check JTAG port */
      if (LblJtag == PORT_ONE)
      {
        /* MISRA Violation: START Msg(4:0306)-1 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* Get the pointer to the function control registers */
        Lp8BitRegAddress = (uint8 *)
                          (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0306)-2 */
        /* Write the register value to the corresponding register */
        *Lp8BitRegAddress = (uint8)LpFuncCtrlReg->usInitModeRegVal;
      }
      else
      {
        /* MISRA Violation: START Msg(4:0306)-1 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* Get the pointer to the function control registers */
        Lp16BitRegAddress = (uint16 *)
                          (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0306)-2 */
        /* Write the register value to the corresponding register */
        *Lp16BitRegAddress = LpFuncCtrlReg->usInitModeRegVal;
      }
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpFuncCtrlReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */
  }
  else
  {
    /* No action required */
  }

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 16Bit PIPC registers */
  LucNoOfRegs = LucNoOfPIPCRegs;
  /* END Msg(4:2962)-5 */
  /* Get the pointer of PIPC register top */
  while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
  {
    /* MISRA Violation: START Msg(4:0306)-2 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset to the Base address */
    Lp16BitRegAddress =
           (uint16 *)(LpPortPIPCReg->usRegAddrOffset + LulOsBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-2 */
    /* Write the register value to the corresponding register */
    *Lp16BitRegAddress = LpPortPIPCReg->usInitModeRegVal;
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPIPCReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  if (LenReturnValue == E_OK)
  {

    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Get the count of total number of PSR registers */
    LucNoOfRegs = LucNoOfPSRRegs;

    #if (PORT_PIN_STATUS_BACKUP == STD_ON)
     if ((PORT_IOHOLD & PORT_IOHOLD_MASK) == PORT_IOHOLD_MASK)
     {
       /* Get the count for number of registers to be restored */
        LpPortPSRReg = LpPortPSRReg + LucNoOfRestoredRegs;
        LucNoOfRegs = LucNoOfRegs - LucNoOfRestoredRegs;
     }
     else
     {
       /* No action required */
     }
    #endif /*End of PORT_PIN_STATUS_BACKUP == STD_ON */

    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    while (LucNoOfRegs > PORT_ZERO)
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp32BitRegAddress =
            (uint32 *)(LpPortPSRReg->usRegAddrOffset + LulUserBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register value to the corresponding register */
      *Lp32BitRegAddress = (LpPortPSRReg->usInitModeRegVal | PORT_MSB_MASK);

      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortPSRReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */

    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_ENTER_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Exit critical section */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the count of total number of Function Control SR registers */
    LucNoOfRegs = LucNoOfPMCSRRegs;
    /* END Msg(4:2962)-5 */
    while (LucNoOfRegs > PORT_ZERO)
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the pointer to the function control registers */
      Lp32BitRegAddress = (uint32 *)
             (LpPortPMCSRReg->usRegAddrOffset + LulUserBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register value to the corresponding register */
      *Lp32BitRegAddress = (uint32)
                    (LpPortPMCSRReg->usInitModeRegVal | PORT_MSB_MASK);
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortPMCSRReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */

    /* Exit critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    PORT_EXIT_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the count of total number of 32Bit PINV registers */
    LucNoOfRegs = LucNoOfPINVRegs;

      /*
     * AUTOSAR IMPL [R3, PORT082][R4, PORT082] RULE VIOLATION: As per
     * requirement AR_PN0062_FR_0048 Level inversion is implemented to invert
     * the output level of a pin when the pin is in output mode  */
    /* END Msg(4:2962)-5 */
    while ((PORT_ZERO < LucNoOfRegs) && (E_OK == LenReturnValue))
    {
      /* Initialize the loop count to ten */
      LucLoopCount = PORT_LOOP_TIMEOUT;

      /* MISRA Violation: START Msg(4:0306)-3 */
      /* Get the register address by adding the offset with the Base address */
      Lp32BitRegAddress =
                (uint32 *)(LpPortReg->usRegAddrOffset + LulUserBaseAddress);
      /* END Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:2984)-8 */
      /* MISRA Violation: START Msg(4:3393)-10 */
      /* MISRA Violation: START Msg(4:1891)-11 */
      /* Get the address of the corresponding PPROTS register */
      #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
      Lp32BitPPROTSRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
               (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                             LblNumAlpha) +
               ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                               LblJtag)) +
                LulOsBaseAddress) +
               (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
               (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
      #else
      Lp8BitPPROTSRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
               (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                             LblNumAlpha) +
               ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                               LblJtag)) +
                LulOsBaseAddress) +
               (PORT_NUM_PPROTS_REG_ADD_OFFSET * LblNumAlpha) +
               (PORT_JTAG_PPROTS_REG_ADD_OFFSET * LblJtag));
      #endif
      /* END Msg(4:1891)-11 */
      /* END Msg(4:3393)-10 */
      /* END Msg(4:2984)-8 */
      /* END Msg(4:0306)-3 */

      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:2984)-8 */
      /* MISRA Violation: START Msg(4:3393)-10 */
      /* MISRA Violation: START Msg(4:1891)-11 */
      /* Get the address of the corresponding PPCMD register */
      #if (PPCMD_32BIT_REG_AVAILABLE == STD_ON)
      LpPPCMDRegAdd = (uint32 *)((LpPortReg->usRegAddrOffset -
                (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblNumAlpha) +
                ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                               LblJtag)) +
                 LulOsBaseAddress) +
                (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));

      #else
      LpPPCMDRegAdd = (uint8 *)((LpPortReg->usRegAddrOffset -
                (((PORT_NUM_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblNumAlpha) +
                ((PORT_JTAG_PINV_REG_ADD_OFFSET + PORT_OS_BASE_ADDRESS_OFFSET) *
                                                              LblJtag)) +
                 LulOsBaseAddress) +
                (PORT_NUM_PPCMD_REG_ADD_OFFSET * LblNumAlpha) +
                (PORT_JTAG_PPCMD_REG_ADD_OFFSET * LblJtag));
      #endif /* End of (PPCMD_32BIT_REG_AVAILABLE == STD_ON) */
      /* END Msg(4:1891)-11 */
      /* END Msg(4:3393)-10 */
      /* END Msg(4:2984)-8 */
      /* END Msg(4:0306)-3 */
      do
      {
        *LpPPCMDRegAdd = PORT_WRITE_ERROR_CLEAR_VAL;
        /*
         * Write the register value to the corresponding register with upper 16
         * bit set to zero
         */
        *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);

        /*
         * Write the bit wise inverse value to the corresponding register with
         * upper 16 bit set to one
         */
        *Lp32BitRegAddress =
                         (uint16)(~LpPortReg->usInitModeRegVal) | PORT_MSB_MASK;
        /*
         * Write the register value to the corresponding register with upper 16
         * bit set to zero
         */
        *Lp32BitRegAddress = LpPortReg->usInitModeRegVal & (~PORT_MSB_MASK);
        /* Decrement the loop count for each iteration */
        LucLoopCount--;
        /*
         * Check the state of PPROTS register for successful write operation or
         * perform maximum ten tries, if failure occurs report DEM and skip
         * further configuration
         */
      }
      #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
      while (((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
                                               && (PORT_ZERO < LucLoopCount));
      #else
      while ((PORT_ONE == *Lp8BitPPROTSRegAdd) && (PORT_ZERO < LucLoopCount));
      #endif

      #if (PORT_DEM_ERROR_DETECT == STD_ON)
      /*
       * Check if the loop has exited because of failure of writing to register
       */
      #if (PPROTS_32BIT_REG_AVAILABLE == STD_ON)
      if ((uint32)PORT_ONE == *Lp32BitPPROTSRegAdd)
      #else
      if (PORT_ONE == *Lp8BitPPROTSRegAdd)
      #endif
      {
        /*
         * AUTOSAR IMPL [R3, PORT139][R4, PORT139] RULE VIOLATION: As per mantis
         * #6426, the configurable pre-compile switch for detection of
         * production code errors is added
         */
        /* TRACE [R3, PORT037] */
        /* TRACE [R4, PORT037] */
        /* Report write failure production error */
        /* TRACE [R3, PORT146][R4, PORT146] */
        Dem_ReportErrorStatus (PORT_E_WRITE_TIMEOUT_FAILURE,
                                      (PORT_DEM_TYPE) DEM_EVENT_STATUS_FAILED);

        /* Set Return Value as E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      } /* End of *Lp8BitPPROTSRegAdd == PORT_ONE */
      else
      {
        /* No action required */
      }
      #endif
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of (LucNoOfRegs > PORT_ZERO) && (LenReturnValue == E_NOT_OK) */

    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the count of total number of PMSR registers */
    LucNoOfRegs = LucNoOfPMSRRegs;
    /* END Msg(4:2962)-5 */
    while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* Get the pointer to the PMSR registers */
      Lp32BitRegAddress =
         (uint32 *)(LpPMSRReg->usRegAddrOffset + LulUserBaseAddress);

      /* END Msg(4:0306)-3 */
      /* Write the register value to the corresponding register */
      *Lp32BitRegAddress = (LpPMSRReg->usInitModeRegVal | PORT_MSB_MASK);
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPMSRReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */

    /*
     * An atomic access to Microcontroller registers by the use of an exclusive
     * area
     */
    /* TRACE [R3, PORT075][R4, PORT075] */
    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_ENTER_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* Get the count of total number of Function Control PIBC registers */
    LucNoOfRegs = LucNoOfPIBCRegs;
    /* END Msg(4:2962)-5 */
    while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
    {
      /* Check JTAG port */
      if (LblJtag == PORT_ONE)
      {
        /* MISRA Violation: START Msg(4:0306)-2 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* Get the register address by adding the offset to the Base address */
        Lp8BitRegAddress =
               (uint8 *)(LpPortPIBCReg->usRegAddrOffset + LulOsBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0306)-2 */
        /* Write the register value to the corresponding register */
        *Lp8BitRegAddress = (uint8)(LpPortPIBCReg->usInitModeRegVal);
      }
      else
      {
        /* MISRA Violation: START Msg(4:0306)-2 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* Get the register address by adding the offset to the Base address */
        Lp16BitRegAddress =
               (uint16 *)(LpPortPIBCReg->usRegAddrOffset + LulOsBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0306)-2 */
        /* Write the register value to the corresponding register */
        *Lp16BitRegAddress = LpPortPIBCReg->usInitModeRegVal;
        /* MISRA Violation: START Msg(4:0489)-7 */
      }
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortPIBCReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */

    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the count of total number of Function Control PBDC registers */
    LucNoOfRegs = LucNoOfPBDCRegs;
    /* END Msg(4:2962)-5 */
    while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
    {
      /* Check JTAG port */
      if (LblJtag == PORT_ONE)
      {
        /* MISRA Violation: START Msg(4:0306)-2 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* Get the register address by adding the offset to the Base address */
        Lp8BitRegAddress =
               (uint8 *)(LpPortPBDCReg->usRegAddrOffset + LulOsBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0306)-2 */
        /* Write the register value to the corresponding register */
        *Lp8BitRegAddress = (uint8)(LpPortPBDCReg->usInitModeRegVal);
      }
      else
      {
        /* MISRA Violation: START Msg(4:0306)-2 */
        /* MISRA Violation: START Msg(4:2962)-5 */
        /* Get the register address by adding the offset to the Base address */
        Lp16BitRegAddress =
               (uint16 *)(LpPortPBDCReg->usRegAddrOffset + LulOsBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0306)-2 */
        /* Write the register value to the corresponding register */
        *Lp16BitRegAddress = LpPortPBDCReg->usInitModeRegVal;
        /* MISRA Violation: START Msg(4:0489)-7 */
      }
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpPortPBDCReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */

    /* Get the count of total number of Function Control SR registers */
    LucNoOfRegs = LucNoOfPMCSRRegs;
    while ((LucNoOfRegs > PORT_ZERO) && (E_OK == LenReturnValue))
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* Get the pointer to the function control registers */
      Lp32BitRegAddress = (uint32 *)
                        (LpFuncCtrlReg->usRegAddrOffset + LulUserBaseAddress);
      /* END Msg(4:0306)-3 */
      /* Write the register value to the corresponding register */
      *Lp32BitRegAddress = (LpFuncCtrlReg->usInitModeRegVal | PORT_MSB_MASK);
      /* MISRA Violation: START Msg(4:0489)-7 */
      LpFuncCtrlReg++;
      /* END Msg(4:0489)-7 */
      LucNoOfRegs--;
    } /* End of LucNoOfRegs > PORT_ZERO */
  } /* End of LenReturnValue == E_OK */
  else
  {
    /* No action required */
  }
  /* Exit critical section */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_EXIT_CRITICAL_SECTION(INIT_CONFIG_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

} /* End of API Port_InitConfig */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name         : Port_SetInitialValue
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         numeric, alphabetic and JTag ports.
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port group type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Dem_ReportErrorStatus
**                         SchM_Enter_Port_INIT_CONFIG_PROTECTION
**                         SchM_Exit_Port_INIT_CONFIG_PROTECTION
**
** Registers Used        : PIBCn, PIPCn,PMCSRn, PMSRn, JPIBCn, JPIPCn, JPBDCn,
**                         JPMCSRn, JPMSRn, JPDSCn
**
*******************************************************************************/

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_SetInitialValue
                                                 (Port_GroupType LenGroupType)
{
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPIBCReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPBDCReg;
  P2CONST(volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST)LpPortPIPCReg;
  P2CONST(volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                               LpPortPMCSRReg;
  P2CONST(volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)LpPMSRReg;
  P2VAR(volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) Lp32BitRegAddress;
  P2VAR(volatile uint16, AUTOMATIC, PORT_CONFIG_DATA) Lp16BitRegAddress;
  P2VAR(volatile uint8, AUTOMATIC, PORT_CONFIG_DATA) Lp8BitRegAddress;
  uint32 LulUserBaseAddress;
  uint32 LulOsBaseAddress;
  uint8 LucNoOfRegs;
  uint8 LucNoOfPMCSRRegs;
  uint8 LucNoOfPIBCRegs;
  uint8 LucNoOfPBDCRegs;
  uint8 LucNoOfPMSRRegs;
  uint8 LucNoOfPIPCRegs;
  boolean LblJtag = PORT_ZERO;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if (LenGroupType == PORT_GROUP_NUMERIC)
  {
    /* Get the pointer to the Numeric PMSR registers */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* Get the total number of Numeric PMCSR registers */
    LucNoOfPMCSRRegs = PORT_NUM_PMCSR_REGS;
    /* Get the Base address of Numeric Port */
    LulUserBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    /* Get the Base address of Numeric Port */
    LulOsBaseAddress = PORT_OS_BASE_ADDRESS_NUMERIC;
    /* Get the total number of Numeric PIBC registers */
    LucNoOfPIBCRegs = PORT_NUM_PIBC_REGS;
    /* Get the total number of Numeric PBDC registers */
    LucNoOfPBDCRegs = PORT_NUM_PBDC_REGS;
    /* Get the total number of Numeric PMSR registers */
    LucNoOfPMSRRegs = PORT_NUM_PMSR_REGS;
    /* Get the total number of Numeric PIPC registers */
    LucNoOfPIPCRegs = PORT_NUM_PIPC_REGS;
    /* Get the pointer to the Numeric PIBC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    LpPortPIBCReg = Port_GpConfigPtr->pPortNumRegs + (PORT_NUM_PSR_REGS
                    + PORT_NUM_PIS_REGS);
    /* END Msg(4:0488)-6 */
    /* Get the pointer to the Numeric PBDC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    LpPortPBDCReg = Port_GpConfigPtr->pPortNumRegs + (PORT_NUM_PSR_REGS
                    + PORT_NUM_PIS_REGS + PORT_NUM_PIBC_REGS
                    + PORT_NUM_PIPC_REGS + PORT_NUM_PU_REGS
                    + PORT_NUM_PD_REGS);
    /* END Msg(4:0488)-6 */
    /* Get the pointer to the Numeric PMCSR registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    LpPortPMCSRReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs
                    + (PORT_NUM_PFCE_REGS + PORT_NUM_PFC_REGS
                    + PORT_NUM_PFCAE_REGS);
    /* END Msg(4:0488)-6 */
    /* Get the pointer to the Numeric PIPC registers */
    /* MISRA Violation: START Msg(4:0488)-6 */
    LpPortPIPCReg = Port_GpConfigPtr->pPortNumRegs + (PORT_NUM_PSR_REGS
                    + PORT_NUM_PIS_REGS + PORT_NUM_PIBC_REGS);
    /* END Msg(4:0488)-6 */
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  {
    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if (LenGroupType == PORT_GROUP_ALPHABETIC)
    {
      /* Get the pointer to the Alphabetic PMSR registers */
      LpPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
      /* Get the total number of Alphabetic PMCSR registers */
      LucNoOfPMCSRRegs = PORT_ALPHA_PMCSR_REGS;
      /* Get the Base address of Alphabetic Port */
      LulUserBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      /* Get the Base address of Alphabetic Port */
      LulOsBaseAddress = PORT_OS_BASE_ADDRESS_ALPHABETIC;
      /* Get the total number of Alphabetic PIBC registers */
      LucNoOfPIBCRegs = PORT_ALPHA_PIBC_REGS;
      /* Get the total number of Alphabetic PBDC registers */
      LucNoOfPBDCRegs = PORT_ALPHA_PBDC_REGS;
      /* Get the total number of Alphabetic PMSR registers */
      LucNoOfPMSRRegs = PORT_ALPHA_PMSR_REGS;
      /* Get the total number of Alphabetic PIPC registers */
      LucNoOfPIPCRegs = PORT_ALPHA_PIPC_REGS;
      /* Get the pointer to the Alphabetic PIBC registers */
      LpPortPIBCReg = Port_GpConfigPtr->pPortAlphaRegs
                      + (PORT_ALPHA_PSR_REGS + PORT_ALPHA_PIS_REGS);
      /* Get the pointer to the Alphabetic PBDC registers */
      LpPortPBDCReg = Port_GpConfigPtr->pPortAlphaRegs
                      + (PORT_ALPHA_PSR_REGS + PORT_ALPHA_PIS_REGS
                      + PORT_ALPHA_PIBC_REGS + PORT_ALPHA_PIPC_REGS
                      + PORT_ALPHA_PU_REGS + PORT_ALPHA_PD_REGS);
      /* Get the pointer to the Alphabetic PMCSR registers */
      LpPortPMCSRReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs
                      + (PORT_ALPHA_PFCE_REGS + PORT_ALPHA_PFC_REGS
                      + PORT_ALPHA_PFCAE_REGS);
      /* Get the pointer to the Alphabetic PIPC registers */
      LpPortPIPCReg = Port_GpConfigPtr->pPortAlphaRegs
                      + (PORT_ALPHA_PSR_REGS + PORT_ALPHA_PIS_REGS
                      + PORT_ALPHA_PIBC_REGS);
    } /* End of LenGroupType == PORT_GROUP_ALPHABETIC */
    else
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if (LenGroupType == PORT_GROUP_JTAG)
      {
        /* Get the pointer to the JTag PMSR registers */
        LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
        /* Get the total number of JTAG PMCSR registers */
        LucNoOfPMCSRRegs = PORT_JTAG_PMCSR_REGS;
        /* Get the Base address of JTag Port */
        LulUserBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        /* Get the Base address of JTag Port */
        LulOsBaseAddress = PORT_OS_BASE_ADDRESS_JTAG;
        /* Get the total number of JTAG PIBC registers */
        LucNoOfPIBCRegs = PORT_JTAG_PIBC_REGS;
        /* Get the total number of JTAG PBDC registers */
        LucNoOfPBDCRegs = PORT_JTAG_PBDC_REGS;
        /* Get the total number of JTAG PMSR registers */
        LucNoOfPMSRRegs = PORT_JTAG_PMSR_REGS;
        /* Get the total number of JTAG PIPC registers */
        LucNoOfPIPCRegs = PORT_JTAG_PIPC_REGS;
        /* Get the pointer to the JTAG PIBC registers */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LpPortPIBCReg = Port_GpConfigPtr->pPortJRegs + PORT_JTAG_PSR_REGS
                        + PORT_JTAG_PIS_REGS;
        /* END Msg(4:0488)-6 */
        /* Get the pointer to the JTAG PBDC registers */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LpPortPBDCReg = Port_GpConfigPtr->pPortJRegs + PORT_JTAG_PSR_REGS
                        + PORT_JTAG_PIS_REGS + PORT_JTAG_PIBC_REGS
                        + PORT_JTAG_PIPC_REGS + PORT_JTAG_PU_REGS
                        + PORT_JTAG_PD_REGS;
        /* END Msg(4:0488)-6 */
        /* Get the pointer to the JTAG PMCSR registers */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LpPortPMCSRReg = Port_GpConfigPtr->pPortJFuncCtrlRegs
                        + (PORT_JTAG_PFCE_REGS + PORT_JTAG_PFC_REGS
                        + PORT_JTAG_PFCAE_REGS);
        /* END Msg(4:0488)-6 */
        /* Get the pointer to the JTAG PIPC registers */
        /* MISRA Violation: START Msg(4:0488)-6 */
        LpPortPIPCReg = Port_GpConfigPtr->pPortJRegs + (PORT_JTAG_PSR_REGS
                        + PORT_JTAG_PIS_REGS + PORT_JTAG_PIBC_REGS);
        /* END Msg(4:0488)-6 */
        /* Update the local variable as one */
        LblJtag = PORT_ONE;
      } /* End of LenGroupType == PORT_GROUP_JTAG */
      else
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
        if (LenGroupType == PORT_GROUP_ANALOG)
        {
          /* Get the pointer to the Analog PMSR registers */
          LpPMSRReg = Port_GpConfigPtr->pPortAnalogPMSRRegs;
          /* Get the total number of Analog PMCSR registers */
          LucNoOfPMCSRRegs = PORT_ZERO;
          /* Get the Base address of Analog Port */
          LulUserBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
          /* Get the Base address of Analog Port */
          LulOsBaseAddress = PORT_OS_BASE_ADDRESS_ANALOG;
          /* Get the total number of Analog PIBC registers */
          LucNoOfPIBCRegs = PORT_ANALOG_PIBC_REGS;
          /* Get the total number of Analog PBDC registers */
          LucNoOfPBDCRegs = PORT_ANALOG_PBDC_REGS;
          /* Get the total number of Analog PMSR registers */
          LucNoOfPMSRRegs = PORT_ANALOG_PMSR_REGS;
          /* Get the total number of Analog PIPC registers */
          LucNoOfPIPCRegs = PORT_ANALOG_PIPC_REGS;
          /* Get the pointer to the Analog PIBC registers */
          /* MISRA Violation: START Msg(4:0488)-6 */
          LpPortPIBCReg = Port_GpConfigPtr->pPortAnalogRegs
                          + (PORT_ANALOG_PSR_REGS + PORT_ANALOG_PIS_REGS);
          /* END Msg(4:0488)-6 */
          /* Get the pointer to the Analog PBDC registers */
          /* MISRA Violation: START Msg(4:0488)-6 */
          LpPortPBDCReg = Port_GpConfigPtr->pPortAnalogRegs
                          + (PORT_ANALOG_PSR_REGS + PORT_ANALOG_PIS_REGS
                          + PORT_ANALOG_PIBC_REGS + PORT_ANALOG_PIPC_REGS
                          + PORT_ANALOG_PU_REGS + PORT_ANALOG_PD_REGS);
          /* END Msg(4:0488)-6 */
        } /* End of LenGroupType == PORT_GROUP_ANALOG */
        else
        #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
          if (LenGroupType == PORT_GROUP_INPUT)
          {
            /* Get the pointer to the Input PMSR registers */
            LpPMSRReg = NULL_PTR;
            /* Get the total number of Input PMCSR registers */
            /* START Message(5:2982)-14 */
            LucNoOfPMCSRRegs = PORT_ZERO;
            /* END Message(5:2982)-14 */
            /* Get the Base address of Input Port */
            LulUserBaseAddress = PORT_USER_BASE_ADDRESS_INPUT;
            /* Get the Base address of Input Port */
            LulOsBaseAddress = PORT_OS_BASE_ADDRESS_INPUT;
            /* Get the total number of Input PIBC registers */
            LucNoOfPIBCRegs = PORT_INPUT_PIBC_REGS;
            /* Get the total number of Input PBDC registers */
            LucNoOfPBDCRegs = PORT_ZERO;
            /* Get the total number of Input PMSR registers */
            LucNoOfPMSRRegs = PORT_ZERO;
            /* Get the total number of Input PMCSR registers */
            LucNoOfPMCSRRegs = PORT_ZERO;
            /* Get the total number of Input PIPC registers*/
            LucNoOfPIPCRegs = PORT_ZERO;
            /* Get the pointer to the JTAG PIBC registers */
            LpPortPIBCReg = Port_GpConfigPtr->pPortInputRegs;
          } /* End of LenGroupType == PORT_GROUP_INPUT */
          else
          {
            /* No action required */
          }
          #endif /* End of PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON */
        }
      }
    }
  }

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 16Bit PIBC registers */
  LucNoOfRegs = LucNoOfPIBCRegs;
  /* END Msg(4:2962)-5 */
  /* Port initialization PIBCn.PIBCn_m=0 */
  while (LucNoOfRegs > PORT_ZERO)
  {
    /* Check JTAG port */
    if (LblJtag == PORT_ONE)
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp8BitRegAddress = (uint8 *)(LpPortPIBCReg->usRegAddrOffset
       + LulOsBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register initial value to the PIPC registers */
      *Lp8BitRegAddress = PORT_ZERO;
    }
    else
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp16BitRegAddress = (uint16 *)(LpPortPIBCReg->usRegAddrOffset
       + LulOsBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register initial value to the PIPC registers */
      *Lp16BitRegAddress = PORT_WORD_ZERO;
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPIBCReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 16Bit PBDC registers */
  LucNoOfRegs = LucNoOfPBDCRegs;
  /* END Msg(4:2962)-5 */
  /* Port initialization PBDCn.PGDCn_m=0 */
  while (LucNoOfRegs > PORT_ZERO)
  {
    /* Check JTAG port */
    if (LblJtag == PORT_ONE)
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp8BitRegAddress = (uint8 *)(LpPortPBDCReg->usRegAddrOffset
       + LulOsBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register initial value to the PBDC registers */
      *Lp8BitRegAddress = PORT_ZERO;
    }
    else
    {
      /* MISRA Violation: START Msg(4:0306)-2 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* Get the register address by adding the offset to the Base address */
      Lp16BitRegAddress = (uint16 *)(LpPortPBDCReg->usRegAddrOffset
       + LulOsBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-2 */
      /* Write the register initial value to the PBDC registers */
      *Lp16BitRegAddress = PORT_WORD_ZERO;
    }
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPBDCReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* MISRA Violation: START Msg(4:2962)-4 */
  /* Get the count of total number of 32Bit PMSR registers */
  LucNoOfRegs = LucNoOfPMSRRegs;
  /* END Msg(4:2962)-4 */
  /* Port initialization PMn.Pmn_m=1 */
  while (LucNoOfRegs > PORT_ZERO)
  {
    /* MISRA Violation: START Msg(4:0306)-2 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress = (uint32 *)((LpPMSRReg->usRegAddrOffset) +
                                                            LulUserBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-2 */
    /* Write the register initial value to the PMSR registers */

    *Lp32BitRegAddress = (PORT_MSB_MASK|PORT_LSB_MASK);
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPMSRReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 32Bit PMCSR registers */
  LucNoOfRegs = LucNoOfPMCSRRegs;
  /* END Msg(4:2962)-5 */
  /* Port initialization PMCn.PMCn_m=0 */
  while (LucNoOfRegs > PORT_ZERO)
  {
    /* MISRA Violation: START Msg(4:0306)-2 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset to the Base address */
    Lp32BitRegAddress = (uint32 *)((LpPortPMCSRReg->usRegAddrOffset) +
                                                            LulUserBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-2 */
    /* Write the register initial value to the PMCSR registers */
    *Lp32BitRegAddress = PORT_MSB_MASK;

    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPMCSRReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* MISRA Violation: START Msg(4:2962)-5 */
  /* Get the count of total number of 16Bit PIPC registers */
  LucNoOfRegs = LucNoOfPIPCRegs;
  /* END Msg(4:2962)-5 */
  /* Port initialization PIPCn.PIPCn_m=0 */
  while (LucNoOfRegs > PORT_ZERO)
  {
    /* MISRA Violation: START Msg(4:0306)-2 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the register address by adding the offset to the Base address */
    Lp16BitRegAddress = (uint16 *)(LpPortPIPCReg->usRegAddrOffset
     + LulOsBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-2 */
    /* Write the register initial value to the PIPC registers */
    *Lp16BitRegAddress = PORT_WORD_ZERO;

    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPortPIPCReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
} /* End of API Port_InitConfig */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Port_SearchDirChangeablePin
**
** Service ID            : Not Applicable
**
** Description           : This function used to verify whether the given pin is
**                         Direction changeable.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : LddPinNumber - Port Pin number
**                         LpStartPtr - Start pointer to the Changeable pin
**                         structures.
**                         Lucsize - Size of the Changeable pin structures.
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : Pointer to Direction Changeable Pin structure - if
**                         given pin number matches.
**                         NULL - If Pin number does not match.
**
** Preconditions         : None
**
** Global Variables Used : None
**
** Functions Invoked     : None
**
** Registers Used        : None
*******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC
FUNC(P2CONST(Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST),
    PORT_PRIVATE_CODE) Port_SearchDirChangeablePin(Port_PinType LddPinNumber,
    P2CONST(Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
    LpStartPtr, uint8 Lucsize)
{
  /* Initializing Direction Control Registers Pointer to Null pointer */
  P2CONST (Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_DATA) LpRetPtr
                                                              = NULL_PTR;
  uint8 LddLow;
  uint8 LddHigh;
  uint8 LddMid;
  uint16 LddListSearchId;
  LddHigh = Lucsize - PORT_ONE;
  LddLow = PORT_ONE;
  /* Get the lower limit of Search ID */
  LddListSearchId = LpStartPtr->ddPinId;
  /* MISRA Violation: START Msg(4:0488)-6 */
  /* Check whether search Search-ID is in range */
  if ((LddPinNumber >= LddListSearchId) &&
     (LddPinNumber <= ((LpStartPtr + LddHigh)->ddPinId)))
  /* END Msg(4:0488)-6 */
  {
    /*
     * Check whether requested Search-ID is same as first Search-ID of the list
     */
    if (LddPinNumber != LddListSearchId)
    {
      do
      {
        /* Get the middle index number */
        LddMid = (LddHigh + LddLow) >> PORT_ONE;
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get the Search-ID of the mid IDs */
        LddListSearchId = ((LpStartPtr + LddMid)->ddPinId);
        /* END Msg(4:0488)-6 */
        /* Compare Search-ID with the requested one */
        if (LddListSearchId == LddPinNumber)
        {
          /* MISRA Violation: START Msg(4:0488)-6 */
          /* Update the return pointer with the pin number structure */
          LpRetPtr = (LpStartPtr + LddMid);
          /* END Msg(4:0488)-6 */
          /* Set LddHigh to zero to break the loop */
          LddHigh = PORT_ZERO;
        } /* End of LddListSearchId == LddPinNumber */
        else
        {
          /* Compare the Search-ID with the requested one */
          if (LddPinNumber < LddListSearchId)
          {
            /* If the priority is lower, update LddHigh */
            LddHigh = LddMid - PORT_ONE;
          } /* End of LddPinNumber < LddListSearchId */
          else
          {
            /* If the priority is higher, update LddLow */
            LddLow = LddMid + PORT_ONE;
          }
        }
      }while(LddLow <= LddHigh);

    } /* End of LddPinNumber != LddListSearchId */
    else
    {
      /* Update the return pointer with start pointer (Matches with first Id) */
      LpRetPtr = LpStartPtr;
    }
  } /*
     * (LddPinNumber >= LddListSearchId) &&
     * (LddPinNumber <= ((LpStartPtr + LddHigh)->ddPinId))
     */
  else
  {
    /* No action required */
  }
  return (LpRetPtr);
} /* End of API Port_SearchDirChangeablePin */

#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DIRECTION_API == STD_ON) */

/*******************************************************************************
** Function Name         : Port_RefreshPortInternal
**
** Service ID            : Not Applicable
**
** Description           : This service shall refresh the direction of all
**                         configured ports to the configured direction.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : LenGroupType - Port Group Type
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**
** Global Variables Used : Port_GpConfigPtr
**
** Functions Invoked     : Det_ReportError
**                         SchM_Enter_Port_REFRESH_PORT_INTERNAL_PROTECTION
**                         SchM_Exit_Port_REFRESH_PORT_INTERNAL_PROTECTION
**
** Registers Used        : PMSRn, JPMSRn.
*******************************************************************************/
/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_RefreshPortInternal
                                                 (Port_GroupType LenGroupType)
{
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)LpPMSRReg;
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_DATA) LpPMSRRegAddress;
  uint32 LulBaseAddress;
  uint8 LucNoOfRegs;

  /*
   * An atomic access to Microcontroller registers by the use of an exclusive
   * area
   */
  /* TRACE [R3, PORT075][R4, PORT075] */
  /* Enter critical section */

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  if (PORT_GROUP_NUMERIC == LenGroupType)
  {
    /* Get the pointer to 32Bit Numeric PMSR register structure */
    LpPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    /* Get the count of 32Bit Numeric PMSR registers */
    LucNoOfRegs = PORT_NUM_PSR_REGS;
    /* Get the Numeric base address */
    LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
  } /* End of LenGroupType == PORT_GROUP_NUMERIC */
  else
  #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
  {
    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if (PORT_GROUP_ALPHABETIC == LenGroupType)
    {
      /* Get the pointer to 32Bit Alphabetic PMSR register structure */
      LpPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
      /* Get the count of 32Bit Alphabetic PMSR registers */
      LucNoOfRegs = PORT_ALPHA_PSR_REGS;
      /* Get the Alphabetic base address */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
    } /* End of LenGroupType == PORT_GROUP_ALPHABETIC */
    else
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
      if (PORT_GROUP_JTAG == LenGroupType)
      {
        /* Get the pointer to 32Bit JTAG PMSR register structure */
        LpPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
        /* Get the count of 32Bit JTAG PMSR registers */
        LucNoOfRegs = PORT_JTAG_PSR_REGS;
        /* Get the JTAG base address */
        LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
      } /* End of LenGroupType == PORT_GROUP_JTAG */
      else
      #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
        if (PORT_GROUP_ANALOG == LenGroupType)
        {
          /* Get the pointer to 32Bit Analog PMSR register structure */
          LpPMSRReg = Port_GpConfigPtr->pPortAnalogPMSRRegs;
          /* Get the count of 32Bit Analog PMSR registers */
          LucNoOfRegs = PORT_ANALOG_PSR_REGS;
          /* Get the Analog base address */
          LulBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
        } /* End of LenGroupType == PORT_GROUP_ANALOG */
        else
        {
          /* No action required */
        }
        #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
      }
    }
  }

  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_ENTER_CRITICAL_SECTION(REFRESH_PORT_INTERNAL_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  /* MISRA Violation: START Msg(4:2962)-5 */
  while (PORT_ZERO < LucNoOfRegs)
  /* END Msg(4:2962)-5 */
  {
    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the contents of the register */
    LpPMSRRegAddress = (uint32 *)(LpPMSRReg->usRegAddrOffset +
                                                LulBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-3 */
    /* TRACE [R3, PORT066][R4, PORT066] */
    /* TRACE [R3, PORT061][R4, PORT061] */
    /*
     * Write the initial value to the pins which are Directional unchangeable
     * and retain the values of those pins which are Directional changeable
     */
    *LpPMSRRegAddress = LpPMSRReg->ulMaskAndConfigValue;
    /* MISRA Violation: START Msg(4:0489)-7 */
    LpPMSRReg++;
    /* END Msg(4:0489)-7 */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */

  /* Exit critical section */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_EXIT_CRITICAL_SECTION(REFRESH_PORT_INTERNAL_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

} /* End of API Port_RefreshPortInternal */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name         : Port_FilterConfig
**
** Service ID            : Not Applicable
**
** Description           : This function used to initialize all the registers of
**                         filter configuration.
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Non-Reentrant
**
** Input Parameters      : None
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : None
**
** Global Variables Used : Port_GpConfigPtr.
**
** Functions Invoked     : None
**
** Registers Used        : DNFA, FCLA, DNFAnCTL, DNFAnEN, DNFCKSnC, FCLAnCTL.
*******************************************************************************/
#if ((PORT_DNFA_REG_CONFIG == STD_ON) || (PORT_FCLA_REG_CONFIG == STD_ON))

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, PORT_PRIVATE_CODE) Port_FilterConfig(void)
{
  /* Pointer to digital filter DNFA register data structure */
  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  P2CONST(volatile Port_DNFARegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFAReg;


  /* Pointer to Edge control EDC register data structure */
  #if (PORT_EDGE_DETECT_CONTROL == STD_ON)
  P2CONST(volatile Port_EDCRegs, AUTOMATIC, PORT_CONFIG_DATA) LpEDCReg;
  #endif /* End of PORT_EDGE_DETECT_CONTROL == STD_ON */

  /* Pointer to analog filter FCLA register data structure */
  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  P2CONST(volatile Port_FCLARegs, AUTOMATIC, PORT_CONFIG_DATA) LpFCLAReg;
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */

  /* Pointer to digital filter DNFCKS register data structure */
  #if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
  P2CONST(volatile Port_DNFCKSRegs, AUTOMATIC, PORT_CONFIG_DATA) LpDNFCKSReg;
  #endif /* End of PORT_DNF_CLK_SRC_AVAILABLE == STD_ON */

  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  uint32 LulBaseAddress;
  uint8 LucNoOfRegs;
  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
  uint16 LusCount;
  LusCount = PORT_WORD_ZERO;
  #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
  #endif
  #if (PORT_EDGE_DETECT_CONTROL == STD_ON)
  /* Get the base address for DNFA Noise Elimination Registers */
  LulBaseAddress = PORT_DNFA_BASE_ADDRESS;

  /* Get the pointer to the details of EDC Registers */
  LpEDCReg = Port_GpConfigPtr->pPortEDCRegs;

  /* Get the count for total number of EDC Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfEDCRegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* Write the DNFnEDCm register value to the corresponding register */
    *((uint8 *)(LulBaseAddress + (uint32)LpEDCReg->usDNFEDCRegAddrOffset)) =
                                                  LpEDCReg->ucDNFEDC;

    /* Increment the pointer to get the value of next structure */
    LpEDCReg++;
    /* Decrement the count for total number of EDC Registers */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_EDGE_DETECT_CONTROL == STD_ON */

  #if (PORT_DNFA_REG_CONFIG == STD_ON)
  /* Get the base address for DNFA Noise Elimination Registers */
  LulBaseAddress = PORT_DNFA_BASE_ADDRESS;

  /* Get the pointer to the details of DNFA Noise Elimination Registers */
  LpDNFAReg = Port_GpConfigPtr->pPortDNFARegs;

  /* Get the count for total number of DNFA Noise Elimination Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfDNFARegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* Write the DNFAnCTL register value to the corresponding register */
    *((uint8 *)(LulBaseAddress + (uint32)LpDNFAReg->usDNFARegAddrOffset)) =
                                                          LpDNFAReg->ucDNFACTL;
    #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)

    /* Write the DNFAnEN register value to the corresponding register */
    *((uint16 *)(LulBaseAddress + (uint32)LpDNFAReg->usDNFARegAddrOffset +
                           PORT_DNFAEN_ADDRESS_OFFSET)) = LpDNFAReg->usDNFAEN;

    while(LusCount < (LpDNFAReg->usDELAY))
    {
      ASM_NOP();
      LusCount++;
    }
    LusCount = PORT_WORD_ZERO;
    #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
    /* Increment the pointer to get the value of next structure */
    LpDNFAReg++;
    /* Decrement the count for total number of DNFA Registers */
    LucNoOfRegs--;

  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

  #if (PORT_FCLA_REG_CONFIG == STD_ON)
  /* Get the base address for FCLA Noise Elimination Registers */
  LulBaseAddress = PORT_FCLA_BASE_ADDRESS;
  /* Get the pointer to the details of FCLA Noise Elimination Registers */
  LpFCLAReg = Port_GpConfigPtr->pPortFCLARegs;
  /* Get the count for total number of FCLA Noise Elimination Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfFCLARegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* Write the FCLAnCTL register value to the corresponding register */
    *((uint8 *)(LulBaseAddress + (uint32)LpFCLAReg->usFCLARegAddrOffset)) =
                                                          LpFCLAReg->ucFCLACTL;

    /* Increment the pointer to get the value of next structure */
    LpFCLAReg++;

    /* Decrement the count for total number of FCLA Registers */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_FCLA_REG_CONFIG == STD_ON */

  #if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
  /* Get the base address for DNFCKS Noise Elimination Registers */
  LulBaseAddress = PORT_DNFCKS_BASE_ADDRESS;

  /* Get the pointer to the details of DNFA Noise Elimination Registers */
  LpDNFCKSReg = Port_GpConfigPtr->pPortDNFCKSRegs;

  /* Get the count for total number of DNFA Noise Elimination Registers */
  LucNoOfRegs = Port_GpConfigPtr->ucNoOfDNFCKSRegs;
  while (PORT_ZERO < LucNoOfRegs)
  {
    /* Write the DNFAnCTL register value to the corresponding register */
    *((uint32 *)(LulBaseAddress + (uint32)LpDNFCKSReg->usDNFCKSRegAddrOffset)) =
                                                     LpDNFCKSReg->ulDNFCKS;
    /* Increment the pointer to get the value of next structure */
    LpDNFCKSReg++;
    /* Decrement the count for total number of DNFA Registers */
    LucNoOfRegs--;
  } /* End of LucNoOfRegs > PORT_ZERO */
  #endif /* End of PORT_DNFA_REG_CONFIG == STD_ON */

} /* End of API Port_FilterConfig */
#define PORT_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /*
        * End of (PORT_DNFA_REG_CONFIG == STD_ON) ||
        * (PORT_FCLA_REG_CONFIG == STD_ON)
        */

/*******************************************************************************
** Function Name         : Port_SetPinDefaultMode
**
** Service ID            : 0x07
**
** Description           : This function used to set the mode of a port pin
**                         during runtime. The PORT Driver module allows
**                         changing the mode of the pin to default mode set by
**                         the configuration at the time of Port_Init().
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be initialized by calling Port_init().
**                         Port_SetPinMode() should be invoked during runtime.
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_SET_PIN_DEFAULT_MODE_PROTECTION,
**                         SchM_Exit_Port_SET_PIN_DEFAULT_MODE_PROTECTION,
**                         Port_SearchModeChangeablePin.
**
** Registers Used        : PMCSR, PFC, PFCE, PSR, PMSR, PFCAE
*******************************************************************************/
#if ((PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) && \
                     (PORT_SET_PIN_MODE_API == STD_ON))

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDefaultMode (Port_PinType Pin)
{
  P2CONST (Port_PinModeChangeableDetails, AUTOMATIC, PORT_CONFIG_CONST)
                                                          LpModeChangeablePin;

  /* Pointer to Alternate mode data structure */
  P2CONST (Port_PinModeChangeableGroups, AUTOMATIC, PORT_CONFIG_CONST)
                                         LpSetPinModeGroupStruct;

  /* Pointer to Port Registers Data structure */
  P2CONST (volatile Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) LpPortReg;

  /* Pointer to Alternate Function Control Registers Data structure */
  P2CONST (volatile Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                                LpFuncCtrlReg;

  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;

  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST) LpRegAddr;

  /* Pointer to hold the register address 16 bit value */
  P2VAR (volatile uint16, AUTOMATIC, PORT_CONFIG_CONST) Lp16BitRegAddr;

  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;

  /* END Msg(4:0759)-1 */
  uint32 LulBaseAddress;

  uint16 LusOrMask;
  uint16 LusInitDirection;
  uint16 LusInitMode;

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;
  #endif

  LpModeChangeablePin = NULL_PTR;

  /*
   * If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, PORT077][R4, PORT077] */
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                              PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* Port_GblDriverStatus == PORT_UNINITIALIZED */
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                           PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  } /* End of Pin >= PORT_TOTAL_NUMBER_OF_PINS */
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* Check whether the Pin mode is changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                              Port_GpConfigPtr->pPinModeChangeableDetails,
                              Port_GpConfigPtr->ucNoOfPinsModeChangeable);

    /* Return value LpModeChangeablePin - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpModeChangeablePin)
    {
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_DEFAULT_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    } /* End of LpModeChangeablePin == NULL_PTR */
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  } /* End of LenReturnValue == E_NOT_OK */

  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_OFF)
    /* Check whether the Pin is mode changeable at run time */
    LpModeChangeablePin = Port_SearchModeChangeablePin (Pin,
                          Port_GpConfigPtr->pPinModeChangeableDetails,
                          Port_GpConfigPtr->ucNoOfPinsModeChangeable);
    #endif

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* Get the pointer to the Set Mode group list */
    LpSetPinModeGroupStruct = ((Port_GpConfigPtr->pPinModeChangeableGroups)
                                    + (LpModeChangeablePin->ucSetModeIndex));
    /* END Msg(4:0488)-6 */
    /* If the Pin group is of Numeric type */
    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_NUMERIC == LpModeChangeablePin->ucPortType)
    {
      LpPortReg = Port_GpConfigPtr->pPortNumRegs;
      LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
      LpFuncCtrlReg = Port_GpConfigPtr->pPortNumFuncCtrlRegs;
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
    } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_NUMERIC */
    else
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */
    {
      #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
      if ((uint8)PORT_GROUP_ALPHABETIC == LpModeChangeablePin->ucPortType)
      {
        LpPortReg = Port_GpConfigPtr->pPortAlphaRegs;
        LpPortPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
        LpFuncCtrlReg = Port_GpConfigPtr->pPortAlphaFuncCtrlRegs;
        LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_ALPHABETIC */
      else
      #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */
      {
        #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
        if ((uint8)PORT_GROUP_JTAG == LpModeChangeablePin->ucPortType)
        {
          LpPortReg = Port_GpConfigPtr->pPortJRegs;
          LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
          LpFuncCtrlReg = Port_GpConfigPtr->pPortJFuncCtrlRegs;
          LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
        } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_JTAG */
        else
        #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */
        {
          #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
          if ((uint8)PORT_GROUP_ANALOG == LpModeChangeablePin->ucPortType)
          {
            LpPortReg = Port_GpConfigPtr->pPortAnalogRegs;
            LpPortPMSRReg = Port_GpConfigPtr->pPortAnalogPMSRRegs;
            LulBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
          } /* End of LpModeChangeablePin->ucPortType == PORT_GROUP_ANALOG */
          else
          {
            /* No action required */
          }
          #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */
        }
      }
    }

    /*
     * An atomic access to Microcontroller registers by the use of an exclusive
     * area
     */
    /* TRACE [R3, PORT075][R4, PORT075] */
    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_ENTER_CRITICAL_SECTION(SET_PIN_DEFAULT_MODE_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /*
     * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
     * variable to 1 of the configured pin whose Mode has to be changed
     */
     LusOrMask = LpModeChangeablePin->usOrMask;

     LunSRRegContent.Tst_Port_Word.usMSWord = LusOrMask;
     /* MISRA Violation: START Msg(4:0488)-6 */
     /* MISRA Violation: START Msg(4:2962)-5 */
     LusInitMode = ((LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usInitModeRegVal) &
                                                                      LusOrMask;
    /* END Msg(4:0488)-6 */
    /* END Msg(4:2962)-5 */

    /* MISRA Violation: START Msg(4:0488)-6 */
    /* MISRA Violation: START Msg(4:2962)-5 */
     LusInitDirection = ((LpPortPMSRReg +
               LpSetPinModeGroupStruct->ucPMSRRegIndex)->usInitModeRegVal) &
                                                                      LusOrMask;
     /* END Msg(4:0488)-6 */
    /* END Msg(4:2962)-5 */
    if((LusInitMode == PORT_WORD_ZERO) && (LusInitDirection == PORT_WORD_ZERO))
    {
      /* Write PSR register.Check for PSR register availability */
      if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPSRRegIndex)
      {
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Write Initial mode register value into Lower word of PSR variable */
        LunSRRegContent.Tst_Port_Word.usLSWord = ((LpPortReg +
                 LpSetPinModeGroupStruct->ucPSRRegIndex)->usInitModeRegVal);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0488)-6 */
        /* MISRA Violation: START Msg(4:0306)-3 */
        /* MISRA Violation: START Msg(4:0488)-6 */
        /* Get the PSR register Address */
        LpRegAddr = (uint32 *)((LpPortReg +
                    LpSetPinModeGroupStruct->ucPSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
        /* END Msg(4:2962)-5 */
        /* END Msg(4:0488)-6 */
        /* END Msg(4:0306)-3 */

        /*
         * Bit value of Upper 16 bits (31-16) of PSR register is to set 1
         * Bit value of Lower 16 bits (15-0) of PSR register is equal to Initial
         * value for the corresponding pin position
         */
        *LpRegAddr = LunSRRegContent.ulRegContent;
      } /* LpSetPinModeGroupStruct->ucPSRRegIndex != PORT_REG_NOTAVAILABLE */
      else
      {
        /* No action required */
      }
    }

    /* Write PMSR register.Check for PMSR register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the PMSR register Address */
      LpRegAddr = (uint32 *)((LpPortPMSRReg +
                    LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-3 */

      LunSRRegContent.Tst_Port_Word.usLSWord = ((LpPortPMSRReg +
               LpSetPinModeGroupStruct->ucPMSRRegIndex)->usInitModeRegVal) &
                                                                      LusOrMask;
      /* END Msg(4:0488)-6 */
      /*
       * Write the contents of Lower word and Upper word of PMSR variable
       * into the PMSR register address
       */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    }
    else
    {
      /* No action required */
    } /*
       * End of LpSetPinModeGroupStruct->ucPMSRRegIndex !=
       * PORT_REG_NOTAVAILABLE
       */

    /* Write PFCE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCERegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCERegIndex)->usRegAddrOffset +
               LulBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-3 */
      /* If bit needs to be set, OR the register contents with OrMask */
       *Lp16BitRegAddr =
          ((*Lp16BitRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
              LpSetPinModeGroupStruct->ucPFCERegIndex)->usInitModeRegVal) &
                                                                  LusOrMask);
      /* END Msg(4:0488)-6 */
    } /* End of Write PFCE register */
    else
    {
      /* No action required */
    }

    /* Write PFC register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCRegIndex)->usRegAddrOffset +
                 LulBaseAddress);
      /* END Msg(4:0306)-3 */

      /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr =
         ((*Lp16BitRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCRegIndex)->usInitModeRegVal) &
                                                                     LusOrMask);
      /* END Msg(4:0488)-6 */
    } /* End of Write PFC register */
    else
    {
      /* No action required */
    }

    /* Write PFCAE register.Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPFCAERegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      Lp16BitRegAddr = (uint16 *)((LpFuncCtrlReg +
                 LpSetPinModeGroupStruct->ucPFCAERegIndex)->usRegAddrOffset
                 + LulBaseAddress);
      /* END Msg(4:0306)-3 */

      /* If bit needs to be set, OR the register contents with OrMask */
        *Lp16BitRegAddr =
          ((*Lp16BitRegAddr)&(uint16)(~LusOrMask)) | (((uint16)(LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPFCAERegIndex)->usInitModeRegVal) &
                                                                     LusOrMask);
      /* END Msg(4:0488)-6 */
    } /* End of Write PFCAE register */
    else
    {
      /* No action required */
    }

    /* Write PMCSR register. Check for register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMCSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the address of PMCSR register */
      LpRegAddr = (uint32 *)((LpFuncCtrlReg +
                  LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usRegAddrOffset
                  + LulBaseAddress);
      /* END Msg(4:0488)-6 */
      /* END Msg(4:0306)-3 */
      /*
       * Write the requested direction into Lower word of PMCSR variable
       * by using OR mask
       */
      /* MISRA Violation: START Msg(4:0488)-6 */
      LunSRRegContent.Tst_Port_Word.usLSWord = ((LpFuncCtrlReg +
               LpSetPinModeGroupStruct->ucPMCSRRegIndex)->usInitModeRegVal) &
                                                                      LusOrMask;
      /* END Msg(4:0488)-6 */
      /* Write the corresponding 32 bit value to the PMCSR register */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    } /* End of Write PMCSR register */
    else
    {
      /* No action required */
    }

    /* Write PMSR register.Check for PMSR register availability */
    if (PORT_REG_NOTAVAILABLE != LpSetPinModeGroupStruct->ucPMSRRegIndex)
    {
      /* MISRA Violation: START Msg(4:0306)-3 */
      /* MISRA Violation: START Msg(4:2962)-5 */
      /* MISRA Violation: START Msg(4:0488)-6 */
      /* Get the PMSR register Address */
      LpRegAddr = (uint32 *)((LpPortPMSRReg +
                    LpSetPinModeGroupStruct->ucPMSRRegIndex)->usRegAddrOffset
                    + LulBaseAddress);
      /* END Msg(4:2962)-5 */
      /* END Msg(4:0306)-3 */

      LunSRRegContent.Tst_Port_Word.usLSWord = ((LpPortPMSRReg +
               LpSetPinModeGroupStruct->ucPMSRRegIndex)->usInitModeRegVal) &
                                                                      LusOrMask;
      /* END Msg(4:0488)-6 */
      /*
       * Write the contents of Lower word and Upper word of PMSR variable
       * into the PMSR register address
       */
      *LpRegAddr = LunSRRegContent.ulRegContent;
    }
    else
    {
      /* No action required */
    } /*
       * End of LpSetPinModeGroupStruct->ucPMSRRegIndex !=
       * PORT_REG_NOTAVAILABLE
       */

  /* Exit critical section */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_EXIT_CRITICAL_SECTION(SET_PIN_DEFAULT_MODE_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

  } /* End of LenReturnValue == E_NOT_OK */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif

} /* End of API Port_SetPinDefaultMode */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DEFAULT_MODE_API == STD_ON) */

/*******************************************************************************
** Function Name         : Port_SetPinDefaultDirection
**
** Service ID            : 0x08
**
** Description           : This service sets the port pin direction during
**                         runtime. The PORT Driver module allows changing the
**                         direction of the pin to configured direction set by
**                         the configuration at the time of Port_Init().
**
** Sync/Async            : Synchronous
**
** Reentrancy            : Reentrant
**
** Input Parameters      : Pin - Port Pin ID number
**
** InOut Parameters      : None
**
** Output Parameters     : None
**
** Return Parameter      : None
**
** Preconditions         : Ports should be  initialized by calling Port_Init().
**                         Port_SetPinDirection() should be invoked during
**                         runtime.
**
** Global Variables Used : Port_GblDriverStatus, Port_GpConfigPtr.
**
** Functions Invoked     : Det_ReportError,
**                         SchM_Enter_Port_SET_PIN_DEFAULT_DIR_PROTECTION,
**                         SchM_Exit_Port_SET_PIN_DEFAULT_DIR_PROTECTION,
**                         Port_SearchDirChangeablePin.
**
** Registers Used        : PMSR, APMSR
*******************************************************************************/
#if ((PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON) && \
                     (PORT_SET_PIN_DIRECTION_API == STD_ON))

/* TRACE [R4, PORT131] */
#define PORT_START_SEC_PUBLIC_CODE
#include "MemMap.h"

FUNC (void, PORT_PUBLIC_CODE) Port_SetPinDefaultDirection (Port_PinType Pin)
{
  P2CONST(volatile Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                            LpChangeablePinDet;

  /* Pointer to Direction Control Registers Data structure */
  P2CONST (volatile Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST) LpPortPMSRReg;

  /* Pointer to hold the register address of 32 bit value */
  P2VAR (volatile uint32, AUTOMATIC, PORT_CONFIG_CONST) LpRegAddr;

  /* MISRA Violation: START Msg(4:0759)-1 */
  Port_Pin_Direction LunSRRegContent;
  /* END Msg(4:0759)-1 */
  uint32 LulBaseAddress;
  uint16 LusOrMask;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Variable to store the return value and Initialize the return value */
  Std_ReturnType LenReturnValue;

  /* Initialize the return value */
  LenReturnValue = E_OK;
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */

  LpChangeablePinDet = NULL_PTR;
  LpPortPMSRReg = NULL_PTR;

  /*
   * If DET is enabled, the API parameter checking shall be performed according
   * to the respective functions
   */
  /* TRACE [R3, PORT031] */
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* TRACE [R3, PORT077][R4, PORT077] */
  /* Check whether the PORT module is initialized */
  if (PORT_UNINITIALIZED == Port_GblDriverStatus)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                               PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_UNINIT);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether the requested PIN number is invalid */
  if (PORT_TOTAL_NUMBER_OF_PINS <= Pin)
  {
    /* TRACE [R3, PORT146][R4, PORT146] */
    /* Report to DET */
    (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                            PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_PARAM_PIN);
    /* Set Return Value as E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  {
    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);

    /* Return value LpChangeablePinDet - Changeable, NULL - Unchangeable */
    if (NULL_PTR == LpChangeablePinDet)
    {
      /* TRACE [R3, PORT146][R4, PORT146] */
      /* Report to DET */
      (void)Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID,
                 PORT_SET_PIN_DEFAULT_DIR_SID, PORT_E_DIRECTION_UNCHANGEABLE);
      /* Set Return Value as E_NOT_OK */
      LenReturnValue = E_NOT_OK;
    }
    else
    {
      /* No action required */
    }
  }
  else
  {
    /* No action required */
  }

  if (E_OK == LenReturnValue)
  #endif /* End of PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if (PORT_DEV_ERROR_DETECT == STD_OFF)

    /* Check whether the Pin direction is changeable at run time */
    LpChangeablePinDet = Port_SearchDirChangeablePin (Pin,
                         Port_GpConfigPtr->pPinDirChangeable,
                         Port_GpConfigPtr->ucNoOfPinsDirChangeable);
    #endif /* End of PORT_DEV_ERROR_DETECT == STD_OFF */

    /* Get the base address of the corresponding Port Type */

    #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_NUMERIC == LpChangeablePinDet->ucPortType)
    {
      /* Get the Base address of Numeric Port */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_NUMERIC;
      LpPortPMSRReg = Port_GpConfigPtr->pPortNumPMSRRegs;
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_ALPHABETIC == LpChangeablePinDet->ucPortType)
    {
      /* Get the Base address of Alphabetic Port */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ALPHABETIC;
      LpPortPMSRReg = Port_GpConfigPtr->pPortAlphaPMSRRegs;
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_JTAG == LpChangeablePinDet->ucPortType)
    {
      /* Get the Base address of JTag Port */
      LulBaseAddress = PORT_USER_BASE_ADDRESS_JTAG;
      LpPortPMSRReg = Port_GpConfigPtr->pPortJPMSRRegs;
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON */

    #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
    if ((uint8)PORT_GROUP_ANALOG == LpChangeablePinDet->ucPortType)
    {
      LulBaseAddress = PORT_USER_BASE_ADDRESS_ANALOG;
      LpPortPMSRReg = Port_GpConfigPtr->pPortAnalogPMSRRegs;
    }
    else
    {
      /* No action required */
    }
    #endif /* End of PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON */

    /*
     * Set the bit position in the upper 16 bits (31-16) of the PSR or PMSR
     * variable to 1 of the configured pin whose Direction has to be changed
     */
    LusOrMask = LpChangeablePinDet->usOrMaskVal;

    LunSRRegContent.Tst_Port_Word.usMSWord = (LpChangeablePinDet->usOrMaskVal);

    /*
     * An atomic access to Microcontroller registers by the use of an exclusive
     * area
     */
    /* TRACE [R3, PORT075] */
    /* TRACE [R4, PORT075] */
    /* Enter critical section */
    #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
    /* MISRA Violation: START Msg(4:3138)-12 */
    PORT_ENTER_CRITICAL_SECTION(SET_PIN_DEFAULT_DIR_PROTECTION);
    /* MISRA Violation: END Msg(4:3138)-12 */
    #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

    /* MISRA Violation: START Msg(4:0306)-3 */
    /* MISRA Violation: START Msg(4:0488)-6 */
    /* MISRA Violation: START Msg(4:2962)-5 */
    /* Get the PMSR register Address */
    LpRegAddr = (uint32 *)((LpPortPMSRReg +
                  LpChangeablePinDet->ucPMSRRegIndex)->usRegAddrOffset
                                                         + LulBaseAddress);
    /* END Msg(4:2962)-5 */
    /* END Msg(4:0306)-3 */
    /*
     * Write the contents of Lower word of PMSR variable into the PMSR
     * register address
     */
    LunSRRegContent.Tst_Port_Word.usLSWord = ((LpPortPMSRReg +
             LpChangeablePinDet->ucPMSRRegIndex)->usInitModeRegVal) & LusOrMask;
    /* END Msg(4:0488)-6 */
    /*
     * Write the contents of Lower word and upper word of PMSR variable
     * into the PMSR register address
     */
    *LpRegAddr = LunSRRegContent.ulRegContent;
  } /* End of LenReturnValue == E_OK */

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }

  /* Exit critical section */
  #endif /* End of (PORT_DEV_ERROR_DETECT == STD_ON) */
  #if (PORT_CRITICAL_SECTION_PROTECTION == STD_ON)
  /* MISRA Violation: START Msg(4:3138)-12 */
  PORT_EXIT_CRITICAL_SECTION(SET_PIN_DEFAULT_DIR_PROTECTION);
  /* MISRA Violation: END Msg(4:3138)-12 */
  #endif /* End of CRITICAL_SECTION_PROTECTION == STD_ON*/

} /* End of API Port_SetPinDefaultDirection */

#define PORT_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"
#endif /* (PORT_SET_PIN_DEFAULT_DIRECTION_API == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
