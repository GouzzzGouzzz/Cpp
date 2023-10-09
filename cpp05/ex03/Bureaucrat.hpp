#pragma once
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	const std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
	void signForm(AForm &obj);
	void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
