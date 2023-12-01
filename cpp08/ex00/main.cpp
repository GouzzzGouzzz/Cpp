#include "easyfind.hpp"

#include <vector>
#include <list>
int main()
{
	std::vector<int> vector;
	std::list<int> lst;

	for (int i = 0; i < 10; i++)
		vector.push_back(i);
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	std::cout << "trying to find 8(vector): " << easyfind(vector,8) << "\n";
	std::cout << "trying to find 11(vector): " << easyfind(vector,11) << "\n";
	std::cout << "trying to find 8(list): " << easyfind(lst,8) << "\n";
	std::cout << "trying to find 11(list): " << easyfind(lst,11) << "\n";

}
