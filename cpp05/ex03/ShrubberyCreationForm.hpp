#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	void exec() const;
public:
	ShrubberyCreationForm(std::string name);
	ShrubberyCreationForm(ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
};

