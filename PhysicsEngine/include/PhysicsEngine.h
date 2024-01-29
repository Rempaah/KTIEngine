#pragma once

#include <cstdint>
#include <random>
#include <unordered_map>

#include <CircleCollider.h>
#include <Quadtree.h>

namespace pe {

	class PhysicsEngine
	{
	public:
		PhysicsEngine(float left, float right, float bottom, float top);
		~PhysicsEngine();

		uint32_t CreateCircleCollider();
		uint32_t CreateCircleCollider(Vector2f position, float radius);
		CircleCollider& GetCircleCollider(uint32_t id);

		float left, right, bottom, top;

		void Start();
		void UpdateGrid(float deltaTime);
		void UpdateQuadtree(float deltaTime);
	private:
		std::unordered_map<uint32_t, CircleCollider> m_CircleColliders;
		std::mt19937 m_Distribution;
		std::uniform_int_distribution<uint32_t> m_Random;
		std::vector< std::vector<std::vector<int> > > grid;

		Quadtree m_Quadtree;

		Vector2f m_Gravity;
	};

}