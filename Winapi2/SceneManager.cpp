#include "SceneManager.h"
#include "LogoScene.h"

Scene* SceneManager::m_Scenes[(UINT)eSceneType::Max] = {};
Scene* SceneManager::m_CurScene = nullptr;

void SceneManager::Initalize()
{
	//들고있는 모든 씬 초기화
	m_Scenes[(UINT)eSceneType::Logo] = new LogoScene;
	m_Scenes[(UINT)eSceneType::Logo]->Initalize();

	m_CurScene = m_Scenes[(UINT)eSceneType::Logo];
}

void SceneManager::Tick()
{
	//현재 씬 업데이트
	m_CurScene->Tick();
}

void SceneManager::Render(HDC _dc)
{
	//현재 씬 렌더
	m_CurScene->Render(_dc);
}

void SceneManager::Release()
{
	for (UINT i = 0; i < (UINT)eSceneType::Max; i++)
	{
		if (m_Scenes[i] != nullptr)
		{
			delete m_Scenes[i];
			m_Scenes[i] = nullptr;
		}
	}
}
