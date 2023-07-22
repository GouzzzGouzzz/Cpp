#include "Character.hpp"

//Constructor

Character::Character(std::string Name) : _Name(Name)
{
	std::cout << "Character constructor called\n";
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called\n";
	*this = copy;
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
}

//Getter / setter

const std::string& Character::getName() const
{
	return this->_Name;
}

//Functions

void Character::equip(AMateria* m)
{
	if (_slot == 3)
		std::cout << this->getName() << " inventory is full, couldn't equip this item !\n";
	if (_slot != 3)
	{
		_inventory[_slot] = m;
		_slot++;
	}
}
//ca va pas ensemble la
void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	if (_inventory[idx])
	{
		if (_groundSlot == 99)
		{
			_groundSlot = 0;
			delete _onGround[_groundSlot];
		}
		if (_onGround[_groundSlot])
			delete _onGround[_groundSlot];
		_onGround[_groundSlot] = _inventory[idx]->clone();
		delete _inventory[idx];
		_groundSlot++;
		_slot--;
		std::cout << this->getName() << " has succesfully unequiped slot" << idx << "\n";
	}
}

void Character::use(int idx, Character& target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout <<this->getName() <<" inventory slot number" << idx << "is empty !\n";
}

//Overloading

Character& Character::operator=(const Character &copy)
{
	std::cout << "Character copy assignement operator called\n";
	delete [] _inventory;
	this->_Name = copy._Name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
}
