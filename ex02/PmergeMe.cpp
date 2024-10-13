#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
	{
		
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::take(const char *str[])
{
	for (int i = 0; i < 7; i++)
		vect.push_back(atoi(str[i]));
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		if (*it < 0)
			throw BigNumber();
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		for (std::vector<int>::iterator it2 = it + 1; it2 != vect.end(); it2++)
			if (*it == *it2)
				throw Doublon();
}

void PmergeMe::print()
{
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
}