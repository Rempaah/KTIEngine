#pragma once

#include <vector>
#include <CircleCollider.h>

namespace pe {

	struct Node
	{
		std::vector<uint32_t> colliderIds;
	};

	class Quadtree
	{
	public:
		Quadtree(float left, float right, float top, float bottom, int depthLimit);
		~Quadtree();

		std::vector<Node> GetNodes();
	private:
		float m_Left;
		float m_Right;
		float m_Top;
		float m_Bottom;
		int m_DepthLimit;
	};

}