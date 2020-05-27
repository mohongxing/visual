
// MFCClass3-2View.cpp: CMFCClass32View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCClass3-2.h"
#endif

#include "MFCClass3-2Doc.h"
#include "MFCClass3-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCClass32View

IMPLEMENT_DYNCREATE(CMFCClass32View, CView)

BEGIN_MESSAGE_MAP(CMFCClass32View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCClass32View 构造/析构

CMFCClass32View::CMFCClass32View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(100);
}

CMFCClass32View::~CMFCClass32View()
{
}

BOOL CMFCClass32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCClass32View 绘图

void CMFCClass32View::OnDraw(CDC* pDC)
{
	CMFCClass32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCClass32View 打印

BOOL CMFCClass32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCClass32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCClass32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCClass32View 诊断

#ifdef _DEBUG
void CMFCClass32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCClass32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCClass32Doc* CMFCClass32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCClass32Doc)));
	return (CMFCClass32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCClass32View 消息处理程序


void CMFCClass32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - r, point.x + r,point.y+r);
	ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
