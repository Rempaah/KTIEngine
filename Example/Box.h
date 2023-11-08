#pragma once

#include <SFML/Graphics.hpp>

#include <BoxCollider.h>

class Box : public sf::Drawable
{
public:
	Box();
	Box(const pe::Vector2f& position, const pe::Vector2f& size);
	~Box();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Setter
	void SetPosition(const pe::Vector2f& position);
	void SetSize(const pe::Vector2f& size);

	// Getter
	pe::Vector2f GetPosition() const;
	pe::Vector2f GetSize() const;
private:
	uint32_t m_BoxCollider;
	sf::RectangleShape m_Box;
};