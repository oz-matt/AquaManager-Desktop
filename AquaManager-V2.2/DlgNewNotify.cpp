// DlgNewNotify.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgNewNotify.h"
#include "afxdialogex.h"

#include "SelectDevice.h"

extern int g_m_select_device_notif;
extern CString g_m_select_device_notif_name;

// CDlgNewNotify dialog

IMPLEMENT_DYNAMIC(CDlgNewNotify, CDialogEx)

CDlgNewNotify::CDlgNewNotify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNewNotify::IDD, pParent)
{

	m_device = _T("");
}

CDlgNewNotify::~CDlgNewNotify()
{
}

void CDlgNewNotify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Device, m_device);
}


BEGIN_MESSAGE_MAP(CDlgNewNotify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgNewNotify::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Btn_DeviceSelect, &CDlgNewNotify::OnBnClickedBtnDeviceselect)
END_MESSAGE_MAP()


// CDlgNewNotify message handlers


void CDlgNewNotify::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


BOOL CDlgNewNotify::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgNewNotify::OnBnClickedBtnDeviceselect()
{
	// TODO: Add your control notification handler code here
	CSelectDevice dlg;
	dlg.DoModal();

	m_device = g_m_select_device_notif_name;
	UpdateData(False);
}
