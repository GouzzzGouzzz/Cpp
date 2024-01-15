#pragma once

#include <vector>
#include <deque>
#include <iostream>

class Pmerge
{
private:
	std::vector<int> vector;
	std::deque<int> deque;
	template<class T>
	void insertion_sort(T);
public:
	Pmerge();
	Pmerge(const Pmerge &copy);
	Pmerge& operator=(const Pmerge &cpy);
	~Pmerge();
	void sort(std::string);
};
