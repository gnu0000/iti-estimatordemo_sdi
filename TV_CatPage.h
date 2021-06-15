#if !defined(AFX_PROPPAGE2_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_PROPPAGE2_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TV_Sheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTV_CatPage dialog

class CTV_CatPage : public CPropertyPage
{
//	DECLARE_DYNCREATE(CTV_CatPage)

	CImageList		m_imageList;   // images for tree
	CSplitterWnd**	m_ppSplitter;		// sometimes right view has a splitter
	LONG*				m_pPaneType;		// type of window on right pane

public:
	CTV_CatPage(LONG* pPaneType, CSplitterWnd** ppSplitter);
	~CTV_CatPage();

	//{{AFX_DATA(CTV_CatPage)
	enum { IDD = IDD_PAGE2 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTV_CatPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CTV_CatPage)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void	Init();
	void	SwitchView(LONG lNewType);

};


/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPPAGE2_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
