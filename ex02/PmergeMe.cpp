#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
	return;
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

void PmergeMe::take(const char *str[], int argc)
{
	for (int i = 0; i < argc; i++)
		vect.push_back(atoi(str[i]));
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		if (*it < 0)
			throw BigNumber();
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		for (std::vector<int>::iterator it2 = it + 1; it2 != vect.end(); it2++)
			if (*it == *it2)
				throw Doublon();
}

bool PmergeMe::isSorted()
{
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		std::vector<int>::iterator it2 = it + 1;
		if (it2 != vect.end() && *it > *it2)
			return false;
	}
	return true;
}

void PmergeMe::print()
{
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
}