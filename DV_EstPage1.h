#if !defined(AFX_ESTVIEWPAGE1_H__977D1C48_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_ESTVIEWPAGE1_H__977D1C48_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DV_EstPage1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDV_EstPage1 dialog

class CDV_EstPage1 : public CDynaPropPage
{
	DECLARE_DYNCREATE(CDV_EstPage1)

public:
	CDV_EstPage1();
	~CDV_EstPage1();

	CEstimate *GetEstimate();

	//{{AFX_DATA(CDV_EstPage1)
	enum { IDD = IDD_ESTIMATE1 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDV_EstPage1)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDV_EstPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillFocusSetData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ESTVIEWPAGE1_H__977D1C48_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
