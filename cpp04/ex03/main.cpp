#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
	AMateria *ice = new Ice();
	AMateria *ice2 = ice; // not a deep copy;
	std::cout << "\nEND OF CONSTRUCT\n\n";
 	ICharacter *joe = new Character("joe");
	ICharacter *bot = new Character("Bot");
	MateriaSource source;

	std::cout << "\nEND OF CONSTRUCT\n\n";

	std::cout << "\nTESTING ALL ERROR\n\n";
	joe->equip(NULL);
	joe->equip(ice2);
	joe->equip(ice);
	joe->equip(ice);
	joe->equip(ice);
	joe->equip(ice);
	joe->unequip(0);
	joe->unequip(1);
	joe->unequip(2);
	joe->unequip(3);
	joe->unequip(10000000);
	joe->use(100, *bot);
	joe->use(0, *bot);
	joe->use(-10, *bot);
	source.createMateria("asdas");

	std::cout << "\nBASIC TETS\n\n";
	source.learnMateria(ice);
	source.learnMateria(new Cure());
	joe->equip(ice);
	joe->equip(source.createMateria("cure"));
	joe->equip(new Cure());
	joe->equip(source.createMateria("ice"));
	std::cout << "\n";
	joe->use(0, *bot);
	joe->use(1, *bot);
	joe->use(2, *bot);
	joe->use(3, *bot);
	std::cout << "\nUnequipping ice pointer, it will be deleted in the sourcemateria since it learned it previously\n";
	joe->unequip(0);
	std::cout << "\nDELETING ALL BEFORE SUBJECT MAIN TEST\n\n";
	delete joe;
	delete bot;

	std::cout << "\n\nSUBJECT MAIN TEST\n\n";
	MateriaSource* src = new MateriaSource();

	std::cout << "\n\nLEARNING ICE AND CURE \n\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << "\n\nCREATING AND EQUIPING 2 MATERIA WITH 1 POINTER \n\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	std::cout << "\n\nUSING EQUIPPED MATERIA \n";
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "\n\nDELETING ALL \n\n";
	delete bob;
	delete me;
	delete src;
}
