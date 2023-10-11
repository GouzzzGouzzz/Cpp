#include "ScalarConverter.hpp"

int main(int ac, char **ag)
{
	if (ac != 2)
	{
		std::cout << "Need only one args\n";
		return 0;
	}
	ScalarConverter bob;

	bob.convert(ag[1]);
}
