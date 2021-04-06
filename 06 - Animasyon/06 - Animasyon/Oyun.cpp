#include "Oyun.hpp"
#include<iostream>
#include "Karakter.hpp"

Karakter k;
float x = 0;
sf::Texture kaplama;
Oyun::Oyun()
{
	m_alinanMesafe = 0.0f;

	m_kapalimi = false;
	m_yeniOyunTiklandimi = false;
	m_cerceveSayisi = 0;
	m_cerceveSuresi = 1.0f / 60.0f;
	menuAyarla();
	m_hucreBoyutu = 20.0f;
	auto boyut = m_pencere.pencereGetir().getSize();
	m_sahne.olustur(boyut.x, boyut.y);


	k.olustur("./resimler/hero.png");



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
int sayi = 0;
void Oyun::girisKontrol()
{
	k.sabit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		k.sagaZipla();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		k.solaZipla();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		k.sagYukariBakarakYuru();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		k.solYukariBakarakYuru();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		k.sagaYuru();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		k.solaYuru();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		k.cok();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		k.yukariBak();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		k.zipla();

}

void Oyun::sahneGuncelle()
{
	m_pencere.olayKontrol();
	if (!m_yeniOyunTiklandimi)
	{
		return;
	}

	if (m_gecenSure.asSeconds() >= m_cerceveSuresi)
	{

		girisKontrol();

		m_gecenSure -= sf::seconds(m_cerceveSuresi);
		if (m_cerceveSayisi >= 5)
		{
			k.animasyonGuncelle();

			m_cerceveSayisi = 0;
		}
		k.konumGuncelle();
		sayi = 0;
		x += 2;
		m_cerceveSayisi++;
	}
}

void Oyun::sahneCiz()
{
	m_pencere.cizimeBasla();
	if (m_yeniOyunTiklandimi)
	{
		m_sahne.ciz(m_pencere.pencereGetir());
		k.ciz(m_pencere.pencereGetir());
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

	m_btnCikis.konum(x, y + 50);

	m_pencere.aracEkle(&m_btnYeniOyun);
	m_pencere.aracEkle(&m_btnCikis);
}

void Oyun::menuCiz()
{
	m_btnCikis.ciz(m_pencere.pencereGetir());
	m_btnYeniOyun.ciz(m_pencere.pencereGetir());
}
