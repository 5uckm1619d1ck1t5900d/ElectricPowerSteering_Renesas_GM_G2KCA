/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_PBTypes.h                                              */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post Build time Parameters      */
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
 * V1.0.1:  27-Sep-2012  : As per SCR 018, PORT_WRITE_ERROR_CLEAR_VAL is updated
 *
 * V1.0.2:  17-Oct-2012  : As per SCR 027, structures added for Port filter
 *                         functionality.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, following changes are made:
 *                         1. PORT_IOHOLD_MASK and PORT_IOHOLD_CLEAR
 *                         are updated.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  12-Mar-2013  : As per SCR 091 for mantis #9240, following changes
 *                         are made:
 *                         1. New union type 'Port_Pin_DioOrAltMode' and
 *                            new structure type
 *                            'Port_PinDioAltChangeableDetails' is declared to
 *                            support functionality of new APIs
 *                            'Port_SetToDioMode' and 'Port_SetToAlternateMode'.
 *                         2. Ex-tern for 'Port_GstSetDioAltPinDetails[]' array
 *                            is declared.
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11215 and #11895, following changes
 *                         are made:
 *                         1. Structure STag_Port_EDCRegs is added to have
 *                            digital Noise filter edge detect control
 *                            functionality.
 *                         2. Header and Environment sections are updated to
 *                            change the device name.
 *                         3. Pre-compile option PORT_DNFAEN_REG_AVAILABLE is
 *                            added to have DNFAnEN register for F1x variant.
 *                         4. Offset's for PODC, PDSC, JPODC, JPDSC, PPROTS,
 *                            PPCMD, JPPROTS, JPPCMD registers and PORT_MAX_MODE
 *                            macro are removed and same will be generated by
 *                            generation tool in Port_Cfg.h file.
 *                         5. Macro PORT_WRITE_ERROR_CLEAR_VAL is removed and
 *                            same will be generated by generation tool as
 *                            32-bit value for F1x and 8-bit value for E1x in
 *                            Port_Cfg.h file.
 *
 * V1.4.0:  04-Sep-2013  : As per CR 236 for mantis issues #12602, Pre-compile
 *                         option 'PORT_PINV_REG_AVAILABLE' is added to have
 *                         Port pin level inversion functionality.
 *
 * V1.4.1:  29-Dec-2013  : As per CR 338, definitions are added for
 *                         PORT_SET_PIN_MODE_API.
 *
 * V1.4.2:  04-Jan-2014  : As per CR 378 for mantis #19208, as part of merging
 *                         activity following changes are made:
 *                         1. Copyright information is updated.
 *                         2. Alternative modes for Port_SetPinMode() API are
 *                            removed.
 *
 * V1.4.3:  06-Mar-2014  : As per CR419, PORT_WORD_ZERO is added.
 *
 * V1.4.4:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, New structure 'STag_Port_DNFCKSRegs' is
 *                         added for digital filter.
 *
 * V1.4.5:  22-Aug-2014  : As per CR 570, following changes are made:
 *                         1. STag_Port_PinsDirChangeable is
 *                            modified to add new structure element
 *                            'ucPMSRRegIndex' to get PMSR index.
 *                         2. MISRA C Rule Violations are updated as per QAC
 *                            8.1.1.
 * V1.4.6:  28-Jan_2015  : As per mantis #24335,#24187 and #23493 following
 *                         changes are made :
 *                         1. STag_Port_PinModeChangeableGroups is modified
 *                            to add new structure element
 *                            'uint8 ucPIPCRegIndex' to get PIPC index.
 *                         2. Critical Section Macros are updated.
 *                         3. STag_Port_DNFARegs is modified to add new
 *                            structure element 'usDelay' for Digital Filter
 *                         4. STag_Port_PinDioAltChangeableDetails is modified
 *                            to add new structure element
 *                            'uint8 ucPortPIPCIndex' to get PIPC index.
 *                         5. Copyright information is updated.
 * 1.4.7     12-Feb-2015   As per merge activity(#26024), the macro
 *                         PORT_LSB_MASK is added
 */
/******************************************************************************/
#ifndef PORT_PBTYPES_H
#define PORT_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for module version information */
#include "Port.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define PORT_PBTYPES_AR_RELEASE_MAJOR_VERSION  PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_PBTYPES_AR_RELEASE_MINOR_VERSION  PORT_AR_RELEASE_MINOR_VERSION
#define PORT_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                            PORT_AR_RELEASE_REVISION_VERSION

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define PORT_PBTYPES_AR_MAJOR_VERSION  PORT_AR_MAJOR_VERSION_VALUE
#define PORT_PBTYPES_AR_MINOR_VERSION  PORT_AR_MINOR_VERSION_VALUE
#define PORT_PBTYPES_AR_PATCH_VERSION  PORT_AR_PATCH_VERSION_VALUE
#endif
/* File version information */
#define PORT_PBTYPES_SW_MAJOR_VERSION  PORT_SW_MAJOR_VERSION
#define PORT_PBTYPES_SW_MINOR_VERSION  PORT_SW_MINOR_VERSION

/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:0750) A union type specifier has been defined.          */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : union type specifier is used to achieve better throughput. */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:0750)-1 and END Msg(4:0750)-1         */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 2. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3453) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : function macro is used for critical section protection.    */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3453)-2 and END Msg(4:3453)-2         */
/*                 tags in the code.                                          */

