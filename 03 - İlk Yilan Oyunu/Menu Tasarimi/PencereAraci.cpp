#include "PencereAraci.hpp"

PencereAraci::PencereAraci()
{
	
}

void PencereAraci::fareHareket(int x, int y)
{
}

void PencereAraci::fareButonBasildi(sf::Event::MouseButtonEvent butonOlayi)
{
	for (auto siradaki : m_tiklaFonksiyonlari)
		siradaki();
}

void PencereAraci::fareButonBirakildi(sf::Event::MouseButtonEvent butonOlayi)
{
}

void PencereAraci::tiklaFonksiyonuEkle(FonksiyonTikla fonk)
{
	m_tiklaFonksiyonlari.push_back(fonk);
}
