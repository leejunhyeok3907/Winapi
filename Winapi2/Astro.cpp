#include "Astro.h"
#include "TimeManager.h"

Astro::Astro()
{
	Vector2 tempPos;
	Vector2 Size;
	tempPos.y = -300;
	tempPos.x = rand() % 1920;


	Size = (rand() % 200) + 100;
	m_fSpeed = (rand() % 300) + 200;

	SetPos(tempPos);
	SetScale(Size);
}

Astro::~Astro()
{
}

void Astro::Initalize()
{
}

void Astro::Tick()
{
	Vector2 pos = GetPos();

	pos.y += m_fSpeed * TimeManager::DeltaTime();

	SetPos(pos);
}

void Astro::Render(HDC _dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Ellipse(_dc, pos.x - scale.x / 2, pos.y - scale.y / 2, pos.x + scale.x / 2, pos.y + scale.y / 2);
}