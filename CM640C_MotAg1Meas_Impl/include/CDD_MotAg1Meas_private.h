/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotAg1Meas_private.h
* Module Description: Private header file for the CDD_MotAg1Meas component
* Project           : CBD   
* Author            : Avinash James
*****************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       jzk9cc %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/01/16	1   	 AJM	   Initial version                                                                 EA4#7270 
******************************************************************************/
/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG1MEAS_PRIVATE_H
#define CDD_MOTAG1MEAS_PRIVATE_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

#define  SPIPARMASK_CNT_U32 				((uint32)33554432U) 
#define  CORRNTBLSIZEMASK_CNT_U08  			((uint8)127U) 


#define  PimMotAg1CorrnTbl  ( *(Ary1D_sm5p12_128 *) (Rte_Pim_MotAg1CorrnTbl()) )


/******************************************** File Level Rule Deviations *********************************************/



/*********************************************** Exported Declarations ***********************************************/


/**************************************** End Of Multiple Include Protection *****************************************/
#endif


