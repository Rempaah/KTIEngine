#include "Circle.h"

Circle::Circle()
	: m_Circle(0), m_CircleCollider()
{
	m_Circle.setPosition(m_CircleCollider.position.x, m_CircleCollider.position.y);
	m_Circle.setOutlineColor(sf::Color::Green);
	m_Circle.setOutlineThickness(5);
	m_Circle.setFillColor(sf::Color::Transparent);

	m_Circle.setOrigin(0, 0);
}

Circle::Circle(const pe::Vector2f& position, float radius)
	: m_Circle(radius), m_CircleCollider(position, radius)
{
	m_Circle.setPosition(m_CircleCollider.position.x, m_CircleCollider.position.y);
	m_Circle.setOutlineColor(sf::Color::Green);
	m_Circle.setOutlineThickness(5);
	m_Circle.setFillColor(sf::Color::Transparent);

	m_Circle.setOrigin(radius, radius);
}

Circle::~Circle()
{}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Circle, states);
}

// Setters

void Circle::SetPosition(const pe::Vector2f& position)
{
	m_Circle.setPosition(position.x, position.y);
	m_CircleCollider.position.x = position.x;
	m_CircleCollider.position.y = position.y;
}

void Circle::SetRadius(float radius)
{
	m_Circle.setRadius(radius);
	m_CircleCollider.radius = radius;

	m_Circle.setOrigin(radius, radius);
}

// Getters

pe::Vector2f Circle::GetPosition()
{
	return m_CircleCollider.position;
}

float Circle::GetRadius()
{
	return m_CircleCollider.radius;
}