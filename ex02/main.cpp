#include "PmergeMe.hpp"

int main()
{
	PmergeMe p;
	const char *argv[] = {"10", "50", "", "11", "90", "98745", "41241"};
	int argc = 7;

	try
	{
		p.take(argv, argc);
		p.print();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}