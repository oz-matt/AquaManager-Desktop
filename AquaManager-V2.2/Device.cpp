// Device.cpp : implementation file
//

#include "stdafx.h"
#include "afxdialogex.h"
#include "AquaManager-V2.2.h"
#include "AquaLib.h"
#include "Device.h"
#include "DlgAddDevice.h"
#include "DeviceName.h"

#include<fstream>
#include<iterator>
#include<iostream>
#include<sstream>

#include "include/json/reader.h"
#include "include/json/value.h"

using namespace std;

double g_m_previous_lat;
double g_m_previous_lng;
double g_m_current_lat;
double g_m_current_lng;
CString g_m_previous_location;
CString g_m_current_location;
CString g_m_previous_time;
CString g_m_current_time;

CString g_m_datetime;
CString g_m_uuid;
CString g_m_time;
//CString g_m_numsat;
CString g_m_lon;///////////////
CString g_m_lat;
//CString g_m_height;
//CString g_m_gspeed;
CString g_m_accelerometer;
CString g_m_pressure;
CString g_m_update_rate;
CString g_m_incoming_ip;
CString g_m_install_id;////////////
CString g_m_aqsense_data[10];
CString g_m_aqsense_data_head[10];
int g_m_aqsense_count;

int g_m_device_count;

extern int currentTabSelected;
extern CString g_m_device_name;
extern CComQIPtr<IHTMLDocument2> pDoc;

enum
{
    FUNCTION_ShowMessageBox = 1,
    FUNCTION_GetProcessID = 2,
};

// CDevice dialog

IMPLEMENT_DYNAMIC(CDevice, CDialog)

CDevice::CDevice(CWnd* pParent /*=NULL*/)
	: CDialog(CDevice::IDD, pParent)
{
	m_lst_device.pdevice = this;

	ImgHeaders = new CImageList;
}

CDevice::~CDevice()
{
	delete ImgHeaders;
}

void CDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Device, m_lst_device);
	DDX_Control(pDX, IDC_BTN_AddMarker, m_btn_add_device);
}


BEGIN_MESSAGE_MAP(CDevice, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_AddMarker, &CDevice::OnBnClickedBtnAddmarker)
//	ON_NOTIFY(HDN_ITEMCLICK, 0, &CDevice::OnItemclickLstDevice)
END_MESSAGE_MAP()


// CDevice message handlers


BOOL CDevice::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	ImgHeaders->Create(16, 16, ILC_MASK, 1, 1);
	ImgHeaders->Add(AfxGetApp()->LoadIcon(IDI_SETTING));
	m_lst_device.SetImageList(ImgHeaders, LVSIL_SMALL);

	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = _T("Name");
	m_lst_device.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 0;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Location");
	m_lst_device.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 1;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Battery");
	m_lst_device.InsertColumn(2, &lvColumn);

	// Add some columns to the list control
	//m_lst_device.InsertColumn( 0, _T("Name") );
	//m_lst_device.InsertColumn( 1, _T("Location") );
	//m_lst_device.InsertColumn( 2, _T("Battery") );

	// Set the column widths
	m_lst_device.SetColumnWidth( 0, 70 );
	m_lst_device.SetColumnWidth( 1, 70 );
	m_lst_device.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	/*
	nIndex = m_lst_device.InsertItem(0, _T("Dev1"));
	m_lst_device.SetItemText(nIndex, 1, _T("Woods Way, New Fairfield CT, USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("45%"));

	nIndex = m_lst_device.InsertItem(0, _T("Dev2"));
	m_lst_device.SetItemText(nIndex, 1, _T("St Louis St, Avon, CT USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("88%"));

	nIndex = m_lst_device.InsertItem(0, _T("Dev3"));
	m_lst_device.SetItemText(nIndex, 1, _T("15th St, New York, NY, USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("11%"));

	nIndex = m_lst_device.InsertItem(0, _T("Dev4"));
	m_lst_device.SetItemText(nIndex, 1, _T("Woods Way, New Fairfield CT, USA"));
	m_lst_device.SetItemText(nIndex, 2, _T("45%"));
	*/

	m_lst_device.SetBkColor(RGB(255, 255, 255));

	m_brush.CreateSolidBrush(RGB(255, 255, 255));

	m_btn_add_device.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_add_device.SetTextColor(RGB(0, 0, 255));

	if (pDoc == NULL)
		return TRUE;
	CComDispatchDriver spScript;
	pDoc->get_Script(&spScript);
	CComVariant var(static_cast<IDispatch*>(this));
	spScript.Invoke1(L"SaveGeoObject", &var);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CDevice::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	currentTabSelected = 0;
	// TODO:  Return a different brush if the default is not desired
	if (pDoc == NULL)
		return hbr;

	CComDispatchDriver spScript;
	pDoc->get_Script(&spScript);
	CComVariant var(static_cast<IDispatch*>(this));
	spScript.Invoke1(L"HideGeoControls", &var);

	CComVariant var_int = 0;
	spScript.Invoke1(L"SetCurrentTab", &var_int);

	return hbr;
}

