#include "MateriaSource.hpp"

//Constructor

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called\n";
	for (int i = 0; i < 4; i++)
		_known[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called\n";
	for (int i = 0; i < 4; i++)
		if(_known[i] != NULL)
			delete _known[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy assignment operator called (Pointer in self will be lost, keep track on them before calling this)" << std::endl;
	for (int i = 0; i < 4; i++)
		if (copy._known[i] != NULL)
			this->_known[i] = copy._known[i]->clone();
	return *this;
}

//Functions

void MateriaSource::learnMateria(AMateria *type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_known[i] == NULL)
		{
			_known[i] = type;
			std::cout << "A Materia has been learned\n";
			return ;
		}
	}
	std::cout << "Couldn't learn a materia !\n";
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_known[i] && _known[i]->getType() == type)
			return _known[i]->clone();
	}
	std::cout << "Materia type is unknown !\n";
	return 0;
}
