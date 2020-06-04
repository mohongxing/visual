
// MFCClass4-1View.cpp: CMFCClass41View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCClass4-1.h"
#endif

#include "MFCClass4-1Doc.h"
#include "MFCClass4-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCClass41View

IMPLEMENT_DYNCREATE(CMFCClass41View, CView)

BEGIN_MESSAGE_MAP(CMFCClass41View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCClass41View 构造/析构

CMFCClass41View::CMFCClass41View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCClass41View::~CMFCClass41View()
{
}

BOOL CMFCClass41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCClass41View 绘图

void CMFCClass41View::OnDraw(CDC* pDC)
{
	CMFCClass41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->MoveTo(pDoc->p);
	pDC->LineTo(pDoc->m_point.x, pDoc->p.y);
	pDC->LineTo(pDoc->m_point);
	pDC->LineTo(pDoc->p.x,pDoc->m_point.y);
	pDC->LineTo(pDoc->p);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCClass41View 打印

BOOL CMFCClass41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCClass41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCClass41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCClass41View 诊断

#ifdef _DEBUG
void CMFCClass41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCClass41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCClass41Doc* CMFCClass41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCClass41Doc)));
	return (CMFCClass41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCClass41View 消息处理程序


void CMFCClass41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	CMFCClass41Doc* pDoc = GetDocument();
	pDoc->p = point;
	CView::OnLButtonDown(nFlags, point);
}



void CMFCClass41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    CMFCClass41Doc* pDoc = GetDocument();
	pDoc->m_point=point;
	InvalidateRect(NULL, FALSE);
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}



