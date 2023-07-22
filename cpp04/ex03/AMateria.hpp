#pragma once
#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
