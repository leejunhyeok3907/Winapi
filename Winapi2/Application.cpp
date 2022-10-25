#include "Application.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "InputManager.h"

Application Application::m_Instance;

Application::Application()
{
	m_WinData.clear();
}

Application::~Application()
{
	SceneManager::Release();
	ReleaseDC(m_WinData.hWnd, m_WinData.hdc);
	ReleaseDC(m_WinData.hWnd, m_WinData.backBuffer);
}

void Application::Initialize(WindowData _data)
{
	InitalizeWindow(_data);

	SceneManager::Initalize();
	TimeManager::Initalize();
	InputManager::Initalize();
}

void Application::InitalizeWindow(WindowData _data)//윈도우 관련 초기화만 따로
{
	//코드가 길어지면 읽기 힘들어지니 가독성을 위해 코드 분할
	m_WinData = _data;
	m_WinData.hdc = GetDC(_data.hWnd);

	//비트맵 해상도를 설정하기 위한 실제 윈도우 크기 계산
	RECT rect = { 0, 0, m_WinData.width, m_WinData.height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	SetWindowPos(m_WinData.hWnd
		, nullptr, 0, 0
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);

	ShowWindow(m_WinData.hWnd, true);
	//더블버퍼링, 스왑 체인
	m_WinData.backTexture = CreateCompatibleBitmap(m_WinData.hdc, m_WinData.width, m_WinData.height);

	m_WinData.backBuffer = CreateCompatibleDC(m_WinData.hdc);

	HBITMAP DefaultBitmap = (HBITMAP)SelectObject(m_WinData.backBuffer, m_WinData.backTexture);

	DeleteObject(DefaultBitmap);
}

void Application::Tick()
{
	TimeManager::Tick();
	InputManager::Tick();
	SceneManager::Tick();

	Rectangle(m_WinData.backBuffer, -1, -1, m_WinData.width + 1, m_WinData.height + 1);

	SceneManager::Render(m_WinData.backBuffer);
	TimeManager::Render(m_WinData.backBuffer);
	InputManager::Render(m_WinData.backBuffer);

	//DC간의 이미지를 복사해주는 함수
	BitBlt(m_WinData.hdc, 0, 0, m_WinData.width, m_WinData.height,
		m_WinData.backBuffer, 0, 0, SRCCOPY);
}