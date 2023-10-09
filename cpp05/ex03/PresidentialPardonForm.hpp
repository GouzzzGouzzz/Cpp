#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	void exec() const;
public:
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(PresidentialPardonForm &copy);
	~PresidentialPardonForm();
};

