#pragma once

#include <vector>
#include <deque>
#include <iostream>

template<class T>
class Pmerge
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
	void insertion_sort(T container);
public:
	Pmerge();
	Pmerge(const Pmerge &copy);
	Pmerge& operator=(const Pmerge &cpy);
	~Pmerge();
	void sort(std::string parse);
};
