#include "Karakter.hpp"
#include<iostream>

Karakter::Karakter()
{
	m_aktifAnimasyon = AnimasyonTuru::Sabit;
	m_hareketMiktari = 2;
	m_yon = YON::SAG;
	m_konum.y = 0;
	m_ziplamaSayaci = 0;
	m_ziplamaMiktari = 40;
}

void Karakter::olustur(sf::String dosyaIsmi)
{
	sf::Image image;
	image.loadFromFile(dosyaIsmi);
	auto maskColor = image.getPixel(0, 0);
	image.createMaskFromColor(maskColor);
	m_kaplama.loadFromImage(image);

	solAnimasyonlariYukle();
	sagAnimasyonlariYukle();
}

void Karakter::ciz(sf::RenderWindow& pencere)
{
	if (m_yon == YON::SOL)
	{
		m_solAnimasyonlar[m_aktifAnimasyon].konum(m_konum);
		m_solAnimasyonlar[m_aktifAnimasyon].ciz(pencere);
	}
	else
	{
		m_sagAnimasyonlar[m_aktifAnimasyon].konum(m_konum);
		m_sagAnimasyonlar[m_aktifAnimasyon].ciz(pencere);
	}

}


void Karakter::animasyonGuncelle()
{
	if (m_yon == YON::SOL)
	{
		if (m_aktifAnimasyon == AnimasyonTuru::Zipla)
			m_solAnimasyonlar[AnimasyonTuru::Zipla].guncelle();
		else
		{
			m_solAnimasyonlar[m_aktifAnimasyon].guncelle();
		}

	}
	else
	{
		m_sagAnimasyonlar[m_aktifAnimasyon].guncelle();
	}

}

void Karakter::zipla()
{
	m_ziplamaSayaci = m_ziplamaMiktari;
	animasyonDegistir(AnimasyonTuru::Zipla);
}

void Karakter::solaYuru()
{
	m_yon = YON::SOL;
	animasyonDegistir(AnimasyonTuru::Yuru);

}

void Karakter::sagaYuru()
{
	m_yon = YON::SAG;
	animasyonDegistir(AnimasyonTuru::Yuru);

}



void Karakter::cok()
{
	m_aktifAnimasyon = AnimasyonTuru::Cok;
}

void Karakter::sabit()
{
	animasyonDegistir(AnimasyonTuru::Sabit);
}

void Karakter::solaZipla()
{
	yon(YON::SOL);
	m_ziplamaSayaci = m_ziplamaMiktari;
	animasyonDegistir(AnimasyonTuru::IleriZipla);
}

void Karakter::sagaZipla()
{
	yon(YON::SAG);
	m_ziplamaSayaci = m_ziplamaMiktari;
	animasyonDegistir(AnimasyonTuru::IleriZipla);
}

void Karakter::sagYukariBakarakYuru()
{
	yon(YON::SAG);

	animasyonDegistir(AnimasyonTuru::YuruCaprazYukari);
}

void Karakter::solYukariBakarakYuru()
{
	yon(YON::SOL);

	animasyonDegistir(AnimasyonTuru::YuruCaprazYukari);
}

void Karakter::yukariBak()
{
	animasyonDegistir(AnimasyonTuru::SabitYukari);
}


void Karakter::yon(YON yon)
{
	m_yon = yon;
}

void Karakter::solAnimasyonlariYukle()
{
	Animasyon solaYuru, sabit, cok, zipla;
	Animasyon caprazYukari, yukari, yuruCaprazYukari;

	solaYuru.olustur(m_kaplama, sf::Vector2i(24, 375), sf::Vector2i(50, 50), 8);
	sabit.olustur(m_kaplama, sf::Vector2i(24, 200), sf::Vector2i(50, 50), 1);
	cok.olustur(m_kaplama, sf::Vector2i(75, 200), sf::Vector2i(50, 50), 1);
	zipla.olustur(m_kaplama, sf::Vector2i(126, 200), sf::Vector2i(50, 50), 1);
	m_solAnimasyonlar[AnimasyonTuru::Yuru] = (solaYuru);
	m_solAnimasyonlar[AnimasyonTuru::Sabit] = (sabit);
	m_solAnimasyonlar[AnimasyonTuru::Cok] = (cok);
	m_solAnimasyonlar[AnimasyonTuru::Zipla] = (zipla);
	m_solAnimasyonlar[AnimasyonTuru::IleriZipla] = zipla;

	caprazYukari.olustur(m_kaplama, sf::Vector2i(249, 676), sf::Vector2i(50, 57), 1);
	yukari.olustur(m_kaplama, sf::Vector2i(193, 676), sf::Vector2i(50, 57), 1);
	yuruCaprazYukari.olustur(m_kaplama, sf::Vector2i(25, 1063), sf::Vector2i(50, 57), 8);


	m_solAnimasyonlar[AnimasyonTuru::SabitYukariCapraz] = (caprazYukari);
	m_solAnimasyonlar[AnimasyonTuru::SabitYukari] = yukari;
	m_solAnimasyonlar[AnimasyonTuru::YuruCaprazYukari] = yuruCaprazYukari;
}

