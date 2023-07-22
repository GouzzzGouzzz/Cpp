#include "Cat.hpp"
#include "Brain.hpp"

//CONSTRUCTOR

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called\n";
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Copy constructor called\n";
	this->_type = copy._type;
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete this->_brain;
}

//FUNCTION

void Cat::makeSound() const
{
	std::cout << "* MEOWS *\n";
}

//OVERLOADING

Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Copy constructor operator called\n";
	if (this == &copy)
		return (*this);
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain[i] = copy._brain[i];
	return (*this);
}
