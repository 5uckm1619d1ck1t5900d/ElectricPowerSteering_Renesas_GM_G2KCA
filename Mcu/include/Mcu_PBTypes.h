/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x MCAL Components                         */
/* Module       = Mcu_PBTypes.h                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2013-2015 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the type definitions of Post-build Time Parameters      */
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
 *                        1. MCU_FIFTYSIX, MCU_ECMEMK1_OFFSET,
 *                           MCU_ECMPE1_OFFSET, MCU_ECMIRCFG1_OFFSET,
 *                           MCU_ECMNMICFG1_OFFSET, MCU_ECMMICFG1_OFFSET,
 *                           MCU_LOCKSTEP_DUMMY_VALUE is added.
 *                        2. MCU_MAX_ECMRAM_CONFIG, MCU_CVM_FACTOR_CLEAR values
 *                           are updated.
 *                        3. Union ConvertByte is removed since it is not used.
 *                        4. Macros are added for calculated delay count for two
 *                           sampling cycles in CLMA and MCU_CVM_DELAY_CNT is
 *                           added for 12us for CVM.
 *                        5. Macro name and value is updated for enabling
 *                           interrupt through IMR register.
 *
 * V1.0.2:  07-Oct-2014 : As per CR008 and mantis #19850, Following
 *                        changes are made,
 *                        1. Following macro values are updated
 *                           MCU_ECM029_MASK_VALUE, MCU_ECMEMK0_FULL_MASK
 *                           MCU_ECM_DELY_OVRFLW_RSTBIT, MCU_RAM_MASK0_VALUE,
 *                           MCU_ECMEMK1_FULL_MASK, MCU_RAM_MASK1_VALUE,
 *                           MCU_CLMA0_DELAY_CNT, MCU_CLMA1_DELAY_CNT,
 *                           MCU_CLMA2_DELAY_CNT, MCU_CLMA3_DELAY_CNT
 *                        2. Global RAM related macros are removed and
 *                           MCU_CVM_CLEAR is added.
 *                        3. Trace marking is added in the file.
 *
 * V1.0.3:  05-Dec-2014 : As per CR076 and mantis #25069,
 *                        Following changes are made,
 *                        1. 'MISRA C Rule Violations' section is updated for
 *                           Justification of misra rule 4:3684.
 *
 * V1.0.4:  28-Apr-2015 : Added code comments as per MO Review in Mantis
 *                        #27515
 */
/******************************************************************************/

#ifndef MCU_PBTYPES_H
/*Defining MCU_PBTYPES_H to avoid multiple inclusion*/
#define MCU_PBTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Included for Mcu type declarations */
#include "Mcu_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR release version information */
#define MCU_PBTYPES_AR_RELEASE_MAJOR_VERSION \
                                        MCU_TYPES_AR_RELEASE_MAJOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_MINOR_VERSION \
                                        MCU_TYPES_AR_RELEASE_MINOR_VERSION
#define MCU_PBTYPES_AR_RELEASE_REVISION_VERSION \
                                     MCU_TYPES_AR_RELEASE_REVISION_VERSION

/* Module Software version information */
#define MCU_PBTYPES_SW_MAJOR_VERSION  MCU_TYPES_SW_MAJOR_VERSION
#define MCU_PBTYPES_SW_MINOR_VERSION  MCU_TYPES_SW_MINOR_VERSION

/******************************************************************************
**                      SchM Critical Section Protection Macros              **
******************************************************************************/
#define MCU_ENTER_CRITICAL_SECTION(Exclusive_Area) \
                              SchM_Enter_Mcu_##Exclusive_Area()

#define MCU_EXIT_CRITICAL_SECTION(Exclusive_Area) \
                              SchM_Exit_Mcu_##Exclusive_Area()

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      MISRA C Rule Violations                               **
*******************************************************************************/

/* 1. MISRA C RULE VIOLATION:                                                 */
/* Message       : (4:3684)Array declared with unknown size.                  */
/* Rule          : MISRA-C:2004 Rule 8.12                                     */
/* Justification : As array is declared with external linkage, it's size is   */
/*                 assinged at the runtime by application layer.              */
/* Verification  : However, part of the code is verified manually and it is   */
/*                 not having any impact.                                     */
/* Reference     : Look for START Msg(4:3684)-1 and                           */
/*                 END Msg(4:3684)-1 tags in the code.                        */
/******************************************************************************/

