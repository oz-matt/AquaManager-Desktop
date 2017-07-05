// DlgNewNotify.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgNewNotify.h"
#include "afxdialogex.h"

#include "SelectDevice.h"
#include "SelectTrigger.h"
#include "SelectAlarm.h"

extern int g_m_select_device_notif;
extern CString g_m_select_device_notif_name;
extern CString g_m_select_trigger_notif_name;
extern CString g_m_select_alarm_notif_name;

// CDlgNewNotify dialog

IMPLEMENT_DYNAMIC(CDlgNewNotify, CDialogEx)

CDlgNewNotify::CDlgNewNotify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNewNotify::IDD, pParent)
{

	m_device = _T("");
	m_trigger = _T("");
	m_alarm = _T("");
}

CDlgNewNotify::~CDlgNewNotify()
{
}

void CDlgNewNotify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Device, m_device);
	DDX_Text(pDX, IDC_EDIT_Trigger, m_trigger);
	DDX_Text(pDX, IDC_EDIT_Alarm, m_alarm);
}


BEGIN_MESSAGE_MAP(CDlgNewNotify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgNewNotify::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Btn_DeviceSelect, &CDlgNewNotify::OnBnClickedBtnDeviceselect)
	ON_BN_CLICKED(IDC_Btn_TriggerSelect, &CDlgNewNotify::OnBnClickedBtnTriggerselect)
	ON_BN_CLICKED(IDC_Btn_AlarmSelect, &CDlgNewNotify::OnBnClickedBtnAlarmselect)
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


void CDlgNewNotify::OnBnClickedBtnTriggerselect()
{
	// TODO: Add your control notification handler code here
	CSelectTrigger dlg;
	dlg.DoModal();

	m_trigger = g_m_select_trigger_notif_name;
	UpdateData(False);
}


void CDlgNewNotify::OnBnClickedBtnAlarmselect()
{
	// TODO: Add your control notification handler code here
	CSelectAlarm dlg;
	dlg.DoModal();

	m_alarm = g_m_select_alarm_notif_name;
	UpdateData(False);
}
