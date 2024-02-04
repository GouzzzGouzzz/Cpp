#include "Serialize.hpp"

int main()
{
	Data test("truc", 10);
	std::cout << "Truc address: " << &test << "\n";
	Data *ptr2;
	test.getInfo();
	uintptr_t seri = Serialize::serialize(&test);
	ptr2 = Serialize::deserialize(seri);
	std::cout << "Deserialized address: " << &ptr2 << "\n";
	ptr2->getInfo();
	if (&(*ptr2) == &test)
		std::cout << "the same\n";
}
