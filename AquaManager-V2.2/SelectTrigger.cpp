// SelectTrigger.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "SelectTrigger.h"
#include "afxdialogex.h"


// CSelectTrigger dialog
int g_m_select_trigger_notif;
CString g_m_select_trigger_notif_name;

IMPLEMENT_DYNAMIC(CSelectTrigger, CDialogEx)

CSelectTrigger::CSelectTrigger(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectTrigger::IDD, pParent)
{
	count = 0;
}

CSelectTrigger::~CSelectTrigger()
{
}

void CSelectTrigger::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Trigger, m_select_trigger);
}


BEGIN_MESSAGE_MAP(CSelectTrigger, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelectTrigger::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectTrigger message handlers


BOOL CSelectTrigger::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_select_trigger.SubclassDlgItem(IDD_DLG_SelectTrigger, this);
	m_select_trigger.SetCheckStyle(BS_AUTOCHECKBOX);

	m_select_trigger.InsertString(count++, "Low Battery");
	m_select_trigger.InsertString(count++, "Enters Geofence");
	m_select_trigger.InsertString(count++, "Exits Geofence");
	m_select_trigger.InsertString(count++, "Uploads Data");
	m_select_trigger.InsertString(count++, "See Mac Address");
	m_select_trigger.InsertString(count++, "Starts Moving");
	m_select_trigger.InsertString(count++, "Stops Moving");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSelectTrigger::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	int iState;

	for (int i = 0; i < count; i++) {
		iState = m_select_trigger.GetCheck(i);
		if (iState == 1) {
			g_m_select_trigger_notif = i;
			m_select_trigger.GetText(i, g_m_select_trigger_notif_name);
			break;
		}
	}

	CDialogEx::OnOK();
}
