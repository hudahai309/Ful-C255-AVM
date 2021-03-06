/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ    									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        : 
* Module        : 
* Instance      : 
* Description   : 
*-----------------------------------------------------------------------
* Version: 
* Date: 
* Author: 
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
*-----------------------------------------------------------------------
*   0.1         2016/8/20       ShangQiuju      Init verssion
*-----------------------------------------------------------------------
*   0.2         2017/1/13      ShangQiuju      Fix coverity warnings.
*-----------------------------------------------------------------------
*   0.3         2017/2/10      ShangQiuju      Remove unused parameters.
*-----------------------------------------------------------------------
*   0.4         2017/3/13      ShangQiuju      Add eol spi upgrade test function.
*------------------------------------------------------------------------
*   0.5   Apr 01,2017   PEI Jingli  Fix headfile included.
*=====================================================================*/
#ifndef _SOC_MSG_CFG_H_
#define _SOC_MSG_CFG_H_ 
#include "Define.h"

/**** Definition of constants ****/

#define SOC_FRAME_MAXLENGTH 255
typedef enum
{
  E_MSG_SAFE=1,
  E_MSG_DIG,
  E_MSG_GEN,
  E_MSG_DBG,
  E_INVALD_PRI
}E_NAVIMSGID_PRI;

/**** Definition of macros ****/
typedef struct
{
U8 MsgReqType;
U8 MsgRepType;
U8 MsgPriority;
U16 MsgIDVal;
}MsgConfig;


#define MAX_LIST_ITEMS 30
#define MAX_PAGE_ITEMS 5
#define SVR(x,y)                  (((x << 3) + y)<<8)

enum CMPT_ID_ITEM
{
    CMPT_ID_GEN,       //0
    CMPT_ID_REC,       //1
    CMPT_ID_CD,        //2
    CMPT_ID_COMMONINFO,   // 3
    CMPT_ID_MP3,       //4
    CMPT_ID_DVD,       //5
    CMPT_ID_AUDIO,     //6
    CMPT_ID_CLOCK,     //7
    CMPT_ID_SYSTEM,    //8
    CMPT_ID_INP,       //9
    CMPT_ID_OOM,       //10
    CMPT_ID_PWM,       //11
    CMPT_ID_NAVIGATION,     //12
    CMPT_ID_AUX,       //13
    CMPT_ID_THIEFT,    //14
    CMPT_ID_DIAG,      //15
    CMPT_ID_EOL,  //16
    CMPT_ID_BT_PHONE,  //17
    CMPT_ID_MEDIA,     //18
    CMPT_ID_HVAC,     //19
    CMPT_ID_END       //20
};

enum EN_CMD_TYPE
{
    TYPE_SERVICE=1,
    TYPE_QUERY,
    TYPE_RESPONSE,
    TYPE_EVENT,
    TYPE_CONTROL,
    TYPE_UTILITY,
    TYPE_MAX
};

enum COMMON_INFO_REQUEST
{
    SOC_REQ_SOFT_VERSION = 0x4201,
    SOC_REQ_RESEND_IMPORTANT_MESSAGE = 0x4202,
    SOC_NOTI_CAMERA_FAULT = 0x4203,
    REQ_SOC_TO_SEND_REMOVABLE_DEVICE_STATUS = 0x820A,
};

enum COMMON_INFO_RESPONSE
{
    SEND_RESP_OF_SOC_NOTIFY_CAMERA_FAULT = 0x4303,
    SOC_SEND_RESP_OF_REMOVABLE_DEVICE_STATUS = 0x830B,
};


