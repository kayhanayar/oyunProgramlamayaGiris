#include "Pencere.hpp"

Pencere::Pencere()
{
	ayarla(800, 600, "SFML");
}

void Pencere::ayarla(unsigned int genislik, 
	unsigned int yukseklik, sf::String baslik)
{
	m_window.create(sf::VideoMode(genislik, yukseklik), 
					baslik);
}
void Pencere::cizimeBasla()
{
	m_window.clear();
}
void Pencere::cizimiBitir()
{
	m_window.display();
}

bool Pencere::kapandimi()
{
	return !m_window.isOpen();
}

void Pencere::olayKontrol()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void Pencere::ciz(sf::Drawable& sekil)
{
	m_window.draw(sekil);
}
