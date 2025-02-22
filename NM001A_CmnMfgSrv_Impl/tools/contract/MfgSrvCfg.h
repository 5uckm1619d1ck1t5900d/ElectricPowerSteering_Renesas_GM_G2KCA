/***********************************************************************************************************************
* Copyright 2015 Nexteer
* Nexteer Confidential
*
* Module File Name: MfgSrvCfg.h
* Module Description: Manufacturing Services Configuration - Contract Header
* Project           : Common Manufacturing Services
* Author            : KZDYFH
************************************************************************************************************************
* Version Control:
* %version:         14 %
* %derived_by:      kzdyfh %
* ---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author    Change Description                                                           SCR #
* --------  -------  --------  ---------------------------------------------------------------------------  ----------
* 11/23/15  1        KZDYFH    Initial file creation                                                        EA4#
***********************************************************************************************************************/
#ifndef MFGSRVCFG_H
#define MFGSRVCFG_H

#include "CmnMfgSrvTyp.h"

extern CONST(uint32, CmnMfgSrv_CONST) CmnMfgSrv_PsrId_Cnt_u32;
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_PsrRev_Cnt_u08;
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_PsrAuthor_Cnt_u08[6U];
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_BuildDate_Cnt_str[11U];
extern CONST(uint8, CmnMfgSrv_CONST) CmnMfgSrv_BuildTi_Cnt_str[8U];

extern CONST(MfgSrvTblRec, AUTOMATIC) CmnMfgSrv_MfgSrvTbl_Cnt_str[100u];
extern CONSTP2VAR(boolean, AUTOMATIC, AUTOMATIC) CmnMfgSrv_DiTbl[64U];
extern CONST(uint16, AUTOMATIC) CmnMfgSrvCfg_NtFctPtrTbl[11U];

/* Service Enable/Disable */
#define CMNMFGSRV_F001ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDB2ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F119ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE99ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE08ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD06ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD61ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F114ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDC8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEB1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD70ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_107EENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_1001ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F112ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F141ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDB8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDF0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD9ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDB0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD00ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F151ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD80ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE88ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD3BENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F117ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F101ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE02ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE00ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE90ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE20ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE98ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F000ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F118ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F010ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE9CENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD60ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD3AENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD32ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDDBENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD85ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD71ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDF5ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD30ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD8CENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F150ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F002ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDDFENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDBAENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD68ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDABENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDDDENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD3CENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F4ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE8AENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F195ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F116ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE03ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE89ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD89ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEA9ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE01ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEA1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F110ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F2ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F11AENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD5ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDA9ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD03ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE21ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDF8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDA2ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F7ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1FDENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDDAENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDF4ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE8BENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD31ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1FFENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD7ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDA8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE82ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEA2ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD02ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD8DENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD42ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD41ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD3ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD38ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDAAENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDBBENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDA0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD84ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDDCENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F194ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE9EENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F3ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD88ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEA8ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE80ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEA0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD4ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDB3ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_2762ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_2761ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD05ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FEB0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F115ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD2ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDF1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1FEENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F111ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F140ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDA3ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDB9ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDB1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F113ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE83ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD01ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDC0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDD0ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD39ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F1F9ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD81ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FDA1ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE81ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FE9DENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_FD40ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC
#define CMNMFGSRV_F100ENA_CNT_LGC	CMNMFGSRV_ENAD_CNT_LGC

/* Prototypes for enabled services */
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF001RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB2Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB2Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF119RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF119RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF119RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE99RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE08Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE08Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD06Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD61Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF114RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF114RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF114RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDC8Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDC8Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEB1RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD70RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvSessionNxtr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvSessionDflt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF112RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF112RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF112RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF141RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF141RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF141RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB8Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF0RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF0RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD9Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD9Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB0Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB0Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD00Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF151RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF151RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF151RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD80RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE88RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD3BWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD3BRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF117RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF117RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF117RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF101RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF101RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF101RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE02Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE02Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE00Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE00Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE90Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE90Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE20RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE20RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE98RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF000RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF118RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF118RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF118RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF010RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE9CRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE9CWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD60Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD3ARd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD3AWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD32Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD32Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDBRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDBWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD85RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD71RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF5Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF5Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD30Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD30Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD8CRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF150RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF150RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF150RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD8RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF002RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDFWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDFRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDBARd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD68RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDABRoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDDRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDDWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD3CWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD3CRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F4Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE8ARd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE8AWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF195Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF116RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF116RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF116RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE03Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE03Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE89RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F0Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD89Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD89Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEA9Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE01Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE01Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEA1RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF110RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF110RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF110RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F2Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF11ARoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF11ARoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF11ARoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD5Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD5Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDA9RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD03Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD03Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE21Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE21Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF8Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF8Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDA2RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F7Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1FDRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDAWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDARd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF4Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF4Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE8BWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE8BRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD31Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD31Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1FFRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD7Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD7Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F1Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDA8RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE82Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE82Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEA2Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEA2Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F8Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD02Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD02Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD8DRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD42CtrlAdj(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD42CtrlRtn(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD41CtrlAdj(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD41CtrlRtn(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD3Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD3Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD38Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD38Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDAARoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDBBRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDA0RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD84RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD1Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD1Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDCWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDDCRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF194Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE9EWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE9ERd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F3Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD88Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD88Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEA8RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE80RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEA0RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD4Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD4Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB3Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB3Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvSecuKey(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvSecuSeed(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD05Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD05Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFEB0RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF115RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF115RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF115RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD2Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD2Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF1RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDF1RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1FERd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF111RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF111RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF111RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF140RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF140RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF140RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDA3RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB9Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB1Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDB1Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF113RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF113RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF113RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE83Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE83Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD01Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDC0Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDC0Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDD0RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD39Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD39Wr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF1F9Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD81RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFDA1RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE81Rd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE9DRd(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFE9DWr(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD40CtrlAdj(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvFD40CtrlRtn(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF100RoutineStop(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF100RoutineStrt(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);
FUNC(NegRespCodEnum, CmnMfgSrv_CODE) CmnMfgSrv_SrvF100RoutineSts(VAR(uint8, CmnMfgSrv_VAR) DataBuf_Uls_T_u08[]);

#endif
/* End of File: MfgSrvCfg.h */
