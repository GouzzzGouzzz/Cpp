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

//OVERLOADING

Brain& Brain::operator=(const Brain &copy)
{
	std::cout << "Copy constructor operator called\n";
	*(this)->_ideas = *(copy)._ideas;
	return (*this);
}
