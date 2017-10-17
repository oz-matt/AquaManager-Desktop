#pragma once


// CNotificationSettings dialog

class CNotificationSettings : public CDialogEx
{
	DECLARE_DYNAMIC(CNotificationSettings)

public:
	CNotificationSettings(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNotificationSettings();

// Dialog Data
	enum { IDD = IDD_DLG_Notification_Settings };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	void *pdevice;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_alert;
	CString m_alert_trigger;
	CString m_device_name;
	CString m_geofence;
	CString m_id;
	CString m_trigger;
	CString m_trigger_freq;
	CString m_trigger_key;
};
