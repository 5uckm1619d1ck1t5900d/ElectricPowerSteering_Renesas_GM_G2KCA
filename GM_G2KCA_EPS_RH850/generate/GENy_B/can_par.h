/* -----------------------------------------------------------------------------
  Filename:    can_par.h
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

#if !defined(__CAN_PAR_H__)
#define __CAN_PAR_H__

#include "can_cfg.h"
#include "v_inc.h"
#include "drv_par.h"

/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of callback functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 4 START */

extern void NmCanError(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */

extern void ApplCanBusOff(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */

extern void NmCanWakeUp(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */

extern void ApplCanWakeUp(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


#if defined(C_MULTIPLE_RECEIVE_CHANNEL) || defined(C_SINGLE_RECEIVE_CHANNEL)
#endif

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgWheel_Pulses_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPPEI_Engine_General_Status_5PreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPPEI_Platform_Eng_Cntrl_RequestsPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgNonDriven_Wheel_Grnd_Velocity_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgDriven_Wheel_Grnd_Velocity_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgDriving_Mode_Control_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgBrake_Pedal_Driver_Status_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPPEI_Trans_General_Status_2PreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPPEI_Platform_General_StatusPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPPEI_Chassis_General_Status_1PreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgLKA_Steering_Torque_Cmd_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgAntilock_Brake_and_TC_Status_HSPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPPEI_Engine_General_Status_1PreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgNonDriven_Wheel_Grnd_Velocity_CEPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgDriven_Wheel_Grnd_Velocity_CEPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgPark_Assist_Parallel_CEPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgVehicle_Dynamics_ESC_Hyb_CEPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpPrecopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 XcpPreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpFuncPrecopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 GgdaFuncPrecopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */


/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of confirmation functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 1 START */
extern void TpDrvConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void XcpConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void DescUudtConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void GgdaUudtConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SerlComOutpProxy_335CfmFct(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SerlComOutpProxy_1E5ChassisExpCfmFct(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */



/* -----------------------------------------------------------------------------
    &&&~ Multiple Callback Functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 3 START */
extern C_CALLBACK_1 void C_CALLBACK_2 IlCanCancelNotification(CanTransmitHandle txHandle);
/* CODE CATEGORY 3 END */
/* CODE CATEGORY 3 START */
extern C_CALLBACK_1 void C_CALLBACK_2 ApplCanCancelNotification(CanTransmitHandle txHandle);
/* CODE CATEGORY 3 END */


/* -----------------------------------------------------------------------------
    &&&~ Extern declarations Hw specififc
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 4 START */
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_0[1];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_1[1];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_2[1];
/* ROM CATEGORY 4 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 extern  V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_0[4];
V_MEMROM0 extern  V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_1[2];
V_MEMROM0 extern  V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_2[2];
/* ROM CATEGORY 4 END */





/* -----------------------------------------------------------------------------
    &&&~ Handles of send objects
 ----------------------------------------------------------------------------- */

#define CanTxDTC_Triggered_778               0
#define CanTxCmnMfgSrvResp                   1
#define CanTxXcp_Slave_Msg                   2
#define CanTxUSDT_Resp_From_EHPS_EPS_HS      3
#define CanTxUUDT_Resp_From_EHPS_EPS_HS      4
#define CanTxPPEI_Steering_Wheel_Angle       5
#define CanTxPower_Steering_Information_HS   6
#define CanTxUSDT_Resp_From_EPS_EPS_JR_CE    7
#define CanTxUUDT_Resp_From_EPS_EPS_JR_CE    8
#define CanTxElectric_Power_Steering_CE      9
#define CanTxPPEI_Steering_Wheel_Angle_CE    10
#define CanTxSG9_Msg_EPS_B                   11
#define CanTxSG0_Msg_EPS_B_ONLY_SCI          12
#define CanTxSG16_Msg_EPS_B                  13
#define CanTxSG15_Msg_EPS_B                  14
#define CanTxSG14_Msg_EPS_B                  15
#define CanTxSG13_Msg_EPS_B                  16
#define CanTxSG12_Msg_EPS_B                  17
#define CanTxSG11_Msg_EPS_B                  18
#define CanTxSG10_Msg_EPS_B                  19
#define CanTxSG8_Msg_EPS_B                   20
#define CanTxSG7_Msg_EPS_B                   21
#define CanTxSG6_Msg_EPS_B                   22
#define CanTxSG5_Msg_EPS_B                   23
#define CanTxSG4_Msg_EPS_B                   24
#define CanTxSG3_Msg_EPS_B                   25
#define CanTxSG2_Msg_EPS_B                   26
#define CanTxSG1_Msg_EPS_B                   27


/* -----------------------------------------------------------------------------
    &&&~ Access to confirmation flags
 ----------------------------------------------------------------------------- */

#define DTC_Triggered_778_conf_b             (CanConfirmationFlags.w[0].b0)
#define CanWriteSyncDTC_Triggered_778_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  DTC_Triggered_778_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Steering_Wheel_Angle_conf_b     (CanConfirmationFlags.w[0].b1)
#define CanWriteSyncPPEI_Steering_Wheel_Angle_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Steering_Wheel_Angle_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Power_Steering_Information_HS_conf_b (CanConfirmationFlags.w[0].b2)
#define CanWriteSyncPower_Steering_Information_HS_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Power_Steering_Information_HS_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Electric_Power_Steering_CE_conf_b    (CanConfirmationFlags.w[0].b3)
#define CanWriteSyncElectric_Power_Steering_CE_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Electric_Power_Steering_CE_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Steering_Wheel_Angle_CE_conf_b  (CanConfirmationFlags.w[0].b4)
#define CanWriteSyncPPEI_Steering_Wheel_Angle_CE_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Steering_Wheel_Angle_CE_conf_b = (x); \
  CanEndFlagWriteSync(); \
}


/* -----------------------------------------------------------------------------
    &&&~ Handles of receive objects
 ----------------------------------------------------------------------------- */

#define CanRxT1_HostToTarget                 0
#define CanRxWheel_Pulses_HS                 1
#define CanRxPPEI_Engine_General_Status_5    2
#define CanRxPPEI_Platform_Eng_Cntrl_Requests 3
#define CanRxNonDriven_Wheel_Grnd_Velocity_HS 4
#define CanRxDriven_Wheel_Grnd_Velocity_HS   5
#define CanRxDriving_Mode_Control_HS         6
#define CanRxBrake_Pedal_Driver_Status_HS    7
#define CanRxPPEI_Trans_General_Status_2     8
#define CanRxPPEI_Platform_General_Status    9
#define CanRxPPEI_Chassis_General_Status_1   10
#define CanRxLKA_Steering_Torque_Cmd_HS      11
#define CanRxAntilock_Brake_and_TC_Status_HS 12
#define CanRxPPEI_Engine_General_Status_1    13
#define CanRxPPEI_NonDrivn_Whl_Rotationl_Stat 14
#define CanRxNonDriven_Wheel_Grnd_Velocity_CE 15
#define CanRxDriven_Wheel_Grnd_Velocity_CE   16
#define CanRxPark_Assist_Parallel_CE         17
#define CanRxVehicle_Dynamics_ESC_Hyb_CE     18
#define CanRxSteering_Torque_Command_CE      19
#define CanRxSG16_Msg_EPS_A                  20
#define CanRxSG15_Msg_EPS_A                  21
#define CanRxSG14_Msg_EPS_A                  22
#define CanRxSG13_Msg_EPS_A                  23
#define CanRxSG12_Msg_EPS_A                  24
#define CanRxSG11_Msg_EPS_A                  25
#define CanRxSG10_Msg_EPS_A                  26
#define CanRxSG9_Msg_EPS_A                   27
#define CanRxSG8_Msg_EPS_A                   28
#define CanRxSG7_Msg_EPS_A                   29
#define CanRxSG6_Msg_EPS_A                   30
#define CanRxSG5_Msg_EPS_A                   31
#define CanRxSG4_Msg_EPS_A                   32
#define CanRxSG3_Msg_EPS_A                   33
#define CanRxSG2_Msg_EPS_A                   34
#define CanRxSG1_Msg_EPS_A                   35
#define CanRxSG0_Msg_EPS_A_ONLY_SCI          36
#define CanRxCmnMfgSrvReq                    37
#define CanRxXcp_Master_Msg                  38
#define CanRxUSDT_Req_to_EHPS_EPS_HS         39
#define CanRxUSDT_Req_to_All_HS_ECUs         40
#define CanRxUSDT_Req_to_EPS_EPS_JR_CE       41
#define CanRxUSDT_Req_to_All_CE_ECUs         42


/* -----------------------------------------------------------------------------
    &&&~ Access to indication flags
 ----------------------------------------------------------------------------- */

#define Wheel_Pulses_HS_ind_b                (CanIndicationFlags.w[0].b0)
#define CanWriteSyncWheel_Pulses_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Wheel_Pulses_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Engine_General_Status_5_ind_b   (CanIndicationFlags.w[0].b1)
#define CanWriteSyncPPEI_Engine_General_Status_5_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Engine_General_Status_5_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Platform_Eng_Cntrl_Requests_ind_b (CanIndicationFlags.w[0].b2)
#define CanWriteSyncPPEI_Platform_Eng_Cntrl_Requests_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Platform_Eng_Cntrl_Requests_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define NonDriven_Wheel_Grnd_Velocity_HS_ind_b (CanIndicationFlags.w[0].b3)
#define CanWriteSyncNonDriven_Wheel_Grnd_Velocity_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  NonDriven_Wheel_Grnd_Velocity_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Driven_Wheel_Grnd_Velocity_HS_ind_b  (CanIndicationFlags.w[0].b4)
#define CanWriteSyncDriven_Wheel_Grnd_Velocity_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Driven_Wheel_Grnd_Velocity_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Driving_Mode_Control_HS_ind_b        (CanIndicationFlags.w[0].b5)
#define CanWriteSyncDriving_Mode_Control_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Driving_Mode_Control_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Brake_Pedal_Driver_Status_HS_ind_b   (CanIndicationFlags.w[0].b6)
#define CanWriteSyncBrake_Pedal_Driver_Status_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Brake_Pedal_Driver_Status_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Trans_General_Status_2_ind_b    (CanIndicationFlags.w[0].b7)
#define CanWriteSyncPPEI_Trans_General_Status_2_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Trans_General_Status_2_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Platform_General_Status_ind_b   (CanIndicationFlags.w[0].b10)
#define CanWriteSyncPPEI_Platform_General_Status_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Platform_General_Status_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Chassis_General_Status_1_ind_b  (CanIndicationFlags.w[0].b11)
#define CanWriteSyncPPEI_Chassis_General_Status_1_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Chassis_General_Status_1_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define LKA_Steering_Torque_Cmd_HS_ind_b     (CanIndicationFlags.w[0].b12)
#define CanWriteSyncLKA_Steering_Torque_Cmd_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  LKA_Steering_Torque_Cmd_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Antilock_Brake_and_TC_Status_HS_ind_b (CanIndicationFlags.w[0].b13)
#define CanWriteSyncAntilock_Brake_and_TC_Status_HS_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Antilock_Brake_and_TC_Status_HS_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_Engine_General_Status_1_ind_b   (CanIndicationFlags.w[0].b14)
#define CanWriteSyncPPEI_Engine_General_Status_1_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_Engine_General_Status_1_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PPEI_NonDrivn_Whl_Rotationl_Stat_ind_b (CanIndicationFlags.w[0].b15)
#define CanWriteSyncPPEI_NonDrivn_Whl_Rotationl_Stat_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PPEI_NonDrivn_Whl_Rotationl_Stat_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define NonDriven_Wheel_Grnd_Velocity_CE_ind_b (CanIndicationFlags.w[0].b16)
#define CanWriteSyncNonDriven_Wheel_Grnd_Velocity_CE_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  NonDriven_Wheel_Grnd_Velocity_CE_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Driven_Wheel_Grnd_Velocity_CE_ind_b  (CanIndicationFlags.w[0].b17)
#define CanWriteSyncDriven_Wheel_Grnd_Velocity_CE_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Driven_Wheel_Grnd_Velocity_CE_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Park_Assist_Parallel_CE_ind_b        (CanIndicationFlags.w[0].b20)
#define CanWriteSyncPark_Assist_Parallel_CE_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Park_Assist_Parallel_CE_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Vehicle_Dynamics_ESC_Hyb_CE_ind_b    (CanIndicationFlags.w[0].b21)
#define CanWriteSyncVehicle_Dynamics_ESC_Hyb_CE_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Vehicle_Dynamics_ESC_Hyb_CE_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Steering_Torque_Command_CE_ind_b     (CanIndicationFlags.w[0].b22)
#define CanWriteSyncSteering_Torque_Command_CE_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Steering_Torque_Command_CE_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG16_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b23)
#define CanWriteSyncSG16_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG16_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG15_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b24)
#define CanWriteSyncSG15_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG15_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG14_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b25)
#define CanWriteSyncSG14_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG14_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG13_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b26)
#define CanWriteSyncSG13_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG13_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG12_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b27)
#define CanWriteSyncSG12_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG12_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG11_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b30)
#define CanWriteSyncSG11_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG11_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG10_Msg_EPS_A_ind_b                 (CanIndicationFlags.w[0].b31)
#define CanWriteSyncSG10_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG10_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG9_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[0].b32)
#define CanWriteSyncSG9_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG9_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG8_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[0].b33)
#define CanWriteSyncSG8_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG8_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG7_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[0].b34)
#define CanWriteSyncSG7_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG7_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG6_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[0].b35)
#define CanWriteSyncSG6_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG6_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG5_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[0].b36)
#define CanWriteSyncSG5_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG5_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG4_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[0].b37)
#define CanWriteSyncSG4_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG4_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG3_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[1].b0)
#define CanWriteSyncSG3_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG3_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG2_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[1].b1)
#define CanWriteSyncSG2_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG2_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG1_Msg_EPS_A_ind_b                  (CanIndicationFlags.w[1].b2)
#define CanWriteSyncSG1_Msg_EPS_A_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG1_Msg_EPS_A_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define SG0_Msg_EPS_A_ONLY_SCI_ind_b         (CanIndicationFlags.w[1].b3)
#define CanWriteSyncSG0_Msg_EPS_A_ONLY_SCI_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  SG0_Msg_EPS_A_ONLY_SCI_ind_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Xcp_Master_Msg_ind_b                 (CanIndicationFlags.w[1].b4)
#define CanWriteSyncXcp_Master_Msg_ind_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Xcp_Master_Msg_ind_b = (x); \
  CanEndFlagWriteSync(); \
}


/* -----------------------------------------------------------------------------
    &&&~ Access to signals
 ----------------------------------------------------------------------------- */

#define b_Xcp_Slave_Byte0_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte0)
#define b_Xcp_Slave_Byte1_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte1)
#define b_Xcp_Slave_Byte2_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte2)
#define b_Xcp_Slave_Byte3_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte3)
#define b_Xcp_Slave_Byte4_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte4)
#define b_Xcp_Slave_Byte5_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte5)
#define b_Xcp_Slave_Byte6_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte6)
#define b_Xcp_Slave_Byte7_c                  (Xcp_Slave_Msg.Xcp_Slave_Msg.Xcp_Slave_Byte7)
#define b_DgnInf_CE542_0_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_0)
#define b_DgnInf_CE542_1_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_1)
#define b_DgnInf_CE542_2_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_2)
#define b_DgnInf_CE542_3_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_3)
#define b_DgnInf_CE542_4_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_4)
#define b_DgnInf_CE542_5_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_5)
#define b_DgnInf_CE542_6_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_6)
#define b_DgnInf_CE542_7_b                   (UUDT_Resp_From_EPS_EPS_JR_CE.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_7)
#define b_SG9_Data_EPS_B_0_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_0)
#define b_SG9_Data_EPS_B_1_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_1)
#define b_SG9_Data_EPS_B_2_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_2)
#define b_SG9_Data_EPS_B_3_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_3)
#define b_SG9_Data_EPS_B_4_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_4)
#define b_SG9_Data_EPS_B_5_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_5)
#define b_SG9_Data_EPS_B_6_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_6)
#define b_SG9_Data_EPS_B_7_b                 (SG9_Msg_EPS_B.SG9_Msg_EPS_B.SG9_Data_EPS_B_7)
#define b_SG0_Data_EPS_B_0_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_0)
#define b_SG0_Data_EPS_B_1_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_1)
#define b_SG0_Data_EPS_B_2_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_2)
#define b_SG0_Data_EPS_B_3_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_3)
#define b_SG0_Data_EPS_B_4_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_4)
#define b_SG0_Data_EPS_B_5_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_5)
#define b_SG0_Data_EPS_B_6_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_6)
#define b_SG0_Data_EPS_B_7_b                 (SG0_Msg_EPS_B_ONLY_SCI.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_7)
#define b_SG16_Data_EPS_B_0_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_0)
#define b_SG16_Data_EPS_B_1_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_1)
#define b_SG16_Data_EPS_B_2_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_2)
#define b_SG16_Data_EPS_B_3_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_3)
#define b_SG16_Data_EPS_B_4_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_4)
#define b_SG16_Data_EPS_B_5_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_5)
#define b_SG16_Data_EPS_B_6_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_6)
#define b_SG16_Data_EPS_B_7_b                (SG16_Msg_EPS_B.SG16_Msg_EPS_B.SG16_Data_EPS_B_7)
#define b_SG15_Data_EPS_B_0_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_0)
#define b_SG15_Data_EPS_B_1_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_1)
#define b_SG15_Data_EPS_B_2_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_2)
#define b_SG15_Data_EPS_B_3_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_3)
#define b_SG15_Data_EPS_B_4_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_4)
#define b_SG15_Data_EPS_B_5_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_5)
#define b_SG15_Data_EPS_B_6_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_6)
#define b_SG15_Data_EPS_B_7_b                (SG15_Msg_EPS_B.SG15_Msg_EPS_B.SG15_Data_EPS_B_7)
#define b_SG14_Data_EPS_B_0_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_0)
#define b_SG14_Data_EPS_B_1_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_1)
#define b_SG14_Data_EPS_B_2_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_2)
#define b_SG14_Data_EPS_B_3_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_3)
#define b_SG14_Data_EPS_B_4_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_4)
#define b_SG14_Data_EPS_B_5_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_5)
#define b_SG14_Data_EPS_B_6_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_6)
#define b_SG14_Data_EPS_B_7_b                (SG14_Msg_EPS_B.SG14_Msg_EPS_B.SG14_Data_EPS_B_7)
#define b_SG13_Data_EPS_B_0_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_0)
#define b_SG13_Data_EPS_B_1_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_1)
#define b_SG13_Data_EPS_B_2_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_2)
#define b_SG13_Data_EPS_B_3_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_3)
#define b_SG13_Data_EPS_B_4_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_4)
#define b_SG13_Data_EPS_B_5_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_5)
#define b_SG13_Data_EPS_B_6_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_6)
#define b_SG13_Data_EPS_B_7_b                (SG13_Msg_EPS_B.SG13_Msg_EPS_B.SG13_Data_EPS_B_7)
#define b_SG12_Data_EPS_B_0_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_0)
#define b_SG12_Data_EPS_B_1_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_1)
#define b_SG12_Data_EPS_B_2_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_2)
#define b_SG12_Data_EPS_B_3_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_3)
#define b_SG12_Data_EPS_B_4_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_4)
#define b_SG12_Data_EPS_B_5_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_5)
#define b_SG12_Data_EPS_B_6_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_6)
#define b_SG12_Data_EPS_B_7_b                (SG12_Msg_EPS_B.SG12_Msg_EPS_B.SG12_Data_EPS_B_7)
#define b_SG11_Data_EPS_B_0_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_0)
#define b_SG11_Data_EPS_B_1_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_1)
#define b_SG11_Data_EPS_B_2_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_2)
#define b_SG11_Data_EPS_B_3_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_3)
#define b_SG11_Data_EPS_B_4_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_4)
#define b_SG11_Data_EPS_B_5_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_5)
#define b_SG11_Data_EPS_B_6_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_6)
#define b_SG11_Data_EPS_B_7_b                (SG11_Msg_EPS_B.SG11_Msg_EPS_B.SG11_Data_EPS_B_7)
#define b_SG10_Data_EPS_B_0_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_0)
#define b_SG10_Data_EPS_B_1_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_1)
#define b_SG10_Data_EPS_B_2_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_2)
#define b_SG10_Data_EPS_B_3_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_3)
#define b_SG10_Data_EPS_B_4_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_4)
#define b_SG10_Data_EPS_B_5_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_5)
#define b_SG10_Data_EPS_B_6_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_6)
#define b_SG10_Data_EPS_B_7_b                (SG10_Msg_EPS_B.SG10_Msg_EPS_B.SG10_Data_EPS_B_7)
#define b_SG8_Data_EPS_B_0_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_0)
#define b_SG8_Data_EPS_B_1_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_1)
#define b_SG8_Data_EPS_B_2_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_2)
#define b_SG8_Data_EPS_B_3_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_3)
#define b_SG8_Data_EPS_B_4_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_4)
#define b_SG8_Data_EPS_B_5_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_5)
#define b_SG8_Data_EPS_B_6_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_6)
#define b_SG8_Data_EPS_B_7_b                 (SG8_Msg_EPS_B.SG8_Msg_EPS_B.SG8_Data_EPS_B_7)
#define b_SG7_Data_EPS_B_0_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_0)
#define b_SG7_Data_EPS_B_1_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_1)
#define b_SG7_Data_EPS_B_2_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_2)
#define b_SG7_Data_EPS_B_3_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_3)
#define b_SG7_Data_EPS_B_4_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_4)
#define b_SG7_Data_EPS_B_5_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_5)
#define b_SG7_Data_EPS_B_6_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_6)
#define b_SG7_Data_EPS_B_7_b                 (SG7_Msg_EPS_B.SG7_Msg_EPS_B.SG7_Data_EPS_B_7)
#define b_SG6_Data_EPS_B_0_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_0)
#define b_SG6_Data_EPS_B_1_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_1)
#define b_SG6_Data_EPS_B_2_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_2)
#define b_SG6_Data_EPS_B_3_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_3)
#define b_SG6_Data_EPS_B_4_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_4)
#define b_SG6_Data_EPS_B_5_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_5)
#define b_SG6_Data_EPS_B_6_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_6)
#define b_SG6_Data_EPS_B_7_b                 (SG6_Msg_EPS_B.SG6_Msg_EPS_B.SG6_Data_EPS_B_7)
#define b_SG5_Data_EPS_B_0_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_0)
#define b_SG5_Data_EPS_B_1_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_1)
#define b_SG5_Data_EPS_B_2_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_2)
#define b_SG5_Data_EPS_B_3_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_3)
#define b_SG5_Data_EPS_B_4_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_4)
#define b_SG5_Data_EPS_B_5_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_5)
#define b_SG5_Data_EPS_B_6_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_6)
#define b_SG5_Data_EPS_B_7_b                 (SG5_Msg_EPS_B.SG5_Msg_EPS_B.SG5_Data_EPS_B_7)
#define b_SG4_Data_EPS_B_0_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_0)
#define b_SG4_Data_EPS_B_1_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_1)
#define b_SG4_Data_EPS_B_2_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_2)
#define b_SG4_Data_EPS_B_3_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_3)
#define b_SG4_Data_EPS_B_4_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_4)
#define b_SG4_Data_EPS_B_5_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_5)
#define b_SG4_Data_EPS_B_6_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_6)
#define b_SG4_Data_EPS_B_7_b                 (SG4_Msg_EPS_B.SG4_Msg_EPS_B.SG4_Data_EPS_B_7)
#define b_SG3_Data_EPS_B_0_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_0)
#define b_SG3_Data_EPS_B_1_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_1)
#define b_SG3_Data_EPS_B_2_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_2)
#define b_SG3_Data_EPS_B_3_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_3)
#define b_SG3_Data_EPS_B_4_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_4)
#define b_SG3_Data_EPS_B_5_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_5)
#define b_SG3_Data_EPS_B_6_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_6)
#define b_SG3_Data_EPS_B_7_b                 (SG3_Msg_EPS_B.SG3_Msg_EPS_B.SG3_Data_EPS_B_7)
#define b_SG2_Data_EPS_B_0_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_0)
#define b_SG2_Data_EPS_B_1_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_1)
#define b_SG2_Data_EPS_B_2_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_2)
#define b_SG2_Data_EPS_B_3_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_3)
#define b_SG2_Data_EPS_B_4_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_4)
#define b_SG2_Data_EPS_B_5_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_5)
#define b_SG2_Data_EPS_B_6_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_6)
#define b_SG2_Data_EPS_B_7_b                 (SG2_Msg_EPS_B.SG2_Msg_EPS_B.SG2_Data_EPS_B_7)
#define b_SG1_Data_EPS_B_0_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_0)
#define b_SG1_Data_EPS_B_1_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_1)
#define b_SG1_Data_EPS_B_2_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_2)
#define b_SG1_Data_EPS_B_3_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_3)
#define b_SG1_Data_EPS_B_4_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_4)
#define b_SG1_Data_EPS_B_5_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_5)
#define b_SG1_Data_EPS_B_6_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_6)
#define b_SG1_Data_EPS_B_7_b                 (SG1_Msg_EPS_B.SG1_Msg_EPS_B.SG1_Data_EPS_B_7)
#define b_SG16_Data_EPS_A_0_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_0)
#define b_SG16_Data_EPS_A_1_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_1)
#define b_SG16_Data_EPS_A_2_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_2)
#define b_SG16_Data_EPS_A_3_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_3)
#define b_SG16_Data_EPS_A_4_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_4)
#define b_SG16_Data_EPS_A_5_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_5)
#define b_SG16_Data_EPS_A_6_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_6)
#define b_SG16_Data_EPS_A_7_b                (SG16_Msg_EPS_A.SG16_Msg_EPS_A.SG16_Data_EPS_A_7)
#define b_SG15_Data_EPS_A_0_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_0)
#define b_SG15_Data_EPS_A_1_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_1)
#define b_SG15_Data_EPS_A_2_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_2)
#define b_SG15_Data_EPS_A_3_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_3)
#define b_SG15_Data_EPS_A_4_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_4)
#define b_SG15_Data_EPS_A_5_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_5)
#define b_SG15_Data_EPS_A_6_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_6)
#define b_SG15_Data_EPS_A_7_b                (SG15_Msg_EPS_A.SG15_Msg_EPS_A.SG15_Data_EPS_A_7)
#define b_SG14_Data_EPS_A_0_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_0)
#define b_SG14_Data_EPS_A_1_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_1)
#define b_SG14_Data_EPS_A_2_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_2)
#define b_SG14_Data_EPS_A_3_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_3)
#define b_SG14_Data_EPS_A_4_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_4)
#define b_SG14_Data_EPS_A_5_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_5)
#define b_SG14_Data_EPS_A_6_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_6)
#define b_SG14_Data_EPS_A_7_b                (SG14_Msg_EPS_A.SG14_Msg_EPS_A.SG14_Data_EPS_A_7)
#define b_SG13_Data_EPS_A_0_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_0)
#define b_SG13_Data_EPS_A_1_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_1)
#define b_SG13_Data_EPS_A_2_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_2)
#define b_SG13_Data_EPS_A_3_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_3)
#define b_SG13_Data_EPS_A_4_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_4)
#define b_SG13_Data_EPS_A_5_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_5)
#define b_SG13_Data_EPS_A_6_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_6)
#define b_SG13_Data_EPS_A_7_b                (SG13_Msg_EPS_A.SG13_Msg_EPS_A.SG13_Data_EPS_A_7)
#define b_SG12_Data_EPS_A_0_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_0)
#define b_SG12_Data_EPS_A_1_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_1)
#define b_SG12_Data_EPS_A_2_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_2)
#define b_SG12_Data_EPS_A_3_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_3)
#define b_SG12_Data_EPS_A_4_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_4)
#define b_SG12_Data_EPS_A_5_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_5)
#define b_SG12_Data_EPS_A_6_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_6)
#define b_SG12_Data_EPS_A_7_b                (SG12_Msg_EPS_A.SG12_Msg_EPS_A.SG12_Data_EPS_A_7)
#define b_SG11_Data_EPS_A_0_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_0)
#define b_SG11_Data_EPS_A_1_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_1)
#define b_SG11_Data_EPS_A_2_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_2)
#define b_SG11_Data_EPS_A_3_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_3)
#define b_SG11_Data_EPS_A_4_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_4)
#define b_SG11_Data_EPS_A_5_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_5)
#define b_SG11_Data_EPS_A_6_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_6)
#define b_SG11_Data_EPS_A_7_b                (SG11_Msg_EPS_A.SG11_Msg_EPS_A.SG11_Data_EPS_A_7)
#define b_SG10_Data_EPS_A_0_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_0)
#define b_SG10_Data_EPS_A_1_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_1)
#define b_SG10_Data_EPS_A_2_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_2)
#define b_SG10_Data_EPS_A_3_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_3)
#define b_SG10_Data_EPS_A_4_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_4)
#define b_SG10_Data_EPS_A_5_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_5)
#define b_SG10_Data_EPS_A_6_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_6)
#define b_SG10_Data_EPS_A_7_b                (SG10_Msg_EPS_A.SG10_Msg_EPS_A.SG10_Data_EPS_A_7)
#define b_SG9_Data_EPS_A_0_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_0)
#define b_SG9_Data_EPS_A_1_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_1)
#define b_SG9_Data_EPS_A_2_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_2)
#define b_SG9_Data_EPS_A_3_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_3)
#define b_SG9_Data_EPS_A_4_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_4)
#define b_SG9_Data_EPS_A_5_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_5)
#define b_SG9_Data_EPS_A_6_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_6)
#define b_SG9_Data_EPS_A_7_b                 (SG9_Msg_EPS_A.SG9_Msg_EPS_A.SG9_Data_EPS_A_7)
#define b_SG8_Data_EPS_A_0_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_0)
#define b_SG8_Data_EPS_A_1_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_1)
#define b_SG8_Data_EPS_A_2_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_2)
#define b_SG8_Data_EPS_A_3_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_3)
#define b_SG8_Data_EPS_A_4_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_4)
#define b_SG8_Data_EPS_A_5_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_5)
#define b_SG8_Data_EPS_A_6_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_6)
#define b_SG8_Data_EPS_A_7_b                 (SG8_Msg_EPS_A.SG8_Msg_EPS_A.SG8_Data_EPS_A_7)
#define b_SG7_Data_EPS_A_0_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_0)
#define b_SG7_Data_EPS_A_1_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_1)
#define b_SG7_Data_EPS_A_2_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_2)
#define b_SG7_Data_EPS_A_3_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_3)
#define b_SG7_Data_EPS_A_4_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_4)
#define b_SG7_Data_EPS_A_5_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_5)
#define b_SG7_Data_EPS_A_6_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_6)
#define b_SG7_Data_EPS_A_7_b                 (SG7_Msg_EPS_A.SG7_Msg_EPS_A.SG7_Data_EPS_A_7)
#define b_SG6_Data_EPS_A_0_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_0)
#define b_SG6_Data_EPS_A_1_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_1)
#define b_SG6_Data_EPS_A_2_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_2)
#define b_SG6_Data_EPS_A_3_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_3)
#define b_SG6_Data_EPS_A_4_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_4)
#define b_SG6_Data_EPS_A_5_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_5)
#define b_SG6_Data_EPS_A_6_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_6)
#define b_SG6_Data_EPS_A_7_b                 (SG6_Msg_EPS_A.SG6_Msg_EPS_A.SG6_Data_EPS_A_7)
#define b_SG5_Data_EPS_A_0_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_0)
#define b_SG5_Data_EPS_A_1_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_1)
#define b_SG5_Data_EPS_A_2_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_2)
#define b_SG5_Data_EPS_A_3_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_3)
#define b_SG5_Data_EPS_A_4_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_4)
#define b_SG5_Data_EPS_A_5_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_5)
#define b_SG5_Data_EPS_A_6_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_6)
#define b_SG5_Data_EPS_A_7_b                 (SG5_Msg_EPS_A.SG5_Msg_EPS_A.SG5_Data_EPS_A_7)
#define b_SG4_Data_EPS_A_0_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_0)
#define b_SG4_Data_EPS_A_1_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_1)
#define b_SG4_Data_EPS_A_2_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_2)
#define b_SG4_Data_EPS_A_3_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_3)
#define b_SG4_Data_EPS_A_4_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_4)
#define b_SG4_Data_EPS_A_5_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_5)
#define b_SG4_Data_EPS_A_6_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_6)
#define b_SG4_Data_EPS_A_7_b                 (SG4_Msg_EPS_A.SG4_Msg_EPS_A.SG4_Data_EPS_A_7)
#define b_SG3_Data_EPS_A_0_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_0)
#define b_SG3_Data_EPS_A_1_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_1)
#define b_SG3_Data_EPS_A_2_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_2)
#define b_SG3_Data_EPS_A_3_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_3)
#define b_SG3_Data_EPS_A_4_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_4)
#define b_SG3_Data_EPS_A_5_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_5)
#define b_SG3_Data_EPS_A_6_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_6)
#define b_SG3_Data_EPS_A_7_b                 (SG3_Msg_EPS_A.SG3_Msg_EPS_A.SG3_Data_EPS_A_7)
#define b_SG2_Data_EPS_A_0_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_0)
#define b_SG2_Data_EPS_A_1_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_1)
#define b_SG2_Data_EPS_A_2_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_2)
#define b_SG2_Data_EPS_A_3_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_3)
#define b_SG2_Data_EPS_A_4_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_4)
#define b_SG2_Data_EPS_A_5_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_5)
#define b_SG2_Data_EPS_A_6_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_6)
#define b_SG2_Data_EPS_A_7_b                 (SG2_Msg_EPS_A.SG2_Msg_EPS_A.SG2_Data_EPS_A_7)
#define b_SG1_Data_EPS_A_0_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_0)
#define b_SG1_Data_EPS_A_1_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_1)
#define b_SG1_Data_EPS_A_2_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_2)
#define b_SG1_Data_EPS_A_3_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_3)
#define b_SG1_Data_EPS_A_4_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_4)
#define b_SG1_Data_EPS_A_5_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_5)
#define b_SG1_Data_EPS_A_6_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_6)
#define b_SG1_Data_EPS_A_7_b                 (SG1_Msg_EPS_A.SG1_Msg_EPS_A.SG1_Data_EPS_A_7)
#define b_SG0_Data_EPS_A_0_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_0)
#define b_SG0_Data_EPS_A_1_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_1)
#define b_SG0_Data_EPS_A_2_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_2)
#define b_SG0_Data_EPS_A_3_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_3)
#define b_SG0_Data_EPS_A_4_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_4)
#define b_SG0_Data_EPS_A_5_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_5)
#define b_SG0_Data_EPS_A_6_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_6)
#define b_SG0_Data_EPS_A_7_b                 (SG0_Msg_EPS_A_ONLY_SCI.SG0_Msg_EPS_A_ONLY_SCI.SG0_Data_EPS_A_7)
#define b_Xcp_Master_Byte0_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte0)
#define b_Xcp_Master_Byte1_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte1)
#define b_Xcp_Master_Byte2_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte2)
#define b_Xcp_Master_Byte3_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte3)
#define b_Xcp_Master_Byte4_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte4)
#define b_Xcp_Master_Byte5_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte5)
#define b_Xcp_Master_Byte6_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte6)
#define b_Xcp_Master_Byte7_c                 (Xcp_Master_Msg.Xcp_Master_Msg.Xcp_Master_Byte7)


/* -----------------------------------------------------------------------------
    &&&~ Access to data bytes of Rx messages
 ----------------------------------------------------------------------------- */

/* ID: 0x000007cb, Handle: 0, T1_HostToTarget [BC] */
#define c1_T1_HostToTarget_c                 (T1_HostToTarget._c[0])
#define c2_T1_HostToTarget_c                 (T1_HostToTarget._c[1])
#define c3_T1_HostToTarget_c                 (T1_HostToTarget._c[2])
#define c4_T1_HostToTarget_c                 (T1_HostToTarget._c[3])
#define c5_T1_HostToTarget_c                 (T1_HostToTarget._c[4])
#define c6_T1_HostToTarget_c                 (T1_HostToTarget._c[5])
#define c7_T1_HostToTarget_c                 (T1_HostToTarget._c[6])
#define c8_T1_HostToTarget_c                 (T1_HostToTarget._c[7])

/* ID: 0x00000500, Handle: 1, Wheel_Pulses_HS [FC] */
#define c1_Wheel_Pulses_HS_c                 (Wheel_Pulses_HS._c[0])
#define c2_Wheel_Pulses_HS_c                 (Wheel_Pulses_HS._c[1])
#define c3_Wheel_Pulses_HS_c                 (Wheel_Pulses_HS._c[2])
#define c4_Wheel_Pulses_HS_c                 (Wheel_Pulses_HS._c[3])

/* ID: 0x000004d1, Handle: 2, PPEI_Engine_General_Status_5 [FC] */
#define c1_PPEI_Engine_General_Status_5_c    (PPEI_Engine_General_Status_5._c[0])
#define c2_PPEI_Engine_General_Status_5_c    (PPEI_Engine_General_Status_5._c[1])

/* ID: 0x000003f1, Handle: 3, PPEI_Platform_Eng_Cntrl_Requests [FC] */
#define c1_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[0])
#define c2_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[1])
#define c3_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[2])
#define c4_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[3])
#define c5_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[4])
#define c6_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[5])
#define c7_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[6])
#define c8_PPEI_Platform_Eng_Cntrl_Requests_c (PPEI_Platform_Eng_Cntrl_Requests._c[7])

/* ID: 0x0000034a, Handle: 4, NonDriven_Wheel_Grnd_Velocity_HS [FC] */
#define c1_NonDriven_Wheel_Grnd_Velocity_HS_c (NonDriven_Wheel_Grnd_Velocity_HS._c[0])
#define c2_NonDriven_Wheel_Grnd_Velocity_HS_c (NonDriven_Wheel_Grnd_Velocity_HS._c[1])
#define c3_NonDriven_Wheel_Grnd_Velocity_HS_c (NonDriven_Wheel_Grnd_Velocity_HS._c[2])
#define c4_NonDriven_Wheel_Grnd_Velocity_HS_c (NonDriven_Wheel_Grnd_Velocity_HS._c[3])
#define c5_NonDriven_Wheel_Grnd_Velocity_HS_c (NonDriven_Wheel_Grnd_Velocity_HS._c[4])

/* ID: 0x00000348, Handle: 5, Driven_Wheel_Grnd_Velocity_HS [FC] */
#define c1_Driven_Wheel_Grnd_Velocity_HS_c   (Driven_Wheel_Grnd_Velocity_HS._c[0])
#define c2_Driven_Wheel_Grnd_Velocity_HS_c   (Driven_Wheel_Grnd_Velocity_HS._c[1])
#define c3_Driven_Wheel_Grnd_Velocity_HS_c   (Driven_Wheel_Grnd_Velocity_HS._c[2])
#define c4_Driven_Wheel_Grnd_Velocity_HS_c   (Driven_Wheel_Grnd_Velocity_HS._c[3])
#define c5_Driven_Wheel_Grnd_Velocity_HS_c   (Driven_Wheel_Grnd_Velocity_HS._c[4])

/* ID: 0x00000232, Handle: 6, Driving_Mode_Control_HS [FC] */
#define c1_Driving_Mode_Control_HS_c         (Driving_Mode_Control_HS._c[0])
#define c2_Driving_Mode_Control_HS_c         (Driving_Mode_Control_HS._c[1])
#define c3_Driving_Mode_Control_HS_c         (Driving_Mode_Control_HS._c[2])
#define c4_Driving_Mode_Control_HS_c         (Driving_Mode_Control_HS._c[3])
#define c5_Driving_Mode_Control_HS_c         (Driving_Mode_Control_HS._c[4])

/* ID: 0x00000214, Handle: 7, Brake_Pedal_Driver_Status_HS [FC] */
#define c1_Brake_Pedal_Driver_Status_HS_c    (Brake_Pedal_Driver_Status_HS._c[0])
#define c2_Brake_Pedal_Driver_Status_HS_c    (Brake_Pedal_Driver_Status_HS._c[1])
#define c3_Brake_Pedal_Driver_Status_HS_c    (Brake_Pedal_Driver_Status_HS._c[2])
#define c4_Brake_Pedal_Driver_Status_HS_c    (Brake_Pedal_Driver_Status_HS._c[3])
#define c5_Brake_Pedal_Driver_Status_HS_c    (Brake_Pedal_Driver_Status_HS._c[4])
#define c6_Brake_Pedal_Driver_Status_HS_c    (Brake_Pedal_Driver_Status_HS._c[5])

/* ID: 0x000001f5, Handle: 8, PPEI_Trans_General_Status_2 [FC] */
#define c1_PPEI_Trans_General_Status_2_c     (PPEI_Trans_General_Status_2._c[0])
#define c2_PPEI_Trans_General_Status_2_c     (PPEI_Trans_General_Status_2._c[1])
#define c3_PPEI_Trans_General_Status_2_c     (PPEI_Trans_General_Status_2._c[2])
#define c4_PPEI_Trans_General_Status_2_c     (PPEI_Trans_General_Status_2._c[3])
#define c5_PPEI_Trans_General_Status_2_c     (PPEI_Trans_General_Status_2._c[4])
#define c6_PPEI_Trans_General_Status_2_c     (PPEI_Trans_General_Status_2._c[5])

/* ID: 0x000001f1, Handle: 9, PPEI_Platform_General_Status [FC] */
#define c1_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[0])
#define c2_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[1])
#define c3_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[2])
#define c4_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[3])
#define c5_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[4])
#define c6_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[5])
#define c7_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[6])
#define c8_PPEI_Platform_General_Status_c    (PPEI_Platform_General_Status._c[7])

/* ID: 0x000001e9, Handle: 10, PPEI_Chassis_General_Status_1 [FC] */
#define c1_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[0])
#define c2_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[1])
#define c3_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[2])
#define c4_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[3])
#define c5_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[4])
#define c6_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[5])
#define c7_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[6])
#define c8_PPEI_Chassis_General_Status_1_c   (PPEI_Chassis_General_Status_1._c[7])

/* ID: 0x00000180, Handle: 11, LKA_Steering_Torque_Cmd_HS [FC] */
#define c1_LKA_Steering_Torque_Cmd_HS_c      (LKA_Steering_Torque_Cmd_HS._c[0])
#define c2_LKA_Steering_Torque_Cmd_HS_c      (LKA_Steering_Torque_Cmd_HS._c[1])
#define c3_LKA_Steering_Torque_Cmd_HS_c      (LKA_Steering_Torque_Cmd_HS._c[2])
#define c4_LKA_Steering_Torque_Cmd_HS_c      (LKA_Steering_Torque_Cmd_HS._c[3])

/* ID: 0x0000017d, Handle: 12, Antilock_Brake_and_TC_Status_HS [FC] */
#define c1_Antilock_Brake_and_TC_Status_HS_c (Antilock_Brake_and_TC_Status_HS._c[0])

/* ID: 0x000000c9, Handle: 13, PPEI_Engine_General_Status_1 [FC] */
#define c1_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[0])
#define c2_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[1])
#define c3_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[2])
#define c4_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[3])
#define c5_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[4])
#define c6_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[5])
#define c7_PPEI_Engine_General_Status_1_c    (PPEI_Engine_General_Status_1._c[6])

/* ID: 0x000000c5, Handle: 14, PPEI_NonDrivn_Whl_Rotationl_Stat [FC] */
#define c1_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[0])
#define c2_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[1])
#define c3_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[2])
#define c4_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[3])
#define c5_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[4])
#define c6_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[5])
#define c7_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[6])
#define c8_PPEI_NonDrivn_Whl_Rotationl_Stat_c (PPEI_NonDrivn_Whl_Rotationl_Stat._c[7])

/* ID: 0x0000034a, Handle: 15, NonDriven_Wheel_Grnd_Velocity_CE [FC] */
#define c1_NonDriven_Wheel_Grnd_Velocity_CE_c (NonDriven_Wheel_Grnd_Velocity_CE._c[0])
#define c2_NonDriven_Wheel_Grnd_Velocity_CE_c (NonDriven_Wheel_Grnd_Velocity_CE._c[1])
#define c3_NonDriven_Wheel_Grnd_Velocity_CE_c (NonDriven_Wheel_Grnd_Velocity_CE._c[2])
#define c4_NonDriven_Wheel_Grnd_Velocity_CE_c (NonDriven_Wheel_Grnd_Velocity_CE._c[3])
#define c5_NonDriven_Wheel_Grnd_Velocity_CE_c (NonDriven_Wheel_Grnd_Velocity_CE._c[4])

/* ID: 0x00000348, Handle: 16, Driven_Wheel_Grnd_Velocity_CE [FC] */
#define c1_Driven_Wheel_Grnd_Velocity_CE_c   (Driven_Wheel_Grnd_Velocity_CE._c[0])
#define c2_Driven_Wheel_Grnd_Velocity_CE_c   (Driven_Wheel_Grnd_Velocity_CE._c[1])
#define c3_Driven_Wheel_Grnd_Velocity_CE_c   (Driven_Wheel_Grnd_Velocity_CE._c[2])
#define c4_Driven_Wheel_Grnd_Velocity_CE_c   (Driven_Wheel_Grnd_Velocity_CE._c[3])
#define c5_Driven_Wheel_Grnd_Velocity_CE_c   (Driven_Wheel_Grnd_Velocity_CE._c[4])

/* ID: 0x00000337, Handle: 17, Park_Assist_Parallel_CE [FC] */
#define c1_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[0])
#define c2_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[1])
#define c3_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[2])
#define c4_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[3])
#define c5_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[4])
#define c6_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[5])
#define c7_Park_Assist_Parallel_CE_c         (Park_Assist_Parallel_CE._c[6])

/* ID: 0x00000182, Handle: 18, Vehicle_Dynamics_ESC_Hyb_CE [FC] */
#define c1_Vehicle_Dynamics_ESC_Hyb_CE_c     (Vehicle_Dynamics_ESC_Hyb_CE._c[0])
#define c2_Vehicle_Dynamics_ESC_Hyb_CE_c     (Vehicle_Dynamics_ESC_Hyb_CE._c[1])
#define c3_Vehicle_Dynamics_ESC_Hyb_CE_c     (Vehicle_Dynamics_ESC_Hyb_CE._c[2])
#define c4_Vehicle_Dynamics_ESC_Hyb_CE_c     (Vehicle_Dynamics_ESC_Hyb_CE._c[3])
#define c5_Vehicle_Dynamics_ESC_Hyb_CE_c     (Vehicle_Dynamics_ESC_Hyb_CE._c[4])

/* ID: 0x00000180, Handle: 19, Steering_Torque_Command_CE [FC] */
#define c1_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[0])
#define c2_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[1])
#define c3_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[2])
#define c4_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[3])
#define c5_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[4])
#define c6_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[5])
#define c7_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[6])
#define c8_Steering_Torque_Command_CE_c      (Steering_Torque_Command_CE._c[7])

/* ID: 0x00000020, Handle: 20, SG16_Msg_EPS_A [FC] */
#define c1_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[0])
#define c2_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[1])
#define c3_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[2])
#define c4_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[3])
#define c5_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[4])
#define c6_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[5])
#define c7_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[6])
#define c8_SG16_Msg_EPS_A_c                  (SG16_Msg_EPS_A._c[7])

/* ID: 0x0000001e, Handle: 21, SG15_Msg_EPS_A [FC] */
#define c1_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[0])
#define c2_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[1])
#define c3_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[2])
#define c4_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[3])
#define c5_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[4])
#define c6_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[5])
#define c7_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[6])
#define c8_SG15_Msg_EPS_A_c                  (SG15_Msg_EPS_A._c[7])

/* ID: 0x0000001c, Handle: 22, SG14_Msg_EPS_A [FC] */
#define c1_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[0])
#define c2_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[1])
#define c3_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[2])
#define c4_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[3])
#define c5_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[4])
#define c6_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[5])
#define c7_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[6])
#define c8_SG14_Msg_EPS_A_c                  (SG14_Msg_EPS_A._c[7])

/* ID: 0x0000001a, Handle: 23, SG13_Msg_EPS_A [FC] */
#define c1_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[0])
#define c2_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[1])
#define c3_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[2])
#define c4_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[3])
#define c5_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[4])
#define c6_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[5])
#define c7_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[6])
#define c8_SG13_Msg_EPS_A_c                  (SG13_Msg_EPS_A._c[7])

/* ID: 0x00000018, Handle: 24, SG12_Msg_EPS_A [FC] */
#define c1_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[0])
#define c2_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[1])
#define c3_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[2])
#define c4_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[3])
#define c5_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[4])
#define c6_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[5])
#define c7_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[6])
#define c8_SG12_Msg_EPS_A_c                  (SG12_Msg_EPS_A._c[7])

/* ID: 0x00000016, Handle: 25, SG11_Msg_EPS_A [FC] */
#define c1_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[0])
#define c2_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[1])
#define c3_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[2])
#define c4_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[3])
#define c5_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[4])
#define c6_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[5])
#define c7_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[6])
#define c8_SG11_Msg_EPS_A_c                  (SG11_Msg_EPS_A._c[7])

/* ID: 0x00000014, Handle: 26, SG10_Msg_EPS_A [FC] */
#define c1_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[0])
#define c2_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[1])
#define c3_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[2])
#define c4_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[3])
#define c5_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[4])
#define c6_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[5])
#define c7_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[6])
#define c8_SG10_Msg_EPS_A_c                  (SG10_Msg_EPS_A._c[7])

/* ID: 0x00000012, Handle: 27, SG9_Msg_EPS_A [FC] */
#define c1_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[0])
#define c2_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[1])
#define c3_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[2])
#define c4_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[3])
#define c5_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[4])
#define c6_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[5])
#define c7_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[6])
#define c8_SG9_Msg_EPS_A_c                   (SG9_Msg_EPS_A._c[7])

/* ID: 0x00000010, Handle: 28, SG8_Msg_EPS_A [FC] */
#define c1_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[0])
#define c2_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[1])
#define c3_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[2])
#define c4_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[3])
#define c5_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[4])
#define c6_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[5])
#define c7_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[6])
#define c8_SG8_Msg_EPS_A_c                   (SG8_Msg_EPS_A._c[7])

/* ID: 0x0000000e, Handle: 29, SG7_Msg_EPS_A [FC] */
#define c1_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[0])
#define c2_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[1])
#define c3_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[2])
#define c4_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[3])
#define c5_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[4])
#define c6_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[5])
#define c7_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[6])
#define c8_SG7_Msg_EPS_A_c                   (SG7_Msg_EPS_A._c[7])

/* ID: 0x0000000c, Handle: 30, SG6_Msg_EPS_A [FC] */
#define c1_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[0])
#define c2_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[1])
#define c3_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[2])
#define c4_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[3])
#define c5_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[4])
#define c6_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[5])
#define c7_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[6])
#define c8_SG6_Msg_EPS_A_c                   (SG6_Msg_EPS_A._c[7])

/* ID: 0x0000000a, Handle: 31, SG5_Msg_EPS_A [FC] */
#define c1_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[0])
#define c2_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[1])
#define c3_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[2])
#define c4_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[3])
#define c5_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[4])
#define c6_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[5])
#define c7_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[6])
#define c8_SG5_Msg_EPS_A_c                   (SG5_Msg_EPS_A._c[7])

/* ID: 0x00000008, Handle: 32, SG4_Msg_EPS_A [FC] */
#define c1_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[0])
#define c2_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[1])
#define c3_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[2])
#define c4_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[3])
#define c5_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[4])
#define c6_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[5])
#define c7_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[6])
#define c8_SG4_Msg_EPS_A_c                   (SG4_Msg_EPS_A._c[7])

/* ID: 0x00000006, Handle: 33, SG3_Msg_EPS_A [FC] */
#define c1_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[0])
#define c2_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[1])
#define c3_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[2])
#define c4_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[3])
#define c5_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[4])
#define c6_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[5])
#define c7_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[6])
#define c8_SG3_Msg_EPS_A_c                   (SG3_Msg_EPS_A._c[7])

/* ID: 0x00000004, Handle: 34, SG2_Msg_EPS_A [FC] */
#define c1_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[0])
#define c2_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[1])
#define c3_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[2])
#define c4_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[3])
#define c5_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[4])
#define c6_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[5])
#define c7_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[6])
#define c8_SG2_Msg_EPS_A_c                   (SG2_Msg_EPS_A._c[7])

/* ID: 0x00000002, Handle: 35, SG1_Msg_EPS_A [FC] */
#define c1_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[0])
#define c2_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[1])
#define c3_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[2])
#define c4_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[3])
#define c5_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[4])
#define c6_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[5])
#define c7_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[6])
#define c8_SG1_Msg_EPS_A_c                   (SG1_Msg_EPS_A._c[7])

/* ID: 0x00000000, Handle: 36, SG0_Msg_EPS_A_ONLY_SCI [BC] */
#define c1_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[0])
#define c2_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[1])
#define c3_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[2])
#define c4_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[3])
#define c5_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[4])
#define c6_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[5])
#define c7_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[6])
#define c8_SG0_Msg_EPS_A_ONLY_SCI_c          (SG0_Msg_EPS_A_ONLY_SCI._c[7])

/* ID: 0x0000070c, Handle: 38, Xcp_Master_Msg [BC] */
#define c1_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[0])
#define c2_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[1])
#define c3_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[2])
#define c4_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[3])
#define c5_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[4])
#define c6_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[5])
#define c7_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[6])
#define c8_Xcp_Master_Msg_c                  (Xcp_Master_Msg._c[7])



/* -----------------------------------------------------------------------------
    &&&~ Access to data bytes of Tx messages
 ----------------------------------------------------------------------------- */

/* ID: 0x0000078a, Handle: 0, DTC_Triggered_778 [BC] */
#define c1_DTC_Triggered_778_c               (DTC_Triggered_778._c[0])
#define c2_DTC_Triggered_778_c               (DTC_Triggered_778._c[1])
#define c3_DTC_Triggered_778_c               (DTC_Triggered_778._c[2])
#define c4_DTC_Triggered_778_c               (DTC_Triggered_778._c[3])
#define c5_DTC_Triggered_778_c               (DTC_Triggered_778._c[4])
#define c6_DTC_Triggered_778_c               (DTC_Triggered_778._c[5])
#define c7_DTC_Triggered_778_c               (DTC_Triggered_778._c[6])

/* ID: 0x00000711, Handle: 1, CmnMfgSrvResp [BC] */
#define c1_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[0])
#define c2_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[1])
#define c3_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[2])
#define c4_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[3])
#define c5_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[4])
#define c6_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[5])
#define c7_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[6])
#define c8_CmnMfgSrvResp_c                   (CmnMfgSrvResp._c[7])

/* ID: 0x0000070a, Handle: 2, Xcp_Slave_Msg [BC] */
#define c1_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[0])
#define c2_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[1])
#define c3_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[2])
#define c4_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[3])
#define c5_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[4])
#define c6_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[5])
#define c7_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[6])
#define c8_Xcp_Slave_Msg_c                   (Xcp_Slave_Msg._c[7])

/* ID: 0x00000642, Handle: 3, USDT_Resp_From_EHPS_EPS_HS [BC] */
#define c1_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[0])
#define c2_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[1])
#define c3_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[2])
#define c4_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[3])
#define c5_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[4])
#define c6_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[5])
#define c7_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[6])
#define c8_USDT_Resp_From_EHPS_EPS_HS_c      (USDT_Resp_From_EHPS_EPS_HS._c[7])

/* ID: 0x00000542, Handle: 4, UUDT_Resp_From_EHPS_EPS_HS [BC] */
#define c1_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[0])
#define c2_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[1])
#define c3_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[2])
#define c4_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[3])
#define c5_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[4])
#define c6_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[5])
#define c7_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[6])
#define c8_UUDT_Resp_From_EHPS_EPS_HS_c      (UUDT_Resp_From_EHPS_EPS_HS._c[7])

/* ID: 0x00000185, Handle: 5, PPEI_Steering_Wheel_Angle [BC] */
#define c1_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[0])
#define c2_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[1])
#define c3_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[2])
#define c4_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[3])
#define c5_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[4])
#define c6_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[5])
#define c7_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[6])
#define c8_PPEI_Steering_Wheel_Angle_c       (PPEI_Steering_Wheel_Angle._c[7])

/* ID: 0x00000149, Handle: 6, Power_Steering_Information_HS [BC] */
#define c1_Power_Steering_Information_HS_c   (Power_Steering_Information_HS._c[0])

/* ID: 0x0000064a, Handle: 7, USDT_Resp_From_EPS_EPS_JR_CE [BC] */
#define c1_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[0])
#define c2_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[1])
#define c3_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[2])
#define c4_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[3])
#define c5_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[4])
#define c6_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[5])
#define c7_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[6])
#define c8_USDT_Resp_From_EPS_EPS_JR_CE_c    (USDT_Resp_From_EPS_EPS_JR_CE._c[7])

/* ID: 0x0000054a, Handle: 8, UUDT_Resp_From_EPS_EPS_JR_CE [BC] */
#define c1_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[0])
#define c2_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[1])
#define c3_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[2])
#define c4_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[3])
#define c5_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[4])
#define c6_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[5])
#define c7_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[6])
#define c8_UUDT_Resp_From_EPS_EPS_JR_CE_c    (UUDT_Resp_From_EPS_EPS_JR_CE._c[7])

/* ID: 0x00000336, Handle: 9, Electric_Power_Steering_CE [BC] */
#define c1_Electric_Power_Steering_CE_c      (Electric_Power_Steering_CE._c[0])
#define c2_Electric_Power_Steering_CE_c      (Electric_Power_Steering_CE._c[1])
#define c3_Electric_Power_Steering_CE_c      (Electric_Power_Steering_CE._c[2])
#define c4_Electric_Power_Steering_CE_c      (Electric_Power_Steering_CE._c[3])

/* ID: 0x00000185, Handle: 10, PPEI_Steering_Wheel_Angle_CE [BC] */
#define c1_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[0])
#define c2_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[1])
#define c3_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[2])
#define c4_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[3])
#define c5_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[4])
#define c6_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[5])
#define c7_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[6])
#define c8_PPEI_Steering_Wheel_Angle_CE_c    (PPEI_Steering_Wheel_Angle_CE._c[7])

/* ID: 0x00000013, Handle: 11, SG9_Msg_EPS_B [BC] */
#define c1_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[0])
#define c2_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[1])
#define c3_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[2])
#define c4_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[3])
#define c5_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[4])
#define c6_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[5])
#define c7_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[6])
#define c8_SG9_Msg_EPS_B_c                   (SG9_Msg_EPS_B._c[7])

/* ID: 0x00000001, Handle: 12, SG0_Msg_EPS_B_ONLY_SCI [BC] */
#define c1_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[0])
#define c2_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[1])
#define c3_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[2])
#define c4_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[3])
#define c5_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[4])
#define c6_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[5])
#define c7_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[6])
#define c8_SG0_Msg_EPS_B_ONLY_SCI_c          (SG0_Msg_EPS_B_ONLY_SCI._c[7])

/* ID: 0x00000021, Handle: 13, SG16_Msg_EPS_B [FC] */
#define c1_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[0])
#define c2_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[1])
#define c3_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[2])
#define c4_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[3])
#define c5_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[4])
#define c6_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[5])
#define c7_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[6])
#define c8_SG16_Msg_EPS_B_c                  (SG16_Msg_EPS_B._c[7])

/* ID: 0x0000001f, Handle: 14, SG15_Msg_EPS_B [FC] */
#define c1_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[0])
#define c2_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[1])
#define c3_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[2])
#define c4_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[3])
#define c5_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[4])
#define c6_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[5])
#define c7_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[6])
#define c8_SG15_Msg_EPS_B_c                  (SG15_Msg_EPS_B._c[7])

/* ID: 0x0000001d, Handle: 15, SG14_Msg_EPS_B [FC] */
#define c1_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[0])
#define c2_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[1])
#define c3_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[2])
#define c4_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[3])
#define c5_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[4])
#define c6_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[5])
#define c7_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[6])
#define c8_SG14_Msg_EPS_B_c                  (SG14_Msg_EPS_B._c[7])

/* ID: 0x0000001b, Handle: 16, SG13_Msg_EPS_B [FC] */
#define c1_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[0])
#define c2_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[1])
#define c3_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[2])
#define c4_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[3])
#define c5_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[4])
#define c6_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[5])
#define c7_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[6])
#define c8_SG13_Msg_EPS_B_c                  (SG13_Msg_EPS_B._c[7])

/* ID: 0x00000019, Handle: 17, SG12_Msg_EPS_B [FC] */
#define c1_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[0])
#define c2_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[1])
#define c3_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[2])
#define c4_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[3])
#define c5_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[4])
#define c6_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[5])
#define c7_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[6])
#define c8_SG12_Msg_EPS_B_c                  (SG12_Msg_EPS_B._c[7])

/* ID: 0x00000017, Handle: 18, SG11_Msg_EPS_B [FC] */
#define c1_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[0])
#define c2_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[1])
#define c3_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[2])
#define c4_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[3])
#define c5_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[4])
#define c6_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[5])
#define c7_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[6])
#define c8_SG11_Msg_EPS_B_c                  (SG11_Msg_EPS_B._c[7])

/* ID: 0x00000015, Handle: 19, SG10_Msg_EPS_B [FC] */
#define c1_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[0])
#define c2_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[1])
#define c3_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[2])
#define c4_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[3])
#define c5_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[4])
#define c6_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[5])
#define c7_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[6])
#define c8_SG10_Msg_EPS_B_c                  (SG10_Msg_EPS_B._c[7])

/* ID: 0x00000011, Handle: 20, SG8_Msg_EPS_B [FC] */
#define c1_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[0])
#define c2_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[1])
#define c3_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[2])
#define c4_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[3])
#define c5_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[4])
#define c6_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[5])
#define c7_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[6])
#define c8_SG8_Msg_EPS_B_c                   (SG8_Msg_EPS_B._c[7])

/* ID: 0x0000000f, Handle: 21, SG7_Msg_EPS_B [FC] */
#define c1_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[0])
#define c2_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[1])
#define c3_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[2])
#define c4_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[3])
#define c5_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[4])
#define c6_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[5])
#define c7_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[6])
#define c8_SG7_Msg_EPS_B_c                   (SG7_Msg_EPS_B._c[7])

/* ID: 0x0000000d, Handle: 22, SG6_Msg_EPS_B [FC] */
#define c1_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[0])
#define c2_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[1])
#define c3_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[2])
#define c4_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[3])
#define c5_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[4])
#define c6_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[5])
#define c7_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[6])
#define c8_SG6_Msg_EPS_B_c                   (SG6_Msg_EPS_B._c[7])

/* ID: 0x0000000b, Handle: 23, SG5_Msg_EPS_B [FC] */
#define c1_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[0])
#define c2_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[1])
#define c3_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[2])
#define c4_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[3])
#define c5_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[4])
#define c6_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[5])
#define c7_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[6])
#define c8_SG5_Msg_EPS_B_c                   (SG5_Msg_EPS_B._c[7])

/* ID: 0x00000009, Handle: 24, SG4_Msg_EPS_B [FC] */
#define c1_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[0])
#define c2_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[1])
#define c3_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[2])
#define c4_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[3])
#define c5_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[4])
#define c6_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[5])
#define c7_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[6])
#define c8_SG4_Msg_EPS_B_c                   (SG4_Msg_EPS_B._c[7])

/* ID: 0x00000007, Handle: 25, SG3_Msg_EPS_B [FC] */
#define c1_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[0])
#define c2_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[1])
#define c3_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[2])
#define c4_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[3])
#define c5_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[4])
#define c6_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[5])
#define c7_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[6])
#define c8_SG3_Msg_EPS_B_c                   (SG3_Msg_EPS_B._c[7])

/* ID: 0x00000005, Handle: 26, SG2_Msg_EPS_B [FC] */
#define c1_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[0])
#define c2_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[1])
#define c3_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[2])
#define c4_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[3])
#define c5_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[4])
#define c6_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[5])
#define c7_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[6])
#define c8_SG2_Msg_EPS_B_c                   (SG2_Msg_EPS_B._c[7])

/* ID: 0x00000003, Handle: 27, SG1_Msg_EPS_B [FC] */
#define c1_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[0])
#define c2_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[1])
#define c3_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[2])
#define c4_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[3])
#define c5_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[4])
#define c6_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[5])
#define c7_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[6])
#define c8_SG1_Msg_EPS_B_c                   (SG1_Msg_EPS_B._c[7])



/* -----------------------------------------------------------------------------
    &&&~ RDS Access
 ----------------------------------------------------------------------------- */

#define b_CAN_Xcp_Slave_Byte0_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte0)
#define b_CAN_Xcp_Slave_Byte1_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte1)
#define b_CAN_Xcp_Slave_Byte2_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte2)
#define b_CAN_Xcp_Slave_Byte3_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte3)
#define b_CAN_Xcp_Slave_Byte4_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte4)
#define b_CAN_Xcp_Slave_Byte5_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte5)
#define b_CAN_Xcp_Slave_Byte6_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte6)
#define b_CAN_Xcp_Slave_Byte7_c              (RDSTx_0.Xcp_Slave_Msg.Xcp_Slave_Byte7)

typedef struct _c_Xcp_Slave_Msg_RDS_msgTypeTag
{
  vbittype Xcp_Slave_Byte0 : 8;
  vbittype Xcp_Slave_Byte1 : 8;
  vbittype Xcp_Slave_Byte2 : 8;
  vbittype Xcp_Slave_Byte3 : 8;
  vbittype Xcp_Slave_Byte4 : 8;
  vbittype Xcp_Slave_Byte5 : 8;
  vbittype Xcp_Slave_Byte6 : 8;
  vbittype Xcp_Slave_Byte7 : 8;
} _c_Xcp_Slave_Msg_RDS_msgType;

typedef struct _c_Power_Steering_Information_HS_RDS_msgTypeTag
{
  vbittype PwrStrIO : 1;
  vbittype StrngAsstRdcdIO : 1;
  vbittype StrAsstRdcdLvl2IO : 1;
  vbittype StrAsstRdcdLvl3IO : 1;
  vbittype unused0 : 4;
} _c_Power_Steering_Information_HS_RDS_msgType;

typedef struct _c_DTC_Triggered_778_RDS_msgTypeTag
{
  vbittype DTCI_DTCTriggered_778 : 1;
  vbittype DTCIUnused7_778 : 1;
  vbittype DTCIUnused6_778 : 1;
  vbittype DTCIUnused5_778 : 1;
  vbittype DTCIUnused4_778 : 1;
  vbittype DTCIUnused3_778 : 1;
  vbittype DTCIUnused2_778 : 1;
  vbittype DTCIUnused1_778 : 1;
  vbittype DTCI_DTCSource_778 : 8;
  vbittype DTCI_DTCNumber_778_1 : 8;
  vbittype DTCI_DTCNumber_778_0 : 8;
  vbittype DTCI_DTCFailType_778 : 8;
  vbittype DTCI_CodeSupported_778 : 1;
  vbittype DTCI_CurrentStatus_778 : 1;
  vbittype DTCI_TstNPsdCdClrdSt_778 : 1;
  vbittype DTCI_TstFldCdClrdStat_778 : 1;
  vbittype DTCI_HistStat_778 : 1;
  vbittype DTCI_TstNPsdPwrUpSt_778 : 1;
  vbittype DTCI_TstFldPwrUpSt_778 : 1;
  vbittype DTCI_WrnIndRqdSt_778 : 1;
  vbittype DTCI_DTCFaultType_778 : 8;
} _c_DTC_Triggered_778_RDS_msgType;

typedef struct _c_PPEI_Steering_Wheel_Angle_RDS_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype StrWhAngMsk_0 : 1;
  vbittype StrWhlAngSenTyp_0 : 2;
  vbittype StrWhlAngSenCalStat_0 : 2;
  vbittype StrWhAngV_0 : 1;
  vbittype StrWhAng_0_1 : 8;
  vbittype StrWhAng_0_0 : 8;
  vbittype StrWhAngGrd_0_1 : 4;
  vbittype StrWhAngGrdMsk_0 : 1;
  vbittype StWhlAngAliveRollCnt_0 : 2;
  vbittype StrWhAngGrdV_0 : 1;
  vbittype StrWhAngGrd_0_0 : 8;
  vbittype unused1 : 8;
  vbittype StrAngSnsChksm_0_1 : 3;
  vbittype unused2 : 5;
  vbittype StrAngSnsChksm_0_0 : 8;
} _c_PPEI_Steering_Wheel_Angle_RDS_msgType;

typedef struct _c_UUDT_Resp_From_EHPS_EPS_HS_RDS_msgTypeTag
{
  vbittype DgnInf_HS542_7 : 8;
  vbittype DgnInf_HS542_6 : 8;
  vbittype DgnInf_HS542_5 : 8;
  vbittype DgnInf_HS542_4 : 8;
  vbittype DgnInf_HS542_3 : 8;
  vbittype DgnInf_HS542_2 : 8;
  vbittype DgnInf_HS542_1 : 8;
  vbittype DgnInf_HS542_0 : 8;
} _c_UUDT_Resp_From_EHPS_EPS_HS_RDS_msgType;

typedef struct _c_USDT_Resp_From_EHPS_EPS_HS_RDS_msgTypeTag
{
  vbittype DgnInf_0_7 : 8;
  vbittype DgnInf_0_6 : 8;
  vbittype DgnInf_0_5 : 8;
  vbittype DgnInf_0_4 : 8;
  vbittype DgnInf_0_3 : 8;
  vbittype DgnInf_0_2 : 8;
  vbittype DgnInf_0_1 : 8;
  vbittype DgnInf_0_0 : 8;
} _c_USDT_Resp_From_EHPS_EPS_HS_RDS_msgType;

typedef struct _c_CmnMfgSrvResp_RDS_msgTypeTag
{
  vbittype DgnInf_0_7 : 8;
  vbittype DgnInf_0_6 : 8;
  vbittype DgnInf_0_5 : 8;
  vbittype DgnInf_0_4 : 8;
  vbittype DgnInf_0_3 : 8;
  vbittype DgnInf_0_2 : 8;
  vbittype DgnInf_0_1 : 8;
  vbittype DgnInf_0_0 : 8;
} _c_CmnMfgSrvResp_RDS_msgType;

typedef struct _c_Wheel_Pulses_HS_RDS_msgTypeTag
{
  vbittype WhlPlsPerRevDrvn_0 : 7;
  vbittype unused0 : 1;
  vbittype WhlPlsPerRevNonDrvn_0 : 7;
  vbittype unused1 : 1;
  vbittype WhlRotStatTmstmpRes_1 : 3;
  vbittype unused2 : 5;
  vbittype WhlRotStatTmstmpRes_0 : 8;
} _c_Wheel_Pulses_HS_RDS_msgType;

typedef struct _c_PPEI_Engine_General_Status_5_RDS_msgTypeTag
{
  vbittype unused0 : 7;
  vbittype EngOilTmpV : 1;
  vbittype EngOilTmp : 8;
} _c_PPEI_Engine_General_Status_5_RDS_msgType;

typedef struct _c_PPEI_Platform_Eng_Cntrl_Requests_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 2;
  vbittype EngOffTmExtRngV : 1;
  vbittype EngOffTmVDA : 1;
  vbittype unused4 : 4;
  vbittype EngOffTmExtRng : 8;
  vbittype unused5 : 8;
  vbittype OtsAirTmpCrValV : 1;
  vbittype unused6 : 2;
  vbittype OtsAirTmpCrValMsk : 1;
  vbittype unused7 : 4;
  vbittype OtsAirTmpCrVal : 8;
} _c_PPEI_Platform_Eng_Cntrl_Requests_RDS_msgType;

typedef struct _c_NonDriven_Wheel_Grnd_Velocity_HS_RDS_msgTypeTag
{
  vbittype WhlGrndVlctyLftNnDrvn_0_1 : 6;
  vbittype WhlGrndVlctyLftNnDrvnV_0 : 1;
  vbittype unused0 : 1;
  vbittype WhlGrndVlctyLftNnDrvn_0_0 : 8;
  vbittype WhlGrndVlctyRtNnDrvn_0_1 : 6;
  vbittype WhlGrndVlctyRtNnDrvnV_0 : 1;
  vbittype unused1 : 1;
  vbittype WhlGrndVlctyRtNnDrvn_0_0 : 8;
  vbittype WhlRotDrctnlSRtNDrvn : 3;
  vbittype WhlRotDrctnlStLfNDrvn : 3;
  vbittype unused2 : 2;
} _c_NonDriven_Wheel_Grnd_Velocity_HS_RDS_msgType;

typedef struct _c_Driven_Wheel_Grnd_Velocity_HS_RDS_msgTypeTag
{
  vbittype WhlGrndVlctyLftDrvn_0_1 : 6;
  vbittype WhlGrndVlctyLftDrvnV_0 : 1;
  vbittype unused0 : 1;
  vbittype WhlGrndVlctyLftDrvn_0_0 : 8;
  vbittype WhlGrndVlctyRtDrvn_0_1 : 6;
  vbittype WhlGrndVlctyRtDrvnV_0 : 1;
  vbittype unused1 : 1;
  vbittype WhlGrndVlctyRtDrvn_0_0 : 8;
  vbittype WhlRotDrctnlStRtDrvn : 3;
  vbittype WhlRotDrctnlStLftDrvn : 3;
  vbittype unused2 : 2;
} _c_Driven_Wheel_Grnd_Velocity_HS_RDS_msgType;

typedef struct _c_Driving_Mode_Control_HS_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 3;
  vbittype StgSysPerfMdRq : 3;
  vbittype unused4 : 2;
  vbittype DrvMdCntrlState : 8;
} _c_Driving_Mode_Control_HS_RDS_msgType;

typedef struct _c_Brake_Pedal_Driver_Status_HS_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 1;
  vbittype AutoBrkngAvlbl : 1;
  vbittype unused3 : 6;
  vbittype unused4 : 8;
  vbittype unused5 : 5;
  vbittype RedntVSEActARC : 2;
  vbittype RedntVSEAct : 1;
  vbittype unused6 : 2;
  vbittype ABSActvProtPVal : 2;
  vbittype ABSActvProtARC : 2;
  vbittype ABSActvProt : 1;
  vbittype unused7 : 1;
} _c_Brake_Pedal_Driver_Status_HS_RDS_msgType;

