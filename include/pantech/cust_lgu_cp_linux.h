#ifndef __CUST_LGU_CP_LINUX_H
#define __CUST_LGU_CP_LINUX_H

/* =============================================================================
FILE: cust_lgu_cp_linux.h

Copyright (c) 2010 by PANTECH Incorporated.  All Rights Reserved.

��)     FEATURE_LGU_CP_xxx_XXX_001
         Ver.001 : 2011-08-18 : Jake, Lee 
���� ���� : -------------------------------------------------------------------------

1.	Custfile�� ���� ������ �ڼ��� �ۼ��� �ֽð� �ش� �ڵ� �κп� feature�� ������ �ۼ��մϴ�.
2.	���� ���� �ۼ��ÿ��� ������ �䱸 ���� �� standard spec. �� index�� �켱���� �ۼ��Ͻð�
3.	�׿� ��û���� �� side effect ������ ���� �ۼ� �մϴ�.

============================================================================= */

/*************************************************/
/*                     COMMON                    */
/*************************************************/

#define FEATURE_LGU_CP_COMMON_LOCAL_DB_WITH_QMI
#define FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_COMMON_NVIO_WITH_QMI

/*
    PS1 add.
*/
#define FEATURE_LGU_CP_RIL_FW_ANDROID_REQUEST_HNDL_MAX_EVT_ID_FIX
#define FEATURE_LGU_CP_FW_DEDICATED_ANDROID_REQ_BUG_FIX



#define FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#ifdef FEATURE_LGU_CP_MANAGER_DAEMON_INTERFACE
#define FEATURE_LGU_CP_CPMGRIF_QMI_CLIENT
#define FEATURE_LGU_CP_OEM_COMMANDS_WITH_QMI
#define FEATURE_LGU_CP_OEM_QMI_ACCESS
#define FEATURE_LGU_COMMON_TELEPHONY_IF
#endif

#define FEATURE_LGU_GW_COMMON_TELEPHONY_IF

#define FEATURE_LGU_COMMON_DEBUG_SCREEN

#define FEATURE_LGU_CP_COMMON_GLOBAL_SD

#define FEATURE_LGU_CP_COMMON_TEST_MODE

#define FEATURE_LGU_CP_SKY_ENG_MENU

#define FEATURE_LGU_CP_COMMON_RSSI

#define FEATURE_LGU_CP_COMON_DEFAULT_SETTINGS

#define FEATURE_LGU_CP_COMMON_MDN_MIN_FIX

#define FEATURE_LGU_CP_COMMON_PLMN_FIX_FOR_CDMA

/* SKY �ڵ��������� Interface */
#define FEATURE_LGU_CP_AUTOANSWER_INTERFACE

#define FEATURE_LGU_CP_CARD_POWER_DOWN_NOT_SUPPORT

#define FEATURE_LGU_CP_COMMON_OPERATORS_FOR_3GPP2

#define FEATURE_LGU_CP_COMMON_CLEAR_ALL_CONNECTIONS_WHEN_LPM

#define FEATURE_LGU_CP_COMMON_UPDATE_VOICE_RTE

#define FEATURE_LGU_CP_GUARD_NULL_EXCEPTION_WHEN_PHONE_CHANGE

#define FEATURE_LGU_CP_COMMON_UPDATE_SERVICE_STATE_FOR_DATA_ONLY

#define FEATURE_LGU_CP_COMMON_ROAMING_STATE_FIX

#define FEATURE_LGU_CP_COMMON_ANDROID_OTASP_BLOCK

#define FEATURE_LGU_CP_COMMON_RUDE_WAKEUP

#define FEATURE_LGU_CP_COMMON_CARD_ABSENT_BUG_FIX

#define FEATURE_LGU_CP_COMMON_OPENING_DAY
#ifdef FEATURE_LGU_CP_COMMON_OPENING_DAY
#define FEATURE_SKY_CP_NEW_OPENING_DAY
#define FEATURE_SKY_CP_OEM_PH_EVENT_WITH_QMI /* Deliver CM PH event info via qmi(nas) */
#endif /* FEATURE_LGU_CP_COMMON_OPENING_DAY */

#define FEATURE_LGU_CP_DOMESTIC_CHECK

#define FEATURE_LGU_CP_COMMON_SPN_DEBUG

/*************************************************/
/*                     1X                        */
/*************************************************/

#define FEATURE_LGU_CP_1X_DEFAULT_SETUP

#define FEATURE_LGU_CP_1X_LOCAL_DB

#ifdef FEATURE_LGU_CP_1X_LOCAL_DB
#define FEATURE_LGU_CP_1X_LOCAL_DB_WITH_QMI
#endif /* FEATURE_LGU_CP_1X_LOCAL_DB */

#ifdef FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_1X_DEBUG_SCREEN
#endif /* FEATURE_LGU_COMMON_DEBUG_SCREEN */

#define FEATURE_LGU_CP_OEM_API

#define FEATURE_LGU_CP_1X_OTASP

