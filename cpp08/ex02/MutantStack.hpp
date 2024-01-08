#pragma once
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack &copy) { *this = copy; };
	MutantStack& operator=(const MutantStack &cpy)
	{
		std::stack<T>::operator=(cpy);
		return *this;
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };
};
