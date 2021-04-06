#include <SFML/Graphics.hpp>
#include <iostream>
#include "Oyun.hpp"
#include<functional>

int main()
{
	Oyun oyun;
	while (!oyun.bittimi())
	{
		oyun.girisKontrol();
		oyun.sahneGuncelle();
		oyun.sahneCiz();
		oyun.saatiYenidenBaslat();
	}
	return 0;
}
