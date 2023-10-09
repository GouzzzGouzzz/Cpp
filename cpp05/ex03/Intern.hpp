#pragma once
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &obj);
	Intern &operator=(Intern &copy);
	~Intern();
	AForm *makeForm(std::string formName, std::string target) const;
};

