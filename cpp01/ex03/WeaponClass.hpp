#ifndef Weapon_Class_HPP
# define Weapon_Class_HPP
# include <iostream>
class Weapon
{
public:
	Weapon(std::string weapon);
	~Weapon();
	std::string getType( void );
	void setType ( std::string );
private:
	std::string type;
};


#endif
