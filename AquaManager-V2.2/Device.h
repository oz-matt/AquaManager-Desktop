#pragma once
#include "ColorListCtrol.h"

#include<string>

using namespace std;

typedef struct {
	string g_m_aquaid;
	string g_m_passcode;
	string g_m_pct_battery;
	string g_m_temperature;
	string g_m_humidity;
	string g_m_height;
	string g_m_speed;
	string g_m_direction;
	string g_m_numsat;
	string g_m_phone;
	string g_m_aquakey;

	double g_m_previous_lat;
	double g_m_previous_lng;
	double g_m_current_lat;
	double g_m_current_lng;
	string g_m_previous_location;
	string g_m_current_location;
	string g_m_previous_time;
	string g_m_current_time;

	string g_m_datetime;
	string g_m_uuid;
	string g_m_time;
	//string g_m_numsat;
	string g_m_lon;///////////////
	string g_m_lat;
	//string g_m_height;
	//string g_m_gspeed;
	string g_m_accelerometer;
	string g_m_pressure;
	string g_m_update_rate;
	string g_m_incoming_ip;
	string g_m_install_id;////////////
	string g_m_aqsense_data[10];
	string g_m_aqsense_data_head[10];

	int g_m_aqsense_count;
	int g_m_device_count;
} _DeviceData;

struct __Device {
	_DeviceData &data;
	__Device &next;
};

typedef struct __Device _Device;

// CDevice dialog

class CDevice : public CDialog, public IDispatch
{
	DECLARE_DYNAMIC(CDevice)

public:
	CDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDevice();

// Dialog Data
	enum { IDD = IDD_DLG_Device };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CColorListCtrol m_lst_device;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int nIndex;
	CImageList *ImgHeaders;
	afx_msg void OnLvnItemchangedLstDevice(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnAddmarker();
	CMFCButton m_btn_add_device;
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNMRClickLstDevice(NMHDR *pNMHDR, LRESULT *pResult);
	void AddMarker(double lat, double lng);
	void AddRawData(CString datetime, CString uuid, CString time, CString numsat, CString lon, CString lat,
	CString height, CString gspeed, CString direction, CString pct_battery, CString accelerometer, 
	CString temperature, CString humidity, CString pressure, CString update_rate, CString incoming_ip,
	CString install_id);
	void AddRawDataStr(CString str);
	void Setcenter(float x, float y);

	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo);
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
	virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
		WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();

	DWORD GetProcessID();
	void ShowMessageBox(const wchar_t *msg);
};
