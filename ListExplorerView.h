// ListExplorerView.h : interface of the CListExplorerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTEXPLORERVIEW_H__F9C82FEB_AE29_11DB_B910_C96B64896645__INCLUDED_)
#define AFX_LISTEXPLORERVIEW_H__F9C82FEB_AE29_11DB_B910_C96B64896645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CListExplorerView : public CListView
{
protected: // create from serialization only
	CListExplorerView();
	DECLARE_DYNCREATE(CListExplorerView)

// Attributes
public:
	CListExplorerDoc* GetDocument();
protected:
	CString root;
	CString root_copy;
	CString file_copy;
	int m_nitem;
	int m_dragTarget;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListExplorerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	DWORD m_Type;
	void SetListView(DWORD dwNewStyle);
	virtual ~CListExplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL m_bIsDragging;
// Generated message map functions
protected:
	int m_oper; //0 no op 1=copy -1=cat
	//{{AFX_MSG(CListExplorerView)
	afx_msg void OnIcon();
	afx_msg void OnReport();
	afx_msg void OnSmall();
	afx_msg void OnList();
	afx_msg void OnUpdateList(CCmdUI* pCmdUI);
	afx_msg void OnUpdateIcon(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReport(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSmall(CCmdUI* pCmdUI);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileDelete();
	afx_msg void OnFileCopyc();
	afx_msg void OnFilePaste();
	afx_msg void OnFileCut();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnFileCopyAs();
	afx_msg void OnFileMoveAs();
	afx_msg void OnCreateDirector();
	afx_msg void OnProperty();
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRename();
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ListExplorerView.cpp
inline CListExplorerDoc* CListExplorerView::GetDocument()
   { return (CListExplorerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTEXPLORERVIEW_H__F9C82FEB_AE29_11DB_B910_C96B64896645__INCLUDED_)
