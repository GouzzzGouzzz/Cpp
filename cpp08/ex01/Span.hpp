#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>

class Span
{
public:
	class maximumReached : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	class notEnoughNumbers : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	Span(unsigned int n);
	Span &operator=(const Span &copy);
	Span(const Span &copy);
	~Span();
	void addNumber(int n);
	template<class InputIterator>
	void manyNumbers(InputIterator first, InputIterator last)
	{
		std::srand(std::time(NULL));
		while (first != last)
		{
			if (this->store.size() + 1 > this->max){
				std::cout << "Maximal size reached !\n A total of : " << first << " numbers have been added\n";
				break;
			}
			this->store.push_back(std::rand());
			first++;
		}
	}
	int shortestSpan() const;
	int longestSpan() const;
private:
	std::vector<int> store;
	unsigned int max;
};




