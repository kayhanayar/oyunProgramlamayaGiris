#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ilk SFML Programi!");

	sf::CircleShape shape(30.f);
	sf::RectangleShape dortgen({ 50,30 });
	float x = 10;

	shape.setFillColor(sf::Color::Green);
	dortgen.setFillColor(sf::Color::Red);
	dortgen.setOutlineThickness(10.0f);
	dortgen.setOutlineColor(sf::Color(250, 150, 100));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		shape.setPosition(x, 300);
		dortgen.setPosition(300, x);
		window.clear();
		window.draw(shape);
		window.draw(dortgen);
		window.display();

		x += 0.1;
	}

	return 0;
}
