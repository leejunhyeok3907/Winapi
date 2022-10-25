#pragma once
#include "Common.h"
#include "Resources.h"

//템플릿 클래스는 헤더에 구현
template <typename T>
class ResourcesManager
{
private:
	static map<wstring, Resources*> m_Resources;

public:
	static T* Find(const wstring& _key)
	{
		//auto를 이용해도 괜찮으나
		//가독성이 떨어진다.
		ResourceIter iter = m_Resources.find(_key);

		if (iter != m_Resources.end())//해당 key를 가진 리소스가 있다
		{
			return dynamic_cast<T*>(iter->second);
		}

		return nullptr;
	}

	static T* Load(const wstring& _key, const wstring& _path)
	{
		T* resource = Find(_key);

		//해당 키로 이미 로딩된 리소스가 있을 경우
		if (resource != nullptr)
			return resource;

		//리소스가 없음
		resource = new T;
		if (FAILED(resource->Load(_path)))
		{
			MessageBox(nullptr, L"Image Load Failed", L"Error", MB_OK);
			delete resource;
			return nullptr;
		}

		resource->SetKey(_key);
		resource->SetPath(_path);

		m_Resources.insert({ _key, resource });

		return dynamic_cast<T*>(resource);
	}

	typedef map<wstring, Resources*>::iterator ResourceIter;
};

//static변수 초기화
template<typename T>
map<wstring, Resources*> ResourcesManager<T>::m_Resources;
