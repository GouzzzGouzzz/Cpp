#pragma once
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _is_signed;
	const int _grade_sign;
	const int _grade_exec;
	virtual void exec() const = 0;
public:
	AForm(const std::string name, const int sign, const int exec);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();
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
	class NotSignedException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	const std::string getName() const;
	bool getSigned();
	int getSignGrade();
	int getExecGrade();
	void beSigned(Bureaucrat& obj);
	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, AForm& obj);
