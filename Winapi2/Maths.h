#pragma once

struct Vector2
{
	float x;
	float y;

	//�����Ϸ��� �������ִ� �⺻ �����ڸ� ����ϰڴ�
	Vector2(const Vector2& _other) = default;
	Vector2() = default;
	~Vector2() = default;

	Vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};