#include "PhoneBookClass.hpp"
#include <string>

static void	add(PhoneBook *phonebook)
{
	int index = phonebook->target;
	std::string first, last, nick, phone, secret;
	if (phonebook->target >= 8)
		phonebook->target = 0;
	std::cin.ignore();
	std::cout << "Enter a first name" << std::endl; //can enter empty field
	std::getline(std::cin, first);
	std::cout << "Enter a last name" << std::endl;
	std::getline(std::cin, last);
	std::cout << "Enter a nickname" << std::endl;
	std::getline(std::cin, nick);
	std::cout << "Enter a phone number" << std::endl;
	std::getline(std::cin, phone);
	std::cout << "Enter the biggest secret you know about him / her" << std::endl;
	std::getline(std::cin, secret);
	if (!last.empty() && !first.empty() && !nick.empty() && !phone.empty() && !secret.empty())
	{
		phonebook->contact[index].set_firstname(first);
		phonebook->contact[index].set_lastname(last);
		phonebook->contact[index].set_nickname(nick);
		phonebook->contact[index].set_phone(phone);
		phonebook->contact[index].set_secret(secret);
		if (phonebook->nb_contact < 8)
		{
			phonebook->target++;
			phonebook->nb_contact++;
		}
	}
	else
		std::cout << "A field is empty, the contact will not be saved" << std::endl;
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
