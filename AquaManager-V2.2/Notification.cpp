// Notification.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "Notification.h"
#include "afxdialogex.h"


// CNotification dialog

IMPLEMENT_DYNAMIC(CNotification, CDialog)

CNotification::CNotification(CWnd* pParent /*=NULL*/)
	: CDialog(CNotification::IDD, pParent)
{
	m_lst_notificaton.type = 1;
}

CNotification::~CNotification()
{
}

void CNotification::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_Notification, m_lst_notificaton);
}


BEGIN_MESSAGE_MAP(CNotification, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CNotification message handlers


BOOL CNotification::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	// Add some columns to the list control
	m_lst_notificaton.InsertColumn( 0, _T("Device Name") );
	m_lst_notificaton.InsertColumn( 1, _T("Trigger") );
	m_lst_notificaton.InsertColumn( 2, _T("Alarm") );

	// Set the column widths
	m_lst_notificaton.SetColumnWidth( 0, 70 );
	m_lst_notificaton.SetColumnWidth( 1, 70 );
	m_lst_notificaton.SetColumnWidth( 2, LVSCW_AUTOSIZE_USEHEADER );

	nIndex = m_lst_notificaton.InsertItem(0, _T("Dev2"));
	m_lst_notificaton.SetItemText(nIndex, 1, _T("entersGeo"));
	m_lst_notificaton.SetItemText(nIndex, 2, _T("e-mail"));

	nIndex = m_lst_notificaton.InsertItem(0, _T("Dev4"));
	m_lst_notificaton.SetItemText(nIndex, 1, _T("uploadsData"));
	m_lst_notificaton.SetItemText(nIndex, 2, _T("text"));

	m_lst_notificaton.SetBkColor(RGB(0, 0, 0));

	m_brush.CreateSolidBrush(RGB(0, 0, 0));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CNotification::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	HBRUSH hbr = m_brush;

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
