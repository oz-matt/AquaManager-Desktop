// Test.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Test.h"
#include "afxdialogex.h"

#include "AquaLib.h"

#include <afxinet.h>
#include <curl/curl.h>
#include <atlsafe.h>
#include <vector>

using namespace std;

extern CComQIPtr<IHTMLDocument2> pDoc;

// CTest dialog

IMPLEMENT_DYNAMIC(CTest, CDialogEx)

CTest::CTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTest::IDD, pParent)
{

}

CTest::~CTest()
{
}

void CTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_SetCenter, m_btn_setCenter);
	DDX_Control(pDX, IDC_BTN_AddMarker, m_btn_addMarker);
	DDX_Control(pDX, IDC_BTN_Auth, m_btn_auth);
	DDX_Control(pDX, IDC_BTN_DeleteMarkers, m_btn_deleteMarkers);
	DDX_Control(pDX, IDC_BTN_Getaqsens, m_btn_getAqsens);
	DDX_Control(pDX, IDC_BTN_NotifCircle, m_btn_notifCircle);
	DDX_Control(pDX, IDC_BTN_NotifLowBat, m_btn_notifLowBat);
	DDX_Control(pDX, IDC_BTN_NotifOutCircle, m_btn_notifOutCircle);
	DDX_Control(pDX, IDC_BTN_NotifOutPolygon, m_btn_notifOutPolygon);
	DDX_Control(pDX, IDC_BTN_NotifPolygon, m_btn_notifPolygon);
	DDX_Control(pDX, IDC_BTN_NotifSeeMac, m_btn_notifSeeMac);
	DDX_Control(pDX, IDC_BTN_NotifStartMov, m_notifStartMov);
	DDX_Control(pDX, IDC_BTN_NotifStopMov, m_notifStopMov);
	DDX_Control(pDX, IDC_BTN_NotifUploadData, m_notifUploadData);
	DDX_Control(pDX, IDC_BTN_RemoveNotif, m_btn_removeNotif);
	DDX_Control(pDX, IDC_BTN_SetZoom, m_btn_setZoom);
}


BEGIN_MESSAGE_MAP(CTest, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SetCenter, &CTest::OnBnClickedBtnSetcenter)
	ON_BN_CLICKED(IDC_BTN_AddMarker, &CTest::OnBnClickedBtnAddmarker)
	ON_BN_CLICKED(IDC_BTN_SetZoom, &CTest::OnBnClickedBtnSetzoom)
	ON_BN_CLICKED(IDC_BTN_DeleteMarkers, &CTest::OnBnClickedBtnDeletemarkers)
	ON_BN_CLICKED(IDC_BTN_Auth, &CTest::OnBnClickedBtnAuth)
	ON_BN_CLICKED(IDC_BTN_Getaqsens, &CTest::OnBnClickedBtnGetaqsens)
	ON_BN_CLICKED(IDC_BTN_NotifCircle, &CTest::OnBnClickedBtnNotifcircle)
	ON_BN_CLICKED(IDC_BTN_NotifPolygon, &CTest::OnBnClickedBtnNotifpolygon)
	ON_BN_CLICKED(IDC_BTN_NotifLowBat, &CTest::OnBnClickedBtnNotiflowbat)
	ON_BN_CLICKED(IDC_BTN_NotifOutCircle, &CTest::OnBnClickedBtnNotifoutcircle)
	ON_BN_CLICKED(IDC_BTN_NotifOutPolygon, &CTest::OnBnClickedBtnNotifoutpolygon)
	ON_BN_CLICKED(IDC_BTN_NotifSeeMac, &CTest::OnBnClickedBtnNotifseemac)
	ON_BN_CLICKED(IDC_BTN_NotifStartMov, &CTest::OnBnClickedBtnNotifstartmov)
	ON_BN_CLICKED(IDC_BTN_NotifStopMov, &CTest::OnBnClickedBtnNotifstopmov)
	ON_BN_CLICKED(IDC_BTN_NotifUploadData, &CTest::OnBnClickedBtnNotifuploaddata)
	ON_BN_CLICKED(IDC_BTN_RemoveNotif, &CTest::OnBnClickedBtnRemovenotif)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CTest message handlers


