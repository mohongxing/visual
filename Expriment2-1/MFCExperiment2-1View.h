
// MFCExperiment2-1View.h: CMFCExperiment21View 类的接口
//

#pragma once


class CMFCExperiment21View : public CView
{
protected: // 仅从序列化创建
	CMFCExperiment21View() noexcept;
	DECLARE_DYNCREATE(CMFCExperiment21View)

// 特性
public:
	CMFCExperiment21Doc* GetDocument() const;

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
	virtual ~CMFCExperiment21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCExperiment2-1View.cpp 中的调试版本
inline CMFCExperiment21Doc* CMFCExperiment21View::GetDocument() const
   { return reinterpret_cast<CMFCExperiment21Doc*>(m_pDocument); }
#endif

