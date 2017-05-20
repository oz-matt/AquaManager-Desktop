// DlgNewNotify.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgNewNotify.h"
#include "afxdialogex.h"


// CDlgNewNotify dialog

IMPLEMENT_DYNAMIC(CDlgNewNotify, CDialogEx)

CDlgNewNotify::CDlgNewNotify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNewNotify::IDD, pParent)
{

}

CDlgNewNotify::~CDlgNewNotify()
{
}

void CDlgNewNotify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNewNotify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgNewNotify::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgNewNotify message handlers


void CDlgNewNotify::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
