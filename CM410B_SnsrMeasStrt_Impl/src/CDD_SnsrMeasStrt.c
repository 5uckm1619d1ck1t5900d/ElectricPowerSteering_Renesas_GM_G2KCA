/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_SnsrMeasStrt.c
 *     SW-C Type:  CDD_SnsrMeasStrt
 *  Generated at:  Fri Nov 18 10:27:06 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_SnsrMeasStrt>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_SnsrMeasStrt.c
* Module Description: Sensor Measurement Start
* Project           : CBD
* Author            : Shruthi Raghavan
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz2554 %
*----------------------------------------------------------------------------------------------------------
*   Date         Rev     Author         Change Description                                         SCR #
* ----------   -------  --------  ------------------------------------------------------------- -----------
* 11/17/2016    1          SR     Initial Implementation of FDD v1.0.0							EA4#7053
***********************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Port Prototypes:
 ================
  SnsrMeasStrtTrigDly
    Trigger Delay - 2ms Jitter control


 Runnable Entities:
 ==================
  SnsrMeasStrtInit1
    Timer Peripheral Initialization

  SnsrMeasStrtPer1
    Calculate the Timer Value for Trigger


 Per-Instance Memory:
 ====================
  TqMsgTrigCnt
    Captures how many timer trigger happen

 *********************************************************************************************************************/

#include "Rte_CDD_SnsrMeasStrt.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 /* ----------[File Includes]--------- */
 #include "ostm_regs.h"
 #include "Os.h"
 #include "osekext.h"

 /* ----[MISRA Deviation Comments]---- */
 /* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */
 
 /* ----[Local Embedded Constants]---- */
 #define ONEMICROSECCNT_CNT_U16  80U

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint32 *Rte_Pim_TqMsgTrigCnt(void)
 *
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint16 Rte_Prm_SnsrMeasStrtTrigDly_Val(void)
 *
 *********************************************************************************************************************/


#define CDD_SnsrMeasStrt_START_SEC_CODE
#include "CDD_SnsrMeasStrt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrMeasStrtInit1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, CDD_SnsrMeasStrt_CODE) SnsrMeasStrtInit1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrMeasStrtInit1
 *********************************************************************************************************************/
 
 OSTM1TT       = 1U;
 OSTMIC0CKSEL1 = 0U;
 OSTM1CTL      = 0U;
 osClearIMRmEI(75U); /*Unmask the OSTM1 Interrupt */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SnsrMeasStrtPer1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, CDD_SnsrMeasStrt_CODE) SnsrMeasStrtPer1(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SnsrMeasStrtPer1
 *********************************************************************************************************************/
 
 OSTM1CMP = (uint32)(OSTM0CNT - ((uint32)Rte_Prm_SnsrMeasStrtTrigDly_Val() * (uint32)ONEMICROSECCNT_CNT_U16));
 OSTM1TS  = 1U; /*Restart the timer*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_SnsrMeasStrt_STOP_SEC_CODE
#include "CDD_SnsrMeasStrt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
