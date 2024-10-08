#include <iostream>
#include "mapBtc.hpp"

int main(int argc, char **argv)
{
	mapBtc map;

	if (argc != 2)
		return (logError("Usage: ./a.out input.txt"));
	try
	{
		map.fillMap();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	map.printPrice(argv[1]);
}
