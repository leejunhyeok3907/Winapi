#pragma once
#include "Scene.h"
class LogoScene :
    public Scene
{
private:
    float m_fCooltime;

public:
    void Initalize() override;
    void Tick() override;
    void Render(HDC _dc) override;

public:
    LogoScene();
    ~LogoScene();
};