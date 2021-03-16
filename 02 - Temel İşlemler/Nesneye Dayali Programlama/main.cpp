#include <SFML/Graphics.hpp>
#include "Oyun.hpp"
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
