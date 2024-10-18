#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <string>
#include <list>

class PmergeMe
{
private:
	std::vector<int> vect;
	std::list<int> list;
	long timeVect;
	long timeList;
	bool isSorted();

public:
	PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();

	void take(const char *str[], int argc);
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
