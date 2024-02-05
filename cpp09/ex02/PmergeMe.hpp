#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sys/time.h>
#include <iomanip>

#define MAKEITSHORTER 0

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &cpy);
	~PmergeMe();
	void sort(char **ag, int ac);
private:
	std::vector<int> vector;

	std::vector<int> vector_copy;
	std::deque<int> deque;
	bool input(char **ag, int ac);
	void print_vector();
	void print_deque();
	int get_paired(int target);
	std::vector<int> sort_pair(std::vector<int> &arr);
	void mergeInsert_vector(std::vector<int>& main);
	int binarySearch_vector(std::vector<int>& sortedArray, int target, int low, int high) const;
};
