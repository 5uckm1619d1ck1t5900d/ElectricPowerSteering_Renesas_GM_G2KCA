/* -----------------------------------------------------------------------------
  Filename:    can_par.c
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__base
               
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

#define C_DRV_INTERNAL
#include "can_inc.h"
#include "can_par.h"
#include "v_inc.h"

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanTxId0 V_MEMROM2 CanTxId0[kCanNumberOfTxObjects] = 
{
  MK_STDID0(0x78Au) /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  MK_STDID0(0x711u) /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  MK_STDID0(0x70Au) /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  MK_STDID0(0x642u) /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  MK_STDID0(0x542u) /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  MK_STDID0(0x185u) /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  MK_STDID0(0x149u) /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  MK_STDID0(0x64Au) /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  MK_STDID0(0x54Au) /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  MK_STDID0(0x336u) /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  MK_STDID0(0x185u) /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  MK_STDID0(0x013u) /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  MK_STDID0(0x001u) /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  MK_STDID0(0x021u) /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  MK_STDID0(0x01Fu) /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  MK_STDID0(0x01Du) /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  MK_STDID0(0x01Bu) /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  MK_STDID0(0x019u) /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  MK_STDID0(0x017u) /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  MK_STDID0(0x015u) /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  MK_STDID0(0x011u) /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  MK_STDID0(0x00Fu) /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  MK_STDID0(0x00Du) /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  MK_STDID0(0x00Bu) /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  MK_STDID0(0x009u) /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  MK_STDID0(0x007u) /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  MK_STDID0(0x005u) /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  MK_STDID0(0x003u) /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxDLC[kCanNumberOfTxObjects] = 
{
  MK_TX_DLC(7) /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  MK_TX_DLC(1) /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  MK_TX_DLC(4) /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 1 END */


