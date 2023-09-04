#include "MateriaSource.hpp"

//Constructor

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource construcotr called\n";
	for (int i = 0; i < 3; i++)
		_known[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destrucotr called\n";
	for (int i = 0; i < 3; i++)
		if(_known[i])
			delete _known[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i < 3; i++)
		this->_known[i] = copy._known[i];
	return *this;
}

//Functions

void MateriaSource::learnMateria(AMateria *type)
{
	for (int i = 0; i < 3; i++)
	{
		if (!_known[i])
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
	for (int i = 0; i < 3; i++)
	{
		if (_known[i] && _known[i]->getType() == type)
			return _known[i]->clone();
	}
	std::cout << "Materia type is unknown !\n";
	return 0;
}
