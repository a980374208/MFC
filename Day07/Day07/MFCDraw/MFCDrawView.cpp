
// MFCDrawView.cpp: CMFCDrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCDraw.h"
#endif

#include "MFCDrawDoc.h"
#include "MFCDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrawView

IMPLEMENT_DYNCREATE(CMFCDrawView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawView, CView)
	ON_WM_PAINT()
	ON_COMMAND(ID_CLIDC, &CMFCDrawView::OnClientDC)
	ON_COMMAND(ID_PEN, &CMFCDrawView::OnPen)
	ON_COMMAND(ID_BRUSH, &CMFCDrawView::OnBrush)
	ON_COMMAND(ID_FONT, &CMFCDrawView::OnFont)
	ON_COMMAND(ID_BITMAP, &CMFCDrawView::OnBitmap)
END_MESSAGE_MAP()

// CMFCDrawView 构造/析构

CMFCDrawView::CMFCDrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCDrawView::~CMFCDrawView()
{
}

BOOL CMFCDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDrawView 绘图

void CMFCDrawView::OnDraw(CDC* /*pDC*/)
{
	CMFCDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDrawView 诊断

#ifdef _DEBUG
void CMFCDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawDoc* CMFCDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawDoc)));
	return (CMFCDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawView 消息处理程序


void CMFCDrawView::OnPaint()
{
	CPaintDC dc(this); 
	dc.Rectangle(100,100,300,300);
}


void CMFCDrawView::OnClientDC()
{
	CClientDC dc(this);
	dc.Ellipse(300, 300, 500, 500);
	//::PostQuitMessage(0);
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnPen()
{
	CClientDC dc(this);
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HGDIOBJ oldPen = dc.SelectObject(pen);
	dc.Rectangle(100, 100, 300, 300);
	dc.SelectObject(oldPen);
	pen.DeleteObject();
	
}


void CMFCDrawView::OnBrush()
{
	CClientDC dc(this);
	CBrush brush(RGB(0,255,0));
	HGDIOBJ oldbrush = dc.SelectObject(brush);
	dc.Rectangle(100, 100, 300, 300);
	dc.SelectObject(oldbrush);
	brush.DeleteObject();
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnFont()
{
	CClientDC dc(this);
	CFont pont;
	pont.CreatePointFont(300, "宋体", &dc);
	HGDIOBJ oldpont = dc.SelectObject(pont);
	dc.TextOutA(100, 100, "Hello 沃德");
	dc.SelectObject(oldpont);
	pont.DeleteObject();
	// TODO: 在此添加命令处理程序代码
}


void CMFCDrawView::OnBitmap()
{
	CClientDC dc(this);
	CDC tempDc;
	tempDc.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);
	HGDIOBJ oldbit = tempDc.SelectObject(&bitmap);
	dc.BitBlt(300, 300, 48, 48, &tempDc, 0, 0, SRCCOPY);
	tempDc.SelectObject(&oldbit);
	bitmap.DeleteObject();
	// TODO: 在此添加命令处理程序代码
}