#ifdef C_ENABLE_COPY_TX_DATA
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 TxDataPtr V_MEMROM2 CanTxDataPtr[kCanNumberOfTxObjects] = 
{
  (TxDataPtr) DTC_Triggered_778._c /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  (TxDataPtr) CmnMfgSrvResp._c /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  (TxDataPtr) Xcp_Slave_Msg._c /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  (TxDataPtr) USDT_Resp_From_EHPS_EPS_HS._c /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  (TxDataPtr) UUDT_Resp_From_EHPS_EPS_HS._c /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  (TxDataPtr) PPEI_Steering_Wheel_Angle._c /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  (TxDataPtr) Power_Steering_Information_HS._c /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  (TxDataPtr) USDT_Resp_From_EPS_EPS_JR_CE._c /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  (TxDataPtr) UUDT_Resp_From_EPS_EPS_JR_CE._c /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  (TxDataPtr) Electric_Power_Steering_CE._c /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  (TxDataPtr) PPEI_Steering_Wheel_Angle_CE._c /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  (TxDataPtr) SG9_Msg_EPS_B._c /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  (TxDataPtr) SG0_Msg_EPS_B_ONLY_SCI._c /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  (TxDataPtr) SG16_Msg_EPS_B._c /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG15_Msg_EPS_B._c /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG14_Msg_EPS_B._c /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG13_Msg_EPS_B._c /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG12_Msg_EPS_B._c /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG11_Msg_EPS_B._c /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG10_Msg_EPS_B._c /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG8_Msg_EPS_B._c /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG7_Msg_EPS_B._c /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG6_Msg_EPS_B._c /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG5_Msg_EPS_B._c /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG4_Msg_EPS_B._c /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG3_Msg_EPS_B._c /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG2_Msg_EPS_B._c /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  (TxDataPtr) SG1_Msg_EPS_B._c /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PRETRANSMIT_FCT
/* ROM CATEGORY 1 START */
/* PRQA  S 1334 QAC_Can_1334 */ /* MD_Can_1334 */
V_MEMROM0 V_MEMROM1 ApplPreTransmitFct V_MEMROM2 CanTxApplPreTransmitPtr[kCanNumberOfTxObjects] = 
{
  V_NULL /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  V_NULL /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  V_NULL /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  V_NULL /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  V_NULL /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  V_NULL /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  V_NULL /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  V_NULL /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  V_NULL /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  V_NULL /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  V_NULL /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  V_NULL /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  V_NULL /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  V_NULL /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* PRQA  L:QAC_Can_1334 */

/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_CONFIRMATION_FCT
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplConfirmationFct V_MEMROM2 CanTxApplConfirmationPtr[kCanNumberOfTxObjects] = 
{
  V_NULL /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  TpDrvConfirmation /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  XcpConfirmation /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  TpDrvConfirmation /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  DescUudtConfirmation /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  V_NULL /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  V_NULL /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  TpDrvConfirmation /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  GgdaUudtConfirmation /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  SerlComOutpProxy_335CfmFct /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  SerlComOutpProxy_1E5ChassisExpCfmFct /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  V_NULL /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  V_NULL /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  V_NULL /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  V_NULL /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PART_OFFLINE
/* ROM CATEGORY 2 START */

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxSendMask[kCanNumberOfTxObjects] = 
{
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  (vuint8) C_SEND_GRP_NONE /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};

/* ROM CATEGORY 2 END */

#endif


#ifdef C_ENABLE_CONFIRMATION_FLAG
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanConfirmationOffset[kCanNumberOfTxObjects] = 
{
  0 /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  0 /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  0 /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  0 /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0 /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0 /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  0 /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  0 /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0 /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0 /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  0 /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  0 /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  0 /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  0 /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  0 /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  0 /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  0 /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  0 /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  0 /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  0 /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  0 /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanConfirmationMask[kCanNumberOfTxObjects] = 
{
  0x01u /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  0x00u /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  0x00u /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  0x00u /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0x00u /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0x02u /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  0x04u /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  0x00u /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0x00u /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0x08u /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  0x10u /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  0x00u /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  0x00u /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  0x00u /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  0x00u /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 1 END */


#endif




/* Id table depending on search algorithm */
/* Linear search */
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanRxId0 V_MEMROM2 CanRxId0[kCanNumberOfRxObjects] = 
{
  MK_STDID0(0x7CBu) /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  MK_STDID0(0x713u) /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  MK_STDID0(0x70Cu) /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  MK_STDID0(0x242u) /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  MK_STDID0(0x101u) /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  MK_STDID0(0x500u) /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  MK_STDID0(0x4D1u) /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  MK_STDID0(0x3F1u) /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  MK_STDID0(0x34Au) /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  MK_STDID0(0x348u) /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  MK_STDID0(0x232u) /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  MK_STDID0(0x214u) /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  MK_STDID0(0x1F5u) /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  MK_STDID0(0x1F1u) /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  MK_STDID0(0x1E9u) /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  MK_STDID0(0x180u) /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  MK_STDID0(0x17Du) /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  MK_STDID0(0x0C9u) /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  MK_STDID0(0x0C5u) /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  MK_STDID0(0x242u) /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  MK_STDID0(0x101u) /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */, 
  MK_STDID0(0x34Au) /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  MK_STDID0(0x348u) /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  MK_STDID0(0x337u) /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  MK_STDID0(0x182u) /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  MK_STDID0(0x180u) /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  MK_STDID0(0x000u) /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  MK_STDID0(0x020u) /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  MK_STDID0(0x01Eu) /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  MK_STDID0(0x01Cu) /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  MK_STDID0(0x01Au) /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  MK_STDID0(0x018u) /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  MK_STDID0(0x016u) /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  MK_STDID0(0x014u) /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  MK_STDID0(0x012u) /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  MK_STDID0(0x010u) /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  MK_STDID0(0x00Eu) /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  MK_STDID0(0x00Cu) /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  MK_STDID0(0x00Au) /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  MK_STDID0(0x008u) /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  MK_STDID0(0x006u) /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  MK_STDID0(0x004u) /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  MK_STDID0(0x002u) /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxMsgIndirection[kCanNumberOfRxObjects] = 
{
  0 /* ID: 0x000007cb, Handle: 0, T1_HostToTarget */, 
  37 /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq */, 
  38 /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg */, 
  39 /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS */, 
  40 /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs */, 
  1 /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS */, 
  2 /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 */, 
  3 /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests */, 
  4 /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS */, 
  5 /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS */, 
  6 /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS */, 
  7 /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS */, 
  8 /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 */, 
  9 /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status */, 
  10 /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 */, 
  11 /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS */, 
  12 /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS */, 
  13 /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 */, 
  14 /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat */, 
  41 /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE */, 
  42 /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs */, 
  15 /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE */, 
  16 /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE */, 
  17 /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE */, 
  18 /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE */, 
  19 /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE */, 
  36 /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI */, 
  20 /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A */, 
  21 /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A */, 
  22 /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A */, 
  23 /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A */, 
  24 /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A */, 
  25 /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A */, 
  26 /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A */, 
  27 /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A */, 
  28 /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A */, 
  29 /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A */, 
  30 /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A */, 
  31 /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A */, 
  32 /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A */, 
  33 /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A */, 
  34 /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A */, 
  35 /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxDataLen[kCanNumberOfRxObjects] = 
{
  8 /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  4 /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  2 /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  8 /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  5 /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  5 /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  5 /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  6 /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  6 /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  8 /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  8 /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  4 /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  1 /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  7 /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  8 /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  5 /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  5 /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  7 /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  5 /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  8 /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  8 /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  8 /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  8 /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  8 /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  8 /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  8 /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  8 /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  8 /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  0 /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  8 /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  0 /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  0 /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  0 /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  0 /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* ROM CATEGORY 1 END */


#ifdef C_ENABLE_COPY_RX_DATA
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 RxDataPtr V_MEMROM2 CanRxDataPtr[kCanNumberOfRxObjects] = 
{
  (RxDataPtr) T1_HostToTarget._c /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  (RxDataPtr) Wheel_Pulses_HS._c /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  (RxDataPtr) PPEI_Engine_General_Status_5._c /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  (RxDataPtr) PPEI_Platform_Eng_Cntrl_Requests._c /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  (RxDataPtr) NonDriven_Wheel_Grnd_Velocity_HS._c /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  (RxDataPtr) Driven_Wheel_Grnd_Velocity_HS._c /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  (RxDataPtr) Driving_Mode_Control_HS._c /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  (RxDataPtr) Brake_Pedal_Driver_Status_HS._c /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  (RxDataPtr) PPEI_Trans_General_Status_2._c /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  (RxDataPtr) PPEI_Platform_General_Status._c /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  (RxDataPtr) PPEI_Chassis_General_Status_1._c /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  (RxDataPtr) LKA_Steering_Torque_Cmd_HS._c /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  (RxDataPtr) Antilock_Brake_and_TC_Status_HS._c /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  (RxDataPtr) PPEI_Engine_General_Status_1._c /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  (RxDataPtr) PPEI_NonDrivn_Whl_Rotationl_Stat._c /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  (RxDataPtr) NonDriven_Wheel_Grnd_Velocity_CE._c /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  (RxDataPtr) Driven_Wheel_Grnd_Velocity_CE._c /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  (RxDataPtr) Park_Assist_Parallel_CE._c /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  (RxDataPtr) Vehicle_Dynamics_ESC_Hyb_CE._c /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  (RxDataPtr) Steering_Torque_Command_CE._c /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  (RxDataPtr) SG16_Msg_EPS_A._c /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG15_Msg_EPS_A._c /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG14_Msg_EPS_A._c /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG13_Msg_EPS_A._c /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG12_Msg_EPS_A._c /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG11_Msg_EPS_A._c /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG10_Msg_EPS_A._c /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG9_Msg_EPS_A._c /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG8_Msg_EPS_A._c /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG7_Msg_EPS_A._c /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG6_Msg_EPS_A._c /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG5_Msg_EPS_A._c /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG4_Msg_EPS_A._c /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG3_Msg_EPS_A._c /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG2_Msg_EPS_A._c /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG1_Msg_EPS_A._c /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  (RxDataPtr) SG0_Msg_EPS_A_ONLY_SCI._c /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  (RxDataPtr) 0 /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  (RxDataPtr) Xcp_Master_Msg._c /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  (RxDataPtr) 0 /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  (RxDataPtr) 0 /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  (RxDataPtr) 0 /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  (RxDataPtr) 0 /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PRECOPY_FCT
/* CODE CATEGORY 1 START */
/* CODE CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplPrecopyFct V_MEMROM2 CanRxApplPrecopyPtr[kCanNumberOfRxObjects] = 
{
  V_NULL /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  IlMsgWheel_Pulses_HSPreCopy /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  IlMsgPPEI_Engine_General_Status_5PreCopy /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  IlMsgPPEI_Platform_Eng_Cntrl_RequestsPreCopy /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  IlMsgNonDriven_Wheel_Grnd_Velocity_HSPreCopy /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  IlMsgDriven_Wheel_Grnd_Velocity_HSPreCopy /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  IlMsgDriving_Mode_Control_HSPreCopy /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  IlMsgBrake_Pedal_Driver_Status_HSPreCopy /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  IlMsgPPEI_Trans_General_Status_2PreCopy /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  IlMsgPPEI_Platform_General_StatusPreCopy /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  IlMsgPPEI_Chassis_General_Status_1PreCopy /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  IlMsgLKA_Steering_Torque_Cmd_HSPreCopy /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  IlMsgAntilock_Brake_and_TC_Status_HSPreCopy /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  IlMsgPPEI_Engine_General_Status_1PreCopy /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  V_NULL /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  IlMsgNonDriven_Wheel_Grnd_Velocity_CEPreCopy /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  IlMsgDriven_Wheel_Grnd_Velocity_CEPreCopy /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  IlMsgPark_Assist_Parallel_CEPreCopy /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  IlMsgVehicle_Dynamics_ESC_Hyb_CEPreCopy /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  V_NULL /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  V_NULL /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  TpPrecopy /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  XcpPreCopy /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  TpPrecopy /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  TpFuncPrecopy /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  TpPrecopy /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  GgdaFuncPrecopy /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_INDICATION_FCT
/* ROM CATEGORY 1 START */
/* PRQA  S 1334 QAC_Can_1334 */ /* MD_Can_1334 */
V_MEMROM0 V_MEMROM1 ApplIndicationFct V_MEMROM2 CanRxApplIndicationPtr[kCanNumberOfRxObjects] = 
{
  V_NULL /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  V_NULL /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  V_NULL /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  V_NULL /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  V_NULL /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  V_NULL /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  V_NULL /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  V_NULL /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  V_NULL /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  V_NULL /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  V_NULL /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  V_NULL /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  V_NULL /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  V_NULL /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  V_NULL /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  V_NULL /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  V_NULL /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  V_NULL /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  V_NULL /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  V_NULL /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  V_NULL /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  V_NULL /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  V_NULL /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  V_NULL /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  V_NULL /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  V_NULL /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  V_NULL /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  V_NULL /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* PRQA  L:QAC_Can_1334 */

/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_INDICATION_FLAG
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanIndicationOffset[kCanNumberOfRxObjects] = 
{
  0 /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  0 /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  0 /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  0 /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  0 /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  0 /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  0 /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  0 /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  0 /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  1 /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  1 /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  1 /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  1 /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  1 /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  1 /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  1 /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  1 /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  2 /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  2 /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  2 /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  2 /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  2 /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  2 /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  2 /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  2 /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  3 /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  3 /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  3 /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  3 /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  3 /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  3 /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  3 /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  3 /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  4 /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  4 /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  4 /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  4 /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  0 /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  4 /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  0 /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  0 /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  0 /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  0 /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanIndicationMask[kCanNumberOfRxObjects] = 
{
  0x00u /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  0x01u /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  0x02u /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  0x04u /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  0x08u /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  0x10u /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  0x20u /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  0x40u /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  0x80u /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  0x01u /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  0x02u /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  0x04u /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  0x08u /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  0x10u /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  0x20u /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  0x40u /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  0x80u /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  0x01u /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  0x02u /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  0x04u /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  0x08u /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  0x10u /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  0x20u /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  0x40u /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  0x80u /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  0x02u /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  0x04u /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  0x08u /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  0x10u /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  0x20u /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  0x40u /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  0x80u /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  0x02u /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  0x04u /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  0x08u /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  0x00u /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  0x10u /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  0x00u /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  0x00u /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  0x00u /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  0x00u /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* ROM CATEGORY 1 END */


#endif




/* -----------------------------------------------------------------------------
    &&&~ Init structures
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 4 START */
/* PRQA S 3408 1 */ /* MD_Can_3408_extLinkage */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanInitObjectStartIndex[4] = 
{
  0, 
  1, 
  2, 
  3
};

/* ROM CATEGORY 4 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_0[4] = 
{
  
  {
    0x0000u, 
    0x0000u
  }, 
  
  {
    0x0000u, 
    0x0000u
  }, 
  
  {
    0x0000u, 
    0x0000u
  }, 
  
  {
    0x0000u, 
    0x0000u
  }
};
V_MEMROM0 V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_1[2] = 
{
  
  {
    0x0242u, 
    0x07FFu
  }, 
  
  {
    0x0101u, 
    0x07FFu
  }
};
V_MEMROM0 V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_2[2] = 
{
  
  {
    0x0003u, 
    0x07FFu
  }, 
  
  {
    0x0001u, 
    0x07FFu
  }
};
V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 CanInitBCFG[3] = 
{
  0x022B0004u, 
  0x022B0004u, 
  0x00160003u
};
/* ROM CATEGORY 4 END */



/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 CanTxDynRomStartIndex[kCanNumberOfChannels] = 
{
  7, 
  11, 
  28
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 CanTxDynRamStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  0, 
  0, 
  0
};

/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
/* PRQA  S 1334 QAC_Can_1334 */ /* MD_Can_1334 */
V_MEMROM0 V_MEMROM1 tCanChannelObject V_MEMROM2 CanChannelObject[kCanNumberOfChannels] = 
{
  
  {
    ApplCanChannelDummy, 
    CAN_RECEIVE_FCT_DUMMY, 
    
    {
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY
    }, 
    NmCanError, 
    IlCanCancelNotification, 
    ApplCanChannelDummy, 
    
    {
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u)
    }, 
    
    {
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u)
    }, 
    0x00u, 
    
    {
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd
    }
  }, 
  
  {
    ApplCanChannelDummy, 
    CAN_RECEIVE_FCT_DUMMY, 
    
    {
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY
    }, 
    NmCanError, 
    IlCanCancelNotification, 
    ApplCanChannelDummy, 
    
    {
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u)
    }, 
    
    {
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u)
    }, 
    0x00u, 
    
    {
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd
    }
  }, 
  
  {
    ApplCanChannelDummy, 
    CAN_RECEIVE_FCT_DUMMY, 
    
    {
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY
    }, 
    ApplCanBusOff, 
    ApplCanCancelNotification, 
    ApplCanChannelDummy, 
    
    {
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u)
    }, 
    
    {
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u)
    }, 
    0x00u, 
    
    {
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd
    }
  }
};
/* PRQA  L:QAC_Can_1334 */

/* ROM CATEGORY 1 END */

#if defined(C_ENABLE_MULTI_ECU_CONFIG)
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanPhysToLogChannel[kVNumberOfIdentities][kCanNumberOfPhysChannels] = 
{
  
  {
    0, 
    1, 
    2
  }
};
/* ROM CATEGORY 1 END */

#endif

#if defined(C_ENABLE_MULTI_ECU_CONFIG)
/* ROM CATEGORY 2 START */

V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanChannelIdentityAssignment[kCanNumberOfChannels] = 
{
  0x01u, 
  0x01u, 
  0x01u
};

/* ROM CATEGORY 2 END */

#endif

#if defined(C_ENABLE_MULTI_ECU_PHYS)
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanRxIdentityAssignment[kCanNumberOfRxObjects] = 
{
  0x01u /* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */, 
  0x01u /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */, 
  0x01u /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */, 
  0x01u /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */, 
  0x01u /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */, 
  0x01u /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */, 
  0x01u /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */, 
  0x01u /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */, 
  0x01u /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */, 
  0x01u /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */, 
  0x01u /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */, 
  0x01u /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */, 
  0x01u /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */, 
  0x01u /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */, 
  0x01u /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */, 
  0x01u /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */, 
  0x01u /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */, 
  0x01u /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */, 
  0x01u /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */, 
  0x01u /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */, 
  0x01u /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */, 
  0x01u /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */, 
  0x01u /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq [BC] */, 
  0x01u /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */, 
  0x01u /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS [BC] */, 
  0x01u /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs [BC] */, 
  0x01u /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE [BC] */, 
  0x01u /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs [BC] */
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanTxIdentityAssignment[kCanNumberOfTxObjects] = 
{
  0x01u /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  0x01u /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  0x01u /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  0x01u /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0x01u /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0x01u /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  0x01u /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  0x01u /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0x01u /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0x01u /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  0x01u /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  0x01u /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  0x01u /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  0x01u /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  0x01u /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
/* ROM CATEGORY 4 END */

#endif


/* ROM CATEGORY 1 START */
/* PRQA S 3408 1 */ /* MD_Can_3408_extLinkage */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxQueuePadBits[kCanNumberOfChannels] = 
{
  0, 
  25, 
  53
};

/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
/* PRQA S 3408 1 */ /* MD_Can_3408_extLinkage */
V_MEMROM0 V_MEMROM1 CanSignedTxHandle V_MEMROM2 CanTxQueueStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  1, 
  2, 
  3
};

/* ROM CATEGORY 1 END */

/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanChannelHandle V_MEMROM2 CanTxMsgHandleToChannel[kCanNumberOfTxObjects] = 
{
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  1, 
  1, 
  1, 
  1, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2, 
  2
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 CanTxStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  7, 
  11, 
  28
};

/* ROM CATEGORY 1 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  19, 
  26, 
  43
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxBasicStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  19, 
  26, 
  43
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxFullStartIndex[kCanNumberOfChannels+1] = 
{
  5, 
  21, 
  27, 
  43
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanLogHwTxStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  1, 
  2, 
  18
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwTxStartIndex[kCanNumberOfChannels] = 
{
  160, 
  176, 
  192
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxFullStartIndex[kCanNumberOfChannels] = 
{
  0, 
  14, 
  19
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxBasicStartIndex[kCanNumberOfChannels] = 
{
  128, 
  129, 
  130
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 4 START */

V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwUnusedStartIndex[kCanNumberOfChannels] = 
{
  1, 
  73, 
  160
};

/* ROM CATEGORY 4 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwTxStopIndex[kCanNumberOfChannels] = 
{
  161, 
  177, 
  208
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxFullStopIndex[kCanNumberOfChannels] = 
{
  14, 
  19, 
  35
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxBasicStopIndex[kCanNumberOfChannels] = 
{
  129, 
  130, 
  131
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 4 START */

V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwUnusedStopIndex[kCanNumberOfChannels] = 
{
  57, 
  138, 
  199
};

/* ROM CATEGORY 4 END */


#ifdef C_ENABLE_TX_FULLCAN_OBJECTS
/* ROM CATEGORY 2 START */
#ifdef C_ENABLE_HW_OBJ_EXCEED_255_DRV
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanTxHwObj[kCanNumberOfTxObjects] = 
{
  0xA0 /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  0xA0 /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  0xA0 /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  0xA0 /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0xA0 /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0xA0 /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  0xA0 /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  0xB0 /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0xB0 /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0xB0 /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  0xB0 /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  0xC0 /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  0xC0 /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  0xCF /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  0xCE /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  0xCD /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  0xCC /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  0xCB /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  0xCA /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  0xC9 /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  0xC8 /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  0xC7 /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  0xC6 /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  0xC5 /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  0xC4 /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  0xC3 /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  0xC2 /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  0xC1 /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
#else
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxHwObj[kCanNumberOfTxObjects] = 
{
  0xA0 /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */, 
  0xA0 /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */, 
  0xA0 /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */, 
  0xA0 /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0xA0 /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */, 
  0xA0 /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */, 
  0xA0 /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */, 
  0xB0 /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0xB0 /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */, 
  0xB0 /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */, 
  0xB0 /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */, 
  0xC0 /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */, 
  0xC0 /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */, 
  0xCF /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */, 
  0xCE /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */, 
  0xCD /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */, 
  0xCC /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */, 
  0xCB /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */, 
  0xCA /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */, 
  0xC9 /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */, 
  0xC8 /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */, 
  0xC7 /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */, 
  0xC6 /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */, 
  0xC5 /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */, 
  0xC4 /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */, 
  0xC3 /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */, 
  0xC2 /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */, 
  0xC1 /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
};
#endif

/* ROM CATEGORY 2 END */

#endif



/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwTxNormalIndex[kCanNumberOfChannels] = 
{
  160, 
  176, 
  192
};

/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 vsintx V_MEMROM2 CanTxOffsetHwToLog[kCanNumberOfChannels] = 
{
  -160, 
  -175, 
  -190
};

/* ROM CATEGORY 1 END */



/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanHwObjIndivPolling[1][kCanNumberOfHwObjIndivPolling] = 
{
  
  {
    1 /* Index: 0, HS, Wheel_Pulses_HS */, 
    1 /* Index: 1, HS, PPEI_Engine_General_Status_5 */, 
    1 /* Index: 2, HS, PPEI_Platform_Eng_Cntrl_Requests */, 
    1 /* Index: 3, HS, NonDriven_Wheel_Grnd_Velocity_HS */, 
    1 /* Index: 4, HS, Driven_Wheel_Grnd_Velocity_HS */, 
    1 /* Index: 5, HS, Driving_Mode_Control_HS */, 
    1 /* Index: 6, HS, Brake_Pedal_Driver_Status_HS */, 
    1 /* Index: 7, HS, PPEI_Trans_General_Status_2 */, 
    1 /* Index: 8, HS, PPEI_Platform_General_Status */, 
    1 /* Index: 9, HS, PPEI_Chassis_General_Status_1 */, 
    1 /* Index: 10, HS, LKA_Steering_Torque_Cmd_HS */, 
    1 /* Index: 11, HS, Antilock_Brake_and_TC_Status_HS */, 
    1 /* Index: 12, HS, PPEI_Engine_General_Status_1 */, 
    1 /* Index: 13, HS, PPEI_NonDrivn_Whl_Rotationl_Stat */, 
    1 /* Index: 14, CE, NonDriven_Wheel_Grnd_Velocity_CE */, 
    1 /* Index: 15, CE, Driven_Wheel_Grnd_Velocity_CE */, 
    1 /* Index: 16, CE, Park_Assist_Parallel_CE */, 
    1 /* Index: 17, CE, Vehicle_Dynamics_ESC_Hyb_CE */, 
    1 /* Index: 18, CE, Steering_Torque_Command_CE */, 
    1 /* Index: 19, IMC, SG16_Msg_EPS_A */, 
    1 /* Index: 20, IMC, SG15_Msg_EPS_A */, 
    1 /* Index: 21, IMC, SG14_Msg_EPS_A */, 
    1 /* Index: 22, IMC, SG13_Msg_EPS_A */, 
    1 /* Index: 23, IMC, SG12_Msg_EPS_A */, 
    1 /* Index: 24, IMC, SG11_Msg_EPS_A */, 
    1 /* Index: 25, IMC, SG10_Msg_EPS_A */, 
    1 /* Index: 26, IMC, SG9_Msg_EPS_A */, 
    1 /* Index: 27, IMC, SG8_Msg_EPS_A */, 
    1 /* Index: 28, IMC, SG7_Msg_EPS_A */, 
    1 /* Index: 29, IMC, SG6_Msg_EPS_A */, 
    1 /* Index: 30, IMC, SG5_Msg_EPS_A */, 
    1 /* Index: 31, IMC, SG4_Msg_EPS_A */, 
    1 /* Index: 32, IMC, SG3_Msg_EPS_A */, 
    1 /* Index: 33, IMC, SG2_Msg_EPS_A */, 
    1 /* Index: 34, IMC, SG1_Msg_EPS_A */, 
    0 /* Index: 35, Unused */, 
    0 /* Index: 36, Unused */, 
    0 /* Index: 37, Unused */, 
    0 /* Index: 38, Unused */, 
    0 /* Index: 39, Unused */, 
    0 /* Index: 40, Unused */, 
    0 /* Index: 41, Unused */, 
    0 /* Index: 42, Unused */, 
    0 /* Index: 43, Unused */, 
    0 /* Index: 44, Unused */, 
    0 /* Index: 45, Unused */, 
    0 /* Index: 46, Unused */, 
    0 /* Index: 47, Unused */, 
    0 /* Index: 48, Unused */, 
    0 /* Index: 49, Unused */, 
    0 /* Index: 50, Unused */, 
    0 /* Index: 51, Unused */, 
    0 /* Index: 52, Unused */, 
    0 /* Index: 53, Unused */, 
    0 /* Index: 54, Unused */, 
    0 /* Index: 55, Unused */, 
    0 /* Index: 56, Unused */, 
    0 /* Index: 57, Unused */, 
    0 /* Index: 58, Unused */, 
    0 /* Index: 59, Unused */, 
    0 /* Index: 60, Unused */, 
    0 /* Index: 61, Unused */, 
    0 /* Index: 62, Unused */, 
    0 /* Index: 63, Unused */, 
    0 /* Index: 64, Unused */, 
    0 /* Index: 65, Unused */, 
    0 /* Index: 66, Unused */, 
    0 /* Index: 67, Unused */, 
    0 /* Index: 68, Unused */, 
    0 /* Index: 69, Unused */, 
    0 /* Index: 70, Unused */, 
    0 /* Index: 71, Unused */, 
    0 /* Index: 72, Unused */, 
    0 /* Index: 73, Unused */, 
    0 /* Index: 74, Unused */, 
    0 /* Index: 75, Unused */, 
    0 /* Index: 76, Unused */, 
    0 /* Index: 77, Unused */, 
    0 /* Index: 78, Unused */, 
    0 /* Index: 79, Unused */, 
    0 /* Index: 80, Unused */, 
    0 /* Index: 81, Unused */, 
    0 /* Index: 82, Unused */, 
    0 /* Index: 83, Unused */, 
    0 /* Index: 84, Unused */, 
    0 /* Index: 85, Unused */, 
    0 /* Index: 86, Unused */, 
    0 /* Index: 87, Unused */, 
    0 /* Index: 88, Unused */, 
    0 /* Index: 89, Unused */, 
    0 /* Index: 90, Unused */, 
    0 /* Index: 91, Unused */, 
    0 /* Index: 92, Unused */, 
    0 /* Index: 93, Unused */, 
    0 /* Index: 94, Unused */, 
    0 /* Index: 95, Unused */, 
    0 /* Index: 96, Unused */, 
    0 /* Index: 97, Unused */, 
    0 /* Index: 98, Unused */, 
    0 /* Index: 99, Unused */, 
    0 /* Index: 100, Unused */, 
    0 /* Index: 101, Unused */, 
    0 /* Index: 102, Unused */, 
    0 /* Index: 103, Unused */, 
    0 /* Index: 104, Unused */, 
    0 /* Index: 105, Unused */, 
    0 /* Index: 106, Unused */, 
    0 /* Index: 107, Unused */, 
    0 /* Index: 108, Unused */, 
    0 /* Index: 109, Unused */, 
    0 /* Index: 110, Unused */, 
    0 /* Index: 111, Unused */, 
    0 /* Index: 112, Unused */, 
    0 /* Index: 113, Unused */, 
    0 /* Index: 114, Unused */, 
    0 /* Index: 115, Unused */, 
    0 /* Index: 116, Unused */, 
    0 /* Index: 117, Unused */, 
    0 /* Index: 118, Unused */, 
    0 /* Index: 119, Unused */, 
    0 /* Index: 120, Unused */, 
    0 /* Index: 121, Unused */, 
    0 /* Index: 122, Unused */, 
    0 /* Index: 123, Unused */, 
    0 /* Index: 124, Unused */, 
    0 /* Index: 125, Unused */, 
    0 /* Index: 126, Unused */, 
    0 /* Index: 127, Unused */, 
    0 /* Index: 128, HS, BasicCAN0 Rx Polling */, 
    0 /* Index: 129, CE, BasicCAN0 Rx Polling */, 
    0 /* Index: 130, IMC, BasicCAN0 Rx Polling */, 
    0 /* Index: 131, Unused */, 
    0 /* Index: 132, Unused */, 
    0 /* Index: 133, Unused */, 
    0 /* Index: 134, Unused */, 
    0 /* Index: 135, Unused */, 
    0 /* Index: 136, Unused */, 
    0 /* Index: 137, Unused */, 
    0 /* Index: 138, Unused */, 
    0 /* Index: 139, Unused */, 
    0 /* Index: 140, Unused */, 
    0 /* Index: 141, Unused */, 
    0 /* Index: 142, Unused */, 
    0 /* Index: 143, Unused */, 
    0 /* Index: 144, Unused */, 
    0 /* Index: 145, Unused */, 
    0 /* Index: 146, Unused */, 
    0 /* Index: 147, Unused */, 
    0 /* Index: 148, Unused */, 
    0 /* Index: 149, Unused */, 
    0 /* Index: 150, Unused */, 
    0 /* Index: 151, Unused */, 
    0 /* Index: 152, Unused */, 
    0 /* Index: 153, Unused */, 
    0 /* Index: 154, Unused */, 
    0 /* Index: 155, Unused */, 
    0 /* Index: 156, Unused */, 
    0 /* Index: 157, Unused */, 
    0 /* Index: 158, Unused */, 
    0 /* Index: 159, Unused */, 
    0 /* Index: 160, HS, Normal Tx Polling */, 
    0 /* Index: 161, Unused */, 
    0 /* Index: 162, Unused */, 
    0 /* Index: 163, Unused */, 
    0 /* Index: 164, Unused */, 
    0 /* Index: 165, Unused */, 
    0 /* Index: 166, Unused */, 
    0 /* Index: 167, Unused */, 
    0 /* Index: 168, Unused */, 
    0 /* Index: 169, Unused */, 
    0 /* Index: 170, Unused */, 
    0 /* Index: 171, Unused */, 
    0 /* Index: 172, Unused */, 
    0 /* Index: 173, Unused */, 
    0 /* Index: 174, Unused */, 
    0 /* Index: 175, Unused */, 
    0 /* Index: 176, CE, Normal Tx Polling */, 
    0 /* Index: 177, Unused */, 
    0 /* Index: 178, Unused */, 
    0 /* Index: 179, Unused */, 
    0 /* Index: 180, Unused */, 
    0 /* Index: 181, Unused */, 
    0 /* Index: 182, Unused */, 
    0 /* Index: 183, Unused */, 
    0 /* Index: 184, Unused */, 
    0 /* Index: 185, Unused */, 
    0 /* Index: 186, Unused */, 
    0 /* Index: 187, Unused */, 
    0 /* Index: 188, Unused */, 
    0 /* Index: 189, Unused */, 
    0 /* Index: 190, Unused */, 
    0 /* Index: 191, Unused */, 
    0 /* Index: 192, IMC, Normal Tx Polling */, 
    0 /* Index: 193, IMC, SG1_Msg_EPS_B */, 
    0 /* Index: 194, IMC, SG2_Msg_EPS_B */, 
    0 /* Index: 195, IMC, SG3_Msg_EPS_B */, 
    0 /* Index: 196, IMC, SG4_Msg_EPS_B */, 
    0 /* Index: 197, IMC, SG5_Msg_EPS_B */, 
    0 /* Index: 198, IMC, SG6_Msg_EPS_B */, 
    0 /* Index: 199, IMC, SG7_Msg_EPS_B */, 
    0 /* Index: 200, IMC, SG8_Msg_EPS_B */, 
    0 /* Index: 201, IMC, SG10_Msg_EPS_B */, 
    0 /* Index: 202, IMC, SG11_Msg_EPS_B */, 
    0 /* Index: 203, IMC, SG12_Msg_EPS_B */, 
    0 /* Index: 204, IMC, SG13_Msg_EPS_B */, 
    0 /* Index: 205, IMC, SG14_Msg_EPS_B */, 
    0 /* Index: 206, IMC, SG15_Msg_EPS_B */, 
    0 /* Index: 207, IMC, SG16_Msg_EPS_B */, 
    0 /* Index: 208, Unused */, 
    0 /* Index: 209, Unused */, 
    0 /* Index: 210, Unused */, 
    0 /* Index: 211, Unused */, 
    0 /* Index: 212, Unused */, 
    0 /* Index: 213, Unused */, 
    0 /* Index: 214, Unused */, 
    0 /* Index: 215, Unused */, 
    0 /* Index: 216, Unused */, 
    0 /* Index: 217, Unused */, 
    0 /* Index: 218, Unused */, 
    0 /* Index: 219, Unused */, 
    0 /* Index: 220, Unused */, 
    0 /* Index: 221, Unused */, 
    0 /* Index: 222, Unused */, 
    0 /* Index: 223, Unused */, 
    0 /* Index: 224, Unused */, 
    0 /* Index: 225, Unused */, 
    0 /* Index: 226, Unused */, 
    0 /* Index: 227, Unused */, 
    0 /* Index: 228, Unused */, 
    0 /* Index: 229, Unused */, 
    0 /* Index: 230, Unused */, 
    0 /* Index: 231, Unused */, 
    0 /* Index: 232, Unused */, 
    0 /* Index: 233, Unused */, 
    0 /* Index: 234, Unused */, 
    0 /* Index: 235, Unused */, 
    0 /* Index: 236, Unused */, 
    0 /* Index: 237, Unused */, 
    0 /* Index: 238, Unused */, 
    0 /* Index: 239, Unused */, 
    0 /* Index: 240, Unused */, 
    0 /* Index: 241, Unused */, 
    0 /* Index: 242, Unused */, 
    0 /* Index: 243, Unused */, 
    0 /* Index: 244, Unused */, 
    0 /* Index: 245, Unused */, 
    0 /* Index: 246, Unused */, 
    0 /* Index: 247, Unused */, 
    0 /* Index: 248, Unused */, 
    0 /* Index: 249, Unused */, 
    0 /* Index: 250, Unused */, 
    0 /* Index: 251, Unused */, 
    0 /* Index: 252, Unused */, 
    0 /* Index: 253, Unused */, 
    0 /* Index: 254, Unused */, 
    0 /* Index: 255, Unused */, 
    0 /* Index: 256, Unused */, 
    0 /* Index: 257, Unused */, 
    0 /* Index: 258, Unused */, 
    0 /* Index: 259, Unused */, 
    0 /* Index: 260, Unused */, 
    0 /* Index: 261, Unused */, 
    0 /* Index: 262, Unused */, 
    0 /* Index: 263, Unused */, 
    0 /* Index: 264, Unused */, 
    0 /* Index: 265, Unused */, 
    0 /* Index: 266, Unused */, 
    0 /* Index: 267, Unused */, 
    0 /* Index: 268, Unused */, 
    0 /* Index: 269, Unused */, 
    0 /* Index: 270, Unused */, 
    0 /* Index: 271, Unused */, 
    0 /* Index: 272, Unused */, 
    0 /* Index: 273, Unused */, 
    0 /* Index: 274, Unused */, 
    0 /* Index: 275, Unused */, 
    0 /* Index: 276, Unused */, 
    0 /* Index: 277, Unused */, 
    0 /* Index: 278, Unused */, 
    0 /* Index: 279, Unused */, 
    0 /* Index: 280, Unused */, 
    0 /* Index: 281, Unused */, 
    0 /* Index: 282, Unused */, 
    0 /* Index: 283, Unused */, 
    0 /* Index: 284, Unused */, 
    0 /* Index: 285, Unused */, 
    0 /* Index: 286, Unused */, 
    0 /* Index: 287, Unused */
  }
};
/* ROM CATEGORY 1 END */

/* -----------------------------------------------------------------------------
    &&&~ Hw specific
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanLogToPhys[kCanNumberOfHwChannels] = 
{
  0u, 
  1u, 
  2u
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanTxBufOffset[kCanNumberOfHwChannels] = 
{
  kCanTxBufOffset_0, 
  kCanTxBufOffset_1, 
  kCanTxBufOffset_2
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanChannelData V_MEMROM2 CanChannelData[kCanNumberOfHwChannels] = 
{
  
  {
    CanRxFifoDepth_0 /* CanRxFifoDepth */, 
    CanFilterRulesBc_0 /* CanFilterRulesBc */, 
    0xFFFFB172u /* CanIntcChTxBaseAdr */, 
    0xFFFFB16Eu /* CanIntcChErrorBaseAdr */, 
    { 0x00003FFFu, 0x00000000u } /* CanRxFcMask */, 
    0x0001u /* CanTxIntMask */, 
    0u /* CanFilterRulesStartIndex */, 
    0x12u /* CanFilterRulesTotalCount */, 
    4u /* CanFilterRulesBcCount */, 
    0x01u /* CanRxBcMask */, 
    0x08u /* CanRxBcMsgProcessCount */, 
    0u /* CanRxBcStartIndex */, 
    1u /* CanRxBcStopIndex */, 
    15u /* CanIntPrio */
  }, 
  
  {
    CanRxFifoDepth_1 /* CanRxFifoDepth */, 
    CanFilterRulesBc_1 /* CanFilterRulesBc */, 
    0xFFFFB178u /* CanIntcChTxBaseAdr */, 
    0xFFFFB174u /* CanIntcChErrorBaseAdr */, 
    { 0x0007C000u, 0x00000000u } /* CanRxFcMask */, 
    0x0001u /* CanTxIntMask */, 
    18u /* CanFilterRulesStartIndex */, 
    0x07u /* CanFilterRulesTotalCount */, 
    2u /* CanFilterRulesBcCount */, 
    0x02u /* CanRxBcMask */, 
    0x08u /* CanRxBcMsgProcessCount */, 
    1u /* CanRxBcStartIndex */, 
    2u /* CanRxBcStopIndex */, 
    15u /* CanIntPrio */
  }, 
  
  {
    CanRxFifoDepth_2 /* CanRxFifoDepth */, 
    CanFilterRulesBc_2 /* CanFilterRulesBc */, 
    0x00u /* CanIntcChTxBaseAdr */, 
    0x00u /* CanIntcChErrorBaseAdr */, 
    { 0xFFF80000u, 0x00000007u } /* CanRxFcMask */, 
    0xFFFFu /* CanTxIntMask */, 
    25u /* CanFilterRulesStartIndex */, 
    0x12u /* CanFilterRulesTotalCount */, 
    2u /* CanFilterRulesBcCount */, 
    0x04u /* CanRxBcMask */, 
    0x08u /* CanRxBcMsgProcessCount */, 
    2u /* CanRxBcStartIndex */, 
    3u /* CanRxBcStopIndex */, 
    15u /* CanIntPrio */
  }
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanFifoToLogChannel[kVNumberOfIdentities][kCanNumberOfRxFifos] = 
{
  
  {
    0, 
    1, 
    2
  }
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_0[1] = 
{
  0x01u
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_1[1] = 
{
  0x01u
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_2[1] = 
{
  0x01u
};
/* ROM CATEGORY 4 END */





/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245625395
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\can_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\can_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

