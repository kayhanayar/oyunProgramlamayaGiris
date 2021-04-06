#include "Buton.hpp"
#include<iostream>
Buton::Buton()
{
	if (!m_texArkaPlan.loadFromFile("buton.png"))
	{
		std::cout << "buton.png acilmadi" << std::endl;
	}
	else
	{
		m_resArkaPlan.setTexture(m_texArkaPlan);
		m_resBasili.setTexture(m_texArkaPlan);
		m_resUzerinde.setTexture(m_texArkaPlan);
		
	}
	m_aktifRes = &m_resArkaPlan;

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
	
	
	pencere.draw(*m_aktifRes);
	pencere.draw(m_yazi);
}
void Buton::boyut(float genislik, float yukseklik)
{
	if (m_yazi.getLocalBounds().width < genislik)
	{
		m_boyut = sf::Vector2f(genislik, yukseklik);
		m_arkaPlan.setSize(m_boyut);

	}
	kaplamaAyarla();
}
void Buton::konum(float x, float y)
{
	m_konum = sf::Vector2f(x, y);

	auto yaziBoyut = m_yazi.getLocalBounds();
	
	float farkx = (m_boyut.x - yaziBoyut.width) / 2.0f;
	
	float yazix = abs(yaziBoyut.left);

	m_yazi.setPosition(x + yazix + farkx, y);

	m_arkaPlan.setPosition(m_konum);
	m_resArkaPlan.setPosition(m_konum);
	m_resBasili.setPosition(m_konum);
	m_resUzerinde.setPosition(m_konum);
}

sf::Vector2f Buton::boyutGetir()
{
	return m_boyut;
}

void Buton::fareHareket(int x, int y)
{
	if(m_durum!=ButonDurum::Basili)
		m_aktifRes = &m_resUzerinde;
}

void Buton::fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi)
{
	
	m_aktifRes = &m_resBasili;
	m_durum = ButonDurum::Basili;
}

void Buton::fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi)
{
	if(m_durum==ButonDurum::Basili)
		PencereAraci::fareButonBasildi(butonOlayi);
	m_durum = ButonDurum::Uzerinde;
	m_aktifRes = &m_resUzerinde;
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
	m_aktifRes = &m_resArkaPlan;
	return false;
}

void Buton::kaplamaAyarla()
{
	auto texBoyut = m_texArkaPlan.getSize();
	float sx = m_boyut.x / texBoyut.x;
	float sy = m_boyut.y / (texBoyut.y/3);
	m_resArkaPlan.setTextureRect(sf::IntRect(0, 0, texBoyut.x, texBoyut.y / 3));
	m_resArkaPlan.setScale(sx, sy);

	m_resBasili.setTextureRect(sf::IntRect(0, texBoyut.y / 3, texBoyut.x, texBoyut.y / 3));
	m_resBasili.setScale(sx, sy);
	m_resUzerinde.setTextureRect(sf::IntRect(0, 2*texBoyut.y / 3, texBoyut.x, texBoyut.y / 3));
	m_resUzerinde.setScale(sx, sy);
}
