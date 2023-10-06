#include "Bureaucrat.hpp"

int main()
{
	try // Too low
	{
		Bureaucrat a("test", 150);
		std::cout << "trying to increase 'a' which is graded 150\n";
		std::cout << a << "\n";
		a.decreaseGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try // Too high
	{
		std::cout << "trying to increase 'b' which is graded 1\n";
		Bureaucrat b("test", 1);
		std::cout << b << "\n";
		b.increaseGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try // Too high on init
	{
		std::cout << "trying to init : test(truc, -1)\n";
		Bureaucrat test("truc", -1);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try // Too low on init
	{
		std::cout << "trying to init : test(truc, 200)\n";
		Bureaucrat test("truc", 200);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nEND OF MAIN\n";
}
