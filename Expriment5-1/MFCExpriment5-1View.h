
// MFCExpriment5-1View.h: CMFCExpriment51View 类的接口
//

#pragma once


class CMFCExpriment51View : public CView
{
protected: // 仅从序列化创建
	CMFCExpriment51View() noexcept;
	DECLARE_DYNCREATE(CMFCExpriment51View)

// 特性
public:
	CMFCExpriment51Doc* GetDocument() const;

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
	virtual ~CMFCExpriment51View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShownumber();
};

#ifndef _DEBUG  // MFCExpriment5-1View.cpp 中的调试版本
inline CMFCExpriment51Doc* CMFCExpriment51View::GetDocument() const
   { return reinterpret_cast<CMFCExpriment51Doc*>(m_pDocument); }
#endif

