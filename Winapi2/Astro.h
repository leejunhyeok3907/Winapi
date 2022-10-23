#pragma once
#include "GameObject.h"
class Astro :
    public GameObject
{
private:
    float m_fSpeed;

public:
    virtual void Initalize() override;
    virtual void Tick() override;
    virtual void Render(HDC _dc) override;

public:
    Astro();
    ~Astro();
};