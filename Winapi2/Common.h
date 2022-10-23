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