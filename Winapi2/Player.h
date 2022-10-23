#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
private:

public:
    virtual void Initalize() override;
    virtual void Tick() override;
    virtual void Render(HDC _dc) override;

public:
    Player();
    ~Player();
};