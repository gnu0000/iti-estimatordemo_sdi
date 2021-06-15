#if !defined(AFX_BLANK_H__B7ABA5C4_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_BLANK_H__B7ABA5C4_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// DV_Blank.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDV_Blank form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDV_Blank : public CFormView
{
protected:
	CDV_Blank();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDV_Blank)

// Form Data
public:
	//{{AFX_DATA(CDV_Blank)
	enum { IDD = IDD_BLANK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

public:

	//{{AFX_VIRTUAL(CDV_Blank)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	virtual ~CDV_Blank();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	//{{AFX_MSG(CDV_Blank)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLANK_H__B7ABA5C4_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
