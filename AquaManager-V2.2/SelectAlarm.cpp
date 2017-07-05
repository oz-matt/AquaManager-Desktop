// SelectAlarm.cpp : implementation file
//

#include "stdafx.h"
#include "AquaManager-V2.2.h"
#include "SelectAlarm.h"
#include "afxdialogex.h"


// CSelectAlarm dialog
int g_m_select_alarm_notif;
CString g_m_select_alarm_notif_name;

IMPLEMENT_DYNAMIC(CSelectAlarm, CDialogEx)

CSelectAlarm::CSelectAlarm(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectAlarm::IDD, pParent)
{
	count = 0;
}

CSelectAlarm::~CSelectAlarm()
{
}

void CSelectAlarm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Alarm, m_alarm);
}


BEGIN_MESSAGE_MAP(CSelectAlarm, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelectAlarm::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectAlarm message handlers


BOOL CSelectAlarm::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_alarm.SubclassDlgItem(IDD_DLG_SelectAlarm, this);
	m_alarm.SetCheckStyle(BS_AUTOCHECKBOX);

	m_alarm.InsertString(count++, "Text Message");
	m_alarm.InsertString(count++, "E-Mail");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSelectAlarm::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	int iState;

	for (int i = 0; i < count; i++) {
		iState = m_alarm.GetCheck(i);
		if (iState == 1) {
			g_m_select_alarm_notif = i;
			m_alarm.GetText(i, g_m_select_alarm_notif_name);
			break;
		}
	}

	CDialogEx::OnOK();
}