enum SYSTEM_COMMAND_ID
{      
    /*VICP_SIG_SPEED=0x4401,
    VICP_SIG_PLUSE_CNT,//0x4402
    VICP_SIG_TURN_INDICATOR,//0x4403
    VICP_SIG_STEERING_WHEEL,//0x4404
    VICP_SIG_REVERSE_STATUS,//0x4405
    VICP_SIG_VIEW_ANGLE_SWITCH=0x4406,
    VICP_SIG_SETTING_MSG,//0x4407
    VICP_SIG_ALERT_INFO,//0x4408
    VICP_SIG_INFO_OF_RADAR,//0x4409
    VICP_SIG_INFO_OF_KEY_STAUS,//0x440A
    VICP_SIG_VIEW_MODLE_SWITCH,//0x440B
    VICP_SIG_AVM_DIAPLAY_REQUEST,//0x440C
    VICP_SIG_DVR_WARNING,//0x440D
    VICP_SIG_LDWS_WARNING,//0x440E    
    VICP_SIG_BSD_WARNING,//0x440F
    VICP_SIG_CRASHOUT_STATUS,//0x4410
    VICP_SIG_BEAM_STATUS,//0x4411
    VICP_SIG_TRUNK_STATUS,//0x4412
    VICP_SIG_DVD_TIMES,//0x4413
    VICP_SIG_YRS_DATA,//0x4414
    VICP_SIG_NAVI_SETTING_RESP,//0x4415
    VICP_SIG_AVM_STATUS,//0x4416
    VICP_SIG_AVM_OTHER_MSG_RESP,//0x4417
    VICP_SIG_MAX*/
    RADIO_NOTIFY_SPEED_DATA=0x4401,
    RADIO_NOTIFY_PLUS_COUNT_DATA,//0x4402
    RADIO_NOTIFY_TURNING_SIGNAL=0x4403,//0x4403
    RADIO_NOTIFY_STEERING_WHEEL_DATA,//0x4404
    RADIO_NOTIFY_RVC_STATUS,//0x4405
    RADIO_NOTIFY_KEY_STATUS=0x4406,
    RADIO_NOTIFY_COORDINATE_DATA=0x4407, 
    RADIO_NOTIFY_SET_STATUS=0x4408,
    RADIO_NOTIFY_ALERT_INFO=0x4409,
    RADIO_NOTIFY_RADAR_SENSOR_DISTANCE=0x440A,
    RADIO_NOTIFY_DOORS_INFO=0x440C,
    RADIO_NOTIFY_IGN_KEY_STATUS=0x440D,
    RADIO_NOTIFY_LDW_SETTING_DATA=0x440E,
    RADIO_NOTIFY_VIEW_MODE_ANGLE=0x440F,
    CPU_NOTIFY_M3_AVM_DISPLAY_STATUS=0x4410,//4410
    CPU_NOTIFY_M3_AVM_SETTING_RESULT=0x4411,//4411
    CPU_NOTIFY_M3_AVM_SYSTEM_STATUS,//4412
    CPU_NOTIFY_M3_LDW_SETTING_RESULT,//4413
    CPU_NOTIFY_M3_LDW_STATUS,//4414
    RADIO_NOTIFY_RADAR_AND_PDC_STATUS=0x4415,
    RADIO_NOTIFY_RADAR_SENSOR_ERROR_FLAG=0x4416,
    RADIO_NOTIFY_RADAR_SENSOR_BLOCKAGE_FLAG=0x4417,
    NAVI_SEND_CAMERA_BLOCKAGE_STATUS=0x4418,
    RADIO_NOTIFY_DYNAMICPGS_STATUS=0x4419,
    RADIO_NOTIFY_HAZARD_TURNING_SIGNAL=0x4420,
    RADIO_NOTIFY_GEAR_DISPLAY_STATUS=0x4421,
    RADIO_NOTIFY_DVR_BROWSE_COMMAND=0x4426,
    RADIO_NOTIFY_DVR_COMMAND_LIST_REQ=0x4427, 
    RADIO_NOTIFY_DVR_SELECT_COMMAND=0x4428,
//    RADIO_NOTIFY_CURRENT_DATE_TIME=0x442B,
	RADIO_NOTIFY_LANGIAGE_SET = 0x442A,
    RADIO_NOTIFY_WARN_RCTA_STATUS=0x442C,
    CPU_NOTIFY_M3_AVM_DISPLAY_VIEWSTSRSP=0x442D,
    CPU_NOTIFY_M3_DVR_SYSTEM_STATUS=0x442E,
    CPU_NOTIFY_M3_DVR_SDSTATUS=0x442F,
    CPU_NOTIFY_M3_DVR_COMMAND_LIST_RESP=0x4430,
    CPU_NOTIFY_M3_DVR_CURRENTVIDEO_CNT=0x4431,
    CPU_NOTIFY_M3_DVR_SET_RESP=0x4432,
    CPU_NOTIFY_M3_CALIBRATION_SUCCESS=0x4433,
    RADIO_NOTIFY_COORDINATE_RESOLUTION=0x4434,
    RADIO_NOTIFY_STEERING_WHEEL_DIRECTION = 0x443F,
    J6_SEND_RESPONSE_OF_BLINDSPOTFILLED_STATUS=0x4443,
    RADIO_NOTIFY_J6_BLINDSPOTFILLED_REQ=0x4445,
    J6_SEND_RESPONSE_OF_TurnFollowUp_STATUS=0x4446,
    RADIO_NOTIFY_J6_TurnFollowUp_REQ=0x4447,
    RADIO_NOTIFY_REARVIEW_MIRROR_STATUS=0x444D, 
    //SOC_REQ_SOFT_VERSION = 0x4201,
    //J6_REQUEST_M3_TO_RESEND_IMPORTANT_MESSAGE=0x4202,//4202
    //SOC_REQ_RESEND_IMPORTANT_MESSAGE = 0x4202,
    //SOC_NOTI_CAMERA_FAULT = 0x4203,
    //REQ_SOC_TO_SEND_USB_INTERFACE_STATUS = 0x4204,
    SEND_SOFT_VERSION_TO_SOC = 0x4301,
    RADIO_NOTIFY_APA_SYSTEM_STATUS = 0x44C5,
    MCU_Send_EOL_Line_View_To_APP = 0x44C7,
    APP_Send_EOL_View_Result_To_MCU = 0x44C8,
    RADIO_NOTIFY_ENTER_OFFLINE_CALIBRATION_MODE=0x44F0,
    CPU_NOTIFY_M3_ENTER_OFFLINE_CALIBRATION_STATUS_RESULT=0x44F1,
    RADIO_NOTIFY_START_OFFLINE_CALIBRATION=0x44F2,
    CPU_NOTIFY_M3_OFFLINE_CALIBRATION_RESULT=0x44F3,
    CPU_NOTIFY_M3_CALIBRATION_FAIL_REASON=0x44F4,
    CPU_NOTIFY_M3_CALIBRATION_DONE=0x44F5,
    RADIO_NOTIFY_REQUEST_CALIBRATION_RESULT=0x44F6,
    
};


