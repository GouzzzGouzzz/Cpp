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
	std::cout << "Brain copy constructor operator called\n";
	if (this != &copy)
		*(this)->_ideas = *(copy)._ideas;
	return (*this);
}
