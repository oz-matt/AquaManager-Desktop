// NotificationRemove.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "NotificationRemove.h"
#include "afxdialogex.h"


// CNotificationRemove dialog

IMPLEMENT_DYNAMIC(CNotificationRemove, CDialogEx)

CNotificationRemove::CNotificationRemove(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotificationRemove::IDD, pParent)
{

	m_remove = _T("");
}

CNotificationRemove::~CNotificationRemove()
{
}

void CNotificationRemove::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Remove, m_remove);
}


BEGIN_MESSAGE_MAP(CNotificationRemove, CDialogEx)
END_MESSAGE_MAP()


// CNotificationRemove message handlers


BOOL CNotificationRemove::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_remove = "Are you sure you want to remove this notification?";
	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
