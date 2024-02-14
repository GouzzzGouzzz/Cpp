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
				std::cout << "Error: at pos: " << i << " `"<< parse[i] << "` is not a valid input !" << std::endl;
				return false;
			}
			if (parse[i] == ' ' && strtol(parse.substr(i, parse.size()).c_str(), NULL,10) > 2147483647)
			{
				std::cout<< "Error: Too big number given ! need to be less than 2147483647 and greather than 0."<< std::endl;
				return false;
			}
			if (i == 0 && strtol(parse.substr(i, parse.size()).c_str(), NULL,10) > 2147483647)
			{
				std::cout<< "Error: Too big number given ! need to be less than 2147483647 and greather than 0."<< std::endl;
				return false;
			}
		}
		while (stream >> nb)
		{
			this->vector.push_back(nb);
			this->deque.push_back(nb);
		}
	}
	for (std::vector<int>::iterator it = this->vector.begin(); it != this->vector.end(); ++it)
	{
		for (std::vector<int>::iterator it2 = it+1; it2 != this->vector.end(); ++it2)
		{
			if (*it == *it2)
			{
				std::cout << "Error: Duplicated number aren't allowed\n";
				return false;
			}
		}
	}
	return true;
}

int PmergeMe::get_jacobsthal(int index) const
{
	if (index == 0)
		return 0;
	else if (index == 1)
		return 1;
	else
		return get_jacobsthal(index - 1) + 2 * get_jacobsthal(index - 2);
}

//	*********************************** DEQUE ***********************************

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

void PmergeMe::sort_pair_deque(std::deque<int> &deque, int offset)
{
	if (size_t(offset) < deque.size() - 1)
	{
		for (size_t i = offset + 1; i < deque.size(); i++)
		{
			if (deque[i] < deque[offset])
			{
				int tmp = deque[i];
				deque[i] = deque[offset];
				deque[offset] = tmp;
			}
		}
		sort_pair_deque(deque, offset + 1);
	}
}

int PmergeMe::binarySearch_deque(std::deque<int>& sorted, int target) const
{
	int mid = 0, low = 0, high = sorted.size() - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sorted[mid] == target)
			return mid;
		else if (sorted[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

void PmergeMe::mergeInsert_deque(std::deque<int>& main)
{
	std::deque<int> larger_pair;
	std::deque<int> jacob_suite;
	int index = 3;
	int insertIndex = 0;
	int last = -1;

	if (main.size() % 2 != 0){
		last = main.back();
		main.pop_back();
	}
	for (std::deque<int>::iterator it = main.begin(); it < main.end(); it+=2){
		if (*it < *(it+1))
			larger_pair.push_back(*(it+1));
		else
			larger_pair.push_back(*it);
	}
	for (std::deque<int>::iterator it = larger_pair.begin(); it != larger_pair.end(); ++it)
		main.erase(std::remove(main.begin(), main.end(), *it), main.end());
	sort_pair_deque(larger_pair, 0);
	larger_pair.insert(larger_pair.begin(), main[0]);
	main.erase(main.begin());
	while (get_jacobsthal(index) < static_cast<int>(main.size() - 1)){
		jacob_suite.push_back(get_jacobsthal(index));
		index++;
	}
	while (jacob_suite.empty() == false){
		insertIndex = binarySearch_deque(larger_pair, main[jacob_suite[0] - 1]);
		larger_pair.insert(larger_pair.begin() + insertIndex, main[jacob_suite[0] - 1]);
		main.erase(main.begin() + jacob_suite[0] -1);
		jacob_suite.erase(jacob_suite.begin());
	}
	for (size_t i = 0; i < main.size(); i++){
		insertIndex = binarySearch_deque(larger_pair, main[i]);
		larger_pair.insert(larger_pair.begin() + insertIndex, main[i]);
	}
	if (last != -1){
		insertIndex = binarySearch_deque(larger_pair, last);
		larger_pair.insert(larger_pair.begin() + insertIndex, last);
	}
	this->deque = larger_pair;
}


//	*********************************** VECTOR ***********************************

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
	std::cout << "\n\n";
}

int PmergeMe::binarySearch_vector(std::vector<int>& sortedArray, int target) const
{
	int mid = 0, low = 0, high = sortedArray.size() - 1;
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

void PmergeMe::sort_pair_vector(std::vector<int>& arr, int offset)
{
	if (size_t(offset) < arr.size() - 1)
	{
		for (size_t i = offset + 1; i < arr.size(); i++)
		{
			if (arr[i] < arr[offset])
			{
				int tmp = arr[i];
				arr[i] = arr[offset];
				arr[offset] = tmp;
			}
		}
		sort_pair_vector(arr, offset + 1);
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

	//erasing from the main vector, since we moved those value in "larger_pair"
	for (std::vector<int>::iterator it = larger_pair.begin(); it != larger_pair.end(); ++it)
		main.erase(std::remove(main.begin(), main.end(), *it), main.end());

	//recursively sorting each pair in ascending order
	sort_pair_vector(larger_pair, 0);

	//inserting the first element manually since it was the lower value of our first pair
	larger_pair.insert(larger_pair.begin(), main[0]);
	main.erase(main.begin());

	//creating the jacobsthal sequence for the main array
	std::vector<int> jacob_suite;
	int index = 3;
	while (get_jacobsthal(index) < static_cast<int>(main.size() - 1))
	{
		jacob_suite.push_back(get_jacobsthal(index));
		index++;
	}

	//inserting the unsorted elements into our sorted vector using the jacobsthal sequence
	int insertIndex = 0;
	while (jacob_suite.empty() == false)
	{
		insertIndex = binarySearch_vector(larger_pair, main[jacob_suite[0] - 1]);
		larger_pair.insert(larger_pair.begin() + insertIndex, main[jacob_suite[0] - 1]);
		main.erase(main.begin() + jacob_suite[0] -1);
		jacob_suite.erase(jacob_suite.begin());
	}

	//insert the remaining elements of the main array into the sorted one
	for (size_t i = 0; i < main.size(); i++)
	{
		insertIndex = binarySearch_vector(larger_pair, main[i]);
		larger_pair.insert(larger_pair.begin() + insertIndex, main[i]);
	}

	//adding back the popped element from the start if there was one
	if (last != -1)
	{
		insertIndex = binarySearch_vector(larger_pair, last);
		larger_pair.insert(larger_pair.begin() + insertIndex, last);
	}
	this->vector = larger_pair;
}

//	**************** PUBLIC ****************

void PmergeMe::sort(char **ag, int ac)
{
	if (input(ag, ac) == false)
		return;
	struct timeval start_v, start_d;
	struct timeval end_v, end_d;
	double buffer;

	print_deque();
	print_vector();

	gettimeofday(&start_v, NULL);

	mergeInsert_vector(this->vector);

	gettimeofday(&end_v, NULL);
	buffer = (double)(end_v.tv_sec - start_v.tv_sec) + (double)(end_v.tv_usec - start_v.tv_usec) / 1000000;
	std::cout << "Time to process a range of: " << this->vector.size() << " elements with std::vector :";
	std::cout << std::fixed << std::setprecision(5) << buffer << " us\n";
	gettimeofday(&start_d, NULL);

	mergeInsert_deque(this->deque);

	gettimeofday(&end_d, NULL);
	buffer = (double)(end_d.tv_sec - start_d.tv_sec) + (double)(end_d.tv_usec - start_d.tv_usec) / 1000000;
	std::cout << "Time to process a range of: " << this->deque.size() << " elements with std::deque  :";
	std::cout << std::fixed << std::setprecision(5) << buffer << " us\n";

	print_deque();
	print_vector();
}
