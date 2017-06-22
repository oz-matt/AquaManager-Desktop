#pragma once


// CAddPolygon dialog

class CAddPolygon : public CDialogEx
{
	DECLARE_DYNAMIC(CAddPolygon)

public:
	CAddPolygon(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAddPolygon();

// Dialog Data
	enum { IDD = IDD_DLG_AddPolygon };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_side;
};
