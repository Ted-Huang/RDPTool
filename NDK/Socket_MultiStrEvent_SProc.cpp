#include "StdAfx.h"
#include "Socket_MultiStrEvent_SProc.h"

CExcelReportProc::CExcelReportProc(void)
{
}

CExcelReportProc::~CExcelReportProc(void)
{
}

void CExcelReportProc::InitParam(RESPONSE_EXCEL_REPORT_INFO* pDes)
{
	if(!pDes)
		return;

	pDes->nUseCmdLine = 1;
	pDes->nNormalRepoerEndRow = 1;

	// ====== Image Relative ====== //
	pDes->x_nImgStartXOffset =_IMG_CELL_START_XOFFSET_ ;
	pDes->x_nImgStartYOffset = _IMG_CELL_START_YOFFSET_;
	pDes->x_nImgCellWidth = _IMG_CELL_WIDTH_;
	pDes->x_nImgCellHeight = _IMG_CELL_HEIGHT_;
	
	//HEAD Text
	pDes->x_nImgHeadInfo_PreEmptyRow = _IMG_HEADINFO_PRE_EMPTY_ROW_;
	pDes->x_nImgHeadInfo_RowCnt = _IMG_HEADINFO_ROW_;
	pDes->x_nImgHeadInfo_PostEmptyRow = _IMG_HEADINFO_POST_EMPTY_ROW_;
	
	//IMG
	pDes->x_nImgCnt_InRow = _IMG_CNT_IN_ROW_;

	//NORMAL Text
	pDes->x_nImgInfo_PreEmptyRow = _IMG_INFO_PRE_EMPTY_ROW_;
	pDes->x_nImgInfo_RowCnt = _IMG_INFO_ROW_;
	pDes->x_nImgInfo_PostEmptyRow = _IMG_INFO_POST_EMPTY_ROW_;

	//..
	pDes->x_nImgInfo_PostEmptyCol = _IMG_INFO_POST_EMPTY_COL_;
}


void CExcelReportProc::InitAliasNoImageParam(RESPONSE_EXCEL_REPORT_INFO* pDes,BOOL bNoImagePartOnly)
{
	if(!pDes)
		return;

	if(!bNoImagePartOnly)
	{
		pDes->nUseCmdLine = 1;
		pDes->nNormalRepoerEndRow = 1;

		// ====== Image Relative ====== //
		pDes->x_nImgStartXOffset =_IMG_CELL_START_XOFFSET_ ;
		pDes->x_nImgStartYOffset = _IMG_CELL_START_YOFFSET_;
	}
	pDes->x_nImgCellWidth = _IMG_CELL_WIDTH_;
	pDes->x_nImgCellHeight = 0;
	
	//HEAD Text
	pDes->x_nImgHeadInfo_PreEmptyRow = 0;
	pDes->x_nImgHeadInfo_RowCnt = 0;
	pDes->x_nImgHeadInfo_PostEmptyRow = 0;
	
	//IMG
	pDes->x_nImgCnt_InRow = _IMG_CNT_IN_ROW_;

	//NORMAL Text
	pDes->x_nImgInfo_PreEmptyRow = 0;
	pDes->x_nImgInfo_RowCnt = 3;
	pDes->x_nImgInfo_PostEmptyRow = 0;

	//..
	pDes->x_nImgInfo_PostEmptyCol = _IMG_INFO_POST_EMPTY_COL_;
}

void CExcelReportProc::InitAliasImageParam(RESPONSE_EXCEL_REPORT_INFO* pDes)
{
	if(!pDes)
		return;

	pDes->nUseCmdLine = 1;
	pDes->nNormalRepoerEndRow = 1;

	// ====== Image Relative ====== //
	pDes->x_nImgStartXOffset =_IMG_CELL_START_XOFFSET_ ;
	pDes->x_nImgStartYOffset = _IMG_CELL_START_YOFFSET_;
	pDes->x_nImgCellWidth = _IMG_CELL_WIDTH_;
	pDes->x_nImgCellHeight = _IMG_CELL_HEIGHT_;
	
	//HEAD Text
	pDes->x_nImgHeadInfo_PreEmptyRow = _IMG_HEADINFO_PRE_EMPTY_ROW_;
	pDes->x_nImgHeadInfo_RowCnt = _IMG_HEADINFO_ROW_;
	pDes->x_nImgHeadInfo_PostEmptyRow = _IMG_HEADINFO_POST_EMPTY_ROW_;
	
	//IMG
	pDes->x_nImgCnt_InRow = _IMG_CNT_IN_ROW_;

	//NORMAL Text
	pDes->x_nImgInfo_PreEmptyRow = _IMG_INFO_PRE_EMPTY_ROW_;
	pDes->x_nImgInfo_RowCnt = _IMG_INFO_ROW_;
	pDes->x_nImgInfo_PostEmptyRow = _IMG_INFO_POST_EMPTY_ROW_;

	//..
	pDes->x_nImgInfo_PostEmptyCol = _IMG_INFO_POST_EMPTY_COL_;
}