typedef struct _c_PPEI_Trans_General_Status_2_RDS_msgTypeTag
{
  vbittype TransEstGear : 4;
  vbittype TransEstGearV : 1;
  vbittype unused0 : 3;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype TrnsShftLvrPos : 4;
  vbittype TrnsShftLvrPosV : 1;
  vbittype unused3 : 3;
  vbittype unused4 : 8;
  vbittype unused5 : 2;
  vbittype TrnShftPtrnActStat : 3;
  vbittype unused6 : 3;
} _c_PPEI_Trans_General_Status_2_RDS_msgType;

typedef struct _c_PPEI_Platform_General_Status_RDS_msgTypeTag
{
  vbittype SysPwrMd : 2;
  vbittype unused0 : 2;
  vbittype SysBkUpPwrMd : 2;
  vbittype SysBkupPwrMdEn : 1;
  vbittype BkupPwrModeMstrVDA : 1;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 2;
  vbittype TrStLgMdAtv : 1;
  vbittype unused5 : 5;
} _c_PPEI_Platform_General_Status_RDS_msgType;

typedef struct _c_PPEI_Chassis_General_Status_1_RDS_msgTypeTag
{
  vbittype VSELatAcc_1 : 4;
  vbittype VSELatAccV : 1;
  vbittype unused0 : 1;
  vbittype BrkPdlDrvAppPrsDetcd : 1;
  vbittype BrkPdlDrvAppPrsDetcdV : 1;
  vbittype VSELatAcc_0 : 8;
  vbittype unused1 : 8;
  vbittype VSEAct_0 : 1;
  vbittype unused2 : 1;
  vbittype TracCntrlSysDrIntnt : 1;
  vbittype TCSysEnbld : 1;
  vbittype TCSysAtv : 1;
  vbittype ABSFld : 1;
  vbittype ABSAtv_0 : 1;
  vbittype unused3 : 1;
  vbittype VehDynYawRate_1 : 4;
  vbittype VehDynYawRateV : 1;
  vbittype VhDynCntlSysSt : 3;
  vbittype VehDynYawRate_0 : 8;
  vbittype VehDynOvrUndrStr_0_1 : 2;
  vbittype VehDynOvrUndrStrV_0 : 1;
  vbittype unused4 : 5;
  vbittype VehDynOvrUndrStr_0_0 : 8;
} _c_PPEI_Chassis_General_Status_1_RDS_msgType;

