/*============================================================================*/
/* Project      = AUTOSAR Renesas X1x MCAL Components                         */
/* Module       = Dio_Cfg.h                                                   */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2012-2014 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains pre-compile time parameters.                            */
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
/*              Devices:        X1x                                           */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  23-Aug-2012  : Initial Version
 * V1.0.1:  05-Mar-2013  : As per SCR 090, 
 *                         1. DIO_SW_PATCH_VERSION_VALUE macro is added.
 *                         2. In R4.0.3,CONFIG_HANDLES are updated.
 * V1.0.2:  08-Aug-2013  : As per CR 225, F1x is renamed to X1x.
 * V1.0.3:  02-Jan-2014  : As per CR 331, 
 *                         %BswHdrTpl::Precompile_Parameters and
 *                         %BswHdrTpl::Template_Hash are updated.
 * V1.0.4:  17-Mar-2014  : As per CR 413, 
 *                         1. DIO_CRITICAL_SECTION_PROTECTION Macro is added.
 *                         2. CONFIG_HANDLES are updated.
 * V1.0.5:  27-Jul-2014  : As per CR 103 and 563, following change is made:
 *                         1. Marker IDs are added newly.
 * V1.0.6:  02-Sep-2014  : As per CR 569, Changes are made at all relevant 
 *                         places accordingly to append U or UL unsigned values.
 */
/******************************************************************************/

/*******************************************************************************
**                   Generation Tool Version                                  **
*******************************************************************************/
/*
 * TOOL VERSION:  1.0.16
 */

/*******************************************************************************
**                          Input File                                        **
*******************************************************************************/
/*
 * INPUT FILE:    C:\_synergy\G2KCAT3_CZ8L9T\Dio\generate\R403_DIO_P1x_BSWMDT.arxml
 *                C:\Users\cz8l9t\AppData\Local\Temp\Cfg_Gen-1484837221603-8\AutosarFiles_ValGen-1484838501299-0\Dio_ECUC_4501856353292358394.arxml
 * GENERATED ON:  19 Jan 2017 - 10:08:45
 */


#ifndef DIO_CFG_H 
#define DIO_CFG_H  
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR release version information */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION  4U
#define DIO_CFG_AR_RELEASE_MINOR_VERSION  0U
#define DIO_CFG_AR_RELEASE_REVISION_VERSION  3U

/* File version information */
#define DIO_CFG_SW_MAJOR_VERSION   1U
#define DIO_CFG_SW_MINOR_VERSION   0U


/*******************************************************************************
**                       Common Published Information                         **
*******************************************************************************/

#define DIO_AR_RELEASE_MAJOR_VERSION_VALUE  4U
#define DIO_AR_RELEASE_MINOR_VERSION_VALUE  0U
#define DIO_AR_RELEASE_REVISION_VERSION_VALUE  3U

#define DIO_SW_MAJOR_VERSION_VALUE  1U
#define DIO_SW_MINOR_VERSION_VALUE  0U
#define DIO_SW_PATCH_VERSION_VALUE  9U

#define DIO_VENDOR_ID_VALUE  59U
#define DIO_MODULE_ID_VALUE  120U

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Instance ID of the DIO Driver */
#define DIO_INSTANCE_ID_VALUE               0U

/* Pre-compile option for Version information */
#define DIO_AR_VERSION                      DIO_AR_HIGHER_VERSION

/* TRACE [R4, DIO066] */
/* TRACE [R4, DIO142_Conf] */ 
/* TRACE [R4, DIO124] */ 
/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                STD_ON

/* TRACE [R4, DIO143_Conf] */
/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                STD_OFF

/* Pre-compile option for presence ofDio_MaskedWritePort API */
#define DIO_MASKED_WRITE_PORT_API           STD_OFF

/* TRACE [R4, DIO153_Conf] */
/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                STD_OFF

/* Pre-compile option for presence of Channel */
#define DIO_CHANNEL_CONFIGURED              STD_ON

/* Pre-compile option for presence of Channel Group */
#define DIO_CHANNELGROUP_CONFIGURED         STD_OFF

/* Pre-compile option for enable or disable version check of inter-module
   dependencies */
#define DIO_VERSION_CHECK_EXT_MODULES       STD_ON

/* Pre-compile option for critical section protection */
#define DIO_CRITICAL_SECTION_PROTECTION     STD_ON

/* Offset for getting PPR register address from PSR
    register address for Numeric and Alphabetic ports. */
#define DIO_PPR_OFFSET_NONJTAG              (uint8)0x02

/* Offset for getting PNOT register address 
    from PSR register address for Numeric and Alphabetic ports. */
