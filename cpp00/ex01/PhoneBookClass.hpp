#ifndef Phone_Book_Hpp
# define Phone_Book_Hpp
# include "ContactClass.hpp"

class PhoneBook
{
public:
	Contact	contact[8];
	int		nb_contact;
	int		target;
	void	showinfo( void );
	void	showcontact( int );
	PhoneBook();
	~PhoneBook();
};

#endif
