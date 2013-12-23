#ifndef __CUST_PANTECH_DS_H__
#define __CUST_PANTECH_DS_H__
/* ========================================================================
FILE: cust_pantech_ds.h

Copyright (c) 2011 by PANTECH Incorporated.  All Rights Reserved.

USE the format "FEATURE_LGT_DS_XXXX"
=========================================================================== */ 

/*===========================================================================

                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

  when        	who     what, where, why
--------   	---      ----------------------------------------------------------
11/09/30    sjm   	  initial
11/12/22    phi   	  move to EF46L from EF65L. 
11/12/30   Alice     delete some of feature not yet adapted.
12/01/13   Alice     change file name. : Cust_pantech_data_linux.h -> CUST_PANTECH_DS.h
12/09/27   Alice     re-arrange features for JB version.

===========================================================================*/

/*===========================================================================*/
  //4!!ATTENTION!!
/*===========================================================================*/
/*------------------------------------------------------------------------------------

  1. must record history in this file header when you modify this file.

  2. FEEATUR's name start with "FEATURE_LGT_DS_xxx".
  
  3. each FEATURE is need to detailed description. because this file is instad of Feature Specification.
        - Item, Comment(Date, Author), Reason, Modified Files, Added Files, Deleted Files.

  4. In Java Code, Feature' exprssion is comment.
        - Exmaple. // FEATURE_LGT_DS_COMMON

  5. this file must be included CUST_PANTECH.h
        
--------------------------------------------------------------------------------------*/

/*===========================================================================
    Data Service Features
===========================================================================*/

/* 20120105 Alice : Common import, include.. etc. */
#define FEATURE_LGT_DS_COMMON

#ifdef FEATURE_LGT_DS_COMMON

/* -----------------------------------------------------------------------------------*/
    //3 Android & QCT Bug Fix
/*-------------------------------------------------------------------------------------*/

