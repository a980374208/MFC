#include <afxwin.h>
#define WM_MYMESSAGE WM_USER+1001

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT pCS);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nKey, CPoint cPt);
public:
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	int m_x = 100;
	int m_y = 100;

};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	//ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)
	ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pCS) {
	AfxMessageBox("OnCreate");
	::PostMessage(m_hWnd, WM_MYMESSAGE,100, 200);
	return CFrameWnd::OnCreate(pCS);
}
void  CMyFrameWnd::OnPaint() {
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(m_hWnd,&ps);
	::TextOut(hdc, m_x, m_y, "hello", strlen("hello"));
	::EndPaint(m_hWnd,&ps);
}
LRESULT CMyFrameWnd::OnMyMessage(WPARAM wParam, LPARAM lParam){
	CString str;
	str.Format("wParam=%d,lParam=%d", wParam, lParam);
	AfxMessageBox(str);
	return 0;
}

void CMyFrameWnd::OnMouseMove(UINT nKey, CPoint cPt)
{
	m_x = cPt.x;
	m_y = cPt.y;
	::InvalidateRect(m_hWnd, nullptr, TRUE);
}


class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance() {
		CMyFrameWnd* pFrame = new CMyFrameWnd;
		pFrame->Create(nullptr, "MFCCreate");
		m_pMainWnd = pFrame;
		pFrame->ShowWindow(SW_SHOW);
		pFrame->UpdateWindow();
		return TRUE;
	}
};
CMyWinApp theApp;