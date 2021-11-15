#include <afxwin.h>
#include "resource.h"
#include <afxext.h>

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	CMenu menu;
	CToolBar toolbar;
public:
	afx_msg int OnCreate(LPCREATESTRUCT pSt);
	afx_msg void OnNew();
	afx_msg void OnSet();

};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_NEW,OnNew)
	ON_COMMAND(ID_SET,OnSet)


END_MESSAGE_MAP()

class CMyWndApp : public CWinApp {
	virtual BOOL InitInstance();

};

CMyWndApp theApp;
BOOL CMyWndApp::InitInstance() {
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(nullptr, "MFCToolBar", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, nullptr, (char*)IDR_MENU1);
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pSt)
{
	toolbar.CreateEx(this,TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP|CBRS_GRIPPER);
	toolbar.LoadToolBar(IDR_TOOLBAR1);
	toolbar.EnableDocking(CBRS_ALIGN_ANY);
	this->EnableDocking(CBRS_ALIGN_ANY);
	this->DockControlBar(&toolbar, AFX_IDW_DOCKBAR_BOTTOM);
	return CFrameWnd::OnCreate(pSt);
}

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("新建被单机");
}

void CMyFrameWnd::OnSet()
{
	AfxMessageBox("Set被单机");
}
