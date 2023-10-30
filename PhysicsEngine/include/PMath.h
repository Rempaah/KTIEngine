#pragma once

namespace pe {

	class Vector2f
	{
	public:
		float x, y;

		Vector2f();
		Vector2f(float x, float y);
		~Vector2f();

		Vector2f operator+(const Vector2f& other) const;
		Vector2f operator-(const Vector2f& other)const;
		Vector2f operator*(float other) const;
		Vector2f operator/(float other) const;

		static float dot(const Vector2f& v1, const Vector2f& v2);
		static float distance(const Vector2f& v1, const Vector2f& v2);
	};

}