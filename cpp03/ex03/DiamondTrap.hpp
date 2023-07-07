#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public virtual FragTrap, public virtual ScavTrap
{
private:
	std::string _Name;
public:
	DiamondTrap(std::string name);
	void whoAmI();
	~DiamondTrap();
};


