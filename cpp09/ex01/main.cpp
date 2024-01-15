#include "RPN.hpp"
#include <iostream>

int main(int ac, char **ag)
{
	RPN test;
	(void)ac;
	(void) ag;
	std::string truc = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	test.calcul(truc);
}