/* Item : startusingnetworkfeature()
   Commnet - 20120109 Alice, 20130219 Alice
	Reason - return value check before reconnect() belong to  startUsingNetworkFeature().
	                 -> do not return Phone.APN_REQUEST_STARTED unconditional.
	          - do not set IDLE when already try to set up data call.
	          
	Modified files - ConnectivityService.java (frameworks\base\services\java\com\android\server),
	                     MobileDataStateTracker.java (frameworks\base\core\java\android\net)
*/
#define FEATURE_LGT_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/* Item : Settings >> Data Usage
 	Commnet - 20121129 Alice
  	Reason - set to Data Usage >> Set mobile data limit >> Restrict background data,
                UID/SYS_UID's setting is processed one by one as android's source architetecture.
                on the way setting if user request App., occur ANR(Application Not Responsding).
  	           - merge from EF49K
 	Modified files - NetworkPolicyManagerService.java(frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_SKY_DS_BACKGROUND_RESTRICT_BUG_FIX

/* Item : IPTABLEV6
 	Commnet - 20120224 phi
  	Reason - /system/bin/iptables's permission is set to system permission. 
  	             on the other hands ip6tables's permission is set to shell permission.
  	             and change ip6tables's permission to system permission.
  	          - merge from EF45K
 	Modified files - android_filesystem_config.h (system\core\include\private)
*/
#define FEATURE_SKY_DS_IP6TABLE_UID_BUG_FIX


/* Item : Exception
 	Commnet - 20120329 Alice
  	Reason - when be called NetworkManagementService, change to catch exception error.
  	             RemoteException -> Exception
  	          - for IPV6
  	          - derive problem in SystemServer.
  	          
 	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity)

 	Commnet - 20121217 Alice
  	Reason - silent reset
  	          
 	Modified files - NetworkPolicyManagerService.java (frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_LGT_DS_EXCEPTION_CATCH_BUG_FIX

/* Item : TCP Buffer
 	Commnet - 20121113 Alice
  	Reason - It doesn't exist TCP buffer size about EHRPD. 
  	             TCP Buffer size is choosen default size when connected to data in EHRPD.
  	             It's derived to change radio technology from EHRPD to LTE. because of keeping
  	             in Defualt TCP Buffer size.
  	          - modify to change TCP Buffer size

 	Modified files - MobileDataStateTracker.java (frameworks\base\core\java\android\net)
*/
#define FEATURE_SKY_DS_SET_TCPBUF_IN_RAT_CHANGE

/* Item : Data Connection
   Commnet - 20120726 kns
  	Reason - After anr or kill phone process, data connection isn't established.
  	          - From EF49K.
  Modified files - Qcril_data_netctrl.c(vendor\qcom\proprietary\qcril\common\data)
*/
#define FEATURE_SKY_DS_FOUND_DATA_CALL_AFTER_PHONE_PROCESS_RESTART

/* Item : UI
	Commnet - 20130225 Alice
	Reason - remove afterimage of popup window about Mobile data disabled
	Modified files - NetworkOverLimitActivity.java (frameworks\base\packages\SystemUI\src\com\android\systemui\net)
*/
#define FEATURE_LGT_DS_REMOVE_AFTERIMAGE

/*......................................................................................................................................
  Roaming
.........................................................................................................................................*/


/* -----------------------------------------------------------------------------------*/
    //3    LGU+ Requirement
/*-------------------------------------------------------------------------------------*/

/* Item : APN List
	Commnet - 20120927, Alice
	Reason - single apn for LGU+.
	Modified files - apns.xml(frameworks\base\core\res\res\xml)
*/
#define FEATURE_LGT_DS_LTE_SINGLE_APN

/* Item : LTE Auth Check
	Commnet - 20120403 Alice
	Reason - default authType is set to RILConstants.SETUP_DATA_AUTH_NONE.
	Modified files - DataProfile.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_AUTH_CHAP_PAP_CHECK

/* Item : DHCP
	Commnet - 20120227 Alice
	Reason - Since default DHCP Lease Time is 1 hour, 
	             VPN, RMNET and android Tethering are disconnected frequently. 
	             So, Increase the DHCP Lease Time to 7 days
	Modified files - TetherController.cpp (system\netd) 
*/
#define FEATURE_LGT_DS_INCREASE_DHCP_LEASETIME

/*Item : RestoreTimer
   Commnet - 20120618 Alice
   Reason - not used RestoreTimer : DUN, IMS
              - and HIPRI : Spec Out - but MQS Issue.
              - deleted FEATURE_LGT_DS_DISABLE_INACTIVITY_TIMER
              - concerned FEATURE_LGT_DS_LTE_MULTIPLE_APN

              - HIPRI : 5 min >> 10min
              
   Modified files - Config.xml(device\qcom\common\overlay\frameworks\base\core\res\res\values),
                        Config.xml(device\qcom\msm8960\overlay\frameworks\base\core\res\res\values)
*/
#define FEATURE_LGT_DS_DISABLE_RESTORE_TIMER

/* Item : TCP sync retries
	Commnet - 20120104 Alice
	Reason - change RTO and TCP_SYN_RETRIES when TCP syn transfer
	           - tcp resync nymber is 5.(first transfer, 1s, 2s, 4s, 8s)
	Modified files - tcp.h(kernel\include\net)
*/
#define FEATURE_LGT_DS_TCP_SYN_RETRANSMIT

/* Item : DNS
	Commnet - 20120111 Alice
	Reason - do not query DNS IPv6.
	Modified files - getaddrinfo.c(bionic\libc\netbsd\net)
*/
#define FEATURE_LGT_DS_IPV6_DNS_QUERY

/* Item : Emergency Call
	Commnet - 20120118 Alice
	Reason - keep connecting the Data Call after Emergency call end.
	Modified files - CdmaCallTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma)
*/
#define FEATURE_LGT_DS_NO_TEARDOWN_DATA_EMERGENCYCALL

/* EVDO/EHRPD Error */
#define FEATURE_LGT_DS_EVDO_ERROR

#ifdef FEATURE_LGT_DS_EVDO_ERROR

/* Item : EVDO/EHRPD Error
	Commnet - 20120113 Alice
	Reason - In AMSS side found out EVDO/EHRPD Error, 
	             write EVDO/EHRPD error cause to property_set(ril.cdma.errorcause) in QCRIL.
	Modified files - Dsc_qmi_wds.c (vendor\qcom\proprietary\data\dss\src),
                        Dsc_qmi_wds.h (vendor\qcom\proprietary\data\dss\src),
                        Qcril_data_netctrl.c (vendor\qcom\proprietary\qcril\common\data),
                        Qmi_wds_srvc.h (vendor\qcom\proprietary\qmi\inc)
*/
#define FEATURE_LGT_DS_EVDO_ERROR_REASON

/* Item : EVDO/EHRPD Error
	Commnet - 20120213 Alice
	Reason - after read EVDO/EHRPD Error casue in property(ril.cdma.errorcause) 
	             show the Pop-up Message or Toast and write Error cause to other property(ril.cdma.wipinetval).
	Modified files -  CdmaDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma),
                         DataConnection.java (frameworks\base\telephony\java\com\android\internal\telephony),
                         DataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony),	
                         GsmDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\gsm),
                         SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony),
                         Public.xml (frameworks\base\core\res\res\values),
	                     Strings_ds.xml (frameworks\base\core\res\res\values),
	                     Strings_ds.xml (frameworks\base\core\res\res\values-ko),
	                     Strings_ds.xml (frameworks\base\core\res\res\values-zh-rcn),
                        Strings_ds.xml (frameworks\base\core\res\res\values-zh-rtw)
*/
#define FEATURE_LGT_DS_EVDO_ERROR_MESSAGE
#endif /* FEATURE_LGT_DS_EVDO_ERROR */

/* Item : Connectivity
 	Commnet - 20120215 Alice
  	Reason - 1. only try to connect Data call when EVDO_REV_0/EVDO_REV_A 
  	                -> 1x Data call isn't possible.
  	             2. do not try to connect Data call IPV6 in LTE/EHRPD system.
  	                -> but possible aborad.

 	Modified files - CdmaDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma),
                        GsmDataConnection.java (frameworks\base\telephony\java\com\android\internal\telephony\gsm),
                        GsmDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\gsm),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)

   Commnet - 20120730 sjm, 20121108 Alice, 20121211 Alice
   Reason - Check Data onoff in startUsingNetworkFeature()
              - replaced of FEATURE_LGT_DS_WPS_CHECK_DATA_ONOFF in EF50L ICS.
              - for CTS : android.net.cts.ConnectivityManagerTest
 
   Modified files - ConnectivityService.java (frameworks\base\services\java\com\android\server),
                        ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_RESTRICT_DATA_CALL

/* Item :Tether
	Commnet - 20121205 Alice
	Reason - define tether upstream.
	
	Modified files - Config.xml(device\qcom\common\overlay\frameworks\base\core\res\res\values),
                        Config.xml(device\qcom\msm8960\overlay\frameworks\base\core\res\res\values)
*/
#define FEATURE_LGT_DS_TETHER_UPSTREAM_TYPE

/*......................................................................................................................................
  EasySetting, Data On/Off
.........................................................................................................................................*/

/* Item : Data On/off Property
	Commnet - 20121022 Alice
	Reason - Manage LGU+'s customized Data on/off property
	Modified files - DatabaseHelper.java (frameworks\base\packages\settingsprovider\src\com\android\providers\settings),
                        Settings.java (frameworks\base\core\java\android\provider),
                        ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_GET_SECUREDB_FOR_LGT

/* Item : EasySetting
 	Commnet - 20120509 Alice
 	Reason - match setting value between EasySetting ans Setting
 	
 	Modified files - ConnectivityManager.java (frameworks\base\core\java\android\net),
                        ConnectivityService.java (frameworks\base\services\java\com\android\server),
                        IConnectivityManager.aidl (frameworks\base\core\java\android\net),
                        ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_EASY_SETTING

/* Item : Booting Pop-up
 	Commnet - 20120516 Alice, 20121214 Alice, 20130122 Alice
 	Reason - display data connection pop-up for user's choice when booting
 	          - to display only once. even silent reset
 	          - added theme(AlertDialog.THEME_DEVICE_DEFAULT_LIGHT)
 	          - added condition when return to domestic 
 	             concerned to AutoRadReceiver.java(packages\apps\Phone\src\com\android\phone)
 	
 	Modified files - CDMAPhone.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma),
 	                     DatabaseHelper.java (frameworks\base\packages\settingsprovider\src\com\android\providers\settings),
                        DataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
                        Public.xml (frameworks\base\core\res\res\values),
                        Settings.java (frameworks\base\core\java\android\provider),
                        SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        System.prop(device\qcom\msm8960)

	Added files - Strings_ds.xml(frameworks\base\core\res\res\values),
	                  Strings_ds.xml(frameworks\base\core\res\res\values-ko),
                     Strings_ds.xml (frameworks\base\core\res\res\values-zh-rcn),
                     Strings_ds.xml (frameworks\base\core\res\res\values-zh-rtw)
*/
#define FEATURE_LGT_DS_BOOTING_POPUP

/* Item : Toast
 	Commnet - 20120517 Alice
 	Reason - Show Data Connection and Disconnection.
 	
 	Modified files - DataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        Intent.java (frameworks\base\core\java\android\content),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_TOAST

/*......................................................................................................................................
  QMI
.........................................................................................................................................*/

/* Item : QMI
	Commnet - 20120426 Alice
	Reason - Added for communication between Modem and Linux
	          - Just only use for Data Service.
	          - must be adpated to pair with Linux.
	          
	Modified files - Android.mk (android\frameworks\base)

	Added files - LINUX\android\pantech\frameworks\qmi_data

   Commnet - 20120503 Alice
   Reason - not only IDL QMI but also Legacy QMI
             -  use Legacy QMI, must block the compile option flags.
                (LOCAL_CFLAGS += -DQCCI_OVER_QMUX )
             - added permission for failure socket
             
   Modified files - Android.mk (vendor\qcom\proprietary\qmi-framework\qcci\src),
                        ipc_socket.c(kernel\arch\arm\mach-msm)
*/
#define FEATURE_LGT_DS_QMI

#ifdef FEATURE_LGT_DS_QMI
/* Item : Connectivity(Dormancy)
	Commnet - 20120426 Alice
	Reason - when screen off, change CTA Timer to 3 sec.
	Modified files - SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
					 
	Added files - Qmi_data_def.h (pantech\frameworks\qmi_data\qmi),
                    QmiDataClnt.java(pantech\frameworks\qmi_data\java),
                    QmiDataClnt.cpp (pantech\frameworks\qmi_data\jni),
                    Qmi_data_clnt.c (pantech\frameworks\qmi_data\qmi)
*/
#define FEATURE_LGT_DS_FAST_DORMANCY
#endif /* FEATURE_LGT_DS_QMI */

/*......................................................................................................................................
  Hidden Menu : Enginerring, Debug screen, etc.
.........................................................................................................................................*/

/* Item : Eng Menu
 	Commnet - 20121030 Alice
  	Reason - added Engineering Menu for Data service function
 	Modified files - LgtSkyEngMenu.java (pantech\apps\hiddenmenu\src\com\android\hiddenmenu)
*/
#define FEATURE_LGT_DS_ENG_MENU

#ifdef FEATURE_LGT_DS_ENG_MENU
/* Item : Alwayson Setting
 	Commnet - 20120128 Alice
  	Reason - added AlwasyOn/Off API
 	Modified files - LgtSkyEngMenu.java (pantech\apps\hiddenmenu\src\com\android\hiddenmenu)
*/
#define FEATURE_LGT_DS_ENG_3G_MENU

#ifdef FEATURE_LGT_DS_QMI
/* Item : Dun Setting
   Comment - 20121217 Alice
   Reason - To set dun value in NV for LGT lab test.

   Modified files - LgtSkyEngMenu.java (pantech\apps\hiddenmenu\src\com\android\hiddenmenu),
                        QmiDataClnt.cpp (pantech\frameworks\qmi_data\jni),
                        QmiDataClnt.java(pantech\frameworks\qmi_data\java),
                        Qmi_data_clnt.c (pantech\frameworks\qmi_data\qmi),
                        Qmi_data_def.h (pantech\frameworks\qmi_data\qmi)                        
*/
#define FEATURE_LGT_DS_ENG_DUN_MENU
#endif /* FEATURE_LGT_DS_QMI */
#endif /* FEATURE_LGT_DS_ENG_MENU */

/*......................................................................................................................................
  Roaming
.........................................................................................................................................*/
/* Item : Roaming Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - Show roaming data connection dialog box when we are in roaming area
 	Modified files - DataConnectionTracker.java, GsmDataConnectionTracker.java, ISkyDataConnection.aidl, SkyDataConInterfaceManager.java
 	               - Strings_ds.xml (linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values\)
 	               - Strings_ds.xml (linux\android\vendor\pantech\overlay\frameworks\base\core\res\res\values-ko\)
*/
#define FEATURE_LGT_DS_ROAMING_DATA_MENU_POPUP

/* Item : Roaming Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - Check whether PS domain attachment is rejected or not when we are in roaming area
 	Modified files - DataConnectionTracker.java, GsmDataConnectionTracker.java
*/
#define FEATURE_LGT_DS_PS_REJECT

/* Item : Roaming Data Connection
 	Commnet - 20120315 Yoonjunho
  	Reason - Disable data connection menu in easy setting when we are in roaming area
 	Modified files - GsmDataConnectionTracker.java, GsmServiceStateTracker.java
*/
#define FEATURE_LGT_DS_ALWAYSON_MENU_DISABLED_IN_ROAMING

/* Item : Roaming Data Connection
 	Commnet - 20120510 Yoonjunho
  	Reason - Change default APN with "wroaming.lguplus.co.kr" when we are in roaming area
 	Modified files - GsmDataConnectionTracker.java, Qcril_data_netctrl.c
*/
#define FEATURE_LGT_DS_ROAMING_APN_CHANGE
/* Item : Roaming Data Connection
 	Commnet - 20130320 ParkMinOh
  	Reason - MOBILE_DATA and DATA_ROAMING have different usage with Original, So make seperate usage 
 	Modified files - GsmDataConnectionTracker.java
*/
#define FEATURE_LGT_DS_DIFFERENT_DARA_ROAMING



/* -----------------------------------------------------------------------------------*/
    //3 Issue Follow up
/*-------------------------------------------------------------------------------------*/

/* Item : DCT
	Commnet - 20120831 Alice
	Reason - Added additional DCT for Pantech features.

	Modified files - CdmaDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma),
                        DataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        GsmDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\gsm),
				           
	Added files - SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADDITIONAL_DCT

/* Item : Data Connection Interface, AIDL
	Commnet - 20120831 Alice
	Reason - Added DCT interface for other service.

	Modified files - Android.mk(frameworks\base), 
			              service_manager.c(frameworks\base\cmds\servicemanager),
				           DataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
				           
	Added files - ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
			            SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADD_DATA_AIDL

/* Item : CNE
 	Commnet - 20121008 Alice
 	Reason - CNE disable : Connectivity Engine
   Modified files - System.prop(device\qcom\msm8960)
*/
#define FEATURE_LGT_DS_DISABLE_CNE
 
/* Item : Max windowsize/memsize for LTE
 	Commnet - 20120202 Alice
 	Reason - change max windowsize/memsize for LTE
 	          -  FEATURE_SKY_DS_SET_TCPBUF_IN_RAT_CHANGE
 	Modified files - init_EF46L.rc(system\core\rootdir)
*/
#define FEATURE_LGT_DS_TCP_BUFFER_FOR_LTE

/* Item : MTU
 	Commnet - 20121008 Alice
 	Reason - change MTU size for LTE
 		       - deleted usb0 interface set MTU size and change TCP MSS for tethering by NAT

 	Modified files - msm8960_ef46l_xxxx_defconfig(kernel\arch\arm\configs)
                       msm8960_ef46l_xxxx_perf_defconfig(kernel\arch\arm\configs)
 				           NatController.cpp(system\netd)
*/
#define FEATURE_LGT_DS_USB_KERNEL_MTU_SETTING

/* Item : MTU
 	Commnet - 20130318 jsmin
 	Reason -  add&delete in the mangle table (at the Tethring on->off )  
 	Modified files - NatController.cpp(system\netd)
*/

#define FEATURE_LGT_DS_USB_KERNEL_MTU_SETTING_NOT_DELETE_MANGLE
/* Item : Data Connection
 	Commnet - 20120111 Alice
 	Reason - do query failure cause when occur failure in DC.
 	Modified files - DataConnection.java(frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_FAIL_CAUSE

/* Item : Data Connection
 	Commnet - 20120111 Alice
 	Modified files - DataConnection.java(frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_PS_FAIL_CAUSE_FATAL_EXCEPTION

/* Item : VPN
 	Commnet - 20120117 Alice, 20120217 Alice, 20120509 kns
 	Reason - 1. VPN BUG FIX :  just function execution's order change.
	              -> L2tp.c 	
 	             2. added a few compile option
 	             3. adapted to new file (msm8960_ef50l_xxxx_defconfig)
                4. fix build error as PPP enable

 	             5. VPN Editing -> Null check
 	                - replace of FEATURE_LGT_DS_VPN_SPACE_CHECK
 	                
 	Modified files  L2tp.c(LINUX\android\external\mtpd),
                      msm8960_ef46l_xxxx_defconfig(kernel\arch\arm\configs),
                      msm8960_ef46l_xxxx_perf_defconfig(kernel\arch\arm\configs),
                      ppp_defs.h(kernel\include\linux),
                      VpnDialog.java (packages\apps\settings\src\com\android\settings\vpn2)
*/
#define FEATURE_LGT_DS_VPN_FIX

/* Item : Tethering 
	Commnet - 20120404 Alice
	Reason - enable DIAG port when usb tethering.
	          - merge from STARQ	
	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity),
	                     UsbManager.java (frameworks\base\core\java\android\hardware\usb)

	Instead of ##872# >> Diag Endable Control
*/
#undef FEATURE_LGT_DS_ADD_DIAG_PORT_WHEN_TETHERING

/* Item : NetworkInfo
 	Commnet - 20120417 Alice
  	Reason - NetworkInfo isAvailable is false when APN State is failed
  	          - merge From STARQ, FEATURE_P_VZW_DS_APN_FAILED_STATE_BUG
 	Modified files -  CdmaDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma),
 	                     GsmDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony\gsm),
*/
#define FEATURE_LGT_DS_APN_FAILED_STATE_BUG

/* Item : Route
 	Commnet - 20121109 Alice
  	Reason - Reconnect when routing add failed.
  	          - If occured failure to add Route, do tear down and try to reconnect after 3 sec.
  	          - merge From STARQ, FEATURE_P_VZW_DS_ROUTE_ADD_FAIL
  	          
 	Modified files - ConnectivityService.java (frameworks\base\services\java\com\android\server),
 	                     MobileDataStateTracker.java (frameworks\base\core\java\android\net),
                        NetworkStateTracker.java (frameworks\base\core\java\android\net)
*/
#define FEATURE_LGT_DS_ROUTE_ADD_FAILURE

/* Item : Tethering
 	Commnet - 20120418 Alice
  	Reason - at the same time USB tethering and WiFi Hotstop, DATA off -> DATA on -> WiFi on
  	             display both WiFi icon and DATA icon for a few seconds. maybe the longest 60 sec.
  	           - after startUsingNetworkFeature, don't call stopUsingNetworkFeature
  	              now, when IMS de-registration, call stopUsingNetworkFeature.
  	           - If IMS doesn't call stopUsingNetworkFeature, do stopUsingNetworkFeature.
 	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity)
*/
#define FEATURE_LGT_DS_DISPLAY_WIFI_DATA_ICON_WHEN_TETHERING

/* Item : Tethering
 	Commnet - 20120723 sjm
  	Reason - Tethering DNS Forward Error Fix from SKT
 	Modified files - Tethering.java (frameworks\base\services\java\com\android\server\connectivity)
*/
#define FEATURE_LGT_DS_TETHERING_DNS_FORWARD

/* Item : APN Changed
 	Commnet - 20120727 sjm, 20121023 Alice
  	Reason - Ignore APN Changed event due to setRoaminAPN()

 	Modified files - GsmDataConnectionTracker.java (rameworks\base\telephony\java\com\android\internal\telephony\gsm),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define  FEATURE_LGT_DS_IGNORE_APN_CHANGED

/*
 - 20120816 sjm
 - immediatly send Connection_action intent 
 */
 #define FEATURE_LGT_DS_CONNECTIVTY_INTENT_IMMEDIATE

/* Item : Route
 	Commnet - 20120905 sjm, 20121212 Alice
  	Reason - SilentReset when modify route
 - Add try/catch and syncronized

 	Modified files - ConnectivityService.java (frameworks\base\services\java\com\android\server),
 	                     AbstractCollection.java (libcore\luni\src\main\java\java\util)
 */
 #define FATURE_LGT_DS_CONCURRENTMODIFICATIONEXCEPTION

 /*
 - 20120912 sjm
 - APN State Bug WorkAround Code
 */
#define FEATURE_LGT_DS_APN_STATE_FIX

#ifdef FEATURE_SKY_DS_BACKGROUND_RESTRICT_BUG_FIX
/* Item : Mutex
   Commnet - 20121129 Alice
   Reason - Change mutex time to 300ms for fixing ANR

   Modified files - NetworkPolicyManagerService.java(frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_LGT_DS_RELEASE_MUTEX_TIME
#endif /* FEATURE_SKY_DS_BACKGROUND_RESTRICT_BUG_FIX */

/* Item : RadioTech
  Commnet - 2012.05.25 sjm 
  Reason - When MDM connected on eHRPD, radiotech of framework is EVDO-Rev.A. 
               Then Qcril make data connection to disconnect due to mismatch radiotech.
  Modified files - Qmi_wds_srvc.c (vendor\qcom\proprietary\qmi\src)
*/
#define FEATURE_LGT_DS_EHRPD_RADIO_TECH

/* Item : Route
 	Commnet - 20121113 Alice
  	Reason - added method to suspend data call. 

 	Modified files - ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_ADD_DATA_SUSPEND_FUNC

/* Item : Toast
	Commnet - 20121128 Alice
	Reason - show toast msg when try to fail over mobile
	          - except for airplane moe on
	Modified files - SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_DATA_CONNECTION_TOAST

/* Item : Retry count
	Commnet - 20121204 Alice
	Reason - prevent to reset retry counter 
	             according to occur EVENT_TETHERED_MODE_STATE_CHANGED
	             when fail data connection
	          - LGU+ MultiMode TEST : 16.16. PDN connectivity reject #27 (internet PDN)
	          - retry interval : 5s, 10s, 20s. and repeat after 30 min.
	             
	Modified files - DataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_DO_NOT_RESET_RETRY_COUNT

/* Item : iptables
	Commnet - 20121126 Alice
	Reason - show data usage menu.
	          - enable iptables's option about raw table.
	
	Modified files - msm8960_ef46l_xxxx_defconfig(kernel\arch\arm\configs)
*/
#define FEATURE_LGT_DS_SHOW_DATA_USAGE

/* Item : Data Call
	Commnet - 20130123 Alice
	Reason - failure data call after erased EFS.
	          - merge from EF51L
	          
	Modified files - Qcril_data_netctrl.c (vendor\qcom\proprietary\qcril\common\data)
*/
#define FEATURE_LGT_DS_DATA_CONNECT_BUG_FIX_AFTER_ERASING_EFS

/* Item : Throughput
	Commnet - 20130123 Alice
	Reason - Increase TCP Advanced Window Scale
	          - /proc/sys/net/ipv4/tcp_adv_win_scale 1 -> 2 
	          
	Modified files - tcp_input.c  (kernel\net\ipv4)
*/
//20130130 Alice #define FEATURE_LGT_DS_TCP_WIN_SCALE

/* Item : OMH
	Commnet - 20130219 Alice
	Reason - do not read unnecessary profile.

	Modified files - System.prop(device\qcom\msm8960)
*/
#define FEATURE_LGT_DS_OMH_DISABLED

/*......................................................................................................................................
  DNS
.........................................................................................................................................*/

/* Item : DNS
 	Commnet - 20120105 Alice
 	Reason - check null DNS.
              - not only NULL_IP(0.0.0.0) but also length 0
 	          
 	Modified files - CdmaDataConnection.java (frameworks\base\telephony\java\com\android\internal\telephony\cdma),
                        GsmDataConnection.java (frameworks\base\telephony\java\com\android\internal\telephony\gsm)
*/
#define FEATURE_LGT_DS_PS_NULL_DNS_CHECK

/* Item : DNS
 	Commnet - 20120113 Alice
 	Reason - MMS App. is checked the test DNS as soon as possible to disconnect Data call.
 	             and then MMS App try to send MMS, Inetaddress.getbyname occur unknown host exception.
 	             
 	Modified files - getaddrinfo.c(bionic\libc\netbsd\net)
*/
#define FEATURE_LGT_DS_DISABLE_TEST_DNS

/* Item : DNS
 	Commnet - 20120113 Alice
 	Reason - do not add route KT's(168.126.63.1/168.126.63.2) for VT(startusingnetworkfeature(), TYPE_DUN).
 	
 	Modified files - ConnectivityService.java (frameworks\base\services\java\com\android\server)
*/
#define FEATURE_LGU_DS_3G_DNS_REMOVE_IN_ROUTETABLE

/*......................................................................................................................................
  For App.
.........................................................................................................................................*/
  
/* Item : RADIO
  Commnet - 20120113 Alice
   Reason - RADIO Tech°¡ Data Connection state, qcril?????????????? ??? ??? °æ??.
*/
#define FEATURE_LGU_DS_UNKNOWN_RADIO
  
#ifdef FEATURE_LGU_DS_UNKNOWN_RADIO  
/* Item : RADIO
  Commnet - 20120113 Alice
  Reason - App. is not working When enter Out Of Servcie(OOS)
               Although App. already had receivced patcket.
            - the reason why NetworkInfo.available is false.

  Modified files - MobileDataStateTracker.java (frameworks\base\core\java\android\net),
                      NetworkController.java (frameworks\base\packages\systemui\src\com\android\systemui\statusbar\policy)  
*/
#define FEATURE_LGT_DS_AVOID_OOS_FOR_APP
  
  /* Item : RADIO
    Commnet - 20120320 Alice
    Reason - set to false "TelephonyProperties.PROPERTY_OOS_IS_DISCONNECT".
               - if mOosIsDisconnect == true, changed data connection to disconnection as soon as entering no-service.
               - cause confusion in App. layer.
 	Modified files - System.prop(device\qcom\msm8960)
  */
#define FEATURE_LGT_DS_OOS_PROPERTY_INITIAL_VAL
  
#endif /* FEATURE_LGU_DS_UNKNOWN_RADIO */


/* Item : MMS
 	Commnet - 20120217 Alice
  	Reason - MMS App. Request.
            - added "isAvailableForMms" return to connection state of mobile_mms before "startUsingNetworkFeature" 
            - return true :: AlwaysOnSetting true, AuthFail false, DC.FailCause not permanantfail, In service.

            - added getServiceState:: for No service.
            - as 1x Data Disable return false when RadioTech is 1x
            
    Modified files - ISkyDataConnection.aidl (frameworks\base\telephony\java\com\android\internal\telephony),
                        MobileDataStateTracker.java (frameworks\base\core\java\android\net),
                        SkyDataConInterfaceManager.java (frameworks\base\telephony\java\com\android\internal\telephony),
                        SkyDataConnectionTracker.java (frameworks\base\telephony\java\com\android\internal\telephony)
*/
#define FEATURE_LGT_DS_CHECK_NETWORK_AVAILABLE_FOR_MMS

/*......................................................................................................................................
  CTS
.........................................................................................................................................*/

/* Item : UID_STAT CONFIG
    Commnet - 20121205 Alice
    Reason - enable UID_STAT=y for TrafficStats(CTS TEST Fail)
    Modified files - msm8960_ef46l_xxxx_defconfig(kernel\arch\arm\configs),
                        msm8960_ef46l_xxxx_perf_defconfig(kernel\arch\arm\configs)
*/
#define FEATURE_LGT_DS_UID_TRAFFIC_STATS_ENABLE

/*......................................................................................................................................
  Network Tools
.........................................................................................................................................*/

/* Item : BUSYBOX 
	Commnet - 20120509 Alice
	Reason - busybox install for root(eng) version 1.19.0

   Added files - busybox folder all (vendor\pantech\development\busybox)
*/
#define FEATURE_LGT_DS_BUSYBOX_INSTALL

/* Item : IPERF 
	Commnet - 20120509 Alice
	Reason - iperf install for root, version : 2.0.5 (08 Jul 2010)

   Added files - iperf folder all (vendor\pantech\development\iperf)
*/
#define FEATURE_LGT_DS_IPERF_INSTALL

/*......................................................................................................................................
  Roaming
.........................................................................................................................................*/

/* Item : Data Connection
 	Commnet - 20120406 Yoonjunho
  	Reason - ISkyDataConnection??3rd parth app???? ????????????????? ?????????????????? API ??????
 	Modified files - SkyDataConInterfaceManager.java, ISkyDataConnection.aidl, DataConnectionTracker.java
*/ 
#define FEATURE_LGT_DS_NET_OVERLIMIT_API


#endif /* FEATURE_LGT_DS_COMMON */

/*===========================================================================
    Others
===========================================================================*/

/* Item : Log change (Radio -> Main)
    Commnet - 20120915 Alice
    Reason - change buffer to print Data Framework log, RADIO BUFFER -> MAIN BUFFER.
                 for Data Call State. 
    Modified files - GsmDataConnectionTracker.java, CdmaDataConnectionTracker.java,
                         logd_write.c(android\system\core\liblog\logd_write.c),
                         MobileDataStateTracker.java (frameworks\base\core\java\android\net),
                         Tethering.java (frameworks\base\services\java\com\android\server\connectivity),
                         NetworkPolicyManagerService.java(frameworks\base\services\java\com\android\server\net)
*/
#define FEATURE_LGT_DS_CHANGE_RADIO_LOG

#endif/* __CUST_PANTECH_DS_H__ */


