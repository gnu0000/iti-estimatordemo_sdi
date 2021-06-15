// EstDemo.h : main header file for the PROPSHEET1 application
//

#if !defined(AFX_PROPSHEET1_H__B7ABA5B1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_PROPSHEET1_H__B7ABA5B1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEstDemoApp:
// See EstDemo.cpp for the implementation of this class
//

class CEstDemoApp : public CWinApp
{
public:
	CEstDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEstDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEstDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEET1_H__B7ABA5B1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
