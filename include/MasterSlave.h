#pragma once

#define MAXCLIENT				8
#define	MAXGROUP				8	// Beagle 20111108
#define MAX_DFRECT				4
#define DEFECT_IMGRECT_W		224 //eric chao 20130626 change Defect View Size
#define DEFECT_IMGRECT_H		256
#define WEAKEN_LEARN_SIZE		14
#define MAX_BARCODE_DIGITS		23	// Beagle 20120302 added. 20 data digits, 2 check digits, 1 blank digit.
#define MAX_IMAGES_PER_SHEET	64	// Beagle 20120706 added.
#define MAX_QRCODE_RESULT		250  // eric chao 20130418
#define MAX_DECODE_BUF_SIZE		1024 //eric chao 20141003
#define MAXSAMPLE				8

#ifdef _WIN64
#define NDK_BUFFER_SIZE_BIG		(800*1024*1024)			// 800MB
#define NDK_BUFFER_SIZE_MID		(120*1024*1024)			// 120MB
#else
//#define NDK_BUFFER_SIZE_BIG		(100*1024*1024)			// 100MB
//#define NDK_BUFFER_SIZE_MID		(20*1024*1024)			// 20MB
#define NDK_BUFFER_SIZE_BIG		(120*1024*1024)			// 120MB //eric chao 20130125
#define NDK_BUFFER_SIZE_MID		(40*1024*1024)			// 40MB //eric chao 20130125
#endif
#define NDK_BUFFER_SIZE_INSP	(10*1024*1024)			// 10MB //eric chao 20170701
#define NDK_BUFFER_SIZE_INFO	(1024*1024)				// 1MB
#define	NDK_BUFFER_SIZE_SMALL	(64*1024)				// 64K

#define NDK_MAX_PACKSIZE		(40*1024*1024)			// 40MB

#define ServerListenPort	35020
#define AoiCaptureServerListenPort	3232

#define USE_QUICKLZ	// added by danny at 20110317

#ifdef _DEBUG
	#define ServerIPAddress		_T("127.0.0.1")
//	#define ServerIPAddress		_T("0.0.0.0")		// Auto detect subnet.
#else
	#define ServerIPAddress		_T("0.0.0.0")		// Auto detect subnet. -- Beagle 20120503 modified.
#endif

#define WM_SELF_MSG				(WM_APP+200)
#define WM_RX_SOCKET_MSG_UITH	(WM_APP+298)		// added by seanchen  20130826-1
#define WM_REQ_SOCKET_MSG		(WM_APP+299)		// added by seanchen  20130710
#define WM_SOCKET_MSG			(WM_APP+300)

#define NDK_C1_ERROR_MSG		(WM_APP+301)		// message to tell that server socket got a error with client 1
#define NDK_C2_ERROR_MSG		(WM_APP+302)		// message to tell that server socket got a error with client 2
#define NDK_C3_ERROR_MSG		(WM_APP+303)		// message to tell that server socket got a error with client 3
#define NDK_C4_ERROR_MSG		(WM_APP+304)		// message to tell that server socket got a error with client 4
#define NDK_C5_ERROR_MSG		(WM_APP+305)		// message to tell that server socket got a error with client 5
#define NDK_C6_ERROR_MSG		(WM_APP+306)		// message to tell that server socket got a error with client 6
#define NDK_C7_ERROR_MSG		(WM_APP+307)		// message to tell that server socket got a error with client 7
#define NDK_C8_ERROR_MSG		(WM_APP+308)		// message to tell that server socket got a error with client 8

#define NDK_CLIENT_CONNECT_MSG	(WM_APP+309)		// message to tell that one client machine has connected to server 
#define NDK_SERVER_CONNECT_MSG	(WM_APP+310)		// message to tell that this client machine has connected to server 
#define NDK_CLIENTERROR_MSG		(WM_APP+311)		// message to tell that client socket got a error

#define NDK_UPDATE_ENCODERDIST	(WM_APP+312)
#define NDK_UPDATE_SOLENOIDRT	(WM_APP+313)
//#define NDK_UPDATE_PIXELDIST	(WM_APP+314)		//eric chao 20161220 remove
#define NDK_SETKEEPDAY_MSG		(WM_APP+315)
#define NDK_AUTOKEEPDAY_MSG		(WM_APP+316)
#define NDK_SETLOGINUSER		(WM_APP+317)

#define NDK_ACT_NEWPROJECT		(WM_APP+318)
#define NDK_ACT_DELPROJECT		(WM_APP+319)
#define NDK_ACT_CHPRJNAME		(WM_APP+320)
#define NDK_ACT_CHPRJSETTING1	(WM_APP+321)
#define NDK_ACT_CHPRJSETTING2	(WM_APP+322)
#define NDK_ACT_NEWPRODUCTION	(WM_APP+323)
#define NDK_ACT_LOADPROJECT		(WM_APP+324)

#define NDK_CLIENT_SETPRJINFO	(WM_APP+325)
#define NDK_CHANGE_ACTIVEPAGE	(WM_APP+326)
#define NDK_ENTER_SETGOLDEN		(WM_APP+327)

#define NDK_SETANCHOOR_MSG		(WM_APP+328)
#define NDK_ADDSEGMENT_MSG		(WM_APP+329)
#define NDK_DELSEGMENT_MSG		(WM_APP+330)
#define NDK_MODSEGMENT_MSG		(WM_APP+331)
#define NDK_DIFFSEGMENT_KEY		(WM_APP+332)
#define NDK_MGESEGMENT_MSG		(WM_APP+333)
#define NDK_MOVSEGMENT_MSG		(WM_APP+334)
#define NDK_MODINSPRGN_MSG		(WM_APP+335)

#define NDK_SET_DARKPNT			(WM_APP+336)
#define NDK_SET_COLORDIFFCHECK	(WM_APP+337)
#define NDK_SET_COLORDELTA		(WM_APP+338)
//#define NDK_SET_PAPERSHRINK		(WM_APP+339)    no use
//#define NDK_SET_INKCHECK1		(WM_APP+340)		no use
//#define NDK_SET_INKCHECK2		(WM_APP+341)		no use
//#define NDK_SET_INKPERCENTAGE	(WM_APP+342)		no use

//#define NDK_UNLOCK_WAITING		(WM_APP+343)	no use
//#define NDK_GETBACK_INSPRGN		(WM_APP+344)	no use

#define NDK_START_SAMPLING		(WM_APP+345)
#define NDK_STOP_SAMPLING		(WM_APP+346)
#define NDK_GET_SAMPLEIMG		(WM_APP+347)
#define NDK_CHECK_IDXSAMPLE		(WM_APP+348)
#define NDK_GET_SAMPLEINFO		(WM_APP+349) //eric chao 20131230
#define NDK_ACT_SETGOLDEN		(WM_APP+350)

#define NDK_START_INSPECTION	(WM_APP+351)
#define NDK_STOP_INSPECTION		(WM_APP+352)
#define NDK_SET_INSPRESULT		(WM_APP+353)
#define NDK_ASK_INSPIMAGE		(WM_APP+354)
#define NDK_SET_INSPIMAGE		(WM_APP+355)

#define NDK_HASULTRASONIC_MSG	(WM_APP+356)
//#define NDK_HASTRIGGER2_MSG		(WM_APP+357)
//#define NDK_TG2DISTANCE_MSG		(WM_APP+358)

//#define NDK_DEL_DLGROUP			(WM_APP+359) //eric chao 20160222 remove
#define NDK_INSP_SAMPLES		(WM_APP+360)
//#define NDK_ADD_DLGROUP_BYSAMPLE	(WM_APP+361) //eric chao 20160222 remove
//#define NDK_DIFFDLGROUP_KEY		(WM_APP+362) //eric chao 20160222 remove
//#define NDK_UPDATE_DLSIZE		(WM_APP+363) //eric chao 20160222 remove

