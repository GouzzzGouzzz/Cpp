#include "PhoneBookClass.hpp"
#include <iostream>
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
	std::cout << this->contact[index].first_name << std::endl
	<< this->contact[index].last_name << std::endl
	<< this->contact[index].nickname << std::endl
	<< this->contact[index].phone << std::endl
	<< this->contact[index].secret << std::endl;
}

void	PhoneBook::showinfo(void)
{
	int index;

	index = -1;
	for (int i = 0; i < this->nb_contact; i++)
	{
		if (this->contact[i].first_name.length() >= 10)
		{
			this->contact[i].first_name.resize(10);
			this->contact[i].first_name[9] = '.';
		}
		if (this->contact[i].last_name.length() > 10)
		{
			this->contact[i].last_name.resize(10);
			this->contact[i].last_name[9] = '.';
		}
		if (this->contact[i].nickname.length() > 10)
		{
			this->contact[i].nickname.resize(10);
			this->contact[i].nickname[9] = '.';
		}
		std::cout << std::right << std::setw(10) << i << "|"
		<< std::right << std::setw(10) << this->contact[i].first_name << "|"
		<< std::right << std::setw(10) << this->contact[i].last_name << "|"
		<< std::right << std::setw(10) << this->contact[i].nickname << "|"<< std::endl;
	}
	std::cout << "Enter an index to display the entry" << std::endl;
	std::cin >> index; //<-- les problemes
	if (index < 0 || index > this->nb_contact || (index > this->target && this->nb_contact < 8))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	showcontact(index);
}
