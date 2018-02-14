// ListExplorerView.cpp : implementation of the CListExplorerView class
//

#include "stdafx.h"
#include "ListExplorer.h"
#include <direct.h>
#include "ListExplorerDoc.h"
#include "ListExplorerView.h"
#include "Name.h"
#include "Properties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListExplorerView

IMPLEMENT_DYNCREATE(CListExplorerView, CListView)

BEGIN_MESSAGE_MAP(CListExplorerView, CListView)
	//{{AFX_MSG_MAP(CListExplorerView)
	ON_COMMAND(ID_Icon, OnIcon)
	ON_COMMAND(ID_Report, OnReport)
	ON_COMMAND(ID_Small, OnSmall)
	ON_COMMAND(ID_List, OnList)
	ON_UPDATE_COMMAND_UI(ID_List, OnUpdateList)
	ON_UPDATE_COMMAND_UI(ID_Icon, OnUpdateIcon)
	ON_UPDATE_COMMAND_UI(ID_Report, OnUpdateReport)
	ON_UPDATE_COMMAND_UI(ID_Small, OnUpdateSmall)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_COMMAND(ID_FILE_DELETE, OnFileDelete)
	ON_COMMAND(ID_FILE_COPYC, OnFileCopyc)
	ON_COMMAND(ID_FILE_PASTE, OnFilePaste)
	ON_COMMAND(ID_FILE_CUT, OnFileCut)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_FILE_COPY_AS, OnFileCopyAs)
	ON_COMMAND(ID_FILE_MOVE_AS, OnFileMoveAs)
	ON_COMMAND(ID_CREATE_DIRECTOR, OnCreateDirector)
	ON_COMMAND(ID_PROPERTY, OnProperty)
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_RENAME, OnRename)
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndlabeledit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListExplorerView construction/destruction

CListExplorerView::CListExplorerView()
{
	// TODO: add construction code here
}

CListExplorerView::~CListExplorerView()
{
}

BOOL CListExplorerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style|=LVS_EDITLABELS;
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CListExplorerView drawing

void CListExplorerView::OnDraw(CDC* pDC)
{
	CListExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CListExplorerView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	CListExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& m_listctrl=GetListCtrl();
	m_listctrl.SetImageList(&(pDoc->m_imageLarge),LVSIL_NORMAL);
	m_listctrl.SetImageList(&(pDoc->m_imageSmall),LVSIL_SMALL);
	CFileFind finder;
	BOOL worked=finder.FindFile("*.*");
	int i;
	i=0;
	LV_ITEM listItem;
	CString str;
	listItem.mask=LVIF_TEXT|LVIF_IMAGE;
	listItem.iSubItem=0;
	BOOL flg;
	flg=FALSE;
	while (worked)
	{
		worked = finder.FindNextFile();
		listItem.iItem=i;
		str.Empty();
		str=finder.GetFileName();
		if(flg==FALSE)
		{
			root=finder.GetRoot();
			flg=TRUE;
		}
		LPSTR buf=str.GetBuffer(100);
		listItem.pszText=buf;
		str.ReleaseBuffer(100);
		if(finder.IsDirectory()==0)
			listItem.iImage=0;
		else
			listItem.iImage=1;
		m_listctrl.InsertItem(&listItem);
		i++;
	}
	m_oper=0;
}

/////////////////////////////////////////////////////////////////////////////
// CListExplorerView printing

BOOL CListExplorerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListExplorerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListExplorerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CListExplorerView diagnostics

#ifdef _DEBUG
void CListExplorerView::AssertValid() const
{
	CListView::AssertValid();
}

