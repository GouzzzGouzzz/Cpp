#include "ScalarConverter.hpp"
#include <limits.h>
#include <stdlib.h>
//Constructor / destructor

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called\n";
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	std::cout << "ScalarConverter constructor called (copy constructor)\n";
	(void) copy;
	ScalarConverter();
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter constructor called (copy assignement)\n";
	*this = copy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called\n";
}

void ScalarConverter::convert(std::string convert)
{

}
