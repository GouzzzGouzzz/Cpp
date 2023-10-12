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

void toChar(std::string convert)
{
	char temp = static_cast<char>(convert[0]);
	if (convert.length() != 1)
		std::cout << "Char : Doesn't make sense !\n";
	else if (temp < 32 || temp > 126)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: " << temp << "\n";
}

void toInt(double val)
{
	if (val > INT_MAX || val < INT_MIN)
		std::cout << "Int: Overflow / Underflow\n";
	else
		std::cout << "Int: " << static_cast<int>(val) << "\n";
}

double fromChar(std::string convert)
{
	char temp = static_cast<char>(convert[0]);
	return (static_cast<double>(temp));
}

void ScalarConverter::convert(std::string convert)
{
	double temp;

	temp = strtod(convert.c_str(), NULL);
	if (convert.find_first_of("0123456789") > convert.length())
		temp = static_cast<double>(convert[0]);
	toChar(convert);
	toInt(temp);
	std::cout << "Float: " << static_cast<float>(temp) <<
	"\nDouble: " << temp << "\n";
}
