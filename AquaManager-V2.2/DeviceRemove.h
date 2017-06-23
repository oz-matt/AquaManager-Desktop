#pragma once


// CDeviceRemove dialog

class CDeviceRemove : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceRemove)

public:
	CDeviceRemove(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeviceRemove();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DLG_Device_Remove };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_remove;
};
