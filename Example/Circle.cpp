#include "Circle.h"

Circle::Circle()
	: m_Circle(0), m_CircleCollider()
{
	m_Circle.setPosition(m_CircleCollider.x, m_CircleCollider.y);
	m_Circle.setFillColor(sf::Color::Red);
}

Circle::Circle(float x, float y, float radius)
	: m_Circle(radius), m_CircleCollider(x, y, radius)
{
	m_Circle.setPosition(m_CircleCollider.x, m_CircleCollider.y);
	m_Circle.setFillColor(sf::Color::Red);
}

Circle::~Circle()
{}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Circle, states);
}

// Setters

void Circle::SetPosition(float x, float y)
{
	m_Circle.setPosition(x, y);
	m_CircleCollider.x = x;
	m_CircleCollider.y = y;
}

void Circle::SetRadius(float radius)
{
	m_Circle.setRadius(radius);
	m_CircleCollider.radius = radius;
}

// Getters

std::tuple<float, float> Circle::GetPosition()
{
	return { m_CircleCollider.x, m_CircleCollider.y };
}

float Circle::GetRadius()
{
	return m_CircleCollider.radius;
}