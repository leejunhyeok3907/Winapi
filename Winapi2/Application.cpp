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
}

void Application::Initialize(WindowData data)
{
	m_WinData = data;
	m_WinData.hdc = GetDC(data.hWnd);

	SceneManager::Initalize();
	TimeManager::Initalize();
	InputManager::Initalize();
}

void Application::Tick()
{
	TimeManager::Tick();
	InputManager::Tick();
	SceneManager::Tick();

	SceneManager::Render(m_WinData.hdc);
	TimeManager::Render(m_WinData.hdc);
	InputManager::Render(m_WinData.hdc);
}