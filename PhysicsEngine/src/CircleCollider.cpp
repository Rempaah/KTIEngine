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


	bool CircleCollider::Collide(const BoxCollider& other, Vector2f* collisionNormal) const
	{
		if (!(position.x + radius <= other.position.x - other.size.x / 2 || position.x - radius >= other.position.x + other.size.x / 2
			|| position.y + radius <= other.position.y - other.size.y / 2 || position.y - radius >= other.position.y + other.size.y / 2))
		{
			Vector2f closestBoxPoint;

			closestBoxPoint.x = std::clamp(position.x, other.position.x - other.size.x / 2, other.position.x + other.size.x / 2);
			closestBoxPoint.y = std::clamp(position.y, other.position.y - other.size.y / 2, other.position.y + other.size.y / 2);

			Vector2f distanceToBox = position - closestBoxPoint;
			if (Vector2f::Dot(distanceToBox, distanceToBox) < radius * radius)
			{
				*collisionNormal = distanceToBox.Normalize();
				return true;
			}
		}

		return false;
	}
}