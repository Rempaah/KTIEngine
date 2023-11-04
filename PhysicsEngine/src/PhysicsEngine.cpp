#include "PhysicsEngine.h"

#include <random>
#include <cassert>

namespace pe {

	Vector2f PhysicsEngine::gravity = { 0.0f, 1000.0f };

	std::unordered_map<uint32_t, CircleCollider> PhysicsEngine::m_CircleColliders;
	std::mt19937 PhysicsEngine::m_Distribution;
	std::uniform_int_distribution<uint32_t> PhysicsEngine::m_Random(0, UINT32_MAX);

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

		BoxCollider boxCollider;
		m_BoxColliders[id] = boxCollider;

		return id;
	}

	uint32_t PhysicsEngine::CreateCircleCollider(Vector2f position, float radius)
	{
		uint32_t id = CreateCircleCollider();

		m_CircleColliders[id].position = position;
		m_CircleColliders[id].radius = radius;

		return id;
	}

	uint32_t PhysicsEngine::CreateBoxCollider(Vector2f position, Vector2f size)
	{
		uint32_t id = CreateBoxCollider();
		m_BoxColliders[id].position = position;
		m_BoxColliders[id].size = size;
		
		return id;
	}

	CircleCollider& PhysicsEngine::GetCircleCollider(uint32_t id)
	{
		assert(m_CircleColliders.contains(id) && "Cannot find circle collider with id " && id);

		return m_CircleColliders[id];
	}

	BoxCollider& PhysicsEngine::GetBoxCollider(uint32_t id)
	{
		assert(m_BoxColliders.contains(id) && "Cannot find box collider with id " && id);

		return m_BoxColliders[id];
	}

	void PhysicsEngine::Update(float deltaTime)
	{
		for (auto& collider : m_CircleColliders)
		{
			collider.second.position += collider.second.velocity * deltaTime;
			collider.second.velocity += gravity * deltaTime;
		}
	}

}