#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	mapBtc map;

	if (argc != 2)
		return (logError("Usage: ./btc input.txt"));
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
