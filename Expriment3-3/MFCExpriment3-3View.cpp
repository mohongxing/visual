
// MFCExpriment3-3View.cpp: CMFCExpriment33View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment3-3.h"
#endif

#include "MFCExpriment3-3Doc.h"
#include "MFCExpriment3-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExpriment33View

IMPLEMENT_DYNCREATE(CMFCExpriment33View, CView)

BEGIN_MESSAGE_MAP(CMFCExpriment33View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCExpriment33View 构造/析构

CMFCExpriment33View::CMFCExpriment33View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCExpriment33View::~CMFCExpriment33View()
{
}

BOOL CMFCExpriment33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExpriment33View 绘图

void CMFCExpriment33View::OnDraw(CDC* pDC)
{
	CMFCExpriment33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->crA);
	pDC->Rectangle(pDoc->crB);
	pDC->Rectangle(pDoc->crC);
	pDC->TextOutW(200, 110, _T("A"));
	pDC->TextOutW(750, 60, _T("B"));
	pDC->TextOutW(350, 310, _T("C"));
	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMFCExpriment33View 打印

BOOL CMFCExpriment33View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExpriment33View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExpriment33View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExpriment33View 诊断

#ifdef _DEBUG
void CMFCExpriment33View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExpriment33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExpriment33Doc* CMFCExpriment33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExpriment33Doc)));
	return (CMFCExpriment33Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExpriment33View 消息处理程序


void CMFCExpriment33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExpriment33Doc* pDoc = GetDocument();
	CString sA, sB;
	sA.Format(_T("%d"), pDoc->A);
	sB.Format(_T("%d"), pDoc->B);
	CRect cr;
	CClientDC dc(this);
	GetClientRect(cr);
	if (point.x > pDoc->crA.left && point.x <pDoc->crA.right && point.y>pDoc->crA.top && point.y < pDoc->crA.bottom)
		dc.TextOutW(200, 150, sA);
	else if (point.x > pDoc->crB.left && point.x <pDoc->crB.right && point.y>pDoc->crB.top && point.y < pDoc->crB.bottom)
		dc.TextOutW(730, 150, sB);
	else dc.TextOutW(point.x, point.y,_T("点击无效"));
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExpriment33View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExpriment33Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("%d"), pDoc->C);
	CRect cl;
	CClientDC dc(this);
	GetClientRect(cl);
	if (point.x > pDoc->crC.left && point.x <pDoc->crC.right && point.y>pDoc->crC.top && point.y < pDoc->crC.bottom)
		dc.TextOutW(350, 350, s);
	CView::OnRButtonDown(nFlags, point);
}
