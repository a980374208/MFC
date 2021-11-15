#include <afxwin.h>

class CMyFrameWnd : public CFrameWnd {
	virtual LRESULT WindowProc(UINT msgID, WPARAM wParam, LPARAM lParam) {
		switch (msgID) {
		case WM_CREATE:
			AfxMessageBox("WM_CREATE");
			break;
		case WM_PAINT:
			PAINTSTRUCT ps = { 0 };
			HDC hdc = ::BeginPaint(m_hWnd, &ps);
			::TextOut(hdc, 100, 100, "text", 5);
			::EndPaint(m_hWnd, &ps);
			break;
		}
		return CFrameWnd::WindowProc(msgID, wParam, lParam);
	}
};
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