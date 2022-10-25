#pragma once
#include "Resources.h"
class Image :
    public Resources
{
private:
    HBITMAP m_Bitmap;
    HDC m_hdc;
    UINT m_Width;
    UINT m_Height;

public:
    HDC GetDC() { return m_hdc; }
    UINT GetWidth() { return m_Width; }
    UINT GetHeight() { return m_Height; }

    virtual HRESULT Load(const wstring& _path);

public:
    Image();
    ~Image();
};

