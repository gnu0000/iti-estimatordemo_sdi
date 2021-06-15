#if !defined(AFX_ESTVIEW_H__977D1C46_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_ESTVIEW_H__977D1C46_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_Est.h : header file
//


#include "DV_Sheet.h"

/////////////////////////////////////////////////////////////////////////////
// CDV_Est view

class CDV_Est : public CView
{
protected:
	CDV_Est();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDV_Est)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDV_Est)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDV_Est();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CDV_Est)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESTVIEW_H__977D1C46_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
