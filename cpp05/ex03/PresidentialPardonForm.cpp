#include "PresidentialPardonForm.hpp"

//Constructor / destructor

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : AForm(obj.getName()+"_copy", 25, 5)
{
	std::cout << "PresidentialPardonForm has been created(copy constructor)\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
	std::cout << "PresidentialPardonForm has been created (copy assignement)\n";
	*this = obj;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

//Function

void PresidentialPardonForm::exec() const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
}
