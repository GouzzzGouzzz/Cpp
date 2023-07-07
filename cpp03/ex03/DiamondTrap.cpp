#include "DiamondTrap.hpp"

//CONSTRUCTOR

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->ClapTrap::_Name = name+"_clap_name";
	this->_Name = name;
	this->_Hitpoints = 100;
	this->_Max_hp = 100;
	this->_Energy = 50;
	this->_Attack_dmg = 30;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

//FUNCTIONS

void DiamondTrap::whoAmI()
{
	std::cout << "I am :" << this->_Name << " a object from :" << this->ClapTrap::_Name << "\n";
}
