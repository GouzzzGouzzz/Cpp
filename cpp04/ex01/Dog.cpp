#include "Dog.hpp"

//CONSTRUCTOR

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called\n";
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal()
{
	std::cout << "Copy constructor called\n";
	this->_type = copy._type;
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete this->_brain;
}

//FUNCTION

void Dog::makeSound() const
{
	std::cout << "* BARKS *\n";
}

//OVERLOADING

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Copy constructor operator called\n";
	if (this == &copy)
		return (*this);
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain[i] = copy._brain[i];
	return (*this);
}
