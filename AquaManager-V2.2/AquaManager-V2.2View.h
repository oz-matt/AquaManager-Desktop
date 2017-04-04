
// AquaManager-V2.2View.h : interface of the CAquaManagerV22View class
//

#pragma once


class CAquaManagerV22View : public CHtmlView
{
protected: // create from serialization only
	CAquaManagerV22View();
	DECLARE_DYNCREATE(CAquaManagerV22View)

// Attributes
public:
	CAquaManagerV22Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CAquaManagerV22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	void Init(void);
};

#ifndef _DEBUG  // debug version in AquaManager-V2.2View.cpp
inline CAquaManagerV22Doc* CAquaManagerV22View::GetDocument() const
   { return reinterpret_cast<CAquaManagerV22Doc*>(m_pDocument); }
#endif