enum OOM_EVENT
{
    NAVI_SHUT_DOWN_EVENT = SVR(CMPT_ID_OOM,TYPE_EVENT)+1,   /*5401 NEED USED*/
    NAVI_RESP_EVENT,
    NAVI_SPECIAL_EVENT,
    NAVI_30_HOUR_RESET_FINISH,
    NAVI_SWDL_CONFIG_EVENT=0x5410,
    NAVI_START_END_SWDL_FILE_EVENT,
    NAVI_SWDL_DATA_EVENT,
    NAVI_SWDL_STATUS_EVENT,//0x5413
    NAVI_REQ_TO_RESET_EVENT,//0x5414
    NAVI_SELF_UPGRADE_RESULT_EVENT,//0x5415
};
enum OOM_SERVICE
{
    RADIO_DISPATCH_CHANGE_POWER_MODE= SVR(CMPT_ID_OOM,TYPE_SERVICE)+1,/*5101 USED*/
    RADIO_DISPATCH_SET_BACK_LIGHT,
    RADIO_DISPATCH_ERROR_SET_BACK_LIGHT,
    RADIO_DISPATCH_NAVI_30_HOUR_RESET,
    RADIO_DISPATCH_SWDL_GET_DATA=0x5110,
    RADIO_DISPATCH_SWDL_ENTER_EXIT,
};

enum OOM_QUERY
{
    NAVI_GET_RADIO_STATUS = SVR(CMPT_ID_OOM,TYPE_QUERY)+1,  //0x5201
    M3_SEND_UOGRADE_REQUEST_TO_J6 = 0x5202,
     J6_REQUEST_M3_EOL_STATUS = 0x5306,
};

enum OOM_RESPONSE
{
    RADIO_SEND_RECV_J6_SELFUPGRADE_RESP=0x5301,
	M3_RESPOND_J6_EOL_STATUS = 0x5307,
};


