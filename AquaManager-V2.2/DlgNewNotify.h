#pragma once

#include<string>
using namespace std;
// CDlgNewNotify dialog

class CDlgNewNotify : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNewNotify)

public:
	CDlgNewNotify(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgNewNotify();

// Dialog Data
	enum { IDD = IDD_DLG_NewNotify };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	string trigger;
	string geo_type;
	string geo_data;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnDeviceselect();
	CString m_device;
	CString m_trigger;
	afx_msg void OnBnClickedBtnTriggerselect();
	afx_msg void OnBnClickedBtnAlarmselect();
	CString m_alarm;
	afx_msg void OnBnClickedBtnOnchangeInfo();
	BOOL m_continuous;
//	CButton m_onchange;
	CString m_tip;
	BOOL m_onchange;
	afx_msg void OnBnClickedCheckContinuous();
	afx_msg void OnBnClickedCheckOnchange();

	BOOL m_phone;
	BOOL m_email;
	CString m_phone_val;
	CString m_email_val;
	CString mac_address;
};
