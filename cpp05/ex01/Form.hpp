#pragma once
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_exec;
public:
	Form(const std::string name, const int sign, const int exec);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();
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
	std::string getName();
	bool getSigned();
	int getSignGrade();
	int getExecGrade();
	void beSigned(Bureaucrat& obj);
};

std::ostream& operator<<(std::ostream& os, Form& obj);