#define NDK_ASK_PRJ_PRODUCTION	(WM_APP+364)
#define NDK_ASK_DIMG_DETAIL		(WM_APP+365)

#define NDK_ADD_USER			(WM_APP+366)
#define NDK_MOD_USER			(WM_APP+367)
#define NDK_DEL_USER			(WM_APP+368)

//#define NDK_ADD_DLGROUP_BYINSPIMG	(WM_APP+369) //eric chao 20160222 remove
#define NDK_ASK_INSPDETAIL			(WM_APP+370)
#define NDK_CLI_INSPDETAIL			(WM_APP+371)

#define NDK_UPDATE_SEGMENT		(WM_APP+372)

#define NDK_LEVEL1_CHANGE		(WM_APP+373)
#define NDK_LEVEL2_CHANGE		(WM_APP+374)
#define NDK_LEVEL3_CHANGE		(WM_APP+375)

#define NDK_LEAVE_SETGOLDEN		(WM_APP+376)
//#define NDK_SET_SPEED			(WM_APP+377)  //eric chao 20171222 Remove
#define NDK_SHUTDOWN			(WM_APP+378)

#define NDK_ADD_LIGHTLEVEL		(WM_APP+379)
#define NDK_DES_LIGHTLEVEL		(WM_APP+380)

#define NDK_CLIENT_ERRMSG		(WM_APP+381)

#define NDK_SET_SAVEALLIMG		(WM_APP+382)

#define NDK_GET_WEAKENIMG		(WM_APP+383)		// added by danny at 20110302
#define NDK_START_WEAKLEARN		(WM_APP+384)		// added by danny at 20110302
#define NDK_SET_WEAKENMAP		(WM_APP+385)		// added by danny at 20110302
#define NDK_MOD_WEAKENMAXMAP	(WM_APP+386)		// added by danny at 20110302
#define NDK_MOD_WEAKENMINMAP	(WM_APP+387)		// added by danny at 20110302
#define NDK_ADD_WEAKEN_BYINSPIMG		(WM_APP+388)		// added by danny at 20110302
#define NDK_START_SINGLE_WEAKENLEARN	(WM_APP+389)
#define NDK_UNDOMOD_MAXMINMAP	(WM_APP+390)
#define NDK_MOD_MAXMAP_NOSAVE	(WM_APP+391)
#define NDK_MOD_MINMAP_NOSAVE	(WM_APP+392)
#define NDK_RELOAD_MAXMINMAP	(WM_APP+393)
#define NDK_SET_PRODUCTION		(WM_APP+394)
#define	NDK_CLIENT_SET_SYSTEMINFO		(WM_APP+395)		// Beagle 20110711
#define NDK_SET_IOVERSION		(WM_APP+396)		// Beagle 20110715
#define NDK_CLIENT_BLANKTOOCLOSE	(WM_APP+397)	// added by eric at 20110718
#define NDK_UNLOAD_PROJECT		(WM_APP+398)		// Beagle 20110719
#define NDK_GET_FULLSAMPLEIMAGE	(WM_APP+399)		// Beagle 20110728
#define NDK_SET_FULLSAMPLEIMAGE	(WM_APP+400)		// Beagle 20110728
#define NDK_REMOVESEGMENT_MSG	(WM_APP+401)	// added by eric at 20110802
#define NDK_ACT_PRODUCTIONREPORT	(WM_APP+402)	// added by eric at 20110822
#define NDK_CHANGELANGUAGE_MSG	(WM_APP+403)	// added by eric at 20110825
#define NDK_LOADPRJ_ERRMSG		(WM_APP+404)	// added by eric at 20110914
#define NDK_MOD_MAXMAP	(WM_APP+405)		// added by eric at 20110929
#define NDK_MOD_MINMAP	(WM_APP+406)		// added by eric at 20110929
#define NDK_SET_DEFECTFOLDER_MSG (WM_APP+407)		// added by eric at 20110930
#define NDK_SET_BARCODEVALS_MSG	(WM_APP+408)	// added by eric at 20111024
#define NDK_SET_BARCODEOCRIMGS_MSG	(WM_APP+409)	// added by eric at 20111024
#define NDK_SET_BARCODEFILE_MSG	(WM_APP+410)	// added by eric at 20111024
#define	NDK_ACK_START_INSPECTION	(WM_APP+411)	// Beagle 20111123 added.
#define	NDK_NOTIFY_GRABBER_STOPPED	(WM_APP+412)	// Beagle 20111123 added.

#define NDK_ACT_EXPORTPROJECT	(WM_APP+413)		// added by eric at 20111202
#define NDK_ACT_IMPORTPROJECT	(WM_APP+414)		// added by eric at 20111202
#define NDK_CLIENT_EXPORTPRJINFO	(WM_APP+415)	// added by eric at 20111202
#define NDK_CLI_EXPORT_ERRMSG	(WM_APP+416)		// added by eric at 20111202
#define NDK_CLI_IMPORT_ERRMSG	(WM_APP+417)		// added by eric at 20111202
#define NDK_ACT_UNDO_IMPORTPROJECT (WM_APP+418)		// added by eric at 20111202

#define NDK_ACT_DELDEFECTIMGAGE	(WM_APP+419)		// added by eric at 20111206
#define NDK_CLI_DELDEFECTIMGAGE	(WM_APP+420)		// added by eric at 20111206
#define NDK_ACT_DONEDELDEFECTIMGAGE	(WM_APP+421)	// added by eric at 20111206

#define NDK_ADD_LIGHTINK_BYINSPIMG	(WM_APP+422)	// added by eric at 20120106
#define NDK_CLI_LIGHTINKMAP		(WM_APP+423)		// added by eric at 20120106

