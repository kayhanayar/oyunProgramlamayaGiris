#pragma once

#include<SFML/Graphics.hpp>
#include "PencereAraci.hpp"
class Buton:public PencereAraci
{
public:
	Buton();
	void yazi(sf::String yeniYazi);
	void renk(sf::Color renk);
	void font(sf::Font& yeniFont);
	void ciz(sf::RenderWindow& pencere);
	void boyut(float genislik, float yukseklik);
	void konum(float x, float y);

	sf::Vector2f boyutGetir();
private:
	sf::RectangleShape	m_arkaPlan;
	sf::Text			m_yazi;
	sf::Vector2f		m_konum;
	sf::Vector2f		m_boyut;

	virtual void fareHareket(int x, int y) override;
	virtual void fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi) override;
	virtual void fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi) override;
	virtual bool icerdemi(int x, int y) override;


};
