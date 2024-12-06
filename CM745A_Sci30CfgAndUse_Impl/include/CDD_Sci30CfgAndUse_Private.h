/*****************************************************************************
* Copyright 2017 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_Sci30CfgAndUse_Private.h
* Module Description: Private header file for Sci30CfgAndUse
* Project           : CBD
* Author            : Avinash James
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       rzk04c %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 01/13/17	1   	 AJM			Initial version                                                            EA4#8022
**********************************************************************************************************************/

#ifndef CDD_SCI30CFGANDUSE_PRIVATE_H
#define CDD_SCI30CFGANDUSE_PRIVATE_H

#include "ImcArbn.h" 
 
typedef uint8 Ary1D_u8_Sci30CfgAndUseA[8U]; /* Frame Buffer */


/* typedef for For all Tx/Rx buffers */
#if (IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08 == 0U)
typedef Ary1D_u8_Sci30CfgAndUseA Ary2D_u8_Sci30CfgAndUseA[1U]; 
#else
typedef Ary1D_u8_Sci30CfgAndUseA Ary2D_u8_Sci30CfgAndUseA[IMCARBN_NROF2MILLISECRATEGROUP_CNT_U08]; 
#endif

#if (IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08 == 0U)
typedef Ary1D_u8_Sci30CfgAndUseA Ary2D_u8_Sci30CfgAndUseB[1U]; 
#else
typedef Ary1D_u8_Sci30CfgAndUseA Ary2D_u8_Sci30CfgAndUseB[IMCARBN_NROF10MILLISECRATEGROUP_CNT_U08]; 
#endif

#if (IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08 == 0U)
typedef Ary1D_u8_Sci30CfgAndUseA Ary2D_u8_Sci30CfgAndUseC[1U]; 
#else
typedef Ary1D_u8_Sci30CfgAndUseA Ary2D_u8_Sci30CfgAndUseC[IMCARBN_NROF100MILLISECRATEGROUP_CNT_U08]; 
#endif

#endif
