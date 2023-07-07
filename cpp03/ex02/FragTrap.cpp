#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called\n";
	this->_Hitpoints = 100;
	this->_Energy = 100;
	this->_Attack_dmg = 30;
	this->_Max_hp = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuy(void)
{
	std::cout << this->_Name << " his requesting a high fives !\n";
}
