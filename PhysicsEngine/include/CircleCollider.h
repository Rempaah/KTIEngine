#pragma once

namespace pe {
	class CircleCollider
	{
	public:
		CircleCollider();
		CircleCollider(float x, float y, float radius);
		~CircleCollider();

		bool Collide(const CircleCollider& other);
		bool Collide(const CircleCollider& other, float* xPoint, float* yPoint);

		float x;
		float y;
		float radius;
	private:
	};
}