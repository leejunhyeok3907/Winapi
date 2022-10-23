#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <map>

#include "Maths.h"

using namespace std;

//typedef Pos POINT;
//using Pos = POINT;//c++14���� �߰��� ����

struct WindowData
{
	HWND hWnd;
	HDC hdc;
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