#define NDK_CLI_COMPORT_ERR		(WM_APP+424)		// added by eric at 20120109
#define NDK_CLI_INSPECTION_ERR	(WM_APP+425)		// added by eric at 20120109
#define NDK_CLI_ACK_ENTER_SETGOLDEN	(WM_APP+426)	// Beagle 20120106 added.
#define NDK_ACT_DEFIMAGESIZEINFO	(WM_APP+427)	// added by eric at 20120112
#define NDK_CLI_DEFIMAGESIZEINFO	(WM_APP+428)	// added by eric at 20120112
#define NDK_ASK_PRODUCTION_DETAIL	(WM_APP+429)	// added by eric at 20120116
#define NDK_CLICKED_RECONNECT_BTN	(WM_APP+430)	// Beagle 20120119 added.
#define NDK_CLI_IOERROR_MSG			(WM_APP+431)	// added by eric at 20120201
#define NDK_UPDATE_MAXSPEED 		(WM_APP+432)	// added by eric at 20120217
#define NDK_CLI_SPEEDTOOFAST_MSG	(WM_APP+433)	// added by eric at 20120217
#define NDK_SET_SHRINKIMAGE			(WM_APP+434)	// Beagle 20120220 added.
#define NDK_ASK_SETNEWBARCODE		(WM_APP+435)	// added by eric at 20120223
#define NDK_INFORM_INSPRESULT		(WM_APP+436)	// Beagle 20120302 added.
#define NDK_ASK_BARCODELIST			(WM_APP+437)	// added by eric at 20120312
#define NDK_ACT_BARCODELIST			(WM_APP+438)	// added by eric at 20120312
#define NDK_ASK_BARCODEFILE			(WM_APP+439)	// added by eric at 20120312
#define NDK_ACT_BARCODEFILE			(WM_APP+440)	// added by eric at 20120312
#define NDK_CLI_BARCORDFILE_ERR		(WM_APP+441)	// added by eric at 20120312
#define NDK_MOD_GOLDENMAP			(WM_APP+442)	// added by eric at 20120330
#define NDK_CLI_DELETEPROJECT		(WM_APP+443)	// added by eric at 20120528
#define NDK_CLI_CAMERANUMBER		(WM_APP+444)	// added by eric at 20120506
#define NDK_SET_2DCODEINSPVALS_MSG	(WM_APP+445)	// added by eric at 20120506
//#define NDK_SETPRINTMODE			(WM_APP+446)	// added by eric at 20120704
//#define NDK_UNI_LIGHTLEVEL			(WM_APP+447)	// added by eric at 20120706,20131218 remove
#define NDK_ALL_LIGHTLEVEL			(WM_APP+448)	// added by eric at 20120712
#define NDK_SET_CONNECTEDLSID		(WM_APP+449)	// added by eric at 20120810
#define NDK_SET_ALARMLIGHTVALS		(WM_APP+450)	// added by eric at 20120810
#define NDK_SET_WEBMODEFULLIMAGE	(WM_APP+451)	// added by eric at 20120817
#define NDK_SET_WEBMODESAMPLE		(WM_APP+452)	// added by eric at 20120817
#define NDK_SET_WEBPRJVALS			(WM_APP+453)	// added by eric at 20120822
#define NDK_SET_SOLENOID_MODE		(WM_APP+454)	// Beagle 20120905 added.
#define NDK_GOLDEN_CHANGE			(WM_APP+455)	// added by eric at 20120919
#define NDK_SET_PATTERNPOSVAL		(WM_APP+456)	// added by eric at 20121008
#define NDK_SET_PATTERNMAPMOD		(WM_APP+457)	// added by eric at 20121008
#define NDK_SET_RESETSAMPLE			(WM_APP+458)	// added by eric at 20121008
#define NDK_ASK_SEGMENTMAPIMG		(WM_APP+459)	// added by eric at 20121019
#define NDK_NOTIFY_CMD				(WM_APP+460)	// added by eric chao at 20121025
#define NDK_ASK_SOLENOIDTRIGGERTEST	(WM_APP+461)	// added by eric at 20121030
#define NDK_FULLWEAKEN_BYINSPIMG	(WM_APP+462)	// added by eric at 20121127
#define NDK_SET_LIGHTSOURCETEMPLATE	(WM_APP+463)	// added by eric at 20121130
#define NDK_ASK_REMOVEPRODUCTION	(WM_APP+464)	// added by eric at 20121205
#define NDK_SET_SEGMENTNUMBER		(WM_APP+465)	// added by eric at 20130109
#define NDK_SET_LAYOUTSETTING		(WM_APP+466)	// added by eric at 20130109
#define NDK_SET_SEGMENTRELATION		(WM_APP+467)	// added by eric at 20130109
#define NDK_SET_IMAGEROTATION		(WM_APP+468)	// added by eric at 20130130
#define NDK_CLI_TOOFAST_NOECHO_MSG	(WM_APP+469)	// added by eric chao at 20130201
#define NDK_CLI_CHANGE_EWF_MODE		(WM_APP+470)	// added by eric chao at 20130204
#define NDK_UPDATE_IOPULSE			(WM_APP+471)	// added by eric chao at 20130416
#define NDK_SET_VIEWORIGINALIMG		(WM_APP+472)	// added by eric at 20130509
#define NDK_SET_MACHINETIME			(WM_APP+473)	// added by eric at 20130522
#define NDK_START_FREERUN			(WM_APP+474)	// added by eric at 20130528
#define NDK_RESET_INSP				(WM_APP+475)	// added by eric chao 20130605
#define NDK_SET_SOLENOID			(WM_APP+476)	// added by eric at 20130703
#define NDK_CLI_WARNING_MSG			(WM_APP+477)	// added by amike at 20130704
#define NDK_SET_LIGHTSRCMAP			(WM_APP+478)	// added by eric at 20130724
#define NDK_SET_INPUTTRIGGERLINK	(WM_APP+479)	// added by eric at 20130731
#define NDK_SET_ULTRASONICRESPONSETIME	(WM_APP+480)	// added by eric at 20130814
#define NDK_SET_EXPOSUREVALS		(WM_APP+481)	// added by eric at 20130906
#define NDK_SET_FOVTIMES			(WM_APP+482)	// added by eric at 20130906
#define NDK_SET_IOPINCAMERAMAP		(WM_APP+483)	// added by eric at 20130911
#define NDK_FILE_TRANSFER			(WM_APP+484)    //eric chao 20130914
#define NDK_ESTIMATEBLANKS			(WM_APP+485)	// added by eric at 20130917
#define NDK_SET_BLANKBOXINSP		(WM_APP+486)	// added by eric at 20131115
#define NDK_CUR_LIGHTSOURCE			(WM_APP+487)    //eric chao 20131115
#define NDK_HARDWARE_DETECTION		(WM_APP+488)	// added by eric at 20131119
#define NDK_SET_BELTLENGTHVALS		(WM_APP+489)	// added by eric at 20140220
#define NDK_ASK_CLEARPAGE2SETS		(WM_APP+490)	// added by eric at 20140320
#define NDK_SET_QCMODE				(WM_APP+491)	// added by eric at 20140429
#define NDK_SET_WASTEZONEVALS		(WM_APP+492)	// added by eric at 20140506
#define NDK_SET_EXSOLENOIDVALS		(WM_APP+493)	// added by eric at 20140515
#define NDK_SET_BEEPVALS			(WM_APP+494)	// added by eric at 20140515
#define NDK_SET_CONFIGIO			(WM_APP+495)	// added by eric at 20140515
#define NDK_SET_MISSTRIGGERVALS		(WM_APP+496)	// added by eric at 20140520
#define NDK_ANCHORCHECK_MESSAGE		(WM_APP+497)	// added by eric at 20140619
#define NDK_CHECKMGCSTATE_MSG		(WM_APP+498)	// added by eric at 20140801
#define NDK_UPDATE_SEGMENT_EX		(WM_APP+499)	//seanchen 20140728-01
#define NDK_SET_WEBMODE_START_POS	(WM_APP+500)	// eric chao 20140728
#define NDK_SET_DECODEINSPRELATION	(WM_APP+501)	// added by eric at 20140912
#define NDK_SET_ALIASDEFECTTYPE_KEY	(WM_APP+502)	// added by eric at 20140925
#define NDK_SET_BACKUPBARCODEFILE	(WM_APP+503)	// added by eric at 20140926
#define NDK_SET_TRANSCARDVERSION	(WM_APP+504)	//seanchen 20141001-01
#define NDK_RECHECK_IOCARD			(WM_APP+505)	//seanchen 20141001-01
#define NDK_SET_CORPPROFILE			(WM_APP+506)	// added by eric at 20141006
#define NDK_UNMASK_DEFECTIMG		(WM_APP+507)	//未使用　以後可以使用
#define NDK_SET_ROTATIONCHECK		(WM_APP+508)	// added by eric at 20141013
#define NDK_ASK_QRIMAGERECT			(WM_APP+509)	// added by eric at 20141209
#define NDK_SET_SPECIALINSPPROFILE	(WM_APP+510)	// added by eric at 20150115
#define NDK_ASK_TEMPLATE_IMAGES		(WM_APP+511)	// added by eric at 20150125
#define NDK_SEND_SEGTEMPLATE		(WM_APP+512)	// added by eric at 20150201
#define NDK_MOD_TEMPLATEMAXMINMAP	(WM_APP+513)	// added by eric at 20150224
#define NDK_SET_DEFECTGROUPTYPE		(WM_APP+514)	// added by eric at 20150310
//#define NDK_SET_EDGESTATE			(WM_APP+515)	// added by eric at 20150330    no use
#define NDK_SENDCUSTOMSEGMENTTAB	(WM_APP+516)	// added by eric at 20150415
#define NDK_SET_FREQMAP				(WM_APP+517)	// eric chao 20150420
#define NDK_ASK_ANCHORPOINT			(WM_APP+518)	// added by eric at 20150427
#define NDK_ASK_MODIFYCLRDERIVATE	(WM_APP+519)	// added by eric at 20150430
#define NDK_RESP_BMP_FILE			(WM_APP+520)	// seanchen 20150610-02
#define NDK_SET_DEFECT_OBJECT_INFO	(WM_APP+521)	// eric chao 20150615
#define NDK_SET_REPRESENTIMAGE		(WM_APP+522)	// added by eric at 20150617
#define NDK_SET_GPIOLINK			(WM_APP+523)	// added by eric at 20150820
#define NDK_GET_QRENCODEPAGE		(WM_APP+525)	// added by eric at 20151001
#define NDK_SET_REELMODE			(WM_APP+526)	// added by eric at 20151022
#define NDK_SET_WEBNOTRIGGERLEADER	(WM_APP+527)	//seanchen 20151015-01
#define NDK_ASK_EDGECHKMAP			(WM_APP+528)	// added by eric at 20151204
#define NDK_SET_INSPECTIONCHECK		(WM_APP+529)	// added by eric at 20151222
#define NDK_SET_ENCRYPTMODE			(WM_APP+530)	// added by eric at 20160127
#define NDK_ASK_UPDATEIMPORTFILERELATION	(WM_APP+531)	// added by eric at 20160328
#define NDK_SET_REALTIMEIMAGE_RECT	(WM_APP+532)	// added by eric at 20160402
#define NDK_SET_REALTIMEIMAGE_STATUS (WM_APP+533)	// added by eric at 20160402
#define NDK_SEND_REALTIMEIMAGE		(WM_APP+534)	// added by eric at 20160402
#define NDK_SET_WEBUNITSETTINGS		(WM_APP+535)	// added by eric at 20160415
#define NDK_SET_T2ULTRASONICDIST	(WM_APP+536)	// added by eric at 20160420
#define NDK_SET_LABELINGVALS		(WM_APP+537)	// added by eric at 20160504
#define NDK_SET_LABELINGOFFSETVALS	(WM_APP+538)	// added by eric at 20160505
#define NDK_SET_AUTOPRJ				(WM_APP+539)	// added by eric at 20160515
#define NDK_SET_AUTOPRJSTEP			(WM_APP+540)	// added by eric at 20160515
#define NDK_SET_SAMPLEINDEX			(WM_APP+541)	// added by eric at 20160520
#define NDK_SET_HARDWAREDEFAULTVALS	(WM_APP+542)	// added by eric at 20160621
#define NDK_MSG_COMMAND_ITEM		(WM_APP+543)	//eric chao 20160630
#define NDK_MSG_COMMAND_ITEM_ECHO	(WM_APP+544)	//eric chao 20160630
#define NDK_SET_NEWBATCHNOTIFYSET	(WM_APP+545)	// added by eric at 20160729
#define NDK_MOD_DECODE_EXTRA		(WM_APP+546)	// eric chao 20160804
#define NDK_SET_INSP_RESULT_ITEM	(WM_APP+547)	// eric chao 20160812
#define NDK_SEND_PDFIMAGE			(WM_APP+548)	// added by eric at 20160825
#define NDK_SET_FAESETTINGTVALS		(WM_APP+549)	// added by eric at 20161214
#define NDK_SET_INSPSKIPDIST		(WM_APP+550)	// added by eric at 20170510
#define NDK_AOICAPTURE_NET_STATUS   (WM_APP+551)
#define NDK_SOLENOID_UI_CTRL		(WM_APP+552)	//eric chao 20180130
#define NDK_SET_LEDSETTINGVALS		(WM_APP+553)    // added by eric at 20180207
#define NDK_SET_RDPSESSION_CONNECTIONSTRING		(WM_APP+554)   
// machine type
typedef enum
{
	MT_CLIENT1 = 0,
	MT_CLIENT2 = 1,
	MT_CLIENT3 = 2,
	MT_CLIENT4 = 3,
	MT_CLIENT5 = 4,
	MT_CLIENT6 = 5,
	MT_CLIENT7 = 6,
	MT_CLIENT8 = 7
} MACHINE_TYPE;

