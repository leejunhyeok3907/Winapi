#pragma once
#include "Common.h"

class Application
{
private:
	static Application m_Instance;

	WindowData m_WinData;

public:
	//�����Ҵ� �̱����� ���� : �Ҹ��ڰ� ȣ���� �����ʴ´�
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

