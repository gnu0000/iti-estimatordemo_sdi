#if !defined(AFX_ESTVIEWPAGE2_H__977D1C49_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_ESTVIEWPAGE2_H__977D1C49_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_EstPage2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage2 dialog

class CDV_EstPage2 : public CDynaPropPage
{
	DECLARE_DYNCREATE(CDV_EstPage2)

// Construction
public:
	CDV_EstPage2();
	~CDV_EstPage2();

// Dialog Data
	//{{AFX_DATA(CDV_EstPage2)
	enum { IDD = IDD_ESTIMATE2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CDV_EstPage2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDV_EstPage2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESTVIEWPAGE2_H__977D1C49_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
