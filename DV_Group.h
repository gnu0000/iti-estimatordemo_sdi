#if !defined(AFX_GROUPVIEW_H__7D021DD8_DA42_11D3_B4E2_005004D39EC7__INCLUDED_)
#define AFX_GROUPVIEW_H__7D021DD8_DA42_11D3_B4E2_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_Group.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDV_Group form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "ugctrl.h"



class CDV_Group : public CDynaFormView
{
	CUGCtrl		m_itemGrid;

protected:
	CDV_Group();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDV_Group)

// Form Data
public:
	//{{AFX_DATA(CDV_Group)
	enum { IDD = IDD_GROUP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDV_Group)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDV_Group();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDV_Group)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPVIEW_H__7D021DD8_DA42_11D3_B4E2_005004D39EC7__INCLUDED_)
