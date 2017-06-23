// DeviceRemove.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceRemove.h"
#include "afxdialogex.h"


// CDeviceRemove dialog

IMPLEMENT_DYNAMIC(CDeviceRemove, CDialogEx)

CDeviceRemove::CDeviceRemove(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceRemove::IDD, pParent)
{

	m_remove = _T("");
}

CDeviceRemove::~CDeviceRemove()
{
}

void CDeviceRemove::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Remove, m_remove);
}


BEGIN_MESSAGE_MAP(CDeviceRemove, CDialogEx)
END_MESSAGE_MAP()


// CDeviceRemove message handlers


BOOL CDeviceRemove::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_remove = "Are you sure you want to remove this entry,\r\n along with all associated notifications?";
	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
