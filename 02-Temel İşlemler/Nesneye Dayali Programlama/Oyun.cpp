#include "Oyun.hpp"

Oyun::Oyun()
{
	m_sekil.setRadius(30);
	m_sekil.setFillColor(sf::Color::Green);
	m_artis = 1.0f;
	m_konumX = 10.0f;
	m_cerceveSuresi = 1.0f / 60.0f;
}

Oyun::~Oyun()
{
}

void Oyun::girisKontrol()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_artis = 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_artis = -1.0f;

}

void Oyun::sahneGuncelle()
{
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		m_konumX += m_artis;
		m_sekil.setPosition(m_konumX, 300);
		m_gecenSure -= sf::seconds(m_cerceveSuresi);
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	m_pencere.ciz(m_sekil);
	m_pencere.cizimiBitir();
}

void Oyun::saatiYenidenBaslat()
{
	m_gecenSure += m_saat.restart();
}

bool Oyun::bittimi()
{
	return m_pencere.kapandimi();
}
