/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Port_Types.h                                                */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  30-Aug-2012  : Initial Version
 *
 * V1.0.1:  17-Oct-2012  : As per SCR 027, STag_Port_ConfigType structure is
 *                         updated to add filter registers.
 *
 * V1.1.0:  16-Jan-2013  : As per SCR 055, following changes are made:
 *                         1. STag_Port_ConfigType structure is
 *                         updated.
 *                         2. Copyright information is updated.
 *
 * V1.2.0:  12-Mar-2013  : As per SCR 091 for mantis #9240, new structure
 *                         elements 'pPinDioAltModeDetails' and
 *                         'ucNoOfPinsDioAltModeChangeable' are added in
 *                         STag_Port_ConfigType structure.
 *
 * V1.3.0:  05-Aug-2013  : As per CR 225, as part of merging activity and mantis
 *                         issues #11827, #11215 and #11895, following changes
 *                         are made:
 *                         1. Header and Environment sections are updated to
 *                            change the device name.
 *                         2. Pre-compile option PORT_EDGE_DETECT_CONTROL is
 *                            added to have digital Noise filter edge detect
 *                            control functionality.
 *
 * V1.3.1:  25-Jul-2014  : As per CR 563 for mantis #22811, as part of merging
 *                         activity, new structure elements 'pPortDNFCKSRegs'
 *                         and 'ucNoOfDNFCKSRegs' are added in
 *                         STag_Port_ConfigType structure.
 */
/******************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
/* Included for pre-compile options */
/* TRACE [R3, PORT130][R4, PORT130] */
#include "Port_Cfg.h"

/*******************************************************************************
**                        Version Information                                 **
*******************************************************************************/
#if (PORT_AR_VERSION == PORT_AR_HIGHER_VERSION)
/* Functionality related to R4.0 */
/* AUTOSAR release version information */
#define PORT_TYPES_AR_RELEASE_MAJOR_VERSION    PORT_AR_RELEASE_MAJOR_VERSION
#define PORT_TYPES_AR_RELEASE_MINOR_VERSION    PORT_AR_RELEASE_MINOR_VERSION
#define PORT_TYPES_AR_RELEASE_REVISION_VERSION \
                                     PORT_AR_RELEASE_REVISION_VERSION

#elif (PORT_AR_VERSION == PORT_AR_LOWER_VERSION)
/* Functionality related to R3.2 */
#define PORT_TYPES_AR_MAJOR_VERSION  PORT_AR_MAJOR_VERSION_VALUE
#define PORT_TYPES_AR_MINOR_VERSION  PORT_AR_MINOR_VERSION_VALUE
#define PORT_TYPES_AR_PATCH_VERSION  PORT_AR_PATCH_VERSION_VALUE
#endif

/* Module Software version information */
#define PORT_TYPES_SW_MAJOR_VERSION    PORT_SW_MAJOR_VERSION
#define PORT_TYPES_SW_MINOR_VERSION    PORT_SW_MINOR_VERSION

