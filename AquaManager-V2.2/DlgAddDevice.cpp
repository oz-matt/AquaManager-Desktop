// DlgAddDevice.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgAddDevice.h"
#include "afxdialogex.h"

#include "DeviceName.h"

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

	CDeviceName dlg;
	dlg.DoModal();
	this->m_device_name = dlg.m_device_name;
}
