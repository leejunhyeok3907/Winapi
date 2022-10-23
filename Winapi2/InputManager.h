#pragma once
#include "Common.h"

//키의 상태
enum class eKeyState
{
	DOWN,
	PRESSED,
	UP,
	NONE,
};

//키 코드
enum class eKeyCode
{
	//Alphabet
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,

	//Special Key
	ENTER, ESC, LSHIFT, LALT, LCTRL,
	SPACE, LEFT, RIGHT, UP, DOWN,
	LBTN, RBTN,

	//Num Pad
	NUM_0, NUM_1, NUM_2,
	NUM_3, NUM_4, NUM_5,
	NUM_6, NUM_7, NUM_8,
	NUM_9,

	//Num Line
	N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9, N_0,

	MAX
};

class InputManager
{
private:
	struct Key
	{
		eKeyCode keyCode;//키의 종류
		eKeyState state;//키의 상태
		bool b_Pressed;
	};

private:
	static vector<Key> m_Keys;

public:
	static void Initalize();
	static void Tick();
	static void Render(HDC _dc);
	static eKeyState GetKeyState(eKeyCode _keyCode) { return m_Keys[(UINT)_keyCode].state; };
};