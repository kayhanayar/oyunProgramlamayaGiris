#include "Oyun.hpp"
#include<iostream>

Oyun::Oyun()
{
	m_alinanMesafe = 0.0f;
	m_siradakiYon = YON::SAG;
	m_kapalimi = false;
	m_yeniOyunTiklandimi = false;

	m_cerceveSuresi = 1.0f / 60.0f;
	menuAyarla();
	m_hucreBoyutu = 20.0f;
	auto boyut = m_pencere.pencereGetir().getSize();
	m_sahne.olustur(boyut.x, boyut.y, m_hucreBoyutu);
}

Oyun::~Oyun()
{
}

void Oyun::btnYeniOyunTikla()
{
	m_yeniOyunTiklandimi = true;
}

void Oyun::btnCikisTikla()
{
	m_kapalimi = true;
}

void Oyun::girisKontrol()
{
	m_pencere.olayKontrol();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_siradakiYon = YON::SAG;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_siradakiYon = YON::SOL;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_siradakiYon = YON::YUKARI;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_siradakiYon = YON::ASAGI;
}

void Oyun::sahneGuncelle()
{
	
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		m_gecenSure -= sf::seconds(m_cerceveSuresi);
		if (m_alinanMesafe >= m_hucreBoyutu)
		{
			if (sahneIcindemi()==false||
				m_yilan.kendiniYedimi()==true)
			{
				m_kapalimi = true;
				return;
			}
			if (yemYendimi())
			{
				m_sahne.yemOlustur();
				m_yilan.kuyrugaEkle();
			}
			//Diðer kýsýmlarda deðiþim yok.
			m_yilan.yonleriAktar();
			m_yilan.yonDegistir(m_siradakiYon);
			m_alinanMesafe -= m_hucreBoyutu;
		}
		m_yilan.hareket(2);
		m_alinanMesafe += 2;
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	if (m_yeniOyunTiklandimi)
	{
		m_sahne.ciz(m_pencere.pencereGetir());
		m_yilan.ciz(m_pencere.pencereGetir());
	}
	else
	{
		menuCiz();
	}
	m_pencere.cizimiBitir();
}

void Oyun::saatiYenidenBaslat()
{
	m_gecenSure += m_saat.restart();
}

bool Oyun::bittimi()
{
	if (m_kapalimi)
		return true;
	return m_pencere.kapandimi();
}

bool Oyun::yemYendimi()
{
	auto basKonum = m_yilan.basKonumGetir();
	auto yemKonum = m_sahne.yemKonumGetir();

	if (basKonum.x == yemKonum.x && basKonum.y == yemKonum.y)
		return true;
	return false;
}

bool Oyun::sahneIcindemi()
{
	auto konum = m_yilan.basKonumGetir();
	auto boyut = m_sahne.boyutGetir();

	if (konum.x <= 0||
		konum.y<=0||
		konum.x+m_hucreBoyutu>=boyut.x||
		konum.y+m_hucreBoyutu>=boyut.y)
	{
		return false;
	}
	return true;
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
