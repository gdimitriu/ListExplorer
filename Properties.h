#if !defined(AFX_PROPERTIES_H__EA6C6544_B11A_11DB_B910_FB091DEB784F__INCLUDED_)
#define AFX_PROPERTIES_H__EA6C6544_B11A_11DB_B910_FB091DEB784F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Properties.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProperties dialog

class CProperties : public CDialog
{
// Construction
public:
	BOOL SetFiles(LPSTR file);
	CProperties(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProperties)
	enum { IDD = IDD_PROPERTIES };
	CString	m_name;
	BOOL	m_directory;
	BOOL	m_archive;
	BOOL	m_hidden;
	BOOL	m_compressed;
	BOOL	m_readonly;
	BOOL	m_sparse;
	BOOL	m_system;
	BOOL	m_normal;
	BOOL	m_encrypted;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProperties)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIES_H__EA6C6544_B11A_11DB_B910_FB091DEB784F__INCLUDED_)
