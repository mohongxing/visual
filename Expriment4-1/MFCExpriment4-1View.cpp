﻿
// MFCExpriment4-1View.cpp: CMFCExpriment41View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment4-1.h"
#endif

#include "MFCExpriment4-1Doc.h"
#include "MFCExpriment4-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExpriment41View

IMPLEMENT_DYNCREATE(CMFCExpriment41View, CView)

BEGIN_MESSAGE_MAP(CMFCExpriment41View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCExpriment41View 构造/析构

CMFCExpriment41View::CMFCExpriment41View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCExpriment41View::~CMFCExpriment41View()
{
}

BOOL CMFCExpriment41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExpriment41View 绘图

void CMFCExpriment41View::OnDraw(CDC* pDC)
{
	CMFCExpriment41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str.Format(_T("MOUSEMOVE发生：%d"), pDoc->count);
	pDC->TextOutW(30, 30, str);
	CString s;
	s.Format(_T("横向发生：%d"), pDoc->a);
	pDC->TextOutW(30, 50, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExpriment41View 打印

BOOL CMFCExpriment41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExpriment41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExpriment41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExpriment41View 诊断

#ifdef _DEBUG
void CMFCExpriment41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExpriment41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExpriment41Doc* CMFCExpriment41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExpriment41Doc)));
	return (CMFCExpriment41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExpriment41View 消息处理程序


void CMFCExpriment41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	CMFCExpriment41Doc* pDoc = GetDocument();
	pDoc->m = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCExpriment41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	InvalidateRect(NULL, FALSE);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCExpriment41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExpriment41Doc* pDoc = GetDocument();
	pDoc->count += 1;
	if(pDoc->m.y!=point.y)pDoc->a += 1;
	CView::OnMouseMove(nFlags, point);
}
