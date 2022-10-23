#include "LogoScene.h"

#include "TimeManager.h"

#include "Player.h"
#include "Astro.h"

LogoScene::LogoScene()
	: m_fCooltime(0.f)
{
}

LogoScene::~LogoScene()
{
}

void LogoScene::Initalize()
{
	Player* player = new Player();

	AddGameObject(player);
}

void LogoScene::Tick()
{
	Scene::Tick();

	if (m_fCooltime <= 0)
	{
		Astro* astro = new Astro;

		AddGameObject(astro);

		m_fCooltime = rand() % 5;
	}

	m_fCooltime -= TimeManager::DeltaTime();
}

void LogoScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}