/* -----------------------------------------------------------------------------
  Filename:    drv_par.c
  Description: Toolversion: 01.01.35.01.40.03.46.01.00.00
               
               Serial Number: CBD1400346
               Customer Info: Nexteer Automotive Corporation
                              Package: GMLAN 3.1 - CANbedded License for GM; MultiChannel
                              Micro: R7F701311
                              Compiler: GHS 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyDriverBase
               
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

#include "v_inc.h"
#include "can_inc.h"

#include "drv_par.h"
/* -----------------------------------------------------------------------------
    &&&~ Message Buffers
 ----------------------------------------------------------------------------- */

/* RAM CATEGORY 2 START */
/* PRQA  S 0759 QAC_Can_0759 */ /* MD_Can_0759 */
V_MEMRAM0 V_MEMRAM1 _c_Xcp_Slave_Msg_buf V_MEMRAM2 Xcp_Slave_Msg;
V_MEMRAM0 V_MEMRAM1 _c_Xcp_Master_Msg_buf V_MEMRAM2 Xcp_Master_Msg;
V_MEMRAM0 V_MEMRAM1 _c_T1_HostToTarget_buf V_MEMRAM2 T1_HostToTarget;
V_MEMRAM0 V_MEMRAM1 _c_LKA_Steering_Trq_Overlay_Stat_HS_buf V_MEMRAM2 LKA_Steering_Trq_Overlay_Stat_HS;
V_MEMRAM0 V_MEMRAM1 _c_LKA_Steering_Torque_Cmd_HS_buf V_MEMRAM2 LKA_Steering_Torque_Cmd_HS;
V_MEMRAM0 V_MEMRAM1 _c_Wheel_Pulses_HS_buf V_MEMRAM2 Wheel_Pulses_HS;
V_MEMRAM0 V_MEMRAM1 _c_Driving_Mode_Control_HS_buf V_MEMRAM2 Driving_Mode_Control_HS;
V_MEMRAM0 V_MEMRAM1 _c_Brake_Pedal_Driver_Status_HS_buf V_MEMRAM2 Brake_Pedal_Driver_Status_HS;
V_MEMRAM0 V_MEMRAM1 _c_Power_Steering_Information_HS_buf V_MEMRAM2 Power_Steering_Information_HS;
V_MEMRAM0 V_MEMRAM1 _c_DTC_Triggered_778_buf V_MEMRAM2 DTC_Triggered_778;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Steering_Wheel_Angle_buf V_MEMRAM2 PPEI_Steering_Wheel_Angle;
V_MEMRAM0 V_MEMRAM1 _c_NonDriven_Wheel_Grnd_Velocity_HS_buf V_MEMRAM2 NonDriven_Wheel_Grnd_Velocity_HS;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Engine_General_Status_5_buf V_MEMRAM2 PPEI_Engine_General_Status_5;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Engine_General_Status_1_buf V_MEMRAM2 PPEI_Engine_General_Status_1;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Trans_General_Status_2_buf V_MEMRAM2 PPEI_Trans_General_Status_2;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_NonDrivn_Whl_Rotationl_Stat_buf V_MEMRAM2 PPEI_NonDrivn_Whl_Rotationl_Stat;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Platform_Eng_Cntrl_Requests_buf V_MEMRAM2 PPEI_Platform_Eng_Cntrl_Requests;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Platform_General_Status_buf V_MEMRAM2 PPEI_Platform_General_Status;
V_MEMRAM0 V_MEMRAM1 _c_Driven_Wheel_Grnd_Velocity_HS_buf V_MEMRAM2 Driven_Wheel_Grnd_Velocity_HS;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Chassis_General_Status_1_buf V_MEMRAM2 PPEI_Chassis_General_Status_1;
V_MEMRAM0 V_MEMRAM1 _c_Antilock_Brake_and_TC_Status_HS_buf V_MEMRAM2 Antilock_Brake_and_TC_Status_HS;
V_MEMRAM0 V_MEMRAM1 _c_UUDT_Resp_From_EHPS_EPS_HS_buf V_MEMRAM2 UUDT_Resp_From_EHPS_EPS_HS;
V_MEMRAM0 V_MEMRAM1 _c_USDT_Resp_From_EHPS_EPS_HS_buf V_MEMRAM2 USDT_Resp_From_EHPS_EPS_HS;
V_MEMRAM0 V_MEMRAM1 _c_CmnMfgSrvResp_buf V_MEMRAM2 CmnMfgSrvResp;
V_MEMRAM0 V_MEMRAM1 _c_Vehicle_Dynamics_ESC_Hyb_CE_buf V_MEMRAM2 Vehicle_Dynamics_ESC_Hyb_CE;
V_MEMRAM0 V_MEMRAM1 _c_NonDriven_Wheel_Grnd_Velocity_CE_buf V_MEMRAM2 NonDriven_Wheel_Grnd_Velocity_CE;
V_MEMRAM0 V_MEMRAM1 _c_Driven_Wheel_Grnd_Velocity_CE_buf V_MEMRAM2 Driven_Wheel_Grnd_Velocity_CE;
V_MEMRAM0 V_MEMRAM1 _c_PPEI_Steering_Wheel_Angle_CE_buf V_MEMRAM2 PPEI_Steering_Wheel_Angle_CE;
V_MEMRAM0 V_MEMRAM1 _c_Steering_Torque_Command_CE_buf V_MEMRAM2 Steering_Torque_Command_CE;
V_MEMRAM0 V_MEMRAM1 _c_Park_Assist_Parallel_CE_buf V_MEMRAM2 Park_Assist_Parallel_CE;
V_MEMRAM0 V_MEMRAM1 _c_Electric_Power_Steering_CE_buf V_MEMRAM2 Electric_Power_Steering_CE;
V_MEMRAM0 V_MEMRAM1 _c_UUDT_Resp_From_EPS_EPS_JR_CE_buf V_MEMRAM2 UUDT_Resp_From_EPS_EPS_JR_CE;
V_MEMRAM0 V_MEMRAM1 _c_USDT_Resp_From_EPS_EPS_JR_CE_buf V_MEMRAM2 USDT_Resp_From_EPS_EPS_JR_CE;
V_MEMRAM0 V_MEMRAM1 _c_Steering_Torque_Overlay_Stat_CE_buf V_MEMRAM2 Steering_Torque_Overlay_Stat_CE;
V_MEMRAM0 V_MEMRAM1 _c_SG16_Msg_EPS_B_buf V_MEMRAM2 SG16_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG16_Msg_EPS_A_buf V_MEMRAM2 SG16_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG15_Msg_EPS_B_buf V_MEMRAM2 SG15_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG15_Msg_EPS_A_buf V_MEMRAM2 SG15_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG14_Msg_EPS_B_buf V_MEMRAM2 SG14_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG14_Msg_EPS_A_buf V_MEMRAM2 SG14_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG13_Msg_EPS_B_buf V_MEMRAM2 SG13_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG13_Msg_EPS_A_buf V_MEMRAM2 SG13_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG12_Msg_EPS_B_buf V_MEMRAM2 SG12_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG12_Msg_EPS_A_buf V_MEMRAM2 SG12_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG11_Msg_EPS_B_buf V_MEMRAM2 SG11_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG11_Msg_EPS_A_buf V_MEMRAM2 SG11_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG10_Msg_EPS_B_buf V_MEMRAM2 SG10_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG10_Msg_EPS_A_buf V_MEMRAM2 SG10_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG9_Msg_EPS_B_buf V_MEMRAM2 SG9_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG9_Msg_EPS_A_buf V_MEMRAM2 SG9_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG8_Msg_EPS_B_buf V_MEMRAM2 SG8_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG8_Msg_EPS_A_buf V_MEMRAM2 SG8_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG7_Msg_EPS_B_buf V_MEMRAM2 SG7_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG7_Msg_EPS_A_buf V_MEMRAM2 SG7_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG6_Msg_EPS_B_buf V_MEMRAM2 SG6_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG6_Msg_EPS_A_buf V_MEMRAM2 SG6_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG5_Msg_EPS_B_buf V_MEMRAM2 SG5_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG5_Msg_EPS_A_buf V_MEMRAM2 SG5_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG4_Msg_EPS_B_buf V_MEMRAM2 SG4_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG4_Msg_EPS_A_buf V_MEMRAM2 SG4_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG3_Msg_EPS_B_buf V_MEMRAM2 SG3_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG3_Msg_EPS_A_buf V_MEMRAM2 SG3_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG2_Msg_EPS_B_buf V_MEMRAM2 SG2_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG2_Msg_EPS_A_buf V_MEMRAM2 SG2_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG1_Msg_EPS_B_buf V_MEMRAM2 SG1_Msg_EPS_B;
V_MEMRAM0 V_MEMRAM1 _c_SG1_Msg_EPS_A_buf V_MEMRAM2 SG1_Msg_EPS_A;
V_MEMRAM0 V_MEMRAM1 _c_SG0_Msg_EPS_B_ONLY_SCI_buf V_MEMRAM2 SG0_Msg_EPS_B_ONLY_SCI;
V_MEMRAM0 V_MEMRAM1 _c_SG0_Msg_EPS_A_ONLY_SCI_buf V_MEMRAM2 SG0_Msg_EPS_A_ONLY_SCI;
/* PRQA  L:QAC_Can_0759 */

