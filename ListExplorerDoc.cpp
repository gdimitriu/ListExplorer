// ListExplorerDoc.cpp : implementation of the CListExplorerDoc class
//

#include "stdafx.h"
#include "ListExplorer.h"

#include "ListExplorerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListExplorerDoc

IMPLEMENT_DYNCREATE(CListExplorerDoc, CDocument)

BEGIN_MESSAGE_MAP(CListExplorerDoc, CDocument)
	//{{AFX_MSG_MAP(CListExplorerDoc)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListExplorerDoc construction/destruction

CListExplorerDoc::CListExplorerDoc()
{
	// TODO: add one-time construction code here

}

CListExplorerDoc::~CListExplorerDoc()
{
}

BOOL CListExplorerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_imageLarge.Create(IDB_BALLS,32,1,RGB(255,255,255));
	m_imageSmall.Create(IDB_SM_BALLS,16,1,RGB(255,255,255));
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CListExplorerDoc serialization

void CListExplorerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CListExplorerDoc diagnostics

#ifdef _DEBUG
void CListExplorerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CListExplorerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListExplorerDoc commands


