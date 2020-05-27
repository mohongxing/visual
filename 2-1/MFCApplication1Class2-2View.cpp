
// MFCApplication1Class2-2View.cpp: CMFCApplication1Class22View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1Class2-2.h"
#endif

#include "MFCApplication1Class2-2Doc.h"
#include "MFCApplication1Class2-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Class22View

IMPLEMENT_DYNCREATE(CMFCApplication1Class22View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1Class22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication1Class22View 构造/析构

CMFCApplication1Class22View::CMFCApplication1Class22View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication1Class22View::~CMFCApplication1Class22View()
{
}

BOOL CMFCApplication1Class22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1Class22View 绘图

void CMFCApplication1Class22View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Class22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication1Class22View 打印

BOOL CMFCApplication1Class22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1Class22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1Class22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication1Class22View 诊断

#ifdef _DEBUG
void CMFCApplication1Class22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1Class22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Class22Doc* CMFCApplication1Class22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Class22Doc)));
	return (CMFCApplication1Class22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1Class22View 消息处理程序


void CMFCApplication1Class22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CRect cr;
	GetClientRect (cr);
	CRect cr1(point.x - r, point.y - r, point.x + r, point.y + r);
	CClientDC dc(this);
	dc.Ellipse(cr1);

	CView::OnLButtonDown(nFlags, point);
}
