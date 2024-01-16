#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
	void insertion_sort(std::vector<int>& vector, int start, int end);
	void insertion_sort(std::deque<int>& deque, int start, int end);
	void merge_sort(std::vector<int>& vector, int start, int half, int end);
	void merge_insert_vector(int start, int end);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &cpy);
	~PmergeMe();
	void sort(std::string parse);
};
