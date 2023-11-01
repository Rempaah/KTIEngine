#pragma once

#include <tuple>

#include <SFML/Graphics.hpp>

#include <CircleCollider.h>

class Circle : public sf::Drawable
{
public:
	Circle();
	Circle(const pe::Vector2f& position, float radius);
	~Circle();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Setters
	void SetPosition(const pe::Vector2f& position);
	void SetRadius(float radius);

	// Getters
	pe::Vector2f GetPosition();
	float GetRadius();
private:
	uint32_t m_CircleCollider;
	sf::CircleShape m_Circle;
};