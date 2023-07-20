#include "PhoneBookClass.hpp"
#include <string>

int main()
{
	std::string cmd = "";
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> cmd;
		if (cmd.length() == 0)
			return (-1);
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.showinfo();
		else if (cmd == "EXIT")
			return (0);
		cmd.clear();
	}
}