void CListExplorerView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListExplorerDoc* CListExplorerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListExplorerDoc)));
	return (CListExplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListExplorerView message handlers

void CListExplorerView::OnIcon() 
{
	m_Type=LVS_ICON;
	SetListView(LVS_ICON);
}

void CListExplorerView::OnReport() 
{
	m_Type=LVS_REPORT;
	SetListView(LVS_REPORT);
}

void CListExplorerView::OnSmall() 
{
	m_Type=LVS_SMALLICON;
	SetListView(LVS_SMALLICON);
}

void CListExplorerView::OnList() 
{
	m_Type=LVS_LIST;
	SetListView(LVS_LIST);
}

void CListExplorerView::SetListView(DWORD dwNewStyle)
{
	CListExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& m_listctrl=GetListCtrl();
	DWORD dwOldStyle;
	HWND hWndList;
	hWndList=m_listctrl.GetSafeHwnd();
	dwOldStyle=GetWindowLong(hWndList,GWL_STYLE);
	if((dwOldStyle&LVS_TYPEMASK)!=dwNewStyle)
	{
		dwOldStyle&=~LVS_TYPEMASK;
		dwNewStyle|=dwOldStyle;
		SetWindowLong(hWndList,GWL_STYLE,dwNewStyle);
	}
}

void CListExplorerView::OnUpdateList(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_Type==LVS_LIST ? 1 : 0);
}

void CListExplorerView::OnUpdateIcon(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_Type==LVS_ICON ? 1 : 0);
}

void CListExplorerView::OnUpdateReport(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_Type==LVS_REPORT ? 1 : 0);
}

void CListExplorerView::OnUpdateSmall(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_Type==LVS_SMALLICON ? 1 : 0);
}

void CListExplorerView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LPSTR buf;
	CFileFind finder;
	CString str;
	BOOL worked;
	CListCtrl& m_listctrl=GetListCtrl();	
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		int nitem=m_listctrl.GetNextSelectedItem(pos);
		str=m_listctrl.GetItemText(nitem,0);
		buf=str.GetBuffer(100);
		LPSTR root_buf=root.GetBuffer(256);
		_chdir(root_buf);
		root.ReleaseBuffer(256);
		finder.FindFile(buf);
		finder.FindNextFile();
		if(finder.IsDirectory()!=0)
		{
			_chdir(buf);
			str.ReleaseBuffer(100);
			finder.Close();
			m_listctrl.DeleteAllItems();
			worked=finder.FindFile("*.*");
			int i;
			i=0;
			LV_ITEM listItem;
			str.Empty();
			listItem.mask=LVIF_TEXT|LVIF_IMAGE;
			listItem.iSubItem=0;
			BOOL flg;
			flg=FALSE;
			while (worked)
			{
				worked = finder.FindNextFile();
				listItem.iItem=i;
				str.Empty();
				str=finder.GetFileName();
				if(flg==FALSE)
				{
					root=finder.GetRoot();
					flg=TRUE;
				}
				buf=str.GetBuffer(100);
				listItem.pszText=buf;
				str.ReleaseBuffer(100);
				if(finder.IsDirectory()==0)
					listItem.iImage=0;
				else
					listItem.iImage=1;
				m_listctrl.InsertItem(&listItem);
				i++;
			}
		}
		else
			str.ReleaseBuffer(100);
	}
	*pResult = 0;
}

void CListExplorerView::OnFileDelete() 
{
	CListCtrl& m_listctrl=GetListCtrl();
	CString str;
	LPSTR buf;
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		int nitem=m_listctrl.GetNextSelectedItem(pos);
		str=m_listctrl.GetItemText(nitem,0);
		buf=str.GetBuffer(100);	
		if(DeleteFile(buf)!=0)
			m_listctrl.DeleteItem(nitem);
		else if(RemoveDirectory(buf)!=0)
			m_listctrl.DeleteItem(nitem);
		str.ReleaseBuffer(100);
		m_listctrl.Arrange(LVA_DEFAULT);
	}
}

void CListExplorerView::OnFileCut() 
{
	CListCtrl& m_listctrl=GetListCtrl();
	root_copy.Empty();
	root_copy.Insert(0,root);
	CString str;
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		int nitem=m_listctrl.GetNextSelectedItem(pos);
		str=m_listctrl.GetItemText(nitem,0);
		file_copy.Empty();
		file_copy.Insert(0,str);
		m_listctrl.DeleteItem(nitem);
		m_listctrl.Arrange(LVA_DEFAULT);
	}
	m_oper=1;
}

