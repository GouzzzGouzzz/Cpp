#include "AMateria.hpp"

//Constructor

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria constructor called\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

//SETTER/GETTER

const std::string& AMateria::getType() const { return this->_type; }

//Functions

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria (" << this->getType() << ") used is ability on " << target.getName();
}
