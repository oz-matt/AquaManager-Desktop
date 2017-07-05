#pragma once


// CDLGInfo dialog

class CDLGInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CDLGInfo)

public:
	CDLGInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDLGInfo();

// Dialog Data
	enum { IDD = IDD_DLG_Info };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_info;
};
