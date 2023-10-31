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
		if (Vector2f::Dot(position, other.position) <= (radius + other.radius) * (radius * other.radius))
		{
			return true;
		}

		return false;
	}

	bool CircleCollider::Collide(const CircleCollider& other, Vector2f* collisionPoint)
	{
		bool collide = Collide(other);
		Vector2f collisionDir = other.position - position;

		if (collide)
		{
			*collisionPoint = position + collisionDir.Normalize() * radius;
		}

		return collide;
	}

}