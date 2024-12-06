/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CDD_MotAgCmp.c
 *     SW-C Type:  CDD_MotAgCmp
 *  Generated at:  Fri Nov  6 15:16:46 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 4.3.0
 *                 RTE Core Version 1.3.0
 *       License:  Unlimited license CBD1400351 (THE ECU PRODUCT "STEERING SYSTEMS", THE ECU SUPPLIER "NEXTEER", THE VEHICLE MANUFACTURER "GENERAL MOTORS CORPORATION") for Nexteer Automotive Corporation
 *
 *   Description:  C-Code implementation template for SW-C <CDD_MotAgCmp>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name: CDD_MotAgCmp.c
* Module Description: Implementation of Motor Angle Compensation FDD ES247A
* Project           : CBD 
* Author            : Spandana Balani
***********************************************************************************************************************
* Version Control:
* %version:           1 %
* %derived_by:        gzkys7 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 06/02/15  1        SB       Initial Version                                                                   EA4#636
* 11/06/15  2        SB       Updated to ES247A_MotAgCmp_Design_1.4.0 - modified MtrRev calc &                  EA4#2415
                              implemented overflow protection                               
**********************************************************************************************************************/

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
  s15p16
    sint32 represents integers with a minimum value of -2147483648 and a maximum 
     value of 2147483647. The order-relation on sint32 is: x < y if y - x is
     positive. sint32 has a lexical representation consisting of an optional sign 
     allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
     sign is omitted, "+" is assumed. 
     
     For example: -1, 0, -12688778, +10000, 250098675.

  s18p13
    sint32 represents integers with a minimum value of -2147483648 and a maximum 
     value of 2147483647. The order-relation on sint32 is: x < y if y - x is
     positive. sint32 has a lexical representation consisting of an optional sign 
     allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
     sign is omitted, "+" is assumed. 
     
     For example: -1, 0, -12688778, +10000, 250098675.

  u0p16
    uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
     The order-relation on uint16 is: x < y if y - x is positive.
     uint16 has a lexical representation consisting of a finite-length sequence 
     of decimal digits (#x30-#x39).
     
     For example: 1, 0, 1267, +10000.

 *********************************************************************************************************************/

#include "Rte_CDD_MotAgCmp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "NxtrMath.h"
 /* MISRA-C:2004 Rule 16.10 [NXTRDEV 16.10.1]: There is no appropriate action to take on the return value */ 
/* MISRA-C:2004 Rule 19.1 [NXTRDEV 19.1.1]: AUTOSAR requires deviation from this rule for Memory Mapping include statements */

#define     MOTAGCMPMECLDEGPERREV_DEGPERREV_U16P0       360U
#define     MOTAGCUMVALGNDMASK_CNT_U32                  0x3FFFFFUL      /* (4194303UL) */

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
 * Boolean: Boolean
 * s15p16: Integer in interval [-2147483648...2147483647]
 * s18p13: Integer in interval [-2147483648...2147483647]
 * u0p16: Integer in interval [0...65535]
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   s15p16 *Rte_Pim_MotAgCmpMotCtrlMotAgCumvAlgndMrfRevSVPrev(void)
 *   s15p16 *Rte_Pim_MotAgCmpMotCtrlMotAgMeclPrev(void)
 *   u0p16 *Rte_Pim_MotAgCmpMotAgBackEmf(void)
 *   boolean *Rte_Pim_MotAgCmpFirstRunCmpl(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   u0p16 Rte_CData_MotAgCmpMotAgBackEmfDft(void)
 *
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_SysGlbPrmMotPoleCnt_Val(void)
 *
 *********************************************************************************************************************/


#define CDD_MotAgCmp_START_SEC_CODE
#include "CDD_MotAgCmp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpBackEmfRead_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAgCmpBackEmfRead>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MotAgCmpBackEmfRead_Oper(u0p16 *MotAgBackEmfRead)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpBackEmfRead_Oper(P2VAR(u0p16, AUTOMATIC, RTE_CDD_MOTAGCMP_APPL_VAR) MotAgBackEmfRead) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpBackEmfRead_Oper
 *********************************************************************************************************************/
     /* REQ: ES247A #71 I */
     *MotAgBackEmfRead = *Rte_Pim_MotAgCmpMotAgBackEmf();    
     /* ENDREQ: ES247A #71 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpBackEmfWr_Oper
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Oper> of PortPrototype <MotAgCmpBackEmfWr>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MotAgCmpBackEmfWr1_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CDD_MotAgCmp_CODE) MotAgCmpBackEmfWr_Oper(u0p16 MotAgCmpBackEmfWrData) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpBackEmfWr_Oper (returns application error)
 *********************************************************************************************************************/
     /* REQ: ES247A #32 I */
     *Rte_Pim_MotAgCmpMotAgBackEmf() = MotAgCmpBackEmfWrData;
     (void) Rte_Call_MotAgCmpMotAgBackEmf_SetRamBlockStatus(TRUE);
     return RTE_E_OK;
     /* ENDREQ: ES247A #32 I */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotAgCmpPer2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_AssiMechPolarity_Val(sint8 *data)
 *   Std_ReturnType Rte_Read_MotAgCumvAlgndMrfRev_Val(s15p16 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndCrf_Val(s18p13 data)
 *   Std_ReturnType Rte_Write_MotAgCumvAlgndMrf_Val(s18p13 data)
 *
 *********************************************************************************************************************/

FUNC(void, CDD_MotAgCmp_CODE) MotAgCmpPer2(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotAgCmpPer2
 *********************************************************************************************************************/
    /* REQ: ES247A #77 I */
    VAR(sint8, AUTOMATIC)   AssiMechPolarity_Uls_T_s08;
    VAR(sint32, AUTOMATIC)  MotAgCumvAlgndMrfRev_MotRev_T_s15p16;
    VAR(sint32, AUTOMATIC)  MotAgCumvAlgndMrf_MotDeg_T_s18p13;
    VAR(sint32, AUTOMATIC)  MotAgCumvAlgndCrf_MotDeg_T_s18p13;
    
    /* REQ: ES247A #81 I */
    (void) Rte_Read_AssiMechPolarity_Val(&AssiMechPolarity_Uls_T_s08);                  /* REQ: ES247A #49 I */
    (void) Rte_Read_MotAgCumvAlgndMrfRev_Val(&MotAgCumvAlgndMrfRev_MotRev_T_s15p16);    /* REQ: ES247A #49 I */ 
    
    MotAgCumvAlgndMrf_MotDeg_T_s18p13 = (sint32)Sign_s08_s32(MotAgCumvAlgndMrfRev_MotRev_T_s15p16) *
										(sint32)(uint32)((Abslt_u32_s32(MotAgCumvAlgndMrfRev_MotRev_T_s15p16) >> 3U) & MOTAGCUMVALGNDMASK_CNT_U32) * 
                                        (sint32)MOTAGCMPMECLDEGPERREV_DEGPERREV_U16P0;   
    MotAgCumvAlgndCrf_MotDeg_T_s18p13  = MotAgCumvAlgndMrf_MotDeg_T_s18p13 * AssiMechPolarity_Uls_T_s08;        /* REQ: ES247A #82 I */ 

    (void) Rte_Write_MotAgCumvAlgndMrf_Val(MotAgCumvAlgndMrf_MotDeg_T_s18p13);          /* REQ: ES247A #65 I */
	(void) Rte_Write_MotAgCumvAlgndCrf_Val(MotAgCumvAlgndCrf_MotDeg_T_s18p13);          /* REQ: ES247A #66 I */
    
    /* ENDREQ: ES247A #77 I */ /* ENDREQ: ES247A #81 I */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CDD_MotAgCmp_STOP_SEC_CODE
#include "CDD_MotAgCmp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
