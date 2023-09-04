#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called\n";
	this->_Hitpoints = 100;
	this->_Energy = 100;
	this->_Attack_dmg = 30;
	this->_Max_hp = 100;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy._Name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_Attack_dmg = copy._Attack_dmg;
	this->_Energy = copy._Energy;
	this->_Hitpoints = copy._Hitpoints;
	this->_Name = copy._Name;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuy(void)
{
	std::cout << this->_Name << " his requesting a high fives !\n";
}
