#pragma once

#include "Pencere.hpp"

class Oyun
{
public:
	Oyun();
	~Oyun();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();

	void saatiYenidenBaslat();
	bool bittimi();
	
private:
	Pencere			m_pencere;
	sf::Clock		m_saat;
	sf::Time		m_gecenSure;
	sf::CircleShape	m_sekil;
	float m_artis;
	float m_konumX;
	float m_cerceveSuresi;
};