#include "Cat.hpp"

//CONSTRUCTOR

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called\n";
	this->setType("Cat");
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

//FUNCTION

void Cat::makeSound() const
{
	std::cout << "* MEOWS *\n";
}
