#if !defined(AFX_NAME_H__EA6C6543_B11A_11DB_B910_FB091DEB784F__INCLUDED_)
#define AFX_NAME_H__EA6C6543_B11A_11DB_B910_FB091DEB784F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Name.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CName dialog

class CName : public CDialog
{
// Construction
public:
	CName(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CName)
	enum { IDD = IDD_Name };
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CName)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAME_H__EA6C6543_B11A_11DB_B910_FB091DEB784F__INCLUDED_)
