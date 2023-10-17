#include "Dog.hpp"

//CONSTRUCTOR

Dog::Dog() : AAnimal()
{
	std::cout << "Dog constructor called\n";
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal()
{
	std::cout << "Dog copy constructor called\n";
	this->_brain = new Brain();
	*this = copy;
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
	std::cout << "Dog copy constructor operator called\n";
	if (this == &copy)
		return (*this);
	delete this->_brain;
	this->_brain = new Brain();
	this->_brain->setIdea(copy._brain->getIdea());
	return (*this);
}
