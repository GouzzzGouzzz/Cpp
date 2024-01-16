#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "Pmerge created with copy constructor\n";
	(void) copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout << "Pmerge created with operator constructor\n";
	(void) copy;
	return *this;
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::insertion_sort(std::vector<int>& vector)
{
	int val, j;
	for (size_t i = 1; i < vector.size(); i++)
	{
		val = vector[i];
		j = i - 1;

		while (j >= 0 && vector[j] > val)
		{
			vector[j + 1] = vector[j];
			j = j - 1;
		}
		vector[j + 1] = val;
	}
}

void PmergeMe::insertion_sort(std::deque<int>& deque)
{
	int val, j;
	for (size_t i = 1; i < deque.size(); i++)
	{
		val = deque[i];
		j = i - 1;

		while (j >= 0 && deque[j] > val)
		{
			deque[j + 1] = deque[j];
			j = j - 1;
		}
		deque[j + 1] = val;
	}
}

void PmergeMe::sort(std::string data)
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
