#include "WeaponClass.hpp"

Weapon::Weapon(std::string name)
{
	this->type = name;
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::Weapon()
{
	this->type = "\0";
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;

}

const std::string& Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
