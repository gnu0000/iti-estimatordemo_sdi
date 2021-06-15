#if !defined(AFX_DV_ESTPAGE3_H__977D1C63_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_DV_ESTPAGE3_H__977D1C63_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_EstPage3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage3 dialog

class CDV_EstPage3 : public CDynaPropPage
{
	DECLARE_DYNCREATE(CDV_EstPage3)

// Construction
public:
	CDV_EstPage3();
	~CDV_EstPage3();

// Dialog Data
	//{{AFX_DATA(CDV_EstPage3)
	enum { IDD = IDD_ESTIMATE3 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDV_EstPage3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDV_EstPage3)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DV_ESTPAGE3_H__977D1C63_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
