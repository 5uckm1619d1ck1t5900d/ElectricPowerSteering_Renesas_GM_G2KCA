/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotAg4Meas.c
 *     SW-C Type:  CDD_MotAg4Meas
 *  Generated at:  Wed Nov  9 10:47:13 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotAg4Meas>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/*************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotAg4Meas.c
* Module Description: Implements the measurement function of MotorAngle4.
*                     Includes configuration and use of the ENCA peripheral.
* Project           : CBD
* Author            : Shruthi Raghavan
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz2554 %
*------------------------------------------------------------------------------------------------------------
* Date          Rev     Author                          Change Description                            SCR #
* ----------   ------  --------  ---------------------------------------------------------------   ----------
* 11/01/2016    1        SR      Initial Implementation of CM515A according to FDD v1.2.0          EA4#7745
*************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  u0p16
    uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
     The order-relation on uint16 is: x < y if y - x is positive.
     uint16 has a lexical representation consisting of a finite-length sequence 
     of decimal digits (#x30-#x39).
     
     For example: 1, 0, 1267, +10000.


 Port Prototypes:
 ================
  MotAgMecl4Polarity
    Polarity value of Motor Angle 4


 Runnable Entities:
 ==================
  MotAg4MeasInit1
    Initial Function for Motor Angle 4 Measurement

 *********************************************************************************************************************/

#include "Rte_CDD_MotAg4Meas.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* -----[ File Includes ]------------------------------ */
 #include "CDD_MotAg4Meas.h"
 #include "enca_regs.h"
 
 /* -----[ MISRA Deviation Comments ]------------------- */
 /* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value of RTE_write functions */
 /* MISRA-C:2004 Rule 19.1  [NXTRDEV 19.1.1 ]: AUTOSAR requires deviation from this rule for Memory Mapping include statements   */
 
 /* -----[ Local Constant Definitions ]----------------- */
 #define MOTAGCNTRREGMASK_CNT_U16        16383U /*0x3FFFU*/
 #define MOTAGLIM_CNT_U16                65535U
                                         
 #define REGENCA1CTLINITVAL_CNT_U16      0x03U
 #define REGENCA1IOC1INITVAL_CNT_U08     0x04U
                                         
 #define REGENCA1TTINITVAL_CNT_U08       0x01U
 #define REGENCA1TSINITVAL_CNT_U08       0x01U

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * u0p16: Integer in interval [0...65535]
 *
 *********************************************************************************************************************/


#define CDD_MotAg4Meas_START_SEC_CODE
#include "CDD_MotAg4Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMotAg4Mecl_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <GetMotAg4Mecl>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_MotAgMecl4Polarity_Val(sint8 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void GetMotAg4Mecl_Oper(u0p16 *MotAgMecl_Arg)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg4Meas_CODE) GetMotAg4Mecl_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAG4MEAS_APPL_VAR) MotAgMecl_Arg) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMotAg4Mecl_Oper
 *********************************************************************************************************************/

 /* -----[ Inputs ]------------------------------------- */
 VAR(uint16, AUTOMATIC) EncATmrCntr_Cnt_T_u16;
 VAR(sint8 , AUTOMATIC) MotAgMecl4Polarity_Uls_T_s08;

 /* -----[ Temporary Variables ]------------------------ */
 VAR(uint16, AUTOMATIC) MotAg4Raw_Cnt_T_u0p16;

 /* -----[ Read Inputs ]-------------------------------- */
 EncATmrCntr_Cnt_T_u16 = ENCA1CNT; /*To ensure no unintended modification of register*/
 (void)Rte_Read_MotAgMecl4Polarity_Val(&MotAgMecl4Polarity_Uls_T_s08); 

 /* -----[ Processing ]--------------------------------- */

 /*Block: MotAg3Calcn*/
 MotAg4Raw_Cnt_T_u0p16 = (uint16)((EncATmrCntr_Cnt_T_u16 & MOTAGCNTRREGMASK_CNT_U16) << 2U);
 /*Sub-block: Polarity
  *ENCA Counter is opposite to SPI's Internal Counter.*/
 if(MotAgMecl4Polarity_Uls_T_s08 < 0)
 {
     *MotAgMecl_Arg = (MOTAGLIM_CNT_U16 - MotAg4Raw_Cnt_T_u0p16);
 }
 else
 {
     *MotAgMecl_Arg = MotAg4Raw_Cnt_T_u0p16;
 }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAg4MeasInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_MotAg4Meas_CODE) MotAg4MeasInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAg4MeasInit1
 *********************************************************************************************************************/

 /* -----[ Initializa ENCA Registers ]-------------------- */
 
 /*Stop Counter*/
 ENCA1TT       = REGENCA1TTINITVAL_CNT_U08;
 
 /*Configure operation settings of encoder timer*/
 ENCA1CTL      = REGENCA1CTLINITVAL_CNT_U16;

 /*Enable Rising Edge Detection and Clear counter on valid edge*/
 ENCA1IOC1     = REGENCA1IOC1INITVAL_CNT_U08;

 /*Enable Counter and Set to Operation*/
 ENCA1TS       = REGENCA1TSINITVAL_CNT_U08;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_MotAg4Meas_STOP_SEC_CODE
#include "CDD_MotAg4Meas_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
