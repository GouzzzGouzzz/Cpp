#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("MyBureaucrat", 111);
		Form b("MyForm",110, 100);
		std::cout << "\n* BUREAUCRAT WILL TRY TO SIGN A FORM BUT HE CAN'T *\n";
		a.signForm(b);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat a("MyBureaucrat", 110);
		Form b("MyForm",110, 100);
		std::cout << "\n* A BUREAUCRAT WILL SIGN A FORM *\n";
		a.signForm(b);
		std::cout << "\n* OUTPUTING FORM INFO USING << OPERATOR *\n";
		std::cout << b;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		std::cout << "\n* STILL CAN'T HAVE A GRADE TOO HIGH OR TOO LOW *\n";
		Form b("MyForm",160, 100);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		Form b("MyForm",-1, 100);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what();
	}
	std::cout << "\nEND OF MAIN\n";
}
