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
	std::cout << map.checkFormat("2024-12-31");
}
