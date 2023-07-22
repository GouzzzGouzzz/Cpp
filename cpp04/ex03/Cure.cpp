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

//FUNCTIONS

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}
