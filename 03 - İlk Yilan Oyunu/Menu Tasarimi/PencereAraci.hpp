#pragma once
#include<SFML/Window/Event.hpp>
#include "Olaylar.hpp"
class PencereAraci
{
public:
	PencereAraci();
	virtual void fareHareket(int x, int y);
	virtual void fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi);
	virtual void fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi) ;
	virtual bool icerdemi(int x, int y)=0;

	void tiklaFonksiyonuEkle(FonksiyonTikla fonk);
protected:
	TiklaListesi m_tiklaFonksiyonlari;
};