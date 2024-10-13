#include "PmergeMe.hpp"

int main()
{
	PmergeMe p;
	const char *argv[] = {"10", "50", "2147483647", "11", "90", "98745", "41241"};

	try
	{
		p.take(argv);
		p.print();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}