#pragma once
#include "Common.h"

class TimeManager
{
private:
	static LARGE_INTEGER m_CpuFrequency;
	static LARGE_INTEGER m_PrevFrequency;
	static LARGE_INTEGER m_CurFrequency;

	static float m_DeltaTime;
public:
	static const float DeltaTime() { return m_DeltaTime; }

public:
	static void Initalize();
	static void Tick();
	static void Render(HDC _dc);
};

