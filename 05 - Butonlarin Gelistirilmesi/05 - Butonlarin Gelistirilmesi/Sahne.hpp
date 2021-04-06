#pragma once
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
class Sahne
{
public:
	Sahne();
	void olustur(float sahneGenislik, 
		         float sahneYukseklik, 
		         float hucreBoyut);
	void ciz(sf::RenderWindow& pencere);
	void yemOlustur();
	sf::Vector2f yemKonumGetir();
	sf::Vector2f boyutGetir();
private:
	sf::Texture	m_texArkaPlan;
	sf::Sprite	m_resYem;
	int		m_satirSayisi;
	int		m_sutunSayisi;

	float	m_hucreBoyutu;

	sf::RectangleShape			m_satirHucresi;
	sf::RectangleShape			m_sutunHucresi;
	sf::RectangleShape			m_Yem;

};