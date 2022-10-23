#pragma once
#include "Common.h"
#include "Entity.h"

class GameObject :
    public Entity
{
private:
    Vector2 m_Pos;
    Vector2 m_Scale;

public:
    virtual void Initalize();
    virtual void Tick();
    virtual void Render(HDC _dc);

    void SetPos(Vector2 _pos) { m_Pos = _pos; }
    void SetScale(Vector2 _scale) { m_Scale = _scale; }
    Vector2 GetPos() { return m_Pos; }
    Vector2 GetScale() { return m_Scale; }

public:
    GameObject();
    ~GameObject();
};