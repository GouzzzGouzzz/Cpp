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

void PmergeMe::mergeInsert_vector(std::vector<int>& main)
{
	// end of recursion
	if(main.size() <= 1)
		return ;

	int insertIndex = 0;
	std::vector<int> sorted;

	//get the highest pair grouped
	for (size_t i = 0; i < main.size() - 1; i+=2)
	{
		if (main[i] < main[i+1])
			sorted.push_back(main[i+1]);
		else
			sorted.push_back(main[i]);
	}
	//sorting with recursion
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;
	mergeInsert_vector(sorted);
	std::vector<int> test;
	test.push_back(main[0]);
	//inserted remaining elements (starting to 1 since 0 has been inserted)
	/* for (size_t i = 1; i < main.size(); i++)
	{
		insertIndex = binarySearch_vector(sorted, main[i], 0, sorted.size() - 1);
		sorted.insert(sorted.begin() + insertIndex, main[i]);
	} */
	this->vector = sorted;
}

void PmergeMe::sort(char **ag, int ac)
{
	if (input(ag, ac) == false)
		return;
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
