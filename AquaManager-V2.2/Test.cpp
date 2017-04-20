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
}


BEGIN_MESSAGE_MAP(CTest, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SetCenter, &CTest::OnBnClickedBtnSetcenter)
	ON_BN_CLICKED(IDC_BTN_AddMarker, &CTest::OnBnClickedBtnAddmarker)
	ON_BN_CLICKED(IDC_BTN_SetZoom, &CTest::OnBnClickedBtnSetzoom)
	ON_BN_CLICKED(IDC_BTN_DeleteMarkers, &CTest::OnBnClickedBtnDeletemarkers)
	ON_BN_CLICKED(IDC_BTN_Auth, &CTest::OnBnClickedBtnAuth)
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
