
// MFCExpriment5-3View.cpp: CMFCExpriment53View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment5-3.h"
#endif

#include "MFCExpriment5-3Doc.h"
#include "MFCExpriment5-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExpriment53View

IMPLEMENT_DYNCREATE(CMFCExpriment53View, CView)

BEGIN_MESSAGE_MAP(CMFCExpriment53View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32772, &CMFCExpriment53View::On32772)
	ON_COMMAND(ID_32771, &CMFCExpriment53View::On32771)
	ON_COMMAND(ID_32773, &CMFCExpriment53View::On32773)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCExpriment53View 构造/析构

CMFCExpriment53View::CMFCExpriment53View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCExpriment53View::~CMFCExpriment53View()
{
}

BOOL CMFCExpriment53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExpriment53View 绘图

void CMFCExpriment53View::OnDraw(CDC* pDC)
{
	CMFCExpriment53Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (true && pDoc->set == 1) {
		pDC->MoveTo(pDoc->p);
		pDC->LineTo(pDoc->m_point);
	}
	
	if (true && pDoc->set == 2) {
		pDC->MoveTo(pDoc->p);
		pDC->LineTo(pDoc->m_point.x, pDoc->p.y);
		pDC->LineTo(pDoc->m_point);
		pDC->LineTo(pDoc->p.x, pDoc->m_point.y);
		pDC->LineTo(pDoc->p);
	}

	if (true && pDoc->set == 3) {
		CRect cr(pDoc->p, pDoc->m_point);
		CClientDC dc(this);
		pDC->Ellipse(cr);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExpriment53View 打印

BOOL CMFCExpriment53View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExpriment53View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExpriment53View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExpriment53View 诊断

#ifdef _DEBUG
void CMFCExpriment53View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExpriment53View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExpriment53Doc* CMFCExpriment53View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExpriment53Doc)));
	return (CMFCExpriment53Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExpriment53View 消息处理程序


void CMFCExpriment53View::On32771()
{

	CMFCExpriment53Doc* pDoc = GetDocument();
	pDoc->set = 1;
	// TODO: 在此添加命令处理程序代码
	//画线
}


void CMFCExpriment53View::On32772()
{

	CMFCExpriment53Doc* pDoc = GetDocument();
	pDoc->set = 2;
	// TODO: 在此添加命令处理程序代码
	//画矩形
}

void CMFCExpriment53View::On32773()
{

	CMFCExpriment53Doc* pDoc = GetDocument();
	pDoc->set = 3;
	// TODO: 在此添加命令处理程序代码
	//画椭圆
}



void CMFCExpriment53View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExpriment53Doc* pDoc = GetDocument();
		SetCapture();
		pDoc->p = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExpriment53View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExpriment53Doc* pDoc = GetDocument();
		pDoc->m_point = point;
		InvalidateRect(NULL, FALSE);
		ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