// Message Id shared with the client and the server
typedef enum 
{
	DM_CONNECT,				// message id for connection to server 
	DM_SHUTDOWN,			// command to ask client shutdown itself, from server to client
	DM_SETBASEINFO,			// command to setup system base info, server => client

	DM_NEWPROJECT,			// command to ask client to new a project, server => client
	DM_LOADPROJECT,			// command to ask client to load a project, server => client
	DM_DELETEPROJECT,		// command to ask client to delete a project, server => client
	DM_CHANGE_PRJNAME,		// command to ask client to change project name, server => client
	DM_CHANGE_PRJSET1,		// command to ask client to change project blank length, interval, trigger 2 solenoid, server => client
	DM_CHANGE_PRJSET2,		// command to ask client to change project trigger 2 camera, light source template, server => client
	DM_NEWPRODUCTION,		// command to ask client to begin another new production, server => client

	DM_START_INSPECTION,	// command to ask client to start working, server => client
	DM_STOP_INSPECTION,		// command to ask other machines to stop machine, server => client
	DM_LOGINUSER,			// command to setup login user, server => client
	
	DM_CUR_LIGHTSOURCE,		// command to tell server the current connected light source info of client side, client => server
	DM_CLI_PROJECTINFO,		// command to tell server each client's project detail information, client => server
	DM_CHANGE_PAGE,			// command to tell client to force change to specified page, server <=> client
	DM_ENTER_SETGOLDEN,		// command to tell client to enter set golden sample mode, server <=> client
	DM_LEAVE_SETGOLDEN,		// command to tell client to leave set golden sample mode, server <=> client

	DM_SET_ANCHOR,			// command to tell server/client to remove all anchor points and add new anchor points, server <=> client
	DM_NEW_SEGMENT,			// command to tell server/client to add a new segment, server <=> client
	DM_DEL_SEGMENT,			// command to tell server/client to delete a new segment, server <=> client
	DM_REMOVE_SEGMENT,		// command to tell server/client to remove a segment, server <=> client	// added by eric at 20110802
	DM_MOD_SEGMENT,			// command to tell server/client to modify a new segment, server <=> client
	DM_MGE_SEGMENT,			// command to tell server/client to merge(delete/new) a new segment, server <=> client
	DM_DIFF_SEGMENT_KEY,	// command to tell server the changed segment's primary key of client, client => server
	DM_MOV_SEGMENT,			// command to tell server/client to move a segment, server <=> client
	DM_MOD_INSPREGION,		// command to tell server/client to modify current inspection region, server <=> client
	DM_ASK_CLEARPAGE2SETS,	// command to ask client to clear segments, anchors, inspection region server => client	// added by eric at 20140320
	DM_SET_CHECKMGCSTATE,	// command to ask client to checkMgcState // added by eric at 20140801

	DM_SET_DARKPNT,			// command to tell server/client to modify the serious check points of project setting, server <=> client
	//DM_SET_COLORDIFFCHECK,	// command to tell server/client to modify the color diff check of project setting, server <=> client
	//DM_SET_COLORDELTA,		// command to tell server/client to modify the color diff delta of project setting, server <=> client
	//DM_SET_PAPERSHRINK,		// command to tell server/client to modify the paper shrink points of project setting, server <=> client    no use
	//DM_SET_INKCHECK1,		// command to tell server/client to modify the horizontal ink check of project setting, server <=> client			no use
	//DM_SET_INKCHECK2,		// command to tell server/client to modify the vertical ink of project setting, server <=> client						no use
	//DM_SET_INKPERCENTAGE,	// command to tell server/client to modify the ink check percentage of project setting, server <=> client	no use
	//DM_CLI_UNLOCKWAIT,		// command to tell server the client has finished the action, the waiting lock can be unlock, client => server	no use
	//DM_CLI_INSPRGNBACK,		// command to tell server the re-generated inspection region from client, client => server								no use
	
	DM_START_SAMPLING,		// command to tell server/client to start sampling, server <=> client
	DM_STOP_SAMPLING,		// command to tell server/client to stop sampling, server <=> client
	DM_CLI_SETSAMPLEIMG,	// command to tell server the last captured sample image from client, client = server
	DM_CHECK_IDXSAMPLE,		// command to tell server/client to check specified sample image, server <=> client
	DM_DO_SETGOLDEN,		// command to tell client to do set golden image, server <=> client

	DM_CLI_INSPRESULT,		// command to tell server the inspection result from client side, client => server
	DM_ASK_INSPIMAGE,		// command to ask client send back the specified inspection image, server => client
	DM_CLI_INSPIMAGE,		// command to tell server the inspection image from client side, client => server
//eric chao 20160222 remove DL
//	DM_DEL_DLGROUP,			// command to tell client to delete the specified defect learning group, server => client
	DM_INSP_SAMPLES,		// command to ask client to do inspection on samples or send the sample inspection results back to server, server <=> client
//	DM_ADD_DLGROUP_BYSAMPLE,	// command to tell client to add one defect learning group by using sample image, server => client
//	DM_ADD_DLGROUP_BYINSPIMG,	// command to tell client to add one defect learning group by using inspected image, server => client
//	DM_DIFF_DLGROUP_KEY,	// command to tell server the changed defect learning group's primary key of client, client => server
//	DM_UPDATE_DLSIZE,		// command to tell server the defect learning size of client, client => server

	DM_ASK_INSPDETAIL,		// command to ask client to do the inspection on specified image(by index) and specified defect learning group, server => client
	DM_CLI_INSPDETAIL,		// command to tell server the inspection result detail from client side, including defect map and defect learning result, client => server

	DM_ASK_PRJ_PRODUCTION,	// command to ask/set all production of client, client <=> server
	DM_ASK_PRODUCTION_DETAIL,	// command to ask/set a production records of client, client <=> server	-- added by eric at 20120116
	DM_ASK_DIMG_DETAIL,		// command to ask/set one specified defect image record of one specified production, server <=> client

	DM_SET_ENCODERDIST,		// command to setup encoder distance, server => client
	DM_SET_SOLENOIDRT,		// command to setup solenoid distance, server => client
//eric chao 20161220 remove
//	DM_SET_PIXELDIST,		// command to setup pixel distance, server => client
	DM_SET_KEEPDAY,			// command to setup defected image keep day, server => client
	DM_SET_AUTOCLEAN,		// command to setup if auto clean, server => client
	DM_SET_HASULTRASONIC,	// command to setup enabling ultrasonic
	//DM_SET_HASTRIGGER2,		// command to setup enabling trigger2								no use
	//DM_SET_TG2DISTANCE,		// command to setup trigger 2 to solenoid distance					no use
	DM_SET_MAXSPEED,		// command to setup max speed, server => client	-- added by eric at 20120217

	DM_LEVEL1_CHANGE,		// command to ask client to do the level 1 change
	DM_LEVEL2_CHANGE,		// command to ask client to do the level 2 change
	DM_LEVEL3_CHANGE,		// command to ask client to do the level 3 change
	DM_GOLDENCHANGE,		// command to ask client to do Golden change -- added by eric at 20120919

	DM_ADD_USER,			// command to ask client to add a user
	DM_MOD_USER,			// command to ask client to modify a user's password
	DM_DEL_USER,			// command to ask client to delete a user

	DM_UPDATE_SEGMENT,		// command to update the inspection segment data from client to server, client => server, for import function
	DM_UPDATE_SEGMENT_EX,	// command to update the inspection segment data from server TO client //seanchen 20140728

//	DM_SET_SPEED,			// command to tell server the current speed //eric chao 20171222 remove
	
	//DM_UNI_LIGHTLEVEL,		// command to ask client to change uni-lighting level -- added by eric at 20120706.eric chao 20131218 remove,no use now
	DM_ADD_LIGHTLEVEL,		// command to ask client to add lighting level
	DM_DES_LIGHTLEVEL,		// command to ask client to decrease lighting level
	//DM_ALL_LIGHTLEVEL,		// command to ask client to change all lighting level	-- added by eric at 20120712,eric chao 20131218 remove,no use now

	DM_CLIENT_ERRMSG,		// command to tell server the client error message

	DM_SET_SAVEALLIMG,		// command to ask client to save all rotated images for debug

	DM_CLI_SETWEAKENIMG,	// command to tell server the last captured weaken image from client, client = server
	DM_START_WEAKENLEARN,	// command to tell all client to start weaken learning
	DM_SET_WEAKENMAP,		// command to tell server the newest max/min maps
	DM_MOD_WEAKENMAP,		// command to ask client to modify its max/min maps	
	//DM_ADD_WEAKEN_BYINSPIMG,// command to ask client to do local weaken learn  //eric chao 20171117 no use remove
	DM_START_SINGLE_WEAKENLEARN,	// command to tell single client to start weaken learning
	DM_UNDOMOD_MAXMINMAP,
	DM_MOD_WEAKENMAP_NOSAVE,
	DM_RELOAD_MAXMINMAP,
	DM_SET_PRODUCTION,			// command to tell server the current production

//eric chao 20150211 no use ------------------------
	DM_SET_IOCARD_DEVICEMODE,//DM_CLI_PRJINFO_START,
	DM_SET_DEFECT_OBJECT_INFO,//DM_CLI_PRJINFO_END, //eric chao 20150615
	//DM_INSP_SAMPLE_START,				no use
	//DM_INSP_SAMPLE_END,					no use
//-----------------------

	DM_SET_IOVERSION,		// Command to tell server the I/O board version is acquired. -- Beagle 20110715
	// added by eric at 20110718
	DM_CLIENT_BLANKTOOCLOSE,	// command to display "blank too close" image
	DM_UNLOAD_PROJECT,		// Command to ask client to unload project and return to page 1 -- Beagle 20110719

	DM_ASK_FULLSAMPLEIMAGE,	// Command that request current client to send back sampling image. server => client -- Beagle 20110727
	DM_CLI_FULLSAMPLEIMAGE,	// Command for current client to send sampling image to server. client => server -- Beagle 20110727

	//DM_ASK_PRODUCTIONREPORT,	// Command to tell server/client to start production report, server <=> client	-- added by eric at 20110822		no use
	//DM_CLI_PRODUCTIONREPORT,	// Command to tell server to receive production report, server <=> client	-- added by eric at 20110822			no use

	DM_CHANGE_LANGUAGE,		// Command to tell clients to change UI language, server => client	-- added by eric at 20110825

	DM_ACK_START_INSPECTION,	// For clients to tell server ready to perform inspection. client => server -- Beagle 20110829

	DM_LOADPRJ_ERRMSG,	// command to tell server the client load project error message -- added by eric at 20110914

	DM_MOD_MAXMINMAP,		// command to ask client to modify its max/min maps	 --  added by eric at 20110929

	DM_SET_DEFECTFOLDER,	// command to ask client to modify its defect folder	 --  added by eric at 20110930

	DM_SET_BARCODEVALS,		// command to ask client to modify its barcode settings	 --  added by eric at 20111024
	DM_SET_BARCODEOCRIMGS,		// command to ask client to modify its barcode OCR imgs settings	 --  added by eric at 20111024
	DM_SET_BARCODEFILE,		// command to ask client to modify its barcode file	 --  added by eric at 20111024

	DM_NOTIFY_GRABBER_STOPPED,	// Client tell Master that grabber card is stopped. -- Beagle 20111123 added.

	DM_EXPORTPROJECT,			// command to ask client to export a project, server => client -- added by eric at 20111202
	DM_CLI_EXPORTPROJECT,		// command to tell server each client's project detail information, client => server -- added by eric at 20111202
	DM_IMPORTPROJECT,			// command to ask client to import a project, server => client -- added by eric at 20111202
	DM_CLI_EXPORT_ERRMSG,		// command to tell server the client export error message -- added by eric at 20111202
	DM_CLI_IMPORT_ERRMSG,		// command to tell server the client import error message -- added by eric at 20111202
	DM_UNDO_IMPORTPROJECT,		// command to tell client to undo import project -- added by eric at 20111202
	DM_ANCHORCHECK_MESSAGE,		// command to check anchor settings and show result -- added by eric at 20140619

	DM_ACK_DEFIMAGESIZEINFO,	// command to ask client to defect images size, server => client -- added by eric at 20120112
	DM_CLI_DEFIMAGESIZEINFO,	// command to tell server the client defect image size -- added by eric at 20120112
	DM_DELDEFECTIMGAGE,			// command to tell client to delete defect images -- added by eric at 20111206
	DM_CLI_DELDEFECTIMGAGE,		// command to tell server the client delete defect image size and the number that needs to delete -- added by eric at 20111206
	DM_DONE_DELDEFECTIMGAGE,	// command to tell client to finished to delete defect images -- added by eric at 20111206
	DM_CLI_DELETEPROJECT,		// Command to ask server to delete a project, client => server	-- added by eric at 20120528

	//DM_ADD_LIGHTINK_BYINSPIMG,	// command to ask client to do local Light & Ink learn	 -- added by eric at 20120106
	//DM_CLI_LIGHTINKMAP,			// command to tell server the client update learn maps -- added by eric at 20120106

	DM_CLI_COMPORT_ERR,			// Command to tell server the COM Port status. -- added by eric at 20120109
	DM_CLI_INSPECTION_ERR,		// Command to tell server the disable inspection. -- added by eric at 20120109
	DM_CLI_ACK_ENTER_SETGOLDEN,	// Acknowledge DM_ENTER_SETGOLDEN -- Beagle 20120106 added.
	DM_CLI_IOERROR_MSG,			// Command to tell server the IO Error. -- added by eric at 20120201
	DM_CLI_WARNING_MSG,			// Command to tell server to show warning message. -- added by amike at 20130704
	DM_CLIENT_SPEEDTOOFAST,		// command to display "speed too fast" error message	-- added by eric at 20120217
	DM_SET_SHRINKIMAGE,			// Command to setup client shrink rate of instant images. -- Beagle 20120220 added.
	DM_ASK_SETNEWBARCODE,		// command to ask client to backup barcode files	-- added by eric at 20120223
	DM_INFORM_INSPRESULT,		// command to tell client the inspection result of other clients, server => client -- Beagle 20120302 added.

	DM_ASK_BARCODELIST,			// command to ask client to send all barcode inspenction files list.	-- added by eric at 20120312
	DM_CLI_BARCODELIST,			// command to tell server the client selected barcode file list.	-- added by eric at 20120312
	DM_ASK_BARCORDFILE,			// command to ask client to send all barcode inspenction files.	-- added by eric at 20120312
	DM_CLI_BARCORDFILE,			// command to tell server the client selected barcode file.	-- added by eric at 20120312
	DM_CLI_BARCORDFILE_ERR,		// Command to tell server the barocde file Error. -- added by eric at 20120312
	DM_CLI_CAMERANUMBER,		// command to tell server the client set camera number.	-- added by eric at 20120506
	DM_SET_2DCODEINSPVALS,		// command to ask client to modify its 2D Code settings	 --  added by eric at 20120506
	DM_CLI_SETPRINTMODE,		// command to ask client to change printing test mode --  added by eric at 20120704
	DM_SET_CONNECTEDLSID,		// command to ask client to modify its connected light source ID setting	 --  added by eric at 20120810
	DM_SET_ALARMLIGHTVALS,		// command to ask client to modify alarm light setting	 --  added by eric at 20120810
	DM_CLI_WEBMODEFULLIMAGE,	// Command for current client to send sampling image to server. client => server -- added by eric at 20120817
	DM_SET_WEBMODESAMPLE,		// Command to tell client settings start point and offset size, server => client -- added by eric at 20120817
	DM_SET_WEBPRJVALS,			// command to ask client to modify its web mode settings	 --  added by eric at 20120822
	DM_SET_SOLENOID_MODE,		// Command to tell client to change I/O board solenoid mode. server => client	-- Beagle 20120905 added.
	DM_SET_PATTERNPOSVALS,		// command to ask client to modify its pattern three top-left position settings	 --  added by eric at 20121008
	DM_SET_PATTERNMAPMOD,		// command to ask client to modify its pattern map data	 --  added by eric at 20121008
	DM_SET_RESETSAMPLE,			// command to ask client to reset its golden max min images	 --  added by eric at 20121008
	DM_ASK_SEGMENTMAPIMG,		// command to ask client to send segment map & mask images	 --  added by eric at 20121019
	DM_NOTIFY_CMD,				// command to tell server the client complete  added by eric at 20121025
	DM_ASK_SOLENOIDTRIGGERTEST,	// command to ask client to do solenoid or page trigger test	-- added by eric at 20121030
	DM_FULLWEAKEN_BYINSPIMG,	// command to ask client to do full weaken learn	-- added by eric at 20121127
	DM_SET_LIGHTSOURCETEMPLATE,	// command to ask client to add a template light source -- added by eric at 20121130
	DM_ASK_REMOVEPRODUCTION,	// command to ask client to remove a production date -- added by eric at 20121205
	DM_SET_SEGMENTNUMBER,		// command to tell client number of segments to be sent from server -- added by eric at 20130109
	DM_SET_LAYOUTSETTING,		// command to tell client layout format from server -- added by eric at 20130109
	DM_SET_SEGMENTRELATION, 	// command to tell client project segments relation settings from server -- added by eric at 20130109
	DM_SET_IMAGEROTATION,		// command to tell client rotation start and stop position settings from server -- added by eric at 20130130
	DM_CLIENT_TOOFAST_NOECHO,	// command to tell server the client production too fast and io card sent blank decision no echo --- added by eric chao at 20130201
	DM_SET_CLIENT_EWF,			// command to tell client change ewf mode added by eric chao 20130204
	DM_NOTIFY_DETECT_CAM,		// command to tell server the client get the correct camera type added by eric chao 20130322
	DM_SET_IOPITCH,				// command to setup IO pulse, server => client
	DM_SET_VIEWORIGINALIMG,		// command to tell all clients to set show/hide original image check -- added by eric at 20130509
	DM_SET_MACHINETIME,			// command to tell all clients to be synchronized with server time -- added by eric at 20130522
	DM_START_FREERUN,			// command to tell server/client to start Free Run Images, server <=> client -- added by eric at 20130528
	DM_RESET_INSPECTION,		// command to tell client to reset current inspection -- eric chao 20130605
	DM_SHOW_DEFECTMAP,			// command to tell client to Show/Hide defect rect map -- eric chao 20130627
	DM_SET_SOLENOID,			// command to tell all clients to set solenoid check -- added by eric at 20130703
	DM_NORMAL_STREVNET,			// command for client and server (general purprse) (must delete memory after using) -- added by seanchen at 20130710
	DM_NORMAL_DYSTREVNET,		// command for client and server (general purprse) (must delete memory after using) -- added by seanchen at 20130710
	DM_SET_LIGHTSRCMAP,			// command to tell all clients to set Light Source Mapping -- added by eric at 20130724
	DM_SET_INPUTTRIGGERLINK,	// command to tell all clients to set total input trigger, each Input Trigger length, and solenoid link --- added by eric at 20130731
	DM_SET_ULTRASONICRESPONSETIME,	// command to tell all clients to set UltraSonic Response Time --- added by eric at 20130814
	DM_SET_EXPOSUREVALS,		// command to tell all clients to set Camera Exposure Value -- added by eric at 20130906
	DM_SET_FOVTIMES,			// command to tell all clients to set FOV Times -- added by eric at 20130906
	DM_SET_IOPINCAMERAMAP,		// command to tell all clients to set Frame Grabber Pin & Page Delay Pin with All Camera -- added by eric at 20130911
	DM_PRJ_INFO_QUERY,			// command to tell all clients to send all info to master --- eric chao 20130912
	DM_FILE_TRANSFER,			// command to trans file to client or to server   eric chao 20130914
	DM_ESTIMATEBLANKS,			// command to ask client to send Estimate Blanks -- added by eric at 20130917
	DM_SET_PAGEMODERUN,			// command to tell server to run PageMode -- eric chao 20131007
	DM_SET_BLANKBOXINSP,		// command to tell client to set Blank Box Inspection check -- added by eric at 20131115
	DM_NOTIFY_CONNECT_SUCCESS,	// command to tell server to client connect ok -- eric chao 20131115
	DM_HARDWARE_DETECTION,		//  command to tell client to set Hardware detection -- added by eric at 20131119
	DM_SET_SAMPLEEXTRAINFO,		// command to tell server all extra sample info --- eric chao 20131230
	DM_AUTO_UPDATE,				// command to tell client to Execute update process --- eric chao 20140102
	DM_AOI_RESTART,				// command to tell client to Restart AOI --- eric chao 20140113
	DM_SET_BELTLENGTHVALS,		// command to ask client to save Belt Length settings	 --  added by eric at 20140220
	DM_PREPARE_AUTO_UPDATE,		// command to tell client prepare Auto Update --- eric chao 20140308
	DM_SET_QCMODE,				// command to tell server QC Mode --- added by eric at 20140429
	DM_SET_WASTEZONEVALS,		// command to tell client to update Waste Paper Zone Settings --- added by eric at 20140506
	DM_SET_EXSOLENOIDVALS,		// command to tell client to update Extra Solenoid Output Pin settings --- added by eric at 20140515
	DM_SET_BEEPVALS,			// command to tell client to update Beep Alarm Output Pin settings --- added by eric at 20140515
	DM_SET_CONFIGIO,			// command to tell client to set Config IO settings --- added by eric at 20140515
	DM_SET_MISSTRIGGERVALS,		// command to tell client to set Miss Trigger settings --- added by eric at 20140520
	DM_SET_WEBMODE_START_POS,   // command to tell client to set WebMode Inspection Start Position ---- eric chao 20140728
	DM_WEB_INFO_EXPORT,			// command to tell master to finish get web export FILE --- eric chao 20140728
	DM_SET_DECODEINSPRELATION,	// command to tell client to set Decode & Inspection relation settings -- added by eric at 20140912
	DM_SET_ALIASDEFECTTYPE_KEY,	// command to tell master that defectType's Id in Alias table -- added by eric at 20140925
	DM_SET_BACKUPBARCODEFILE,	// command to tell client to backup its barcode file	 --  added by eric at 20140926
	DM_SET_TRANSCARDVERSION,	// Command to tell server the Trans board version is acquired. -- seanchen 20141001-01
	DM_RECHECK_IOCARD,			// Command to tell clint to run check IO Card flow -- seanchen 20141001-01
	DM_SET_CORPPROFILE,			// Command to tell client to set Corporation Profile --- added by eric at 20141006	
	DM_UNMASK_DEFECTIMG,		// Command to tell clint to unmask defect image or client tell master to unmask defect -- 未使用　以後可以使用
	DM_SET_ROTATIONCHECK,		// Command to tell client to change rotation check --- added by eric at 20141013
	DM_ASK_SEGBARCODEREPORT,	// Command to ask All clients to send segment barcode report files --- added by eric at 20141125
	DM_ASK_QRIMAGERECT,			// Command to ask client to send "calculator shift values" for QR Image --- added by eric at 20141209
	DM_SET_SPECIALINSPPROFILE,	// Command to tell client to set Special Insp Type value -- added by eric at 20150115
	DM_SEND_SEGTEMPLATE,		// Command to tell client to set Template value --- added by eric at 20150125
	DM_ASK_TEMPLATE_IMAGES,		// Command to ask client to send Template Images --- added by eric at 20150125
	DM_MOD_TEMPLATEMAXMINMAP,	// Command to tell client to save Template Golden, MaxMap, MinMap --- added by eric at 20150224
	DM_SET_DEFECTGROUPTYPE,		// Command to tell client to set Corp. set Defect Group Type values -- added by eric at 20150304
	//DM_SET_EDGESTATE,			// Command to tell client to set Check Edge Pixels -- added by eric at 20150330 // no use
	DM_SENDCUSTOMSEGMENTTAB,	// Command to tell client to save Custom Segment Tab Display settings -- added by eric at 20150415
	DM_QUERY_FREQMAP,			// Command to tell clinet to send Defect Freq Map --- eric chao 20150420
	DM_SET_FREQMAP,				// Command to tell master to Update Defect Freq Map --- eric chao 20150420
	DM_ASK_ANCHORPOINT,			// Command to ask client to send anchor point -- added by eric at 20150427
	DM_ASK_MODIFYCLRDERIVATE,	// Command to ask client to do auto modify color derivate segment -- added by eric at 20150430
	DM_RESP_BMP_FILE,			// command to tell server the client send BMP image -- seanchen 20150610-02
	DM_QUERY_DEFECT_OBJECT_ITEM,	// Command to ask client to send Defect Object Item --- eric chao 20150611
	DM_SET_REPRESENTIMAGE,		// Command to tell client to set Representative Image Settings -- added by eric at 20150617
	DM_WMCLOSE_NOTIFY,			// Command to tell client to do WM_CLOSE notify -- added by eric at 20150728
	DM_SET_GPIOLINK,			// command to tell client to set GPIO Link Settings ---- added by eric at 20150820
	DM_GET_QRENCODEPAGE,		// Command to ask client to check QR Encode Page ---- added by eric at 20151001
	DM_SET_REELMODE,			// command to tell client to set Reel Mode Settings ---- added by eric at 20151022
	DM_SET_WEBNOTRIGGERLEADER,	// command to tell client to find start for web mode ---- seanchen 20151015-01
	DM_ASK_EDGECHKMAP,			// command to ask client to send Edge Check Map ---- added by eric at 20151204
	DM_SET_INSPECTIONCHECK,		// command to tell client to set Inspection Check ---- added by eric at 20151222
	DM_SET_PDF_LAYER,			// command to tell client PDF Layer process		eric chao 20160118
	DM_SET_ENCRYPTMODE,			// command to tell client to set Encrypt Mode Settings ---- added by eric at 20160126
	DM_ASK_UPDATEIMPORTFILERELATION,	// command to tell client to update code file or relation ---- added by eric at 20160328
	DM_SET_REALTIMEIMAGE_RECT,	// command to tell client to set Real-time display area---- added by eric at 20160402
	DM_SET_REALTIMEIMAGE_STATUS,// command to tell client to set Real-time disable/enable ---- added by eric at 20160402
	DM_SEND_REALTIMEIMAGE,		// command to ask client to set Real-time image ---- added by eric at 20160402
	DM_SET_QRTYPE,				// command to ask client to set QR Type ---- added by eric at 20160413
	DM_SET_WEBUNITSETTINGS,		// command to ask client to set Web Unit settings ---- added by eric at 20160415
	DM_SET_T2ULTRASONICDIST,	// command to tell client to set Trigger to Solenoid distance Settings ---- added by eric at 20160420
	DM_SET_LABELINGVALS,		// command to tell client to update Labeling Output Pin settings --- added by eric at 20160504
	DM_SET_LABELINGOFFSETVALS,	// command to ask client to modify labeling offset settings	 --  added by eric at 20160505
	DM_SET_AUTOPRJ,				// command to tell client to set auto project for anchors and derivate segment Settings ---- added by eric at 20160515
	DM_SET_AUTOPRJSTEP,			// command to tell server to set auto project step information ---- added by eric at 20160515
	DM_SET_SAMPLEINDEX,			// command to tell client to set sample index ---- added by eric at 20160520
	DM_SET_HARDWAREDEFAULTVALS,	// command to ask client to set HW default settings ---- added by eric at 20160621
	DM_SET_NEWBATCHNOTIFYSET,	// command to ask client to set new batch notify check T2Notify dist settings ---- added by eric at 20160729
	DM_MSG_COMMAND_ITEM,		// command for MSG_ITEM_COMMAND
	DM_MOD_DECODE_EXTRA,		// command to modidy client Decode List eric chao 20160804
	DM_SET_INSP_RESULT_ITEM,	// command to tell server Insp Result //eric chao 20160812
	DM_SET_INSP_WEBEXPORTCACHE,	// command to tell server Cache Result Done	// added by eric at 20160914 
	DM_SEND_PDFIMAGE,			// Command to send a PDF file to client --- added by eric at 20160826
	DM_SET_FAESETTINGTVALS,		// command to ask client to set FAE settings ---- added by eric at 20161214
	DM_SET_INSPSKIPDIST,		// command to ask client to set new Inspection Skip Dist dist settings ---- added by eric at 20170510
	DM_MACHINE_REBOOT,			// command to ask client Machine Reboot //eric chao 20171011
    DM_AOICAPTURE_BATCH_ID,     // command to tell client batch-id
    DM_AOICAPTURE_CALCULATE_SIZE, // command to tell server capture size
	DM_SOLENOID_UI_CTRL,		//command to tell client Solenoid Ui Control
	DM_SET_LEDSETVALS,          //command to tell client to update LED settings --- added by eric at 20180207
	DM_RDPSESSION_CONNECTIONSTRING,	// command to tell server RDPSession ConnectionString
} NDK_DataMessage;


