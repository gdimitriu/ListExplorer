// Properties.cpp : implementation file
//

#include "stdafx.h"
#include "ListExplorer.h"
#include "Properties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProperties dialog


CProperties::CProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProperties)
	m_name = _T("");
	m_directory = FALSE;
	m_archive = FALSE;
	m_hidden = FALSE;
	m_compressed = FALSE;
	m_readonly = FALSE;
	m_sparse = FALSE;
	m_system = FALSE;
	m_normal = FALSE;
	m_encrypted = FALSE;
	//}}AFX_DATA_INIT
}


void CProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProperties)
	DDX_Text(pDX, IDC_name, m_name);
	DDX_Check(pDX, IDC_directory, m_directory);
	DDX_Check(pDX, IDC_archive, m_archive);
	DDX_Check(pDX, IDC_hidden, m_hidden);
	DDX_Check(pDX, IDC_compressed, m_compressed);
	DDX_Check(pDX, IDC_readonly, m_readonly);
	DDX_Check(pDX, IDC_sparse, m_sparse);
	DDX_Check(pDX, IDC_system, m_system);
	DDX_Check(pDX, IDC_hormal, m_normal);
	DDX_Check(pDX, IDC_encrypted, m_encrypted);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProperties, CDialog)
	//{{AFX_MSG_MAP(CProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProperties message handlers

BOOL CProperties::SetFiles(LPSTR file)
{
	DWORD attr=0;
	if(m_archive==TRUE)
		attr=attr|FILE_ATTRIBUTE_ARCHIVE;
	if(m_hidden==TRUE)
		attr=attr|FILE_ATTRIBUTE_HIDDEN;
	if(m_readonly==TRUE)
		attr=attr|FILE_ATTRIBUTE_READONLY;
	if(m_system==TRUE)
		attr=attr|FILE_ATTRIBUTE_SYSTEM;
	if(m_normal==TRUE)
		attr=FILE_ATTRIBUTE_NORMAL;
	return SetFileAttributes(file,attr);
}

void CProperties::OnOK() 
{
	CDialog::OnOK();
}
