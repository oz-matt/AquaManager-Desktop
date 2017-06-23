#pragma once


// CNotificationRemove dialog

class CNotificationRemove : public CDialogEx
{
	DECLARE_DYNAMIC(CNotificationRemove)

public:
	CNotificationRemove(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNotificationRemove();

// Dialog Data
	enum { IDD = IDD_DLG_Notification_Remove };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_remove;
};
