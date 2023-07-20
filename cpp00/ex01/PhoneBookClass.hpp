#ifndef Phone_Book_Hpp
# define Phone_Book_Hpp
# include "ContactClass.hpp"
# include <iostream>

class PhoneBook
{
	Contact	_contact[8];
	int		_nb_contact;
	int		_target;
public:
	void	showinfo( void );
	void	showcontact( int );
	void	add();
	PhoneBook();
	~PhoneBook();
};

#endif