/******************************************************************************/

/* 3. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3684) Macro defines a braced code statement block.      */
/*Rule           : MISRA-C:2004 Rule 17.4                                     */
/*Justification  : Subscripting cannot be applied on the array since size can */
/*                 grow based on configuration done by user i.e. multi        */
/*                 configuration                                              */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3684)-3 and END Msg(4:3684)-3         */
/*                 tags in the code.                                          */

/******************************************************************************/
/******************************************************************************/

/* 4. MISRA C RULE VIOLATION:                                                 */
/*Message        : (4:3412) A function could probably be used instead of this */
/*                 function-like macro.                                       */
/*Rule           : MISRA-C:2004 Rule 19.4                                     */
/*Justification  : An additional semi-colon is added to the critical section  */
/*                 macro to avoid static analysis warning.                    */
/*Verification   : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/*Reference      : Look for START Msg(4:3412)-4 and END Msg(4:3412)-4         */
/*                 tags in the code.                                          */

/******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* General defines */
#define PORT_DBTOC_VALUE               ((PORT_VENDOR_ID_VALUE << 22) | \
                                        (PORT_MODULE_ID_VALUE << 14) | \
                                        (PORT_SW_MAJOR_VERSION_VALUE << 8) | \
                                        (PORT_SW_MINOR_VERSION_VALUE << 3))
#define PORT_ZERO                      (uint8)0x00
#define PORT_ONE                       (uint8)0x01
#define PORT_TEN                       (uint8)0x0A
#define PORT_MODE_MASK                 (uint8)0x1F
#define SET_PIPC_MIN_MODE              (uint8)0x82
#define PORT_UNINITIALIZED             (boolean)0x00
#define PORT_INITIALIZED               (boolean)0x01
#define PORT_REG_NOTAVAILABLE          (uint8)0xFF

#define PORT_MSB_MASK                  (uint32)0xFFFF0000ul
#define PORT_LSB_MASK                  (uint32)0x0000FFFFul


#define PORT_IOHOLD_MASK                (uint32)0x00000001ul
#define PORT_IOHOLD_CLEAR               (uint32)0x00000000ul

#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_DIO_OUT                   (Port_PinModeType)0x00
#define PORT_DIO_IN                    (Port_PinModeType)0x01
#endif

#define PORT_MODE_ADJUST               (Port_PinModeType)0x0E

#define PORT_TRUE                      (boolean)0x01
#define PORT_FALSE                     (boolean)0x00

#define PORT_INV_NOT_CFG               (uint16)0xFFFF
#define PORT_WORD_ZERO                 (uint16)0x0000

#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)

#define PORT_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                              SchM_Enter_Port_##Exclusive_Area()
#define PORT_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                              SchM_Exit_Port_##Exclusive_Area()

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* MISRA Violation: START Msg(4:3412)-4 */
#define PORT_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                                          SchM_Enter_Port(Exclusive_Area);
#define PORT_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                                          SchM_Exit_Port(Exclusive_Area);
#endif
/* END Msg(4:3412)-4 */