/* Macros to avoid Magic numbers */
#define MCU_DBTOC_VALUE \
                        ((((uint32)MCU_VENDOR_ID_VALUE) << 22) | \
                        (((uint32)MCU_MODULE_ID_VALUE) << 14) | \
                        (((uint32)MCU_SW_MAJOR_VERSION) << 8) | \
                        (((uint32)MCU_SW_MINOR_VERSION) << 3))

#define MCU_ZERO                          (uint8)0x00

#define MCU_ONE                           (uint8)0x01

#define MCU_TWO                           (uint8)0x02

#define MCU_THREE                         (uint8)0x03

#define MCU_FOUR                          (uint8)0x04

#define MCU_FIVE                          (uint8)0x05

#define MCU_SIX                           (uint8)0x06

#define MCU_SEVEN                         (uint8)0x07

#define MCU_EIGHT                         (uint8)0x08

#define MCU_NINE                          (uint8)0x09

#define MCU_TEN                           (uint8)0x0A

#define MCU_ELEVEN                        (uint8)0x0B

#define MCU_TWELVE                        (uint8)0x0C

#define MCU_THIRTEEN                      (uint8)0x0D

#define MCU_FOURTEEN                      (uint8)0x0E

#define MCU_FIFTEEN                       (uint8)0x0F

#define MCU_SIXTEEN                       (uint8)0x10

#define MCU_SEVENTEEN                     (uint8)0x11

#define MCU_EIGHTEEN                      (uint8)0x12

#define MCU_NINETEEN                      (uint8)0x13

#define MCU_TWENTY                        (uint8)0x14

#define MCU_TWENTYONE                     (uint8)0x15

#define MCU_TWENTYTWO                     (uint8)0x16

#define MCU_TWENTYTHREE                   (uint8)0x17

#define MCU_TWENTYFOUR                    (uint8)0x18

#define MCU_TWENTYFIVE                    (uint8)0x19

#define MCU_TWENTYSIX                     (uint8)0x1A

#define MCU_TWENTYSEVEN                   (uint8)0x1B

#define MCU_TWENTYEIGHT                   (uint8)0x1C

#define MCU_TWENTYNINE                    (uint8)0x1D

#define MCU_THIRTY                        (uint8)0x1E

#define MCU_THIRTYONE                     (uint8)0x1F

#define MCU_THIRTYTWO                     (uint8)0x20

#define MCU_THIRTYTHREE                   (uint8)0x21

#define MCU_THIRTYFOUR                    (uint8)0x22

#define MCU_THIRTYFIVE                    (uint8)0x23

#define MCU_THIRTYSIX                     (uint8)0x24

#define MCU_THIRTYSEVEN                   (uint8)0x25

#define MCU_THIRTYEIGHT                   (uint8)0x26

#define MCU_THIRTYNINE                    (uint8)0x27

#define MCU_FOURTY                        (uint8)0x28

#define MCU_FOURTYONE                     (uint8)0x29

#define MCU_FOURTYTWO                     (uint8)0x2A

#define MCU_FOURTYTHREE                   (uint8)0x2B

#define  MCU_FIFTYSIX                     (uint8)0x38

#define MCU_INVERTED_ONE                  (uint8)0xFE

#define MCU_LONG_WORD_ZERO                (uint32)0x00000000ul

#define MCU_LONG_WORD_TWENTY_FOUR         (uint32)0x00000018ul

#define MCU_INITIALIZED                   (boolean)0x01

#define MCU_UNINITIALIZED                 (boolean)0x00

#define MCU_TRUE                          (boolean)0x01

#define MCU_FALSE                         (boolean)0x00

/* LVI Mask value */
#define MCU_LVI_MASK                      (uint32)0x00000004


/* Definition of uninitialized RESET value */
#define MCU_RESET_UNINIT                  (uint32)0xFFFFFFFFul

#define MCU_EIBD08_CPU1_VALUE             (uint32)0x00000001

#define MCU_ENABLE_INTERRUPT              (uint16)0x0100

#define MCU_RESF_CLEAR                    (uint32)0x00000007ul
#define MCU_POF_CLEAR                     (uint32)0x00000001ul
#define MCU_CVM_CLEAR                     (uint8)0x83u
/* Definition for Reset source check values */
#define MCU_SWR                           (uint32)0x00000001ul
#define MCU_ECM                           (uint32)0x00000002ul
#define MCU_POF_RST                       (uint32)0x00000001ul
#define MCU_PINRST                        (uint32)0x00000004ul

