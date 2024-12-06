
/**********************************************************************************************************************
* Copyright 2017 Nexteer
* Nexteer Confidential
*
* Module File Name:   ImcArbn_Cfg.c
* Module Description: Private configuration source file for IMC Arbitration
* Project           : CBD
* Author            : Akilan Rathakrishnan
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       tzyksv %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev     Author  Change Description                                                                 SCR #
* --------  ------- ------- ---------------------------------------------------------------------------     ----------
* 15/Jan/17  1       Akilan    ImcArbn Initial Version                                                       EA4#9291   
**********************************************************************************************************************/
#include "Rte_ImcArbn.h"
/************************************************ Include Statements *************************************************/
#include "ImcArbn_Private_Cfg.h"
/******************************************** File Level Rule Deviations *********************************************/

/*********** ImcArbn Signal Wrapper functions prototype ************************/
/* Wrapper function to get value of EcuId */
static FUNC(uint32, RTE_IMCARBN_APPL_CODE) GetEcuId(void);

/*************** [START]Configuration of individual Signal Groups **************/
/* Signal configuration for the signal group EcuIdSignalGroup  */
static const SigPrmRec1  ECUIDSIGNALGROUP_REC[] =
{
    {
        &GetEcuId, /* Pointer to the Signal wrapper function */
        IMCARBN_ECUID_CNT_U16, /* Signal ID */
        8U, /* Number of bits used for this Signal in the Signal Group */       
        0U, /* Start position of the Signal in the Signal Group */
    },

};
/* Signal configuration for the signal group EcuIdSignalGroup10ms  */
static const SigPrmRec1  ECUIDSIGNALGROUP10MS_REC[] =
{
    {
        &GetEcuId, /* Pointer to the Signal wrapper function */
        IMCARBN_ECUID_CNT_U16, /* Signal ID */
        8U, /* Number of bits used for this Signal in the Signal Group */       
        0U, /* Start position of the Signal in the Signal Group */
    },

};
/* Signal configuration for the signal group EcuIdSignalGroup2ms  */
static const SigPrmRec1  ECUIDSIGNALGROUP2MS_REC[] =
{
    {
        &GetEcuId, /* Pointer to the Signal wrapper function */
        IMCARBN_ECUID_CNT_U16, /* Signal ID */
        8U, /* Number of bits used for this Signal in the Signal Group */       
        0U, /* Start position of the Signal in the Signal Group */
    },

};
/************************ [END]Configuration of individual Signal Groups *******/

/************************ [START]Configuration of all Signal Groups ************/
const SigGroupRec1 SIGGROUPCONFIG_REC[IMCARBN_TOTALNROFSIGGROUP_CNT_U08] =
{
/*************** [START]Signal Groups Configured under 2ms Rate Group **********/
    {
        &ECUIDSIGNALGROUP2MS_REC[0], /*Signal Group Structure */
        1U, /* Number of Signals Configured under the Signal Group */
        IMCARBN_ECUIDSIGNALGROUP2MS_CNT_U08, /* Signal Group ID */
        TRUE, /* Transmit on Primary Source only */
    },
/*************** [END]Signal Groups Configured under 2ms Rate Group ************/
/*************** [START]Signal Groups Configured under 10ms Rate Group *********/
    {
        &ECUIDSIGNALGROUP10MS_REC[0], /*Signal Group Structure */
        1U, /* Number of Signals Configured under the Signal Group */
        IMCARBN_ECUIDSIGNALGROUP10MS_CNT_U08, /* Signal Group ID */
        FALSE, /* Transmit on Primary Source only */
    },
/*************** [END]Signal Groups Configured under 10ms Rate Group ***********/
/*************** [START]Signal Groups Configured under 100ms Rate Group ********/
    {
        &ECUIDSIGNALGROUP_REC[0], /*Signal Group Structure */
        1U, /* Number of Signals Configured under the Signal Group */
        IMCARBN_ECUIDSIGNALGROUP_CNT_U08, /* Signal Group ID */
        FALSE, /* Transmit on Primary Source only */
    },
/*************** [END]Signal Groups Configured under 100ms Rate Group **********/
};
/************************ [END]Configuration of all Signal Groups **************/

/***********[START] Signal functions definitions *******************************/
//#define IMCARBN_START_SEC_CODE
//#include "MemMap.h" /* PRQA S 5087 */
/* Wrapper function to get value of EcuId */
static FUNC(uint32, RTE_IMCARBN_APPL_CODE) GetEcuId(void)
{
    uint32 RetVal_Uls_T_u32;
    uint8 SigVal_Uls_T_u08;
    (void)Rte_Read_EcuId_Val(&SigVal_Uls_T_u08); 
    RetVal_Uls_T_u32 =  (uint32)SigVal_Uls_T_u08;
    return(RetVal_Uls_T_u32);
}
//#define IMCARBN_STOP_SEC_CODE
//#include "MemMap.h" /* PRQA S 5087 */
/***********[END] Signal functions definitions *********************************/