/*******************************************************************************
**  Global symbols used for For verifying the Modes
*******************************************************************************/
#define PORT_BIT4_MASK                 (uint8)0x10   /* For PMC */
#define PORT_BIT3_MASK                 (uint8)0x08   /* For PFCAE */
#define PORT_BIT2_MASK                 (uint8)0x04   /* For PFCE */
#define PORT_BIT1_MASK                 (uint8)0x02   /* For PFC */
#define PORT_BIT0_MASK                 (uint8)0x01   /* For PM */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Type definition for Port Group types */
typedef enum ETag_Port_GroupType
{
  PORT_GROUP_NUMERIC,
  PORT_GROUP_ALPHABETIC,
  PORT_GROUP_JTAG,
  PORT_GROUP_ANALOG,
  PORT_GROUP_INPUT

} Port_GroupType;

/* MISRA Violation: START Msg(4:0750)-1 */
/* Type definition for 32-bit PMSR register */
typedef union UTag_Port_Pin_Direction
{
  /* Full Word */
  uint32 ulRegContent;
/* END Msg(4:0750)-1 */
  struct
  {
    /* Lower Word */
    uint16 usLSWord;
    /* Higher Word */
    uint16 usMSWord;
  }Tst_Port_Word;
} Port_Pin_Direction;

/* MISRA Violation: START Msg(4:0750)-1 */
/* Type definition for 32-bit PMCSR register */
typedef union UTag_Port_Pin_DioOrAltMode
{
  /* Full Word */
  uint32 ulRegContent;
/* END Msg(4:0750)-1 */
  struct
  {
    /* Lower Word */
    uint16 usLSWord;
    /* Higher Word */
    uint16 usMSWord;
  }Tst_Port_Word;
} Port_Pin_DioOrAltMode;

/*******************************************************************************
** Structure declaration of port group registers, except PMSR, PFCE, PFC      **
** and PMCSR.                                                                 **
** This structure will be generated in the following sequence of registers:   **
** PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.             **
*******************************************************************************/
typedef struct STag_Port_Regs
{
  /* Offset value of the register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured value of the port group registers for initial mode. */
  uint16 usInitModeRegVal;
} Port_Regs;

/*******************************************************************************
** Structure declaration of PFCE, PFC and PMCSR port group registers          **
** This structure will be generated in the following sequence of registers:   **
** PFCE, PFC and PMCSR.                                                       **
*******************************************************************************/
typedef struct STag_Port_FuncCtrlRegs
{
  /*
   * Offset value of the register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured value of the port group registers for initial mode. */
  uint16 usInitModeRegVal;
} Port_FuncCtrlRegs;

/*******************************************************************************
** Structure declaration of PMSR registers for all port groups                **
*******************************************************************************/
typedef struct STag_Port_PMSRRegs
{
  /* Bit value of upper 16 bits (31 - 16) is to set 0 if for pin
   * "PortPinDirectionChangeable" is configured as true
   * Bit value of upper 16 bits (31 - 16) is to set 1 if for pin
   * "PortPinDirectionChangeable" configured as false
   * Bit value of lower 16 bits (15 - 0) = Initial value of the corresponding
   * pin
   */
  uint32 ulMaskAndConfigValue;
  /* Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usRegAddrOffset;
  /* Configured PMSR Register value for initial mode */
  uint16 usInitModeRegVal;
} Port_PMSRRegs;

