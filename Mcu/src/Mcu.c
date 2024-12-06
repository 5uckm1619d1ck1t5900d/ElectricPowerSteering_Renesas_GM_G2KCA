/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu.c                                                       */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains API function implementations of MCU Driver              */
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
 *                        1. Mcu_ProtectedWrite and Mcu_ReadBackDiagTest
 *                           functions are implemented as macros
 *                        2. As part of safety measure in conditional checks,
 *                           macros are placed on the left side
 *                        3. LucProtTypeAndWriteSize is removed since
 *                           Mcu_ProtectedWrite is implemented as a macro
 *                        4. Mcu_LockStepSelfDiagnosticTest is implemented as
 *                           per new requirement EAAR_PN0079_FR_0092
 *                        5. Initialization of ECM is updated in Mcu_init() and
 *                           Mcu_InitRamSection() as given in the device manual
 *                        6. All APIs are updated for the initialization of
 *                           local variables to avoid garbage values
 *                        7. MCU_ENTER_CRITICAL_SECTION and
 *                           MCU_EXIT_CRITICAL_SECTION areas are invoked
 *                        8. Mcu_ClmaSelfDiagnosticTest() is invoked in
 *                           Mcu_InitClock() instead of Mcu_init()
 *                        9. Mcu_GetResetReason is updated since an internal
 *                           function 'Mcu_SaveResetReason()' will updated the
 *                           latest reset reason occurred
 *                        10. Mcu_GetResetRawValue is updated since an internal
 *                            function 'Mcu_SaveResetReason()' will updated the
 *                            reset raw value
 *                        11. Mcu_GetRamState() is updated for addition of
 *                            CRITICAL_SECTION
 *                        12. Mcu_ClmaSelfDiagnosticTest() prototype is changed
 *                            for passing calculated delay count for two
 *                            sampling cycles also Mcu_CvmSelfDiagnosticTest()
 *                            is updated for providing 12us delay
 *                        13. MCU_EIC8L is replaced with MCU_IMR0EIMK8 register
 *                            to enable interrupt through IMR register
 *                        14. MCU_RAM_SECTOR_SETTING_CONFIGURED precompile
 *                            option is added for Mcu_InitRamSection API
 *
 * V1.0.2:  12-May-2014 : As per CR99 and mantis #21334,
 *                        Following changes are made,
 *                        1. 'MISRA C Rule Violations' section is updated for
 *                           Justification of misra rule 7:0505
 *
 * V1.0.3:  26-Sep-2014 : As per CR008 and mantis #19850,
 *                        Following changes are made,
 *                        1. Mcu_Init API is updated for changing 8 bit register
 *                           access to 32 bit and ECM delay timer start settings
 *                           are added
 *                        2. Mcu_GetResetReason API is updated to remove
 *                           unreferenced variables
 *                        3. Mcu_PerformReset and Mcu_SaveResetReason APIs are
 *                           updated to add Mcu_ProtectedWriteRetNone macro
 *                           instead of Mcu_ProtectedWrite macro
 *                        4. Mcu_EcmSelfDiagnosticTest API is updated for
 *                           ERROROUT generation for ECM source 29 and 8 bit
 *                           register access to 32 bit
 *                        5. Trace marking is added throughout the file
 *                        6. Mcu_Init and Mcu_SaveResetReason APIs are updated
 *                           to configure, check and store CVM reset status
 *                        7. Mcu_Init and Mcu_EcmSelfDiagnosticTest APIs are
 *                           updated to remove Nesting of control structures
 *                           exceeds 15 QAC warning
 *                        8. Mcu_ClearEcmErrorOutput API added to remove
 *                           QAC warning in Mcu_EcmSelfDiagnosticTest API
 *
 * V1.0.4:  09-Dec-2014 : As per CR076 and mantis #18031 and #17005
 *                        Following changes are made,
 *                        1. As per coding rule constants are moved towards
 *                           left side of the respective operands.
 *                        2. Unwanted QAC comments are removed from Mcu_Init
 *                           API.
 *                        3. End comment is added for QAC in Mcu_Init API.
 *                        4. SYNCP instruction execution is implemented when
 *                           IMR register is accessed in between DI and EI
 *                           instructions.
 *
 * V1.0.5:  11-Feb-2014 : As per mantis #26305 ,following changes are made:
 *                        1. REG_DATA_PROTECTION is renamed to
 *                           MCU_REGISTER_PROTECTION.
 *                        2. Copyright information is updated.
 *
 * V1.0.6:  25-Mar-2015 : 1. As per mantis #26418 ,following change is made:
 *                             MCU_SW_RST is corrected with name MCU_SW_RESET ,
 *                             MCU_WDT_RST is corrected with name
 *                             MCU_WATCHDOG_RESET ,
 *                             MCU_POWER_ON_CLEAR_RST is corrected with name
 *                             MCU_POWER_ON_RESET
 *                        2. Added code comments as per MO Review in Mantis
 *                             #27515
 *                        3. Justifications for QAC warnings Msg(4:0857),
 *                           Msg(4:2983), Msg(4:4499), Msg(4:2991), Msg(4:2982),
 *                           Msg(4:2992), Msg(4:2996), Msg(4:0400).
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Post-build Time Parameters */
#include "Mcu_PBTypes.h"
/* Included for RAM variable declarations */
#include "Mcu_Ram.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Included for the declaration of Det_ReportError() */
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

/* Included for declaration of the function Dem_ReportErrorStatus() */
/* TRACE [R4, MCU102] */
/* TRACE [R4, MCU109] */
/* TRACE [R4, MCU152] */
/* TRACE [R4, MCU111] */
/* TRACE [R4, MCU111] */
#include "Dem.h"

#if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
#include "SchM_Mcu.h"
#endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

/* Included for Register access */
#include "Mcu_Reg.h"
/* TRACE [R4, MCU108] */
/* Included for module version information */
#include "Mcu.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_C_AR_RELEASE_MAJOR_VERSION     MCU_AR_RELEASE_MAJOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_MINOR_VERSION     MCU_AR_RELEASE_MINOR_VERSION_VALUE
#define MCU_C_AR_RELEASE_REVISION_VERSION  MCU_AR_RELEASE_REVISION_VERSION_VALUE

/* File version information */
#define MCU_C_SW_MAJOR_VERSION     1
#define MCU_C_SW_MINOR_VERSION     0

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION)
  #error "Mcu.c : Mismatch in Release Major Version"
#endif /* (MCU_AR_RELEASE_MAJOR_VERSION != MCU_C_AR_RELEASE_MAJOR_VERSION) */

#if (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION)
  #error "Mcu.c : Mismatch in Release Minor Version"
#endif /* (MCU_AR_RELEASE_MINOR_VERSION != MCU_C_AR_RELEASE_MINOR_VERSION) */

#if (MCU_AR_RELEASE_REVISION_VERSION != MCU_C_AR_RELEASE_REVISION_VERSION)
  #error "Mcu.c : Mismatch in Release Revision Version"
#endif /* (MCU_AR_RELEASE_REVISION_VERSION !=
        *                                MCU_C_AR_RELEASE_REVISION_VERSION)
        */

#if (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION)
  #error "Mcu.c : Mismatch in Software Major Version"
#endif /* (MCU_SW_MAJOR_VERSION != MCU_C_SW_MAJOR_VERSION) */

#if (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION)
  #error "Mcu.c : Mismatch in Software Minor Version"
#endif /* (MCU_SW_MINOR_VERSION != MCU_C_SW_MINOR_VERSION) */
/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0316)Cast from a pointer to void to a pointer to object */
/*                 type.                                                      */
/* Rule          : MISRA-C:2004 Rule 11.4                                     */
/* Justification : Void type pointer is taken in order not to publish the     */
/*                 type to the upper layer.                                   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0316)-1 and                           */
/*                 END Msg(4:0316)-1 tags in the code.                        */
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
/* Message       : (4:0488) Performing pointer arithmetic.                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : Pointer arithmetic is used to achieve better throughput.   */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0488)-3 and                           */
/*                 END Msg(4:0488)-3 tags in the code.                        */
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2995) The result of this logical operation is always    */
/*                 'true'                                                     */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The result of this logical operation is always true since  */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2995)-4 and                           */
/*                 END Msg (4:2995)-4 tags in the code.                       */
/******************************************************************************/

/* 5. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4464) A constant expression of 'essentially unsigned'   */
/*                 type is being converted to narrower unsigned type,         */
/*                 'unsigned char' on assignment.                             */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/*                 REFERENCE - ISO-6.3.4 Semantics                            */
/* Justification : The 8-bit write protected register is written with 32-bit  */
/*                 value as this is the constant value to be written in       */
/*                 sequence.                                                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4464)-5 and                           */
/*                 END Msg (4:4464)-5 tags in the code.                       */
/******************************************************************************/

/* 6. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:0857) Number of macro definitions exceeds 1024          */
/*                 - program does not conform strictly to ISO:C99.            */
/* Rule          : MISRA-C:2004 Rule 1.1                                      */
/* Justification : In order to ensure portability, it is advisable to avoid   */
/*                 writing code that assumes a level of compiler capability   */
/*                 which may not always be supported.                         */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0857)-6 and                           */
/*                 END Msg(4:0857)-6 tags in the code.                        */
/******************************************************************************/

/* 7. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2983) This assignment is redundant. The value of this   */
/*                 object is never subsequently used.                         */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : Lock step error is produced by different values in core    */
/*                 and checker. The different values are manipulated          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2983)-7 and                           */
/*                 END Msg(4:2983)-7 tags in the code.                        */
/******************************************************************************/

/* 8. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:4499) An expression which is the result of a ~ or <<    */
/*                 operation has been converted to a wider essential type on  */
/*                 assignment.                                                */
/* Rule          : MISRA-C:2004 Rule 10.5                                     */
/* Justification : ~ operation has been done as part of  Mcu_ProtectedWrite   */
/*                 Macro                                                      */
/*                 and checker. The different values are manipulated          */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:4499)-8 and                           */
/*                 END Msg(4:4499)-8 tags in the code.                        */
/******************************************************************************/

/* 9. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:2991)The value of this 'if' controlling expression is   */
/*                 always 'true'                                              */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always true since  */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2991)-9 and                           */
/*                 END Msg(4:2991)-9 tags in the code.                        */
/******************************************************************************/

/* 10. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2982) This assignment is redundant. The value of this   */
/*                 object is never used before being modified                 */
/* Rule          : MISRA-C:2004 Rule 21.1                                     */
/* Justification : The assignment is redundant as reinitialise is done        */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2982)-10 and                          */
/*                 END Msg(4:2982)-10 tags in the code.                       */
/******************************************************************************/

/* 11. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2992) The value of this 'if' controlling expression is  */
/*                 always 'false'                                             */
/* Rule          : MISRA-C:2004 Rule 13.7                                     */
/* Justification : The result of this logical operation is always false since */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2992)-11 and                          */
/*                 END Msg(4:2992)-11 tags in the code.                       */
/******************************************************************************/

/* 12. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:2996) The result of this logical operation is always    */
/*                 'false'                                                    */
/* Rule          : MISRA-C:2004 Rule 17.4                                     */
/* Justification : The result of this logical operation is always false since */
/*                 this value is dependent on configuration.                  */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:2996)-12 and                          */
/*                 END Msg (4:2996)-12 tags in the code.                      */
/******************************************************************************/

/* 13. MISRA C RULE VIOLATION:                                                */
/* Message       : (4:0400) 'LulEcmConfigAddress' is modified more than once  */
/*                 between sequence points - evaluation order unspecified.   s */
/* Rule          : MISRA-C:2004 Rule 1.2 and Rule 12.2                        */
/* Justification : 'LulEcmConfigAddress' is incremented by 4. This is a valid */
/*                 statement in C                                             */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:0400)-13 and                          */
/*                 END Msg(4:0400)-13 tags in the code.                       */
/******************************************************************************/
/*******************************************************************************
**             Internal Function Prototypes                                   **
*******************************************************************************/
/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_SaveResetReason (void);

#if ((MCU_CLMA0_SELFDIAGNOSTIC_TEST == STD_ON) || \
     (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON) || \
     (MCU_CLMA2_SELFDIAGNOSTIC_TEST == STD_ON) || \
     (MCU_CLMA3_SELFDIAGNOSTIC_TEST == STD_ON))
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClmaSelfDiagnosticTest
                        (Mcu_ClmaIndexType LenClmaXIndex, uint16 Delay_Count);
#endif /* ((MCU_CLMA0_SELFDIAGNOSTIC_TEST == STD_ON) ||
        *  (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON) ||
        *  (MCU_CLMA2_SELFDIAGNOSTIC_TEST == STD_ON) ||
        *  (MCU_CLMA3_SELFDIAGNOSTIC_TEST == STD_ON))
        */

#if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmSelfDiagnosticTest (void);
#endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */

#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticTest (void);
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClearEcmErrorOutput (void);
#endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */

#if (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON)
STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
                                        Mcu_LockStepSelfDiagnosticTest (void);
#endif /* (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON) */


/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

/*******************************************************************************
**             Function Definitions                                           **
*******************************************************************************/

