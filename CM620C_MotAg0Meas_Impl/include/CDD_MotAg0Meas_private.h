/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotAg0Meas_private.h
* Module Description: Private header file for the CDD_MotAg0Meas component
* Project           : CBD   
* Author            : Avinash James
*****************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 10/26/16  1        AJM       Initial Version                                                                 EA4#7471  
******************************************************************************/
/******************************************* Multiple Include Protection *********************************************/
#ifndef CDD_MOTAG0MEAS_PRIVATE_H
#define CDD_MOTAG0MEAS_PRIVATE_H

/************************************************ Include Statements *************************************************/
#include "Std_Types.h"

#define  SPIPARMASK_CNT_U32 				((uint32)33554432U) 
#define  CORRNTBLSIZEMASK_CNT_U08  			((uint8)127U) 


#define  PimMotAg0CorrnTbl  ( *(Ary1D_sm5p12_128 *) (Rte_Pim_MotAg0CorrnTbl()) )


/******************************************** File Level Rule Deviations *********************************************/



/*********************************************** Exported Declarations ***********************************************/


/**************************************** End Of Multiple Include Protection *****************************************/
#endif


