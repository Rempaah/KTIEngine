#include "Quadtree.h"

namespace pe {

	Quadtree::Quadtree(float left, float right, float top, float bottom, int maxDepth)
		: m_Left(left), m_Right(right), m_Top(top), m_Bottom(bottom), m_MaxDepth(maxDepth)
	{}

	Quadtree::~Quadtree()
	{}

	std::vector<Node> Quadtree::GenerateNodes(std::unordered_map<uint32_t, CircleCollider>& colliders)
	{
		m_Nodes.clear();

		Node root;
		root.left = m_Left;
		root.right = m_Right;
		root.top = m_Top;
		root.bottom = m_Bottom;
		for (const auto& [id, collider] : colliders)
		{
			root.colliderIds.push_back(id);
		}
		m_Nodes.push_back(root);

		for (int i = 0; i < m_Nodes.size(); i++)
		{
			if (m_Nodes[i].colliderIds.size() > static_cast<size_t>(m_MaxObject) && m_Nodes[i].depth < m_MaxDepth)
			{
				// Subdivide the node

				Node topLeft, topRight, bottomLeft, bottomRight;

				topLeft.left = m_Nodes[i].left;
				topLeft.right = (m_Nodes[i].right + m_Nodes[i].left) / 2.0f;
				topLeft.top = m_Nodes[i].top;
				topLeft.bottom = (m_Nodes[i].top + m_Nodes[i].bottom) / 2.0f;
				topLeft.depth = m_Nodes[i].depth + 1;

				topRight.left = (m_Nodes[i].right + m_Nodes[i].left) / 2.0f;
				topRight.right = m_Nodes[i].right;
				topRight.top = m_Nodes[i].top;
				topRight.bottom = (m_Nodes[i].top + m_Nodes[i].bottom) / 2.0f;
				topRight.depth = m_Nodes[i].depth + 1;

				bottomLeft.left = m_Nodes[i].left;
				bottomLeft.right = (m_Nodes[i].right + m_Nodes[i].left) / 2.0f;
				bottomLeft.top = (m_Nodes[i].top + m_Nodes[i].bottom) / 2.0f;
				bottomLeft.bottom = m_Nodes[i].bottom;
				bottomLeft.depth = m_Nodes[i].depth + 1;

				bottomRight.left = (m_Nodes[i].right + m_Nodes[i].left) / 2.0f;
				bottomRight.right = m_Nodes[i].right;
				bottomRight.top = (m_Nodes[i].top + m_Nodes[i].bottom) / 2.0f;
				bottomRight.bottom = m_Nodes[i].bottom;
				bottomRight.depth = m_Nodes[i].depth + 1;

				for (const auto& id : m_Nodes[i].colliderIds)
				{
					Vector2f colliderPos = colliders[id].position;
					if ((colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(topLeft.left), static_cast<float>(topLeft.right))) *
						(colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(topLeft.left), static_cast<float>(topLeft.right))) +
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(topLeft.bottom), static_cast<float>(topLeft.top))) *
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(topLeft.bottom), static_cast<float>(topLeft.top))) < colliders[id].radius * colliders[id].radius)
						topLeft.colliderIds.push_back(id);

					if ((colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(topRight.left), static_cast<float>(topRight.right))) *
						(colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(topRight.left), static_cast<float>(topRight.right))) +
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(topRight.bottom), static_cast<float>(topRight.top))) *
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(topRight.bottom), static_cast<float>(topRight.top))) < colliders[id].radius * colliders[id].radius)
						topRight.colliderIds.push_back(id);

					if ((colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(bottomLeft.left), static_cast<float>(bottomLeft.right))) *
						(colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(bottomLeft.left), static_cast<float>(bottomLeft.right))) +
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(bottomLeft.bottom), static_cast<float>(bottomLeft.top))) *
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(bottomLeft.bottom), static_cast<float>(bottomLeft.top))) < colliders[id].radius * colliders[id].radius)
						bottomLeft.colliderIds.push_back(id);

					if ((colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(bottomRight.left), static_cast<float>(bottomRight.right))) *
						(colliderPos.x - std::clamp(colliderPos.x, static_cast<float>(bottomRight.left), static_cast<float>(bottomRight.right))) +
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(bottomRight.bottom), static_cast<float>(bottomRight.top))) *
						(colliderPos.y - std::clamp(colliderPos.y, static_cast<float>(bottomRight.bottom), static_cast<float>(bottomRight.top))) < colliders[id].radius * colliders[id].radius)
						bottomRight.colliderIds.push_back(id);
				}

				m_Nodes[i] = topLeft;
				m_Nodes.push_back(topRight);
				m_Nodes.push_back(bottomLeft);
				m_Nodes.push_back(bottomRight);
			}
		}

		return m_Nodes;
	}

}