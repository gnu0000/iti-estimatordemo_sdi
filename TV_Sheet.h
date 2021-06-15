#if !defined(AFX_PROPSHEET_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_PROPSHEET_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TV_Sheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTV_Sheet

class CTV_Sheet : public CResizingPropSheet
{
	DECLARE_DYNAMIC(CTV_Sheet)

	CTV_EstPage		m_page1;
	CTV_CatPage		m_page2;
	LONG				   m_lPaneType;		// type of window on right pane
	CSplitterWnd*	   m_pSplitter;		// sometimes right view has a splitter

public:
	CTV_Sheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CTV_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

	//{{AFX_VIRTUAL(CTV_Sheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

public:
	virtual ~CTV_Sheet();

protected:
	//{{AFX_MSG(CTV_Sheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void	Init();
};


/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEET_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
