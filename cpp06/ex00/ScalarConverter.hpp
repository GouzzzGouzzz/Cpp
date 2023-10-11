#pragma once
#include <iostream>

class ScalarConverter
{
private:
	/* data */
public:
	ScalarConverter();
	ScalarConverter( ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();
	static void convert(std::string convert);
};


