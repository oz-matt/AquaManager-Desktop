#pragma once
#include "ColorListCtrol.h"

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
	virtual HRESULT STDMETHODCALLTYPE CDevice::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
		WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();

	DWORD GetProcessID();
	void ShowMessageBox(const wchar_t *msg);
};
