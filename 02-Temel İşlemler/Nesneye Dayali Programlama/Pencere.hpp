#pragma once
#include<SFML/Graphics.hpp>

class Pencere
{
public:
	Pencere();
	void ayarla(unsigned int genislik,
		        unsigned int yukseklik,
		        sf::String baslik);
	void cizimeBasla();
	void cizimiBitir();
	bool kapandimi();
	void olayKontrol();
	void ciz(sf::Drawable& sekil);
private:
	sf::RenderWindow m_window;
};
