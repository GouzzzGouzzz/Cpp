#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	~WrongCat();
	void makeSound() const;
};
