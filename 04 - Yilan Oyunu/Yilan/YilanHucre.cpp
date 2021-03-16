#include "YilanHucre.hpp"

YilanHucre::YilanHucre()
{
	yon(YON::SAG);
}

void YilanHucre::hareketEt(float boyut)
{
	switch (m_yon)
	{
	case YON::SAG:
		m_konum += sf::Vector2f(boyut, 0);
		break;
	case YON::SOL:
		m_konum -= sf::Vector2f(boyut, 0);
		break;
	case YON::ASAGI:
		m_konum += sf::Vector2f(0, boyut);
		break;
	case YON::YUKARI:
		m_konum -= sf::Vector2f(0, boyut);
		break;
	}
}

void YilanHucre::yon(YON yeniYon)
{
	m_yon = yeniYon;
}

void YilanHucre::konum(sf::Vector2f yeniKonum)
{
	m_konum = yeniKonum;
}

sf::Vector2f YilanHucre::konumGetir() const
{
	return m_konum;
}

YON YilanHucre::yonGetir()
{
	return m_yon;
}
