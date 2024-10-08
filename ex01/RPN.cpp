#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "RPN default constructor called\n";
}

RPN::RPN(const RPN &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return ;
}

RPN &RPN::operator=(const RPN &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
		
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << "Destructor of RPN called\n";
}
