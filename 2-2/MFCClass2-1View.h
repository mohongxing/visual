
// MFCClass2-1View.h: CMFCClass21View 类的接口
//

#pragma once


class CMFCClass21View : public CView
{
protected: // 仅从序列化创建
	CMFCClass21View() noexcept;
	DECLARE_DYNCREATE(CMFCClass21View)

// 特性
public:
	CMFCClass21Doc* GetDocument() const;

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
	virtual ~CMFCClass21View();
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

#ifndef _DEBUG  // MFCClass2-1View.cpp 中的调试版本
inline CMFCClass21Doc* CMFCClass21View::GetDocument() const
   { return reinterpret_cast<CMFCClass21Doc*>(m_pDocument); }
#endif

