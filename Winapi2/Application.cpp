#include "Application.h"

Application Application::m_Instance;

Application::Application()
{
	m_WinData.clear();
}

Application::~Application()
{
	ReleaseDC(m_WinData.hWnd, m_WinData.hdc);
}

void Application::Initialize(WindowData data)
{
	m_WinData = data;
	m_WinData.hdc = GetDC(data.hWnd);
}

void Application::Tick()
{
}