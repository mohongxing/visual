
// MFCExpriment5-1View.cpp: CMFCExpriment51View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment5-1.h"
#endif

#include "MFCExpriment5-1Doc.h"
#include "MFCExpriment5-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExpriment51View

IMPLEMENT_DYNCREATE(CMFCExpriment51View, CView)

BEGIN_MESSAGE_MAP(CMFCExpriment51View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWNUMBER, &CMFCExpriment51View::OnShownumber)
END_MESSAGE_MAP()

// CMFCExpriment51View 构造/析构

CMFCExpriment51View::CMFCExpriment51View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCExpriment51View::~CMFCExpriment51View()
{
}

BOOL CMFCExpriment51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExpriment51View 绘图

void CMFCExpriment51View::OnDraw(CDC* /*pDC*/)
{
	CMFCExpriment51Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExpriment51View 打印

BOOL CMFCExpriment51View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExpriment51View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExpriment51View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExpriment51View 诊断

#ifdef _DEBUG
void CMFCExpriment51View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExpriment51View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExpriment51Doc* CMFCExpriment51View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExpriment51Doc)));
	return (CMFCExpriment51Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExpriment51View 消息处理程序


void CMFCExpriment51View::OnShownumber()
{
	// TODO: 在此添加命令处理程序代码
	CString s;
	CClientDC dc(this);
	s = _T("201812300073,莫鸿杏");
	dc.TextOutW(100, 200, s);
}
