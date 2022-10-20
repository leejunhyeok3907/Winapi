#include "Application.h"
#include "SceneManager.h"

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
}

void Application::Tick()
{
	SceneManager::Tick();

	SceneManager::Render(m_WinData.hdc);
}