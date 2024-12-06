/* -----------------------------------------------------------------------------
  Filename:    nm_par.c
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Nm_Gmlan_Gm
               
               Configuration   : C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\tools\GENy\EPS_B.gny
               
               ECU: 
                       TargetSystem: Hw_Rh850Cpu
                       Compiler:     GreenHills
                       Derivates:    P1M
               
               Channel "HS":
                       Databasefile: C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\tools\GENy\GlobalA_HS_EPSB.dbc
                       Bussystem:    CAN
                       Manufacturer: General Motors
                       Node:         EPS_HS
               Channel "CE":
                       Databasefile: C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\tools\GENy\GlobalA_CE_EPSB.dbc
                       Bussystem:    CAN
                       Manufacturer: General Motors
                       Node:         EPS_CE
               Channel "IMC":
                       Databasefile: C:\_synergy\G2KCAT2_CZ8L9T\GMG2KCAT2_EPS_TMS570\Tools\AsrProject\GENy\IMC_GM.dbc
                       Bussystem:    CAN
                       Node:         EPS_B

 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2015 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#include "v_inc.h"
#include "gmnmdef.h"
#include "nm_par.h"
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxHandle_VNMF_Field[kNmNumberOfChannels * kNmNumberOfIdentities] = 
{
  kCanTxHandleNotUsed, 
  kCanTxHandleNotUsed
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmSourceId_Field[kNmNumberOfChannels * kNmNumberOfIdentities] = 
{
  49, 
  49
};

V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 NmTxHandle_HLVW_Field[kNmNumberOfChannels] = 
{
  kCanTxHandleNotUsed, 
  kCanTxHandleNotUsed
};

/* VN configuration */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnTypeTable[kNmNumberOfVirtualNets] = 
{
  kVnLocal | kVnInitActive /* VN_SLHSSharedDiagnostic, Id: 0, Ch: HS */, 
  kVnLocal /* VN_AllNodes, Id: 1, Ch: HS */, 
  kVnLocal | kVnInitActive /* VN_SLHS_VNReq, Id: 2, Ch: HS */, 
  kVnLocal | kVnInitActive /* VN_SLHSSharedDiagnostic, Id: 0, Ch: CE */, 
  kVnLocal /* VN_AllNodes, Id: 1, Ch: CE */, 
  kVnLocal | kVnInitActive /* VN_SLHS_VNReq, Id: 2, Ch: CE */
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnStartIndex[kNmNumberOfChannels+1] = 
{
  0, 
  3, 
  6
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnRelevantMask[kNmNumberOfVnBytes] = 
{
  0x00, 
  0x00
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnByteMask[kNmNumberOfVirtualNets] = 
{
  0x80 /* VN_SLHSSharedDiagnostic, Id: 0, Ch: HS */, 
  0x40 /* VN_AllNodes, Id: 1, Ch: HS */, 
  0x20 /* VN_SLHS_VNReq, Id: 2, Ch: HS */, 
  0x80 /* VN_SLHSSharedDiagnostic, Id: 0, Ch: CE */, 
  0x40 /* VN_AllNodes, Id: 1, Ch: CE */, 
  0x20 /* VN_SLHS_VNReq, Id: 2, Ch: CE */
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnByteOffset[kNmNumberOfVirtualNets] = 
{
  0x00 /* VN_SLHSSharedDiagnostic, Id: 0, Ch: HS */, 
  0x00 /* VN_AllNodes, Id: 1, Ch: HS */, 
  0x00 /* VN_SLHS_VNReq, Id: 2, Ch: HS */, 
  0x01 /* VN_SLHSSharedDiagnostic, Id: 0, Ch: CE */, 
  0x01 /* VN_AllNodes, Id: 1, Ch: CE */, 
  0x01 /* VN_SLHS_VNReq, Id: 2, Ch: CE */
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmVnByteStartIndex[kNmNumberOfChannels+1] = 
{
  0, 
  1, 
  2
};

/* Nm channel properties */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 NmCallCycle_Field[kNmNumberOfChannels] = 
{
  10, 
  10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmHighSpeedCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmHighSpeedTime + 10) - 1) / 10, 
  ((kNmHighSpeedTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmWakeupFailCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmWakeupFailTime + 10) - 1) / 10, 
  ((kNmWakeupFailTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVnTimerCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmVnTimerTime + 10) - 1) / 10, 
  ((kNmVnTimerTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVnRxTimerCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmVnRxTimerTime + 10) - 1) / 10, 
  ((kNmVnRxTimerTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmWakeupSleepCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmWakeupSleepTime + 10) - 1) / 10, 
  ((kNmWakeupSleepTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmDeactSleepCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmDeactSleepTime + 10) - 1) / 10, 
  ((kNmDeactSleepTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmSleepDeniedCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmSleepDeniedTime + 10) - 1) / 10, 
  ((kNmSleepDeniedTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmLastWakeupCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmLastWakeupTime + 10) - 1) / 10, 
  ((kNmLastWakeupTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVNRestartIVNMFCnt_Field[kNmNumberOfChannels] = 
{
  ((kNmVnRestartIVNMFTime + 10) - 1) / 10, 
  ((kNmVnRestartIVNMFTime + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 vuint16 V_MEMROM2 NmVNMFConfirmCnt_Field[kNmNumberOfChannels] = 
{
  ((500 + 10) - 1) / 10, 
  ((500 + 10) - 1) / 10
};

V_MEMROM0 V_MEMROM1 tNmTrcvrType V_MEMROM2 NmTrcvType_Field[kNmNumberOfChannels] = 
{
  NM_HIGHSPEED_NOSLEEP_TRCV, 
  NM_HIGHSPEED_NOSLEEP_TRCV
};


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245625395
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\nm_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\nm_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

