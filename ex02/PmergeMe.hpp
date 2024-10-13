#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <string>

class PmergeMe
{
private:
	std::vector<int> vect;
	long timeVect;
	long timeList;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();

	void take(const char *str[]);
	void print();

	class BigNumber : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Big number or negative number";
		}
	};

	class Doublon : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "There is a duplicate";
		}
	};
};
#endif
