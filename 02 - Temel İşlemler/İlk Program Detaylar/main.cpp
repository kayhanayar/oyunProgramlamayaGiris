//SFML k�t�phanesi ile �izim yapabilmek i�in Graphics.hpp k�t�phanesi ekleniyor
#include <SFML/Graphics.hpp>

int main()
{
	//Pencere olu�turmak i�in 1 adet RenderWindow nesnesi olu�turuluyor
	//kurucu fonksiyonun ilk parametresi olu�turulacak pencerenin geni�lik ve y�ksekli�idir
	//ikinci parametre pencerenin ba�l��� olacakt�r.
	sf::RenderWindow window(sf::VideoMode(200, 200), "ilk SFML Programi!");

	//�izim nesnesi olu�turuluyor. Bir adet daire olu�turuldu.
	//�ap� 100 birim olacakt�r
	sf::CircleShape shape(100.f);
	//dairenin dolgu rengi belirtiliyor.
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		//Kodlar
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
