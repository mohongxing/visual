
// MFCExcepriment2-2View.h: CMFCExcepriment22View 类的接口
//

#pragma once


class CMFCExcepriment22View : public CView
{
protected: // 仅从序列化创建
	CMFCExcepriment22View() noexcept;
	DECLARE_DYNCREATE(CMFCExcepriment22View)

// 特性
public:
	CMFCExcepriment22Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMFCExcepriment22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCExcepriment2-2View.cpp 中的调试版本
inline CMFCExcepriment22Doc* CMFCExcepriment22View::GetDocument() const
   { return reinterpret_cast<CMFCExcepriment22Doc*>(m_pDocument); }
#endif

