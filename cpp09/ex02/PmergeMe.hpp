#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
	void insertion_sort(std::vector<int>& vector);
	void insertion_sort(std::deque<int>& deque);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe& operator=(const PmergeMe &cpy);
	~PmergeMe();
	void sort(std::string parse);
};
