#pragma once

#include <unordered_map>
#include <vector>
#include <CircleCollider.h>

namespace pe {

	struct Node
	{
		int left, right, top, bottom;
		int depth = 0;
		std::vector<uint32_t> colliderIds;
	};

	class Quadtree
	{
	public:
		Quadtree(float left, float right, float top, float bottom, int maxDepth = 9);
		~Quadtree();

		std::vector<Node> GenerateNodes(std::unordered_map<uint32_t, CircleCollider>& colliders);
	private:

		float m_Left;
		float m_Right;
		float m_Top;
		float m_Bottom;

		int m_MaxDepth;
		int m_MaxObject = 5;

		std::vector<Node> m_Nodes;
	};

}