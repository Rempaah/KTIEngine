#include "Quadtree.h"

namespace pe {

	Quadtree::Quadtree(float left, float right, float top, float bottom, int depthLimit)
		: m_Left(left), m_Right(right), m_Top(top), m_Bottom(bottom), m_DepthLimit(depthLimit)
	{}

	Quadtree::~Quadtree()
	{}

}