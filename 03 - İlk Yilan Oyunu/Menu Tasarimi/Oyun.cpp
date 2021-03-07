#include "Oyun.hpp"
#include<iostream>

Oyun::Oyun()
{

	m_cerceveSuresi = 1.0f / 60.0f;
	menuAyarla();
}

Oyun::~Oyun()
{
}

void Oyun::btnYeniOyunTikla()
{
}

void Oyun::btnCikisTikla()
{
}

void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));

}

void Oyun::sahneGuncelle()
{
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		
		m_gecenSure -= sf::seconds(m_cerceveSuresi);
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	menuCiz();
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

void Oyun::menuAyarla()
{
	auto fonk = std::bind(&Oyun::btnYeniOyunTikla, this);
	m_btnYeniOyun.tiklaFonksiyonuEkle(fonk);
	fonk = std::bind(&Oyun::btnCikisTikla, this);
	m_btnCikis.tiklaFonksiyonuEkle(fonk);

	if (m_font.loadFromFile("alev.ttf") != false)
	{
		m_btnCikis.font(m_font);
		m_btnYeniOyun.font(m_font);
	}
	m_btnYeniOyun.renk(sf::Color::Red);
	m_btnCikis.renk(sf::Color::Red);
	
	m_btnYeniOyun.yazi("Yeni Oyun");
	m_btnCikis.yazi(L"Çýkýþ");

	auto sahneBoyut = m_pencere.pencereGetir().getSize();
	auto btnBoyut = m_btnYeniOyun.boyutGetir();

	float x = (sahneBoyut.x - btnBoyut.x) / 2.0f;
	float y = (sahneBoyut.y - btnBoyut.y) / 2.0f;
	m_btnYeniOyun.konum(x, y);
	m_btnCikis.boyut(btnBoyut.x, btnBoyut.y);

	m_btnCikis.konum(x, y+50);

	m_pencere.aracEkle(&m_btnYeniOyun);
	m_pencere.aracEkle(&m_btnCikis);
}

void Oyun::menuCiz()
{
	m_btnCikis.ciz(m_pencere.pencereGetir());
	m_btnYeniOyun.ciz(m_pencere.pencereGetir());
}
