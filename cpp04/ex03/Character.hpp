#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _Name;
	AMateria *_inventory[4];
public:
	Character(std::string Name);
	Character(const Character &copy);
	~Character();
	Character& operator=(const Character &copy);
	virtual	std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};
