#include <afxwin.h>
#include "resource.h"

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
public:
	CMenu menu;
	afx_msg int OnCreate(LPCREATESTRUCT cs);
	afx_msg void OnNew();
	afx_msg void OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint Pos);

};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_NEW, OnNew)
	ON_WM_INITMENUPOPUP()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()
afx_msg int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	menu.LoadMenuA(IDR_MENU1);
	SetMenu(&menu);
	return CFrameWnd::OnCreate(pcs);
}
afx_msg void CMyFrameWnd::OnNew() {
	AfxMessageBox("新建被单机");
}

afx_msg void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i) {
	pPopup->CheckMenuItem(ID_NEW, MF_CHECKED);
}

afx_msg void CMyFrameWnd::OnContextMenu(CWnd* pWnd, CPoint Pos) {
	CMenu* pContextMeun = menu.GetSubMenu(0);
	pContextMeun->TrackPopupMenu(TPM_TOPALIGN | TPM_LEFTALIGN, Pos.x, Pos.y, pWnd, nullptr);

}
class CMyWidApp : public CWinApp {
	//CMyWndApp() {};
public:
	virtual BOOL InitInstance(){
		CMyFrameWnd* pFrame = new CMyFrameWnd;
		pFrame->Create(nullptr, "MFCMenu");
		m_pMainWnd = pFrame;
		pFrame->ShowWindow(SW_SHOW);
		pFrame->UpdateData();
		return 1;
	}
};

CMyWidApp theApp;