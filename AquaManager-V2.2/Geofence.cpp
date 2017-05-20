// Geofence.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Geofence.h"
#include "afxdialogex.h"

#include "DlgAddGeofence.h"

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
}


BEGIN_MESSAGE_MAP(CGeofence, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_Geofence, &CGeofence::OnBnClickedBtnGeofence)
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
	m_lst_geofence.InsertColumn(1, &lvColumn);

	// Add some columns to the list control
	//m_lst_geofence.InsertColumn( 0, _T("Name") );
	//m_lst_geofence.InsertColumn( 1, _T("Centered In") );
	//m_lst_geofence.InsertColumn( 2, _T("Size") );

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

	m_lst_geofence.SetBkColor(RGB(255, 255, 255));

	m_brush.CreateSolidBrush(RGB(255, 255, 255));

	m_btn_geofence.SetFaceColor(RGB(255, 255, 255), true);
	m_btn_geofence.SetTextColor(RGB(0, 0, 255));

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


void CGeofence::OnBnClickedBtnGeofence()
{
	// TODO: Add your control notification handler code here

	CDlgAddGeofence dlg;
	dlg.DoModal();
}
