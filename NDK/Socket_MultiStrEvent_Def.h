//#include "Socket_MultiStrEvent_Def.h"

#pragma once
#include "Socket_StrEvent_Def.h"

#ifndef _SOCKET_MULTISETEVENT_DEF_HEADER_
#define _SOCKET_MULTISETEVENT_DEF_HEADER_

typedef struct tagMulti_StrEvent_V1000
{
	bool bAutoDelete;
		
	CArray<CString> csEvent;

	// ------ //

	tagMulti_StrEvent_V1000(bool bAutoRelease = true)
	{
		InitParam();
		bAutoDelete = bAutoRelease;
	}

	~tagMulti_StrEvent_V1000()
	{
		if(bAutoDelete)
		{Release();}

	}

	void InitParam()
	{
	}

	void Release()
	{
		InitParam();
		csEvent.RemoveAll();
	}

}MULTI_STREVENT_V1000;

typedef struct tagMulti_StrEvent : public tagMulti_StrEvent_V1000
{

}
MULTI_STREVENT;


namespace SocketMultiStrEvent		//seanchen 20130710
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
	struct RESPONSE_EXCEL_REPORT_INFO : public MSG_INFO
	{
		enum { MSG_ID = 1 };
		RESPONSE_EXCEL_REPORT_INFO(){nMsgID = MSG_ID;};
	};

	
	
	// ====================================== //
	// .... MsgID .... //
	struct RESPONSE_O_MODULE_O_PJ_INFO : public MSG_INFO
	{
		enum { MSG_ID = 100 };
		RESPONSE_O_MODULE_O_PJ_INFO(){nMsgID = MSG_ID;};
	};


};


// ************************************************************ //
//																//
//																//
//																//
// ************************************************************ //

#define _MAX_COL_CNT_				100
#define _CELL_COL_WIDTH_1			14
#define _CELL_COL_WIDTH_N			10

#define _IMG_CELL_START_XOFFSET_	1
#define _IMG_CELL_START_YOFFSET_	1
#define _IMG_CELL_WIDTH_			3
#define _IMG_CELL_HEIGHT_			13 //excel is 13

#define _IMG_CELL_WIDTH_EXTRA			2
#define _IMG_CELL_HEIGHT_EXTRA_BIG		15 
#define _IMG_CELL_HEIGHT_EXTRA_NOR		9 
#define _WEBIMG_CELL_HEIGHT_EXTRA_NOR	8

#define _GOLD_WEBIMG_CELL_WIDTH_EXTRA			8
#define _GOLD_WEBIMG_CELL_HEIGHT_EXTRA_NOR		12

#define _GOLD_NORIMG_CELL_WIDTH_EXTRA			(10)
#define _GOLD_NORIMG_CELL_HEIGHT_EXTRA_NOR		(14)

//HEAD Text
#define _IMG_HEADINFO_PRE_EMPTY_ROW_	1
#define _IMG_HEADINFO_ROW_	1
#define _IMG_HEADINFO_POST_EMPTY_ROW_	0

//IMG
#define _IMG_CNT_IN_ROW_			4
#define _WEBIMG_CNT_IN_ROW_			3
#define _WEBIMG_CNT_IN_COL_			3
#define _GOLD_WEBIMG_CNT_IN_ROW_	1
#define _GOLD_NORIMG_CNT_IN_ROW_	1
#define _WEBIMG_EMPTY_COL_IN_ROW_	1
#define _WEBIMG_DATA_ROW_			4 //No,Dis,Ret,Area
#define _WEBIMG_DATA_EMPTY_ROW_		1 
#define _WEBIMG_PAGE_EMPTY_ROW_		1

//..
#define  _WEBIMG_REPORT_SHEET_CNT	3 

#define _NoUseImgSheetIdx_	0 
#define _DFImgSheetIdx_		1
#define _GoldImgSheetIdx_	2



//NORMAL Text
#define _IMG_INFO_PRE_EMPTY_ROW_	0
#define _IMG_INFO_ROW_				4
#define _IMG_INFO_POST_EMPTY_ROW_	1

#define _IMG_INFO_TIME_CELLCNT_			2
#define _ALIAS_INFO_ITME_CELLCNT_		2

//COL
#define _IMG_INFO_POST_EMPTY_COL_	1


// ============================= //
#define _WEBIMG_CELL_START_XOFFSET_	0
#define _WEBIMG_CELL_START_YOFFSET_	0
#define _WEBIMG_CELL_PRINT_START_YOFFSET_	(_WEBIMG_CELL_START_YOFFSET_+1)

#define _GOLD_WEBIMG_CELL_START_XOFFSET_	0
#define _GOLD_WEBIMG_CELL_START_YOFFSET_	0
//#define _IMG_CELL_WIDTH_			3
//#define _IMG_CELL_HEIGHT_			13 //excel is 13

#define _GOLD_NORIMG_CELL_START_XOFFSET_	1
#define _GOLD_NORIMG_CELL_START_YOFFSET_	1

// ============================= //
typedef struct tagRESPONSE_EXCEL_REPORT_INFO_V1000 : public SocketMultiStrEvent::RESPONSE_EXCEL_REPORT_INFO
{
	int nUseCmdLine;
	int nNormalRepoerEndRow;	//1 base

	//IMG-1
	int x_nImgStartXOffset;
	int x_nImgStartYOffset;
	int x_nImgCellWidth;
	int x_nImgCellHeight;

	//HEAD Text
	int x_nImgHeadInfo_PreEmptyRow;
	int x_nImgHeadInfo_RowCnt;
	int x_nImgHeadInfo_PostEmptyRow;
	//IMG-2
	int x_nImgCnt_InRow;
	//NORMAL Text
	int x_nImgInfo_PreEmptyRow;
	int x_nImgInfo_RowCnt;
	int x_nImgInfo_PostEmptyRow;
	//
	int x_nImgInfo_PostEmptyCol;


}RESPONSE_EXCEL_REPORT_INFO_V1000;


typedef struct tagRESPONSE_EXCEL_REPORT_INFO : public tagRESPONSE_EXCEL_REPORT_INFO_V1000
{

}
RESPONSE_EXCEL_REPORT_INFO;



#endif //_SOCKET_MULTISETEVENT_DEF_HEADER_