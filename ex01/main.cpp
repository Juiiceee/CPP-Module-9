#include <stack>
#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl;
		return (1);
	}
	try
	{
		std::cout << rpn.process(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}