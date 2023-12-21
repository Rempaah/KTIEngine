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

	bool CircleCollider::Collide(const CircleCollider& other, Vector2f* collisionNormal) const
	{
		Vector2f distance = other.position - position;

		if (Vector2f::Dot(distance, distance) <= radius * radius)
		{
			*collisionNormal = distance.Normalize() * -1;
			return true;
		}

		return false;
	}
}