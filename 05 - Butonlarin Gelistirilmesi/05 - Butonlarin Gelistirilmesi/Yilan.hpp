#pragma once
#include "YilanHucre.hpp"
#include <SFML/Graphics.hpp>
class Yilan
{
public:
	Yilan();
	void	ciz(sf::RenderWindow& pencere);
	void	kuyrugaEkle();
	void	hareket(float mesafe);
	float	hucreBoyutGetir();
	void	yonleriAktar();
	void	yonDegistir(YON yeniYon);
	sf::Vector2f	basKonumGetir();
	bool	kendiniYedimi();
private:
	void	resimYukle(sf::String resimAdi);
	sf::Texture			m_texArkaPlan;
	sf::Sprite			m_resArkaPlan;
	HucreListesi		m_hucreler;
	sf::RectangleShape	m_hucreSekil;
	float				m_hucreBoyutu;

};