/* RAM CATEGORY 2 END */

/* -----------------------------------------------------------------------------
    &&&~ message buffer for group signals
 ----------------------------------------------------------------------------- */

V_MEMRAM0 V_MEMRAM1 _c_DTCInfo_778_buf V_MEMRAM2 DTCInfo_778;
V_MEMRAM0 V_MEMRAM1 _c_StrWhAngGroup_0_buf V_MEMRAM2 StrWhAngGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_StrWhAngGrdGroup_0_buf V_MEMRAM2 StrWhAngGrdGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_HndsOffStrWhlDtStGroup_buf V_MEMRAM2 HndsOffStrWhlDtStGroup;
V_MEMRAM0 V_MEMRAM1 _c_LKADrvAppldTrqGroup_buf V_MEMRAM2 LKADrvAppldTrqGroup;
V_MEMRAM0 V_MEMRAM1 _c_DrvStrIntfrDtcdGroup_buf V_MEMRAM2 DrvStrIntfrDtcdGroup;
V_MEMRAM0 V_MEMRAM1 _c_StrWhAngGroup_1_buf V_MEMRAM2 StrWhAngGroup_1;
V_MEMRAM0 V_MEMRAM1 _c_StrWhAngGrdGroup_1_buf V_MEMRAM2 StrWhAngGrdGroup_1;
V_MEMRAM0 V_MEMRAM1 _c_EngOilTmpGroup_buf V_MEMRAM2 EngOilTmpGroup;
V_MEMRAM0 V_MEMRAM1 _c_EngOffTmExtRngGroup_buf V_MEMRAM2 EngOffTmExtRngGroup;
V_MEMRAM0 V_MEMRAM1 _c_OtsAirTmpCrValGroup_buf V_MEMRAM2 OtsAirTmpCrValGroup;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyLftNnDrvnGroup_0_buf V_MEMRAM2 WhlGrndVlctyLftNnDrvnGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyRtNnDrvnGroup_0_buf V_MEMRAM2 WhlGrndVlctyRtNnDrvnGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyLftDrvnGroup_0_buf V_MEMRAM2 WhlGrndVlctyLftDrvnGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyRtDrvnGroup_0_buf V_MEMRAM2 WhlGrndVlctyRtDrvnGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_TransEstGearGroup_buf V_MEMRAM2 TransEstGearGroup;
V_MEMRAM0 V_MEMRAM1 _c_TrnsShftLvrPosGroup_buf V_MEMRAM2 TrnsShftLvrPosGroup;
V_MEMRAM0 V_MEMRAM1 _c_BkupPwrModeMstrGroup_buf V_MEMRAM2 BkupPwrModeMstrGroup;
V_MEMRAM0 V_MEMRAM1 _c_VSELatAccGroup_buf V_MEMRAM2 VSELatAccGroup;
V_MEMRAM0 V_MEMRAM1 _c_BrkPdlDrvAppPrsDetcdGroup_buf V_MEMRAM2 BrkPdlDrvAppPrsDetcdGroup;
V_MEMRAM0 V_MEMRAM1 _c_VehDynYawRateGroup_buf V_MEMRAM2 VehDynYawRateGroup;
V_MEMRAM0 V_MEMRAM1 _c_VehDynOvrUndrStrGroup_0_buf V_MEMRAM2 VehDynOvrUndrStrGroup_0;
V_MEMRAM0 V_MEMRAM1 _c_LKATqOvrDltCmd_buf V_MEMRAM2 LKATqOvrDltCmd;
V_MEMRAM0 V_MEMRAM1 _c_WhlRotStatLftNDrvn_buf V_MEMRAM2 WhlRotStatLftNDrvn;
V_MEMRAM0 V_MEMRAM1 _c_WhlRotStatRghtNDrvn_buf V_MEMRAM2 WhlRotStatRghtNDrvn;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyLftNnDrvnGroup_1_buf V_MEMRAM2 WhlGrndVlctyLftNnDrvnGroup_1;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyRtNnDrvnGroup_1_buf V_MEMRAM2 WhlGrndVlctyRtNnDrvnGroup_1;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyLftDrvnGroup_1_buf V_MEMRAM2 WhlGrndVlctyLftDrvnGroup_1;
V_MEMRAM0 V_MEMRAM1 _c_WhlGrndVlctyRtDrvnGroup_1_buf V_MEMRAM2 WhlGrndVlctyRtDrvnGroup_1;
V_MEMRAM0 V_MEMRAM1 _c_StrWhlAngReq_buf V_MEMRAM2 StrWhlAngReq;
V_MEMRAM0 V_MEMRAM1 _c_VSELongAccLoResGroup_buf V_MEMRAM2 VSELongAccLoResGroup;
V_MEMRAM0 V_MEMRAM1 _c_VehDynOvrUndrStrGroup_1_buf V_MEMRAM2 VehDynOvrUndrStrGroup_1;






/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245472022
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy\drv_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy\drv_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

