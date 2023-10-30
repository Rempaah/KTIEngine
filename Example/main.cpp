#include <iostream>

#include <SFML/Graphics.hpp>

#include "Circle.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 5;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Example", sf::Style::Default, settings);
	sf::Event event;

	Circle circle(100.0f, 100.0f, 50.0f);

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

		window.clear();
		window.draw(circle);
		window.display();

		system("cls");

		auto [x, y] = circle.GetPosition();
		float radius = circle.GetRadius();

		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << radius << std::endl;
	}
}