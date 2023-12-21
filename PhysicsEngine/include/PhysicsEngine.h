#pragma once

#include <cstdint>
#include <random>
#include <unordered_map>

#include <CircleCollider.h>

namespace pe {

	class PhysicsEngine
	{
	public:
		PhysicsEngine();
		~PhysicsEngine();

		uint32_t CreateCircleCollider();
		uint32_t CreateCircleCollider(Vector2f position, float radius);
		CircleCollider& GetCircleCollider(uint32_t id);

		void Update(float deltaTime);
	private:
		std::unordered_map<uint32_t, CircleCollider> m_CircleColliders;
		std::mt19937 m_Distribution;
		std::uniform_int_distribution<uint32_t> m_Random;

		Vector2f m_Gravity;
	};

}