typedef struct _c_LKA_Steering_Torque_Cmd_HS_RDS_msgTypeTag
{
  vbittype LKATODC_TrqVl_1 : 3;
  vbittype LKATODC_TrqRqAct : 1;
  vbittype LKATqOvrDltCmdRC : 2;
  vbittype unused0 : 2;
  vbittype LKATODC_TrqVl_0 : 8;
  vbittype LKATqOvrDltCmdPrtVl_1 : 4;
  vbittype unused1 : 4;
  vbittype LKATqOvrDltCmdPrtVl_0 : 8;
} _c_LKA_Steering_Torque_Cmd_HS_RDS_msgType;

typedef struct _c_Antilock_Brake_and_TC_Status_HS_RDS_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype VehStabEnhmntStat_0 : 3;
  vbittype TCSysOpMd : 3;
} _c_Antilock_Brake_and_TC_Status_HS_RDS_msgType;

typedef struct _c_PPEI_Engine_General_Status_1_RDS_msgTypeTag
{
  vbittype EngSpdStat : 2;
  vbittype unused0 : 4;
  vbittype PT_CrnkAct : 1;
  vbittype EngRunAtv : 1;
  vbittype EngSpd_1 : 8;
  vbittype EngSpd_0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 5;
  vbittype Eng12vStrtrMtrCmmdOn : 1;
  vbittype unused5 : 2;
} _c_PPEI_Engine_General_Status_1_RDS_msgType;

