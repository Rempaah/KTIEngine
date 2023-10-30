#include <CircleCollider.h>

namespace pe {

	CircleCollider::CircleCollider()
		: radius(0)
	{}

	CircleCollider::CircleCollider(const Vector2f& position, float radius)
		: position(position), radius(radius)
	{}

	CircleCollider::~CircleCollider()
	{}

	bool CircleCollider::Collide(const CircleCollider& other)
	{
		// TODO: Collision check between circles
		return false;
	}

	bool CircleCollider::Collide(const CircleCollider& other, Vector2f* collisionPoint)
	{
		// TODO: Collision check + collision point
		return false;
	}

}