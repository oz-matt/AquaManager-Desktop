// DlgNoGeofence.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgNoGeofence.h"
#include "afxdialogex.h"


// CDlgNoGeofence dialog

IMPLEMENT_DYNAMIC(CDlgNoGeofence, CDialogEx)

CDlgNoGeofence::CDlgNoGeofence(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNoGeofence::IDD, pParent)
{

	m_nogeofence = _T("");
}

CDlgNoGeofence::~CDlgNoGeofence()
{
}

void CDlgNoGeofence::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT_NoGeofence, m_nogeofence);
	DDX_Text(pDX, IDC_EDIT_NoGeofence, m_nogeofence);
}


BEGIN_MESSAGE_MAP(CDlgNoGeofence, CDialogEx)
END_MESSAGE_MAP()


// CDlgNoGeofence message handlers


BOOL CDlgNoGeofence::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_nogeofence = "Create at least one geofence to use this function";

	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