typedef struct _c_PPEI_NonDrivn_Whl_Rotationl_Stat_RDS_msgTypeTag
{
  vbittype WRSLNDWhlDistPCntr_1 : 2;
  vbittype WRSLNDWhlDistVal : 1;
  vbittype WRSLNDWhlRotStRst : 1;
  vbittype WRSLNDSeqNum : 2;
  vbittype WRSLNDWhlDisTpRC : 2;
  vbittype WRSLNDWhlDistPCntr_0 : 8;
  vbittype WRSLNDWhlDistTstm_1 : 8;
  vbittype WRSLNDWhlDistTstm_0 : 8;
  vbittype WRSRNDWhlDistPCntr_1 : 2;
  vbittype WRSRNDWhlDistVal : 1;
  vbittype WRSRNDWhlRotStRst : 1;
  vbittype WRSRNDSeqNum : 2;
  vbittype WRSRNDWhlDisTpRC : 2;
  vbittype WRSRNDWhlDistPCntr_0 : 8;
  vbittype WRSRNDWhlDistTstm_1 : 8;
  vbittype WRSRNDWhlDistTstm_0 : 8;
} _c_PPEI_NonDrivn_Whl_Rotationl_Stat_RDS_msgType;

#define b_CAN_Xcp_Master_Byte0_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte0)
#define b_CAN_Xcp_Master_Byte1_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte1)
#define b_CAN_Xcp_Master_Byte2_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte2)
#define b_CAN_Xcp_Master_Byte3_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte3)
#define b_CAN_Xcp_Master_Byte4_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte4)
#define b_CAN_Xcp_Master_Byte5_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte5)
#define b_CAN_Xcp_Master_Byte6_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte6)
#define b_CAN_Xcp_Master_Byte7_c             (RDSBasic_0.Xcp_Master_Msg.Xcp_Master_Byte7)

