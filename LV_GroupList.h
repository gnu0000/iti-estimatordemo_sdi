#if !defined(AFX_GROUPLISTVIEW_H__512AFB48_DB11_11D3_B4E3_005004D39EC7__INCLUDED_)
#define AFX_GROUPLISTVIEW_H__512AFB48_DB11_11D3_B4E3_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LV_GroupList.h : header file
//


#include "ugctrl.h"


/////////////////////////////////////////////////////////////////////////////
// CLV_GroupList window

class CLV_GroupList : public CView
{
	DECLARE_DYNCREATE(CLV_GroupList)

	CUGCtrl		m_grid;

// Construction
public:
	CLV_GroupList();

// Attributes
public:

// Operations
public:
	void	Init();

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLV_GroupList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLV_GroupList();

	virtual void OnDraw( CDC* pDC )		{}

	// Generated message map functions
protected:
	//{{AFX_MSG(CLV_GroupList)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPLISTVIEW_H__512AFB48_DB11_11D3_B4E3_005004D39EC7__INCLUDED_)
