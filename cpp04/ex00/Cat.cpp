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

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}
//FUNCTION

void Cat::makeSound() const
{
	std::cout << "* MEOWS *\n";
}
