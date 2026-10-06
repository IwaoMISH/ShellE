; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShellEDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ShellE.h"

ClassCount=3
Class1=CShellEApp
Class2=CShellEDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SHELLE_DIALOG

[CLS:CShellEApp]
Type=0
HeaderFile=ShellE.h
ImplementationFile=ShellE.cpp
Filter=N

[CLS:CShellEDlg]
Type=0
HeaderFile=ShellED.h
ImplementationFile=ShellED.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CShellEDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ShellED.h
ImplementationFile=ShellED.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHELLE_DIALOG]
Type=1
Class=CShellEDlg
ControlCount=6
Control1=IDC_COMBO_OPERATION,combobox,1344340033
Control2=IDC_COMBO_FILE,combobox,1344342081
Control3=IDC_COMBO_PARAMETERS,combobox,1344342081
Control4=IDC_EXECUTE,button,1342242816
Control5=IDOK,button,1073807361
Control6=IDCANCEL,button,1342242816

