#pragma once
#include "GameObject.h"

class Image;

class Player :
    public GameObject
{
private:
    Image* m_Image;

public:
    virtual void Initalize() override;
    virtual void Tick() override;
    virtual void Render(HDC _dc) override;

public:
    Player();
    ~Player();
};