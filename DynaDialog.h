#if !defined(AFX_DYNADIALOG_H__977D1C5E_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
#define AFX_DYNADIALOG_H__977D1C5E_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

// DynaDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////

#define DT_MOVER 0x01 // Move relative to rt edge
#define DT_SIZER 0x02 // Size relative to rt edge
#define DT_MOVEB 0x04 // Move relative to bottom edge
#define DT_SIZEB 0x08 // Size relative to bottom edge

//#define IDC_MR 5001
//#define IDC_SR	5002
//#define IDC_MB	5003
//#define IDC_SB	5004


class CCtlInfo: public CObject
	{
public:
	int iDynaType;
	int iXGap;
	int iXMinPos;
	int iYGap;
	int iYMinPos;
	};
// todo: cleanup!!!


typedef CMap<HWND,HWND,CCtlInfo*,CCtlInfo*&> CMapCtlInfo;

class CDynaInfo
	{
	public:

	CDynaInfo ();
	~CDynaInfo ();
	CMapCtlInfo m_mapCtlInfo;
	BOOL m_bInitialized;
	BOOL Init (CDialog *pDlg);
	void Size (CDialog *pDlg);
	};


/////////////////////////////////////////////////////////////////////////////
// CDynaDialog dialog

class CDynaDialog : public CDialog
{
// Construction
public:
	CDynaDialog(CWnd* pParent = NULL);   // standard constructor
	CDynaDialog(CWnd* pParent, UINT nIDTemplate); // standard constructor
//	BOOL Init ();
	void Size ();
	
	CDynaInfo m_cDynaInfo;

	//{{AFX_DATA(CDynaDialog)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDynaDialog)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDynaDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////
// CDynaFormView form view

class CDynaFormView : public CFormView
{
protected:
	CDynaFormView();           // protected constructor used by dynamic creation
	CDynaFormView(UINT nIDTemplate);
		
	DECLARE_DYNCREATE(CDynaFormView)
 	CDynaInfo m_cDynaInfo;

public:
	//{{AFX_DATA(CDynaFormView)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDynaFormView)
public:
	virtual void OnInitialUpdate();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	virtual ~CDynaFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	//{{AFX_MSG(CDynaFormView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////
// CDynaPropPage dialog

class CDynaPropPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDynaPropPage)

public:
	CDynaPropPage();
	CDynaPropPage(UINT nIDTemplate);
	~CDynaPropPage();

//	void Init ();

	CDynaInfo m_cDynaInfo;

	//{{AFX_DATA(CDynaPropPage)
	enum { IDD = 0 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDynaPropPage)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDynaPropPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNADIALOG_H__977D1C5E_DBEC_11D3_91D9_AB50FD7CBB26__INCLUDED_)