void CExcelReportProc::InitSGoldImageParam(RESPONSE_EXCEL_REPORT_INFO* pDes)
{
	if(!pDes)
		return;

	pDes->nUseCmdLine = 1;
	pDes->nNormalRepoerEndRow = 1;

	// ====== Image Relative ====== //
	pDes->x_nImgStartXOffset =_GOLD_NORIMG_CELL_START_XOFFSET_ ;
	pDes->x_nImgStartYOffset = _GOLD_NORIMG_CELL_START_YOFFSET_;
	pDes->x_nImgCellWidth = _GOLD_NORIMG_CELL_WIDTH_EXTRA;
	pDes->x_nImgCellHeight = _GOLD_NORIMG_CELL_HEIGHT_EXTRA_NOR;
	
	//HEAD Text
	pDes->x_nImgHeadInfo_PreEmptyRow = 0;
	pDes->x_nImgHeadInfo_RowCnt = 0;
	pDes->x_nImgHeadInfo_PostEmptyRow = 0;
	
	//IMG
	pDes->x_nImgCnt_InRow = _GOLD_NORIMG_CNT_IN_ROW_;

	//NORMAL Text
	pDes->x_nImgInfo_PreEmptyRow = 0;
	pDes->x_nImgInfo_RowCnt = 1;
	pDes->x_nImgInfo_PostEmptyRow = 0;

	//..
	pDes->x_nImgInfo_PostEmptyCol = _IMG_INFO_POST_EMPTY_COL_;



}

void CExcelReportProc::Release(RESPONSE_EXCEL_REPORT_INFO* pDes)
{
	if(!pDes)
		return;
}

void CExcelReportProc::AssignParam(RESPONSE_EXCEL_REPORT_INFO* pDes ,RESPONSE_EXCEL_REPORT_INFO *pData)
{
	if((!pDes)||(!pData))
		return;

	pDes->nUseCmdLine = pData->nUseCmdLine;
	pDes->nNormalRepoerEndRow = pData->nNormalRepoerEndRow;

	// ====== Image Relative ====== //
	pDes->x_nImgStartXOffset = pData->x_nImgStartXOffset ;
	pDes->x_nImgStartYOffset = pData->x_nImgStartYOffset;
	pDes->x_nImgCellWidth = pData->x_nImgCellWidth;
	pDes->x_nImgCellHeight = pData->x_nImgCellHeight;
	
	//HEAD Text
	pDes->x_nImgHeadInfo_PreEmptyRow = pData->x_nImgHeadInfo_PreEmptyRow;
	pDes->x_nImgHeadInfo_RowCnt = pData->x_nImgHeadInfo_RowCnt;
	pDes->x_nImgHeadInfo_PostEmptyRow = pData->x_nImgHeadInfo_PostEmptyRow;
	
	//IMG
	pDes->x_nImgCnt_InRow = pData->x_nImgCnt_InRow;

	//NORMAL Text
	pDes->x_nImgInfo_PreEmptyRow = pData->x_nImgInfo_PreEmptyRow;
	pDes->x_nImgInfo_RowCnt = pData->x_nImgInfo_RowCnt;
	pDes->x_nImgInfo_PostEmptyRow = pData->x_nImgInfo_PostEmptyRow;

	//..
	pDes->x_nImgInfo_PostEmptyCol = pData->x_nImgInfo_PostEmptyCol;

}

void CExcelReportProc::AssignParam(RESPONSE_EXCEL_REPORT_INFO& sDes,RESPONSE_EXCEL_REPORT_INFO& sData)	
{ 
	AssignParam(&sDes, &sData );
}

