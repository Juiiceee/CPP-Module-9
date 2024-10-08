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
	map.printMap();
	std::cout << map.checkFormat("2024-12-31");
}
