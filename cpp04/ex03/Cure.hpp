#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure();
	Cure(const Cure& copy);
	~Cure();
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};
