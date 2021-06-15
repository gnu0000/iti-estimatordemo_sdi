// EstDemoView.h : interface of the CEstDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPSHEET1VIEW_H__B7ABA5B9_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_PROPSHEET1VIEW_H__B7ABA5B9_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEstDemoView : public CView
{
protected: // create from serialization only
	CEstDemoView();
	DECLARE_DYNCREATE(CEstDemoView)

// Attributes
public:
	CEstDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEstDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEstDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEstDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EstDemoView.cpp
inline CEstDemoDoc* CEstDemoView::GetDocument()
   { return (CEstDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPSHEET1VIEW_H__B7ABA5B9_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
