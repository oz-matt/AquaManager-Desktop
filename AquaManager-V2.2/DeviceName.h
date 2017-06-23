#pragma once


// CDeviceName dialog

class CDeviceName : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceName)

public:
	CDeviceName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeviceName();

// Dialog Data
	enum { IDD = IDD_DLG_DeviceName };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_device_name;
};