void CListExplorerView::OnFileCopyc() 
{
	CListCtrl& m_listctrl=GetListCtrl();
	root_copy.Empty();
	root_copy.Insert(0,root);
	CString str;
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		int nitem=m_listctrl.GetNextSelectedItem(pos);
		str=m_listctrl.GetItemText(nitem,0);
		file_copy.Empty();
		file_copy.Insert(0,str);
	}
	m_oper=1;
}

void CListExplorerView::OnFilePaste() 
{
	CListCtrl& m_listctrl=GetListCtrl();
	LV_ITEM listItem;
	CString str;
	str.Empty();
	listItem.mask=LVIF_TEXT|LVIF_IMAGE;
	listItem.iSubItem=0;
	listItem.iItem=m_listctrl.GetItemCount();
	LPSTR buf,buf1;
	buf1=file_copy.GetBuffer(100);
	listItem.pszText=buf1;
	listItem.iImage=0;
	m_listctrl.InsertItem(&listItem);
	str.Insert(0,root_copy);
	str.Insert(str.GetLength(),'\\');
	str.Insert(str.GetLength(),file_copy);
	buf=str.GetBuffer(256);
	if(m_oper==1)
		if(CopyFile(buf,buf1,FALSE)==0)
			AfxMessageBox("Could not copy the file");
	else if(m_oper==-1)
		if(MoveFile(buf,buf1)==0)
			AfxMessageBox("Could not move the file");
	str.ReleaseBuffer(256);
	file_copy.ReleaseBuffer(100);
	m_listctrl.Arrange(LVA_DEFAULT);
}

void CListExplorerView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu menu;
	// Load the context menu
	menu.LoadMenu(IDR_CONTEXTMENU);
	// Get the first sub menu (the real menu)
	CMenu *pContextMenu = menu.GetSubMenu(0);

	// Display the context menu for the user
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON,
		point.x, point.y, AfxGetMainWnd());
}

void CListExplorerView::OnFileCopyAs() 
{
	CFileDialog ask_file(FALSE);
	if(ask_file.DoModal()!=0)
	{
		CListCtrl& m_listctrl=GetListCtrl();
		CString source;
		POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
		if(pos!=NULL)
		{
			int nitem=m_listctrl.GetNextSelectedItem(pos);
			source.Insert(0,root);
			source.Insert(source.GetLength(),'\\');
			source.Insert(source.GetLength(),m_listctrl.GetItemText(nitem,0));
			CString dest;
			dest=ask_file.GetPathName();
			LPSTR source_buf;
			LPSTR dest_buf;
			source_buf=source.GetBuffer(100);
			dest_buf=dest.GetBuffer(256);
			AfxMessageBox(source_buf);
			AfxMessageBox(dest_buf);
			CopyFile(source_buf,dest_buf,FALSE);
			source.ReleaseBuffer(100);
			dest.ReleaseBuffer(256);
		}
	}
}

void CListExplorerView::OnFileMoveAs() 
{
	CFileDialog ask_file(FALSE);
	if(ask_file.DoModal()!=0)
	{
		CListCtrl& m_listctrl=GetListCtrl();
		CString source;
		POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
		if(pos!=NULL)
		{
			int nitem=m_listctrl.GetNextSelectedItem(pos);
			source.Insert(0,root);
			source.Insert(source.GetLength(),'\\');
			source.Insert(source.GetLength(),m_listctrl.GetItemText(nitem,0));
			CString dest;
			dest=ask_file.GetPathName();
			LPSTR source_buf;
			LPSTR dest_buf;
			source_buf=source.GetBuffer(100);
			dest_buf=dest.GetBuffer(256);
			MoveFile(source_buf,dest_buf);
			source.ReleaseBuffer(100);
			dest.ReleaseBuffer(256);
			m_listctrl.DeleteItem(nitem);
			m_listctrl.Arrange(LVA_DEFAULT);
		}
	}
}

