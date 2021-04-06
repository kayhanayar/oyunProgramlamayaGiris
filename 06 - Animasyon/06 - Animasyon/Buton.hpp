#pragma once
#include<SFML/Graphics.hpp>
#include "PencereAraci.hpp"
enum class ButonDurum{Uzerinde,Basili,Normal};
class Buton:public PencereAraci
{
public:
	Buton();
	void yazi(sf::String yeniYazi);
	void renk(sf::Color renk);
	void font(sf::Font& yeniFont);
	void ciz(sf::RenderWindow& pencere);
	void boyut(float genislik, float yukseklik);
	void konum(float x, float y);

	sf::Vector2f boyutGetir();
private:
	void resimleriYukle(sf::String dosyaIsmi);
	void resimAyarla();
	sf::RectangleShape	m_arkaPlan;
	sf::Text			m_yazi;
	sf::Vector2f		m_konum;
	sf::Vector2f		m_boyut;
	sf::Sprite			m_resBasili;
	sf::Sprite			m_resNormal;
	sf::Sprite			m_resUzerinde;
	sf::Texture			m_texArkaPlan;
	ButonDurum			m_butonDurumu;

	virtual void fareHareket(int x, int y) override;
	virtual void fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi) override;
	virtual void fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi) override;
	virtual bool icerdemi(int x, int y) override;


};
