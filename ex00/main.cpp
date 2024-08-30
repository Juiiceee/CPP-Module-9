#include <iostream>
#include "mapBtc.hpp"

int main()
{
	mapBtc map;

	try
	{
		map.fillMap();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	map.checkKey("Salut");
}
