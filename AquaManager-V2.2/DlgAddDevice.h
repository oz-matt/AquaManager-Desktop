#pragma once


// CDlgAddDevice dialog

class CDlgAddDevice : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddDevice)

public:
	CDlgAddDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAddDevice();

// Dialog Data
	enum { IDD = IDD_DLG_AddDevice };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_aquaid;
	CString m_passcode;
	CString m_device_name;
	virtual BOOL OnInitDialog();
};
