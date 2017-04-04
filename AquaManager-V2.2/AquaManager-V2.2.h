
// AquaManager-V2.2.h : main header file for the AquaManager-V2.2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CAquaManagerV22App:
// See AquaManager-V2.2.cpp for the implementation of this class
//

class CAquaManagerV22App : public CWinAppEx
{
public:
	CAquaManagerV22App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAquaManagerV22App theApp;
