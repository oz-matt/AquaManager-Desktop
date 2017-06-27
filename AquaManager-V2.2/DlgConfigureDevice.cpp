// DlgConfigureDevice.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgConfigureDevice.h"
#include "afxdialogex.h"


// CDlgConfigureDevice dialog

IMPLEMENT_DYNAMIC(CDlgConfigureDevice, CDialogEx)

CDlgConfigureDevice::CDlgConfigureDevice(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgConfigureDevice::IDD, pParent)
{

	m_name = _T("");
	m_pct_battery = _T("");
	m_marker_color_val = _T("");
	m_temperature = _T("");
	m_humidity = _T("");
	m_height = _T("");
	m_speed = _T("");
	m_direction = _T("");
	m_numsat = _T("");
	m_phone = _T("");
	m_aquaid = _T("");
	//  m_passcode = _T("");
	m_aquakey = _T("");
}

CDlgConfigureDevice::~CDlgConfigureDevice()
{
}

void CDlgConfigureDevice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Name, m_name);
	DDX_Text(pDX, IDC_EDIT_Battery, m_pct_battery);
	DDX_CBString(pDX, IDC_COMBO_MarkerColor, m_marker_color_val);
	DDX_Control(pDX, IDC_COMBO_MarkerColor, m_marker_color_ctl);
	DDX_Text(pDX, IDC_EDIT_Temperature, m_temperature);
	DDX_Text(pDX, IDC_EDIT_Humidity, m_humidity);
	DDX_Text(pDX, IDC_EDIT_Height, m_height);
	DDX_Text(pDX, IDC_EDIT_Speed, m_speed);
	DDX_Text(pDX, IDC_EDIT_Direction, m_direction);
	DDX_Text(pDX, IDC_EDIT_Satelittes, m_numsat);
	DDX_Text(pDX, IDC_EDIT_Phone_Number, m_phone);
	DDX_Text(pDX, IDC_EDIT_Aqua_ID, m_aquaid);
	//  DDX_Text(pDX, IDC_EDIT_Aqua_Key, m_passcode);
	DDX_Text(pDX, IDC_EDIT_Aqua_Key, m_aquakey);
}


BEGIN_MESSAGE_MAP(CDlgConfigureDevice, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgConfigureDevice::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_MarkerColor, &CDlgConfigureDevice::OnCbnSelchangeComboMarkercolor)
END_MESSAGE_MAP()


// CDlgConfigureDevice message handlers


void CDlgConfigureDevice::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


BOOL CDlgConfigureDevice::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_marker_color_ctl.AddString("Red");
	m_marker_color_ctl.AddString("Blue");
	m_marker_color_ctl.AddString("Green");
	m_marker_color_ctl.AddString("Orange");
	m_marker_color_ctl.AddString("Violet");
	m_marker_color_ctl.AddString("Rose");
	m_marker_color_ctl.AddString("Magenta");
	m_marker_color_ctl.AddString("Azure");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgConfigureDevice::OnCbnSelchangeComboMarkercolor()
{
	// TODO: Add your control notification handler code here
}
