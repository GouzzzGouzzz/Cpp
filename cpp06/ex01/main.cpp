#include "Serialize.hpp"

int main()
{
	Data test("truc", 10);
	std::cout << "Truc address: " << &test << "\n";
	Serialize truc;
	Data *ptr2;
	test.getInfo();
	uintptr_t seri = truc.serialize(&test);
	ptr2 = truc.deserialize(seri);
	std::cout << "Deserialized address: " << &ptr2 << "\n";
	ptr2->getInfo();
	if (&(*ptr2) == &test)
		std::cout << "the same\n";
}