void CListExplorerView::OnCreateDirector() 
{
	CName name;
	name.DoModal();
	LPSTR buf;
	buf=name.m_Name.GetBuffer(100);
	CreateDirectory(buf,NULL);
	CListCtrl& m_listctrl=GetListCtrl();
	LV_ITEM listItem;
	listItem.mask=LVIF_TEXT|LVIF_IMAGE;
	listItem.iSubItem=0;
	listItem.iItem=m_listctrl.GetItemCount();
	listItem.pszText=buf;
	listItem.iImage=1;
	m_listctrl.InsertItem(&listItem);
	name.m_Name.ReleaseBuffer(100);
	m_listctrl.Arrange(LVA_DEFAULT);
}

void CListExplorerView::OnProperty() 
{
	CProperties prop;
	CListCtrl& m_listctrl=GetListCtrl();
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		CString str;
		int nitem=m_listctrl.GetNextSelectedItem(pos);
		str=m_listctrl.GetItemText(nitem,0);
		prop.m_name.Insert(0,str);
		LPSTR buf=str.GetBuffer(100);
		DWORD attr=GetFileAttributes(buf);
		BOOL flag=TRUE;
		DWORD n_attr;
		n_attr=attr & FILE_ATTRIBUTE_DIRECTORY;
		if(FILE_ATTRIBUTE_DIRECTORY==n_attr)
		{
			prop.m_directory=TRUE;
			flag=FALSE;
		}
		n_attr=attr & FILE_ATTRIBUTE_HIDDEN;
		if(FILE_ATTRIBUTE_HIDDEN==n_attr)
		{
			prop.m_hidden=TRUE;
			flag=FALSE;
		}
		n_attr=attr & FILE_ATTRIBUTE_ARCHIVE;
		if(FILE_ATTRIBUTE_ARCHIVE==n_attr)
		{
			prop.m_archive=TRUE;
			flag=FALSE;
		}
		n_attr=attr & FILE_ATTRIBUTE_READONLY;
		if(FILE_ATTRIBUTE_READONLY==n_attr)
		{
			prop.m_readonly=TRUE;
			flag=FALSE;
		}
		n_attr=attr &FILE_ATTRIBUTE_SYSTEM;
		if(FILE_ATTRIBUTE_SYSTEM==n_attr)
		{
			prop.m_system=TRUE;
			flag=FALSE;
		}
		n_attr=attr & FILE_ATTRIBUTE_COMPRESSED;
		if(FILE_ATTRIBUTE_COMPRESSED==n_attr)
		{
			prop.m_compressed=TRUE;
			flag=FALSE;
		}
		n_attr=attr & FILE_ATTRIBUTE_SPARSE_FILE;
		if(FILE_ATTRIBUTE_SPARSE_FILE==n_attr)
		{
			prop.m_sparse=TRUE;
			flag=FALSE;
		}
		n_attr=attr & FILE_ATTRIBUTE_ENCRYPTED;
		if(FILE_ATTRIBUTE_ENCRYPTED==n_attr)
		{
			prop.m_encrypted=TRUE;
			flag=FALSE;
		}
		if(attr==FILE_ATTRIBUTE_NORMAL && flag==TRUE)
			prop.m_normal=TRUE;
		if(prop.DoModal()==IDOK) //set the data
			prop.SetFiles(buf);
		str.ReleaseBuffer(100);
	}
}

void CListExplorerView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CListCtrl& m_listctrl=GetListCtrl();
	CListCtrl* p_listctrl=&m_listctrl;
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		CString str;
		m_nitem=m_listctrl.GetNextSelectedItem(pos);
		POINT point;
		CImageList* pDragImage=m_listctrl.CreateDragImage(m_nitem,&point);
		pDragImage->BeginDrag(0,CPoint(0,0));
		pDragImage->DragEnter(p_listctrl,pNMListView->ptAction);
		SetCapture();
		m_bIsDragging=TRUE;
	}
	*pResult = 0;
}

void CListExplorerView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CListCtrl& m_listctrl=GetListCtrl();
	CListCtrl* p_listctrl=&m_listctrl;
	if(m_bIsDragging==TRUE)
	{
		CPoint ptList(point);
		MapWindowPoints(p_listctrl,&ptList,1);
		CImageList::DragMove(ptList);
		UINT flg;
		m_dragTarget=m_listctrl.HitTest(ptList,&flg);
	}
	CListView::OnMouseMove(nFlags, point);
}

