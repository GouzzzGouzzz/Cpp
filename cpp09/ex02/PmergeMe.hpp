#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sys/time.h>
#include <iomanip>
#include <algorithm>

#define MAKEITSHORTER 1

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	void sort(char **ag, int ac);
private:
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &cpy);
	std::vector<int> vector;
	std::deque<int> deque;
	bool input(char **ag, int ac);
	int get_jacobsthal(int index) const;
	//deque
	void print_deque();
	void sort_pair_deque(std::deque<int> &arr, int offset);
	void mergeInsert_deque(std::deque<int>& main);
	int binarySearch_deque(std::deque<int>& sortedArray, int target) const;
	//vector
	void print_vector();
	void sort_pair_vector(std::vector<int> &arr, int offset);
	void mergeInsert_vector(std::vector<int>& main);
	int binarySearch_vector(std::vector<int>& sortedArray, int target) const;
};
