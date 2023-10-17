#include "Cat.hpp"
#include "Brain.hpp"

//CONSTRUCTOR

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called\n";
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << "Cat copy constructor called\n";
	this->_brain = new Brain();
	*this = copy;
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
	std::cout << "Cat copy constructor operator called\n";
	if (this == &copy)
		return (*this);
	delete this->_brain;
	this->_brain = new Brain();
	this->_brain->setIdea(copy._brain->getIdea());
	return (*this);
}
