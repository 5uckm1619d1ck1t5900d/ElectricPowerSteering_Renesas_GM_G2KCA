/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : ImcArbn.h
* Module Description: IMC Arbitration Header
* Project           : CBD
* Author            : Akilan Rathakrishnan
***********************************************************************************************************************
* Version Control:
* %version:          2 %
* %derived_by:       tzyksv %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/01/2016	1     RA			 Initial version							                              
**********************************************************************************************************************/

/******************************************* Multiple Include Protection *********************************************/
#ifndef IMCARBN_H
#define IMCARBN_H

/************************************************ Include Statements *************************************************/
//#include "ImcArbn_Cfg.h"
/******************************************** File Level Rule Deviations *********************************************/

/*********************************************** Exported Declarations ***********************************************/
/* Signal Group Frame Size */
#define IMCARBN_RATEGROUPID2MILLISEC_CNT_U08     (0U)
#define IMCARBN_RATEGROUPID10MILLISEC_CNT_U08    (1U)
#define IMCARBN_RATEGROUPID100MILLISEC_CNT_U08   (2U)
#define IMCARBN_NROFRATEGROUP_CNT_U08 (3U)


/* Status enum IMCARBNRXEXTDSTS values */
#define IMCARBNRXEXTDSTS_NEVERRCVD            (0U)
#define IMCARBNRXEXTDSTS_MISS                 (1U)
#define IMCARBNRXEXTDSTS_DATAINVLD            (2U)
#define IMCARBNRXEXTDSTS_PREVDATA             (3U)
#define IMCARBNRXEXTDSTS_DATAVLDWITHBACKUP    (4U)
#define IMCARBNRXEXTDSTS_DATAVLDWITHNOBACKUP  (5U)
#define IMCARBNRXEXTDSTS_STRTG                (6U)

/* Values for ImcArbnRxDataSrc1 */
#define IMCARBNRXDATASRC_NOSRC                (0U)
#define IMCARBNRXDATASRC_PRIM                 (1U)
#define IMCARBNRXDATASRC_SECDRY               (2U)

#define IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08		1U
#define IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08 	2U
#define IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08	3U


#define IMCARBN_FRMSIZE_CNT_U08				8U
#define IMCARBN_PATIDN_CNT_U08 				160U
#define IMCARBN_PATIDMASKVAL_CNT_U08		224U

typedef uint8 ImcArbnRxDataSrc2;
/**************************************** End Of Multiple Include Protection *****************************************/
#endif

