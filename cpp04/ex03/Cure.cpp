#include "Cure.hpp"

//CONSTRUCTOR

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called\n";
}

Cure::Cure(const Cure& copy) : AMateria("cure")
{
	std::cout << "Cure copy constructor called\n";
	*this = copy;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

Cure& Cure::operator=(const Cure &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

//FUNCTIONS

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}
