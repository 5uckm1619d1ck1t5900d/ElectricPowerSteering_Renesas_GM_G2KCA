/* -----------------------------------------------------------------------------
  Filename:    xcp_par.c
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Xcp
               
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

#if !defined(__XCP_PAR_C__)
#define __XCP_PAR_C__

#include "v_inc.h"
#include "XcpProf.h"
#include "drv_par.h"

/* Events */
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 kXcpEventName_0[] = "2ms_DAQ";
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 kXcpEventName[] = 
{
  &kXcpEventName_0[0]
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventNameLength[] = 
{
  (vuint8) 7
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventCycle[] = 
{
  (vuint8) 2
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[] = 
{
  (vuint8) DAQ_TIMESTAMP_UNIT_1MS
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventDirection[] = 
{
  (vuint8) DAQ_EVENT_DIRECTION_DAQ
};
/* Online calibration */
/* Flash programming */
/* Transport Layer */
/*  */

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245625395
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\xcp_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 245625395
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_PAR_C__ */
