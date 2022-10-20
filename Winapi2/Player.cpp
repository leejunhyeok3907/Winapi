#include "Player.h"

Player::Player()
{
	SetPos(Vector2(100.f, 100.f));
	SetScale(Vector2(100.f, 100.f));
}

Player::~Player()
{
}

void Player::Initalize()
{
}

void Player::Tick()
{
}

void Player::Render(HDC _dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Rectangle(_dc, pos.x - scale.x / 2, pos.y - scale.y / 2, pos.x + scale.x / 2, pos.y + scale.y / 2);
}
