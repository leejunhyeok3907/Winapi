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

void Application::Initialize(WindowData _data)
{
	InitalizeWindow(_data);

	SceneManager::Initalize();
	TimeManager::Initalize();
	InputManager::Initalize();
}

void Application::InitalizeWindow(WindowData _data)//������ ���� �ʱ�ȭ�� ����
{
	//�ڵ尡 ������� �б� ��������� �������� ���� �ڵ� ����
	m_WinData = _data;
	m_WinData.hdc = GetDC(_data.hWnd);

	//��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�� ���
	RECT rect = { 0, 0, m_WinData.width, m_WinData.height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	SetWindowPos(m_WinData.hWnd
		, nullptr, 0, 0
		, rect.right - rect.left
		, rect.bottom - rect.top
		, 0);

	ShowWindow(m_WinData.hWnd, true);
	//������۸�, ���� ü��
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

	//DC���� �̹����� �������ִ� �Լ�
	BitBlt(m_WinData.hdc, 0, 0, m_WinData.width, m_WinData.height,
		m_WinData.backBuffer, 0, 0, SRCCOPY);
}