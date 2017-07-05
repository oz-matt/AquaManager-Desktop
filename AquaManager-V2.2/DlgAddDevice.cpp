// DlgAddDevice.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgAddDevice.h"
#include "afxdialogex.h"

#include "DeviceName.h"

CString g_m_device_name;

// CDlgAddDevice dialog

IMPLEMENT_DYNAMIC(CDlgAddDevice, CDialogEx)

CDlgAddDevice::CDlgAddDevice(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddDevice::IDD, pParent)
{

	m_aquaid = _T("");
	m_passcode = _T("");
}

CDlgAddDevice::~CDlgAddDevice()
{
}

void CDlgAddDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AquaID, m_aquaid);
	DDX_Text(pDX, IDC_EDIT_PassCode, m_passcode);
}


BEGIN_MESSAGE_MAP(CDlgAddDevice, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgAddDevice::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddDevice message handlers


void CDlgAddDevice::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


BOOL CDlgAddDevice::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_aquaid = "8DC8B056";
	m_passcode = "849DEEE4";

	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
