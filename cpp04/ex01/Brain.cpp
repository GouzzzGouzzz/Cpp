#include "Brain.hpp"

//CONSTRUCTOR

Brain::Brain()
{
	std::cout << "Brain constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

//OVERLOADING

Brain& Brain::operator=(const Brain &copy)
{
	std::cout << "Copy constructor operator called\n";
	if (this != &copy)
		*(this)->_ideas = *(copy)._ideas;
	return (*this);
}
