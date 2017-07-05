#pragma once


// CSelectDevice dialog

class CSelectDevice : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectDevice)

public:
	CSelectDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectDevice();

// Dialog Data
	enum { IDD = IDD_DLG_SelectDevice };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CCheckListBox m_device;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

	int count;
};
