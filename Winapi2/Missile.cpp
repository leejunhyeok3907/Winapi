#include "Missile.h"
#include "TimeManager.h"

Missile::Missile()
{
	SetScale(Vector2(50.f, 50.f));
}

Missile::~Missile()
{
}

void Missile::Initalize()
{
}

void Missile::Tick()
{
	Vector2 pos = GetPos();

	pos.y -= 100.0f * TimeManager::DeltaTime();

	SetPos(pos);
}

void Missile::Render(HDC _dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Ellipse(_dc, pos.x - scale.x / 2, pos.y - scale.y / 2, pos.x + scale.x / 2, pos.y + scale.y / 2);
}