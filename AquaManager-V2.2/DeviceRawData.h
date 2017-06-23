#pragma once


// CDeviceRawData dialog

class CDeviceRawData : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceRawData)

public:
	CDeviceRawData(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeviceRawData();

// Dialog Data
	enum { IDD = IDD_DLG_Device_RawData };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