typedef enum //eric chao 20160630
{
	MSG_CMD_HOTKEY = 0,
	MSG_GRAB_STARTOFFSET, //Slave ==> Master Send WebMode Start Line Offset
	MSG_GRAB_MOVEOFFSET,  //Master ==> Slave Send WebMode Insp First Blank Position (pixel)
	MSG_GRAB_CAMERAOFFSET,//Master ==> Slave Send Camera dist from Lead of Camera (mm)

	MSG_IO_SYNCSET_START,
	MSG_IO_SYNCSET_END,
    MSG_INSPRESUMEPAUSE,

	MSG_P2_GETSAMPLE,
	MSG_P2_TEMPALATEMAP,
	MSG_P2_SAMPLEITEMCHANGE,
	MSG_P2_SAMPLEITEMCHANGE_EX,
	MSG_P2_GLOBALSAMPLESET,
	MSG_P2_SAMPLEDIRTYPROCESS,
	MSG_P2_DELSEGMENT_SUBKEY,
    MSG_P2_AREADECODEVALS,
    MSG_P2_AREADECODE_TYPE_CHANGE,
    MSG_P2_ALLPASSWIZARDSTATUS,
	//MSG_IO_XX
	//MSG_P1_XX
	//MSG_P2_XX
	//MSG_P3_XX
	MSG_P3_NEWBATCH,
	MSG_P3_DIST,
    MSG_P3_SAMPLEDIRTYPROCESS,
	MSG_P3_SOLENOID, //20180723

	MSG_WEB_PRE_DIST,
	MSG_WEB_NEXT_DIST,
	MSG_P1_PDFSET,	// added by eric at 20160825
	MSG_EDGE_SETTING_MOD, //20170822
	MSG_EDGE_INSP_MOD, //20171024
	MSG_MAXBLANKLEN_DIST,
}MSG_ITEM_COMMAND;