#define FEATURE_LGU_CP_1X_PRL_VERSION

#define FEATURE_LGU_CP_1X_SYSLOST_MONITOR

#define FEATURE_LGU_CP_1X_TEST_CALL_SO

#define FEATURE_LGU_CP_1X_SWITCH_TO_BURST_DTMF

#define FEATURE_LGU_CP_1X_8BIT_CHAR_SUPPORT

#define FEATURE_LGU_CP_1X_REG_STATE_UPDATE

#define FEATURE_LGU_CP_1X_FACTORY_INIT

#define FEATURE_LGU_CP_1X_REJ_DISPLAY

#define FEATURE_LGU_CP_SKIP_TOA_CHECK // related to modem Feature : FEATURE_LGU_CP_1X_NUMBERTYPE_FIX

// #define FEATURE_LGU_CP_1X_EXT_DISPLAY_Q_BUGFIX // Removed for EF46L JB// Qualmm fixed

/*************************************************/
/*                    EVDO                       */
/*************************************************/
#ifdef FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_EVDO_DEBUG_SCREEN
#define FEATURE_LGU_CP_EVDO_DB_QMI
#endif /* FEATURE_LGU_COMMON_DEBUG_SCREEN */

#define FEATURE_LGU_CP_EVDO_ENG_MODE
#ifdef FEATURE_LGU_CP_EVDO_ENG_MODE
#define FEATURE_LGU_CP_EVDO_REV_SETTING
#define FEATURE_LGU_CP_EVDO_SESSION_RESET
#define FEATURE_LGU_CP_EVDO_ERROR_REASON_CODE_WITH_QMI
#define FEATURE_LGU_CP_EVDO_CHECK_VT_REG_STATUS
#define FEATURE_LGU_CP_EVDO_WIPI_NETWORK_ERROR_CODE  
#define FEATURE_LGU_CP_EVDO_SESSION_CLOSE_NOTY_FOR_VT
#endif

/*************************************************/
/*                 WCDMA/GSM                     */
/*************************************************/
#define FEATURE_LGU_CP_GW_LOCAL_DB

#define FEATURE_LGU_CP_LOCAL_DB_GW_ACCESS_CPMGRIF

#define FEATURE_LGU_CP_GW_LOCAL_DB_WITH_QMI

#define FEATURE_LGU_CP_GW_DEBUG_SCREEN

#define FEATURE_LGU_CP_GW_REJECT_CAUSE_DISPLAY

#define FEATURE_LGU_CP_GW_RSSI_LEVEL

/* QMI �� ���ؼ� CM system selection preference ȣ�� */
#define FEATURE_LGU_CP_CM_SYS_SELECTION_PREF

/* UMTS SMS MO PS/CS Domain setting menu support */
#define FEATURE_LGU_CP_SMS_CFG_SET_GW_DOMAIN

/* Phone Operation Mode setting (lpm, offline, online .. ) */
#define FEATURE_LGU_CP_PHONE_OPERATION_MODE

/* Voice Call connection sound event */
#define FEATURE_LGU_CP_GW_CS_CALL_CONNECTION_SND_START

/*
   ��ȭ�� ������ ������ ���� Setup ind. ���� signal value�� ������.
   AMSS���� FEATURE_SKY_CP_SETUP_IND_SIGNAL_VALUE �� �ݵ��� �����Ǿ��� ��.
*/   
#define FEATURE_LGU_CP_GW_SETUP_IND_SIGNAL_VALUE

/* PLMN ���� �˻�  */
#define FEATURE_LGU_CP_GW_NETWORK_PLMN_MANUAL_SELECTION

/* Limited service���¸� �����ϱ� ���ؼ� ServiceState ����. */
#define FEATURE_LGU_CP_GW_SERVICE_STATUS_DETAIL_SUBSTATE

/* 
    Network Name�� ������������ �ұ��ϰ�, "nas_cached_info.current_plmn" ���� Invalid�� ó���Ǿ� 
   �ش� Network Name�� �ƴ� Table�� name�� ǥ���ϴ� ������ ���� Qcril���� �����ϴ� system info�� 
   state ��ȭ�ø��� update�ϵ��� ��.
   QCT�� �� system info�� LCD enable�ÿ��� update �ϵ��� �ϰ� ����
*/
#define FEATURE_LGU_CP_GW_QMI_SYS_INFO_ALWAYS_UPDATE

/* 
  �ܸ� PS ONLY ������ ������ android�ܿ��� Reg state�� No Service�� ó���ϴ� ������ ���� 
  CS reject, PS accept �Ǵ� reject cause���迡���� ���� ���� �߻�.
*/
#define FEATURE_LGU_CP_GW_SUPPORT_PS_ONLY_MODE

/*
   MccMnc Table ���� ( SKT�� ����.. )
*/
#define FEATURE_LGU_CP_GW_PLMN_TABLE_LIST_SEARCH

