#if !defined(AFX_ESTVIEWSHEET_H__977D1C47_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_ESTVIEWSHEET_H__977D1C47_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_Sheet.h : header file
//
#include "ResizingPropSheet.h"
#include "DV_EstPage1.h"
#include "DV_EstPage2.h"
#include "DV_EstPage3.h"


/////////////////////////////////////////////////////////////////////////////
// CDV_Sheet

class CDV_Sheet : public CResizingPropSheet
{
	DECLARE_DYNAMIC(CDV_Sheet)

// Construction
public:
	CDV_Sheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CDV_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

	void CDV_Sheet::Init();

// Attributes
public:
	CDV_EstPage1 m_cPage1;
	CDV_EstPage2 m_cPage2;
	CDV_EstPage3 m_cPage3;
//	CEstDemoDoc  *m_pDocument;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDV_Sheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDV_Sheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDV_Sheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESTVIEWSHEET_H__977D1C47_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
