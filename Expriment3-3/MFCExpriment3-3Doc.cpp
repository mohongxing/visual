
// MFCExpriment3-3Doc.cpp: CMFCExpriment33Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCExpriment3-3.h"
#endif

#include "MFCExpriment3-3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCExpriment33Doc

IMPLEMENT_DYNCREATE(CMFCExpriment33Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCExpriment33Doc, CDocument)
END_MESSAGE_MAP()


// CMFCExpriment33Doc 构造/析构

CMFCExpriment33Doc::CMFCExpriment33Doc() noexcept
{
	// TODO: 在此添加一次性构造代码
	A = rand();
	B = rand();
	C = A + B;

	crA.top = 100;
	crA.bottom = 200;
	crA.left = 100;
	crA.right = 300;

	crB.top = 50;
	crB.bottom =300;
	crB.left = 700;
	crB.right = 800;

	crC.top = 300;
	crC.bottom = 400;
	crC.left = 100;
	crC.right = 600;


}

CMFCExpriment33Doc::~CMFCExpriment33Doc()
{
}

BOOL CMFCExpriment33Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCExpriment33Doc 序列化

void CMFCExpriment33Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFCExpriment33Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFCExpriment33Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFCExpriment33Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCExpriment33Doc 诊断

#ifdef _DEBUG
void CMFCExpriment33Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCExpriment33Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCExpriment33Doc 命令
