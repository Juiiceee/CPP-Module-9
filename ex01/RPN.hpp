#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <sstream>

class RPN
{
private:
	int add(int a, int b);
	int mult(int a, int b);
	int div(int a, int b);
	int sous(int a, int b);

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
