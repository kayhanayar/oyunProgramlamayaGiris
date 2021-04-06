#include "Pencere.hpp"
#include<iostream>
#include "PencereAraci.hpp"
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
void Pencere::aracEkle(PencereAraci* arac)
{
	m_pencereAraclari.push_back(arac);
}
void Pencere::olayKontrol()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		if (event.type == sf::Event::MouseMoved)
		{
			int x = event.mouseMove.x;
			int y = event.mouseMove.y;
			for (auto siradaki : m_pencereAraclari)
			{
				if (siradaki->icerdemi(x, y))
				{
					siradaki->fareHareket(x, y);
				}
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			for (auto siradaki : m_pencereAraclari)
			{
				if (siradaki->icerdemi(x, y))
				{
					siradaki->fareButonBasildi(event.mouseButton);
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			for (auto siradaki : m_pencereAraclari)
			{
				if (siradaki->icerdemi(x, y))
				{
					siradaki->fareButonBirakildi(event.mouseButton);
				}
			}
		}
		
	}
}

void Pencere::ciz(sf::Drawable& sekil)
{
	m_window.draw(sekil);
}

sf::RenderWindow& Pencere::pencereGetir()
{
	return m_window;
}
