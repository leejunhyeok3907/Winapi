#pragma once
#include "Scene.h"
class LogoScene :
    public Scene
{
private:

public:
    void Initalize() override;
    void Tick() override;
    void Render(HDC _dc) override;

public:
    LogoScene();
    ~LogoScene();
};