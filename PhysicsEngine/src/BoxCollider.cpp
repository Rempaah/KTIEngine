#include "BoxCollider.h"

namespace pe {

	BoxCollider::BoxCollider()
		: position(), size()
	{}

	BoxCollider::BoxCollider(const Vector2f& position, const Vector2f& size)
		: position(position), size(size)
	{}

	BoxCollider::~BoxCollider()
	{}

}