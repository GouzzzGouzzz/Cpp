#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> s;
	MutantStack<int> truc;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	for (MutantStack<int>::iterator it = s.begin(); it != s.end(); it++)
		std::cout << *it << " ";
	std::cout << "\nNOW PRINTING COPY OF 's' named 'truc'" << std::endl;
	truc = s;
	for (MutantStack<int>::iterator it = truc.begin(); it != truc.end(); it++)
		std::cout << *it << " ";
}
