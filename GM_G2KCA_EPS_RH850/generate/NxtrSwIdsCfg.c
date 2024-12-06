
/**********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name  : NxtrSwIdsCfg.c
* Module Description: Nexteer Software Identifiers
* Project           : CBD
* Author            : Jared Julien
* Generator         : artt 2.0.2.0
* Generation Time   : 21.12.2016 10:56:58
***********************************************************************************************************************
* Version Control:
* %version:          5 %
* %derived_by:       CZ8L9T %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 12/04/15  1        JWJ       Initial Template Version                                                        EA4#
**********************************************************************************************************************/

/************************************************ Include Statements *************************************************/
#include "NxtrSwIds.h"
#include "DualEcuSelect.h"

#if defined (DUALECUSELECT_EPSA_SELECTED)
	#define NXTSWID "G2KCA_EPSA"
#endif

#if defined (DUALECUSELECT_EPSB_SELECTED)
	#define NXTSWID "G2KCA_EPSB"
#endif


/******************************************** File Level Rule Deviations *********************************************/

/********************************************* Embedded Local Constants **********************************************/
CONST(SwRelNrRec, NxtrSwIds_CONST) NxtrSwIds_SwRelNr_Cnt_str = {NXTSWID, "02.01.00"};


/* The fields in this group are updated at compile time using a preexec script to values read from the user's PC */
CONST(uint8, NxtrSwIds_CONST) NxtrSwIds_SwAuthor_Cnt_u08[6U] = "cz8l9t";
CONST(SwOriginRec, NxtrSwIds_CONST) NxtrSwIds_SwOrigin_Cnt_enum = SWORIGIN_DEV;


/* The fields in this group are used for PSR builds.  If creating a PSR, also set SwOrigin above to SWORIGIN_PSR. */
CONST(uint32, NxtrSwIds_CONST) NxtrSwIds_PsrId_Cnt_u32 = 0U;
CONST(uint8, NxtrSwIds_CONST) NxtrSwIds_PsrRev_Cnt_u08 = 'A';


/******************************************** Module Specific Variables **********************************************/

/******************************************** Local Function Prototypes **********************************************/

/*********************************************** Function Definitions ************************************************/

/* End of File: NxtrSwIdsCfg.c */
