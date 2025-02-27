#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	void makeSound() const;
	Dog& operator=(const Dog &copy);
};
