#include <SFML/Graphics.hpp>
#include <iostream>
#include "Oyun.hpp"
#include<functional>
void tikla()
{
	std::cout << "tikla" << std::endl;
}
std::function<void()> functionTikla;

int main()
{
	functionTikla = std::bind(tikla);
	functionTikla();
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