typedef struct _c_Xcp_Master_Msg_RDS_msgTypeTag
{
  vbittype Xcp_Master_Byte0 : 8;
  vbittype Xcp_Master_Byte1 : 8;
  vbittype Xcp_Master_Byte2 : 8;
  vbittype Xcp_Master_Byte3 : 8;
  vbittype Xcp_Master_Byte4 : 8;
  vbittype Xcp_Master_Byte5 : 8;
  vbittype Xcp_Master_Byte6 : 8;
  vbittype Xcp_Master_Byte7 : 8;
} _c_Xcp_Master_Msg_RDS_msgType;

typedef struct _c_T1_HostToTarget_RDS_msgTypeTag
{
  vbittype T1_HostToTarget_0 : 8;
  vbittype T1_HostToTarget_1 : 8;
  vbittype T1_HostToTarget_2 : 8;
  vbittype T1_HostToTarget_3 : 8;
  vbittype T1_HostToTarget_4 : 8;
  vbittype T1_HostToTarget_5 : 8;
  vbittype T1_HostToTarget_6 : 8;
  vbittype T1_HostToTarget_7 : 8;
} _c_T1_HostToTarget_RDS_msgType;

typedef struct _c_USDT_Req_to_EHPS_EPS_HS_RDS_msgTypeTag
{
  vbittype DgnInf_0_7 : 8;
  vbittype DgnInf_0_6 : 8;
  vbittype DgnInf_0_5 : 8;
  vbittype DgnInf_0_4 : 8;
  vbittype DgnInf_0_3 : 8;
  vbittype DgnInf_0_2 : 8;
  vbittype DgnInf_0_1 : 8;
  vbittype DgnInf_0_0 : 8;
} _c_USDT_Req_to_EHPS_EPS_HS_RDS_msgType;

typedef struct _c_USDT_Req_to_All_HS_ECUs_RDS_msgTypeTag
{
  vbittype DgnInf_0_7 : 8;
  vbittype DgnInf_0_6 : 8;
  vbittype DgnInf_0_5 : 8;
  vbittype DgnInf_0_4 : 8;
  vbittype DgnInf_0_3 : 8;
  vbittype DgnInf_0_2 : 8;
  vbittype DgnInf_0_1 : 8;
  vbittype DgnInf_0_0 : 8;
} _c_USDT_Req_to_All_HS_ECUs_RDS_msgType;

typedef struct _c_CmnMfgSrvReq_RDS_msgTypeTag
{
  vbittype DgnInf_0_7 : 8;
  vbittype DgnInf_0_6 : 8;
  vbittype DgnInf_0_5 : 8;
  vbittype DgnInf_0_4 : 8;
  vbittype DgnInf_0_3 : 8;
  vbittype DgnInf_0_2 : 8;
  vbittype DgnInf_0_1 : 8;
  vbittype DgnInf_0_0 : 8;
} _c_CmnMfgSrvReq_RDS_msgType;

typedef union _c_RDS_Tx_buf_0Tag
{
  vuint8 _c[8];
  _c_Xcp_Slave_Msg_RDS_msgType Xcp_Slave_Msg;
  _c_Power_Steering_Information_HS_RDS_msgType Power_Steering_Information_HS;
  _c_DTC_Triggered_778_RDS_msgType DTC_Triggered_778;
  _c_PPEI_Steering_Wheel_Angle_RDS_msgType PPEI_Steering_Wheel_Angle;
  _c_UUDT_Resp_From_EHPS_EPS_HS_RDS_msgType UUDT_Resp_From_EHPS_EPS_HS;
  _c_USDT_Resp_From_EHPS_EPS_HS_RDS_msgType USDT_Resp_From_EHPS_EPS_HS;
  _c_CmnMfgSrvResp_RDS_msgType CmnMfgSrvResp;
} _c_RDS_Tx_buf_0;
typedef union _c_RDS0_bufTag
{
  vuint8 _c[4];
  _c_Wheel_Pulses_HS_RDS_msgType Wheel_Pulses_HS;
} _c_RDS0_buf;
typedef union _c_RDS1_bufTag
{
  vuint8 _c[2];
  _c_PPEI_Engine_General_Status_5_RDS_msgType PPEI_Engine_General_Status_5;
} _c_RDS1_buf;
typedef union _c_RDS2_bufTag
{
  vuint8 _c[8];
  _c_PPEI_Platform_Eng_Cntrl_Requests_RDS_msgType PPEI_Platform_Eng_Cntrl_Requests;
} _c_RDS2_buf;
typedef union _c_RDS3_bufTag
{
  vuint8 _c[5];
  _c_NonDriven_Wheel_Grnd_Velocity_HS_RDS_msgType NonDriven_Wheel_Grnd_Velocity_HS;
} _c_RDS3_buf;
typedef union _c_RDS4_bufTag
{
  vuint8 _c[5];
  _c_Driven_Wheel_Grnd_Velocity_HS_RDS_msgType Driven_Wheel_Grnd_Velocity_HS;
} _c_RDS4_buf;
typedef union _c_RDS5_bufTag
{
  vuint8 _c[5];
  _c_Driving_Mode_Control_HS_RDS_msgType Driving_Mode_Control_HS;
} _c_RDS5_buf;
typedef union _c_RDS6_bufTag
{
  vuint8 _c[6];
  _c_Brake_Pedal_Driver_Status_HS_RDS_msgType Brake_Pedal_Driver_Status_HS;
} _c_RDS6_buf;
typedef union _c_RDS7_bufTag
{
  vuint8 _c[6];
  _c_PPEI_Trans_General_Status_2_RDS_msgType PPEI_Trans_General_Status_2;
} _c_RDS7_buf;
typedef union _c_RDS8_bufTag
{
  vuint8 _c[8];
  _c_PPEI_Platform_General_Status_RDS_msgType PPEI_Platform_General_Status;
} _c_RDS8_buf;
typedef union _c_RDS9_bufTag
{
  vuint8 _c[8];
  _c_PPEI_Chassis_General_Status_1_RDS_msgType PPEI_Chassis_General_Status_1;
} _c_RDS9_buf;
typedef union _c_RDS10_bufTag
{
  vuint8 _c[4];
  _c_LKA_Steering_Torque_Cmd_HS_RDS_msgType LKA_Steering_Torque_Cmd_HS;
} _c_RDS10_buf;
typedef union _c_RDS11_bufTag
{
  vuint8 _c[1];
  _c_Antilock_Brake_and_TC_Status_HS_RDS_msgType Antilock_Brake_and_TC_Status_HS;
} _c_RDS11_buf;
typedef union _c_RDS12_bufTag
{
  vuint8 _c[7];
  _c_PPEI_Engine_General_Status_1_RDS_msgType PPEI_Engine_General_Status_1;
} _c_RDS12_buf;
typedef union _c_RDS13_bufTag
{
  vuint8 _c[8];
  _c_PPEI_NonDrivn_Whl_Rotationl_Stat_RDS_msgType PPEI_NonDrivn_Whl_Rotationl_Stat;
} _c_RDS13_buf;
typedef union _c_RDSBasic_buf_0Tag
{
  vuint8 _c[8];
  _c_Xcp_Master_Msg_RDS_msgType Xcp_Master_Msg;
  _c_T1_HostToTarget_RDS_msgType T1_HostToTarget;
  _c_USDT_Req_to_EHPS_EPS_HS_RDS_msgType USDT_Req_to_EHPS_EPS_HS;
  _c_USDT_Req_to_All_HS_ECUs_RDS_msgType USDT_Req_to_All_HS_ECUs;
  _c_CmnMfgSrvReq_RDS_msgType CmnMfgSrvReq;
} _c_RDSBasic_buf_0;


#define RDSTx_0                              ((* ((_c_RDS_Tx_buf_0 MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xa00))))
#define RDS0                                 ((* ((_c_RDS0_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS1                                 ((* ((_c_RDS1_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS2                                 ((* ((_c_RDS2_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS3                                 ((* ((_c_RDS3_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS4                                 ((* ((_c_RDS4_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS5                                 ((* ((_c_RDS5_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS6                                 ((* ((_c_RDS6_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS7                                 ((* ((_c_RDS7_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS8                                 ((* ((_c_RDS8_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS9                                 ((* ((_c_RDS9_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS10                                ((* ((_c_RDS10_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS11                                ((* ((_c_RDS11_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS12                                ((* ((_c_RDS12_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS13                                ((* ((_c_RDS13_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDSBasic_0                           ((* ((_c_RDSBasic_buf_0 MEMORY_NORMAL *)(canRDSRxPtr[0]))))

typedef struct _c_PPEI_Steering_Wheel_Angle_CE_RDS_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype StrWhAngMsk_1 : 1;
  vbittype StrWhlAngSenTyp_1 : 2;
  vbittype StrWhlAngSenCalStat_1 : 2;
  vbittype StrWhAngV_1 : 1;
  vbittype StrWhAng_1_1 : 8;
  vbittype StrWhAng_1_0 : 8;
  vbittype StrWhAngGrd_1_1 : 4;
  vbittype StrWhAngGrdMsk_1 : 1;
  vbittype StWhlAngAliveRollCnt_1 : 2;
  vbittype StrWhAngGrdV_1 : 1;
  vbittype StrWhAngGrd_1_0 : 8;
  vbittype unused1 : 8;
  vbittype StrAngSnsChksm_1_1 : 3;
  vbittype unused2 : 5;
  vbittype StrAngSnsChksm_1_0 : 8;
} _c_PPEI_Steering_Wheel_Angle_CE_RDS_msgType;

typedef struct _c_Electric_Power_Steering_CE_RDS_msgTypeTag
{
  vbittype ElecPwrStrAvalStat : 2;
  vbittype DrvStrIntfrDtcdV : 1;
  vbittype DrvStrIntfrDtcd : 1;
  vbittype DrvStrIntfrDetARC : 2;
  vbittype DrvStrIntfrDetPrtVal : 2;
  vbittype ElcPwrStrAvalStatARC : 2;
  vbittype ElcPwrStrAvalStatPVal : 2;
  vbittype unused0 : 4;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
} _c_Electric_Power_Steering_CE_RDS_msgType;

#define b_CAN_DgnInf_CE542_0_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_0)
#define b_CAN_DgnInf_CE542_1_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_1)
#define b_CAN_DgnInf_CE542_2_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_2)
#define b_CAN_DgnInf_CE542_3_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_3)
#define b_CAN_DgnInf_CE542_4_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_4)
#define b_CAN_DgnInf_CE542_5_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_5)
#define b_CAN_DgnInf_CE542_6_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_6)
#define b_CAN_DgnInf_CE542_7_b               (RDSTx_1.UUDT_Resp_From_EPS_EPS_JR_CE.DgnInf_CE542_7)

typedef struct _c_UUDT_Resp_From_EPS_EPS_JR_CE_RDS_msgTypeTag
{
  vbittype DgnInf_CE542_7 : 8;
  vbittype DgnInf_CE542_6 : 8;
  vbittype DgnInf_CE542_5 : 8;
  vbittype DgnInf_CE542_4 : 8;
  vbittype DgnInf_CE542_3 : 8;
  vbittype DgnInf_CE542_2 : 8;
  vbittype DgnInf_CE542_1 : 8;
  vbittype DgnInf_CE542_0 : 8;
} _c_UUDT_Resp_From_EPS_EPS_JR_CE_RDS_msgType;

typedef struct _c_USDT_Resp_From_EPS_EPS_JR_CE_RDS_msgTypeTag
{
  vbittype DgnInf_1_7 : 8;
  vbittype DgnInf_1_6 : 8;
  vbittype DgnInf_1_5 : 8;
  vbittype DgnInf_1_4 : 8;
  vbittype DgnInf_1_3 : 8;
  vbittype DgnInf_1_2 : 8;
  vbittype DgnInf_1_1 : 8;
  vbittype DgnInf_1_0 : 8;
} _c_USDT_Resp_From_EPS_EPS_JR_CE_RDS_msgType;

typedef struct _c_NonDriven_Wheel_Grnd_Velocity_CE_RDS_msgTypeTag
{
  vbittype WhlGrndVlctyLftNnDrvn_1_1 : 6;
  vbittype WhlGrndVlctyLftNnDrvnV_1 : 1;
  vbittype unused0 : 1;
  vbittype WhlGrndVlctyLftNnDrvn_1_0 : 8;
  vbittype WhlGrndVlctyRtNnDrvn_1_1 : 6;
  vbittype WhlGrndVlctyRtNnDrvnV_1 : 1;
  vbittype unused1 : 1;
  vbittype WhlGrndVlctyRtNnDrvn_1_0 : 8;
  vbittype WhlPlsPerRevNonDrvn_1 : 7;
  vbittype unused2 : 1;
} _c_NonDriven_Wheel_Grnd_Velocity_CE_RDS_msgType;

typedef struct _c_Driven_Wheel_Grnd_Velocity_CE_RDS_msgTypeTag
{
  vbittype WhlGrndVlctyLftDrvn_1_1 : 6;
  vbittype WhlGrndVlctyLftDrvnV_1 : 1;
  vbittype unused0 : 1;
  vbittype WhlGrndVlctyLftDrvn_1_0 : 8;
  vbittype WhlGrndVlctyRtDrvn_1_1 : 6;
  vbittype WhlGrndVlctyRtDrvnV_1 : 1;
  vbittype unused1 : 1;
  vbittype WhlGrndVlctyRtDrvn_1_0 : 8;
  vbittype WhlPlsPerRevDrvn_1 : 7;
  vbittype unused2 : 1;
} _c_Driven_Wheel_Grnd_Velocity_CE_RDS_msgType;

typedef struct _c_Park_Assist_Parallel_CE_RDS_msgTypeTag
{
  vbittype StrWhlTctlFdbkReqActRC : 2;
  vbittype unused0 : 1;
  vbittype StrWhlTctlFdbkReqAct : 1;
  vbittype StrWhlTctlFdbkReqActProtVal : 2;
  vbittype unused1 : 2;
  vbittype SWAR_ReqActV : 1;
  vbittype SWAR_ReqAct : 1;
  vbittype unused2 : 6;
  vbittype SWAR_TrgtAng_1 : 8;
  vbittype SWAR_TrgtAng_0 : 8;
  vbittype StrWhlAngReqPrtVal_2 : 2;
  vbittype StrWhlAngReqARC : 2;
  vbittype unused3 : 4;
  vbittype StrWhlAngReqPrtVal_1 : 8;
  vbittype StrWhlAngReqPrtVal_0 : 8;
} _c_Park_Assist_Parallel_CE_RDS_msgType;

typedef struct _c_Vehicle_Dynamics_ESC_Hyb_CE_RDS_msgTypeTag
{
  vbittype VSEAct_1 : 1;
  vbittype unused0 : 2;
  vbittype VSELongAccLoResV : 1;
  vbittype unused1 : 4;
  vbittype VSELongAccLoRes_1 : 2;
  vbittype VehStabEnhmntStat_1 : 3;
  vbittype unused2 : 3;
  vbittype VSELongAccLoRes_0 : 8;
  vbittype VehDynOvrUndrStr_1_1 : 2;
  vbittype VehDynOvrUndrStrV_1 : 1;
  vbittype unused3 : 5;
  vbittype VehDynOvrUndrStr_1_0 : 8;
} _c_Vehicle_Dynamics_ESC_Hyb_CE_RDS_msgType;

typedef struct _c_Steering_Torque_Command_CE_RDS_msgTypeTag
{
  vbittype TqOvrDltTqCmdVl_1 : 3;
  vbittype TqOvrDltTqCmdAct : 1;
  vbittype TrqOvrlARC : 4;
  vbittype TqOvrDltTqCmdVl_0 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype TrqOvrlCmdChksm_1 : 3;
  vbittype unused4 : 5;
  vbittype TrqOvrlCmdChksm_0 : 8;
} _c_Steering_Torque_Command_CE_RDS_msgType;

typedef struct _c_USDT_Req_to_All_CE_ECUs_RDS_msgTypeTag
{
  vbittype DgnInf_1_7 : 8;
  vbittype DgnInf_1_6 : 8;
  vbittype DgnInf_1_5 : 8;
  vbittype DgnInf_1_4 : 8;
  vbittype DgnInf_1_3 : 8;
  vbittype DgnInf_1_2 : 8;
  vbittype DgnInf_1_1 : 8;
  vbittype DgnInf_1_0 : 8;
} _c_USDT_Req_to_All_CE_ECUs_RDS_msgType;

