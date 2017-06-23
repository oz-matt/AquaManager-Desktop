// GeofenceRemove.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "GeofenceRemove.h"
#include "afxdialogex.h"


// CGeofenceRemove dialog

IMPLEMENT_DYNAMIC(CGeofenceRemove, CDialogEx)

CGeofenceRemove::CGeofenceRemove(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeofenceRemove::IDD, pParent)
{

	m_remove = _T("");
}

CGeofenceRemove::~CGeofenceRemove()
{
}

void CGeofenceRemove::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Remove, m_remove);
}


BEGIN_MESSAGE_MAP(CGeofenceRemove, CDialogEx)
END_MESSAGE_MAP()


// CGeofenceRemove message handlers


BOOL CGeofenceRemove::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_remove = "Are you sure you want to remove this entry,\r\n along with all associated notifications?";
	UpdateData(False);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
