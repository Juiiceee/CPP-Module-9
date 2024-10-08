#include "RPN.hpp"

RPN::RPN() : first(0), second(0)
{
	std::cout << "RPN default constructor called\n";
}

RPN::RPN(const RPN &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return;
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

int add(int a, int b)
{
	return (a + b);
}

int mult(int a, int b)
{
	return (a * b);
}

int divi(int a, int b)
{
	return (a / b);
}

int sous(int a, int b)
{
	return (a - b);
}

int RPN::foundOperator(std::string key)
{
	int res = 0;
	switch (key[0])
	{
	case '+':
		res = add(first, second);
		break;
	case '-':
		res = sous(first, second);
		break;
	case '*':
		res = mult(first, second);
		break;
	case '/':
		res = divi(first, second);
		break;
	default:
		break;
	}
	return (res);
}

int RPN::process(std::string str)
{
	std::istringstream file(str);
	std::string line;
	std::string tmp;
	while (std::getline(file, line, ' '))
	{
		if (line.size() != 1 || !isOperator(line[0]))
			throw InvalidExpression();
		tmp = line[0];
		if (isdigit(line[0]))
			_stack.push(line[0] - '0');
		else
		{
			second = _stack.top();
			_stack.pop();
			first = _stack.top();
			_stack.pop();
			_stack.push(foundOperator(tmp));
		}
		return (_stack.top());
	}
	return (0);
}