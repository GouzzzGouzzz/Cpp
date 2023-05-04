#include "PhoneBookClass.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructur called" << std::endl;

}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::showcontact(int index)
{
	std::cout << "First name     :" << this->contact[index].get_firstname() << std::endl
	<< "Last name      :" << this->contact[index].get_lastname() << std::endl
	<< "Nickname       :" << this->contact[index].get_nickname() << std::endl
	<< "Phone number   :" << this->contact[index].get_phone() << std::endl
	<< "Darkest secret :" << this->contact[index].get_secret() << std::endl;
}

void	PhoneBook::showinfo(void)
{
	int index;
	std::string data, first, last, nick;
	index = -1;
	if (this->nb_contact == 0)
	{
		std::cout << "NO CONTACT FOUND" << std::endl;
		return ;
	}
 	for (int i = 0; i < this->nb_contact; i++)
	{
		first = this->contact[i].get_firstname();
		last = this->contact[i].get_lastname();
		nick = this->contact[i].get_nickname();
		if (first.length() >= 10)
			first.resize(10); first[9] = '.';
		if (last.length() >= 10)
			last.resize(10); last[9] = '.';
		if (nick.length() >= 10)
			nick.resize(10); nick[9] = '.';
		std::cout << std::setw(10) << i+1 << "|"
		<< std::setw(10) << first << "|"
		<< std::setw(10) << last << "|"
		<< std::setw(10) << nick << "|"<< std::endl;
	}
	std::cout << "Enter an index to display the entry" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, data);
	index = atoi(data.c_str());
	if (index <= 0 || index > this->nb_contact || (index > this->target && this->nb_contact < 8))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	showcontact(atoi(data.c_str()) - 1);
}