/*******************************************************************************
** Function Name      : Mcu_Init
**
** Service ID         : 0x00
**
** Description        : This service performs initialization of the MCU Driver
**                      component.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ConfigPtr - Pointer to MCU Driver Configuration set
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr, Mcu_GpEcmSetting, Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_SaveResetReason, Mcu_LockStepSelfDiagnosticTest,
**                      Mcu_EcmSelfDiagnosticTest, Mcu_CvmSelfDiagnosticTest,
**                      MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION,
**                      Mcu_ProtectedWrite, Det_ReportError,
**                      Mcu_ReadBackDiagTest
**
** Registers Used     : ECMIRCFG0, LVICNT, PROT1PHCMD, PROT1PS, ECMMICFG0HH,
**                      ECMNMICFG0HH, ECMIRCFG0HH, ECMMECLR, ECMMPCMD0,
**                      ECMCECLR, ECMCPCMD0, ECMESSTC0, CVMDEW, PROTCMDCVM,
**                      PROTSCVM, ECMEPCTL, ECMPCMD1, ECMPS, EIBD8, EIC8L
**                      ECMEMK0, ECMEMK1, ECMEPCFG, ECMMICFG0, ECMMICFG1,
**                      ECMNMICFG0, ECMNMICFG1, ECMIRCFG1, ECMDTMCTL, ECMDTMCMP,
**                      ECMDTMCFG0
*******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU153] */
FUNC(void, MCU_PUBLIC_CODE) Mcu_Init
                (P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr)
{
  /* Pointer to Ecm configuration */
  P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) LpEcmSetting;
  Std_ReturnType LenReturnValue;
  /* Local variable to hold Ecm configuration registers address */
  volatile uint32 LulEcmConfigAddress;
  uint32 LulEcmwordvalue;
  /* To store Ecm error status data */
  uint32 LulEcmStatusData;
  uint32 LulCntValue;
  uint32 LulDataVal;
  uint8 LucCVMCntValue;
  uint16 LusLoopCount;
  uint8 LucRetryCount;
  uint8 LucIndex;
  boolean LblDemReported;

  /* Initialize to default values */
  LenReturnValue = E_OK;
  LulEcmConfigAddress = MCU_ZERO;
  LulEcmwordvalue = MCU_ZERO;
  LulEcmStatusData = MCU_ZERO;
  LulCntValue = MCU_ZERO;
  LucCVMCntValue = MCU_ZERO;

  /* Initialize the count value */
  LucRetryCount = MCU_ZERO;
  /* Initialize the index value */
  LucIndex = MCU_ZERO;
  LulDataVal = MCU_ZERO;
  LblDemReported = MCU_FALSE;

  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the config pointer is NULL pointer */
    if (NULL_PTR == ConfigPtr)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU018] */
    /* TRACE [R4, MCU163] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                            MCU_INIT_SID, MCU_E_PARAM_CONFIG);
    /* Set return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check whether Dem reported or not */
  if (E_OK == LenReturnValue)
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Check if the database is present */
    if (MCU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc))
    {
      /* Assign the global pointer with the config pointer */
      /* TRACE [R4, MCU026] */
      Mcu_GpConfigPtr = ConfigPtr;

      /* MISRA Violation: START Msg(4:0316)-1 */
      /* Load the Ecm config array start address to global pointer */
      Mcu_GpEcmSetting =
            (P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST))
                                               (Mcu_GpConfigPtr->pEcmSetting);
      /* END Msg(4:0316)-1 */

      /* Initialize wait count value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      Mcu_ProtectedWrite (MCU_ECMIRCFG0, MCU_IRCFG0_INIT_VALUE, MCU_ECMPCMD1,
                                     MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */

      /* Save the reset reason from  hardware registers and clear the same */
      Mcu_SaveResetReason();

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Check LVI error is masked. otherwise mask first */
      if ((MCU_LVICNT & MCU_LVI_MASK) != MCU_LVI_MASK)
      /* END Msg(4:0303)-2 */
      {
        /* Initialize wait count value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Mask LVI error */
        Mcu_ProtectedWrite(MCU_LVICNT, MCU_LVI_MASK, MCU_PROT1PHCMD,
                                   MCU_PROT1PS, LucRetryCount, LenReturnValue)
        /* END Msg(4:0303)-2 */

        /* Check whether Dem reported or not */
        if (E_NOT_OK == LenReturnValue)
        {
          /* Set the flag to true value */
          LblDemReported = MCU_TRUE;
        }
        else
        {
          #if (MCU_READBACK_CONFIGURATION == STD_ON)
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Check whether value is written successfully to the register.*/
          Mcu_ReadBackDiagTest(MCU_LVICNT, MCU_LVI_MASK, LenReturnValue)
          /* END Msg(4:0303)-2 */

          /* Check whether Dem reported or not */
          if (E_NOT_OK == LenReturnValue)
          {
            /* Set the flag to true value */
            LblDemReported = MCU_TRUE;
          }
          else
          {
            /* No action required */
          }
          #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        }
      } /* End of if ((MCU_LVICNT & MCU_LVI_MASK) != MCU_LVI_MASK) */
      else
      {
        /* No action required */
      }

      /* Check the Dem reported flag set or not */
      if (MCU_FALSE == LblDemReported)
      {
        /* Get the configured LVI detection level value */
        LulCntValue =
                    (uint32)(Mcu_GpConfigPtr->ulLVIindicationReg & MCU_THREE);

        LulCntValue = (uint32) (LulCntValue | MCU_LVI_MASK);

        /* Initialize wait count value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Set LVI voltage detection level as per configuration */
        Mcu_ProtectedWrite(MCU_LVICNT, LulCntValue, MCU_PROT1PHCMD,
                                  MCU_PROT1PS, LucRetryCount, LenReturnValue)
        /* END Msg(4:0303)-2 */

        /* Check whether Dem reported or not */
        if (E_NOT_OK == LenReturnValue)
        {
          /* Set the flag to true value */
          LblDemReported = MCU_TRUE;
        }
        else
        {
          #if (MCU_READBACK_CONFIGURATION == STD_ON)
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Check whether value is written successfully to the register. */
          Mcu_ReadBackDiagTest(MCU_LVICNT, LulCntValue, LenReturnValue)
          /* END Msg(4:0303)-2 */

          /* Check whether Dem reported or not */
          if (E_NOT_OK == LenReturnValue)
          {
            /* Set the flag to true value */
            LblDemReported = MCU_TRUE;
          }
          else
          {
            /* No action required */
          }

          /* Check the Dem reported flag set or not */
          if (MCU_FALSE == LblDemReported)
          #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
          {
            /* Initialize wait count value */
            LusLoopCount = MCU_LVI_DELAY_CNT;

            /* Wait for LVI stabilization time 80 us  */
            while (LusLoopCount > MCU_ZERO)
            {
              LusLoopCount--;
            }

            /* Check LVI error is not masked */
            if (MCU_ZERO == (Mcu_GpConfigPtr->ulLVIindicationReg
                                                            & MCU_LVI_MASK))
            {
              /* MISRA Violation: START Msg(4:0303)-2 */
              LulCntValue = (uint32) (MCU_LVICNT & (~MCU_LVI_MASK));
              /* END Msg(4:0303)-2 */

              /* Initialize retry count value */
              LucRetryCount = MCU_LOOPCOUNT;

              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Set LVI error mask as per configuration*/
              Mcu_ProtectedWrite(MCU_LVICNT, LulCntValue, MCU_PROT1PHCMD,
                                    MCU_PROT1PS, LucRetryCount, LenReturnValue)
              /* END Msg(4:0303)-2 */

              if (E_NOT_OK == LenReturnValue)
              {
                /* Set the flag to true value */
                LblDemReported = MCU_TRUE;
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
          }
          #if (MCU_READBACK_CONFIGURATION == STD_ON)
          else
          {
            /* No action required */
          }
          #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        }
      } /* End of if (MCU_FALSE == LblDemReported) */
      else
      {
        /* No action required */
      }
      /* TRACE [R4, MCU245] */
      /* Set Ecm Error output pin as inactive level initially,
       * Setting or clearing the error output via the ECMmECLR or ECMmESET
       * register will generate the error. Therefore, the following has to be
       * set in advance.
       */

      /* Mask error out pin for all ECM because it is enabled at power up */
      /* Initialize the index to zero */
      LucIndex = MCU_ZERO;

      do
      {
        switch (LucIndex)
        {
          case MCU_ZERO:
          /* Load Ecm error mask reg0 configuration value */
          LulEcmwordvalue = MCU_ECMEMK0_FULL_MASK;

          /* Update the Ecm base address to error mask reg0 config reg */
          LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMEMK0_OFFSET;
          break;

          case MCU_ONE:
          /* Load Ecm error mask reg1 configuration value */
          LulEcmwordvalue = MCU_ECMEMK1_FULL_MASK;

          /* Increment address to Ecm error mask reg1 */
          LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMEMK1_OFFSET;
          break;

          default:
          /* No action required */
          break;
        }

        /* Initialize the retry count to configured loop count */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Mask the ECM errors */
        Mcu_ProtectedWrite ((*(volatile uint32 *)LulEcmConfigAddress),
                  LulEcmwordvalue, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
                                                              LenReturnValue)
        /* END Msg(4:0303)-2 */

        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Read back the Error mask configuration register */
        Mcu_ReadBackDiagTest(*(volatile uint32 *)LulEcmConfigAddress,
                                           LulEcmwordvalue, LenReturnValue)
        /* END Msg(4:0303)-2 */

        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        if (E_NOT_OK == LenReturnValue)
        {
          /* Set the flag to true value */
          LblDemReported = MCU_TRUE;
        }
        else
        {
          /* No action required */
        }

        /* Increment the index */
        LucIndex++;
      }while ((LucIndex < MCU_TWO) && (MCU_FALSE == LblDemReported));

      /* Check Dem reported */
      if (MCU_FALSE == LblDemReported)
      {
        /* Initialize the index to zero */
        LucIndex = MCU_ZERO;
        do
        {
          switch (LucIndex)
          {
            case MCU_ZERO:
            /* Disable MI by setting the ECMIE029 bit of the ECMMICFG0 register
             * to disabled.
             */
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read data from the address */
            LulDataVal = MCU_ECMMICFG0;
            /* END Msg(4:0303)-2 */

            /* Check already masked else mask the bit */
            if (MCU_ZERO != (LulDataVal & MCU_ECM029_MASK_VALUE))
            {
              /* Interrupt generation is disabled */
              LulDataVal = LulDataVal & (~MCU_ECM029_MASK_VALUE);

              /* Initialize the retry count to configured loop count */
              LucRetryCount = MCU_LOOPCOUNT;

              /* MISRA Violation: START Msg(4:0303)-2 */
              /* write the value to ECMMICFG0 register */
              Mcu_ProtectedWrite(MCU_ECMMICFG0, LulDataVal,
                       MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
              /* END Msg(4:0303)-2 */

              #if (MCU_READBACK_CONFIGURATION == STD_ON)
              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Read back the ECM maskable interrupt configuration
               * register 0
               */
              Mcu_ReadBackDiagTest(MCU_ECMMICFG0, LulDataVal,
                                                            LenReturnValue)
              /* END Msg(4:0303)-2 */
              #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            } /* End of (MCU_ZERO != (LulDataVal & MCU_ECM029_MASK_VALUE)) */
            else
            {
              /* No action required */
            }
            break;

            case MCU_ONE:
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Disable NMI by setting the ECNMIE029 bit of the ECMNMICFG0 reg
             * to disabled.
             */
            LulDataVal = MCU_ECMNMICFG0;
            /* END Msg(4:0303)-2 */

            /* Check already disabled */
            if (MCU_ZERO != (LulDataVal & MCU_ECM029_MASK_VALUE))
            {
              /* Set the write size and protection register type */
              LulDataVal = LulDataVal & (~MCU_ECM029_MASK_VALUE);

              /* Initialize the retry count to configured loop count */
              LucRetryCount = MCU_LOOPCOUNT;

              /* MISRA Violation: START Msg(4:0303)-2 */
              /* write the value to ECMNMICFG0 register */
              Mcu_ProtectedWrite(MCU_ECMNMICFG0, LulDataVal,
                       MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
              /* END Msg(4:0303)-2 */

              #if (MCU_READBACK_CONFIGURATION == STD_ON)
              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Read back the ECM FE level interrupt configuration
               * register 0
               */
              Mcu_ReadBackDiagTest(MCU_ECMNMICFG0,
                                               LulDataVal, LenReturnValue)
              /* END Msg(4:0303)-2 */


              #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            }
            else
            {
              /* no action required */
            }
            break;

            case MCU_TWO:
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Disable an internal reset by setting the ECMIRE029 bit of the
             * ECMIRCFG0 register to disabled.
             */
            LulDataVal = MCU_ECMIRCFG0;
            /* END Msg(4:0303)-2 */

            /* Check already disabled */
            if (MCU_ZERO != (LulDataVal & MCU_ECM029_MASK_VALUE))
            {
              /* Initialize the retry count to configured loop count */
              LucRetryCount = MCU_LOOPCOUNT;

              /* Internal reset generation is disabled */
              LulDataVal = LulDataVal & (~MCU_ECM029_MASK_VALUE);

              /* MISRA Violation: START Msg(4:0303)-2 */
              /* write the value to ECMIRCFG0 register */
              Mcu_ProtectedWrite(MCU_ECMIRCFG0, LulDataVal, MCU_ECMPCMD1,
                                     MCU_ECMPS, LucRetryCount, LenReturnValue)
              /* END Msg(4:0303)-2 */

              #if (MCU_READBACK_CONFIGURATION == STD_ON)
              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Read back the ECM internal reset configuration register 0 */
              Mcu_ReadBackDiagTest(MCU_ECMIRCFG0,
                                               LulDataVal, LenReturnValue)
              /* END Msg(4:0303)-2 */
              #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_THREE:
            /* Set the output level from the error pin to the inactive
             * (high) level
             */
            /* Initialize the retry count to configured loop count */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* write the value to ECMMECLR register */
            Mcu_ProtectedWriteRetNone(MCU_ECMMECLR, MCU_ONE, MCU_ECMMPCMD0,
                                     MCU_ECMPS, LucRetryCount)
            /* END Msg(4:0303)-2 */

            /* Initialize the retry count to configured loop count */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* write the value to ECMCECLR register */
            Mcu_ProtectedWrite(MCU_ECMCECLR, MCU_ONE, MCU_ECMCPCMD0,
                                   MCU_ECMPS, LucRetryCount, LenReturnValue)
            /* END Msg(4:0303)-2 */
            break;

            case MCU_FOUR:
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
            #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Clear error flags by setting the ECMCLSSE029 bit of the
             * ECMESSTC0 register
             */
            LulEcmStatusData = (uint32)MCU_ECMESSTC0;
            /* END Msg(4:0303)-2 */

            LulEcmStatusData = (LulEcmStatusData | MCU_ECM029_MASK_VALUE);

            /* Initialize retry count */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* write the value to ECMESSTC0 register */
            Mcu_ProtectedWrite(MCU_ECMESSTC0, LulEcmStatusData,
                       MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
            /* END Msg(4:0303)-2 */

            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
            #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */


            break;

            default:
            LblDemReported = MCU_TRUE;
            break;
          }

          /* Check Protected write sequence error */
          if (E_NOT_OK == LenReturnValue)
          {
            /* Set the flag to true value */
            LblDemReported = MCU_TRUE;

            /* Load the loopcount value */
            LucIndex = MCU_FIVE;
          }
          else
          {
            /* Increment the Index value */
            LucIndex++;
          }
        /* MISRA Violation: START Msg(4:2995)-4 */
        }while ((MCU_FIVE > LucIndex) && (MCU_FALSE == LblDemReported));
        /* END Msg(4:2995)-4 */

        if (MCU_FALSE == LblDemReported)
        {
          #if (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON)
          LenReturnValue = Mcu_LockStepSelfDiagnosticTest();
          #endif /* (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON) */

          #if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)
          LenReturnValue = Mcu_EcmSelfDiagnosticTest();
          #endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */

          #if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)
          LenReturnValue = Mcu_CvmSelfDiagnosticTest();
          #endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */

          /* Get the configured CVM control value  */
          LucCVMCntValue = Mcu_GpConfigPtr->ucCvmIndicationReg;

          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          Mcu_ProtectedWriteRetNone(MCU_CVMDEW, LucCVMCntValue, MCU_PROTCMDCVM,
                                  MCU_PROTSCVM, LucRetryCount)
          /* END Msg(4:0303)-2 */

          /* Get the configured CVM reset enable control value  */
          LulCntValue = Mcu_GpConfigPtr->ulCvmResetEnableReg;
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          Mcu_ProtectedWriteRetNone(MCU_CVMREN, LulCntValue, MCU_PROTCMDCVM,
                                MCU_PROTSCVM, LucRetryCount)
          /* END Msg(4:0303)-2 */

          /* Set Ecm error pulse register to select dynamic or non-dynamic */
          /* Get the Ecm base address (Error Pulse Configuration Register) */
          LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMEPCFG_OFFSET;

          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Load Ecm error pulse config register to select dynamic or
           * non-dynamic
           */
          Mcu_ProtectedWrite((*(volatile uint8 *)LulEcmConfigAddress),
                            MCU_ECM_ERROUT_MODE, MCU_ECMPCMD1, MCU_ECMPS,
                                              LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */

          #if (MCU_READBACK_CONFIGURATION == STD_ON)
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Read back the Ecm error pulse register*/
          Mcu_ReadBackDiagTest(*(volatile uint32 *)LulEcmConfigAddress,
                                     MCU_ECM_ERROUT_MODE, LenReturnValue)
          /* END Msg(4:0303)-2 */
          #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
          /* Check whether Dem reported or not */
          if (E_NOT_OK == LenReturnValue)
          {
            /* Set the flag to true value */
            LblDemReported = MCU_TRUE;
          }
          else
          {
            /* No action required */
          }
          
          /* Check Dem reported */
          if (MCU_FALSE == LblDemReported)
          {
            /* If Dynamic mode selected, set the timer as OSTM or
             * Channel 15 TAUD1 as per configuration.
             */
             LucIndex = MCU_ECM_ERROUT_MODE;
            /* MISRA Violation: START Msg(4:2992)-11 */
            /* MISRA Violation: START Msg(4:2996)-12 */
            if (MCU_ONE == LucIndex)
            {
              /* END Msg(4:2992)-11 */
              /* END Msg(4:2996)-12 */
              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Load the Error out timer value to the register. */
              MCU_ECMEPCTL = MCU_ECM_ERROUT_TIMER;
              /* END Msg(4:0303)-2 */
            }
            else
            {
              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Load the Error out default timer value to the register. */
              MCU_ECMEPCTL = MCU_ZERO;
              /* END Msg(4:0303)-2 */
            }
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

        /* Load the Ecm config start address  */
        LpEcmSetting = Mcu_GpEcmSetting;

        /* Check Dem reported */
        if (MCU_FALSE == LblDemReported)
        {
          /* Initialize the index value */
          LucIndex = MCU_ZERO;

          do
          {
            switch (LucIndex)
            {
              case MCU_ZERO:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMMICFG0_OFFSET);

              /* Load Ecm maskable interrupt reg0 configuration value */
              LulEcmwordvalue = ((LpEcmSetting->ulEcmMaskInterReg0value &
                             (~MCU_RAM_MASK0_VALUE)) | MCU_IRCFG0_INIT_VALUE);
              break;

              case MCU_ONE:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMMICFG1_OFFSET);

              /* Load Ecm maskable interrupt reg1 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmMaskInterReg1value &
                                                      (~MCU_RAM_MASK1_VALUE));
              break;

              case MCU_TWO:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMNMICFG0_OFFSET);

              /* Load Ecm non maskable interrupt reg0 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmNonMaskInterReg0value &
                                                      (~MCU_RAM_MASK0_VALUE));
              break;

              case MCU_THREE:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMNMICFG1_OFFSET);

              /* Load Ecm non maskable interrupt reg1 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmNonMaskInterReg1value &
                                                      (~MCU_RAM_MASK1_VALUE));
              break;

              case MCU_FOUR:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMIRCFG0_OFFSET);

              /* Load Ecm internal reset reg0 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmInternalResetReg0value &
                                                      (~MCU_RAM_MASK0_VALUE));
              break;

              case MCU_FIVE:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMIRCFG1_OFFSET);

              /* Load Ecm internal reset reg1 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmInternalResetReg1value &
                                                      (~MCU_RAM_MASK1_VALUE));
              break;

              case MCU_SIX:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMEMK0_OFFSET);

              /* Load Ecm error mask reg0 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmErrorMaskReg0Value |
                                                      (MCU_RAM_MASK0_VALUE));
              break;

              case MCU_SEVEN:
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMEMK1_OFFSET);

              /* Load Ecm error mask reg1 configuration value */
              LulEcmwordvalue = (LpEcmSetting->ulEcmErrorMaskReg1Value |
                                                      (MCU_RAM_MASK1_VALUE));
              break;

              default:
              break;
            }

            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* write the value the particular register address */
            Mcu_ProtectedWrite((*(volatile uint32 *)LulEcmConfigAddress),
                  LulEcmwordvalue, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
                                                            LenReturnValue)
            /* END Msg(4:0303)-2 */

            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read back the Ecm error pulse register*/
            Mcu_ReadBackDiagTest(*(volatile uint32 *) LulEcmConfigAddress,
                                           LulEcmwordvalue, LenReturnValue)
            /* END Msg(4:0303)-2 */
                        /* Check status of the protection write operation */
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            if (E_NOT_OK == LenReturnValue)
            {
              /* Set the flag to true value */
              LblDemReported = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            /* Increment the index */
            LucIndex++;
          }while ((LucIndex < MCU_MAX_ECM_CONFIG) &&
                                               (MCU_FALSE == LblDemReported));

          /* check whether Dem is reported or not */
          if (MCU_FALSE == LblDemReported)
          {
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
            #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

            /* Stop ECM delay timer and initialize the counter to zero
             * using control register
             */
            LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCTL_OFFSET;

            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* write the value to ECMDTMCTL register */
            Mcu_ProtectedWriteRetNone((*(volatile uint8 *) LulEcmConfigAddress),
                          MCU_ECM_DELY_TIMER_STOP, MCU_ECMPCMD1, MCU_ECMPS,
                                                LucRetryCount)
            /* END Msg(4:0303)-2 */

            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
            #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

            /* Update the Ecm base address to delay timer compare register */
            LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCMP_OFFSET;

            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            LulEcmStatusData = MCU_ECM_DLYTIMER_VALUE;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Load configured ECM delay timer value */
            Mcu_ProtectedWrite((*(volatile uint16 *)LulEcmConfigAddress),
                        (uint16)(LulEcmStatusData), MCU_ECMPCMD1, MCU_ECMPS,
                                             LucRetryCount, LenReturnValue)
            /* END Msg(4:0303)-2 */

            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read back the ECM delay timer register */
            Mcu_ReadBackDiagTest(*(volatile uint16 *)LulEcmConfigAddress,
                                   MCU_ECM_DLYTIMER_VALUE, LenReturnValue)
            /* END Msg(4:0303)-2 */
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
            /* Check whether Dem reported or not */
            if (E_NOT_OK == LenReturnValue)
            {
              /* Set Dem error reported flag */
              LblDemReported = MCU_TRUE;
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

          /* Check Dem reported */
          if (MCU_FALSE == LblDemReported)
          {
            /* Update the Ecm base address to delay timer config register */
            LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS +
                                                    MCU_ECMDTMCFG0_OFFSET;

            /* Initialize the index value */
            LucIndex = MCU_ZERO;

            /* Load ECM delay timer configuration reg 0, 1, 2, 3  */
            do
            {
              switch (LucIndex)
              {
                case MCU_ZERO:
                /* Assign the configured delay values */
                LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg0Value;
                break;

                case MCU_ONE:
                /* Assign the configured delay values */
                LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg1Value;
                break;

                case MCU_TWO:
                /* Assign the configured delay values */
                LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg2Value;
                break;

                case MCU_THREE:
                /* Assign the configured delay values */
                LulEcmwordvalue = LpEcmSetting->ulEcmDelayTimerReg3Value;
                break;

                default:
                /* No action required */
                break;
              }

              /* Initialize the retry count to config value */
              LucRetryCount = MCU_LOOPCOUNT;

              /* MISRA Violation: START Msg(4:0303)-2 */
              /* write the value to ECMDTMCFGn register */
              Mcu_ProtectedWrite((*(volatile uint32 *)LulEcmConfigAddress),
                           LulEcmwordvalue, MCU_ECMPCMD1, MCU_ECMPS,
                                          LucRetryCount, LenReturnValue)
              /* END Msg(4:0303)-2 */

              #if (MCU_READBACK_CONFIGURATION == STD_ON)
              /* MISRA Violation: START Msg(4:0303)-2 */
              /*Read back the ECM delay timer configuration register 0 */
              Mcu_ReadBackDiagTest(*(volatile uint32 *)
                  LulEcmConfigAddress, LulEcmwordvalue, LenReturnValue)
              /* END Msg(4:0303)-2 */
              #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
              if (E_NOT_OK == LenReturnValue)
              {
                /* Set the flag to true value */
                LblDemReported = MCU_TRUE;
              }
              else
              {
                /* No action required */
              }
              /* MISRA Violation: START Msg(4:0400)-13 */
              /* Increment to next ECM reg address */
              LulEcmConfigAddress = LulEcmConfigAddress + MCU_FOUR;
              /* END Msg(4:0400)-13 */
              /* Increment the index */
              LucIndex++;
            }while ((LucIndex < MCU_MAX_ECMDLY_CONFIG) &&
                                              (MCU_FALSE == LblDemReported));
          }
          else
          {
            /* No action required */
          }
          if (MCU_FALSE == LblDemReported)
          {
            /* Configure control register to start ECM delay timer once
             * interrupt occurs.
             */
            LulEcmConfigAddress =
                             MCU_ECM_BASE_ADDRESS + MCU_ECMDTMCTL_OFFSET;

            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* write the value to ECMDTMCTL register */
            Mcu_ProtectedWrite((*(volatile uint8 *) LulEcmConfigAddress),
                          MCU_ONE, MCU_ECMPCMD1, MCU_ECMPS,
                                           LucRetryCount, LenReturnValue)
            /* END Msg(4:0303)-2 */
          }
          else
          {
            /* No action required */
          }
        } /* End of (MCU_FALSE == LblDemReported) */
        else
        {
          /* No action required */
        }

        /* Check Dem reported.*/
        if (MCU_FALSE == LblDemReported)
        {
          /* Check if any error source of ECM is configured for
           * maskable interrupt
           */
          if ((MCU_LONG_WORD_ZERO != LpEcmSetting->ulEcmMaskInterReg0value) ||
              (MCU_LONG_WORD_ZERO != LpEcmSetting->ulEcmMaskInterReg1value))
          {
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Setting to bound Interrupts to the CPU1 */
            MCU_EIBD8 =  MCU_EIBD08_CPU1_VALUE;
            /* END Msg(4:0303)-2 */
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
            #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Enable the ECM maskable Interrupt */
            RH850_SV_MODE_IMR_AND(16, &MCU_IMR0EIMK8,
                           (uint16)(~MCU_ENABLE_INTERRUPT));
            /* Register dummy read-write  */
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
             RH850_SV_MODE_IMR_AND(16, &MCU_IMR0EIMK8,
                           (uint16)(~MCU_ENABLE_INTERRUPT));
            /* SYNCP execution */
            EXECUTE_SYNCP();
            #endif
            /* END Msg(4:0303)-2 */
            #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
            MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
            #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
          }
          else
          {
            /* No action required */
          }

          /* Set the Global Status */
          Mcu_GblDriverStatus = MCU_INITIALIZED;
        } /* End of (MCU_FALSE == LblDemReported) */
        else
        {
          /* No action required */
        }
      } /* End of (MCU_FALSE == LblDemReported) */
      else
      {
        /* No action required */
      }
    } /* End of (MCU_DBTOC_VALUE == (ConfigPtr->ulStartOfDbToc)) */
    else
    {
      /* TRACE [R4, MCU013] */
      #if (MCU_DEV_ERROR_DETECT == STD_ON)
      /* No database flashed. Hence, report to DET */
      /* TRACE [R4, MCU017] */
      /* TRACE [R4, MCU016] */
      /* TRACE [R4, MCU163] */
      (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_SID,
                                                      MCU_E_INVALID_DATABASE);
      #endif /* End of (MCU_DEV_ERROR_DETECT == STD_ON) */
    }
  } /* End of (E_OK == LenReturnValue) */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name      : Mcu_InitRamSection
**
** Service ID         : 0x01
**
** Description        : This function initializes the RAM section as provided
**                      from the configuration structure.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : RamSection - Id for RAM section
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpConfigPtr, Mcu_GpEcmSetting
**
** Function Invoked   : MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION,
**                      Mcu_ProtectedWrite, Mcu_ReadBackDiagTest
**
** Registers Used     : ECMMESSTR0, ECMESSTC0, ECMMESSTR1, ECMESSTC1, ECMPCMD1,
**                      ECMPS, ECMMICFG0, ECMMICFG1, ECMNMICFG0, ECMNMICFG1,
**                      ECMIRCFG0, ECMIRCFG1, ECMEMK0, ECMEMK1
*******************************************************************************/
#if (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_ON)

/* MISRA Violation: START Msg(4:0857)-6 */
/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
/* END Msg(4:0857)-6 */
#include "MemMap.h"

/* TRACE [R4, MCU239] */
/* TRACE [R4, MCU154] */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitRamSection
                                               (Mcu_RamSectionType RamSection)
{
  /* Pointer to Ram setting */
  P2CONST(Mcu_RamSetting, AUTOMATIC, MCU_CONFIG_CONST) LpRamSetting;

  /* Pointer to Ecm setting */
  P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) LpEcmSetting;

  Std_ReturnType LenReturnValue;
  boolean LblDemReported;
  boolean LblWriteFlag;
  volatile uint32 LulRamStartAddress;
  uint32 LulNoOfByte;
  volatile uint32 LulEcmConfigAddress;
  uint32 LulEcmwordvalue;
  uint8 LucDataByte;

  uint8 LucRetryCount;
  uint8 LucIndex;

  /* Initialize return value with E_OK */
  LenReturnValue = E_OK;
  /* Initialize to false */
  LblWriteFlag = MCU_FALSE;
  /* Initialize to false */
  LblDemReported = MCU_FALSE;
  LulRamStartAddress = MCU_ZERO;
  LulEcmConfigAddress = MCU_ZERO;
  LulEcmwordvalue = MCU_ZERO;

  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  /* TRACE [R4, MCU125] */
  /* TRACE [R4, MCU136] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU163] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                        MCU_INITRAMSECTION_SID, MCU_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Report to DET, if RamSetting Id is out of range */
  /* TRACE [R4, MCU239] */
  /* TRACE [R4, MCU172_Conf] */
  if (MCU_MAX_RAMSETTING <= RamSection)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU021] */
    /* TRACE [R4, MCU163] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                MCU_INITRAMSECTION_SID, MCU_E_PARAM_RAMSECTION);
    /* Set return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if any development error occurred */
  if (E_OK == LenReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* MISRA Violation: START Msg(4:0316)-1 */
    /* Get the pointer to the RAM structure */
    /* TRACE [R4, MCU239] */
    LpRamSetting = (((P2CONST(Mcu_RamSetting, MCU_VAR, MCU_CONFIG_CONST))
                                  Mcu_GpConfigPtr->pRamSetting) + RamSection);
    /* END Msg(4:0316)-1 */
    /* END Msg(4:0488)-3 */

    /* Get the start address of the RAM section */
    LulRamStartAddress = LpRamSetting->ulRamSectionBaseAddress;

    /* Get the size of RAM section */
    LulNoOfByte = LpRamSetting->ulRamSectionSize;

    /* Get initial value */
    LucDataByte = (uint8)LpRamSetting->ulRamDefaultValue;
    /* TRACE [R4, MCU011] */
    while (MCU_LONG_WORD_ZERO != LulNoOfByte)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Write configured data to memory address */
      *((volatile uint8*)LulRamStartAddress) = LucDataByte;
      /* END Msg(4:0303)-2 */

      /* Decrement the size */
      LulNoOfByte--;

      /* Increment the pointer of RAM Section address */
      LulRamStartAddress++;
    }

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check and clear if any ECM ram error during initialization */
    if ((MCU_ECMMESSTR0 & MCU_RAM_MASK0_VALUE) != MCU_LONG_WORD_ZERO)
    /* END Msg(4:0303)-2 */
    {
      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear the ECM ram error */
      Mcu_ProtectedWrite (MCU_ECMESSTC0, MCU_RAM_MASK0_VALUE, MCU_ECMPCMD1,
                                    MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */

      #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
      MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
      #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
    }
    else
    {
      /* No action required  */
    }

    /* Check whether Dem reported or not */
    if (E_OK == LenReturnValue)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Check and clear if any ECM ram error during initialization */
      if ((MCU_ECMMESSTR1 & MCU_RAM_MASK1_VALUE) != MCU_LONG_WORD_ZERO)
      /* END Msg(4:0303)-2 */
      {
        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
        #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Clear the ECM ram error */
        Mcu_ProtectedWrite (MCU_ECMESSTC1, MCU_RAM_MASK1_VALUE, MCU_ECMPCMD1,
                                    MCU_ECMPS, LucRetryCount, LenReturnValue)
        /* END Msg(4:0303)-2 */

        #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
        MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
        #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
      }
      else
      {
        /* No action required  */
      }

      /* Check whether Dem reported or not */
      if (E_OK == LenReturnValue)
      {
        /* Load the Ecm config setting */
        LpEcmSetting = Mcu_GpEcmSetting;

        /* Initialize the index value */
        LucIndex = MCU_ZERO;

        do
        {
          switch (LucIndex)
          {
            case MCU_ZERO:
            /* ECM maskable interrupt configuration for RAM */
            if ((LpEcmSetting->ulEcmMaskInterReg0value & MCU_RAM_MASK0_VALUE)
                                                        != MCU_LONG_WORD_ZERO)
            {
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMMICFG0_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmMaskInterReg0value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_ONE:
            /* ECM maskable interrupt configuration for RAM */
            if ((LpEcmSetting->ulEcmMaskInterReg1value & MCU_RAM_MASK1_VALUE)
                                                        != MCU_LONG_WORD_ZERO)
            {
              /* Update the Ecm base address to maskable interrupt reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMMICFG1_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmMaskInterReg1value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_TWO:
            /* ECM maskable interrupt configuration for RAM */
            if ((LpEcmSetting->ulEcmNonMaskInterReg0value & MCU_RAM_MASK0_VALUE)
                                                        != MCU_LONG_WORD_ZERO)
            {
              /* Update the Ecm base address to non maskable interrupt reg */
              LulEcmConfigAddress =
                               (MCU_ECM_BASE_ADDRESS + MCU_ECMNMICFG0_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmNonMaskInterReg0value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_THREE:
            /* ECM maskable interrupt configuration for RAM */
            if ((LpEcmSetting->ulEcmNonMaskInterReg1value & MCU_RAM_MASK1_VALUE)
                                                        != MCU_LONG_WORD_ZERO)
            {
              /* Update the Ecm base address to non maskable interrupt reg */
              LulEcmConfigAddress =
                               (MCU_ECM_BASE_ADDRESS + MCU_ECMNMICFG1_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmNonMaskInterReg1value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_FOUR:
            /* ECM maskable interrupt configuration for RAM */
            if (MCU_LONG_WORD_ZERO !=
             (LpEcmSetting->ulEcmInternalResetReg0value & MCU_RAM_MASK0_VALUE))
            {
              /* Update the Ecm base address to internal reset reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMIRCFG0_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmInternalResetReg0value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_FIVE:
            /* ECM maskable interrupt configuration for RAM */
            if (MCU_LONG_WORD_ZERO  !=
            (LpEcmSetting->ulEcmInternalResetReg1value & MCU_RAM_MASK1_VALUE))
            {
              /* Update the Ecm base address to internal reset reg */
              LulEcmConfigAddress =
                                (MCU_ECM_BASE_ADDRESS + MCU_ECMIRCFG1_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmInternalResetReg1value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_SIX:
            /* ECM error mask reg0 configuration for RAM */
            if (((~LpEcmSetting->ulEcmErrorMaskReg0Value) & MCU_RAM_MASK0_VALUE)
                                                        != MCU_LONG_WORD_ZERO)
            {
              /* Update the Ecm base address to error mask reg */
              LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMEMK0_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmErrorMaskReg0Value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            case MCU_SEVEN:
            /* ECM error mask reg0 configuration for RAM */
            if (((~LpEcmSetting->ulEcmErrorMaskReg1Value) & MCU_RAM_MASK1_VALUE)
                                                          != MCU_LONG_WORD_ZERO)
            {
              /* Update the Ecm base address to error mask reg */
              LulEcmConfigAddress = (MCU_ECM_BASE_ADDRESS + MCU_ECMEMK1_OFFSET);

              /* Load MI reg0 word value to do Ecm byte writing */
              LulEcmwordvalue = LpEcmSetting->ulEcmErrorMaskReg1Value;

              /* Make the flag true */
              LblWriteFlag = MCU_TRUE;
            }
            else
            {
              /* No action required */
            }
            break;

            default:

            break;
          }

          /* Check if the flag is true */
          if (MCU_TRUE == LblWriteFlag)
          {
            /* Initialize the retry count to config value */
            LucRetryCount = MCU_LOOPCOUNT;

            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Write the value to the corresponding register */
            Mcu_ProtectedWrite((*(volatile uint32 *)LulEcmConfigAddress),
                    LulEcmwordvalue, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
                                                              LenReturnValue)
            /* END Msg(4:0303)-2 */

            /* Check status of the protection write operation */
            if (E_NOT_OK == LenReturnValue)
            {
              /* Set the flag to true value */
              LblDemReported = MCU_TRUE;
            }
            else
            {
              #if (MCU_READBACK_CONFIGURATION == STD_ON)
              /* MISRA Violation: START Msg(4:0303)-2 */
              /* Check if the flag is true */
              /* Read back the Ecm error pulse register*/
              Mcu_ReadBackDiagTest(*(volatile uint32 *) LulEcmConfigAddress,
                                               LulEcmwordvalue, LenReturnValue)
              /* END Msg(4:0303)-2 */

              /* Check whether Dem reported or not */
              if (E_NOT_OK == LenReturnValue)
              {
                /* Set Dem error report flag */
                LblDemReported = MCU_TRUE;
              }
              else
              {
                /* No action required */
              }
              #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
            }
          }
          else
          {
            /* No action required */
          }
          /* Initialize the variable */
          LblWriteFlag = MCU_FALSE;

          /* Increment the Index value */
          LucIndex++;
        }while ((LucIndex < MCU_MAX_ECMRAM_CONFIG) &&
                                              (MCU_FALSE == LblDemReported));
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
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* Set return value to E_NOT_OK */
    LenReturnValue = E_NOT_OK;
  }
  #endif /* if (MCU_DEV_ERROR_DETECT == STD_ON) */

  return (LenReturnValue);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_RAM_SECTOR_SETTING_CONFIGURED == STD_ON) */
/******************************************************************************
** Function Name      : Mcu_InitClock
**
** Service ID         : 0x02
**
** Description        : This service initializes the PLL and other MCU specific
**                      clock options.
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : ClockSetting - Id for Clock setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Std_ReturnType (E_OK, E_NOT_OK)
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GpClockSetting, Mcu_GpConfigPtr
**
** Function Invoked   : Det_ReportError, Dem_ReportErrorStatus,
**                      Mcu_ClmaSelfDiagnosticTest, Mcu_ReadBackDiagTest,
**                      Mcu_ProtectedWrite
**
** Registers Used     : PROT1PHCMD, PROT1PS, CLMA0CMPH, CLMA0CMPL, CLMA0PCMD,
**                      CLMA0PS, CLMA0CTL0, CLMA1CMPH, CLMA1CMPL, CLMA1PCMD,
**                      CLMA1PS, CLMA1CTL0, CLMA2CMPH, CLMA2CMPL, CLMA2PCMD,
**                      CLMA2PS CLMA2CTL0, CLMA3CMPH, CLMA3CMPL, CLMA3PCMD,
**                      CLMA3PS, CLMA3CTL0
******************************************************************************/
/* TRACE [R4, MCU210] */
#if (MCU_INIT_CLOCK == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU155] */
/* TRACE [R4, MCU137] */
/* TRACE [R4, MCU183_Conf] */
/* TRACE [R4, MCU232] */
/* TRACE [R4, MCU248] */
FUNC(Std_ReturnType, MCU_PUBLIC_CODE) Mcu_InitClock (Mcu_ClockType ClockSetting)
{
  Std_ReturnType LenReturnValue;
  Mcu_ExtnClkSettingReg LMcuExtClockReg;
  uint32 LulExternaClkDivider;
  uint8 LucExtClkSrcClk;
  uint16 LusCount;
  uint8 LucRetryCount;
  uint8 LucClockIndex;
  #if ((MCU_CLMA0_OPERATION == STD_ON) || \
      (MCU_CLMA1_OPERATION == STD_ON) || \
      (MCU_CLMA2_OPERATION == STD_ON) || \
      (MCU_CLMA3_OPERATION == STD_ON))

  uint8 LucData;
  #endif
  /* MISRA Violation: START (4:2982)-10 */
  /* Initialize to default values */
  LenReturnValue = E_OK;
  LusCount = MCU_LOOPCOUNT;
  LulExternaClkDivider = MCU_ZERO;
  LucExtClkSrcClk = MCU_ZERO;
  LucRetryCount = MCU_LOOPCOUNT;
  LucClockIndex = MCU_ZERO;
 /* END (4:2982)-10 */
  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  /* TRACE [R4, MCU139] */
  /* TRACE [R4, MCU125] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU163] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                             MCU_INITCLOCK_SID, MCU_E_UNINIT);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Report to DET, if clock setting Id is invalid */
  /* TRACE [R4, MCU183_Conf] */
  /* TRACE [R4, MCU232] */
  if (MCU_MAX_CLK_SET <= ClockSetting)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU163] */
    /* TRACE [R4, MCU019] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                        MCU_INITCLOCK_SID, MCU_E_PARAM_CLOCK);
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  /* Check if any development error occurred */
  if (E_OK == LenReturnValue)
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  {
    /* MISRA Violation: START Msg(4:0316)-1 */
    /* MISRA Violation: START Msg(4:0488)-3 */
    /* Store the pointer to the configured clock structure  */
    /* TRACE [R4, MCU183_Conf] */
    /* TRACE [R4, MCU232] */
    Mcu_GpClockSetting =
          (((P2CONST(Mcu_ClockSetting, MCU_VAR, MCU_CONFIG_CONST))
                              Mcu_GpConfigPtr->pClockSetting) + ClockSetting);
    /* END Msg(4:0488)-3 */
    /* END Msg(4:0316)-1 */

    /* Initialize clock index */
    LucClockIndex = MCU_ZERO;

    do
    {
      switch (LucClockIndex)
      {
        case MCU_ZERO:
        /* Get the value of the selected source clock for extclk 0 */
        LucExtClkSrcClk = Mcu_GpClockSetting->ucExtClk0SelectedSrcClock;

        /* Get the value of the divider for extclk 0 */
        LulExternaClkDivider = Mcu_GpClockSetting->ulExternalClk0Divider;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CLKD0DIV register to the pointer structure */
        LMcuExtClockReg.pMcuExtClkDiv = &MCU_CLKD0DIV;
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CLKD0STAT register to the pointer structure */
        LMcuExtClockReg.pMcuExtClkDivStat = &MCU_CLKD0STAT;
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CKSC0CTL register to the pointer structure */
        LMcuExtClockReg.pMcuExtCkscCtl = &MCU_CKSC0CTL;
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CKSC0STAT register to the pointer structure */
        LMcuExtClockReg.pMcuExtCkscStat = &MCU_CKSC0STAT;
        /* END Msg(4:0303)-2 */
        break;

        case MCU_ONE:
        /* Get the value of the selected source clock for extclk 1 */
        LucExtClkSrcClk = Mcu_GpClockSetting->ucExtClk1SelectedSrcClock;

        /* Get the value of the divider for extclk 1 */
        LulExternaClkDivider = Mcu_GpClockSetting->ulExternalClk1Divider;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CLKD1DIV register to the pointer structure */
        LMcuExtClockReg.pMcuExtClkDiv = &MCU_CLKD1DIV;
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CLKD1STAT register to the pointer structure */
        LMcuExtClockReg.pMcuExtClkDivStat = &MCU_CLKD1STAT;
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CKSC1CTL register to the pointer structure */
        LMcuExtClockReg.pMcuExtCkscCtl = &MCU_CKSC1CTL;
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Load the address of CKSC1STAT register to the pointer structure */
        LMcuExtClockReg.pMcuExtCkscStat = &MCU_CKSC1STAT;
        /* END Msg(4:0303)-2 */
        break;

        default:

        break;
      }

      /* Load zero in div register */
      *(LMcuExtClockReg.pMcuExtClkDiv) = MCU_ZERO;

      /* Disable the clock output first */
      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Load value in control reg to stop external clock */
      Mcu_ProtectedWrite((*(LMcuExtClockReg.pMcuExtCkscCtl)),
                            MCU_LONG_WORD_ZERO, MCU_PROT1PHCMD, MCU_PROT1PS,
                            LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */


      if (E_OK == LenReturnValue)
      {
        /* Check configured clock is already selected, if no select it */
        if ((*(LMcuExtClockReg.pMcuExtCkscStat) & LucExtClkSrcClk) !=
                                                              LucExtClkSrcClk)
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Load source clock selection for external clock in control reg */
          Mcu_ProtectedWrite((*LMcuExtClockReg.pMcuExtCkscCtl),
           (uint32)LucExtClkSrcClk, MCU_PROT1PHCMD, MCU_PROT1PS, LucRetryCount,
                                                              LenReturnValue)
          /* END Msg(4:0303)-2 */

          /* Check if any DEM error occurred */
          if (E_OK == LenReturnValue)
          {
            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* Read back to Clock selection Control register 0 */
            Mcu_ReadBackDiagTest(*LMcuExtClockReg.pMcuExtCkscCtl,
                                             LucExtClkSrcClk, LenReturnValue)
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            /* Check if any development error occurred and
             * external clock selected is not NO_OUTPUT */
            /* MISRA Violation: START Msg(4:2995)-4 */
            /* MISRA Violation: START Msg(4:2991)-9 */
            if ((E_OK == LenReturnValue) && (MCU_ZERO != LucExtClkSrcClk))
            {
            /* END Msg(4:2991)-9 */
            /* END Msg(4:2995)-4 */
              /* Initialize maximum 12us Delay count value */
              LusCount = MCU_EXTCLKSEL_DELAY_CNT;

              /* Check clock selection happened successfully  */
              while ((((*LMcuExtClockReg.pMcuExtCkscStat) &
                        ((uint32)LucExtClkSrcClk | MCU_CLOCK_ACTIVE)) !=
                        ((uint32)LucExtClkSrcClk | MCU_CLOCK_ACTIVE)) &&
                                                        (LusCount > MCU_ZERO))
              {
                LusCount--;
              }

              if (((*LMcuExtClockReg.pMcuExtCkscStat) &
                        ((uint32)LucExtClkSrcClk | MCU_CLOCK_ACTIVE)) !=
                        ((uint32)LucExtClkSrcClk | MCU_CLOCK_ACTIVE))
              {
                /* Clock selection failed and report production error */
                /* TRACE [R4, MCU102] */
                /* TRACE [R4, MCU053] */
                /* TRACE [R4, MCU049] */
                /* TRACE [R4, MCU051] */
                /* TRACE [R4, MCU166] */
                Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);
                /* Set the return value to  E_NOT_OK */
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

        /* Set the divider value as per configuration if the external clock
         * selected is not NO_OUTPUT */
        if ((E_OK == LenReturnValue) && (MCU_ZERO != LucExtClkSrcClk))
        {
          /* Delay before configuration divider if HSINT oscillation
           * clock selected
           */
          if ( MCU_HSINT_OSC == LucExtClkSrcClk)
          {
            LusCount = MCU_EXTCLKSEL_DELAY_CNT;
            while ((LusCount > MCU_ZERO))
            {
              /* Decrement the counter */
              LusCount--;
            }
          }
          else
          {
            /* No action required */
          }

          /* Load the divider value as per configuration */
          *(LMcuExtClockReg.pMcuExtClkDiv) = LulExternaClkDivider;

          #if (MCU_READBACK_CONFIGURATION == STD_ON)
          /* Read back divider Control register  */
          Mcu_ReadBackDiagTest(*(LMcuExtClockReg.pMcuExtClkDiv),
                                        LulExternaClkDivider, LenReturnValue)

          /* Check if any DEM error occurred */
          if (E_OK == LenReturnValue)
          #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
          {
            /* Initialize maximum 12 us delay count value */
            LusCount = MCU_EXTCLKSEL_DELAY_CNT;

            /* Check clock selection happened successfully  */
            while ((MCU_CLKOUT_ACTIVE_SYNC  !=
                 ((*LMcuExtClockReg.pMcuExtClkDivStat) &
                            MCU_CLKOUT_ACTIVE_SYNC)) && (LusCount > MCU_ZERO))
            {
              /* Decrement the counter */
              LusCount--;
            }

            if (MCU_CLKOUT_ACTIVE_SYNC != ((*LMcuExtClockReg.pMcuExtClkDivStat)
                                   & MCU_CLKOUT_ACTIVE_SYNC))
            {
              /* PLL0 Clock selection failed and report production error */
              /* TRACE [R4, MCU102] */
              /* TRACE [R4, MCU053] */
              /* TRACE [R4, MCU049] */
              /* TRACE [R4, MCU051] */
              /* TRACE [R4, MCU166] */
              Dem_ReportErrorStatus(MCU_E_CLOCK_FAILURE,
                                                    DEM_EVENT_STATUS_FAILED);
              LenReturnValue = E_NOT_OK;
            }
            else
            {
              /* No action required */
            }
          }
          #if (MCU_READBACK_CONFIGURATION == STD_ON)
          else
          {
            /* No action required */
          }
          #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
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

      /* Increment the clock index */
      LucClockIndex++;
    }while ((LucClockIndex < MCU_TWO) && (E_OK == LenReturnValue));

    #if (MCU_CLMA0_OPERATION == STD_ON)
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check if No Dem error occurred and Clock monitor CLMA0 is disabled */
    if ((E_OK == LenReturnValue) && ((MCU_CLMA0CTL0 & MCU_ONE) == MCU_ZERO))
    /* END Msg(4:0303)-2 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the Higher threshold value for frequency limit in
       * the compare register
       */
      MCU_CLMA0CMPH = Mcu_GpConfigPtr->usCLMA0CMPH;
      /* END Msg(4:0303)-2 */

      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Read back to Higher threshold value compare register */
      Mcu_ReadBackDiagTest(MCU_CLMA0CMPH, Mcu_GpConfigPtr->usCLMA0CMPH,
                                                              LenReturnValue)
      /* END Msg(4:0303)-2 */

      if (E_OK == LenReturnValue)
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Set the Lower threshold value for frequency limit in
         * the compare register
         */
        MCU_CLMA0CMPL = Mcu_GpConfigPtr->usCLMA0CMPL;
        /* END Msg(4:0303)-2 */

        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Read back to Lower threshold value compare register */
        Mcu_ReadBackDiagTest(MCU_CLMA0CMPL,
                                Mcu_GpConfigPtr->usCLMA0CMPL, LenReturnValue)
        /* END Msg(4:0303)-2 */

        if (E_OK == LenReturnValue)
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:4464)-5 */
          /* Write data to protected CLMA0 control register */
          LucData = MCU_ONE;
          Mcu_ProtectedWrite(MCU_CLMA0CTL0, LucData, MCU_CLMA0PCMD,
                                  MCU_CLMA0PS, LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */
          /* END Msg(4:4464)-5 */

          if (E_OK == LenReturnValue)
          {
            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read back to CLMA0 Control register 0 */
            Mcu_ReadBackDiagTest(MCU_CLMA0CTL0, MCU_ONE, LenReturnValue)
            /* END Msg(4:0303)-2 */
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            #if (MCU_CLMA0_SELFDIAGNOSTIC_TEST == STD_ON)
            LenReturnValue =
                    Mcu_ClmaSelfDiagnosticTest(MCU_CLMA0, MCU_CLMA0_DELAY_CNT);
            #endif /* (MCU_CLMA0_SELFDIAGNOSTIC_TEST == STD_ON) */
          }
          else
          {
            /* No action required */
          }
        }
        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        else
        {
          /* No action required */
        }
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      }
      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      else
      {
        /* No action required */
      }
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_CLMA0_ENABLE == STD_ON) */

    #if (MCU_CLMA1_OPERATION == STD_ON)
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check if No Dem error occurred and Clock monitor CLMA1 is disabled */
    if ((E_OK == LenReturnValue) && (MCU_ZERO == (MCU_CLMA1CTL0 & MCU_ONE)))
    /* END Msg(4:0303)-2 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the Higher threshold value for frequency limit in
       * the compare register
       */
      MCU_CLMA1CMPH = Mcu_GpConfigPtr->usCLMA1CMPH;
      /* END Msg(4:0303)-2 */

      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Read back to Higher threshold value compare register */
      Mcu_ReadBackDiagTest(MCU_CLMA1CMPH,
                                Mcu_GpConfigPtr->usCLMA1CMPH, LenReturnValue)
      /* END Msg(4:0303)-2 */

      /* Check if any DEM error occurred */
      if (E_OK == LenReturnValue)
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Set the Lower threshold value for frequency limit in
         * the compare register
         */
        MCU_CLMA1CMPL = Mcu_GpConfigPtr->usCLMA1CMPL;
        /* END Msg(4:0303)-2 */

        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Read back to Lower threshold value compare register */
        Mcu_ReadBackDiagTest(MCU_CLMA1CMPL,
                                Mcu_GpConfigPtr->usCLMA1CMPL, LenReturnValue)
        /* END Msg(4:0303)-2 */

        if (E_OK == LenReturnValue)
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:4464)-5 */
          /* Write data to protected CLMA1 control register */
          LucData = MCU_ONE;
          Mcu_ProtectedWrite(MCU_CLMA1CTL0, LucData, MCU_CLMA1PCMD,
                                   MCU_CLMA1PS, LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */
          /* END Msg(4:4464)-5 */

          if (E_OK == LenReturnValue)
          {
            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read back to CLMA1 Control register */
            Mcu_ReadBackDiagTest(MCU_CLMA1CTL0, MCU_ONE, LenReturnValue)
            /* END Msg(4:0303)-2 */
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            #if (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON)
            LenReturnValue =
                    Mcu_ClmaSelfDiagnosticTest(MCU_CLMA1, MCU_CLMA1_DELAY_CNT);
            #endif /* (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON) */
          }
          else
          {
            /* No action required */
          }
        }
        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        else
        {
          /* No action required */
        }
        #endif /* (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON) */
      }
      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      else
      {
        /* No action required */
      }
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_CLMA1_ENABLE == STD_ON) */

    #if (MCU_CLMA2_OPERATION == STD_ON)
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check if No Dem error occurred and Clock monitor CLMA2 is disabled */
    if ((E_OK == LenReturnValue) && (MCU_ZERO == (MCU_CLMA2CTL0 & MCU_ONE)))
    /* END Msg(4:0303)-2 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the Higher threshold value for frequency limit in the compare
       * register
       */
      MCU_CLMA2CMPH = Mcu_GpConfigPtr->usCLMA2CMPH;
      /* END Msg(4:0303)-2 */

      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Read back Higher threshold value compare register */
      Mcu_ReadBackDiagTest(MCU_CLMA2CMPH,
                                  Mcu_GpConfigPtr->usCLMA2CMPH, LenReturnValue)
      /* END Msg(4:0303)-2 */

      if (E_OK == LenReturnValue)
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Set the Lower threshold value for frequency limit in
         * the compare register
         */
        MCU_CLMA2CMPL = Mcu_GpConfigPtr->usCLMA2CMPL;
        /* END Msg(4:0303)-2 */

        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Read back Lower threshold value compare register */
        Mcu_ReadBackDiagTest(MCU_CLMA2CMPL,
                                Mcu_GpConfigPtr->usCLMA2CMPL, LenReturnValue)
        /* END Msg(4:0303)-2 */

        /* Check if any DEM error occurred */
        if (E_OK == LenReturnValue)
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:4464)-5 */
          /* Write data to protected CLMA2 control register */
          LucData = MCU_ONE;
          Mcu_ProtectedWrite(MCU_CLMA2CTL0, LucData, MCU_CLMA2PCMD,
                                  MCU_CLMA2PS, LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */
          /* END Msg(4:4464)-5 */

          /* Check if any DEM error occurred */
          if (E_OK == LenReturnValue)
          {
            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read back to CLMA2 Control register 0 */
            Mcu_ReadBackDiagTest(MCU_CLMA2CTL0, MCU_ONE, LenReturnValue)
            /* END Msg(4:0303)-2 */
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            #if (MCU_CLMA2_SELFDIAGNOSTIC_TEST == STD_ON)
            LenReturnValue =
                    Mcu_ClmaSelfDiagnosticTest(MCU_CLMA2, MCU_CLMA2_DELAY_CNT);
            #endif /* (MCU_CLMA2_SELFDIAGNOSTIC_TEST == STD_ON) */
          }
          else
          {
            /* No action required */
          }
        }
        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        else
        {
          /* No action required */
        }
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      }
      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      else
      {
        /* No action required */
      }
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_CLMA2_ENABLE == STD_ON) */

    #if (MCU_CLMA3_OPERATION == STD_ON)
    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Check if No Dem error occurred and Clock monitor CLMA3 is disabled */
    if ((E_OK == LenReturnValue) && (MCU_ZERO == (MCU_CLMA3CTL0 & MCU_ONE)))
    /* END Msg(4:0303)-2 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the Higher threshold value for frequency limit in
       * the compare register
       */
      MCU_CLMA3CMPH = Mcu_GpConfigPtr->usCLMA3CMPH;
      /* END Msg(4:0303)-2 */

      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Read back Higher threshold value compare register */
      Mcu_ReadBackDiagTest(MCU_CLMA3CMPH,
                                Mcu_GpConfigPtr->usCLMA3CMPH, LenReturnValue)
      /* END Msg(4:0303)-2 */

      /* Check if any DEM error occurred */
      if (E_OK == LenReturnValue)
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Set the Lower threshold value for frequency limit in
         * the compare register
         */
        MCU_CLMA3CMPL = Mcu_GpConfigPtr->usCLMA3CMPL;
        /* END Msg(4:0303)-2 */

        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Read back Lower threshold value compare register */
        Mcu_ReadBackDiagTest(MCU_CLMA3CMPL,
                                Mcu_GpConfigPtr->usCLMA3CMPL, LenReturnValue)
        /* END Msg(4:0303)-2 */

        if (E_OK == LenReturnValue)
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* MISRA Violation: START Msg(4:4464)-5 */
          /* Write data to protected CLMA3 control register */
          LucData = MCU_ONE;
          Mcu_ProtectedWrite(MCU_CLMA3CTL0, LucData, MCU_CLMA3PCMD,
                             MCU_CLMA3PS, LucRetryCount, LenReturnValue)
          /* END Msg(4:4464)-5 */
          /* END Msg(4:0303)-2 */

          if (E_OK == LenReturnValue)
          {
            #if (MCU_READBACK_CONFIGURATION == STD_ON)
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Read back to CLMA3 Control register 0 */
            Mcu_ReadBackDiagTest(MCU_CLMA3CTL0, MCU_ONE, LenReturnValue)
            /* END Msg(4:0303)-2 */
            #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */

            #if (MCU_CLMA3_SELFDIAGNOSTIC_TEST == STD_ON)
            LenReturnValue =
                    Mcu_ClmaSelfDiagnosticTest(MCU_CLMA3, MCU_CLMA3_DELAY_CNT);
            #endif /* (MCU_CLMA3_SELFDIAGNOSTIC_TEST == STD_ON) */
          }
          else
          {
            /* no action required */
          }
        }
        #if (MCU_READBACK_CONFIGURATION == STD_ON)
        else
        {
          /* no action required */
        }
        #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
      }
      #if (MCU_READBACK_CONFIGURATION == STD_ON)
      else
      {
        /* no action required */
      }
      #endif /* (MCU_READBACK_CONFIGURATION == STD_ON) */
    }
    else
    {
      /* No action required */
    }
    #endif /* (MCU_CLMA3_ENABLE == STD_ON) */
  }
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* No action required */
  }
  #endif /* MCU_DEV_ERROR_DETECT == STD_ON */
  return (LenReturnValue);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_INIT_CLOCK == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_DistributePllClock
**
** Service ID         : 0x03
**
** Description        : This service activates the PLL clock to the MCU clock
**                      distribution
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : void
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Mcu_GetPllStatus, Det_ReportError
**
** Registers Used     : None
******************************************************************************/
#if (MCU_NO_PLL == STD_OFF)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R4, MCU156] */
/* TRACE [R4, MCU140] */
/* TRACE [R4, MCU141] */
/* TRACE [R4, MCU056] */
FUNC(void, MCU_PUBLIC_CODE) Mcu_DistributePllClock (void)
{
  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  Mcu_PllStatusType LddPllLockStatus;

  /* Get the PLL status */
  LddPllLockStatus = Mcu_GetPllStatus();

  /* Report to DET, if module is not initialized */
  /* TRACE [R4, MCU125] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU163] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                   MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_UNINIT);
  }
  else
  {
    /* No action required */
  }

  /* Get the PLL status and if PLL status is not 'LOCKED', report to DET */
  if (MCU_PLL_UNLOCKED == LddPllLockStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    /* TRACE [R4, MCU163] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                           MCU_DISTRIBUTEPLLCLOCK_SID, MCU_E_PLL_NOT_LOCKED);
  }
  /* If no DET error, continue */
  else
  {
    /* No action required */
  }
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_NO_PLL == STD_OFF) */
/******************************************************************************
** Function Name      : Mcu_GetPllStatus
**
** Service ID         : 0x04
**
** Description        : This service provides the lock status of the PLL
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_PllStatusType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU157] */
FUNC(Mcu_PllStatusType, MCU_PUBLIC_CODE) Mcu_GetPllStatus (void)
{
  Mcu_PllStatusType LddPllLockStatus;
  /* Set PLL status to undefined */
  /* TRACE [R4, MCU132] */
  /* TRACE [R4, MCU206] */
  LddPllLockStatus = MCU_PLL_STATUS_UNDEFINED;

  /* Report to DET, if module is not initialized */
  /* TRACE [R4, MCU125] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* TRACE [R4, MCU013] */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                          MCU_GETPLLSTATUS_SID, MCU_E_UNINIT);
    #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  }
  else
  {
    #if (MCU_NO_PLL == STD_OFF)
    /* PLL is locked */
    LddPllLockStatus = MCU_PLL_LOCKED;
    #endif /* (MCU_NO_PLL == STD_OFF) */
  }
  /* TRACE [R4, MCU008] */
  /* TRACE [R4, MCU230] */
  return(LddPllLockStatus);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_GetResetReason
**
** Service ID         : 0x05
**
** Description        : The function reads the reset type from the hardware
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_ResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GulLastResetReasonStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
*******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU052] */
/* TRACE [R4, MCU158] */
FUNC(Mcu_ResetType, MCU_PUBLIC_CODE) Mcu_GetResetReason (void)
{
  Mcu_ResetType LddResetSource;

  /* Report to DET, if module is not initialized */
  /* TRACE [R4, MCU125] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* TRACE [R4, MCU013] */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                        MCU_GETRESETREASON_SID, MCU_E_UNINIT);
    #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    /* Set Reset status to undefined */
    /* TRACE [R4, MCU133] */
    LddResetSource = MCU_RESET_UNDEFINED;
  }
  else
  {
    /* return the last reset reason status */
    /* TRACE [R4, MCU005] */
    LddResetSource = (Mcu_ResetType)Mcu_GulLastResetReasonStatus;
  }

  return (LddResetSource);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_GetResetRawValue
**
** Service ID         : 0x06
**
** Description        : The service return reset type value from the hardware
**                      register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : Mcu_RawResetType
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus, Mcu_GulMcuSavedResfStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU159] */
FUNC(Mcu_RawResetType, MCU_PUBLIC_CODE) Mcu_GetResetRawValue (void)
{
  uint32 LddResetValue;

  /* Report to DET, if module is not initialized */
  /* TRACE [R4, MCU125] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* TRACE [R4, MCU013] */
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                      MCU_GETRESETRAWVAULE_SID, MCU_E_UNINIT);
    #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    /* Set RESET status to uninitialized */
    /* TRACE [R4, MCU135] */
    LddResetValue = MCU_RESET_UNINIT;
  }
  else
  {
    /* Return the last clear reset raw status */
    /* TRACE [R4, MCU006] */
    LddResetValue = Mcu_GulMcuSavedResfStatus;
  }

  return(LddResetValue);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/******************************************************************************
** Function Name      : Mcu_PerformReset
**
** Service ID         : 0x07
**
** Description        : This service provides microcontroller reset by accessing
**                      the Software reset register
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : MCU_RESET_CALLOUT, Det_ReportError, Mcu_ProtectedWrite
**
** Registers Used     : SWRESA, PROT1PHCMD, PROT1PS
******************************************************************************/
/* TRACE [R4, MCU146] */
#if (MCU_PERFORM_RESET_API == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"
/* TRACE [R4, MCU160] */
/* TRACE [R4, MCU055] */
FUNC (void, MCU_PUBLIC_CODE) Mcu_PerformReset (void)
{
  #if (MCU_SW_RESET_CALL_API == STD_OFF)
  uint8 LucSWRESCount;
  LucSWRESCount = MCU_LOOPCOUNT;
  #endif /* (MCU_SW_RESET_CALL_API == STD_OFF) */

  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if module is not initialized */
  /* TRACE [R4, MCU145] */
  /* TRACE [R4, MCU125] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                          MCU_PERFORMRESET_SID, MCU_E_UNINIT);
  }
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (MCU_SW_RESET_CALL_API == STD_ON)
    /* invoke the reset call API */
    MCU_RESET_CALLOUT();
    #else

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Write value to SWRESA register */
    /* TRACE [R4, MCU143] */
    /* TRACE [R4, MCU144] */
    Mcu_ProtectedWriteRetNone(MCU_SWRESA, MCU_RES_CORRECT_VAL, MCU_PROT1PHCMD,
                       MCU_PROT1PS, LucSWRESCount)
    /* END Msg(4:0303)-2 */

    #endif /* (MCU_SW_RESET_CALL_API == STD_ON) */
  }
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_PERFORMRESET_API == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_SetMode
**
** Service ID         : 0x08
**
** Description        : This service activates the MCU power modes
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : McuMode - Id for power mode setting
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : MCU Driver component must be initialized
**
** Global Variables   : Mcu_GblDriverStatus
**
** Function Invoked   : Det_ReportError
**
** Registers Used     : None
******************************************************************************/

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU161] */
/* TRACE [R4, MCU237] */
FUNC(void, MCU_PUBLIC_CODE) Mcu_SetMode (Mcu_ModeType McuMode)
{
  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  /* TRACE [R4, MCU125] */
  /* TRACE [R4, MCU148] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                               MCU_SETMODE_SID, MCU_E_UNINIT);
  }
  else
  {
    /* No action required */
  }

  if (MCU_MAX_MODESETTING <= McuMode )
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                            MCU_SETMODE_SID, MCU_E_PARAM_MODE);
  }
  else
  {
    /* No action required */
  }
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Mcu_GetRamState
**
** Service ID           : 0x0A
**
** Description          : This service provides the actual status of the
**                        microcontroller RAM area
**
** Sync/Async           : Synchronous
**
** Reentrancy           : Non-Reentrant
**
** Input Parameters     : None
**
** InOut Parameters     : None
**
** Output Parameters    : None
**
** Return parameter     : Mcu_RamStateType
**                        (MCU_RAMSTATE_INVALID, MCU_RAMSTATE_VALID)
**
** Preconditions        : MCU Driver component must be initialized
**
** Global Variables     : Mcu_GblDriverStatus, Mcu_GblRAMInitStatus
**
** Functions Invoked    : Det_ReportError, MCU_ENTER_CRITICAL_SECTION,
**                        MCU_EXIT_CRITICAL_SECTION
**
** Registers Used       : None
*******************************************************************************/
/* TRACE [R4, MCU209] */
#if (MCU_GET_RAM_STATE_API == STD_ON)

/*To use Public Code section in the Memory*/
#define MCU_START_SEC_PUBLIC_CODE
#include "MemMap.h"

/* TRACE [R4, MCU207] */
FUNC(Mcu_RamStateType, MCU_PUBLIC_CODE) Mcu_GetRamState (void)
{
  Mcu_RamStateType LddRamStatus;

  LddRamStatus = MCU_RAMSTATE_INVALID;
  /* TRACE [R4, MCU013] */
  #if (MCU_DEV_ERROR_DETECT == STD_ON)
  /* Report to DET, if the component is not initialized */
  /* TRACE [R4, MCU125] */
  /* TRACE [R4, MCU208] */
  if (MCU_UNINITIALIZED == Mcu_GblDriverStatus)
  {
    /* Report to DET */
    /* TRACE [R4, MCU017] */
    /* TRACE [R4, MCU016] */
    (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID,
                                           MCU_GETRAMSTATE_SID, MCU_E_UNINIT);
  }
  /* if no development error occurred */
  else
  #endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
  {
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Store the current variable value to the return value */
    LddRamStatus = (Mcu_RamStateType) Mcu_GblRAMInitStatus;

    /* Clear the global variable status to default state */
    Mcu_GblRAMInitStatus = (boolean) MCU_RAMSTATE_VALID;

    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }

  return (LddRamStatus);
}

/*Exit Public Code section in the Memory*/
#define MCU_STOP_SEC_PUBLIC_CODE
#include "MemMap.h"

#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_CvmSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check CVM self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpConfigPtr
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ProtectedWrite
**
** Registers Used     : CVMDIAG, CVMFC, CVMF, CVMDMASK, PROTCMDCVM, PROTSCVM
******************************************************************************/
#if (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_CvmSelfDiagnosticTest (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint16, AUTOMATIC) LusLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucCVMCntValue;
  VAR(uint8, AUTOMATIC) LucCVMFStatus;
  VAR(uint8, AUTOMATIC) LucCVMFCData;

  /* Initialize the return value */
  LenReturnValue = E_OK;
  /* Get the configured CVM control value  */
  LucCVMCntValue = Mcu_GpConfigPtr->ucCvmIndicationReg;
  LucCVMFStatus = MCU_CVM_UNMASK_ERROR_CHECK;

  /* Check if CVM output mask is configured */
  if (MCU_CVM_DIAG_MASK == (LucCVMCntValue & MCU_CVM_DIAG_MASK))
  {
    /* Initialize the loop count value */
    LucRetryCount = MCU_LOOPCOUNT;

    LucCVMFStatus = MCU_CVM_MASK_ERROR_CHECK;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Mask CVMOUT output in self diagnosis mode */
    Mcu_ProtectedWrite(MCU_CVMDMASK, MCU_ONE, MCU_PROTCMDCVM, MCU_PROTSCVM,
                                               LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */
  }
  else
  {
    /* No action required */
  }

  /* Initialize the loop count value */
  LusLoopCount = MCU_LOOPCOUNT;

  /* Clear all the error flags before starting the self diagnostic testing */
  do
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_CVMF != MCU_ZERO)
    /* END Msg(4:0303)-2 */
    {
      /* Initialize the loop count value */
      LucRetryCount = MCU_LOOPCOUNT;

      LucCVMFCData = MCU_CVM_FACTOR_CLEAR;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Write the value to the CVM factor clear register  */
      Mcu_ProtectedWrite(MCU_CVMFC, LucCVMFCData, MCU_PROTCMDCVM,
                                 MCU_PROTSCVM, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
    }
    else
    {
      /* No action required */
    }

    LusLoopCount--;
  /* MISRA Violation: START Msg(4:0303)-2 */
  } while ((MCU_ZERO != MCU_CVMF) && (LusLoopCount > MCU_ZERO));
  /* END Msg(4:0303)-2 */

  /* Generate CVM low and high voltage error condition using DIAG registers
   * and check the status registers accordingly
   */
  if (E_OK == LenReturnValue)
  {
    /* Initialize the loop count value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* Write the value to shift to diagnosis mode */
    Mcu_ProtectedWrite(MCU_CVMDIAG, MCU_TWELVE, MCU_PROTCMDCVM,
                                  MCU_PROTSCVM, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */

    /* Check whether Dem reported or not */
    if (E_OK == LenReturnValue)
    {
      LusLoopCount = MCU_CVM_DELAY_CNT;

      /* check error status register until idle wait time 12 us
       */
      do
      {
        ASM_NOP();

        LusLoopCount--;
        /* MISRA Violation: START Msg(4:0303)-2 */
      } while ((MCU_CVMF != LucCVMFStatus) && (MCU_ZERO < LusLoopCount));
      /* END Msg(4:0303)-2 */

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Check the status of CVM Error in Factor register  */
      if ((MCU_CVMF & LucCVMFStatus) != LucCVMFStatus)
      /* END Msg(4:0303)-2 */
      {
        /* Self Diagnostic test for CVM is failed.*/
        /* TRACE [R4, MCU102] */
        /* TRACE [R4, MCU049] */
        /* TRACE [R4, MCU051] */
        /* TRACE [R4, MCU166] */
        Dem_ReportErrorStatus(MCU_E_CVM_SELFDIAG_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);

        /* Set LenReturnValue to E_NOT_OK */
        LenReturnValue = E_NOT_OK;
      }
      else
      {
        /* Initialize the loop count value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Write the value to shift to normal mode */
        Mcu_ProtectedWrite(MCU_CVMDIAG, MCU_ZERO, MCU_PROTCMDCVM,
                                 MCU_PROTSCVM, LucRetryCount, LenReturnValue)
        /* END Msg(4:0303)-2 */
      }

      /* Initialize the loop count value */
      LusLoopCount = MCU_CVM_DELAY_CNT;
    /* Wait for idle time after shifting to normal mode*/
      do
      {
        /* MISRA Violation: START Msg(4:0303)-2 */
        if (MCU_ZERO != MCU_CVMF)
        /* END Msg(4:0303)-2 */
        {
          /* Initialize the loop count value */
          LucRetryCount = MCU_LOOPCOUNT;

          LucCVMFCData = MCU_CVM_FACTOR_CLEAR;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Write the value to the CVM factor clear register  */
          Mcu_ProtectedWrite(MCU_CVMFC, LucCVMFCData, MCU_PROTCMDCVM,
                                 MCU_PROTSCVM, LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */
        }
        else
        {
          /* No action required */
        }

        LusLoopCount--;
      /* MISRA Violation: START Msg(4:0303)-2 */
      } while ((MCU_ZERO != MCU_CVMF) && (LusLoopCount > MCU_ZERO));
      /* END Msg(4:0303)-2 */

      /* Initialize the loop count value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Write the value to unmask CVMOUT output in diagnosis mode */
      Mcu_ProtectedWrite(MCU_CVMDMASK, MCU_ZERO, MCU_PROTCMDCVM,
                                MCU_PROTSCVM, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
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

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_CVM_SELFDIAGNOSTIC_TEST == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_ClmaSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check CLMA self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ProtectedWrite
**
** Registers Used     : CLMATESTS, CLMATEST, PROT1PHCMD, PROT1PS
******************************************************************************/
#if ((MCU_CLMA0_SELFDIAGNOSTIC_TEST == STD_ON) || \
     (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON) || \
     (MCU_CLMA2_SELFDIAGNOSTIC_TEST == STD_ON) || \
     (MCU_CLMA3_SELFDIAGNOSTIC_TEST == STD_ON))

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
Mcu_ClmaSelfDiagnosticTest (Mcu_ClmaIndexType LenClmaXIndex, uint16 Delay_Count)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC)LulClmaXTestValue;
  VAR(uint8, AUTOMATIC) LucClmaDiagIndex;
  VAR(uint16, AUTOMATIC) LusClmaCount;
  VAR(uint8, AUTOMATIC)LucRetryCount;
  VAR(boolean, AUTOMATIC) LblDemReported;

  /* Initialize Clock monitor index */
  LucClmaDiagIndex = MCU_ZERO;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  LblDemReported = MCU_FALSE;
  LulClmaXTestValue = MCU_ZERO;

  do
  {
    switch (LucClmaDiagIndex)
    {
      case MCU_ZERO:
      /* Set the value to enable the Self testing for CLMAn and mask the error
       * notification to ECM.
       */
      LulClmaXTestValue = ((CLMA_SELF_TEST_VALUE << LenClmaXIndex) | MCU_FOUR);
      break;

      case MCU_ONE:
      /* Set the value to fixes the level of the clock input to the CLMAn
       * that should be monitored, to the low level.
       */
      LulClmaXTestValue = (LulClmaXTestValue | MCU_TWO);
      break;

      case MCU_TWO:
      /* maximum wait delay count value */
      LusClmaCount = Delay_Count;

      /* wait for sampling cycles to set corresponding error status */
      do
      {
        LusClmaCount--;
      /* MISRA Violation: START Msg(4:0303)-2 */
      }while ((((uint8)MCU_CLMATESTS & (uint8)(MCU_ONE << LenClmaXIndex)) !=
              (uint8)(MCU_ONE << LenClmaXIndex)) && (LusClmaCount > MCU_ZERO));
      /* END Msg(4:0303)-2 */

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Check the clock monitor status bit for error detection */
      if (((uint8)MCU_CLMATESTS & (uint8)(MCU_ONE << LenClmaXIndex))
                                         != (uint8)(MCU_ONE << LenClmaXIndex))
      /* END Msg(4:0303)-2 */
      {
        /* Self Diagnostic test for CLMA is failed.*/
        /* TRACE [R4, MCU102] */
        /* TRACE [R4, MCU049] */
        /* TRACE [R4, MCU051] */
        /* TRACE [R4, MCU166] */
        Dem_ReportErrorStatus(MCU_E_CLM_SELFDIAG_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);

        /* Set the flag to true value */
        LblDemReported = MCU_TRUE;
      }
      else
      {
        /* No action required */
      }

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the value to clear the error generated by self-diagnosis */
      LulClmaXTestValue = (MCU_CLMATEST | MCU_ONE);
      /* END Msg(4:0303)-2 */
      break;

      case MCU_THREE:
      /*Set the value to terminate self-diagnosis by writing zero */
      LulClmaXTestValue = MCU_ZERO;
      break;

      default:
      /* Set the value so that it exits the loop */
      LucClmaDiagIndex = MCU_FOUR;
      break;
    }

    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    Mcu_ProtectedWrite(MCU_CLMATEST, LulClmaXTestValue, MCU_PROT1PHCMD,
                                  MCU_PROT1PS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */

    /* Increase the index */
    LucClmaDiagIndex++;
  } while ((LucClmaDiagIndex < MCU_FOUR) && (E_OK == LenReturnValue));

  /* Check self test failed */
  if (MCU_TRUE == LblDemReported)
  {
    LenReturnValue = E_NOT_OK;
  }
  else
  {
    /* No action required */
  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* ((MCU_CLMA0_SELFDIAGNOSTIC_TEST == STD_ON) ||
        *  (MCU_CLMA1_SELFDIAGNOSTIC_TEST == STD_ON) ||
        *  (MCU_CLMA2_SELFDIAGNOSTIC_TEST == STD_ON) ||
        *  (MCU_CLMA3_SELFDIAGNOSTIC_TEST == STD_ON))
        */

/******************************************************************************
** Function Name      : Mcu_EcmSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check Ecm self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting
**
** Function Invoked   : MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION,
**                      Dem_ReportErrorStatus, Mcu_ProtectedWrite
**
** Registers Used     : ECMEMK0, ECMMESSTR0, ECMCESSTR0, ECMEMK1, ECMMESSTR1,
**                      ECMCESSTR1, ECMESSTC1, ECMEMK0HH, ECMMICFG0HH,
**                      ECMNMICFG0HH, ECMIRCFG0HH, ECMMECLR, ECMMPCMD0,
**                      ECMCECLR, ECMCPCMD0, ECMESSTC0, ECMPCMD1, ECMPS, ECMPE0
**                      ECMPE1
******************************************************************************/
#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_EcmSelfDiagnosticTest (void)
{
  P2CONST(Mcu_EcmSetting, MCU_VAR, MCU_CONFIG_CONST) LpEcmSetting;
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulEcmPseudoData;
  VAR(volatile uint32, AUTOMATIC) LulEcmConfigAddress;
  VAR(uint8, AUTOMATIC) LucEcmDiagCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;


  /* Load the Ecm config start address  */
  LpEcmSetting = Mcu_GpEcmSetting;
  /* Initialize the return value */
  LenReturnValue = E_OK;
  /* Initialize the retry count to config value */
  LucRetryCount = MCU_LOOPCOUNT;

  /* load ECM pseudo error trigger register 0 address */
  LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMPE0_OFFSET;

  /* MISRA Violation: START Msg(4:0303)-2 */
  Mcu_ProtectedWrite(MCU_ECMEMK0, LpEcmSetting->ulEcmErrorMaskReg0Value,
                      MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
  /* END Msg(4:0303)-2 */

  /* Check diagnostic test on each ECM error source */
  for (LucEcmDiagCount = MCU_ZERO;
          (LucEcmDiagCount < MCU_THIRTYTWO) && (E_OK == LenReturnValue);
                                                            LucEcmDiagCount++)
  {
    /* Skip unused bits in the config reg */
    if ((MCU_TWO != LucEcmDiagCount) && (MCU_THREE != LucEcmDiagCount))
    {
      LulEcmPseudoData = (uint32)((LpEcmSetting->ulEcmErrorMaskReg0Value) &
                                        ((uint32)MCU_ONE << LucEcmDiagCount));

      /* Check only error out configured sources */
      if (MCU_ZERO == LulEcmPseudoData)
      {
        if (MCU_TWENTYNINE == LucEcmDiagCount)
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Unmask the ERROROUT bit for ECM error source 29 */
          Mcu_ProtectedWrite(MCU_ECMEMK0,
                        (MCU_ECMEMK0 & (~MCU_ECM029_MASK_VALUE)),
                        MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */
        }
        else
        {
          /* No action required */
        }

        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;

        /* Write the value for generating the ECM error */
        LulEcmPseudoData = ((uint32)MCU_ONE << LucEcmDiagCount);

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Generate the error using ECMPE0 register */
        Mcu_ProtectedWrite(*(volatile uint32 *)LulEcmConfigAddress,
              LulEcmPseudoData, MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount,
                                                              LenReturnValue)
        /* END Msg(4:0303)-2 */

        /* Check whether Dem reported or not */
        if (E_OK == LenReturnValue)
        {
          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Check error out put status as low
           * MCU_ERROROUT_STATUS = 0x80000000
           */
          if ((MCU_ZERO != (MCU_ECMMESSTR0 & LulEcmPseudoData)) &&
              (MCU_ZERO != (MCU_ECMCESSTR0 & LulEcmPseudoData)) &&
              ((MCU_ZERO == (MCU_ECMMESSTR1 & MCU_ERROROUT_STATUS)) &&
              (MCU_ZERO == (MCU_ECMCESSTR1 & MCU_ERROROUT_STATUS))))
          /* END Msg(4:0303)-2 */
          {
            /* Setting the error signal from the error pin to the high level
             * (inactive) for next test
             */
            LenReturnValue = Mcu_ClearEcmErrorOutput();
          }
          else
          {
            /* Self Diagnostic test for ECM is failed.*/
            /* TRACE [R4, MCU102] */
            /* TRACE [R4, MCU049] */
            /* TRACE [R4, MCU051] */
            /* TRACE [R4, MCU166] */
            Dem_ReportErrorStatus(MCU_E_ECM_SELFDIAG_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);

            /* Set LenReturnValue to E_NOT_OK */
            LenReturnValue = E_NOT_OK;
          }
        } /* End of (E_OK == LenReturnValue) */
        else
        {
          /* No action required */
        }
      } /* End of (MCU_ZERO != LulEcmPseudoData) */
      else
      {
        /* No action required */
      }
    }
    else
    {
      /* No action required */
    }
  }

  /* Check whether Dem reported or not */
  if (E_OK == LenReturnValue)
  {
    /* Perform Ecm diagnostic test on register 1 */
    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    Mcu_ProtectedWrite(MCU_ECMEMK1, LpEcmSetting->ulEcmErrorMaskReg1Value,
                      MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:0303)-2 */

    /* load ECM pseudo error trigger register 1 address */
    LulEcmConfigAddress = MCU_ECM_BASE_ADDRESS + MCU_ECMPE1_OFFSET;

    for (LucEcmDiagCount = MCU_ZERO;
          (LucEcmDiagCount < MCU_THIRTYTWO) && (E_OK == LenReturnValue);
                                                            LucEcmDiagCount++)
    {
      if ((LucEcmDiagCount < MCU_ELEVEN) ||
                                          (MCU_TWENTYNINE == LucEcmDiagCount))
      {
        LulEcmPseudoData = (uint32)((LpEcmSetting->ulEcmErrorMaskReg1Value) &
                                        ((uint32)MCU_ONE << LucEcmDiagCount));

        /* Check only error out configured sources */
        if (MCU_ZERO == LulEcmPseudoData)
        {
          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          LulEcmPseudoData = ((uint32)MCU_ONE << LucEcmDiagCount);

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* Generate the error using ECMPE1 register */
          Mcu_ProtectedWrite(*(volatile uint32 *)LulEcmConfigAddress,
                              LulEcmPseudoData, MCU_ECMPCMD1, MCU_ECMPS,
                                               LucRetryCount, LenReturnValue)
          /* END Msg(4:0303)-2 */

          /* Check whether Dem reported or not */
          if (E_OK == LenReturnValue)
          {
            /* MISRA Violation: START Msg(4:0303)-2 */
            /* Check error out put status as low
             * MCU_ERROROUT_STATUS = 0x80000000
             */
            if ((MCU_ZERO != (MCU_ECMMESSTR1 & LulEcmPseudoData)) &&
               (MCU_ZERO != (MCU_ECMCESSTR1 & LulEcmPseudoData)) &&
               ((MCU_ZERO == (MCU_ECMMESSTR1 & MCU_ERROROUT_STATUS)) &&
               (MCU_ZERO == (MCU_ECMCESSTR1 & MCU_ERROROUT_STATUS))))
            /* END Msg(4:0303)-2 */
            {
              /* Setting the error signal from the error pin to the high level
               * (inactive) for next test.
               */
               LenReturnValue = Mcu_ClearEcmErrorOutput();
            }
            else
            {
              /* Self Diagnostic test for ECM is failed.*/
              /* TRACE [R4, MCU102] */
              /* TRACE [R4, MCU049] */
              /* TRACE [R4, MCU051] */
              /* TRACE [R4, MCU166] */
              Dem_ReportErrorStatus(MCU_E_ECM_SELFDIAG_FAILURE,
                                                     DEM_EVENT_STATUS_FAILED);

              /* Set LenReturnValue to E_NOT_OK */
              LenReturnValue = E_NOT_OK;
            }
          } /* (LenReturnValue == E_OK) */
          else
          {
            /* No action required*/
          }
        } /* (LulEcmPseudoData != MCU_ZERO) */
        else
        {
          /* No action required */
        }
      }
      else
      {
        /* No action required */
      }
    }
  }
  else
  {
    /* No action required */
  }

  return(LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */


/******************************************************************************
** Function Name      : Mcu_LockStepSelfDiagnosticTest
**
** Service ID         : None
**
** Description        : This service is to check lockstep self diagnostic test
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : MCU_EXIT_CRITICAL_SECTION, MCU_ENTER_CRITICAL_SECTION,
**                      Mcu_ProtectedWrite
**
** Registers Used     : TESTCOMPREG1, TESTCOMPREG0, ECMMESSTR0, ECMESSTC0,
**                      ECMPCMD1, ECMPS
******************************************************************************/
#if (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE)
                                         Mcu_LockStepSelfDiagnosticTest (void)
{
  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint32, AUTOMATIC) LulTestCompValue;
  VAR(uint8, AUTOMATIC) LucLoopCount;
  VAR(uint8, AUTOMATIC) LucRetryCount;

  /* Initialize the return value */
  LenReturnValue = E_OK;

  /* MISRA Violation: START Msg(4:0303)-2 */
  /* Write the arbitrary value to register TESTCOMPREG0 */
  MCU_TESTCOMPREG0 = MCU_LOCKSTEP_DUMMY_VALUE;

  /* Write the different value to register TESTCOMPREG0 */
  MCU_TESTCOMPREG1 = (~MCU_LOCKSTEP_DUMMY_VALUE);

  /* Read the TESTCOMPREG0 value so that different values will be given
   * to master and checker core, As a result lockstep error status will be set
   */
  LulTestCompValue = MCU_TESTCOMPREG0;
  /* MISRA Violation: START Msg(4:2983)-7 */
  /* Dummy operation on variable */
  LulTestCompValue++;
  /* END Msg(4:2983)-7 */
  /* END Msg(4:0303)-2 */
  /* Initialize the loop count value */
  LucLoopCount = MCU_LOOPCOUNT;

  /* MISRA Violation: START Msg(4:0303)-2 */
  /* check lock step compare error status */
  do
  {
    LucLoopCount--;
  } while ((MCU_ZERO == (MCU_ECMMESSTR0 & MCU_TWO)) &&
                                                   (LucLoopCount > MCU_ZERO));

  if (MCU_TWO == (MCU_ECMMESSTR0 & MCU_TWO))
  {
	/* END Msg(4:0303)-2 */
    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    /* MISRA Violation: START Msg(4:0303)-2 */
    /* MISRA Violation: START Msg(4:4499)-8 */
    /* Clear the ECM lock step compare error */
    Mcu_ProtectedWrite (MCU_ECMESSTC0, MCU_TWO, MCU_ECMPCMD1,
                                    MCU_ECMPS, LucRetryCount, LenReturnValue)
    /* END Msg(4:4499)-8 */
    /* END Msg(4:0303)-2 */


    #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
    MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
    #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
  }
  else
  {
    LenReturnValue = E_NOT_OK;
  }

  return (LenReturnValue);
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"

#endif /* (MCU_LOCKSTEP_SELFDIAGNOSTIC_TEST == STD_ON) */

/******************************************************************************
** Function Name      : Mcu_SaveResetReason
**
** Service ID         : NA
**
** Description        : The function reads the reset type from the hardware
**                      and saved for the usage of get reset reason and
**                      get reset raw value API's
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : None
**
** Return parameter   : None
**
** Preconditions      : None
**
** Global Variables   : Mcu_GpEcmSetting, Mcu_GulMcuSavedResfStatus,
**                      Mcu_GulLastResetReasonStatus, Mcu_GblResetStatusSaved
**
** Function Invoked   : MCU_ENTER_CRITICAL_SECTION, MCU_EXIT_CRITICAL_SECTION,
**                      Mcu_ProtectedWrite
**
** Registers Used     : POF, POFC, ECMMESSTR0, ECMMESSTR1, ECMESSTC0, ECMESSTC1,
**                      ECMPCMD1, ECMPS, RESF, RESFC
*******************************************************************************/

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(void, MCU_PRIVATE_CODE) Mcu_SaveResetReason (void)
{
  Mcu_ResetType LddResetSource;
  uint32 LulEcmStatusData0;
  uint32 LulEcmStatusData1;
  uint32 LulResfStatus;
  uint8 LucRetryCount;
  uint8 LucWriteData;

  /* Initialize to default values */
  LddResetSource = MCU_RESET_UNKNOWN;

  /* Check whether reset reason saved already, if yes no action required */
  if (MCU_FALSE == Mcu_GblResetStatusSaved)
  {
    /* MISRA Violation: START Msg(4:0303)-2 */
    if (MCU_POF_RST == MCU_POF)
    /* END Msg(4:0303)-2 */
    {
      /* Get the reset reason value for power on reset */
      LddResetSource = MCU_POWER_ON_RESET;

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear Reset factor register */
      MCU_POFC = MCU_POF_CLEAR;
      /* END Msg(4:0303)-2 */
    }
    /* MISRA Violation: START Msg(4:0303)-2 */
    else if (MCU_ZERO != MCU_RESF)
    /* END Msg(4:0303)-2 */
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Get the resf register status */
      LulResfStatus = MCU_RESF;
      /* END Msg(4:0303)-2 */

      switch (LulResfStatus)
      {
        case MCU_PINRST:
        /* Pin reset */
        LddResetSource = MCU_PIN_RST;
        break;

        case MCU_ECM:
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Reset is due to ECM Error */
        /* Get only internal reset enabled Ecm error status data  */
        LulEcmStatusData0 = (uint32)(MCU_ECMMESSTR0 &
                              Mcu_GpEcmSetting->ulEcmInternalResetReg0value);
        /* END Msg(4:0303)-2 */

        /* MISRA Violation: START Msg(4:0303)-2 */
        LulEcmStatusData1 = (uint32)(MCU_ECMMESSTR1 &
                              Mcu_GpEcmSetting->ulEcmInternalResetReg1value);
        /* END Msg(4:0303)-2 */

        /* Check multiple reset reason, if yes return unknown reset */
        if ((MCU_ZERO != LulEcmStatusData0) && (MCU_ZERO != LulEcmStatusData1))
        {
          /* if Multiple reset reason return unknown */
          LddResetSource = MCU_RESET_UNKNOWN;
        }
        /* If any reset has occurred in the mentioned registers */
        else if (MCU_ZERO != LulEcmStatusData0)
        {
          /* Check reset occurred under ECM config reg 0 */
          switch (LulEcmStatusData0)
          {
            case MCU_WDG_RSTBIT:
            LddResetSource = MCU_WATCHDOG_RESET;
            break;

            case MCU_LOCKSTEP_RSTBIT:
            LddResetSource = MCU_LOCK_STEP_CORE_RST;
            break;

            case MCU_CLMA0_UPLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA0_UPPER_LIMIT_RST;
            break;

            case MCU_CLMA0_LOLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA0_LOWER_LIMIT_RST;
            break;

            case MCU_CLMA2_UPLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA2_UPPER_LIMIT_RST;
            break;

            case MCU_CLMA2_LOLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA2_LOWER_LIMIT_RST;
            break;

            case MCU_CLMA1_UPLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA1_UPPER_LIMIT_RST;
            break;

            case MCU_CLMA1_LOLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA1_LOWER_LIMIT_RST;
            break;

            case MCU_CLMA3_UPLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA3_UPPER_LIMIT_RST;
            break;

            case MCU_CLMA3_LOLIMIT_RSTBIT:
            LddResetSource = MCU_CLMA3_LOWER_LIMIT_RST;
            break;

            case MCU_LRAM_ECC2_ADDPTY_RSTBIT:
            LddResetSource = MCU_LRAM_ECC2_ADDPTY_RST;
            break;

            case MCU_CACHE_RAM_RSTBIT:
            LddResetSource = MCU_CASHE_RAM_ECC2_RST;
            break;

            case MCU_CFLH_ECC2_ADDPTY_RSTBIT:
            LddResetSource = MCU_CFLH_ECC2_ADDPTY_RST;
            break;

            case MCU_DATA_FLSH_ECC2_RSTBIT:
            LddResetSource = MCU_DATA_FLSH_ECC2_RST;
            break;

            case MCU_DTS_RAM_ECC2_RSTBIT:
            LddResetSource = MCU_DTS_RAM_ECC2_RST;
            break;

            case MCU_CSIH_RAM_ECC2_RSTBIT:
            LddResetSource = MCU_CSIH_RAM_ECC2_RST;
            break;

            case MCU_CAN_RAM_ECC2_RSTBIT:
            LddResetSource = MCU_CAN_RAM_ECC2_RST;
            break;

            case MCU_FLXR_RAM_ECC2_RSTBIT:
            LddResetSource = MCU_FLXR_RAM_ECC2_RST;
            break;

            case MCU_MODE0_RSTBIT:
            LddResetSource = MCU_MODE0_RST;
            break;

            case MCU_MODE1_RSTBIT:
            LddResetSource = MCU_MODE1_RST;
            break;

            case MCU_MODE2_RSTBIT:
            LddResetSource = MCU_MODE2_RST;
            break;

            case MCU_PEGUARD_RSTBIT:
            LddResetSource = MCU_PEGUARD_RST;
            break;

            case MCU_PBUSGUARD_RSTBIT:
            LddResetSource = MCU_PBUSGUARD_RST;
            break;

            case MCU_SAR_ADC_RSTBIT:
            LddResetSource = MCU_SAR_ADC_PTY_RST;
            break;

            case MCU_BUS_DATA_PRTY_RSTBIT:
            LddResetSource = MCU_DATA_PRTY_RST;
            break;

            case MCU_ECM_COMP_RSTBIT:
            LddResetSource = MCU_ECM_COMP_RST;
            break;

            case MCU_LVI_RSTBIT:
            LddResetSource = MCU_LVI_RST;
            break;

            case MCU_TEMP_SENSE_RSTBIT:
            LddResetSource = MCU_TEMP_SENSE_RST;
            break;

            default:
            /* Reset is due to unknown source */
            LddResetSource = MCU_RESET_UNKNOWN;
            break;
          }
        }
        else if (MCU_ZERO != LulEcmStatusData1)
        {
          /* Check reset occurred under ECM config reg 1 */
          switch (LulEcmStatusData1)
          {
            case MCU_DMA_RSTBIT:
            LddResetSource = MCU_DMA_TRANSF_RST;
            break;

            case MCU_DMA_REG_PROTECT_RSTBIT:
            LddResetSource = MCU_DMA_REG_PROTECT_RST;
            break;

            case MCU_LRAM_ECC1_PTY_RSTBIT:
            LddResetSource = MCU_LRAM_ECC1_PTY_RST;
            break;

            case MCU_CFLH_ECC1_RSTBIT:
            LddResetSource = MCU_CFLH_ECC1_RST;
            break;

            case MCU_DATA_FLSH_ECC1_RSTBIT:
            LddResetSource = MCU_DATA_FLSH_ECC1_RST;
            break;

            case MCU_DTS_RAM_ECC1_RSTBIT:
            LddResetSource = MCU_DTS_RAM_ECC1_RST;
            break;

            case MCU_ALL_PERI_RAM_ECC1_RSTBIT:
            LddResetSource = MCU_ALL_PERI_RAM_ECC1_RST;
            break;

            case MCU_BIST_ECC1_RSTBIT:
            LddResetSource = MCU_BIST_ECC1_RST;
            break;

            case MCU_BIST_ECC2_RSTBIT:
            LddResetSource = MCU_BIST_ECC2_RST;
            break;

            case MCU_FACI_TRANSF_RSTBIT:
            LddResetSource = MCU_FACI_TRANSF_RST;
            break;

            case MCU_ECM_DELY_OVRFLW_RSTBIT:
            LddResetSource = MCU_ECM_DELY_OVRFLW_RST;
            break;

            default:
            /* Reset is due to unknown source */
            LddResetSource = MCU_RESET_UNKNOWN;
            break;
          }
        }
        else
        {
          /* No action required */
        }

        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Clear the status registers */
        if (MCU_ZERO != (MCU_ECMMESSTR0 & MCU_ECMMESSTR0_FULL_MASK))
        {
        /* END Msg(4:0303)-2 */
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
          #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* write the value to ECMESSTC0 register */
          Mcu_ProtectedWriteRetNone(MCU_ECMESSTC0, MCU_ECMMESSTR0_FULL_MASK,
                     MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
          /* END Msg(4:0303)-2 */


          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
          #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
        }
        else
        {
          /* No action required */
        }

        /* MISRA Violation: START Msg(4:0303)-2 */
        if (MCU_ZERO != (MCU_ECMMESSTR1 & MCU_ECMMESSTR1_FULL_MASK))
        {
        /* END Msg(4:0303)-2 */
          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_ENTER_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
          #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */

          /* Initialize the retry count to config value */
          LucRetryCount = MCU_LOOPCOUNT;

          /* MISRA Violation: START Msg(4:0303)-2 */
          /* write the value to ECMESSTC1 register */
          Mcu_ProtectedWriteRetNone(MCU_ECMESSTC1, MCU_ECMMESSTR1_FULL_MASK,
                     MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount)
          /* END Msg(4:0303)-2 */

          #if (MCU_CRITICAL_SECTION_PROTECTION == STD_ON)
          MCU_EXIT_CRITICAL_SECTION(MCU_REGISTER_PROTECTION);
          #endif /* (MCU_CRITICAL_SECTION_PROTECTION == STD_ON) */
        }
        else
        {
          /* No action required */
        }
        break;

        case MCU_SWR:
        /* Software reset */
        LddResetSource = MCU_SW_RESET;
        break;

        default:
        /* Reset is due to unknown source */
        LddResetSource = MCU_RESET_UNKNOWN;
        break;
      }

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Save the RESF register before clearing, for next call */
      /* TRACE [R4, MCU235] */
      /* TRACE [R4, MCU006] */
      Mcu_GulMcuSavedResfStatus = (uint32)MCU_RESF;
      /* END Msg(4:0303)-2 */

      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear Reset factor register */
      MCU_RESFC = MCU_RESF_CLEAR;
      /* END Msg(4:0303)-2 */

    }
    else if (MCU_THREE == Mcu_GpConfigPtr->ulCvmResetEnableReg)
    {
      /* MISRA Violation: START Msg(4:0303)-2 */
      /*Check CVMF status for low or high voltage detection */
      if (MCU_ZERO != (MCU_CVMF & MCU_THREE))
      /* END Msg(4:0303)-2 */
      {
        /* Get the reset reason value for power on reset */
        LddResetSource = MCU_CVM_RST;

        /* Initialize the retry count to config value */
        LucRetryCount = MCU_LOOPCOUNT;
        LucWriteData = MCU_CVM_CLEAR;
        /* MISRA Violation: START Msg(4:0303)-2 */
        /* Clear CVMF status*/
        Mcu_ProtectedWriteRetNone(MCU_CVMFC, LucWriteData,
                                  MCU_PROTCMDCVM, MCU_PROTSCVM, LucRetryCount)
        /* END Msg(4:0303)-2 */

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

    /* Save the reset status */
    /* TRACE [R4, MCU005] */
    Mcu_GulLastResetReasonStatus = (uint32) LddResetSource;

    /* Update reset saved status to true */
    Mcu_GblResetStatusSaved = MCU_TRUE;
  }
  else
  {
    /* No action required */
  }
}

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
/******************************************************************************
** Function Name      : Mcu_ClearEcmErrorOutput
**
** Service ID         : None
**
** Description        : This service is used to make error out put as inactive
**                      during the ECM self diagnostic function call
**
** Sync/Async         : Synchronous
**
** Reentrancy         : Non-Reentrant
**
** Input Parameters   : None
**
** InOut Parameters   : None
**
** Output Parameters  : none
**
** Return parameter   : Std_ReturnType
**
** Preconditions      : None
**
** Global Variables   : None
**
** Function Invoked   : Dem_ReportErrorStatus, Mcu_ProtectedWrite
**
** Registers Used     : ECMEMK0, ECMMESSTR0, ECMCESSTR0, ECMEMK1, ECMMESSTR1,
**                      ECMCESSTR1, ECMESSTC1, ECMEMK0HH, ECMMICFG0HH,
**                      ECMNMICFG0HH, ECMIRCFG0HH, ECMMECLR, ECMMPCMD0,
**                      ECMCECLR, ECMCPCMD0, ECMESSTC0, ECMPCMD1, ECMPS, ECMPE0
**                      ECMPE1
******************************************************************************/
#if (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON)

/*To use Private Code section in the Memory*/
#define MCU_START_SEC_PRIVATE_CODE
#include "MemMap.h"

STATIC FUNC(Std_ReturnType, MCU_PRIVATE_CODE) Mcu_ClearEcmErrorOutput (void)
{

  VAR(Std_ReturnType, AUTOMATIC) LenReturnValue;
  VAR(uint8, AUTOMATIC) LucRetryCount;
  VAR(uint8, AUTOMATIC) LucIndex;

  /* Initialize the return value */
  LenReturnValue = E_OK;


  /* Setting the error signal from the error pin to the high level
   * (inactive) for next test
   */
  LucIndex = MCU_ZERO;

  do
  {
    /* Initialize the retry count to config value */
    LucRetryCount = MCU_LOOPCOUNT;

    switch (LucIndex)
    {
      case MCU_ZERO:


      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear the status register */
      if (MCU_ZERO != (MCU_ECMMESSTR0 & MCU_ECMMESSTR0_FULL_MASK))
      {
        Mcu_ProtectedWrite(MCU_ECMESSTC0, MCU_ECMMESSTR0_FULL_MASK,
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      }
      else
      {
        /* No action required */
      }
      if (MCU_ZERO != (MCU_ECMMESSTR1 & MCU_ECMMESSTR1_FULL_MASK))
      {
        Mcu_ProtectedWrite(MCU_ECMESSTC1, MCU_ECMMESSTR1_FULL_MASK,
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      }
      else
      {
        /* No action required */
      }
      /* END Msg(4:0303)-2 */

      break;

      case MCU_ONE:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable Error Output by setting the ECMIE029 bit of the
       * ECMEMK0 register to disabled.
       */
      Mcu_ProtectedWrite(MCU_ECMEMK0, (MCU_ECMEMK0 | MCU_ECM029_MASK_VALUE),
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      break;

      case MCU_TWO:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable MI by setting the ECMIE029 bit of the ECMMICFG0
       * register to disabled.
       */
      Mcu_ProtectedWrite(MCU_ECMMICFG0,
        (MCU_ECMMICFG0 & (~MCU_ECM029_MASK_VALUE)),
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      break;

      case MCU_THREE:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable NMI by setting the ECNMIE029 bit of the ECMNMICFG0
       * reg to disabled.
       */
      Mcu_ProtectedWrite(MCU_ECMNMICFG0,
        (MCU_ECMNMICFG0 & (~MCU_ECM029_MASK_VALUE)),
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      break;

      case MCU_FOUR:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Disable an internal reset by setting the ECMIRE029 bit of
       * the ECMIRCFG0 register to disabled.
       */
      Mcu_ProtectedWrite(MCU_ECMIRCFG0,
          (MCU_ECMIRCFG0 & (~MCU_ECM029_MASK_VALUE)),
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      break;

      case MCU_FIVE:
      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Set the output level from the error pin to the inactive
       * (high) level
       */
      Mcu_ProtectedWrite(MCU_ECMMECLR, MCU_ONE, MCU_ECMMPCMD0,
                          MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */

      /* Initialize the retry count to config value */
      LucRetryCount = MCU_LOOPCOUNT;

      /* MISRA Violation: START Msg(4:0303)-2 */
      Mcu_ProtectedWrite(MCU_ECMCECLR, MCU_ONE, MCU_ECMCPCMD0,
                          MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */
      break;

      case MCU_SIX:


      /* MISRA Violation: START Msg(4:0303)-2 */
      /* Clear error flags by setting the ECMCLSSE029 bit of the
       * ECMESSTC0 register
       */
      Mcu_ProtectedWrite(MCU_ECMESSTC0, MCU_ECM029_MASK_VALUE,
            MCU_ECMPCMD1, MCU_ECMPS, LucRetryCount, LenReturnValue)
      /* END Msg(4:0303)-2 */

      break;

      default:
      LenReturnValue = E_NOT_OK;
      break;
    }

    LucIndex++;
  } while ((LucIndex < MCU_SEVEN) && (E_OK == LenReturnValue));

  return(LenReturnValue);
  }

/*Exit Private Code section in the Memory*/
#define MCU_STOP_SEC_PRIVATE_CODE
#include "MemMap.h"
#endif /* (MCU_ECM_SELFDIAGNOSTIC_TEST == STD_ON) */
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
