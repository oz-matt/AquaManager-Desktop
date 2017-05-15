#pragma once
#include <afxinet.h>
#include <curl/curl.h>
#include <atlsafe.h>
#include <vector>

using namespace std;

// CTest dialog

class CTest : public CDialogEx
{
	DECLARE_DYNAMIC(CTest)

public:
	CTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTest();

// Dialog Data
	enum { IDD = IDD_DLG_Test };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSetcenter();
	afx_msg void OnBnClickedBtnAddmarker();
	afx_msg void OnBnClickedBtnSetzoom();
	afx_msg void OnBnClickedBtnDeletemarkers();
	afx_msg void OnBnClickedBtnAuth();
	char * handle_url_fields(char * url, char * fields);
	afx_msg void OnBnClickedBtnGetaqsens();
	afx_msg void OnBnClickedBtnNotifcircle();
	afx_msg void OnBnClickedBtnNotifpolygon();
	afx_msg void OnBnClickedBtnNotiflowbat();
	afx_msg void OnBnClickedBtnNotifoutcircle();
	afx_msg void OnBnClickedBtnNotifoutpolygon();
	afx_msg void OnBnClickedBtnNotifseemac();
	afx_msg void OnBnClickedBtnNotifstartmov();
	afx_msg void OnBnClickedBtnNotifstopmov();
	afx_msg void OnBnClickedBtnNotifuploaddata();
	afx_msg void OnBnClickedBtnRemovenotif();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	CBrush m_brush;
	CMFCButton m_btn_setCenter;
	CMFCButton m_btn_addMarker;
	CMFCButton m_btn_auth;
	CMFCButton m_btn_deleteMarkers;
	CMFCButton m_btn_getAqsens;
	CMFCButton m_btn_notifCircle;
	CMFCButton m_btn_notifLowBat;
	CMFCButton m_btn_notifOutCircle;
	CMFCButton m_btn_notifOutPolygon;
	CMFCButton m_btn_notifPolygon;
	CMFCButton m_btn_notifSeeMac;
	CMFCButton m_notifStartMov;
	CMFCButton m_notifStopMov;
	CMFCButton m_notifUploadData;
	CMFCButton m_btn_removeNotif;
	CMFCButton m_btn_setZoom;
	double get_circle(double *lat, double *lng);
	void set_circle(double lat, double lng, double radius);
	int get_polygon(vector<CComVariant> &vecVarsLat, vector<CComVariant> &vecVarsLng);
};
