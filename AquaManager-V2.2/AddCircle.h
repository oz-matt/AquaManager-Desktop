#pragma once


// CAddCircle dialog

class CAddCircle : public CDialogEx
{
	DECLARE_DYNAMIC(CAddCircle)

public:
	CAddCircle(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddCircle();

// Dialog Data
	enum { IDD = IDD_DLG_AddCircle };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_radius;
};
