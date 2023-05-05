#ifndef Zombie_HPP
# define Zombie_HPP
# include <iostream>

class Zombie
{
public:
	Zombie( std::string );
	Zombie();
	~Zombie();
	void announce( void );
	std::string get_name( void );
private:
	std::string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name);

#endif
