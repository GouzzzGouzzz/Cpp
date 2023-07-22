#include "Ice.hpp"

//CONSTRUCTOR

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice& copy) : AMateria("ice")
{
	std::cout << "Ice copy constructor called\n";
	*this = copy;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

//FUNCTIONS

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at *" << target.getName() << "\n";
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}
