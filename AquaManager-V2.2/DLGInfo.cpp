// DLGInfo.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DLGInfo.h"
#include "afxdialogex.h"


// CDLGInfo dialog

IMPLEMENT_DYNAMIC(CDLGInfo, CDialogEx)

CDLGInfo::CDLGInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDLGInfo::IDD, pParent)
{

	m_info = _T("");
}

CDLGInfo::~CDLGInfo()
{
}

void CDLGInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Info, m_info);
}


BEGIN_MESSAGE_MAP(CDLGInfo, CDialogEx)
END_MESSAGE_MAP()


// CDLGInfo message handlers


BOOL CDLGInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_info = "This option will set the notification to only send an alarm\r\n"
			 "when the target Aqua changes from a non-triggered state\r\n"
			 "to triggered one.";

	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
