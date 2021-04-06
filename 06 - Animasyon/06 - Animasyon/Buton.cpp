#include "Buton.hpp"
#include<iostream>
Buton::Buton()
{
	m_butonDurumu = ButonDurum::Normal;

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

	this->resimleriYukle("buton.png");
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
	//pencere.draw(m_arkaPlan);
	switch (m_butonDurumu)
	{
	case ButonDurum::Normal:
		pencere.draw(m_resNormal);
		break;
	case ButonDurum::Basili:
		pencere.draw(m_resBasili);
		break;
	case ButonDurum::Uzerinde:
		pencere.draw(m_resUzerinde);
		break;
	}
	pencere.draw(m_yazi);
	
}
void Buton::boyut(float genislik, float yukseklik)
{
	if (m_yazi.getLocalBounds().width < genislik)
	{
		m_boyut = sf::Vector2f(genislik, yukseklik);
		m_arkaPlan.setSize(m_boyut);
		resimAyarla();

	}
}
void Buton::konum(float x, float y)
{
	m_konum = sf::Vector2f(x, y);

	auto yaziBoyut = m_yazi.getLocalBounds();
	
	float farkx = (m_boyut.x - yaziBoyut.width) / 2.0f;
	
	float yazix = abs(yaziBoyut.left);

	m_yazi.setPosition(x + yazix + farkx, y);

	m_arkaPlan.setPosition(m_konum);
	m_resNormal.setPosition(m_konum);
	m_resBasili.setPosition(m_konum);
	m_resUzerinde.setPosition(m_konum);
}

sf::Vector2f Buton::boyutGetir()
{
	return m_boyut;
}

void Buton::resimleriYukle(sf::String dosyaIsmi)
{
	if (!m_texArkaPlan.loadFromFile(dosyaIsmi));
	{

	}
	m_resNormal.setTexture(m_texArkaPlan);
	m_resBasili.setTexture(m_texArkaPlan);
	m_resUzerinde.setTexture(m_texArkaPlan);
	auto texBoyut = m_texArkaPlan.getSize();
	m_resNormal.setTextureRect(sf::IntRect(0, 0, texBoyut.x, texBoyut.y / 3));
	m_resUzerinde.setTextureRect(sf::IntRect(0, texBoyut.y / 3, texBoyut.x, texBoyut.y / 3));
	m_resBasili.setTextureRect(sf::IntRect(0, 2*texBoyut.y / 3, texBoyut.x, texBoyut.y / 3));

	resimAyarla();

}

void Buton::resimAyarla()
{
	auto texBoyut = m_texArkaPlan.getSize();
	float sx = m_boyut.x / texBoyut.x;
	float sy = m_boyut.y / (texBoyut.y / 3);
	m_resNormal.setScale(sx, sy);
	m_resBasili.setScale(sx, sy);
	m_resUzerinde.setScale(sx, sy);

	m_resBasili.setPosition(m_konum);
	m_resNormal.setPosition(m_konum);
	m_resUzerinde.setPosition(m_konum);
}

void Buton::fareHareket(int x, int y)
{
	if(m_butonDurumu!=ButonDurum::Basili)
		m_butonDurumu = ButonDurum::Uzerinde;
	m_arkaPlan.setFillColor(sf::Color::Green);
}

void Buton::fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi)
{
	
	m_butonDurumu = ButonDurum::Basili;
	
}

void Buton::fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi)
{
	if (m_butonDurumu == ButonDurum::Basili)
		PencereAraci::fareButonBasildi(butonOlayi);

	m_butonDurumu = ButonDurum::Uzerinde;
	
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
	
	m_butonDurumu = ButonDurum::Normal;
	return false;
}
