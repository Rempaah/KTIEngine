#pragma once

#include <algorithm>

namespace pe {

	class Vector2f
	{
	public:
		float x, y;

		Vector2f();
		Vector2f(float x, float y);
		~Vector2f();

		Vector2f operator+(const Vector2f& other) const;
		Vector2f operator-(const Vector2f& other) const;
		Vector2f operator*(float other) const;
		Vector2f operator/(float other) const;
		void operator+=(const Vector2f& other);
		void operator-=(const Vector2f& other);
		void operator*=(float other);
		void operator/=(float other);
		float Length() const;
		Vector2f Normalize() const;

		static float Dot(const Vector2f& v1, const Vector2f& v2);
		static float Distance(const Vector2f& v1, const Vector2f& v2);
	};

}