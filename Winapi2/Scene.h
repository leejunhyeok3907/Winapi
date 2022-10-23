#pragma once
#include "Common.h"
#include "Entity.h"

class GameObject;

class Scene : public Entity
{
private:
	vector<GameObject*> m_Objvec;

public:
	virtual void Initalize() PURE;
	virtual void Tick();
	virtual void Render(HDC _dc);

	void AddGameObject(GameObject* _object);

public:
	Scene();
	virtual ~Scene();
};
