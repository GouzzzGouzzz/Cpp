#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
	void insertion_sort(std::vector<int>& vector, int start, int end);
	void insertion_sort(std::deque<int>& deque, int start, int end);
	void merge(std::vector<int>& vector, int start, int half, int end);
	void merge(std::deque<int>& vector, int start, int half, int end);
	void merge_insert_vector(int start, int end);
	void merge_insert_deque(int start, int end);
	bool input(char **ag, int ac);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &cpy);
	~PmergeMe();
	void sort(char **ag, int ac);
};
