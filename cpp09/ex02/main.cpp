#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **ag)
{
	if (ac < 2)
	{
		std::cout << "Need more args\n";
		return 0;
	}
	(void) ag;
	PmergeMe test;
	test.sort(ag,ac);
	return 1;
}