/*******************************************************************************
**                      GLOBAL DATA TYPES                                     **
*******************************************************************************/
/* Structure for Port Init Configuration */
/* TRACE [R3, PORT073][R4, PORT073] */
/* TRACE [R3, PORT072][R4, PORT072] */
/* TRACE [R3, PORT072][R4, PORT072] */
/* Overall Module Configuration Data Structure */
typedef struct STag_Port_ConfigType
{
  /* Database start value - 0x0EDF0400 */
  uint32 ulStartOfDbToc;

  #if (PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Numeric Port Group registers in sequence: PSR,
   * PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(struct STag_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) pPortNumRegs;

  /* Pointer to structure of Numeric Function Control Port Group registers
   * in sequence: PFCE, PFC, PFCAE and PMCSR
   */
  P2CONST(struct STag_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortNumFuncCtrlRegs;

  /* Pointer to structure of Numeric PMSR Port Group registers */
  P2CONST(struct STag_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortNumPMSRRegs;
  #endif

  #if (PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Alphabetic Port Group registers in sequence:
   * PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(struct STag_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) pPortAlphaRegs;

  /* Pointer to structure of Alphabetic Function Control Port Group
   * registers in sequence: PFCE, PFC, PFCAE and PMCSR
   */
  P2CONST(struct STag_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortAlphaFuncCtrlRegs;

  /* Pointer to structure of Alphabetic PMSR Port Group registers */
  P2CONST(struct STag_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortAlphaPMSRRegs;
  #endif

  #if (PORT_JTAG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of JTAG Port Group registers in sequence:
   * PSR, PIS, PISE, PISA, PIBC, PIPC, PU, PD, PBDC, PODC and PDSC.
   */
  P2CONST(struct STag_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) pPortJRegs;

  /* Pointer to structure of JTAG Function Control Port Group registers in
   * sequence: PFCE, PFC, PFCAE and PMCSR
   */
  P2CONST(struct STag_Port_FuncCtrlRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortJFuncCtrlRegs;

  /* Pointer to structure of JTAG PMSR Port Group registers */
  P2CONST(struct STag_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortJPMSRRegs;
  #endif

  #if (PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Analog Port Group registers in sequence: PSR,
   * PIBC and PBDC.
   */
  P2CONST(struct STag_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) pPortAnalogRegs;

  /* Pointer to structure of Analog PMSR Port Group registers */
  P2CONST(struct STag_Port_PMSRRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPortAnalogPMSRRegs;
  #endif

  #if (PORT_INPUT_PORT_GROUPS_AVAILABLE == STD_ON)
  /* Pointer to structure of Input Port Group registers in sequence:PIBC.
   */
  P2CONST(struct STag_Port_Regs, AUTOMATIC, PORT_CONFIG_CONST) pPortInputRegs;
  #endif

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* TRACE [R3, PORT137] */
  /* TRACE [R4, PORT137] */
  /* Pointer to structure containing details about the pins whose direction
   * can be changed during run time
   */
  P2CONST(struct STag_Port_PinsDirChangeable, AUTOMATIC, PORT_CONFIG_CONST)
                                                       pPinDirChangeable;
  #endif

  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* Pointer to structure containing details about the port pin mode */
  P2CONST(struct STag_Port_PinModeChangeableGroups, AUTOMATIC,
                              PORT_CONFIG_CONST) pPinModeChangeableGroups;
  /* Pointer to structure containing details about the port pin mode */
  P2CONST(struct STag_Port_PinModeChangeableDetails, AUTOMATIC,
                              PORT_CONFIG_CONST) pPinModeChangeableDetails;
  #endif

  #if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
  /* Pointer to structure containing details about the port dio or alternate
   * pin mode
   */
  P2CONST(struct STag_Port_PinDioAltChangeableDetails, AUTOMATIC,
                              PORT_CONFIG_CONST) pPinDioAltModeDetails;
  #endif

  #if (PORT_EDGE_DETECT_CONTROL == STD_ON)
  /* Pointer to array of structure containing details about DNFA registers */
  P2CONST(struct STag_Port_EDCRegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                 pPortEDCRegs;
  #endif

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* Pointer to array of structure containing details about DNFA registers */
  P2CONST(struct STag_Port_DNFARegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                 pPortDNFARegs;
  #endif

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* Pointer to array of structure containing details about FCLA registers */
  P2CONST(struct STag_Port_FCLARegs, AUTOMATIC, PORT_CONFIG_CONST)
                                                 pPortFCLARegs;
  #endif

  #if (PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
  /* Pointer to array of structure containing details about DNFCKS registers */
  P2CONST(struct STag_Port_DNFCKSRegs, AUTOMATIC, PORT_CONFIG_DATA)
                                                            pPortDNFCKSRegs;
  #endif

  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* The Total number of Pins configured for Direction Change at run time. */
  uint8 ucNoOfPinsDirChangeable;
  #endif

  #if (PORT_SET_PIN_MODE_API == STD_ON)
  /* The Total number of Pins configured for Mode Change at run time. */
  uint8 ucNoOfPinsModeChangeable;
  #endif

  #if (PORT_SET_TO_DIO_ALT_MODE_API == STD_ON)
  /*
   * The Total number of Pins configured for Dio or Alternate Mode
   * changeable at run time.
   */
  uint8 ucNoOfPinsDioAltModeChangeable;
  #endif

  #if(PORT_DNFA_REG_CONFIG == STD_ON)
  /* The total number of DNFA noise elimination registers configured */
  uint8 ucNoOfDNFARegs;
  #endif

  #if(PORT_EDGE_DETECT_CONTROL == STD_ON)
  /* The total number of EDC registers configured */
  uint8 ucNoOfEDCRegs;
  #endif

  #if(PORT_FCLA_REG_CONFIG == STD_ON)
  /* The total number of FCLA noise elimination registers configured */
  uint8 ucNoOfFCLARegs;
  #endif

  #if(PORT_DNF_CLK_SRC_AVAILABLE == STD_ON)
  /* The total number of DNFCKS noise elimination registers configured */
  uint8 ucNoOfDNFCKSRegs;
  #endif

  #if ((PORT_NUM_PORT_GROUPS_AVAILABLE == STD_ON) && \
        (PORT_PIN_STATUS_BACKUP == STD_ON))
  /* The Total number of Numeric Restored registers configured */
  uint8 ucNoOfNumRestoredRegs;
  #endif

  #if ((PORT_ALPHA_PORT_GROUPS_AVAILABLE == STD_ON) && \
       (PORT_PIN_STATUS_BACKUP == STD_ON))
  /* The Total number of Alphabetic Restored registers configured */
  uint8 ucNoOfAlphaRestoredRegs;
  #endif

  #if ((PORT_ANALOG_PORT_GROUPS_AVAILABLE == STD_ON) && \
        (PORT_PIN_STATUS_BACKUP == STD_ON))
  /* The Total number of Jtag Restored registers configured */
  uint8 ucNoOfAnalogRestoredRegs;
  #endif

} Port_ConfigType;

#endif /* PORT_TYPES_H */

/*******************************************************************************
**                          End Of File                                       **
*******************************************************************************/
