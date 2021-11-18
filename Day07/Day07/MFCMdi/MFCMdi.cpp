#include <afxwin.h>
#include"resource.h"
class CMyDoc : public CDocument {
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* cdc);
};
IMPLEMENT_DYNCREATE(CMyView, CView)

class CMyFraneWnd : public CMDIFrameWnd {

};
class CMyChildWnd : public CMDIChildWnd {
	DECLARE_DYNCREATE(CMyChildWnd)
};
IMPLEMENT_DYNCREATE(CMyChildWnd, CMDIChildWnd)




void CMyView::OnDraw(CDC* cdc) {
	cdc->TextOut(100, 100, "CMyView");
}

class CMyWinApp : public CWinApp {
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance()
{
	CMyFraneWnd* pFrame = new CMyFraneWnd;
	pFrame->LoadFrame(IDR_MENU1);
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateData();

	CMultiDocTemplate* pMulDocTmp = new CMultiDocTemplate(IDR_MENU2, RUNTIME_CLASS(CMyDoc), RUNTIME_CLASS(CMyChildWnd), RUNTIME_CLASS(CMyView));
	
	AddDocTemplate(pMulDocTmp);

	OnFileNew();
	OnFileNew();
	OnFileNew();
	return TRUE;
}
CMyWinApp theApp;