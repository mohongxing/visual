
// MFCExpriment4-1View.h: CMFCExpriment41View 类的接口
//

#pragma once


class CMFCExpriment41View : public CView
{
protected: // 仅从序列化创建
	CMFCExpriment41View() noexcept;
	DECLARE_DYNCREATE(CMFCExpriment41View)

// 特性
public:
	CMFCExpriment41Doc* GetDocument() const;

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
	virtual ~CMFCExpriment41View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExpriment4-1View.cpp 中的调试版本
inline CMFCExpriment41Doc* CMFCExpriment41View::GetDocument() const
   { return reinterpret_cast<CMFCExpriment41Doc*>(m_pDocument); }
#endif