//--------------------------------------------------
// Eric Chao 20160630
// 
// *.Action Command Item
//   nType = 0 , other field set Null
// 
// *.Setup Command Item
//   nType = 1 , Data Field : nTypeValue, pLinkData = NULL
//
// *.Link Command Item
//   nType = 2 , Data Size: nTypeValue, Data Ptr = pLinkData
//
//--------------------------------------------------
typedef enum
{
	MSG_CMD_TYPE_ACTION =0,
	MSG_CMD_TYPE_SETUP,
	MSG_CMD_TYPE_LINK,
}MSG_CMD_TYPE;

typedef struct MSG_NDK_ITEM_{
	DWORD dwMsg; //MSG_ITEM_COMMAND
	int	  nClientId;
	int   nEcho;
	int   nType;  
	int   nTypeValue;
	unsigned char *pLinkData;
}MSG_NDK_ITEM;

typedef struct FILE_DATA_INFO_{ //eric chao 20130914
	CString sFileName;
	int nFileSize;
	int nSlaveId;
	unsigned char *pFileData;
}FILE_DATA_INFO;
typedef struct BASE_INFO_ {
	
	wchar_t	userName[50];	// login user name
	double	encDistance;
	int		solenoidRpTime;
	//double	pixelDistance; //eric chao 20130318 remove 20130318 remove
	int		keepDay;
	BOOL	autoClean;

	BOOL	hasUltraSonic;	// added by eric at 20130819

	int		maxSpeed;	// added by eric at 20120217
	int		cameraNumber;	// added by eric at 20120506
	int		IoPitch; //eric chao 20130416
	double	exposureVals;	// added by eric at 20130906
	int		FOVTimes;	// added by eric at 20130906
	wchar_t PinCameraMap[255];	// added by eric at 20130911
	BOOL	bEncoderCheck;	// added by eric at 20131111
	double	beltDiameter;	// added by eric at 20131111
	int		beltFrequency;	// added by eric at 20131111
	int		cropProfile;	// added by eric at 20141006
	BOOL	rotationCheck;	// added by eric at 20141013
	int		specialInsptype;	// added by eric at 20150115
} NDK_BASE_INFO;

