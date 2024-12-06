/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_SnsrMeasStrt_Irq.c
* Module Description: Sensor Measurement Start
* Project           : CBD
* Author            : Shruthi Raghavan
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz2554 %
*--------------------------------------------------------------------------------------------------------------------
* Date        Rev     Author         Change Description                                                        SCR #
* --------  -------  --------  -------------------------------------------------------------------------    ---------
* 11/17/16    1        SR       Initial Version                                                             EA4#7053               
**********************************************************************************************************************/

#include "Rte_CDD_SnsrMeasStrt.h"

/***********************************************
 * << Start of include and declaration area >> *
 ***********************************************/
 /* ----------[File Includes]--------- */
 #include "ostm_regs.h"
 #include "Os.h"
 #include "CDD_HwTq0Meas.h"
 #include "CDD_HwTq1Meas.h"
 
 
 /* ----[MISRA Deviation Comments]---- */

/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */


/***********************************************
 * <<  End of include and declaration area  >> *
 ***********************************************/

#define CDD_SnsrMeasStrt_START_SEC_CODE
#include "CDD_SnsrMeasStrt_MemMap.h"

/***********************************************
 * <<     Start of ISR definition area      >> *
 ***********************************************/
ISR(SnsrMeasStrtIrq)
{
    OSTM1TT = 1U; /*Stop the OSTM1 Timer*/

    (void)HwTq0MeasTrigStrt_Oper(); /*Execute server call HwTq0MeasTrigStrt*/
    (void)HwTq1MeasTrigStrt_Oper(); /*Execute server call HwTq1MeasTrigStrt*/

    /*Increment the Message Counter : Rollover Intentional*/
    *Rte_Pim_TqMsgTrigCnt() = *Rte_Pim_TqMsgTrigCnt() + 1U;
}
/***********************************************
 * <<       End of ISR definition area      >> *
 ***********************************************/
 
#define CDD_SnsrMeasStrt_STOP_SEC_CODE
#include "CDD_SnsrMeasStrt_MemMap.h"



