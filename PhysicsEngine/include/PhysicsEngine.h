#include <cstdint>
#include <random>
#include <unordered_map>

#include <CircleCollider.h>
#include <BoxCollider.h>

namespace pe {

	class PhysicsEngine
	{
	public:
		static Vector2f gravity;

		static uint32_t CreateCircleCollider();
		static uint32_t CreateBoxCollider();
		static uint32_t CreateCircleCollider(Vector2f position, float radius);
		static uint32_t CreateBoxCollider(Vector2f position, Vector2f size);
		static CircleCollider& GetCircleCollider(uint32_t id);
		static BoxCollider& GetBoxCollider(uint32_t id);

		static void Update(float deltaTime);
	private:
		static std::unordered_map<uint32_t, CircleCollider> m_CircleColliders;
		static std::unordered_map<uint32_t, BoxCollider> m_BoxColliders;
		static std::mt19937 m_Distribution;
		static std::uniform_int_distribution<uint32_t> m_Random;
	};

}