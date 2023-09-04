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

Ice& Ice::operator=(const Ice &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
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
