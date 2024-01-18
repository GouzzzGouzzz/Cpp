#pragma once
#include <iostream>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter( ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();
	static void convert(std::string convert);
private:

};


