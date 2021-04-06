#include "Sahne.hpp"

Sahne::Sahne()
{
	m_satirHucresi.setFillColor(sf::Color::Green);
	m_sutunHucresi.setFillColor(sf::Color::Green);
	m_Yem.setFillColor(sf::Color::Blue);
	std::srand(std::time(nullptr));
}

void Sahne::olustur(float sahneGenislik, float sahneYukseklik, float hucreBoyut)
{
	m_sutunSayisi = sahneGenislik / hucreBoyut;
	m_satirSayisi = sahneYukseklik / hucreBoyut;
	m_hucreBoyutu = hucreBoyut;
	m_satirHucresi.setSize({ sahneGenislik,1 });
	m_sutunHucresi.setSize({ 1,sahneYukseklik });
	m_Yem.setSize({ hucreBoyut,hucreBoyut });

	if (m_texArkaPlan.loadFromFile("yem.png"))
	{

	}
	m_resYem.setTexture(m_texArkaPlan);
	auto texBoyut = m_texArkaPlan.getSize();
	float sx = m_hucreBoyutu / texBoyut.x;
	float sy = m_hucreBoyutu / (texBoyut.y);
	m_resYem.setScale(sx, sy);
	yemOlustur();
}
void Sahne::yemOlustur()
{
	float x = std::rand() % m_sutunSayisi;
	float y = std::rand() % m_satirSayisi;
	m_Yem.setPosition(sf::Vector2f(x * m_hucreBoyutu, y * m_hucreBoyutu));
	m_resYem.setPosition(sf::Vector2f(x * m_hucreBoyutu, y * m_hucreBoyutu));
}
void Sahne::ciz(sf::RenderWindow& pencere)
{
	sf::Vector2f konum;
	pencere.draw(m_resYem);
	for (int satir = 0; satir < m_satirSayisi; satir++)
	{
		konum.x = 0;
		konum.y = satir * m_hucreBoyutu;
		m_satirHucresi.setPosition(konum);
		pencere.draw(m_satirHucresi);
	}
	for (int sutun = 0; sutun < m_sutunSayisi; sutun++)
	{
		konum.x = sutun * m_hucreBoyutu;
		konum.y = 0;
		m_sutunHucresi.setPosition(konum);
		pencere.draw(m_sutunHucresi);

	}

}

sf::Vector2f Sahne::yemKonumGetir()
{
	return m_Yem.getPosition();
}

sf::Vector2f Sahne::boyutGetir()
{
	sf::Vector2f boyut;
	boyut.x = m_sutunSayisi * m_hucreBoyutu;
	boyut.y = m_satirSayisi * m_hucreBoyutu;
	return boyut;
}


