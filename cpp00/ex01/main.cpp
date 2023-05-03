#include <iostream>
#include "PhoneBookClass.hpp"

static void	add(PhoneBook *phonebook)
{
	int index = phonebook->target;
	if (phonebook->nb_contact < 8)
	{
		phonebook->target++;
		phonebook->nb_contact++;
	}
	if (phonebook->target >= 8)
		phonebook->target = 0;
	std::cout << "Enter a first name" << std::endl;
	std::cin >> phonebook->contact[index].first_name;
	std::cout << "Enter a last name" << std::endl;
	std::cin >> phonebook->contact[index].last_name;
	std::cout << "Enter a nickname" << std::endl;
	std::cin >> phonebook->contact[index].nickname;
	std::cout << "Enter a phone number" << std::endl;
	std::cin >> phonebook->contact[index].phone;
	std::cout << "Enter the biggest secret you know about him / her" << std::endl;
	std::cin >> phonebook->contact[index].secret;
}

int main()
{
	std::string cmd = "";
	PhoneBook phonebook;
	phonebook.nb_contact = 0;
	phonebook.target = 0;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			add(&phonebook);
		else if (cmd == "SEARCH")
			phonebook.showinfo();
		else if (cmd == "EXIT")
			return (0);
	}
}
