// Device.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Device.h"
#include "afxdialogex.h"

#include<fstream>
#include<string>
#include<iterator>

#include "DlgAddDevice.h"
#include "AquaLib.h"
#include "DeviceName.h"

#include "include/json/reader.h"
#include "include/json/value.h"

using namespace std;

CString g_m_aquaid;
CString g_m_passcode;
CString g_m_pct_battery;
CString g_m_temperature;
CString g_m_humidity;
CString g_m_height;
CString g_m_speed;
CString g_m_direction;
CString g_m_numsat;
CString g_m_phone;
CString g_m_aquakey;

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

// CDevice dialog

IMPLEMENT_DYNAMIC(CDevice, CDialog)

CDevice::CDevice(CWnd* pParent /*=NULL*/)
	: CDialog(CDevice::IDD, pParent)
{
	m_lst_device.type = 0;
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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LST_Device, &CDevice::OnLvnItemchangedLstDevice)
	ON_BN_CLICKED(IDC_BTN_AddMarker, &CDevice::OnBnClickedBtnAddmarker)
//	ON_WM_LBUTTONDOWN()
ON_NOTIFY(NM_RCLICK, IDC_LST_Device, &CDevice::OnNMRClickLstDevice)
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
	return hbr;
}


void CDevice::OnLvnItemchangedLstDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

// should be add device and add marker
void CDevice::OnBnClickedBtnAddmarker()
{
	// TODO: Add your control notification handler code here
	CDlgAddDevice dlg;
	dlg.DoModal();
	g_m_aquaid = dlg.m_aquaid;
	g_m_passcode = dlg.m_passcode;

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
		g_m_phone = qdata["phonenumber"].asCString();
		g_m_aquakey = qdata["aquakey"].asCString();

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

			battery_show.Format(_T("%d%%"), pct_battery);
			g_m_pct_battery = battery_show;
			g_m_temperature.Format(_T("%d"), temperature);
			g_m_humidity.Format(_T("%d"), humidity);
			g_m_height.Format(_T("%f"), height);
			g_m_speed.Format(_T("%f"), gspeed);
			g_m_direction.Format(_T("%f"), direction);
			g_m_numsat.Format(_T("%d"), numsat);	
			g_m_lon.Format(_T("%f"), lon);
			g_m_lat.Format(_T("%f"), lat);
			g_m_accelerometer = sensors["accelerometer"].asCString();
			g_m_pressure.Format(_T("%d"), pressure);
			g_m_update_rate.Format(_T("%d"), update_rate);
			g_m_incoming_ip = aqsens_node[i]["incoming_ip"].asCString();
			g_m_install_id = aqsens_node[i]["install_id"].asCString();
			g_m_datetime = aqsens_node[i]["datetime"].asCString();
			g_m_uuid = aqsens_node[i]["uuid"].asCString();
			g_m_time = gpsminimum["time"].asCString();

			CString tmp_convert;
			g_m_aqsense_data_head[i].Append(g_m_datetime);
			g_m_aqsense_data[i].Append("datetime: " + g_m_datetime + "\r\n");
			g_m_aqsense_data[i].Append("uuid: " + g_m_uuid + "\r\n");
			g_m_aqsense_data[i].Append("time: " + g_m_time + "\r\n");
			g_m_aqsense_data[i].Append("numsat: " + g_m_numsat + "\r\n");
			g_m_aqsense_data[i].Append("lon: " + g_m_lon + "\r\n");
			g_m_aqsense_data[i].Append("lat: " + g_m_lat + "\r\n");
			g_m_aqsense_data[i].Append("height: " + g_m_height + "\r\n");
			g_m_aqsense_data[i].Append("gspeed: " + g_m_speed + "\r\n");
			g_m_aqsense_data[i].Append("direction: " + g_m_direction + "\r\n");
			g_m_aqsense_data[i].Append("pct_battery: " + g_m_pct_battery + "\r\n");
			g_m_aqsense_data[i].Append("accelerometer: " + g_m_accelerometer + "\r\n");
			g_m_aqsense_data[i].Append("temperature: " + g_m_temperature + "\r\n");
			g_m_aqsense_data[i].Append("humidity: " + g_m_humidity + "\r\n");
			g_m_aqsense_data[i].Append("pressure: " + g_m_pressure + "\r\n");
			g_m_aqsense_data[i].Append("update_rate: " + g_m_update_rate + "\r\n");
			g_m_aqsense_data[i].Append("incoming_ip: " + g_m_incoming_ip + "\r\n");
			g_m_aqsense_data[i].Append("install_id: " + g_m_install_id);
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


//void CDevice::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: Add your message handler code here and/or call default
//
//	CDialog::OnLButtonDown(nFlags, point);
//}


void CDevice::OnNMRClickLstDevice(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
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
