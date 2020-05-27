
// MFCClass2-3View.cpp: CMFCClass23View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCClass2-3.h"
#endif

#include "MFCClass2-3Doc.h"
#include "MFCClass2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCClass23View

IMPLEMENT_DYNCREATE(CMFCClass23View, CView)

BEGIN_MESSAGE_MAP(CMFCClass23View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCClass23View 构造/析构

CMFCClass23View::CMFCClass23View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCClass23View::~CMFCClass23View()
{
}

BOOL CMFCClass23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCClass23View 绘图

void CMFCClass23View::OnDraw(CDC* /*pDC*/)
{
	CMFCClass23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect cr;
	GetClientRect(cr);
	CClientDC dc(this);
	dc.Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCClass23View 打印

BOOL CMFCClass23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCClass23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCClass23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCClass23View 诊断

#ifdef _DEBUG
void CMFCClass23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCClass23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCClass23Doc* CMFCClass23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCClass23Doc)));
	return (CMFCClass23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCClass23View 消息处理程序
