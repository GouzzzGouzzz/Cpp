#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice &copy);
	~Ice();
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};


