#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	void exec() const;
public:
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(RobotomyRequestForm &obj);
	RobotomyRequestForm &operator=(RobotomyRequestForm &copy);
	~RobotomyRequestForm();
};