#define MCU_POF_RSTBIT                    (uint32)0x00000001ul
#define MCU_PIN_RSTBIT                    (uint32)0x00000002ul
#define MCU_SW_RSTBIT                     (uint32)0x00000004ul
#define MCU_WDG_RSTBIT                    (uint32)0x00000001ul
#define MCU_LOCKSTEP_RSTBIT               (uint32)0x00000002ul
#define MCU_CLMA0_UPLIMIT_RSTBIT          (uint32)0x00000010ul
#define MCU_CLMA0_LOLIMIT_RSTBIT          (uint32)0x00000020ul
#define MCU_CLMA2_UPLIMIT_RSTBIT          (uint32)0x00000040ul
#define MCU_CLMA2_LOLIMIT_RSTBIT          (uint32)0x00000080ul
#define MCU_CLMA1_UPLIMIT_RSTBIT          (uint32)0x00000100ul
#define MCU_CLMA1_LOLIMIT_RSTBIT          (uint32)0x00000200ul
#define MCU_CLMA3_UPLIMIT_RSTBIT          (uint32)0x00000400ul
#define MCU_CLMA3_LOLIMIT_RSTBIT          (uint32)0x00000800ul
#define MCU_LRAM_ECC2_ADDPTY_RSTBIT       (uint32)0x00001000ul
#define MCU_CACHE_RAM_RSTBIT              (uint32)0x00004000ul
#define MCU_CFLH_ECC2_ADDPTY_RSTBIT       (uint32)0x00008000ul
#define MCU_DATA_FLSH_ECC2_RSTBIT         (uint32)0x00010000ul
#define MCU_DTS_RAM_ECC2_RSTBIT           (uint32)0x00020000ul
#define MCU_CSIH_RAM_ECC2_RSTBIT          (uint32)0x00040000ul
#define MCU_CAN_RAM_ECC2_RSTBIT           (uint32)0x00080000ul
#define MCU_FLXR_RAM_ECC2_RSTBIT          (uint32)0x00100000ul
#define MCU_MODE0_RSTBIT                  (uint32)0x00200000ul
#define MCU_MODE1_RSTBIT                  (uint32)0x00400000ul
#define MCU_MODE2_RSTBIT                  (uint32)0x00800000ul
#define MCU_PEGUARD_RSTBIT                (uint32)0x01000000ul
#define MCU_PBUSGUARD_RSTBIT              (uint32)0x04000000ul
#define MCU_SAR_ADC_RSTBIT                (uint32)0x08000000ul
#define MCU_BUS_DATA_PRTY_RSTBIT          (uint32)0x10000000ul
#define MCU_ECM_COMP_RSTBIT               (uint32)0x20000000ul
#define MCU_LVI_RSTBIT                    (uint32)0x40000000ul
#define MCU_TEMP_SENSE_RSTBIT             (uint32)0x80000000ul
#define MCU_DMA_RSTBIT                    (uint32)0x00000001ul
#define MCU_DMA_REG_PROTECT_RSTBIT        (uint32)0x00000002ul
#define MCU_LRAM_ECC1_PTY_RSTBIT          (uint32)0x00000004ul
#define MCU_CFLH_ECC1_RSTBIT              (uint32)0x00000010ul
#define MCU_DATA_FLSH_ECC1_RSTBIT         (uint32)0x00000020ul
#define MCU_DTS_RAM_ECC1_RSTBIT           (uint32)0x00000040ul
#define MCU_ALL_PERI_RAM_ECC1_RSTBIT      (uint32)0x00000080ul
#define MCU_BIST_ECC1_RSTBIT              (uint32)0x00000100ul
#define MCU_BIST_ECC2_RSTBIT              (uint32)0x00000200ul
#define MCU_FACI_TRANSF_RSTBIT            (uint32)0x00000400ul
#define MCU_ECM_DELY_OVRFLW_RSTBIT        (uint32)0x20000000ul


/* Data to be written to the protection command register to enable
 * writing to the write protected register
 */
#define MCU_WRITE_DATA                    (uint32)0x000000A5

