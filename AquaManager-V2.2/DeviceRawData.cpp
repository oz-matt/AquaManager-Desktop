// DeviceRawData.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DeviceRawData.h"
#include "afxdialogex.h"
#include "DeviceRawDataShow.h"

// CDeviceRawData dialog
extern double g_m_previous_lat;
extern double g_m_previous_lng;
extern double g_m_current_lat;
extern double g_m_current_lng;
extern CString g_m_previous_time;
extern CString g_m_current_time;
extern CString g_m_previous_location;
extern CString g_m_current_location;
extern CString g_m_aqsense_data[10];
extern CString g_m_aqsense_data_head[10];
extern int g_m_aqsense_count;

IMPLEMENT_DYNAMIC(CDeviceRawData, CDialogEx)

CDeviceRawData::CDeviceRawData(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeviceRawData::IDD, pParent)
{

	m_raw_data_val = _T("");
}

CDeviceRawData::~CDeviceRawData()
{
}

void CDeviceRawData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_RawData, m_raw_data);
	DDX_LBString(pDX, IDC_LIST_RawData, m_raw_data_val);
}


BEGIN_MESSAGE_MAP(CDeviceRawData, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_LBN_DBLCLK(IDC_LIST_RawData, &CDeviceRawData::OnLbnDblclkListRawdata)
END_MESSAGE_MAP()


// CDeviceRawData message handlers


BOOL CDeviceRawData::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	for( int i = 0; i < g_m_aqsense_count; i++) {
		this->m_raw_data.AddString(g_m_aqsense_data_head[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDeviceRawData::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// it's for dialog double click, not listbox
	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CDeviceRawData::OnLbnDblclkListRawdata()
{
	// TODO: Add your control notification handler code here
	int nItem = m_raw_data.GetCurSel();

	CDeviceRawDataShow dlg;
	dlg.m_raw_data_show = g_m_aqsense_data[nItem];
	UpdateData(False);
	dlg.DoModal();
}
