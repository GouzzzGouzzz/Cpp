#ifndef Contact_Class_Hpp
# define Contact_Class_Hpp
# include <string>

class Contact
{
public:
	Contact();
	~Contact();
	void	set_firstname(std::string);
	void	set_lastname(std::string);
	void	set_nickname(std::string);
	void	set_phone(std::string);
	void	set_secret(std::string);
	std::string	get_firstname(void);
	std::string	get_lastname(void);
	std::string	get_nickname(void);
	std::string	get_phone(void);
	std::string	get_secret(void);
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
};

#endif
