//SFML kütüphanesi ile çizim yapabilmek için Graphics.hpp kütüphanesi ekleniyor
#include <SFML/Graphics.hpp>

int main()
{
	//Pencere oluþturmak için 1 adet RenderWindow nesnesi oluþturuluyor
	//kurucu fonksiyonun ilk parametresi oluþturulacak pencerenin geniþlik ve yüksekliðidir
	//ikinci parametre pencerenin baþlýðý olacaktýr.
	sf::RenderWindow window(sf::VideoMode(200, 200), "ilk SFML Programi!");

	//Çizim nesnesi oluþturuluyor. Bir adet daire oluþturuldu.
	//çapý 100 birim olacaktýr
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
