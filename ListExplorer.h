// ListExplorer.h : main header file for the LISTEXPLORER application
//

#if !defined(AFX_LISTEXPLORER_H__F9C82FE3_AE29_11DB_B910_C96B64896645__INCLUDED_)
#define AFX_LISTEXPLORER_H__F9C82FE3_AE29_11DB_B910_C96B64896645__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CListExplorerApp:
// See ListExplorer.cpp for the implementation of this class
//

class CListExplorerApp : public CWinApp
{
public:
	CListExplorerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListExplorerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CListExplorerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTEXPLORER_H__F9C82FE3_AE29_11DB_B910_C96B64896645__INCLUDED_)
