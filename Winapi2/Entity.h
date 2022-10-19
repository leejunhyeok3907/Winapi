#pragma once
#include "Common.h"

class Entity
{
private:
	wstring m_Name;
	UINT m_UID;

public:
	void SetName(const wstring _name) { m_Name = _name; }
	wstring GetName() { return m_Name; }

public:
	Entity();
	virtual ~Entity();
};

