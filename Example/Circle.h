#pragma once

#include <tuple>

#include <SFML/Graphics.hpp>

#include <CircleCollider.h>

class Circle : public sf::Drawable
{
public:
	Circle();
	Circle(float x, float y, float radius);
	~Circle();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Setters
	void SetPosition(float x, float y);
	void SetRadius(float radius);

	// Getters
	std::tuple<float, float> GetPosition();
	float GetRadius();
private:
	sf::CircleShape m_Circle;
	pe::CircleCollider m_CircleCollider;
};