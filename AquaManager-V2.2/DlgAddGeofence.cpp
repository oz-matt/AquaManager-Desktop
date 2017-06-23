// DlgAddGeofence.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "DlgAddGeofence.h"
#include "afxdialogex.h"


// CDlgAddGeofence dialog

IMPLEMENT_DYNAMIC(CDlgAddGeofence, CDialogEx)

CDlgAddGeofence::CDlgAddGeofence(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddGeofence::IDD, pParent)
{

}

CDlgAddGeofence::~CDlgAddGeofence()
{
}

void CDlgAddGeofence::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAddGeofence, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgAddGeofence::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddGeofence message handlers


void CDlgAddGeofence::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
