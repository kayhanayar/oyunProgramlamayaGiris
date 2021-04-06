#pragma once

#include "Pencere.hpp"
#include "Buton.hpp"
#include "Sahne.hpp"

#include <SFML/Audio.hpp>
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
private:
	sf::SoundBuffer	m_soundBuffer;
	sf::Sound		m_sesYeme;
	sf::Music		m_music;
	Pencere		m_pencere;
	Buton		m_btnYeniOyun;
	Buton		m_btnCikis;
	Sahne		m_sahne;
	sf::Font	m_font;
	sf::Clock	m_saat;
	sf::Time	m_gecenSure;
	sf::Clock	m_tusSaati;
	bool		m_kapalimi;
	bool		m_yeniOyunTiklandimi;

	float		m_cerceveSuresi;
	int			m_cerceveSayisi;
	float		m_hucreBoyutu;
	float		m_alinanMesafe;
};