// should be add device and add marker
void CDevice::OnBnClickedBtnAddmarker()
{
	// TODO: Add your control notification handler code here
	CDlgAddDevice dlg;
	dlg.DoModal();

	DeviceData *d = new DeviceData();
	d->device_index = device_count;
	device_count++;
	_device.push_front(d);
	d->aquaid =  dlg.m_aquaid.GetBuffer(0);
	d->passcode = dlg.m_passcode.GetBuffer(0);

	char* data;
	char ip[32] = "https://data.aquaiot.com";
	char temp[1024] = "";
	
	sprintf(temp, "%s\"%s\",%s\"%s\",%s", "{\"reqtype\":\"auth\",\"id\":",dlg.m_aquaid, "\"pass\":", dlg.m_passcode, "\"iid\":\"12341234123412341234\"}");
	data = handle_url_fields(ip, temp);

	// process data
	CDeviceName dlg_name;
	dlg_name.DoModal();
	dlg.m_device_name = dlg_name.m_device_name;
	g_m_device_name = dlg_name.m_device_name;

	Json::Reader reader;
	Json::Value root;
	double lon_show;
	double lat_show;
	CString battery_show;
	string location;

	if (reader.parse(data, root))
	{
		std::string qresponse;
		// Return the member named key if it exist, defaultValue otherwise.
		qresponse = root.get("qresponse", "null").asString();

		//Json::Value qdata = root.get("qdata", "null");
		//string aquakey = qdata.get("aquakey", "null").asString();
		//string phonenumber = qdata.get("phonenumber", "null").asString();
		Json::Value qdata = root["qdata"];
		string aquakey = qdata["aquakey"].asString();
		string phonenumber = qdata["phonenumber"].asString();
		d->phone = qdata["phonenumber"].asCString();
		d->aquakey = qdata["aquakey"].asCString();

		//Json::Value aqsens = root.get("aqsens", "null");
		Json::Value aqsens = root["aqsens"];
		int aqsens_size = 0;
		string aqsens_string = aqsens.asString();

		Json::Reader aqsens_reader;
		Json::Value aqsens_node;
		if (aqsens_reader.parse(aqsens_string, aqsens_node)) // IMPORTANT
		{
			aqsens_size = aqsens_node.size();
		}

		g_m_aqsense_count = 0;
		for(int i = 0; i < aqsens_size; ++i)
		{
			//g_m_aqsense_data[i] = aqsens_node.asCString(); // ???
			//g_m_aqsense_count++;

			string datetime = aqsens_node[i]["datetime"].asString();
			string uuid = aqsens_node[i]["uuid"].asString();

			Json::Value gpsminimum = aqsens_node[i]["gpsminimum"];
			string time = gpsminimum["time"].asString();
			int numsat = gpsminimum["numsat"].asInt();
			double lon = gpsminimum["lon"].asDouble();
			double lat = gpsminimum["lat"].asDouble();
			double height = gpsminimum["height"].asDouble();
			double gspeed = gpsminimum["gspeed"].asDouble();
			double direction = gpsminimum["direction"].asDouble();

			if (i == 0)
			{
				g_m_current_lat = lat;
				g_m_current_lng = lon;
				g_m_current_time = gpsminimum["time"].asCString();

				Json::Reader reader_tmp;
				Json::Value root_tmp;
				char tmp_loc[1024] = "";
				sprintf(tmp_loc, "https://maps.googleapis.com/maps/api/geocode/json?latlng=%f,%f&key=AIzaSyAeHtCDX8llqpxW-xOHZ-nyBPHvKGDeOIw", lat, lon);
				data = handle_url_fields(tmp_loc, "");
				if (reader_tmp.parse(data, root_tmp))
				{
					Json::Value loc_tmp = root_tmp["results"];
					int n = loc_tmp.size();
					g_m_current_location = loc_tmp[2]["formatted_address"].asCString();
				}
			}
			if (i == 1)
			{
				g_m_previous_lat = lat;
				g_m_previous_lng = lon;
				g_m_previous_time = gpsminimum["time"].asCString();

				Json::Reader reader_tmp;
				Json::Value root_tmp;
				char tmp_loc[1024] = "";
				sprintf(tmp_loc, "https://maps.googleapis.com/maps/api/geocode/json?latlng=%f,%f&key=AIzaSyAeHtCDX8llqpxW-xOHZ-nyBPHvKGDeOIw", lat, lon);
				data = handle_url_fields(tmp_loc, "");
				if (reader_tmp.parse(data, root_tmp))
				{
					Json::Value loc_tmp = root_tmp["results"];
					int n = loc_tmp.size();
					g_m_previous_location = loc_tmp[2]["formatted_address"].asCString();
				}

				Setcenter(lat, lon);
			}

			Json::Value gpsextended = aqsens_node[i]["gpsextended"];

			Json::Value sensors = aqsens_node[i]["sensors"];
			int pct_battery = sensors["pct_battery"].asInt();
			string accelerometer = sensors["accelerometer"].asString();
			int temperature = sensors["temperature"].asInt();
			int humidity = sensors["humidity"].asInt();
			int pressure = sensors["pressure"].asInt();
			int update_rate = sensors["update_rate"].asInt();

			Json::Value ble = aqsens_node[i]["ble"];
			Json::Value custom = aqsens_node[i]["custom"];
			string incoming_ip = aqsens_node[i]["incoming_ip"].asString();
			string install_id = aqsens_node[i]["install_id"].asString();

			lon_show = lon;
			lat_show = lat;

			// add marker
			AddMarker(lat, lon);

			battery_show.Format(_T("%d%%"), pct_battery); // local use
			d->pct_battery = battery_show.GetBuffer(0);

			std::stringstream stream;
			stream<<temperature;
			d->temperature = stream.str();

			stream<<humidity;
			d->humidity = stream.str();

			stream << height;
			d->height = stream.str();
			
			stream << gspeed;
			d->speed = stream.str();

			stream << direction;
			d->direction = stream.str();

			stream << numsat;
			d->numsat = stream.str();

			stream << lon;
			d->lon = stream.str();

			stream << lat;
			d->lat = stream.str();

			d->accelerometer = sensors["accelerometer"].asString();

			stream << pressure;
			d->pressure = stream.str();

			stream << update_rate;
			d->update_rate = stream.str();

			d->incoming_ip = aqsens_node[i]["incoming_ip"].asString();

			d->install_id = aqsens_node[i]["install_id"].asString();

			d->datetime = aqsens_node[i]["datetime"].asString();

			d->uuid = aqsens_node[i]["uuid"].asString();

			d->time = gpsminimum["time"].asString();


			CString tmp_convert;
			d->aqsense_data_head.push_back(d->datetime);
			d->aqsense_data.push_back("datetime: " + d->datetime + "\r\n" +
										"uuid: " + d->uuid + "\r\n" +
										"time: " + d->time + "\r\n" +
										"numsat: " + d->numsat + "\r\n" +
										"lon: " + d->lon + "\r\n" +
										"lat: " + d->lat + "\r\n" +
										"height: " + d->height + "\r\n" +
										"gspeed: " + d->speed + "\r\n" +
										"direction: " + d->direction + "\r\n" +
										"pct_battery: " + d->pct_battery + "\r\n" +
										"accelerometer: " + d->accelerometer + "\r\n" +
										"temperature: " + d->temperature + "\r\n" +
										"humidity: " + d->humidity + "\r\n" +
										"pressure: " + d->pressure + "\r\n" +
										"update_rate: " + d->update_rate + "\r\n" +
										"incoming_ip: " + d->incoming_ip + "\r\n" +
										"install_id: " + d->install_id);

			//AddRawData(g_m_datetime, g_m_uuid, g_m_time, g_m_numsat, g_m_lon, g_m_lat, g_m_height, g_m_speed,
			//	g_m_direction, g_m_pct_battery, g_m_accelerometer, g_m_temperature, g_m_humidity, g_m_pressure,
			//	g_m_update_rate, g_m_incoming_ip, g_m_install_id);

			AddRawDataStr(g_m_aqsense_data[i]);

			g_m_aqsense_count++;
		}
	}

	Json::Reader reader_loc;
	Json::Value root_loc;
	char temp_loc[1024] = "";
	sprintf(temp_loc, "https://maps.googleapis.com/maps/api/geocode/json?latlng=%f,%f&key=AIzaSyAeHtCDX8llqpxW-xOHZ-nyBPHvKGDeOIw", lat_show, lon_show);
	data = handle_url_fields(temp_loc, "");
	if (reader_loc.parse(data, root_loc))
	{
		Json::Value loc_value = root_loc["results"];
		int n = loc_value.size();
		CString loc_cstring = loc_value[2]["formatted_address"].asCString();
		location = loc_value[2]["formatted_address"].asString();
	}
		 
	nIndex = m_lst_device.InsertItem(0, dlg.m_device_name);
	m_lst_device.SetItemText(nIndex, 1, location.c_str());
	m_lst_device.SetItemText(nIndex, 2, battery_show);

	g_m_device_count++;
}


