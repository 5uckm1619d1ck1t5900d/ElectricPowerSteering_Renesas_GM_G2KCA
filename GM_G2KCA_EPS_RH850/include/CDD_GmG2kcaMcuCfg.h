/**********************************************************************************************************************
* Copyright 2015 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_GmG2kcaMcuCfg.h
* Module Description: Stub GM G2kca Mcu Config header until component is created and implemented
* Project           : GM G2kca
* Author            : Lucas Wendling
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       czgng4 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 04/28/15  1        LWW       Initial Version                                                                 EA4#517
* 10/22/15  2        JWJ       Added Adc0OutpInin prototype for micro diagnostics updates                      EA4#2198
**********************************************************************************************************************/

#ifndef CDD_GMG2KCAMCUCFG_H
#define CDD_GMG2KCAMCUCFG_H

#include "Std_Types.h"

extern FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit1(void);
extern FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgInit2(void);
extern FUNC(void, CDD_GmG2kcaMcuCfg_CODE) GmG2kcaMcuCfgPer1(void);
extern FUNC(void, CDD_GmG2kcaMcuCfg_CODE) Adc0OutpInin(void);
	
#endif
