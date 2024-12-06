/* -----------------------------------------------------------------------------
  Filename:    xcp_par.h
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Xcp
               
               Configuration   : C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\tools\GENy\EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Rh850Cpu
                       Compiler:     GreenHills
                       Derivates:    P1M
               
               Channel "HS":
                       Databasefile: GlobalA_HS.dbc
                       Bussystem:    CAN
                       Manufacturer: General Motors
                       Node:         EPS_HS
               Channel "CE":
                       Databasefile: GlobalA_CE.dbc
                       Bussystem:    CAN
                       Manufacturer: General Motors
                       Node:         EPS_CE
               Channel "IMC":
                       Databasefile: C:\_synergy\G2KCAT2_CZ8L9T\GMG2KCAT2_EPS_TMS570\Tools\AsrProject\GENy\IMC_GM.dbc
                       Bussystem:    CAN
                       Node:         EPS_A

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

#if !defined(__XCP_PAR_H__)
#define __XCP_PAR_H__

#include "v_inc.h"
/*  */
typedef unsigned char XcpCharType;
/*  */
/* Events */
V_MEMROM0 extern  V_MEMROM1 XcpCharType V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 kXcpEventName[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventNameLength[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventCycle[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventDirection[];
#define XcpEventChannel_2ms_DAQ_2            0u
/*  */
/* Online calibration */
/*  */
/* Flash programming */
/*  */
/* DAQ */
/*  */
/* Checksum */
/*  */
/* Transport Layer */
#define XcpGetCanTransmitHandle()            CanTxXcp_Slave_Msg
#define XcpGetCanTransmitDataPtr()           (Xcp_Slave_Msg._c)
#define ApplXcpInterruptDisable()            CanInterruptDisable()
#define ApplXcpInterruptEnable()             CanInterruptRestore()
#define XcpTransmit()                        CanTransmit(XcpGetCanTransmitHandle())

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245472022
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy\xcp_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 245472022
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_PAR_H__ */