void CDevice::AddMarker(double lat, double lng)
{
	// TODO: Add your control notification handler code here
	CString js;
	//float x = 45.378802;
	//float y = -72.242796;
	js.Format(_T("AddMarker(%.2f, %.2f);"), lat, lng);

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


void CDevice::AddRawData(CString datetime, CString uuid, CString time, CString numsat, CString lon, CString lat,
	CString height, CString gspeed, CString direction, CString pct_battery, CString accelerometer, 
	CString temperature, CString humidity, CString pressure, CString update_rate, CString incoming_ip,
	CString install_id)
{
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CString js;
	js.Format(_T("addRawData(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s);"),
		datetime, uuid, time, numsat, lon, lat, height, gspeed, direction, pct_battery, accelerometer, temperature, humidity, pressure, update_rate,
		incoming_ip, install_id);

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CDevice::AddRawDataStr(CString str)
{
	if (pDoc == NULL)
		return;

	CComDispatchDriver spScript;
	pDoc->get_Script(&spScript);

	//CComVariant var1 = 10, var2 = 20, varRet;

	//spScript.Invoke2(L"Add", &var1, &var2, &varRet);

	//spScript.Invoke2(L"AddArray", &var1, &var2, &varRet);
	//CComDispatchDriver spArray = varRet.pdispVal;
	//CComVariant varArrayLen;
	//spArray.GetPropertyByName(L"length", &varArrayLen);
	//CComVariant varValue[3];
	//spArray.GetPropertyByName(L"0", &varValue[0]);
	//spArray.GetPropertyByName(L"1", &varValue[1]);
	//spArray.GetPropertyByName(L"2", &varValue[2]);

	//spScript.Invoke2(L"AddObj", &var1, &var2, &varRet);
	//CComDispatchDriver spData = varRet.pdispVal;
	//CComVariant varValue1, varValue2;
	//spData.GetPropertyByName(L"result", &varValue1);
	//spData.GetPropertyByName(L"str", &varValue2);

	/* Next, i plan to use IDispatch to handle multi parameters, arrays and string to java script. */
	// transfer vc class pointer to java script
	//CComVariant var(static_cast<IDispatch*>(this));
	//spScript.Invoke1(L"SaveCPPObject", &var);

	//CComQIPtr<IHTMLWindow2> pWin;
	//pDoc->get_parentWindow(&pWin);
	//if (pWin == NULL)
	//	return;

	//CString js;

	char *ptest = (LPSTR)(LPCTSTR)str;

	CComVariant var_str = ptest;
	spScript.Invoke1(L"addRawDataStr", &var_str);

	//js.Format(_T("addRawDataStr(%s);"), ptest);

	//CComBSTR bstrJS = js.AllocSysString();
	//CComBSTR bstrLanguage = SysAllocString(L"javascript");
	//VARIANT varResult;
	//pWin->execScript(bstrJS, bstrLanguage, &varResult);
}

void CDevice::Setcenter(float x, float y)
{
	// TODO: Add your control notification handler code here
	CString js;
	//float x = 45.378802;
	//float y = -72.242796;
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

HRESULT STDMETHODCALLTYPE CDevice::GetTypeInfoCount(UINT *pctinfo)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CDevice::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CDevice::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
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

HRESULT STDMETHODCALLTYPE CDevice::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
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

HRESULT STDMETHODCALLTYPE CDevice::QueryInterface(REFIID riid, void **ppvObject)
{
    if (riid == IID_IDispatch || riid == IID_IUnknown)
    {
        *ppvObject = static_cast<IDispatch*>(this);
        return S_OK;
    }
    else
        return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE CDevice::AddRef()
{
    return 1;
}

ULONG STDMETHODCALLTYPE CDevice::Release()
{
    return 1;
}

DWORD CDevice::GetProcessID()
{
    return GetCurrentProcessId();
}

void CDevice::ShowMessageBox(const wchar_t *msg)
{
    MessageBox(CW2T(msg), _T("the message come from java script"));
}
