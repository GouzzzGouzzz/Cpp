#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog();
	~Dog();
	void makeSound() const;
	Dog& operator=(const Dog &copy);
	Dog(const Dog &copy);
};
