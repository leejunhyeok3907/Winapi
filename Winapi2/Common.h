#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <map>

#include "Maths.h"
#include "Macro.h"
#include "define.h"

using namespace std;

#define PURE =0

//typedef Pos POINT;
//using Pos = POINT;//c++14부터 추가된 문법

struct WindowData
{
	
	HWND hWnd;
	HDC hdc;

	//DirectX에서는 렌더 타겟 또는 프레임 버퍼라고도 함.
	HBITMAP backTexture;
	HDC backBuffer;

	UINT height;
	UINT width;

	void clear()
	{
		HWND hWnd = nullptr;
		HDC hdc = nullptr;
		height = 0;
		width = 0;
	}
};

struct Pen
{
private:
	HDC m_hdc;
	HPEN m_OldPen;
	HPEN m_Pen;

public:
	Pen(HDC _hdc, HPEN _pen)
		: m_hdc(_hdc)
		, m_Pen(_pen)
		, m_OldPen(NULL)
	{
		m_OldPen = (HPEN)SelectObject(m_hdc, m_Pen);
	}

	~Pen()
	{
		SelectObject(m_hdc, m_OldPen);
		DeleteObject(m_Pen);
	}
};

struct Brush 
{
private:
	HDC m_hdc;
	HBRUSH m_OldBrush;
	HBRUSH m_Brush;

public:
	Brush(HDC _hdc, HBRUSH _brush)
		: m_hdc(_hdc)
		, m_Brush(_brush)
		, m_OldBrush(NULL)
	{
		m_OldBrush = (HBRUSH)SelectObject(m_hdc, m_Brush);
	}

	~Brush()
	{
		SelectObject(m_hdc, m_OldBrush);
		DeleteObject(m_Brush);
	}
};