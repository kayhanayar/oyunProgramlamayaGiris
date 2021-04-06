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
	if (!m_yeniOyunTiklandimi)
		return;
	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{
		if (!yilanIcerdemi())
		{
			m_kapalimi = true;
			return;
		}
		m_gecenSure = sf::seconds(0);
		if (m_alinanMesafe >= m_hucreBoyutu)
		{
			if (yilanYemUzerindemi())
			{
				m_yilan.kuyrugaEkle();
				m_sahne.yemOlustur();
			}
			if (m_yilan.kendiniYedimi())
			{
				m_kapalimi = true;
				return;
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

bool Oyun::yilanIcerdemi()
{
	auto yilanKonum = m_yilan.basKonumGetir();

	auto sahneBoyut = m_sahne.boyutGetir();


	if (yilanKonum.x < 0 ||
		yilanKonum.y < 0||
		yilanKonum.x+m_hucreBoyutu>sahneBoyut.x||
		yilanKonum.y+m_hucreBoyutu>sahneBoyut.y)
	{
		return false;
	}

	return true;
}

bool Oyun::yilanYemUzerindemi()
{
	auto yemKonum = m_sahne.yemKonumGetir();
	auto yilanKonum = m_yilan.basKonumGetir();

	if (yemKonum.x == yilanKonum.x && yemKonum.y == yilanKonum.y)
	{
		return true;
	}

	return false;
}
