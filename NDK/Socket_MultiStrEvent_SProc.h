//#include "Socket_MultiStrEvent_SProc.h"
#pragma once

#include "Socket_MultiStrEvent_Def.h"

class CExcelReportProc
{
public:
	CExcelReportProc(void);
	~CExcelReportProc(void);

	static void InitParam(RESPONSE_EXCEL_REPORT_INFO* pDes);
	static void InitAliasNoImageParam(RESPONSE_EXCEL_REPORT_INFO* pDes,BOOL bNoImagePartOnly);
	static void InitAliasImageParam(RESPONSE_EXCEL_REPORT_INFO* pDes);
	static void InitSGoldImageParam(RESPONSE_EXCEL_REPORT_INFO* pDes);
	static void Release(RESPONSE_EXCEL_REPORT_INFO* pDes);
	static void AssignParam(RESPONSE_EXCEL_REPORT_INFO* pDes ,RESPONSE_EXCEL_REPORT_INFO *pData);
	static void AssignParam(RESPONSE_EXCEL_REPORT_INFO& sDes,RESPONSE_EXCEL_REPORT_INFO& sData);

};
