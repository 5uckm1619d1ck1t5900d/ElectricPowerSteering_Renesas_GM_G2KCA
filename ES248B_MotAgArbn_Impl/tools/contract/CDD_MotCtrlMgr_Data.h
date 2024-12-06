/**********************************************************************************************************************
* Copyright 2016 Nexteer 
* Nexteer Confidential
*
* Module File Name  : CDD_MotCtrlMgr_Data.h
* Module Description: MotCtrlMgr Complex Driver Header Stub
* Project           : CBD
* Author            : Matthew Leser
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       nz2796 %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------
* 11/15/16  1        ML        Initial Version                                                                 EA4#7269
**********************************************************************************************************************/

#ifndef CDD_MOTCTRLMGR_DATA_H
#define CDD_MOTCTRLMGR_DATA_H

#ifndef Rte_TypeDef_SigQlfr1
   typedef uint8 SigQlfr1;
#endif

# ifndef SIGQLFR_NORES
#  define SIGQLFR_NORES (0U)
# endif

# ifndef SIGQLFR_PASSD
#  define SIGQLFR_PASSD (1U)
# endif

# ifndef SIGQLFR_FAILD
#  define SIGQLFR_FAILD (2U)
# endif
/***************** Inputs ***********************/
extern uint8 MOTCTRLMGR_MotCtrlMotAgMeclCorrlnSts;
extern uint8 MOTCTRLMGR_MotCtrlMotAgAMeclRollgCntr;
extern uint16 MOTCTRLMGR_MotCtrlMotAgAMecl;
extern SigQlfr1 MOTCTRLMGR_MotCtrlMotAgAMeclQlfr;

/***************** Outputs *********************/
extern uint16 MOTCTRLMGR_MotCtrlMotAgMecl;


#endif