void CTest::OnBnClickedBtnSetcenter()
{
	// TODO: Add your control notification handler code here
	CString js;
	float x = 45.378802;
	float y = -72.242796;
	js.Format(_T("SetCenter(%.2f, %.2f, %d);"), x, y, 15);

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnAddmarker()
{
	// TODO: Add your control notification handler code here
	CString js;
	float x = 45.378802;
	float y = -72.242796;
	js.Format(_T("AddMarker(%.2f, %.2f);"), x, y);

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnSetzoom()
{
	// TODO: Add your control notification handler code here
	CString js;
	int type = 15;
	js.Format(_T("SetZoom(%d);"), type);

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnDeletemarkers()
{
	// TODO: Add your control notification handler code here
	CString js;
	int type = 15;
	js.Format(_T("deleteMarkers();"));

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CTest::OnBnClickedBtnAuth()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url("https://data.aquaiot.com");

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Auth Info");
        free(data);
    }
}

char * CTest::handle_url_fields(char * url, char * fields)
{
	CURL *curl;
    struct url_data data;

    data.size = 0;
    data.data = (char *)malloc(4096); /* reasonable size initial buffer */
    if (NULL == data.data) {
        //fprintf(stderr, "Failed to allocate memory.\n");
        return NULL;
    }
    data.data[0] = '\0';

    CURLcode res;
    struct curl_slist *headers = NULL;
    // headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    // headers = curl_slist_append(headers, "charsets: utf-8");

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields);
        // curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            //fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return data.data;
}


void CTest::OnBnClickedBtnGetaqsens()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("https://data.aquaiot.com",
		"{\"reqtype\":\"getaqsen\",\"aquakey\":\"D4ADCC0DA03DAC64\",\"pass\":\"849DEEE4\",\"iid\":\"12341234123412341234\"}");

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifcircle()
{
	// TODO: Add your control notification handler code here
	char* data;
	double radius = 50.0000;
	double lat = 34.74773453;
	double lng = -124.6547654;
	char temp[1024] = "";

	radius = get_circle(&lat, &lng);
	set_circle(lat, lng, radius);

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

	data = handle_url_fields("https://data.aquaiot.com",
		temp);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyInsideCircle Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifpolygon()
{
	// TODO: Add your control notification handler code here
	char* data;
	vector<CComVariant> vecVarsLat;
	vector<CComVariant> vecVarsLng;
	char temp[1024] = "";

	get_polygon(vecVarsLat, vecVarsLng);

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyInsidePolygon Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotiflowbat()
{
	// TODO: Add your control notification handler code here
	char* data;

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyLowBat Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifoutcircle()
{
	// TODO: Add your control notification handler code here
	char* data;
	double radius = 50.0000;
	double lat = 34.74773453;
	double lng = -124.6547654;
	char temp[1024] = "";

	radius = get_circle(&lat, &lng);

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

	data = handle_url_fields("https://data.aquaiot.com",
		temp);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyOutOfCircle Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifoutpolygon()
{
	// TODO: Add your control notification handler code here
	char* data;
	vector<CComVariant> vecVarsLat;
	vector<CComVariant> vecVarsLng;
	char temp[1024] = "";

	get_polygon(vecVarsLat, vecVarsLng);

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyOutOfPolygon Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifseemac()
{
	// TODO: Add your control notification handler code here
	char* data;

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifySeeMac Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifstartmov()
{
	// TODO: Add your control notification handler code here
	char* data;

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyStartMov Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifstopmov()
{
	// TODO: Add your control notification handler code here
	char* data;

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyStopMov Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifuploaddata()
{
	// TODO: Add your control notification handler code here
	char* data;

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

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "NotifyUploadData Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnRemovenotif()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("https://data.aquaiot.com",
		"{\
		  \"reqtype\":\"rmntfid\",\
		  \"aquaname\":\"device\",\
		  \"ntfid\":\"a679a225\",\
		  \"iid\":\"12341234123412341234\"\
		}"
		);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "RemoveNotify Info");
        free(data);
    }
}


HBRUSH CTest::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}


BOOL CTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_brush.CreateSolidBrush(RGB(255, 255, 255));

	m_btn_setCenter.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_setCenter.SetTextColor(RGB(0, 0, 255));

	m_btn_addMarker.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_addMarker.SetTextColor(RGB(0, 0, 255));

	m_btn_auth.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_auth.SetTextColor(RGB(0, 0, 255));

	m_btn_deleteMarkers.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_deleteMarkers.SetTextColor(RGB(0, 0, 255));

	m_btn_getAqsens.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_getAqsens.SetTextColor(RGB(0, 0, 255));

	m_btn_notifCircle.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_notifCircle.SetTextColor(RGB(0, 0, 255));

	m_btn_notifLowBat.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_notifLowBat.SetTextColor(RGB(0, 0, 255));

	m_btn_notifOutCircle.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_notifOutCircle.SetTextColor(RGB(0, 0, 255));

	m_btn_notifOutPolygon.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_notifOutPolygon.SetTextColor(RGB(0, 0, 255));

	m_btn_notifPolygon.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_notifPolygon.SetTextColor(RGB(0, 0, 255));

	m_btn_notifSeeMac.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_notifSeeMac.SetTextColor(RGB(0, 0, 255));

	m_notifStartMov.SetFaceColor(RGB(255, 255, 255), true);
	m_notifStartMov.SetTextColor(RGB(0, 0, 255));

	m_notifStopMov.SetFaceColor(RGB(255, 255, 255), true);
	m_notifStopMov.SetTextColor(RGB(0, 0, 255));

	m_notifUploadData.SetFaceColor(RGB(255, 255, 255), true);
	m_notifUploadData.SetTextColor(RGB(0, 0, 255));

	m_btn_removeNotif.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_removeNotif.SetTextColor(RGB(0, 0, 255));

	m_btn_setZoom.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_setZoom.SetTextColor(RGB(0, 0, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


double CTest::get_circle(double *lat, double *lng)
{
	// TODO: Add your control notification handler code here

	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return -1;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return -1;

	//CString js;
	//js.Format(_T("getCircle();"));
	//CComBSTR bstrJS = js.AllocSysString();
	//CComBSTR bstrLanguage = SysAllocString(L"javascript");
	//VARIANT varResult;
	//pWin->execScript(bstrJS, bstrLanguage, &varResult);

	double radius = 0.0;
	//double lat = 0.0;
	//double lng = 0.0;
	static LPOLESTR strFxn = OLESTR("getCircle");
	static LPOLESTR strFxnLat = OLESTR("getCircleLat");
	static LPOLESTR strFxnLng = OLESTR("getCircleLng");
	CComPtr<IDispatch>pdispScript;
	if (SUCCEEDED(pDoc->get_Script(&pdispScript)) && pdispScript)
    {
        DISPID dispID;
        if (SUCCEEDED(pdispScript->GetIDsOfNames(
            IID_NULL, &strFxn, 1, LOCALE_USER_DEFAULT, &dispID)))
        {
            CComVariant vArgs[] = { lng, lat };
            DISPPARAMS params = { vArgs, NULL, 2, 0 };
            CComVariant vResult;
            if (SUCCEEDED(pdispScript->Invoke(dispID, IID_NULL, 0,
                DISPATCH_METHOD, &params, &vResult, NULL, NULL)))
            {
                if ((vResult.vt != VT_EMPTY) && ((vResult.vt == VT_I4) ||
                    SUCCEEDED(vResult.ChangeType(VT_I4))))
                {
                    radius = vResult.lVal;
                }
            }
        }

		if (SUCCEEDED(pdispScript->GetIDsOfNames(
            IID_NULL, &strFxnLat, 1, LOCALE_USER_DEFAULT, &dispID)))
        {
            CComVariant vArgs[] = { lng, lat };
            DISPPARAMS params = { vArgs, NULL, 2, 0 };
            CComVariant vResult;
            if (SUCCEEDED(pdispScript->Invoke(dispID, IID_NULL, 0,
                DISPATCH_METHOD, &params, &vResult, NULL, NULL)))
            {
                if ((vResult.vt != VT_EMPTY) && ((vResult.vt == VT_I4) ||
                    SUCCEEDED(vResult.ChangeType(VT_I4))))
                {
                    *lat = vResult.lVal;
                }
            }
        }

		if (SUCCEEDED(pdispScript->GetIDsOfNames(
            IID_NULL, &strFxnLng, 1, LOCALE_USER_DEFAULT, &dispID)))
        {
            CComVariant vArgs[] = { lng, lat };
            DISPPARAMS params = { vArgs, NULL, 2, 0 };
            CComVariant vResult;
            if (SUCCEEDED(pdispScript->Invoke(dispID, IID_NULL, 0,
                DISPATCH_METHOD, &params, &vResult, NULL, NULL)))
            {
                if ((vResult.vt != VT_EMPTY) && ((vResult.vt == VT_I4) ||
                    SUCCEEDED(vResult.ChangeType(VT_I4))))
                {
                    *lng = vResult.lVal;
                }
            }
        }
    }

	return radius;
}


void CTest::set_circle(double lat, double lng, double radius)
{
	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CString js;
	js.Format(_T("setCircle(%.2f, %.2f, %.2f);"), lat, lng, radius);

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}

int CTest::get_polygon(vector<CComVariant> &vecVarsLat, vector<CComVariant> &vecVarsLng)
{
	//CComQIPtr<IHTMLDocument2> pDoc = (IHTMLDocument2*)GetHtmlDocument();
	if (pDoc == NULL)
		return -1;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return -1;

	double lat = 0.0;
	double lng = 0.0;
	int count = 0;
	double lat10[10] = {0};
	double lng10[10] = {0};
	static LPOLESTR strFxn = OLESTR("getPolygonArraryCount");
	static LPOLESTR strFxnLat1 = OLESTR("getPolygonLat1");
	static LPOLESTR strFxnLat2 = OLESTR("getPolygonLat2");
	static LPOLESTR strFxnLat3 = OLESTR("getPolygonLat3");
	static LPOLESTR strFxnLat4 = OLESTR("getPolygonLat4");
	static LPOLESTR strFxnLat5 = OLESTR("getPolygonLat5");
	static LPOLESTR strFxnLat6 = OLESTR("getPolygonLat6");
	static LPOLESTR strFxnLat7 = OLESTR("getPolygonLat7");
	static LPOLESTR strFxnLat8 = OLESTR("getPolygonLat8");
	static LPOLESTR strFxnLat9 = OLESTR("getPolygonLat9");
	static LPOLESTR strFxnLat10 = OLESTR("getPolygonLat10");
	static LPOLESTR strFxnLng1 = OLESTR("getPolygonLng1");
	static LPOLESTR strFxnLng2 = OLESTR("getPolygonLng2");
	static LPOLESTR strFxnLng3 = OLESTR("getPolygonLng3");
	static LPOLESTR strFxnLng4 = OLESTR("getPolygonLng4");
	static LPOLESTR strFxnLng5 = OLESTR("getPolygonLng5");
	static LPOLESTR strFxnLng6 = OLESTR("getPolygonLng6");
	static LPOLESTR strFxnLng7 = OLESTR("getPolygonLng7");
	static LPOLESTR strFxnLng8 = OLESTR("getPolygonLng8");
	static LPOLESTR strFxnLng9 = OLESTR("getPolygonLng9");
	static LPOLESTR strFxnLng10 = OLESTR("getPolygonLng10");
	static LPOLESTR strFxnLatArray = OLESTR("getPolygonLat");
	static LPOLESTR strFxnLngArray = OLESTR("getPolygonLng");
	CComPtr<IDispatch>pdispScript;
	CComVariant vResult;
	CComVariant vArgs[] = { lng, lat };
    DISPPARAMS params = { vArgs, NULL, 2, 0 };
	CComPtr<IEnumVARIANT> pEnumVariant;
	CComPtr<IDispatch> pDispatchResult;
	CComVariant varItem;
	ULONG uiFetched = 0;
	//vector<CComVariant> vecVarsLat;
	//vector<CComVariant> vecVarsLng;
	int i = 0;
	if (SUCCEEDED(pDoc->get_Script(&pdispScript)) && pdispScript)
    {
        DISPID dispID;
		CComSafeArray<double> SafeArray;
        if (SUCCEEDED(pdispScript->GetIDsOfNames(
            IID_NULL, &strFxn, 1, LOCALE_USER_DEFAULT, &dispID)))
        {
			// get the number of elements using the DISPID of length parameter
            if (SUCCEEDED(pdispScript->Invoke(dispID, IID_NULL, 0,
                DISPATCH_METHOD, &params, &vResult, NULL, NULL)))
            {
                if ((vResult.vt != VT_EMPTY) && ((vResult.vt == VT_I4) ||
                    SUCCEEDED(vResult.ChangeType(VT_I4))))
                {
                    count = vResult.lVal;
                }
            }
        }

		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLatArray, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		pDispatchResult = vResult.pdispVal;
		pEnumVariant = pDispatchResult;
		pEnumVariant->Reset();
		i = 0;
		uiFetched = 0;
		do 
		{
			// get next item
			pEnumVariant->Next(1, &varItem, &uiFetched);

			if (i == count)
				break;

			if (uiFetched == NULL) // last item
				break;

			// insert the item to the vector 
			vecVarsLat.push_back(varItem);
			i++;
		} while (true);

		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLngArray, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		pDispatchResult = vResult.pdispVal;
		pEnumVariant = pDispatchResult;
		pEnumVariant->Reset();
		i = 0;
		uiFetched = 0;
		do 
		{
			// get next item
			pEnumVariant->Next(1, &varItem, &uiFetched);

			if (i == count)
				break;

			if (uiFetched == NULL) // last item
				break;

			// insert the item to the vector 
			vecVarsLng.push_back(varItem);
			i++;
		} while (true);

		/*pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat1, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[0] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat2, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[1] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat3, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[2] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat4, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[3] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat5, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[4] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat6, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[5] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat7, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[6] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat8, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[7] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat9, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[8] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLat10, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lat10[9] = vResult.dblVal;

		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng1, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[0] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng2, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[1] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng3, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[2] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng4, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[3] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng5, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[4] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng6, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[5] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng7, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[6] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng8, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[7] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng9, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[8] = vResult.dblVal;
		pdispScript->GetIDsOfNames(IID_NULL, &strFxnLng10, 1, LOCALE_USER_DEFAULT, &dispID);
		pdispScript->Invoke(dispID, IID_NULL, 0, DISPATCH_METHOD, &params, &vResult, NULL, NULL);
		lng10[9] = vResult.dblVal;*/
    }

	return 0;
}
