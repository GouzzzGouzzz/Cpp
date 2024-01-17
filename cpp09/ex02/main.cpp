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
	PmergeMe test;
	test.sort(std::string(ag[1]));
	return 1;
}
