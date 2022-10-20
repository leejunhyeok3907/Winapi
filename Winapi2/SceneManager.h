#pragma once
#include "Common.h"

class Scene;

class SceneManager
{
private:
	static Scene* m_Scenes[(UINT)eSceneType::Max];
	static Scene* m_CurScene;

public:
	static Scene* GetCurScene() { return m_CurScene; }

public:
	static void Initalize();
	static void Tick();
	static void Render(HDC _dc);
	static void Release();
};

