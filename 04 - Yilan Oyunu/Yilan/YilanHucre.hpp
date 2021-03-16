#pragma once
#pragma once
#include<SFML/Graphics.hpp>
enum class YON { BOS, SOL, SAG, YUKARI, ASAGI };
class YilanHucre
{
public:

	YilanHucre();
	void hareketEt(float boyut);
	void yon(YON yeniYon);
	void konum(sf::Vector2f yeniKonum);
	sf::Vector2f konumGetir() const;
	YON	yonGetir();
private:
	YON m_yon;
	sf::Vector2f m_konum;
};
typedef std::vector<YilanHucre> HucreListesi;