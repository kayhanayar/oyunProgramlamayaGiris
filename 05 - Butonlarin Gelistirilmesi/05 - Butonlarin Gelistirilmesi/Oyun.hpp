#pragma once

#include "Pencere.hpp"
#include "Buton.hpp"
#include "Sahne.hpp"
#include "Yilan.hpp"
class Oyun
{
public:
	Oyun();
	~Oyun();
	void btnYeniOyunTikla();
	void btnCikisTikla();
	void girisKontrol();
	void sahneGuncelle();
	void sahneCiz();
	void saatiYenidenBaslat();
	bool bittimi();
	void menuAyarla();
	void menuCiz();
	bool yilanIcerdemi();
	bool yilanYemUzerindemi();
private:
	Pencere		m_pencere;
	Buton		m_btnYeniOyun;
	Buton		m_btnCikis;
	Sahne		m_sahne;
	Yilan		m_yilan;
	sf::Font	m_font;
	sf::Clock	m_saat;
	sf::Time	m_gecenSure;
	bool		m_kapalimi;
	bool		m_yeniOyunTiklandimi;
	YON			m_siradakiYon;
	float		m_cerceveSuresi;
	float		m_hucreBoyutu;
	float		m_alinanMesafe;
};