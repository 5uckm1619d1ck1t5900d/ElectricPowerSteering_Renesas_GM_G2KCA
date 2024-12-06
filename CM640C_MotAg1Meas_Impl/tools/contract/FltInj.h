/* Header file for contract folder of CM640C */

#ifndef FLTINJ_H	/* Multiple include preventer */
#define FLTINJ_H


#define FLTINJ_MOTAG1MEAS_TESTOK             	(39U)
#define FLTINJ_MOTAG1MEAS_MOTCTRLMOTAG1MECL     (38U)

extern FUNC(void, FltInj_CODE) FltInj_u08_Oper(P2VAR(uint8, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg);
extern FUNC(void, FltInj_CODE) FltInj_u0p16_Oper(P2VAR(u0p16, AUTOMATIC, RTE_FLTINJ_APPL_VAR) SigPah_Arg, uint16 LocnKey_Arg);

#define FLTINJENA 	 STD_ON  /* FLTINJENA is defined as STD_ON in contract folder to let the compiler check the function call */


#endif
