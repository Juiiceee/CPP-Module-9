#include <stack>
#include <iostream>
#include "RPN.hpp"

int main()
{
	RPN rpn;

	try
	{
		rpn.process("1 2 + - 4 6 9 8");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}