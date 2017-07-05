#pragma once


// CSelectTrigger dialog

class CSelectTrigger : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTrigger)

public:
	CSelectTrigger(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectTrigger();

// Dialog Data
	enum { IDD = IDD_DLG_SelectTrigger };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CCheckListBox m_select_trigger;
	afx_msg void OnBnClickedOk();

	int count;
};
