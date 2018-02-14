// Name.cpp : implementation file
//

#include "stdafx.h"
#include "ListExplorer.h"
#include "Name.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CName dialog


CName::CName(CWnd* pParent /*=NULL*/)
	: CDialog(CName::IDD, pParent)
{
	//{{AFX_DATA_INIT(CName)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CName)
	DDX_Text(pDX, IDC_name, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CName, CDialog)
	//{{AFX_MSG_MAP(CName)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CName message handlers
