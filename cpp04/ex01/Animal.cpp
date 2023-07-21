#include "Animal.hpp"

//CONSTRUCTOR

Animal::Animal() : _type("Unknown")
{
	std::cout << "Animal constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

//SETTER/GETTER

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string new_type)
{
	this->_type = new_type;
}

//FUNCTION

void Animal::makeSound() const
{
	std::cout << "* weird and scary yell *\n";
}
