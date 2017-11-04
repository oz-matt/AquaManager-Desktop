#pragma once
#include "ColorListCtrol.h"

#include <string>

using namespace std;

struct _notify_data {
	string device_name;
	string trigger;
	string trigger_freq;
	string alert;
	string alert_target;
};

typedef struct _notify_data notify_data;

// CNotification dialog

class CNotification : public CDialog, public IDispatch
{
	DECLARE_DYNAMIC(CNotification)

public:
	CNotification(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNotification();

// Dialog Data
	enum { IDD = IDD_DLG_Notification };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CColorListCtrol m_lst_notificaton;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	int nIndex;
	CImageList *ImgHeaders;
	afx_msg void OnBnClickedBtnNewnotify();
	CMFCButton m_btn_newNotify;

	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo);
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
	virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
		WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();

	DWORD GetProcessID();
	void ShowMessageBox(const wchar_t *msg);
};
