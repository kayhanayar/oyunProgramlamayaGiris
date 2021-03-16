#include "Buton.hpp"
#include<iostream>
Buton::Buton()
{
}
void Buton::yazi(sf::String yeniYazi)
{
	m_yazi.setString(yeniYazi);
	
	auto yaziBoyut = m_yazi.getLocalBounds();

	float x = abs(yaziBoyut.left);

	float y = yaziBoyut.top;

	float genislik = yaziBoyut.width + x*2+ 20;

	float yukseklik = yaziBoyut.height + y *2;
	
	boyut(genislik, yukseklik);
	
	m_yazi.setPosition(m_arkaPlan.getPosition().x+ x + 10,0);
}
void Buton::renk(sf::Color renk)
{
	m_arkaPlan.setFillColor(renk);
}
void Buton::font(sf::Font& yeniFont)
{
	m_yazi.setFont(yeniFont);
}
void Buton::ciz(sf::RenderWindow& pencere)
{
	pencere.draw(m_arkaPlan);
	pencere.draw(m_yazi);
}
void Buton::boyut(float genislik, float yukseklik)
{
	if (m_yazi.getLocalBounds().width < genislik)
	{
		m_boyut = sf::Vector2f(genislik, yukseklik);
		m_arkaPlan.setSize(m_boyut);
	}
}
void Buton::konum(float x, float y)
{
	m_konum = sf::Vector2f(x, y);

	auto yaziBoyut = m_yazi.getLocalBounds();
	
	float farkx = (m_boyut.x - yaziBoyut.width) / 2.0f;
	
	float yazix = abs(yaziBoyut.left);

	m_yazi.setPosition(x + yazix + farkx, y);

	m_arkaPlan.setPosition(m_konum);
}

sf::Vector2f Buton::boyutGetir()
{
	return m_boyut;
}

void Buton::fareHareket(int x, int y)
{
	
	m_arkaPlan.setFillColor(sf::Color::Green);
}

void Buton::fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi)
{
	PencereAraci::fareButonBasildi(butonOlayi);
}

void Buton::fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi)
{
	std::cout << "eee";
}


bool Buton::icerdemi(int x, int y)
{
	auto konum = m_arkaPlan.getPosition();
	auto boyut = m_arkaPlan.getSize();

	if (konum.x <= x &&
		konum.x + boyut.x >= x &&
		konum.y <= y &&
		konum.y + boyut.y >= y)
	{
		return true;
	}
	m_arkaPlan.setFillColor(sf::Color::Red);
	return false;
}
