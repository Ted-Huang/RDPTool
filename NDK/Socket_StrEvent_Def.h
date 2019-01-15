//#include "Socket_StrEvent_Def.h"
#pragma once

//<SendToSlaveUser>[[%d]]  %d = -1 (unknow) , = -2 (cur salve) ,  = 9999 (all slave)
#define _SendToSlaveUserID_Unknow_		-1
#define _SendToSlaveUserID_CurSlave_	-2
#define _SendToSlaveUserID_AllSlave_	9999

namespace SocketStrEvent		//seanchen 20130710
{
	enum { UNKNOW_MSG_ID = -1 };

	struct MSG_INFO
	{
		int nMsgID;

		MSG_INFO()
		{
			nMsgID = UNKNOW_MSG_ID;
		}
	};

	// .... MsgID .... //
	struct INIT_DEFECTIMG_QUERY : public MSG_INFO
	{
		enum { MSG_ID = 3 };
		INIT_DEFECTIMG_QUERY(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct CLOSE_DEFECTIMG_QUERY : public MSG_INFO
	{
		enum { MSG_ID = 4 };
		CLOSE_DEFECTIMG_QUERY(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct RESPONSE_INIT_DEFECTIMG_QUERY : public MSG_INFO
	{
		enum { MSG_ID = 5 };
		RESPONSE_INIT_DEFECTIMG_QUERY(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct REQ_GET_DEFECTIMG_ITEM : public MSG_INFO	//Non sort
	{
		enum { MSG_ID = 6 };
		REQ_GET_DEFECTIMG_ITEM(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct REQ_GET_SORT_DEFECTIMG_ITEM : public MSG_INFO
	{
		enum { MSG_ID = 7 };
		REQ_GET_SORT_DEFECTIMG_ITEM(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct DEFECTIMG_ITEM_DATA : public MSG_INFO
	{
		enum { MSG_ID = 8 };
		DEFECTIMG_ITEM_DATA(){nMsgID = MSG_ID;};
	};

	struct REQ_DEFECT_IMG_BUF : public MSG_INFO
	{
		enum { MSG_ID = 9 };
		REQ_DEFECT_IMG_BUF(){nMsgID = MSG_ID;};
	};

	struct INIT_SORT_DEFECTIMG_QUERY : public MSG_INFO
	{
		enum { MSG_ID = 10 };
		INIT_SORT_DEFECTIMG_QUERY(){nMsgID = MSG_ID;};
	};


	struct RESPONSE_SORT_DEFECTIMG_QUERY : public MSG_INFO
	{
		enum { MSG_ID = 11 };
		RESPONSE_SORT_DEFECTIMG_QUERY(){nMsgID = MSG_ID;};
	};
	// ====================================== //
	// .... MsgID .... //
	struct REQ_AREA_CFG : public MSG_INFO
	{
		enum { MSG_ID = 30 };
		REQ_AREA_CFG(){nMsgID = MSG_ID;};
	};


	// .... MsgID .... //
	struct AREA_CFG : public MSG_INFO
	{
		enum { MSG_ID = 31 };
		AREA_CFG(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct NONGENERAL_SEGMENT_ALIAS : public MSG_INFO
	{
		enum { MSG_ID = 32 };
		NONGENERAL_SEGMENT_ALIAS(){nMsgID = MSG_ID;};
	};

	// .... MsgID .... //
	struct PRODUCT_ID_MAPPING : public MSG_INFO
	{
		enum { MSG_ID = 33 };
		PRODUCT_ID_MAPPING(){nMsgID = MSG_ID;};
	};

	// ====================================== //
	// .... MsgID .... //
	struct REQ_EXCEL_REPORT : public MSG_INFO
	{
		enum { MSG_ID = 50 };
		REQ_EXCEL_REPORT(){nMsgID = MSG_ID;};
	};

	struct RESPONSE_PRODUCTION_IMAGE_INFO : public MSG_INFO //slave send RESPONSE_PRODUCTION_IMAGE_INFO to master when get REQ_EXCEL_REPORT form master 
	{
		enum { MSG_ID = 51 };
		RESPONSE_PRODUCTION_IMAGE_INFO(){nMsgID = MSG_ID;};
	};

	struct REQ_SEL_PD_DEFECT_OBJECT : public MSG_INFO
	{
		enum { MSG_ID = 52 };
		REQ_SEL_PD_DEFECT_OBJECT(){nMsgID = MSG_ID;};
	};

	struct RESPONSE_ALIAS_IMAGE_INFO : public MSG_INFO //slave send RESPONSE_ALIAS_IMAGE_INFO to master when get REQ_EXCEL_REPORT form master 
	{
		enum { MSG_ID = 53 };
		RESPONSE_ALIAS_IMAGE_INFO(){nMsgID = MSG_ID;};
	};
	// ====================================== //
	// .... MsgID .... //
	struct SET_DISPLAY_LENGTHUNIT : public MSG_INFO
	{
		enum { MSG_ID = 70 };
		SET_DISPLAY_LENGTHUNIT(){nMsgID = MSG_ID;};
	};


	// ====================================== //
	// .... MsgID .... //
	struct NDK_MODULES_INFO : public MSG_INFO
	{
		enum { MSG_ID = 100 };
		NDK_MODULES_INFO(){nMsgID = MSG_ID;};
	};


	struct NDK_PJ_MODULES_INFO : public MSG_INFO //SDK QR
	{
		enum { MSG_ID = 101 };
		NDK_PJ_MODULES_INFO(){nMsgID = MSG_ID;};
	};

	struct NDK_O_SLAVE_MODULES_INFO : public MSG_INFO
	{
		enum { MSG_ID = 102 };
		NDK_O_SLAVE_MODULES_INFO(){nMsgID = MSG_ID;};
	};

	struct NDK_O_MODULES_IOCARD_INFO : public MSG_INFO
	{
		enum { MSG_ID = 103 };
		NDK_O_MODULES_IOCARD_INFO(){nMsgID = MSG_ID;};
	};

	struct NDK_O_MODULES_O_PJ_INFO : public MSG_INFO
	{
		enum { MSG_ID = 104 };
		NDK_O_MODULES_O_PJ_INFO(){nMsgID = MSG_ID;};
	};

	
	struct NDK_MODULES_SEL_INFO : public MSG_INFO
	{
		enum { MSG_ID = 105 };
		NDK_MODULES_SEL_INFO(){nMsgID = MSG_ID;};
	};

	// ====================================== //
	// .... MsgID .... //
	struct NDK_SDK_INFO : public MSG_INFO
	{
		enum { MSG_ID = 200 };
		NDK_SDK_INFO(){nMsgID = MSG_ID;};
	};
}



// =============================== //



typedef struct tagAOI_Set_Display_LengthUnit_V1000	:  public SocketStrEvent::SET_DISPLAY_LENGTHUNIT //seanchen 20130826-1
{
	bool bAutoDelete;
	
	int   nSelDispalyUnit;

	// ------ //

	tagAOI_Set_Display_LengthUnit_V1000(bool bAutoRelease = true)
	{
		InitParam();
		bAutoDelete = bAutoRelease;
	}

	~tagAOI_Set_Display_LengthUnit_V1000()
	{
		if(bAutoDelete)
		{Release();}

	}

	void InitParam()
	{
		nSelDispalyUnit = 0;
	}

	void Release()
	{
		InitParam();
	}



}AOI_SET_DISPLAY_LENGTHUNIT_V1000;

typedef struct tagAOI_Set_Display_LengthUnit : public tagAOI_Set_Display_LengthUnit_V1000
{

}
AOI_SET_DISPLAY_LENGTHUNIT;