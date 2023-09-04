#pragma once
# include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	virtual ~Animal();
	std::string getType() const;
	void setType(std::string new_type);
	virtual void makeSound() const;
	Animal(const Animal &copy);
	Animal& operator=(const Animal &copy);
};
