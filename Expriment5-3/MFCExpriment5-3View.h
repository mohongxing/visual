﻿
// MFCExpriment5-3View.h: CMFCExpriment53View 类的接口
//

#pragma once


class CMFCExpriment53View : public CView
{
protected: // 仅从序列化创建
	CMFCExpriment53View() noexcept;
	DECLARE_DYNCREATE(CMFCExpriment53View)

// 特性
public:
	CMFCExpriment53Doc* GetDocument() const;

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
	virtual ~CMFCExpriment53View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32774();
	afx_msg void On32772();
	afx_msg void On32771();
	afx_msg void On32773();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCExpriment5-3View.cpp 中的调试版本
inline CMFCExpriment53Doc* CMFCExpriment53View::GetDocument() const
   { return reinterpret_cast<CMFCExpriment53Doc*>(m_pDocument); }
#endif

