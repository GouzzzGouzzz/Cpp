#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	~WrongCat();
	void makeSound() const;
	WrongCat& operator=(const WrongCat &copy);
	WrongCat(const WrongCat &copy);
};
