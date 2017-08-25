// Notification.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Notification.h"
#include "afxdialogex.h"

#include "DlgNewNotify.h"
#include "AquaLib.h"

#include <afxinet.h>
#include <curl/curl.h>
#include <atlsafe.h>
#include <vector>

using namespace std;

extern int currentTabSelected;
extern int g_m_device_count;

extern CComQIPtr<IHTMLDocument2> pDoc;

CString g_device_name;
CString g_trigger;
CString g_trigger_freq;
CString g_alert;
CString g_alert_target;

// CNotification dialog

enum
{
    FUNCTION_ShowMessageBox = 1,
    FUNCTION_GetProcessID = 2,
};

IMPLEMENT_DYNAMIC(CNotification, CDialog)

CNotification::CNotification(CWnd* pParent /*=NULL*/)
	: CDialog(CNotification::IDD, pParent)
{
	m_lst_notificaton.type = 1;
	ImgHeaders = new CImageList;
}

CNotification::~CNotification()
{
	delete ImgHeaders;
}

void CNotification::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Notification, m_lst_notificaton);
	DDX_Control(pDX, IDC_BTN_NewNotify, m_btn_newNotify);
}


BEGIN_MESSAGE_MAP(CNotification, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_NewNotify, &CNotification::OnBnClickedBtnNewnotify)
END_MESSAGE_MAP()


// CNotification message handlers


