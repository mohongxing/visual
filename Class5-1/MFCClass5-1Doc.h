
// MFCClass5-1Doc.h: CMFCClass51Doc 类的接口
//


#pragma once


class CMFCClass51Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCClass51Doc() noexcept;
	DECLARE_DYNCREATE(CMFCClass51Doc)

// 特性
public:

// 操作
public:
	CRect cr;
	CRect client;
	bool set;
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCClass51Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
