#include "PhysicsEngine.h"

#include <iostream>
#include <random>
#include <cassert>

namespace pe {
	PhysicsEngine::PhysicsEngine(float left, float right, float bottom, float top)
		: m_Random(0, UINT32_MAX), m_Gravity({0.0f, -1000.0f}),
		left(left), right(right), bottom(bottom), top(top)
	{}

	PhysicsEngine::~PhysicsEngine()
	{}

	uint32_t PhysicsEngine::CreateCircleCollider()
	{
		uint32_t id = m_Random(m_Distribution);
		while (m_CircleColliders.contains(id))
		{
			id = m_Random(m_Distribution);
		}

		CircleCollider circleCollider;
		m_CircleColliders[id] = circleCollider;

		return id;
	}

	uint32_t PhysicsEngine::CreateCircleCollider(Vector2f position, float radius)
	{
		uint32_t id = CreateCircleCollider();

		m_CircleColliders[id].position = position;
		m_CircleColliders[id].radius = radius;

		return id;
	}

	CircleCollider& PhysicsEngine::GetCircleCollider(uint32_t id)
	{
		assert(m_CircleColliders.contains(id) && "Cannot find circle collider with id " && id);

		return m_CircleColliders[id];
	}

	void PhysicsEngine::Update(float deltaTime)
	{
		for (auto& [id, circle] : m_CircleColliders)
		{
			if (circle.position.y - circle.radius < bottom || circle.position.y + circle.radius > top)
			{
				circle.position.y = (circle.position.y - circle.radius < bottom)? bottom + circle.radius : top - circle.radius;
				circle.velocity.y *= -1;
			}
			if (circle.position.x - circle.radius < left || circle.position.x + circle.radius > right)
			{
				circle.position.x = (circle.position.x - circle.radius < left) ? left + circle.radius : right - circle.radius;
				circle.velocity.x *= -1;
			}

			circle.velocity += m_Gravity * deltaTime;
			circle.position += circle.velocity * deltaTime;

			for (auto& [otherId, otherCircle] : m_CircleColliders)
			{
				if (id == otherId)
					continue;
				pe::Vector2f collisionNormal;
				if (circle.Collide(otherCircle, &collisionNormal))
				{
					//std::cout << circle.second.velocity.Length() << ", ";
					pe::Vector2f temp = circle.velocity;
					circle.velocity = otherCircle.velocity;
					otherCircle.velocity = temp;
					//std::cout << circle.second.velocity.Length() << "circle and circle"<< std::endl;
				}
			}
		}
	}

}