#include "Dog.hpp"

//CONSTRUCTOR

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called\n";
	this->setType("Dog");
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &copy) : Animal()
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}
//FUNCTION

void Dog::makeSound() const
{
	std::cout << "* BARKS *\n";
}
