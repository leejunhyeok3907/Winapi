#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Scene.h"

#include "Missile.h"

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
	Vector2 pos = GetPos();

	if (KEY_CHECK(eKeyCode::W))
	{
		pos.y -= 200 * TimeManager::DeltaTime();
	}

	if (KEY_CHECK(eKeyCode::S))
	{
		pos.y += 200 * TimeManager::DeltaTime();
	}

	if (KEY_CHECK(eKeyCode::A))
	{
		pos.x -= 200 * TimeManager::DeltaTime();
	}

	if (KEY_CHECK(eKeyCode::D))
	{
		pos.x += 200 * TimeManager::DeltaTime();
	}

	if (KEY_DOWN(eKeyCode::SPACE))
	{
		Missile* missile = new Missile;

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale();

		missile->SetPos(playerPos);

		Scene* playScene = SceneManager::GetCurScene();
		playScene->AddGameObject(missile);
	}

	SetPos(pos);
}

void Player::Render(HDC _dc)
{
	Vector2 pos = GetPos();
	Vector2 scale = GetScale();

	Rectangle(_dc, pos.x - scale.x / 2, pos.y - scale.y / 2, pos.x + scale.x / 2, pos.y + scale.y / 2);
}