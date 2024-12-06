extern VAR(boolean, AUTOMATIC) DTC_Triggered_778_conf_b;
extern VAR(boolean, AUTOMATIC) PPEI_Steering_Wheel_Angle_conf_b;
extern VAR(boolean, AUTOMATIC) LKA_Steering_Trq_Overlay_Stat_HS_conf_b;
extern VAR(boolean, AUTOMATIC) Power_Steering_Information_HS_conf_b;
extern VAR(boolean, AUTOMATIC) Electric_Power_Steering_CE_conf_b;
extern VAR(boolean, AUTOMATIC) PPEI_Steering_Wheel_Angle_CE_conf_b;
extern VAR(boolean, AUTOMATIC) Steering_Torque_Overlay_Stat_CE_conf_b;

extern FUNC(void, AUTOMATIC) CanWriteSyncDTC_Triggered_778_conf_b(VAR(boolean, AUTOMATIC) Flag);
extern FUNC(void, AUTOMATIC) CanWriteSyncPPEI_Steering_Wheel_Angle_conf_b(VAR(boolean, AUTOMATIC) Flag);
extern FUNC(void, AUTOMATIC) CanWriteSyncLKA_Steering_Trq_Overlay_Stat_HS_conf_b(VAR(boolean, AUTOMATIC) Flag);
extern FUNC(void, AUTOMATIC) CanWriteSyncPower_Steering_Information_HS_conf_b(VAR(boolean, AUTOMATIC) Flag);
extern FUNC(void, AUTOMATIC) CanWriteSyncElectric_Power_Steering_CE_conf_b(VAR(boolean, AUTOMATIC) Flag);
extern FUNC(void, AUTOMATIC) CanWriteSyncPPEI_Steering_Wheel_Angle_CE_conf_b(VAR(boolean, AUTOMATIC) Flag);
extern FUNC(void, AUTOMATIC) CanWriteSyncSteering_Torque_Overlay_Stat_CE_conf_b(VAR(boolean, AUTOMATIC) Flag);

#define CanTxDTC_Triggered_778               0
#define CanTxCmnMfgSrvResp                   1
#define CanTxXcp_Slave_Msg                   2
#define CanTxUSDT_Resp_From_EHPS_EPS_HS      3
#define CanTxUUDT_Resp_From_EHPS_EPS_HS      4
#define CanTxPPEI_Steering_Wheel_Angle       5
#define CanTxLKA_Steering_Trq_Overlay_Stat_HS 6
#define CanTxPower_Steering_Information_HS   7
#define CanTxUSDT_Resp_From_EPS_EPS_JR_CE    8
#define CanTxUUDT_Resp_From_EPS_EPS_JR_CE    9
#define CanTxElectric_Power_Steering_CE      10
#define CanTxPPEI_Steering_Wheel_Angle_CE    11
#define CanTxSteering_Torque_Overlay_Stat_CE 12
#define CanTxSG9_Msg_EPS_A                   13
#define CanTxSG0_Msg_EPS_A_ONLY_SCI          14
#define CanTxSG16_Msg_EPS_A                  15
#define CanTxSG15_Msg_EPS_A                  16
#define CanTxSG14_Msg_EPS_A                  17
#define CanTxSG13_Msg_EPS_A                  18
#define CanTxSG12_Msg_EPS_A                  19
#define CanTxSG11_Msg_EPS_A                  20
#define CanTxSG10_Msg_EPS_A                  21
#define CanTxSG8_Msg_EPS_A                   22
#define CanTxSG7_Msg_EPS_A                   23
#define CanTxSG6_Msg_EPS_A                   24
#define CanTxSG5_Msg_EPS_A                   25
#define CanTxSG4_Msg_EPS_A                   26
#define CanTxSG3_Msg_EPS_A                   27
#define CanTxSG2_Msg_EPS_A                   28
#define CanTxSG1_Msg_EPS_A                   29

typedef unsigned int     vbittype;
typedef uint8            vuint8;
typedef uint16           vuint16;

typedef vuint16           CanTransmitHandle;
typedef vuint16           CanObjectHandle;
typedef vuint8            CanChannelHandle;

typedef struct _c_SG1_Msg_EPS_A_msgTypeTag
{
  vbittype SG1_Data_EPS_A_7 : 8;
  vbittype SG1_Data_EPS_A_6 : 8;
  vbittype SG1_Data_EPS_A_5 : 8;
  vbittype SG1_Data_EPS_A_4 : 8;
  vbittype SG1_Data_EPS_A_3 : 8;
  vbittype SG1_Data_EPS_A_2 : 8;
  vbittype SG1_Data_EPS_A_1 : 8;
  vbittype SG1_Data_EPS_A_0 : 8;
} _c_SG1_Msg_EPS_A_msgType;

typedef union _c_SG1_Msg_EPS_A_bufTag
{
  vuint8 _c[8];
  _c_SG1_Msg_EPS_A_msgType SG1_Msg_EPS_A;
} _c_SG1_Msg_EPS_A_buf;

extern _c_SG1_Msg_EPS_A_buf SG1_Msg_EPS_A;

extern vuint8 CanTransmit(CanTransmitHandle txHandle);
extern void SerlComOutpProxy_184CfmFct(CanTransmitHandle txObject);
extern void SerlComOutpProxy_1CACfmFct(CanTransmitHandle txObject);
extern void SerlComOutpProxy_1E5HiSpdCfmFct(CanTransmitHandle txObject);
extern void SerlComOutpProxy_184CfmFct(CanTransmitHandle txObject);
extern void GgdaUudtConfirmation(CanTransmitHandle txObject);
extern void SerlComOutpProxy_335CfmFct(CanTransmitHandle txObject);
extern void SerlComOutpProxy_1E5ChassisExpCfmFct(CanTransmitHandle txObject);
extern void SerlComOutpProxy_1CACfmFct(CanTransmitHandle txObject);
