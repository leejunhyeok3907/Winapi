#include "TimeManager.h"
#include "Application.h"

LARGE_INTEGER TimeManager::m_CpuFrequency;
LARGE_INTEGER TimeManager::m_PrevFrequency;
LARGE_INTEGER TimeManager::m_CurFrequency;
float TimeManager::m_DeltaTime = 0.0f;

void TimeManager::Initalize()
{
	//CPU�� �ʴ� �ݺ��Ǵ� �������� ������ �Լ�
	QueryPerformanceFrequency(&m_CpuFrequency);

	//���α׷� ������������ CPU Ŭ�� ��
	QueryPerformanceCounter(&m_PrevFrequency);
}

void TimeManager::Tick()
{
	QueryPerformanceCounter(&m_CurFrequency);

	float diff_freq = static_cast<float>(m_CurFrequency.QuadPart - m_PrevFrequency.QuadPart);

	//deltatime - �� ������ ���� �ɸ� �ð�
	m_DeltaTime = static_cast<float>(diff_freq / m_CpuFrequency.QuadPart);//�� ������ ���� �ɸ� �ð��� ���� �������� �������ָ� deltatime

	//������ Ŭ������ �ٽ� ����
	m_PrevFrequency = m_CurFrequency;
}

void TimeManager::Render(HDC _dc)
{
	wchar_t szFloat[50] = {};

	float fps = 1.0f / m_DeltaTime;

	swprintf(szFloat, 50, L"DeltaTime : %f", fps);
	int strlen = wcslen(szFloat);

	TextOut(_dc, 10, 10, szFloat, strlen);
}