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

	bool CircleCollider::Collide(const CircleCollider& other) const
	{
		if (Vector2f::Dot(position, other.position) <= (radius + other.radius) * (radius * other.radius))
		{
			return true;
		}

		return false;
	}

	bool CircleCollider::Collide(const CircleCollider& other, Vector2f* collisionNormal) const
	{
		bool collide = Collide(other);
		Vector2f distance = other.position - position;

		if (collide)
		{
			*collisionNormal =  distance.Normalize() * -1;
		}

		return collide;
	}


	bool CircleCollider::Collide(const BoxCollider& other) const
	{
		if (position.x + radius < other.position.x - other.size.x / 2 || position.x - radius > other.position.x + other.size.x / 2
			|| position.y + radius < other.position.y - other.size.y / 2 || position.y - radius > other.position.y + other.size.y / 2)
			return false;

		return true;
	}

	bool CircleCollider::Collide(const BoxCollider& other, Vector2f* collisionNormal) const
	{
		bool collide = Collide(other);

		if (collide)
		{
			Vector2f normal;
			if (std::abs((position.x - other.position.x) - other.size.x / 2) > std::abs((position.y - other.position.y) - other.size.y))
			{
				// top collision
				if (position.y - other.position.y > 0)
				{
					normal = { 0, 1 };
				}
				// bottom collision
				else
				{
					normal = { 0, -1 };
				}
			}
			else
			{
				// left collision
				if (position.x - other.position.x > 0)
				{
					normal = { 1, 0 };
				}
				// bottom collision
				else
				{
					normal = { -1, 0 };
				}
			}

			*collisionNormal = normal;
		}

		return collide;
	}
}