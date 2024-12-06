/* -----------------------------------------------------------------------------
  Filename:    tp_par.c
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Tp_Iso15765
               
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

#include "can_inc.h"
#include "tpmc.h"
#include "v_inc.h"
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 kTpTxHandle_Field[kTpTxChannelCount] = {
	  CanTxUSDT_Resp_From_EHPS_EPS_HS
	, CanTxUSDT_Resp_From_EPS_EPS_JR_CE
	, CanTxCmnMfgSrvResp
};


V_MEMROM0 V_MEMROM1 TxDataPtr V_MEMROM2 kTpTxData_Field[kTpTxChannelCount] = {
	  USDT_Resp_From_EHPS_EPS_HS._c
	, USDT_Resp_From_EPS_EPS_JR_CE._c
	, CmnMfgSrvResp._c
};


vuint8 DummyCopyToCan(TpCopyToCanInfoStructPtr infoStruct)
{
	__ApplTpTxCopyToCAN_mem(infoStruct);
	return 0;
}


V_MEMROM0 V_MEMROM1 ApplTpIndicationFct V_MEMROM2 TpRxIndication[kTpRxChannelCount] = {
	  DescPhysReqInd
	, GgdaPhysReqInd
	, ApplTpRxIndication
};

V_MEMROM0 V_MEMROM1 ApplTpRxErrorIndicationFct V_MEMROM2 TpRxErrorIndication[kTpRxChannelCount] = {
	  DescRxErrorIndication
	, GgdaRxErrorIndication
	, ApplTpRxErrorIndication
};

V_MEMROM0 V_MEMROM1 ApplTpConfirmationFct V_MEMROM2 TpTxConfirmation[kTpTxChannelCount] = {
	  DescConfirmation
	, GgdaConfirmation
	, ApplTpTxConfirmation
};

V_MEMROM0 V_MEMROM1 ApplTpGetRxBufferFct V_MEMROM2 TpGetRxBuffer[kTpRxChannelCount] = {
	  DescGetBuffer
	, GgdaPhysGetBuffer
	, ApplTpRxGetBuffer
};

V_MEMROM0 V_MEMROM1 ApplTpTxErrorIndicationFct V_MEMROM2 TpTxErrorIndication[kTpTxChannelCount] = {
	  DescTxErrorIndication
	, GgdaTxErrorIndication
	, ApplTpTxErrorIndication
};

V_MEMROM0 V_MEMROM1 ApplTpCopyToCanFct V_MEMROM2 TpTxCopyToCan[kTpTxChannelCount] = {
	  DescCopyToCAN
	, DummyCopyToCan
	, DummyCopyToCan
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 TpRxHandleToChannel[] = 
{
  0xFF /* ID: 0x000007cb, Handle: 0, T1_HostToTarget */, 
  0xFF /* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS */, 
  0xFF /* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 */, 
  0xFF /* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests */, 
  0xFF /* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS */, 
  0xFF /* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS */, 
  0xFF /* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS */, 
  0xFF /* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS */, 
  0xFF /* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 */, 
  0xFF /* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status */, 
  0xFF /* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 */, 
  0xFF /* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS */, 
  0xFF /* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS */, 
  0xFF /* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 */, 
  0xFF /* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat */, 
  0xFF /* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE */, 
  0xFF /* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE */, 
  0xFF /* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE */, 
  0xFF /* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE */, 
  0xFF /* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE */, 
  0xFF /* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A */, 
  0xFF /* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A */, 
  0xFF /* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A */, 
  0xFF /* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A */, 
  0xFF /* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A */, 
  0xFF /* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A */, 
  0xFF /* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A */, 
  0xFF /* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A */, 
  0xFF /* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A */, 
  0xFF /* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A */, 
  0xFF /* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A */, 
  0xFF /* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A */, 
  0xFF /* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A */, 
  0xFF /* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A */, 
  0xFF /* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A */, 
  0xFF /* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A */, 
  0xFF /* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI */, 
  2 /* ID: 0x00000713, Handle: 37, CmnMfgSrvReq */, 
  0xFF /* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg */, 
  0 /* ID: 0x00000242, Handle: 39, USDT_Req_to_EHPS_EPS_HS */, 
  0xFF /* ID: 0x00000101, Handle: 40, USDT_Req_to_All_HS_ECUs */, 
  1 /* ID: 0x00000242, Handle: 41, USDT_Req_to_EPS_EPS_JR_CE */, 
  0xFF /* ID: 0x00000101, Handle: 42, USDT_Req_to_All_CE_ECUs */
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 TpTxHandleToChannel[] = 
{
  0xFF /* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 */, 
  2 /* ID: 0x00000711, Handle: 1, CmnMfgSrvResp */, 
  0xFF /* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg */, 
  0 /* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS */, 
  0xFF /* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS */, 
  0xFF /* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle */, 
  0xFF /* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS */, 
  1 /* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE */, 
  0xFF /* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE */, 
  0xFF /* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE */, 
  0xFF /* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE */, 
  0xFF /* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B */, 
  0xFF /* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI */, 
  0xFF /* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B */, 
  0xFF /* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B */, 
  0xFF /* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B */, 
  0xFF /* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B */, 
  0xFF /* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B */, 
  0xFF /* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B */, 
  0xFF /* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B */, 
  0xFF /* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B */, 
  0xFF /* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B */, 
  0xFF /* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B */, 
  0xFF /* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B */, 
  0xFF /* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B */, 
  0xFF /* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B */, 
  0xFF /* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B */, 
  0xFF /* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B */
};

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245625395
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\tp_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\tp_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

