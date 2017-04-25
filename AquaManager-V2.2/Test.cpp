// Test.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Test.h"
#include "afxdialogex.h"

#include <afxinet.h>
#include <curl/curl.h>

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

	data = handle_url("198.61.169.55:8081");

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Auth Info");
        free(data);
    }
}


char * handle_url(char * url)
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
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"reqtype\":\"auth\",\"id\":\"8DC8B056\",\"pass\":\"849DEEE4\",\"iid\":\"12341234123412341234\"}");
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


size_t write_data(void * ptr, size_t size, size_t nmemb, struct url_data * data)
{
	size_t index = data->size;
    size_t n = (size * nmemb);
    char* tmp;

    data->size += (size * nmemb);

#ifdef DEBUG
    //fprintf(stderr, "data at %p size=%ld nmemb=%ld\n", ptr, size, nmemb);
#endif
    tmp = (char *)realloc(data->data, data->size + 1); /* +1 for '\0' */

    if (tmp) {
        data->data = tmp;
    } else {
        if (data->data) {
            free(data->data);
        }
        //fprintf(stderr, "Failed to allocate memory.\n");
        return 0;
    }

    memcpy((data->data + index), ptr, n);
    data->data[data->size] = '\0';

    return size * nmemb;
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

	data = handle_url_fields("198.61.169.55:8081",
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

	data = handle_url_fields("198.61.169.55:8081",
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
		\"geodata\" : [\"34.74773453\", \"-124.6547654\", \"50.0000\"] },\
		\"iid\":\"12341234123412341234\"}");

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifpolygon()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
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
		\"geodata\" : { \"pt1_lat\" : 34.74773453,\
		\"pt1_lon\" : -124.6547654,\
		\"pt2_lat\" : 35.74773453,\
		\"pt2_lon\" : -125.6547654,\
		\"pt3_lat\" : 36.74773453,\
		\"pt3_lon\" : -125.6547654,\
		\"pt4_lat\" : 37.74773453,\
		\"pt4_lon\" : -127.6547654,\
		\"pt5_lat\" : 38.74773453,\
		\"pt5_lon\" : -128.6547654,\
		\"pt6_lat\" : 39.74773453,\
		\"pt6_lon\" : -129.6547654,\
		\"pt7_lat\" : 33.74773453,\
		\"pt7_lon\" : -123.6547654,\
		\"pt8_lat\" : 32.74773453,\
		\"pt8_lon\" : -122.6547654 } },\
		\"iid\":\"12341234123412341234\"}");

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotiflowbat()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"text\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"+12037701412\",\
			\"trigger\" : \"lowBattery\",\
			\"continuous\" : \"true\",\
		  },\
		  \"iid\":\"1234123412341234\"\
		}"
		);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifoutcircle()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
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
			\"geodata\" : [\
			  \"34.74773453\",\
			  \"-124.6547654\",\
			  \"50.0000\"\
			]\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"
		);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifoutpolygon()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
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
			\"geodata\" : {\
			  \"pt1_lat\" : 34.74773453,\
			  \"pt1_lon\" : -124.6547654,\
			  \"pt2_lat\" : 35.74773453,\
			  \"pt2_lon\" : -125.6547654,\
			  \"pt3_lat\" : 36.74773453,\
			  \"pt3_lon\" : -126.6547654,\
			  \"pt4_lat\" : 37.74773453,\
			  \"pt4_lon\" : -127.6547654,\
			  \"pt5_lat\" : 38.74773453,\
			  \"pt5_lon\" : -128.6547654,\
			  \"pt6_lat\" : 39.74773453,\
			  \"pt6_lon\" : -129.6547654,\
			  \"pt7_lat\" : 33.74773453,\
			  \"pt7_lon\" : -123.6547654,\
			  \"pt8_lat\" : 32.74773453,\
			  \"pt8_lon\" : -122.6547654\
			}\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"
		);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifseemac()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
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
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifstartmov()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
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
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifstopmov()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
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
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnNotifuploaddata()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
		"{\
		  \"reqtype\":\"notif\",\
		  \"aquakey\":\"D4ADCC0DA03DAC64\",\
		  \"data\": {\
			\"alert\" : \"text\",\
			\"aquaname\" : \"myaqua\",\
			\"ntfuuid\" : \"abcdefghi-qwerfeqrf-qerf\",\
			\"target\" : \"+12037701412\",\
			\"trigger\" : \"uploadsData\",\
			\"continuous\" : \"false\",\
		  },\
		  \"iid\":\"12341234123412341234\"\
		}"
		);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
        free(data);
    }
}


void CTest::OnBnClickedBtnRemovenotif()
{
	// TODO: Add your control notification handler code here
	char* data;

	data = handle_url_fields("198.61.169.55:8081",
		"{\
		  \"reqtype\":\"rmntfid\",\
		  \"aquaname\":\"hihi\",\
		  \"ntfid\":\"a13d15a0-a0ed-41b0-8d7d-2f8629df2383\",\
		  \"iid\":\"12341234123412341234\"\
		}"
		);

	if (data) {
		//printf("%s\n", data);
		MessageBox(data, "Getaqsens Info");
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
