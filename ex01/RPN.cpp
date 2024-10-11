#include "RPN.hpp"

RPN::RPN() : first(0), second(0)
{
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
}

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || isdigit(c));
}

void RPN::foundOperator(std::string key)
{
	switch (key[0])
	{
	case '+':
		sta.push(first + second);
		break;
	case '-':
		sta.push(first - second);
		break;
	case '*':
		sta.push(first * second);
		break;
	case '/':
		sta.push(first / second);
		break;
	default:
		break;
	}
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
			sta.push(line[0] - '0');
		else
		{
			second = sta.top();
			sta.pop();
			first = sta.top();
			sta.pop();
			foundOperator(tmp);
		}
	}
	return (sta.top());
	return (0);
}