/* Definitions of values to be written to Software reset register
 * to perform reset
 */
#define MCU_RES_CORRECT_VAL               (uint32)0x00000001ul
#define MCU_RES_INVERTED_VAL              (uint32)0xFFFFFFFEul

/* Maximum number of ECM config registers */
#define MCU_MAX_ECM_CONFIG                (uint8)0x08

/* Maximum number of ECM delay timer config registers */
#define MCU_MAX_ECMDLY_CONFIG             (uint8)0x04

/* Maximum number of ECM delay timer config registers */
#define MCU_MAX_ECMRAM_CONFIG             (uint8)0x08

#define MCU_CLOCK_ACTIVE                  (uint8) 0x01

#define MCU_CLKOUT_ACTIVE_SYNC            (uint8)0x03

#define MCU_HSINT_OSC                     (uint8)0x04

#define MCU_ECMEMK0_FULL_MASK             (uint32)0xFDFFDFF3ul

#define MCU_ECMMESSTR0_FULL_MASK          (uint32)0xFDFFDFF3ul

#define MCU_ECMMESSTR1_FULL_MASK          (uint32)0x600007F7ul

#define MCU_ECMEMK1_FULL_MASK              (uint32)0x200007F7ul

#define MCU_RAM_MASK0_VALUE               (uint32)0x001E5000ul

#define MCU_RAM_MASK1_VALUE               (uint32)0x000000C4ul

#define MCU_LSB_MASK                      (uint8)0x0F

#define MCU_MSB_MASK                      (uint8)0xF0

#define MCU_ECM029_MASK_VALUE             (uint32)0x20000000

#define MCU_ECM_DELY_TIMER_STOP           (uint8)0x02

#define MCU_ECMDTMCTL_OFFSET              (uint8)0x3C

#define MCU_ECMDTMCMP_OFFSET              (uint8)0x44

#define MCU_ECMDTMCFG0_OFFSET             (uint8)0x48

#define MCU_ECMNMICFG0_OFFSET             (uint8)0x0C

#define MCU_ECMNMICFG1_OFFSET             (uint8)0x10

#define MCU_ECMIRCFG0_OFFSET              (uint8)0x14

#define MCU_ECMIRCFG1_OFFSET              (uint8)0x18

#define MCU_ECMEMK0_OFFSET                (uint8)0x1C

#define MCU_ECMEMK1_OFFSET                (uint8)0x20

#define MCU_ECMPE0_OFFSET                 (uint8)0x34

#define MCU_ECMPE1_OFFSET                 (uint8)0x38

#define MCU_ECMMICFG0_OFFSET              (uint8)0x04

#define MCU_ECMMICFG1_OFFSET              (uint8)0x08

#define MCU_ECMEPCFG_OFFSET               (uint8)0x00

/* CVM Factor Clear value */
#define MCU_CVM_FACTOR_CLEAR              (uint8)0x83

#define MCU_CVM_UNMASK_ERROR_CHECK        (uint8)0x83

#define MCU_CVM_MASK_ERROR_CHECK          (uint8)0x03

#define MCU_CVM_DIAG_MASK                 (uint8)0x08

#define MCU_IRCFG0_INIT_VALUE             (uint32)0x0000000Cul

/* CLMA Self Test value */
#define CLMA_SELF_TEST_VALUE              (uint32)0x00000008ul

/* To get the ECM error out status */
#define MCU_ERROROUT_STATUS               (uint32)0x80000000ul

/* To check comparator self test */
#define MCU_LOCKSTEP_DUMMY_VALUE          (uint32)0x55555555ul

/* Calculated CLMA wait delay based on sampling frequency */
#define MCU_CLMA0_DELAY_CNT               (uint16) 2560
#define MCU_CLMA1_DELAY_CNT               (uint16) 2560
#define MCU_CLMA2_DELAY_CNT               (uint16) 163840
#define MCU_CLMA3_DELAY_CNT               (uint16) 640

