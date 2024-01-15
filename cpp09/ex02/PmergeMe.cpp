#include "PmergeMe.hpp"

Pmerge::Pmerge()
{

}

Pmerge::Pmerge(const Pmerge &copy)
{
	std::cout << "Pmerge created with copy constructor\n";
	(void) copy;
}

Pmerge& Pmerge::operator=(const Pmerge &copy)
{
	std::cout << "Pmerge created with operator constructor\n";
	(void) copy;
	return *this;
}

Pmerge::~Pmerge()
{

}

template<class T>
void Pmerge::insertion_sort(T container)
{
	int val, j;
	for (size_t i = 1; i < container.size(); i++)
	{
		val = container[i];
		j = i - 1;

		while (j >= 0 && container[j] > val)
		{
			container[j + 1] = container[j];
			j = j - 1;
		}
		container[j + 1] = val;
	}
}

void Pmerge::sort(std::string data)
{
	(void) data;
	for (int i = 10; i > 0; i--)
	{
		this->vector.push_back(i);
		this->deque.push_back(i);
	}
	insertion_sort(this->vector);
	insertion_sort(this->deque);
	for (int i = 0; i < 10; i++)
		std::cout << this->vector[i] << " ";
	std::cout << "\n";
	for (int i = 0; i < 10; i++)
		std::cout << this->deque[i] << " ";
	this->deque.clear();
	this->vector.clear();
}