enum EOL_QUERY
{
    RADIO_QUERY_ENG_SW_VERSION=SVR(CMPT_ID_EOL,TYPE_QUERY)+1,//8201
    FORWARD_QUERY_J6_TO_START_UPGRADE_LICENSE_REQ,//8202
    FORWARD_QUERY_J6_TO_SEND_LICENSE_HW_INFO_REQ,//8203
    FORWARD_QUERY_J6_OF_LICENSE_TRANSMIT_REQ,//8204
    FORWARD_QUERY_J6_OF_LICENSE_TRANSMIT_DATA,//8205
    #ifdef AB01_HW
    RADIO_REQUEST_A6_ENTER_FAIL_SAFE_MODE = 0x8206,
    #endif
    RADIO_REQUEST_SET_J6_CONFIG_DATA = 0x8207,
    RADIO_REQUEST_GET_J6_CONFIG_DATA = 0x8208,
    J6_NOTIFY_M3_SELFTEST_RESULT = 0x8401,
    M3_SEND_RESP_OF_J6SELFTEST = 0x8301,
    J6_SEND_RESPONSE_OF_VERSION = 0x8302,
    FORWARD_START_UPGRADE_LICENSE_RESP_TO_PC,//8303
    FORWARD_SEND_LICENSE_HW_INFO_RESP_TO_PC,//8304
    FORWARD_LICENSE_TRANSMIT_REQ_RESP_TO_PC,//8305
    FORWARD_LICENSE_TRANSMIT_DATA_RESP_TO_PC,//8306
    #ifdef AB01_HW
    A6_SEND_ENTER_FAIL_SAFE_MODE_RESP_TO_RADIO = 0x8307,
    #endif
    J6_SEND_RESPONSE_OF_SET_J6_CONFIG_DATA = 0x8308,
    J6_SEND_RESPONSE_OF_GET_J6_CONFIG_DATA = 0x8309,
	M3_REQ_J6_ENTER_SELF_DIAG = 0x820D, 		//	REQ_J6_ENTER_SELF_DIAG
	J6_RESP_OF_ENTER_SELF_DIAG_STATUS = 0x830E, //	response  REQ_J6_ENTER_SELF_DIAG

	M3_SEND_RESP_OF_CAMERA_STATUS = 0x830A,	
};

/*************for keyboard**************/
enum INP_EVENT
{
 #ifdef ENABLE_UNUSED
    RADIO_DISPATCH_HU_HARD_KEY= SVR(CMPT_ID_INP,TYPE_EVENT)+1,
    RADIO_DISPATCH_HU_ROTARY,
    NAVI_TOUCH_SCREEN_KEY,
    NAVI_SCROLL_KEY,
    NAVI_BACKLIGHT,
    NAVI_SPI_TEST_DATA_0,
    NAVI_SPI_TEST_DATA_1,
    NAVI_NULL,
    NAVI_VR_CONTRL,          //0x4C09
    NAVI_VR_OVER,            //0x4C0A
    NAVI_VR_SOURCE_CONTROL,          //0x4C0B
    NAVI_INTER_CHANGE,//      //0x4C0C
    NAVI_SRC_RETURN,          //0x4C0D
    NAVI_LOGO_FINISHED,       //0x4C0E
    NAVI_TOUCH_SCREEN_KEY_EXTEND,//NAVI_EVENT_NULL_1,
    NAVI_EVENT_NULL_2,
    HK_FROM_NAVI,
#endif /*ENABLE_UNUSED*/
    NAVI_REC_SET_FREQ = 0x4C13,
    NAVI_ENTER_NVAI_MAP = 0x4C14,
    NAVI_DEVICES_STATE = 0x4C16,
    RADIO_NOTIFY_INP_ROTARY,
    RADIO_NOTIFY_INP_HARDKEY,
};

enum INP_HK_PARAM_HD_KEY
{
    HD_KEY1 = 1,
	HD_KEY2,
	HD_KEY3,
	HD_KEY4,
	HD_KEY5,
	HD_KEY6,
	HD_KEY7,
	HD_KEY8,
	HD_KEY9,
	HD_KEY10,
	HD_KEY11,
	HD_KEY12,
	HD_KEY13,
	HD_KEY14,
	HD_KEY15,
	HD_KEY16,
	HD_KEY17,
    HD_KEY18,

    HD_KEY_NULL = HD_KEY18 // Last key
    
};

enum INP_PARAM_KEY_STATE
{
    KEY_PRESSED,
    KEY_RELEASED,
    /*G4 key event: upper byte=key state; lower byte=key id */
    KEY_RELEASE = 0x0000,
    KEY_PRESS = 0x0100,
    KEY_LONGPRESS = 0xf000,
    KEY_LONGLONGPRESS = 0xff00,
};

/**** Declaration of constants ****/
extern void SocManager_Dispatcher_Msg(U8 cmpt_id,U16 commandid, U8* data);
extern void SocManager_Dispatcher_SentResult(U16 commandid, BOOL result);

#define SOC_MSGDISPATCHER(cmpt_id,commandid,data)    SocManager_Dispatcher_Msg(cmpt_id,commandid,data)
/**** Declaration of variables ****/

/**** Declaration of functions ****/
#endif /*_SOC_MSG_CFG_H_*/

/****************************** END OF FILE ***************************/

