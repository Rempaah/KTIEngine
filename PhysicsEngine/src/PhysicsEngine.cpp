#include "PhysicsEngine.h"

#include <random>
#include <cassert>

namespace pe {

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
		for (auto i = m_CircleColliders.begin(); i != m_CircleColliders.end(); i++)
		{

		}
	}

}