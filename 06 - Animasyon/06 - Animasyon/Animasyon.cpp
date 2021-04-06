#include "Animasyon.hpp"

Animasyon::Animasyon()
{
	m_spriteSayisi = 0;
	m_spriteIndeks = 0;
	m_konum = sf::Vector2f(0, 0);
}

void Animasyon::ciz(sf::RenderWindow& pencere)
{
	m_spriteListesi[m_spriteIndeks].setPosition(m_konum);
	pencere.draw(m_spriteListesi[m_spriteIndeks]);
}

void Animasyon::olustur(sf::Texture& kaplama,
	sf::Vector2i konum,
	sf::Vector2i boyut,
	int cerceveSayisi)
{
	for (int i = 0; i < cerceveSayisi; i++)
	{
		sf::Sprite sprite;
		sprite.setTexture(kaplama);
		sprite.setTextureRect(sf::IntRect(konum, boyut));
		m_spriteListesi.push_back(sprite);
		//bir sonraki resmin koordinatý hesaplanýyor.
		konum.x += boyut.x + 1;

	}
	m_spriteSayisi = cerceveSayisi;

}

void Animasyon::guncelle()
{
	m_spriteIndeks++;
	m_spriteIndeks = (m_spriteIndeks) % m_spriteSayisi;

}

void Animasyon::konum(sf::Vector2f konum)
{
	konum.y -= m_spriteListesi[0].getLocalBounds().height;
	m_konum = konum;
}

sf::Vector2f Animasyon::boyutGetir()
{
	sf::Vector2f boyut(m_spriteListesi[0].getLocalBounds().width,
		m_spriteListesi[0].getLocalBounds().height);
	return boyut;
}
