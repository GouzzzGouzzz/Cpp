#include "HumanBClass.hpp"

HumanB::HumanB(const char *name)
{
	this->name = name;
	this->weapon = NULL;
	std::cout << "HumanB constructor called by : " << this->name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " attack with their hands" << std::endl;
	else
		std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}
