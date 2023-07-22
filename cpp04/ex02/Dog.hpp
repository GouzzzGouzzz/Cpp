#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
