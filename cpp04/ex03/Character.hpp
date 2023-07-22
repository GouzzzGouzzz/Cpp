#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _Name;
	AMateria *_inventory[4];
	AMateria *_onGround[100];
	int _groundSlot;
	int	_slot;
public:
	Character(std::string Name);
	Character(const Character &copy);
	~Character();
	std::string const & getName() const;
	Character& operator=(const Character &copy);
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, Character& target);
};
