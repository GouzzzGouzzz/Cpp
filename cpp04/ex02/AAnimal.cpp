#include "AAnimal.hpp"

//CONSTRUCTOR

AAnimal::AAnimal() : _type("Unknown")
{
	std::cout << "Animal constructor called\n";
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "Copy constructor called\n";
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called\n";
}

//SETTER/GETTER

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::setType(std::string new_type)
{
	this->_type = new_type;
}

//FUNCTION

void AAnimal::makeSound() const
{
	std::cout << "* weird and scary yell *\n";
}

//OVERLOADING

AAnimal& AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "Copy constructor operator called\n";
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}
