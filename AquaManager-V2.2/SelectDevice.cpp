// SelectDevice.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "SelectDevice.h"
#include "afxdialogex.h"

extern CString g_m_device_name;

int g_m_select_device_notif;
CString g_m_select_device_notif_name;

// CSelectDevice dialog

IMPLEMENT_DYNAMIC(CSelectDevice, CDialogEx)

CSelectDevice::CSelectDevice(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectDevice::IDD, pParent)
{
	count = 0;
}

CSelectDevice::~CSelectDevice()
{
}

void CSelectDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Device, m_device);
}


BEGIN_MESSAGE_MAP(CSelectDevice, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelectDevice::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectDevice message handlers


BOOL CSelectDevice::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_device.SubclassDlgItem(IDD_DLG_SelectDevice, this);
	m_device.SetCheckStyle(BS_AUTOCHECKBOX);

	m_device.InsertString(count++, g_m_device_name);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSelectDevice::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	int iState;

	for (int i = 0; i < count; i++) {
		iState = m_device.GetCheck(i);
		if (iState == 1) {
			g_m_select_device_notif = i;
			m_device.GetText(i, g_m_select_device_notif_name);
			break;
		}
	}

	CDialogEx::OnOK();
}
