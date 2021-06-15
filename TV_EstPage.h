#if !defined(AFX_PROPPAGE1_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
#define AFX_PROPPAGE1_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TV_Sheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTV_EstPage dialog

class CTV_EstPage : public CPropertyPage
{
	CImageList		m_imageList;   // images for tree
	CSplitterWnd**	m_ppSplitter;		// sometimes right view has a splitter
	LONG*				m_pPaneType;		// type of window on right pane

// Construction
public:
	CTV_EstPage(LONG* pPaneType, CSplitterWnd** ppSplitter);
	~CTV_EstPage();

	//{{AFX_DATA(CTV_EstPage)
	enum { IDD = IDD_PAGE1 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTV_EstPage)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CTV_EstPage)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint( );
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void	Init();
	void	SwitchView(LONG lNewType);
};



/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPPAGE1_H__B7ABA5C1_AE3E_11D3_B4B9_005004D39EC7__INCLUDED_)
