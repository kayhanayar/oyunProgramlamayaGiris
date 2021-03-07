#pragma once

#include "Pencere.hpp"
#include "Buton.hpp"
class Oyun
{
public:
	Oyun();
	~Oyun();
	void btnYeniOyunTikla();
	void btnCikisTikla();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();
	void saatiYenidenBaslat();
	bool bittimi();

	void menuAyarla();
	void menuCiz();
private:
	Pencere			m_pencere;
	Buton			m_btnYeniOyun;
	Buton			m_btnCikis;
	sf::Font		m_font;
	sf::Clock		m_saat;
	sf::Time		m_gecenSure;
	float m_cerceveSuresi;
};