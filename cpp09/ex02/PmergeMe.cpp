#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "PmergeMe created with copy constructor\n";
	(void) copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout << "PmergeMe created with operator constructor\n";
	(void) copy;
	return *this;
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::insertion_sort(std::vector<int>& vector, int start, int end)
{
	int val, j;
	for (int i = start; i < end; i++)
	{
		val = vector[i];
		j = i - 1;

		while (j >= start && vector[j] > val)
		{
			vector[j + 1] = vector[j];
			j = j - 1;
		}
		vector[j + 1] = val;
	}
}

void PmergeMe::insertion_sort(std::deque<int>& deque, int start, int end)
{
	int val, j;
	for (int i = start; i < end; i++)
	{
		val = deque[i];
		j = i - 1;

		while (j >= start && deque[j] > val)
		{
			deque[j + 1] = deque[j];
			j = j - 1;
		}
		deque[j + 1] = val;
	}
}

void PmergeMe::merge_sort(std::vector<int>& vector, int start, int half, int end)
{
	int right_idx = 0, left_idx = 0, n1, n2;
	n1 = half - start + 1;
	n2 = end - half;

	std::vector<int> right, left;
	for (int i = start; i < half; i++) // half + 1
		left.push_back(vector[i]);
	for (int i = half; i < end; i++)// half + 1
		right.push_back(vector[i]);

	//debug
	std::cout << "vector right :";
	for (size_t i = 0; i < right.size(); i++)
		std::cout << right[i] << " ";
	std::cout << "\n";
	std::cout << "vector left :";
	for (size_t i = 0; i < left.size(); i++)
		std::cout << left[i] << " ";
	std::cout << "\n";
	std::cout << "vector curr :";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << "\n";
	//end

	for (int i = start; i < end - start + 1; i++)
	{
		if (right_idx == n2) {
			vector[i] = left[left_idx];
			left_idx++;
		}
		else if (left_idx == n1){
			vector[i] = right[right_idx];
			right_idx++;
		}
		else if (right[right_idx] > left[left_idx]){
			vector[i] = left[left_idx];
			left_idx++;
		}
		else{
			vector[i] = right[right_idx];
			right_idx++;
		}
	}
}

void PmergeMe::merge_insert_vector(int start, int end)
{
	if (end - start > 5) {
		int half = (start + end) / 2;
		merge_insert_vector(start, half);
		merge_insert_vector(half + 1, end);
		merge_sort(this->vector, start, half, end);
	}
	else
		insertion_sort(this->vector, start, end);
}

void PmergeMe::sort(std::string data)
{
	(void) data;
	for (int i = 12; i > 0; i--)
	{
		this->vector.push_back(i);
		this->deque.push_back(i);
	}
	merge_insert_vector(0, this->vector.size());
	for (int i = 0; i < 10; i++)
		std::cout << this->vector[i] << " ";
	std::cout << "\n";
	//for (int i = 0; i < 10; i++)
	//	std::cout << this->deque[i] << " ";
	this->deque.clear();
	this->vector.clear();
}
