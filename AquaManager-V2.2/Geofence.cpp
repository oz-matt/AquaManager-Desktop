// Geofence.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Geofence.h"
#include "afxdialogex.h"


// CGeofence dialog

IMPLEMENT_DYNAMIC(CGeofence, CDialog)

CGeofence::CGeofence(CWnd* pParent /*=NULL*/)
	: CDialog(CGeofence::IDD, pParent)
{
	m_lst_geofence.type = 2;
}

CGeofence::~CGeofence()
{
}

void CGeofence::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Geofence, m_lst_geofence);
}


BEGIN_MESSAGE_MAP(CGeofence, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGeofence message handlers


BOOL CGeofence::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// Add some columns to the list control
	m_lst_geofence.InsertColumn( 0, _T("Name") );
	m_lst_geofence.InsertColumn( 1, _T("Centered In") );
	m_lst_geofence.InsertColumn( 2, _T("Size") );

	// Set the column widths
	m_lst_geofence.SetColumnWidth( 0, 70 );
	m_lst_geofence.SetColumnWidth( 1, 70 );
	m_lst_geofence.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	nIndex = m_lst_geofence.InsertItem(0, _T("Geo1"));
	m_lst_geofence.SetItemText(nIndex, 1, _T("15th St, New York, NY, USA"));
	m_lst_geofence.SetItemText(nIndex, 2, _T("180 sq.mi"));

	nIndex = m_lst_geofence.InsertItem(0, _T("Geo2"));
	m_lst_geofence.SetItemText(nIndex, 1, _T("15th St, New York, NY, USA"));
	m_lst_geofence.SetItemText(nIndex, 2, _T("6 sq.mi"));

	m_lst_geofence.SetBkColor(RGB(0, 0, 0));

	m_brush.CreateSolidBrush(RGB(0, 0, 0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CGeofence::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
