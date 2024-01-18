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
	for (int i = start + 1; i <= end; i++)
	{
		val = vector[i];
		j = i - 1;

		while (j >= start && vector[j] > val)
		{
			vector[j + 1] = vector[j];
			--j;
		}
		vector[j + 1] = val;
	}
}

void PmergeMe::insertion_sort(std::deque<int>& deque, int start, int end)
{
	int val, j;
	for (int i = start + 1; i <= end; i++)
	{
		val = deque[i];
		j = i - 1;

		while (j >= start && deque[j] > val)
		{
			deque[j + 1] = deque[j];
			--j;
		}
		deque[j + 1] = val;
	}
}

void PmergeMe::merge(std::vector<int>& vector, int start, int half, int end)
{
	int size_left = half - start + 1;
	int size_right = end - half;
	int i = 0, j = 0;
	int k = start;
	std::vector<int> left(size_left);
	std::vector<int> right(size_right);

	for (int i = 0; i < size_left; ++i)
		left[i] = vector[start + i];
	for (int j = 0; j < size_right; ++j)
		right[j] = vector[half + 1 + j];
	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j]) {
			vector[k] = left[i];
			++i;
		} else {
			vector[k] = right[j];
			++j;
		}
		++k;
	}
	while (i < size_left)
	{
		vector[k] = left[i];
		++k;
		++i;
	}
	while (j < size_right)
	{
		vector[k] = right[j];
		++j;
		++k;
	}
}

void PmergeMe::merge(std::deque<int>& deque, int start, int half, int end)
{
	int size_left = half - start + 1;
	int size_right = end - half;
	int i = 0, j = 0;
	int k = start;
	std::deque<int> left(size_left);
	std::deque<int> right(size_right);

	for (int i = 0; i < size_left; ++i)
		left[i] = deque[start + i];
	for (int j = 0; j < size_right; ++j)
		right[j] = deque[half + 1 + j];
	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j]) {
			deque[k] = left[i];
			++i;
		} else {
			deque[k] = right[j];
			++j;
		}
		++k;
	}
	while (i < size_left)
	{
		deque[k] = left[i];
		++k;
		++i;
	}
	while (j < size_right)
	{
		deque[k] = right[j];
		++j;
		++k;
	}
}

void PmergeMe::merge_insert_vector(int start, int end)
{
	if (start < end)
	{
		if (end - start + 1 <= 5)
			insertion_sort(this->vector,start, end);
		else
		{
			int half = start + (end - start) / 2;
			merge_insert_vector(start, half);
			merge_insert_vector(half+1, end);
			merge(this->vector,start, half,end);
		}
	}
}

void PmergeMe::merge_insert_deque(int start, int end)
{
	if (start < end)
	{
		if (end - start + 1 <= 5)
			insertion_sort(this->deque,start, end);
		else
		{
			int half = start + (end - start) / 2;
			merge_insert_deque(start, half);
			merge_insert_deque(half+1, end);
			merge(this->deque,start, half,end);
		}
	}
}

bool PmergeMe::input(char **ag, int ac)
{
	std::vector<int> temp;
	int nb;
	for (int i = 1; i < ac; i++)
	{
		std::istringstream stream(ag[i]);
		std::string parse = ag[i];
		for (size_t i = 0; i < parse.size(); i++)
		{
			if (parse[i] != ' ' && isdigit(parse[i]) == false){
				std::cout << "At pos: " << i << " `"<< parse[i] << "` is not a valid input !" << std::endl;
				return false;
			}
			if (parse[i] == ' ' && strtol(parse.substr(i, parse.size()).c_str(), NULL,10) > 2147483647)
			{
				std::cout<< "Too big number given ! need to be less than 2147483647 and greather than 0."<< std::endl;
				return false;
			}
			if (i == 0 && strtol(parse.substr(i, parse.size()).c_str(), NULL,10) > 2147483647)
			{
				std::cout<< "Too big number given ! need to be less than 2147483647 and greather than 0."<< std::endl;
				return false;
			}
		}
		while (stream >> nb)
		{
			this->vector.push_back(nb);
			this->deque.push_back(nb);
		}
	}
	return true;
}

void PmergeMe::print_vector()
{
	std::cout << "Printing vector :";
	if (MAKEITSHORTER == 1 && this->vector.size() > 10){
		for (size_t i = 0; i < 10; i++)
			std::cout << this->vector[i] << " ";
	}
	else{
		for (std::vector<int>::iterator it = this->vector.begin(); it < this->vector.end();it++)
			std::cout << (*it) << " ";
	}
	std::cout << "\n";
}

void PmergeMe::print_deque()
{
	std::cout << "\nPrinting deque  :";
	if (MAKEITSHORTER == 1 && this->deque.size() > 10){
		for (size_t i = 0; i < 10; i++)
			std::cout << this->deque[i] << " ";
	}
	else{
		for (std::deque<int>::iterator it = this->deque.begin(); it < this->deque.end();it++)
			std::cout << (*it) << " ";
	}
	std::cout << "\n";
}

void PmergeMe::sort(char **ag, int ac)
{
	if (input(ag, ac) == false)
		return;
	print_vector();
	print_deque();

	struct timeval start_v, start_d;
	struct timeval end_v, end_d;
	double buffer;
	gettimeofday(&start_v, NULL);
	merge_insert_vector(0, this->vector.size()-1);
	gettimeofday(&end_v, NULL);
	buffer = (double)(end_v.tv_sec - start_v.tv_sec) + (double)(end_v.tv_usec - start_v.tv_usec) / 1000000;
	std::cout << "Time to process a range of: " << this->vector.size() << " elements with std::vector :";
	std::cout << std::fixed << std::setprecision(5) << buffer << " us\n";
	gettimeofday(&start_d, NULL);
	merge_insert_deque(0, this->deque.size()-1);
	gettimeofday(&end_d, NULL);
	buffer = (double)(end_d.tv_sec - start_d.tv_sec) + (double)(end_d.tv_usec - start_d.tv_usec) / 1000000;
	std::cout << "Time to process a range of: " << this->deque.size() << " elements with std::deque  :";
	std::cout << std::fixed << std::setprecision(5) << buffer << " us\n";

	print_vector();
	print_deque();
}
