// NotificationSettings.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "NotificationSettings.h"
#include "afxdialogex.h"

#include "Device.h"

extern CString g_device_name;
extern CString g_trigger;
extern CString g_trigger_freq;
extern CString g_alert;
extern CString g_alert_target;

// CNotificationSettings dialog

IMPLEMENT_DYNAMIC(CNotificationSettings, CDialogEx)

CNotificationSettings::CNotificationSettings(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotificationSettings::IDD, pParent)
{

	m_alert = _T("");
	m_alert_trigger = _T("");
	m_device_name = _T("");
	m_geofence = _T("");
	m_id = _T("");
	m_trigger = _T("");
	m_trigger_freq = _T("");
	m_trigger_key = _T("");
}

CNotificationSettings::~CNotificationSettings()
{
}

void CNotificationSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Alert, m_alert);
	DDX_Text(pDX, IDC_EDIT_Alert_Trigger, m_alert_trigger);
	DDX_Text(pDX, IDC_EDIT_Device_Name, m_device_name);
	DDX_Text(pDX, IDC_EDIT_Geofence, m_geofence);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_Trigger, m_trigger);
	DDX_Text(pDX, IDC_EDIT_Trigger_Frequency, m_trigger_freq);
	DDX_Text(pDX, IDC_EDIT_Trigger_Key, m_trigger_key);
}


BEGIN_MESSAGE_MAP(CNotificationSettings, CDialogEx)
END_MESSAGE_MAP()


// CNotificationSettings message handlers


BOOL CNotificationSettings::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_device_name = g_device_name;
	m_trigger = g_trigger;
	m_trigger_freq = g_trigger_freq;
	m_alert = g_alert;
	m_alert_trigger = g_alert_target;
	m_trigger_key = ((CDevice*)pdevice)->_device->aquakey.c_str();

	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
