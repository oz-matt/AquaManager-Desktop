// DlgAddGeofence.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgAddGeofence.h"
#include "afxdialogex.h"

CString g_geo_name;
int g_radius;
BOOL g_circle;
BOOL g_polygon;

// CDlgAddGeofence dialog

IMPLEMENT_DYNAMIC(CDlgAddGeofence, CDialogEx)

CDlgAddGeofence::CDlgAddGeofence(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddGeofence::IDD, pParent)
{

	m_geo_name = _T("");
	m_radius = _T("");
	m_radius_int = 0;
	m_radius_double = 0.0;
}

CDlgAddGeofence::~CDlgAddGeofence()
{
}

void CDlgAddGeofence::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GeoName, m_geo_name);
	DDX_Text(pDX, IDC_EDIT_Radius, m_radius);
	DDX_Check(pDX, IDC_CHECK_Circle, m_circle);
	DDX_Check(pDX, IDC_CHECK_Polygon, m_polygon);
	DDX_Text(pDX, IDC_EDIT_Radius, m_radius_int);
	DDX_Text(pDX, IDC_EDIT_Radius, m_radius_double);
}


BEGIN_MESSAGE_MAP(CDlgAddGeofence, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgAddGeofence::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddGeofence message handlers


void CDlgAddGeofence::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(True);

	g_geo_name = m_geo_name;
	g_radius = m_radius_int;
	g_circle = m_circle;
	g_polygon = m_polygon;

	CDialogEx::OnOK();
}


BOOL CDlgAddGeofence::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
