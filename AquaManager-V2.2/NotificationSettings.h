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

	DECLARE_MESSAGE_MAP()
};
