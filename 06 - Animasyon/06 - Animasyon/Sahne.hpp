#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<vector>

class Sahne
{
public:
	Sahne();
	void olustur(float sahneGenislik,
		float sahneYukseklik);
	void ciz(sf::RenderWindow& pencere);

	sf::Vector2f boyutGetir();
private:
	sf::Texture	m_kaplama;
	sf::Sprite	m_resYem;
	int		m_satirSayisi;
	int		m_sutunSayisi;

	float	m_hucreBoyutu;

	sf::RectangleShape			m_satirHucresi;
	sf::RectangleShape			m_sutunHucresi;
	sf::RectangleShape			m_Yem;
	std::vector<sf::Sprite>		m_zeminBloklari;
};