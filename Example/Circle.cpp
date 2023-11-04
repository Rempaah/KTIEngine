#include "Circle.h"

#include <PhysicsEngine.h>

Circle::Circle()
	: m_Circle(0)
{
	m_CircleCollider = pe::PhysicsEngine::CreateCircleCollider({ 0, 0 }, 0);

	m_Circle.setPosition(0, 0);
	m_Circle.setOutlineColor(sf::Color::Green);
	m_Circle.setOutlineThickness(-5);
	m_Circle.setFillColor(sf::Color::Transparent);

	m_Circle.setOrigin(0, 0);
}

Circle::Circle(const pe::Vector2f& position, float radius)
	: m_Circle(radius)
{
	m_CircleCollider = pe::PhysicsEngine::CreateCircleCollider(position, radius);

	m_Circle.setPosition(position.x, position.y);
	m_Circle.setOutlineColor(sf::Color::Green);
	m_Circle.setOutlineThickness(-5);
	m_Circle.setFillColor(sf::Color::Transparent);

	m_Circle.setOrigin(radius, radius);
}

Circle::~Circle()
{}

void Circle::Update()
{
	pe::Vector2f newPos = GetPosition();
	m_Circle.setPosition(newPos.x, newPos.y);
}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Circle, states);
}

// Setters

void Circle::SetPosition(const pe::Vector2f& position)
{
	m_Circle.setPosition(position.x, position.y);
	pe::PhysicsEngine::GetCircleCollider(m_CircleCollider).position = position;
}

void Circle::SetRadius(float radius)
{
	m_Circle.setRadius(radius);
	pe::PhysicsEngine::GetCircleCollider(m_CircleCollider).radius = radius;

	m_Circle.setOrigin(radius, radius);
}

// Getters

pe::Vector2f Circle::GetPosition()
{
	return pe::PhysicsEngine::GetCircleCollider(m_CircleCollider).position;
}

float Circle::GetRadius()
{
	return pe::PhysicsEngine::GetCircleCollider(m_CircleCollider).radius;
}