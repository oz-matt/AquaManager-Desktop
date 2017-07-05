// Geofence.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Geofence.h"
#include "afxdialogex.h"

#include "include/json/reader.h"
#include "include/json/value.h"

#include "AquaLib.h"

#include "DlgAddGeofence.h"

extern int currentTabSelected;

extern CComQIPtr<IHTMLDocument2> pDoc;
// CGeofence dialog

IMPLEMENT_DYNAMIC(CGeofence, CDialog)

CGeofence::CGeofence(CWnd* pParent /*=NULL*/)
	: CDialog(CGeofence::IDD, pParent)
{
	m_lst_geofence.type = 2;
	ImgHeaders = new CImageList;
}

CGeofence::~CGeofence()
{
	delete ImgHeaders;
}

void CGeofence::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Geofence, m_lst_geofence);
	DDX_Control(pDX, IDC_BTN_Geofence, m_btn_geofence);
	DDX_Control(pDX, IDC_BTN_Save, m_btn_save);
	DDX_Control(pDX, IDC_BTN_Cancel, m_btn_cancel);
}


BEGIN_MESSAGE_MAP(CGeofence, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_Geofence, &CGeofence::OnBnClickedBtnGeofence)
	ON_BN_CLICKED(IDC_BTN_Save, &CGeofence::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_Cancel, &CGeofence::OnBnClickedBtnCancel)
END_MESSAGE_MAP()


// CGeofence message handlers


BOOL CGeofence::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	ImgHeaders->Create(16, 16, ILC_MASK, 1, 1);
	ImgHeaders->Add(AfxGetApp()->LoadIcon(IDI_SETTING));
	m_lst_geofence.SetImageList(ImgHeaders, LVSIL_SMALL);

	LVCOLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 70;
	lvColumn.pszText = _T("Name");
	m_lst_geofence.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 0;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Centered In");
	m_lst_geofence.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_IMAGE;
	lvColumn.fmt = LVCFMT_LEFT | LVCFMT_IMAGE;
	lvColumn.iImage = 1;
	lvColumn.cx = 70;
	lvColumn.pszText =_T("Size");
	m_lst_geofence.InsertColumn(2, &lvColumn);

	// Add some columns to the list control
	//m_lst_geofence.InsertColumn( 0, _T("Name") );
	//m_lst_geofence.InsertColumn( 1, _T("Centered In") );
	//m_lst_geofence.InsertColumn( 2, _T("Size") );

	// Set the column widths
	m_lst_geofence.SetColumnWidth( 0, 70 );
	m_lst_geofence.SetColumnWidth( 1, 70 );
	m_lst_geofence.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	/*nIndex = m_lst_geofence.InsertItem(0, _T("Geo1"));
	m_lst_geofence.SetItemText(nIndex, 1, _T("15th St, New York, NY, USA"));
	m_lst_geofence.SetItemText(nIndex, 2, _T("180 sq.mi"));

	nIndex = m_lst_geofence.InsertItem(0, _T("Geo2"));
	m_lst_geofence.SetItemText(nIndex, 1, _T("15th St, New York, NY, USA"));
	m_lst_geofence.SetItemText(nIndex, 2, _T("6 sq.mi"));*/

	m_lst_geofence.SetBkColor(RGB(255, 255, 255));

	m_brush.CreateSolidBrush(RGB(255, 255, 255));

	m_btn_geofence.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_geofence.SetTextColor(RGB(0, 0, 255));

	m_btn_save.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_save.SetTextColor(RGB(0, 0, 255));

	m_btn_cancel.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_cancel.SetTextColor(RGB(0, 0, 255));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CGeofence::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	currentTabSelected = 2;
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}


void CGeofence::OnBnClickedBtnGeofence()
{
	// TODO: Add your control notification handler code here

	CDlgAddGeofence dlg;
	dlg.DoModal();

	if (dlg.m_circle) {
		draw_circle(dlg.m_radius_double);
	}
	else if (dlg.m_polygon) {
		draw_polygon(dlg.m_radius_double);
	}

	m_geo_name = dlg.m_geo_name;
	m_radius = dlg.m_radius_double;
}


void CGeofence::OnBnClickedBtnSave()
{
	// TODO: Add your control notification handler code here
	double size;
	CString size_cstr;
	double lat;
	double lng;
	char* data;

	size = 3.1416 * m_radius * m_radius;
	size_cstr.Format("%f", size);
	get_center(&lat, &lng);

	Json::Reader reader_loc;
	Json::Value root_loc;
	char temp_loc[1024] = "";
	CString loc_cstring;
	sprintf(temp_loc, "https://maps.googleapis.com/maps/api/geocode/json?latlng=%f,%f&key=AIzaSyAeHtCDX8llqpxW-xOHZ-nyBPHvKGDeOIw", lat, lng);
	data = handle_url_fields(temp_loc, "");
	if (reader_loc.parse(data, root_loc))
	{
		Json::Value loc_value = root_loc["results"];
		int n = loc_value.size();
		loc_cstring = loc_value[2]["formatted_address"].asCString();
	}

	nIndex = m_lst_geofence.InsertItem(0, m_geo_name);
	m_lst_geofence.SetItemText(nIndex, 1, loc_cstring);
	m_lst_geofence.SetItemText(nIndex, 2, size_cstr);
}


void CGeofence::OnBnClickedBtnCancel()
{
	// TODO: Add your control notification handler code here
}


void CGeofence::draw_circle(double radius)
{
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CString js;
	// 1 mi = 1609.344 m;
	js.Format(_T("DrawCircle(%.2f);"), radius * 1609.344);

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CGeofence::draw_polygon(double side)
{
	if (pDoc == NULL)
		return;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return;

	CString js;
	js.Format(_T("DrawPolygon(%.2f);"), side);

	CComBSTR bstrJS = js.AllocSysString();
	CComBSTR bstrLanguage = SysAllocString(L"javascript");
	VARIANT varResult;
	pWin->execScript(bstrJS, bstrLanguage, &varResult);
}


void CGeofence::get_center(double * lat, double * lng)
{
	if (pDoc == NULL)
		return ;

	CComQIPtr<IHTMLWindow2> pWin;
	pDoc->get_parentWindow(&pWin);
	if (pWin == NULL)
		return ;

	static LPOLESTR strFxnLat = OLESTR("getCenterLat");
	static LPOLESTR strFxnLng = OLESTR("getCenterLng");
	CComPtr<IDispatch>pdispScript;
	if (SUCCEEDED(pDoc->get_Script(&pdispScript)) && pdispScript)
    {
        DISPID dispID;

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
}
