#pragma once


// CDeviceSettings dialog

class CDeviceSettings : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceSettings)

public:
	CDeviceSettings(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeviceSettings();

// Dialog Data
	enum { IDD = IDD_DLG_DeviceSetting };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
