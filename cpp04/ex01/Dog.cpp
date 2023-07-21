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

//FUNCTION

void Dog::makeSound() const
{
	std::cout << "* BARKS *\n";
}
