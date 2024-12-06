/* Contract file for CM200C */

#define MCUDIAGCERRINJ  STD_ON

#if (MCUDIAGCERRINJ == STD_ON)
extern void ClrErrInjReg_Oper(void);
extern void ReadErrInjReg_Oper(uint32* ErrId);
extern FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) InjDmaErr(void);
extern FUNC(Std_ReturnType, CDD_DmaCfgAndUse_CODE) InjMcuDiagcErr(void);
#endif

