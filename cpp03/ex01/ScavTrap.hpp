#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void attack(const std::string &target);
	void    guardGate();
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &cpy);
};



