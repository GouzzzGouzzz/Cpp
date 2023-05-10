#include "HumanAClass.hpp"

HumanA::HumanA( const char *name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
	std::cout << "Constructor called HumanA : " << name << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Destructor called HumanA :" << name << std::endl;
}

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " <<this->weapon->getType() << std::endl;
}
