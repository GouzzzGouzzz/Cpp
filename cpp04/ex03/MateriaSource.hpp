#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_known[4];
public:
	MateriaSource();
	~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	MateriaSource& operator=(const MateriaSource &copy);
	MateriaSource(const MateriaSource &copy);
};