void Karakter::sagAnimasyonlariYukle()
{
	Animasyon sagaYuru, sabit, cok, zipla;
	Animasyon caprazYukari, yukari, yuruCaprazYukari;

	sagaYuru.olustur(m_kaplama, sf::Vector2i(24, 315), sf::Vector2i(50, 50), 8);
	cok.olustur(m_kaplama, sf::Vector2i(75, 143), sf::Vector2i(50, 50), 1);
	sabit.olustur(m_kaplama, sf::Vector2i(24, 143), sf::Vector2i(50, 50), 1);
	zipla.olustur(m_kaplama, sf::Vector2i(126, 143), sf::Vector2i(50, 50), 1);

	caprazYukari.olustur(m_kaplama, sf::Vector2i(81, 676), sf::Vector2i(50, 57), 1);
	yukari.olustur(m_kaplama, sf::Vector2i(137, 676), sf::Vector2i(50, 57), 1);
	yuruCaprazYukari.olustur(m_kaplama, sf::Vector2i(25, 925), sf::Vector2i(50, 57), 8);

	m_sagAnimasyonlar[AnimasyonTuru::Yuru] = (sagaYuru);
	m_sagAnimasyonlar[AnimasyonTuru::Sabit] = (sabit);
	m_sagAnimasyonlar[AnimasyonTuru::Cok] = (cok);
	m_sagAnimasyonlar[AnimasyonTuru::Zipla] = (zipla);
	m_sagAnimasyonlar[AnimasyonTuru::IleriZipla] = zipla;
	m_sagAnimasyonlar[AnimasyonTuru::SabitYukariCapraz] = (caprazYukari);
	m_sagAnimasyonlar[AnimasyonTuru::SabitYukari] = yukari;
	m_sagAnimasyonlar[AnimasyonTuru::YuruCaprazYukari] = yuruCaprazYukari;
}

void Karakter::yerCekimiUygula()
{
	if (!zemindemi())
		m_konum.y += m_hareketMiktari;
}

bool Karakter::zemindemi()
{
	if (m_konum.y >= 300)
	{
		return true;
	}
	return false;
}

void Karakter::animasyonDegistir(AnimasyonTuru yeniAnimasyon)
{
	if (m_aktifAnimasyon == AnimasyonTuru::Zipla)
	{
		if (m_ziplamaSayaci == 0)
		{
			m_aktifAnimasyon = yeniAnimasyon;
		}
	}
	else if (m_aktifAnimasyon == AnimasyonTuru::IleriZipla)
	{
		if (m_ziplamaSayaci == 0)
		{
			m_aktifAnimasyon = AnimasyonTuru::Sabit;
		}
	}
	else
	{
		m_aktifAnimasyon = yeniAnimasyon;
	}

}
void Karakter::konumGuncelle()
{
	if (m_aktifAnimasyon == AnimasyonTuru::Yuru ||
		m_aktifAnimasyon == AnimasyonTuru::YuruCaprazYukari)
	{
		hareketYuru(m_yon);
	}
	if (m_aktifAnimasyon == AnimasyonTuru::Zipla)
	{
		hareketZipla();
	}
	if (m_aktifAnimasyon == AnimasyonTuru::IleriZipla)
	{
		hareketIleriZipla(m_yon);
	}

	yerCekimiUygula();
}
void Karakter::hareketIleriZipla(YON yon)
{
	sf::Vector2f hareket;
	if (m_ziplamaSayaci >= 20)
	{

		hareket.y -= m_hareketMiktari * 2;
		hareket.x = (int)yon * m_hareketMiktari;
		m_ziplamaSayaci--;
	}
	else if (m_ziplamaSayaci >= 0)
	{
		hareket.x = (int)yon * m_hareketMiktari;
		m_ziplamaSayaci--;
	}
	m_konum += hareket;
}

void Karakter::hareketZipla()
{
	sf::Vector2f hareket;
	if (m_ziplamaSayaci >= 20)
	{
		hareket.y -= m_hareketMiktari * 2;
		m_ziplamaSayaci--;

	}
	else if (m_ziplamaSayaci >= 0)
	{
		m_ziplamaSayaci--;
	}
	m_konum += hareket;
}

void Karakter::hareketYuru(YON yon)
{
	m_konum.x += (int)yon * m_hareketMiktari;
}
