
// MFCExpriment5-2View.h: CMFCExpriment52View 类的接口
//

#pragma once


class CMFCExpriment52View : public CView
{
protected: // 仅从序列化创建
	CMFCExpriment52View() noexcept;
	DECLARE_DYNCREATE(CMFCExpriment52View)

// 特性
public:
	CMFCExpriment52Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nwidth;
	int m_nhigth;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCExpriment52View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCExpriment5-2View.cpp 中的调试版本
inline CMFCExpriment52Doc* CMFCExpriment52View::GetDocument() const
   { return reinterpret_cast<CMFCExpriment52Doc*>(m_pDocument); }
#endif

