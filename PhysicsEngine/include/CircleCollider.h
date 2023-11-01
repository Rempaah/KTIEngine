#pragma once

#include "PMath.h"

namespace pe {
	class CircleCollider
	{
	public:
		CircleCollider();
		CircleCollider(const Vector2f& position, float radius);
		~CircleCollider();

		bool Collide(const CircleCollider& other);
		bool Collide(const CircleCollider& other, Vector2f* collisionPoint);

		Vector2f position;
		Vector2f velocity;

		float radius;
	private:
	};
}