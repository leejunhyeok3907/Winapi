#include "Image.h"
#include "Application.h"

Image::Image()
	: m_Bitmap(NULL)
	, m_hdc(NULL)
	, m_Width(0)
	, m_Height(0)
{
}

Image::~Image()
{
}


HRESULT Image::Load(const wstring& _path)
{
	m_Bitmap = (HBITMAP)LoadImageW(nullptr, _path.c_str(), IMAGE_BITMAP, 
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (m_Bitmap == nullptr)
	{
		return E_FAIL;
	}

	BITMAP bitInfo = {};
	GetObject(m_Bitmap, sizeof(BITMAP), &bitInfo);

	m_Width = bitInfo.bmWidth;
	m_Height = bitInfo.bmHeight;

	HDC mainDC = Application::GetInstance().GetWindowData().hdc;
	m_hdc = CreateCompatibleDC(mainDC);
	HBITMAP prevBit = (HBITMAP)SelectObject(m_hdc, m_Bitmap);
	DeleteObject(prevBit);

	return S_OK;
}