#pragma once

#include "PMath.h"
#include "BoxCollider.h"

namespace pe {
	class CircleCollider
	{
	public:
		CircleCollider();
		CircleCollider(const Vector2f& position, float radius);
		~CircleCollider();

		bool Collide(const CircleCollider& other, Vector2f* collisionNormal) const;
		bool Collide(const BoxCollider& other, Vector2f* collisionNormal) const;

		Vector2f position;
		Vector2f velocity = { 0.0f, 0.0f };

		float radius;
	private:
	};
}