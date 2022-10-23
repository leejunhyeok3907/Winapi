#include "LogoScene.h"

#include "Player.h"

LogoScene::LogoScene()
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
}

void LogoScene::Render(HDC _dc)
{
	Scene::Render(_dc);
}