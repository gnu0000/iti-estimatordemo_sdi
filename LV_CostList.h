#if !defined(AFX_COSTLISTVIEW_H__512AFB4A_DB11_11D3_B4E3_005004D39EC7__INCLUDED_)
#define AFX_COSTLISTVIEW_H__512AFB4A_DB11_11D3_B4E3_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LV_CostList.h : header file
//

#include "ugctrl.h"


/////////////////////////////////////////////////////////////////////////////
// CLV_CostList view

class CLV_CostList : public CView
{
	CUGCtrl		m_grid;

protected:
	CLV_CostList();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLV_CostList)

public:
	void	Init();

	//{{AFX_VIRTUAL(CLV_CostList)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

protected:
	virtual ~CLV_CostList();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//{{AFX_MSG(CLV_CostList)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COSTLISTVIEW_H__512AFB4A_DB11_11D3_B4E3_005004D39EC7__INCLUDED_)
