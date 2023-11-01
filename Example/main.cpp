#include <iostream>

#include <SFML/Graphics.hpp>

#include <PhysicsEngine.h>
#include "Circle.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 5;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Example", sf::Style::Default, settings);
	sf::Event event;

	Circle circle1({ 100.0f, 100.0f }, 100.0f);
	Circle circle2({ 280.0f, 100.0f }, 100.0f);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		pe::PhysicsEngine::Update(2);

		window.clear();
		window.draw(circle1);
		window.draw(circle2);
		window.display();
	}
}