#define DIO_PNOT_OFFSET_NONJTAG             (uint16)0x01

/* Offset for getting PPR register address from PSR 
    register address for JTAG ports  */
#define DIO_PPR_OFFSET_JTAG                 (uint8)0x02

/* Offset for getting JPNOT register address from JPSR
    register address for JTAG ports. */
#define DIO_PNOT_OFFSET_JTAG                (uint16)0x01

/* Offset for getting PMSR register address from PMSR 
    register address for JTAG ports  */
#define DIO_PMSR_OFFSET_JTAG                (uint16)0x07

/* Offset for getting PMSR register address from 
    PMSR register address for NONJTAG ports. */
#define DIO_PMSR_OFFSET_NONJTAG             (uint16)0x07


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Total number of configured ports */
#define DIO_MAXNOOFPORT                     (Dio_PortType)5

/* Total number of configured channels */
#define DIO_MAXNOOFCHANNEL                  (Dio_ChannelType)17

/* Configuration Set Handles */
#define DioConfig                           (&Dio_GstConfiguration[0])

/* DIO Port Configuration Handles */
#define DioConf_DioPort_Port0               (Dio_PortType)0
#define DioConf_DioPort_Port5               (Dio_PortType)1
#define DioConf_DioPort_Port4               (Dio_PortType)2
#define DioConf_DioPort_Port3               (Dio_PortType)3
#define DioConf_DioPort_Port2               (Dio_PortType)4

/* The Pointer to Port Group name */

/* DIO Channel Configuration Handles */
#define DioConf_DioChannel_PwrTurnOffCtrl   (Dio_ChannelType)0
#define DioConf_DioChannel_McuEna           (Dio_ChannelType)1
#define DioConf_DioChannel_EcuIdnPin2       (Dio_ChannelType)2
#define DioConf_DioChannel_TmplMonrWdg      (Dio_ChannelType)3
#define DioConf_DioChannel_MotAg0CsihCs     (Dio_ChannelType)4
#define DioConf_DioChannel_GateDrv0Rst      (Dio_ChannelType)5
#define DioConf_DioChannel_PhaALowrCmd      (Dio_ChannelType)6
#define DioConf_DioChannel_MotDrvr0Diag     (Dio_ChannelType)7
#define DioConf_DioChannel_PhaBLowrCmd      (Dio_ChannelType)8
#define DioConf_DioChannel_PhaBUpprCmd      (Dio_ChannelType)9
#define DioConf_DioChannel_PhaCLowrCmd      (Dio_ChannelType)10
#define DioConf_DioChannel_PhaCUpprCmd      (Dio_ChannelType)11
#define DioConf_DioChannel_PwrOutpEnaFb     (Dio_ChannelType)12
#define DioConf_DioChannel_MotAg1CsihCs     (Dio_ChannelType)13
#define DioConf_DioChannel_PhaAUpprCmd      (Dio_ChannelType)14
#define DioConf_DioChannel_SysFlt2A         (Dio_ChannelType)15
#define DioConf_DioChannel_EcuIdnPin1       (Dio_ChannelType)16

/* Channel Mapping for DioChannelBitPosition */
#define DioConfig_PwrTurnOffCtrl_bit        (uint8)0x0D
#define DioConfig_McuEna_bit                (uint8)0x08
#define DioConfig_EcuIdnPin2_bit            (uint8)0x0E
#define DioConfig_TmplMonrWdg_bit           (uint8)0x0A
#define DioConfig_MotAg0CsihCs_bit          (uint8)0x03
#define DioConfig_GateDrv0Rst_bit           (uint8)0x05
#define DioConfig_PhaALowrCmd_bit           (uint8)0x08
#define DioConfig_MotDrvr0Diag_bit          (uint8)0x04
#define DioConfig_PhaBLowrCmd_bit           (uint8)0x0A
#define DioConfig_PhaBUpprCmd_bit           (uint8)0x09
#define DioConfig_PhaCLowrCmd_bit           (uint8)0x0D
#define DioConfig_PhaCUpprCmd_bit           (uint8)0x0C
#define DioConfig_PwrOutpEnaFb_bit          (uint8)0x06
#define DioConfig_MotAg1CsihCs_bit          (uint8)0x03
#define DioConfig_PhaAUpprCmd_bit           (uint8)0x07
#define DioConfig_SysFlt2A_bit              (uint8)0x04
#define DioConfig_EcuIdnPin1_bit            (uint8)0x0D

/* The Pointer to Port Channel name */

/* DIO Channel Group Configuration Handles */
         
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* DIO_CFG_H  */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
