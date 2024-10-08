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

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || isdigit(c));
}

int	RPN::add(int a, int b)
{
	return (a + b);
}

int	RPN::mult(int a, int b)
{
	return (a * b);
}

int	RPN::div(int a, int b)
{
	return (a / b);
}


int	RPN::sous(int a, int b)
{
	return (a -b);
}

int RPN::process(std::string str)
{
	std::istringstream file(str);
	std::string line;
	while (std::getline(file, line, ' '))
	{
		if (line.size() != 1 || !isOperator(line[0]))
			throw InvalidExpression();
		std::cout << line << std::endl;
	}
	return (0);
}