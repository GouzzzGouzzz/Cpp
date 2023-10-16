#include "Character.hpp"

//Constructor

Character::Character(std::string Name) : _Name(Name)
{
	std::cout << "Character constructor called\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i]->clone();
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
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
	if (!m)
	{
		std::cout << "Couldn't equip this item !\n";
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << this->getName() << " equiped an item : "<< m->getType()<<  "!\n";
			return ;
		}
	}
	std::cout << this->getName() << " inventory is full, couldn't equip this item !\n";
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	_inventory[idx] = NULL;
	std::cout << this->getName() << " has succesfully unequiped slot " << idx << "\n";
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout <<this->getName() <<" inventory slot number " << idx << " is empty !\n";
}

//Overloading

Character& Character::operator=(const Character &copy)
{
	std::cout << "Character copy assignement operator called\n";
	this->_Name = copy._Name;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = copy._inventory[i]->clone();
	return *this;
}
