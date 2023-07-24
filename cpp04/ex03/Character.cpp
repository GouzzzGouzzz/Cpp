#include "Character.hpp"

//Constructor

Character::Character(std::string Name) : _Name(Name), _groundSlot(0), full_inv(false)
{
	std::cout << "Character constructor called\n";
	for (int i = 0; i < 3; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called\n";
	*this = copy;
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
	for (int i = 0; i < 3; i++)
		if (_inventory[i])
			delete _inventory[i];
}

//Getter / setter
const std::string& Character::getName() const
{
	return this->_Name;
}

//Functions

void Character::equip(AMateria* m)
{
	if (full_inv)
		std::cout << this->getName() << " inventory is full, couldn't equip this item !\n";
	for (int i = 0; i < 3; i++)
	{
		if (!_inventory[i])
		{
				_inventory[i] = m;
			if (i == 3)
				full_inv = true;
			return ;
		}
	}
}

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
		_inventory[idx] = NULL;
		_groundSlot++;
		full_inv = false;
		std::cout << this->getName() << " has succesfully unequiped slot" << idx << "\n";
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout <<this->getName() <<" inventory slot number " << idx << " is empty !\n";
}

//Overloading

Character& Character::operator=(const Character &copy)
{
	std::cout << "Character copy assignement operator called\n";
	for (int i = 0; i < 3; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 99; i++)
		if (_onGround[i])
			delete _onGround[i];
	this->_Name = copy._Name;
	this->full_inv = copy.full_inv;
	this->_groundSlot = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i];
	return *this;
}
