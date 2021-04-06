#include "Sahne.hpp"

Sahne::Sahne()
{
	m_satirHucresi.setFillColor(sf::Color::Green);
	m_sutunHucresi.setFillColor(sf::Color::Green);
	m_Yem.setFillColor(sf::Color::Blue);
	std::srand(std::time(nullptr));
}

void Sahne::olustur(float sahneGenislik, float sahneYukseklik)
{

	sf::Image image;
	image.loadFromFile("resimler/tiles.png");
	auto renk = image.getPixel(0, 0);
	image.createMaskFromColor(renk);
	m_kaplama.loadFromImage(image);

	sf::Sprite solKose, orta, sagkose;
	solKose.setTexture(m_kaplama);
	orta.setTexture(m_kaplama);
	sagkose.setTexture(m_kaplama);
	solKose.setTextureRect(sf::IntRect(21, 206, 50, 50));
	orta.setTextureRect(sf::IntRect(75, 206, 50, 50));
	sagkose.setTextureRect(sf::IntRect(129, 206, 50, 50));

	solKose.setPosition(0, 300);
	orta.setPosition(50, 300);
	sagkose.setPosition(250, 300);
	m_zeminBloklari.push_back(solKose);
	m_zeminBloklari.push_back(orta);
	orta.setPosition(100, 300);
	m_zeminBloklari.push_back(orta);
	orta.setPosition(150, 300);
	m_zeminBloklari.push_back(orta);
	orta.setPosition(200, 300);
	m_zeminBloklari.push_back(orta);
	m_zeminBloklari.push_back(sagkose);
}

void Sahne::ciz(sf::RenderWindow& pencere)
{
	sf::Vector2f konum;
	for (int i = 0; i < m_zeminBloklari.size(); i++)
	{
		pencere.draw(m_zeminBloklari[i]);
	}



}


sf::Vector2f Sahne::boyutGetir()
{
	sf::Vector2f boyut;
	boyut.x = m_sutunSayisi * m_hucreBoyutu;
	boyut.y = m_satirSayisi * m_hucreBoyutu;
	return boyut;
}


