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
public:
	CListBox m_raw_data;
	CString m_raw_data_val;
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLbnDblclkListRawdata();
};
