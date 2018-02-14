// ListExplorerDoc.h : interface of the CListExplorerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTEXPLORERDOC_H__F9C82FE9_AE29_11DB_B910_C96B64896645__INCLUDED_)
#define AFX_LISTEXPLORERDOC_H__F9C82FE9_AE29_11DB_B910_C96B64896645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CListExplorerDoc : public CDocument
{
protected: // create from serialization only
	CListExplorerDoc();
	DECLARE_DYNCREATE(CListExplorerDoc)
	CImageList m_imageLarge;
	CImageList m_imageSmall;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListExplorerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListExplorerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CListExplorerDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTEXPLORERDOC_H__F9C82FE9_AE29_11DB_B910_C96B64896645__INCLUDED_)
