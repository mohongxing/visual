
// MFCClass2-1View.cpp: CMFCClass21View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCClass2-1.h"
#endif

#include "MFCClass2-1Doc.h"
#include "MFCClass2-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCClass21View

IMPLEMENT_DYNCREATE(CMFCClass21View, CView)

BEGIN_MESSAGE_MAP(CMFCClass21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCClass21View 构造/析构

CMFCClass21View::CMFCClass21View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCClass21View::~CMFCClass21View()
{
}

BOOL CMFCClass21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCClass21View 绘图

void CMFCClass21View::OnDraw(CDC* /*pDC*/)
{
	CMFCClass21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCClass21View 打印

BOOL CMFCClass21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCClass21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCClass21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCClass21View 诊断

#ifdef _DEBUG
void CMFCClass21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCClass21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCClass21Doc* CMFCClass21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCClass21Doc)));
	return (CMFCClass21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCClass21View 消息处理程序


void CMFCClass21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % (50 - 25) + 50;
	CClientDC dc(this);
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
