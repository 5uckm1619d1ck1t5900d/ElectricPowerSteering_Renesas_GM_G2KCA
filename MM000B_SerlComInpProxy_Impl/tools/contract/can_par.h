#ifndef CAN_PAR_H
#define CAN_PAR_H



void CanRxFullCANObjTask(uint8, uint16);

#define CanRxSG1_Msg_EPS_B_HW_CHANNEL        2
#define CanRxSG1_Msg_EPS_B_HW_OBJ            35

typedef unsigned int     vbittype;
typedef uint8            vuint8;
typedef uint16           vuint16;

typedef vuint16           CanObjectHandle;
typedef vuint8 CanChannelHandle;

typedef struct _c_SG1_Msg_EPS_B_msgTypeTag
{
  vbittype SG1_Data_EPS_B_7 : 8;
  vbittype SG1_Data_EPS_B_6 : 8;
  vbittype SG1_Data_EPS_B_5 : 8;
  vbittype SG1_Data_EPS_B_4 : 8;
  vbittype SG1_Data_EPS_B_3 : 8;
  vbittype SG1_Data_EPS_B_2 : 8;
  vbittype SG1_Data_EPS_B_1 : 8;
  vbittype SG1_Data_EPS_B_0 : 8;
} _c_SG1_Msg_EPS_B_msgType;

typedef union _c_SG1_Msg_EPS_B_bufTag
{
  vuint8 _c[8];
  _c_SG1_Msg_EPS_B_msgType SG1_Msg_EPS_B;
} _c_SG1_Msg_EPS_B_buf;

extern _c_SG1_Msg_EPS_B_buf SG1_Msg_EPS_B;

#endif
