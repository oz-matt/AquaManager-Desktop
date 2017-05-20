#pragma once


// CDlgConfigureDevice dialog

class CDlgConfigureDevice : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgConfigureDevice)

public:
	CDlgConfigureDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgConfigureDevice();

// Dialog Data
	enum { IDD = IDD_DLG_ConfigureDevice };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