typedef struct _c_USDT_Req_to_EPS_EPS_JR_CE_RDS_msgTypeTag
{
  vbittype DgnInf_1_7 : 8;
  vbittype DgnInf_1_6 : 8;
  vbittype DgnInf_1_5 : 8;
  vbittype DgnInf_1_4 : 8;
  vbittype DgnInf_1_3 : 8;
  vbittype DgnInf_1_2 : 8;
  vbittype DgnInf_1_1 : 8;
  vbittype DgnInf_1_0 : 8;
} _c_USDT_Req_to_EPS_EPS_JR_CE_RDS_msgType;

typedef union _c_RDS_Tx_buf_1Tag
{
  vuint8 _c[8];
  _c_PPEI_Steering_Wheel_Angle_CE_RDS_msgType PPEI_Steering_Wheel_Angle_CE;
  _c_Electric_Power_Steering_CE_RDS_msgType Electric_Power_Steering_CE;
  _c_UUDT_Resp_From_EPS_EPS_JR_CE_RDS_msgType UUDT_Resp_From_EPS_EPS_JR_CE;
  _c_USDT_Resp_From_EPS_EPS_JR_CE_RDS_msgType USDT_Resp_From_EPS_EPS_JR_CE;
} _c_RDS_Tx_buf_1;
typedef union _c_RDS14_bufTag
{
  vuint8 _c[5];
  _c_NonDriven_Wheel_Grnd_Velocity_CE_RDS_msgType NonDriven_Wheel_Grnd_Velocity_CE;
} _c_RDS14_buf;
typedef union _c_RDS15_bufTag
{
  vuint8 _c[5];
  _c_Driven_Wheel_Grnd_Velocity_CE_RDS_msgType Driven_Wheel_Grnd_Velocity_CE;
} _c_RDS15_buf;
typedef union _c_RDS16_bufTag
{
  vuint8 _c[7];
  _c_Park_Assist_Parallel_CE_RDS_msgType Park_Assist_Parallel_CE;
} _c_RDS16_buf;
typedef union _c_RDS17_bufTag
{
  vuint8 _c[5];
  _c_Vehicle_Dynamics_ESC_Hyb_CE_RDS_msgType Vehicle_Dynamics_ESC_Hyb_CE;
} _c_RDS17_buf;
typedef union _c_RDS18_bufTag
{
  vuint8 _c[8];
  _c_Steering_Torque_Command_CE_RDS_msgType Steering_Torque_Command_CE;
} _c_RDS18_buf;
typedef union _c_RDSBasic_buf_1Tag
{
  vuint8 _c[8];
  _c_USDT_Req_to_All_CE_ECUs_RDS_msgType USDT_Req_to_All_CE_ECUs;
  _c_USDT_Req_to_EPS_EPS_JR_CE_RDS_msgType USDT_Req_to_EPS_EPS_JR_CE;
} _c_RDSBasic_buf_1;


#define RDSTx_1                              ((* ((_c_RDS_Tx_buf_1 MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xb00))))
#define RDS14                                ((* ((_c_RDS14_buf MEMORY_NORMAL *)(canRDSRxPtr[1]))))
#define RDS15                                ((* ((_c_RDS15_buf MEMORY_NORMAL *)(canRDSRxPtr[1]))))
#define RDS16                                ((* ((_c_RDS16_buf MEMORY_NORMAL *)(canRDSRxPtr[1]))))
#define RDS17                                ((* ((_c_RDS17_buf MEMORY_NORMAL *)(canRDSRxPtr[1]))))
#define RDS18                                ((* ((_c_RDS18_buf MEMORY_NORMAL *)(canRDSRxPtr[1]))))
#define RDSBasic_1                           ((* ((_c_RDSBasic_buf_1 MEMORY_NORMAL *)(canRDSRxPtr[1]))))

#define b_CAN_SG9_Data_EPS_B_0_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_0)
#define b_CAN_SG9_Data_EPS_B_1_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_1)
#define b_CAN_SG9_Data_EPS_B_2_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_2)
#define b_CAN_SG9_Data_EPS_B_3_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_3)
#define b_CAN_SG9_Data_EPS_B_4_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_4)
#define b_CAN_SG9_Data_EPS_B_5_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_5)
#define b_CAN_SG9_Data_EPS_B_6_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_6)
#define b_CAN_SG9_Data_EPS_B_7_b             (RDSTx_2.SG9_Msg_EPS_B.SG9_Data_EPS_B_7)

typedef struct _c_SG9_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG9_Data_EPS_B_7 : 8;
  vbittype SG9_Data_EPS_B_6 : 8;
  vbittype SG9_Data_EPS_B_5 : 8;
  vbittype SG9_Data_EPS_B_4 : 8;
  vbittype SG9_Data_EPS_B_3 : 8;
  vbittype SG9_Data_EPS_B_2 : 8;
  vbittype SG9_Data_EPS_B_1 : 8;
  vbittype SG9_Data_EPS_B_0 : 8;
} _c_SG9_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG0_Data_EPS_B_0_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_0)
#define b_CAN_SG0_Data_EPS_B_1_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_1)
#define b_CAN_SG0_Data_EPS_B_2_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_2)
#define b_CAN_SG0_Data_EPS_B_3_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_3)
#define b_CAN_SG0_Data_EPS_B_4_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_4)
#define b_CAN_SG0_Data_EPS_B_5_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_5)
#define b_CAN_SG0_Data_EPS_B_6_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_6)
#define b_CAN_SG0_Data_EPS_B_7_b             (RDSTx_2.SG0_Msg_EPS_B_ONLY_SCI.SG0_Data_EPS_B_7)

typedef struct _c_SG0_Msg_EPS_B_ONLY_SCI_RDS_msgTypeTag
{
  vbittype SG0_Data_EPS_B_7 : 8;
  vbittype SG0_Data_EPS_B_6 : 8;
  vbittype SG0_Data_EPS_B_5 : 8;
  vbittype SG0_Data_EPS_B_4 : 8;
  vbittype SG0_Data_EPS_B_3 : 8;
  vbittype SG0_Data_EPS_B_2 : 8;
  vbittype SG0_Data_EPS_B_1 : 8;
  vbittype SG0_Data_EPS_B_0 : 8;
} _c_SG0_Msg_EPS_B_ONLY_SCI_RDS_msgType;

#define b_CAN_SG1_Data_EPS_B_0_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_0)
#define b_CAN_SG1_Data_EPS_B_1_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_1)
#define b_CAN_SG1_Data_EPS_B_2_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_2)
#define b_CAN_SG1_Data_EPS_B_3_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_3)
#define b_CAN_SG1_Data_EPS_B_4_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_4)
#define b_CAN_SG1_Data_EPS_B_5_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_5)
#define b_CAN_SG1_Data_EPS_B_6_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_6)
#define b_CAN_SG1_Data_EPS_B_7_b             (RDS193.SG1_Msg_EPS_B.SG1_Data_EPS_B_7)

typedef struct _c_SG1_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG1_Data_EPS_B_7 : 8;
  vbittype SG1_Data_EPS_B_6 : 8;
  vbittype SG1_Data_EPS_B_5 : 8;
  vbittype SG1_Data_EPS_B_4 : 8;
  vbittype SG1_Data_EPS_B_3 : 8;
  vbittype SG1_Data_EPS_B_2 : 8;
  vbittype SG1_Data_EPS_B_1 : 8;
  vbittype SG1_Data_EPS_B_0 : 8;
} _c_SG1_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG2_Data_EPS_B_0_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_0)
#define b_CAN_SG2_Data_EPS_B_1_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_1)
#define b_CAN_SG2_Data_EPS_B_2_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_2)
#define b_CAN_SG2_Data_EPS_B_3_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_3)
#define b_CAN_SG2_Data_EPS_B_4_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_4)
#define b_CAN_SG2_Data_EPS_B_5_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_5)
#define b_CAN_SG2_Data_EPS_B_6_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_6)
#define b_CAN_SG2_Data_EPS_B_7_b             (RDS194.SG2_Msg_EPS_B.SG2_Data_EPS_B_7)

typedef struct _c_SG2_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG2_Data_EPS_B_7 : 8;
  vbittype SG2_Data_EPS_B_6 : 8;
  vbittype SG2_Data_EPS_B_5 : 8;
  vbittype SG2_Data_EPS_B_4 : 8;
  vbittype SG2_Data_EPS_B_3 : 8;
  vbittype SG2_Data_EPS_B_2 : 8;
  vbittype SG2_Data_EPS_B_1 : 8;
  vbittype SG2_Data_EPS_B_0 : 8;
} _c_SG2_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG3_Data_EPS_B_0_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_0)
#define b_CAN_SG3_Data_EPS_B_1_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_1)
#define b_CAN_SG3_Data_EPS_B_2_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_2)
#define b_CAN_SG3_Data_EPS_B_3_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_3)
#define b_CAN_SG3_Data_EPS_B_4_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_4)
#define b_CAN_SG3_Data_EPS_B_5_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_5)
#define b_CAN_SG3_Data_EPS_B_6_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_6)
#define b_CAN_SG3_Data_EPS_B_7_b             (RDS195.SG3_Msg_EPS_B.SG3_Data_EPS_B_7)

typedef struct _c_SG3_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG3_Data_EPS_B_7 : 8;
  vbittype SG3_Data_EPS_B_6 : 8;
  vbittype SG3_Data_EPS_B_5 : 8;
  vbittype SG3_Data_EPS_B_4 : 8;
  vbittype SG3_Data_EPS_B_3 : 8;
  vbittype SG3_Data_EPS_B_2 : 8;
  vbittype SG3_Data_EPS_B_1 : 8;
  vbittype SG3_Data_EPS_B_0 : 8;
} _c_SG3_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG4_Data_EPS_B_0_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_0)
#define b_CAN_SG4_Data_EPS_B_1_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_1)
#define b_CAN_SG4_Data_EPS_B_2_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_2)
#define b_CAN_SG4_Data_EPS_B_3_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_3)
#define b_CAN_SG4_Data_EPS_B_4_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_4)
#define b_CAN_SG4_Data_EPS_B_5_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_5)
#define b_CAN_SG4_Data_EPS_B_6_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_6)
#define b_CAN_SG4_Data_EPS_B_7_b             (RDS196.SG4_Msg_EPS_B.SG4_Data_EPS_B_7)

typedef struct _c_SG4_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG4_Data_EPS_B_7 : 8;
  vbittype SG4_Data_EPS_B_6 : 8;
  vbittype SG4_Data_EPS_B_5 : 8;
  vbittype SG4_Data_EPS_B_4 : 8;
  vbittype SG4_Data_EPS_B_3 : 8;
  vbittype SG4_Data_EPS_B_2 : 8;
  vbittype SG4_Data_EPS_B_1 : 8;
  vbittype SG4_Data_EPS_B_0 : 8;
} _c_SG4_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG5_Data_EPS_B_0_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_0)
#define b_CAN_SG5_Data_EPS_B_1_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_1)
#define b_CAN_SG5_Data_EPS_B_2_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_2)
#define b_CAN_SG5_Data_EPS_B_3_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_3)
#define b_CAN_SG5_Data_EPS_B_4_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_4)
#define b_CAN_SG5_Data_EPS_B_5_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_5)
#define b_CAN_SG5_Data_EPS_B_6_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_6)
#define b_CAN_SG5_Data_EPS_B_7_b             (RDS197.SG5_Msg_EPS_B.SG5_Data_EPS_B_7)

typedef struct _c_SG5_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG5_Data_EPS_B_7 : 8;
  vbittype SG5_Data_EPS_B_6 : 8;
  vbittype SG5_Data_EPS_B_5 : 8;
  vbittype SG5_Data_EPS_B_4 : 8;
  vbittype SG5_Data_EPS_B_3 : 8;
  vbittype SG5_Data_EPS_B_2 : 8;
  vbittype SG5_Data_EPS_B_1 : 8;
  vbittype SG5_Data_EPS_B_0 : 8;
} _c_SG5_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG6_Data_EPS_B_0_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_0)
#define b_CAN_SG6_Data_EPS_B_1_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_1)
#define b_CAN_SG6_Data_EPS_B_2_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_2)
#define b_CAN_SG6_Data_EPS_B_3_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_3)
#define b_CAN_SG6_Data_EPS_B_4_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_4)
#define b_CAN_SG6_Data_EPS_B_5_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_5)
#define b_CAN_SG6_Data_EPS_B_6_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_6)
#define b_CAN_SG6_Data_EPS_B_7_b             (RDS198.SG6_Msg_EPS_B.SG6_Data_EPS_B_7)

typedef struct _c_SG6_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG6_Data_EPS_B_7 : 8;
  vbittype SG6_Data_EPS_B_6 : 8;
  vbittype SG6_Data_EPS_B_5 : 8;
  vbittype SG6_Data_EPS_B_4 : 8;
  vbittype SG6_Data_EPS_B_3 : 8;
  vbittype SG6_Data_EPS_B_2 : 8;
  vbittype SG6_Data_EPS_B_1 : 8;
  vbittype SG6_Data_EPS_B_0 : 8;
} _c_SG6_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG7_Data_EPS_B_0_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_0)
#define b_CAN_SG7_Data_EPS_B_1_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_1)
#define b_CAN_SG7_Data_EPS_B_2_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_2)
#define b_CAN_SG7_Data_EPS_B_3_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_3)
#define b_CAN_SG7_Data_EPS_B_4_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_4)
#define b_CAN_SG7_Data_EPS_B_5_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_5)
#define b_CAN_SG7_Data_EPS_B_6_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_6)
#define b_CAN_SG7_Data_EPS_B_7_b             (RDS199.SG7_Msg_EPS_B.SG7_Data_EPS_B_7)

typedef struct _c_SG7_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG7_Data_EPS_B_7 : 8;
  vbittype SG7_Data_EPS_B_6 : 8;
  vbittype SG7_Data_EPS_B_5 : 8;
  vbittype SG7_Data_EPS_B_4 : 8;
  vbittype SG7_Data_EPS_B_3 : 8;
  vbittype SG7_Data_EPS_B_2 : 8;
  vbittype SG7_Data_EPS_B_1 : 8;
  vbittype SG7_Data_EPS_B_0 : 8;
} _c_SG7_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG8_Data_EPS_B_0_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_0)
#define b_CAN_SG8_Data_EPS_B_1_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_1)
#define b_CAN_SG8_Data_EPS_B_2_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_2)
#define b_CAN_SG8_Data_EPS_B_3_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_3)
#define b_CAN_SG8_Data_EPS_B_4_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_4)
#define b_CAN_SG8_Data_EPS_B_5_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_5)
#define b_CAN_SG8_Data_EPS_B_6_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_6)
#define b_CAN_SG8_Data_EPS_B_7_b             (RDS200.SG8_Msg_EPS_B.SG8_Data_EPS_B_7)

typedef struct _c_SG8_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG8_Data_EPS_B_7 : 8;
  vbittype SG8_Data_EPS_B_6 : 8;
  vbittype SG8_Data_EPS_B_5 : 8;
  vbittype SG8_Data_EPS_B_4 : 8;
  vbittype SG8_Data_EPS_B_3 : 8;
  vbittype SG8_Data_EPS_B_2 : 8;
  vbittype SG8_Data_EPS_B_1 : 8;
  vbittype SG8_Data_EPS_B_0 : 8;
} _c_SG8_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG10_Data_EPS_B_0_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_0)
#define b_CAN_SG10_Data_EPS_B_1_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_1)
#define b_CAN_SG10_Data_EPS_B_2_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_2)
#define b_CAN_SG10_Data_EPS_B_3_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_3)
#define b_CAN_SG10_Data_EPS_B_4_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_4)
#define b_CAN_SG10_Data_EPS_B_5_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_5)
#define b_CAN_SG10_Data_EPS_B_6_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_6)
#define b_CAN_SG10_Data_EPS_B_7_b            (RDS201.SG10_Msg_EPS_B.SG10_Data_EPS_B_7)

typedef struct _c_SG10_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG10_Data_EPS_B_7 : 8;
  vbittype SG10_Data_EPS_B_6 : 8;
  vbittype SG10_Data_EPS_B_5 : 8;
  vbittype SG10_Data_EPS_B_4 : 8;
  vbittype SG10_Data_EPS_B_3 : 8;
  vbittype SG10_Data_EPS_B_2 : 8;
  vbittype SG10_Data_EPS_B_1 : 8;
  vbittype SG10_Data_EPS_B_0 : 8;
} _c_SG10_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG11_Data_EPS_B_0_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_0)
#define b_CAN_SG11_Data_EPS_B_1_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_1)
#define b_CAN_SG11_Data_EPS_B_2_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_2)
#define b_CAN_SG11_Data_EPS_B_3_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_3)
#define b_CAN_SG11_Data_EPS_B_4_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_4)
#define b_CAN_SG11_Data_EPS_B_5_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_5)
#define b_CAN_SG11_Data_EPS_B_6_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_6)
#define b_CAN_SG11_Data_EPS_B_7_b            (RDS202.SG11_Msg_EPS_B.SG11_Data_EPS_B_7)

typedef struct _c_SG11_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG11_Data_EPS_B_7 : 8;
  vbittype SG11_Data_EPS_B_6 : 8;
  vbittype SG11_Data_EPS_B_5 : 8;
  vbittype SG11_Data_EPS_B_4 : 8;
  vbittype SG11_Data_EPS_B_3 : 8;
  vbittype SG11_Data_EPS_B_2 : 8;
  vbittype SG11_Data_EPS_B_1 : 8;
  vbittype SG11_Data_EPS_B_0 : 8;
} _c_SG11_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG12_Data_EPS_B_0_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_0)
#define b_CAN_SG12_Data_EPS_B_1_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_1)
#define b_CAN_SG12_Data_EPS_B_2_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_2)
#define b_CAN_SG12_Data_EPS_B_3_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_3)
#define b_CAN_SG12_Data_EPS_B_4_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_4)
#define b_CAN_SG12_Data_EPS_B_5_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_5)
#define b_CAN_SG12_Data_EPS_B_6_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_6)
#define b_CAN_SG12_Data_EPS_B_7_b            (RDS203.SG12_Msg_EPS_B.SG12_Data_EPS_B_7)

typedef struct _c_SG12_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG12_Data_EPS_B_7 : 8;
  vbittype SG12_Data_EPS_B_6 : 8;
  vbittype SG12_Data_EPS_B_5 : 8;
  vbittype SG12_Data_EPS_B_4 : 8;
  vbittype SG12_Data_EPS_B_3 : 8;
  vbittype SG12_Data_EPS_B_2 : 8;
  vbittype SG12_Data_EPS_B_1 : 8;
  vbittype SG12_Data_EPS_B_0 : 8;
} _c_SG12_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG13_Data_EPS_B_0_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_0)
#define b_CAN_SG13_Data_EPS_B_1_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_1)
#define b_CAN_SG13_Data_EPS_B_2_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_2)
#define b_CAN_SG13_Data_EPS_B_3_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_3)
#define b_CAN_SG13_Data_EPS_B_4_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_4)
#define b_CAN_SG13_Data_EPS_B_5_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_5)
#define b_CAN_SG13_Data_EPS_B_6_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_6)
#define b_CAN_SG13_Data_EPS_B_7_b            (RDS204.SG13_Msg_EPS_B.SG13_Data_EPS_B_7)

