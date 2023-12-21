#include <iostream>
#include <chrono>

#include <SFML/Graphics.hpp>

#include <PhysicsEngine.h>
#include "Circle.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 5;
	sf::RenderWindow window(sf::VideoMode(1280, 1280), "Example", sf::Style::Default, settings);
	sf::Event event;

	pe::PhysicsEngine physicsEngine;

	Circle circle1(&physicsEngine, { 480.0f, 300.0f }, 100.0f);
	Circle circle2(&physicsEngine, { 900.0f, 300.0f }, 100.0f);

	std::chrono::steady_clock::time_point previousTime = std::chrono::steady_clock::now();
	std::chrono::microseconds frameTime(8333);
	std::chrono::microseconds deltaTime(0);
	std::chrono::microseconds lag(0);

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

		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previousTime);
		lag += deltaTime;
		previousTime += deltaTime;

		while (lag >= frameTime)
		{
			lag -= frameTime;

			physicsEngine.Update(frameTime.count()/1000000.0f);
			circle1.Update();
			circle2.Update();

			if (lag < frameTime)
			{
				window.clear(sf::Color(0, 0, 0, 255));
				window.draw(circle1);
				window.draw(circle2);
				window.display();
			}
		}
	}
}