BOOL CNotification::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	ImgHeaders->Create(16, 16, ILC_MASK, 1, 1);
	ImgHeaders->Add(AfxGetApp()->LoadIcon(IDI_SETTING));
	m_lst_notificaton.SetImageList(ImgHeaders, LVSIL_SMALL);

	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = _T("Device Name");
	m_lst_notificaton.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 0;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Trigger");
	m_lst_notificaton.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 1;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Alarm");
	m_lst_notificaton.InsertColumn(2, &lvColumn);

	// Add some columns to the list control
	//m_lst_notificaton.InsertColumn( 0, _T("Device Name") );
	//m_lst_notificaton.InsertColumn( 1, _T("Trigger") );
	//m_lst_notificaton.InsertColumn( 2, _T("Alarm") );

	// Set the column widths
	m_lst_notificaton.SetColumnWidth( 0, 70 );
	m_lst_notificaton.SetColumnWidth( 1, 70 );
	m_lst_notificaton.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	/*nIndex = m_lst_notificaton.InsertItem(0, _T("Dev2"));
	m_lst_notificaton.SetItemText(nIndex, 1, _T("entersGeo"));
	m_lst_notificaton.SetItemText(nIndex, 2, _T("e-mail"));

	nIndex = m_lst_notificaton.InsertItem(0, _T("Dev4"));
	m_lst_notificaton.SetItemText(nIndex, 1, _T("uploadsData"));
	m_lst_notificaton.SetItemText(nIndex, 2, _T("text"));*/

	m_lst_notificaton.SetBkColor(RGB(255, 255, 255));

	m_brush.CreateSolidBrush(RGB(255, 255, 255));

	m_btn_newNotify.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_newNotify.SetTextColor(RGB(0, 0, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CNotification::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	currentTabSelected = 1;
	// TODO:  Return a different brush if the default is not desired
	if (pDoc == NULL)
		return hbr;

	CComDispatchDriver spScript;
	pDoc->get_Script(&spScript);
	CComVariant var(static_cast<IDispatch*>(this));
	spScript.Invoke1(L"HideGeoControls", &var);

	return hbr;
}


void CNotification::OnBnClickedBtnNewnotify()
{
	// TODO: Add your control notification handler code here
	if (g_m_device_count == 0) {
		MessageBox("You must add a device before creating a notification", "Need Device");
		return;
	}

	CDlgNewNotify dlg;
	dlg.DoModal();

	char* data;
	char ip[32] = "https://data.aquaiot.com";
	char temp[1024] = "";

	double radius = 50.0000;
	double lat = 34.74773453;
	double lng = -124.6547654;

	vector<CComVariant> vecVarsLat;
	vector<CComVariant> vecVarsLng;

	if (dlg.trigger == "insideGeo" && dlg.geo_type == "circle")
	{
		sprintf(temp, "%s\"%f\",\"%f\",\"%f\"%s",
		"{\"reqtype\":\"notif\",\
		\"aquakey\": \"D4ADCC0DA03DAC64\",\
		\"data\": { \"alert\" : \"e-mail\",\
		\"aquaname\": \"myaqua\",\
		\"ntfuuid\": \"abcdefghi-qwerfeqrf-qerf\",\
		\"target\": \"klutchkings@gmail.com\",\
		\"trigger\": \"insideGeo\",\
		\"continuous\": \"true\",\
		\"geotype\": \"circle\",\
		\"geoname\": \"myGeofence\",\
		\"geodata\" : [",
		lat, lng, radius,
		"] }, \"iid\":\"12341234123412341234\"}");

		data = handle_url_fields(ip, temp);
	}

	if (dlg.trigger == "insideGeo" && dlg.geo_type == "polygon")
	{
		sprintf(temp, "%s\"pt1_lat\":%f,\"pt1_lon\":%f,\"pt2_lat\":%f,\"pt2_lon\":%f,\"pt3_lat\":%f,\"pt3_lon\":%f,\"pt4_lat\":%f,\"pt4_lon\":%f,\"pt5_lat\":%f,\"pt5_lon\":%f,\"pt6_lat\":%f,\"pt6_lon\":%f,\"pt7_lat\":%f,\"pt7_lon\":%f,\"pt8_lat\":%f,\"pt8_lon\":%f%s",
		"{\"reqtype\":\"notif\",\
		\"aquakey\": \"D4ADCC0DA03DAC64\",\
		\"data\": { \"alert\" : \"e-mail\",\
		\"aquaname\": \"myaqua\",\
		\"ntfuuid\": \"abcdefghi-qwerfeqrf-qerf\",\
		\"target\": \"klutchkings@gmail.com\",\
		\"trigger\": \"insideGeo\",\
		\"continuous\": \"true\",\
		\"geotype\": \"polygon\",\
		\"geoname\": \"myGeofence\",\
		\"geodata\" : { ",
		vecVarsLat[0].dblVal,
		vecVarsLng[0].dblVal,
		vecVarsLat[1].dblVal,
		vecVarsLng[1].dblVal,
		vecVarsLat[2].dblVal,
		vecVarsLng[2].dblVal,
		vecVarsLat[3].dblVal,
		vecVarsLng[3].dblVal,
		vecVarsLat[4].dblVal,
		vecVarsLng[4].dblVal,
		vecVarsLat[5].dblVal,
		vecVarsLng[5].dblVal,
		vecVarsLat[6].dblVal,
		vecVarsLng[6].dblVal,
		vecVarsLat[7].dblVal,
		vecVarsLng[7].dblVal,
		"} }, \"iid\":\"12341234123412341234\"}"
		);

		data = handle_url_fields("https://data.aquaiot.com",
		temp);
	}

	if (dlg.trigger == "outsideGeo" && dlg.geo_type == "circle")
	{
		sprintf(temp, "%s\"%f\",\"%f\",\"%f\"%s",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"e-mail\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"klutchkings@gmail.com\",\
			\"trigger\" : \"outsideGeo\",\
			\"continuous\" : \"true\",\
			\"geotype\" : \"circle\",\
			\"geoname\" : \"myGeofence\",\
			\"geodata\" : [",
			  lat, lng, radius,
			"]\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}");

		data = handle_url_fields(ip, temp);
	}

	if (dlg.trigger == "outsideGeo" && dlg.geo_type == "polygon")
	{
		sprintf(temp, "%s\"pt1_lat\":%f,\"pt1_lon\":%f,\"pt2_lat\":%f,\"pt2_lon\":%f,\"pt3_lat\":%f,\"pt3_lon\":%f,\"pt4_lat\":%f,\"pt4_lon\":%f,\"pt5_lat\":%f,\"pt5_lon\":%f,\"pt6_lat\":%f,\"pt6_lon\":%f,\"pt7_lat\":%f,\"pt7_lon\":%f,\"pt8_lat\":%f,\"pt8_lon\":%f%s",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"text\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"+12037701412\",\
			\"trigger\" : \"outsideGeo\",\
			\"continuous\" : \"true\",\
			\"geotype\" : \"polygon\",\
			\"geoname\" : \"myGeofence\",\
			\"geodata\" : {",
			  vecVarsLat[0].dblVal,
				vecVarsLng[0].dblVal,
				vecVarsLat[1].dblVal,
				vecVarsLng[1].dblVal,
				vecVarsLat[2].dblVal,
				vecVarsLng[2].dblVal,
				vecVarsLat[3].dblVal,
				vecVarsLng[3].dblVal,
				vecVarsLat[4].dblVal,
				vecVarsLng[4].dblVal,
				vecVarsLat[5].dblVal,
				vecVarsLng[5].dblVal,
				vecVarsLat[6].dblVal,
				vecVarsLng[6].dblVal,
				vecVarsLat[7].dblVal,
				vecVarsLng[7].dblVal,
			"}\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}");

		data = handle_url_fields("https://data.aquaiot.com",
		temp);
	}

	if (dlg.trigger == "lowBattery")
	{
		data = handle_url_fields("https://data.aquaiot.com",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"text\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"+12037701412\",\
			\"trigger\" : \"lowBattery\",\
			\"continuous\" : \"true\"\
		  },\
		  \"iid\":\"1234123412341234\"\
		}"
		);
	}

	if (dlg.trigger == "seesMac")
	{
		data = handle_url_fields("https://data.aquaiot.com",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"e-mail\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"klutchkings@gmail.com\",\
			\"trigger\" : \"seesMac\",\
			\"continuous\" : \"false\",\
			\"macaddress\" : \"AA:BB:CC:DD:EE:FF\"\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"
		);
	}

	if (dlg.trigger == "startsMoving")
	{
		data = handle_url_fields("https://data.aquaiot.com",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"e-mail\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"klutchkings@gmail.com\",\
			\"trigger\" : \"startsMoving\",\
			\"continuous\" : \"false\"\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"\
		);
	}

	if (dlg.trigger == "stopsMoving")
	{
		data = handle_url_fields("https://data.aquaiot.com",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"e-mail\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"klutchkings@gmail.com\",\
			\"trigger\" : \"stopsMoving\",\
			\"continuous\" : \"false\"\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"
		);
	}

	if (dlg.trigger == "uploadsData")
	{
		data = handle_url_fields("https://data.aquaiot.com",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"text\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"+12037701412\",\
			\"trigger\" : \"uploadsData\",\
			\"continuous\" : \"false\"\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"
		);
	}

	nIndex = m_lst_notificaton.InsertItem(0, dlg.m_device);
	m_lst_notificaton.SetItemText(nIndex, 1, dlg.m_trigger);
	m_lst_notificaton.SetItemText(nIndex, 2, dlg.m_alarm);

	g_device_name = dlg.m_device;
	g_trigger = dlg.m_trigger;
	dlg.m_continuous ? g_trigger_freq = "Continuous" : 0;
	dlg.m_onchange ? g_trigger_freq = "On Change" : 0;
	g_alert = dlg.m_alarm;
	dlg.m_phone ? g_alert_target = dlg.m_phone_val : 0;
	dlg.m_email ? g_alert_target = dlg.m_email_val : 0;
}

HRESULT STDMETHODCALLTYPE CNotification::GetTypeInfoCount(UINT *pctinfo)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CNotification::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CNotification::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
    if (cNames != 1)
        return E_NOTIMPL;

    if (wcscmp(rgszNames[0], L"ShowMessageBox") == 0)
    {
        *rgDispId = FUNCTION_ShowMessageBox;
        return S_OK;
    }

    else if (wcscmp(rgszNames[0], L"GetProcessID") == 0)
    {
        *rgDispId = FUNCTION_GetProcessID;
        return S_OK;
    }
    else
        return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CNotification::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
    WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
    if (dispIdMember == FUNCTION_ShowMessageBox)
    {
        if (pDispParams->cArgs != 1)
            return E_NOTIMPL;

        if (pDispParams->rgvarg[0].vt != VT_BSTR)
            return E_NOTIMPL;

        ShowMessageBox(pDispParams->rgvarg[0].bstrVal);
        return S_OK;
    }
    else if (dispIdMember == FUNCTION_GetProcessID)
    {
        DWORD id = GetProcessID();
        *pVarResult = CComVariant(id);
        return S_OK;
    }
    else
        return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CNotification::QueryInterface(REFIID riid, void **ppvObject)
{
    if (riid == IID_IDispatch || riid == IID_IUnknown)
    {
        *ppvObject = static_cast<IDispatch*>(this);
        return S_OK;
    }
    else
        return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE CNotification::AddRef()
{
    return 1;
}

ULONG STDMETHODCALLTYPE CNotification::Release()
{
    return 1;
}

DWORD CNotification::GetProcessID()
{
    return GetCurrentProcessId();
}

void CNotification::ShowMessageBox(const wchar_t *msg)
{
    MessageBox(CW2T(msg), _T("the message come from java script"));
}