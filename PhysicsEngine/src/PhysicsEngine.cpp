#include "PhysicsEngine.h"

#include <iostream>
#include <random>
#include <cassert>

namespace pe {

	Vector2f PhysicsEngine::gravity = { 0.0f, 1000.0f };

	std::mt19937 PhysicsEngine::m_Distribution;
	std::uniform_int_distribution<uint32_t> PhysicsEngine::m_Random(0, UINT32_MAX);

	std::unordered_map<uint32_t, CircleCollider> PhysicsEngine::m_CircleColliders;

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

	uint32_t PhysicsEngine::CreateBoxCollider()
	{
		uint32_t id = m_Random(m_Distribution);
		while (m_CircleColliders.contains(id))
		{
			id = m_Random(m_Distribution);
		}

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
		for (auto& circle : m_CircleColliders)
		{
			/*for (auto& box : m_BoxColliders)
			{
				pe::Vector2f collisionNormal;
				if (circle.second.Collide(box.second, &collisionNormal))
				{
					//std::cout << circle.second.velocity.Length() << ", ";
					circle.second.velocity += collisionNormal * -2.0f * pe::Vector2f::Dot(circle.second.velocity, collisionNormal);
					//std::cout << circle.second.velocity.Length() << std::endl;
				}
			}

			for (auto& circle2 : m_CircleColliders) {
				pe::Vector2f collisionNormal;
				if (circle.second.Collide(circle2.second, &collisionNormal)) {
					//std::cout << circle.second.velocity.Length() << ", ";
					circle.second.velocity += collisionNormal * -2.0f * pe::Vector2f::Dot(circle.second.velocity, collisionNormal);
					//std::cout << circle.second.velocity.Length() << "circle and circle"<< std::endl;
				}
			}*/

			circle.second.velocity += gravity * deltaTime;
			circle.second.position += circle.second.velocity * deltaTime;
		}
	}

}