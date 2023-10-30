#include <CirlceCollider.h>

namespace pe {

	CircleCollider::CircleCollider()
		: x(0), y(0), radius(1)
	{}

	CircleCollider::CircleCollider(float x, float y, float radius)
		: x(x), y(y), radius(radius)
	{}

	CircleCollider::~CircleCollider()
	{}

	bool CircleCollider::Collide(const CircleCollider& other)
	{
		// TODO: Collision check between circles
		return false;
	}

	bool CircleCollider::Collide(const CircleCollider& other, float* xPoint, float* yPoint)
	{
		// TODO: Collision check + collision point
		return false;
	}

}