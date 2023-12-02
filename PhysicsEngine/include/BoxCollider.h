#pragma once

#include "PMath.h"

namespace pe {

	class BoxCollider
	{
	public:
		BoxCollider();
		BoxCollider(const Vector2f& position, const Vector2f& size);
		~BoxCollider();

		Vector2f position;
		Vector2f size;
	private:
	};

}