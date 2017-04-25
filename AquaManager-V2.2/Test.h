#pragma once

struct url_data {
    size_t size;
    char* data;
};

char * handle_url(char * url);
size_t write_data(void * ptr, size_t size, size_t nmemb, struct url_data * data);
// CTest dialog

class CTest : public CDialogEx
{
	DECLARE_DYNAMIC(CTest)

public:
	CTest(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTest();

// Dialog Data
	enum { IDD = IDD_DLG_Test };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSetcenter();
	afx_msg void OnBnClickedBtnAddmarker();
	afx_msg void OnBnClickedBtnSetzoom();
	afx_msg void OnBnClickedBtnDeletemarkers();
	afx_msg void OnBnClickedBtnAuth();
	char * handle_url_fields(char * url, char * fields);
	afx_msg void OnBnClickedBtnGetaqsens();
	afx_msg void OnBnClickedBtnNotifcircle();
	afx_msg void OnBnClickedBtnNotifpolygon();
	afx_msg void OnBnClickedBtnNotiflowbat();
	afx_msg void OnBnClickedBtnNotifoutcircle();
	afx_msg void OnBnClickedBtnNotifoutpolygon();
	afx_msg void OnBnClickedBtnNotifseemac();
	afx_msg void OnBnClickedBtnNotifstartmov();
	afx_msg void OnBnClickedBtnNotifstopmov();
	afx_msg void OnBnClickedBtnNotifuploaddata();
	afx_msg void OnBnClickedBtnRemovenotif();
};
