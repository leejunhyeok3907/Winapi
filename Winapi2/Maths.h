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

	Vector2 operator+(const Vector2& _other)
	{
		Vector2 temp;
		temp.x = this->x + _other.x;
		temp.y = this->y + _other.y;

		return temp;
	}

	Vector2 operator-(const Vector2& _other)
	{
		Vector2 temp;
		temp.x = this->x - _other.x;
		temp.y = this->y - _other.y;

		return temp;
	}

	Vector2 operator/(const float _value)
	{
		Vector2 temp;
		
		temp.x = x / _value;
		temp.y = y / _value;

		return temp;
	}
};