#if !defined(AFX_RESIZINGPROPSHEET_H__977D1C43_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_RESIZINGPROPSHEET_H__977D1C43_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResizingPropSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResizingPropSheet

class CResizingPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CResizingPropSheet)

// Construction
public:
	CResizingPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CResizingPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	void ResizeSheet (CRect &rNewSize);

// Attributes
public:
	CRect	m_rTabDelta;
	CRect	m_rPageDelta;
	BOOL	m_bMetricsStored;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResizingPropSheet)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL StoreMetrics ();
	virtual ~CResizingPropSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CResizingPropSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESIZINGPROPSHEET_H__977D1C43_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
