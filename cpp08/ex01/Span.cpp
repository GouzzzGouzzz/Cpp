#include "Span.hpp"

Span::Span(unsigned int n)
{
	std::cout << "Span default constructor called\n";
	this->max = n;
}

Span& Span::operator=(const Span &copy)
{
	std::cout << "Span  copy operator called\n";
	this->store = copy.store;
	this->max = copy.max;
	return *this;
}

Span::Span(const Span &copy)
{
	std::cout << "Span copy constructor called\n";
	*this = copy;
}

Span::~Span()
{
	std::cout << "Span  destructor called\n";
	this->store.clear();
}

void Span::addNumber(int n)
{
	if (this->store.size() + 1 > this->max)
		throw maximumReached();
	this->store.push_back(n);
}

int Span::shortestSpan() const
{
	if (this->store.size() <= 1)
		throw notEnoughNumbers();
	int n1 = 2147483647;
	std::vector<int> sorted_cpy;
	sorted_cpy = this->store;
	std::sort(sorted_cpy.begin(),sorted_cpy.end());
	for (size_t i = sorted_cpy.size()-1; i > 1; i--)
		if (sorted_cpy[i] - sorted_cpy[i-1] < n1)
			n1 = sorted_cpy[i] - sorted_cpy[i - 1];
	return n1;
}

int Span::longestSpan() const
{
	if (this->store.size() <= 1)
		throw notEnoughNumbers();
	std::vector<int> sorted_cpy;
	sorted_cpy = this->store;
	std::sort(sorted_cpy.begin(),sorted_cpy.end());
	return (sorted_cpy[sorted_cpy.size() - 1] - sorted_cpy[0]);
}

const char *Span::maximumReached::what() const throw() { return "Error : Maximum capacity reached !\n"; }
const char *Span::notEnoughNumbers::what() const throw() { return "Error : Not enough number !\n"; }

