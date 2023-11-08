#include "Box.h"

#include "PhysicsEngine.h"

Box::Box()
	: m_Box()
{
	m_BoxCollider = pe::PhysicsEngine::CreateBoxCollider();

	m_Box.setPosition(0, 0);
	m_Box.setOutlineColor(sf::Color::Yellow);
	m_Box.setOutlineThickness(-5);
	m_Box.setFillColor(sf::Color::Transparent);

	m_Box.setOrigin(0, 0);
}

Box::Box(const pe::Vector2f& position, const pe::Vector2f& size)
	: m_Box()
{
	m_BoxCollider = pe::PhysicsEngine::CreateBoxCollider(position, size);

	m_Box.setPosition(position.x, position.y);
	m_Box.setSize({ size.x, size.y });
	m_Box.setOutlineColor(sf::Color::Yellow);
	m_Box.setOutlineThickness(-5);
	m_Box.setFillColor(sf::Color::Transparent);

	m_Box.setOrigin(size.x / 2, size.y / 2);
}

Box::~Box()
{}

void Box::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Box, states);
}

// Setters

void Box::SetPosition(const pe::Vector2f& position)
{
	m_Box.setPosition(position.x, position.y);
	pe::PhysicsEngine::GetBoxCollider(m_BoxCollider).position = position;
}

void Box::SetSize(const pe::Vector2f& size)
{
	m_Box.setSize({ size.x, size.y });
	pe::PhysicsEngine::GetBoxCollider(m_BoxCollider).size = size;

	m_Box.setOrigin(size.x / 2, size.y / 2);
}

// Getters

pe::Vector2f Box::GetPosition() const
{
	return pe::PhysicsEngine::GetBoxCollider(m_BoxCollider).position;
}

pe::Vector2f Box::GetSize() const
{
	return pe::PhysicsEngine::GetBoxCollider(m_BoxCollider).size;
}