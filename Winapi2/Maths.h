#pragma once

struct Vector2
{
	float x;
	float y;

	//컴파일러가 생성해주는 기본 생성자를 사용하겠다
	Vector2(const Vector2& _other) = default;
	Vector2() = default;
	~Vector2() = default;

	Vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};