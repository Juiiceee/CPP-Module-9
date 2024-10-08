#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN
{
private:
	std::stack<int> _stack;
	int first;
	int second;
	int foundOperator(std::string key);
public:
	RPN();
	RPN(const RPN &obj);
	RPN &operator=(const RPN &obj);
	~RPN();
	int process(std::string str);
	class InvalidExpression : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Invalid expression";
		}
	};
};
#endif
