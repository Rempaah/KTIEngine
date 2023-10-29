#include <iostream>

#include <SFML/Graphics.hpp>
#include <PhysicsEngine.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Example");

	sf::Event event;
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

		Engine engine;
		engine.hello();
	}
}