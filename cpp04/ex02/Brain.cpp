#include "Brain.hpp"

//CONSTRUCTOR

Brain::Brain()
{
	std::cout << "Brain constructor called\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "randomIdea";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

//OVERLOADING

Brain& Brain::operator=(const Brain &copy)
{
	std::cout << "Brain copy constructor operator called\n";
	if (this != &copy)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	return (*this);
}

//FUNCTIONS

void Brain::setIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}

std::string Brain::getIdea(void)
{
	return this->_ideas[0];
}
