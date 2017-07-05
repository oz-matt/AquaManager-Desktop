// DlgNewNotify.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgNewNotify.h"
#include "afxdialogex.h"

#include "SelectDevice.h"
#include "SelectTrigger.h"
#include "SelectAlarm.h"
#include "EamilTarget.h"
#include "PhoneTarget.h"
#include "DLGInfo.h"
#include "DlgNoGeofence.h"
#include "DlgMacAddress.h"

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
	m_tip = _T("");

	m_phone = False;
	m_email = False;
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
	DDX_Check(pDX, IDC_CHECK_Continuous, m_continuous);
	//  DDX_Control(pDX, IDC_CHECK_OnChange, m_onchange);
	DDX_Text(pDX, IDC_EDIT_Tip, m_tip);
	DDX_Check(pDX, IDC_CHECK_OnChange, m_onchange);
}


BEGIN_MESSAGE_MAP(CDlgNewNotify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgNewNotify::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Btn_DeviceSelect, &CDlgNewNotify::OnBnClickedBtnDeviceselect)
	ON_BN_CLICKED(IDC_Btn_TriggerSelect, &CDlgNewNotify::OnBnClickedBtnTriggerselect)
	ON_BN_CLICKED(IDC_Btn_AlarmSelect, &CDlgNewNotify::OnBnClickedBtnAlarmselect)
	ON_BN_CLICKED(IDC_Btn_OnChange_Info, &CDlgNewNotify::OnBnClickedBtnOnchangeInfo)
	ON_BN_CLICKED(IDC_CHECK_Continuous, &CDlgNewNotify::OnBnClickedCheckContinuous)
	ON_BN_CLICKED(IDC_CHECK_OnChange, &CDlgNewNotify::OnBnClickedCheckOnchange)
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

	if (m_phone == True) {
		m_tip = "Whenever " + m_device + " " + m_trigger + ", send " + m_phone_val + " a text";
	}
	else if (m_email == True) {
		m_tip = "Whenever " + m_device + " " + m_trigger + ", send " + m_email_val + " an e-mail";
	}
	UpdateData(False);
}


void CDlgNewNotify::OnBnClickedBtnTriggerselect()
{
	// TODO: Add your control notification handler code here
	CSelectTrigger dlg;
	dlg.DoModal();

	m_trigger = g_m_select_trigger_notif_name;

	if (m_trigger == "Enters Geofence" || m_trigger == "Exits Geofence") {
		CDlgNoGeofence dlg;
		dlg.DoModal();
		return;
	}

	if (m_trigger == "Sees Mac Address") {
		CDlgMacAddress dlg;
		dlg.DoModal();
		mac_address = dlg.mac_addr;
	}

	if (m_phone == True) {
		m_tip = "Whenever " + m_device + " " +  m_trigger + ", send " + m_phone_val + " a text";
	}
	else if (m_email == True) {
		m_tip = "Whenever " + m_device + " " + m_trigger + ", send " + m_email_val + " an e-mail";
	}
	UpdateData(False);
}


void CDlgNewNotify::OnBnClickedBtnAlarmselect()
{
	// TODO: Add your control notification handler code here
	CSelectAlarm dlg;
	dlg.DoModal();

	m_alarm = g_m_select_alarm_notif_name;
	if (m_alarm == "E-Mail") {
		CEamilTarget dlg;
		dlg.DoModal();
		m_email_val = dlg.m_email;
		m_email = True;
		m_phone = False;
	}
	if (m_alarm == "Text Message") {
		CPhoneTarget dlg;
		dlg.DoModal();
		m_phone_val = dlg.m_phone;
		m_phone = True;
		m_email = False;
	}

	if (m_phone == True) {
		m_tip = "Whenever " + m_device + " " + m_trigger + ", send " + m_phone_val + " a text.";
	}
	else if (m_email == True) {
		m_tip = "Whenever " + m_device + " " + m_trigger + ", send " + m_email_val + " an e-mail.";
	}
	UpdateData(False);
}


void CDlgNewNotify::OnBnClickedBtnOnchangeInfo()
{
	// TODO: Add your control notification handler code here
	CDLGInfo dlg;
	dlg.DoModal();
}


void CDlgNewNotify::OnBnClickedCheckContinuous()
{
	// TODO: Add your control notification handler code here
}


void CDlgNewNotify::OnBnClickedCheckOnchange()
{
	// TODO: Add your control notification handler code here
}
