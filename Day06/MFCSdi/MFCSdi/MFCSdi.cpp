#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

class CMyDoc : public CDocument {
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

class CMyView :public CView {
	DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* cdc);
};
IMPLEMENT_DYNCREATE(CMyView, CView)

void CMyView::OnDraw(CDC* cdc)
{
	cdc->TextOutA(100, 100, "MyView");
}

class CMyFrameWnd :public CFrameWnd {
	DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)

class CMyWinApp :public CWinApp {
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance()
{
	CSingleDocTemplate* pTemplate = new CSingleDocTemplate(IDR_MENU1, RUNTIME_CLASS(CMyDoc), RUNTIME_CLASS(CMyFrameWnd), RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);
	OnFileNew();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateData();
	return 1;
}
CMyWinApp theApp;