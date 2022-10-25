#pragma once
#include "Common.h"

class Resources
{
private:
	wstring m_Path;
	wstring m_Key;

public:
	const wstring& GetPath() { return m_Path; }
	const wstring& GetKey() { return m_Key; }

	void SetPath(const wstring& _path) { m_Path = _path; }
	void SetKey(const wstring& _key) { m_Key = _key; }

	virtual HRESULT Load(const wstring& _path) PURE;

public:
	Resources();
	virtual ~Resources();
};

