#include "GameObject.h"

GameObject::GameObject()
	: m_Pos(Vector2(0.f, 0.f))
	, m_Scale(Vector2(1.0f, 1.0f))
{
}

GameObject::~GameObject()
{
}

void GameObject::Initalize()
{
}

void GameObject::Tick()
{
}

void GameObject::Render(HDC _dc)
{
}