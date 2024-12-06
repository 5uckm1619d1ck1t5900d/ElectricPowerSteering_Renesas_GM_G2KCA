/*****************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : NxtrDmaRegs.h
* Module Description: Nexteer Direct Memory Access Peripheral Registers
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/08/16	1   	 AJM			Initial version derived from CM200A baseline version 2.1.0                 EA4#7566
**********************************************************************************************************************/

#ifndef NXTRDMAREGS_H
#define NXTRDMAREGS_H

/**********************************************************************************************************************
* Include files
 *********************************************************************************************************************/
#include "dma_regs.h"

#define DMASSDRQC9 (DMASS.DTFRRQC9.BIT.DRQC)
#define DMASSTCC9 (DMASS.DCSTC9.BIT.TCC)
#define DMASSDTE9 (DMASS.DCEN9.BIT.DTE)
#define DMASSDRQC14 (DMASS.DTFRRQC14.BIT.DRQC)
#define DMASSTCC14 (DMASS.DCSTC14.BIT.TCC)
#define DMASSDTE14 (DMASS.DCEN14.BIT.DTE)
#define DMASSTC15 (DMASS.DCST15.BIT.TC)
#define DMASSTCC15 (DMASS.DCSTC15.BIT.TCC)

#endif
