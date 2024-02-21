#include "PhysicsEngine.h"

#include <iostream>
#include <random>
#include <cassert>

namespace pe {
	PhysicsEngine::PhysicsEngine(float left, float right, float bottom, float top)
		: m_Random(0, UINT32_MAX), m_Gravity({0.0f, -1000.0f}),
		left(left), right(right), bottom(bottom), top(top), m_Quadtree(left, right, top, bottom)
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
	
	

	void PhysicsEngine::Start() {
		grid.resize(101);
		for (int i = 0; i <= 100; i++) grid[i].resize(101);
		for (auto& [id, circle] : m_CircleColliders) {
			int col, row;
			col = circle.position.x / 10;
			row = circle.position.y / 10;
			std::cout << col << " " << row << std::endl;
			grid[col][row].push_back(id);
			circle.loc = { col, row };
		}
	}

	void PhysicsEngine::UpdateGrid(float deltaTime)
	{
		int count = 0;

		for (auto& [id, circle] : m_CircleColliders)
		{
			circle.velocity += m_Gravity * deltaTime;
			circle.position += circle.velocity * deltaTime;

			if (circle.position.y - circle.radius < bottom || circle.position.y + circle.radius > top)
			{
				circle.position.y = (circle.position.y - circle.radius < bottom) ? bottom + circle.radius : top - circle.radius;
				circle.velocity.y *= -1;
			}
			if (circle.position.x - circle.radius < left || circle.position.x + circle.radius > right)
			{
				circle.position.x = (circle.position.x - circle.radius < left) ? left + circle.radius : right - circle.radius;
				circle.velocity.x *= -1;
			}

			int col, row;
			col = circle.position.x / 10;
			row = circle.position.y / 10;

			auto it = find(grid[circle.loc.first][circle.loc.second].begin(), grid[circle.loc.first][circle.loc.second].end(), id);
			grid[circle.loc.first][circle.loc.second].erase(it);

			grid[col][row].push_back(id);
			circle.loc = { col, row };

			int minx = std::max(0, circle.loc.first - 1), maxx = std::min(100, circle.loc.first + 1);
			int miny = std::max(0, circle.loc.second - 1), maxy = std::min(100, circle.loc.second + 1);
			for (int i = minx; i <= maxx; i++) {
				for (int j = miny; j <= maxy; j++) {
					for (auto k : grid[i][j]) {
						std::cout << grid[i][j].size() << '\n';
						count++;
						if (id == k)continue;
						CircleCollider otherCircle = m_CircleColliders[k];
						pe::Vector2f collisionNormal;
						if (circle.Collide(otherCircle, &collisionNormal))
						{
							circle.velocity = collisionNormal * circle.velocity.Length() * 1;
							otherCircle.velocity = collisionNormal * otherCircle.velocity.Length() * -1;
							//pe::Vector2f temp = circle.velocity;
							//circle.velocity = otherCircle.velocity;
							//otherCircle.velocity = res;
							//std::cout << circle.second.velocity.Length() << "circle and circle"<< std::endl;
						}
					}
				}
			}



			//for (auto& [otherId, otherCircle] : m_CircleColliders)
			//{
			//	if (id == otherId)
			//		continue;
			//	pe::Vector2f collisionNormal;
			//	if (circle.Collide(otherCircle, &collisionNormal))
			//	{
			//		//std::cout << circle.second.velocity.Length() << ", ";
			//		circle.velocity = collisionNormal*circle.velocity.Length()*1;
			//		otherCircle.velocity = collisionNormal * otherCircle.velocity.Length() * -1;
			//		//pe::Vector2f temp = circle.velocity;
			//		//circle.velocity = otherCircle.velocity;
			//		//otherCircle.velocity = res;
			//		//std::cout << circle.second.velocity.Length() << "circle and circle"<< std::endl;
			//	}
			//}


		}

		//std::cout << count << '\n';
	}

	void PhysicsEngine::UpdateQuadtree(float deltaTime)
	{
		int count = 0;
		std::vector<Node> nodes = m_Quadtree.GenerateNodes(m_CircleColliders);

		for (const auto& node : nodes)
		{
			for (uint32_t id1 : node.colliderIds)
			{
				if (m_CircleColliders[id1].position.y - m_CircleColliders[id1].radius < bottom || m_CircleColliders[id1].position.y + m_CircleColliders[id1].radius > top)
				{
					m_CircleColliders[id1].position.y = (m_CircleColliders[id1].position.y - m_CircleColliders[id1].radius < bottom) ? bottom + m_CircleColliders[id1].radius : top - m_CircleColliders[id1].radius;
					m_CircleColliders[id1].velocity.y *= -1;
				}
				if (m_CircleColliders[id1].position.x - m_CircleColliders[id1].radius < left || m_CircleColliders[id1].position.x + m_CircleColliders[id1].radius > right)
				{
					m_CircleColliders[id1].position.x = (m_CircleColliders[id1].position.x - m_CircleColliders[id1].radius < left) ? left + m_CircleColliders[id1].radius : right - m_CircleColliders[id1].radius;
					m_CircleColliders[id1].velocity.x *= -1;
				}

				m_CircleColliders[id1].velocity += m_Gravity * deltaTime;
				m_CircleColliders[id1].position += m_CircleColliders[id1].velocity * deltaTime;

				for (uint32_t id2 : node.colliderIds)
				{
					if (id1 == id2)
						continue;
					count++;

					pe::Vector2f collisionNormal;
					if (m_CircleColliders[id1].Collide(m_CircleColliders[id2], &collisionNormal))
					{
						//std::cout << circle.second.velocity.Length() << ", ";
						m_CircleColliders[id1].velocity = collisionNormal * m_CircleColliders[id1].velocity.Length() * 1;
						m_CircleColliders[id2].velocity = collisionNormal * m_CircleColliders[id2].velocity.Length() * -1;
						//pe::Vector2f temp = circle.velocity;
						//circle.velocity = otherCircle.velocity;
						//otherCircle.velocity = res;
						//std::cout << circle.second.velocity.Length() << "circle and circle"<< std::endl;
					}
				}
			}
		}
		std::cout << count << '\n';
	}
}