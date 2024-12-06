/* -----------------------------------------------------------------------------
  Filename:    v_par.c
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyVcfgNameDecorator
               
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

/* -----------------------------------------------------------------------------
    &&&~ BaseEnv_PSF_Includes
 ----------------------------------------------------------------------------- */

#include "v_inc.h"
#include "can_inc.h"



/* -----------------------------------------------------------------------------
    &&&~ GENy Version Information
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kGENyVersion[kGENyVersionNumberOfBytes] = 
{
  VGEN_DELIVERY_VERSION_BYTE_0, 
  VGEN_DELIVERY_VERSION_BYTE_1, 
  VGEN_DELIVERY_VERSION_BYTE_2, 
  VGEN_DELIVERY_VERSION_BYTE_3, 
  VGEN_DELIVERY_VERSION_BYTE_4, 
  VGEN_DELIVERY_VERSION_BYTE_5, 
  VGEN_DELIVERY_VERSION_BYTE_6, 
  VGEN_DELIVERY_VERSION_BYTE_7, 
  VGEN_DELIVERY_VERSION_BYTE_8, 
  VGEN_DELIVERY_VERSION_BYTE_9
};
/* ROM CATEGORY 4 END */



/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 tDBCVersion V_MEMROM2 kDBCVersion[3] = 
{
  { 0x17, 0x0, 0x107, 0x0, 0x0 }, 
  { 0x17, 0x0, 0x107, 0x0, 0x0 }, 
  { 0x16, 0x6, 0x0, 0x7, 0x1 }
};
/* ROM CATEGORY 4 END */


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245625395
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\v_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\v_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

