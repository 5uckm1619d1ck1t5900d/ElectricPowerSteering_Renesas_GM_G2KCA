/***********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name: CmnMfgSrv.h
* Module Description: Common Manufacturing Services Header
* Project           : Common Manufacturing Services
* Author            : Jared Julien
************************************************************************************************************************
* Version Control:
* %version:         3 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 04/20/15  1        JWJ       Initial file creation                                                        EA4#550
* 06/09/15  2        JWJ       Removed macro functions - made into actual function in CmnMfgSrvFct.c        EA4#
* 10/21/15  3        JWJ       Updates made to bootloader, part number location was adjusted                EA4#2174
* 11/30/15  4        JWJ       Removed the ENAD and DISAD definitions, moved to CmnMfgSrvTyp                EA4#2518
***********************************************************************************************************************/
#ifndef CMNMFGSRV_H
#define CMNMFGSRV_H

#include "CmnMfgSrvTyp.h"

/* ================================================================================================================== */
/* External Variables */
/* ------------------------------------------------------------------------------------------------------------------ */
extern CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) CmnMfgSrv_DiTbl[64U];
extern VAR(NegRespCodEnum, CmnMfgSrv_VAR) CmnMfgSrvRetBuf_G;


#endif
/* End of File: CmnMfgSrv.h */
