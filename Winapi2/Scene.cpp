#include "Scene.h"
#include "GameObject.h"

#include "Player.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (size_t i = 0; i < m_Objvec.size(); i++)
	{
		delete m_Objvec[i];
	}
}

void Scene::Initalize()
{
	for (size_t i = 0; i < m_Objvec.size(); i++)
	{
		m_Objvec[i]->Initalize();
	}
}

void Scene::Tick()
{
	for (size_t i = 0; i < m_Objvec.size(); i++)
	{
		m_Objvec[i]->Tick();
	}
}

void Scene::Render(HDC _dc)
{
	for (size_t i = 0; i < m_Objvec.size(); i++)
	{
		m_Objvec[i]->Render(_dc);
	}
}

void Scene::AddGameObject(GameObject* _object)
{
	if (_object == nullptr) return;

	m_Objvec.push_back(_object);
}