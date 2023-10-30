#include "pMath.h"

#include <math.h>

namespace pe {

	Vector2f::Vector2f()
		: x(0), y(0)
	{}

	Vector2f::Vector2f(float x, float y)
		: x(x), y(y)
	{}

	Vector2f::~Vector2f()
	{}

	Vector2f Vector2f::operator+(const Vector2f& other) const
	{
		Vector2f result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	Vector2f Vector2f::operator-(const Vector2f& other) const
	{
		Vector2f result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	Vector2f Vector2f::operator*(float other) const
	{
		Vector2f result;
		result.x = other * x;
		result.y = other * y;
		return result;
	}

	Vector2f Vector2f::operator/(float other) const
	{
		return *this * (1 / other);
	}

	float Vector2f::dot(const Vector2f& v1, const Vector2f& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Vector2f::distance(const Vector2f& v1, const Vector2f& v2)
	{
		return sqrt(dot(v2 - v1, v2 - v1) * dot(v2 - v1, v2 - v1));
	}

}