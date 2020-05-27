
// MFCExperiment2-1View.cpp: CMFCExperiment21View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExperiment2-1.h"
#endif

#include "MFCExperiment2-1Doc.h"
#include "MFCExperiment2-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExperiment21View

IMPLEMENT_DYNCREATE(CMFCExperiment21View, CView)

BEGIN_MESSAGE_MAP(CMFCExperiment21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCExperiment21View 构造/析构

CMFCExperiment21View::CMFCExperiment21View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCExperiment21View::~CMFCExperiment21View()
{
}

BOOL CMFCExperiment21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCExperiment21View 绘图

void CMFCExperiment21View::OnDraw(CDC* pDC)
{
	CMFCExperiment21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString S = _T("我是***"),str;
	int A = 1000;
	str.Format(_T("%d"), A);
	pDC->TextOutW(200, 200, S);
	pDC->TextOutW(200, 100, str);

}


// CMFCExperiment21View 打印

BOOL CMFCExperiment21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCExperiment21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCExperiment21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCExperiment21View 诊断

#ifdef _DEBUG
void CMFCExperiment21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCExperiment21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCExperiment21Doc* CMFCExperiment21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCExperiment21Doc)));
	return (CMFCExperiment21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCExperiment21View 消息处理程序
