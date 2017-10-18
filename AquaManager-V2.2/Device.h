#pragma once
#include "DeviceListCtrl.h"

#include <string>
#include <list>

using namespace std;

class DeviceData{
public:
	//DeviceData();
	//~DeviceData();
	friend class CDevice;
	friend class CColorListCtrol;

private:
	string aquaid;
	string passcode;
	string pct_battery;
	string temperature;
	string humidity;
	string height;
	string speed;
	string direction;
	string numsat;
	string phone;
	string aquakey;

	double previous_lat;
	double previous_lng;
	double current_lat;
	double current_lng;
	string previous_location;
	string current_location;
	string previous_time;
	string current_time;

	string datetime;
	string uuid;
	string time;
	//string numsat;
	string lon;///////////////
	string lat;
	//string height;
	//string gspeed;
	string accelerometer;
	string pressure;
	string update_rate;
	string incoming_ip;
	string install_id;////////////
	std::list<string> aqsense_data;
	std::list<string> aqsense_data_head;

	int aqsense_count;
	int device_index;
	string device_name;
};

// CDevice dialog

class CDevice : public CDialog, public IDispatch
{
	DECLARE_DYNAMIC(CDevice)

public:
	CDevice(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDevice();

// Dialog Data
	enum { IDD = IDD_DLG_Device };

	friend class CColorListCtrol;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	int device_count;
	std::list<DeviceData *> _device;

public:
	virtual BOOL OnInitDialog();
	CDeviceListCtrl m_lst_device;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int nIndex;
	CImageList *ImgHeaders;
	afx_msg void OnBnClickedBtnAddmarker();
	CMFCButton m_btn_add_device;
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
