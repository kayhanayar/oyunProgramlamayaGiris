#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
class PencereAraci;

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
	void arkaPlanRengi(sf::Color renk);
	void ciz(sf::Drawable& sekil);
	sf::RenderWindow& pencereGetir();

	void aracEkle(PencereAraci* arac);
private:
	sf::Color		m_arkaPlanRengi;
	sf::RenderWindow m_window;
	std::vector<PencereAraci*> m_pencereAraclari;
};
