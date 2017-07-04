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
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString m_name;
	CString m_pct_battery;
	CString m_marker_color_val;
	CComboBox m_marker_color_ctl;
	afx_msg void OnCbnSelchangeComboMarkercolor();
	CString m_temperature;
	CString m_humidity;
	CString m_height;
	CString m_speed;
	CString m_direction;
	CString m_numsat;
	CString m_phone;
	CString m_aquaid;
//	CString m_passcode;
	CString m_aquakey;
	CString m_previous_location;
	CString m_previous_time;
	CString m_current_location;
	CString m_current_time;
};
