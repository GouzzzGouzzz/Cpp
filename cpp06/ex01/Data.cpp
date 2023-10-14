#include "Data.hpp"

Data::Data(std::string name, int nb)
{
	std::cout << "Data constructor called\n";
	this->name = name;
	this->numbers = nb;
}

Data::Data(Data &copy)
{
	std::cout << "Data constructor called (copy constructor)\n";
	this->name = copy.name;
	this->numbers = copy.numbers;
}

Data& Data::operator=(const Data &copy)
{
	std::cout << "Data constructor called (copy assignement)\n";
	(void)copy;
	return *this;
}

Data::~Data()
{
	std::cout << "Data destructor called\n";
}

//Function

void Data::getInfo()
{
	std::cout << "Info : \n|" << this->name << "\n|" << this->numbers << "\n";
}