typedef struct LTEMPLATE_INFO_ {
	
	wchar_t	blankType[50];
	wchar_t	lightValue[1000];

} NDK_LTEMPLATE_INFO;

typedef struct LIGHTSOURCE_INFO_ {

	wchar_t	modelName[50];
	int		sensorStatus;
	int		templateNumber;

} NDK_LIGHTSR_INFO;

typedef struct NEWPRJ_ {
	
	wchar_t prjName[255];
	double	blankLength;
	double	tg2Camera;
	double	tg2Solenoid;
	double	blankInterval;
	int		lightTpIndex;
	wchar_t productionDate[255];	// added by eric at 20111012
	wchar_t s2DCodePrjVals[255];	// added by eric at 20120506
	wchar_t s2DCodeInspVals[2048];	// added by eric at 20120506
	wchar_t sWebModePrjVals[2048];	// added by eric at 20120822
	wchar_t sPatternPosVals[32];	// added by eric at 20121008
	wchar_t	lightTpValue[1000];		// added by eric at 20121129
	wchar_t sLayoutFormatVals[1024];	// added by eric at 20130109
	wchar_t segmentRelationVals[2048];	// added by eric at 20130109
	int triggerEnable;	// added by eric at 20140304
	int absoluteLenEnable;	// added by eric at 20140422
} NDK_NEWPRJ;
