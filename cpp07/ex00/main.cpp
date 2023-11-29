#include <iostream>
#include "whatever.hpp"

int main(int, char**)
{
	int a,b;
	a = 2;
	b = 4;
	swap(a,b);
	std::cout << "A = " << a << "\nB = " << b << "\n";
	std::cout << "min = " << min(a,b) << "\n";
	std::cout << "min = " << max(a,b) << "\n";
}
