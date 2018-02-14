; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CListExplorerView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ListExplorer.h"
LastPage=0

ClassCount=7
Class1=CListExplorerApp
Class2=CListExplorerDoc
Class3=CListExplorerView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_CONTEXTMENU
Class5=CAboutDlg
Resource2=IDD_Name
Resource3=IDD_ABOUTBOX
Class6=CName
Resource4=IDR_MAINFRAME
Class7=CProperties
Resource5=IDD_PROPERTIES

[CLS:CListExplorerApp]
Type=0
HeaderFile=ListExplorer.h
ImplementationFile=ListExplorer.cpp
Filter=N

[CLS:CListExplorerDoc]
Type=0
HeaderFile=ListExplorerDoc.h
ImplementationFile=ListExplorerDoc.cpp
Filter=N
LastObject=ID_EDIT_CUT
BaseClass=CDocument
VirtualFilter=DC

[CLS:CListExplorerView]
Type=0
HeaderFile=ListExplorerView.h
ImplementationFile=ListExplorerView.cpp
Filter=C
LastObject=CListExplorerView
BaseClass=CListView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=ListExplorer.cpp
ImplementationFile=ListExplorer.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_SEND_MAIL
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_FILE_COPY
Command12=ID_FILE_COPY_AS
Command13=ID_FILE_MOVE
Command14=ID_FILE_MOVE_AS
Command15=ID_FILE_DELETE
Command16=ID_FILE_CUT
Command17=ID_FILE_COPYC
Command18=ID_FILE_PASTE
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_Icon
Command22=ID_List
Command23=ID_Report
Command24=ID_Small
Command25=ID_APP_ABOUT
CommandCount=25

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_COPYC
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_FILE_PASTE
Command7=ID_FILE_DELETE
Command8=ID_NEXT_PANE
Command9=ID_PREV_PANE
Command10=ID_FILE_CUT
CommandCount=10

[MNU:IDR_CONTEXTMENU]
Type=1
Class=CListExplorerView
Command1=ID_CREATE_DIRECTOR
Command2=ID_FILE_CREATE
Command3=ID_FILE_CUT
Command4=ID_FILE_COPYC
Command5=ID_FILE_PASTE
Command6=ID_FILE_DELETE
Command7=ID_PROPERTY
Command8=ID_RENAME
CommandCount=8

[DLG:IDD_Name]
Type=1
Class=CName
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_name,edit,1350631552

[CLS:CName]
Type=0
HeaderFile=Name.h
ImplementationFile=Name.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_name

[DLG:IDD_PROPERTIES]
Type=1
Class=CProperties
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_name,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308353
Control6=IDC_archive,button,1342242819
Control7=IDC_compressed,button,1342242819
Control8=IDC_directory,button,1342242819
Control9=IDC_readonly,button,1342242819
Control10=IDC_system,button,1342242819
Control11=IDC_sparse,button,1342242819
Control12=IDC_hidden,button,1342242819
Control13=IDC_hormal,button,1342242819
Control14=IDC_encrypted,button,1342242819
Control15=IDC_STATIC,static,1342308353

[CLS:CProperties]
Type=0
HeaderFile=Properties.h
ImplementationFile=Properties.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

