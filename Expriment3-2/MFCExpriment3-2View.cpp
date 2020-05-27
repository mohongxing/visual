
// MFCExpriment3-2View.cpp: CMFCExpriment32View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment3-2.h"
#endif

#include "MFCExpriment3-2Doc.h"
#include "MFCExpriment3-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExpriment32View

IMPLEMENT_DYNCREATE(CMFCExpriment32View, CView)

BEGIN_MESSAGE_MAP(CMFCExpriment32View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCExpriment32View 构造/析构

CMFCExpriment32View::CMFCExpriment32View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCExpriment32View::~CMFCExpriment32View()
{
}

BOOL CMFCExpriment32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExpriment32View 绘图

void CMFCExpriment32View::OnDraw(CDC* /*pDC*/)
{
	CMFCExpriment32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExpriment32View 打印

BOOL CMFCExpriment32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExpriment32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExpriment32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExpriment32View 诊断

#ifdef _DEBUG
void CMFCExpriment32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExpriment32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExpriment32Doc* CMFCExpriment32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExpriment32Doc)));
	return (CMFCExpriment32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExpriment32View 消息处理程序


void CMFCExpriment32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCExpriment32Doc* pDoc = GetDocument();
	CRect cr;
	this->GetClientRect(cr);
	CClientDC dc(this);
	CString s;
	int a = pDoc->A +pDoc->B;
	s.Format(_T("A+B=%d"), a);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
