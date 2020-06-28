
// MFCClass6-1View.h: CMFCClass61View 类的接口
//

#pragma once


class CMFCClass61View : public CView
{
protected: // 仅从序列化创建
	CMFCClass61View() noexcept;
	DECLARE_DYNCREATE(CMFCClass61View)

// 特性
public:
	CMFCClass61Doc* GetDocument() const;

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
	virtual ~CMFCClass61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFCClass6-1View.cpp 中的调试版本
inline CMFCClass61Doc* CMFCClass61View::GetDocument() const
   { return reinterpret_cast<CMFCClass61Doc*>(m_pDocument); }
#endif

