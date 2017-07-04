#pragma once


// CDeviceRawDataShow dialog

class CDeviceRawDataShow : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceRawDataShow)

public:
	CDeviceRawDataShow(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeviceRawDataShow();

// Dialog Data
	enum { IDD = IDD_DLG_Device_RawDataShow };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_raw_data_show;
	virtual BOOL OnInitDialog();
};
