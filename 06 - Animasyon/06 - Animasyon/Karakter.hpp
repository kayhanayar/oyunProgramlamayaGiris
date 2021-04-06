#pragma once
#include "Animasyon.hpp"


class Karakter
{
public:
	Karakter();
	void olustur(sf::String dosyaIsmi);
	void ciz(sf::RenderWindow& pencere);

	void solaYuru();
	void sagaYuru();
	void konumGuncelle();
	void animasyonGuncelle();
	void zipla();
	void cok();
	void sabit();
	void solaZipla();
	void sagaZipla();
	void sagYukariBakarakYuru();
	void solYukariBakarakYuru();
	void yukariBak();

	void yon(YON yon);
	void solAnimasyonlariYukle();
	void sagAnimasyonlariYukle();
	void yerCekimiUygula();
	bool zemindemi();
private:
	void				animasyonDegistir(AnimasyonTuru yeniAnimasyon);
	sf::Vector2f		m_konum;
	sf::Texture			m_kaplama;
	AnimasyonTuru		m_aktifAnimasyon;
	int					m_ziplamaSayaci;
	int					m_ziplamaMiktari;
	YON					m_yon;
	AnimasyonHaritasi	m_solAnimasyonlar;
	AnimasyonHaritasi	m_sagAnimasyonlar;
	float				m_hareketMiktari;

	//animasyonhareket fonksiyonlarý

	void				hareketIleriZipla(YON yon);
	void				hareketZipla();
	void				hareketYuru(YON yon);
};
