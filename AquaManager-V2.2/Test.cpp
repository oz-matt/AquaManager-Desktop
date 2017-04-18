// Test.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Test.h"
#include "afxdialogex.h"


extern CComQIPtr<IHTMLDocument2> pDoc;

// CTest dialog

IMPLEMENT_DYNAMIC(CTest, CDialogEx)

CTest::CTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest::IDD, pParent)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTest, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SetCenter, &CTest::OnBnClickedBtnSetcenter)
	ON_BN_CLICKED(IDC_BTN_AddMarker, &CTest::OnBnClickedBtnAddmarker)
	ON_BN_CLICKED(IDC_BTN_SetZoom, &CTest::OnBnClickedBtnSetzoom)
	ON_BN_CLICKED(IDC_BTN_DeleteMarkers, &CTest::OnBnClickedBtnDeletemarkers)
END_MESSAGE_MAP()


// CTest message handlers


void CTest::OnBnClickedBtnSetcenter()
{
	// TODO: Add your control notification handler code here
	CString js;
	float x = 45.378802;
	float y = -72.242796;
	js.Format(_T("SetCenter(%.2f, %.2f, %d);"), x, y, 15);

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnAddmarker()
{
	// TODO: Add your control notification handler code here
	CString js;
	float x = 45.378802;
	float y = -72.242796;
	js.Format(_T("AddMarker(%.2f, %.2f);"), x, y);

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnSetzoom()
{
	// TODO: Add your control notification handler code here
	CString js;
	int type = 15;
	js.Format(_T("SetZoom(%d);"), type);

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnDeletemarkers()
{
	// TODO: Add your control notification handler code here
	CString js;
	int type = 15;
	js.Format(_T("deleteMarkers();"));

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}
