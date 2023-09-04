#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();
	void highFivesGuy(void);
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &cpy);
};


