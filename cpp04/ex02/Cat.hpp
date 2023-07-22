#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	void makeSound() const;
	Cat& operator=(const Cat &copy);
};
