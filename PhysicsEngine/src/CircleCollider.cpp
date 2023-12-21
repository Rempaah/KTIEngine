#include <CircleCollider.h>
#include<iostream>

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
		//std::cout << Vector2f::Dot(distance, distance) << " " << 4 * radius * radius << std::endl;
		float dis = Vector2f::Dot(distance, distance);
		if (dis>1e-6 and dis <= 4*radius * radius)
		{
			*collisionNormal = distance.Normalize() * -1;
			return true;
		}

		

		return false;
	}
}