#include <iostream>
#include <chrono>

#include <SFML/Graphics.hpp>

#include <PhysicsEngine.h>
#include "Circle.h"

#include "Timer.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 5;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Example", sf::Style::Default, settings);
	sf::Event event;

	pe::PhysicsEngine physicsEngine(0, 1000, 0, 1000);

	std::vector<Circle> something;
	int n;
	std::cin >> n;
	while (n--) {
		float a, b, c;
		std::cin >> a >> b >> c;
		Circle temp(&physicsEngine, { a, b}, c);
		temp.m_Circle.setOutlineColor(sf::Color(a / 1000.0f * 2555, b / 1000.0f * 2555, 255));
		something.push_back(temp);
	}

	physicsEngine.Start();
	

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

		physicsEngine.UpdateQuadtree(frameTime.count()/1000000.0f);
		for (auto& i : something) {
			i.Update();
		}

		window.clear(sf::Color(0, 0, 0, 255));
		for (auto& i : something) {
			window.draw(i);
		}
		window.display();
	}
}