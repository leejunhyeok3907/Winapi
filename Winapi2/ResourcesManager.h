#pragma once
#include "Common.h"
#include "Resources.h"

//���ø� Ŭ������ ����� ����
template <typename T>
class ResourcesManager
{
private:
	static map<wstring, Resources*> m_Resources;

public:
	static T* Find(const wstring& _key)
	{
		//auto�� �̿��ص� ��������
		//�������� ��������.
		ResourceIter iter = m_Resources.find(_key);

		if (iter != m_Resources.end())//�ش� key�� ���� ���ҽ��� �ִ�
		{
			return dynamic_cast<T*>(iter->second);
		}

		return nullptr;
	}

	static T* Load(const wstring& _key, const wstring& _path)
	{
		T* resource = Find(_key);

		//�ش� Ű�� �̹� �ε��� ���ҽ��� ���� ���
		if (resource != nullptr)
			return resource;

		//���ҽ��� ����
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

//static���� �ʱ�ȭ
template<typename T>
map<wstring, Resources*> ResourcesManager<T>::m_Resources;
