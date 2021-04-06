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
	ButonDurum			m_durum;
	sf::RectangleShape	m_arkaPlan;
	sf::Text			m_yazi;
	sf::Vector2f		m_konum;
	sf::Vector2f		m_boyut;
	sf::Texture			m_texArkaPlan;
	sf::Sprite*			m_aktifRes;
	sf::Sprite			m_resArkaPlan;
	sf::Sprite			m_resUzerinde;
	sf::Sprite			m_resBasili;
	virtual void fareHareket(int x, int y) override;
	virtual void fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi) override;
	virtual void fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi) override;
	virtual bool icerdemi(int x, int y) override;
	void kaplamaAyarla();

};
