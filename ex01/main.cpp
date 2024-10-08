#include <stack>
#include <iostream>
#include "RPN.hpp"

int main()
{
	RPN rpn;

	try
	{
		std::cout << rpn.process("1 2 * 6 + 9 *") << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}