void CListExplorerView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CListCtrl& m_listctrl=GetListCtrl();
	CListCtrl* p_listctrl=&m_listctrl;
	CString nitem_str;
	if(m_bIsDragging==TRUE)
	{
		CImageList::DragLeave(p_listctrl);
		CImageList::EndDrag();
		ReleaseCapture();
		m_bIsDragging=FALSE;
		if(m_dragTarget!=-1)
		{
			int i;
			LV_ITEM listItem;
			nitem_str.Empty();
			nitem_str.Insert(0,m_listctrl.GetItemText(m_nitem,0));
			if(m_dragTarget<m_nitem)
			{
				for(i=m_nitem;i>m_dragTarget;i--)
				{
					CString str;
					listItem.mask=LVIF_TEXT|LVIF_IMAGE;
					listItem.iSubItem=0;
					listItem.iItem=i;
					str=m_listctrl.GetItemText(i-1,0);
					LPSTR buf=str.GetBuffer(100);
					listItem.pszText=buf;
					str.ReleaseBuffer(100);
					listItem.iImage=0;
					m_listctrl.SetItem(&listItem);
				}
			}
			else if(m_dragTarget>m_nitem)
			{
				for(i=m_nitem;i<m_dragTarget;i++)
				{
					CString str;
					listItem.mask=LVIF_TEXT|LVIF_IMAGE;
					listItem.iSubItem=0;
					listItem.iItem=i;
					str=m_listctrl.GetItemText(i+1,0);
					LPSTR buf=str.GetBuffer(100);
					listItem.pszText=buf;
					str.ReleaseBuffer(100);
					listItem.iImage=0;
					m_listctrl.SetItem(&listItem);
				}
			}
			else
				CListView::OnLButtonUp(nFlags, point);
			listItem.mask=LVIF_TEXT|LVIF_IMAGE;
			listItem.iSubItem=0;
			listItem.iItem=m_dragTarget;
			listItem.pszText=nitem_str.GetBuffer(100);
			nitem_str.ReleaseBuffer(100);
			listItem.iImage=0;
			m_listctrl.SetItem(&listItem);
			m_listctrl.Arrange(LVA_DEFAULT);
		}
	}
	else
		CListView::OnLButtonUp(nFlags, point);
}

void CListExplorerView::OnRename() 
{
	CListCtrl& m_listctrl=GetListCtrl();
	POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
	if(pos!=NULL)
	{
		CString str;
		int nitem=m_listctrl.GetNextSelectedItem(pos);
		CEdit* edit=m_listctrl.EditLabel(nitem);
	}
}

void CListExplorerView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	CListCtrl& m_listctrl=GetListCtrl();
	CEdit *edit=m_listctrl.GetEditControl();
	if(edit!=NULL)
	{
		CString str;
		str.Empty();
		LPSTR buf=str.GetBuffer(256);
		int nr=edit->GetLine(0,buf);
		str.ReleaseBuffer(nr);
		str.FreeExtra();
		POSITION pos=m_listctrl.GetFirstSelectedItemPosition();
		if(pos!=NULL)
		{
			int nitem=m_listctrl.GetNextSelectedItem(pos);
			CString str1=m_listctrl.GetItemText(nitem,0);
			LV_ITEM listItem;
			listItem.mask=LVIF_TEXT|LVIF_IMAGE;
			listItem.iSubItem=0;
			listItem.iItem=nitem;
			listItem.pszText=str.GetBuffer(nr);
			listItem.iImage=0;
			m_listctrl.SetItem(&listItem);
			int dim_ex;
			dim_ex=str1.GetLength();
			LPSTR buf_ex=str1.GetBuffer(dim_ex);
			MoveFile(buf_ex,listItem.pszText);
			str1.ReleaseBuffer(dim_ex);
			str.ReleaseBuffer(nr);
		}
	}
	*pResult = 0;
}