typedef struct _c_SG13_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG13_Data_EPS_B_7 : 8;
  vbittype SG13_Data_EPS_B_6 : 8;
  vbittype SG13_Data_EPS_B_5 : 8;
  vbittype SG13_Data_EPS_B_4 : 8;
  vbittype SG13_Data_EPS_B_3 : 8;
  vbittype SG13_Data_EPS_B_2 : 8;
  vbittype SG13_Data_EPS_B_1 : 8;
  vbittype SG13_Data_EPS_B_0 : 8;
} _c_SG13_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG14_Data_EPS_B_0_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_0)
#define b_CAN_SG14_Data_EPS_B_1_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_1)
#define b_CAN_SG14_Data_EPS_B_2_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_2)
#define b_CAN_SG14_Data_EPS_B_3_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_3)
#define b_CAN_SG14_Data_EPS_B_4_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_4)
#define b_CAN_SG14_Data_EPS_B_5_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_5)
#define b_CAN_SG14_Data_EPS_B_6_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_6)
#define b_CAN_SG14_Data_EPS_B_7_b            (RDS205.SG14_Msg_EPS_B.SG14_Data_EPS_B_7)

typedef struct _c_SG14_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG14_Data_EPS_B_7 : 8;
  vbittype SG14_Data_EPS_B_6 : 8;
  vbittype SG14_Data_EPS_B_5 : 8;
  vbittype SG14_Data_EPS_B_4 : 8;
  vbittype SG14_Data_EPS_B_3 : 8;
  vbittype SG14_Data_EPS_B_2 : 8;
  vbittype SG14_Data_EPS_B_1 : 8;
  vbittype SG14_Data_EPS_B_0 : 8;
} _c_SG14_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG15_Data_EPS_B_0_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_0)
#define b_CAN_SG15_Data_EPS_B_1_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_1)
#define b_CAN_SG15_Data_EPS_B_2_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_2)
#define b_CAN_SG15_Data_EPS_B_3_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_3)
#define b_CAN_SG15_Data_EPS_B_4_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_4)
#define b_CAN_SG15_Data_EPS_B_5_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_5)
#define b_CAN_SG15_Data_EPS_B_6_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_6)
#define b_CAN_SG15_Data_EPS_B_7_b            (RDS206.SG15_Msg_EPS_B.SG15_Data_EPS_B_7)

typedef struct _c_SG15_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG15_Data_EPS_B_7 : 8;
  vbittype SG15_Data_EPS_B_6 : 8;
  vbittype SG15_Data_EPS_B_5 : 8;
  vbittype SG15_Data_EPS_B_4 : 8;
  vbittype SG15_Data_EPS_B_3 : 8;
  vbittype SG15_Data_EPS_B_2 : 8;
  vbittype SG15_Data_EPS_B_1 : 8;
  vbittype SG15_Data_EPS_B_0 : 8;
} _c_SG15_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG16_Data_EPS_B_0_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_0)
#define b_CAN_SG16_Data_EPS_B_1_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_1)
#define b_CAN_SG16_Data_EPS_B_2_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_2)
#define b_CAN_SG16_Data_EPS_B_3_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_3)
#define b_CAN_SG16_Data_EPS_B_4_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_4)
#define b_CAN_SG16_Data_EPS_B_5_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_5)
#define b_CAN_SG16_Data_EPS_B_6_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_6)
#define b_CAN_SG16_Data_EPS_B_7_b            (RDS207.SG16_Msg_EPS_B.SG16_Data_EPS_B_7)

typedef struct _c_SG16_Msg_EPS_B_RDS_msgTypeTag
{
  vbittype SG16_Data_EPS_B_7 : 8;
  vbittype SG16_Data_EPS_B_6 : 8;
  vbittype SG16_Data_EPS_B_5 : 8;
  vbittype SG16_Data_EPS_B_4 : 8;
  vbittype SG16_Data_EPS_B_3 : 8;
  vbittype SG16_Data_EPS_B_2 : 8;
  vbittype SG16_Data_EPS_B_1 : 8;
  vbittype SG16_Data_EPS_B_0 : 8;
} _c_SG16_Msg_EPS_B_RDS_msgType;

#define b_CAN_SG16_Data_EPS_A_0_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_0)
#define b_CAN_SG16_Data_EPS_A_1_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_1)
#define b_CAN_SG16_Data_EPS_A_2_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_2)
#define b_CAN_SG16_Data_EPS_A_3_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_3)
#define b_CAN_SG16_Data_EPS_A_4_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_4)
#define b_CAN_SG16_Data_EPS_A_5_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_5)
#define b_CAN_SG16_Data_EPS_A_6_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_6)
#define b_CAN_SG16_Data_EPS_A_7_b            (RDS19.SG16_Msg_EPS_A.SG16_Data_EPS_A_7)

typedef struct _c_SG16_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG16_Data_EPS_A_7 : 8;
  vbittype SG16_Data_EPS_A_6 : 8;
  vbittype SG16_Data_EPS_A_5 : 8;
  vbittype SG16_Data_EPS_A_4 : 8;
  vbittype SG16_Data_EPS_A_3 : 8;
  vbittype SG16_Data_EPS_A_2 : 8;
  vbittype SG16_Data_EPS_A_1 : 8;
  vbittype SG16_Data_EPS_A_0 : 8;
} _c_SG16_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG15_Data_EPS_A_0_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_0)
#define b_CAN_SG15_Data_EPS_A_1_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_1)
#define b_CAN_SG15_Data_EPS_A_2_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_2)
#define b_CAN_SG15_Data_EPS_A_3_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_3)
#define b_CAN_SG15_Data_EPS_A_4_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_4)
#define b_CAN_SG15_Data_EPS_A_5_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_5)
#define b_CAN_SG15_Data_EPS_A_6_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_6)
#define b_CAN_SG15_Data_EPS_A_7_b            (RDS20.SG15_Msg_EPS_A.SG15_Data_EPS_A_7)

typedef struct _c_SG15_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG15_Data_EPS_A_7 : 8;
  vbittype SG15_Data_EPS_A_6 : 8;
  vbittype SG15_Data_EPS_A_5 : 8;
  vbittype SG15_Data_EPS_A_4 : 8;
  vbittype SG15_Data_EPS_A_3 : 8;
  vbittype SG15_Data_EPS_A_2 : 8;
  vbittype SG15_Data_EPS_A_1 : 8;
  vbittype SG15_Data_EPS_A_0 : 8;
} _c_SG15_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG14_Data_EPS_A_0_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_0)
#define b_CAN_SG14_Data_EPS_A_1_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_1)
#define b_CAN_SG14_Data_EPS_A_2_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_2)
#define b_CAN_SG14_Data_EPS_A_3_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_3)
#define b_CAN_SG14_Data_EPS_A_4_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_4)
#define b_CAN_SG14_Data_EPS_A_5_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_5)
#define b_CAN_SG14_Data_EPS_A_6_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_6)
#define b_CAN_SG14_Data_EPS_A_7_b            (RDS21.SG14_Msg_EPS_A.SG14_Data_EPS_A_7)

typedef struct _c_SG14_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG14_Data_EPS_A_7 : 8;
  vbittype SG14_Data_EPS_A_6 : 8;
  vbittype SG14_Data_EPS_A_5 : 8;
  vbittype SG14_Data_EPS_A_4 : 8;
  vbittype SG14_Data_EPS_A_3 : 8;
  vbittype SG14_Data_EPS_A_2 : 8;
  vbittype SG14_Data_EPS_A_1 : 8;
  vbittype SG14_Data_EPS_A_0 : 8;
} _c_SG14_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG13_Data_EPS_A_0_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_0)
#define b_CAN_SG13_Data_EPS_A_1_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_1)
#define b_CAN_SG13_Data_EPS_A_2_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_2)
#define b_CAN_SG13_Data_EPS_A_3_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_3)
#define b_CAN_SG13_Data_EPS_A_4_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_4)
#define b_CAN_SG13_Data_EPS_A_5_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_5)
#define b_CAN_SG13_Data_EPS_A_6_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_6)
#define b_CAN_SG13_Data_EPS_A_7_b            (RDS22.SG13_Msg_EPS_A.SG13_Data_EPS_A_7)

typedef struct _c_SG13_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG13_Data_EPS_A_7 : 8;
  vbittype SG13_Data_EPS_A_6 : 8;
  vbittype SG13_Data_EPS_A_5 : 8;
  vbittype SG13_Data_EPS_A_4 : 8;
  vbittype SG13_Data_EPS_A_3 : 8;
  vbittype SG13_Data_EPS_A_2 : 8;
  vbittype SG13_Data_EPS_A_1 : 8;
  vbittype SG13_Data_EPS_A_0 : 8;
} _c_SG13_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG12_Data_EPS_A_0_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_0)
#define b_CAN_SG12_Data_EPS_A_1_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_1)
#define b_CAN_SG12_Data_EPS_A_2_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_2)
#define b_CAN_SG12_Data_EPS_A_3_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_3)
#define b_CAN_SG12_Data_EPS_A_4_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_4)
#define b_CAN_SG12_Data_EPS_A_5_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_5)
#define b_CAN_SG12_Data_EPS_A_6_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_6)
#define b_CAN_SG12_Data_EPS_A_7_b            (RDS23.SG12_Msg_EPS_A.SG12_Data_EPS_A_7)

typedef struct _c_SG12_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG12_Data_EPS_A_7 : 8;
  vbittype SG12_Data_EPS_A_6 : 8;
  vbittype SG12_Data_EPS_A_5 : 8;
  vbittype SG12_Data_EPS_A_4 : 8;
  vbittype SG12_Data_EPS_A_3 : 8;
  vbittype SG12_Data_EPS_A_2 : 8;
  vbittype SG12_Data_EPS_A_1 : 8;
  vbittype SG12_Data_EPS_A_0 : 8;
} _c_SG12_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG11_Data_EPS_A_0_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_0)
#define b_CAN_SG11_Data_EPS_A_1_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_1)
#define b_CAN_SG11_Data_EPS_A_2_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_2)
#define b_CAN_SG11_Data_EPS_A_3_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_3)
#define b_CAN_SG11_Data_EPS_A_4_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_4)
#define b_CAN_SG11_Data_EPS_A_5_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_5)
#define b_CAN_SG11_Data_EPS_A_6_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_6)
#define b_CAN_SG11_Data_EPS_A_7_b            (RDS24.SG11_Msg_EPS_A.SG11_Data_EPS_A_7)

typedef struct _c_SG11_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG11_Data_EPS_A_7 : 8;
  vbittype SG11_Data_EPS_A_6 : 8;
  vbittype SG11_Data_EPS_A_5 : 8;
  vbittype SG11_Data_EPS_A_4 : 8;
  vbittype SG11_Data_EPS_A_3 : 8;
  vbittype SG11_Data_EPS_A_2 : 8;
  vbittype SG11_Data_EPS_A_1 : 8;
  vbittype SG11_Data_EPS_A_0 : 8;
} _c_SG11_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG10_Data_EPS_A_0_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_0)
#define b_CAN_SG10_Data_EPS_A_1_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_1)
#define b_CAN_SG10_Data_EPS_A_2_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_2)
#define b_CAN_SG10_Data_EPS_A_3_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_3)
#define b_CAN_SG10_Data_EPS_A_4_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_4)
#define b_CAN_SG10_Data_EPS_A_5_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_5)
#define b_CAN_SG10_Data_EPS_A_6_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_6)
#define b_CAN_SG10_Data_EPS_A_7_b            (RDS25.SG10_Msg_EPS_A.SG10_Data_EPS_A_7)

typedef struct _c_SG10_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG10_Data_EPS_A_7 : 8;
  vbittype SG10_Data_EPS_A_6 : 8;
  vbittype SG10_Data_EPS_A_5 : 8;
  vbittype SG10_Data_EPS_A_4 : 8;
  vbittype SG10_Data_EPS_A_3 : 8;
  vbittype SG10_Data_EPS_A_2 : 8;
  vbittype SG10_Data_EPS_A_1 : 8;
  vbittype SG10_Data_EPS_A_0 : 8;
} _c_SG10_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG9_Data_EPS_A_0_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_0)
#define b_CAN_SG9_Data_EPS_A_1_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_1)
#define b_CAN_SG9_Data_EPS_A_2_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_2)
#define b_CAN_SG9_Data_EPS_A_3_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_3)
#define b_CAN_SG9_Data_EPS_A_4_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_4)
#define b_CAN_SG9_Data_EPS_A_5_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_5)
#define b_CAN_SG9_Data_EPS_A_6_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_6)
#define b_CAN_SG9_Data_EPS_A_7_b             (RDS26.SG9_Msg_EPS_A.SG9_Data_EPS_A_7)

typedef struct _c_SG9_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG9_Data_EPS_A_7 : 8;
  vbittype SG9_Data_EPS_A_6 : 8;
  vbittype SG9_Data_EPS_A_5 : 8;
  vbittype SG9_Data_EPS_A_4 : 8;
  vbittype SG9_Data_EPS_A_3 : 8;
  vbittype SG9_Data_EPS_A_2 : 8;
  vbittype SG9_Data_EPS_A_1 : 8;
  vbittype SG9_Data_EPS_A_0 : 8;
} _c_SG9_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG8_Data_EPS_A_0_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_0)
#define b_CAN_SG8_Data_EPS_A_1_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_1)
#define b_CAN_SG8_Data_EPS_A_2_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_2)
#define b_CAN_SG8_Data_EPS_A_3_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_3)
#define b_CAN_SG8_Data_EPS_A_4_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_4)
#define b_CAN_SG8_Data_EPS_A_5_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_5)
#define b_CAN_SG8_Data_EPS_A_6_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_6)
#define b_CAN_SG8_Data_EPS_A_7_b             (RDS27.SG8_Msg_EPS_A.SG8_Data_EPS_A_7)

typedef struct _c_SG8_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG8_Data_EPS_A_7 : 8;
  vbittype SG8_Data_EPS_A_6 : 8;
  vbittype SG8_Data_EPS_A_5 : 8;
  vbittype SG8_Data_EPS_A_4 : 8;
  vbittype SG8_Data_EPS_A_3 : 8;
  vbittype SG8_Data_EPS_A_2 : 8;
  vbittype SG8_Data_EPS_A_1 : 8;
  vbittype SG8_Data_EPS_A_0 : 8;
} _c_SG8_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG7_Data_EPS_A_0_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_0)
#define b_CAN_SG7_Data_EPS_A_1_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_1)
#define b_CAN_SG7_Data_EPS_A_2_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_2)
#define b_CAN_SG7_Data_EPS_A_3_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_3)
#define b_CAN_SG7_Data_EPS_A_4_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_4)
#define b_CAN_SG7_Data_EPS_A_5_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_5)
#define b_CAN_SG7_Data_EPS_A_6_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_6)
#define b_CAN_SG7_Data_EPS_A_7_b             (RDS28.SG7_Msg_EPS_A.SG7_Data_EPS_A_7)

typedef struct _c_SG7_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG7_Data_EPS_A_7 : 8;
  vbittype SG7_Data_EPS_A_6 : 8;
  vbittype SG7_Data_EPS_A_5 : 8;
  vbittype SG7_Data_EPS_A_4 : 8;
  vbittype SG7_Data_EPS_A_3 : 8;
  vbittype SG7_Data_EPS_A_2 : 8;
  vbittype SG7_Data_EPS_A_1 : 8;
  vbittype SG7_Data_EPS_A_0 : 8;
} _c_SG7_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG6_Data_EPS_A_0_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_0)
#define b_CAN_SG6_Data_EPS_A_1_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_1)
#define b_CAN_SG6_Data_EPS_A_2_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_2)
#define b_CAN_SG6_Data_EPS_A_3_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_3)
#define b_CAN_SG6_Data_EPS_A_4_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_4)
#define b_CAN_SG6_Data_EPS_A_5_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_5)
#define b_CAN_SG6_Data_EPS_A_6_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_6)
#define b_CAN_SG6_Data_EPS_A_7_b             (RDS29.SG6_Msg_EPS_A.SG6_Data_EPS_A_7)

typedef struct _c_SG6_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG6_Data_EPS_A_7 : 8;
  vbittype SG6_Data_EPS_A_6 : 8;
  vbittype SG6_Data_EPS_A_5 : 8;
  vbittype SG6_Data_EPS_A_4 : 8;
  vbittype SG6_Data_EPS_A_3 : 8;
  vbittype SG6_Data_EPS_A_2 : 8;
  vbittype SG6_Data_EPS_A_1 : 8;
  vbittype SG6_Data_EPS_A_0 : 8;
} _c_SG6_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG5_Data_EPS_A_0_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_0)
#define b_CAN_SG5_Data_EPS_A_1_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_1)
#define b_CAN_SG5_Data_EPS_A_2_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_2)
#define b_CAN_SG5_Data_EPS_A_3_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_3)
#define b_CAN_SG5_Data_EPS_A_4_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_4)
#define b_CAN_SG5_Data_EPS_A_5_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_5)
#define b_CAN_SG5_Data_EPS_A_6_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_6)
#define b_CAN_SG5_Data_EPS_A_7_b             (RDS30.SG5_Msg_EPS_A.SG5_Data_EPS_A_7)

typedef struct _c_SG5_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG5_Data_EPS_A_7 : 8;
  vbittype SG5_Data_EPS_A_6 : 8;
  vbittype SG5_Data_EPS_A_5 : 8;
  vbittype SG5_Data_EPS_A_4 : 8;
  vbittype SG5_Data_EPS_A_3 : 8;
  vbittype SG5_Data_EPS_A_2 : 8;
  vbittype SG5_Data_EPS_A_1 : 8;
  vbittype SG5_Data_EPS_A_0 : 8;
} _c_SG5_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG4_Data_EPS_A_0_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_0)
#define b_CAN_SG4_Data_EPS_A_1_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_1)
#define b_CAN_SG4_Data_EPS_A_2_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_2)
#define b_CAN_SG4_Data_EPS_A_3_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_3)
#define b_CAN_SG4_Data_EPS_A_4_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_4)
#define b_CAN_SG4_Data_EPS_A_5_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_5)
#define b_CAN_SG4_Data_EPS_A_6_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_6)
#define b_CAN_SG4_Data_EPS_A_7_b             (RDS31.SG4_Msg_EPS_A.SG4_Data_EPS_A_7)

typedef struct _c_SG4_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG4_Data_EPS_A_7 : 8;
  vbittype SG4_Data_EPS_A_6 : 8;
  vbittype SG4_Data_EPS_A_5 : 8;
  vbittype SG4_Data_EPS_A_4 : 8;
  vbittype SG4_Data_EPS_A_3 : 8;
  vbittype SG4_Data_EPS_A_2 : 8;
  vbittype SG4_Data_EPS_A_1 : 8;
  vbittype SG4_Data_EPS_A_0 : 8;
} _c_SG4_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG3_Data_EPS_A_0_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_0)
#define b_CAN_SG3_Data_EPS_A_1_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_1)
#define b_CAN_SG3_Data_EPS_A_2_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_2)
#define b_CAN_SG3_Data_EPS_A_3_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_3)
#define b_CAN_SG3_Data_EPS_A_4_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_4)
#define b_CAN_SG3_Data_EPS_A_5_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_5)
#define b_CAN_SG3_Data_EPS_A_6_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_6)
#define b_CAN_SG3_Data_EPS_A_7_b             (RDS32.SG3_Msg_EPS_A.SG3_Data_EPS_A_7)

