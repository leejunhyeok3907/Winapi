#pragma once
#include "Common.h"

class Application
{
private:
	static Application m_Instance;

	WindowData m_WinData;

public:
	//동적할당 싱글톤의 단점 : 소멸자가 호출이 되지않는다
	static Application& GetInstance()
	{
		return m_Instance;
	}

public:
	void Initialize(WindowData data);
	void Tick();

public:
	Application();
	~Application();
};

