#include "PhoneBookClass.hpp"
#include <string>

static void	add(PhoneBook *phonebook)
{
	int index = phonebook->target;
	std::string data;
	if (phonebook->nb_contact < 8)
	{
		phonebook->target++;
		phonebook->nb_contact++;
	}
	if (phonebook->target >= 8)
		phonebook->target = 0;
	std::cin.ignore();
	std::cout << "Enter a first name" << std::endl; //can enter empty field
	std::getline(std::cin, data);
	phonebook->contact[index].set_firstname(data);
	std::cout << "Enter a last name" << std::endl;
	std::getline(std::cin, data);
	phonebook->contact[index].set_lastname(data);
	std::cout << "Enter a nickname" << std::endl;
	std::getline(std::cin, data);
	phonebook->contact[index].set_nickname(data);
	std::cout << "Enter a phone number" << std::endl;
	std::getline(std::cin, data);
	phonebook->contact[index].set_phone(data);
	std::cout << "Enter the biggest secret you know about him / her" << std::endl;
	std::getline(std::cin, data);
	phonebook->contact[index].set_secret(data);
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