typedef struct _c_SG3_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG3_Data_EPS_A_7 : 8;
  vbittype SG3_Data_EPS_A_6 : 8;
  vbittype SG3_Data_EPS_A_5 : 8;
  vbittype SG3_Data_EPS_A_4 : 8;
  vbittype SG3_Data_EPS_A_3 : 8;
  vbittype SG3_Data_EPS_A_2 : 8;
  vbittype SG3_Data_EPS_A_1 : 8;
  vbittype SG3_Data_EPS_A_0 : 8;
} _c_SG3_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG2_Data_EPS_A_0_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_0)
#define b_CAN_SG2_Data_EPS_A_1_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_1)
#define b_CAN_SG2_Data_EPS_A_2_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_2)
#define b_CAN_SG2_Data_EPS_A_3_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_3)
#define b_CAN_SG2_Data_EPS_A_4_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_4)
#define b_CAN_SG2_Data_EPS_A_5_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_5)
#define b_CAN_SG2_Data_EPS_A_6_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_6)
#define b_CAN_SG2_Data_EPS_A_7_b             (RDS33.SG2_Msg_EPS_A.SG2_Data_EPS_A_7)

typedef struct _c_SG2_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG2_Data_EPS_A_7 : 8;
  vbittype SG2_Data_EPS_A_6 : 8;
  vbittype SG2_Data_EPS_A_5 : 8;
  vbittype SG2_Data_EPS_A_4 : 8;
  vbittype SG2_Data_EPS_A_3 : 8;
  vbittype SG2_Data_EPS_A_2 : 8;
  vbittype SG2_Data_EPS_A_1 : 8;
  vbittype SG2_Data_EPS_A_0 : 8;
} _c_SG2_Msg_EPS_A_RDS_msgType;

#define b_CAN_SG1_Data_EPS_A_0_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_0)
#define b_CAN_SG1_Data_EPS_A_1_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_1)
#define b_CAN_SG1_Data_EPS_A_2_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_2)
#define b_CAN_SG1_Data_EPS_A_3_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_3)
#define b_CAN_SG1_Data_EPS_A_4_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_4)
#define b_CAN_SG1_Data_EPS_A_5_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_5)
#define b_CAN_SG1_Data_EPS_A_6_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_6)
#define b_CAN_SG1_Data_EPS_A_7_b             (RDS34.SG1_Msg_EPS_A.SG1_Data_EPS_A_7)

typedef struct _c_SG1_Msg_EPS_A_RDS_msgTypeTag
{
  vbittype SG1_Data_EPS_A_7 : 8;
  vbittype SG1_Data_EPS_A_6 : 8;
  vbittype SG1_Data_EPS_A_5 : 8;
  vbittype SG1_Data_EPS_A_4 : 8;
  vbittype SG1_Data_EPS_A_3 : 8;
  vbittype SG1_Data_EPS_A_2 : 8;
  vbittype SG1_Data_EPS_A_1 : 8;
  vbittype SG1_Data_EPS_A_0 : 8;
} _c_SG1_Msg_EPS_A_RDS_msgType;

typedef union _c_RDS_Tx_buf_2Tag
{
  vuint8 _c[8];
  _c_SG9_Msg_EPS_B_RDS_msgType SG9_Msg_EPS_B;
  _c_SG0_Msg_EPS_B_ONLY_SCI_RDS_msgType SG0_Msg_EPS_B_ONLY_SCI;
} _c_RDS_Tx_buf_2;
typedef union _c_RDS193_bufTag
{
  vuint8 _c[8];
  _c_SG1_Msg_EPS_B_RDS_msgType SG1_Msg_EPS_B;
} _c_RDS193_buf;
typedef union _c_RDS194_bufTag
{
  vuint8 _c[8];
  _c_SG2_Msg_EPS_B_RDS_msgType SG2_Msg_EPS_B;
} _c_RDS194_buf;
typedef union _c_RDS195_bufTag
{
  vuint8 _c[8];
  _c_SG3_Msg_EPS_B_RDS_msgType SG3_Msg_EPS_B;
} _c_RDS195_buf;
typedef union _c_RDS196_bufTag
{
  vuint8 _c[8];
  _c_SG4_Msg_EPS_B_RDS_msgType SG4_Msg_EPS_B;
} _c_RDS196_buf;
typedef union _c_RDS197_bufTag
{
  vuint8 _c[8];
  _c_SG5_Msg_EPS_B_RDS_msgType SG5_Msg_EPS_B;
} _c_RDS197_buf;
typedef union _c_RDS198_bufTag
{
  vuint8 _c[8];
  _c_SG6_Msg_EPS_B_RDS_msgType SG6_Msg_EPS_B;
} _c_RDS198_buf;
typedef union _c_RDS199_bufTag
{
  vuint8 _c[8];
  _c_SG7_Msg_EPS_B_RDS_msgType SG7_Msg_EPS_B;
} _c_RDS199_buf;
typedef union _c_RDS200_bufTag
{
  vuint8 _c[8];
  _c_SG8_Msg_EPS_B_RDS_msgType SG8_Msg_EPS_B;
} _c_RDS200_buf;
typedef union _c_RDS201_bufTag
{
  vuint8 _c[8];
  _c_SG10_Msg_EPS_B_RDS_msgType SG10_Msg_EPS_B;
} _c_RDS201_buf;
typedef union _c_RDS202_bufTag
{
  vuint8 _c[8];
  _c_SG11_Msg_EPS_B_RDS_msgType SG11_Msg_EPS_B;
} _c_RDS202_buf;
typedef union _c_RDS203_bufTag
{
  vuint8 _c[8];
  _c_SG12_Msg_EPS_B_RDS_msgType SG12_Msg_EPS_B;
} _c_RDS203_buf;
typedef union _c_RDS204_bufTag
{
  vuint8 _c[8];
  _c_SG13_Msg_EPS_B_RDS_msgType SG13_Msg_EPS_B;
} _c_RDS204_buf;
typedef union _c_RDS205_bufTag
{
  vuint8 _c[8];
  _c_SG14_Msg_EPS_B_RDS_msgType SG14_Msg_EPS_B;
} _c_RDS205_buf;
typedef union _c_RDS206_bufTag
{
  vuint8 _c[8];
  _c_SG15_Msg_EPS_B_RDS_msgType SG15_Msg_EPS_B;
} _c_RDS206_buf;
typedef union _c_RDS207_bufTag
{
  vuint8 _c[8];
  _c_SG16_Msg_EPS_B_RDS_msgType SG16_Msg_EPS_B;
} _c_RDS207_buf;
typedef union _c_RDS19_bufTag
{
  vuint8 _c[8];
  _c_SG16_Msg_EPS_A_RDS_msgType SG16_Msg_EPS_A;
} _c_RDS19_buf;
typedef union _c_RDS20_bufTag
{
  vuint8 _c[8];
  _c_SG15_Msg_EPS_A_RDS_msgType SG15_Msg_EPS_A;
} _c_RDS20_buf;
typedef union _c_RDS21_bufTag
{
  vuint8 _c[8];
  _c_SG14_Msg_EPS_A_RDS_msgType SG14_Msg_EPS_A;
} _c_RDS21_buf;
typedef union _c_RDS22_bufTag
{
  vuint8 _c[8];
  _c_SG13_Msg_EPS_A_RDS_msgType SG13_Msg_EPS_A;
} _c_RDS22_buf;
typedef union _c_RDS23_bufTag
{
  vuint8 _c[8];
  _c_SG12_Msg_EPS_A_RDS_msgType SG12_Msg_EPS_A;
} _c_RDS23_buf;
typedef union _c_RDS24_bufTag
{
  vuint8 _c[8];
  _c_SG11_Msg_EPS_A_RDS_msgType SG11_Msg_EPS_A;
} _c_RDS24_buf;
typedef union _c_RDS25_bufTag
{
  vuint8 _c[8];
  _c_SG10_Msg_EPS_A_RDS_msgType SG10_Msg_EPS_A;
} _c_RDS25_buf;
typedef union _c_RDS26_bufTag
{
  vuint8 _c[8];
  _c_SG9_Msg_EPS_A_RDS_msgType SG9_Msg_EPS_A;
} _c_RDS26_buf;
typedef union _c_RDS27_bufTag
{
  vuint8 _c[8];
  _c_SG8_Msg_EPS_A_RDS_msgType SG8_Msg_EPS_A;
} _c_RDS27_buf;
typedef union _c_RDS28_bufTag
{
  vuint8 _c[8];
  _c_SG7_Msg_EPS_A_RDS_msgType SG7_Msg_EPS_A;
} _c_RDS28_buf;
typedef union _c_RDS29_bufTag
{
  vuint8 _c[8];
  _c_SG6_Msg_EPS_A_RDS_msgType SG6_Msg_EPS_A;
} _c_RDS29_buf;
typedef union _c_RDS30_bufTag
{
  vuint8 _c[8];
  _c_SG5_Msg_EPS_A_RDS_msgType SG5_Msg_EPS_A;
} _c_RDS30_buf;
typedef union _c_RDS31_bufTag
{
  vuint8 _c[8];
  _c_SG4_Msg_EPS_A_RDS_msgType SG4_Msg_EPS_A;
} _c_RDS31_buf;
typedef union _c_RDS32_bufTag
{
  vuint8 _c[8];
  _c_SG3_Msg_EPS_A_RDS_msgType SG3_Msg_EPS_A;
} _c_RDS32_buf;
typedef union _c_RDS33_bufTag
{
  vuint8 _c[8];
  _c_SG2_Msg_EPS_A_RDS_msgType SG2_Msg_EPS_A;
} _c_RDS33_buf;
typedef union _c_RDS34_bufTag
{
  vuint8 _c[8];
  _c_SG1_Msg_EPS_A_RDS_msgType SG1_Msg_EPS_A;
} _c_RDS34_buf;


#define RDSTx_2                              ((* ((_c_RDS_Tx_buf_2 MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc00))))
#define RDS193                               ((* ((_c_RDS193_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc10))))
#define RDS194                               ((* ((_c_RDS194_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc20))))
#define RDS195                               ((* ((_c_RDS195_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc30))))
#define RDS196                               ((* ((_c_RDS196_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc40))))
#define RDS197                               ((* ((_c_RDS197_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc50))))
#define RDS198                               ((* ((_c_RDS198_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc60))))
#define RDS199                               ((* ((_c_RDS199_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc70))))
#define RDS200                               ((* ((_c_RDS200_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc80))))
#define RDS201                               ((* ((_c_RDS201_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xc90))))
#define RDS202                               ((* ((_c_RDS202_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xca0))))
#define RDS203                               ((* ((_c_RDS203_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xcb0))))
#define RDS204                               ((* ((_c_RDS204_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xcc0))))
#define RDS205                               ((* ((_c_RDS205_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xcd0))))
#define RDS206                               ((* ((_c_RDS206_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xce0))))
#define RDS207                               ((* ((_c_RDS207_buf MEMORY_NORMAL *)(0xffd20000 + 0x608 + 0xcf0))))
#define RDS19                                ((* ((_c_RDS19_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS20                                ((* ((_c_RDS20_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS21                                ((* ((_c_RDS21_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS22                                ((* ((_c_RDS22_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS23                                ((* ((_c_RDS23_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS24                                ((* ((_c_RDS24_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS25                                ((* ((_c_RDS25_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS26                                ((* ((_c_RDS26_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS27                                ((* ((_c_RDS27_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS28                                ((* ((_c_RDS28_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS29                                ((* ((_c_RDS29_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS30                                ((* ((_c_RDS30_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS31                                ((* ((_c_RDS31_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS32                                ((* ((_c_RDS32_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS33                                ((* ((_c_RDS33_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))
#define RDS34                                ((* ((_c_RDS34_buf MEMORY_NORMAL *)(canRDSRxPtr[2]))))



#define C_TX_NORMAL_0_HW_OBJ                 160
#define C_TX_NORMAL_0_HW_CHANNEL             0
#define CanRxWheel_Pulses_HS_HW_OBJ          0
#define CanRxWheel_Pulses_HS_HW_CHANNEL      0
#define CanRxPPEI_Engine_General_Status_5_HW_OBJ 1
#define CanRxPPEI_Engine_General_Status_5_HW_CHANNEL 0
#define CanRxPPEI_Platform_Eng_Cntrl_Requests_HW_OBJ 2
#define CanRxPPEI_Platform_Eng_Cntrl_Requests_HW_CHANNEL 0
#define CanRxNonDriven_Wheel_Grnd_Velocity_HS_HW_OBJ 3
#define CanRxNonDriven_Wheel_Grnd_Velocity_HS_HW_CHANNEL 0
#define CanRxDriven_Wheel_Grnd_Velocity_HS_HW_OBJ 4
#define CanRxDriven_Wheel_Grnd_Velocity_HS_HW_CHANNEL 0
#define CanRxDriving_Mode_Control_HS_HW_OBJ  5
#define CanRxDriving_Mode_Control_HS_HW_CHANNEL 0
#define CanRxBrake_Pedal_Driver_Status_HS_HW_OBJ 6
#define CanRxBrake_Pedal_Driver_Status_HS_HW_CHANNEL 0
#define CanRxPPEI_Trans_General_Status_2_HW_OBJ 7
#define CanRxPPEI_Trans_General_Status_2_HW_CHANNEL 0
#define CanRxPPEI_Platform_General_Status_HW_OBJ 8
#define CanRxPPEI_Platform_General_Status_HW_CHANNEL 0
#define CanRxPPEI_Chassis_General_Status_1_HW_OBJ 9
#define CanRxPPEI_Chassis_General_Status_1_HW_CHANNEL 0
#define CanRxLKA_Steering_Torque_Cmd_HS_HW_OBJ 10
#define CanRxLKA_Steering_Torque_Cmd_HS_HW_CHANNEL 0
#define CanRxAntilock_Brake_and_TC_Status_HS_HW_OBJ 11
#define CanRxAntilock_Brake_and_TC_Status_HS_HW_CHANNEL 0
#define CanRxPPEI_Engine_General_Status_1_HW_OBJ 12
#define CanRxPPEI_Engine_General_Status_1_HW_CHANNEL 0
#define CanRxPPEI_NonDrivn_Whl_Rotationl_Stat_HW_OBJ 13
#define CanRxPPEI_NonDrivn_Whl_Rotationl_Stat_HW_CHANNEL 0
#define C_BASIC0_0_HW_OBJ                    128
#define C_BASIC0_0_HW_CHANNEL                0

#define C_TX_NORMAL_1_HW_OBJ                 176
#define C_TX_NORMAL_1_HW_CHANNEL             1
#define CanRxNonDriven_Wheel_Grnd_Velocity_CE_HW_OBJ 14
#define CanRxNonDriven_Wheel_Grnd_Velocity_CE_HW_CHANNEL 1
#define CanRxDriven_Wheel_Grnd_Velocity_CE_HW_OBJ 15
#define CanRxDriven_Wheel_Grnd_Velocity_CE_HW_CHANNEL 1
#define CanRxPark_Assist_Parallel_CE_HW_OBJ  16
#define CanRxPark_Assist_Parallel_CE_HW_CHANNEL 1
#define CanRxVehicle_Dynamics_ESC_Hyb_CE_HW_OBJ 17
#define CanRxVehicle_Dynamics_ESC_Hyb_CE_HW_CHANNEL 1
#define CanRxSteering_Torque_Command_CE_HW_OBJ 18
#define CanRxSteering_Torque_Command_CE_HW_CHANNEL 1
#define C_BASIC0_1_HW_OBJ                    129
#define C_BASIC0_1_HW_CHANNEL                1

#define C_TX_NORMAL_2_HW_OBJ                 192
#define C_TX_NORMAL_2_HW_CHANNEL             2
#define CanTxSG1_Msg_EPS_B_HW_OBJ            193
#define CanTxSG1_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG2_Msg_EPS_B_HW_OBJ            194
#define CanTxSG2_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG3_Msg_EPS_B_HW_OBJ            195
#define CanTxSG3_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG4_Msg_EPS_B_HW_OBJ            196
#define CanTxSG4_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG5_Msg_EPS_B_HW_OBJ            197
#define CanTxSG5_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG6_Msg_EPS_B_HW_OBJ            198
#define CanTxSG6_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG7_Msg_EPS_B_HW_OBJ            199
#define CanTxSG7_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG8_Msg_EPS_B_HW_OBJ            200
#define CanTxSG8_Msg_EPS_B_HW_CHANNEL        2
#define CanTxSG10_Msg_EPS_B_HW_OBJ           201
#define CanTxSG10_Msg_EPS_B_HW_CHANNEL       2
#define CanTxSG11_Msg_EPS_B_HW_OBJ           202
#define CanTxSG11_Msg_EPS_B_HW_CHANNEL       2
#define CanTxSG12_Msg_EPS_B_HW_OBJ           203
#define CanTxSG12_Msg_EPS_B_HW_CHANNEL       2
#define CanTxSG13_Msg_EPS_B_HW_OBJ           204
#define CanTxSG13_Msg_EPS_B_HW_CHANNEL       2
#define CanTxSG14_Msg_EPS_B_HW_OBJ           205
#define CanTxSG14_Msg_EPS_B_HW_CHANNEL       2
#define CanTxSG15_Msg_EPS_B_HW_OBJ           206
#define CanTxSG15_Msg_EPS_B_HW_CHANNEL       2
#define CanTxSG16_Msg_EPS_B_HW_OBJ           207
#define CanTxSG16_Msg_EPS_B_HW_CHANNEL       2
#define CanRxSG16_Msg_EPS_A_HW_OBJ           19
#define CanRxSG16_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG15_Msg_EPS_A_HW_OBJ           20
#define CanRxSG15_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG14_Msg_EPS_A_HW_OBJ           21
#define CanRxSG14_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG13_Msg_EPS_A_HW_OBJ           22
#define CanRxSG13_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG12_Msg_EPS_A_HW_OBJ           23
#define CanRxSG12_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG11_Msg_EPS_A_HW_OBJ           24
#define CanRxSG11_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG10_Msg_EPS_A_HW_OBJ           25
#define CanRxSG10_Msg_EPS_A_HW_CHANNEL       2
#define CanRxSG9_Msg_EPS_A_HW_OBJ            26
#define CanRxSG9_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG8_Msg_EPS_A_HW_OBJ            27
#define CanRxSG8_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG7_Msg_EPS_A_HW_OBJ            28
#define CanRxSG7_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG6_Msg_EPS_A_HW_OBJ            29
#define CanRxSG6_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG5_Msg_EPS_A_HW_OBJ            30
#define CanRxSG5_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG4_Msg_EPS_A_HW_OBJ            31
#define CanRxSG4_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG3_Msg_EPS_A_HW_OBJ            32
#define CanRxSG3_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG2_Msg_EPS_A_HW_OBJ            33
#define CanRxSG2_Msg_EPS_A_HW_CHANNEL        2
#define CanRxSG1_Msg_EPS_A_HW_OBJ            34
#define CanRxSG1_Msg_EPS_A_HW_CHANNEL        2
#define C_BASIC0_2_HW_OBJ                    130
#define C_BASIC0_2_HW_CHANNEL                2




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 245625395
      #error "The magic number of the generated file <C:\_synergy\G2KCAT3_CZ8L9T\GM_G2KCA_EPS_RH850\generate\GENy_B\can_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 245625395
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __CAN_PAR_H__ */
