#include <afxwin.h>

class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()
//protected: 
//	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); 
//	virtual const AFX_MSGMAP* GetMessageMap() const; 
public:
	LRESULT OnCreate(WPARAM wParam,LPARAM lParam) {
		AfxMessageBox("WM_Create");
		return 0;
	}
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_MESSAGE(WM_CREATE, OnCreate)
END_MESSAGE_MAP()

/*const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const
{ return GetThisMessageMap(); } 
const AFX_MSGMAP* PASCAL CMyFrameWnd::GetThisMessageMap()
{ 
    __pragma(warning(push))							   
    __pragma(warning(disable: 4640)) 
    static const AFX_MSGMAP_ENTRY _messageEntries[] = 
    {
		{ WM_CREATE, 0, 0, 0, AfxSig_lwl, (AFX_PMSG)(AFX_PMSGW) 
		(static_cast<LRESULT(AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM)> (&OnCreate)) },
		
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } }; 
    __pragma(warning(pop))	
    static const AFX_MSGMAP messageMap = 
    { &CFrameWnd::GetThisMessageMap, & _messageEntries[0] };
    return &messageMap; 
}	*/							  

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