#include "InputManager.h"

int ASCII[(UINT)eKeyCode::MAX] = {
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',

	//Special Key
	VK_RETURN, VK_ESCAPE, VK_LSHIFT, VK_LMENU, VK_LCONTROL,
	VK_SPACE, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	VK_LBUTTON, VK_RBUTTON,

	//Num Pad
	VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2,
	VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5,
	VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8,
	VK_NUMPAD9,

	//Num Line
	'1','2','3','4','5','6','7','8','9','0',
};

vector<InputManager::Key> InputManager::m_Keys;

void InputManager::Initalize()
{
	for (size_t i = 0; i < (UINT)eKeyCode::MAX; i++)
	{
		Key key;
		key.keyCode = (eKeyCode)i;
		key.state = eKeyState::NONE;
		key.b_Pressed = false;

		m_Keys.push_back(key);
	}
}

void InputManager::Tick()
{
	for (size_t i = 0; i < (UINT)eKeyCode::MAX; i++)
	{
		//키가 현재 눌려져 있는 경우
		if (GetAsyncKeyState(ASCII[i]) & 0x8000)
		{
			//이전 프레임에서 눌려져있던 상태라면
			if (m_Keys[i].b_Pressed)
			{
				m_Keys[i].state = eKeyState::PRESSED;
			}
			else
			{
				m_Keys[i].state = eKeyState::DOWN;
			}
			m_Keys[i].b_Pressed = true;//키 눌림 체크
		}
		//눌려져있지 않은 경우
		else
		{
			if (m_Keys[i].b_Pressed)
			{
				m_Keys[i].state = eKeyState::UP;
			}
			else
			{
				m_Keys[i].state = eKeyState::NONE;
			}
			m_Keys[i].b_Pressed = false;
		}
	}
}

void InputManager::Render(HDC _dc)
{
}