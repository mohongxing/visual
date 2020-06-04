﻿
// MFCMouseView.h: CMFCMouseView 类的接口
//

#pragma once


class CMFCMouseView : public CView
{
protected: // 仅从序列化创建
	CMFCMouseView() noexcept;
	DECLARE_DYNCREATE(CMFCMouseView)

// 特性
public:
	CMFCMouseDoc* GetDocument() const;

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
	virtual ~CMFCMouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCMouseView.cpp 中的调试版本
inline CMFCMouseDoc* CMFCMouseView::GetDocument() const
   { return reinterpret_cast<CMFCMouseDoc*>(m_pDocument); }
#endif

