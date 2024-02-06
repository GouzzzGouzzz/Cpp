#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

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
	std::vector<int> larger_pair;

	//popping the latest value if the vector isn't even, so we can create pair
	int last = -1;
	if (main.size() % 2 != 0)
	{
		last = main.back();
		main.pop_back();
	}

	// the n/2 comparison per pair
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it+=2)
	{
		if (*it < *(it+1))
			larger_pair.push_back(*(it+1));
		else
			larger_pair.push_back(*it);
	}

	//erasing form the main vector, since we moved those value in the larger_pair one
	for (std::vector<int>::iterator it = main.begin(); it != main.end(); it+=2)
	{
		if (*it < *(it+1))
		{
			main.erase((it+1));
			it--;
		}
		else
			main.erase(it);
	}

	//recursively sorting each pair in ascending order
	sort_pair(larger_pair, 0);

	//step 4 of wikipedia

	//inserting the unsorted elements into our sorted vector
	int insertIndex = 0;
	for (size_t i = 0; i < main.size(); i++)
	{
		insertIndex = binarySearch_vector(larger_pair, main[i], 0, larger_pair.size() - 1);
		larger_pair.insert(larger_pair.begin() + insertIndex, main[i]);
	}

	//adding back the popped element from the start if there was one
	if (last != -1)
	{
		insertIndex = binarySearch_vector(larger_pair, last, 0, larger_pair.size() - 1);
		larger_pair.insert(larger_pair.begin() + insertIndex, last);
	}

	this->vector = larger_pair;
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
