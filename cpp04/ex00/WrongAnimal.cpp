#include "WrongAnimal.hpp"

//CONSTRUCTOR

WrongAnimal::WrongAnimal() : _type("Wrong Animal")
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

//SETTER/GETTER

void WrongAnimal::setType(std::string new_type)
{
	this->_type = new_type;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

//FUNCTIONS

void WrongAnimal::makeSound() const
{
	std::cout << "* WrongAnimal sound *\n";
}


