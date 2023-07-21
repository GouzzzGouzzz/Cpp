#include "WrongCat.hpp"

//CONSTRUCTOR

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat destructor called\n";
	this->setType("WrongCat");
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

//FUNCTIONS

void WrongCat::makeSound() const
{
	std::cout << "* WrongCat meows *\n";
}
