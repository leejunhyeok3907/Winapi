#include "TimeManager.h"
#include "Application.h"

LARGE_INTEGER TimeManager::m_CpuFrequency;
LARGE_INTEGER TimeManager::m_PrevFrequency;
LARGE_INTEGER TimeManager::m_CurFrequency;
float TimeManager::m_DeltaTime = 0.0f;

void TimeManager::Initalize()
{
	//CPU의 초당 반복되는 진동수를 얻어오는 함수
	QueryPerformanceFrequency(&m_CpuFrequency);

	//프로그램 시작했을때의 CPU 클럭 수
	QueryPerformanceCounter(&m_PrevFrequency);
}

void TimeManager::Tick()
{
	QueryPerformanceCounter(&m_CurFrequency);

	float diff_freq = static_cast<float>(m_CurFrequency.QuadPart - m_PrevFrequency.QuadPart);

	//deltatime - 한 프레임 동안 걸린 시간
	m_DeltaTime = static_cast<float>(diff_freq / m_CpuFrequency.QuadPart);//한 프레임 동안 걸린 시간을 고유 진동수로 나누어주면 deltatime

	//이전의 클럭값을 다시 세팅
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