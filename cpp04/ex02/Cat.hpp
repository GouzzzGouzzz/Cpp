#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
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
