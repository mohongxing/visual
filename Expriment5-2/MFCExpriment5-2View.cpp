
// MFCExpriment5-2View.cpp: CMFCExpriment52View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment5-2.h"
#endif

#include "MFCExpriment5-2Doc.h"
#include "MFCExpriment5-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExpriment52View

IMPLEMENT_DYNCREATE(CMFCExpriment52View, CView)

BEGIN_MESSAGE_MAP(CMFCExpriment52View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCExpriment52View 构造/析构

CMFCExpriment52View::CMFCExpriment52View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nwidth = BM.bmWidth;
	m_nhigth = BM.bmHeight;
}

CMFCExpriment52View::~CMFCExpriment52View()
{
}

BOOL CMFCExpriment52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExpriment52View 绘图

void CMFCExpriment52View::OnDraw(CDC* pDC)
{
	CMFCExpriment52Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(10,10 , m_nwidth, m_nhigth, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCExpriment52View 打印

BOOL CMFCExpriment52View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExpriment52View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExpriment52View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExpriment52View 诊断

#ifdef _DEBUG
void CMFCExpriment52View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExpriment52View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExpriment52Doc* CMFCExpriment52View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExpriment52Doc)));
	return (CMFCExpriment52Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExpriment52View 消息处理程序
