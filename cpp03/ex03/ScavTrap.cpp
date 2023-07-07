#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called\n";
	this->_Hitpoints = 100;
	this->_Energy = 50;
	this->_Attack_dmg = 20;
	this->_Max_hp = 100;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_Hitpoints = 100;
	this->_Energy = 50;
	this->_Attack_dmg = 20;
	this->_Max_hp = 100;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
	if (this->_Hitpoints > 0)
		std::cout << "ScavTrap "<< this->_Name << " is now in Gate keeper mode !\n";
	else
		std::cout << "ScavTrap "<< this->_Name << " is already dead and can't enter in Gate keeper mode !\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Hitpoints <= 0)
	{
		std::cout << this->_Name << " is already dead and can't attack !\n";
		return ;
	}
	if (this->_Energy <= 0)
	{
		std::cout << this->_Name << " is out of energy, couldn't attack\n";
		return ;
	}
	this->_Energy--;
	std::cout << this->_Name << " (ScavTrap) slashed " << target << " and deal " << this->_Attack_dmg << " damage\n";
}
