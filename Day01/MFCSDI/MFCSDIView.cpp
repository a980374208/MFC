
// MFCSDIView.cpp: CMFCSDIView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCSDI.h"
#endif

#include "MFCSDIDoc.h"
#include "MFCSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSDIView

IMPLEMENT_DYNCREATE(CMFCSDIView, CView)

BEGIN_MESSAGE_MAP(CMFCSDIView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCSDIView 构造/析构

CMFCSDIView::CMFCSDIView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCSDIView::~CMFCSDIView()
{
}

BOOL CMFCSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCSDIView 绘图

void CMFCSDIView::OnDraw(CDC* /*pDC*/)
{
	CMFCSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCSDIView 打印

BOOL CMFCSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCSDIView 诊断

#ifdef _DEBUG
void CMFCSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSDIDoc* CMFCSDIView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSDIDoc)));
	return (CMFCSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSDIView 消息处理程序
