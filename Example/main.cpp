#include <iostream>

#include <SFML/Graphics.hpp>
#include <CirlceCollider.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Example");
	sf::Event event;

	pe::CircleCollider collider;
	collider.x = 100.0f;
	collider.y = 100.0f;
	collider.radius = 60.0f;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			default:
				break;
			}
		}

		system("cls");

		std::cout << collider.x << std::endl;
		std::cout << collider.y << std::endl;
		std::cout << collider.radius << std::endl;
	}
}