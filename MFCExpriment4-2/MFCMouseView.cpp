
// MFCMouseView.cpp: CMFCMouseView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCMouse.h"
#endif

#include "MFCMouseDoc.h"
#include "MFCMouseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMouseView

IMPLEMENT_DYNCREATE(CMFCMouseView, CView)

BEGIN_MESSAGE_MAP(CMFCMouseView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCMouseView 构造/析构

CMFCMouseView::CMFCMouseView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCMouseView::~CMFCMouseView()
{
}

BOOL CMFCMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCMouseView 绘图

void CMFCMouseView::OnDraw(CDC* pDC)
{
	CMFCMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_crlRect);
}


// CMFCMouseView 打印

BOOL CMFCMouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCMouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCMouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCMouseView 诊断

#ifdef _DEBUG
void CMFCMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMouseDoc* CMFCMouseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMouseDoc)));
	return (CMFCMouseDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMouseView 消息处理程序


void CMFCMouseView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCMouseDoc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar) {
	case VK_LEFT:
		if (pDoc->m_crlRect.left > 0) {
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.right -= 5;

		}break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right <= (clientRec.right - clientRec.left)) {
			pDoc->m_crlRect.left += 5;
			pDoc->m_crlRect.right += 5;
		}break;
	case VK_UP:
		if (pDoc->m_crlRect.top > 0) {
			pDoc->m_crlRect.top -= 5;
			pDoc->m_crlRect.bottom -= 5;

		}break;
	case VK_DOWN:
		if (pDoc->m_crlRect.bottom <= (clientRec.bottom - clientRec.top)) {
			pDoc->m_crlRect.top += 5;
			pDoc->m_crlRect.bottom += 5;
		}break;
	case VK_HOME:
		if (pDoc->m_crlRect.left > 0 && pDoc->m_crlRect.top > 0) {
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.top -= 5;
		}break;
	case VK_END:
		if ((pDoc->m_crlRect.right <= (clientRec.right - clientRec.left)) && (pDoc->m_crlRect.bottom <= (clientRec.bottom - clientRec.top))) {
			pDoc->m_crlRect.left += 5;
			pDoc->m_crlRect.top += 5;
		}break;
		
	}
	InvalidateRect(NULL, TRUE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCMouseView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCMouseDoc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	if (nFlags) {
		pDoc->m_crlRect.left = 30; pDoc->m_crlRect.top = 30;
		pDoc->m_crlRect.right = 80; pDoc->m_crlRect.bottom = 80;
	}
	InvalidateRect(NULL, TRUE);

	CView::OnLButtonDown(nFlags, point);
}
