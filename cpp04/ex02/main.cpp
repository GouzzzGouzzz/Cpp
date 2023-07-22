#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete i;
	delete j;

	//AAnimal test;
	//unquoting the previous line will give a warning because AAnimal is an abstract class
	//however, you can still define an array of an abstract class like this :
  	const AAnimal* array[6] = {new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};
	for (int i = 0; i < 6; i++)
		delete array[i];
	const Dog *t1 = new Dog();
	const AAnimal *t2 = new Dog((*t1));
	delete t1;
	std::cout << "t2=" << t2->getType() << "\n";
	delete t2;

	return 0;
}
