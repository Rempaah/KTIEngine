#include <cstdint>
#include <random>
#include <unordered_map>

#include <CircleCollider.h>

namespace pe {

	class PhysicsEngine
	{
	public:
		static uint32_t CreateCircleCollider();
		static uint32_t CreateCircleCollider(Vector2f position, float radius);
		static CircleCollider& GetCircleCollider(uint32_t id);

		static void Update(float deltaTime);
	private:
		static std::unordered_map<uint32_t, CircleCollider> m_CircleColliders;
		static std::mt19937 m_Distribution;
		static std::uniform_int_distribution<uint32_t> m_Random;
	};

}