/*
   ������ ���� ������ MCC/MNC �� update �Ǵ� �κ��� Limited service���¿����� update�� �����ϵ��� ������.
*/
#define FEATURE_LGU_CP_GW_GET_MCCMNC_UPDATE_IN_LIMITED_SRV

/*
   �ؿ� �ιֽ� (52501: Sing Tel) NITZ ������ �������� ������ OP NAME ������ NULL�� �ƴ����� length�� (0)�� ���쿡 �ش� ��.
   MCCMNC Table���� �ش� OP NAME�� �Ѹ��ٰ� MM INFO ���� ���� NAME�� �Ⱥ��̴� ���� ������.
*/
#define FEATURE_LGU_CP_GW_FIX_OPERATOR_NAME_DISPLAY

/*
    ������ �� ���� ���� property�� ������ network nameǥ�⸦ �߸��ϴ� ������ �߻��Ͽ� ����.
*/
#define FEATURE_LGU_CP_GW_INIT_NITZ_INFO_PROPERTY

/*
   invalid code input --> network no response --> ui pop-up remain forever....
*/
#define FEATURE_LGU_CP_GW_USSD_NEWORK_NO_RESPONSE

#define FEATURE_LGU_CP_GW_CENTRALIZED_EONS_NOT_SUPPORTED

#define FEATURE_LGU_CP_GW_MANUAL_SELECTION_BUG_FIX

/*************************************************/
/*                    LTE                        */
/*************************************************/
#ifdef FEATURE_LGU_COMMON_DEBUG_SCREEN
#define FEATURE_LGU_CP_LTE_DEBUG_SCREEN
#define FEATURE_LGU_CP_LTE_DB_QMI
#endif /* FEATURE_LGU_COMMON_DEBUG_SCREEN */

#define FEATURE_LGU_CP_LTE_PROCESS_REJECT
//#define FEATURE_LGU_CP_LTE_REJECT_DISPLAY_SIMULATION    //NOT USED.. 

#define FEATURE_LGU_CP_LTE_ANDSF_CELLID

#define FEATURE_LGU_CP_LTE_TEST_MODE_SETTING

/*************************************************/
/*                    UICC                       */
/*************************************************/
#define FEATURE_LGU_CP_UICC_CARD_CUSTOM_INFO
#define FEATURE_LGU_CP_UICC_CARD_TYPE
#define FEATURE_LGU_CP_UICC_CARD_MODE
#define FEATURE_LGU_CP_UICC_SUPPORT_FOR_ISIM_APPLICATION

#define FEATURE_LGU_CP_UICC_BIP_STATUS
#define FEATURE_LGU_CP_UICC_GET_ATR_QMI
#define FEATURE_LGU_CP_UICC_SUPPORT_NFC
#define FEATURE_LGU_CP_UICC_SUPPORT_AKA
#define FEAUTRE_LGU_CP_UICC_ERROR_FIX
#define FEATURE_LGU_CP_UICC_CHECK_ROAMING_SETTINGS
#define FEATURE_LGU_CP_UICC_STK_RESEND
#define FEATURE_LGU_CP_UICC_UI
#define FEATURE_LGU_CP_UICC_FIXED_QC_PROBLEM_FOR_CARD_STATUS
#define FEATURE_LGU_CP_UICC_CARD_STATUS_PINPUK_RETRY_CNT

/*************************************************/
/*                   LBS(GPS)                    */
/*************************************************/
//EF46L_GPS_PORTING_LINUX

//These are for both of modem and linux
#define FEATURE_LGU_CP_GPS_COMMON
#define FEATURE_LGU_CP_GPS_PREFERRED_TIME
#define FEATURE_LGU_CP_GPS_XTRA_DL
#define FEATURE_LGU_CP_GPS_XTRA_DL_TIME
#define FEATURE_LGU_CP_GPS_NMEA_WRITE

//These are for modem
#define FEATURE_LGU_CP_GPS_AAGPS
#define FEATURE_LGU_CP_GPS_PDSM_PD_END_TIMEOUT
#define FEATURE_LGU_CP_GPS_LOCATION_SERVICE
#define FEATURE_LGU_CP_GPS_NMEA

//These are for linux
#define FEATURE_LGU_CP_GPS_XTRA_T
#define FEATURE_LGU_CP_GPS_LOCATION
#define FEATURE_LGU_CP_GPS_WIPER
#define FEATURE_LGU_CP_GPS_GSIFF
#define FEATURE_LGU_CP_GPS_SD_CARD
#define FEATURE_LGU_CP_GPS_GPSON
#define FEATURE_LGU_CP_GPS_NMEA_CB
#define FEATURE_LGU_CP_GPS_NTP_TIME
#define FEATURE_LGU_CP_GPS_HIDDENMENU
#define FEATURE_LGU_CP_GPS_AGPS
#define FEATURE_LGU_CP_GPS_ULP
#define FEATURE_LGU_CP_GPS_TESTMENU
#define FEATURE_LGU_CP_GPS_FIX_FAIL

#endif /* __CUST_LGU_CP_LINUX_H */

