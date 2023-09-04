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

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}
//FUNCTIONS

void WrongCat::makeSound() const
{
	std::cout << "* WrongCat meows *\n";
}