/*******************************************************************************
** Structure containing information on PINs whose direction can be changed    **
** during run time                                                            **
*******************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
typedef struct STag_Port_PinsDirChangeable
{
  /* The PIN number whose direction is configured as changeable at run time */
  Port_PinType ddPinId;
  /* Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPMSRRegAddrOffset;
  /*
   * Offset value of the PSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPSRRegAddrOffset;
  #if (PORT_PINV_REG_AVAILABLE == STD_ON)
  /* Offset value of the PMSR register address. This value of any register, when
   * added to the base address, gives the address of that particular register.
   */
  uint16 usPINVRegAddrOffset;
  /* Configured level value for PSR register */
  uint16 usPortinversionVal;
  /* Index of the structure array Port_GstNumFuncCtrlRegs[], which provide the
   * information of the PMCSR register of the port group to which this pin
   * belongs.
   */
  uint8 ucPortGroupIndex;
  #endif /* End of PORT_PINV_REG_AVAILABLE == STD_ON */
  /* Mask value to check whether the requested direction and current direction
   * of the PIN are same.
   */
  uint16 usOrMaskVal;
  /* Configured level value for PSR register */
  uint16 usChangeableConfigVal;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG/ Analog) */
  uint8 ucPortType;
  /* Index of PMSR register in the structure array of PMSR registers.*/
  uint8 ucPMSRRegIndex;
} Port_PinsDirChangeable;
#endif /* End of PORT_SET_PIN_DIRECTION_API == STD_ON */

/*******************************************************************************
** Structure contains information about the port groups, containing the PINs  **
** whose mode can be changed during run time.                                 **
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
typedef struct STag_Port_PinModeChangeableGroups
{

  /* Index of the PSR register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPSRRegIndex;
  /* Index of the PFCE register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCERegIndex;
  /* Index of the PFC register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCRegIndex;
  /* Index of the PFCAE register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPFCAERegIndex;
  /* Index of the PMCSR register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPMCSRRegIndex;
  /* Index of PMSR register in the structure array of PMSR registers.*/
  uint8 ucPMSRRegIndex;
  /* Index of the PIPC register in the structure array, where all port group
   * registers, except PMSR, are generated.
   */
  uint8 ucPIPCRegIndex;
} Port_PinModeChangeableGroups;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains details of PINs whose mode can be changed during run    **
** time.                                                                      **
*******************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
typedef struct STag_Port_PinModeChangeableDetails
{
  /* The PIN number whose mode is configured as changeable at run time. */
  Port_PinType ddPinId;
  /* Or mask value of the port pin */
  uint16 usOrMask;
  /* Index of the structure array which provide the information of port groups,
   * containing the PINs whose mode can be changed during run time
   */
  uint8 ucSetModeIndex;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG/ Analog/ Input)  */
  uint8 ucPortType;
} Port_PinModeChangeableDetails;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains details of PINs whose mode can be changed to DIO or     **
** alternate mode during runtime.                                             **
*******************************************************************************/
#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
typedef struct STag_Port_PinDioAltChangeableDetails
{
  /* The PIN number whose mode is configured as changeable at run time. */
  Port_PinType ddPinId;
  /* Or mask value of the port pin */
  uint16 usOrMask;
  /* Index of the structure array Port_GstNumFuncCtrlRegs[], which provide the
   * information of the PMCSR register of the port group to which this pin
   * belongs.
   */
  uint8 ucPortGroupIndex;
  /* Indicates the Port type (Numeric/ Alphabetic/ JTAG/ Analog/ Input)  */
  uint8 ucPortType;
  /* Index of the PIPC register in the structure array */
  uint8 ucPortPIPCIndex;
} Port_PinDioAltChangeableDetails;
#endif /* End of PORT_SET_PIN_MODE_API == STD_ON */

/*******************************************************************************
** Structure contains the declaration for DNFA registers                      **
** This structure will be generated in the following sequence of registers:   **
** DNFAnCTL, DNFAnEN.                                                         **
*******************************************************************************/
typedef struct STag_Port_DNFARegs
{
  /* Offset value of the DNFACTL register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usDNFARegAddrOffset;
  #if (PORT_DNFAEN_REG_AVAILABLE == STD_ON)
  /* Configured value for DNFA noise elimination enable register */
  uint16 usDNFAEN;
  #endif /* End of PORT_DNFAEN_REG_AVAILABLE == STD_ON */
  /* Configured value for DNFA noise elimination control register */
  uint8 ucDNFACTL;

  uint16 usDELAY;
} Port_DNFARegs;

