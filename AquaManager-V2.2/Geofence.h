#pragma once
#include "ColorListCtrol.h"

// CGeofence dialog

class CGeofence : public CDialog, public IDispatch
{
	DECLARE_DYNAMIC(CGeofence)

public:
	CGeofence(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGeofence();

// Dialog Data
	enum { IDD = IDD_DLG_Geofence };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CColorListCtrol m_lst_geofence;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int nIndex;
	CImageList *ImgHeaders;
	afx_msg void OnBnClickedBtnGeofence();
	CMFCButton m_btn_geofence;
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnCancel();
	CString m_geo_name;
	CMFCButton m_btn_save;
	CMFCButton m_btn_cancel;
	void draw_circle(double radius);
	void draw_polygon(double side);
	double m_radius;
	void get_center(double * lat, double * lng);
	BOOL m_circle;
	BOOL m_polygon;
	void getPolygonLat1(double * lat);
	void getPolygonLat2(double * lat);
	void getPolygonLat3(double * lat);
	void getPolygonLat4(double * lat);
	void getPolygonLng1(double * lng);
	void getPolygonLng2(double * lng);
	void getPolygonLng3(double * lng);
	void getPolygonLng4(double * lng);

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

	void SaveGeoObject();
};
