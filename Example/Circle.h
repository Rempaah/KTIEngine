#pragma once

#include <tuple>

#include <SFML/Graphics.hpp>

#include <PhysicsEngine.h>
#include <CircleCollider.h>

class Circle : public sf::Drawable
{
public:
	Circle(pe::PhysicsEngine* physicsEngine);
	Circle(pe::PhysicsEngine* physicsEngine, const pe::Vector2f& position, float radius);
	~Circle();

	void Update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Setters
	void SetPosition(const pe::Vector2f& position);
	void SetRadius(float radius);

	// Getters
	pe::Vector2f GetPosition() const;
	float GetRadius() const;
private:
	uint32_t m_CircleCollider;
	sf::CircleShape m_Circle;

	pe::PhysicsEngine* m_PhysicsEngine;
};