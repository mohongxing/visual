
// MFCApplication1Class2-2View.h: CMFCApplication1Class22View 类的接口
//

#pragma once


class CMFCApplication1Class22View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication1Class22View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1Class22View)

// 特性
public:
	CMFCApplication1Class22Doc* GetDocument() const;

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
	virtual ~CMFCApplication1Class22View();
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

#ifndef _DEBUG  // MFCApplication1Class2-2View.cpp 中的调试版本
inline CMFCApplication1Class22Doc* CMFCApplication1Class22View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Class22Doc*>(m_pDocument); }
#endif

