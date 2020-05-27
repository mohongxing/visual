
// MFCClass3-1View.h: CMFCClass31View 类的接口
//

#pragma once


class CMFCClass31View : public CView
{
protected: // 仅从序列化创建
	CMFCClass31View() noexcept;
	DECLARE_DYNCREATE(CMFCClass31View)

// 特性
public:
	CMFCClass31Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CRect cl;
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
	virtual ~CMFCClass31View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCClass3-1View.cpp 中的调试版本
inline CMFCClass31Doc* CMFCClass31View::GetDocument() const
   { return reinterpret_cast<CMFCClass31Doc*>(m_pDocument); }
#endif

