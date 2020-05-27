
// MFCClass2-4View.h: CMFCClass24View 类的接口
//

#pragma once


class CMFCClass24View : public CView
{
protected: // 仅从序列化创建
	CMFCClass24View() noexcept;
	DECLARE_DYNCREATE(CMFCClass24View)

// 特性
public:
	CMFCClass24Doc* GetDocument() const;

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
	virtual ~CMFCClass24View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCClass2-4View.cpp 中的调试版本
inline CMFCClass24Doc* CMFCClass24View::GetDocument() const
   { return reinterpret_cast<CMFCClass24Doc*>(m_pDocument); }
#endif

