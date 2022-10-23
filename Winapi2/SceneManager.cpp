#include "SceneManager.h"
#include "LogoScene.h"

Scene* SceneManager::m_Scenes[(UINT)eSceneType::Max] = {};
Scene* SceneManager::m_CurScene = nullptr;

void SceneManager::Initalize()
{
	//����ִ� ��� �� �ʱ�ȭ
	m_Scenes[(UINT)eSceneType::Logo] = new LogoScene;
	m_Scenes[(UINT)eSceneType::Logo]->Initalize();

	m_CurScene = m_Scenes[(UINT)eSceneType::Logo];
}

void SceneManager::Tick()
{
	//���� �� ������Ʈ
	m_CurScene->Tick();
}

void SceneManager::Render(HDC _dc)
{
	//���� �� ����
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