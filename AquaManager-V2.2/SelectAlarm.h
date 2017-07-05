#pragma once


// CSelectAlarm dialog

class CSelectAlarm : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectAlarm)

public:
	CSelectAlarm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectAlarm();

// Dialog Data
	enum { IDD = IDD_DLG_SelectAlarm };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CCheckListBox m_alarm;
	virtual BOOL OnInitDialog();

	int count;
	afx_msg void OnBnClickedOk();
};
