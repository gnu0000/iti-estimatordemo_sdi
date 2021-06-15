#if !defined(AFX_ITEMVIEW_H__91169141_DAFE_11D3_829C_0050DA0C5DE1__INCLUDED_)
#define AFX_ITEMVIEW_H__91169141_DAFE_11D3_829C_0050DA0C5DE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_Item.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDV_Item dialog

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "ugctrl.h"



class CDV_Item : public CDynaFormView
{


protected:
	CDV_Item();
	DECLARE_DYNCREATE(CDV_Item)

// Construction
public:
	//{{AFX_DATA(CDV_Item)
	enum { IDD = IDD_ESTITEM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDV_Item)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDV_Item)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ITEMVIEW_H__91169141_DAFE_11D3_829C_0050DA0C5DE1__INCLUDED_)
