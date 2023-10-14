#include "ScalarConverter.hpp"
#include <limits>
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
	int temp = atoi(convert.c_str());
	if (temp < 32 || temp > 126)
		std::cout << "Char: Non displayable\n";
	else
		std::cout << "Char: " << static_cast<char>(temp) << "\n";
}

void toInt(double val)
{
	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
		std::cout << "Int: Overflow / Underflow\n";
	else
		std::cout << "Int: " << static_cast<int>(val) << "\n";
}

void toDouble(double temp)
{
	std::cout << "Double: " << temp;
	if (temp - (int) temp == 0)
		std::cout << ".0\n";
	else
		std::cout << "\n";
}

void toFloat(double temp)
{
	std::cout << "Float: " << static_cast<float>(temp);
	if (temp - (int) temp == 0)
		std::cout << ".0f\n";
	else
		std::cout << "f\n";
}

double fromChar(std::string convert)
{
	std::cout << "Char :" << static_cast<char>(convert[0]) << "\n";
	return (static_cast<double>(convert[0]));
}

int check_nan(std::string convert)
{
	if (convert == "nan" || convert == "nanf")
	{
		std::cout <<"Char: impossible\nInt: impossible\nFloat: nanf\nDouble: nan\n";
		return 1;
	}
	return (-1);
}

void ScalarConverter::convert(std::string convert)
{
	double temp;

	temp = strtod(convert.c_str(), NULL);
	if (check_nan(convert) == 1)
		return ;
	if (convert.find_first_of("0123456789") > convert.length())
		temp = fromChar(convert);
	else
		toChar(convert);
	toInt(temp);
	toFloat(temp);
	toDouble(temp);
}
