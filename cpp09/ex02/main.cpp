#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **ag)
{
	if (ac != 2)
	{
		std::cout << "Need 1 args\n";
		return 0;
	}
	(void) ag;
	Pmerge test;
	test.sort("test");
	return 1;
}
