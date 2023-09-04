#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap();
	~ScavTrap();
	void attack(const std::string &target);
	void    guardGate();
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &cpy);
};



