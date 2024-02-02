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
	std::deque<int> deque;
	bool input(char **ag, int ac);
	void print_vector();
	void print_deque();
	void merge_insert_vector(std::vector<int>& main);
	std::vector<int> create_pairs(std::vector<int>& main);
};