/* Calculated CVM wait delay based on CPU clock frequency */
#define MCU_CVM_DELAY_CNT                 (uint16) 1920
/* Calculated External clock selection delay based on CPU clock frequency */
#define MCU_EXTCLKSEL_DELAY_CNT           (uint16) 3200
/* Calculated LVI stabilization delay based on CPU clock frequency */
#define MCU_LVI_DELAY_CNT           (uint16) 12800
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      RAM Setting Data Structure                          **
*******************************************************************************/
/* RAM Sector Data Structure */
/* TRACE [R4, MCU030] */
typedef struct STag_Mcu_RamSetting
{
  /* RAM Initial Value */
  uint32 ulRamDefaultValue;
  /* Value of RAM Starting Address */
  uint32 ulRamSectionBaseAddress;
  /* Size of RAM Section  */
  /* TRACE [R4, MCU179_Conf] */
  uint32 ulRamSectionSize;
} Mcu_RamSetting;


/*******************************************************************************
**                      Clock Setting Data Structure                          **
*******************************************************************************/
/* TRACE [R4, MCU031] */
typedef struct STag_Mcu_ClockSetting
{
  /* Details of selected CPU clock sources */
  uint8 ucExtClk0SelectedSrcClock;
  uint8 ucExtClk1SelectedSrcClock;
  /* Details of External clock Divider */
  uint32 ulExternalClk0Divider;
  uint32 ulExternalClk1Divider;
} Mcu_ClockSetting;

typedef struct STag_Mcu_ErrorNotification
{
  /* Pointer to callback notification function */
  P2FUNC (void, MCU_VAR, pNotificationFuncPtr)(void);
  /* To check Delaytimer status on ISR routine */
  uint8 ucDelayTimerOnStatus;
} Mcu_ErrorNotification;

typedef struct STag_Mcu_ExtnClkSettingReg
{
  /* pointer to extn clk control reg */
  volatile uint32* pMcuExtCkscCtl;
  /* pointer to extn clk control status reg */
  volatile uint32* pMcuExtCkscStat;
  /* pointer to extn clk divider control reg */
  volatile uint32* pMcuExtClkDiv;
  /* pointer to extn clk divider status reg */
  volatile uint32* pMcuExtClkDivStat;
} Mcu_ExtnClkSettingReg;

typedef struct STag_Mcu_EcmSetting
{
  /* ECM Maskable interrupt config reg0 value */
  uint32 ulEcmMaskInterReg0value;
  /* ECM Maskable interrupt config reg1 value */
  uint32 ulEcmMaskInterReg1value;
  /* ECM Non-Maskable interrupt config reg0 value */
  uint32 ulEcmNonMaskInterReg0value;
  /* ECM Non-Maskable interrupt config reg1 value */
  uint32 ulEcmNonMaskInterReg1value;
  /* ECM  internal reset config reg0 value */
  uint32 ulEcmInternalResetReg0value;
  /* ECM internal reset config reg1 value */
  uint32 ulEcmInternalResetReg1value;
  /* ECM error mask reg 0 value */
  uint32 ulEcmErrorMaskReg0Value;
  /* ECM error mask reg 1 value */
  uint32 ulEcmErrorMaskReg1Value;
  /* ECM delay timer reg 0 value */
  uint32 ulEcmDelayTimerReg0Value;
  /* ECM delay timer reg 1 value */
  uint32 ulEcmDelayTimerReg1Value;
  /* ECM delay timer reg 2 value */
  uint32 ulEcmDelayTimerReg2Value;
  /* ECM delay timer reg 3 value */
  uint32 ulEcmDelayTimerReg3Value;
} Mcu_EcmSetting;

/*******************************************************************************
**                       Extern declarations for Global Data                  **
*******************************************************************************/
/*To use CONFIG_DATA section in the Memory*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"
/* MISRA Violation: START Msg(4:3684)-1 */
/* Global array for the Ecm setting configuration */
extern CONST(Mcu_EcmSetting, MCU_CONST)Mcu_GstEcmSetting[];

/* Global array for the RAM setting configuration */
extern CONST(Mcu_RamSetting, MCU_CONST)Mcu_GstRamSetting[];

/* Global array for Clock Setting Configuration */
extern CONST(Mcu_ClockSetting, MCU_CONST) Mcu_GstClockSetting[];

/* Global array for MI notification Configuration */
extern CONST(Mcu_ErrorNotification, MCU_CONST) Mcu_GstMINotification[];

/* Global array for NMI notification Configuration */
extern CONST(Mcu_ErrorNotification, MCU_CONST) Mcu_GstNMINotification[];
/* END Msg(4:3684)-1 */

/*Exit CONFIG_DATA section in the Memory*/
#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* MCU_PBTYPES_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
