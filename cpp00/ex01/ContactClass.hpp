#ifndef Contact_Class_Hpp
# define Contact_Class_Hpp
# include <string>

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	Contact();
	~Contact();
};

#endif
