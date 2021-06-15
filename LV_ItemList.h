#if !defined(AFX_ITEMLISTVIEW_H__512AFB49_DB11_11D3_B4E3_005004D39EC7__INCLUDED_)
#define AFX_ITEMLISTVIEW_H__512AFB49_DB11_11D3_B4E3_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LV_ItemList.h : header file
//

#include "ugctrl.h"


/////////////////////////////////////////////////////////////////////////////
// CLV_ItemList view

class CLV_ItemList : public CView
{
	CUGCtrl		m_grid;

protected:
	CLV_ItemList();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLV_ItemList)

// Attributes
public:

// Operations
public:
	void	Init();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLV_ItemList)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLV_ItemList();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLV_ItemList)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMLISTVIEW_H__512AFB49_DB11_11D3_B4E3_005004D39EC7__INCLUDED_)
