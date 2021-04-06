#include "Yilan.hpp"

Yilan::Yilan()
{
	m_hucreBoyutu = 20.0f;
	m_hucreSekil.setFillColor(sf::Color::Red);
	m_hucreSekil.setSize({ m_hucreBoyutu,m_hucreBoyutu });
	for (int i = 0; i < 5; i++)
		kuyrugaEkle();

	resimYukle("L.png");
}
void Yilan::ciz(sf::RenderWindow& pencere)
{
	for (auto siradaki : m_hucreler)
	{
		m_resArkaPlan.setPosition(siradaki.konumGetir());
		pencere.draw(m_resArkaPlan);
	}
}
float Yilan::hucreBoyutGetir()
{
	return m_hucreBoyutu;
}
void Yilan::yonleriAktar()
{
	int hucreSayisi = m_hucreler.size();
	for (int i = hucreSayisi - 1; i > 0; i--)
	{
		YON yeniYon = m_hucreler[i - 1].yonGetir();
		m_hucreler[i].yon(yeniYon);
	}
}
void Yilan::hareket(float mesafe)
{

	for (auto& siradaki : m_hucreler)
	{
		siradaki.hareketEt(mesafe);
	}
}
void Yilan::kuyrugaEkle()
{
	int sonIndis = m_hucreler.size() - 1;
	if (sonIndis < 0)
	{
		YilanHucre hucre;
		hucre.konum(sf::Vector2f(m_hucreBoyutu, m_hucreBoyutu));
		m_hucreler.push_back(hucre);
		return;
	}
	//Diðer kýsýmlar ayný
	auto konum = m_hucreler[sonIndis].konumGetir();
	auto yon = m_hucreler[sonIndis].yonGetir();
	switch (yon)
	{
	case YON::SAG:
		konum.x -= m_hucreBoyutu;
		break;
	case YON::SOL:
		konum.x += m_hucreBoyutu;
		break;
	case YON::ASAGI:
		konum.y -= m_hucreBoyutu;
		break;
	case YON::YUKARI:
		konum.y += m_hucreBoyutu;
		break;
	}
	YilanHucre yeniHucre;
	yeniHucre.konum(konum);
	yeniHucre.yon(yon);
	m_hucreler.push_back(yeniHucre);

}





void Yilan::yonDegistir(YON yeniYon)
{
	auto yon = m_hucreler[0].yonGetir();
	if (yeniYon == YON::ASAGI || yeniYon == YON::YUKARI)
	{
		if (yon == YON::SAG || yon == YON::SOL)
			m_hucreler[0].yon(yeniYon);
	}
	else
	{
		if (yon == YON::ASAGI ||yon == YON::YUKARI)
			m_hucreler[0].yon(yeniYon);
	}
	
}

sf::Vector2f Yilan::basKonumGetir()
{
	return m_hucreler[0].konumGetir();
}

bool Yilan::kendiniYedimi()
{
	auto konum = basKonumGetir();
	int hucreSayisi = m_hucreler.size();
	for (int i = 1; i < hucreSayisi; i++)
	{
		auto sirKonum = m_hucreler[i].konumGetir();
		if (konum.x == sirKonum.x && konum.y == sirKonum.y)
			return true;
	}
	return false;
}

void Yilan::resimYukle(sf::String resimAdi)
{
	if (!m_texArkaPlan.loadFromFile(resimAdi));
	{

	}
	m_resArkaPlan.setTexture(m_texArkaPlan);
	
	//çizim fonksiyonu içerisinde
	auto texBoyut = m_texArkaPlan.getSize();
	float sx = m_hucreBoyutu/ texBoyut.x;
	float sy = m_hucreBoyutu / (texBoyut.y);
	m_resArkaPlan.setScale(sx, sy);

}
