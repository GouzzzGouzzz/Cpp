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


//return the index from where our target should be placed --> TODO : ADD Jacobsthal here
int PmergeMe::binarySearch_vector(std::vector<int>& sortedArray, int target, int low, int high) const
{
	int mid = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sortedArray[mid] == target)
			return mid;
		else if (sortedArray[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

int PmergeMe::get_paired(int target)
{
	for (size_t i = 0; i < this->vector_copy.size(); i++)
	{
		if (this->vector_copy[i] == target)
		{
			if (i % 2 == 0)
			{
				std::cout << "returned :" << this->vector_copy[i+1] << " for " << target << "\n";
				return this->vector_copy[i+1];
			}
			else
			{
				std::cout << "returned :" << this->vector_copy[i+1] << " for " << target << "\n";
				return this->vector_copy[i-1];
			}
		}
	}
	return -1;
}

void PmergeMe::sort_pair(std::vector<int> &arr, int offset)
{
	if (size_t(offset) < arr.size() - 1)
	{
		for (size_t i = offset + 1; i < arr.size(); i++)
		{
			if (arr[i] < arr[offset]) // swap
			{
				int tmp = arr[i];
				arr[i] = arr[offset];
				arr[offset] = tmp;
			}
		}
		sort_pair(arr, offset + 1);
	}
}

void PmergeMe::mergeInsert_vector(std::vector<int>& main)
{
	std::vector<int> larger_pair; //n/2 elem pair
	for (size_t i = 0; i < main.size() - 1; i+=2)
	{
		if (main[i] < main[i+1])
			larger_pair.push_back(main[i+1]);
		else
			larger_pair.push_back(main[i]);
	}
	sort_pair(larger_pair, 0);//les pairs sont trier plus qu a binarysort
	for (size_t i = 0; i < larger_pair.size(); i++)
		std::cout << larger_pair[i] << " ";
	std::cout << std::endl;
	/* for (size_t i = 0; i < larger_pair.size(); i++)
		std::cout << larger_pair[i] << " ";
	std::cout << std::endl; */
/*
	int insertIndex = 0;
	for (size_t i = 0; i < main.size(); i++)
	{
		insertIndex = binarySearch_vector(sorted, main[i], 0, sorted.size() - 1);
		std::cout << "inserted:" << main[i] << " at []" << insertIndex<<"\n";
		std::cout << "now : ";
		sorted.insert(sorted.begin() + insertIndex, main[i]);
		for (size_t i = 0; i < sorted.size(); i++)
			std::cout << sorted[i] << " ";
		std::cout << "\n";
	}
	this->vector = sorted; */
}

void PmergeMe::sort(char **ag, int ac)
{
	if (input(ag, ac) == false)
		return;
	this->vector_copy = this->vector;
	print_vector();
	print_deque();

	mergeInsert_vector(this->vector);
/* 	struct timeval start_v, start_d;
	struct timeval end_v, end_d;
	double buffer;
	gettimeofday(&start_v, NULL);
	merge_insert_vector(0, this->vector.size()-1);
	gettimeofday(&end_v, NULL);
	buffer = (double)(end_v.tv_sec - start_v.tv_sec) + (double)(end_v.tv_usec - start_v.tv_usec) / 1000000;
	std::cout << "Time to process a range of: " << this->vector.size() << " elements with std::vector :";
	std::cout << std::fixed << std::setprecision(5) << buffer << " us\n";
	gettimeofday(&start_d, NULL);
	//merge_insert_deque(0, this->deque.size()-1);
	gettimeofday(&end_d, NULL);
	buffer = (double)(end_d.tv_sec - start_d.tv_sec) + (double)(end_d.tv_usec - start_d.tv_usec) / 1000000;
	std::cout << "Time to process a range of: " << this->deque.size() << " elements with std::deque  :";
	std::cout << std::fixed << std::setprecision(5) << buffer << " us\n";

	print_deque(); */
	print_vector();
}
