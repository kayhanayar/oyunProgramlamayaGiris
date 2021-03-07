#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ilk SFML Programi!");

	sf::CircleShape shape(30.f);
	sf::Clock saat;
	float x = 10;

	shape.setFillColor(sf::Color::Green);

	sf::Time gecenSure;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		shape.setPosition(x, 300);
		window.clear();
		window.draw(shape);
		window.display();

		
		float turSuresi = saat.restart().asSeconds();
		if (gecenSure.asMilliseconds() >= 200.0f)
		{
			gecenSure -= sf::milliseconds(200.0f);
			int fps = (1 / turSuresi);
			window.setTitle(std::to_string(fps));
		}
		gecenSure += sf::seconds(turSuresi);
		x += 100 * turSuresi;
	
	}

	return 0;
}