/*******************************************************************************
** Structure contains the declaration for EDC  registers                      **
** This structure will be generated in the following sequence of registers:   **
** DNFnEDCm.                                                                  **
*******************************************************************************/
#if (PORT_EDGE_DETECT_CONTROL == STD_ON)
typedef struct STag_Port_EDCRegs
{
  /* Offset value of the DNFEDC register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usDNFEDCRegAddrOffset;
  /* Configured value for DNFEDC edge detection control register */
  uint8 ucDNFEDC;
} Port_EDCRegs;
#endif /* End of PORT_EDGE_DETECT_CONTROL == STD_ON */

/*******************************************************************************
** Structure contains the declaration for FCLA registers                      **
** This structure will be generated in the following sequence of registers:   **
** FCLAnCTL.                                                                  **
*******************************************************************************/
typedef struct STag_Port_FCLARegs
{
  /* Offset value of the FLCACTL register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usFCLARegAddrOffset;
  /* Configured value for FCLA noise elimination control register */
  uint8 ucFCLACTL;
} Port_FCLARegs;

/*******************************************************************************
** Structure contains the declaration for DNFCKS register                     **
** This structure will be generated in the following sequence                 **
*******************************************************************************/
#if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
typedef struct STag_Port_DNFCKSRegs
{
  /* Configured value for DNFA noise elimination control register */
  uint32 ulDNFCKS;
  /* Offset value of the DNFCKS register address. This value of any register,
   * if added to the base address, gives the address of that particular register
   */
  uint16 usDNFCKSRegAddrOffset;
} Port_DNFCKSRegs;
#endif /* End of PORT_DNF_CLK_SRC_AVAILABLE == STD_ON */

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-3 */
#if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_Regs, PORT_CONST) Port_GstNumRegs[];
extern CONST(Port_FuncCtrlRegs, PORT_CONST) Port_GstNumFuncCtrlRegs[];
extern CONST(Port_PMSRRegs, PORT_CONST) Port_GstNumPMSRRegs[];
#endif

#if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_Regs, PORT_CONST) Port_GstAlphaRegs[];
extern CONST(Port_FuncCtrlRegs, PORT_CONST) Port_GstAlphaFuncCtrlRegs[];
extern CONST(Port_PMSRRegs, PORT_CONST) Port_GstAlphaPMSRRegs[];
#endif

#if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_Regs, PORT_CONST) Port_GstJTAGRegs[];
extern CONST(Port_FuncCtrlRegs, PORT_CONST) Port_GstJTAGFuncCtrlRegs[];
extern CONST(Port_PMSRRegs, PORT_CONST) Port_GstJTAGPMSRRegs[];
#endif

#if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_Regs, PORT_CONST) Port_GstAnalogRegs[];
extern CONST(Port_PMSRRegs, PORT_CONST) Port_GstAnalogPMSRRegs[];
#endif

#if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
extern CONST(Port_Regs, PORT_CONST) Port_GstInputRegs[];
#endif

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
extern CONST(Port_PinsDirChangeable, PORT_CONST)
                                  Port_GstPinDirChangeableList[];
#endif

#if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
extern CONST(Port_PinDioAltChangeableDetails, PORT_CONST)
                                                Port_GstSetDioAltPinDetails[];
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)
extern CONST(Port_PinModeChangeableGroups, PORT_CONST)
                                  Port_GstSetModeGroupsList[];
extern CONST (Port_PinModeChangeableDetails, PORT_CONST)
                                  Port_GstSetModePinDetailsList[];
#endif

extern CONST(Port_DNFARegs, PORT_CONST) Port_GstDNFARegs[];
extern CONST(Port_FCLARegs, PORT_CONST) Port_GstFCLARegs[];

#if (PORT_EDGE_DETECT_CONTROL == STD_ON)
extern CONST(Port_EDCRegs, PORT_CONST) Port_GstEDCRegs[];
#endif

#if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
extern CONST(Port_DNFCKSRegs, PORT_CONST) Port_GstDNFCKSRegs[];
#endif
/* END Msg(4:3684)-3 */

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if (PORT_DEM_ERROR_DETECT == STD_ON)
#if (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
  #define PORT_DEM_TYPE uint8
#else
  #define PORT_DEM_TYPE Dem_EventStatusType
#endif
#endif

#endif /* PORT_PBTYPES_H  */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
